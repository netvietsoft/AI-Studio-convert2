import cv2
import numpy as np
import ncnn

# 1. Load Models
bisenet = ncnn.Net()
bisenet.load_param("app/src/main/assets/models/bisenet_face_19.param")
bisenet.load_model("app/src/main/assets/models/bisenet_face_19.bin")

selfie = ncnn.Net()
selfie.load_param("app/src/main/assets/models/selfie_segmentation.param")
selfie.load_model("app/src/main/assets/models/selfie_segmentation.bin")

def rgb_to_oklab(r, g, b):
    # sRGB to linear
    def to_linear(c):
        return np.where(c <= 0.04045, c / 12.92, ((c + 0.055) / 1.055) ** 2.4)
    lr = to_linear(r)
    lg = to_linear(g)
    lb = to_linear(b)
    
    l = np.cbrt(0.4122214708 * lr + 0.5363325363 * lg + 0.0514459929 * lb)
    m = np.cbrt(0.2119034982 * lr + 0.6806995451 * lg + 0.1073969566 * lb)
    s = np.cbrt(0.0883024619 * lr + 0.2817188376 * lg + 0.6299787005 * lb)
    
    L = 0.2104542553 * l + 0.7936177850 * m - 0.0040720468 * s
    a = 1.9779984951 * l - 2.4285922050 * m + 0.4505937099 * s
    bCoord = 0.0259040371 * l + 0.7827717662 * m - 0.8086757660 * s
    return L, a, bCoord

def oklab_to_rgb(L, a, bCoord):
    l = L + 0.3963377774 * a + 0.2158037573 * bCoord
    m = L - 0.1055613458 * a - 0.0638541728 * bCoord
    s = L - 0.0894841775 * a - 1.2914855480 * bCoord
    
    l3 = l * l * l
    m3 = m * m * m
    s3 = s * s * s
    
    lr = +4.0767434721 * l3 - 3.3077115913 * m3 + 0.2309699292 * s3
    lg = -1.2684380046 * l3 + 2.6097574011 * m3 - 0.3413193965 * s3
    lb = -0.0041960863 * l3 - 0.7034186147 * m3 + 1.7076147010 * s3
    
    def from_linear(c):
        c_clamped = np.clip(c, 0.0, 1.0)
        return np.where(c_clamped <= 0.0031308, c_clamped * 12.92, 1.055 * (c_clamped ** (1.0 / 2.4)) - 0.055)
    
    r = from_linear(lr)
    g = from_linear(lg)
    b = from_linear(lb)
    return np.clip(r, 0.0, 1.0), np.clip(g, 0.0, 1.0), np.clip(b, 0.0, 1.0)

def is_human_skin_pixel(r, g, b):
    # Vectorized YCbCr & RGB human skin check
    y = 0.299 * r + 0.587 * g + 0.114 * b
    cr = (r - y) * 0.713 + 128.0
    cb = (b - y) * 0.564 + 128.0
    cond_dark = (r <= 45) | (g <= 28) | (b <= 15)
    c1 = (cr >= 130.0) & (cr <= 175.0) & (cb >= 77.0) & (cb <= 130.0) & (r > b)
    c2 = (r > g) & (g >= b) & ((r - g) >= 5) & ((r - b) >= 10)
    return (c1 | c2) & (~cond_dark)

def process_rebuild(img_path, target_rgb, bleach_power=0.82, intensity=0.75, gloss=0.65):
    img = cv2.imread(img_path)
    h, w = img.shape[:2]
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    
    # 1. BiSeNet parsing
    in_mat = ncnn.Mat.from_pixels_resize(img_rgb, ncnn.Mat.PixelType.PIXEL_RGB, w, h, 512, 512)
    mean_vals = [0.485 * 255.0, 0.456 * 255.0, 0.406 * 255.0]
    norm_vals = [1.0 / (0.229 * 255.0), 1.0 / (0.224 * 255.0), 1.0 / (0.225 * 255.0)]
    in_mat.substract_mean_normalize(mean_vals, norm_vals)
    ex = bisenet.create_extractor()
    ex.input("in0", in_mat)
    _, out_bisenet = ex.extract("out0")
    bisenet_arr = np.array(out_bisenet) # (19, 512, 512)
    labels512 = np.argmax(bisenet_arr, axis=0).astype(np.uint8)
    
    # Compute hair probability
    max_scores = np.max(bisenet_arr, axis=0)
    exp_scores = np.exp(bisenet_arr - max_scores)
    hair_prob512 = exp_scores[17] / np.sum(exp_scores, axis=0)
    
    labels = cv2.resize(labels512, (w, h), interpolation=cv2.INTER_NEAREST)
    hair_prob = cv2.resize(hair_prob512, (w, h), interpolation=cv2.INTER_LINEAR)
    
    # 2. Selfie Segmentation (person mask)
    in_selfie = ncnn.Mat.from_pixels_resize(img_rgb, ncnn.Mat.PixelType.PIXEL_RGB, w, h, 256, 256)
    in_selfie.substract_mean_normalize([], [1.0/255.0, 1.0/255.0, 1.0/255.0])
    ex_s = selfie.create_extractor()
    ex_s.input("in0", in_selfie)
    _, out_selfie = ex_s.extract("out0")
    selfie_prob256 = np.array(out_selfie).reshape(256, 256)
    person_prob = cv2.resize(selfie_prob256, (w, h), interpolation=cv2.INTER_LINEAR)
    
    # 3. Locate Head / Face Anatomical Anchors
    # Face skin (1), Brows (2,3), Eyes (4,5), Glasses (6), Nose (10), Mouth (11..13)
    face_feature_mask = (labels == 1) | ((labels >= 2) & (labels <= 6)) | (labels == 10) | ((labels >= 11) & (labels <= 13))
    feature_pts = np.argwhere(face_feature_mask)
    
    if len(feature_pts) < 100:
        # No face detected
        face_cx = w * 0.5
        face_cy = h * 0.4
        chin_y = h * 0.6
        forehead_y = h * 0.25
        head_w = w * 0.4
    else:
        min_fy, min_fx = feature_pts.min(axis=0)
        max_fy, max_fx = feature_pts.max(axis=0)
        face_cx = (min_fx + max_fx) * 0.5
        face_cy = (min_fy + max_fy) * 0.5
        chin_y = max_fy
        face_h = max_fy - min_fy
        head_w = max_fx - min_fx
        forehead_y = min_fy - 0.25 * face_h
    
    # 4. Strict Protected Region Mask
    r_chan = img_rgb[:,:,0]
    g_chan = img_rgb[:,:,1]
    b_chan = img_rgb[:,:,2]
    skin_map = is_human_skin_pixel(r_chan, g_chan, b_chan)
    
    # Protected classes from BiSeNet:
    # 1: Skin, 2..6: Eyes/Brows/Glasses, 7,8: Ears, 9: Earrings, 10: Nose, 11..13: Mouth, 14: Neck, 15: Necklace, 16: Cloth
    bisenet_protected = (labels == 1) | ((labels >= 2) & (labels <= 15)) | (labels == 16)
    
    # Protected region combines semantic labels AND color skin AND background (outside person)
    bg_mask = (person_prob < 0.25)
    protected_mask = bisenet_protected | skin_map | bg_mask
    
    # Extra protection: Any skin in the face/forehead oval (extended from facial features)
    y_coords, x_coords = np.mgrid[0:h, 0:w]
    dx_face = (x_coords - face_cx) / (head_w * 0.65 + 1e-5)
    dy_face = (y_coords - face_cy) / ((chin_y - forehead_y) * 0.75 + 1e-5)
    in_face_oval = (dx_face**2 + dy_face**2 <= 1.0) & (y_coords >= forehead_y - 0.1*(chin_y-forehead_y)) & (y_coords <= chin_y + 0.1*(chin_y-forehead_y))
    protected_mask = protected_mask | (in_face_oval & skin_map)
    
    # 5. Anatomical Hair Extraction & Propagation
    # True scalp hair must exist in the upper head area (y <= chin_y + 0.2 * face_h)
    scalp_zone = (y_coords <= chin_y + 0.15 * (chin_y - forehead_y))
    raw_hair_seed = (labels == 17) & scalp_zone & (~protected_mask) & (hair_prob > 0.45)
    
    seed_pixels = img_rgb[raw_hair_seed]
    if len(seed_pixels) < 150:
        print(f"[{img_path}] Negative control / bald detected (hair seeds={len(seed_pixels)})")
        return img_rgb, np.zeros((h, w), dtype=np.float32)
    
    # Compute hair appearance model (LAB mean & std)
    seed_r = seed_pixels[:, 0] / 255.0
    seed_g = seed_pixels[:, 1] / 255.0
    seed_b = seed_pixels[:, 2] / 255.0
    sL, sa, sb = rgb_to_oklab(seed_r, seed_g, seed_b)
    mean_hL, std_hL = float(np.mean(sL)), float(np.std(sL))
    mean_ha, std_ha = float(np.mean(sa)), float(np.std(sa))
    mean_hb, std_hb = float(np.mean(sb)), float(np.std(sb))
    print(f"[{img_path}] Hair seed OKLab: L={mean_hL:.3f}+-{std_hL:.3f}, a={mean_ha:.3f}, b={mean_hb:.3f}")
    
    # 6. Candidate Hair Validation (Filter out false positives on clothing/arms)
    img_L, img_a, img_b = rgb_to_oklab(r_chan / 255.0, g_chan / 255.0, b_chan / 255.0)
    # Color distance in OKLab from scalp hair seed
    d_color = np.sqrt(((img_L - mean_hL)/max(0.12, std_hL*2.5))**2 + 
                      ((img_a - mean_ha)/0.08)**2 + 
                      ((img_b - mean_hb)/0.08)**2)
    
    # Candidate hair:
    # Upper head: labels == 17, hair_prob > 0.35, not protected
    # Below chin: MUST match scalp hair color (d_color < 3.2), have high texture, not protected, and have labels == 17
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY).astype(np.float32) / 255.0
    gray_blur = cv2.blur(gray, (5, 5))
    tex_energy = np.abs(gray - gray_blur)
    
    hair_candidate = (labels == 17) & (hair_prob > 0.30) & (~protected_mask)
    # For pixels below chin, enforce strict color consistency with head hair
    below_chin = (y_coords > chin_y)
    hair_candidate = hair_candidate & (~(below_chin & (d_color > 2.8)))
    
    # Topological connectivity to scalp hair
    num_labels, comp_labels = cv2.connectedComponents(hair_candidate.astype(np.uint8))
    scalp_components = set(np.unique(comp_labels[raw_hair_seed]))
    scalp_components.discard(0)
    
    connected_hair = np.isin(comp_labels, list(scalp_components))
    
    # 7. High-Resolution Edge-Aware Matting (Trimap + Guided Filter)
    definite_hair = connected_hair & (hair_prob > 0.65) & (d_color < 2.2) & (~protected_mask)
    definite_non_hair = protected_mask | (person_prob < 0.15) | (comp_labels == 0)
    uncertain = connected_hair & (~definite_hair) & (~definite_non_hair)
    # Also include 3-pixel dilation of boundary as uncertain zone
    kernel3 = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5))
    dilated_hair = cv2.dilate(definite_hair.astype(np.uint8), kernel3) > 0
    uncertain = uncertain | (dilated_hair & (~definite_hair) & (~definite_non_hair))
    
    trimap = np.zeros((h, w), dtype=np.float32)
    trimap[definite_hair] = 1.0
    trimap[uncertain] = 0.5
    trimap[definite_non_hair] = 0.0
    
    def box_filter(im, r):
        return cv2.blur(im, (2 * r + 1, 2 * r + 1))

    r = 4
    eps = 1e-3
    mean_I = box_filter(gray, r)
    mean_p = box_filter(trimap, r)
    mean_Ip = box_filter(gray * trimap, r)
    cov_Ip = mean_Ip - mean_I * mean_p
    mean_II = box_filter(gray * gray, r)
    var_I = mean_II - mean_I * mean_I
    a = cov_Ip / (var_I + eps)
    b = mean_p - a * mean_I
    mean_a = box_filter(a, r)
    mean_b = box_filter(b, r)
    refined_matte = np.clip(mean_a * gray + mean_b, 0.0, 1.0)
    
    # Apply strict protected region gate
    # finalAlpha = refinedMatte * semanticConfidence * NOT(protectedMask)
    final_alpha = refined_matte * np.clip(hair_prob * 1.2, 0.0, 1.0) * (1.0 - protected_mask.astype(np.float32))
    final_alpha[definite_non_hair] = 0.0
    final_alpha[protected_mask] = 0.0
    final_alpha = np.clip(final_alpha, 0.0, 1.0)
    
    # 8. Natural Salon Color Transform (OKLab Luminance & Chroma Modulation)
    tgt_r, tgt_g, tgt_b = target_rgb[0] / 255.0, target_rgb[1] / 255.0, target_rgb[2] / 255.0
    tgt_L, tgt_a, tgt_bCoord = rgb_to_oklab(tgt_r, tgt_g, tgt_b)
    
    # Low-frequency base luminance and high-frequency strand ratio
    base_L = cv2.blur(img_L, (7, 7))
    strand_ratio = np.clip((img_L + 0.02) / (base_L + 0.02), 0.70, 1.45)
    strand_detail = img_L - base_L
    
    # Bleach/Lightness lift
    lift_amount = tgt_L - base_L
    melanin_curve = np.where(base_L > 0, 0.40 + 0.60 * np.sqrt(np.clip(base_L, 0.0, 1.0)), 0.40)
    lifted_base_L = base_L + lift_amount * bleach_power * melanin_curve * intensity
    
    # Modulate with 100% strand ratio to preserve curls, highlights, root shadows
    final_L = np.clip(lifted_base_L * strand_ratio + strand_detail * 0.35, 0.02, 0.98)
    
    # Salon Chroma deposition
    dye_strength = np.clip(0.45 + 0.55 * (4.0 * final_L * (1.0 - final_L)), 0.0, 1.0) * intensity
    final_a = img_a * (1.0 - dye_strength) + tgt_a * dye_strength
    final_bCoord = img_b * (1.0 - dye_strength) + tgt_bCoord * dye_strength
    
    # Specular Glint preservation
    spec_strength = np.clip((img_L - 0.50) / 0.40, 0.0, 1.0) * gloss * 0.70
    final_a = final_a * (1.0 - spec_strength * 0.5) + img_a * (spec_strength * 0.5)
    final_bCoord = final_bCoord * (1.0 - spec_strength * 0.5) + img_b * (spec_strength * 0.5)
    
    out_r, out_g, out_b = oklab_to_rgb(final_L, final_a, final_bCoord)
    dyed_rgb = np.stack([out_r, out_g, out_b], axis=2) * 255.0
    
    # Alpha Compositing
    eff_alpha = (final_alpha * intensity)[:, :, None]
    orig_rgb_f = img_rgb.astype(np.float32)
    result_rgb = np.clip(orig_rgb_f * (1.0 - eff_alpha) + dyed_rgb * eff_alpha, 0, 255).astype(np.uint8)
    
    return result_rgb, final_alpha

# Test Rose Gold [225, 140, 160] on Case A and Wine Burgundy [125, 22, 44] on Case B
res_A, alpha_A = process_rebuild("scratch/hair_test_assets/portrait_0_curly.png", [225, 140, 160], bleach_power=0.82, intensity=0.75, gloss=0.65)
cv2.imwrite("scratch/owner_evidence/rebuild_result_A.png", cv2.cvtColor(res_A, cv2.COLOR_RGB2BGR))
cv2.imwrite("scratch/owner_evidence/rebuild_alpha_A.png", (alpha_A * 255).astype(np.uint8))

res_B, alpha_B = process_rebuild("scratch/owner_evidence/owner_fail_B_orig.png", [125, 22, 44], bleach_power=0.40, intensity=0.75, gloss=0.55)
cv2.imwrite("scratch/owner_evidence/rebuild_result_B.png", cv2.cvtColor(res_B, cv2.COLOR_RGB2BGR))
cv2.imwrite("scratch/owner_evidence/rebuild_alpha_B.png", (alpha_B * 255).astype(np.uint8))
print("Finished testing rebuild pipeline!")

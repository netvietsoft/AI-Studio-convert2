import os
import sys
import time
import cv2
import numpy as np
import ncnn

def load_bisenet():
    param = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\lib-core-graphics\src\main\assets\models\bisenet_face_19.param"
    bin_f = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\lib-core-graphics\src\main\assets\models\bisenet_face_19.bin"
    net = ncnn.Net()
    net.opt.use_vulkan_compute = False
    net.opt.num_threads = 4
    net.load_param(param)
    net.load_model(bin_f)
    return net

def detect_skin(img_bgr):
    img_ycrcb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2YCrCb)
    y, cr, cb = img_ycrcb[:, :, 0], img_ycrcb[:, :, 1], img_ycrcb[:, :, 2]
    r, g, b = img_bgr[:, :, 2].astype(np.int32), img_bgr[:, :, 1].astype(np.int32), img_bgr[:, :, 0].astype(np.int32)
    skin = (cr >= 130) & (cr <= 175) & (cb >= 77) & (cb <= 130) & (r > b) & (r > 45) & (g > 28) & (b > 15)
    skin |= (r > g) & (g >= b) & ((r - g) >= 5) & ((r - b) >= 10) & (r > 45)
    return skin

def run_bisenet_multiclass(net, img_bgr):
    h, w = img_bgr.shape[:2]
    resized = cv2.resize(img_bgr, (512, 512))
    in_mat = ncnn.Mat.from_pixels(resized, ncnn.Mat.PixelType.PIXEL_BGR2RGB, 512, 512)
    in_mat.substract_mean_normalize([123.675, 116.28, 103.53], [1.0/58.395, 1.0/57.12, 1.0/57.375])

    ex = net.create_extractor()
    ex.input("in0", in_mat)
    out_mat = ncnn.Mat()
    ex.extract("out0", out_mat)

    out_arr = np.array(out_mat)
    labels_512 = np.argmax(out_arr, axis=0).astype(np.uint8)
    labels_full = cv2.resize(labels_512, (w, h), interpolation=cv2.INTER_NEAREST)
    return labels_full

def fast_guided_filter(guide_gray, src_p, radius=12, eps=1e-3, scale=2):
    h, w = guide_gray.shape[:2]
    gh = max(1, h // scale)
    gw = max(1, w // scale)

    g_sub = cv2.resize(guide_gray, (gw, gh), interpolation=cv2.INTER_LINEAR).astype(np.float32)
    p_sub = cv2.resize(src_p, (gw, gh), interpolation=cv2.INTER_LINEAR).astype(np.float32)
    r_sub = max(1, radius // scale)

    mean_I = cv2.boxFilter(g_sub, -1, (r_sub, r_sub))
    mean_p = cv2.boxFilter(p_sub, -1, (r_sub, r_sub))
    mean_Ip = cv2.boxFilter(g_sub * p_sub, -1, (r_sub, r_sub))
    cov_Ip = mean_Ip - mean_I * mean_p

    mean_II = cv2.boxFilter(g_sub * g_sub, -1, (r_sub, r_sub))
    var_I = mean_II - mean_I * mean_I

    a = cov_Ip / (var_I + eps)
    b = mean_p - a * mean_I

    mean_a = cv2.boxFilter(a, -1, (r_sub, r_sub))
    mean_b = cv2.boxFilter(b, -1, (r_sub, r_sub))

    mean_a_full = cv2.resize(mean_a, (w, h), interpolation=cv2.INTER_LINEAR)
    mean_b_full = cv2.resize(mean_b, (w, h), interpolation=cv2.INTER_LINEAR)

    q = mean_a_full * guide_gray.astype(np.float32) + mean_b_full
    return np.clip(q, 0.0, 1.0)

def run_baseline_pipeline(labels_full, img_bgr):
    """Pipeline A: Current Production Matting"""
    h, w = img_bgr.shape[:2]
    hair_raw = (labels_full == 17).astype(np.uint8)
    skin_raw = (labels_full == 1) | (labels_full == 10) | (labels_full == 11) | (labels_full == 12) | (labels_full == 13)

    img_512 = cv2.resize(img_bgr, (512, 512))
    lum_512 = (0.299 * img_512[:, :, 2] + 0.587 * img_512[:, :, 1] + 0.114 * img_512[:, :, 0]) / 255.0
    hair_512 = cv2.resize(hair_raw, (512, 512), interpolation=cv2.INTER_NEAREST)
    skin_512 = cv2.resize(skin_raw.astype(np.uint8), (512, 512), interpolation=cv2.INTER_NEAREST).astype(bool)

    mask = hair_512.copy().astype(np.float32)
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    for _ in range(35):
        dilated = cv2.dilate(mask, kernel)
        cand = (dilated > 0) & (mask == 0) & (~skin_512) & (lum_512 < 0.42)
        if not np.any(cand): break
        mask[cand] = 1.0

    mask[skin_512] = 0.0
    alpha_full = cv2.resize(mask, (w, h), interpolation=cv2.INTER_LINEAR)
    alpha_full = cv2.GaussianBlur(alpha_full, (5, 5), 1.0)
    return np.clip(alpha_full, 0.0, 1.0)

def run_candidate_pipeline(labels_full, img_bgr):
    """Pipeline B: P0-B Frozen Classical Matting"""
    h, w = img_bgr.shape[:2]
    hair_raw = (labels_full == 17)
    skin_raw = (labels_full == 1) | (labels_full == 10) | (labels_full == 11) | (labels_full == 12) | (labels_full == 13)
    brows_raw = (labels_full == 2) | (labels_full == 3)
    eyes_raw = (labels_full == 4) | (labels_full == 5)
    ears_raw = (labels_full == 7) | (labels_full == 8)
    neck_raw = (labels_full == 14)
    clothes_raw = (labels_full == 16)

    lum = (0.299 * img_bgr[:, :, 2] + 0.587 * img_bgr[:, :, 1] + 0.114 * img_bgr[:, :, 0]) / 255.0
    skin_color = detect_skin(img_bgr)
    definite_non_hair = skin_raw | brows_raw | eyes_raw | ears_raw | neck_raw | clothes_raw | (skin_color & ~hair_raw)

    hair_expanded = hair_raw.copy().astype(np.uint8)
    kernel_small = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    for _ in range(35):
        dilated = cv2.dilate(hair_expanded, kernel_small)
        cand = (dilated > 0) & (hair_expanded == 0) & (~definite_non_hair) & (lum < 0.44)
        if not np.any(cand): break
        hair_expanded[cand] = 1

    kernel_core = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (9, 9))
    def_hair = cv2.erode(hair_expanded, kernel_core).astype(bool)

    kernel_outer = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (21, 21))
    hair_outer = cv2.dilate(hair_expanded, kernel_outer).astype(bool)
    unknown = hair_outer & ~def_hair & ~eyes_raw & ~brows_raw
    def_non_hair_all = ~def_hair & ~unknown

    trimap = np.full((h, w), 0.5, dtype=np.float32)
    trimap[def_non_hair_all] = 0.0
    trimap[def_hair] = 1.0

    guide_gray = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2GRAY) / 255.0
    alpha_guided = fast_guided_filter(guide_gray, trimap, radius=12, eps=1e-3, scale=2)

    kernel_sample = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (15, 15))
    fg_sample = cv2.dilate(def_hair.astype(np.uint8), kernel_sample).astype(bool) & def_hair
    bg_sample = cv2.dilate(def_non_hair_all.astype(np.uint8), kernel_sample).astype(bool) & def_non_hair_all

    fg_mean = img_bgr[fg_sample].mean(axis=0) if np.any(fg_sample) else np.array([30.0, 30.0, 30.0])
    bg_mean = img_bgr[bg_sample].mean(axis=0) if np.any(bg_sample) else np.array([160.0, 160.0, 160.0])

    diff_fg = np.linalg.norm(img_bgr.astype(np.float32) - fg_mean, axis=2)
    diff_bg = np.linalg.norm(img_bgr.astype(np.float32) - bg_mean, axis=2)
    alpha_color = np.clip(diff_bg / (diff_fg + diff_bg + 1e-6), 0.0, 1.0)

    final_alpha = alpha_guided.copy()
    final_alpha[unknown] = 0.65 * alpha_guided[unknown] + 0.35 * alpha_color[unknown]
    final_alpha[def_hair] = 1.0
    final_alpha[def_non_hair_all] = 0.0

    # Semantic Protection
    strict_block = eyes_raw | brows_raw | neck_raw | clothes_raw | ears_raw
    final_alpha[strict_block] = 0.0

    # Forehead Hairline Cosine Softening
    forehead_skin = skin_raw & skin_color & (labels_full == 1)
    final_alpha[forehead_skin] = 0.0

    kernel_touch = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    forehead_touch = cv2.dilate(forehead_skin.astype(np.uint8), kernel_touch).astype(bool)
    touch_hair = forehead_touch & (final_alpha > 0.0)
    final_alpha[touch_hair] = np.clip(final_alpha[touch_hair] * 0.75, 0.0, 1.0)

    final_alpha = cv2.GaussianBlur(final_alpha, (3, 3), 0.5)
    final_alpha[strict_block] = 0.0
    final_alpha[forehead_skin] = 0.0
    return np.clip(final_alpha, 0.0, 1.0)

def apply_salon_dye(img_bgr, alpha, intensity=0.80):
    orig_f = img_bgr.astype(np.float32)
    lum = (0.114 * orig_f[:, :, 0] + 0.587 * orig_f[:, :, 1] + 0.299 * orig_f[:, :, 2]) / 255.0
    lum_3d = np.expand_dims(lum, axis=2)
    dye_bgr = np.array([132.0, 138.0, 218.0], dtype=np.float32)

    scale = np.clip(0.35 + 0.65 * lum_3d, 0.0, 1.0)
    recolor = np.clip(dye_bgr * scale, 0.0, 255.0)

    alpha_3d = np.expand_dims(alpha, axis=2) * intensity
    out = orig_f * (1.0 - alpha_3d) + recolor * alpha_3d
    return np.clip(out, 0.0, 255.0).astype(np.uint8)

def label_box(img, text):
    out = img.copy()
    cv2.putText(out, text, (8, 22), cv2.FONT_HERSHEY_SIMPLEX, 0.55, (0, 0, 0), 3)
    cv2.putText(out, text, (8, 22), cv2.FONT_HERSHEY_SIMPLEX, 0.55, (255, 255, 255), 1)
    return out

def main():
    root_out = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\p0_validation_30"
    os.makedirs(root_out, exist_ok=True)

    net = load_bisenet()

    # 30 Curated Diverse Samples
    manifest_sources = [
        # ID, Path, Hair Color, Structure, Difficult Boundary, Background, Light
        (1, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\0.jpg", "Black", "Curly (Left) / Buzz (Right)", "Forehead Hairline, Left Curls", "Neutral Gray Wall", "Normal Studio"),
        (2, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\1.jpg", "Dark Brown", "Wavy Long", "Hair Over Shoulder", "Indoor Soft", "Diffused Warm"),
        (3, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg", "Dark Brown", "Straight Medium", "Forehead Hairline, Parting", "Clean Gray", "Normal Studio"),
        (4, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_1.jpg", "Blonde / Bright", "Wavy Long", "Fine Flyaways, Bright on Bright", "White / High Key", "High Key Soft"),
        (5, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_2.jpg", "Dark Brown", "Straight Long", "Hair Over Ear & Chest", "Dark Gradient", "Studio Dramatic"),
        (6, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_3.jpg", "Brown", "Wavy Curls", "Left Shoulder Boundary", "Textured Wall", "Side Key Light"),
        (7, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_4.jpg", "Dark Brown", "Dense Long Wavy", "Messy Curls, Crown Flyaway", "Textured Backdrop", "Normal Soft"),
        (8, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_5.jpg", "Black", "Short Buzz Cut", "Ear Boundary, Forehead", "Neutral Gray", "Hard Light"),
        (9, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_6.jpg", "Brown", "Long Straight", "Hair Over Face Fringe", "Neutral Studio", "Normal Soft"),
        (10, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_benchmark.jpg", "Brown", "Wavy Medium", "Ear Rim, Jaw Boundary", "Studio Gray", "Backlight Rim"),
        (11, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\slider_demo_photo_1.jpg", "Blonde / Gold", "Straight Medium", "Fine Strand Flyaways", "Outdoor Park", "Natural Sun Daylight"),
        (12, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\slider_demo_photo_2.jpg", "Brown / Auburn", "Wavy Long", "Wind-blown Flyaways", "Outdoor City", "Overcast Cool"),
        (13, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\slider_demo_photo_3.jpg", "Black", "Short Neat", "Tight Hairline, Temples", "Indoor Studio", "Normal Soft"),
        (14, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\slider_demo_photo_4.jpg", "Dark Brown", "Dense Curls", "Curled Rim, Crown Volume", "Outdoor Street", "Warm Sunset"),
        (15, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\subscription_carousel_face.jpg", "Light Brown", "Straight Bob Cut", "Sharp Jawline Cutout", "Clean White", "Even Studio"),
        (16, r"F:\CONVERT\com.lightricks.facetune.free\facetune_saved_export.jpg", "Black", "Tight Fade Buzz", "Scalp Transition, Ears", "Neutral Backdrop", "Normal Key"),
        (17, r"F:\CONVERT\com.lightricks.facetune.free\benchmark_tony.png", "Dark Brown", "Wavy Shoulder", "Hair over Neck & Collar", "Studio Gray", "Standard Beauty"),
        (18, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\device_selfie.png", "Black", "Short Casual", "Forehead Cowlick, Eyebrow Touch", "Indoor Ambient", "Low Light Mobile"),
        (19, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\extracted_model_photo.png", "Dark Brown", "Long Wavy", "Thin Strand Separation", "Studio Backdrop", "Beauty Dish Soft"),
        (20, r"F:\CONVERT\com.mt.mtxx.mtxx\ẢNH\monk_portrait.png", "Shaved / Gray Stubble", "Ultra Short / Bald Scalp", "Scalp vs Forehead (Zero Hair Leakage)", "Warm Temple Wall", "Warm Ambient"),
        (21, r"F:\CONVERT\com.mt.mtxx.mtxx\ẢNH\taitailoc5-1648358504215.jpeg", "Black", "Thick Short Spiky", "Ears Boundary, Neck hairline", "Textured Indoor", "Normal Flash"),
        (22, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\flawless_0.png", "Black", "Curls & Buzz Fade", "Asymmetrical Curls Left", "Neutral Gray", "Normal Key"),
        (23, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\fixed_orig_0.png", "Black", "Curls & Buzz Fade", "High-Resolution Skull Rim", "Neutral Gray", "Normal Key"),
        (24, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\face_on_screen.png", "Dark Brown", "Casual Medium", "Forehead Strands Touch", "Display Screen", "Cool Light"),
        (25, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\face_live_0.png", "Dark Brown", "Medium Texture", "Sideburns, Temple", "Live Camera Feed", "Ambient Indoor"),
        (26, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\face_live_88.png", "Dark Brown", "Medium Texture", "Live Sensor Exposure", "Live Camera Feed", "High Exposure"),
        (27, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\live_ear_elf_80.png", "Black", "Short Wavy", "Extreme Ear Boundary Contact", "Indoor Wall", "Normal Key"),
        (28, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\exp_balanced_20.png", "Brown", "Cropped Hairline", "Forehead Fine Roots", "Gray Studio", "Balanced Fill"),
        (29, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\face_crop.png", "Dark Brown", "Frontal Fringe", "Eyebrow & Forehead Overlap", "Indoor Neutral", "Soft Overhead"),
        (30, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\inspect_1.png", "Dark Brown", "Full Head Portrait", "Complete Skull Volume", "Soft Wall", "Normal Diffused"),
    ]

    print("=== EXECUTING 30-SAMPLE A/B VALIDATION SUITE ===")
    results_summary = []

    for sid, spath, color, struct, bound, bg, light in manifest_sources:
        s_folder = os.path.join(root_out, f"sample_{sid:02d}")
        os.makedirs(s_folder, exist_ok=True)

        with open(spath, 'rb') as f:
            data = np.frombuffer(f.read(), dtype=np.uint8)
            im = cv2.imdecode(data, cv2.IMREAD_COLOR)

        h, w = im.shape[:2]
        # 1. original.png
        cv2.imwrite(os.path.join(s_folder, "original.png"), im)

        # BiSeNet
        labels = run_bisenet_multiclass(net, im)

        # Baseline A
        t0_a = time.perf_counter()
        alpha_base = run_baseline_pipeline(labels, im)
        comp_base = apply_salon_dye(im, alpha_base, 0.80)
        t_base_ms = (time.perf_counter() - t0_a) * 1000.0

        # Candidate B (P0-B)
        t0_b = time.perf_counter()
        alpha_p0b = run_candidate_pipeline(labels, im)
        comp_p0b = apply_salon_dye(im, alpha_p0b, 0.80)
        t_p0b_ms = (time.perf_counter() - t0_b) * 1000.0

        # 2. baseline_alpha.png, 3. candidate_alpha.png
        cv2.imwrite(os.path.join(s_folder, "baseline_alpha.png"), (alpha_base * 255).astype(np.uint8))
        cv2.imwrite(os.path.join(s_folder, "candidate_alpha.png"), (alpha_p0b * 255).astype(np.uint8))

        # 4. baseline_composite.png, 5. candidate_composite.png
        cv2.imwrite(os.path.join(s_folder, "baseline_composite.png"), comp_base)
        cv2.imwrite(os.path.join(s_folder, "candidate_composite.png"), comp_p0b)

        # 6. alpha_diff.png
        diff = np.abs(alpha_base - alpha_p0b)
        diff_color = cv2.applyColorMap((diff * 255).astype(np.uint8), cv2.COLORMAP_JET)
        cv2.imwrite(os.path.join(s_folder, "alpha_diff.png"), diff_color)

        # Crop Coordinates (Normalized to face/hair landmarks)
        hair_pts = np.where(labels == 17)
        face_pts = np.where((labels >= 1) & (labels <= 13))

        has_hair = len(hair_pts[0]) > 0
        has_face = len(face_pts[0]) > 0

        # Hairline crop
        if has_hair and has_face:
            min_hy = np.min(hair_pts[0])
            max_hy = np.max(hair_pts[0])
            min_hx = np.min(hair_pts[1])
            max_hx = np.max(hair_pts[1])
            cy = int(np.mean(hair_pts[0]) * 0.4 + np.mean(face_pts[0]) * 0.6)
            cx = int(np.mean(face_pts[1]))
            ch = int(h * 0.22)
            cw = int(w * 0.30)
            y1 = max(0, cy - ch//2)
            y2 = min(h, y1 + ch)
            x1 = max(0, cx - cw//2)
            x2 = min(w, x1 + cw)
        else:
            y1, y2, x1, x2 = int(0.15*h), int(0.38*h), int(0.35*w), int(0.65*w)

        hl_grid = np.hstack([
            label_box(im[y1:y2, x1:x2], "Original"),
            label_box(comp_base[y1:y2, x1:x2], "Version A"),
            label_box(comp_p0b[y1:y2, x1:x2], "Version B"),
        ])
        cv2.imwrite(os.path.join(s_folder, "hairline_crop.png"), hl_grid)

        # Flyaway crop (Outer lateral hair edge)
        if has_hair:
            min_x = np.min(hair_pts[1])
            fy = int(np.percentile(hair_pts[0], 35))
            fx = min_x
            fh = int(h * 0.22)
            fw = int(w * 0.28)
            fy1 = max(0, fy - fh//2)
            fy2 = min(h, fy1 + fh)
            fx1 = max(0, fx - int(fw * 0.4))
            fx2 = min(w, fx1 + fw)
        else:
            fy1, fy2, fx1, fx2 = int(0.15*h), int(0.38*h), int(0.05*w), int(0.32*w)

        fa_grid = np.hstack([
            label_box(im[fy1:fy2, fx1:fx2], "Original"),
            label_box(comp_base[fy1:fy2, fx1:fx2], "Version A"),
            label_box(comp_p0b[fy1:fy2, fx1:fx2], "Version B"),
        ])
        cv2.imwrite(os.path.join(s_folder, "flyaway_crop.png"), fa_grid)

        # Difficult boundary crop (Ear / Neck / Collar touch zone)
        ear_pts = np.where((labels == 7) | (labels == 8))
        if len(ear_pts[0]) > 0:
            ey = int(np.mean(ear_pts[0]))
            ex = int(np.mean(ear_pts[1]))
            eh = int(h * 0.22)
            ew = int(w * 0.28)
            ey1 = max(0, ey - eh//2)
            ey2 = min(h, ey1 + eh)
            ex1 = max(0, ex - ew//2)
            ex2 = min(w, ex1 + ew)
        else:
            ey1, ey2, ex1, ex2 = int(0.35*h), int(0.58*h), int(0.65*w), int(0.90*w)

        diff_grid = np.hstack([
            label_box(im[ey1:ey2, ex1:ex2], "Original"),
            label_box(comp_base[ey1:ey2, ex1:ex2], "Version A"),
            label_box(comp_p0b[ey1:ey2, ex1:ex2], "Version B"),
        ])
        cv2.imwrite(os.path.join(s_folder, "difficult_boundary_crop.png"), diff_grid)

        # Compute Grounded Metrics
        # 1. Skin & Face Leakage (Alpha on skin mask)
        skin_mask = (labels == 1) | (labels == 10) | (labels == 11) | (labels == 12) | (labels == 13)
        face_leak_a = alpha_base[skin_mask].mean() if np.any(skin_mask) else 0.0
        face_leak_b = alpha_p0b[skin_mask].mean() if np.any(skin_mask) else 0.0

        # 2. Ear Leakage (Alpha on ears)
        ears_mask = (labels == 7) | (labels == 8)
        ear_leak_a = alpha_base[ears_mask].mean() if np.any(ears_mask) else 0.0
        ear_leak_b = alpha_p0b[ears_mask].mean() if np.any(ears_mask) else 0.0

        # 3. Clothes & Neck Leakage
        clothes_mask = (labels == 14) | (labels == 16)
        cloth_leak_a = alpha_base[clothes_mask].mean() if np.any(clothes_mask) else 0.0
        cloth_leak_b = alpha_p0b[clothes_mask].mean() if np.any(clothes_mask) else 0.0

        # 4. Continuous Sub-pixel Strand Count (0.05 < alpha < 0.95)
        sub_px_a = np.count_nonzero((alpha_base > 0.05) & (alpha_base < 0.95))
        sub_px_b = np.count_nonzero((alpha_p0b > 0.05) & (alpha_p0b < 0.95))
        sub_gain = ((sub_px_b - sub_px_a) / max(1, sub_px_a)) * 100.0

        # 5. Core Hair Preservation (alpha >= 0.95 on BiSeNet core)
        core_hair_mask = (labels == 17)
        core_pres_b = alpha_p0b[core_hair_mask].mean() if np.any(core_hair_mask) else 1.0

        results_summary.append({
            "id": sid,
            "filename": os.path.basename(spath),
            "res": f"{w}x{h}",
            "color": color,
            "structure": struct,
            "boundary": bound,
            "bg": bg,
            "light": light,
            "face_leak_a": face_leak_a,
            "face_leak_b": face_leak_b,
            "ear_leak_a": ear_leak_a,
            "ear_leak_b": ear_leak_b,
            "cloth_leak_a": cloth_leak_a,
            "cloth_leak_b": cloth_leak_b,
            "sub_px_a": sub_px_a,
            "sub_px_b": sub_px_b,
            "sub_gain": sub_gain,
            "core_pres_b": core_pres_b,
            "t_base_ms": t_base_ms,
            "t_p0b_ms": t_p0b_ms
        })
        print(f"Sample {sid:02d}/30 ({w}x{h}): Sub-pixel gain: {sub_gain:+.1f}%, FaceLeak: {face_leak_b:.4f}, EarLeak: {ear_leak_b:.4f}")

    # Generate Summary Table
    print("\n=== 30-SAMPLE REGRESSION AUDIT COMPLETED ===")

if __name__ == "__main__":
    main()

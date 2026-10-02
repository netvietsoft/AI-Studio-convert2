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

def run_bisenet_multiclass(net, img_bgr):
    """Run BiSeNet at 512x512 and return 19-class label map at full native resolution"""
    h, w = img_bgr.shape[:2]
    resized = cv2.resize(img_bgr, (512, 512))
    in_mat = ncnn.Mat.from_pixels(resized, ncnn.Mat.PixelType.PIXEL_BGR2RGB, 512, 512)
    in_mat.substract_mean_normalize([123.675, 116.28, 103.53], [1.0/58.395, 1.0/57.12, 1.0/57.375])

    ex = net.create_extractor()
    ex.input("in0", in_mat)
    out_mat = ncnn.Mat()
    ex.extract("out0", out_mat)

    out_arr = np.array(out_mat) # (19, 512, 512)
    labels_512 = np.argmax(out_arr, axis=0).astype(np.uint8)
    labels_full = cv2.resize(labels_512, (w, h), interpolation=cv2.INTER_NEAREST)
    return labels_full

def fast_guided_filter(guide_gray, src_p, radius, eps, scale=2):
    """
    Fast Guided Image Filter (He & Sun, ECCV 2014)
    Linear-time edge-preserving smoothing that transfers sub-pixel high-frequency
    strands and edges from guide_gray to src_p.
    """
    h, w = guide_gray.shape[:2]
    gh = h // scale
    gw = w // scale

    # Downsample guide and src
    g_sub = cv2.resize(guide_gray, (gw, gh), interpolation=cv2.INTER_LINEAR).astype(np.float32)
    p_sub = cv2.resize(src_p, (gw, gh), interpolation=cv2.INTER_LINEAR).astype(np.float32)
    r_sub = max(1, radius // scale)

    # Box filter mean
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

    # Upsample coefficients to original full resolution
    mean_a_full = cv2.resize(mean_a, (w, h), interpolation=cv2.INTER_LINEAR)
    mean_b_full = cv2.resize(mean_b, (w, h), interpolation=cv2.INTER_LINEAR)

    q = mean_a_full * guide_gray.astype(np.float32) + mean_b_full
    return np.clip(q, 0.0, 1.0)

def detect_skin_mask(img_bgr):
    """Robust YCrCb + RGB skin detection"""
    img_ycrcb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2YCrCb)
    y, cr, cb = img_ycrcb[:, :, 0], img_ycrcb[:, :, 1], img_ycrcb[:, :, 2]
    r, g, b = img_bgr[:, :, 2].astype(np.int32), img_bgr[:, :, 1].astype(np.int32), img_bgr[:, :, 0].astype(np.int32)

    skin = (cr >= 130) & (cr <= 175) & (cb >= 77) & (cb <= 130) & (r > b) & (r > 45) & (g > 28) & (b > 15)
    skin |= (r > g) & (g >= b) & ((r - g) >= 5) & ((r - b) >= 10) & (r > 45)
    return skin

def generate_semantic_trimap(labels_full, img_bgr):
    """
    Generate High-Res Semantic Trimap:
    - DEFINITE_HAIR (1.0): High-confidence hair mass + propagated curls
    - DEFINITE_NON_HAIR (0.0): Face, Skin, Eyes, Brows, Ears, Neck, Clothes, distant Background
    - UNKNOWN (0.5): High-frequency boundary band (hairline, flyaways, curls)
    """
    h, w = labels_full.shape[:2]
    hair_raw = (labels_full == 17)
    skin_raw = (labels_full == 1) | (labels_full == 10) | (labels_full == 11) | (labels_full == 12) | (labels_full == 13)
    brows_raw = (labels_full == 2) | (labels_full == 3)
    eyes_raw = (labels_full == 4) | (labels_full == 5)
    ears_raw = (labels_full == 7) | (labels_full == 8)
    neck_raw = (labels_full == 14)
    clothes_raw = (labels_full == 16)
    bg_raw = (labels_full == 0)

    # 1. Morphological propagation for curls on dark low-lum regions
    lum = (0.299 * img_bgr[:, :, 2] + 0.587 * img_bgr[:, :, 1] + 0.114 * img_bgr[:, :, 0]) / 255.0
    skin_color = detect_skin_mask(img_bgr)
    definite_non_hair_semantic = skin_raw | brows_raw | eyes_raw | ears_raw | neck_raw | clothes_raw | (skin_color & ~hair_raw)

    hair_expanded = hair_raw.copy().astype(np.uint8)
    kernel_small = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    for _ in range(40):
        dilated = cv2.dilate(hair_expanded, kernel_small)
        cand = (dilated > 0) & (hair_expanded == 0) & (~definite_non_hair_semantic) & (lum < 0.44)
        if not np.any(cand):
            break
        hair_expanded[cand] = 1

    # 2. DEFINITE_HAIR: Erode expanded hair so core has zero boundary doubt
    kernel_core = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (11, 11))
    definite_hair = cv2.erode(hair_expanded, kernel_core).astype(bool)

    # 3. UNKNOWN BAND: Dilate around hair boundary to encompass hairline and flyaways
    kernel_outer = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (25, 25))
    hair_outer = cv2.dilate(hair_expanded, kernel_outer).astype(bool)
    
    # Exclude strict non-hair (eyes, brows, center face) from hair_outer
    unknown = hair_outer & ~definite_hair & ~eyes_raw & ~brows_raw

    # 4. DEFINITE_NON_HAIR: Everything else
    definite_non_hair = ~definite_hair & ~unknown

    trimap = np.full((h, w), 0.5, dtype=np.float32)
    trimap[definite_non_hair] = 0.0
    trimap[definite_hair] = 1.0

    return trimap, definite_hair, unknown, definite_non_hair, definite_non_hair_semantic

def solve_highres_matting(img_bgr, trimap, unknown_mask, definite_hair, definite_non_hair):
    """
    High-Res Guided Matting + Color Affinity Boundary Solver
    """
    h, w = img_bgr.shape[:2]
    guide_gray = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2GRAY) / 255.0

    # Step 1: Initial rough alpha from trimap
    init_alpha = trimap.copy()

    # Step 2: High-Resolution Fast Guided Filter
    # radius=12, eps=1e-3 gives crisp hair strand preservation with smooth alpha
    alpha_guided = fast_guided_filter(guide_gray, init_alpha, radius=12, eps=1e-3, scale=2)

    # Step 3: Local Color Sampling & Color-Line Affinity in Unknown Band
    # For every pixel in unknown band, compute distance to foreground hair vs background wall
    # Sample mean FG color from definite hair near boundary
    kernel_sample = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (15, 15))
    fg_boundary_zone = cv2.dilate(definite_hair.astype(np.uint8), kernel_sample).astype(bool) & definite_hair
    bg_boundary_zone = cv2.dilate(definite_non_hair.astype(np.uint8), kernel_sample).astype(bool) & definite_non_hair

    # Foreground hair is dark/textured, background wall is neutral
    fg_mean = img_bgr[fg_boundary_zone].mean(axis=0) if np.any(fg_boundary_zone) else np.array([30.0, 30.0, 30.0])
    bg_mean = img_bgr[bg_boundary_zone].mean(axis=0) if np.any(bg_boundary_zone) else np.array([160.0, 160.0, 160.0])

    diff_fg = np.linalg.norm(img_bgr.astype(np.float32) - fg_mean, axis=2)
    diff_bg = np.linalg.norm(img_bgr.astype(np.float32) - bg_mean, axis=2)
    alpha_color = np.clip(diff_bg / (diff_fg + diff_bg + 1e-6), 0.0, 1.0)

    # Step 4: Blend Guided Alpha with Color Line Alpha in Unknown Band
    final_alpha = alpha_guided.copy()
    # In unknown band: blend guided (structure-preserving) with color-affinity
    final_alpha[unknown_mask] = 0.65 * alpha_guided[unknown_mask] + 0.35 * alpha_color[unknown_mask]

    # Enforce definite regions
    final_alpha[definite_hair] = 1.0
    final_alpha[definite_non_hair] = 0.0

    return np.clip(final_alpha, 0.0, 1.0)

def apply_semantic_protection_and_hairline_refinement(alpha, labels_full, img_bgr):
    """
    Sub-pixel Semantic Protection:
    1. Zero leakage for eyes, brows, neck, clothes, ears
    2. Sub-pixel continuous smooth hairline on forehead (cosine curve transition)
    """
    h, w = alpha.shape[:2]
    refined_alpha = alpha.copy()

    # Masks from BiSeNet
    skin_raw = (labels_full == 1) | (labels_full == 10) | (labels_full == 11) | (labels_full == 12) | (labels_full == 13)
    brows = (labels_full == 2) | (labels_full == 3)
    eyes = (labels_full == 4) | (labels_full == 5)
    ears = (labels_full == 7) | (labels_full == 8)
    neck = (labels_full == 14)
    clothes = (labels_full == 16)
    skin_color = detect_skin_mask(img_bgr)

    # Strict zero-leakage regions
    strict_block = eyes | brows | neck | clothes | ears
    refined_alpha[strict_block] = 0.0

    # Forehead Hairline Refinement:
    # Instead of hard cutoff at forehead, apply smooth transition on forehead skin boundary
    # Find boundary between hair and forehead skin
    hair_mask_binary = (refined_alpha > 0.05).astype(np.uint8)
    forehead_skin = skin_raw & skin_color & (labels_full == 1)

    # Dilate forehead skin by 2 pixels to detect immediate contact zone
    kernel_touch = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    forehead_touch = cv2.dilate(forehead_skin.astype(np.uint8), kernel_touch).astype(bool)

    # On forehead skin itself, alpha MUST be zero
    refined_alpha[forehead_skin] = 0.0

    # In immediate contact zone (1-2 pixels inside hair), soften alpha smoothly to eliminate cutout stairstepping
    touch_hair = forehead_touch & (refined_alpha > 0.0)
    refined_alpha[touch_hair] = np.clip(refined_alpha[touch_hair] * 0.75, 0.0, 1.0)

    # Smooth the whole alpha slightly with bilateral/guided to ensure sub-pixel continuity
    refined_alpha = cv2.GaussianBlur(refined_alpha, (3, 3), 0.5)
    # Re-enforce zero on strict block
    refined_alpha[strict_block] = 0.0
    refined_alpha[forehead_skin] = 0.0

    return np.clip(refined_alpha, 0.0, 1.0)

def apply_salon_rose_gold_recolor(img_bgr, alpha, intensity=0.80):
    """Render Salon Rose Gold recoloring with luminance and edge preservation"""
    orig_f = img_bgr.astype(np.float32)
    lum = (0.114 * orig_f[:, :, 0] + 0.587 * orig_f[:, :, 1] + 0.299 * orig_f[:, :, 2]) / 255.0
    lum_3d = np.expand_dims(lum, axis=2)

    # Salon Rose Gold preset: BGR(132, 138, 218)
    dye_bgr = np.array([132.0, 138.0, 218.0], dtype=np.float32)

    # Multi-band detail
    gray = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2GRAY).astype(np.float32) / 255.0
    blur_wide = cv2.GaussianBlur(gray, (17, 17), 5.0)
    blur_narrow = cv2.GaussianBlur(gray, (5, 5), 1.2)
    micro_detail = gray - blur_narrow
    micro_detail_3d = np.expand_dims(micro_detail, axis=2)

    # Recolor formula with acutance retention
    scale = np.clip(0.35 + 0.65 * lum_3d, 0.0, 1.0)
    recolor = np.clip(dye_bgr * scale + micro_detail_3d * 45.0, 0.0, 255.0)

    # Blend
    alpha_3d = np.expand_dims(alpha, axis=2) * intensity
    out = orig_f * (1.0 - alpha_3d) + recolor * alpha_3d
    return np.clip(out, 0.0, 255.0).astype(np.uint8)

def main():
    out_dir = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\p0_b_prototype"
    os.makedirs(out_dir, exist_ok=True)

    print("=== RUNNING PHASE P0-B HIGH-RES HAIR BOUNDARY MATTING PROTOTYPE ===")
    net = load_bisenet()

    test_images = [
        ("0.jpg", r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\0.jpg"),
        ("1.jpg", r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\1.jpg"),
        ("sample_portrait.jpg", r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg"),
    ]

    for img_name, img_path in test_images:
        print(f"\n--- Processing {img_name} ---")
        img_bgr = cv2.imread(img_path)
        h, w = img_bgr.shape[:2]

        t0 = time.perf_counter()
        # Stage 1: BiSeNet Multi-class semantic parsing
        labels_full = run_bisenet_multiclass(net, img_bgr)
        t1 = time.perf_counter()

        # Stage 2: Semantic Trimap Generation
        trimap, def_hair, unknown, def_non_hair, strict_non_hair = generate_semantic_trimap(labels_full, img_bgr)
        t2 = time.perf_counter()

        # Stage 3: High-Res Classical Matting Solver
        alpha_raw_matting = solve_highres_matting(img_bgr, trimap, unknown, def_hair, def_non_hair)
        t3 = time.perf_counter()

        # Stage 4: Semantic Protection & Hairline/Flyaway Refinement
        final_matte = apply_semantic_protection_and_hairline_refinement(alpha_raw_matting, labels_full, img_bgr)
        t4 = time.perf_counter()

        # Stage 5: Recolor Composite
        comp = apply_salon_rose_gold_recolor(img_bgr, final_matte, 0.80)
        t5 = time.perf_counter()

        bisenet_ms = (t1 - t0) * 1000.0
        trimap_ms = (t2 - t1) * 1000.0
        matting_ms = (t3 - t2) * 1000.0
        protect_ms = (t4 - t3) * 1000.0
        render_ms = (t5 - t4) * 1000.0
        total_ms = (t5 - t0) * 1000.0

        print(f"Timing on {w}x{h}:")
        print(f"  BiSeNet Inference:        {bisenet_ms:.1f} ms")
        print(f"  Semantic Trimap:          {trimap_ms:.1f} ms")
        print(f"  High-Res Matting Solver:  {matting_ms:.1f} ms")
        print(f"  Semantic Protection:      {protect_ms:.1f} ms")
        print(f"  Recolor Render:           {render_ms:.1f} ms")
        print(f"  TOTAL END-TO-END:         {total_ms:.1f} ms")

        # Save artifacts for primary test image (0.jpg)
        if img_name == "0.jpg":
            # 1. Trimap visualization (Definite Hair=255, Unknown=128, Definite Non-Hair=0)
            trimap_vis = (trimap * 255.0).astype(np.uint8)
            cv2.imwrite(os.path.join(out_dir, "p0_b_trimap.png"), trimap_vis)

            # 2. Final High-Res Alpha Matte
            matte_vis = (final_matte * 255.0).astype(np.uint8)
            cv2.imwrite(os.path.join(out_dir, "p0_b_alpha_highres.png"), matte_vis)

            # 3. Recolor Composite
            cv2.imwrite(os.path.join(out_dir, "p0_b_composite_rose_gold.png"), comp)

            # 4. Zoom Comparisons (Load Baseline A from P0-A for direct side-by-side)
            base_comp = cv2.imread(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\p0_test\06_current_composite.png")
            base_alpha = cv2.imread(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\p0_test\03_current_alpha.png", cv2.IMREAD_GRAYSCALE) / 255.0

            def label(im, txt):
                res = im.copy()
                cv2.putText(res, txt, (10, 25), cv2.FONT_HERSHEY_SIMPLEX, 0.65, (0, 0, 0), 3)
                cv2.putText(res, txt, (10, 25), cv2.FONT_HERSHEY_SIMPLEX, 0.65, (255, 255, 255), 2)
                return res

            # Crop 1: Forehead Hairline (y: 20%..38%, x: 38%..62%)
            hy1, hy2, hx1, hx2 = int(0.20 * h), int(0.38 * h), int(0.38 * w), int(0.62 * w)
            crop_orig_hl = img_bgr[hy1:hy2, hx1:hx2]
            crop_base_hl = base_comp[hy1:hy2, hx1:hx2]
            crop_p0b_hl = comp[hy1:hy2, hx1:hx2]
            crop_alpha_hl = cv2.cvtColor((final_matte[hy1:hy2, hx1:hx2] * 255).astype(np.uint8), cv2.COLOR_GRAY2BGR)

            grid_hl = np.hstack([
                label(crop_orig_hl, "Original"),
                label(crop_base_hl, "Baseline A (Coarse)"),
                label(crop_p0b_hl, "P0-B High-Res Matte"),
                label(crop_alpha_hl, "P0-B Alpha Channel")
            ])
            cv2.imwrite(os.path.join(out_dir, "p0_b_hairline_zoom.png"), grid_hl)

            # Crop 2: Left Outer Curls & Flyaways (y: 12%..38%, x: 5%..35%)
            fy1, fy2, fx1, fx2 = int(0.12 * h), int(0.38 * h), int(0.05 * w), int(0.35 * w)
            crop_orig_fa = img_bgr[fy1:fy2, fx1:fx2]
            crop_base_fa = base_comp[fy1:fy2, fx1:fx2]
            crop_p0b_fa = comp[fy1:fy2, fx1:fx2]
            crop_alpha_fa = cv2.cvtColor((final_matte[fy1:fy2, fx1:fx2] * 255).astype(np.uint8), cv2.COLOR_GRAY2BGR)

            grid_fa = np.hstack([
                label(crop_orig_fa, "Original"),
                label(crop_base_fa, "Baseline A (Coarse)"),
                label(crop_p0b_fa, "P0-B High-Res Matte"),
                label(crop_alpha_fa, "P0-B Alpha Channel")
            ])
            cv2.imwrite(os.path.join(out_dir, "p0_b_left_curls_zoom.png"), grid_fa)

            # Crop 3: Ear Boundary & Buzz Cut (y: 28%..52%, x: 68%..88%)
            ey1, ey2, ex1, ex2 = int(0.28 * h), int(0.52 * h), int(0.68 * w), int(0.88 * w)
            crop_orig_eb = img_bgr[ey1:ey2, ex1:ex2]
            crop_base_eb = base_comp[ey1:ey2, ex1:ex2]
            crop_p0b_eb = comp[ey1:ey2, ex1:ex2]
            crop_alpha_eb = cv2.cvtColor((final_matte[ey1:ey2, ex1:ex2] * 255).astype(np.uint8), cv2.COLOR_GRAY2BGR)

            grid_eb = np.hstack([
                label(crop_orig_eb, "Original"),
                label(crop_base_eb, "Baseline A (Coarse)"),
                label(crop_p0b_eb, "P0-B High-Res Matte"),
                label(crop_alpha_eb, "P0-B Alpha Channel")
            ])
            cv2.imwrite(os.path.join(out_dir, "p0_b_ear_zoom.png"), grid_eb)

            # 10-Region Evaluation Comparison
            regions = [
                ('Crown', int(0.02*h), int(0.18*h), int(0.35*w), int(0.65*w), True),
                ('Forehead Hairline', int(0.24*h), int(0.32*h), int(0.42*w), int(0.58*w), False),
                ('Left Curls', int(0.15*h), int(0.35*h), int(0.10*w), int(0.32*w), True),
                ('Right Hair (Buzz)', int(0.20*h), int(0.38*h), int(0.68*w), int(0.85*w), True),
                ('Flyaways', int(0.18*h), int(0.30*h), int(0.04*w), int(0.12*w), True),
                ('Ear Boundary', int(0.40*h), int(0.52*h), int(0.70*w), int(0.82*w), False),
                ('Face Boundary', int(0.35*h), int(0.60*h), int(0.35*w), int(0.65*w), False),
                ('Neck', int(0.65*h), int(0.80*h), int(0.40*w), int(0.60*w), False),
                ('Clothes', int(0.82*h), int(0.98*h), int(0.20*w), int(0.80*w), False),
                ('Background', int(0.02*h), int(0.30*h), int(0.02*w), int(0.20*w), False),
            ]

            print("\n=== QUANTITATIVE REGION COMPARISON: BASELINE vs P0-B PROTOTYPE ===")
            header = '%-20s | %-12s | %-12s | %-12s | %-12s' % ('Region', 'Target', 'Baseline A', 'P0-B Matte', 'Status')
            print(header)
            print('-' * len(header))
            for name, y1, y2, x1, x2, is_hair in regions:
                t_str = 'HAIR (1.0)' if is_hair else 'NON-HAIR (0)'
                val_base = base_alpha[y1:y2, x1:x2].mean()
                val_p0b = final_matte[y1:y2, x1:x2].mean()
                status = "PASS" if (is_hair and val_p0b >= 0.5) or (not is_hair and val_p0b <= 0.05) else "CHECK"
                print('%-20s | %-12s | %-12.4f | %-12.4f | %-12s' % (name, t_str, val_base, val_p0b, status))

if __name__ == "__main__":
    main()

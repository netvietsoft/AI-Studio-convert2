import os
import sys
import time
import psutil
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

def load_hair_matting_mobile():
    param = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\models\ncnn\hair_matting_mobile.param"
    bin_f = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\models\ncnn\hair_matting_mobile.bin"
    net = ncnn.Net()
    net.opt.use_vulkan_compute = False
    net.opt.num_threads = 4
    net.load_param(param)
    net.load_model(bin_f)
    return net

def is_skin_pixel(r, g, b):
    if r <= 45 or g <= 28 or b <= 15:
        return False
    y = 0.299 * r + 0.587 * g + 0.114 * b
    cr = (r - y) * 0.713 + 128.0
    cb = (b - y) * 0.564 + 128.0
    if 130.0 <= cr <= 175.0 and 77.0 <= cb <= 130.0 and r > b:
        return True
    if r > g >= b and (r - g) >= 5 and (r - b) >= 10:
        return True
    return False

def run_bisenet(net, img_bgr):
    h, w = img_bgr.shape[:2]
    t0 = time.perf_counter()
    resized = cv2.resize(img_bgr, (512, 512))
    in_mat = ncnn.Mat.from_pixels(resized, ncnn.Mat.PixelType.PIXEL_BGR2RGB, 512, 512)
    in_mat.substract_mean_normalize([123.675, 116.28, 103.53], [1.0/58.395, 1.0/57.12, 1.0/57.375])
    t1 = time.perf_counter()

    ex = net.create_extractor()
    ex.input("in0", in_mat)
    out_mat = ncnn.Mat()
    ex.extract("out0", out_mat)
    t2 = time.perf_counter()

    out_arr = np.array(out_mat) # (19, 512, 512)
    labels = np.argmax(out_arr, axis=0).astype(np.uint8)
    t3 = time.perf_counter()

    pre_ms = (t1 - t0) * 1000.0
    inf_ms = (t2 - t1) * 1000.0
    post_ms = (t3 - t2) * 1000.0
    return labels, pre_ms, inf_ms, post_ms

def run_current_pipeline(bisenet_labels, img_bgr):
    h, w = img_bgr.shape[:2]
    t0 = time.perf_counter()
    hair_cls = (bisenet_labels == 17).astype(np.float32)
    skin_cls = (bisenet_labels == 1)

    # Replicate C++ morphological propagation
    img_512 = cv2.resize(img_bgr, (512, 512))
    lum_512 = (0.299 * img_512[:, :, 2] + 0.587 * img_512[:, :, 1] + 0.114 * img_512[:, :, 0]) / 255.0

    mask = hair_cls.copy()
    # Grow into dark low-lum regions not in skin
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    for _ in range(35):
        dilated = cv2.dilate(mask, kernel)
        cand = (dilated > 0) & (mask == 0) & (~skin_cls) & (lum_512 < 0.42)
        if not np.any(cand):
            break
        mask[cand] = 1.0

    # Forehead skin barrier
    mask[skin_cls] = 0.0

    # Bilinear upscale with feather
    alpha_full = cv2.resize(mask, (w, h), interpolation=cv2.INTER_LINEAR)
    alpha_full = cv2.GaussianBlur(alpha_full, (5, 5), 1.0)
    t1 = time.perf_counter()
    return alpha_full, (t1 - t0) * 1000.0

def run_matting_mobile(net, img_bgr):
    h, w = img_bgr.shape[:2]
    t0 = time.perf_counter()
    resized = cv2.resize(img_bgr, (512, 512))
    in_mat = ncnn.Mat.from_pixels(resized, ncnn.Mat.PixelType.PIXEL_BGR2RGB, 512, 512)
    in_mat.substract_mean_normalize([127.5, 127.5, 127.5], [1.0/127.5, 1.0/127.5, 1.0/127.5])
    t1 = time.perf_counter()

    ex = net.create_extractor()
    ex.input("data", in_mat)
    out_mat = ncnn.Mat()
    ex.extract("alpha_mask", out_mat)
    t2 = time.perf_counter()

    out_arr = np.array(out_mat).squeeze() # (512, 512)
    alpha_full = cv2.resize(out_arr, (w, h), interpolation=cv2.INTER_LINEAR)
    t3 = time.perf_counter()

    pre_ms = (t1 - t0) * 1000.0
    inf_ms = (t2 - t1) * 1000.0
    post_ms = (t3 - t2) * 1000.0
    return alpha_full, pre_ms, inf_ms, post_ms

def run_hybrid_pipeline(current_alpha, matting_raw_alpha, bisenet_labels, img_bgr):
    h, w = img_bgr.shape[:2]
    # Core mask from BiSeNet (eroded)
    hair_cls = (bisenet_labels == 17).astype(np.uint8)
    hair_full = cv2.resize(hair_cls, (w, h), interpolation=cv2.INTER_NEAREST)
    
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (15, 15))
    core_hair = cv2.erode(hair_full, kernel).astype(np.float32)
    
    # Outer bound
    kernel_wide = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (35, 35))
    outer_hair = cv2.dilate(hair_full, kernel_wide).astype(np.float32)
    transition = (outer_hair - core_hair).clip(0.0, 1.0)
    
    # In core, use current high-confidence alpha; in transition, modulate by matting_raw
    # Note: since matting_raw is ~0.4984 everywhere, this test will empirically prove what happens
    hybrid = core_hair * current_alpha + transition * (current_alpha * 0.5 + matting_raw_alpha * 0.5)
    hybrid = np.clip(hybrid, 0.0, 1.0)
    return hybrid

def apply_rose_gold_dye(img_bgr, alpha, intensity=0.80):
    # Rose Gold salon preset: RGB(218, 138, 132) -> BGR(132, 138, 218)
    dye_bgr = np.array([132.0, 138.0, 218.0], dtype=np.float32)
    orig_f = img_bgr.astype(np.float32)
    
    # Luminance of original
    lum = (0.114 * orig_f[:, :, 0] + 0.587 * orig_f[:, :, 1] + 0.299 * orig_f[:, :, 2]) / 255.0
    lum = np.expand_dims(lum, axis=2)
    
    # Recolor with luminance preservation
    recolor = dye_bgr * (lum * 0.85 + 0.15)
    recolor = np.clip(recolor, 0.0, 255.0)
    
    alpha_3d = np.expand_dims(alpha, axis=2) * intensity
    composite = orig_f * (1.0 - alpha_3d) + recolor * alpha_3d
    return np.clip(composite, 0.0, 255.0).astype(np.uint8)

def main():
    out_dir = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\p0_test"
    os.makedirs(out_dir, exist_ok=True)
    
    print("Loading models for Characterization...")
    bisenet_net = load_bisenet()
    matting_net = load_hair_matting_mobile()
    
    test_images = [
        ("0.jpg", r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\0.jpg"),
        ("1.jpg", r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\1.jpg"),
        ("sample_portrait.jpg", r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg"),
    ]
    
    # Process primary test image: 0.jpg
    prim_name, prim_path = test_images[0]
    orig_img = cv2.imread(prim_path)
    h, w = orig_img.shape[:2]
    print(f"Primary Image: {prim_name}, Resolution: {w}x{h}")
    
    # 01_original.png
    cv2.imwrite(os.path.join(out_dir, "01_original.png"), orig_img)
    
    # Run BiSeNet
    bisenet_labels, b_pre, b_inf, b_post = run_bisenet(bisenet_net, orig_img)
    
    # 02_bisenet_mask.png
    hair_mask_raw = (bisenet_labels == 17).astype(np.uint8) * 255
    hair_mask_full = cv2.resize(hair_mask_raw, (w, h), interpolation=cv2.INTER_NEAREST)
    cv2.imwrite(os.path.join(out_dir, "02_bisenet_mask.png"), hair_mask_full)
    
    # Pipeline A: Current
    current_alpha, curr_post_ms = run_current_pipeline(bisenet_labels, orig_img)
    cv2.imwrite(os.path.join(out_dir, "03_current_alpha.png"), (current_alpha * 255.0).astype(np.uint8))
    
    # Pipeline B: Matting Model Direct
    matting_raw_alpha, m_pre, m_inf, m_post = run_matting_mobile(matting_net, orig_img)
    cv2.imwrite(os.path.join(out_dir, "04_matting_raw_alpha.png"), (matting_raw_alpha * 255.0).astype(np.uint8))
    
    # Pipeline C: Hybrid
    hybrid_alpha = run_hybrid_pipeline(current_alpha, matting_raw_alpha, bisenet_labels, orig_img)
    cv2.imwrite(os.path.join(out_dir, "05_hybrid_alpha.png"), (hybrid_alpha * 255.0).astype(np.uint8))
    
    # Composites (Rose Gold 80%)
    curr_comp = apply_rose_gold_dye(orig_img, current_alpha, 0.80)
    cv2.imwrite(os.path.join(out_dir, "06_current_composite.png"), curr_comp)
    
    matt_comp = apply_rose_gold_dye(orig_img, matting_raw_alpha, 0.80)
    cv2.imwrite(os.path.join(out_dir, "07_matting_composite.png"), matt_comp)
    
    hybr_comp = apply_rose_gold_dye(orig_img, hybrid_alpha, 0.80)
    cv2.imwrite(os.path.join(out_dir, "08_hybrid_composite.png"), hybr_comp)
    
    # 09_alpha_diff.png (Difference between Current and Matting)
    diff = np.abs(current_alpha - matting_raw_alpha)
    diff_vis = (diff * 255.0).astype(np.uint8)
    diff_color = cv2.applyColorMap(diff_vis, cv2.COLORMAP_JET)
    cv2.imwrite(os.path.join(out_dir, "09_alpha_diff.png"), diff_color)
    
    # 10_hairline_crop_comparison.png (Forehead center crop: y: 200..450, x: 380..580)
    # Scaled to 0.jpg resolution 960x1280
    hy1, hy2, hx1, hx2 = int(0.20 * h), int(0.38 * h), int(0.38 * w), int(0.62 * w)
    crop_orig_hl = orig_img[hy1:hy2, hx1:hx2]
    crop_curr_hl = curr_comp[hy1:hy2, hx1:hx2]
    crop_matt_hl = matt_comp[hy1:hy2, hx1:hx2]
    crop_hybr_hl = hybr_comp[hy1:hy2, hx1:hx2]
    
    def add_label(img, text):
        out = img.copy()
        cv2.putText(out, text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 0), 3)
        cv2.putText(out, text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)
        return out
    
    hl_grid = np.hstack([
        add_label(crop_orig_hl, "Original"),
        add_label(crop_curr_hl, "A: Current"),
        add_label(crop_matt_hl, "B: Matting Direct"),
        add_label(crop_hybr_hl, "C: Hybrid"),
    ])
    cv2.imwrite(os.path.join(out_dir, "10_hairline_crop_comparison.png"), hl_grid)
    
    # 11_flyaway_crop_comparison.png (Left Outer Curls: y: 150..450, x: 80..320)
    fy1, fy2, fx1, fx2 = int(0.12 * h), int(0.38 * h), int(0.08 * w), int(0.35 * w)
    crop_orig_fa = orig_img[fy1:fy2, fx1:fx2]
    crop_curr_fa = curr_comp[fy1:fy2, fx1:fx2]
    crop_matt_fa = matt_comp[fy1:fy2, fx1:fx2]
    crop_hybr_fa = hybr_comp[fy1:fy2, fx1:fx2]
    
    fa_grid = np.hstack([
        add_label(crop_orig_fa, "Original"),
        add_label(crop_curr_fa, "A: Current"),
        add_label(crop_matt_fa, "B: Matting Direct"),
        add_label(crop_hybr_fa, "C: Hybrid"),
    ])
    cv2.imwrite(os.path.join(out_dir, "11_flyaway_crop_comparison.png"), fa_grid)
    
    print("Exported all 11 required PNG artifacts successfully!")
    
    # Benchmark on all 3 images
    print("\n=== BENCHMARK SUITE ===")
    process = psutil.Process(os.getpid())
    
    for name, path in test_images:
        im = cv2.imread(path)
        ih, iw = im.shape[:2]
        
        # BiSeNet
        _, b_p, b_i, b_po = run_bisenet(bisenet_net, im)
        b_tot = b_p + b_i + b_po
        
        # Matting Mobile
        _, m_p, m_i, m_po = run_matting_mobile(matting_net, im)
        m_tot = m_p + m_i + m_po
        
        mem_mb = process.memory_info().rss / (1024 * 1024)
        print(f"Image: {name} ({iw}x{ih})")
        print(f"  BiSeNet 19-class:    pre={b_p:.1f}ms, inf={b_i:.1f}ms, post={b_po:.1f}ms, total={b_tot:.1f}ms")
        print(f"  hair_matting_mobile: pre={m_p:.1f}ms, inf={m_i:.1f}ms, post={m_po:.1f}ms, total={m_tot:.1f}ms")
        print(f"  Peak RSS RAM: {mem_mb:.1f} MB")
        
    param_size = os.path.getsize(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\models\ncnn\hair_matting_mobile.param")
    bin_size = os.path.getsize(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\models\ncnn\hair_matting_mobile.bin")
    bise_bin_size = os.path.getsize(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\lib-core-graphics\src\main\assets\models\bisenet_face_19.bin")
    
    print("\n=== MODEL SIZES ON DISK ===")
    print(f"  hair_matting_mobile.param: {param_size} bytes")
    print(f"  hair_matting_mobile.bin:   {bin_size} bytes ({bin_size/(1024*1024):.2f} MB)")
    print(f"  bisenet_face_19.bin:       {bise_bin_size} bytes ({bise_bin_size/(1024*1024):.2f} MB)")

if __name__ == "__main__":
    main()

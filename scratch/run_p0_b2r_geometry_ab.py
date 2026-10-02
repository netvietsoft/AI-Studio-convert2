import os
import sys
import cv2
import numpy as np
import ncnn

sys.path.append("scratch")
from run_p0_b2_full_suite import run_p0_b2_pipeline, apply_salon_dye, label_box, load_bisenet

net = load_bisenet()

def run_mode_a(im):
    h, w = im.shape[:2]
    resized = cv2.resize(im, (512, 512))
    in_mat = ncnn.Mat.from_pixels(resized, ncnn.Mat.PixelType.PIXEL_BGR2RGB, 512, 512)
    in_mat.substract_mean_normalize([123.675, 116.28, 103.53], [1.0/58.395, 1.0/57.12, 1.0/57.375])
    ex = net.create_extractor()
    ex.input("in0", in_mat)
    out_mat = ncnn.Mat()
    ex.extract("out0", out_mat)
    l512 = np.argmax(np.array(out_mat), axis=0).astype(np.uint8)
    l_full = cv2.resize(l512, (w, h), interpolation=cv2.INTER_NEAREST)
    return resized, l512, l_full

def run_mode_b(im):
    h, w = im.shape[:2]
    scale = min(512.0 / w, 512.0 / h)
    nw = int(round(w * scale))
    nh = int(round(h * scale))
    im_scaled = cv2.resize(im, (nw, nh))
    pad_x = (512 - nw) // 2
    pad_y = (512 - nh) // 2

    canvas = np.zeros((512, 512, 3), dtype=np.uint8)
    canvas[pad_y:pad_y+nh, pad_x:pad_x+nw] = im_scaled

    in_mat = ncnn.Mat.from_pixels(canvas, ncnn.Mat.PixelType.PIXEL_BGR2RGB, 512, 512)
    in_mat.substract_mean_normalize([123.675, 116.28, 103.53], [1.0/58.395, 1.0/57.12, 1.0/57.375])
    ex = net.create_extractor()
    ex.input("in0", in_mat)
    out_mat = ncnn.Mat()
    ex.extract("out0", out_mat)
    l512 = np.argmax(np.array(out_mat), axis=0).astype(np.uint8)

    unpadded = l512[pad_y:pad_y+nh, pad_x:pad_x+nw]
    l_full = cv2.resize(unpadded, (w, h), interpolation=cv2.INTER_NEAREST)
    return canvas, l512, l_full

def run_mode_c(im):
    h, w = im.shape[:2]
    canvas_b, l512_b, l_full_b = run_mode_b(im)

    face_mask = (l_full_b >= 1) & (l_full_b <= 13)
    if np.sum(face_mask) < 50:
        return canvas_b, l512_b, l_full_b, im

    pts = np.where(face_mask)
    y_min, y_max = np.min(pts[0]), np.max(pts[0])
    x_min, x_max = np.min(pts[1]), np.max(pts[1])
    fh = y_max - y_min
    fw = x_max - x_min

    roi_y1 = max(0, int(y_min - fh * 0.9))
    roi_y2 = min(h, int(y_max + fh * 0.6))
    roi_x1 = max(0, int(x_min - fw * 0.6))
    roi_x2 = min(w, int(x_max + fw * 0.6))

    roi_im = im[roi_y1:roi_y2, roi_x1:roi_x2]
    rw, rh = roi_im.shape[1], roi_im.shape[0]
    r_scale = min(512.0 / rw, 512.0 / rh)
    rnw, rnh = int(round(rw * r_scale)), int(round(rh * r_scale))
    r_im_scaled = cv2.resize(roi_im, (rnw, rnh))
    r_pad_x = (512 - rnw) // 2
    r_pad_y = (512 - rnh) // 2

    r_canvas = np.zeros((512, 512, 3), dtype=np.uint8)
    r_canvas[r_pad_y:r_pad_y+rnh, r_pad_x:r_pad_x+rnw] = r_im_scaled

    in_mat = ncnn.Mat.from_pixels(r_canvas, ncnn.Mat.PixelType.PIXEL_BGR2RGB, 512, 512)
    in_mat.substract_mean_normalize([123.675, 116.28, 103.53], [1.0/58.395, 1.0/57.12, 1.0/57.375])
    ex = net.create_extractor()
    ex.input("in0", in_mat)
    out_mat = ncnn.Mat()
    ex.extract("out0", out_mat)
    r_l512 = np.argmax(np.array(out_mat), axis=0).astype(np.uint8)

    r_unpadded = r_l512[r_pad_y:r_pad_y+rnh, r_pad_x:r_pad_x+rnw]
    roi_labels = cv2.resize(r_unpadded, (rw, rh), interpolation=cv2.INTER_NEAREST)

    out = np.zeros((h, w), dtype=np.uint8)
    out[roi_y1:roi_y2, roi_x1:roi_x2] = roi_labels
    return r_canvas, r_l512, out, roi_im

def colorize_labels(labels):
    h, w = labels.shape[:2]
    vis = np.zeros((h, w, 3), dtype=np.uint8)
    vis[labels == 17] = [255, 0, 0]   # Blue Hair
    vis[labels == 1]  = [0, 255, 255] # Yellow Skin
    vis[labels == 18] = [0, 0, 255]   # Red Class18
    vis[(labels >= 2) & (labels <= 13) & (labels != 1)] = [0, 255, 0] # Green Face
    return vis

def process_geometry_ab():
    out_root = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\p0_b2r_validation\geometry_ab"
    samples = [
        ("holdout_07", r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_11_2026-09-25_21-30-16.jpg"),
        ("edge_05", r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_6_2026-09-25_21-30-16.jpg"),
        ("edge_06", r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_8_2026-09-25_21-30-16.jpg"),
    ]

    for sname, spath in samples:
        s_dir = os.path.join(out_root, sname)
        os.makedirs(s_dir, exist_ok=True)

        with open(spath, "rb") as f:
            im = cv2.imdecode(np.frombuffer(f.read(), dtype=np.uint8), cv2.IMREAD_COLOR)

        h, w = im.shape[:2]

        # Mode A
        in_a, l512_a, l_full_a = run_mode_a(im)
        alpha_a, _, _, _, _ = run_p0_b2_pipeline(l_full_a, im)
        comp_a = apply_salon_dye(im, alpha_a, 0.80)

        # Mode B
        in_b, l512_b, l_full_b = run_mode_b(im)
        alpha_b, _, _, _, _ = run_p0_b2_pipeline(l_full_b, im)
        comp_b = apply_salon_dye(im, alpha_b, 0.80)

        # Mode C
        in_c, l512_c, l_full_c, roi_im = run_mode_c(im)
        alpha_c, _, _, _, _ = run_p0_b2_pipeline(l_full_c, im)
        comp_c = apply_salon_dye(im, alpha_c, 0.80)

        # Artifacts per Section 27:
        cv2.imwrite(os.path.join(s_dir, "01_original.png"), im)
        cv2.imwrite(os.path.join(s_dir, "02_mode_A_input.png"), in_a)
        cv2.imwrite(os.path.join(s_dir, "03_mode_A_semantic.png"), colorize_labels(l512_a))
        cv2.imwrite(os.path.join(s_dir, "04_mode_A_alpha.png"), (alpha_a * 255).astype(np.uint8))

        cv2.imwrite(os.path.join(s_dir, "05_mode_B_letterbox_input.png"), in_b)
        cv2.imwrite(os.path.join(s_dir, "06_mode_B_semantic.png"), colorize_labels(l512_b))
        cv2.imwrite(os.path.join(s_dir, "07_mode_B_inverse_mapped.png"), colorize_labels(l_full_b))
        cv2.imwrite(os.path.join(s_dir, "08_mode_B_alpha.png"), (alpha_b * 255).astype(np.uint8))

        cv2.imwrite(os.path.join(s_dir, "09_mode_C_roi.png"), roi_im)
        cv2.imwrite(os.path.join(s_dir, "10_mode_C_semantic.png"), colorize_labels(l512_c))
        cv2.imwrite(os.path.join(s_dir, "11_mode_C_inverse_mapped.png"), colorize_labels(l_full_c))
        cv2.imwrite(os.path.join(s_dir, "12_mode_C_alpha.png"), (alpha_c * 255).astype(np.uint8))

        # Composite comparison
        comp_strip = np.hstack([
            label_box(im, "Original"),
            label_box(comp_a, "Mode A (Anisotropic)"),
            label_box(comp_b, "Mode B (Letterbox)"),
            label_box(comp_c, "Mode C (Subject ROI)"),
        ])
        cv2.imwrite(os.path.join(s_dir, "13_A_B_C_composite.png"), comp_strip)

        # Difference maps
        diff_18 = np.abs((l_full_a == 18).astype(np.float32) - (l_full_c == 18).astype(np.float32))
        cv2.imwrite(os.path.join(s_dir, "14_class18_difference.png"), cv2.applyColorMap((diff_18 * 255).astype(np.uint8), cv2.COLORMAP_JET))

        bg_diff = np.abs(alpha_a - alpha_c)
        cv2.imwrite(os.path.join(s_dir, "15_background_leak_difference.png"), cv2.applyColorMap((bg_diff * 255).astype(np.uint8), cv2.COLORMAP_JET))

        bg_a = float(np.mean(alpha_a[l_full_a == 0]) * 100.0)
        bg_b = float(np.mean(alpha_b[l_full_b == 0]) * 100.0)
        bg_c = float(np.mean(alpha_c[l_full_c == 0]) * 100.0)
        print(f"[{sname}] Background Leakage: Mode A={bg_a:.2f}% | Mode B={bg_b:.2f}% | Mode C={bg_c:.2f}%")

if __name__ == "__main__":
    process_geometry_ab()

import os
import sys
import cv2
import numpy as np
import ncnn

sys.path.append("scratch")
from run_p0_b2_full_suite import run_p0_b2_pipeline, run_bisenet_multiclass, apply_salon_dye, label_box, load_bisenet

net = load_bisenet()

def run_exposure_recovery_pipeline(labels, im):
    h, w = im.shape[:2]
    alpha, hoe, acc, f1_ev, guard_ev = run_p0_b2_pipeline(labels, im)

    # R1: High-Exposure Hair Recovery
    # For high-exposure hair where hair strands touch forehead skin:
    # If a pixel in Class 17 has strong hair texture (t_tex > 0.05),
    # retain high alpha (> 0.82) rather than over-attenuated by forehead touch
    hair_c17 = (labels == 17)
    forehead_touch = cv2.dilate((labels == 1).astype(np.uint8), cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))) > 0

    touch_c17 = forehead_touch & hair_c17
    preserve_touch = touch_c17 & (f1_ev["t_tex"] > 0.05)
    alpha[preserve_touch] = np.maximum(alpha[preserve_touch], 0.85)

    # Strict skin zero: Forehead skin itself is NEVER modified
    alpha[labels == 1] = 0.0

    return np.clip(alpha, 0.0, 1.0), hoe, acc, f1_ev, guard_ev

def diagnose_sample_26():
    out_dir = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\p0_b2r_validation\exposure\sample_26"
    os.makedirs(out_dir, exist_ok=True)

    spath = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\face_live_88.png"
    with open(spath, "rb") as f:
        im = cv2.imdecode(np.frombuffer(f.read(), dtype=np.uint8), cv2.IMREAD_COLOR)

    h, w = im.shape[:2]
    labels = run_bisenet_multiclass(net, im)

    alpha_p0b2, _, _, f1_ev, guard_ev = run_p0_b2_pipeline(labels, im)
    alpha_r1, hoe_r1, acc_r1, f1_r1, guard_r1 = run_exposure_recovery_pipeline(labels, im)

    # 1. 01_original.png
    cv2.imwrite(os.path.join(out_dir, "01_original.png"), im)

    # 2. 02_semantic_overlay.png
    sem_vis = im.copy()
    sem_vis[labels == 17] = (sem_vis[labels == 17] * 0.4 + np.array([255, 0, 0]) * 0.6).astype(np.uint8)
    sem_vis[labels == 1]  = (sem_vis[labels == 1] * 0.7 + np.array([0, 255, 255]) * 0.3).astype(np.uint8)
    cv2.imwrite(os.path.join(out_dir, "02_semantic_overlay.png"), sem_vis)

    # 3. 03_hair_seed.png
    seed_vis = im.copy()
    seed_vis[f1_ev["core_boost"]] = [0, 255, 0]
    cv2.imwrite(os.path.join(out_dir, "03_hair_seed.png"), seed_vis)

    # 4. 04_candidate_probability.png
    cv2.imwrite(os.path.join(out_dir, "04_candidate_probability.png"), (f1_ev["p_dark_hair"] * 255).astype(np.uint8))

    # 5. 05_skin_protection.png
    skin_vis = np.zeros((h, w, 3), dtype=np.uint8)
    skin_vis[labels == 1] = [0, 255, 255]
    cv2.imwrite(os.path.join(out_dir, "05_skin_protection.png"), skin_vis)

    # 6. 06_connectivity_map.png
    cv2.imwrite(os.path.join(out_dir, "06_connectivity_map.png"), (f1_ev["c_conn"] * 255).astype(np.uint8))

    # 7. 07_texture_map.png
    cv2.imwrite(os.path.join(out_dir, "07_texture_map.png"), (f1_ev["t_tex"] * 255).astype(np.uint8))

    # 8. 08_alpha_p0_b2.png
    cv2.imwrite(os.path.join(out_dir, "08_alpha_p0_b2.png"), (alpha_p0b2 * 255).astype(np.uint8))

    # Core definition:
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (7, 7))
    dilated = cv2.dilate((labels == 17).astype(np.uint8), kernel, iterations=2)
    alpha_base = cv2.GaussianBlur(dilated.astype(np.float32), (15, 15), 5.0)
    core_ref = (alpha_base > 0.90) | (labels == 17)

    # 9. 09_failure_core_map.png
    fail_map = im.copy()
    fail_map[core_ref & (alpha_p0b2 <= 0.75)] = [0, 0, 255] # Red: lost core in P0-B.2
    fail_map[core_ref & (alpha_r1 > 0.75)] = [0, 255, 0]    # Green: recovered in R1
    cv2.imwrite(os.path.join(out_dir, "09_failure_core_map.png"), fail_map)

    # 10. 10_forehead_hairline_crop.png
    hair_pts = np.where(labels == 17)
    cy = int(np.mean(hair_pts[0]))
    cx = int(np.mean(hair_pts[1]))
    ch, cw = int(h * 0.35), int(w * 0.45)
    y1, y2 = max(0, cy - ch//2), min(h, cy + ch//2)
    x1, x2 = max(0, cx - cw//2), min(w, cx + cw//2)

    comp_b2 = apply_salon_dye(im, alpha_p0b2, 0.80)
    comp_r1 = apply_salon_dye(im, alpha_r1, 0.80)

    crop_strip = np.hstack([
        label_box(im[y1:y2, x1:x2], "Original"),
        label_box(comp_b2[y1:y2, x1:x2], "P0-B.2 (73.3%)"),
        label_box(comp_r1[y1:y2, x1:x2], "P0-B.2R (79.1%)"),
    ])
    cv2.imwrite(os.path.join(out_dir, "10_forehead_hairline_crop.png"), crop_strip)

    core_b2 = float(np.mean(alpha_p0b2[core_ref] > 0.75) * 100.0)
    core_r1 = float(np.mean(alpha_r1[core_ref] > 0.75) * 100.0)
    skin_leak = float(np.mean(alpha_r1[labels == 1]) * 100.0)
    print(f"sample_26: Core Pres P0-B.2={core_b2:.2f}% -> P0-B.2R={core_r1:.2f}% | Skin Leakage={skin_leak:.3f}%")

if __name__ == "__main__":
    diagnose_sample_26()

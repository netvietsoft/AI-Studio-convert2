import os
import sys
import time
import math
import shutil
import cv2
import numpy as np
import ncnn

# ======================================================================
# PHASE P0-C — PRODUCTION REGRESSION & PARITY TEST HARNESS
# ======================================================================

def load_bisenet():
    param = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\lib-core-graphics\src\main\assets\models\bisenet_face_19.param"
    bin_f = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\lib-core-graphics\src\main\assets\models\bisenet_face_19.bin"
    net = ncnn.Net()
    net.opt.use_vulkan_compute = False
    net.opt.num_threads = 4
    net.load_param(param)
    net.load_model(bin_f)
    return net

def run_bisenet_production_adaptive(net, img_bgr):
    """
    Production Adaptive Preprocessing Geometry (R2):
    Matches BiSeNetFaceParser::parseFace19Adaptive exactly.
    tau_aspect = 1.45. If maxAspect > 1.45, uses Mode B aspect-preserving letterboxing.
    """
    h, w = img_bgr.shape[:2]
    aspect = max(float(h) / w, float(w) / h)

    if aspect > 1.45:
        # Mode B: Aspect-Preserving Letterbox with neutral gray (128) padding
        scale = min(512.0 / w, 512.0 / h)
        nw = max(1, int(round(w * scale)))
        nh = max(1, int(round(h * scale)))
        scaled = cv2.resize(img_bgr, (nw, nh), interpolation=cv2.INTER_LINEAR)

        pad_x = (512 - nw) // 2
        pad_y = (512 - nh) // 2

        padded = np.full((512, 512, 3), 128, dtype=np.uint8)
        padded[pad_y:pad_y + nh, pad_x:pad_x + nw] = scaled

        in_mat = ncnn.Mat.from_pixels(padded, ncnn.Mat.PixelType.PIXEL_BGR2RGB, 512, 512)
        in_mat.substract_mean_normalize([123.675, 116.28, 103.53], [1.0/58.395, 1.0/57.12, 1.0/57.375])

        ex = net.create_extractor()
        ex.input("in0", in_mat)
        out_mat = ncnn.Mat()
        ex.extract("out0", out_mat)

        out_arr = np.array(out_mat)
        labels_512 = np.argmax(out_arr, axis=0).astype(np.uint8)

        # Unpad and resize back to original (w, h)
        cropped_labels = labels_512[pad_y:pad_y + nh, pad_x:pad_x + nw]
        labels_full = cv2.resize(cropped_labels, (w, h), interpolation=cv2.INTER_NEAREST)
        return labels_full, labels_512, True
    else:
        # Standard Direct Resize
        resized = cv2.resize(img_bgr, (512, 512), interpolation=cv2.INTER_LINEAR)
        in_mat = ncnn.Mat.from_pixels(resized, ncnn.Mat.PixelType.PIXEL_BGR2RGB, 512, 512)
        in_mat.substract_mean_normalize([123.675, 116.28, 103.53], [1.0/58.395, 1.0/57.12, 1.0/57.375])

        ex = net.create_extractor()
        ex.input("in0", in_mat)
        out_mat = ncnn.Mat()
        ex.extract("out0", out_mat)

        out_arr = np.array(out_mat)
        labels_512 = np.argmax(out_arr, axis=0).astype(np.uint8)
        labels_full = cv2.resize(labels_512, (w, h), interpolation=cv2.INTER_NEAREST)
        return labels_full, labels_512, False

def fast_guided_filter_native(guide_gray, src_p, radius=12, eps=1e-3, scale=2):
    """
    Native Fast Guided Filter matching HairMattingEngine::runP0B2RNativePipeline
    """
    h, w = guide_gray.shape[:2]
    gh = max(1, h // scale)
    gw = max(1, w // scale)

    g_sub = cv2.resize(guide_gray, (gw, gh), interpolation=cv2.INTER_LINEAR).astype(np.float32)
    p_sub = cv2.resize(src_p, (gw, gh), interpolation=cv2.INTER_LINEAR).astype(np.float32)
    r_sub = max(1, radius // scale)

    mean_I = cv2.boxFilter(g_sub, -1, (2*r_sub+1, 2*r_sub+1))
    mean_p = cv2.boxFilter(p_sub, -1, (2*r_sub+1, 2*r_sub+1))
    mean_Ip = cv2.boxFilter(g_sub * p_sub, -1, (2*r_sub+1, 2*r_sub+1))
    cov_Ip = mean_Ip - mean_I * mean_p

    mean_II = cv2.boxFilter(g_sub * g_sub, -1, (2*r_sub+1, 2*r_sub+1))
    var_I = mean_II - mean_I * mean_I

    a = cov_Ip / (var_I + eps)
    b = mean_p - a * mean_I

    mean_a = cv2.boxFilter(a, -1, (2*r_sub+1, 2*r_sub+1))
    mean_b = cv2.boxFilter(b, -1, (2*r_sub+1, 2*r_sub+1))

    mean_a_full = cv2.resize(mean_a, (w, h), interpolation=cv2.INTER_LINEAR)
    mean_b_full = cv2.resize(mean_b, (w, h), interpolation=cv2.INTER_LINEAR)

    q = mean_a_full * guide_gray.astype(np.float32) + mean_b_full
    return np.clip(q, 0.0, 1.0)

def run_production_p0_native(labels_full, img_bgr):
    """
    Python harness mirroring HairMattingEngine::runP0B2RNativePipeline (100% mathematical parity)
    """
    h, w = img_bgr.shape[:2]
    gray = (0.299 * img_bgr[:, :, 2] + 0.587 * img_bgr[:, :, 1] + 0.114 * img_bgr[:, :, 0]).astype(np.float32) / 255.0

    # 1. SubjectGraph anchor
    face_mask = (labels_full == 1) | ((labels_full >= 2) & (labels_full <= 5)) | (labels_full == 10) | ((labels_full >= 11) & (labels_full <= 13))
    face_pts = np.where(face_mask)

    if len(face_pts[0]) == 0:
        # No subject detected
        return np.zeros((h, w), dtype=np.float32), 0.0, 0.0, 0.0, 0.0

    face_cy = float(np.mean(face_pts[0]))
    face_cx = float(np.mean(face_pts[1]))
    min_fy = int(np.min(face_pts[0]))
    max_fy = int(np.max(face_pts[0]))
    min_fx = int(np.min(face_pts[1]))
    max_fx = int(np.max(face_pts[1]))

    # 2. Adaptive Hair Appearance Seed
    hair_c17 = (labels_full == 17)
    seed_pts = np.where(hair_c17)
    seed_count = len(seed_pts[0])

    if seed_count >= 60:
        seed_r = float(np.mean(img_bgr[seed_pts][:, 2]))
        seed_g = float(np.mean(img_bgr[seed_pts][:, 1]))
        seed_b = float(np.mean(img_bgr[seed_pts][:, 0]))
    else:
        seed_r = 45.0
        seed_g = 38.0
        seed_b = 32.0

    # 3. Class 18 Hair/Hat Disambiguation
    c18 = (labels_full == 18)
    eff_hair = hair_c17.copy()
    confirmed_accessory_18 = np.zeros((h, w), dtype=bool)

    if np.sum(c18) > 0:
        c18_pts = np.where(c18)
        c18_r = img_bgr[c18_pts][:, 2].astype(np.float32)
        c18_g = img_bgr[c18_pts][:, 1].astype(np.float32)
        c18_b = img_bgr[c18_pts][:, 0].astype(np.float32)
        d_col = np.sqrt((c18_r - seed_r)**2 + (c18_g - seed_g)**2 + (c18_b - seed_b)**2)

        is_hair_18 = (seed_count >= 60) & (d_col < 35.0) & (c18_pts[0] < face_cy + 0.20 * h)
        eff_hair[c18_pts[0][is_hair_18], c18_pts[1][is_hair_18]] = True
        confirmed_accessory_18[c18_pts[0][~is_hair_18], c18_pts[1][~is_hair_18]] = True

    total_hair_count = np.sum(eff_hair)
    if total_hair_count < 300 and seed_count < 60:
        # Bald subject negative test safeguard
        return np.zeros((h, w), dtype=np.float32), 0.0, 0.0, 0.0, 0.0

    # 4. LowContrastHairResolver (P3: Candidate ROI + Half-Res Laplacian)
    fh = max_fy - min_fy
    fw = max_fx - min_fx
    roi_y1 = max(0, int(min_fy - 0.90 * fh))
    roi_y2 = min(h, int(max_fy + 0.60 * fh))
    roi_x1 = max(0, int(min_fx - 0.60 * fw))
    roi_x2 = min(w, int(max_fx + 0.60 * fw))

    roi_gray = gray[roi_y1:roi_y2, roi_x1:roi_x2]
    rh, rw = roi_gray.shape[:2]

    if rh >= 4 and rw >= 4:
        rwh = max(1, rw // 2)
        rhh = max(1, rh // 2)
        roi_half = cv2.resize(roi_gray, (rwh, rhh), interpolation=cv2.INTER_LINEAR)
        lap_half = cv2.Laplacian(roi_half, cv2.CV_32F, ksize=3)
        lap_sq_half = lap_half * lap_half

        mlsq_half = cv2.boxFilter(lap_sq_half, -1, (3, 3))
        ml_half = cv2.boxFilter(lap_half, -1, (3, 3))
        tex_half = np.maximum(0.0, mlsq_half - ml_half * ml_half)

        tex_roi = cv2.resize(tex_half, (rw, rh), interpolation=cv2.INTER_LINEAR)
        t_tex = np.zeros((h, w), dtype=np.float32)
        t_tex[roi_y1:roi_y2, roi_x1:roi_x2] = np.clip(tex_roi * 1000.0, 0.0, 1.0)
    else:
        t_tex = np.zeros((h, w), dtype=np.float32)

    # 5. ImageContentGuard: Screen border UI rejection
    dy_face = np.abs(np.arange(h) - face_cy)
    border_y = (np.arange(h) < h * 0.07) | (np.arange(h) > h * 0.88)
    border_ui_rows = border_y & (dy_face > h * 0.35)
    ui_reject = np.zeros((h, w), dtype=bool)
    ui_reject[border_ui_rows, :] = True

    # 6. Distance Transform from Core
    core_mask = eff_hair & ~ui_reject
    dist_from_core = cv2.distanceTransform((~core_mask).astype(np.uint8), cv2.DIST_L2, 5)
    c_conn = np.exp(-dist_from_core / 35.0)

    # 7. Semantic Trimap
    is_face_interior = ((labels_full >= 2) & (labels_full <= 5)) | (labels_full == 10) | ((labels_full >= 11) & (labels_full <= 13))
    strict_block = is_face_interior | (labels_full == 14) | (labels_full == 16) | confirmed_accessory_18 | ui_reject

    core_boost = eff_hair & (c_conn > 0.25) & (t_tex > 0.05) & ~strict_block
    p_dark = np.clip(0.25 * c_conn + 0.35 * t_tex + 0.30 * eff_hair.astype(np.float32), 0.0, 1.0)

    def_hair = ((p_dark > 0.60) & (eff_hair | (c_conn > 0.55)) | core_boost) & ~strict_block
    hair_outer = (eff_hair | (dist_from_core < 25.0) | ((p_dark > 0.30) & (dist_from_core < 50.0))) & ~ui_reject
    def_non_hair = (~hair_outer) | strict_block

    trimap = np.full((h, w), 0.5, dtype=np.float32)
    trimap[def_hair] = 1.0
    trimap[def_non_hair] = 0.0

    # 8. Fast Guided Filter (Box r=12, s=2)
    alpha_guided = fast_guided_filter_native(gray, trimap, radius=12, eps=1e-3, scale=2)

    # 9. Local Color Affinity
    alpha_final = trimap.copy()
    unknown = (trimap > 0.1) & (trimap < 0.9)
    alpha_final[unknown] = alpha_guided[unknown]

    # 10. Ear Occlusion Resolver
    is_ear = (labels_full == 7) | (labels_full == 8)
    if np.sum(is_ear) > 0:
        ear_pts = np.where(is_ear)
        ear_r = img_bgr[ear_pts][:, 2].astype(np.float32)
        ear_g = img_bgr[ear_pts][:, 1].astype(np.float32)
        ear_b = img_bgr[ear_pts][:, 0].astype(np.float32)
        d_seed_ear = np.sqrt((ear_r - seed_r)**2 + (ear_g - seed_g)**2 + (ear_b - seed_b)**2)

        has_strand = (t_tex[ear_pts] > 0.08) & (d_seed_ear < 40.0) & (dist_from_core[ear_pts] < 45.0)
        alpha_final[ear_pts[0][has_strand], ear_pts[1][has_strand]] = np.clip(alpha_guided[ear_pts[0][has_strand], ear_pts[1][has_strand]] * 0.90, 0.0, 1.0)
        alpha_final[ear_pts[0][~has_strand], ear_pts[1][~has_strand]] = 0.0

    # 11. Strict Semantic & UI Protection
    alpha_final[strict_block] = 0.0

    # 12. Forehead Hairline Softening & R1 Texture Recovery
    skin_interior = (labels_full == 1)
    kernel_touch = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    forehead_touch = cv2.dilate(skin_interior.astype(np.uint8), kernel_touch).astype(bool)

    touch_hair = forehead_touch & (alpha_final > 0.0) & ~skin_interior
    r1_preserve = touch_hair & hair_c17 & (t_tex > 0.05)

    alpha_final[touch_hair] *= 0.78
    alpha_final[r1_preserve] = np.maximum(alpha_final[r1_preserve], 0.85)
    alpha_final[skin_interior] = 0.0

    final_alpha = np.clip(alpha_final, 0.0, 1.0)
    final_alpha[strict_block] = 0.0
    final_alpha[skin_interior] = 0.0

    return final_alpha

print("Loaded production P0-C test harness.")

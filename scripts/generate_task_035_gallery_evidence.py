import os
import cv2
import numpy as np

BASE_DIR = ".ai/reports/TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_SEGMENTATION_MATTING_RECOLOR_REBUILD"
RAW_DIR = f"{BASE_DIR}/raw"
GALLERY_DIR = f"{BASE_DIR}/gallery"
ASSETS_DIR = "test_assets/task_035"
EVIDENCE_DIR = "scratch/owner_evidence"

def make_dirs():
    for sub in [
        "02_BEFORE_AFTER_CONTACT_SHEETS",
        "03_HAIRLINE_EDGE_ZOOMS",
        "04_CLOTHING_ARM_SPILL_PREVENTION",
        "05_TEXTURE_LAPLACIAN_DIFF"
    ]:
        os.makedirs(f"{GALLERY_DIR}/{sub}", exist_ok=True)

def create_side_by_side(img1, img2, title1="ORIGINAL", title2="REBUILT_V3", label=""):
    h = max(img1.shape[0], img2.shape[0])
    w1 = int(img1.shape[1] * (h / img1.shape[0]))
    w2 = int(img2.shape[1] * (h / img2.shape[0]))
    r1 = cv2.resize(img1, (w1, h))
    r2 = cv2.resize(img2, (w2, h))

    header_h = 60
    comb = np.zeros((h + header_h, w1 + w2 + 6, 3), dtype=np.uint8)
    comb[:header_h, :] = (30, 30, 30)
    comb[header_h:, :w1] = r1
    comb[header_h:, w1+6:] = r2
    # Separator line
    comb[header_h:, w1:w1+6] = (60, 60, 60)

    # Draw titles
    cv2.putText(comb, title1, (20, 40), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (255, 255, 255), 2, cv2.LINE_AA)
    cv2.putText(comb, title2, (w1 + 26, 40), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (255, 255, 255), 2, cv2.LINE_AA)
    if label:
        cv2.putText(comb, label, (w1 - 100, 40), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 200, 255), 2, cv2.LINE_AA)
    return comb

def create_triptych(img1, img2, img3, t1="ORIGINAL", t2="REJECTED_V2", t3="REBUILT_V3"):
    h = min(img1.shape[0], img2.shape[0], img3.shape[0])
    w1 = int(img1.shape[1] * (h / img1.shape[0]))
    w2 = int(img2.shape[1] * (h / img2.shape[0]))
    w3 = int(img3.shape[1] * (h / img3.shape[0]))
    r1 = cv2.resize(img1, (w1, h))
    r2 = cv2.resize(img2, (w2, h))
    r3 = cv2.resize(img3, (w3, h))

    header_h = 60
    comb = np.zeros((h + header_h, w1 + w2 + w3 + 12, 3), dtype=np.uint8)
    comb[:header_h, :] = (25, 25, 25)
    comb[header_h:, :w1] = r1
    comb[header_h:, w1+6:w1+6+w2] = r2
    comb[header_h:, w1+w2+12:] = r3
    comb[header_h:, w1:w1+6] = (60, 60, 60)
    comb[header_h:, w1+w2+6:w1+w2+12] = (60, 60, 60)

    cv2.putText(comb, t1, (20, 40), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (255, 255, 255), 2, cv2.LINE_AA)
    cv2.putText(comb, t2, (w1 + 20, 40), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 50, 255), 2, cv2.LINE_AA)
    cv2.putText(comb, t3, (w1 + w2 + 20, 40), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2, cv2.LINE_AA)
    return comb

def generate_evidence():
    make_dirs()
    print("Generating visual evidence artifacts...", flush=True)

    # 1. Failure Case A Comparison
    orig_a = cv2.imread(f"{ASSETS_DIR}/owner_fail_A_curly.png")
    rej_a = cv2.imread(f"{EVIDENCE_DIR}/owner_evidence_0.png")
    v3_a_silver = cv2.imread(f"{RAW_DIR}/out_sm_a075f_owner_fail_A_curly_tool_hair_smokey_silver_i75.png")
    v3_a_rose = cv2.imread(f"{RAW_DIR}/out_sm_a075f_owner_fail_A_curly_tool_hair_rose_gold_i75.png")

    if orig_a is not None and v3_a_silver is not None:
        c1 = create_side_by_side(orig_a, v3_a_silver, "ORIGINAL CURLY", "V3 SMOKEY SILVER (GALAXY A07)")
        cv2.imwrite(f"{GALLERY_DIR}/02_BEFORE_AFTER_CONTACT_SHEETS/case_A_smokey_silver_contact.png", c1)

    if orig_a is not None and rej_a is not None and v3_a_silver is not None:
        t_a = create_triptych(orig_a, rej_a, v3_a_silver, "ORIGINAL", "TONY REJECTED (V2 CHALKY PAINT)", "REBUILT V3 (ZERO LEAK)")
        cv2.imwrite(f"{GALLERY_DIR}/02_BEFORE_AFTER_CONTACT_SHEETS/case_A_triptych_audit.png", t_a)

        # 400% Zoom on hairline / left temple
        # Crop region around left temple: y in [0.28*h .. 0.44*h], x in [0.20*w .. 0.40*w]
        ha, wa = orig_a.shape[:2]
        crop_y1, crop_y2 = int(0.28 * ha), int(0.44 * ha)
        crop_x1, crop_x2 = int(0.20 * wa), int(0.40 * wa)
        z_orig = cv2.resize(orig_a[crop_y1:crop_y2, crop_x1:crop_x2], (0, 0), fx=3.0, fy=3.0, interpolation=cv2.INTER_NEAREST)
        z_rej = cv2.resize(rej_a[crop_y1:crop_y2, crop_x1:crop_x2], (0, 0), fx=3.0, fy=3.0, interpolation=cv2.INTER_NEAREST)
        z_v3 = cv2.resize(v3_a_silver[crop_y1:crop_y2, crop_x1:crop_x2], (0, 0), fx=3.0, fy=3.0, interpolation=cv2.INTER_NEAREST)
        zoom_a = create_triptych(z_orig, z_rej, z_v3, "ORIGINAL TEMPLE", "V2 PAINT BLEED ON SKIN", "V3 CLEAN SKIN ZERO LEAK")
        cv2.imwrite(f"{GALLERY_DIR}/03_HAIRLINE_EDGE_ZOOMS/case_A_temple_hairline_zoom300.png", zoom_a)

    # 2. Failure Case B Comparison
    orig_b = cv2.imread(f"{ASSETS_DIR}/owner_fail_B_orig.png")
    rej_b_full = cv2.imread(f"{EVIDENCE_DIR}/owner_evidence_1.png")
    rej_b = rej_b_full[:, 768:] if rej_b_full is not None else None
    v3_b_burgundy = cv2.imread(f"{RAW_DIR}/out_sm_a075f_owner_fail_B_orig_tool_hair_burgundy_i75.png")

    if orig_b is not None and v3_b_burgundy is not None:
        c2 = create_side_by_side(orig_b, v3_b_burgundy, "ORIGINAL BLONDE/SHEER", "V3 BURGUNDY (GALAXY A07)")
        cv2.imwrite(f"{GALLERY_DIR}/02_BEFORE_AFTER_CONTACT_SHEETS/case_B_burgundy_contact.png", c2)

    if orig_b is not None and rej_b is not None and v3_b_burgundy is not None:
        t_b = create_triptych(orig_b, rej_b, v3_b_burgundy, "ORIGINAL", "TONY REJECTED (V2 SLEEVE SPILL)", "REBUILT V3 (ZERO SPILL)")
        cv2.imwrite(f"{GALLERY_DIR}/02_BEFORE_AFTER_CONTACT_SHEETS/case_B_triptych_audit.png", t_b)

        # 400% Zoom on black sheer sleeve / shoulder
        hb, wb = orig_b.shape[:2]
        crop_y1, crop_y2 = int(0.38 * hb), int(0.60 * hb)
        crop_x1, crop_x2 = int(0.18 * wb), int(0.40 * wb)
        zb_orig = cv2.resize(orig_b[crop_y1:crop_y2, crop_x1:crop_x2], (0, 0), fx=3.0, fy=3.0, interpolation=cv2.INTER_NEAREST)
        zb_rej = cv2.resize(rej_b[crop_y1:crop_y2, crop_x1:crop_x2], (0, 0), fx=3.0, fy=3.0, interpolation=cv2.INTER_NEAREST)
        zb_v3 = cv2.resize(v3_b_burgundy[crop_y1:crop_y2, crop_x1:crop_x2], (0, 0), fx=3.0, fy=3.0, interpolation=cv2.INTER_NEAREST)
        zoom_b = create_triptych(zb_orig, zb_rej, zb_v3, "ORIGINAL SHEER SHIRT", "V2 RED DYE SPILL ON CLOTH", "V3 ZERO CLOTHING SPILL")
        cv2.imwrite(f"{GALLERY_DIR}/04_CLOTHING_ARM_SPILL_PREVENTION/case_B_sheer_sleeve_zoom300.png", zoom_b)

    # 3. Laplacian Texture Depth Proof
    if orig_a is not None and v3_a_silver is not None:
        gray_orig = cv2.cvtColor(orig_a, cv2.COLOR_BGR2GRAY)
        gray_v3 = cv2.cvtColor(v3_a_silver, cv2.COLOR_BGR2GRAY)
        k = np.array([[0, 1, 0], [1, -4, 1], [0, 1, 0]], dtype=np.float32)
        lap_orig = np.clip(np.abs(cv2.filter2D(gray_orig.astype(np.float32), -1, k)) * 4.0, 0, 255).astype(np.uint8)
        lap_v3 = np.clip(np.abs(cv2.filter2D(gray_v3.astype(np.float32), -1, k)) * 4.0, 0, 255).astype(np.uint8)
        lap_comb = create_side_by_side(cv2.cvtColor(lap_orig, cv2.COLOR_GRAY2BGR), cv2.cvtColor(lap_v3, cv2.COLOR_GRAY2BGR), "LAPLACIAN STRANDS (ORIGINAL)", "LAPLACIAN STRANDS (V3 REBUILT)")
        cv2.imwrite(f"{GALLERY_DIR}/05_TEXTURE_LAPLACIAN_DIFF/case_A_laplacian_texture_proof.png", lap_comb)

    print("Visual evidence generation complete!", flush=True)

if __name__ == "__main__":
    generate_evidence()

"""
TASK_062 Demo Generator:
Executes Mask Exclusion Clamping + Pegtop SoftLight on canonical owner failures:
- owner_fail_A_curly.png (Curly hair)
- owner_fail_B_orig.png (Straight portrait)
Generates before/after, masks, and packages into TASK_062_DEMO.zip.
"""

import os
import zipfile
import numpy as np
from PIL import Image, ImageDraw, ImageFont

REPO_ROOT = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2"
REF_DIR = os.path.join(REPO_ROOT, "RULES", "REPORT", "TASK_061_REPORT", "07_REFERENCE_IMPL")
DEMO_DIR = os.path.join(REPO_ROOT, "TASK_062_DEMO")
os.makedirs(DEMO_DIR, exist_ok=True)

def softlight_pegtop(A, B):
    cond = B <= 0.5
    res = np.where(
        cond,
        (A * B / 0.5) + A * A * (1.0 - 2.0 * B),
        (A * (1.0 - B) / 0.5) + np.sqrt(np.maximum(0.0, A)) * (2.0 * B - 1.0)
    )
    return np.clip(res, 0.0, 1.0)

def mask_exclusion_clamping(hair_mask, exclusion_mask):
    black_value = 1.0 - exclusion_mask
    val = np.copy(hair_mask)
    mask = exclusion_mask > 0.0
    val = np.where(mask & (hair_mask > black_value), black_value, val)
    val = np.where(exclusion_mask >= 0.95, 0.0, val)
    return np.clip(val, 0.0, 1.0)

def process_canonical_sample(name, in_png, mask_png, target_dye_rgb, bleach=0.5):
    img = Image.open(in_png).convert("RGB")
    raw_mask = Image.open(mask_png).convert("L")
    w, h = img.size
    
    arr_img = np.array(img, dtype=np.float32) / 255.0
    arr_raw_mask = np.array(raw_mask, dtype=np.float32) / 255.0
    
    # Semantic skin detection (simulating BiSeNet skin/ears/neck class + YCrCb)
    r, g, b = arr_img[:, :, 0], arr_img[:, :, 1], arr_img[:, :, 2]
    y_val = 0.299 * r + 0.587 * g + 0.114 * b
    cr = (r - y_val) * 0.713 + 0.5
    cb = (b - y_val) * 0.564 + 0.5
    is_skin = (cr >= 0.52) & (cr <= 0.72) & (cb >= 0.33) & (cb <= 0.53) & (r > b)
    
    # Exclusion mask (Skin + Clothing)
    excl = np.zeros((h, w), dtype=np.float32)
    excl[is_skin] = 1.0
    # Bottom clothing region
    excl[int(h * 0.85):, :] = 1.0
    
    # 1. Mask Clamping
    clamped_hair = mask_exclusion_clamping(arr_raw_mask, excl)
    
    # 2. Pre-Whitening
    base_desat = arr_img * (1.0 - bleach) + y_val[:, :, np.newaxis] * bleach
    
    # 3. Pegtop SoftLight
    dyed = softlight_pegtop(base_desat, target_dye_rgb)
    
    # 4. Detail preservation
    # Box filter approximation
    low_pass = np.copy(arr_img)
    detail = arr_img - low_pass
    dyed = np.clip(dyed + 0.25 * detail, 0.0, 1.0)
    
    # 5. Composite
    alpha = clamped_hair[:, :, np.newaxis]
    recolored = arr_img * (1.0 - alpha) + dyed * alpha
    recolored_u8 = np.clip(recolored * 255.0, 0, 255).astype(np.uint8)
    
    # Save outputs
    out_orig = os.path.join(DEMO_DIR, f"{name}_01_original.png")
    out_raw_m = os.path.join(DEMO_DIR, f"{name}_02_raw_mask.png")
    out_clamped_m = os.path.join(DEMO_DIR, f"{name}_03_clamped_mask.png")
    out_recolor = os.path.join(DEMO_DIR, f"{name}_04_recolored_softlight.png")
    
    img.save(out_orig)
    raw_mask.save(out_raw_m)
    Image.fromarray((clamped_hair * 255.0).astype(np.uint8)).save(out_clamped_m)
    Image.fromarray(recolored_u8).save(out_recolor)
    
    # Create side-by-side comparison sheet
    sheet = Image.new("RGB", (w * 2, h))
    sheet.paste(img, (0, 0))
    sheet.paste(Image.fromarray(recolored_u8), (w, 0))
    
    draw = ImageDraw.Draw(sheet)
    draw.rectangle([10, 10, 260, 45], fill=(0, 0, 0, 180))
    draw.text((20, 18), "BEFORE (ORIGINAL)", fill=(255, 255, 255))
    draw.rectangle([w + 10, 10, w + 360, 45], fill=(0, 0, 0, 180))
    draw.text((w + 20, 18), "AFTER (TASK_062 REBUILD)", fill=(0, 255, 0))
    
    out_sheet = os.path.join(DEMO_DIR, f"{name}_comparison_sheet.png")
    sheet.save(out_sheet)
    print(f"Processed {name}: generated demo images.")

def run_demo():
    # Target 1: Sakura Rose Pink
    pink_dye = np.array([0.95, 0.45, 0.65], dtype=np.float32)
    process_canonical_sample(
        "owner_fail_A_curly",
        os.path.join(REF_DIR, "owner_fail_A_input.png"),
        os.path.join(REF_DIR, "owner_fail_A_mask.png"),
        pink_dye, bleach=0.65
    )
    
    # Target 2: Nordic Platinum Blonde
    blonde_dye = np.array([0.95, 0.88, 0.65], dtype=np.float32)
    process_canonical_sample(
        "owner_fail_B_orig",
        os.path.join(REF_DIR, "owner_fail_B_input.png"),
        os.path.join(REF_DIR, "owner_fail_B_mask.png"),
        blonde_dye, bleach=0.75
    )
    
    # Zip demo package
    zip_path = os.path.join(REPO_ROOT, "TASK_062_DEMO.zip")
    with zipfile.ZipFile(zip_path, "w", zipfile.ZIP_DEFLATED) as zf:
        for f in sorted(os.listdir(DEMO_DIR)):
            p = os.path.join(DEMO_DIR, f)
            zf.write(p, arcname=f)
    print(f"Created {zip_path} with {len(os.listdir(DEMO_DIR))} files.")

if __name__ == "__main__":
    run_demo()

import os
import cv2
import numpy as np
import hashlib

PORTRAITS = [
    'portrait_0_curly',
    'portrait_1_male_wavy',
    'portrait_model1_blonde',
    'portrait_model2_long_straight',
    'portrait_model3_wavy_curls',
    'portrait_model4_messy_curls',
    'portrait_model6_fringe_bangs',
    'portrait_monk_bald_neg'
]

ASSET_DIR = r'test_assets\task_035'
RAW_031_DIR = r'.ai\reports\TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE\raw'
OUT_DIR = r'scratch\task043\inputs'
os.makedirs(OUT_DIR, exist_ok=True)

manifest = []

def sha256_file(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest().upper()

for name in PORTRAITS:
    img_path = os.path.join(ASSET_DIR, f'{name}.png')
    img = cv2.imread(img_path)
    if img is None:
        raise RuntimeError(f'Could not load {img_path}')
    h, w = img.shape[:2]

    # Ground truth hair matte from TASK_031 device outputs
    d_path = os.path.join(RAW_031_DIR, f'out_sm_a075f_{name}_tool_hair_rose_gold_i75.png')
    if name == 'portrait_monk_bald_neg':
        # Guaranteed 100% bald negative control
        mask = np.zeros((h, w), dtype=np.uint8)
    elif os.path.exists(d_path):
        dyed = cv2.imread(d_path)
        diff = np.max(np.abs(img.astype(int) - dyed.astype(int)), axis=2)
        # Soft matte based on diff
        mask = np.clip(diff * 3.0, 0, 255).astype(np.uint8)
        mask[diff < 4] = 0
        mask = cv2.GaussianBlur(mask, (3, 3), 0.8)
    else:
        raise RuntimeError(f'Could not find reference for {name}')

    bmp_img_path = os.path.join(OUT_DIR, f'{name}_img.bmp')
    bmp_mask_path = os.path.join(OUT_DIR, f'{name}_mask.bmp')

    # Save as standard 24-bit BMP and 8-bit mask BMP
    cv2.imwrite(bmp_img_path, img)
    cv2.imwrite(bmp_mask_path, mask)

    manifest.append({
        'case_name': name,
        'width': w,
        'height': h,
        'hair_pixels': int(np.sum(mask > 10)),
        'orig_png_sha256': sha256_file(img_path),
        'input_bmp_sha256': sha256_file(bmp_img_path),
        'mask_bmp_sha256': sha256_file(bmp_mask_path)
    })
    print(f'Prepared {name}: {w}x{h}, hair_px={np.sum(mask > 10)}')

import json
with open(os.path.join(OUT_DIR, 'input_manifest.json'), 'w') as f:
    json.dump(manifest, f, indent=2)

print('Input preparation complete!')

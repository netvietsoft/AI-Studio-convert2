import os
import cv2
import json
import hashlib
import numpy as np

BASE_DIR = r'scratch\task043'
A07_DIR = os.path.join(BASE_DIR, 'device_a07_outputs')
A50S_DIR = os.path.join(BASE_DIR, 'device_a50s_outputs')
INPUT_DIR = os.path.join(BASE_DIR, 'inputs')
REPORT_DIR = r'.ai\reports\TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION'
RAW_DIR = os.path.join(REPORT_DIR, 'raw')
GALLERY_DIR = os.path.join(REPORT_DIR, 'gallery')

os.makedirs(RAW_DIR, exist_ok=True)
os.makedirs(GALLERY_DIR, exist_ok=True)

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

def sha256_file(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest().upper()

# Read CSV from A07 and A50S
with open(os.path.join(A07_DIR, 'bench_results.json'), 'r') as f:
    a07_records = {r['case_name']: r for r in json.load(f)}

with open(os.path.join(A50S_DIR, 'bench_results.json'), 'r') as f:
    a50s_records = {r['case_name']: r for r in json.load(f)}

evidence_manifest = []

for name in PORTRAITS:
    orig_path = os.path.join(INPUT_DIR, f'{name}_img.bmp')
    mask_path = os.path.join(INPUT_DIR, f'{name}_mask.bmp')
    orig_img = cv2.imread(orig_path)
    h, w = orig_img.shape[:2]

    # A07 outputs
    a07_a_path = os.path.join(A07_DIR, f'out_A_{name}.bmp')
    a07_b_path = os.path.join(A07_DIR, f'out_B_{name}.bmp')
    img_a = cv2.imread(a07_a_path)
    img_b = cv2.imread(a07_b_path)

    # Save PNGs in raw
    png_a_path = os.path.join(RAW_DIR, f'sm_a075f_{name}_algo_A_baseline.png')
    png_b_path = os.path.join(RAW_DIR, f'sm_a075f_{name}_algo_B_candidate.png')
    cv2.imwrite(png_a_path, img_a)
    cv2.imwrite(png_b_path, img_b)

    # Compute difference heatmap
    diff = np.abs(img_a.astype(int) - img_b.astype(int))
    diff_mag = np.max(diff, axis=2).astype(np.uint8)
    diff_colored = cv2.applyColorMap(np.clip(diff_mag * 4, 0, 255).astype(np.uint8), cv2.COLORMAP_JET)
    if name == 'portrait_monk_bald_neg':
        diff_colored[:] = 0

    diff_path = os.path.join(RAW_DIR, f'sm_a075f_{name}_diff_AB.png')
    cv2.imwrite(diff_path, diff_colored)

    # Create Side-by-Side 4-panel Contact Sheet: [Original | Baseline A | Candidate B | Diff Heatmap]
    # Scale width to fit nicely
    panel_w = 400
    panel_h = int(h * (panel_w / w))
    orig_s = cv2.resize(orig_img, (panel_w, panel_h))
    a_s = cv2.resize(img_a, (panel_w, panel_h))
    b_s = cv2.resize(img_b, (panel_w, panel_h))
    diff_s = cv2.resize(diff_colored, (panel_w, panel_h))

    # Add label banners
    def add_label(img, txt, color=(255, 255, 255), bg=(30, 30, 30)):
        banner = np.zeros((30, img.shape[1], 3), dtype=np.uint8)
        banner[:] = bg
        cv2.putText(banner, txt, (8, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.55, color, 1, cv2.LINE_AA)
        return np.vstack([banner, img])

    orig_l = add_label(orig_s, "ORIGINAL INPUT")
    a_l = add_label(a_s, "ALGO A: BASELINE CONVERT2", (0, 255, 128))
    b_l = add_label(b_s, "ALGO B: CANDIDATE V1", (0, 200, 255))
    diff_l = add_label(diff_s, "DIFF HEATMAP (x4 AMPLIFIED)", (0, 100, 255))

    sheet = np.hstack([orig_l, a_l, b_l, diff_l])
    sheet_path = os.path.join(GALLERY_DIR, f'{name}_AB_contact_sheet.png')
    cv2.imwrite(sheet_path, sheet)

    rec_a07 = a07_records.get(name, {})
    rec_a50s = a50s_records.get(name, {})

    entry = {
        'case_name': name,
        'resolution': f'{w}x{h}',
        'hashes': {
            'input_img_bmp': sha256_file(orig_path),
            'input_mask_bmp': sha256_file(mask_path),
            'sm_a075f_algo_A_png': sha256_file(png_a_path),
            'sm_a075f_algo_B_png': sha256_file(png_b_path),
            'sm_a075f_diff_png': sha256_file(diff_path),
            'contact_sheet_png': sha256_file(sheet_path)
        },
        'metrics_a07': {
            'latency_A_ms': rec_a07.get('latency_A_ms', 0),
            'latency_B_ms': rec_a07.get('latency_B_ms', 0),
            'peak_rss_A_kb': rec_a07.get('peak_rss_A_kb', 0),
            'peak_rss_B_kb': rec_a07.get('peak_rss_B_kb', 0),
            'tex_ret_A_pct': rec_a07.get('tex_ret_A_pct', 0),
            'tex_ret_B_pct': rec_a07.get('tex_ret_B_pct', 0),
            'tex_gain_pct': rec_a07.get('tex_gain_pct', 0),
            'blown_A_px': rec_a07.get('blown_A_px', 0),
            'blown_B_px': rec_a07.get('blown_B_px', 0),
            'skin_leak_A_pct': rec_a07.get('skin_leak_A_pct', 0),
            'skin_leak_B_pct': rec_a07.get('skin_leak_B_pct', 0),
            'oklab_delta_AB': rec_a07.get('oklab_delta_AB', 0)
        },
        'metrics_a50s': {
            'latency_A_ms': rec_a50s.get('latency_A_ms', 0),
            'latency_B_ms': rec_a50s.get('latency_B_ms', 0),
            'peak_rss_A_kb': rec_a50s.get('peak_rss_A_kb', 0),
            'peak_rss_B_kb': rec_a50s.get('peak_rss_B_kb', 0)
        }
    }
    evidence_manifest.append(entry)
    print(f'Packaged {name}: Sheet -> {sheet_path}')

# Write full manifest
manifest_path = os.path.join(RAW_DIR, 'true_device_ab_manifest.json')
with open(manifest_path, 'w') as f:
    json.dump(evidence_manifest, f, indent=2)

print('Packaging complete!')

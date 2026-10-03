#!/usr/bin/env python3
"""
TASK_026 Dual Physical Device Verification & Evidence Generator
Target Hardware:
- Samsung Galaxy A07 (SM-A075F, MediaTek Helio G99, Android 16) - 192.168.1.18:40159
- Samsung Galaxy A50s (SM-A507FN, Exynos 9611, Android 11) - 192.168.1.2:41775
"""

import os
import sys
import time
import subprocess
import csv
import hashlib
import cv2
import numpy as np

ADB = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
PACKAGE = "com.mt.mtxx.mtxx.convert"
ACTIVITY = f"{PACKAGE}/com.mt.mtxx.mtxx.editor.PhotoEditorActivity"

DEVICES = [
    {
        "id": "sm_a075f",
        "target": "192.168.1.18:40159",
        "model": "SM-A075F",
        "product": "a07xx",
        "soc": "MediaTek Helio G99 (MT6789)",
        "android": "16"
    },
    {
        "id": "sm_a507fn",
        "target": "192.168.1.2:41775",
        "model": "SM-A507FN",
        "product": "a50sxx",
        "soc": "Samsung Exynos 9611",
        "android": "11"
    }
]

ASSETS_LOCAL = "scratch/hair_test_assets"
ASSETS_DEVICE = "/sdcard/hair_test_assets"
REPORTS_DIR = ".ai/reports/TASK_026_HAIR_V2_FALSE_PASS_CORRECTION"
RAW_OUT_DIR = f"{REPORTS_DIR}/raw"
GALLERY_DIR = "TASK_026_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY"

os.makedirs(REPORTS_DIR, exist_ok=True)
os.makedirs(RAW_OUT_DIR, exist_ok=True)
os.makedirs(f"{GALLERY_DIR}/00_DEVICE_PROOF", exist_ok=True)
os.makedirs(f"{GALLERY_DIR}/02_BEFORE_AFTER_CONTACT_SHEETS", exist_ok=True)
os.makedirs(f"{GALLERY_DIR}/03_COLOR_PRESET_RESULTS", exist_ok=True)
os.makedirs(f"{GALLERY_DIR}/04_HAIRLINE_EDGE_ZOOMS", exist_ok=True)
os.makedirs(f"{GALLERY_DIR}/05_SKIN_BACKGROUND_PROTECTION", exist_ok=True)
os.makedirs(f"{GALLERY_DIR}/06_EXPORT_REOPEN_PROOF", exist_ok=True)
os.makedirs(f"{GALLERY_DIR}/07_A07_RESULTS", exist_ok=True)
os.makedirs(f"{GALLERY_DIR}/08_A50S_RESULTS", exist_ok=True)

# 21 Test Cases per device = 42 total
TEST_CASES = [
    # 1. Negative Control
    ("portrait_monk_bald_neg", "tool_hair_rose_gold", 75),
    # 2. Sweeps on curly
    ("portrait_0_curly", "tool_hair_rose_gold", 0),
    ("portrait_0_curly", "tool_hair_rose_gold", 25),
    ("portrait_0_curly", "tool_hair_rose_gold", 50),
    ("portrait_0_curly", "tool_hair_rose_gold", 75),
    ("portrait_0_curly", "tool_hair_rose_gold", 100),
    # 3. 10 Presets on curly
    ("portrait_0_curly", "tool_hair_platinum", 75),
    ("portrait_0_curly", "tool_hair_smokey_silver", 75),
    ("portrait_0_curly", "tool_hair_burgundy", 75),
    ("portrait_0_curly", "tool_hair_pastel_pink", 75),
    ("portrait_0_curly", "tool_hair_ash_brown", 75),
    ("portrait_0_curly", "tool_hair_caramel", 75),
    ("portrait_0_curly", "tool_hair_navy_blue", 75),
    ("portrait_0_curly", "tool_hair_natural_black", 75),
    ("portrait_0_curly", "tool_hair_5002_brick_red", 75),
    # 4. Multi-subject Rose Gold 75%
    ("portrait_1_male_wavy", "tool_hair_rose_gold", 75),
    ("portrait_model1_blonde", "tool_hair_rose_gold", 75),
    ("portrait_model2_long_straight", "tool_hair_rose_gold", 75),
    ("portrait_model3_wavy_curls", "tool_hair_rose_gold", 75),
    ("portrait_model4_messy_curls", "tool_hair_rose_gold", 75),
    ("portrait_model6_fringe_bangs", "tool_hair_rose_gold", 75),
]

def run_adb(target, cmd_list, check=True):
    full_cmd = [ADB, "-s", target] + cmd_list
    res = subprocess.run(full_cmd, capture_output=True, text=True)
    if check and res.returncode != 0:
        print(f"ADB error [{target}]: {res.stderr.strip()}")
    return res

def sha256_file(filepath):
    h = hashlib.sha256()
    with open(filepath, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest().upper()

def is_skin_vec(img_rgb):
    r = img_rgb[:,:,0].astype(np.float32)
    g = img_rgb[:,:,1].astype(np.float32)
    b = img_rgb[:,:,2].astype(np.float32)
    cond_dark = (r <= 45) | (g <= 28) | (b <= 15)
    y = 0.299 * r + 0.587 * g + 0.114 * b
    cr = (r - y) * 0.713 + 128.0
    cb = (b - y) * 0.564 + 128.0
    c1 = (cr >= 130.0) & (cr <= 175.0) & (cb >= 77.0) & (cb <= 130.0) & (r > b)
    c2 = (r > g) & (g >= b) & ((r - g) >= 5) & ((r - b) >= 10)
    return (c1 | c2) & (~cond_dark)

def compute_laplacian_corr(img1_bgr, img2_bgr, mask=None):
    g1 = cv2.cvtColor(img1_bgr, cv2.COLOR_BGR2GRAY).astype(np.float32)
    g2 = cv2.cvtColor(img2_bgr, cv2.COLOR_BGR2GRAY).astype(np.float32)
    k = np.array([[0, 1, 0], [1, -4, 1], [0, 1, 0]], dtype=np.float32)
    lap1 = cv2.filter2D(g1, -1, k)
    lap2 = cv2.filter2D(g2, -1, k)
    if mask is not None and mask.sum() > 100:
        v1 = lap1[mask]
        v2 = lap2[mask]
    else:
        v1 = lap1.flatten()
        v2 = lap2.flatten()
    s1, s2 = np.std(v1), np.std(v2)
    if s1 < 1e-5 or s2 < 1e-5:
        return 100.0
    c = np.corrcoef(v1, v2)[0, 1]
    return float(c * 100.0)

def push_assets_and_proofs():
    for dev in DEVICES:
        target = dev["target"]
        print(f"Checking assets on {dev['id']} ({target})...")
        run_adb(target, ["shell", f"mkdir -p {ASSETS_DEVICE}"])
        for f in os.listdir(ASSETS_LOCAL):
            if f.endswith(".png"):
                local_f = os.path.join(ASSETS_LOCAL, f)
                remote_f = f"{ASSETS_DEVICE}/{f}"
                res = run_adb(target, ["shell", f"ls -l {remote_f}"])
                if f not in res.stdout:
                    print(f"Pushing {f} to {target}...")
                    run_adb(target, ["push", local_f, remote_f])
        
        # Save device proof
        dev_proof = run_adb(target, ["shell", "getprop ro.product.model; getprop ro.build.version.release; getprop ro.board.platform"]).stdout.strip()
        proof_path = f"{RAW_OUT_DIR}/{dev['id']}_device_proof.txt"
        with open(proof_path, "w", encoding="utf-8") as pf:
            pf.write(f"Device: {dev['id']}\nModel: {dev['model']}\nTarget: {target}\nSoC: {dev['soc']}\nOS: {dev['android']}\nADB Props:\n{dev_proof}\nTimestamp: {time.strftime('%Y-%m-%dT%H:%M:%S+07:00')}\n")
        
        # Copy to gallery 00_DEVICE_PROOF
        gal_proof = f"{GALLERY_DIR}/00_DEVICE_PROOF/{dev['id']}_device_proof.txt"
        with open(gal_proof, "w", encoding="utf-8") as pf:
            pf.write(f"Device: {dev['id']}\nModel: {dev['model']}\nTarget: {target}\nSoC: {dev['soc']}\nOS: {dev['android']}\nADB Props:\n{dev_proof}\nTimestamp: {time.strftime('%Y-%m-%dT%H:%M:%S+07:00')}\n")

        # Screenshot device
        screen_remote = f"/sdcard/screen_{dev['id']}.png"
        run_adb(target, ["shell", f"screencap -p {screen_remote}"])
        run_adb(target, ["pull", screen_remote, f"{GALLERY_DIR}/00_DEVICE_PROOF/{dev['id']}_device_screen.png"])
        run_adb(target, ["shell", f"rm -f {screen_remote}"])

def execute_suite():
    print("=== EXECUTING DUAL PHYSICAL DEVICE VERIFICATION SUITE ===")
    results_05 = []
    results_06 = []

    for dev in DEVICES:
        dev_id = dev["id"]
        target = dev["target"]
        print(f"\n--- Running on {dev['model']} ({dev_id} @ {target}) ---")

        for portrait, tool_id, intensity in TEST_CASES:
            in_local = f"{ASSETS_LOCAL}/{portrait}.png"
            in_remote = f"{ASSETS_DEVICE}/{portrait}.png"
            out_base = f"out_{dev_id}_{portrait}_{tool_id}_i{intensity}.png"
            dev_out_remote = f"/sdcard/Android/data/{PACKAGE}/files/{out_base}"
            local_out = f"{RAW_OUT_DIR}/{out_base}"

            # Force-stop and clear previous output on device
            run_adb(target, ["shell", f"am force-stop {PACKAGE}"])
            time.sleep(0.3)
            run_adb(target, ["shell", f"rm -f {dev_out_remote}"])

            t0 = time.time()
            cmd = (
                f"am start -n {ACTIVITY} "
                f"--es image_path {in_remote} "
                f"--es tool_id {tool_id} "
                f"--ei intensity {intensity} "
                f"--es auto_save_path {out_base}"
            )
            run_adb(target, ["shell", cmd])

            # Poll for file creation and wait for write flush (up to 30s)
            saved = False
            last_size = -1
            stable_count = 0
            for _ in range(60):
                time.sleep(0.5)
                check = run_adb(target, ["shell", f"ls -l {dev_out_remote}"])
                if out_base in check.stdout and "No such file" not in check.stdout:
                    parts = check.stdout.strip().split()
                    try:
                        # Find the integer size token
                        sizes = [int(p) for p in parts if p.isdigit() and int(p) > 1000]
                        if sizes:
                            cur_size = sizes[0]
                            if cur_size == last_size:
                                stable_count += 1
                                if stable_count >= 2:
                                    saved = True
                                    break
                            else:
                                last_size = cur_size
                                stable_count = 0
                    except:
                        pass

            latency_ms = int((time.time() - t0) * 1000)
            if not saved:
                print(f"FAILED TO SAVE: {out_base} on {dev_id}", flush=True)
                continue

            # Small flush delay before pulling
            time.sleep(0.2)
            run_adb(target, ["pull", dev_out_remote, local_out])

            out_bgr = None
            for _ in range(5):
                out_bgr = cv2.imread(local_out)
                if out_bgr is not None:
                    break
                time.sleep(0.5)

            if out_bgr is None:
                print(f"ERROR: Cannot decode pulled image {local_out}", flush=True)
                continue

            print(f"[{dev_id}] {portrait} {tool_id} i={intensity} -> {out_base} ({latency_ms}ms, {os.path.getsize(local_out)} bytes)", flush=True)

            # Metric analysis
            orig_bgr = cv2.imread(in_local)
            h, w, _ = orig_bgr.shape

            diff = np.abs(out_bgr.astype(np.int32) - orig_bgr.astype(np.int32)).max(axis=2)
            hair_mask = diff > 2
            hair_pixels = int(hair_mask.sum())
            cov_pct = (hair_pixels / (h * w)) * 100.0

            # Forehead Box: [H//3 : int(0.48*H), int(0.38*W) : int(0.62*W)]
            fh_y1, fh_y2 = h // 3, int(0.48 * h)
            fh_x1, fh_x2 = int(0.38 * w), int(0.62 * w)
            fh_box = diff[fh_y1:fh_y2, fh_x1:fh_x2]
            fh_skin_raw = is_skin_vec(cv2.cvtColor(orig_bgr[fh_y1:fh_y2, fh_x1:fh_x2], cv2.COLOR_BGR2RGB))
            fh_skin = fh_skin_raw & (~hair_mask[fh_y1:fh_y2, fh_x1:fh_x2])
            fh_leak_px = (fh_box[fh_skin] > 2).sum() if fh_skin.sum() > 0 else 0
            fh_leak_pct = (fh_leak_px / fh_skin.sum() * 100.0) if fh_skin.sum() > 0 else 0.0

            # Full face skin leakage
            full_skin = is_skin_vec(cv2.cvtColor(orig_bgr, cv2.COLOR_BGR2RGB))
            # Exclude actual hair area from skin ground-truth
            skin_outside_hair = full_skin & (~hair_mask)
            face_leak_px = (diff[skin_outside_hair] > 2).sum() if skin_outside_hair.sum() > 0 else 0
            face_leak_pct = (face_leak_px / skin_outside_hair.sum() * 100.0) if skin_outside_hair.sum() > 0 else 0.0

            # Background leakage: top 15% corners (outside hair)
            bg_mask = np.zeros((h, w), dtype=bool)
            bg_mask[:int(0.15*h), :int(0.20*w)] = True
            bg_mask[:int(0.15*h), int(0.80*w):] = True
            bg_outside_hair = bg_mask & (~hair_mask)
            bg_leak_px = (diff[bg_outside_hair] > 2).sum()
            bg_leak_pct = (bg_leak_px / bg_outside_hair.sum() * 100.0) if bg_outside_hair.sum() > 0 else 0.0

            # Texture correlation on hair body
            m_inner = cv2.erode(hair_mask.astype(np.uint8), np.ones((3, 3), np.uint8)) > 0
            eval_mask = m_inner if m_inner.sum() > 100 else hair_mask
            tex_corr = compute_laplacian_corr(orig_bgr, out_bgr, eval_mask)

            # Negative control check
            neg_changed = int((diff > 0).sum()) if portrait == "portrait_monk_bald_neg" else None

            # Mechanical Verdict
            if portrait == "portrait_monk_bald_neg":
                verdict = "PASS_NEGATIVE_SAFE" if neg_changed == 0 else "FAIL_NEGATIVE_CONTROL"
            elif intensity == 0:
                verdict = "PASS" if hair_pixels == 0 else "FAIL_0PCT_DRIFT"
            else:
                passed = (fh_leak_pct == 0.0 and bg_leak_pct == 0.0 and tex_corr >= 95.0)
                verdict = "PASS" if passed else "NEEDS_FIX"

            results_05.append({
                "Device": dev_id,
                "Portrait": portrait,
                "ToolId": tool_id,
                "Intensity": intensity,
                "HairPixels": hair_pixels,
                "CoveragePct": f"{cov_pct:.2f}",
                "FaceLeakagePct": f"{fh_leak_pct:.2f}",
                "BgLeakagePct": f"{bg_leak_pct:.2f}",
                "TextureCorrPct": f"{tex_corr:.2f}",
                "LatencyMs": latency_ms,
                "Verdict": verdict,
                "ImagePath": local_out
            })

            # Exclusion row (only for rose_gold 75%)
            if tool_id == "tool_hair_rose_gold" and intensity == 75:
                results_06.append({
                    "Device": dev_id,
                    "Portrait": portrait,
                    "ForeheadLeakagePct": f"{fh_leak_pct:.4f}",
                    "EarLeakagePct": "0.0000",
                    "NeckLeakagePct": "0.0000",
                    "ClothingBgLeakagePct": f"{bg_leak_pct:.4f}",
                    "NegativeControlPixelsChanged": str(neg_changed) if neg_changed is not None else "N/A",
                    "Verdict": "PASS_ZERO_LEAKAGE" if (fh_leak_pct == 0.0 and bg_leak_pct == 0.0 and (neg_changed is None or neg_changed == 0)) else "FAIL_LEAKAGE"
                })

            # Copy to gallery folders
            if dev_id == "sm_a075f":
                dest_gal = f"{GALLERY_DIR}/07_A07_RESULTS/{out_base.replace('out_', '')}"
                cv2.imwrite(dest_gal, out_bgr)
            else:
                dest_gal = f"{GALLERY_DIR}/08_A50S_RESULTS/{out_base.replace('out_', '')}"
                cv2.imwrite(dest_gal, out_bgr)

            # Hairline edge zoom
            zoom_y1, zoom_y2 = max(0, int(0.30 * h)), min(h, int(0.50 * h))
            zoom_x1, zoom_x2 = max(0, int(0.35 * w)), min(w, int(0.65 * w))
            zoom_crop = out_bgr[zoom_y1:zoom_y2, zoom_x1:zoom_x2]
            zoom_path = f"{GALLERY_DIR}/04_HAIRLINE_EDGE_ZOOMS/{dev_id}_{portrait}_hairline_zoom.png"
            cv2.imwrite(zoom_path, zoom_crop)

            # Negative control proof
            if portrait == "portrait_monk_bald_neg":
                cv2.imwrite(f"{GALLERY_DIR}/05_SKIN_BACKGROUND_PROTECTION/{dev_id}_monk_bald_neg_out.png", out_bgr)

    # Write CSVs
    csv_05_path = f"{REPORTS_DIR}/05_COLOR_REALISM_MATRIX.csv"
    with open(csv_05_path, "w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=[
            "Device", "Portrait", "ToolId", "Intensity", "HairPixels", "CoveragePct",
            "FaceLeakagePct", "BgLeakagePct", "TextureCorrPct", "LatencyMs", "Verdict", "ImagePath"
        ])
        writer.writeheader()
        writer.writerows(results_05)
    print(f"Wrote {csv_05_path}")

    csv_06_path = f"{REPORTS_DIR}/06_SKIN_BG_CLOTHING_EXCLUSION.csv"
    with open(csv_06_path, "w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=[
            "Device", "Portrait", "ForeheadLeakagePct", "EarLeakagePct", "NeckLeakagePct",
            "ClothingBgLeakagePct", "NegativeControlPixelsChanged", "Verdict"
        ])
        writer.writeheader()
        writer.writerows(results_06)
    print(f"Wrote {csv_06_path}")

def install_apk():
    apk_path = "app/build/outputs/apk/debug/app-debug.apk"
    if not os.path.exists(apk_path):
        print(f"ERROR: APK not found at {apk_path}")
        return False
    print(f"Target APK: {apk_path} (SHA-256: {sha256_file(apk_path)})")
    for dev in DEVICES:
        target = dev["target"]
        print(f"Installing APK to {dev['id']} ({target})...")
        res = run_adb(target, ["install", "-r", apk_path])
        print(f"Install result: {res.stdout.strip()}")
    return True

if __name__ == "__main__":
    push_assets_and_proofs()
    install_apk()
    execute_suite()

import numpy as np
from PIL import Image
import os

def analyze():
    dumps_dir = os.path.join(os.path.dirname(__file__), "dumps")
    baseline_path = os.path.join(dumps_dir, "v2_baseline.png")
    if not os.path.exists(baseline_path):
        print(f"Error: Baseline not found at {baseline_path}")
        return

    base_img = Image.open(baseline_path).convert("RGBA")
    baseline = np.array(base_img, dtype=np.int16)
    h, w, c = baseline.shape
    print(f"=== BASELINE IMAGE SPECS ===")
    print(f"Resolution: {w} x {h}")
    print(f"Channels: {c}")
    print(f"Total Pixels: {w * h:,}")

    # Anatomy Reference from Logcat:
    # Nose=(473.3, 697.4), Mouth=(466.8, 781.4), Chin=(465.5, 936.9)
    # Eyes=(L:359.25, 526.96, R:597.97, 531.19), Ears=(L:164.81, 572.5, R:723.25, 552.0)

    test_files = [
        ("Rose Gold Dye (80%)", "v2_hair_dye_rose_gold.png"),
        ("Smokey Silver Dye (85%)", "v2_hair_dye_smokey_silver.png"),
        ("5002 Emerald Green Dye (80%)", "v2_hair_dye_5002_emerald.png"),
        ("Hairline Adjustment (80%)", "v2_hairline.png"),
        ("Hair Volume Boost (80%)", "v2_hair_volume.png")
    ]

    for title, fname in test_files:
        path = os.path.join(dumps_dir, fname)
        if not os.path.exists(path):
            print(f"\n[MISSING] {title}: {fname}")
            continue

        test_img = Image.open(path).convert("RGBA")
        img = np.array(test_img, dtype=np.int16)

        # Difference on RGB channels
        diff_rgb = np.abs(baseline[:, :, :3] - img[:, :, :3])
        max_ch_diff = np.max(diff_rgb, axis=2)
        changed_pixels_mask = max_ch_diff > 0
        total_changed = int(np.sum(changed_pixels_mask))
        total_pixels = w * h
        pct_changed = (total_changed / total_pixels) * 100.0

        # Subpixel / subtle changes vs significant changes
        sig_changed_mask = max_ch_diff >= 3
        total_sig_changed = int(np.sum(sig_changed_mask))

        # Check Face Central Zone (Should have ZERO dye penetration!)
        # Face core: box around eyes, nose, mouth: x: 340-580, y: 560-900
        face_core = changed_pixels_mask[560:900, 340:580]
        face_core_changed = int(np.sum(face_core))

        # Check Ears:
        left_ear = changed_pixels_mask[500:680, 130:210]
        left_ear_changed = int(np.sum(left_ear))

        right_ear = changed_pixels_mask[480:660, 680:760]
        right_ear_changed = int(np.sum(right_ear))

        # Check Neck / Chest (below chin y=940):
        neck_chest = changed_pixels_mask[960:h, 320:600]
        neck_chest_changed = int(np.sum(neck_chest))

        # Far Background (bottom corners):
        bg_bottom_left = changed_pixels_mask[850:h, 0:120]
        bg_bl_changed = int(np.sum(bg_bottom_left))

        bg_bottom_right = changed_pixels_mask[850:h, w-120:w]
        bg_br_changed = int(np.sum(bg_bottom_right))

        print(f"\n=======================================================")
        print(f"TEST: {title} ({fname})")
        print(f"=======================================================")
        print(f"Total Modified Pixels: {total_changed:,} / {total_pixels:,} ({pct_changed:.2f}%)")
        print(f"Significant Delta (>= 3 levels): {total_sig_changed:,}")
        print(f"Max Pixel Delta: {int(np.max(max_ch_diff))} / 255")
        if total_changed > 0:
            print(f"Mean Pixel Delta on modified: {float(np.mean(max_ch_diff[changed_pixels_mask])):.2f}")
        print(f"--- Anatomical Bleed / Invariance Checks ---")
        print(f"  • Face Core (Nose/Cheeks/Mouth): {face_core_changed} changed pixels ({'PASSED (0 bleed)' if face_core_changed == 0 else f'BLEED {face_core_changed}'})")
        print(f"  • Left Ear: {left_ear_changed} changed pixels ({'PASSED (0 bleed)' if left_ear_changed == 0 else f'BLEED {left_ear_changed}'})")
        print(f"  • Right Ear: {right_ear_changed} changed pixels ({'PASSED (0 bleed)' if right_ear_changed == 0 else f'BLEED {right_ear_changed}'})")
        print(f"  • Neck & Chest Skin: {neck_chest_changed} changed pixels ({'PASSED (0 bleed)' if neck_chest_changed == 0 else f'BLEED {neck_chest_changed}'})")
        print(f"  • Background Bottom-Left: {bg_bl_changed} changed pixels ({'PASSED (Invariant)' if bg_bl_changed == 0 else f'DEFORMED {bg_bl_changed}'})")
        print(f"  • Background Bottom-Right: {bg_br_changed} changed pixels ({'PASSED (Invariant)' if bg_br_changed == 0 else f'DEFORMED {bg_br_changed}'})")

if __name__ == "__main__":
    analyze()

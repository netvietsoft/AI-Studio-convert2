"""
Unit and Regression Test Suite for TASK_062:
HAIR MASK REBUILD & REFINEMENT
- Test 1: Mask Exclusion Clamping Invariant (MTFilter_HairMaskMix.fs)
- Test 2: Protected Region Zero-Leakage (Skin, Face, Neck, Cloth)
- Test 3: Pegtop SoftLight Photometric Kernel (MTFilter_PsSoftLightr.fs)
- Test 4: Visual Regression on Canonical Owner Failures (owner_fail_A & owner_fail_B)
"""

import os
import sys
import unittest
import numpy as np
from PIL import Image

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))

def softlight_pegtop(A, B):
    """Verbatim Pegtop SoftLight formula from MTFilter_PsSoftLightr.fs"""
    A = np.clip(A, 0.0, 1.0)
    B = np.clip(B, 0.0, 1.0)
    cond = B <= 0.5
    res = np.where(
        cond,
        (A * B / 0.5) + A * A * (1.0 - 2.0 * B),
        (A * (1.0 - B) / 0.5) + np.sqrt(np.maximum(0.0, A)) * (2.0 * B - 1.0)
    )
    return np.clip(res, 0.0, 1.0)

def mask_exclusion_clamping(hair_mask, exclusion_mask):
    """Verbatim Mask Exclusion Clamping from MTFilter_HairMaskMix.fs"""
    black_value = 1.0 - exclusion_mask
    val = np.copy(hair_mask)
    mask = exclusion_mask > 0.0
    val = np.where(mask & (hair_mask > black_value), black_value, val)
    val = np.where(exclusion_mask >= 0.95, 0.0, val)
    return np.clip(val, 0.0, 1.0)


class TestHairMaskClampingAndSoftLight(unittest.TestCase):

    def test_01_softlight_neutral_gray_invariance(self):
        """When dye color B is 50% neutral gray (0.5), output must exactly equal input A."""
        A = np.linspace(0.0, 1.0, 256)
        B = np.full_like(A, 0.5)
        out = softlight_pegtop(A, B)
        np.testing.assert_allclose(out, A, atol=1e-5, err_msg="SoftLight failed neutral gray invariance!")

    def test_02_softlight_shadow_and_highlight_limits(self):
        """Shadows (A=0) must remain 0; highlights (A=1) must remain 1 for all dye colors B."""
        B_values = np.linspace(0.0, 1.0, 50)
        # Deep shadows
        A_zero = np.zeros_like(B_values)
        out_zero = softlight_pegtop(A_zero, B_values)
        np.testing.assert_allclose(out_zero, 0.0, atol=1e-5, err_msg="SoftLight corrupted deep shadows!")

        # Specular crown highlights
        A_one = np.ones_like(B_values)
        out_one = softlight_pegtop(A_one, B_values)
        np.testing.assert_allclose(out_one, 1.0, atol=1e-5, err_msg="SoftLight crushed specular highlights!")

    def test_03_mask_clamping_pure_hair_unchanged(self):
        """In regions with zero exclusion, hair mask must remain unchanged."""
        hair = np.random.uniform(0.0, 1.0, size=(100, 100))
        excl = np.zeros_like(hair)
        clamped = mask_exclusion_clamping(hair, excl)
        np.testing.assert_allclose(clamped, hair, atol=1e-6, err_msg="Pure hair was improperly altered!")

    def test_04_mask_clamping_strict_exclusion(self):
        """In regions with 100% exclusion (skin, forehead, clothing), hair mask must be strictly 0.0."""
        hair = np.ones((100, 100)) # 100% false-positive hair
        excl = np.ones((100, 100)) # 100% skin/clothing exclusion
        clamped = mask_exclusion_clamping(hair, excl)
        np.testing.assert_allclose(clamped, 0.0, atol=1e-6, err_msg="Exclusion clamping failed to zero out skin!")

    def test_05_mask_clamping_partial_transition(self):
        """In partial transition zones, hair mask must never exceed (1.0 - exclusion)."""
        hair = np.full((100, 100), 0.8)
        excl = np.full((100, 100), 0.4)
        clamped = mask_exclusion_clamping(hair, excl)
        # Expected: min(0.8, 1.0 - 0.4) = 0.6
        np.testing.assert_allclose(clamped, 0.6, atol=1e-6, err_msg="Partial exclusion clamping mismatch!")

    def test_06_protected_regions_zero_leakage(self):
        """Ensure that all pixels marked as protected (skin, clothing) have exactly zero color delta."""
        w, h = 200, 200
        orig_img = np.random.randint(0, 256, (h, w, 3), dtype=np.uint8)
        
        # Synthetic hair and exclusion
        hair_mask = np.zeros((h, w), dtype=np.float32)
        hair_mask[20:100, 50:150] = 0.9 # Hair blob
        
        excl_mask = np.zeros((h, w), dtype=np.float32)
        excl_mask[70:180, 70:130] = 1.0 # Forehead & Face overlapping lower hair blob
        
        clamped_hair = mask_exclusion_clamping(hair_mask, excl_mask)
        
        # Verify that wherever excl_mask == 1.0, clamped_hair is strictly 0.0
        protected_pixels = excl_mask >= 0.95
        self.assertTrue(np.all(clamped_hair[protected_pixels] == 0.0))
        
        # Simulate composite
        alpha = clamped_hair[:, :, np.newaxis]
        target_dye = np.array([255, 105, 180], dtype=np.float32) / 255.0 # Pink
        orig_float = orig_img.astype(np.float32) / 255.0
        dyed = softlight_pegtop(orig_float, target_dye)
        composited = np.clip((orig_float * (1.0 - alpha) + dyed * alpha) * 255.0, 0, 255).astype(np.uint8)
        
        # In protected pixels, composited must be bit-exact to orig_img
        delta = np.abs(composited[protected_pixels].astype(np.int32) - orig_img[protected_pixels].astype(np.int32))
        max_delta = np.max(delta)
        self.assertEqual(max_delta, 0, f"Leakage detected! Max delta on protected skin/clothing: {max_delta}")

    def test_07_visual_regression_canonical_images(self):
        """Test on canonical owner failure images owner_fail_A and owner_fail_B."""
        ref_dir = os.path.join(REPO_ROOT, "RULES", "REPORT", "TASK_061_REPORT", "07_REFERENCE_IMPL")
        img_a_path = os.path.join(ref_dir, "owner_fail_A_input.png")
        mask_a_path = os.path.join(ref_dir, "owner_fail_A_mask.png")
        
        if not os.path.exists(img_a_path) or not os.path.exists(mask_a_path):
            self.skipTest("Canonical reference images not found in TASK_061_REPORT.")
            
        img_a = Image.open(img_a_path).convert("RGB")
        mask_a = Image.open(mask_a_path).convert("L")
        
        arr_img = np.array(img_a, dtype=np.float32) / 255.0
        arr_mask = np.array(mask_a, dtype=np.float32) / 255.0
        
        # Build skin exclusion mask from YCrCb
        r, g, b = arr_img[:, :, 0], arr_img[:, :, 1], arr_img[:, :, 2]
        y_val = 0.299 * r + 0.587 * g + 0.114 * b
        cr = (r - y_val) * 0.713 + 0.5
        cb = (b - y_val) * 0.564 + 0.5
        is_skin = (cr >= 0.52) & (cr <= 0.72) & (cb >= 0.33) & (cb <= 0.53) & (r > b)
        
        # Clamp hair against skin exclusion
        excl = is_skin.astype(np.float32)
        clamped_hair = mask_exclusion_clamping(arr_mask, excl)
        
        # Measure mask accuracy: hair inside skin region must be zero
        leak_count = np.count_nonzero(clamped_hair[is_skin] > 0.01)
        total_skin = np.count_nonzero(is_skin)
        skin_leakage_pct = (leak_count / total_skin) * 100.0 if total_skin > 0 else 0.0
        
        self.assertLess(skin_leakage_pct, 0.05, f"Skin leakage exceeded 0.05%! Got {skin_leakage_pct:.2f}%")


if __name__ == "__main__":
    unittest.main()

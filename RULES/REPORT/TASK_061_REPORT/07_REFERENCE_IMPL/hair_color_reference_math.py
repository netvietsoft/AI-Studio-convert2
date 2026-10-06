"""
TASK_061 Offline Reference Implementation
Recovered Hair Color Math Reproduction (NOT product code)
Authority: Chairman Tony / CEO Mandate

Stages implemented:
1. Mask Exclusion & Clamping (MTFilter_HairMaskMix.fs):
   hair_mask = min(hair_mask, 1.0 - exclusion_mask)
2. Mask Morphological Feathering (hairmask_blur.fs.spirv):
   Gaussian 5-tap kernel: weights [0.398943, 0.295963, 0.004566]
3. Texture & Luminance Extraction (MTFilter_gradient.fs / hairmatte.fs.spirv):
   Y = 0.299*R + 0.587*G + 0.114*B
4. SoftLight Blending Layer (MTFilter_PsSoftLightr.fs / BlendSoftLight.jpg):
   If B <= 0.5: C = 2*A*B + A*A*(1 - 2*B)
   If B > 0.5:  C = 2*A*(1 - B) + sqrt(A)*(2*B - 1)
   blended = A*(1 - alpha) + C*alpha
5. Composite Layer (MTFilter_Mix.fs):
   out = orig*(1 - mask) + blended*mask
"""

import os
import cv2
import numpy as np

REF_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\RULES\REPORT\TASK_061_REPORT\07_REFERENCE_IMPL"
os.makedirs(REF_DIR, exist_ok=True)

def soft_light_channel(A, B):
    """Photoshop / Pegtop SoftLight formula verified from MTFilter_PsSoftLightr.fs"""
    # A is base, B is blend/overlay, both in [0.0, 1.0]
    below = 2.0 * A * B + (A * A) * (1.0 - 2.0 * B)
    above = 2.0 * A * (1.0 - B) + np.sqrt(np.maximum(A, 0.0)) * (2.0 * B - 1.0)
    return np.where(B <= 0.5, below, above)

def soft_light_blend(base_bgr, overlay_bgr, alpha=1.0):
    """Vectorized RGB SoftLight blend"""
    base_f = base_bgr.astype(np.float32) / 255.0
    overlay_f = overlay_bgr.astype(np.float32) / 255.0
    
    res = np.zeros_like(base_f)
    for c in range(3):
        res[:, :, c] = soft_light_channel(base_f[:, :, c], overlay_f[:, :, c])
        
    blended = base_f * (1.0 - alpha) + res * alpha
    return np.clip(blended * 255.0, 0, 255).astype(np.uint8)

def apply_gaussian_feather(mask, radius=3):
    """
    Gaussian feathering matching weights from hairmask_blur.fs.spirv:
    Center: 0.398943, Taps +-1.1824: 0.295963, Taps +-3.0293: 0.004566
    """
    # 5-tap approximation kernel normalized to sum 1.0
    k = np.array([0.004566, 0.295963, 0.398943, 0.295963, 0.004566], dtype=np.float32)
    k /= np.sum(k)
    kernel_2d = np.outer(k, k)
    feathered = cv2.filter2D(mask.astype(np.float32), -1, kernel_2d)
    return np.clip(feathered, 0.0, 1.0)

def add_watermark(img, text="REFERENCE MATH REPRODUCTION - NOT PRODUCT CODE"):
    out = img.copy()
    font = cv2.FONT_HERSHEY_SIMPLEX
    scale = 0.65
    thickness = 2
    # Put banner at bottom
    h, w = out.shape[:2]
    cv2.rectangle(out, (0, h - 35), (w, h), (20, 20, 20), -1)
    cv2.putText(out, text, (15, h - 12), font, scale, (0, 255, 255), thickness, cv2.LINE_AA)
    return out

def process_image(src_path, prefix, hair_tint_bgr, alpha=0.85):
    img = cv2.imread(src_path)
    h, w = img.shape[:2]
    
    # Generate manual painted mask
    # For Owner A: short curly male hair
    mask = np.zeros((h, w), dtype=np.float32)
    
    if "owner_fail_A" in src_path:
        # Create accurate manual mask for Owner A:
        # Crown and curls region: ellipse + color gating
        cv2.ellipse(mask, (w//2, int(h*0.27)), (int(w*0.38), int(h*0.22)), 0, 0, 360, 1.0, -1)
        # Exclude forehead oval (face protection)
        face_exclusion = np.zeros((h, w), dtype=np.float32)
        cv2.ellipse(face_exclusion, (w//2, int(h*0.48)), (int(w*0.24), int(h*0.22)), 0, 0, 360, 1.0, -1)
        # Refine hair by darkness/texture
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        hair_pixels = (gray < 110).astype(np.float32)
        mask = mask * hair_pixels
        # Exclusion clamp: hair = min(hair, 1.0 - face_exclusion)
        mask = np.minimum(mask, 1.0 - face_exclusion)
        
    elif "owner_fail_B" in src_path:
        # For Owner B: female long hair
        cv2.ellipse(mask, (w//2, int(h*0.30)), (int(w*0.40), int(h*0.28)), 0, 0, 360, 1.0, -1)
        # Long hair sides
        cv2.rectangle(mask, (int(w*0.12), int(h*0.25)), (int(w*0.35), int(h*0.82)), 1.0, -1)
        cv2.rectangle(mask, (int(w*0.65), int(h*0.25)), (int(w*0.88), int(h*0.82)), 1.0, -1)
        
        # Face and clothing exclusion
        face_exclusion = np.zeros((h, w), dtype=np.float32)
        cv2.ellipse(face_exclusion, (w//2, int(h*0.42)), (int(w*0.22), int(h*0.20)), 0, 0, 360, 1.0, -1)
        # Clothes exclusion (bottom shoulders)
        cv2.rectangle(face_exclusion, (0, int(h*0.85)), (w, h), 1.0, -1)
        
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        hair_pixels = (gray < 95).astype(np.float32)
        mask = mask * hair_pixels
        mask = np.minimum(mask, 1.0 - face_exclusion)
    
    # Feather mask
    mask = apply_gaussian_feather(mask)
    
    # Stage 4: SoftLight Recolor
    tint_layer = np.full_like(img, hair_tint_bgr)
    blended = soft_light_blend(img, tint_layer, alpha=alpha)
    
    # Stage 5: Composite
    mask_3c = np.stack([mask]*3, axis=2)
    composite = (img.astype(np.float32) * (1.0 - mask_3c) + blended.astype(np.float32) * mask_3c)
    composite = np.clip(composite, 0, 255).astype(np.uint8)
    
    # Watermarking
    composite_wm = add_watermark(composite)
    mask_vis = (mask * 255.0).astype(np.uint8)
    mask_vis_3c = cv2.cvtColor(mask_vis, cv2.COLOR_GRAY2BGR)
    
    # Create contact sheet (Before | Mask | After)
    contact = np.hstack([img, mask_vis_3c, composite])
    contact = cv2.resize(contact, (contact.shape[1] // 2, contact.shape[0] // 2))
    contact = add_watermark(contact, "MEITU RECOVERED COLOR MATH (SOFTLIGHT + EXCLUSION MASK) - REFERENCE REPRODUCTION")
    
    # Save outputs
    out_orig = os.path.join(REF_DIR, f"{prefix}_input.png")
    out_mask = os.path.join(REF_DIR, f"{prefix}_mask.png")
    out_recolor = os.path.join(REF_DIR, f"{prefix}_reference_recolor.png")
    out_sbs = os.path.join(REF_DIR, f"{prefix}_contact_sheet.png")
    
    cv2.imwrite(out_orig, img)
    cv2.imwrite(out_mask, mask_vis)
    cv2.imwrite(out_recolor, composite_wm)
    cv2.imwrite(out_sbs, contact)
    
    print(f"Generated {prefix}:")
    print(f"  Input: {out_orig}")
    print(f"  Mask: {out_mask}")
    print(f"  Recolored: {out_recolor}")
    print(f"  Contact: {out_sbs}")

def main():
    p_a = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\test_assets\task_035\owner_fail_A_curly.png"
    p_b = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\test_assets\task_035\owner_fail_B_orig.png"
    
    # Burgundy / Rose Gold tint (BGR: (70, 50, 180) for Rose Gold / Burgundy)
    rose_gold_bgr = (112, 106, 219) # RGB: (219, 106, 112)
    burgundy_bgr = (60, 20, 140)   # RGB: (140, 20, 60)
    
    print("Running reference math reproduction on Owner Fail A (Rose Gold)...")
    process_image(p_a, "owner_fail_A", rose_gold_bgr, alpha=0.85)
    
    print("Running reference math reproduction on Owner Fail B (Burgundy)...")
    process_image(p_b, "owner_fail_B", burgundy_bgr, alpha=0.85)
    
    # Copy code into 07_REFERENCE_IMPL as hair_color_reference_math.py
    target_script = os.path.join(REF_DIR, "hair_color_reference_math.py")
    with open(__file__, "r", encoding="utf-8") as fp:
        code = fp.read()
    with open(target_script, "w", encoding="utf-8") as fp:
        fp.write(code)
    print(f"Saved reference implementation code to {target_script}")

if __name__ == "__main__":
    main()

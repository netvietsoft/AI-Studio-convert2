import cv2
import numpy as np

def rgb_to_oklab(r, g, b):
    # vectorized sRGB to OKLab
    def to_linear(c):
        return np.where(c <= 0.04045, c / 12.92, ((c + 0.055) / 1.055) ** 2.4)
    lr = to_linear(r)
    lg = to_linear(g)
    lb = to_linear(b)
    
    l = np.cbrt(0.4122214708 * lr + 0.5363325363 * lg + 0.0514459929 * lb)
    m = np.cbrt(0.2119034982 * lr + 0.6806995451 * lg + 0.1073969566 * lb)
    s = np.cbrt(0.0883024619 * lr + 0.2817188376 * lg + 0.6299787005 * lb)
    
    L = 0.2104542553 * l + 0.7936177850 * m - 0.0040720468 * s
    a = 1.9779984951 * l - 2.4285922050 * m + 0.4505937099 * s
    bCoord = 0.0259040371 * l + 0.7827717662 * m - 0.8086757660 * s
    return L, a, bCoord

def oklab_to_rgb(L, a, bCoord):
    l = L + 0.3963377774 * a + 0.2158037573 * bCoord
    m = L - 0.1055613458 * a - 0.0638541728 * bCoord
    s = L - 0.0894841775 * a - 1.2914855480 * bCoord
    
    l3 = l * l * l
    m3 = m * m * m
    s3 = s * s * s
    
    lr = +4.0767434721 * l3 - 3.3077115913 * m3 + 0.2309699292 * s3
    lg = -1.2684380046 * l3 + 2.6097574011 * m3 - 0.3413193965 * s3
    lb = -0.0041960863 * l3 - 0.7034186147 * m3 + 1.7076147010 * s3
    
    def from_linear(c):
        c_clamped = np.clip(c, 0.0, 1.0)
        return np.where(c_clamped <= 0.0031308, c_clamped * 12.92, 1.055 * (c_clamped ** (1.0 / 2.4)) - 0.055)
    
    r = from_linear(lr)
    g = from_linear(lg)
    b = from_linear(lb)
    return np.clip(r, 0.0, 1.0), np.clip(g, 0.0, 1.0), np.clip(b, 0.0, 1.0)

def apply_salon_dye(img_rgb, alpha_mask, target_rgb, bleach_power=0.82, intensity=0.75, gloss=0.65, shadow_pres=0.88):
    h, w = img_rgb.shape[:2]
    r_chan = img_rgb[:,:,0] / 255.0
    g_chan = img_rgb[:,:,1] / 255.0
    b_chan = img_rgb[:,:,2] / 255.0
    
    # 1. Convert source to OKLab
    orig_L, orig_a, orig_b = rgb_to_oklab(r_chan, g_chan, b_chan)
    
    # 2. Target color in OKLab
    tgt_r, tgt_g, tgt_b = target_rgb[0] / 255.0, target_rgb[1] / 255.0, target_rgb[2] / 255.0
    tgt_L, tgt_a, tgt_b = rgb_to_oklab(tgt_r, tgt_g, tgt_b)
    
    # 3. Multiscale Luminance Decomposition:
    # base_L represents the gross shape/lighting (5x5 box filter)
    base_L = cv2.blur(orig_L, (5, 5))
    
    # High-frequency strand micro-contrast ratio:
    # In real hair, strand highlights and shadows modulate the base lighting
    strand_ratio = np.clip((orig_L + 0.03) / (base_L + 0.03), 0.65, 1.55)
    strand_detail = orig_L - base_L
    
    # 4. Melanin Bleaching / Lightness Lift:
    # Deep crevice shadows (where orig_L is very low) are preserved
    shadow_factor = np.clip(base_L / 0.35, 0.20, 1.0) * shadow_pres + (1.0 - shadow_pres)
    lift_amount = tgt_L - base_L
    
    # Melanin lift curve: dark hair needs progressive lift
    melanin_curve = np.where(base_L > 0, 0.38 + 0.62 * np.sqrt(np.clip(base_L, 0.0, 1.0)), 0.38)
    lifted_base_L = base_L + lift_amount * bleach_power * melanin_curve * shadow_factor
    lifted_base_L = np.clip(lifted_base_L, 0.02, 0.98)
    
    # Re-apply 100% strand micro-variation to lifted base
    final_L = np.clip(lifted_base_L * strand_ratio + strand_detail * 0.40, 0.01, 0.99)
    
    # 5. Chroma Deposition (Toner):
    # Chroma is strongest in midtones; deep shadows and glints have controlled chroma
    midtone_weight = 4.0 * final_L * (1.0 - final_L)
    effective_dye = np.clip(0.40 + 0.60 * midtone_weight, 0.0, 1.0) * shadow_factor
    
    final_a = orig_a * (1.0 - effective_dye) + tgt_a * effective_dye
    final_b = orig_b * (1.0 - effective_dye) + tgt_b * effective_dye
    
    # 6. Specular Glint & Sheen Preservation:
    # Natural hair sheen reflects ambient neutral light
    spec_strength = np.clip((orig_L - 0.45) / 0.40, 0.0, 1.0) * gloss
    final_a = final_a * (1.0 - spec_strength * 0.45) + orig_a * (spec_strength * 0.45)
    final_b = final_b * (1.0 - spec_strength * 0.45) + orig_b * (spec_strength * 0.45)
    
    # Convert dyed OKLab back to sRGB
    out_r, out_g, out_b = oklab_to_rgb(final_L, final_a, final_b)
    dyed_rgb = np.stack([out_r, out_g, out_b], axis=2) * 255.0
    
    # 7. Alpha Compositing with original
    eff_alpha = (alpha_mask * np.clip(intensity, 0.0, 1.0))[:, :, None]
    orig_f = img_rgb.astype(np.float32)
    final_rgb = np.clip(orig_f * (1.0 - eff_alpha) + dyed_rgb * eff_alpha, 0, 255).astype(np.uint8)
    
    return final_rgb

print("apply_salon_dye ready")

# Test on portrait_0_curly with Rose Gold, Platinum, Burgundy, Smokey Silver
img = cv2.imread("scratch/hair_test_assets/portrait_0_curly.png")
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
alpha_A = cv2.imread("scratch/owner_evidence/rebuild_alpha_A.png", cv2.IMREAD_GRAYSCALE).astype(np.float32) / 255.0

presets = [
    ("rose_gold", [225, 140, 160], 0.82, 0.75, 0.65),
    ("platinum", [238, 222, 172], 0.92, 0.75, 0.75),
    ("burgundy", [125, 22, 44], 0.38, 0.75, 0.55),
    ("smokey_silver", [192, 198, 210], 0.88, 0.75, 0.75)
]

for name, rgb, bp, inten, gl in presets:
    res = apply_salon_dye(img_rgb, alpha_A, rgb, bleach_power=bp, intensity=inten, gloss=gl)
    cv2.imwrite(f"scratch/owner_evidence/salon_test_{name}.png", cv2.cvtColor(res, cv2.COLOR_RGB2BGR))
    print(f"Saved salon_test_{name}.png")

import numpy as np
from PIL import Image

img = Image.open(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg')
orig = np.array(img).copy()
h, w, _ = orig.shape

# Monk photo visible ear: Left side (viewer's left)
# Roughly: jaw attachment x ~ 285, outer rim x ~ 240
# y from 225 (helix top) to 340 (lobe bottom)
# Occluded side: Right side (viewer's right). Yaw offset > 0.14 -> 100% Occluded!

out_img = orig.copy().astype(np.float32)

y_top = 225
y_bot = 340
h_ear = y_bot - y_top

for y in range(y_top, y_bot):
    # Normalized vertical coordinate
    v = (y - y_top) / float(h_ear)
    
    # Anatomical outer rim curve x_rim(y) and inner attach curve x_jaw(y)
    # The ear is on the left, so x_rim < x_jaw
    # Model ear shape: widest at v=0.35..0.55
    lobe_bulge = np.sin(v * np.pi)
    x_jaw = 285.0 - 5.0 * np.sin(v * np.pi)
    x_rim = 242.0 - 14.0 * np.sin(v * np.pi)
    
    row_w = x_jaw - x_rim
    if row_w <= 1.0: continue
    
    for x in range(int(x_rim), int(x_jaw)):
        # Check actual pixel to protect glasses / hair / dark background
        r, g, b = orig[y, x, :3].astype(np.float32)
        
        # Must be ear skin
        lum = 0.299 * r + 0.587 * g + 0.114 * b
        if lum < 35.0 or lum > 210.0: continue
        if r <= g or (r - b) < 8: continue
        
        # Normalized lateral coordinate from jaw (0) to rim (1)
        u = (x_jaw - x) / row_w
        
        # Edge feathering
        edge_fade = np.sin(u * np.pi) * np.sin(v * np.pi)
        
        # Physiological capillary perfusion weight
        # Higher at outer helix (u > 0.6) and lower lobule (v > 0.65)
        capillary_weight = 0.6 + 0.4 * u + 0.3 * max(0.0, v - 0.6)
        w_pixel = edge_fade * capillary_weight
        w_pixel = np.clip(w_pixel, 0.0, 1.0)
        
        # Apply natural rosy flush (+100%)
        # Warm capillary blood flush
        target_r = min(255.0, r * 1.18 + 14.0)
        target_g = g * 0.94
        target_b = min(255.0, b * 1.03 + 5.0)
        
        out_img[y, x, 0] = r * (1.0 - w_pixel) + target_r * w_pixel
        out_img[y, x, 1] = g * (1.0 - w_pixel) + target_g * w_pixel
        out_img[y, x, 2] = b * (1.0 - w_pixel) + target_b * w_pixel

# Notice: On the right side of the face (viewer's right, monk's occluded left ear):
# ZERO pixels are touched! Right ear is 100% occluded!

res = Image.fromarray(np.clip(out_img, 0, 255).astype(np.uint8))
res.save(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\test_monk_physiological_blush.png')
print("Saved test image: scratch/test_monk_physiological_blush.png")

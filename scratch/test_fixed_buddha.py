import sys
sys.stdout.reconfigure(encoding='utf-8')
from PIL import Image
import numpy as np

img = Image.open('app/src/main/assets/sample_model_portrait.jpg')
arr = np.array(img)[:, :, :3]
h, w, _ = arr.shape

# Calibrate skin on face:
face_patch = arr[285:325, 340:380, :3].astype(np.float32)
mean_face = np.mean(face_patch, axis=(0, 1))
sum_f = np.sum(mean_face)
face_r_chroma = mean_face[0] / sum_f
face_g_chroma = mean_face[1] / sum_f

def is_ear_skin(c):
    c = c.astype(np.float32)
    c_sum = np.sum(c[:3]) + 1e-5
    r_c = c[0] / c_sum
    g_c = c[1] / c_sum
    chroma_dist = np.hypot(r_c - face_r_chroma, g_c - face_g_chroma)
    return (chroma_dist < 0.045 and c[0] > c[1] and (c[0] - c[2]) > 12)

# Monk left ear center ~ (260, 300), radius ~ 40
cx = 260.0
cy = 300.0
rx = 40.0
ry = 50.0
factor = 0.70

new_result = arr.copy()
max_shift_y = ry * 0.48 * factor
max_shift_x = rx * 0.32 * factor

min_x = max(0, int(cx - rx * 1.4))
max_x = min(w - 1, int(cx + rx * 1.4))
min_y = max(0, int(cy - ry * 1.1))
max_y = min(h - 1, int(cy + ry * 1.6))
jaw_x = 285.0

for py in range(min_y, max_y + 1):
    for px in range(min_x, max_x + 1):
        dist_to_face = jaw_x - px
        if dist_to_face < -6.0: continue
        fg = min(1.0, max(0.0, (dist_to_face + 6.0) / 8.0))
        face_guard = fg * fg * (3.0 - 2.0 * fg)
        
        nx = (px - cx) / rx
        ny = (py - cy) / ry
        u = nx * nx + ny * ny
        if u >= 1.0: continue
        
        w_bell = (1.0 - u) * (1.0 - u) * factor * face_guard
        sy = py - max_shift_y * w_bell * (0.65 + 0.35 * max(0.0, ny))
        sx = px - (-1.0) * max_shift_x * w_bell * np.sin(np.pi * (1.0 - u))
        
        # Sample
        x0 = int(sx); y0 = int(sy)
        x1 = min(w - 1, x0 + 1); y1 = min(h - 1, y0 + 1)
        fx = sx - x0; fy = sy - y0
        c00 = arr[y0, x0, :3].astype(float)
        c10 = arr[y0, x1, :3].astype(float)
        c01 = arr[y1, x0, :3].astype(float)
        c11 = arr[y1, x1, :3].astype(float)
        sampled = (1-fx)*(1-fy)*c00 + fx*(1-fy)*c10 + (1-fx)*fy*c01 + fx*fy*c11
        
        # CHECK: Is sampled pixel EAR SKIN?
        # If sampled pixel is NOT ear skin, DO NOT WARP!
        if not is_ear_skin(sampled):
            continue
            
        new_result[py, px, :3] = np.clip(sampled, 0, 255).astype(np.uint8)

# Now check changed pixels:
diff = np.abs(arr[:, :, :3].astype(int) - new_result[:, :, :3].astype(int))
changed = np.any(diff > 0, axis=-1)
print(f"Total changed pixels: {np.sum(changed)}")

# Background check (pixels with x < 210):
bg_changed = np.sum(changed[:, :210])
print(f"Background pixels changed (x < 210): {bg_changed}")

# Check on the ear (x in [230, 285], y in [280, 350]):
ear_changed = np.sum(changed[280:350, 230:285])
print(f"Ear lobe pixels changed: {ear_changed}")

# Save comparison image
Image.fromarray(new_result).save('scratch/test_buddha_fixed.png')
print("Saved scratch/test_buddha_fixed.png")

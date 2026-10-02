import sys
sys.stdout.reconfigure(encoding='utf-8')
from PIL import Image
import numpy as np

img = Image.open('app/src/main/assets/sample_model_portrait.jpg')
arr = np.array(img)
h, w, c = arr.shape

# Let's test Buddha ear on Left ear:
# Monk left ear center ~ (260, 290), radius ~ 45 px
cx = 260.0
cy = 300.0
rx = 40.0
ry = 50.0
factor = 0.70 # 70%

# Old Buddha logic:
old_result = arr.copy()
max_shift_y = ry * 0.48 * factor
max_shift_x = rx * 0.32 * factor

min_x = max(0, int(cx - rx * 1.4))
max_x = min(w - 1, int(cx + rx * 1.4))
min_y = max(0, int(cy - ry * 1.1))
max_y = min(h - 1, int(cy + ry * 1.6))

jaw_x = 285.0 # jaw boundary

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
        
        # Bilinear sample
        x0 = int(sx); y0 = int(sy)
        x1 = min(w - 1, x0 + 1); y1 = min(h - 1, y0 + 1)
        fx = sx - x0; fy = sy - y0
        
        c00 = arr[y0, x0, :3].astype(float)
        c10 = arr[y0, x1, :3].astype(float)
        c01 = arr[y1, x0, :3].astype(float)
        c11 = arr[y1, x1, :3].astype(float)
        sampled = (1-fx)*(1-fy)*c00 + fx*(1-fy)*c10 + (1-fx)*fy*c01 + fx*fy*c11
        old_result[py, px, :3] = np.clip(sampled, 0, 255).astype(np.uint8)

# Check how many BACKGROUND pixels were modified in old_result:
# Background is outside the ear, e.g. px < 215 or py > 350
bg_changed = 0
for py in range(h):
    for px in range(w):
        if px < 210 or (px < 230 and py > 340):
            # Clearly background
            if not np.array_equal(arr[py, px, :3], old_result[py, px, :3]):
                bg_changed += 1

print(f"OLD Buddha Logic: Background pixels changed/warped = {bg_changed}")

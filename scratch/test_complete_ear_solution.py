import sys
sys.stdout.reconfigure(encoding='utf-8')
from PIL import Image
import numpy as np

img = Image.open('app/src/main/assets/sample_model_portrait.jpg')
arr = np.array(img)[:, :, :3]
h, w, _ = arr.shape
print(f"Loaded image: {w}x{h}")

# Calibrate face skin:
face_patch = arr[285:325, 340:380].astype(np.float32)
mean_face = np.mean(face_patch, axis=(0, 1))
sum_f = np.sum(mean_face) + 1e-5
face_r_c = mean_face[0] / sum_f
face_g_c = mean_face[1] / sum_f
face_lum = 0.299 * mean_face[0] + 0.587 * mean_face[1] + 0.114 * mean_face[2]

def is_face_skin(c):
    c = c.astype(np.float32)
    s = np.sum(c[:3]) + 1e-5
    rc = c[0] / s
    gc = c[1] / s
    chroma_dist = np.hypot(rc - face_r_c, gc - face_g_c)
    lum = 0.299 * c[0] + 0.587 * c[1] + 0.114 * c[2]
    lum_ratio = lum / (face_lum + 1e-5)
    return (chroma_dist < 0.038 and c[0] > c[1] and (c[0] - c[2]) > 12 and 0.40 <= lum_ratio <= 1.45)

# Jawline coordinates for monk:
# Left jaw x ~ 285, y in [240, 330]
# Right jaw x ~ 402, y in [240, 330]
eye_dist = 75.0

def detect_ear(is_left, jaw_x, top_y, bot_y):
    dir_x = -1 if is_left else 1
    max_d = int(0.70 * eye_dist)
    connected_rows = 0
    total_skin_px = 0
    max_w = 0
    helix_pts = []
    
    for y in range(top_y, bot_y):
        consec = 0
        outer_x = jaw_x
        row_has_ear = False
        
        for d in range(1, max_d):
            x = int(jaw_x + dir_x * d)
            if x < 0 or x >= w: break
            c = arr[y, x]
            if is_face_skin(c):
                consec += 1
                outer_x = x
            else:
                if consec >= 4:
                    row_has_ear = True
                    break
                elif consec == 0 and d >= 2:
                    # Non-skin gap between jaw and outside!
                    break
        if row_has_ear:
            connected_rows += 1
            total_skin_px += consec
            if consec > max_w: max_w = consec
            helix_pts.append((outer_x, y))
            
    is_visible = (connected_rows >= 12 and total_skin_px >= 80 and max_w >= 8)
    return is_visible, helix_pts

left_vis, left_helix = detect_ear(True, 285, 240, 330)
right_vis, right_helix = detect_ear(False, 402, 240, 330)

print(f"Detection Results: Left Ear Visible={left_vis}, Right Ear Visible={right_vis}")

# Now apply Tai Phật (Buddha Ear) on the image with the new rules:
# Rule 1: Right ear is NOT visible -> DO NOT TOUCH RIGHT SIDE AT ALL!
# Rule 2: Left ear is visible -> Modify left ear, but zero background warping!

result = arr.copy()

if left_vis:
    # Lobe center and radius
    cx = 260.0; cy = 300.0; rx = 40.0; ry = 50.0
    factor = 0.70
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
            
            x0 = int(sx); y0 = int(sy)
            x1 = min(w - 1, x0 + 1); y1 = min(h - 1, y0 + 1)
            fx = sx - x0; fy = sy - y0
            c00 = arr[y0, x0, :3].astype(float)
            c10 = arr[y0, x1, :3].astype(float)
            c01 = arr[y1, x0, :3].astype(float)
            c11 = arr[y1, x1, :3].astype(float)
            sampled = (1-fx)*(1-fy)*c00 + fx*(1-fy)*c10 + (1-fx)*fy*c01 + fx*fy*c11
            
            # Check: Only write if sampled pixel is ear skin!
            if not is_face_skin(sampled):
                continue
                
            result[py, px, :3] = np.clip(sampled, 0, 255).astype(np.uint8)

# Verification:
diff = np.abs(arr.astype(int) - result.astype(int))
changed = np.any(diff > 0, axis=-1)

# 1. Right side (x >= 350)
right_side_changed = np.sum(changed[:, 350:])
print(f"Right side (Face & Background) changed pixels = {right_side_changed} (MUST BE 0!)")

# 2. Left side background (x < 220)
left_bg_changed = np.sum(changed[:, :220])
print(f"Left side background (x < 220) changed pixels = {left_bg_changed} (MUST BE 0!)")

# 3. Ear pixels changed:
ear_changed = np.sum(changed[:, 220:300])
print(f"Ear pixels changed = {ear_changed} (MUST BE > 0 for visible ear modification)")

Image.fromarray(result).save('scratch/test_monk_buddha_perfect.png')
print("Saved scratch/test_monk_buddha_perfect.png")

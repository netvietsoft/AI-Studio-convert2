import sys
sys.stdout.reconfigure(encoding='utf-8')
from PIL import Image
import numpy as np

img = Image.open('app/src/main/assets/sample_model_portrait.jpg')
arr = np.array(img)[:, :, :3]
h, w, _ = arr.shape

def is_skin_rgb(r, g, b):
    mx = max(r, g, b)
    mn = min(r, g, b)
    if mx < 40 or (mx - mn) < 14: return False
    sat = (mx - mn) / mx
    if sat < 0.12: return False
    if r <= g + 8 or g <= int(b * 0.70): return False
    rf, gf, bf = float(r), float(g), float(b)
    cr = 128.0 + 0.5 * rf - 0.418688 * gf - 0.081312 * bf
    cb = 128.0 - 0.168736 * rf - 0.331264 * gf + 0.5 * bf
    return (cr >= 130.0 and cr <= 205.0 and cb >= 70.0 and cb <= 135.0)

# Monk face landmarks approx:
# Left jaw x ~ 285, y in [240, 330]
# Right jaw x ~ 410, y in [240, 330]
eye_dist = 75.0

def scan_outward(is_left, jaw_x, min_y, max_y):
    dir_x = -1 if is_left else 1
    max_d = int(0.70 * eye_dist)
    helix_pts = []
    
    for y in range(min_y, max_y):
        # 1. Connectedness check at jaw attachment
        is_connected = False
        consec_skin = 0
        outer_x = jaw_x
        
        for d in range(1, max_d):
            x = int(jaw_x + dir_x * d)
            if x < 0 or x >= w: break
            r, g, b = arr[y, x]
            if is_skin_rgb(r, g, b):
                consec_skin += 1
                outer_x = x
            else:
                if consec_skin >= 3:
                    # Found outer boundary of ear!
                    is_connected = True
                    break
                elif consec_skin == 0 and d >= 3:
                    # Not connected to jaw!
                    break
                    
        if is_connected and consec_skin >= 4:
            helix_pts.append((outer_x, y))
            
    print(f"{'Left' if is_left else 'Right'} side outward scan: found {len(helix_pts)} connected helix points")
    if len(helix_pts) < 12:
        return False, []
    return True, helix_pts

left_ok, left_helix = scan_outward(True, 285, 240, 330)
right_ok, right_helix = scan_outward(False, 412, 240, 330)

print(f"VERDICT: Left Ear = {left_ok}, Right Ear = {right_ok}")

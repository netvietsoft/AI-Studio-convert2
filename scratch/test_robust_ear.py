import numpy as np
from PIL import Image

# Load the monk image
img = Image.open(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg')
arr = np.array(img)
h, w, _ = arr.shape
print(f"Image dimensions: {w}x{h}")

# In the monk photo, let's verify landmarks and eye positions:
# The monk's face:
# Left eye (on image): roughly (320, 275)
# Right eye (on image): roughly (395, 275)
# Nose tip: roughly (375, 335)
# Chin: roughly (380, 470)
# Left contour (monk's right ear side): x ~ 235..285, y ~ 240..350
# Right contour (monk's left cheek silhouette): x ~ 435..450, y ~ 260..360

lx_eye, ly_eye = 320.0, 275.0
rx_eye, ry_eye = 395.0, 275.0
eye_dist = np.hypot(rx_eye - lx_eye, ry_eye - ly_eye)
eye_mid_x = (lx_eye + rx_eye) / 2.0
nose_x, nose_y = 375.0, 335.0

print(f"Eye Distance: {eye_dist:.1f} px, Eye Mid X: {eye_mid_x:.1f}")
nose_offset = (nose_x - eye_mid_x) / eye_dist
print(f"Nose Yaw Offset: {nose_offset:.3f}")

# Contour outer margins:
# Left margin from left eye (320) to left contour (240): 320 - 240 = 80 px (1.06 * eye_dist)
# Right margin from right eye (395) to right contour (440): 440 - 395 = 45 px (0.60 * eye_dist)
# For severe profile, margin can be < 0.25 * eye_dist.

# Let's test the face skin sampling:
face_skin = arr[int(ly_eye+20):int(nose_y), int(lx_eye+15):int(rx_eye-15), :3].astype(np.float32)
mean_face = np.mean(face_skin, axis=(0, 1))
print(f"Calibrated Face Color: R={mean_face[0]:.1f}, G={mean_face[1]:.1f}, B={mean_face[2]:.1f}")
sum_f = np.sum(mean_face)
face_r_chroma = mean_face[0] / sum_f
face_g_chroma = mean_face[1] / sum_f
print(f"Face Chroma: r={face_r_chroma:.4f}, g={face_g_chroma:.4f}")

# Scan Left side for real ear (x < 300, y in [230, 360]):
def scan_ear(is_left, jaw_x, top_y, bot_y):
    dir_x = -1 if is_left else 1
    max_scan = int(0.65 * eye_dist)
    skin_pixels = []
    
    for y in range(int(top_y), int(bot_y)):
        row = arr[y, :, :3].astype(np.float32)
        consecutive_skin = 0
        for d in range(1, max_scan):
            x = int(jaw_x + dir_x * d)
            if x < 0 or x >= w: break
            c = row[x]
            lum = 0.299 * c[0] + 0.587 * c[1] + 0.114 * c[2]
            c_sum = np.sum(c) + 1e-5
            r_c = c[0] / c_sum
            g_c = c[1] / c_sum
            
            # Chroma distance to face skin
            dr = r_c - face_r_chroma
            dg = g_c - face_g_chroma
            chroma_dist = np.sqrt(dr*dr + dg*dg)
            
            # Lum ratio
            lum_ratio = lum / (0.299*mean_face[0] + 0.587*mean_face[1] + 0.114*mean_face[2])
            
            # Strict human skin match
            is_skin = (chroma_dist < 0.025) and (0.45 <= lum_ratio <= 1.40) and (c[0] > c[1]) and (c[0] - c[2] > 12)
            
            if is_skin:
                consecutive_skin += 1
                skin_pixels.append((x, y))
            else:
                if consecutive_skin >= 3:
                    break # hit outer boundary of ear
                    
    count = len(skin_pixels)
    if count < 50:
        return False, count, 0, 0
    xs = [p[0] for p in skin_pixels]
    ys = [p[1] for p in skin_pixels]
    ear_w = max(xs) - min(xs)
    ear_h = max(ys) - min(ys)
    return True, count, ear_w, ear_h

left_res = scan_ear(True, 290, 230, 360)
print(f"Left Ear Scan (Real Ear): has_ear={left_res[0]}, count={left_res[1]}, width={left_res[2]}, height={left_res[3]}")

# Right Ear Scan (Altar / Occluded side):
# From jaw contour x ~ 440 scanning rightward:
right_res = scan_ear(False, 440, 230, 360)
print(f"Right Ear Scan (Altar side): has_ear={right_res[0]}, count={right_res[1]}, width={right_res[2]}, height={right_res[3]}")

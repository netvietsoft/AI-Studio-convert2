import sys
sys.stdout.reconfigure(encoding='utf-8')
from PIL import Image
import numpy as np

img = Image.open('app/src/main/assets/sample_model_portrait.jpg')
arr = np.array(img)[:, :, :3]
h, w, _ = arr.shape
print(f"Image dimensions: {w}x{h}")

# The monk in sample_model_portrait.jpg:
# Left eye ~ (320, 275), Right eye ~ (395, 275)
# Nose tip ~ (375, 335), Chin ~ (380, 470)
# Let's verify face skin color:
# Sample skin between eyes and nose:
face_patch = arr[285:325, 340:380].astype(np.float32)
mean_face = np.mean(face_patch, axis=(0, 1))
print(f"Calibrated Face Color: R={mean_face[0]:.1f}, G={mean_face[1]:.1f}, B={mean_face[2]:.1f}")
sum_f = np.sum(mean_face)
face_r_chroma = mean_face[0] / sum_f
face_g_chroma = mean_face[1] / sum_f
print(f"Face Chroma: r={face_r_chroma:.4f}, g={face_g_chroma:.4f}")

# Jaw contour:
# Left jaw/tragus is at x ~ 285, y in [240, 340]
# Right jaw/cheek is at x ~ 410, y in [240, 340]
# Let's check connectedness:
# An ear must be PHYSICALLY ATTACHED to the head contour (x_jaw)
# That means from x_jaw, the very first pixels (d=1, 2, 3...) MUST be ear skin!
# If at d=1, 2, 3 it is dark background (shadow between cheek and altar), then there is NO ear attached to the cheek!

def test_ear_attachment(is_left, jaw_x, top_y, bot_y):
    dir_x = -1 if is_left else 1
    connected_rows = 0
    total_skin_px = 0
    max_d_span = 0
    
    for y in range(top_y, bot_y, 2):
        # Check first 5 pixels adjacent to jaw
        is_row_connected = True
        consec = 0
        for d in range(1, 6):
            x = int(jaw_x + dir_x * d)
            if x < 0 or x >= w: 
                is_row_connected = False
                break
            c = arr[y, x].astype(np.float32)
            c_sum = np.sum(c) + 1e-5
            r_c = c[0] / c_sum
            g_c = c[1] / c_sum
            chroma_dist = np.hypot(r_c - face_r_chroma, g_c - face_g_chroma)
            # Is it skin?
            if chroma_dist < 0.035 and c[0] > c[1] and c[0] - c[2] > 15:
                consec += 1
            else:
                is_row_connected = False
                break
        
        if is_row_connected:
            connected_rows += 1
            # Scan full ear width along this row
            row_skin = 0
            for d in range(1, 60):
                x = int(jaw_x + dir_x * d)
                if x < 0 or x >= w: break
                c = arr[y, x].astype(np.float32)
                c_sum = np.sum(c) + 1e-5
                chroma_dist = np.hypot(c[0]/c_sum - face_r_chroma, c[1]/c_sum - face_g_chroma)
                if chroma_dist < 0.040 and c[0] > c[1] and c[0] - c[2] > 15:
                    row_skin += 1
                    total_skin_px += 1
                else:
                    if row_skin >= 3:
                        break
            if row_skin > max_d_span:
                max_d_span = row_skin

    print(f"{'Left' if is_left else 'Right'} side: connected_rows={connected_rows}, total_skin_px={total_skin_px}, max_ear_width={max_d_span}")
    # Requirement for genuine ear: at least 15 connected rows and at least 100 skin pixels and ear width >= 8 px
    has_ear = (connected_rows >= 12 and total_skin_px >= 100 and max_d_span >= 10)
    return has_ear

left_has_ear = test_ear_attachment(True, 285, 240, 330)
right_has_ear = test_ear_attachment(False, 412, 240, 330)
print(f"VERDICT: Left Ear Recognized = {left_has_ear}, Right Ear Recognized = {right_has_ear}")

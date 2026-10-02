import sys
sys.stdout.reconfigure(encoding='utf-8')
from PIL import Image
import numpy as np

def analyze_photo(path, name):
    try:
        img = Image.open(path)
    except Exception as e:
        print(f"Cannot open {path}: {e}")
        return
    arr = np.array(img)[:, :, :3]
    h, w, _ = arr.shape
    print(f"\n--- Testing {name} ({w}x{h}) ---")
    
    # Simple face detector / center sample for testing
    # Find face center
    cx = w // 2
    cy = h // 2
    # Sample face skin
    face_patch = arr[cy-20:cy+20, cx-20:cx+20].astype(np.float32)
    mean_face = np.mean(face_patch, axis=(0, 1))
    sum_f = np.sum(mean_face) + 1e-5
    face_r_c = mean_face[0] / sum_f
    face_g_c = mean_face[1] / sum_f
    
    print(f"Face chroma: r={face_r_c:.4f}, g={face_g_c:.4f}")
    
    # Monk specific:
    if "monk" in name.lower() or w == 500:
        # left jaw ~ 285, right jaw ~ 412, y in [240, 330]
        l_jaw_x = 285
        r_jaw_x = 412
        y_top = 240
        y_bot = 330
    else:
        # Generic frontal face approx
        l_jaw_x = int(w * 0.38)
        r_jaw_x = int(w * 0.62)
        y_top = int(h * 0.35)
        y_bot = int(h * 0.55)
        
    def check_ear(is_left, jaw_x):
        dir_x = -1 if is_left else 1
        connected_rows = 0
        total_skin = 0
        max_width = 0
        
        for y in range(y_top, y_bot, 2):
            consec = 0
            for d in range(1, 40):
                x = int(jaw_x + dir_x * d)
                if x < 0 or x >= w: break
                c = arr[y, x].astype(np.float32)
                c_sum = np.sum(c) + 1e-5
                chroma_dist = np.hypot(c[0]/c_sum - face_r_c, c[1]/c_sum - face_g_c)
                is_skin = (chroma_dist < 0.040 and c[0] > c[1] and (c[0] - c[2]) > 12)
                
                if is_skin:
                    consec += 1
                    total_skin += 1
                else:
                    if consec >= 3:
                        break
                    elif consec == 0 and d > 3:
                        break # Gap between jaw and object -> NOT connected!
            if consec >= 3:
                connected_rows += 1
                if consec > max_width:
                    max_width = consec
                    
        is_visible = (connected_rows >= 12 and total_skin >= 80 and max_width >= 8)
        print(f"  {'Left' if is_left else 'Right'} side: connected_rows={connected_rows}, total_skin={total_skin}, max_w={max_width} -> Visible={is_visible}")
        return is_visible

    is_l = check_ear(True, l_jaw_x)
    is_r = check_ear(False, r_jaw_x)
    print(f"RESULT for {name}: Left Visible = {is_l}, Right Visible = {is_r}")

analyze_photo('app/src/main/assets/sample_model_portrait.jpg', 'Monk Tilted Photo')

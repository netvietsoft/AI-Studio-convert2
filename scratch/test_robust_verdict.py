import sys, os
sys.stdout.reconfigure(encoding='utf-8')
sys.path.insert(0, os.path.abspath('scratch'))
from test_complete_ear_solution import is_face_skin, arr, eye_dist

def detect_ear_robust(is_left, jaw_x, top_y, bot_y):
    dir_x = -1 if is_left else 1
    max_d = int(0.70 * eye_dist)
    min_required_width = max(14, int(0.18 * eye_dist))
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
            if x < 0 or x >= 500: break
            c = arr[y, x]
            if is_face_skin(c):
                consec += 1
                outer_x = x
            else:
                if consec >= min_required_width:
                    row_has_ear = True
                    break
                elif consec == 0 and d >= 2:
                    break
        if row_has_ear:
            connected_rows += 1
            total_skin_px += consec
            if consec > max_w: max_w = consec
            helix_pts.append((outer_x, y))
            
    is_visible = (connected_rows >= 15 and total_skin_px >= 250 and max_w >= min_required_width)
    tag = "Left" if is_left else "Right"
    print(f"  {tag}: connected_rows={connected_rows}, total_skin={total_skin_px}, max_w={max_w} (req >={min_required_width}) -> Visible={is_visible}")
    return is_visible

print("Robust Ear Detection on Monk:")
l_vis = detect_ear_robust(True, 285, 240, 330)
r_vis = detect_ear_robust(False, 402, 240, 330)
print(f"FINAL VERDICT: Left={l_vis}, Right={r_vis}")

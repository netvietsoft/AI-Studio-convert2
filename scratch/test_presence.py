import sys, os
sys.stdout.reconfigure(encoding='utf-8')
sys.path.insert(0, 'scratch')
from test_complete_ear_solution import is_face_skin, arr

def is_ear_truly_visible(is_left, jaw_x, y_top, y_mid, y_bot):
    dir_x = -1 if is_left else 1
    # Check upper half: y in [y_top, y_mid]
    upper_widths = []
    for y in range(y_top, y_mid, 2):
        consec = 0
        for d in range(1, 50):
            x = int(jaw_x + dir_x * d)
            if is_face_skin(arr[y, x]):
                consec += 1
            else:
                if consec >= 3: break
                elif consec == 0 and d >= 3: break
        upper_widths.append(consec)
        
    lower_widths = []
    for y in range(y_mid, y_bot, 2):
        consec = 0
        for d in range(1, 50):
            x = int(jaw_x + dir_x * d)
            if is_face_skin(arr[y, x]):
                consec += 1
            else:
                if consec >= 3: break
                elif consec == 0 and d >= 3: break
        lower_widths.append(consec)
        
    max_upper = max(upper_widths) if upper_widths else 0
    max_lower = max(lower_widths) if lower_widths else 0
    mean_upper = sum(upper_widths)/len(upper_widths) if upper_widths else 0
    mean_lower = sum(lower_widths)/len(lower_widths) if lower_widths else 0
    
    tag = "Left" if is_left else "Right"
    print(f"{tag}: max_upper={max_upper}, mean_upper={mean_upper:.1f}, max_lower={max_lower}, mean_lower={mean_lower:.1f}")
    
    # An ear must have BOTH a distinct upper ear structure (helix/scapha) and lower ear structure
    # With significant extension beyond cheek (>= 15px max, >= 8px mean)
    is_ear = (max_upper >= 15 and mean_upper >= 8 and max_lower >= 15 and mean_lower >= 8)
    return is_ear

print("Ear Anatomical Presence Check:")
l_present = is_ear_truly_visible(True, 285, 240, 275, 310)
r_present = is_ear_truly_visible(False, 402, 240, 275, 310)
print(f"VERDICT: Left Ear Present = {l_present}, Right Ear Present = {r_present}")

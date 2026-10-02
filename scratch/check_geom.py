import sys
sys.stdout.reconfigure(encoding='utf-8')
import numpy as np

lmks = {}
with open('scratch/test_complete_anatomy_fix.py', 'r', encoding='utf-8') as f:
    for line in f:
        line = line.strip().replace('dump = """', '').replace('"""', '')
        if ': (' in line:
            parts = line.split(': (')
            try:
                idx = int(parts[0])
                coords = parts[1].rstrip(')').split(',')
                lmks[idx] = (float(coords[0]), float(coords[1]))
            except: pass

print(f'Loaded {len(lmks)} landmarks')
lx, ly = lmks[104]
rx, ry = lmks[105]
nose_x, nose_y = lmks[60]
chin_x, chin_y = lmks[16]
l_tragus_x, l_tragus_y = lmks[0]
r_tragus_x, r_tragus_y = lmks[32]
l_lobe_attach_x, l_lobe_attach_y = lmks[4]
r_lobe_attach_x, r_lobe_attach_y = lmks[28]

eye_dist = float(np.hypot(rx - lx, ry - ly))
eye_mid_x = (lx + rx) * 0.5
yaw_offset = (nose_x - eye_mid_x) / eye_dist
yaw_deg = yaw_offset * 65.0

print(f'Eyes: Left=({lx:.1f}, {ly:.1f}), Right=({rx:.1f}, {ry:.1f}), eyeDist={eye_dist:.1f}')
print(f'Nose=({nose_x:.1f}, {nose_y:.1f}), Chin=({chin_x:.1f}, {chin_y:.1f})')
print(f'Left Tragus=({l_tragus_x:.1f}, {l_tragus_y:.1f}), Right Tragus=({r_tragus_x:.1f}, {r_tragus_y:.1f})')
print(f'Left Lobe Attach=({l_lobe_attach_x:.1f}, {l_lobe_attach_y:.1f}), Right Lobe Attach=({r_lobe_attach_x:.1f}, {r_lobe_attach_y:.1f})')
print(f'Yaw Offset={yaw_offset:.3f} (Yaw Deg={yaw_deg:.1f} deg)')

min_left_x = min(lmks[i][0] for i in range(5))
max_right_x = max(lmks[i][0] for i in range(28, 33))
left_margin = lx - min_left_x
right_margin = max_right_x - rx
w_left_cheek = abs(nose_x - min_left_x)
w_right_cheek = abs(max_right_x - nose_x)

print(f'minLeftX={min_left_x:.1f}, maxRightX={max_right_x:.1f}')
print(f'leftMargin={left_margin:.1f}, rightMargin={right_margin:.1f}')
print(f'wLeftCheek={w_left_cheek:.1f}, wRightCheek={w_right_cheek:.1f} (ratio={w_right_cheek/w_left_cheek:.2f})')

left_occluded_by_geom = (yaw_offset < -0.38) or (left_margin < 0.08 * eye_dist) or (w_left_cheek < 0.20 * w_right_cheek)
right_occluded_by_geom = (yaw_offset > 0.38) or (right_margin < 0.08 * eye_dist) or (w_right_cheek < 0.20 * w_left_cheek)

print(f'Old Geom Check: leftOccluded={left_occluded_by_geom}, rightOccluded={right_occluded_by_geom}')

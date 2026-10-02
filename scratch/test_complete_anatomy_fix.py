import cv2
import numpy as np

img = cv2.imread(r"C:\Users\PC.DESKTOP-81LIH38\.gemini\antigravity-ide\brain\56fd227d-6b4a-43e8-80a5-02015fa93579\scratch\pulled_gym.jpg")
h, w = img.shape[:2]

dump = """0: (354.7649, 313.48)
1: (355.8272, 326.643)
2: (354.42142, 344.17404)
3: (353.6342, 357.74603)
4: (353.99243, 370.61362)
5: (358.90817, 385.62396)
6: (359.01544, 395.6095)
7: (366.47726, 413.975)
8: (374.97986, 431.10208)
9: (378.95615, 447.0593)
10: (389.11343, 454.39862)
11: (399.1254, 464.45886)
12: (412.64572, 474.44418)
13: (428.37952, 485.60312)
14: (440.27188, 489.3395)
15: (458.03116, 496.39908)
16: (473.78918, 497.05063)
17: (489.31, 495.34805)
18: (501.63995, 485.50143)
19: (516.3961, 479.95944)
20: (524.13116, 467.4773)
21: (537.3553, 459.1067)
22: (545.1963, 449.45078)
23: (552.447, 435.52765)
24: (559.1587, 423.4923)
25: (562.29144, 411.73746)
26: (567.95325, 394.64243)
27: (573.0379, 384.4354)
28: (573.8076, 366.45825)
29: (569.85254, 350.8745)
30: (574.23474, 342.06915)
31: (571.7902, 325.74402)
32: (573.946, 308.28818)
33: (384.69324, 300.81158)
34: (395.8647, 288.99347)
35: (413.77744, 286.56238)
36: (436.93, 287.03455)
37: (452.2668, 294.76834)
38: (452.7002, 302.8428)
39: (435.01486, 301.2535)
40: (418.12003, 297.27515)
41: (395.76593, 300.2288)
42: (496.0674, 296.22766)
43: (510.72165, 290.0048)
44: (529.4077, 288.4324)
45: (544.76666, 286.45724)
46: (556.35693, 302.28342)
47: (544.0943, 299.617)
48: (526.53094, 296.7053)
49: (512.64404, 302.449)
50: (497.17822, 304.00354)
51: (475.8835, 313.20248)
52: (474.90878, 334.6934)
53: (477.30096, 352.98776)
54: (480.57333, 374.63712)
55: (455.2507, 323.61594)
56: (451.67725, 360.82913)
57: (440.92618, 378.7478)
58: (456.6393, 386.34464)
59: (464.48157, 387.56064)
60: (479.04218, 392.46628)
61: (490.732, 386.08575)
62: (494.0803, 384.9216)
63: (504.78906, 379.3352)
64: (497.76205, 363.44135)
65: (488.73563, 322.4666)
66: (399.15326, 322.32117)
67: (412.1427, 315.49115)
68: (422.95776, 315.28366)
69: (435.17444, 315.4388)
70: (443.49353, 327.06564)
71: (436.60266, 327.4481)
72: (423.32108, 326.8394)
73: (413.20517, 326.842)
74: (421.82294, 322.19858)
75: (498.2889, 323.35278)
76: (507.52393, 318.77036)
77: (520.66504, 316.68933)
78: (529.2359, 313.24164)
79: (542.22986, 322.83197)
80: (532.14484, 324.7106)
81: (518.75336, 325.48398)
82: (508.66855, 326.25848)
83: (522.03015, 319.39148)
84: (425.44394, 422.99634)
85: (444.81744, 413.56808)
86: (467.73764, 412.78555)
87: (474.68875, 412.75952)
88: (486.66208, 408.69016)
89: (503.75598, 411.2053)
90: (512.85974, 422.27032)
91: (502.7171, 430.4964)
92: (491.0727, 443.2257)
93: (474.56857, 444.30948)
94: (457.39752, 440.4438)
95: (439.8173, 434.17178)
96: (435.22186, 423.024)
97: (451.50925, 418.02484)
98: (474.412, 420.96173)
99: (496.732, 421.26132)
100: (507.93604, 425.14154)
101: (495.57095, 426.89853)
102: (472.89807, 427.99454)
103: (449.7477, 428.10327)
104: (427.67374, 318.26074)
105: (520.39685, 321.72675)"""

landmarks = []
for line in dump.strip().split("\n"):
    coords = line.split(":")[1].strip().replace("(", "").replace(")", "").split(",")
    landmarks.append([float(coords[0]), float(coords[1])])
landmarks = np.array(landmarks)

sx = w / 896.0
sy = h / 1200.0

out_mask = np.zeros((h, w), dtype=np.float32)
zone_type = np.zeros((h, w), dtype=np.uint8)

# 1. FACE POLYGON (No flawed door filter!)
jaw = [landmarks[i] for i in range(33)]
eyebrow_y = np.mean([landmarks[i][1] for i in range(33, 52)])
nose_y = landmarks[60][1]
face_h = max(40.0 * sy, nose_y - eyebrow_y)
forehead_top = max(5.0, eyebrow_y - face_h * 1.05)

pt_left = landmarks[0]
pt_right = landmarks[32]

forehead_pts = [
    [pt_right[0] + 30.0 * sx, pt_right[1] - face_h * 0.35],
    [pt_right[0] + 25.0 * sx, forehead_top],
    [(pt_left[0] + pt_right[0]) * 0.50, forehead_top - 10.0 * sy],
    [pt_left[0] - 18.0 * sx, forehead_top],
    [pt_left[0] - 22.0 * sx, pt_left[1] - face_h * 0.35]
]
face_poly = np.array(jaw + forehead_pts, dtype=np.int32)
cv2.fillPoly(out_mask, [face_poly], 1.0)
zone_type[out_mask > 0.5] = 1

# 2. NECK POLYGON (Overlap 8px with chin)
chin_y = landmarks[16][1]
neck_top_y = min(landmarks[4][1], landmarks[28][1])
neck_bottom = min(h - 1.0, chin_y + face_h * 0.95)

neck_jaw = [[landmarks[i][0], landmarks[i][1] - 8.0 * sy] for i in range(4, 29)]
neck_bottom_r = [landmarks[28][0] + 45.0 * sx, neck_bottom]
neck_bottom_l = [landmarks[4][0] - 45.0 * sx, neck_bottom]
neck_poly = np.array(neck_jaw + [neck_bottom_r, neck_bottom_l], dtype=np.int32)

neck_mask = np.zeros((h, w), dtype=np.float32)
cv2.fillPoly(neck_mask, [neck_poly], 1.0)

b = img[:,:,0].astype(np.float32)
g = img[:,:,1].astype(np.float32)
r = img[:,:,2].astype(np.float32)
Y = 0.299 * r + 0.587 * g + 0.114 * b
Cr = 128.0 + 0.5 * r - 0.418688 * g - 0.081312 * b

is_neck_skin = (Y >= 20.0) & (r >= g - 16) & (r >= b - 16) & (Cr >= 118.0)
y_grid, x_grid = np.ogrid[:h, :w]
neck_region = (neck_mask > 0.5) & (y_grid >= int(neck_top_y)) & (y_grid <= int(neck_bottom)) & is_neck_skin
out_mask[neck_region] = 1.0
zone_type[neck_region & (zone_type == 0)] = 2

# 3. BODY CANDIDATES & MORPHOLOGY
check_neck_y = max(0, int(neck_bottom - 6.0 * sy))
neck_bottom_skin_count = np.sum(out_mask[check_neck_y, :] > 0.5)

face_center_x = (landmarks[0][0] + landmarks[32][0]) * 0.5
face_w = max(40.0 * sx, landmarks[32][0] - landmarks[0][0])

if neck_bottom_skin_count >= 8:
    body_start_y = max(0, int(neck_top_y) - 5)
    body_cand = np.zeros((h, w), dtype=np.uint8)

    for y in range(body_start_y, h):
        if y < chin_y + 0.55 * face_h:
            t = max(0.0, (y - neck_top_y) / max(1.0, chin_y + 0.55 * face_h - neck_top_y))
            allowed_half_l = face_w * (0.65 + 1.05 * t)
            allowed_half_r = face_w * (0.65 + 1.05 * t)
        elif y < chin_y + 1.75 * face_h:
            allowed_half_l = face_w * 1.80
            allowed_half_r = face_w * 1.68
        else:
            allowed_half_l = face_w * 1.50
            allowed_half_r = face_w * 1.45

        min_body_x = max(0, int(face_center_x - allowed_half_l))
        max_body_x = min(w - 1, int(face_center_x + allowed_half_r))

        for x in range(min_body_x, max_body_x + 1):
            py_lum = Y[y, x]
            if py_lum < 18.0 or py_lum > 252.0: continue
            pr, pg, pb = r[y, x], g[y, x], b[y, x]

            # Reject green/blue floor tile
            if py_lum > 110.0 and (pg > pr + 6 or pb > pr + 8): continue
            # Reject dark trousers below hips
            if py_lum < 32.0 and y > chin_y + 2.0 * face_h: continue

            # Door rejection ONLY at true background positions:
            # Position A: Outside head
            is_door = False
            if y < chin_y + 0.6 * face_h and (x < landmarks[0][0] - 15.0 * sx or x > landmarks[32][0] + 15.0 * sx):
                if pr > 60 and (pr / (pg + 0.1) > 1.55) and (pr - pg > 24) and (abs(pg - pb) <= 15):
                    is_door = True
            # Position B: Through low arm gap (y > chin_y + 1.8 * face_h and x in [185, 215])
            if y > chin_y + 1.8 * face_h and (x < face_center_x - 0.95 * face_w and x > face_center_x - 1.45 * face_w):
                if pr > 60 and (pr / (pg + 0.1) > 1.55) and (pr - pg > 24) and (abs(pg - pb) <= 15):
                    is_door = True
            if is_door: continue

            # Reject ladder / yellow wall on far right
            if x > face_center_x + 1.25 * face_w:
                if pr < 90 and pg < 48 and pb < 42 and (pr - pg > 24): continue
                p_cr = Cr[y, x]
                p_cb = 128.0 - 0.168736 * pr - 0.331264 * pg + 0.5 * pb
                if py_lum > 120.0 and (pr - pg <= 8) and (p_cr - p_cb < 16.0): continue

            # Accept skin, shaded muscle, and tattoos (allow blue/black pigments)
            if pr >= pg - 25 and (pr >= pb - 35 or (py_lum < 60.0 and pb > pr)):
                body_cand[y, x] = 1

    # 2D Morphological closing
    rad_close = int(np.clip(14.0 * sx, 10, 20))
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (rad_close * 2 + 1, rad_close * 2 + 1))
    closed_mask = cv2.morphologyEx(body_cand, cv2.MORPH_CLOSE, kernel)

    # Clean background leaks
    for y in range(body_start_y, h):
        for x in range(w):
            if closed_mask[y, x] == 0: continue
            if x > face_center_x + 1.70 * face_w or x < face_center_x - 1.82 * face_w:
                closed_mask[y, x] = 0; continue
            pr, pg, pb = r[y, x], g[y, x], b[y, x]
            # Exterior door only
            if (y < chin_y + 0.6 * face_h and (x < landmarks[0][0] - 15.0 * sx or x > landmarks[32][0] + 15.0 * sx)) or \
               (y > chin_y + 1.8 * face_h and (x < face_center_x - 0.95 * face_w and x > face_center_x - 1.45 * face_w)):
                if pr > 60 and (pr / (pg + 0.1) > 1.55) and (pr - pg > 24) and (abs(pg - pb) <= 15):
                    closed_mask[y, x] = 0; continue

    # Connected component propagation from neck
    num_labels, labels, stats, centroids = cv2.connectedComponentsWithStats(closed_mask)
    body_connected = np.zeros((h, w), dtype=np.uint8)
    seed_mask = (out_mask > 0.5) & (y_grid >= int(neck_top_y)) & (y_grid <= int(neck_bottom + 15.0 * sy))

    seed_labels = np.unique(labels[seed_mask])
    for lbl in seed_labels:
        if lbl > 0:
            body_connected[labels == lbl] = 1

    # Safe Scanline Infill
    max_infill = int(np.clip(w * 0.16, 40, 120))
    for y in range(body_start_y, h):
        row = body_connected[y, :]
        nz = np.where(row > 0)[0]
        if len(nz) > 1:
            prev_x = -1
            for x in nz:
                if prev_x >= 0 and (x - prev_x) > 1 and (x - prev_x) <= max_infill:
                    # Check that gap does not cross green/blue background
                    gap_g = g[y, prev_x+1:x]
                    gap_r = r[y, prev_x+1:x]
                    gap_b = b[y, prev_x+1:x]
                    is_bg = np.any((gap_g > 140) & (gap_b > 140) & ((gap_g > gap_r + 10) | (gap_b > gap_r + 10)))
                    if not is_bg:
                        body_connected[y, prev_x+1:x] = 1
                prev_x = x

    # Combine into out_mask
    body_pixels = (body_connected > 0)
    out_mask[body_pixels] = 1.0
    zone_type[body_pixels & (zone_type == 0)] = 2

# Check the 3 Regions marked by Chairman
# Region 1: Chin, Jaw, Neck (y: 440..560, x: 380..520)
reg1_mask = np.zeros((h, w), dtype=bool)
reg1_mask[440:560, 380:520] = True
# Only count actual human pixels in region 1 (skin or shadow)
reg1_human = reg1_mask & (Y >= 20.0) & (r >= g - 20) & (r >= b - 20)
cov1 = np.sum(out_mask[reg1_human] > 0.5) / max(1, np.sum(reg1_human))

# Region 2: Inner Arm (y: 550..680, x: 180..240)
reg2_mask = np.zeros((h, w), dtype=bool)
reg2_mask[550:680, 180:240] = True
reg2_human = reg2_mask & (Y >= 20.0) & (r >= g - 25) & (r >= b - 25)
cov2 = np.sum(out_mask[reg2_human] > 0.5) / max(1, np.sum(reg2_human))

# Region 3: Ribs / under-pec (y: 600..750, x: 260..340)
reg3_mask = np.zeros((h, w), dtype=bool)
reg3_mask[600:750, 260:340] = True
reg3_human = reg3_mask & (Y >= 20.0) & (r >= g - 25)
cov3 = np.sum(out_mask[reg3_human] > 0.5) / max(1, np.sum(reg3_human))

# Check background door leakage
# Left door: x < 330, y < 450
left_door = (x_grid < 330) & (y_grid < 450)
left_leak = np.sum(out_mask[left_door] > 0.5)

# Right door: x > 620, y < 450
right_door = (x_grid > 620) & (y_grid < 450)
right_leak = np.sum(out_mask[right_door] > 0.5)

print(f"Region 1 (Face/Jaw/Neck) Coverage: {cov1*100:.2f}%")
print(f"Region 2 (Inner Arm) Coverage: {cov2*100:.2f}%")
print(f"Region 3 (Ribs/Under-pec) Coverage: {cov3*100:.2f}%")
print(f"Left Door Leakage: {left_leak} px")
print(f"Right Door Leakage: {right_leak} px")

# Check Body Contour & Symmetry
body_rows = np.where(np.sum(out_mask > 0.5, axis=1) > 10)[0]
top_y = body_rows[0]
bottom_y = body_rows[-1]

left_edges = []
right_edges = []
left_widths = []
right_widths = []
symmetry_per_row = []

for y in range(top_y, bottom_y + 1):
    row_pixels = np.where(out_mask[y, :] > 0.5)[0]
    if len(row_pixels) > 0:
        xl = row_pixels[0]
        xr = row_pixels[-1]
        wl = face_center_x - xl
        wr = xr - face_center_x
        left_edges.append(xl)
        right_edges.append(xr)
        left_widths.append(wl)
        right_widths.append(wr)
        if wl > 5 and wr > 5:
            sym = min(wl, wr) / max(wl, wr)
            symmetry_per_row.append(sym)

avg_symmetry = np.mean(symmetry_per_row)
print(f"Body Contour: TopY={top_y}, BottomY={bottom_y}, Height={bottom_y - top_y}px")
print(f"Body Width Max: Left={max(left_widths):.1f}px, Right={max(right_widths):.1f}px")
print(f"Anatomical Symmetry Ratio: {avg_symmetry*100:.2f}%")

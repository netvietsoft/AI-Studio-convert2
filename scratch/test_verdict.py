import numpy as np
from PIL import Image

img = Image.open(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg')
arr = np.array(img)
h, w, _ = arr.shape

lx_eye, ly_eye = 320.0, 275.0
rx_eye, ry_eye = 395.0, 275.0
eye_dist = np.hypot(rx_eye - lx_eye, ry_eye - ly_eye)
eye_mid_x = (lx_eye + rx_eye) * 0.5
nose_tip_x, nose_tip_y = 375.0, 335.0

min_left_x = 240.0 # from monk photo left jaw/contour
max_right_x = 440.0 # from monk photo right cheek

yaw_offset = (nose_tip_x - eye_mid_x) / eye_dist
left_margin = lx_eye - min_left_x
right_margin = max_right_x - rx_eye
w_left = abs(nose_tip_x - min_left_x)
w_right = abs(max_right_x - nose_tip_x)

left_occluded = (yaw_offset < -0.12) or (left_margin < 0.28 * eye_dist) or (w_left < 0.40 * w_right)
right_occluded = (yaw_offset > 0.12) or (right_margin < 0.28 * eye_dist) or (w_right < 0.40 * w_left)

print(f"Yaw Offset: {yaw_offset:.3f}")
print(f"Left Margin: {left_margin:.1f} ({left_margin/eye_dist:.2f}*eyeDist), Right Margin: {right_margin:.1f} ({right_margin/eye_dist:.2f}*eyeDist)")
print(f"Left Occluded: {left_occluded}, Right Occluded: {right_occluded}")

is_left_visible = not left_occluded
is_right_visible = not right_occluded
print(f"Visibility Verdict: Left Ear Visible={is_left_visible}, Right Ear Visible={is_right_visible}")

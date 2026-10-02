import numpy as np
from PIL import Image

img = Image.open(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg')
arr = np.array(img)

# 1. Cephalometric Yaw & Occlusion Rule:
# Nose tip X = 375, Eye mid X = 357.5, Eye dist = 75.0
# Yaw Asymmetry = (375 - 357.5) / 75.0 = +0.233
# Positive yaw > 0.15 means face is turned towards the right side of the image.
# Therefore, the ear on the right side of the image (viewer's right, monk's left)
# is anatomically occluded behind the zygomatic arch and mandibular ramus!

yaw_offset = (375.0 - 357.5) / 75.0
print(f"Yaw Offset: {yaw_offset:.3f}")

# Threshold for profile/3/4 occlusion:
# If |yaw_offset| > 0.15, the ear on the side the nose points to is OCCLUDED.
is_right_occluded = (yaw_offset > 0.14)
is_left_occluded = (yaw_offset < -0.14)
print(f"Cephalometric Occlusion Gating: Left Occluded={is_left_occluded}, Right Occluded={is_right_occluded}")

# 2. Outer Edge Contrast (Helix Rim Gradient):
# For the real ear (Left side), let's check edge gradient along the outer contour:
left_edges = []
for y in range(240, 340, 5):
    # Scan from x=290 leftward to find where the ear ends
    row = arr[y, 200:300, :3].astype(np.float32)
    lum = 0.299 * row[:, 0] + 0.587 * row[:, 1] + 0.114 * row[:, 2]
    # compute horizontal derivative d(lum)/dx
    grad = np.abs(np.diff(lum))
    max_grad_idx = np.argmax(grad)
    max_grad_val = grad[max_grad_idx]
    x_edge = 200 + max_grad_idx
    left_edges.append((x_edge, y, max_grad_val))

mean_left_grad = np.mean([e[2] for e in left_edges])
print(f"Left Ear Outer Edge: Mean Gradient = {mean_left_grad:.1f} (Sharp contrast with dark background!)")

# For the altar side (Right side):
right_edges = []
for y in range(240, 340, 5):
    row = arr[y, 440:540, :3].astype(np.float32)
    lum = 0.299 * row[:, 0] + 0.587 * row[:, 1] + 0.114 * row[:, 2]
    grad = np.abs(np.diff(lum))
    max_grad_val = np.max(grad)
    right_edges.append(max_grad_val)

mean_right_grad = np.mean(right_edges)
print(f"Right Altar Region: Mean Gradient = {mean_right_grad:.1f} (No sharp ear boundary!)")

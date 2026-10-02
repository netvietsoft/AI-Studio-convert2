import cv2
import numpy as np

# Load 1.jpg
im = cv2.imread('scratch/1.jpg')
h, w, c = im.shape

stubble_im = im.copy()

# Add realistic gray stubble hairs in the goatee / mustache region
# Based on chin landmarks (x: 240-330, y: 640-720) and mustache (x: 250-320, y: 570-590)
np.random.seed(42)

# Chin goatee gray hairs
for _ in range(350):
    x = np.random.randint(250, 320)
    y = np.random.randint(640, 715)
    # Stubble length 3-6 px
    dx = np.random.randint(-1, 2)
    dy = np.random.randint(2, 5)
    gray_val = np.random.randint(185, 220)
    for step in range(dy):
        px = np.clip(x + int(dx * step / dy), 0, w - 1)
        py = np.clip(y + step, 0, h - 1)
        stubble_im[py, px] = [gray_val, gray_val, gray_val]

# Mustache gray hairs
for _ in range(150):
    x = np.random.randint(260, 310)
    y = np.random.randint(572, 592)
    dx = np.random.randint(-2, 3)
    dy = np.random.randint(1, 4)
    gray_val = np.random.randint(185, 215)
    for step in range(dy):
        px = np.clip(x + int(dx * step / dy), 0, w - 1)
        py = np.clip(y + step, 0, h - 1)
        stubble_im[py, px] = [gray_val, gray_val, gray_val]

cv2.imwrite('scratch/1_gray_stubble.png', stubble_im)
print("Created scratch/1_gray_stubble.png with realistic gray hairs!")
diff = np.abs(im.astype(int) - stubble_im.astype(int))
print("Synthetic gray hair pixels:", np.count_nonzero(diff > 2))

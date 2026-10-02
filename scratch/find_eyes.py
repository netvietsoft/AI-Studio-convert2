from PIL import Image
import numpy as np

img = Image.open(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg')
arr = np.array(img)

# Find glasses / dark pupils around y=240..290
# Let's inspect along y=260 and y=275
for y in [250, 260, 270, 280]:
    row = arr[y, 250:480, :3]
    # find darkest pixels (likely pupils or glasses frame)
    lum = 0.299 * row[:, 0] + 0.587 * row[:, 1] + 0.114 * row[:, 2]
    min_x = np.argmin(lum) + 250
    print(f"y={y}: min lum at x={min_x} with lum={lum.min():.1f}, rgb={row[min_x-250]}")

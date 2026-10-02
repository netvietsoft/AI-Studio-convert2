from PIL import Image
import numpy as np

img = Image.open(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg')
arr = np.array(img)
h, w, _ = arr.shape

# Let's inspect rows 180 to 450 (the head region)
# For each row, find the leftmost skin pixel and rightmost skin pixel
print("Y   | Leftmost Skin X | Rightmost Skin X | Width | Notes")
for y in range(180, 460, 20):
    row = arr[y, :, :3].astype(np.float32)
    # Skin condition: r > g > b, r in [80, 220], g in [50, 180], b in [35, 160], r-b > 15
    is_skin = (row[:, 0] > 70) & (row[:, 1] > 45) & (row[:, 2] > 30) & \
              (row[:, 0] > row[:, 1]) & (row[:, 1] >= row[:, 2]) & \
              ((row[:, 0] - row[:, 2]) > 15) & ((row[:, 0] - row[:, 1]) > 8)
    
    skin_indices = np.where(is_skin)[0]
    if len(skin_indices) > 0:
        lx = skin_indices[0]
        rx = skin_indices[-1]
        print(f"{y:3d} | x={lx:3d} (RGB={row[lx].astype(int)}) | x={rx:3d} (RGB={row[rx].astype(int)}) | {rx-lx:3d}")
    else:
        print(f"{y:3d} | No skin")

from PIL import Image
import numpy as np

img = Image.open(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg')
arr = np.array(img)
h, w, _ = arr.shape
print(f"Loaded image: {w}x{h}")

# Let's inspect the monk's real facial skin chromaticity:
# Sample from the forehead / cheek center: e.g. x in [340, 390], y in [200, 260]
face_sample = arr[200:260, 340:390, :3].astype(np.float32)
# Compute face mean and std
mean_rgb = np.mean(face_sample, axis=(0, 1))
print(f"Face Mean RGB: {mean_rgb}")

# In normalized chromaticity space: r = R/(R+G+B), g = G/(R+G+B)
sum_rgb = np.sum(face_sample, axis=2, keepdims=True) + 1e-5
r_norm = face_sample[:, :, 0] / sum_rgb[:, :, 0]
g_norm = face_sample[:, :, 1] / sum_rgb[:, :, 0]
mean_r = np.mean(r_norm)
mean_g = np.mean(g_norm)
std_r = np.std(r_norm)
std_g = np.std(g_norm)
print(f"Face Chromaticity: r={mean_r:.4f} +/- {std_r:.4f}, g={mean_g:.4f} +/- {std_g:.4f}")

# Now let's test the altar region at x in [480, 540], y in [220, 300]
altar_sample = arr[220:300, 480:540, :3].astype(np.float32)
altar_sum = np.sum(altar_sample, axis=2, keepdims=True) + 1e-5
altar_r = altar_sample[:, :, 0] / altar_sum[:, :, 0]
altar_g = altar_sample[:, :, 1] / altar_sum[:, :, 0]
print(f"Altar Chromaticity: r={np.mean(altar_r):.4f} +/- {np.std(altar_r):.4f}, g={np.mean(altar_g):.4f} +/- {np.std(altar_g):.4f}")

# Now let's test the real ear region at x in [245, 280], y in [240, 310]
ear_sample = arr[240:310, 245:280, :3].astype(np.float32)
ear_sum = np.sum(ear_sample, axis=2, keepdims=True) + 1e-5
ear_r = ear_sample[:, :, 0] / ear_sum[:, :, 0]
ear_g = ear_sample[:, :, 1] / ear_sum[:, :, 0]
print(f"Real Ear Chromaticity: r={np.mean(ear_r):.4f} +/- {np.std(ear_r):.4f}, g={np.mean(ear_g):.4f} +/- {np.std(ear_g):.4f}")

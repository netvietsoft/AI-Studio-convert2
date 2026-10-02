from PIL import Image

img = Image.open(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg')
w, h = img.size

# Let's inspect along y=270 (roughly eye/ear level) from x=200 to x=600
print("Scanning horizontal slice at y=270 (Ear & Eye level):")
for x in range(210, 560, 15):
    r, g, b = img.getpixel((x, 270))[:3]
    # Simple skin detector
    is_skin = (r > 60 and g > 40 and b > 25 and r > g and (r - b) > 10)
    tag = "SKIN" if is_skin else "----"
    print(f"x={x:3d}: [{r:3d}, {g:3d}, {b:3d}] {tag}")

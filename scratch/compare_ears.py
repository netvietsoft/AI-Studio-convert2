from PIL import Image

orig = Image.open(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg')
edited = Image.open(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\test_monk_physiological_blush.png')

# Crop visible ear (left of image): x in [210, 310], y in [210, 360]
c_orig_l = orig.crop((210, 210, 310, 360))
c_edit_l = edited.crop((210, 210, 310, 360))

# Crop occluded ear / cheek (right of image): x in [420, 520], y in [210, 360]
c_orig_r = orig.crop((420, 210, 520, 360))
c_edit_r = edited.crop((420, 210, 520, 360))

# Create side by side: [Orig L, Edit L, Orig R, Edit R]
comp = Image.new('RGB', (400, 150))
comp.paste(c_orig_l, (0, 0))
comp.paste(c_edit_l, (100, 0))
comp.paste(c_orig_r, (200, 0))
comp.paste(c_edit_r, (300, 0))
comp.save(r'f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\ear_comparison.png')
print("Comparison saved to scratch/ear_comparison.png")

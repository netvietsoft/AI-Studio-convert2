import os
from PIL import Image, ImageDraw
import numpy as np

def analyze():
    screen_path = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\screen_buddha_perfect.png"
    if not os.path.exists(screen_path):
        print("Screen file does not exist yet:", screen_path)
        return

    im = Image.open(screen_path)
    print("Screen size:", im.size)

    # Let's crop the canvas area:
    # On 1080x2340:
    # Monk portrait aspect ratio: 500x333 -> height on 1080 width is 719.
    # Center Y is roughly 1000, so y=640..1360
    # Let's inspect the bounding box of the photo inside the canvas:
    arr = np.array(im)

    # Find the top and bottom of the image inside the black editor background
    # Row mean across middle columns:
    row_means = arr[:, 400:680, :3].mean(axis=(1, 2))
    photo_rows = np.where(row_means > 50)[0]
    
    # Editor top bar ends around y=200, bottom bar starts around y=1800
    valid_rows = [r for r in photo_rows if 220 < r < 1780]
    if not valid_rows:
        print("Could not locate photo on screen!")
        return

    photo_top = valid_rows[0]
    photo_bot = valid_rows[-1]
    photo_h = photo_bot - photo_top + 1
    print(f"Detected photo vertically: Y={photo_top} to {photo_bot} (height={photo_h}px)")

    # The photo width is 1080
    photo_crop = im.crop((0, photo_top, 1080, photo_bot))
    photo_crop.save("device_photo_crop_final.png")
    print("Saved device_photo_crop_final.png")

    # The original monk portrait is 500x333
    orig_im = Image.open(r"f:\CONVERT\com.mt.mtxx.mtxx\ẢNH\monk_portrait.png").convert("RGBA")
    
    # Scale photo_crop to 500x333 to do exact pixel-by-pixel alignment and diff
    scaled_crop = photo_crop.resize((500, 333), Image.Resampling.LANCZOS)
    scaled_crop.save("device_scaled_monk.png")

    # Original monk array
    arr_orig = np.array(orig_im)
    arr_dev = np.array(scaled_crop)

    # Compute difference
    diff = np.abs(arr_dev.astype(int) - arr_orig.astype(int))
    diff_thresh = np.any(diff > 8, axis=-1) # tolerance for resampling Lanczos

    # Check background areas:
    # 1. Background to the left of the ear: X < 160
    bg_left_mod = np.count_nonzero(diff_thresh[:, :160])
    print(f"Background modified pixels to the left (X < 160): {bg_left_mod}")

    # 2. Background to the right of the head: X > 310
    bg_right_mod = np.count_nonzero(diff_thresh[:, 310:])
    print(f"Background modified pixels to the right (X > 310): {bg_right_mod}")

    # 3. Background above ear: Y < 65
    bg_top_mod = np.count_nonzero(diff_thresh[:65, :])
    print(f"Background modified pixels above (Y < 65): {bg_top_mod}")

    # 4. Ear modification region: X=165..195, Y=105..160
    ear_mod = np.count_nonzero(diff_thresh[105:160, 165:195])
    print(f"Ear region modified pixels (X=165..195, Y=105..160): {ear_mod}")

    # Side-by-side comparison crop of the ear and surrounding background
    crop_box = (140, 60, 210, 170)
    crop_orig = orig_im.crop(crop_box)
    crop_dev = scaled_crop.crop(crop_box)
    panel_w, panel_h = crop_orig.size

    comb = Image.new("RGBA", (panel_w * 2 + 15, panel_h + 30), (30, 30, 30, 255))
    comb.paste(crop_orig, (5, 25))
    comb.paste(crop_dev, (panel_w + 10, 25))
    draw = ImageDraw.Draw(comb)
    draw.text((10, 5), "GOC (ORIGINAL)", fill=(255, 255, 255))
    draw.text((panel_w + 15, 5), "DEVICE (TAI PHAT 90%)", fill=(100, 255, 100))
    comb.save(r"f:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\ear_device_final_comparison.png")
    print("Saved ear_device_final_comparison.png")

if __name__ == "__main__":
    analyze()

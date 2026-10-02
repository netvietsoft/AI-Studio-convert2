import os
import cv2
import numpy as np
import ncnn

def load_bisenet():
    param = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\lib-core-graphics\src\main\assets\models\bisenet_face_19.param"
    bin_f = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\lib-core-graphics\src\main\assets\models\bisenet_face_19.bin"
    net = ncnn.Net()
    net.opt.use_vulkan_compute = False
    net.opt.num_threads = 4
    net.load_param(param)
    net.load_model(bin_f)
    return net

def check_portrait(net, img_bgr):
    h, w = img_bgr.shape[:2]
    resized = cv2.resize(img_bgr, (512, 512))
    in_mat = ncnn.Mat.from_pixels(resized, ncnn.Mat.PixelType.PIXEL_BGR2RGB, 512, 512)
    in_mat.substract_mean_normalize([123.675, 116.28, 103.53], [1.0/58.395, 1.0/57.12, 1.0/57.375])

    ex = net.create_extractor()
    ex.input("in0", in_mat)
    out_mat = ncnn.Mat()
    ex.extract("out0", out_mat)

    out_arr = np.array(out_mat)
    labels = np.argmax(out_arr, axis=0).astype(np.uint8)

    hair_px = np.count_nonzero(labels == 17)
    skin_px = np.count_nonzero((labels == 1) | (labels == 10))
    face_px = np.count_nonzero((labels >= 1) & (labels <= 13))

    return hair_px, skin_px, face_px, labels

def main():
    net = load_bisenet()
    
    # Priority folders to search for real portraits
    search_dirs = [
        r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch",
        r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets",
        r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models",
        r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi",
        r"F:\CONVERT\com.lightricks.facetune.free",
        r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai",
        r"F:\CONVERT\com.mt.mtxx.mtxx\ẢNH",
    ]
    
    candidate_paths = []
    for d in search_dirs:
        if not os.path.exists(d): continue
        for root, dirs, files in os.walk(d):
            if any(x in root for x in ['build', '.cxx', '.git', 'node_modules', 'intermediates']):
                continue
            for f in files:
                if f.lower().endswith(('.jpg', '.jpeg', '.png')) and not f.startswith('.'):
                    p = os.path.join(root, f)
                    if os.path.getsize(p) > 25000:
                        candidate_paths.append(p)
                        
    print(f"Total candidate paths found: {len(candidate_paths)}")
    
    valid_portraits = []
    seen_hashes = set()
    
    for p in candidate_paths:
        try:
            im = cv2.imread(p)
            if im is None:
                # try utf-8 decode
                with open(p, 'rb') as f:
                    data = np.frombuffer(f.read(), dtype=np.uint8)
                    im = cv2.imdecode(data, cv2.IMREAD_COLOR)
            if im is None: continue
            h, w = im.shape[:2]
            if w < 250 or h < 250 or w > 3000 or h > 3000: continue
            
            # Simple content hash to avoid duplicates
            small = cv2.resize(im, (32, 32))
            hsh = hash(small.tobytes())
            if hsh in seen_hashes: continue
            
            hair_px, skin_px, face_px, labels = check_portrait(net, im)
            # Must have at least 1500 hair pixels and 2000 skin pixels at 512x512
            if hair_px > 1200 and skin_px > 2000:
                seen_hashes.add(hsh)
                valid_portraits.append((p, w, h, hair_px, skin_px, im))
                print(f"Found Portrait #{len(valid_portraits)}: {os.path.basename(p)} ({w}x{h}) - Hair: {hair_px} px, Skin: {skin_px} px")
                if len(valid_portraits) >= 40:
                    break
        except Exception as e:
            pass

    print(f"\nTotal validated real human portraits found: {len(valid_portraits)}")
    
    # Save top 30 to regression folder
    out_dir = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\regression_30"
    os.makedirs(out_dir, exist_ok=True)
    
    for i in range(min(30, len(valid_portraits))):
        p, w, h, hpx, spx, im = valid_portraits[i]
        save_name = f"sample_{i+1:02d}.png"
        save_path = os.path.join(out_dir, save_name)
        cv2.imwrite(save_path, im)
        print(f"Saved {save_name} from {os.path.basename(p)}")

if __name__ == "__main__":
    main()

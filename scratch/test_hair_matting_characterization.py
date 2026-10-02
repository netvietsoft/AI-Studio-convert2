import os
import cv2
import numpy as np
import ncnn

def main():
    param_path = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\models\ncnn\hair_matting_mobile.param"
    bin_path = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\models\ncnn\hair_matting_mobile.bin"
    img_path = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\0.jpg"

    print("=== MODEL CHARACTERIZATION AUDIT ===")
    print("Param path:", param_path, "exists:", os.path.exists(param_path))
    print("Bin path:", bin_path, "exists:", os.path.exists(bin_path))
    print("Img path:", img_path, "exists:", os.path.exists(img_path))

    net = ncnn.Net()
    net.opt.use_vulkan_compute = False
    net.opt.num_threads = 4
    
    ret1 = net.load_param(param_path)
    ret2 = net.load_model(bin_path)
    print(f"load_param ret: {ret1}, load_model ret: {ret2}")

    img = cv2.imread(img_path)
    h, w, c = img.shape
    print(f"Original image shape: {w}x{h}, channels: {c}")

    configs = [
        ("RGB_512_norm_neg1_pos1", 512, 512, "RGB", [127.5, 127.5, 127.5], [1.0/127.5, 1.0/127.5, 1.0/127.5]),
        ("RGB_512_norm_0_1", 512, 512, "RGB", [0, 0, 0], [1.0/255.0, 1.0/255.0, 1.0/255.0]),
        ("RGB_512_ImageNet", 512, 512, "RGB", [123.675, 116.28, 103.53], [1.0/58.395, 1.0/57.12, 1.0/57.375]),
        ("BGR_512_norm_neg1_pos1", 512, 512, "BGR", [127.5, 127.5, 127.5], [1.0/127.5, 1.0/127.5, 1.0/127.5]),
        ("BGR_512_Caffe", 512, 512, "BGR", [104.0, 117.0, 123.0], [1.0, 1.0, 1.0]),
        ("RGB_256_norm_neg1_pos1", 256, 256, "RGB", [127.5, 127.5, 127.5], [1.0/127.5, 1.0/127.5, 1.0/127.5]),
        ("RGB_224_norm_neg1_pos1", 224, 224, "RGB", [127.5, 127.5, 127.5], [1.0/127.5, 1.0/127.5, 1.0/127.5]),
    ]

    out_dir = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\p0_test"
    os.makedirs(out_dir, exist_ok=True)

    for name, tw, th, c_order, mean_vals, norm_vals in configs:
        resized = cv2.resize(img, (tw, th))
        if c_order == "RGB":
            in_mat = ncnn.Mat.from_pixels(resized, ncnn.Mat.PixelType.PIXEL_BGR2RGB, tw, th)
        else:
            in_mat = ncnn.Mat.from_pixels(resized, ncnn.Mat.PixelType.PIXEL_BGR, tw, th)
        
        in_mat.substract_mean_normalize(mean_vals, norm_vals)

        ex = net.create_extractor()
        ex.input("data", in_mat)

        out_mat = ncnn.Mat()
        ret = ex.extract("alpha_mask", out_mat)

        out_np = np.array(out_mat)
        print(f"[{name}] ret: {ret}, shape: {out_np.shape}, min: {out_np.min():.4f}, max: {out_np.max():.4f}, mean: {out_np.mean():.4f}")

        # Normalize to 0-255 for visualization
        vis = (np.clip(out_np, 0.0, 1.0) * 255.0).astype(np.uint8)
        # If output shape has extra dimension, squeeze
        if vis.ndim == 3:
            vis = vis[0] if vis.shape[0] == 1 else vis[:, :, 0]
        vis_resized = cv2.resize(vis, (w, h))
        cv2.imwrite(os.path.join(out_dir, f"test_{name}.png"), vis_resized)

if __name__ == "__main__":
    main()

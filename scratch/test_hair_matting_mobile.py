import cv2
import numpy as np
import ncnn

param_path = "app/src/main/assets/models/ncnn/hair_matting_mobile.param"
bin_path = "app/src/main/assets/models/ncnn/hair_matting_mobile.bin"

net = ncnn.Net()
net.load_param(param_path)
net.load_model(bin_path)

def test_hair_matting_mobile(img_path, out_name):
    img = cv2.imread(img_path)
    h, w = img.shape[:2]
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    
    # Check input layers
    in_names = net.input_names()
    out_names = net.output_names()
    print(f"[{img_path}] inputs: {in_names}, outputs: {out_names}")
    
    in_mat = ncnn.Mat.from_pixels_resize(img_rgb, ncnn.Mat.PixelType.PIXEL_RGB, w, h, 512, 512)
    # Standard normalization or 0..1
    mean_vals = [127.5, 127.5, 127.5]
    norm_vals = [1.0 / 127.5, 1.0 / 127.5, 1.0 / 127.5]
    in_mat.substract_mean_normalize(mean_vals, norm_vals)
    
    ex = net.create_extractor()
    ex.input(in_names[0], in_mat)
    ret, out_mat = ex.extract(out_names[0])
    print(f"ret={ret}, out_mat: c={out_mat.c}, h={out_mat.h}, w={out_mat.w}")
    out_arr = np.array(out_mat)
    print(f"out_arr min={out_arr.min()}, max={out_arr.max()}, mean={out_arr.mean()}")
    
    # Save output matte
    matte = out_arr[0] if out_mat.c == 1 else out_arr[1]
    matte_vis = (np.clip(matte, 0, 1) * 255).astype(np.uint8)
    cv2.imwrite(f"scratch/owner_evidence/{out_name}.png", matte_vis)

test_hair_matting_mobile("scratch/owner_evidence/owner_fail_B_orig.png", "mobile_matte_B")
test_hair_matting_mobile("scratch/hair_test_assets/portrait_0_curly.png", "mobile_matte_A")

import cv2
import numpy as np
import ncnn

param_path = "app/src/main/assets/models/selfie_segmentation.param"
bin_path = "app/src/main/assets/models/selfie_segmentation.bin"

net = ncnn.Net()
net.load_param(param_path)
net.load_model(bin_path)

def test_selfie(img_path, out_name):
    img = cv2.imread(img_path)
    h, w = img.shape[:2]
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    
    in_names = net.input_names()
    out_names = net.output_names()
    print(f"[{img_path}] inputs: {in_names}, outputs: {out_names}")
    
    # MediaPipe selfie segmentation input is usually 256x256 RGB normalized to [-1, 1] or [0, 1]
    # Let's inspect param
    in_mat = ncnn.Mat.from_pixels_resize(img_rgb, ncnn.Mat.PixelType.PIXEL_RGB, w, h, 256, 256)
    mean_vals = [0.0, 0.0, 0.0]
    norm_vals = [1.0 / 255.0, 1.0 / 255.0, 1.0 / 255.0]
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
    matte_full = cv2.resize(matte_vis, (w, h))
    cv2.imwrite(f"scratch/owner_evidence/{out_name}.png", matte_full)
    print(f"Saved {out_name}.png")

test_selfie("scratch/owner_evidence/owner_fail_B_orig.png", "selfie_person_B")
test_selfie("scratch/hair_test_assets/portrait_0_curly.png", "selfie_person_A")

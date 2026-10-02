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

def run_bisenet_multiclass(net, img_bgr):
    h, w = img_bgr.shape[:2]
    resized = cv2.resize(img_bgr, (512, 512))
    in_mat = ncnn.Mat.from_pixels(resized, ncnn.Mat.PixelType.PIXEL_BGR2RGB, 512, 512)
    in_mat.substract_mean_normalize([123.675, 116.28, 103.53], [1.0/58.395, 1.0/57.12, 1.0/57.375])

    ex = net.create_extractor()
    ex.input("in0", in_mat)
    out_mat = ncnn.Mat()
    ex.extract("out0", out_mat)

    out_arr = np.array(out_mat)
    labels_512 = np.argmax(out_arr, axis=0).astype(np.uint8)
    labels_full = cv2.resize(labels_512, (w, h), interpolation=cv2.INTER_NEAREST)
    return labels_full

def test_sample_05_and_holdouts():
    net = load_bisenet()
    
    # 1. Test sample_05
    s05_path = r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_2.jpg"
    im_s05 = cv2.imread(s05_path)
    labels_s05 = run_bisenet_multiclass(net, im_s05)
    print(f"sample_05: shape={im_s05.shape}, hair_pixels={np.sum(labels_s05 == 17)}")

    # 2. Test holdout_03
    h03_path = r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_1_2026-09-25_21-30-16.jpg"
    im_h03 = cv2.imread(h03_path)
    labels_h03 = run_bisenet_multiclass(net, im_h03)
    print(f"holdout_03: shape={im_h03.shape}, hair_pixels={np.sum(labels_h03 == 17)}, face_skin={np.sum(labels_h03 == 1)}")

    # 3. Test holdout_07
    h07_path = r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_11_2026-09-25_21-30-16.jpg"
    im_h07 = cv2.imread(h07_path)
    labels_h07 = run_bisenet_multiclass(net, im_h07)
    print(f"holdout_07: shape={im_h07.shape}, hair_pixels={np.sum(labels_h07 == 17)}, face_skin={np.sum(labels_h07 == 1)}")

if __name__ == '__main__':
    test_sample_05_and_holdouts()

import cv2
import numpy as np
import ncnn

param_path = "app/src/main/assets/models/bisenet_face_19.param"
bin_path = "app/src/main/assets/models/bisenet_face_19.bin"

net = ncnn.Net()
net.load_param(param_path)
net.load_model(bin_path)

def parse_image(img_path):
    img = cv2.imread(img_path)
    h, w = img.shape[:2]
    # BiSeNet standard preproc: resize to 512x512, RGB, normalize: mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    
    # Check letterbox vs direct
    max_aspect = max(w/h, h/w)
    use_letterbox = (max_aspect > 1.80)
    
    in_mat = ncnn.Mat.from_pixels_resize(img_rgb, ncnn.Mat.PixelType.PIXEL_RGB, w, h, 512, 512)
    mean_vals = [0.485 * 255.0, 0.456 * 255.0, 0.406 * 255.0]
    norm_vals = [1.0 / (0.229 * 255.0), 1.0 / (0.224 * 255.0), 1.0 / (0.225 * 255.0)]
    in_mat.substract_mean_normalize(mean_vals, norm_vals)
    
    ex = net.create_extractor()
    ex.input("in0", in_mat)
    ret, out_mat = ex.extract("out0")
    print(f"[{img_path}] ret={ret}, out_mat shape: c={out_mat.c}, h={out_mat.h}, w={out_mat.w}")
    
    out_arr = np.array(out_mat) # shape: (19, 512, 512)
    labels = np.argmax(out_arr, axis=0).astype(np.uint8)
    
    hair_prob = np.exp(out_arr[17] - np.max(out_arr, axis=0)) / np.sum(np.exp(out_arr - np.max(out_arr, axis=0)), axis=0)
    
    # Count classes in 512x512
    unique, counts = np.unique(labels, return_counts=True)
    class_counts = dict(zip(unique, counts))
    print(f"Class distribution: {class_counts}")
    
    # Resize labels back to w, h
    labels_orig = cv2.resize(labels, (w, h), interpolation=cv2.INTER_NEAREST)
    return labels_orig, hair_prob

labels_B, prob_B = parse_image("scratch/owner_evidence/owner_fail_B_orig.png")
labels_A, prob_A = parse_image("scratch/hair_test_assets/portrait_0_curly.png")

# Save hair masks
cv2.imwrite("scratch/owner_evidence/bisenet_hair_B.png", (labels_B == 17).astype(np.uint8) * 255)
cv2.imwrite("scratch/owner_evidence/bisenet_cloth_B.png", (labels_B == 16).astype(np.uint8) * 255)
cv2.imwrite("scratch/owner_evidence/bisenet_skin_B.png", (labels_B == 1).astype(np.uint8) * 255)
cv2.imwrite("scratch/owner_evidence/bisenet_hair_A.png", (labels_A == 17).astype(np.uint8) * 255)
print("Finished saving masks")

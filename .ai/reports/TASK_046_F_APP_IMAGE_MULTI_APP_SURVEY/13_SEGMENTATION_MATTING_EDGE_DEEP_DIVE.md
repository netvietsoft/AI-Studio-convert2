# 13 — NGHIÊN CỨU CHUYÊN SÂU PHÂN ĐOẠN NGỮ NGHĨA & TÁCH LỚP MATTING
# TÀI LIỆU KHẢO SÁT CÔNG NGHỆ TÁCH LỚP 14 ỨNG DỤNG (F:\APP\IMAGE)

---

## 1. SO SÁNH CÁC MÔ HÌNH PHÂN ĐOẠN NGỮ NGHĨA PHỔ BIẾN

| Ứng Dụng | Mô Hình Phát Hiện | Khung Thực Thi (Runtime) | Độ Phân Giải Input | Số Lớp Phân Đoạn | Xử Lý Biên & Matting |
|---|---|---|---|---|---|
| **Meitu** | BiSeNetV2 / ManisNet | Manis (NCNN/MNN) | $512 \times 512$ | 19 Lớp (Khuôn mặt, Tóc, Quần áo, Nền) | Guided Filter + Bilateral Edge Refinement |
| **Facetune** | Lightricks MattingNet | TFLite GPU Delegate | $256 \times 256$ | 2 Lớp (Tóc / Foreground Alpha) | Laplacian Pyramid Trimap-free Matting |
| **FaceApp** | FaceApp UNet Segmentation | ONNX Runtime Mobile | $512 \times 512$ | 8 Lớp (Tóc, Râu, Da, Mắt, Môi, Quần áo) | Sub-pixel Bilinear Upsampling + Guided Filter |
| **SnapEdit** | MobileNetV3-UPerNet | TFLite GPU | $512 \times 512$ | 2 Lớp (Vật thể cần xóa / Nền) | Morphological Dilation (3px) + Gaussian Feather |
| **Ulike** | ByteNN HumanSeg | ByteNN Engine | $384 \times 384$ | 12 Lớp (Chân dung chi tiết) | Fast Guided Filter trên kênh Luminance |

---

## 2. KỸ THUẬT GUIDED FILTER MATTING CHO TÓC TƠ (SUB-PIXEL HAIR STRANDS)

Thuật toán Guided Filter (He et al.) là phương pháp hiệu quả nhất được các ứng dụng hàng đầu sử dụng để biến mặt nạ phân đoạn thô (low-res mask $p$) thành mặt nạ chi tiết sợi tóc ($q$) dựa trên ảnh hướng dẫn độ phân giải cao ($I$):
$$q_i = a_k I_i + b_k, \quad \forall i \in \omega_k$$
Trong đó các hệ số tuyến tính $a_k$ và $b_k$ được tính toán tối ưu trong từng cửa sổ lân cận $\omega_k$:
$$a_k = \frac{\frac{1}{|\omega|} \sum_{i \in \omega_k} I_i p_i - \mu_k \bar{p}_k}{\sigma_k^2 + \epsilon}$$
$$b_k = \bar{p}_k - a_k \mu_k$$

### Ưu điểm vượt trội đối với CONVERT2:
- Tốc độ cực nhanh: Có thể tính toán bằng 4 pass bộ lọc hộp tách rời (Separable Box Filter) trên GPU OpenGL ES hoặc Vulkan compute shader với thời gian dưới 1.5 ms trên Mali-G72 MP3.
- Bảo toàn từng sợi tóc con bay tự do trên nền sáng mà không gây viền trắng hoặc răng cưa pixel.

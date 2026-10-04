# TASK_048 — FEATURE & ALGORITHM BANK SPECIFICATION
**Authority:** Chủ tịch Tony  
**Task ID:** TASK_048_MULTI_AGENT_IMAGE_EFFECT_GRAPH_EVIDENCE_EXPANSION_ACTIVE  
**Execution Lane:** LANE E (Worker Identity: `WORKER-LANE-E-APP-IMAGE-MINING-CREATIVE`)  
**Scope:** Ngân hàng các thuật toán và tính năng giá trị cao được bóc tách từ 14 ứng dụng F:\App\Image sẵn sàng cho Clean-Room Reimplementation.  

---

## 1. THUẬT TOÁN 1: LỌC TÓC HƯỚNG TÍCH PHÂN ĐƯỜNG 21-TAP (21-TAP DIRECTIONAL LIC)
- **Donor / Nguồn gốc:** Meitu (`libMTFilterKernel.so`, symbol `softHairFilterToFBO`)
- **Nguyên lý toán học:** Lấy mẫu 21 điểm đối xứng dọc theo vector tiếp tuyến sợi tóc $\vec{t} = (-\sin \theta, \cos \theta)$.
  Trọng số suy giảm Gauss: $w_k = \exp(-k^2 / (2 \cdot 3.5^2))$ với $k \in [-10, 10]$.
- **Giá trị cốt lõi cho CONVERT2:** Làm mượt các sợi tóc rối, triệt tiêu nhiễu hạt ISO nhưng bảo tồn cấu trúc lọn tóc tự nhiên.
- **Mức độ sẵn sàng tái dựng:** REIMPLEMENTABLE (Có thể viết lại hoàn chỉnh bằng Vulkan Compute Shader hoặc GLSL ES 3.0).

---

## 2. THUẬT TOÁN 2: NỘI SUY TỨ DIỆN 3D LUT (TETRAHEDRAL 3D LUT INTERPOLATION)
- **Donor / Nguồn gốc:** VSCO (`vsco_lut3d_tetrahedral.frag`)
- **Nguyên lý toán học:** Chia mỗi khối lập phương con thành 6 khối tứ diện đơn hình (simplices) dựa trên mối quan hệ thứ tự $(r > g > b)$. Chỉ lấy mẫu 4 đỉnh tứ diện thay vì 8 đỉnh như Trilinear.
- **Giá trị cốt lõi cho CONVERT2:** Loại bỏ hoàn toàn lỗi xé màu sắc (diagonal color tearing) và hiện tượng gãy dải màu (color banding) trên da và tóc.
- **Mức độ sẵn sàng tái dựng:** REIMPLEMENTABLE (Đã có công thức GLSL chuẩn).

---

## 3. THUẬT TOÁN 3: PHÂN TÁCH TẦN SỐ KÉP BẢO TỒN LỖ CHÂN LÔNG (DUAL-PASS SKIN PORE PRESERVATION)
- **Donor / Nguồn gốc:** Facetune (`libfacetune.so`) & Meitu (`MTImageKit snoopy_best.bin`)
- **Nguyên lý toán học:**
  - $I_{\text{Low}} = \text{BilateralFilter}(I, \sigma_s = 5.0, \sigma_r = 0.15)$
  - $I_{\text{High}} = I - I_{\text{Low}}$
  - $I_{\text{Smooth}} = \text{GuidedFilter}(I_{\text{Low}}, \text{Mask})$
  - $I_{\text{Pore}} = \text{Threshold}(I_{\text{High}}, \tau = 0.02) \cdot 0.85$
  - $I_{\text{Final}} = I_{\text{Smooth}} + I_{\text{Pore}}$
- **Giá trị cốt lõi cho CONVERT2:** Đảm bảo da mặt mịn màng nhưng giữ lại tối thiểu 75% vi cấu trúc lỗ chân lông thật, không gây cảm giác búp bê sáp.
- **Mức độ sẵn sàng tái dựng:** REIMPLEMENTABLE.

---

## 4. THUẬT TOÁN 4: NẮN BÓP VÓC DÁNG KHÓA NỀN (ZERO-BACKGROUND DISTORTION LIQUIFY)
- **Donor / Nguồn gốc:** Meitu (`LFBodyShapeModular`) & ULike (`tt_pose_detection_v3.0.model`)
- **Nguyên lý toán học:** Vector dịch chuyển đỉnh lưới $\vec{D}(\mathbf{x}) = \vec{V}_{\text{drag}} \cdot w(r) \cdot M_{\text{body}}(\mathbf{x})$ trong đó $M_{\text{body}}$ là mặt nạ nhị phân cơ thể. Nếu $M_{\text{body}}(\mathbf{x}) = 0 \implies \vec{D}(\mathbf{x}) = \vec{0}$.
- **Giá trị cốt lõi cho CONVERT2:** Nắn thon eo, nâng ngực, kéo chân mà hậu cảnh (gạch men, cửa kính, tường hoa) hoàn toàn đứng yên, không cong vênh méo mó.
- **Mức độ sẵn sàng tái dựng:** REIMPLEMENTABLE.

---

## 5. THUẬT TOÁN 5: TĂNG ĐỘ BÓNG & TRONG TRẺO TÓC 9X9 UNSHARP CLARITY
- **Donor / Nguồn gốc:** Meitu (`libMTFilterKernel.so`, GLSL rodata offset)
- **Nguyên lý toán học:**
  Lưới lấy mẫu $9 \times 9$ bước nhảy $2.3 \times$ độ lệch pixel.
  $$\text{HighBoost} = \text{clamp}(I_{\text{sum}} + (I_{\text{orig}} - I_{\text{sum}}) \times 1.8, 0.0, 1.0)$$
  $$\text{ClarityBoost} = \text{HighBoost} + (\min(I_{\text{orig}} - I_{\text{blur}}, 0.0) + 0.015) \times 0.4$$
- **Giá trị cốt lõi cho CONVERT2:** Tạo độ bóng khỏe, tăng chiều sâu sợi tóc và giúp màu nhuộm phát sáng tự nhiên.
- **Mức độ sẵn sàng tái dựng:** REIMPLEMENTABLE.

# HCE V1 — CLAIM CORRECTION & OVERCLAIM ELIMINATION LOG
**Document ID:** HCE-V1-CLAIMS-01  
**Author:** Agent 0 (CEO / Orchestrator)  
**Standard:** Development Workspace Standard V2.1 + Hiến pháp Vận hành CONVERT  
**Status:** ALL OVERCLAIMS AUDITED AND RECTIFIED  

---

## 1. MỤC ĐÍCH
Rà soát và chuẩn hóa toàn bộ các phát biểu trong các báo cáo kỹ thuật nhằm loại bỏ các tuyên bố thổi phồng ("100%", "triệt để", "tuyệt đối", "không bao giờ sập"), đưa mọi khẳng định về đúng chuẩn mực định lượng thực tế.

---

## 2. NHẬT KÝ ĐIỀU CHỈNH CHI TIẾT (CORRECTION LOG)

| STT | Tuyên bố ban đầu (Cũ) | Vấn đề phát hiện | Tuyên bố chuẩn hóa kiểm toán (Mới) | Bằng chứng thực nghiệm |
|---|---|---|---|---|
| 1 | *"Ground-Truth 62 mẫu"* | 62 mẫu chỉ có ground-truth cho P0 matting, không có annotation cho vector tóc, độ sáng hay quang phổ P1–P5 | **"Canonical 62-sample regression suite / Proxy-metric validation set"** | Không có nhãn sinh thiết hay xạ kế quang phổ vật lý |
| 2 | *"100% natural strand preservation"* | Overclaim từ ngữ tuyệt đối | **"Tỷ số bảo lưu năng lượng tần số cao Laplace $\ge 0.88$ (Mean 0.914) trên 62 mẫu canonical"** | File `P2_TEXTURE_EVIDENCE.csv` |
| 3 | *"Zero leakage"* (Tuyên bố chung) | Không phân biệt vùng có hoặc không có trong ảnh | **"Rò rỉ màu được đo đạc theo từng vùng cụ thể: da trán $\Delta E \le 0.05$, tai $\Delta E \le 0.06$, áo $\Delta E \le 0.03$; các vùng không có ghi nhận 'NA'"** | File `HCE_V1_PROTECTED_REGION_METRICS.csv` |
| 4 | *"100% exact GPU parity (Diff = 0.000)"* | Bỏ qua việc hàm GPU fallback về CPU reference | **"Độ tương đồng Level A (byte-identical) đạt được do hàm runtime thực thi CPU OpenMP fallback; độ tương đồng GPU lý thuyết là Level B ($\le 1.0$ LSB)"** | File `hair_gpu_backend.cpp` (Dòng 146) |
| 5 | *"Mô hình Full Marschner R-Lobe"* | Dễ gây hiểu nhầm là mô phỏng 3D tán xạ ánh sáng vật lý hoàn chỉnh | **"Mô hình xấp xỉ thùy R bất đẳng hướng cảm hứng từ Marschner (Marschner-inspired R-lobe anisotropic highlight approximation)"** | File `hair_anisotropic_specular_engine.cpp` |
| 6 | *"Đo đạc nồng độ sắc tố Melanin"* | Gây hiểu nhầm là có đo phổ quang học thật | **"Tham số Melanin là biến điều khiển hình thái xuất hiện (Appearance-control parameter: $\mu_{	ext{eu}}, \mu_{	ext{pheo}} \in [0, 1]$)"** | File `hair_dye_material_engine.cpp` |
| 7 | *"Loại bỏ hoàn toàn bóng nhờn mũ bảo hiểm"* | Tuyên bố tổng quát hóa quá mức | **"Loại bỏ bóng nhờn kiểu mũ bảo hiểm trên toàn bộ 62 mẫu canonical đã kiểm thử nhờ căn chỉnh vệt sáng theo hướng tiếp tuyến P1"** | File `P5_SPECULAR_EVIDENCE.csv` |
| 8 | *"Hỗ trợ Metal Compute"* | Chưa được kiểm chứng thực tế trên thiết bị Apple | **"Kiến trúc C++ sẵn sàng tương thích Metal (Metal-ready architecture); kiểm thử runtime trên thiết bị Apple được bảo lưu cho pha tiếp theo"** | File `hair_gpu_backend.cpp` |
| 9 | *"Rủi ro quá nhiệt bằng 0 (Thermal risk = zero)"* | Cấm khẳng định rủi ro phần cứng tuyệt đối | **"Không quan sát thấy hiện tượng quá nhiệt hay giảm xung (thermal throttling) trong suốt chu kỳ chạy kiểm thử 62 mẫu trên Samsung A50"** | File `HCE_V1_DEVICE_BENCHMARK.csv` |

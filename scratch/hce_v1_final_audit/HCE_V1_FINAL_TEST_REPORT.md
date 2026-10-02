# HCE V1 — FINAL INDEPENDENT TEST REPORT
**Document ID:** HCE-V1-TEST-01  
**Tester:** Independent Quality Assurance & Verification Agent  
**Standard:** Development Workspace Standard V2.1 + Gated Integration Standard  
**Date:** 2026-10-02  

---

## 1. DANH MỤC KIỂM TRA ĐỘC LẬP (TEST CHECKLIST)

| STT | Hạng mục kiểm tra | Tiêu chuẩn đánh giá | Kết quả kiểm tra | Trạng thái |
|---|---|---|---|---|
| 1 | P0 Freeze Hashes | 17/17 tệp tin không drift logic | Hash thuật toán P0 khớp 100% | **PASS** |
| 2 | P1–P6 Real Upstream | Không dùng mock/fixture trong nghiệm thu cuối | 100% dùng output thật của pha trước | **PASS** |
| 3 | Phase-specific Datasets | Có ma trận phân định GT vs Proxy | Có bảng ma trận 11 cột chuẩn | **PASS** |
| 4 | P1 Orientation Evidence | Công thức ma trận Ten-xơ, phân bố thống kê | Mean $C = 0.842$, Min $0.742$, P50 $0.841$ | **PASS** |
| 5 | P2 Texture Evidence | Năng lượng tần số cao Laplace | Retention $\ge 88.5\%$, Banding $< 0.012$ | **PASS** |
| 6 | P3 Appearance Evidence | Điểm bảo lưu bóng tối, tương phản cục bộ | Shadow pres score $\ge 0.952$ | **PASS** |
| 7 | P4 Dye Material Evidence | Sai biệt màu $\Delta E_{	ext{OKLab}}$, khóa Gamut | $\Delta E \le 1.48$, Gamut violations = 0 | **PASS** |
| 8 | P5 Specular Implementation | Minh bạch mô hình thùy R cảm hứng Marschner | Căn chỉnh tiếp tuyến P1 $\ge 0.962$ | **PASS** |
| 9 | Actual GPU Runtime Dispatch | Có lệnh submit Vulkan Queue trên phần cứng thật | `gpu_dispatch_count = 0` (CPU Fallback) | **NEEDS_FIX** |
| 10 | CPU/GPU Parity Classification | Phân loại chuẩn Level A vs Level B | Minh bạch Level A từ CPU Fallback | **PASS** |
| 11 | JNI Routing Proof | Kotlin gọi trực tiếp vào HairColorPipeline | Trải vết JNI bridge đầy đủ | **PASS** |
| 12 | Visual Artifacts Complete | Đầy đủ 14 tệp ảnh minh chứng chuẩn | Đầy đủ 14 tệp, manual_edit = false | **PASS** |
| 13 | Protected-Region Metrics | Rò rỉ màu trên các vùng cấm xâm lấn | $\Delta E \le 0.06$, dùng NA khi không có vùng | **PASS** |
| 14 | Device Benchmark & Soak | P50/P95/P99 trên Samsung Galaxy A50 | Tổng thời gian $55.7$ ms (P50), RSS $184$ MB | **PASS** |
| 15 | P7 Isolation | P7 Generative HD hoàn toàn đóng băng | Không có tệp P7 nào được kích hoạt | **PASS** |

---

## 2. KẾT LUẬN CỦA ĐƠN VỊ KIỂM THỬ ĐỘC LẬP
Căn cứ trên kết quả kiểm tra 15 hạng mục độc lập:
- 14/15 hạng mục liên quan đến kiến trúc C++, luồng tích hợp P0–P5, JNI, chất lượng hình ảnh và hiệu năng CPU: **PASS HOÀN TOÀN**.
- Hạng mục số 9 (Actual GPU Runtime Dispatch): Thư viện C++ đang vận hành an toàn qua cơ chế **CPU OpenMP Reference Fallback** (`gpu_dispatch_count = 0`), chưa kích hoạt bộ đệm lệnh Vulkan trực tiếp trên phần cứng Galaxy A50.

**PHÁN QUYẾT KIỂM THỬ:** **TESTER_NEEDS_FIX** (Yêu cầu bổ sung lệnh submit hàng đợi GPU Vulkan phần cứng để hoàn tất chứng chỉ GPU).

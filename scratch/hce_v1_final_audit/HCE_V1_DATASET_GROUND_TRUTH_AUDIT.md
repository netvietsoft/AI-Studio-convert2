# HCE V1 — DATASET & GROUND-TRUTH AUDIT REPORT
**Document ID:** HCE-V1-AUDIT-GT-01  
**Project:** CONVERT2 — Hair Color Engine (Phase P1–P6 Parallel Integration)  
**Standard:** Development Workspace Standard V2.1 + Hiến pháp Vận hành CONVERT  
**Auditor:** Agent 0 (CEO / Orchestrator) — Independent Technical Audit  
**Date:** 2026-10-02  

---

## 1. MỤC ĐÍCH & PHẠM VI KIỂM TOÁN
Báo cáo nghiệm thu ban đầu sử dụng thuật ngữ **"Ground-Truth 62 mẫu"** để đại diện cho toàn bộ các metric kiểm thử từ P0 đến P6.
Theo chỉ thị kiểm toán độc lập tại Issue E1 (`HCE_V1_FINAL_EVIDENCE_AUDIT_CORRECTION01_AGENT_SPEC.txt`), Agent kiểm toán phải xác minh chính xác:
1. Bản chất dữ liệu của 62 mẫu có phải là Ground-Truth thực sự cho tất cả các pha không?
2. Có nhãn ground-truth annotation cho orientation field, texture map, intrinsic decomposition, target color, specular field không?
3. Nếu không có nhãn ground-truth vật lý, thuật ngữ bắt buộc phải được chuẩn hóa lại để phản ánh đúng thực tế kỹ thuật.

---

## 2. BẢNG PHÂN LOẠI CHI TIẾT GROUND-TRUTH VS PROXY THEO TỪNG GIAI ĐOẠN

| Giai đoạn | Tên pha kỹ thuật | Loại Annotation có sẵn | Có Ground-Truth Vật lý? | Phân loại dữ liệu thực tế | Thuật ngữ chuẩn hóa bắt buộc | Proxy Metric sử dụng |
|---|---|---|---|---|---|---|
| **P0** | Hair Matting & Boundary Protection | Mặt nạ phân đoạn tóc (Alpha Mask) + Vùng cấm xâm lấn (Skin/Ear/Forehead) | **CÓ** (Ground-truth mask từ bộ P0-C defect trace) | Ground-Truth Boundary Set | Canonical 62-sample regression suite | Aspect ratio $\tau_{\text{aspect}}$, Boundary coverage $\tau_{\text{cov}}$ |
| **P1** | Hair Orientation Engine | KHÔNG có nhãn vector field từ kính hiển vi/quang học | **KHÔNG** | Proxy Validation Set | Canonical 62-sample proxy-metric validation suite | Structure-Tensor Coherence, Streamline Continuity |
| **P2** | Flow-Aware Texture Engine | KHÔNG có bản đồ sợi tóc vi mô (Strand micro-geometry) | **KHÔNG** | Proxy Validation Set | Canonical 62-sample proxy-metric validation suite | High-Frequency Energy Retention, Directional Fourier Ratio, Banding Score |
| **P3** | Hair Appearance / Lighting | KHÔNG có intrinsic image decomposition mặt trời/đèn thật | **KHÔNG** | Proxy Validation Set | Canonical 62-sample proxy-metric validation suite | Shadow Preservation Score, Local Contrast Ratio, Highlight Luminance Retention |
| **P4** | Salon Dye Material Engine | Preset màu salon (Target RGB trong bảng màu Meitu/L'Oreal) | **KHÔNG** (Target là synthetic salon target, không phải sinh thiết tóc thật) | Reference Target Set | Canonical 62-sample reference-target validation suite | $\Delta E_{\text{OKLab}}$, Root Darkness Ratio, Gamut Violation Count |
| **P5** | Anisotropic Specular Highlight | KHÔNG có phép đo xạ kế BRDF/BTDF sợi tóc thực tế | **KHÔNG** | Proxy Validation Set | Canonical 62-sample proxy-metric validation suite | Tangent Adherence Score, Highlight Contrast Gain, Helmet-Shine Absence |
| **P6** | GPU Backend / OpenMP | Kết quả chạy song song trên phần cứng Android (Galaxy A50) | **N/A** (Phần cứng thực tế) | Hardware Benchmark Set | Canonical 62-sample hardware benchmark suite | Runtime latency (ms), RSS (MB), CPU/GPU Buffer Parity |

---

## 3. KẾT LUẬN & CHUẨN HÓA THUẬT NGỮ
1. **Tuyệt đối cấm sử dụng:** Thuật ngữ *"Ground-Truth 62 mẫu"* khi nói về độ chính xác của P1, P2, P3, P4, P5.
2. **Thuật ngữ chuẩn hóa bắt buộc từ thời điểm này:**
   - *"Canonical 62-sample regression suite"* (cho toàn bộ tập mẫu).
   - *"Proxy-metric validation set"* (cho P1, P2, P3, P5).
   - *"Reference-target validation set"* (cho P4).
3. **Ý nghĩa kỹ thuật:** Việc phân định rõ ràng giữa Ground-Truth thực sự (P0 segmentation) và Proxy Metrics (P1–P5) đảm bảo tính trung thực khoa học tối thượng của dự án, tuân thủ tuyệt đối Hiến pháp CONVERT.

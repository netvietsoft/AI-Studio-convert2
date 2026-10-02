# PHASE P0-B.2R — ROBUSTNESS & PERFORMANCE CLOSURE — EXECUTION REPORT

**Authority:** CEO (Agent 0 - Orchestrator)  
**Recipient:** Chủ tịch Tony (Chairman)  
**Reference Document:** `F:\CONVERT\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`  
**Execution Order:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\FIX\P0_B2R_ROBUSTNESS_PERFORMANCE_CLOSURE_MASTER_AGENT_SPEC.txt`  
**Target Device:** Samsung Galaxy SM-A075F (Helio G99 / Android 14 / ARM64-v8a)  
**Date:** 2026-10-02  
**Algorithm Gate Decision:** `P0_B2R_PASS`  
**Evidence Package Status:** `P0_B2R_EVIDENCE_FREEZE_PASS`  

---

## 1. Executive Summary & Final Verdict

Trong Phase **P0-B.2R**, toàn bộ 3 điểm nghẽn kỹ thuật (R1, R2, R3) còn tồn đọng từ P0-B.2 đã được **xử lý và xác minh bằng thực nghiệm trên bộ dữ liệu kiểm thử**:

1. **R1 (High-Exposure Hair Recovery — `sample_26`):**
   - **Baseline P0-B.2:** Hair Core = 73.28% (Trượt gate $\ge 75\%$).
   - **P0-B.2R Fix:** Hair Core = **78.71%** ($\ge 75\%$ PASS).
   - **Forehead Skin Leakage:** Đo đạc **0.000%** trên ROI trán của mẫu thử `sample_26` (0 pixel rò rỉ trong vùng đo quy định).
2. **R2 (Screenshot Semantic Geometry — `holdout_07`, `edge_05`, `edge_06`):**
   - **Xác minh nguyên nhân gốc:** Trong các screenshot failure được kiểm thử ở P0-B.2R, A/B/C experiment cho thấy anisotropic resize là nguyên nhân chính được quan sát; Mode B aspect-preserving letterbox loại bỏ phần lớn Class-18 false positive và đưa Background Leakage xuống dưới gate.
   - **Giải pháp:** Adaptive Mode B (Aspect-Preserving Letterbox khi $\max(H/W, W/H) > 1.80$).
   - **Kết quả xuất xưởng (Final Pipeline Stage Background Leakage):**
     - `holdout_07`: Background Leakage giảm từ **16.42%** $\implies$ **0.025% (~0.03%)**!
     - `edge_05`: Background Leakage giảm từ **15.87%** $\implies$ **0.000%**!
     - `edge_06`: Background Leakage giảm từ **12.49%** $\implies$ **0.000%**!
3. **R3 (Performance Closure — LowContrastHairResolver Cost):**
   - **Đo đạc thực tế 50 vòng lặp trên Samsung Galaxy SM-A075F (Helio G99, ARM64-v8a, 960x1280):**
     - LowContrastHairResolver P50: Giảm từ **53.49 ms** $\implies$ **8.51 ms** (giảm 84.1% latency!).
     - **TOTAL P0-B.2R MATTING P50:** **69.85 ms** (Vượt qua chỉ tiêu cứng $\le 85\text{ ms}$ với biên độ an toàn 15.15 ms trên Samsung Galaxy SM-A075F dưới cấu hình benchmark được ghi nhận).
     - Full Pipeline P50: **317.60 ms**.
     - Peak RAM RSS (VmHWM): **344.76 MB** ($\le 512\text{ MB}$ gate).
4. **Master 62-Sample Suite Evaluation:**
   - **30 Regression Samples:** **30/30 PASS (100.0%)**.
   - **12 Existing Holdout Samples:** **12/12 PASS (100.0%)**.
   - **8 Edge Holdout Samples:** **8/8 PASS (100.0%)**.
   - **12 New Robustness Holdout Samples:** **12/12 PASS (100.0%)**.
   - **TỔNG CỘNG: 62/62 samples trong bộ kiểm định P0-B.2R vượt qua toàn bộ các hard gate được định nghĩa.**

**ALGORITHM VERDICT:** **`P0_B2R_PASS`**

---

## 2. Scope & Constraint Verification

Tuân thủ nghiêm ngặt Hiến pháp vận hành và Chỉ thị P0-B.2R:
- **Không sửa đổi mã nguồn Production:** Mã nguồn trong `lib-core-graphics/src/...` không bị can thiệp logic thuật toán mới (kiểm tra độc lập qua `git status`). Mọi nâng cấp thực hiện và kiểm chứng cô lập trong `scratch/`.
- **Zero New AI Models:** Giữ nguyên BiSeNet 19-class NCNN hiện tại, không thêm ONNX/TNN, không thêm cloud hay generative AI.
- **Zero P1 Leakage:** Không khởi động P1 (Hair Flow / Orientation).
- **Physical Device Only:** Mọi số liệu hiệu năng được đo lường trực tiếp trên CPU ARM64 của Samsung Galaxy SM-A075F qua ADB shell native executable.

---

## 3. R1 — High-Exposure Failure Reproduction (`sample_26`)

- **Ảnh mục tiêu:** `sample_26` (`face_live_88.png`).
- **Hiện tượng lỗi P0-B.2:** Do điều kiện ánh sáng phơi sáng cao (high exposure), ranh giới giữa chân tóc trán và da trán có độ tương phản luminance thấp. Bước làm mềm viền trán (`forehead_touch & final_alpha > 0.0`) của P0-B.2 đã nhân mù quáng hệ số 0.78 lên toàn bộ vùng tiếp xúc, khiến các sợi tóc thực thụ ở rìa trán bị giảm alpha xuống $< 0.75$, kéo Hair Core Preservation xuống còn 73.28% (< 75%).
- **Tập tin chẩn đoán xuất xưởng:** Đầy đủ 10 artifact tại [exposure/sample_26](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/exposure/sample_26/):
  - `01_original.png`, `02_semantic_overlay.png`, `03_hair_seed.png`, `04_candidate_probability.png`, `05_skin_protection.png`, `06_connectivity_map.png`, `07_texture_map.png`, `08_alpha_p0_b2.png`, `09_failure_core_map.png`, `10_forehead_hairline_crop.png`.

---

## 4. R1 — Root Cause Analysis & Evidence

Phân tích bóc tách các vùng tại `sample_26`:
- **Vùng da trán thực thụ:** $L^* > 65$, gradient Laplacian phẳng ($T_{\text{tex}} < 0.02$). Vùng này được bảo vệ nghiêm ngặt bằng mặt nạ loại trừ da trán.
- **Sợi tóc rìa trán bị phơi sáng:** Tuy $L^* > 50$ tương đương da trán, nhưng cấu trúc vi sợi tóc tạo ra năng lượng tần số cao trong ma trận Laplacian ($T_{\text{tex}} > 0.05$).
- **Nguyên nhân cốt lõi:** Bước làm mềm chân tóc của P0-B.2 chưa phân biệt giữa pixel chuyển tiếp mềm (soft blur transition) và sợi tóc mỏng có texture (hair strand), dẫn đến việc triệt tiêu alpha của sợi tóc thật.

---

## 5. R1 — Fix Formulation & Parameter Selection

Nâng cấp thuật toán Hairline Softening có nhận thức Texture (Texture-Aware Hairline Softening):
$$\alpha_{\text{final}}(x, y) = \begin{cases} 
0.0 & \text{nếu } (x, y) \in \text{Forehead Skin (Label 1)} \\
\max(\alpha(x, y), 0.85) & \text{nếu } (x, y) \in \text{Forehead Touch} \land (x, y) \in \text{Class 17} \land T_{\text{tex}} > 0.05 \\
0.78 \cdot \alpha(x, y) & \text{nếu } (x, y) \in \text{Forehead Touch} \land T_{\text{tex}} \le 0.05
\end{cases}$$

- **Tham số đông kết:**
  - $\tau_{\text{tex\_core}} = 0.05$: Ngưỡng năng lượng Laplacian xác nhận sợi tóc thật.
  - $\alpha_{\text{min\_strand}} = 0.85$: Độ mờ tối thiểu của sợi tóc thật tại chân trán.
  - $\text{Strict Skin Zero} = \text{ENABLED}$: Toàn bộ pixel da trán giữ nguyên $\alpha = 0.0$.

---

## 6. R1 — Fixed Output Analysis & Metric Movement

Kết quả đo đạc trên `sample_26`:
| Chỉ số | Baseline P0-B.2 | Fixed P0-B.2R | Delta | Trạng thái Gate |
| :--- | :--- | :--- | :--- | :--- |
| **Hair Core Preservation** | 73.28% | **78.71%** | **+5.43%** | **PASS ($\ge 75\%$)** |
| **Forehead Skin Leakage** | 0.000% | **0.000%** | 0.000% | **PASS ($\le 0.1\%$)** |
| **Background Leakage** | 1.387% | **1.401%** | +0.014% | **PASS ($\le 5\%$)** |
| **Hairline Naturalness** | 84.8 | **85.3** | +0.5 | **PASS** |

---

## 7. R2 — BiSeNet Preprocessing Geometry Audit

Kiểm tra trực tiếp mã nguồn:
- `lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp:82-90`:
  Hàm `from_pixels_resize(..., W, H, 512, 512)` thực hiện co dãn bất đẳng hướng (direct anisotropic resize) trực tiếp ảnh từ $(W, H)$ về hình vuông $512 \times 512$.
- Đối với ảnh chụp màn hình điện thoại (tỷ lệ $576 \times 1280$, tương đương $2.22 : 1$), việc ép về $512 \times 512$ làm khuôn mặt bị dẹt ngang 2.22 lần. Các lớp tích chập của BiSeNet mất tỷ lệ chuẩn của ngũ quan, dẫn đến việc phân loại nhầm toàn bộ các mảng nền và thanh công cụ thành Class 18 (Hat/Accessory).

---

## 8. R2 — A/B/C Geometry Experiment Execution

Thực thi kịch bản độc lập `scratch/run_p0_b2r_geometry_ab.py` so sánh 3 chế độ tiền xử lý trên 3 ảnh screenshot lỗi:
- **Mode A (As-Is):** Direct squish về $512 \times 512$.
- **Mode B (Letterbox):** Giữ nguyên tỷ lệ khung hình, scale cạnh dài về 512, chèn viền xám 128 (neutral gray), sau đó unpad và nội suy ngược.
- **Mode C (Face/Hair ROI):** Trích xuất bounding box chứa đầu người và tóc với margin 0.35, resize ROI về 512, inference và dán ngược lại.

---

## 9. R2 — Mode A vs Mode B vs Mode C Comparative Metrics

Dữ liệu thực nghiệm đo đạc ở tầng tiền xử lý hình học (Geometry Stage) từ [geometry_ab/GEOMETRY_AB_METRICS.csv](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/geometry_ab/GEOMETRY_AB_METRICS.csv):

| Ảnh mẫu | Chế độ | Class 17 Hair Px | Class 18 FP Px | GEOMETRY_STAGE_BACKGROUND_LEAKAGE* | UI Leakage | Phán quyết |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **`holdout_07`** | Mode A (As-Is) | 0 | 126,854 | **16.42%** | 0.00% | **FAIL** |
| | **Mode B (Letterbox)** | **31,245** | **1,520** | **0.07%** | **0.00%** | **PASS (Winner)** |
| | Mode C (ROI) | 28,910 | 4,210 | 0.74% | 0.00% | PASS |
| **`edge_05`** | Mode A (As-Is) | 0 | 118,432 | **15.87%** | 0.00% | **FAIL** |
| | **Mode B (Letterbox)** | **34,512** | **890** | **0.01%** | **0.00%** | **PASS (Winner)** |
| | Mode C (ROI) | 32,104 | 3,850 | 0.68% | 0.00% | PASS |
| **`edge_06`** | Mode A (As-Is) | 0 | 98,410 | **12.49%** | 0.00% | **FAIL** |
| | **Mode B (Letterbox)** | **29,870** | **1,120** | **0.02%** | **0.00%** | **PASS (Winner)** |
| | Mode C (ROI) | 27,650 | 4,110 | 0.79% | 0.00% | PASS |

> *\*Lưu ý đối soát số liệu (Issue E2):* Bảng trên phản ánh `GEOMETRY_STAGE_BACKGROUND_LEAKAGE` đo đạc trực tiếp sau bước Guided Filter & Color Affinity trước khi áp dụng các bộ lọc UI Chrome và Semantic Protection. Khi đi qua toàn bộ pipeline hoàn chỉnh (`FINAL_PIPELINE_BACKGROUND_LEAKAGE` tại `P0_B2R_METRICS.csv`), `ImageContentGuard` và `SemanticProtection` loại bỏ triệt để các pixel viền ngoài cùng, đưa Background Leakage cuối cùng của `holdout_07` xuống **0.025% (~0.03%)**, `edge_05` xuống **0.000%**, và `edge_06` xuống **0.000%**. Xem chi tiết tại [P0_B2R_METRIC_RECONCILIATION.csv](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/P0_B2R_METRIC_RECONCILIATION.csv) và [P0_B2R_METRIC_DEFINITIONS.md](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/P0_B2R_METRIC_DEFINITIONS.md).

Toàn bộ 15 artifact A/B/C được lưu trữ tại [scratch/p0_b2r_validation/geometry_ab/](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/geometry_ab/).

---

## 10. R2 — Root Cause Determination (Geometry vs Heuristic)

- **Kết luận bằng chứng:** Thực nghiệm A/B/C trên các screenshot failure (`holdout_07`, `edge_05`, `edge_06`) cho thấy anisotropic resize là nguyên nhân chính được quan sát gây ra hiện tượng mất nhận diện tóc và nhận diện nhầm nền thành Class 18.
- Khi áp dụng Mode B (Aspect-Preserving Letterbox), BiSeNet phục hồi nhận diện tóc (Class 17) và loại bỏ phần lớn Class 18 false positive trên nền, Background Leakage ở tầng hình học giảm từ ~12% - 16% xuống còn $0.01\% - 0.07\%$ (đạt gate $\le 5.0\%$). Kết hợp với các lớp bảo vệ nội dung (`ImageContentGuard`), rò rỉ nền cuối cùng trong toàn pipeline đạt $\le 0.03\%$.

---

## 11. R2 — Ordinary Portrait Verification

- Kiểm chứng trên các ảnh chân dung chuẩn tỷ lệ 3:4 và 2:3 (`sample_01`, `sample_04`, `sample_11`):
  - Khi aspect ratio $\le 1.80$, việc sử dụng Direct Resize là tối ưu nhất vì tận dụng toàn bộ diện tích input $512 \times 512$ của mạng nơ-ron, không bị lãng phí vùng đệm padding.
  - Do đó, quy tắc kích hoạt được đông kết là: **Adaptive Letterbox kích hoạt khi $\max(H/W, W/H) > 1.80$**.

---

## 12. R3 — Performance Baseline & Problem Statement

- **Baseline P0-B.2:**
  - `LowContrastHairResolver` chiếm **53.49 ms** trên CPU ARM64.
  - Tổng thời gian P0 Matting đạt **114.94 ms** (Vượt ngưỡng mục tiêu $\le 85\text{ ms}$).
- **Nhiệm vụ P0-B.2R:** Tối ưu hóa thuật toán để đưa tổng thời gian P0 Matting về $\le 85\text{ ms}$ mà không làm giảm độ nét chi tiết sub-pixel.

---

## 13. R3 — Hardware Profiling on Samsung Galaxy SM-A075F

- **Thiết bị:** Samsung Galaxy SM-A075F.
- **Vi xử lý:** MediaTek Helio G99 (MT6789), 2x Cortex-A76 @ 2.2GHz + 6x Cortex-A55 @ 2.0GHz.
- **Hệ điều hành:** Android 14, Kernel 5.10.
- **Công cụ đo lường:** Standalone native C++ binary (`/data/local/tmp/p0_b2r_device_bench`), biên dịch bằng Android NDK r26b với `-O3 -fopenmp -static-openmp -static-libstdc++`.

---

## 14. R3 — LowContrastHairResolver Computational Bottleneck

Phân tích mã nguồn chỉ ra 2 điểm nghẽn nặng nề nhất:
1. Tính toán Laplacian Filter $3 \times 3$ trên toàn bộ ma trận ảnh full-resolution ($960 \times 1280 \approx 1.23\text{ Megapixels}$).
2. Hai lần Box Filter $5 \times 5$ (tính $\mathbb{E}[L^2]$ và $\mathbb{E}[L]$) trên toàn bộ ma trận ảnh để tính phương sai cục bộ năng lượng tóc.

---

## 15. R3 — Optimization Variants P0/P1/P2/P3 Architecture

Thiết kế ma trận 4 phương án tối ưu:
- **Variant P0 (Full-Res Native):** Tính Laplacian và Box Filter trên toàn bộ ảnh $960 \times 1280$.
- **Variant P1 (Half-Res Linear):** Downscale ảnh xám về $480 \times 640$, tính toán ma trận năng lượng và nội suy song tuyến (bilinear) trở lại.
- **Variant P2 (Candidate ROI Full-Res):** Chỉ tính toán trong Bounding Box bao quanh vùng đầu tóc (tiết kiệm 60% diện tích ảnh).
- **Variant P3 (Candidate ROI + Half-Res):** Kết hợp cả hai kỹ thuật: Cắt Candidate ROI và tính toán ở độ phân giải $1/2$. Giảm hơn $10\times$ số lượng pixel cần xử lý.

---

## 16. R3 — Device Benchmark Results (50 Iterations)

Dữ liệu trích xuất từ tập tin đo đạc vật lý [device_benchmark/P0_B2R_DEVICE_BENCHMARK.csv](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/device_benchmark/P0_B2R_DEVICE_BENCHMARK.csv) (50 vòng lặp):

| Biến thể kiểm chuẩn | P50 (ms) | P95 (ms) | P99 (ms) | Speedup vs P0 | Phán quyết |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Variant P0 (Full-Res Native)** | 49.36 ms | 64.99 ms | 69.09 ms | 1.00x | Quá chậm |
| **Variant P1 (Half-Res Linear)** | 18.14 ms | 26.76 ms | 28.07 ms | 2.72x | Khá |
| **Variant P2 (Candidate ROI Full-Res)** | 12.46 ms | 17.07 ms | 17.39 ms | 3.96x | Tốt |
| **Variant P3 (Candidate ROI + Half-Res)** | **8.51 ms** | **13.53 ms** | **15.11 ms** | **5.80x** | **ĐẠT CHUẨN (SELECTED)** |

---

## 17. R3 — Stage-by-Stage Latency Breakdown

Bảng đo đạc chi tiết từng công đoạn trong Pipeline P0-B.2R (Variant P3) trên Samsung Galaxy SM-A075F:

| ID | Công đoạn xử lý | P50 (ms) | P95 (ms) | P99 (ms) | Ghi chú Trạng thái |
| :---: | :--- | :---: | :---: | :---: | :--- |
| 1 | BiSeNet Face Parsing (512x512 NCNN) | 248.24 | 288.32 | 310.91 | Đo đạc NCNN 4 threads |
| 2 | Adaptive Hair Appearance Seed | 0.96 | 2.07 | 2.31 | Đo đạc OpenMP |
| 3 | Hair / Hat Resolver (Class 18) | 1.52 | 2.52 | 2.57 | Đo đạc OpenMP |
| **4** | **LowContrastHairResolver (Variant P3 ROI+Half)** | **8.51** | **13.53** | **15.11** | **Biến thể được chọn (P3)** |
| 5 | SubjectGraph (Topological) | 1.17 | 3.20 | 3.94 | Đo đạc OpenMP |
| 6 | ImageContentGuard (UI Chrome Guard) | 0.63 | 1.08 | 1.75 | Đo đạc OpenMP |
| 7 | Semantic Trimap Generation | 2.88 | 5.25 | 6.01 | Đo đạc OpenMP |
| 8 | Fast Guided Filter (Box r=12, s=2) | 46.28 | 72.20 | 93.75 | Đo đạc OpenMP |
| 9 | Local Color Affinity | 3.79 | 8.17 | 10.43 | Đo đạc OpenMP |
| 10 | Strict Semantic & UI Protection | 1.36 | 3.31 | 6.75 | Đo đạc OpenMP |
| 11 | Ear Occlusion Resolver | N/A* | N/A* | N/A* | *EAR_STAGE_NOT_TRIGGERED |
| 12 | Hairline Refinement & Softening | 0.87 | 1.47 | 1.74 | Đo đạc OpenMP |
| **13** | **TOTAL P0-B.2R MATTING (Variant P3)** | **69.85 ms** | **106.31 ms** | **141.98 ms** | **End-to-End Matting Timing** |
| **14** | **FULL RUN (BiSeNet + P0-B.2R Matting)** | **317.60 ms** | **419.12 ms** | **452.89 ms** | **End-to-End Pipeline Timing** |

> *\*Giải trình kỹ thuật Ear Occlusion Resolver (Issue E3):* Trên ảnh chân dung tổng hợp $960 \times 1280$ của bài test benchmark, nhãn ngữ nghĩa tai không xuất hiện ($|\mathcal{R}_{\text{ear}}| = 0$). Do đó, nhánh xử lý tai được bypass có điều kiện (`trigger_count = 0`, 0 pixels processed, clock overhead ghi nhận là $7.7 \times 10^{-5}\text{ ms}$). Trạng thái này được ghi nhận chính xác là `EAR_STAGE_NOT_TRIGGERED`, không phải "zero computational cost" khi áp dụng trên ảnh thực tế có tai.

> **CHỈ TIÊU KPI:** P0 Matting P50 yêu cầu $\le 85\text{ ms}$.  
> **KẾT QUẢ ĐO THỰC TẾ:** **$69.85\text{ ms}$** $\implies$ **VƯỢT CHỈ TIÊU (PASSED)** trên Samsung Galaxy SM-A075F.

---

## 18. R3 — Thermal & Memory Profile

- **Peak RAM RSS (VmHWM):** **344.76 MB** (Đo đạc qua `/proc/self/status` VmHWM trên tiến trình native benchmark standalone, đáp ứng ngưỡng $\le 512\text{ MB}$ của bài test). Số liệu này không thay thế cho kiểm thử rò rỉ bộ nhớ dài hạn (soak test) trong ứng dụng tích hợp hoàn chỉnh.
- **Thermal Behavior:** Trong phạm vi 50 vòng lặp liên tục ở điều kiện phòng thí nghiệm trên Samsung Galaxy SM-A075F (Helio G99), nhiệt độ ghi nhận từ `/sys/class/thermal/thermal_zone0/temp` duy trì ổn định không phát sinh hiện tượng nghẽn nhiệt (thermal throttling).

---

## 19. Master Regression Suite Execution (50 Samples)

- Chạy kiểm thử trên toàn bộ 50 ảnh mẫu (30 Regression + 12 Existing Holdout + 8 Edge Holdout):
  - **Tỷ lệ vượt qua:** **50/50 samples PASS (100.0%)**.
  - Không có bất kỳ hiện tượng thoái biến (regression) nào trên 46 mẫu đã pass ở P0-B.2.
  - Cả 4 mẫu trượt ở P0-B.2 (`sample_26`, `holdout_07`, `edge_05`, `edge_06`) đều đã **PASS**.

---

## 20. 12 New Robustness Holdout Suite Execution

Đánh giá trên 12 ảnh holdout hoàn toàn mới chưa từng qua tinh chỉnh (R01..R12):
- `robustness_01` (Screenshot chân dung góc nghiêng): PASS (Core=91.7%, BgLeak=0.02%).
- `robustness_02` (Screenshot có thanh trượt và công cụ): PASS (Core=92.1%, BgLeak=0.03%).
- `robustness_03` (Screenshot nền ngoài trời phức tạp): PASS (Core=92.2%, BgLeak=0.00%).
- `robustness_04` (Chân dung tóc tương phản thấp với da): PASS (Core=100.0%, BgLeak=0.00%).
- `robustness_05` (Chân dung tóc chìm trong bóng tối ambient): PASS (Core=100.0%, BgLeak=0.00%).
- `robustness_06` (Tóc chạm viền khung hình camera): PASS (Core=100.0%, BgLeak=0.00%).
- `robustness_07` (Chân dung phơi sáng mạnh ngoài trời): PASS (Core=93.5%, BgLeak=2.06%).
- `robustness_08` (Ảnh mẫu backdrop studio): PASS (Core=96.9%, BgLeak=3.77%).
- `robustness_09` (Collage đa đối tượng / multi-face patch): PASS (Core=98.4%, BgLeak=1.66%).
- `robustness_10` (Hiệu ứng ánh sáng mạnh / light flares): PASS (Core=94.9%, BgLeak=0.63%).
- `robustness_11` (Ảnh selfie camera trước chạm sát cạnh viền): PASS (Core=100.0%, BgLeak=0.00%).
- `robustness_12` (Monk portrait - Hard Negative nhà sư không tóc): PASS (Alpha = 0.00, Zero False Positive).
- **Kết quả tập Robustness mới:** **12/12 PASS (100.0%)**.

---

## 21. Negative Test Suite Evaluation

- **Ảnh kiểm thử:** `sample_20` và `robustness_12` (Chân dung sư thầy cạo trọc đầu).
- **Kết quả:** Alpha matte xuất ra 0.0 trên vùng da đầu cạo trọc trong các mẫu negative được kiểm thử. Thuật toán fallback của `SubjectGraph` và `HairSeedStats` xử lý chính xác theo tiêu chí gate.

---

## 22. Border-Touching Real Hair Evaluation

- **Ảnh kiểm thử:** `edge_07`, `robustness_06`, `robustness_11`.
- **Kết quả:** Các lọn tóc thật kéo dài chạm sát viền trên và viền hông của khung hình được bảo toàn cấu trúc nhờ cơ chế liên kết `SubjectGraph`. Không bị `ImageContentGuard` cắt nhầm thành thanh trạng thái màn hình.

---

## 23. Multi-Person Evaluation

- **Ảnh kiểm thử:** `edge_08` (Chân dung đôi bạn thân) và `robustness_09` (Collage đa khuôn mặt).
- **Kết quả:** `SubjectGraph` phân rã thành công từng cụm khuôn mặt độc lập, xây dựng vùng neo đầu tóc riêng biệt cho từng người, phân tách chân tóc chính xác và không bị dính chùm alpha giữa hai chủ thể kề sát nhau.

---

## 24. Failure Case Deep Dive

- **Số lượng ca thất bại:** **0 ca**.
- Toàn bộ 62 trường hợp kiểm thử trong Phase P0-B.2R đều đáp ứng đầy đủ tất cả các Hard Gates về độ nguyên vẹn vùng lõi tóc ($\ge 75\%$), cô lập rò rỉ da mặt ($\le 0.1\%$), rò rỉ nền screenshot ($\le 5\%$), và chống rò rỉ UI ($\le 1\%$).

---

## 25. Blind Review Packet (10 Samples)

Gói 10 ảnh mẫu đại diện kiểm tra mù được trích xuất hoàn chỉnh tại [scratch/p0_b2r_validation/blind_review/](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/blind_review/):
1. `sample_01`: Tóc xoăn ngắn Châu Á (Studio).
2. `sample_04`: Tóc vàng sáng uốn sóng trên nền trắng High-Key.
3. `sample_05`: Tóc tối màu trên nền gradient tối (F1 Low-Contrast Closed).
4. `sample_26`: Chân dung phơi sáng mạnh chạm da trán (R1 Exposure Closed).
5. `holdout_07`: Screenshot điện thoại chân dung lọn tóc dài (R2 Letterbox Closed).
6. `edge_05`: Screenshot giao diện chỉnh sửa ảnh có toolbar (R2 Letterbox Closed).
7. `edge_06`: Screenshot có thanh trượt độ sáng và điều hướng (R2 Letterbox Closed).
8. `edge_07`: Tóc dài chạm viền trên và cạnh phải khung hình.
9. `edge_08`: Chân dung đôi 2 người (Multi-person).
10. `robustness_07`: Ảnh chụp ngoài trời ngược sáng có lóa sáng tóc.

---

## 26. Full 62-Sample Metric Matrix Summary

Dữ liệu tổng hợp từ [scratch/p0_b2r_validation/P0_B2R_METRICS.csv](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/P0_B2R_METRICS.csv):

- **Tổng số mẫu:** 62 mẫu.
- **Tỷ lệ Đạt chuẩn (PASS):** **62 / 62 = 100.0%** (toàn bộ mẫu đạt gate quy định).
- **Tỷ lệ Trượt (FAIL / NEEDS_FIX):** **0 / 62 = 0.0%**.
- **Trung bình Hair Core Preservation:** **94.8%** (vượt xa chỉ tiêu $\ge 75\%$).
- **Trung bình Forehead Skin Leakage:** **0.000%** (0 pixel rò rỉ trên các vùng trán được đánh dấu trong suite).
- **Trung bình Background Leakage (Screenshots):** **0.018%** (vượt xa chỉ tiêu $\le 5\%$).
- **Trung bình UI Toolbar Leakage:** **0.000%** (0 pixel rò rỉ trên các vùng thanh điều hướng được đánh dấu trong suite).

---

## 27. Artifact Index & Directory Verification

Mọi thư mục kết quả và bằng chứng số học đã được tạo lập, lưu trữ đầy đủ và sẵn sàng thẩm định:
- [P0_B2R_METRICS.csv](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/P0_B2R_METRICS.csv): Bảng số liệu chi tiết 62 mẫu (đã chuẩn hóa RFC 4180 và Null Policy).
- [device_benchmark/P0_B2R_DEVICE_BENCHMARK.csv](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/device_benchmark/P0_B2R_DEVICE_BENCHMARK.csv): Log đo đạc native C++ 50 vòng lặp trên Samsung Galaxy SM-A075F.
- [source_trace/SOURCE_TRACE.md](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/source_trace/SOURCE_TRACE.md): Ma trận truy vết mã nguồn.
- [config/P0_B2R_CONFIG.md](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/config/P0_B2R_CONFIG.md): Đặc tả cấu hình siêu tham số đóng băng.
- [geometry_ab/](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/geometry_ab/): Bằng chứng nghiệm A/B/C hình học và `GEOMETRY_AB_METRICS.csv`.
- [exposure/](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/exposure/): Bằng chứng nghiệm chẩn đoán `sample_26`.
- [blind_review/](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scratch/p0_b2r_validation/blind_review/): Gói 10 ảnh kiểm tra mù.

---

## 28. Risk Register & Production Readiness Audit

1. **Rủi ro hồi quy (Regression Risk):** THẤP. Pipeline P0-B.2R đạt 62/62 mẫu đạt gate trên bộ dữ liệu kiểm thử được định nghĩa.
2. **Rủi ro tài nguyên (Memory/Thermal Risk):** THẤP trong điều kiện kiểm thử được ghi nhận. Bộ nhớ RAM tiêu thụ đỉnh 344.76 MB (VmHWM), dưới ngưỡng 512 MB. Latency matting 69.85 ms bảo đảm tốc độ phản hồi người dùng mượt mà trên Samsung Galaxy SM-A075F.
3. **Sẵn sàng tích hợp Production:** Giải pháp Classical Matting với các khối `AdaptiveLetterbox`, `LowContrastHairResolverP3`, `SubjectGraph`, và `ImageContentGuard` đã đạt độ chín muồi về mặt toán học và thực nghiệm để sẵn sàng đưa vào mã nguồn C++ native khi Chủ tịch Tony phê duyệt.

---

## 29. Decision Gate & Final Verdict

Căn cứ vào các bằng chứng thực nghiệm thu thập:
1. Đã đóng dứt điểm lỗi High-Exposure trên `sample_26` (Core 78.7% $\ge 75\%$, Skin Leakage 0.000%).
2. Đã xử lý nguyên nhân méo hình học trên mobile screenshots (`holdout_07`, `edge_05`, `edge_06` leakage giảm từ 16% về $\le 0.03\%$).
3. Đã đưa độ trễ P0 Matting trên thiết bị thật Samsung Galaxy SM-A075F về **69.85 ms** ($\le 85\text{ ms}$).
4. Đã vượt qua toàn bộ 62 mẫu kiểm nghiệm trong test suite P0-B.2R (62/62 samples passed applicable gates).

**ALGORITHM VERDICT:**
$$\mathbf{P0\_B2R\_PASS}$$

**EVIDENCE VERDICT:**
$$\mathbf{P0\_B2R\_EVIDENCE\_FREEZE\_PASS}$$

---

## 30. Stop Condition Enforcement

Theo lệnh điều hành tối cao:
- Dừng ngay lập tức sau khi hoàn tất hồ sơ freeze.
- **KHÔNG** tự ý can thiệp vào `lib-core-graphics/`.
- **KHÔNG** tự ý khởi động Phase P1 (Hair Flow / Orientation).
- Chờ chỉ thị chiến lược tiếp theo từ Chủ tịch Tony.

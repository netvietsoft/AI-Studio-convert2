# CLAIM CORRECTION LOG — PHASE P0-B.2R EVIDENCE NORMALIZATION

**Task:** Phase P0-B.2R — Final Evidence Correction & Freeze  
**Document:** `CLAIM_CORRECTION_LOG.md`  
**Purpose:** Comprehensive audit and normalization of overclaims, unverified uniqueness claims, and un-scoped zero/100% assertions across all P0-B.2R evidence artifacts.  
**Audited Artifacts:**
- `scratch/p0_b2r_validation/P0_B2R_REPORT.md`
- `scratch/p0_b2r_validation/source_trace/SOURCE_TRACE.md`
- `scratch/p0_b2r_validation/config/P0_B2R_CONFIG.md`

---

## 1. Audit Principles & Policy
In accordance with Section 2 and Section 3 of `P0_B2R_FINAL_EVIDENCE_CORRECTION_FREEZE_AGENT_SPEC.txt`:
1. **Evidence-Claim Parity:** Claims must strictly match the scope and direct evidence of the experiment.
2. **No Absolute Uniqueness Overclaims:** "100% root cause", "duy nhất", "triệt để", "hoàn hảo", "tuyệt đối" are strictly forbidden unless every competing mechanism has been exhaustively proven absent.
3. **No Unbounded Generalization:** Findings from 3 screenshot failure cases cannot be extrapolated to all images, all screenshots, or universal production environments.
4. **Legitimate Use of Exact Quantities:** Exact counts (e.g. `62/62 samples in the test suite passed`) and exact pixel metrics (`0 pixels in defined ROI`) are permissible when explicitly scoped to their defined measurement boundaries.

---

## 2. Table of Claim Corrections

| ID | File | Section | Old Claim | New Claim | Reason | Evidence Source | Severity |
| :---: | :--- | :--- | :--- | :--- | :--- | :--- | :---: |
| **C01** | `P0_B2R_REPORT.md` | Executive Summary (§1) | `...toàn bộ 3 điểm nghẽn kỹ thuật (R1, R2, R3) còn tồn đọng từ P0-B.2 đã được giải quyết triệt để và chứng minh thực nghiệm 100%` | `...toàn bộ 3 điểm nghẽn kỹ thuật (R1, R2, R3) còn tồn đọng từ P0-B.2 đã được xử lý và xác minh bằng thực nghiệm trên bộ dữ liệu kiểm thử` | Xóa từ ngữ tuyệt đối ("triệt để", "100%"), quy về phạm vi thực nghiệm đã kiểm chứng. | `P0_B2R_REPORT.md` (§1) | MAJOR |
| **C02** | `P0_B2R_REPORT.md` | Executive Summary (§1.1) | `- Forehead Skin Leakage: Duy trì chính xác 0.000% (Zero leakage).` | `- Forehead Skin Leakage: Đo đạc 0.000% trên ROI trán của mẫu thử sample_26 (0 pixel rò rỉ trong vùng đo quy định).` | Giới hạn phạm vi claim "zero leakage" vào ROI trán cụ thể của mẫu thử `sample_26`. | `run_p0_b2r_exposure_diag.py`, `P0_B2R_METRICS.csv` | MINOR |
| **C03** | `P0_B2R_REPORT.md` | Executive Summary (§1.2) | `- Xác minh nguyên nhân gốc: 100% do hiện tượng méo hình học (Geometric Anisotropic Squish 2.22:1 => 1:1)...` | `- Xác minh nguyên nhân gốc: Trong các screenshot failure được kiểm thử ở P0-B.2R, A/B/C experiment cho thấy anisotropic resize là nguyên nhân chính được quan sát; Mode B aspect-preserving letterbox loại bỏ phần lớn Class-18 false positive và đưa Background Leakage xuống dưới gate.` | Xóa overclaim "100% do hiện tượng méo hình học", dùng wording chuẩn hóa theo Section 2 của spec. | `run_p0_b2r_geometry_ab.py`, `GEOMETRY_AB_METRICS.csv` | CRITICAL |
| **C04** | `P0_B2R_REPORT.md` | Executive Summary (§2) | `- TỔNG CỘNG: 62/62 SAMPLES PASS (100.0%) — ZERO FAILURES.` | `- TỔNG CỘNG: 62/62 samples trong bộ kiểm định P0-B.2R vượt qua toàn bộ các hard gate được định nghĩa.` | Xóa claim "ZERO FAILURES" vô điều kiện, chuyển thành phát biểu chính xác theo quy chuẩn Section 16. | `P0_B2R_METRICS.csv` (62 rows) | MAJOR |
| **C05** | `P0_B2R_REPORT.md` | Section 3 | `- Zero Production Modification: Mã nguồn trong lib-core-graphics/src/... được giữ nguyên vẹn 100% (git status clean).` | `- Không sửa đổi mã nguồn Production: Mã nguồn trong lib-core-graphics/src/... không bị can thiệp logic thuật toán mới (kiểm tra độc lập qua git status).` | Chuẩn hóa thuật ngữ kỹ thuật, không dùng "100%" cảm tính. | `git status`, `git diff` | MINOR |
| **C06** | `P0_B2R_REPORT.md` | Section 4 | `Vùng này cần bảo vệ tuyệt đối.` | `Vùng này được bảo vệ nghiêm ngặt bằng mặt nạ loại trừ da trán.` | Xóa từ "tuyệt đối" không mang ý nghĩa kỹ thuật định lượng. | `run_p0_b2r_exposure_diag.py` | MINOR |
| **C07** | `P0_B2R_REPORT.md` | Section 10 | `- Méo tỷ lệ khung hình là nguyên nhân duy nhất và trực tiếp gây ra rò rỉ nền trên screenshot.` | `- Thực nghiệm A/B/C trên các screenshot failure (holdout_07, edge_05, edge_06) cho thấy anisotropic resize là nguyên nhân chính được quan sát gây ra mất nhận diện tóc và nhầm nền thành Class 18.` | Xóa claim "nguyên nhân duy nhất và trực tiếp", điều chỉnh về quan sát trực tiếp trên 3 ca lỗi. | `scratch/run_p0_b2r_geometry_ab.py` | CRITICAL |
| **C08** | `P0_B2R_REPORT.md` | Section 10 | `...Background Leakage lập tức giảm từ 16% về mức gần như tuyệt đối 0.01% - 0.07%. Không cần bổ sung bất kỳ rule heuristic nào!` | `...Background Leakage ở tầng hình học giảm từ ~12% - 16% xuống còn 0.01% - 0.07% (đạt gate <= 5.0%). Kết hợp với ImageContentGuard, rò rỉ nền cuối cùng trong toàn pipeline đạt <= 0.03%.` | Xóa "mức gần như tuyệt đối", làm rõ 2 tầng metric (Geometry Stage vs Final Pipeline Stage). | `GEOMETRY_AB_METRICS.csv`, `P0_B2R_METRICS.csv` | MAJOR |
| **C09** | `P0_B2R_REPORT.md` | Section 11 | `...tận dụng 100% diện tích 512 x 512 của mạng nơ-ron...` | `...tận dụng toàn bộ diện tích input 512 x 512 của mạng nơ-ron...` | Chuẩn hóa wording kỹ thuật xử lý ảnh. | BiSeNet input specification | MINOR |
| **C10** | `P0_B2R_REPORT.md` | Section 17 | `| 11 | Ear Occlusion Resolver | 0.00 | 0.00 | 0.00 |` | `| 11 | Ear Occlusion Resolver | N/A* | N/A* | N/A* | (Footnote: EAR_STAGE_NOT_TRIGGERED, trigger count = 0)` | Tránh ngộ nhận "zero computational cost", giải thích rõ stage không trigger trên ảnh bench. | `scratch/p0_b2r_device_bench.cpp:490-492` | CRITICAL |
| **C11** | `P0_B2R_REPORT.md` | Section 18 | `Thermal Behavior: Không phát sinh hiện tượng nghẽn nhiệt (thermal throttling), nhiệt độ ổn định qua 50 lần lặp liên tục.` | `Thermal Behavior: Trong phạm vi 50 vòng lặp liên tục ở điều kiện kiểm thử trên Samsung Galaxy SM-A075F, nhiệt độ thermal zone duy trì ổn định không phát sinh thermal throttling.` | Giới hạn phạm vi kết luận nhiệt trong 50 vòng lặp trên thiết bị Galaxy SM-A075F cụ thể. | `p0_b2r_device_bench.cpp` | MINOR |
| **C12** | `P0_B2R_REPORT.md` | Section 22 | `- Kết quả: Alpha matte xuất ra chính xác 0.0 tuyệt đối... Thuật toán fallback của SubjectGraph và HairSeedStats hoạt động hoàn hảo.` | `- Kết quả: Alpha matte xuất ra 0.0 trên vùng da đầu cạo trọc trong các mẫu negative (sample_20, robustness_12). Thuật toán fallback xử lý đạt yêu cầu gate.` | Xóa "tuyệt đối" và "hoàn hảo", quy về kết quả đo đạc trên mẫu thử cụ thể. | `P0_B2R_METRICS.csv` (`sample_20`, `robustness_12`) | MAJOR |
| **C13** | `P0_B2R_REPORT.md` | Section 23 | `...được giữ nguyên vẹn 100% nhờ cơ chế liên kết SubjectGraph.` | `...được bảo toàn cấu trúc nhờ cơ chế liên kết SubjectGraph.` | Xóa từ "100%" mang tính tuyệt đối hóa không có căn cứ sub-pixel. | `P0_B2R_METRICS.csv` (`robustness_06`) | MINOR |
| **C14** | `P0_B2R_REPORT.md` | Section 29 | `- Trung bình Forehead Skin Leakage: 0.000% (Tuyệt đối không rò rỉ da).` | `- Trung bình Forehead Skin Leakage: 0.000% (0 pixel rò rỉ trên các vùng trán được đánh dấu trong suite).` | Định lượng rõ "0 pixel" trong vùng đánh dấu, xóa từ "tuyệt đối". | `P0_B2R_METRICS.csv` | MINOR |
| **C15** | `P0_B2R_REPORT.md` | Section 29 | `- Trung bình UI Toolbar Leakage: 0.000% (Tuyệt đối không rò rỉ thanh điều hướng).` | `- Trung bình UI Toolbar Leakage: 0.000% (0 pixel rò rỉ trên các vùng thanh điều hướng được đánh dấu trong suite).` | Định lượng rõ "0 pixel" trong vùng đánh dấu, xóa từ "tuyệt đối". | `P0_B2R_METRICS.csv` | MINOR |
| **C16** | `P0_B2R_REPORT.md` | Section 32 | `Pipeline P0-B.2R duy trì 100% tỷ lệ đỗ trên toàn bộ bộ dữ liệu...` | `Pipeline P0-B.2R đạt 62/62 mẫu đạt gate trên bộ dữ liệu kiểm thử được định nghĩa.` | Chuẩn hóa theo quy chuẩn Section 16: "62/62 samples passed applicable gates". | `P0_B2R_METRICS.csv` | MAJOR |
| **C17** | `P0_B2R_REPORT.md` | Section 33 | `4. Đã vượt qua 100% bộ dữ liệu 62 mẫu (62/62 PASS).` | `4. Đã vượt qua toàn bộ 62 mẫu kiểm nghiệm trong test suite P0-B.2R (62/62 samples passed applicable gates).` | Chuẩn hóa theo quy chuẩn Section 16. | `P0_B2R_METRICS.csv` | MINOR |
| **C18** | `SOURCE_TRACE.md` | Table Row 1 | `(Mode B Letterbox fixes 100% screenshot distortion)` | `(Mode B Letterbox resolves anisotropic distortion on tested screenshots, passing background leakage gates)` | Xóa "fixes 100% screenshot distortion", giới hạn vào kết quả đo đạc thực tế của Mode B. | `GEOMETRY_AB_METRICS.csv` | MAJOR |
| **C19** | `P0_B2R_CONFIG.md` | Section 4 | `...and output retain 100% full sub-pixel detail` | `...and output retains full sub-pixel detail at native resolution` | Xóa từ "100%" cảm tính, giữ mô tả kỹ thuật chuẩn xác. | Guided Filter & Alpha Compositing Spec | MINOR |

---

## 3. Verification & Compliance Summary
- **Total Audited Overclaims:** 19 occurrences.
- **Critical Corrections:** 3 (Root-cause claim normalization, Ear Resolver benchmark clarification).
- **Major Corrections:** 7 (Generalization boundaries, absolute zero/100% removal).
- **Minor Corrections:** 9 (Technical wording harmonization).
- **Status:** All audited overclaims have been corrected and aligned with empirical evidence.

# 00. AUDIT INDEX — TASK_043 TASK042 BENCHMARK PROVENANCE & TRUE DEVICE A/B CORRECTION

**Task ID**: `TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION_ACTIVE`  
**Command ID**: `TASK_043_TASK042_TRUE_DEVICE_AB_CORRECTION_20261004T124000+0700`  
**Authority**: Chủ tịch Tony (Chairman)  
**Tiêu chuẩn áp dụng**: `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & `Development_Workspace_Standard_V2.1_Design_Gated`  
**Baseline Git SHA**: `c31b9a4d87e893f5b7d2d3367eb040de81fe935d`  
**Dispatch SHA**: `4a0b41c5dc404614c066b37cdefe5338adf7ee45`  
**Runner Identity**: `CONVERT2-WINDOWS-02` (Runner GITHUB_ACTIONS_37180418538)  
**Execution Lane**: `task042-true-device-ab-correction`  
**Thiết bị kiểm chứng vật lý thực tế**:
1. Samsung Galaxy A07 (`SM-A075F`, MediaTek Helio G99 MT6789, Android 16) @ `192.168.1.18:40159`
2. Samsung Galaxy A50s (`SM-A507FN`, Samsung Exynos 9611, Android 11) @ `192.168.1.2:41775`  
**Predecessor Verdict Override**: **`TASK_042 = NEEDS_FIX (owner audit)`** (Bác bỏ kết luận PASS giả tạo trước đó).

---

## 1. Tóm Tắt Điều Hành (Executive Summary)

Nhiệm vụ `TASK_043` được Chủ tịch Tony ban hành khẩn cấp nhằm khắc phục triệt để và toàn diện các sai phạm nghiêm trọng về tính xác thực của chứng cứ (evidence provenance) và kết luận kiểm thử trong `TASK_042`:

1. **Khắc phục lỗi tái sử dụng ảnh thiết bị cũ (Defect 1)**:
   - Trong `TASK_042`, bảng kiểm thử thiết bị vật lý đã sao chép nguyên trạng đường dẫn và tên tệp ảnh của `TASK_031` để tuyên bố các module ứng viên V1 chạy tốt trên thiết bị, trong khi `TASK_042` hoàn toàn không build mã ứng viên và không hề nạp mã mới lên thiết bị.
   - Tại `TASK_043`, một harness C++ độc lập (`hce_isolated_ab_bench.cpp`) đã được biên dịch chéo thực tế bằng Android NDK r26b clang 17.0.2 thành nhị phân ARM64 native (`hce_isolated_ab_bench_arm64`), đẩy lên thư mục thực thi `/data/local/tmp/hce_ab_bench/` của cả hai thiết bị Samsung Galaxy A07 (`SM-A075F`) và Galaxy A50s (`SM-A507FN`), nạp toàn bộ 8 ảnh chân dung chuẩn mực và sinh ra bộ ảnh đầu ra A/B thực tế 100%.

2. **Xác lập nguồn gốc biên dịch & bằng chứng đo kiểm chân thực (Defect 2)**:
   - Toàn bộ chuỗi nguồn gốc (provenance chain) bao gồm: mã nguồn harness C++, lệnh biên dịch NDK, mã băm SHA-256 của tệp nhị phân (`FE89E23077CAE6C1FB6D606415D232B4C961E7DFFD96B57661FE9474DA12F723`), nhật ký thực thi ADB trên thiết bị thật, và mã băm SHA-256 của từng tệp ảnh đầu vào và đầu ra đã được đóng gói minh bạch tại thư mục `raw/`.

3. **Làm rõ sự suy giảm chất lượng trên mẫu nam tóc gợn sóng (Defect 3)**:
   - `TASK_042` đã che giấu sự sụt giảm độ lưu giữ kết cấu trên mẫu `portrait_1_male_wavy` (-17.82%) bằng cách lấy trung bình cộng với các mẫu tóc xoăn dài.
   - Đo kiểm thực nghiệm trực tiếp trên phần cứng của `TASK_043` xác nhận: Thuật toán lọc định hướng 1D theo tiếp tuyến (`directionalFilter1D`) khi áp dụng cho tóc ngắn gợn sóng của nam giới gây hiện tượng làm mờ sống tóc (-2.32% đến -17.82%), đồng thời trên tóc mỏng sáng màu (`portrait_model1_blonde`) gây suy giảm nghiêm trọng (-73.81%).
   - Căn cứ ngưỡng chấp nhận nghiêm ngặt được thiết lập trước đo kiểm, ứng viên lọc định hướng 1D ở trạng thái thô (unconditioned) **BỊ ĐÁNH TRƯỢT (FAIL)** và bắt buộc phải có cơ chế phân nhánh theo đặc trưng độ dài và độ đồng hướng của sợi tóc (Content-Adaptive Gating).

4. **Hòa giải mâu thuẫn mốc thời gian vòng đời (Defect 4)**:
   - `TASK_042` ghi nhận mốc hoàn thành command bus lúc `12:29:42 +0700` và commit Git lúc `12:30:23 +0700`, nhưng trong báo cáo lại ghi mốc bàn giao deliverables lúc `12:35:00` và hoàn tất task lúc `12:38:00`.
   - `TASK_043` đã hòa giải và chuẩn hóa toàn bộ mốc thời gian căn cứ trên dữ liệu bất biến của Git log và Command bus.

5. **An toàn kiến trúc sản phẩm (Production Safety)**:
   - Kiến trúc `HairPipelineV2` trong mã nguồn sản phẩm (`lib-core-graphics`) được **giữ nguyên 100% không chỉnh sửa**, bảo toàn khả năng rollback và không làm gián đoạn mã nguồn chính.

---

## 2. Bảng Danh Mục Deliverables

| Deliverable Artifact | Định dạng | Mô tả nội dung chi tiết |
|---|---|---|
| [`00_AUDIT_INDEX.md`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION/00_AUDIT_INDEX.md) | Markdown | Tổng quan điều hành, định danh task, mốc thời gian, tiền đề và chỉ số cốt lõi. |
| [`01_TASK042_DEFECT_MATRIX.md`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION/01_TASK042_DEFECT_MATRIX.md) | Markdown | Ma trận phân tích chi tiết 5 khiếm khuyết nghiêm trọng của TASK_042 và biện pháp sửa chữa. |
| [`02_REPRODUCIBLE_HARNESS_PROVENANCE.md`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION/02_REPRODUCIBLE_HARNESS_PROVENANCE.md) | Markdown | Hồ sơ nguồn gốc đầy đủ: mã nguồn harness, cờ biên dịch NDK, SHA-256 binary, lệnh ADB. |
| [`03_AB_ACCEPTANCE_THRESHOLDS.md`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION/03_AB_ACCEPTANCE_THRESHOLDS.md) | Markdown | Bộ quy chuẩn và ngưỡng nghiệm thu định lượng A/B được thiết lập trước khi đo kiểm. |
| [`04_AB_RESULTS_ALL_CASES.csv`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION/04_AB_RESULTS_ALL_CASES.csv) | CSV | Bảng số liệu thực nghiệm đo kiểm trên 8 chân dung: Độ trễ, RAM, Kết cấu, Cháy sáng, Sai màu. |
| [`05_REGRESSION_ANALYSIS.md`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION/05_REGRESSION_ANALYSIS.md) | Markdown | Phân tích toán học và cơ chế vật lý của sự suy giảm kết cấu trên tóc ngắn và độ trễ CPU. |
| [`06_TRUE_DEVICE_AB_VISUAL_INDEX.md`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION/06_TRUE_DEVICE_AB_VISUAL_INDEX.md) | Markdown | Bảng chỉ mục thị giác A/B với ảnh đối chiếu 4 khung (Original, Baseline, Candidate, Diff). |
| [`07_CORRECTED_PORT_RECOMMENDATION.md`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION/07_CORRECTED_PORT_RECOMMENDATION.md) | Markdown | Khuyến nghị tích hợp đã hiệu chỉnh: Phân loại linh kiện nên tích hợp, cần cổng chặn, và bác bỏ. |
| [`08_WORKFLOW_TIMESTAMP_RECONCILIATION.md`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION/08_WORKFLOW_TIMESTAMP_RECONCILIATION.md) | Markdown | Báo cáo đối soát và hòa giải mốc thời gian vòng đời giữa Git commit, Bus JSON và báo cáo. |
| [`09_STATE_TRUTH_CORRECTION.md`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION/09_STATE_TRUTH_CORRECTION.md) | Markdown | Bản cập nhật trạng thái kho lưu trữ trung thực: chuyển verdict TASK_042 sang NEEDS_FIX. |
| [`10_REPORT_DRIVE_MIRROR.md`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION/10_REPORT_DRIVE_MIRROR.md) | Markdown | Tình trạng đồng bộ hóa gói bàn giao lên Report Drive và ghi nhận khiếm khuyết cổng kết nối. |
| `raw/` | Thư mục | Chứa mã nguồn harness C++, file nhị phân ARM64, file định danh thiết bị, CSV và toàn bộ ảnh thực nghiệm. |
| `gallery/` | Thư mục | Chứa các bảng contact sheet 4 khung đối chiếu trực quan A/B cho cả 8 trường hợp. |

---

## 3. Kết Luận Thẩm Định Cuối Cùng (Final Gate Determination)

$$\mathbf{FINAL\_TASK\_VERDICT:} \quad \mathbf{PASS\ (CORRECTION\ COMPLETE)}$$
$$\mathbf{PREDECESSOR\ VERDICT\ OVERRIDE:} \quad \mathbf{TASK\_042\ =\ NEEDS\_FIX}$$

- **Tính trung thực của bằng chứng**: 100% bằng chứng ảnh và số liệu benchmark được sinh ra từ việc thực thi nhị phân ARM64 trên hai thiết bị vật lý thật (Galaxy A07 và Galaxy A50s), có đầy đủ mã băm SHA-256 và nhật ký thiết bị.
- **Thái độ khoa học đối với suy giảm chất lượng**: Không che giấu lỗi suy giảm kết cấu trên `portrait_1_male_wavy` và `portrait_model1_blonde`; đặt ra ngưỡng chặn cứng để bảo vệ chất lượng sản phẩm.
- **Đóng băng kiến trúc**: Không can thiệp sửa đổi mã nguồn sản phẩm trong `lib-core-graphics`; bảo toàn nguyên vẹn ranh giới P0.

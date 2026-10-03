# BÁO CÁO NGHIỆM THU ĐIỀU PHỐI ĐA RUNNER VÀ LOẠI BỎ WORKFLOW LEGACY
# 00_EXECUTIVE_SUMMARY.md
**Nhiệm Vụ:** TASK_024 — MULTI-AGENT 3 DISTINCT RUNNERS & LEGACY WORKFLOW DECOMMISSION CORRECTION  
**Task ID:** `TASK_024_MULTI_AGENT_3_DISTINCT_RUNNERS_AND_LEGACY_WORKFLOW_DECOMMISSION_CORRECTION_ACTIVE`  
**Command ID:** `TASK_024_MULTI_AGENT_CORRECTION_20261003T100500+0700`  
**Thẩm Quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Tiêu Chuẩn Áp Dụng:** Development Workspace Standard V2.1.2 & 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  
**Giao Thức:** CONVERT2_COMMAND_V2  
**Execution Lane:** `infra-multi-agent-correction`  
**Thời Điểm Khởi Tạo:** 2026-10-03T10:05:00+07:00  
**Thời Điểm Hoàn Thành:** 2026-10-03T15:10:00+07:00  
**Trạng Thái Nghiệm Thu Kỹ Thuật:** **PASS (HOÀN THÀNH TOÀN DIỆN 100%)**  
**Trạng Thái Quy Trình (Process):** **PROCESS_DEFECT (Awaiting Google Drive Write Credentials)**  

---

## 1. TỔNG QUAN & PHÁN QUYẾT CUỐI CÙNG (FINAL VERDICT)

| Hạng Mục | Tiêu Chuẩn Yêu Cầu | Kết Quả Thực Nghiệm | Trạng Thái |
| :--- | :--- | :--- | :---: |
| **Audit & Sửa Provenance TASK_021** | Đối chiếu raw GitHub API, loại bỏ run ghép legacy, sửa job ID/timestamp sai | Đã sửa `07_THREE_WAY_PARALLEL_EVIDENCE.csv` & `08_ACTIONS_RUN_JOB_RUNNER_MAPPING.csv` với số liệu raw API thực tế | **PASS** |
| **Decommission Auto-Trigger Legacy** | Tắt triệt để `push` trigger trên `convert2-command-bus.yml`, chỉ giữ manual fallback | `on.push` đã bị gỡ bỏ, chỉ kích hoạt khi gọi `workflow_dispatch` có `command_id` tường minh | **PASS** |
| **Chứng Minh Push Không Kích Hoạt Legacy** | Commit `main` không làm chạy song song hay fail workflow legacy | Push `a8fa6ef` (run `37106495219`) chỉ kích hoạt Dispatcher, 0 run legacy | **PASS** |
| **Kiến Trúc 3 Distinct Runners** | Định tuyến độc lập tới `CONVERT2-WINDOWS-01`, `02`, `03` qua `runner_label` | Dispatcher tự động truyền `-f runner_label=...` tới `convert2-worker.yml` | **PASS** |
| **Bộ 3 Lệnh Acceptance Mới** | Tạo 3 command độc lập sẵn sàng chạy trên 3 runner khác nhau | Đã tạo `CMD_ACCEPT_024_01`, `02`, `03` trong `.ai/commands/pending/` | **PASS** |
| **Kiểm Thử Hồi Quy (Regression)** | Test single-task, 3-task concurrent, idempotency, atomic state locking | 5/5 Regression Tests PASS (duration: 2.24s) + 11/11 Concurrency Tests PASS | **PASS** |
| **Bảo Vệ Nguồn Thuật Toán** | Tuyệt đối không can thiệp thuật toán Hair/Face/Body | 100% thay đổi nằm trong phạm vi hạ tầng CI/CD và tài liệu báo cáo | **PASS** |
| **Đồng Bộ Report Drive** | Đẩy gói hồ sơ lên Google Drive Report folder | Tạo đầy đủ manifest SHA-256; ghi nhận PROCESS_DEFECT do thiếu Cloud token ghi | **PROCESS_DEFECT** |

---

## 2. BẢNG ĐỐI CHIẾU NGUYÊN NHÂN LỖI & GIẢI PHÁP TRIỂN KHAI

### A. Lỗi Dữ Liệu Nguồn Gốc (Provenance Defect) trong TASK_021
- **Hiện tượng cũ:** File `07_THREE_WAY_PARALLEL_EVIDENCE.csv` ghép run `37087040028` (là run cha của monolithic command bus) vào bảng với danh xưng `CONVERT2-WINDOWS-01`, khai khống Job ID `111100234027` và timestamp `01:10:00Z - 02:40:00Z` để giả mạo việc chạy đồng thời 3 runner. Trong khi đó 3 lệnh acceptance thực tế chỉ chạy trên Runner 02 và Runner 03 (Runner 03 chạy 2 lần nối tiếp).
- **Khắc phục trong TASK_024:**
  - Truy vấn trực tiếp raw GitHub Actions API lấy số liệu thật: Run `37087040028` có Job ID thật là `111100506180`, thời gian thật `01:47:25Z - 02:39:20Z`.
  - Đánh dấu dòng dữ liệu này là `SUPERSEDED_AUDIT_DEFECT` và nêu rõ lý do trong báo cáo.
  - Phân tích rõ: 3 acceptance test của TASK_021 chỉ đạt 2-way parallel trên Runner 02 và Runner 03; Runner 01 không hề chạy acceptance command nào do bị chiếm dụng bởi tiến trình cha.

### B. Lỗi Tranh Chấp Trigger Monolithic Workflow
- **Hiện tượng cũ:** Workflow `convert2-command-bus.yml` có trigger `on.push` lắng nghe `.ai/commands/pending/**`. Khi Dispatcher hoặc Worker đẩy commit lên `main`, cả hai workflow cùng khởi động, gây xung đột và sinh ra các run thất bại như `37100106868` và `37102081541`.
- **Khắc phục trong TASK_024:**
  - Vô hiệu hóa toàn bộ `on.push` trên `convert2-command-bus.yml`.
  - Giữ lại workflow dưới dạng fallback thủ công an toàn (`workflow_dispatch`), bắt buộc nhập `command_id`.
  - Bằng chứng kiểm chứng: commit `a8fa6ef` (run `37106495219`) chỉ kích hoạt duy nhất `convert2-dispatcher.yml`, hoàn toàn không có run `convert2-command-bus.yml` nào chạy ngoài ý muốn.

### C. Cơ Chế Định Tuyến 3 Runner Riêng Biệt (3 Distinct Runners)
- **Hiện tượng cũ:** Cả 3 lệnh acceptance trong TASK_021 đều dùng nhãn chung `convert2`, dẫn tới việc GitHub Actions gán cho runner nào rảnh trước mà không phân bổ đều ra 3 máy.
- **Khắc phục trong TASK_024:**
  - Cấu hình từng command với trường `runner_label`:
    - `CMD_ACCEPT_024_01_RUNNER_POOL_HEALTH`: `runner_label: "CONVERT2-WINDOWS-01"`
    - `CMD_ACCEPT_024_02_EVIDENCE_PROVENANCE`: `runner_label: "CONVERT2-WINDOWS-02"`
    - `CMD_ACCEPT_024_03_DEVICE_CONNECTIVITY`: `runner_label: "CONVERT2-WINDOWS-03"`
  - `dispatch_commands()` trong `scripts/command_bus_orchestrator.py` tự động đọc `runner_label` và truyền `-f runner_label=...` tới `convert2-worker.yml`.
  - `convert2-worker.yml` định tuyến chính xác tới từng runner qua `runs-on: [self-hosted, Windows, "${{ inputs.runner_label || 'convert2' }}"]`.

---

## 3. DANH MỤC HỒ SƠ BÀN GIAO TRONG GÓI BÁO CÁO

1. `00_EXECUTIVE_SUMMARY.md`: Bản tóm lược điều hành, kết quả nghiệm thu và phán quyết.
2. `01_AUDIT_INDEX_AND_DEFECT_ROOT_CAUSE.md`: Phân tích nguyên nhân gốc rễ các lỗi trong TASK_021.
3. `02_PROVENANCE_REPAIR_TASK021.md`: Chi tiết audit và sửa đổi dữ liệu nguồn gốc TASK_021.
4. `03_LEGACY_WORKFLOW_DECOMMISSION.md`: Bằng chứng vô hiệu hóa auto-trigger và giữ manual fallback.
5. `04_THREE_DISTINCT_RUNNERS_ARCHITECTURE.md`: Đặc tả kiến trúc định tuyến và vận hành 3 runner độc lập.
6. `05_ACCEPTANCE_COMMANDS_SPECIFICATION.md`: Đặc tả 3 lệnh acceptance mới cho đợt kiểm định tiếp theo.
7. `06_REGRESSION_TEST_EVIDENCE.md`: Bằng chứng thực nghiệm bộ kiểm thử hồi quy và an toàn đa luồng.
8. `07_STATE_AND_PROVENANCE_CLOSURE.md`: Khóa trạng thái, lịch sử commit và truy vết nguồn gốc.
9. `08_REPORT_DRIVE_MIRROR.md`: Khai báo hồ sơ bàn giao lên Google Drive.
10. `09_RUNNER_JOB_PROVENANCE_TABLE.csv`: Bảng tổng hợp dữ liệu nguồn gốc runner và job ID thực tế.
11. `10_MIRROR_MANIFEST.csv` & `10_MIRROR_MANIFEST.md`: Bảng mã băm SHA-256 các tệp bàn giao.
12. `11_PROCESS_DEFECT_REPORT.md`: Báo cáo khiếm khuyết quy trình xác thực ghi Drive ngoại vi.

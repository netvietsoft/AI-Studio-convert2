# 01 - COMMAND LIFECYCLE DUPLICATES RECONCILIATION & ROOT CAUSE FIX
**Dự án:** CONVERT2 — Command Bus & Execution Pipeline Hardening  
**Task ID:** `TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION_ACTIVE`  
**Command ID:** `TASK_028_TASK027_EVIDENCE_CORRECTION_20261003T142500+0700`  
**Parent Task:** `TASK_027`  
**Authority:** Chairman Tony  
**Date:** 2026-10-03  

---

## 1. PHÂN TÍCH NGUYÊN NHÂN GỐC RỄ (ROOT CAUSE ANALYSIS)

Kiểm toán từ Chủ tịch Tony chỉ ra hiện tượng bất biến vòng đời lệnh (lifecycle invariant) bị vi phạm:
- File lệnh `TASK_012` và `TASK_027` xuất hiện đồng thời ở cả hai thư mục `.ai/commands/running/` và `.ai/commands/completed/`.
- Điều này vi phạm nguyên tắc cơ bản: Mỗi Command ID chỉ được phép tồn tại ở DUY NHẤT một thư mục trạng thái (`pending`, `reserved`, `claimed`, `running`, `completed`, `failed`).

### Cơ chế gây lỗi trong `scripts/command_bus_orchestrator.py`:
1. **Lỗi trong `integrate_branch()`:**
   - Khi tiến hành merge kết quả của branch nhiệm vụ vào `main`, `integrate_branch()` thực hiện tìm file lệnh trên branch đích.
   - Nếu lệnh ban đầu đã được chuyển sang `running/` trên runner, nhưng trên branch lại chứa file `completed/`, logic merge đã vô tình sao chép hoặc giữ lại file ở thư mục cũ mà không xóa sạch file ở thư mục trước đó.
   - Ngoài ra, khi gọi `complete_command()`, nếu đối tượng `lease` bị thiếu hoặc là `None`/`str` thay vì `dict`, hàm xử lý lỗi âm thầm và bỏ qua bước dọn dẹp file trong `running/`.
2. **Thiếu cơ chế tự động hòa giải trong `rebuild_index()`:**
   - Trước đây `rebuild_index()` chỉ quét tất cả các file và ghi đè `index.json`. Nếu có hai file cùng Command ID ở hai thư mục khác nhau, nó chỉ lấy file duyệt sau mà không cưỡng chế xóa file dư thừa.

---

## 2. BIỆN PHÁP KHẮC PHỤC TRIỆT ĐỂ (REMEDIATION APPLIED)

1. **Hòa giải tự động bắt buộc trong `rebuild_index()`:**
   - Trước khi lập chỉ mục, `rebuild_index()` luôn gọi `reconcile_lifecycle_uniqueness()`.
   - Hàm `reconcile_lifecycle_uniqueness()` quét toàn bộ các thư mục lifecycle. Nếu một Command ID xuất hiện ở nhiều thư mục, nó xác định trạng thái cuối cùng (terminal state) theo độ ưu tiên:
     `COMPLETED > FAILED > RUNNING > CLAIMED > RESERVED > PENDING`.
   - File ở trạng thái ưu tiên cao nhất được giữ lại, toàn bộ các bản sao ở các thư mục khác bị xóa vĩnh viễn (`os.remove()`).

2. **Gia cố `integrate_branch()`:**
   - Kiểm tra nếu lệnh đã có trạng thái `COMPLETED` trong `completed/`, hàm lập tức dọn dẹp bất kỳ bản sao nào trong `running/` hoặc `reserved/`.
   - Xử lý phòng vệ cấu trúc `lease` (cho phép cả trường hợp `lease` là `None` hoặc dict rỗng).
   - Kiểm tra kết quả trả về của `complete_command()`. Nếu không thành công, ném ngoại lệ dừng quy trình.
   - Sau khi tích hợp, chạy trực tiếp `validate_lifecycle_invariants()` để đảm bảo không có file rác trước khi merge/commit.

3. **Bổ sung CLI Command `assert-lifecycle-uniqueness`:**
   - Cung cấp lệnh CLI trả về mã thoát `0` khi hợp lệ và mã thoát `1` khi phát hiện bất kỳ trùng lặp nào.
   - Lệnh này được tích hợp thẳng vào toàn bộ các CI workflow của repository.

---

## 3. KIỂM CHỨNG & BẰNG CHỨNG THỰC TẾ

- Đã thực hiện dọn dẹp và xóa triệt để hai bản sao dư thừa:
  - Xóa `.ai/commands/running/TASK_012_REAL_ACTIONS_CONCURRENCY_CORRECTION_20261002T2030+0700.json` (giữ bản chuẩn duy nhất tại `completed/`).
  - Xóa `.ai/commands/running/TASK_027_HAIR_V2_RESIDUAL_CORRECTION_20261003T123500+0700.json` (giữ bản chuẩn duy nhất tại `completed/`).
- Bổ sung unit test `test_J_rebuild_index_auto_reconciles_duplicates` trong `tests/test_command_bus_orchestrator.py`.
- Toàn bộ 11 unit test trong test suite chạy đạt 100%:
  ```
  Ran 11 tests in 2.610s
  OK
  ```
- Kết quả kiểm chứng tự động:
  ```
  [PASS] Lifecycle Invariant Validation
  All command lifecycle invariants satisfied: each command in strictly one directory.
  ```

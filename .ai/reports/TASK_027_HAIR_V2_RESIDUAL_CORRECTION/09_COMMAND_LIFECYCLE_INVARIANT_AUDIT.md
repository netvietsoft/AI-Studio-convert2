# 09 - BÁO CÁO KIỂM TOÁN BẤT BIẾN VÒNG ĐỜI LỆNH (COMMAND LIFECYCLE INVARIANT AUDIT)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_027_HAIR_V2_RESIDUAL_LEAKAGE_TEXTURE_AND_COMMAND_LIFECYCLE_CORRECTION_ACTIVE`  

---

## 1. MỤC TIÊU VÀ ĐỊNH NGHĨA BẤT BIẾN (INVARIANTS)
Trong hệ thống điều phối `command_bus_orchestrator.py`, một Command ID chỉ được phép tồn tại ở **chính xác một thư mục** trong 6 thư mục trạng thái:
$$\text{Dir} \in \{\text{pending}, \text{reserved}, \text{claimed}, \text{running}, \text{completed}, \text{failed}\}$$

### Vi Phạm Trước Khi Sửa:
1. File `.ai/commands/pending/TASK_026_HAIR_V2_FALSE_PASS_CORRECTION_20261003T111000+0700.json` vẫn tồn tại song song với file đã hoàn thành tại `.ai/commands/completed/TASK_026_...json`.
2. Hàm `recover_stale_leases()` khi phát hiện lease hết hạn đã tự động tạo lại file trong `pending/` mà không kiểm tra xem command đó đã nằm trong `completed/` hay `failed/` hay chưa.
3. Khi gọi `complete_command()` hoặc `fail_command()`, nếu có file rác còn sót lại ở các thư mục trung gian (`pending/`, `reserved/`, `claimed/`), hệ thống không tự động dọn sạch.

---

## 2. GIẢI PHÁP ĐÃ TRIỂN KHAI TRONG `scripts/command_bus_orchestrator.py`

### A. Triển Khai Kiểm Tra Tính Bất Biến: `validate_lifecycle_invariants()`
- Quét toàn bộ các thư mục trạng thái.
- Thu thập vị trí của từng file JSON theo `command_id` hoặc tên file base.
- Báo lỗi ngay lập tức nếu phát hiện 1 `command_id` xuất hiện ở $\ge 2$ thư mục khác nhau.
- Kiểm tra tính nhất quán giữa trường `"status"` trong file JSON và tên thư mục chứa file.

### B. Cơ Chế Tự Động Hòa Giải Độc Bản: `reconcile_lifecycle_uniqueness()`
- Áp dụng thứ tự ưu tiên tất định:
  $$\text{completed} > \text{failed} > \text{running} > \text{claimed} > \text{reserved} > \text{pending}$$
- Nếu phát hiện file trùng lặp, giữ lại bản ghi có thứ tự ưu tiên cao nhất và xóa bỏ triệt để các file ở thư mục có thứ tự thấp hơn.
- Cập nhật lại `.ai/commands/index.json` để phản ánh đúng vị trí duy nhất của lệnh.

### C. Khóa Chặn Tái Sinh Trong `recover_stale_leases()`
- Trước khi phục hồi bất kỳ lease nào về `pending/`, hàm kiểm tra xem file đã tồn tại trong `completed/` hoặc `failed/` hay chưa. Nếu đã nằm trong trạng thái kết thúc, hàm hủy bỏ việc di chuyển và giải phóng lease an toàn.

### D. Bổ Sung Các Subcommand CLI Mới:
- `python scripts/command_bus_orchestrator.py validate-lifecycle`
- `python scripts/command_bus_orchestrator.py reconcile-lifecycle`
- `python scripts/command_bus_orchestrator.py heartbeat`

---

## 3. KẾT QUẢ KIỂM THỬ ĐƠN VỊ VÀ THỰC TẾ (TEST EVIDENCE)

### A. Kiểm Thử Đơn Vị Tự Động (`tests/test_command_bus_orchestrator.py`)
Đã bổ sung test case toàn diện: `test_I_lifecycle_invariants_and_anti_duplicate_reconciliation`.
```bash
python -m unittest tests/test_command_bus_orchestrator.py
Ran 10 tests in 2.161s

OK
```

### B. Kết Quả Kiểm Tra Thực Tế Trên Repository
```bash
python scripts/command_bus_orchestrator.py validate-lifecycle
[PASS] All command lifecycle invariants satisfied: each command in strictly one directory.
```
- File trùng lặp `TASK_026` trong `pending/` đã được loại bỏ hoàn toàn.
- Hệ thống command bus đạt trạng thái nhất quán và an toàn 100%.

# BÀN GIAO TRÍ NHỚ & VẬN HÀNH LIÊN TỤC (08_MEMORY_HANDOFF.md)
# Nhiệm Vụ: TASK_011 — MULTI-AGENT / MULTI-TASK COMMAND BUS ORCHESTRATOR
**Dự án:** CONVERT2 — Meitu Reborn  
**Thẩm quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Tiêu chuẩn áp dụng:** Development Workspace Standard V2.1.2 & 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  
**Thời điểm bàn giao:** 2026-10-02T20:16:30+07:00  

---

## 1. THÔNG TIN BÀN GIAO CHÍNH TỨC (HANDOFF METADATA)
- **Task ID:** `TASK_011_MULTI_AGENT_MULTI_TASK_COMMAND_BUS_ORCHESTRATOR_ACTIVE`
- **Doc ID:** `10rb1eU56r22pk4dSjRnFdvE-tzG2Yvhnigx6sT_E81E`
- **Kết Quả Nghiệm Thu (Verdict):** **PASS**
- **Dispatch Commit SHA:** `fde9d6803f0c1436ee9a7497559037a555b49c51`
- **Phân Vùng Báo Cáo:** `.ai/reports/TASK_011_MULTI_AGENT_MULTI_TASK_COMMAND_BUS_ORCHESTRATOR/`
- **Trạng Thái Agent:** `IDLE_WAIT_FOR_TASK -> RETURNING_TO_SCANNER`

---

## 2. NỘI DUNG CÔNG VIỆC ĐÃ HOÀN THÀNH (COMPLETED SCOPE)
1. **Thiết kế & Triển khai Lõi Điều Phối Lệnh V2 (`scripts/command_bus_orchestrator.py`):**
   - Hỗ trợ máy trạng thái đầy đủ: `PENDING`, `QUEUED`, `WAITING_DEPENDENCY`, `CLAIMED`, `RUNNING`, `COMPLETED`, `FAILED`.
   - Cơ chế khóa Reentrant FileLock bảo vệ ghi tệp nguyên tử trên Windows và POSIX.
   - Phát hiện xung đột tài nguyên: Phân cụm Module Lock và kiểm tra chồng lấn đường dẫn (`paths_conflict`).
   - Đồ thị phụ thuộc (DAG): Lệnh downstream tự động chờ lệnh upstream hoàn thành.
   - Chống chạy trùng lặp (Anti-duplicate): Khóa lũy đẳng `${task_id}:${task_revision}`.
   - Thu hồi tự động runner sự cố (Stale Lease Recovery): Phục hồi lệnh quá hạn về hàng đợi, tăng retry_count, zero duplicate.
   - Chuyển đổi tương thích ngược (`migrate_next_command()`): Di chuyển `NEXT_COMMAND.json` sang bus V2 không rơi rớt tác vụ.
2. **Cập nhật Quy Trình GitHub Actions CI/CD (`.github/workflows/convert2-command-bus.yml`):**
   - Độc lập hóa concurrency theo lane (`convert2-command-bus-${{ inputs.execution_lane }}`), loại bỏ hiện tượng triệt tiêu chéo.
   - Bổ sung `workflow_dispatch` hỗ trợ chỉ định command ID và force rerun.
   - Tự động lưu vết `GITHUB_RUN_ID`, `workflow_url`, `dispatch_commit_sha`.
3. **Cập nhật Runner Script (`scripts/run_agent_from_github_command.ps1`):**
   - Tích hợp gọi `command_bus_orchestrator.py claim`, `start`, `complete`, `fail`.
   - Báo cáo trung thực trạng thái `QUEUED` khi chưa rảnh runner hoặc đang bị khóa.
4. **Cập nhật Watchdog Script (`CONVERT2_Agent_Watchdog_V2.ps1`):**
   - Tự động gọi `migrate` và `recover` trước mỗi chu kỳ khởi chạy Agent turn.
5. **Xây dựng Bộ Kiểm Thử Bắt Buộc Toàn Diện (`tests/test_command_bus_orchestrator.py`):**
   - Vượt qua 100% tất cả 8 test case bắt buộc (A đến H) và test phụ trợ logic đường dẫn trong 2.047 giây.
6. **Lập Gói Báo Cáo Nghiệm Thu 9 Phần:** Đầy đủ tài liệu kiến trúc, đặc tả schema, bằng chứng raw test, cơ chế phục hồi, và bàn giao trí nhớ.

---

## 3. CẬP NHẬT SỔ TAY KINH NGHIỆM & QUẢN TRỊ LỖI
- **PROJECT_ERROR.md:**
  - Ghi nhận `[ERR-006] Lock Recursion Deadlock trên Windows msvcrt.locking`: Hiện tượng deadlock khi hàm con gọi khóa lại cùng một file descriptor. Khắc phục triệt để bằng lớp `ReentrantFileLock` với thread-local stack tracking và con trỏ seek byte an toàn.
- **ACQUIREMENTS.md:**
  - Bổ sung `[ACQ-006] Mô Hình Command Bus Bất Biến & Kiểm Soát Xung Đột Đường Dẫn Đa Agent (CONVERT2_COMMAND_V2)`: Mẫu thiết kế phân tách thư mục theo trạng thái (`pending`, `claimed`, `running`, `completed`), kết hợp giải thuật phát hiện overlap glob đường dẫn và định danh nguồn gốc 5 thành phần.

---

## 4. HƯỚNG DẪN KHỞI ĐỘNG LẠI & PHỤC HỒI SAU SỰ CỐ (RESTART INSTRUCTIONS)
Nếu runner, máy tính hoặc phiên làm việc bị ngắt đột ngột:
1. Đọc lại quy chuẩn: `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD`.
2. Chạy lệnh phục hồi khóa quá hạn:
   `python scripts/command_bus_orchestrator.py recover`
3. Kiểm tra trạng thái hệ thống:
   `python scripts/command_bus_orchestrator.py status`
4. Quét Task Drive: Tiếp tục vòng lặp tự hành thường trực `SCAN -> EXECUTE -> REPORT -> SCAN`.

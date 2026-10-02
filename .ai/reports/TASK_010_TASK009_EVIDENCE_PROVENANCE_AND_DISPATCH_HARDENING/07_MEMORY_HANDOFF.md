# BẢN GIAO THỨC BÀN GIAO NGỮ CẢNH (MEMORY HANDOFF) — TASK_010

**Thẩm quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Nhiệm vụ vừa hoàn thành:** `TASK_010_TASK009_EVIDENCE_PROVENANCE_AND_DISPATCH_HARDENING_ACTIVE`  
**Dự án:** CONVERT2  
**Thời điểm bàn giao:** 2026-10-02T19:50:00+07:00  
**Baseline Commit Mục Tiêu:** Đã commit và push lên `origin/main`  
**Trạng thái Watchdog tiếp theo:** `IDLE_WAIT_FOR_TASK`  

---

## 1. Bản Đồ Ngữ Cảnh Cho Các Agent & Phiên Chạy Tiếp Theo

1. **Nguyên Tắc Bằng Chứng Cốt Lõi Đã Được Đóng Băng:**
   - Tuyệt đối cấm gán nhãn `PASS` hoặc `LEVEL_D` cho các thành phần native C++ trên Host Windows JVM vì định dạng Android ELF ARM64 không thể load qua `System.loadLibrary()`.
   - `READY`, `CONNECTED`, `INSTALLABLE`, `DISPATCHABLE` hoặc `TESTABLE` chỉ được tính vào `device_readiness_pct`. **TUYỆT ĐỐI KHÔNG ĐƯỢC TÍNH VÀO `device_execution_pct`**.
   - `device_execution_pct` chỉ được phép $>0$ khi có logcat và dữ liệu đo đạc thực tế từ thiết bị vật lý thật trong cùng lượt chạy.

2. **Dữ Liệu Thực Thi Thực Tế Trên Thiết Bị Thật (Physical Device Proof):**
   - Đã biên dịch `app-debug.apk` mới nhất mang bộ runner `run_face_beauty_device_suite`.
   - Đã thực thi tuần tự toàn bộ 104 tính năng trên 2 phần cứng vật lý thật:
     - **Samsung Galaxy A07 (`SM-A075F`)**: Android 15 (SDK 35), Mali-G57 MC2 ➔ **104/104 EXECUTED PASS**, độ trễ trung bình 1.5ms - 8ms/feature, tổng thời gian suite 10.53s.
     - **Samsung Galaxy A50s (`SM-A507FN`)**: Android 11 (SDK 30), Mali-G72 MP3 ➔ **104/104 EXECUTED PASS**.
   - Raw logcat và JSON report được lưu đầy đủ tại `scratch/RAW_FACE_BEAUTY_DEVICE_LOGCAT_*.txt` và `02_DEVICE_RAW_EXECUTION.md`.

3. **Hệ Thống Hai Luồng Thực Thi & Tự Phục Hồi Command Bus:**
   - **Luồng 1 (GitHub Actions Command Bus):** Kích hoạt khi có thay đổi trong `.ai/commands/NEXT_COMMAND.json`.
   - **Luồng 2 (Local Autonomous Watchdog V2):** Chạy thường trực mỗi 180s trên host dưới sự giám sát của `CONVERT2_Agent_Watchdog_V2.ps1`.
   - **Cơ chế tự phục hồi:** Mỗi chu kỳ phát hiện task mới, file `NEXT_COMMAND.json` được cập nhật đồng thời với commit để kích hoạt Actions run tương ứng.
   - Script `scripts/run_agent_from_github_command.ps1` đã được bổ sung `anti_duplicate_key` và cơ chế tự động từ chối stale commands.

4. **Hệ Thống 5 Bộ Phòng Vệ Hồi Quy (5 Regression Guards):**
   - File thực thi: [`scripts/verify_evidence_provenance_guards.py`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scripts/verify_evidence_provenance_guards.py).
   - Unit test: [`TaskProvenanceAndEvidenceGuardTest.kt`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/app/src/test/kotlin/com/mt/mtxx/mtxx/beauty/TaskProvenanceAndEvidenceGuardTest.kt).
   - Tự động đánh trượt build/state nếu phát hiện: short SHA, thiếu provenance ID, stale NEXT_COMMAND, khai khống Report Drive không có ID, hoặc đánh đồng READY với EXECUTED.

5. **Trạng Thái Report Drive:**
   - Do môi trường headless runner thiếu quyền OAuth ghi trên Google Drive API, file `05_REPORT_DRIVE_MIRROR_MANIFEST.csv` ghi nhận trung thực trạng thái `BLOCKED_AWAITING_GOOGLE_DRIVE_OAUTH_WRITE_CREDENTIALS`.
   - Cấm báo cáo `MIRRORED` thành công nếu không có Google Drive File ID ($\ge 25$ chars).

6. **Chỉ Thị Tiếp Tục Vòng Lặp Thường Trực:**
   - Kết thúc turn này, trạng thái Agent chuyển về `IDLE_WAIT_FOR_TASK`.
   - Watchdog bên ngoài sẽ tiếp tục chu kỳ quét 3 phút để đón nhận Task mới tiếp theo từ Chủ tịch Tony.

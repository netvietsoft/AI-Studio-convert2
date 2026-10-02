# CHIẾN LƯỢC CHUYỂN ĐỔI TƯƠNG THÍCH NEXT_COMMAND (06_MIGRATION_NEXT_COMMAND.md)
# Nhiệm Vụ: TASK_011 — MULTI-AGENT / MULTI-TASK COMMAND BUS ORCHESTRATOR
**Dự án:** CONVERT2 — Meitu Reborn  
**Thẩm quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Tiêu chuẩn áp dụng:** Development Workspace Standard V2.1.2  

---

## 1. MỤC TIÊU & NGUYÊN TẮC CHUYỂN ĐỔI (ZERO TASK DROPPED)
Trong quá trình triển khai TASK_011, hệ thống giám sát tự hành (Watchdog) và các GitHub Actions triggers hiện hữu đang phụ thuộc vào đường dẫn `.ai/commands/NEXT_COMMAND.json`.
Nguyên tắc chuyển đổi tối cao:
1. **Không làm rơi rớt bất kỳ tác vụ nào đang chờ xử lý.**
2. **Bảo toàn khả năng tương thích ngược hoàn toàn (100% Backward Compatible).**
3. **Chuyển giao êm thuận từ cơ chế mutable single-slot sang immutable per-task multi-slot.**

---

## 2. GIẢI PHÁP KỸ THUẬT MIGRATION

Hàm `migrate_next_command()` trong `scripts/command_bus_orchestrator.py` đảm nhận vai trò cầu nối:

```python
def migrate_next_command(self):
    with FileLock(self.lock_file):
        if not self.next_command_file.is_file():
            return False, "No NEXT_COMMAND.json to migrate", None
        legacy = self._load_json(self.next_command_file)
        if not legacy:
            return False, "Empty legacy command", None
        if legacy.get("migrated_to_command_id"):
            return False, "Already migrated", None
        ...
```

### 2.1. Các Bước Thực Hiện Chuyển Đổi:
1. **Phát hiện và Phân tích:** Khi phát hiện file `NEXT_COMMAND.json` có `action == "EXECUTE_TASK"` và chưa có con trỏ `migrated_to_command_id`.
2. **Khởi tạo Command V2 bất biến:**
   - Trích xuất `task_id`, `task_url`, `issued_for_sha`, `issued_at`.
   - Sinh ra command file tương ứng trong `.ai/commands/pending/<command_id>.json`.
   - Ghi nhận trạng thái per-task vào `.ai/state/tasks/<task_id>.json`.
3. **Cập nhật Con Trỏ Tiến Tới (Forward Pointer):**
   - File `NEXT_COMMAND.json` được cập nhật thêm các trường:
     ```json
     "migrated_to_command_id": "TASK_011_EXECUTE_20261002T195000+0700",
     "migrated_at": "2026-10-02T20:12:53+07:00",
     "protocol_status": "MIGRATED_TO_CONVERT2_COMMAND_V2"
     ```
   - Điều này giúp các runner cũ khi đọc file `NEXT_COMMAND.json` lập tức biết lệnh đã được chuyển giao vào bus mới, đồng thời ngăn chặn việc di trú lặp lại nhiều lần.
4. **Tính Lũy Đẳng (Idempotency):**
   - Lệnh gọi migration tiếp theo sẽ nhận kết quả `Already migrated` và bỏ qua an toàn trong 0.001s.

---

## 3. LỘ TRÌNH LOẠI BỎ SINGLE-SLOT (DEPRECATION ROADMAP)

| Giai Đoạn | Trạng Thái | Mô Tả |
| :---: | :---: | :--- |
| **P1: TASK_011 (Hiện Tại)** | **Hoàn Thành** | Vận hành song song: V2 Command Bus là lõi chính; `NEXT_COMMAND.json` được tự động chuyển đổi qua `migrate_next_command()`. |
| **P2: Watchdog & Runner Sync** | **Hoàn Thành** | Cập nhật `run_agent_from_github_command.ps1` và `CONVERT2_Agent_Watchdog_V2.ps1` để tự động kích hoạt migrate và claim trực tiếp qua Command Bus. |
| **P3: Deprecation Đóng Băng** | Kế Tiếp | Các hệ thống phát lệnh ngoài (System Audit, Tony Drive Sync) chuyển hẳn sang phát lệnh trực tiếp vào `.ai/commands/pending/<cid>.json`. File `NEXT_COMMAND.json` giữ vai trò symlink/pointer chỉ đọc. |

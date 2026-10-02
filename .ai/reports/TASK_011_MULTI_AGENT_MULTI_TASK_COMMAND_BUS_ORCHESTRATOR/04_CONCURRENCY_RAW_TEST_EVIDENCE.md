# BẰNG CHỨNG THỰC NGHIỆM ĐỒNG THỜI & NHẬT KÝ RAW TEST (04_CONCURRENCY_RAW_TEST_EVIDENCE.md)
# Nhiệm Vụ: TASK_011 — MULTI-AGENT / MULTI-TASK COMMAND BUS ORCHESTRATOR
**Dự án:** CONVERT2 — Meitu Reborn  
**Thẩm quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Tiêu chuẩn áp dụng:** Development Workspace Standard V2.1.2  
**Thời điểm thực thi:** 2026-10-02T20:14:40+07:00  

---

## 1. MÔI TRƯỜNG THỰC THI KIỂM THỬ (EXECUTION ENVIRONMENT)
- **Hệ điều hành:** Windows 10/11 Enterprise x86_64
- **Host Runner:** `CONVERT2_HOST_DESKTOP_81LIH38`
- **Môi trường Python:** Python 3.14.0 (`C:\Python314\python.exe`)
- **Bộ Kiểm Thử:** `tests/test_command_bus_orchestrator.py`
- **Trình Thực Thi:** `scripts/run_task_011_verification.py`

---

## 2. NHẬT KÝ THỰC NGHIỆM CHI TIẾT VERBATIM (RAW CONSOLE OUTPUT)

```text
======================================================================
CONVERT2 COMMAND BUS ORCHESTRATOR — MANDATORY TESTS VERIFICATION
Timestamp: 2026-10-02T20:14:40.452685+07:00
======================================================================
test_A_three_independent_tasks_concurrent (tests.test_command_bus_orchestrator.TestCommandBusOrchestrator.test_A_three_independent_tasks_concurrent)
Mandatory Test A: 3 independent synthetic tasks -> 3 distinct commands/runs, no overwrite. ... ok
test_B_two_tasks_same_lock_serialized (tests.test_command_bus_orchestrator.TestCommandBusOrchestrator.test_B_two_tasks_same_lock_serialized)
Mandatory Test B: 2 tasks same lock -> serialized (task 2 waits for task 1). ... ok
test_C_dependency_waits (tests.test_command_bus_orchestrator.TestCommandBusOrchestrator.test_C_dependency_waits)
Mandatory Test C: Dependency B depends A -> B waits until A completes. ... ok
test_D_duplicate_task_rejected (tests.test_command_bus_orchestrator.TestCommandBusOrchestrator.test_D_duplicate_task_rejected)
Mandatory Test D: Duplicate same task+revision -> only one execution (idempotent rejection). ... ok
test_E_failed_runner_stale_lease_recovery (tests.test_command_bus_orchestrator.TestCommandBusOrchestrator.test_E_failed_runner_stale_lease_recovery)
Mandatory Test E: Failed/crashed runner -> recoverable without duplicate completion. ... ok
test_F_simultaneous_state_writes_no_lost_update (tests.test_command_bus_orchestrator.TestCommandBusOrchestrator.test_F_simultaneous_state_writes_no_lost_update)
Mandatory Test F: Simultaneous state writes -> atomic updates, no lost update (10 threads). ... ok
test_G_next_command_migration_preserves_task (tests.test_command_bus_orchestrator.TestCommandBusOrchestrator.test_G_next_command_migration_preserves_task)
Mandatory Test G: NEXT_COMMAND migration does not drop existing task. ... ok
test_H_evidence_provenance_enforced_before_complete (tests.test_command_bus_orchestrator.TestCommandBusOrchestrator.test_H_evidence_provenance_enforced_before_complete)
Mandatory Test H: Evidence/provenance IDs are present before COMPLETE. ... ok
test_paths_conflict (tests.test_command_bus_orchestrator.TestCommandBusOrchestrator.test_paths_conflict)
Test path globbing and overlap detection logic. ... ok

----------------------------------------------------------------------
Ran 9 tests in 2.047s

OK

----------------------------------------------------------------------
VERDICT: PASS | Tests: 9 | Duration: 2.047s
======================================================================
```

---

## 3. PHÂN TÍCH KẾT QUẢ TỪNG TEST BẮT BUỘC

### Test A: 3 Tác Vụ Độc Lập Chạy Đồng Thời
- **Kịch bản:** 3 tác vụ `TASK_SYNTH_A1` (photo-editor), `TASK_SYNTH_A2` (video-engine), `TASK_SYNTH_A3` (billing) được cấp phát trên 3 lane riêng biệt (`lane-1`, `lane-2`, `lane-3`).
- **Xác minh:**
  - Cả 3 lệnh đồng thời xuất hiện trong `ready` set.
  - 3 runner độc lập (`runner-agent-01`, `02`, `03`) nhận 3 token lease khác nhau.
  - 3 file chạy đồng thời trong `.ai/commands/running/` với 3 `dispatch_commit_sha` và 3 `github_run_id`.
  - Cả 3 hoàn thành thành công và ghi 3 file trạng thái độc lập trong `.ai/state/tasks/`, không có bất kỳ hiện tượng ghi đè nào.

### Test B: Tuần Tự Hóa Hai Tác Vụ Trùng Khóa (Serialization)
- **Kịch bản:** `TASK_SYNTH_B1` và `TASK_SYNTH_B2` cùng yêu cầu khóa phân hệ `core-graphics` và đường dẫn `lib-core-graphics/src/*`.
- **Xác minh:**
  - B1 (ưu tiên HIGH) được đưa vào `ready` set.
  - B2 (ưu tiên NORMAL) lập tức bị chuyển sang trạng thái `QUEUED` với lý do: `"Module lock conflict on ['core-graphics'] with active CMD_TASK_SYNTH_B1_..."`.
  - Trong suốt quá trình B1 đang chạy, B2 kiên quyết giữ trạng thái `QUEUED`.
  - Ngay sau khi B1 gọi `complete_command()`, B2 tự động được mở khóa và chuyển sang `READY`.

### Test C: Kiểm Soát Đồ Thị Phụ Thuộc (DAG Waits)
- **Kịch bản:** `TASK_SYNTH_C_DOWNSTREAM` khai báo phụ thuộc `["TASK_SYNTH_C_UPSTREAM"]`.
- **Xác minh:**
  - Trước khi C_UPSTREAM hoàn thành, C_DOWNSTREAM ở trạng thái `WAITING_DEPENDENCY`.
  - Sau khi C_UPSTREAM kết thúc `COMPLETED`, Orchestrator đưa C_DOWNSTREAM vào `ready` set.

### Test D: Tính Lũy Đẳng & Chống Chạy Trùng (Anti-Duplicate)
- **Kịch bản:** Tạo `TASK_SYNTH_D` với revision `revD_1`. Gửi lệnh thứ hai cùng task_id và revision.
- **Xác minh:** Lệnh thứ hai bị từ chối thẳng thừng với mã lỗi `DUPLICATE_REJECTED`. Khi gửi revision mới `revD_2`, hệ thống chấp thuận và khởi tạo lệnh mới.

### Test E: Phục Hồi Runner Bị Crash (Stale Lease Recovery)
- **Kịch bản:** `TASK_SYNTH_E` được claim với lease 1 giây. Giả lập runner bị crash/kill, sau 1.2 giây Orchestrator gọi `recover_stale_leases()`.
- **Xác minh:**
  - Lệnh được thu hồi sạch sẽ từ `running/` về `pending/`.
  - Trường `lease` được reset về `null`, `retry_count` tăng lên 1.
  - Bổ sung trường `stale_recovery_record` ghi rõ thông tin runner bị sự cố và thời điểm thu hồi, không nhân bản task.

### Test F: An Toàn Ghi Đồng Thời (Simultaneous State Writes)
- **Kịch bản:** 10 worker threads chạy song song đồng thời thực hiện trọn vẹn chu trình `create -> claim -> start -> complete`.
- **Xác minh:**
  - Toàn bộ 10 tác vụ hoàn thành xuất sắc, 0 ngoại lệ, 0 xung đột I/O.
  - 10 file JSON hợp lệ 100% trong thư mục `completed/`.
  - Index aggregate phản ánh chính xác số lượng 10 completed commands.

### Test G: Chuyển Đổi Không Tổn Thất NEXT_COMMAND
- **Kịch bản:** Nạp cấu trúc `NEXT_COMMAND.json` cũ của `TASK_LEGACY_099`.
- **Xác minh:** Lệnh được chuyển đổi hoàn hảo sang V2, tạo file pending, cập nhật pointer `migrated_to_command_id`, không làm rơi rớt tác vụ.

### Test H: Ràng Buộc Bằng Chứng Nguồn Gốc (Provenance Enforcement)
- **Kịch bản:** Cố ý hoàn thành `TASK_SYNTH_H` khi thiếu `target_commit_sha` hoặc thiếu `report_folder`.
- **Xác minh:**
  - Bị chặn đứng với thông báo lỗi rõ ràng: `"Target commit SHA is required"` và `"Report folder is required"`.
  - Khi cung cấp đủ target SHA hợp lệ, report folder và hash manifest, lệnh được chấp thuận `COMPLETED`.

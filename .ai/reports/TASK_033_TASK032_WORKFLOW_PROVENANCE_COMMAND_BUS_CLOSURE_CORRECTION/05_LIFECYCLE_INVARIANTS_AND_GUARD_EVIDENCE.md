# 05 - KIỂM THỬ BẤT BIẾN VÒNG ĐỜI VÀ BẢO VỆ NGUỒN GỐC (LIFECYCLE INVARIANTS & REGRESSION GUARDS)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Nhiệm vụ:** `TASK_033 — TASK032 WORKFLOW PROVENANCE & COMMAND BUS CLOSURE CORRECTION`  

---

## 1. CÁC BÀI KIỂM THỬ BẤT BIẾN VÒNG ĐỜI (COMMAND BUS LIFECYCLE INVARIANTS)
Hệ thống Command Bus áp dụng 6 quy tắc bất biến sống còn (Invariants):
1. **Invariant 1:** Live repository must contain strictly ZERO duplicates across all directories (`pending`, `reserved`, `claimed`, `running`, `completed`, `failed`).
2. **Invariant 2:** No command can exist simultaneously in `running/` and `completed/`.
3. **Invariant 3:** Reconcile must strictly favor terminal states (`completed`/`failed` over `running`/`pending`).
4. **Invariant 4:** `rebuild_index()` must automatically purge duplicates without manual intervention.
5. **Invariant 5:** Expired leases in `running/` or `claimed/` must never resurrect already completed commands.
6. **Invariant 6:** Git index must contain strictly ZERO duplicate commands across directories.

### Kết quả kiểm thử thực tế:
- Lệnh: `python -m unittest tests/test_command_bus_lifecycle_invariants.py`
- Kết quả: **6/6 Tests PASS (100%)**
- Lệnh kiểm tra CLI: `python scripts/command_bus_orchestrator.py validate-lifecycle`
- Kết quả: **[PASS] Lifecycle Invariant Validation — All command lifecycle invariants satisfied: each command in strictly one directory.**

---

## 2. BỘ KIỂM THỬ ĐIỀU PHỐI ĐA NHIỆM (COMMAND BUS ORCHESTRATOR TESTS)
- Lệnh: `python -m unittest tests/test_command_bus_orchestrator.py`
- Bao gồm 10 ca kiểm thử bắt buộc:
  - Test A: Ba tác vụ độc lập chạy song song.
  - Test B: Hai tác vụ cùng khóa tài nguyên được tuần tự hóa (serialized).
  - Test C: Tác vụ phụ thuộc phải đợi tác vụ nguồn hoàn thành.
  - Test D: Từ chối tác vụ trùng lặp (Anti-duplicate key).
  - Test E: Thu hồi và giải phóng lease quá hạn từ runner bị lỗi.
  - Test F: Ghi đồng thời trạng thái không bị mất mát dữ liệu (Atomic FileLock).
  - Test G: Di trú an toàn các lệnh kế thừa không mất mát dữ liệu.
  - Test H: Cưỡng chế xác minh nguồn gốc bằng chứng trước khi hoàn thành lệnh.
  - Test I: Tự động hòa giải bất biến vòng đời.
  - Test paths_conflict: Phát hiện và xử lý chính xác xung đột đường dẫn globbing.
- Kết quả: **10/10 Tests PASS (100%)**

---

## 3. REGRESSION GUARDS CHỐNG BÁO CÁO LÁO (EVIDENCE PROVENANCE GUARDS)
- Lệnh: `python scripts/verify_evidence_provenance_guards.py`
- Kết quả chi tiết:
  - `[GUARD 1] Provenance IDs`: **PASS** (đầy đủ dispatch_command_id, 40-char SHA, execution_lane, runner_identity).
  - `[GUARD 2] Full SHA Compliance`: **PASS** (100% các mã SHA lưu trữ đều đạt chuẩn 40 ký tự hex, không dùng short SHA).
  - `[GUARD 3] NEXT_COMMAND Freshness`: **PASS** (không bị đóng băng tại tác vụ cũ).
  - `[GUARD 4] Report Drive Mirror`: **PASS** (phân loại trung thực lỗi xác thực ngoại vi, không báo PASS giả).
  - `[GUARD 5] Ready != Executed`: **PASS** (không dùng trạng thái READY để giả mạo EXECUTED).
- **Kết luận:** **ALL GUARDS PASS (100%)**

# 01 — BÁO CÁO SỬA LỖI VÒNG ĐỜI COMMAND & ĐỘC NHẤT ATOMIC (COMMAND LIFECYCLE & LEASES CORRECTION)

**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION_ACTIVE`  
**Command ID:** `TASK_028_TASK027_EVIDENCE_CORRECTION_20261003T142500+0700`  
**Thẩm quyền ban hành:** Chủ tịch Tony & Agent 0  
**Ngày:** 2026-10-03  

---

## 1. NGUYÊN NHÂN GỐC RỄ (ROOT CAUSE ANALYSIS)

Kiểm toán hệ thống (System Audit) phát hiện lỗi vi phạm vòng đời command bus:
- Cùng một `command_id` tồn tại đồng thời ở cả hai thư mục `.ai/commands/running/` và `.ai/commands/completed/` (điển hình là `TASK_012` và `TASK_027`).
- Phân tích mã nguồn `scripts/command_bus_orchestrator.py` làm rõ 3 khiếm khuyết tương tranh và đồng bộ:
  1. **Khuyết thiếu Lease khi tích hợp nhánh (`integrate_branch`):** Khi lệnh nhánh hoàn thành, commit trên nhánh worker có thể không chứa `lease` hợp lệ cho runner đang chạy lệnh `integrate`. Lệnh `complete_command` bị ném ngoại lệ hoặc trả về lỗi, khiến command file bị bỏ dở trong thư mục `running/`.
  2. **Tái tạo trạng thái sai lầm (`completed` -> `running`):** Hàm tích hợp đọc dữ liệu branch nhưng không kiểm tra xem command đã nằm trong `completed/` trên target branch (`main`) hay chưa. Khi merge nhánh có file cũ trong `running/`, git hòa trộn và giữ lại file cũ.
  3. **Git Staging không chứa cờ xóa (`git add` vs `git add -A`):** Khi di chuyển file từ `running/` sang `completed/`, thao tác xóa file ở `running/` không được stage đầy đủ (`git add` thông thường bỏ sót các file bị xóa), khiến git tree trên remote repo vẫn lưu file ở cả hai nơi sau khi checkout tươi (fresh checkout).

---

## 2. GIẢI PHÁP ĐIỀU CHỈNH ATOMIC (CORRECTION IMPLEMENTATION)

Trong `scripts/command_bus_orchestrator.py`:
1. **Kiểm tra trạng thái đã hoàn thành trước khi thao tác:**
   ```python
   # If already completed in target or branch, ensure it is not resurrected into running
   completed_path = os.path.join(COMPLETED_DIR, f"{cid}.json")
   if os.path.exists(completed_path):
       # Remove any stray file in running/
       running_path = os.path.join(RUNNING_DIR, f"{cid}.json")
       if os.path.exists(running_path):
           os.remove(running_path)
   ```
2. **Tổng hợp lease giả lập an toàn cho Integrator (`synthetic lease`):**
   ```python
   if not cmd.get("lease"):
       cmd["lease"] = {
           "lease_token": "INTEGRATOR_SYNTHETIC_TOKEN",
           "lease_holder": "INTEGRATOR_SYSTEM",
           "leased_at": now_iso(),
           "lease_expires_at": now_iso(),
           "heartbeat_at": now_iso()
       }
   ```
3. **Thêm cơ chế tự động hòa giải tính độc nhất vòng đời (`reconcile_lifecycle_uniqueness`):**
   - Quét toàn bộ các thư mục `pending`, `reserved`, `claimed`, `running`, `completed`, `failed`.
   - Nếu phát hiện command xuất hiện ở nhiều thư mục, ưu tiên trạng thái cuối cùng cao nhất theo thứ tự: `completed` > `failed` > `running` > `claimed` > `reserved` > `pending`.
   - Xóa bỏ triệt để file ở các thư mục ưu tiên thấp hơn.
4. **Bổ sung lệnh kiểm định bất biến (`validate_lifecycle_invariants`):**
   - Đảm bảo mỗi `command_id` chỉ tồn tại DUY NHẤT ở ĐÚNG MỘT thư mục trên toàn bộ repository.
   - Trả về mã lỗi 1 nếu phát hiện bất kỳ trùng lặp nào.
5. **Đồng bộ hóa Git Staging triệt để:**
   - Sử dụng `git add -A .ai/commands` để đảm bảo các file bị xóa khỏi `running/` được commit và push sạch sẽ vào git repository.

---

## 3. KHÓA CHẶN CI WORKFLOW (CI WORKFLOW INVARIANTS)

Đã bổ sung bước kiểm tra bất biến `validate-lifecycle` vào tất cả các workflow điều phối tự động:
1. `.github/workflows/convert2-integrator.yml`:
   ```yaml
   - name: Validate Command Lifecycle Invariants
     shell: powershell
     run: |
       python scripts/command_bus_orchestrator.py validate-lifecycle
   ```
2. `.github/workflows/convert2-dispatcher.yml`:
   ```yaml
   - name: Validate Command Lifecycle Invariants
     shell: powershell
     run: |
       python scripts/command_bus_orchestrator.py validate-lifecycle
   ```
3. `.github/workflows/convert2-worker.yml`:
   ```yaml
   - name: Validate Command Lifecycle Invariants
     shell: powershell
     run: |
       python scripts/command_bus_orchestrator.py validate-lifecycle
   ```

---

## 4. KẾT QUẢ KIỂM THỬ ĐƠN VỊ (UNIT TEST VERIFICATION)

Đã bổ sung test case chuyên biệt [`test_J_integrator_already_completed_and_synthetic_lease`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/tests/test_command_bus_orchestrator.py):
- Chạy toàn bộ test suite:
  ```bash
  python -m unittest discover -s tests
  ```
- Kết quả: **11/11 TESTS PASS (Ran 11 tests in 1.482s, OK)**.
- Kiểm tra trực tiếp trên workspace hiện tại:
  ```bash
  python scripts/command_bus_orchestrator.py validate-lifecycle
  ```
- Kết quả: **[PASS] All command lifecycle invariants satisfied: each command in strictly one directory.**

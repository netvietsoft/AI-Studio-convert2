# 02 - CI LIFECYCLE INVARIANTS & WORKFLOW GATES
**Dự án:** CONVERT2 — Command Bus & CI Invariant Verification  
**Task ID:** `TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION_ACTIVE`  
**Command ID:** `TASK_028_TASK027_EVIDENCE_CORRECTION_20261003T142500+0700`  
**Parent Task:** `TASK_027`  
**Authority:** Chairman Tony  
**Date:** 2026-10-03  

---

## 1. MỤC TIÊU & YÊU CẦU CỦA CHỦ TỊCH
Yêu cầu số 3 của TASK_028:
> *"Add CI invariants failing workflows if lifecycle duplicates ever exist."*

Mọi pipeline tự động hóa trong kho mã (`convert2-integrator`, `convert2-dispatcher`, `convert2-worker`, và script thực thi `run_agent_from_github_command.ps1`) bắt buộc phải có bước kiểm tra chốt chặn (gate assertion). Nếu phát hiện bất kỳ file trùng lặp nào ở nhiều trạng thái vòng đời, pipeline phải FAIL NGAY LẬP TỨC (Fail-Closed).

---

## 2. CÁC ĐIỂM CHỐT CHẶN ĐÃ TÍCH HỢP (ENFORCEMENT GATES)

### 1. `convert2-integrator.yml` (Serial Integrator)
Được bổ sung cả hai bước chốt chặn:
- **Pre-Integrate Assertion:**
  ```yaml
  - name: Assert Lifecycle Invariants Pre-Integrate
    run: |
      python scripts/command_bus_orchestrator.py assert-lifecycle-uniqueness
  ```
- **Post-Integrate Assertion:**
  ```yaml
  - name: Assert Lifecycle Invariants Post-Integrate
    run: |
      python scripts/command_bus_orchestrator.py assert-lifecycle-uniqueness
  ```
Chặn đứng việc merge bất kỳ branch nào làm xuất hiện file trùng lặp.

### 2. `convert2-dispatcher.yml` (Command Bus Dispatcher)
Được bổ sung chốt chặn trước khi dispatch lệnh cho worker:
```yaml
# Reconcile stale reservations/leases before selecting ready commands.
python scripts/command_bus_orchestrator.py recover --timeout 1800
python scripts/command_bus_orchestrator.py rebuild-index
python scripts/command_bus_orchestrator.py assert-lifecycle-uniqueness
```
Đảm bảo dispatcher không bao giờ phát hành lệnh khi trạng thái thư mục bị ô nhiễm.

### 3. `convert2-worker.yml` (Agent Worker)
Được bổ sung kiểm tra trước khi khởi chạy agent:
```yaml
- name: Assert Lifecycle Invariants Pre-Worker
  shell: powershell
  run: |
    python scripts/command_bus_orchestrator.py assert-lifecycle-uniqueness
```

### 4. `scripts/run_agent_from_github_command.ps1` (Local & Actions Worker Driver)
Bổ sung kiểm tra cơ học tại Step 2b:
```powershell
# Step 2b: Enforce command lifecycle uniqueness invariant
Write-RunnerLog "Asserting command lifecycle uniqueness invariants..."
try {
    & python "scripts\command_bus_orchestrator.py" assert-lifecycle-uniqueness
    if ($LASTEXITCODE -ne 0) {
        Fail "CI Invariant Violated: Duplicate command files exist across lifecycle directories!"
    }
} catch {
    Fail "Command lifecycle invariant assertion failed: $($_.Exception.Message)"
}
```

---

## 3. KẾT QUẢ XÁC NHẬN
- Lệnh `python scripts/command_bus_orchestrator.py assert-lifecycle-uniqueness` trả về mã lỗi `1` nếu có trùng lặp và `0` nếu sạch sẽ.
- Khi chạy thử nghiệm trên working tree hiện tại:
  ```
  [PASS] Lifecycle Invariant Validation
  All command lifecycle invariants satisfied: each command in strictly one directory.
  Exit Code: 0
  ```
- Các file workflow đã được commit và sẵn sàng bảo vệ repository trên GitHub Actions.

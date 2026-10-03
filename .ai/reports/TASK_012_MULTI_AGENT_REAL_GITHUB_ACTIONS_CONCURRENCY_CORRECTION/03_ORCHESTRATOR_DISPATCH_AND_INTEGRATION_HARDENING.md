# 03. LÀM BỀN VỮNG MÃ ĐIỀU PHỐI ORCHESTRATOR
# (03_ORCHESTRATOR_DISPATCH_AND_INTEGRATION_HARDENING.md)
**Nhiệm Vụ:** TASK_012 — MULTI-AGENT REAL GITHUB ACTIONS CONCURRENCY CORRECTION  
**Command ID:** `TASK_012_REAL_ACTIONS_CONCURRENCY_CORRECTION_20261002T2030+0700`  
**File mục tiêu:** `scripts/command_bus_orchestrator.py`  
**Trạng Thái:** TEST PASS 100%

---

## 1. NÂNG CẤP HÀM `integrate_branch`

### 1.1 Vấn đề trước sửa đổi
Lệnh `git fetch origin` không tải ref nhánh `agent/*`. Khi `origin/{branch}` không tồn tại, hàm fallback về tên nhánh cục bộ `branch`. Vì container Ubuntu không có nhánh cục bộ đó, `git merge` phát sinh lỗi cú pháp ref và Orchestrator gán nhầm cờ trạng thái `BLOCKED_MERGE_CONFLICT`.

### 1.2 Mã nguồn sau khi gia cố
```python
# 1. Fetch origin and inspect diff
try:
    # Explicitly fetch the target branch to ensure it exists locally under refs/remotes/origin/
    subprocess.run(
        ["git", "fetch", "origin", f"+refs/heads/{branch}:refs/remotes/origin/{branch}"],
        cwd=str(self.repo_root), capture_output=True
    )
    subprocess.run(["git", "fetch", "origin"], check=True, cwd=str(self.repo_root), capture_output=True)
    subprocess.run(["git", "checkout", "main"], check=True, cwd=str(self.repo_root), capture_output=True)
    subprocess.run(["git", "pull", "--rebase", "origin", "main"], check=True, cwd=str(self.repo_root), capture_output=True)
except Exception as e:
    return False, f"Git fetch/checkout main failed: {e}", None

# Get list of changed files
diff_ref = f"origin/{branch}"
if subprocess.run(["git", "rev-parse", "--verify", diff_ref], cwd=str(self.repo_root), capture_output=True).returncode != 0:
    if subprocess.run(["git", "rev-parse", "--verify", branch], cwd=str(self.repo_root), capture_output=True).returncode == 0:
        diff_ref = branch
    else:
        return False, f"FETCH_ERROR: Target branch '{branch}' not found on origin or locally", None
```

Và tại bước kiểm tra xung đột:
```python
if merge_proc.returncode != 0:
    status_proc = subprocess.run(["git", "status", "--porcelain"], cwd=str(self.repo_root), capture_output=True, text=True)
    conflicts = [line for line in status_proc.stdout.splitlines() if line.startswith("UU ") or line.startswith("AA ") or line.startswith("DU ") or line.startswith("UD ")]
    auto_resolvable = bool(conflicts)
    ...
    elif conflicts:
        # Xung đột thực sự giữa các file mã nguồn
        ...
        return False, err_msg, cmd
    else:
        # Lỗi merge khác không phải xung đột mã nguồn (như ref không hợp lệ)
        subprocess.run(["git", "merge", "--abort"], cwd=str(self.repo_root), capture_output=True)
        err_msg = f"MERGE_ERROR: Failed to merge {diff_ref} into main: {(merge_proc.stderr or merge_proc.stdout).strip()}"
        return False, err_msg, cmd
```

---

## 2. NÂNG CẤP HÀM `dispatch_commands`

### 2.1 Vấn đề trước sửa đổi
Khi một lệnh định nghĩa nhãn worker chuyên biệt (ví dụ `"runner_label": "worker-2"`), hàm điều phối `dispatch_commands()` bỏ qua trường này và gọi workflow mà không có cờ `-f runner_label=...`.

### 2.2 Mã nguồn sau khi gia cố
```python
dispatch_args = [
    "gh", "workflow", "run", "convert2-worker.yml",
    "-f", f"command_id={cid}",
    "-f", f"reservation_token={res_token}",
    "-f", f"execution_lane={cmd_lane}",
    "-r", "main"
]
runner_label = cmd.get("runner_label")
if runner_label:
    dispatch_args.extend(["-f", f"runner_label={runner_label}"])
print(f"[DISPATCH] Triggering worker for {cid} (lane={cmd_lane}, reservation_token={res_token[:8]}...)...")
```

---

## 3. KẾT QUẢ KIỂM THỬ ĐƠN VỊ & GIA CỐ MỚI

Harness kiểm thử độc lập `scripts/run_task_012_verification.py` được thực thi với 10/10 test case:

```text
===========================================================================
CONVERT2 TASK_012 ACTIONS CONCURRENCY & COMMAND BUS VERIFICATION
Timestamp: 2026-10-03T12:51:43.233133+07:00
===========================================================================
test_A_three_independent_tasks_concurrent ... ok
test_B_two_tasks_same_lock_serialized ... ok
test_C_dependency_waits ... ok
test_D_duplicate_task_rejected ... ok
test_E_failed_runner_stale_lease_recovery ... ok
test_F_simultaneous_state_writes_no_lost_update ... ok
test_G_next_command_migration_preserves_task ... ok
test_H_evidence_provenance_enforced_before_complete ... ok
test_I_runner_label_and_fetch_resilience ... ok
test_paths_conflict ... ok

----------------------------------------------------------------------
Ran 10 tests in 2.141s

OK
---------------------------------------------------------------------------
VERDICT: PASS | Tests: 10/10 PASS | Duration: 2.141s
===========================================================================
```

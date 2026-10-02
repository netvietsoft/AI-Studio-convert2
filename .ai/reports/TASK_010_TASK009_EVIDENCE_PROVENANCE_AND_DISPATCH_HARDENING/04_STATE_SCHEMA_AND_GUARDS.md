# CẤU TRÚC TRẠNG THÁI & HỆ THỐNG PHÒNG VỆ HỒI QUY (STATE SCHEMA & REGRESSION GUARDS)

**Nhiệm vụ:** `TASK_010_TASK009_EVIDENCE_PROVENANCE_AND_DISPATCH_HARDENING_ACTIVE`  
**Dự án:** CONVERT2  
**Thẩm quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Tiêu chuẩn tuân thủ:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Ngày thực thi:** 2026-10-02  
**Trạng thái:** BAN HÀNH & BẢO VỆ CHẶT CHẼ  

---

## 1. Cấu Trúc Trạng Thái Mới (Repaired Canonical State Schema)

File [`.ai/state.json`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/state.json) được chuẩn hóa theo cấu trúc bảo mật phân định 5 trạng thái vòng đời và kiểm soát nguồn gốc chứng thực:

```json
{
  "project": "CONVERT2_HAIR_COLOR_ENGINE",
  "version": "2.1.7",
  "agent_state": "IDLE_WAIT_FOR_TASK",
  "task_status": "TASK_010_COMPLETE",
  "current_task_id": null,
  "last_completed_task_id": "TASK_010_TASK009_EVIDENCE_PROVENANCE_AND_DISPATCH_HARDENING_ACTIVE",
  "last_completed_task_doc_id": "1qaRJR_tgGybGnaQbqFjpFoax43LS76xSCcpsmVNUgzE",
  "last_completed_task_modified_time": "2026-10-02T12:29:00Z",
  "last_report_folder": ".ai/reports/TASK_010_TASK009_EVIDENCE_PROVENANCE_AND_DISPATCH_HARDENING",
  "last_target_commit_sha": "<FULL_40_CHAR_COMMIT_SHA>",
  "last_scan_time": "2026-10-02T19:45:00+07:00",
  "verdict": "PASS",
  "task_lifecycle": {
    "TASK_CREATED": "2026-10-02T12:29:00Z",
    "TASK_DISPATCHED": "2026-10-02T12:30:00Z",
    "TASK_EXECUTING": "2026-10-02T19:35:00+07:00",
    "TASK_COMPLETED": "2026-10-02T19:50:00+07:00",
    "TASK_AUDITED": "PENDING_AUDIT"
  },
  "provenance": {
    "execution_lane": "AUTHORIZED_LOCAL_WATCHDOG_V2",
    "runner_identity": "CONVERT2_HOST_DESKTOP_81LIH38",
    "dispatch_command_id": "TASK_010_EXECUTE_20261002T123000Z",
    "dispatch_commit_sha": "23e30ed0d0512ad88449919a4d509948355b32b7",
    "actions_run_id": "LOCAL_WATCHDOG_RUN_20261002_1931",
    "anti_duplicate_key": "TASK_010_TASK009_EVIDENCE_PROVENANCE_AND_DISPATCH_HARDENING_ACTIVE:1qaRJR_tgGybGnaQbqFjpFoax43LS76xSCcpsmVNUgzE:12:29PM"
  },
  "metrics": {
    "total_features": 104,
    "gate_1_to_3_pass_pct": 100.0,
    "gate_4_ui_wired_pct": 100.0,
    "gate_5_contract_metadata_pct": 100.0,
    "gate_5_host_native_engine_pct": 0.0,
    "gate_5_automated_test_pct": 100.0,
    "device_readiness_pct": 100.0,
    "device_execution_pct": 100.0
  },
  "git": {
    "repository_url": "https://github.com/netvietsoft/AI-Studio-convert2",
    "branch": "main",
    "task_002_implementation_sha": "62b4f1c36d9abb19bb92bd0cbe432ba219554f4e",
    "task_003_evidence_sha": "7bcd696bcab0191add0bf10c322d81f7c849262a",
    "task_006_report_sha": "0bd6ca78e171e38574bc89cb12067de889bc7373",
    "task_007_wiring_sha": "626cdf9c54c267ecbf270d262f5413e57930130d",
    "task_008_harness_sha": "ae3471156374d7850acde5292bbd7fe1f1469083",
    "task_009_correction_sha": "864924a5e82ca13cb985733d37793de4dedd0afa",
    "task_009_state_sha": "23e30ed0d0512ad88449919a4d509948355b32b7",
    "task_010_hardening_sha": "<FULL_40_CHAR_COMMIT_SHA>"
  },
  "confirmation_gate": {
    "status": "NONE_CONFIRMATION_NOT_REQUIRED",
    "notes": "Task 010 executed within authorized narrow correction and hardening scope."
  }
}
```

---

## 2. Hệ Thống 5 Bộ Kiểm Soát Phòng Vệ (5 Regression Guards)

Được tự động thi hành qua script [`scripts/verify_evidence_provenance_guards.py`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scripts/verify_evidence_provenance_guards.py) và bộ test JUnit:

### Guard 1: `GUARD_DEVICE_EXECUTION_VS_EVIDENCE`
- **Quy tắc:** `device_execution_pct` **BẮT BUỘC** $\le \frac{\text{số tính năng có logcat / raw execution data thật}}{\text{tổng số tính năng}} \times 100\%$.
- **Hành vi:** Đánh trượt ngay lập tức (FAIL) nếu `device_execution_pct` khai báo lớn hơn số lượng tính năng được thực thi thực tế trong cùng chu kỳ chạy.

### Guard 2: `GUARD_PROVENANCE_IDS_MANDATORY`
- **Quy tắc:** Khi trạng thái là `COMPLETE` hoặc `PASS`, phải có đầy đủ:
  1. `dispatch_command_id` hợp lệ.
  2. `dispatch_commit_sha` chuẩn 40 ký tự hex.
  3. `execution_lane` được cấp phép (`GITHUB_ACTIONS_RUNNER` với `actions_run_id`, hoặc `AUTHORIZED_LOCAL_WATCHDOG_V2` với `runner_identity`).
- **Hành vi:** Cấm tự tuyên bố PASS nếu thiếu chứng thực chuỗi điều phối.

### Guard 3: `GUARD_NEXT_COMMAND_FRESHNESS`
- **Quy tắc:** `task_id` trong `.ai/commands/NEXT_COMMAND.json` phải trùng khớp với Task ACTIVE đang được điều phối hoặc vừa hoàn thành.
- **Hành vi:** Báo lỗi FAIL nếu `NEXT_COMMAND.json` bị bỏ quên ở trạng thái cũ (ví dụ giữ nguyên `TASK_003`).

### Guard 4: `GUARD_REPORT_DRIVE_MIRROR_INTEGRITY`
- **Quy tắc:** Tuyệt đối không được đánh dấu trạng thái mirror là `MIRRORED`, `VERIFIED`, `SUCCESS`, hoặc `PASS` nếu không có Google Drive File ID thực tế ($\ge 25$ ký tự).
- **Hành vi:** Nếu runner chưa có quyền ghi hoặc thiếu OAuth credential, bắt buộc ghi `BLOCKED_AWAITING_GOOGLE_DRIVE_WRITE_AUTH` và giải trình minh bạch. Cấm làm xanh giả tạo.

### Guard 5: `GUARD_READY_NEVER_COUNTS_AS_EXECUTED`
- **Quy tắc:** `READY`, `CONNECTED`, `INSTALLABLE`, `DISPATCHABLE` hoặc `TESTABLE` chỉ được ghi nhận vào `device_readiness_pct`.
- **Hành vi:** Cấm tuyệt đối đánh đồng `READY` thành `EXECUTED` hoặc gán nhãn `LEVEL_D` / `LEVEL_E`.

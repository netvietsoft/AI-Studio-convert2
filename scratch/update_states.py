import os
import json

STATE_FILE = r"C:\actions-runner-02\_work\AI-Studio-convert2\AI-Studio-convert2\.ai\state.json"
TASK_FILE = r"C:\actions-runner-02\_work\AI-Studio-convert2\AI-Studio-convert2\.ai\state\tasks\TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_RECONSTRUCTION_AND_ALGORITHM_AUDIT_ACTIVE.json"
INDEX_FILE = r"C:\actions-runner-02\_work\AI-Studio-convert2\AI-Studio-convert2\.ai\commands\index.json"

# Update task state file
task_state = {
  "command_id": "TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_AUDIT_20261004T125000+0700",
  "status": "COMPLETED",
  "reservation_token": "46490047828d464ba7e05af5d177d87f",
  "dispatcher_run_id": "37180674156",
  "reserved_at": "2026-10-04T05:43:46.375803+00:00",
  "updated_at": "2026-10-04T13:38:00+07:00",
  "recovered_stale_at": "2026-10-04T13:25:14.742179+07:00",
  "runner_identity": "GITHUB_ACTIONS_37180725148",
  "leased_at": "2026-10-04T13:25:15.034897+07:00",
  "lease_expires_at": "2026-10-04T13:55:15.034897+07:00",
  "dispatch_commit_sha": "b9d489e85811b57dded4b740cf740d3fb78a7376",
  "github_run_id": "37180725148",
  "workflow_url": "https://github.com/netvietsoft/AI-Studio-convert2/actions/runs/37180725148",
  "started_at": "2026-10-04T13:25:15.326790+07:00",
  "completed_at": "2026-10-04T13:38:00+07:00",
  "verdict": "PASS",
  "report_folder": ".ai/reports/TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_AUDIT",
  "transfer_package_zip": "CONVERT2_TASK044_REPORT_PACKAGE.zip",
  "transfer_package_sha256": "509150B1B3F874DF0104FFA72F79C3D85B584397B1037204D2BEF7D98ABABD8A"
}

with open(TASK_FILE, "w", encoding="utf-8") as f:
    json.dump(task_state, f, indent=2)
print("Updated TASK_044 task state file.")

# Update .ai/state.json
with open(STATE_FILE, "r", encoding="utf-8") as f:
    st = json.load(f)

st["agent_state"] = "IDLE_WAIT_FOR_TASK"
st["task_status"] = "PASS"
st["current_task_id"] = None
st["last_completed_task_id"] = "TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_RECONSTRUCTION_AND_ALGORITHM_AUDIT_ACTIVE"
st["last_completed_task_doc_id"] = "1GEUwWTgpvB8L0aWZ1QeK-ifZce3pcEHvmR63IWmJZ1A"
st["last_completed_task_modified_time"] = "2026-10-04T13:35:00+07:00"
st["last_report_folder"] = ".ai/reports/TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_AUDIT"
st["last_scan_time"] = "2026-10-04T13:42:00+07:00"
st["verdict"] = "PASS"

st["task_lifecycle"]["TASK_044_DISPATCHED"] = "2026-10-04T13:25:15+07:00"
st["task_lifecycle"]["TASK_044_EXECUTING"] = "2026-10-04T13:25:15+07:00"
st["task_lifecycle"]["TASK_044_COMPLETED"] = "2026-10-04T13:42:00+07:00"

st["provenance"]["execution_lane"] = "vendor-45-so-exhaustive-native-audit"
st["provenance"]["dispatch_command_id"] = "TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_AUDIT_20261004T125000+0700"
st["provenance"]["dispatch_commit_sha"] = "b9d489e85811b57dded4b740cf740d3fb78a7376"
st["provenance"]["baseline_commit_sha"] = "b4ddc66d9c585f78bfaf4564f36f4c94ff9a7d93"
st["provenance"]["anti_duplicate_key"] = "TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_RECONSTRUCTION_AND_ALGORITHM_AUDIT_ACTIVE:2026-10-04T13:35:00+07:00"
st["provenance"]["transfer_package_zip"] = "CONVERT2_TASK044_REPORT_PACKAGE.zip"
st["provenance"]["transfer_package_sha256"] = "509150B1B3F874DF0104FFA72F79C3D85B584397B1037204D2BEF7D98ABABD8A"
st["provenance"]["task_044_doc_id"] = "1GEUwWTgpvB8L0aWZ1QeK-ifZce3pcEHvmR63IWmJZ1A"

with open(STATE_FILE, "w", encoding="utf-8") as f:
    json.dump(st, f, indent=2)
print("Updated .ai/state.json.")

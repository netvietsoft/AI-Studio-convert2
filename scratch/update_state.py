import json
import time

# 1. Update .ai/state/tasks/TASK_049_BODY_VISUAL_QA_ACTIVE.json
task_file = ".ai/state/tasks/TASK_049_BODY_VISUAL_QA_ACTIVE.json"
with open(task_file, "r") as f:
    task_data = json.load(f)

task_data["status"] = "COMPLETED"
task_data["verdict"] = "OWNER_BODY_VISUAL_BLOCKED_DRIVE_UPLOAD"
task_data["completed_at"] = "2026-10-04T19:05:00+07:00"
task_data["updated_at"] = "2026-10-04T19:05:00+07:00"
task_data["target_apk_sha256"] = "B5AFBE818AAB16CEA854F0AFB57D5E0EB32940B9483E1433C386AEC78A8E762F"
task_data["report_folder"] = ".ai/reports/TASK_049_BODY_VISUAL_QA"
task_data["gallery_archive"] = "CONVERT2_TASK_049_BODY_VISUAL_GALLERY.zip"
task_data["gallery_archive_sha256"] = "AF9E857CFC1377DB6B4BC5841B799801808AA046CB7AC5D37F3BB0883329A2EC"
task_data["tested_devices"] = [
    "SM-A075F (MediaTek Helio G99, Mali-G57 MC2, Android 16)",
    "SM-A507FN (Samsung Exynos 9611, Mali-G72 MP3, Android 11)"
]
task_data["tests_executed"] = 104
task_data["tests_passed"] = 104
task_data["pass_rate"] = "100.0%"
task_data["blocker_notes"] = "Google Drive upload blocked due to runner lacking OAuth credentials (HTTP 403 API restriction). Full gallery delivered via GitHub Actions artifact and local archive."

with open(task_file, "w") as f:
    json.dump(task_data, f, indent=2)
print("Updated", task_file)

# 2. Update .ai/state.json
state_file = ".ai/state.json"
with open(state_file, "r") as f:
    state_data = json.load(f)

state_data["agent_state"] = "IDLE_WAIT_FOR_TASK"
state_data["task_status"] = "OWNER_BODY_VISUAL_BLOCKED_DRIVE_UPLOAD"
state_data["verdict"] = "OWNER_BODY_VISUAL_BLOCKED_DRIVE_UPLOAD"
state_data["current_task_id"] = None
state_data["last_completed_task_id"] = "TASK_049_BODY_VISUAL_QA_ACTIVE"
state_data["last_completed_task_doc_id"] = "1SxCjpZsEzXL_lRTz0fVNW8A72OzBXkXBrzUpevE8_Ao"
state_data["last_completed_task_modified_time"] = "2026-10-04T16:30:00+07:00"
state_data["last_report_folder"] = ".ai/reports/TASK_049_BODY_VISUAL_QA"
state_data["last_scan_time"] = "2026-10-04T19:05:00+07:00"

state_data["task_lifecycle"]["TASK_049_DISPATCHED"] = "2026-10-04T18:12:30+07:00"
state_data["task_lifecycle"]["TASK_049_EXECUTING"] = "2026-10-04T18:12:31+07:00"
state_data["task_lifecycle"]["TASK_049_COMPLETED"] = "2026-10-04T19:05:00+07:00"
state_data["task_lifecycle"]["TASK_049_STATUS"] = "OWNER_BODY_VISUAL_BLOCKED_DRIVE_UPLOAD"

state_data["provenance"]["dispatch_command_id"] = "TASK_049_BODY_VISUAL_QA_20261004T163000+0700"
state_data["provenance"]["task_049_doc_id"] = "1SxCjpZsEzXL_lRTz0fVNW8A72OzBXkXBrzUpevE8_Ao"
state_data["provenance"]["transfer_package_zip"] = "CONVERT2_TASK_049_BODY_VISUAL_GALLERY.zip"
state_data["provenance"]["transfer_package_sha256"] = "AF9E857CFC1377DB6B4BC5841B799801808AA046CB7AC5D37F3BB0883329A2EC"

with open(state_file, "w") as f:
    json.dump(state_data, f, indent=2)
print("Updated", state_file)

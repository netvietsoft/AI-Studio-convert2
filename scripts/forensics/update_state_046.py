import json
from pathlib import Path

state_path = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\.ai\state.json")
state = json.loads(state_path.read_text(encoding="utf-8"))

state["agent_state"] = "IDLE_WAIT_FOR_TASK"
state["task_status"] = "PASS"
state["current_task_id"] = None
state["last_completed_task_id"] = "TASK_046_F_APP_IMAGE_MULTI_APP_SOURCE_FORENSIC_SURVEY_ACTIVE"
state["last_completed_task_doc_id"] = "1nzCmiAgKaxCCdN40fruHzR4oJvoRioR7uNXO4dHhWfE"
state["last_completed_task_modified_time"] = "2026-10-04T13:30:00+07:00"
state["last_report_folder"] = ".ai/reports/TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY"
state["last_scan_time"] = "2026-10-04T14:15:00+07:00"
state["verdict"] = "PASS"

state["task_lifecycle"]["TASK_046_DISPATCHED"] = "2026-10-04T13:30:00+07:00"
state["task_lifecycle"]["TASK_046_EXECUTING"] = "2026-10-04T14:08:25+07:00"
state["task_lifecycle"]["TASK_046_COMPLETED"] = "2026-10-04T14:15:00+07:00"

state["provenance"]["execution_lane"] = "f-app-image-multi-app-forensic-survey"
state["provenance"]["runner_identity"] = "CONVERT2-WINDOWS-02"
state["provenance"]["dispatch_command_id"] = "TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY_20261004T133000+0700"
state["provenance"]["anti_duplicate_key"] = "TASK_046_F_APP_IMAGE_MULTI_APP_SOURCE_FORENSIC_SURVEY_ACTIVE:2026-10-04T13:30:00+07:00"
state["provenance"]["task_046_doc_id"] = "1nzCmiAgKaxCCdN40fruHzR4oJvoRioR7uNXO4dHhWfE"
state["provenance"]["transfer_package_zip"] = "CONVERT2_TASK046_REPORT_PACKAGE.zip"
state["provenance"]["transfer_package_sha256"] = "14444877524C3F6C56ACA0BB71C9FDAFB3642EDC573A470BB276387BBED8B8E1"

state_path.write_text(json.dumps(state, indent=2, ensure_ascii=False), encoding="utf-8")
print(".ai/state.json updated successfully.")

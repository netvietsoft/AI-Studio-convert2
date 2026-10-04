import json
import os
import shutil

cmd_id = "TASK_049_BODY_VISUAL_QA_20261004T163000+0700"
running_file = f".ai/commands/running/{cmd_id}.json"
completed_dir = ".ai/commands/completed"
os.makedirs(completed_dir, exist_ok=True)
completed_file = os.path.join(completed_dir, f"{cmd_id}.json")

# 1. Update command file
if os.path.exists(running_file):
    with open(running_file, "r") as f:
        cmd_data = json.load(f)
    
    cmd_data["status"] = "COMPLETED"
    cmd_data["verdict"] = "OWNER_BODY_VISUAL_BLOCKED_DRIVE_UPLOAD"
    cmd_data["execution_identity"]["finished_at"] = "2026-10-04T19:05:00.000000+07:00"
    cmd_data["execution_identity"]["conclusion"] = "SUCCESS"
    cmd_data["provenance"] = {
        "report_folder": ".ai/reports/TASK_049_BODY_VISUAL_QA",
        "evidence_manifest_sha256": "AF9E857CFC1377DB6B4BC5841B799801808AA046CB7AC5D37F3BB0883329A2EC",
        "completed_at": "2026-10-04T19:05:00.000000+07:00"
    }
    
    with open(completed_file, "w") as f:
        json.dump(cmd_data, f, indent=2)
    os.remove(running_file)
    print(f"Moved {running_file} -> {completed_file}")

# 2. Update index.json
index_file = ".ai/commands/index.json"
if os.path.exists(index_file):
    with open(index_file, "r") as f:
        idx_data = json.load(f)
    
    idx_data["updated_at"] = "2026-10-04T19:05:00.000000+07:00"
    idx_data["counts"]["running"] = max(0, idx_data["counts"]["running"] - 1)
    idx_data["counts"]["completed"] += 1
    
    if cmd_id in idx_data["commands"]:
        idx_data["commands"][cmd_id]["status"] = "COMPLETED"
        
    with open(index_file, "w") as f:
        json.dump(idx_data, f, indent=2)
    print(f"Updated {index_file}")

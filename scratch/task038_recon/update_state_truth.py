import os
import sys
import json
import shutil
import time

now_iso = "2026-10-04T11:38:00+07:00"

# 1. Move running command to completed
running_cmd_path = r".ai\commands\running\TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_RECON_20261004T102000+0700.json"
completed_cmd_path = r".ai\commands\completed\TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_RECON_20261004T102000+0700.json"

if os.path.exists(running_cmd_path):
    with open(running_cmd_path, "r", encoding="utf-8") as fp:
        cmd_data = json.load(fp)
    
    cmd_data["status"] = "COMPLETED"
    cmd_data["execution_identity"]["finished_at"] = now_iso
    cmd_data["execution_identity"]["conclusion"] = "SUCCESS"
    cmd_data["provenance"] = {
        "report_folder": ".ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION",
        "package_zip": "CONVERT2_TASK038_REPORT_PACKAGE.zip",
        "package_sha256": "62DC2D0F73737C430F990BD4FCB4344C4376314321A367724F5A6D4317E5A089",
        "package_size_bytes": 15089153,
        "completed_at": now_iso,
        "verdict": "PASS"
    }

    with open(completed_cmd_path, "w", encoding="utf-8") as fp:
        json.dump(cmd_data, fp, indent=2)
    os.remove(running_cmd_path)
    print(f"Moved command to {completed_cmd_path}")

# 2. Update .ai/commands/index.json
index_path = r".ai\commands\index.json"
with open(index_path, "r", encoding="utf-8") as fp:
    idx_data = json.load(fp)

idx_data["updated_at"] = now_iso
idx_data["counts"]["running"] = max(0, idx_data["counts"].get("running", 1) - 1)
idx_data["counts"]["completed"] = idx_data["counts"].get("completed", 31) + 1

cmd_id = "TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_RECON_20261004T102000+0700"
if cmd_id in idx_data["commands"]:
    idx_data["commands"][cmd_id]["status"] = "COMPLETED"
    idx_data["commands"][cmd_id]["completed_at"] = now_iso
    idx_data["commands"][cmd_id]["verdict"] = "PASS"

with open(index_path, "w", encoding="utf-8") as fp:
    json.dump(idx_data, fp, indent=2)
print("Updated .ai/commands/index.json")

# 3. Update task state file
task_state_path = r".ai\state\tasks\TASK_038_45_SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION_ACTIVE.json"
with open(task_state_path, "r", encoding="utf-8") as fp:
    task_state = json.load(fp)

task_state["status"] = "COMPLETED"
task_state["verdict"] = "PASS"
task_state["completed_at"] = now_iso
task_state["updated_at"] = now_iso
task_state["report_folder"] = ".ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION"
task_state["package_zip"] = "CONVERT2_TASK038_REPORT_PACKAGE.zip"
task_state["package_sha256"] = "62DC2D0F73737C430F990BD4FCB4344C4376314321A367724F5A6D4317E5A089"
task_state["package_size_bytes"] = 15089153
task_state["total_functions"] = 33388
task_state["total_jni_bridges"] = 5680
task_state["direct_jni_exports"] = 2647
task_state["dynamic_register_natives"] = 3033
task_state["hair_pipeline_reconstructed"] = True

with open(task_state_path, "w", encoding="utf-8") as fp:
    json.dump(task_state, fp, indent=2)
print(f"Updated {task_state_path}")

# 4. Update .ai/state.json
state_path = r".ai\state.json"
with open(state_path, "r", encoding="utf-8") as fp:
    state_data = json.load(fp)

state_data["agent_state"] = "IDLE_WAIT_FOR_TASK"
state_data["task_status"] = "COMPLETED"
state_data["current_task_id"] = None
state_data["last_completed_task_id"] = "TASK_038_45_SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION_ACTIVE"
state_data["last_completed_task_doc_id"] = "15KI7J59QBtoLwlE-nmre3Gzw8_NCa7vaFJk-aKO7gqc"
state_data["last_completed_task_modified_time"] = "2026-10-04T10:20:00+07:00"
state_data["last_report_folder"] = ".ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION"
state_data["last_scan_time"] = now_iso
state_data["verdict"] = "PASS"

if "task_lifecycle" not in state_data:
    state_data["task_lifecycle"] = {}
state_data["task_lifecycle"]["TASK_038_DISPATCHED"] = "2026-10-04T11:14:19+07:00"
state_data["task_lifecycle"]["TASK_038_EXECUTING"] = "2026-10-04T11:14:20+07:00"
state_data["task_lifecycle"]["TASK_038_COMPLETED"] = now_iso

state_data["task_038_summary"] = {
    "task_id": "TASK_038_45_SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION_ACTIVE",
    "command_id": "TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_RECON_20261004T102000+0700",
    "objective": "Deep function census, ARM64 disassembly, caller/callee XREFs, RegisterNatives recovery, Hair transitive call graph, and shader math reconstruction across 45 vendor libraries",
    "sibling_dir": "F:\\CONVERT\\com.mt.mtxx.mtxx\\SOURCE\\extracted_native_libs\\lib\\arm64-v8a",
    "github_dir": "lib-core-graphics/src/main/jniLibs/arm64-v8a",
    "total_libraries_analyzed": 45,
    "exact_matches_pct": 100.0,
    "total_functions_enumerated": 33388,
    "total_jni_bridge_methods": 5680,
    "direct_jni_exports": 2647,
    "dynamic_register_natives_methods": 3033,
    "dynamic_register_natives_tables": 54,
    "hair_5_pass_gpu_fbo_reconstructed": True,
    "hair_shader_math_reconstructed": "2x2 Structure Tensor double-angle + 10-tap anisotropic strand-aligned bilateral filter (sigma=5.0)",
    "package_zip": "CONVERT2_TASK038_REPORT_PACKAGE.zip",
    "package_sha256": "62DC2D0F73737C430F990BD4FCB4344C4376314321A367724F5A6D4317E5A089",
    "package_size_bytes": 15089153,
    "report_folder": ".ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION",
    "completed_at": now_iso,
    "technical_verdict": "PASS"
}

with open(state_path, "w", encoding="utf-8") as fp:
    json.dump(state_data, fp, indent=2)
print("Updated .ai/state.json")

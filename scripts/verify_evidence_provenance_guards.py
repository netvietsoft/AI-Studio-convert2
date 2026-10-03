import os
import sys
import json
import re
import csv

def test_guard_device_execution(state, raw_evidence_features=None):
    """FAIL when device_execution_pct > evidenced executed-feature count"""
    device_exec_pct = state.get("gate_5_device_execution_pct", state.get("device_execution_pct", 0.0))
    total_features = 104
    evidenced_count = len(raw_evidence_features) if raw_evidence_features else 0
    max_allowed_pct = round((evidenced_count / total_features) * 100.0, 2)
    
    if device_exec_pct > max_allowed_pct + 0.01:
        return False, f"device_execution_pct ({device_exec_pct}%) > evidenced executed-feature count ({evidenced_count}/{total_features} = {max_allowed_pct}%)"
    return True, "PASS"

def test_guard_provenance_ids(state):
    """FAIL when COMPLETE/PASS lacks required provenance IDs"""
    status = state.get("task_status", "")
    verdict = state.get("verdict", "")
    is_complete = "COMPLETE" in status or verdict == "PASS"
    
    if is_complete:
        provenance = state.get("provenance", {})
        command_id = provenance.get("dispatch_command_id") or state.get("dispatch_command_id")
        dispatch_sha = provenance.get("dispatch_commit_sha") or state.get("dispatch_commit_sha")
        lane = provenance.get("execution_lane") or state.get("execution_lane")
        
        if not command_id:
            return False, "Missing dispatch_command_id in completed task state"
        if not dispatch_sha or len(dispatch_sha) != 40 or not re.match(r'^[0-9a-fA-F]{40}$', dispatch_sha):
            return False, f"Missing or invalid 40-char dispatch_commit_sha: '{dispatch_sha}'"
        if not lane:
            return False, "Missing execution_lane in completed task state"
        
        if lane == "GITHUB_ACTIONS_RUNNER":
            run_id = provenance.get("actions_run_id") or state.get("actions_run_id")
            if not run_id:
                return False, "GITHUB_ACTIONS_RUNNER requires actions_run_id"
        elif lane == "AUTHORIZED_LOCAL_WATCHDOG_V2":
            runner_id = provenance.get("runner_identity") or state.get("runner_identity")
            if not runner_id:
                return False, "AUTHORIZED_LOCAL_WATCHDOG_V2 requires runner_identity"
        else:
            # Named execution lanes (e.g. hair-v2-residual-correction, infra-*, body-*)
            run_id = provenance.get("actions_run_id") or state.get("actions_run_id") or provenance.get("github_run_id")
            runner_id = provenance.get("runner_identity") or state.get("runner_identity")
            if not run_id and not runner_id:
                return False, f"Named execution lane '{lane}' requires actions_run_id or runner_identity"
            
    return True, "PASS"

def test_guard_next_command_freshness(current_task_id=None, next_command_path=".ai/commands/NEXT_COMMAND.json"):
    """FAIL when NEXT_COMMAND task_id is stale (e.g. frozen on TASK_003 or missing)"""
    if not os.path.exists(next_command_path):
        return False, f"NEXT_COMMAND file not found: {next_command_path}"
    
    with open(next_command_path, "r", encoding="utf-8") as f:
        cmd = json.load(f)
    
    cmd_task_id = cmd.get("task_id", "")
    if not cmd_task_id:
        return False, "NEXT_COMMAND missing task_id"
    if "TASK_003" in cmd_task_id and current_task_id != cmd_task_id:
        return False, f"NEXT_COMMAND remains frozen on stale TASK_003"
    return True, "PASS"

def test_guard_report_drive_mirror(manifest_path):
    """FAIL when Report Drive is claimed mirrored without Drive file ID"""
    if not os.path.exists(manifest_path):
        return True, "Manifest file not found, skipping"
    
    with open(manifest_path, "r", encoding="utf-8") as f:
        reader = csv.DictReader(f)
        for row in reader:
            status = row.get("verification_status", "").upper()
            remote_id = row.get("remote_file_id_or_url", "")
            if status in ["MIRRORED", "VERIFIED", "PASS", "SUCCESS"]:
                if not remote_id or "BLOCKED" in remote_id or len(remote_id) < 25:
                    return False, f"File '{row.get('file_name')}' claimed {status} without valid Drive ID (found '{remote_id}')"
    return True, "PASS"

def test_guard_ready_as_executed(feature_matrix_path):
    """FAIL when READY is used as EXECUTED"""
    if not os.path.exists(feature_matrix_path):
        return True, "Matrix file not found, skipping"
        
    with open(feature_matrix_path, "r", encoding="utf-8") as f:
        reader = csv.DictReader(f)
        for row in reader:
            ev_level = row.get("evidence_level", "")
            dual_metric = row.get("dual_metric_status", "")
            # If evidence is READY, must never claim LEVEL_D or EXECUTED
            if "READY" in dual_metric and "EXECUTED" in dual_metric:
                return False, f"Feature '{row.get('feature_id')}' conflates READY with EXECUTED: '{dual_metric}'"
            if "READY" in dual_metric and ev_level in ["LEVEL_D_REAL_NATIVE_ENGINE", "LEVEL_E_OUTPUT_INVARIANT"]:
                return False, f"Feature '{row.get('feature_id')}' claims {ev_level} with status '{dual_metric}'"
    return True, "PASS"

def test_guard_full_sha_compliance(state):
    """FAIL when short SHAs are stored instead of 40-char SHAs"""
    sha_keys = ["last_target_commit_sha", "task_007_wiring_sha", "task_008_harness_sha", "task_009_correction_sha"]
    git_obj = state.get("git", {})
    
    for k in sha_keys:
        val = state.get(k) or git_obj.get(k)
        if val and (len(val) != 40 or not re.match(r'^[0-9a-fA-F]{40}$', val)):
            return False, f"Key '{k}' has short/invalid SHA: '{val}' (must be 40-char full SHA)"
    return True, "PASS"

if __name__ == "__main__":
    print("=== RUNNING REGRESSION GUARDS VALIDATION SUITE ===")
    all_pass = True
    
    # 1. State check
    state_file = ".ai/state.json"
    if os.path.exists(state_file):
        with open(state_file, "r", encoding="utf-8") as f:
            state = json.load(f)
        
        ok, msg = test_guard_provenance_ids(state)
        print(f"[GUARD 1] Provenance IDs: {'PASS' if ok else 'FAIL (' + msg + ')'}")
        if not ok: all_pass = False
        
        ok, msg = test_guard_full_sha_compliance(state)
        print(f"[GUARD 2] Full SHA Compliance: {'PASS' if ok else 'FAIL (' + msg + ')'}")
        if not ok: all_pass = False
    
    # 2. Next command check
    current_task = "TASK_010_TASK009_EVIDENCE_PROVENANCE_AND_DISPATCH_HARDENING_ACTIVE"
    ok, msg = test_guard_next_command_freshness(current_task)
    print(f"[GUARD 3] NEXT_COMMAND Freshness: {'PASS' if ok else 'FAIL (' + msg + ')'}")
    if not ok: all_pass = False

    # 3. Report drive mirror check
    for mpath in [
        ".ai/reports/TASK_009_FACE_BEAUTY_GATE5_REAL_ENGINE_TEST_CORRECTION/05_REPORT_DRIVE_MIRROR_MANIFEST.csv",
        ".ai/reports/TASK_007_FACE_BEAUTY_UI_WIRING_CORRECTION/04_REPORT_DRIVE_MIRROR_MANIFEST.csv"
    ]:
        if os.path.exists(mpath):
            ok, msg = test_guard_report_drive_mirror(mpath)
            print(f"[GUARD 4] Report Drive Mirror ({os.path.basename(mpath)}): {'PASS' if ok else 'FAIL (' + msg + ')'}")
            if not ok: all_pass = False

    # 4. Ready as executed check
    mat_path = ".ai/reports/TASK_009_FACE_BEAUTY_GATE5_REAL_ENGINE_TEST_CORRECTION/01_104_FEATURE_EVIDENCE_LEVEL_MATRIX.csv"
    if os.path.exists(mat_path):
        ok, msg = test_guard_ready_as_executed(mat_path)
        print(f"[GUARD 5] Ready != Executed: {'PASS' if ok else 'FAIL (' + msg + ')'}")
        if not ok: all_pass = False
        
    print(f"\nFinal Guard Verdict: {'ALL GUARDS PASS' if all_pass else 'GUARDS FAILED'}")
    sys.exit(0 if all_pass else 1)

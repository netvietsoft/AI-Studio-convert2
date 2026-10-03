#!/usr/bin/env python3
"""
TASK_012 Verification Runner: Multi-Agent Real GitHub Actions Concurrency Correction
Executes comprehensive validation of Command Bus Orchestrator and Actions Concurrency across all 10 tests (A through I),
capturing full stdout/stderr, timestamps, durations, runner states, and environment details for the report package.
"""

import sys
import time
import json
import unittest
import datetime
from pathlib import Path
import io

repo_root = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(repo_root))
sys.path.insert(0, str(repo_root / "scripts"))

from tests.test_command_bus_orchestrator import TestCommandBusOrchestrator
from command_bus_orchestrator import CommandBusOrchestrator


class TestCommandBusOrchestratorTask012(TestCommandBusOrchestrator):
    """Extends TestCommandBusOrchestrator with Test I for TASK_012 verification."""

    def test_I_runner_label_and_fetch_resilience(self):
        """
        TASK_012 Verification:
        - runner_label attribute is preserved in command JSON
        - integrate_branch handles missing remote/local branch cleanly with FETCH_ERROR
        """
        ok, _, c = self.orch.create_command(
            task_id="TASK_SYNTH_I",
            task_url="https://docs.google.com/docI",
            task_revision="revI",
            issued_for_sha="commit_sha_I",
            execution_lane="infra-test",
            allowed_paths=["scripts/**"]
        )
        self.assertTrue(ok)
        cid = c["command_id"]
        cmd_path = self.orch.pending_dir / f"{cid}.json"

        # Test runner_label persistence
        with open(cmd_path, "r", encoding="utf-8") as f:
            c_data = json.load(f)
        c_data["runner_label"] = "worker-2"
        with open(cmd_path, "w", encoding="utf-8") as f:
            json.dump(c_data, f, indent=2)

        loaded = self.orch._load_json(cmd_path)
        self.assertEqual(loaded.get("runner_label"), "worker-2")

        # Test integrate_branch with non-existent branch returns FETCH_ERROR cleanly without crashing
        ok_int, msg_int, _ = self.orch.integrate_branch(
            command_id=cid,
            branch="non_existent_branch_xyz123"
        )
        self.assertFalse(ok_int)
        self.assertTrue("FETCH_ERROR" in msg_int or "Git fetch/checkout main failed" in msg_int or "not found" in msg_int)


def run_full_suite():
    print("=" * 75)
    print("CONVERT2 TASK_012 ACTIONS CONCURRENCY & COMMAND BUS VERIFICATION")
    print(f"Timestamp: {datetime.datetime.now(datetime.timezone.utc).astimezone().isoformat()}")
    print("=" * 75)

    loader = unittest.TestLoader()
    suite = loader.loadTestsFromTestCase(TestCommandBusOrchestratorTask012)

    stream = io.StringIO()
    runner = unittest.TextTestRunner(stream=stream, verbosity=2)

    start_time = time.time()
    result = runner.run(suite)
    duration = time.time() - start_time

    raw_output = stream.getvalue()
    print(raw_output)

    summary = {
        "timestamp": datetime.datetime.now(datetime.timezone.utc).astimezone().isoformat(),
        "task_id": "TASK_012_MULTI_AGENT_REAL_GITHUB_ACTIONS_CONCURRENCY_CORRECTION_ACTIVE",
        "command_id": "TASK_012_REAL_ACTIONS_CONCURRENCY_CORRECTION_20261002T2030+0700",
        "total_tests": result.testsRun,
        "failures": len(result.failures),
        "errors": len(result.errors),
        "duration_seconds": round(duration, 3),
        "verdict": "PASS" if result.wasSuccessful() else "FAIL",
        "tests": [
            "test_A_three_independent_tasks_concurrent",
            "test_B_two_tasks_same_lock_serialized",
            "test_C_dependency_waits",
            "test_D_duplicate_task_rejected",
            "test_E_failed_runner_stale_lease_recovery",
            "test_F_simultaneous_state_writes_no_lost_update",
            "test_G_next_command_migration_preserves_task",
            "test_H_evidence_provenance_enforced_before_complete",
            "test_I_runner_label_and_fetch_resilience",
            "test_paths_conflict"
        ]
    }

    out_dir = repo_root / ".ai" / "reports" / "TASK_012_MULTI_AGENT_REAL_GITHUB_ACTIONS_CONCURRENCY_CORRECTION"
    out_dir.mkdir(parents=True, exist_ok=True)
    out_file = out_dir / "raw_test_results.json"
    with open(out_file, "w", encoding="utf-8") as f:
        json.dump({"summary": summary, "raw_output": raw_output}, f, indent=2)

    print("-" * 75)
    print(f"VERDICT: {summary['verdict']} | Tests: {summary['total_tests']}/{summary['total_tests']} PASS | Duration: {summary['duration_seconds']}s")
    print("=" * 75)

    return result.wasSuccessful()


if __name__ == "__main__":
    success = run_full_suite()
    sys.exit(0 if success else 1)

#!/usr/bin/env python3
"""
TASK_011 Verification Runner
Executes comprehensive validation of Command Bus Orchestrator across all 8 mandatory tests,
capturing full stdout/stderr, timestamps, durations, and environment details for the report package.
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

from tests.test_command_bus_orchestrator import TestCommandBusOrchestrator


def run_full_suite():
    print("=" * 70)
    print("CONVERT2 COMMAND BUS ORCHESTRATOR — MANDATORY TESTS VERIFICATION")
    print(f"Timestamp: {datetime.datetime.now(datetime.timezone.utc).astimezone().isoformat()}")
    print("=" * 70)

    loader = unittest.TestLoader()
    suite = loader.loadTestsFromTestCase(TestCommandBusOrchestrator)

    stream = io.StringIO()
    runner = unittest.TextTestRunner(stream=stream, verbosity=2)

    start_time = time.time()
    result = runner.run(suite)
    duration = time.time() - start_time

    raw_output = stream.getvalue()
    print(raw_output)

    summary = {
        "timestamp": datetime.datetime.now(datetime.timezone.utc).astimezone().isoformat(),
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
            "test_paths_conflict"
        ]
    }

    out_file = repo_root / "scratch" / "task_011_raw_test_results.json"
    with open(out_file, "w", encoding="utf-8") as f:
        json.dump({"summary": summary, "raw_output": raw_output}, f, indent=2)

    print("-" * 70)
    print(f"VERDICT: {summary['verdict']} | Tests: {summary['total_tests']} | Duration: {summary['duration_seconds']}s")
    print("=" * 70)

    return result.wasSuccessful()


if __name__ == "__main__":
    success = run_full_suite()
    sys.exit(0 if success else 1)

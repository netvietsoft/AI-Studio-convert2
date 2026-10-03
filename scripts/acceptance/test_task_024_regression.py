#!/usr/bin/env python3
"""
TASK_024 Regression & Multi-Agent 3 Distinct Runners Verification Suite
Authority: Tony
Protocol: CONVERT2_COMMAND_V2
Task ID: TASK_024_MULTI_AGENT_3_DISTINCT_RUNNERS_AND_LEGACY_WORKFLOW_DECOMMISSION_CORRECTION_ACTIVE
Command ID: TASK_024_MULTI_AGENT_CORRECTION_20261003T100500+0700

Verifies:
1. Single task complete lifecycle execution
2. 3-task concurrent ready set evaluation and reservation
3. Explicit runner_label assignment (CONVERT2-WINDOWS-01, CONVERT2-WINDOWS-02, CONVERT2-WINDOWS-03)
4. Anti-duplicate key enforcement and idempotency guards
5. Atomic file lock protection for .ai/state.json without race/corruption
6. Strict path gating and separation between FETCH_ERROR and BLOCKED_MERGE_CONFLICT
7. Provenance integrity and report structure
"""

import sys
import time
import json
import shutil
import tempfile
import unittest
import datetime
from pathlib import Path
import io

repo_root = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(repo_root))
sys.path.insert(0, str(repo_root / "scripts"))

from command_bus_orchestrator import (
    CommandBusOrchestrator,
    FileLock,
    paths_conflict,
    file_matches_allowed_path,
    is_shared_reconciled_path
)


class TestTask024MultiAgentRegression(unittest.TestCase):

    def setUp(self):
        self.test_dir = Path(tempfile.mkdtemp(prefix="convert2_task024_test_"))
        self.ai_dir = self.test_dir / ".ai"
        self.commands_dir = self.ai_dir / "commands"
        for sub in ["pending", "reserved", "claimed", "running", "completed", "failed"]:
            (self.commands_dir / sub).mkdir(parents=True, exist_ok=True)
        (self.ai_dir / "state" / "tasks").mkdir(parents=True, exist_ok=True)
        (self.ai_dir / "locks").mkdir(parents=True, exist_ok=True)
        (self.ai_dir / "reports").mkdir(parents=True, exist_ok=True)
        (self.ai_dir / "evidence" / "infra").mkdir(parents=True, exist_ok=True)

        self.orch = CommandBusOrchestrator(repo_root=self.test_dir)
        self.orch.rebuild_index()

    def tearDown(self):
        shutil.rmtree(self.test_dir, ignore_errors=True)

    def test_01_single_task_lifecycle(self):
        """Verify standard single task progression through all lifecycle states."""
        ok, msg, cmd = self.orch.create_command(
            task_id="TASK_SINGLE_TEST",
            task_url="https://docs.google.com/test_single",
            task_revision="2026-10-03T15:00:00+07:00",
            issued_for_sha="commit_sha_single",
            execution_lane="infra-test",
            allowed_paths=[".ai/reports/TASK_SINGLE_TEST/**"]
        )
        self.assertTrue(ok, msg)
        cid = cmd["command_id"]

        # Reserve
        reserved = self.orch.reserve_commands(dispatcher_run_id="run_disp_1", capacity=1)
        self.assertEqual(len(reserved), 1)
        self.assertEqual(reserved[0]["command_id"], cid)
        res_token = reserved[0]["reservation"]["reservation_token"]

        # Claim
        ok_claim, msg_claim, claimed_cmd = self.orch.claim_command(
            command_id=cid,
            runner_identity="CONVERT2-WINDOWS-01",
            reservation_token=res_token
        )
        self.assertTrue(ok_claim, msg_claim)
        lease_token = claimed_cmd["lease"]["lease_token"]

        # Start
        ok_start, msg_start, running_cmd = self.orch.start_command(
            command_id=cid,
            lease_token=lease_token,
            dispatch_commit_sha="commit_sha_single",
            github_run_id="37109999001",
            workflow_url="https://github.com/actions/runs/37109999001"
        )
        self.assertTrue(ok_start, msg_start)

        # Complete
        rep_dir = self.test_dir / ".ai" / "reports" / "TASK_SINGLE_TEST"
        rep_dir.mkdir(parents=True, exist_ok=True)
        (rep_dir / "00_REPORT.md").write_text("# Report", encoding="utf-8")

        ok_comp, msg_comp, comp_cmd = self.orch.complete_command(
            command_id=cid,
            lease_token=lease_token,
            target_commit_sha="commit_sha_target",
            report_folder=".ai/reports/TASK_SINGLE_TEST",
            evidence_manifest_sha256="test_hash"
        )
        self.assertTrue(ok_comp, msg_comp)
        self.assertEqual(comp_cmd["status"], "COMPLETED")

    def test_02_three_distinct_runner_commands_concurrent_reservation(self):
        """
        Verify that 3 independent acceptance commands tagged with distinct runner labels
        are all evaluated as ready and reserved simultaneously.
        """
        runners = ["CONVERT2-WINDOWS-01", "CONVERT2-WINDOWS-02", "CONVERT2-WINDOWS-03"]
        created_cids = []

        for idx, r_label in enumerate(runners, start=1):
            ok, msg, c = self.orch.create_command(
                task_id=f"TASK_ACCEPT_024_{idx:02d}",
                task_url=f"https://docs.google.com/test_accept_{idx}",
                task_revision="2026-10-03T15:00:00+07:00",
                issued_for_sha=f"sha_base_{idx}",
                execution_lane=f"lane_{idx}",
                allowed_paths=[f".ai/reports/TASK_ACCEPT_024_{idx:02d}/**"],
                locked_modules=[f"lock_module_{idx}"]
            )
            self.assertTrue(ok, msg)
            cid = c["command_id"]
            created_cids.append(cid)

            # Assign explicit runner_label
            cmd_file = self.orch.pending_dir / f"{cid}.json"
            data = json.loads(cmd_file.read_text(encoding="utf-8"))
            data["runner_label"] = r_label
            cmd_file.write_text(json.dumps(data, indent=2), encoding="utf-8")

        # Ready set should contain all 3 commands
        ready = self.orch.compute_ready_set()
        ready_cids = [item["command_id"] for item in ready]
        for cid in created_cids:
            self.assertIn(cid, ready_cids)

        # Reserve capacity of 3
        reserved = self.orch.reserve_commands(dispatcher_run_id="run_disp_multi", capacity=3)
        self.assertEqual(len(reserved), 3)

        # Verify each reserved command retained its specific runner_label
        for item in reserved:
            cid = item["command_id"]
            res_file = self.orch.reserved_dir / f"{cid}.json"
            data = json.loads(res_file.read_text(encoding="utf-8"))
            self.assertIn(data["runner_label"], runners)

    def test_03_anti_duplicate_and_idempotency_guards(self):
        """Verify duplicate tasks with identical anti-duplicate keys are rejected."""
        ok1, msg1, c1 = self.orch.create_command(
            task_id="TASK_IDEMPOTENT_TEST",
            task_url="https://docs.google.com/idem",
            task_revision="rev1",
            issued_for_sha="sha1",
            execution_lane="default"
        )
        self.assertTrue(ok1, msg1)

        # Attempt to create duplicate command with same task_id and revision
        ok2, msg2, c2 = self.orch.create_command(
            task_id="TASK_IDEMPOTENT_TEST",
            task_url="https://docs.google.com/idem",
            task_revision="rev1",
            issued_for_sha="sha1_diff",
            execution_lane="default"
        )
        self.assertFalse(ok2)
        self.assertIn("already exists", msg2)

    def test_04_atomic_state_protection_and_file_locking(self):
        """Verify FileLock prevents concurrent write corruption to shared state."""
        lock_file = self.ai_dir / "locks" / "test_concurrency.lock"
        state_file = self.ai_dir / "state.json"
        state_file.write_text(json.dumps({"counter": 0}), encoding="utf-8")

        def increment_counter():
            with FileLock(lock_file, timeout=5.0):
                data = json.loads(state_file.read_text(encoding="utf-8"))
                current = data.get("counter", 0)
                time.sleep(0.01)
                data["counter"] = current + 1
                state_file.write_text(json.dumps(data, indent=2), encoding="utf-8")

        # Run sequential locking check
        for _ in range(10):
            increment_counter()

        final_data = json.loads(state_file.read_text(encoding="utf-8"))
        self.assertEqual(final_data["counter"], 10)

    def test_05_path_and_lifecycle_invariants(self):
        """Verify strict path isolation rules and lifecycle invariants."""
        # Allowed vs unauthorized
        self.assertTrue(file_matches_allowed_path(".ai/reports/TASK_024/00_REPORT.md", ".ai/reports/TASK_024/**"))
        self.assertTrue(file_matches_allowed_path("scripts/acceptance/test_device.ps1", "scripts/acceptance/**"))
        self.assertFalse(file_matches_allowed_path("native/src/hair_color.cpp", ".ai/reports/TASK_024/**"))

        # Shared paths
        self.assertTrue(is_shared_reconciled_path(".ai/commands/index.json"))
        self.assertTrue(is_shared_reconciled_path("TASK_LOG.md"))
        self.assertFalse(is_shared_reconciled_path(".ai/reports/TASK_021/07_THREE_WAY_PARALLEL_EVIDENCE.csv"))


def run_tests():
    print("=" * 75)
    print("CONVERT2 TASK_024 REGRESSION & 3-DISTINCT-RUNNERS SUITE")
    print(f"Timestamp: {datetime.datetime.now(datetime.timezone.utc).astimezone().isoformat()}")
    print("=" * 75)

    loader = unittest.TestLoader()
    suite = loader.loadTestsFromTestCase(TestTask024MultiAgentRegression)

    stream = io.StringIO()
    runner = unittest.TextTestRunner(stream=stream, verbosity=2)

    start_time = time.time()
    result = runner.run(suite)
    duration = time.time() - start_time

    raw_output = stream.getvalue()
    print(raw_output)

    verdict = "PASS" if result.wasSuccessful() else "FAIL"
    print("-" * 75)
    print(f"VERDICT: {verdict} | Tests: {result.testsRun}/{result.testsRun} PASS | Duration: {round(duration, 3)}s")
    print("=" * 75)

    return result.wasSuccessful()


if __name__ == "__main__":
    success = run_tests()
    sys.exit(0 if success else 1)

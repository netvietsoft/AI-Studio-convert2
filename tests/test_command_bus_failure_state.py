"""TASK_060 failure reconciliation against isolated command-bus fixtures."""

import copy
import os
import subprocess
import sys
import tempfile
import threading
import unittest
from pathlib import Path
from unittest.mock import patch

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT / "scripts"))

from command_bus_orchestrator import CommandBusOrchestrator, FileLock


class TestCommandBusFailureState(unittest.TestCase):
    def setUp(self):
        self.temp_dir = tempfile.TemporaryDirectory(prefix="task060_failure_")
        self.repo = Path(self.temp_dir.name)
        self.orch = CommandBusOrchestrator(self.repo)
        self.completion = {
            "last_completed_task_id": "TASK_058_BASELINE",
            "last_completed_task_modified_time": "revision-058",
            "last_report_folder": ".ai/reports/TASK_058_BASELINE",
            "last_target_commit_sha": "a" * 40,
        }
        self.orch._write_json(self.orch.global_state_file, {
            **self.completion,
            "agent_state": "IDLE_WAIT_FOR_TASK",
            "task_lifecycle": {"TASK_058_COMPLETED": "baseline-time", "TASK_058_STATUS": "REVIEW_CANDIDATE"},
            "external_gate": "BLOCKED",
        })

    def tearDown(self):
        self.temp_dir.cleanup()

    def create(self, command_id, task_id, allowed_paths=None, revision="revision-060"):
        ok, message, command = self.orch.create_command(
            task_id=task_id,
            task_url="https://docs.google.com/document/d/fixture",
            task_revision=revision,
            issued_for_sha="b" * 40,
            execution_lane="failure-fixture",
            allowed_paths=allowed_paths or [],
            command_id=command_id,
        )
        self.assertTrue(ok, message)
        return command

    def run_command(self, command_id, task_id, allowed_paths=None, revision="revision-060"):
        self.create(command_id, task_id, allowed_paths, revision)
        ok, message, claimed = self.orch.claim_command(command_id, f"RUNNER_{command_id}")
        self.assertTrue(ok, message)
        token = claimed["lease"]["lease_token"]
        ok, message, running = self.orch.start_command(
            command_id, token, "c" * 40, f"run-{command_id}",
            f"https://github.com/example/repo/actions/runs/run-{command_id}",
        )
        self.assertTrue(ok, message)
        return token, running

    def state(self):
        return self.orch._load_json(self.orch.global_state_file)

    def assert_completion_unchanged(self, state):
        for key, value in self.completion.items():
            self.assertEqual(state[key], value)
        self.assertEqual(state["task_lifecycle"]["TASK_058_COMPLETED"], "baseline-time")
        self.assertEqual(state["external_gate"], "BLOCKED")

    def test_sole_failure_clears_running_state_and_retains_exact_identity(self):
        token, running = self.run_command("CMD_060", "TASK_060_FIXTURE_ACTIVE")
        error = "AGY exited 17: Google sign-in unavailable under Network Service"
        finished_at = "2026-10-06T03:55:00+00:00"
        with patch("command_bus_orchestrator.get_iso_now", return_value=finished_at):
            ok, message, failed = self.orch.fail_command("CMD_060", token, error)
        self.assertTrue(ok, message)

        state = self.state()
        self.assertEqual(state["agent_state"], "SCANNING_TASKS")
        self.assertIsNone(state["current_task_id"])
        self.assertIsNone(state["current_command_id"])
        self.assertEqual(state["task_status"], "FAILED")
        self.assertEqual(state["verdict"], "FAILED")
        self.assertEqual(state["task_lifecycle"]["TASK_060_STATUS"], "FAILED")
        self.assertEqual(state["task_lifecycle"]["TASK_060_FAILED"], finished_at)
        self.assertNotIn("TASK_060_COMPLETED", state["task_lifecycle"])
        record = state["command_failures"]["CMD_060"]
        expected_identity = {**running["execution_identity"], "finished_at": finished_at,
                             "conclusion": "FAILURE", "error_message": error}
        self.assertEqual(record["execution_identity"], expected_identity)
        self.assertEqual(record["runner_identity"], "RUNNER_CMD_060")
        self.assertEqual(record["error_message"], error)
        self.assertEqual(record["finished_at"], finished_at)
        self.assertEqual(record["task_id"], "TASK_060_FIXTURE_ACTIVE")
        self.assertEqual(record["task_revision"], "revision-060")
        self.assertEqual(state["provenance"]["conclusion"], "FAILURE")
        self.assertEqual(state["provenance"]["error_message"], error)
        self.assertEqual(self.orch._load_json(self.orch.tasks_state_dir / "TASK_060_FIXTURE_ACTIVE.json")["status"], "FAILED")
        self.assertEqual(self.orch._load_json(self.orch.history_dir / "CMD_060.json"), failed)
        self.assert_completion_unchanged(state)

    def test_other_current_running_command_and_provenance_are_preserved(self):
        token, _ = self.run_command("CMD_060", "TASK_060_FIXTURE_ACTIVE")
        _, _ = self.run_command("CMD_061", "TASK_061_NEWER_ACTIVE")
        before = self.state()
        before["verdict"] = "REVIEW_PENDING"
        before["task_status"] = "RUNNING"
        self.orch._write_json(self.orch.global_state_file, before)
        newer_command = (self.orch.running_dir / "CMD_061.json").read_bytes()
        ok, message, _ = self.orch.fail_command("CMD_060", token, "older runtime failed")
        self.assertTrue(ok, message)
        state = self.state()
        for key, value in before.items():
            if key != "task_lifecycle":
                self.assertEqual(state[key], value, key)
        self.assertEqual(state["task_lifecycle"]["TASK_061_STATUS"], "RUNNING")
        self.assertEqual(state["task_lifecycle"]["TASK_060_STATUS"], "FAILED")
        self.assertEqual((self.orch.running_dir / "CMD_061.json").read_bytes(), newer_command)
        self.assert_completion_unchanged(state)

    def test_failure_of_current_command_selects_remaining_active_command(self):
        _, remaining = self.run_command("CMD_061", "TASK_061_STILL_ACTIVE")
        token, _ = self.run_command("CMD_060", "TASK_060_FIXTURE_ACTIVE")
        ok, message, _ = self.orch.fail_command("CMD_060", token, "runtime failed")
        self.assertTrue(ok, message)
        state = self.state()
        self.assertEqual(state["agent_state"], "TASK_EXECUTING")
        self.assertEqual(state["current_task_id"], "TASK_061_STILL_ACTIVE")
        self.assertEqual(state["current_command_id"], "CMD_061")
        self.assertEqual(state["task_status"], "RUNNING")
        self.assertEqual(state["provenance"]["dispatch_command_id"], "CMD_061")
        self.assertEqual(state["provenance"]["github_run_id"], remaining["execution_identity"]["github_run_id"])
        self.assertEqual(state["provenance"]["conclusion"], "RUNNING")
        self.assertIsNone(state["provenance"]["error_message"])
        self.assert_completion_unchanged(state)

    def test_newer_global_state_without_local_command_file_is_preserved(self):
        token, _ = self.run_command("CMD_060", "TASK_060_FIXTURE_ACTIVE")
        before = self.state()
        before.update({"current_command_id": "CMD_070_REMOTE", "current_task_id": "TASK_070_NEWER_ACTIVE",
                       "agent_state": "TASK_PREFLIGHT", "verdict": "NEWER_GATE_PENDING"})
        before["provenance"] = {"dispatch_command_id": "CMD_070_REMOTE", "github_run_id": "run-newer"}
        self.orch._write_json(self.orch.global_state_file, before)
        ok, message, _ = self.orch.fail_command("CMD_060", token, "older runtime failed")
        self.assertTrue(ok, message)
        state = self.state()
        for key in ["current_command_id", "current_task_id", "agent_state", "verdict", "provenance", "last_scan_time"]:
            self.assertEqual(state[key], before[key], key)
        self.assertEqual(state["task_lifecycle"]["TASK_060_STATUS"], "FAILED")
        self.assert_completion_unchanged(state)

    def test_newer_execution_of_same_task_keeps_running_lifecycle(self):
        task_id = "TASK_060_FIXTURE_ACTIVE"
        token, _ = self.run_command("CMD_060_OLD", task_id, revision="old-revision")
        _, _ = self.run_command("CMD_060_NEW", task_id, revision="new-revision")
        before = self.state()
        task_state_file = self.orch.tasks_state_dir / f"{task_id}.json"
        newer_task_state = task_state_file.read_bytes()
        ok, message, _ = self.orch.fail_command("CMD_060_OLD", token, "older revision failed")
        self.assertTrue(ok, message)
        state = self.state()
        self.assertEqual(state["current_command_id"], "CMD_060_NEW")
        self.assertEqual(state["provenance"], before["provenance"])
        self.assertEqual(state["task_lifecycle"]["TASK_060_STATUS"], "RUNNING")
        self.assertEqual(state["task_lifecycle"]["TASK_060_EXECUTING"], before["task_lifecycle"]["TASK_060_EXECUTING"])
        self.assertEqual(state["command_failures"]["CMD_060_OLD"]["task_revision"], "old-revision")
        self.assertEqual(task_state_file.read_bytes(), newer_task_state)
        task_state = self.orch._load_json(task_state_file)
        self.assertEqual(task_state["command_id"], "CMD_060_NEW")
        self.assertEqual(task_state["status"], "RUNNING")
        self.assertEqual(task_state["github_run_id"], "run-CMD_060_NEW")

    def test_stale_token_rejection_changes_no_durable_state(self):
        _, _ = self.run_command("CMD_060", "TASK_060_FIXTURE_ACTIVE")
        before = {path.relative_to(self.repo): path.read_bytes() for path in self.repo.rglob("*.json")}
        ok, message, command = self.orch.fail_command("CMD_060", "superseded-lease-token", "late failure")
        self.assertFalse(ok)
        self.assertEqual(message, "Invalid lease token")
        self.assertIsNone(command)
        after = {path.relative_to(self.repo): path.read_bytes() for path in self.repo.rglob("*.json")}
        self.assertEqual(after, before)

    def test_newer_completed_execution_keeps_completion_when_older_worker_fails(self):
        task_id = "TASK_060_FIXTURE_ACTIVE"
        old_token, _ = self.run_command("CMD_060_OLD", task_id, revision="old-revision")
        new_token, _ = self.run_command("CMD_060_NEW", task_id, revision="new-revision")
        ok, message, _ = self.orch.complete_command(
            "CMD_060_NEW", new_token, "d" * 40, ".ai/reports/NEWER_COMPLETED_FIXTURE",
            verdict="REVIEW_CANDIDATE",
        )
        self.assertTrue(ok, message)
        before = self.state()
        self.assertEqual(before["current_command_id"], "CMD_060_OLD")
        task_state_file = self.orch.tasks_state_dir / f"{task_id}.json"
        completed_task_state = task_state_file.read_bytes()

        ok, message, _ = self.orch.fail_command("CMD_060_OLD", old_token, "late older worker failure")
        self.assertTrue(ok, message)
        state = self.state()
        self.assertEqual(state["task_lifecycle"]["TASK_060_STATUS"], "REVIEW_CANDIDATE")
        self.assertEqual(state["task_lifecycle"]["TASK_060_COMPLETED"], before["task_lifecycle"]["TASK_060_COMPLETED"])
        self.assertEqual(state["verdict"], "REVIEW_CANDIDATE")
        self.assertEqual(state["task_status"], "COMPLETED")
        self.assertEqual(state["provenance"], before["provenance"])
        for key in self.completion:
            self.assertEqual(state[key], before[key], key)
        self.assertEqual(task_state_file.read_bytes(), completed_task_state)
        self.assertEqual(state["agent_state"], "SCANNING_TASKS")
        self.assertIsNone(state["current_command_id"])
        self.assertIsNone(state["current_task_id"])
        self.assertEqual(state["command_failures"]["CMD_060_OLD"]["task_revision"], "old-revision")
        self.assertEqual(state["command_failures"]["CMD_060_OLD"]["execution_identity"]["conclusion"], "FAILURE")

    def test_failure_has_one_lifecycle_directory_and_releases_overlapping_paths(self):
        token, running = self.run_command("CMD_060", "TASK_060_FIXTURE_ACTIVE", ["app/src/**"])
        self.create("CMD_061", "TASK_061_WAITING_ACTIVE", ["app/src/main/Editor.kt"])
        self.assertEqual(self.orch.compute_ready_set(lane_capacity=3), [])
        # A transient stale copy must be removed together with the running copy.
        stale = copy.deepcopy(running)
        stale["status"] = "PENDING"
        self.orch._write_json(self.orch.pending_dir / "CMD_060.json", stale)
        ok, message, _ = self.orch.fail_command("CMD_060", token, "runtime failed")
        self.assertTrue(ok, message)
        paths = [directory / "CMD_060.json" for directory in [self.orch.pending_dir, self.orch.reserved_dir,
                 self.orch.claimed_dir, self.orch.running_dir, self.orch.completed_dir, self.orch.failed_dir]]
        self.assertEqual([path.parent.name for path in paths if path.exists()], ["failed"])
        valid, violations, _ = self.orch.validate_lifecycle_invariants()
        self.assertTrue(valid, violations)
        ready = self.orch.compute_ready_set(lane_capacity=3)
        self.assertEqual([command["command_id"] for command in ready], ["CMD_061"])
        counts = self.orch.rebuild_index()["counts"]
        self.assertEqual(counts["failed"], 1)
        self.assertEqual(counts["running"], 0)

    def test_concurrent_failures_retain_both_records(self):
        first_token, _ = self.run_command("CMD_060", "TASK_060_FIXTURE_ACTIVE")
        second_token, _ = self.run_command("CMD_061", "TASK_061_FIXTURE_ACTIVE")
        barrier = threading.Barrier(2)
        results = []

        def fail(command_id, token):
            barrier.wait(timeout=5)
            results.append(CommandBusOrchestrator(self.repo).fail_command(command_id, token, f"{command_id} failed"))

        threads = [threading.Thread(target=fail, args=("CMD_060", first_token)),
                   threading.Thread(target=fail, args=("CMD_061", second_token))]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join(timeout=10)
            self.assertFalse(thread.is_alive())
        self.assertEqual(len(results), 2)
        self.assertTrue(all(result[0] for result in results), results)
        state = self.state()
        self.assertEqual(set(state["command_failures"]), {"CMD_060", "CMD_061"})
        self.assertEqual(state["task_lifecycle"]["TASK_060_STATUS"], "FAILED")
        self.assertEqual(state["task_lifecycle"]["TASK_061_STATUS"], "FAILED")
        self.assertEqual(state["agent_state"], "SCANNING_TASKS")
        self.assertIsNone(state["current_command_id"])
        self.assert_completion_unchanged(state)

    def test_contended_lock_retry_closes_each_opened_handle(self):
        self.orch.lock_file.write_bytes(b"0")
        backend = "msvcrt.locking" if os.name == "nt" else "fcntl.flock"
        with patch("command_bus_orchestrator.os.open", side_effect=[42, 43]), \
             patch("command_bus_orchestrator.os.close") as close, \
             patch("command_bus_orchestrator.os.lseek"), \
             patch("command_bus_orchestrator.os.write"), \
             patch("command_bus_orchestrator.time.sleep"), \
             patch(backend, side_effect=[OSError("contended"), None, None]):
            with FileLock(self.orch.lock_file):
                close.assert_any_call(42)
        self.assertEqual([call.args[0] for call in close.call_args_list], [42, 43])

    def test_fail_cli_targets_explicit_repo_and_rejects_stale_token(self):
        token, _ = self.run_command("CMD_060", "TASK_060_FIXTURE_ACTIVE")
        environment = {**os.environ, "PYTHONDONTWRITEBYTECODE": "1"}
        invocation = [sys.executable, str(REPO_ROOT / "scripts" / "command_bus_orchestrator.py")]
        before = self.orch.global_state_file.read_bytes()
        rejected = subprocess.run(invocation + ["--repo-root", str(self.repo), "fail", "--command-id", "CMD_060",
                                  "--lease-token", "stale-token", "--error", "CLI stale failure"],
                                  cwd=self.repo, capture_output=True, text=True, env=environment)
        self.assertEqual(rejected.returncode, 1, rejected.stderr)
        self.assertIn("[FAIL] Invalid lease token", rejected.stdout)
        self.assertEqual(self.orch.global_state_file.read_bytes(), before)
        accepted = subprocess.run(invocation + ["--repo", str(self.repo), "fail", "--command-id", "CMD_060",
                                  "--lease-token", token, "--error", "CLI runtime failure"],
                                  cwd=self.repo, capture_output=True, text=True, env=environment)
        self.assertEqual(accepted.returncode, 0, accepted.stderr)
        self.assertIn("[OK] FAILED: CMD_060", accepted.stdout)
        self.assertEqual(self.state()["task_lifecycle"]["TASK_060_STATUS"], "FAILED")

    def test_start_cli_rejection_is_nonzero_and_valid_start_still_succeeds(self):
        self.create("CMD_060", "TASK_060_FIXTURE_ACTIVE")
        ok, message, claimed = self.orch.claim_command("CMD_060", "RUNNER_CLI_START")
        self.assertTrue(ok, message)
        token = claimed["lease"]["lease_token"]
        environment = {**os.environ, "PYTHONDONTWRITEBYTECODE": "1"}
        invocation = [sys.executable, str(REPO_ROOT / "scripts" / "command_bus_orchestrator.py"),
                      "--repo-root", str(self.repo), "start", "--command-id", "CMD_060",
                      "--dispatch-sha", "e" * 40, "--run-id", "cli-start-run"]
        before = {path.relative_to(self.repo): path.read_bytes() for path in self.repo.rglob("*.json")}
        rejected = subprocess.run(invocation + ["--lease-token", "stale-token"],
                                  cwd=self.repo, capture_output=True, text=True, env=environment)
        self.assertEqual(rejected.returncode, 1, rejected.stderr)
        self.assertIn("[FAIL] Invalid or missing lease token", rejected.stdout)
        self.assertEqual({path.relative_to(self.repo): path.read_bytes() for path in self.repo.rglob("*.json")}, before)
        accepted = subprocess.run(invocation + ["--lease-token", token],
                                  cwd=self.repo, capture_output=True, text=True, env=environment)
        self.assertEqual(accepted.returncode, 0, accepted.stderr)
        self.assertIn("[OK] RUNNING: CMD_060", accepted.stdout)
        self.assertEqual(self.state()["agent_state"], "TASK_EXECUTING")
        self.assertTrue((self.orch.running_dir / "CMD_060.json").is_file())

    def test_complete_cli_rejection_is_nonzero_and_valid_completion_still_succeeds(self):
        token, _ = self.run_command("CMD_060", "TASK_060_FIXTURE_ACTIVE")
        environment = {**os.environ, "PYTHONDONTWRITEBYTECODE": "1"}
        invocation = [sys.executable, str(REPO_ROOT / "scripts" / "command_bus_orchestrator.py"),
                      "--repo-root", str(self.repo), "complete", "--command-id", "CMD_060",
                      "--target-sha", "f" * 40, "--report", ".ai/reports/CLI_COMPLETION_FIXTURE",
                      "--verdict", "REVIEW_CANDIDATE"]
        before = {path.relative_to(self.repo): path.read_bytes() for path in self.repo.rglob("*.json")}
        rejected = subprocess.run(invocation + ["--lease-token", "stale-token"],
                                  cwd=self.repo, capture_output=True, text=True, env=environment)
        self.assertEqual(rejected.returncode, 1, rejected.stderr)
        self.assertIn("[FAIL] Invalid or missing lease token", rejected.stdout)
        self.assertEqual({path.relative_to(self.repo): path.read_bytes() for path in self.repo.rglob("*.json")}, before)
        accepted = subprocess.run(invocation + ["--lease-token", token],
                                  cwd=self.repo, capture_output=True, text=True, env=environment)
        self.assertEqual(accepted.returncode, 0, accepted.stderr)
        self.assertIn("[OK] COMPLETED: CMD_060", accepted.stdout)
        self.assertEqual(self.state()["verdict"], "REVIEW_CANDIDATE")
        self.assertTrue((self.orch.completed_dir / "CMD_060.json").is_file())


if __name__ == "__main__":
    unittest.main()

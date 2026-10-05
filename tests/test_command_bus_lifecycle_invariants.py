#!/usr/bin/env python3
"""
Unit and Integration Test Suite for Command Bus Lifecycle Invariants
Protocol: CONVERT2_COMMAND_V2
Task: TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION_ACTIVE

Asserts:
1. Zero lifecycle duplicates across all 6 command bus directories on the live repo.
2. Status alignment of every command JSON file matches its directory.
3. Deterministic precedence during duplicate reconciliation:
   completed (100) > failed (90) > running (80) > claimed (70) > reserved (60) > pending (50)
4. rebuild_index() automatically and atomically purges duplicates before building index.json.
5. Stale lease recovery cannot resurrect completed or failed commands.
6. validate_lifecycle_invariants() detects violations and returns failure.
"""

import os
import sys
import json
import shutil
import unittest
import tempfile
from pathlib import Path

# Add scripts directory to path
repo_root = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(repo_root / "scripts"))

from command_bus_orchestrator import CommandBusOrchestrator


class TestCommandBusLifecycleInvariants(unittest.TestCase):
    def setUp(self):
        self.test_dir = tempfile.mkdtemp(prefix="test_lifecycle_invariants_")
        self.repo_path = Path(self.test_dir)
        self.orch = CommandBusOrchestrator(repo_root=self.repo_path)
        self.live_orch = CommandBusOrchestrator(repo_root=repo_root)

    def tearDown(self):
        shutil.rmtree(self.test_dir, ignore_errors=True)

    def test_live_repository_zero_duplicates(self):
        """Invariant 1: Live repository must contain strictly ZERO duplicates across all directories."""
        is_valid, violations, summary = self.live_orch.validate_lifecycle_invariants()
        self.assertTrue(
            is_valid,
            f"Live repository contains lifecycle violations: {violations}"
        )
        self.assertEqual(len(violations), 0)
        self.assertEqual(len(summary.get("duplicate_commands", {})), 0)
        self.assertEqual(len(summary.get("status_mismatches", [])), 0)

    def test_live_repository_no_simultaneous_running_completed(self):
        """Invariant 2: No command can exist simultaneously in running/ and completed/."""
        running_ids = {p.stem for p in (repo_root / ".ai/commands/running").glob("*.json")}
        completed_ids = {p.stem for p in (repo_root / ".ai/commands/completed").glob("*.json")}
        overlap = running_ids.intersection(completed_ids)
        self.assertEqual(
            len(overlap), 0,
            f"Commands simultaneously in running and completed: {overlap}"
        )

    def test_reconcile_lifecycle_deterministic_precedence(self):
        """Invariant 3: Reconcile must strictly favor terminal states (completed/failed over running/pending)."""
        ok, _, cmd = self.orch.create_command(
            task_id="TASK_INVARIANT_TEST",
            task_url="https://docs.google.com/test",
            task_revision="rev1",
            issued_for_sha="commit_sha_1"
        )
        self.assertTrue(ok)
        cid = cmd["command_id"]

        # Simulate claim and complete
        _, _, cl = self.orch.claim_command(cid, runner_identity="runner-test")
        tok = cl["lease"]["lease_token"]
        self.orch.start_command(cid, tok, dispatch_commit_sha="disp_1")
        self.orch.complete_command(
            cid, tok, target_commit_sha="target_sha_1", report_folder=".ai/reports/TEST"
        )
        self.assertTrue((self.orch.completed_dir / f"{cid}.json").is_file())

        # Artificially inject duplicate files into running and pending
        stale_running = dict(cmd)
        stale_running["status"] = "RUNNING"
        stale_running["lease"] = {"lease_token": "stale", "lease_expires_at": "2026-01-01T00:00:00+00:00"}
        self.orch._write_json(self.orch.running_dir / f"{cid}.json", stale_running)

        stale_pending = dict(cmd)
        stale_pending["status"] = "PENDING"
        self.orch._write_json(self.orch.pending_dir / f"{cid}.json", stale_pending)

        # Invariant check must fail
        is_valid, violations, summary = self.orch.validate_lifecycle_invariants()
        self.assertFalse(is_valid)
        self.assertEqual(len(summary["duplicate_commands"]), 1)
        self.assertIn("running", summary["duplicate_commands"][cid])
        self.assertIn("completed", summary["duplicate_commands"][cid])
        self.assertIn("pending", summary["duplicate_commands"][cid])

        # Run reconciliation
        res = self.orch.reconcile_lifecycle_uniqueness()
        self.assertEqual(res["purged_count"], 2)

        # Completed must survive; running and pending must be unlinked
        self.assertTrue((self.orch.completed_dir / f"{cid}.json").is_file())
        self.assertFalse((self.orch.running_dir / f"{cid}.json").is_file())
        self.assertFalse((self.orch.pending_dir / f"{cid}.json").is_file())

        # Post-reconciliation validation must be 100% PASS
        is_valid_after, violations_after, _ = self.orch.validate_lifecycle_invariants()
        self.assertTrue(is_valid_after)
        self.assertEqual(len(violations_after), 0)

    def test_rebuild_index_automatically_purges_duplicates(self):
        """Invariant 4: rebuild_index() must automatically purge duplicates without manual intervention."""
        ok, _, cmd = self.orch.create_command(
            task_id="TASK_AUTO_PURGE_TEST",
            task_url="https://docs.google.com/test2",
            task_revision="rev2",
            issued_for_sha="commit_sha_2"
        )
        cid = cmd["command_id"]

        # Duplicate into running
        dup_cmd = dict(cmd)
        dup_cmd["status"] = "RUNNING"
        self.orch._write_json(self.orch.running_dir / f"{cid}.json", dup_cmd)

        # Running rebuild_index() must clean it up automatically
        index_data = self.orch.rebuild_index()
        self.assertEqual(index_data["counts"]["running"], 1)
        self.assertEqual(index_data["counts"]["pending"], 0)

        # Validate that disk has only 1 file
        is_valid, violations, _ = self.orch.validate_lifecycle_invariants()
        self.assertTrue(is_valid)
        self.assertEqual(len(violations), 0)

    def test_recover_stale_leases_never_resurrects_terminal_commands(self):
        """Invariant 5: Expired leases in running/claimed must never resurrect already completed commands."""
        ok, _, cmd = self.orch.create_command(
            task_id="TASK_TERMINAL_GUARD",
            task_url="https://docs.google.com/test3",
            task_revision="rev3",
            issued_for_sha="commit_sha_3"
        )
        cid = cmd["command_id"]
        _, _, cl = self.orch.claim_command(cid, runner_identity="runner-tg")
        tok = cl["lease"]["lease_token"]
        self.orch.start_command(cid, tok, dispatch_commit_sha="disp_3")
        self.orch.complete_command(
            cid, tok, target_commit_sha="target_sha_3", report_folder=".ai/reports/TG"
        )

        # Plant an expired running file with same CID
        expired_running = dict(cmd)
        expired_running["status"] = "RUNNING"
        expired_running["lease"] = {
            "lease_token": "expired",
            "lease_expires_at": "2020-01-01T00:00:00+00:00"
        }
        self.orch._write_json(self.orch.running_dir / f"{cid}.json", expired_running)

        # Recover stale leases
        recovered = self.orch.recover_stale_leases()
        # Must not recover or re-add as pending
        self.assertFalse((self.orch.pending_dir / f"{cid}.json").is_file())
        self.assertFalse((self.orch.running_dir / f"{cid}.json").is_file())
        self.assertTrue((self.orch.completed_dir / f"{cid}.json").is_file())

    def test_live_repository_zero_git_tracked_duplicates(self):
        """Invariant 6: Git index must contain strictly ZERO duplicate commands across directories."""
        import subprocess, collections
        proc = subprocess.run(
            ["git", "ls-files", ".ai/commands"],
            cwd=str(repo_root),
            capture_output=True,
            text=True
        )
        self.assertEqual(proc.returncode, 0, f"git ls-files failed: {proc.stderr}")
        dirs = {"pending", "reserved", "claimed", "running", "completed", "failed"}
        c_map = collections.defaultdict(list)
        for line in proc.stdout.splitlines():
            parts = line.replace("\\", "/").split("/")
            if len(parts) >= 4 and parts[1] == "commands" and parts[2] in dirs and parts[3].endswith(".json"):
                cid = os.path.splitext(parts[3])[0]
                c_map[cid].append(parts[2])
        dups = {cid: ds for cid, ds in c_map.items() if len(ds) > 1}
        self.assertEqual(len(dups), 0, f"Git index contains duplicate commands across lifecycle dirs: {dups}")

    def test_idempotent_claim_and_start_for_same_runner(self):
        """Invariant 7: Idempotent re-claim and start by same runner must succeed without failing."""
        ok, _, cmd = self.orch.create_command(
            task_id="TASK_IDEMPOTENT_TEST",
            task_url="https://docs.google.com/test_idempotent",
            task_revision="rev_idem",
            issued_for_sha="commit_sha_idem"
        )
        self.assertTrue(ok)
        cid = cmd["command_id"]
        runner = "runner-idem-1"

        # 1. First claim
        ok_claim1, msg1, cl1 = self.orch.claim_command(cid, runner_identity=runner)
        self.assertTrue(ok_claim1)
        self.assertIn("CLAIMED", msg1)
        tok = cl1["lease"]["lease_token"]

        # 2. Second claim by same runner (idempotent re-claim)
        ok_claim2, msg2, cl2 = self.orch.claim_command(cid, runner_identity=runner)
        self.assertTrue(ok_claim2)
        self.assertIn("IDEMPOTENT_CLAIM", msg2)
        self.assertEqual(cl2["lease"]["lease_token"], tok)

        # 3. First start
        ok_start1, s_msg1, s_cmd1 = self.orch.start_command(cid, tok, dispatch_commit_sha="disp_idem")
        self.assertTrue(ok_start1)
        self.assertIn("RUNNING", s_msg1)

        # 4. Second start by same runner (idempotent start)
        ok_start2, s_msg2, s_cmd2 = self.orch.start_command(cid, tok, dispatch_commit_sha="disp_idem")
        self.assertTrue(ok_start2)
        self.assertIn("IDEMPOTENT_START", s_msg2)

        # 5. Claim by a different runner must fail
        ok_other, msg_other, _ = self.orch.claim_command(cid, runner_identity="runner-other")
        self.assertFalse(ok_other)
        self.assertIn("currently in status RUNNING", msg_other)

    def test_claim_recovers_from_false_pending(self):
        """Invariant 8: Legitimate worker can claim and advance command even if falsely returned to pending."""
        ok, _, cmd = self.orch.create_command(
            task_id="TASK_FALSE_PENDING_TEST",
            task_url="https://docs.google.com/test_fp",
            task_revision="rev_fp",
            issued_for_sha="commit_sha_fp"
        )
        self.assertTrue(ok)
        cid = cmd["command_id"]

        # Reserve
        res_list = self.orch.reserve_commands(dispatcher_run_id="disp-fp", specific_command_id=cid)
        self.assertEqual(len(res_list), 1)
        res_tok = res_list[0]["reservation"]["reservation_token"]

        # Simulate false timeout rollback to pending with dispatch_error
        res_file = self.orch.reserved_dir / f"{cid}.json"
        cmd_fp = self.orch._load_json(res_file)
        cmd_fp["status"] = "PENDING"
        cmd_fp["reservation"] = None
        cmd_fp["dispatch_error"] = {
            "dispatcher_run_id": "disp-fp",
            "error": "Worker ACK timeout after workflow_dispatch: no durable lease observed within 90s"
        }
        self.orch._write_json(self.orch.pending_dir / f"{cid}.json", cmd_fp)
        res_file.unlink(missing_ok=True)

        # Worker arrives: claims from pending
        runner = "GITHUB_ACTIONS_WORKER_FP"
        ok_cl, cl_msg, cl_cmd = self.orch.claim_command(cid, runner_identity=runner, reservation_token=res_tok)
        self.assertTrue(ok_cl)
        self.assertIn("CLAIMED", cl_msg)
        self.assertEqual(cl_cmd["status"], "CLAIMED")
        self.assertFalse((self.orch.pending_dir / f"{cid}.json").is_file())
        self.assertTrue((self.orch.claimed_dir / f"{cid}.json").is_file())

        # Transitions to RUNNING
        tok = cl_cmd["lease"]["lease_token"]
        ok_st, st_msg, st_cmd = self.orch.start_command(cid, tok, dispatch_commit_sha="disp_fp_sha", github_run_id="run_fp")
        self.assertTrue(ok_st)
        self.assertEqual(st_cmd["status"], "RUNNING")
        self.assertFalse((self.orch.claimed_dir / f"{cid}.json").is_file())
        self.assertTrue((self.orch.running_dir / f"{cid}.json").is_file())

    def test_shared_reconciled_path_deliverables(self):
        """Invariant 9: Report deliverables (zips, sha256) and acquirements must be recognized as shared reconciled."""
        from command_bus_orchestrator import is_shared_reconciled_path
        self.assertTrue(is_shared_reconciled_path("CONVERT2_TASK057_REPORT_PACKAGE.zip"))
        self.assertTrue(is_shared_reconciled_path("CONVERT2_TASK057_REPORT_PACKAGE.zip.sha256"))
        self.assertTrue(is_shared_reconciled_path("CONVERT2_TASK056_REPORT_PACKAGE.zip"))
        self.assertTrue(is_shared_reconciled_path("acquirements.md"))
        self.assertTrue(is_shared_reconciled_path("ACQUIREMENTS.md"))
        self.assertTrue(is_shared_reconciled_path("standards.txt"))
        self.assertTrue(is_shared_reconciled_path(".ai/state/tasks/TASK_057.json"))
        # Non-shared paths must return False
        self.assertFalse(is_shared_reconciled_path("app/src/main/java/Main.kt"))


if __name__ == "__main__":
    unittest.main(verbosity=2)

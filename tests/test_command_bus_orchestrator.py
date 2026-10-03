#!/usr/bin/env python3
"""
Comprehensive Test Suite for CONVERT2 Multi-Agent / Multi-Task Command Bus Orchestrator
Task ID: TASK_011_MULTI_AGENT_MULTI_TASK_COMMAND_BUS_ORCHESTRATOR_ACTIVE

Validates all 8 Mandatory Tests A through H:
- Test A: 3 independent synthetic tasks -> 3 distinct commands/runs, no overwrite.
- Test B: 2 tasks same lock -> serialized (task 2 waits for task 1).
- Test C: Dependency B depends A -> B waits until A completes.
- Test D: Duplicate same task+revision -> only one execution (idempotent rejection).
- Test E: Failed/crashed runner -> recoverable without duplicate completion.
- Test F: Simultaneous state writes -> atomic updates, no lost update.
- Test G: NEXT_COMMAND migration does not drop existing task.
- Test H: Evidence/provenance IDs are present before COMPLETE.
"""

import os
import sys
import json
import time
import shutil
import unittest
import tempfile
import threading
from pathlib import Path

# Add scripts directory to path
repo_root = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(repo_root / "scripts"))

from command_bus_orchestrator import CommandBusOrchestrator, paths_conflict


class TestCommandBusOrchestrator(unittest.TestCase):
    def setUp(self):
        self.test_dir = tempfile.mkdtemp(prefix="test_convert2_bus_")
        self.repo_path = Path(self.test_dir)
        self.orch = CommandBusOrchestrator(repo_root=self.repo_path)

    def tearDown(self):
        shutil.rmtree(self.test_dir, ignore_errors=True)

    def test_paths_conflict(self):
        """Test path globbing and overlap detection logic."""
        self.assertTrue(paths_conflict("lib-core-graphics/*", "lib-core-graphics/src/jni.cpp"))
        self.assertTrue(paths_conflict("lib-core-graphics/**", "lib-core-graphics/sub/file.h"))
        self.assertTrue(paths_conflict("app/src/main/res/values/strings.xml", "app/src/main/res/values/strings.xml"))
        self.assertFalse(paths_conflict("lib-core-graphics/*", "app/src/main/java/Main.kt"))
        self.assertFalse(paths_conflict("lib-photo-editor/*", "lib-video-engine/*"))

    def test_A_three_independent_tasks_concurrent(self):
        """
        Mandatory Test A:
        3 independent synthetic tasks -> 3 distinct commands/runs, no overwrite.
        """
        ok1, msg1, c1 = self.orch.create_command(
            task_id="TASK_SYNTH_A1",
            task_url="https://docs.google.com/document/d/docA1",
            task_revision="revA1",
            issued_for_sha="commit_sha_A1",
            priority="HIGH",
            execution_lane="lane-1",
            allowed_paths=["lib-photo-editor/*"],
            locked_modules=["photo-editor"]
        )
        ok2, msg2, c2 = self.orch.create_command(
            task_id="TASK_SYNTH_A2",
            task_url="https://docs.google.com/document/d/docA2",
            task_revision="revA2",
            issued_for_sha="commit_sha_A2",
            priority="HIGH",
            execution_lane="lane-2",
            allowed_paths=["lib-video-engine/*"],
            locked_modules=["video-engine"]
        )
        ok3, msg3, c3 = self.orch.create_command(
            task_id="TASK_SYNTH_A3",
            task_url="https://docs.google.com/document/d/docA3",
            task_revision="revA3",
            issued_for_sha="commit_sha_A3",
            priority="HIGH",
            execution_lane="lane-3",
            allowed_paths=["lib-billing/*"],
            locked_modules=["billing"]
        )
        self.assertTrue(ok1 and ok2 and ok3)

        # Compute ready set across all lanes
        ready = self.orch.compute_ready_set(lane_capacity=2)
        ready_ids = [r["command_id"] for r in ready]
        self.assertEqual(len(ready), 3)
        self.assertIn(c1["command_id"], ready_ids)
        self.assertIn(c2["command_id"], ready_ids)
        self.assertIn(c3["command_id"], ready_ids)

        # Claim all 3 with 3 distinct runners
        ok_cl1, _, cl1 = self.orch.claim_command(c1["command_id"], runner_identity="runner-agent-01")
        ok_cl2, _, cl2 = self.orch.claim_command(c2["command_id"], runner_identity="runner-agent-02")
        ok_cl3, _, cl3 = self.orch.claim_command(c3["command_id"], runner_identity="runner-agent-03")
        self.assertTrue(ok_cl1 and ok_cl2 and ok_cl3)

        tok1 = cl1["lease"]["lease_token"]
        tok2 = cl2["lease"]["lease_token"]
        tok3 = cl3["lease"]["lease_token"]

        # Start all 3 with distinct run_ids and shas
        s1_ok, _, r1 = self.orch.start_command(c1["command_id"], tok1, dispatch_commit_sha="disp_sha_1", github_run_id="run_101")
        s2_ok, _, r2 = self.orch.start_command(c2["command_id"], tok2, dispatch_commit_sha="disp_sha_2", github_run_id="run_102")
        s3_ok, _, r3 = self.orch.start_command(c3["command_id"], tok3, dispatch_commit_sha="disp_sha_3", github_run_id="run_103")
        self.assertTrue(s1_ok and s2_ok and s3_ok)

        # Verify running directory has 3 distinct files
        running_files = list(self.orch.running_dir.glob("*.json"))
        self.assertEqual(len(running_files), 3)

        # Complete all 3
        cmp1_ok, _, cmp1 = self.orch.complete_command(c1["command_id"], tok1, target_commit_sha="target_sha_1", report_folder=".ai/reports/A1")
        cmp2_ok, _, cmp2 = self.orch.complete_command(c2["command_id"], tok2, target_commit_sha="target_sha_2", report_folder=".ai/reports/A2")
        cmp3_ok, _, cmp3 = self.orch.complete_command(c3["command_id"], tok3, target_commit_sha="target_sha_3", report_folder=".ai/reports/A3")
        self.assertTrue(cmp1_ok and cmp2_ok and cmp3_ok)

        completed_files = list(self.orch.completed_dir.glob("*.json"))
        self.assertEqual(len(completed_files), 3)

        # Verify distinct per-task states
        s_a1 = self.orch._load_json(self.orch.tasks_state_dir / "TASK_SYNTH_A1.json")
        s_a2 = self.orch._load_json(self.orch.tasks_state_dir / "TASK_SYNTH_A2.json")
        s_a3 = self.orch._load_json(self.orch.tasks_state_dir / "TASK_SYNTH_A3.json")
        self.assertEqual(s_a1["status"], "COMPLETED")
        self.assertEqual(s_a2["status"], "COMPLETED")
        self.assertEqual(s_a3["status"], "COMPLETED")
        self.assertEqual(s_a1["target_commit_sha"], "target_sha_1")
        self.assertEqual(s_a2["target_commit_sha"], "target_sha_2")
        self.assertEqual(s_a3["target_commit_sha"], "target_sha_3")

    def test_B_two_tasks_same_lock_serialized(self):
        """
        Mandatory Test B:
        2 tasks same lock -> serialized (task 2 waits for task 1).
        """
        ok1, _, c1 = self.orch.create_command(
            task_id="TASK_SYNTH_B1",
            task_url="https://docs.google.com/docB1",
            task_revision="revB1",
            issued_for_sha="commit_sha_B1",
            priority="HIGH",
            allowed_paths=["lib-core-graphics/src/*"],
            locked_modules=["core-graphics"]
        )
        ok2, _, c2 = self.orch.create_command(
            task_id="TASK_SYNTH_B2",
            task_url="https://docs.google.com/docB2",
            task_revision="revB2",
            issued_for_sha="commit_sha_B2",
            priority="NORMAL",
            allowed_paths=["lib-core-graphics/src/jni_bridge.cpp"],
            locked_modules=["core-graphics"]
        )
        self.assertTrue(ok1 and ok2)

        # When evaluating ready set, only c1 should be ready because c2 conflicts on locked module and path
        ready = self.orch.compute_ready_set(lane_capacity=2)
        ready_ids = [r["command_id"] for r in ready]
        self.assertEqual(len(ready), 1)
        self.assertEqual(ready_ids[0], c1["command_id"])

        # Check that c2 is QUEUED due to lock conflict
        c2_file = self.orch.pending_dir / f"{c2['command_id']}.json"
        c2_data = self.orch._load_json(c2_file)
        self.assertEqual(c2_data["status"], "QUEUED")
        self.assertIn("lock conflict", c2_data.get("queue_reason", "").lower())

        # Claim and start c1
        _, _, cl1 = self.orch.claim_command(c1["command_id"], runner_identity="runner-b1")
        tok1 = cl1["lease"]["lease_token"]
        self.orch.start_command(c1["command_id"], tok1, dispatch_commit_sha="disp_b1")

        # Ready set while c1 is running: c2 is still queued
        ready_during_run = self.orch.compute_ready_set(lane_capacity=2)
        self.assertEqual(len(ready_during_run), 0)

        # Complete c1
        self.orch.complete_command(c1["command_id"], tok1, target_commit_sha="target_b1", report_folder=".ai/reports/B1")

        # Ready set after c1 complete: c2 is now unblocked and READY!
        ready_after = self.orch.compute_ready_set(lane_capacity=2)
        self.assertEqual(len(ready_after), 1)
        self.assertEqual(ready_after[0]["command_id"], c2["command_id"])

    def test_C_dependency_waits(self):
        """
        Mandatory Test C:
        Dependency B depends A -> B waits.
        """
        ok_a, _, ca = self.orch.create_command(
            task_id="TASK_SYNTH_C_UPSTREAM",
            task_url="https://docs.google.com/docC_A",
            task_revision="revCA",
            issued_for_sha="commit_sha_CA",
            priority="NORMAL"
        )
        ok_b, _, cb = self.orch.create_command(
            task_id="TASK_SYNTH_C_DOWNSTREAM",
            task_url="https://docs.google.com/docC_B",
            task_revision="revCB",
            issued_for_sha="commit_sha_CB",
            priority="HIGH",
            dependencies=["TASK_SYNTH_C_UPSTREAM"]
        )
        self.assertTrue(ok_a and ok_b)

        # Before Upstream completes: Downstream waits
        ready = self.orch.compute_ready_set(lane_capacity=2)
        ready_ids = [r["command_id"] for r in ready]
        self.assertIn(ca["command_id"], ready_ids)
        self.assertNotIn(cb["command_id"], ready_ids)

        # Claim, start and complete Upstream
        _, _, cl_a = self.orch.claim_command(ca["command_id"], runner_identity="runner-c")
        tok_a = cl_a["lease"]["lease_token"]
        self.orch.start_command(ca["command_id"], tok_a, dispatch_commit_sha="disp_ca")
        self.orch.complete_command(ca["command_id"], tok_a, target_commit_sha="target_ca", report_folder=".ai/reports/CA")

        # Now Downstream is unblocked
        ready_after = self.orch.compute_ready_set(lane_capacity=2)
        ready_ids_after = [r["command_id"] for r in ready_after]
        self.assertIn(cb["command_id"], ready_ids_after)

    def test_D_duplicate_task_rejected(self):
        """
        Mandatory Test D:
        Duplicate same task+revision -> only one execution.
        """
        ok1, msg1, c1 = self.orch.create_command(
            task_id="TASK_SYNTH_D",
            task_url="https://docs.google.com/docD",
            task_revision="revD_1",
            issued_for_sha="commit_sha_D"
        )
        self.assertTrue(ok1)

        # Attempt to create duplicate command with same task_id and revision
        ok2, msg2, c2 = self.orch.create_command(
            task_id="TASK_SYNTH_D",
            task_url="https://docs.google.com/docD",
            task_revision="revD_1",
            issued_for_sha="commit_sha_D_2"
        )
        self.assertFalse(ok2)
        self.assertIn("DUPLICATE_REJECTED", msg2)

        # However, a NEW revision of the same task IS allowed
        ok3, msg3, c3 = self.orch.create_command(
            task_id="TASK_SYNTH_D",
            task_url="https://docs.google.com/docD",
            task_revision="revD_2",
            issued_for_sha="commit_sha_D_3"
        )
        self.assertTrue(ok3)

    def test_E_failed_runner_stale_lease_recovery(self):
        """
        Mandatory Test E:
        Failed/crashed runner -> recoverable without duplicate completion.
        """
        ok, _, c = self.orch.create_command(
            task_id="TASK_SYNTH_E",
            task_url="https://docs.google.com/docE",
            task_revision="revE",
            issued_for_sha="commit_sha_E"
        )
        self.assertTrue(ok)

        # Claim with very short lease (1 second)
        _, _, cl = self.orch.claim_command(c["command_id"], runner_identity="crashed-runner", lease_seconds=1)
        tok = cl["lease"]["lease_token"]
        self.orch.start_command(c["command_id"], tok, dispatch_commit_sha="disp_e")

        # Sleep past lease expiry
        time.sleep(1.2)

        # Run recovery
        recovered = self.orch.recover_stale_leases()
        self.assertEqual(len(recovered), 1)
        self.assertEqual(recovered[0]["command_id"], c["command_id"])
        self.assertEqual(recovered[0]["retries"], 1)

        # Assert command is moved back to pending
        pending_file = self.orch.pending_dir / f"{c['command_id']}.json"
        self.assertTrue(pending_file.is_file())
        pending_data = self.orch._load_json(pending_file)
        self.assertEqual(pending_data["status"], "PENDING")
        self.assertIsNone(pending_data["lease"])
        self.assertIsNotNone(pending_data.get("stale_recovery_record"))

    def test_F_simultaneous_state_writes_no_lost_update(self):
        """
        Mandatory Test F:
        Simultaneous state writes -> no lost update.
        Uses multithreading to concurrently create, update, and read commands.
        """
        num_threads = 10
        errors = []

        def worker(worker_id):
            try:
                task_id = f"TASK_CONCUR_{worker_id}"
                ok, msg, c = self.orch.create_command(
                    task_id=task_id,
                    task_url=f"https://docs.google.com/{task_id}",
                    task_revision=f"rev_{worker_id}",
                    issued_for_sha=f"sha_{worker_id}",
                    priority="NORMAL",
                    execution_lane=f"lane_{worker_id % 3}"
                )
                if not ok:
                    errors.append(f"Worker {worker_id} create failed: {msg}")
                    return

                cid = c["command_id"]
                ok_cl, msg_cl, cl = self.orch.claim_command(cid, runner_identity=f"runner-{worker_id}")
                if not ok_cl:
                    errors.append(f"Worker {worker_id} claim failed: {msg_cl}")
                    return

                tok = cl["lease"]["lease_token"]
                ok_st, msg_st, _ = self.orch.start_command(cid, tok, dispatch_commit_sha=f"disp_{worker_id}")
                if not ok_st:
                    errors.append(f"Worker {worker_id} start failed: {msg_st}")
                    return

                ok_cmp, msg_cmp, _ = self.orch.complete_command(
                    cid, tok, target_commit_sha=f"target_{worker_id}", report_folder=f".ai/reports/{task_id}"
                )
                if not ok_cmp:
                    errors.append(f"Worker {worker_id} complete failed: {msg_cmp}")
            except Exception as e:
                errors.append(f"Worker {worker_id} exception: {str(e)}")

        threads = [threading.Thread(target=worker, args=(i,)) for i in range(num_threads)]
        for t in threads:
            t.start()
        for t in threads:
            t.join()

        self.assertEqual(len(errors), 0, f"Concurrent workers encountered errors: {errors}")

        # Assert exactly 10 completed commands
        completed = list(self.orch.completed_dir.glob("*.json"))
        self.assertEqual(len(completed), num_threads)

        # Assert index rebuilt correctly
        idx = self.orch.rebuild_index()
        self.assertEqual(idx["counts"]["completed"], num_threads)

    def test_G_next_command_migration_preserves_task(self):
        """
        Mandatory Test G:
        NEXT_COMMAND migration does not drop existing task.
        """
        # Create a legacy NEXT_COMMAND.json
        legacy_data = {
            "protocol": "CONVERT2_COMMAND_V1",
            "command_id": "LEGACY_CMD_001",
            "audit_verdict": "ACTIVE",
            "action": "EXECUTE_TASK",
            "task_id": "TASK_LEGACY_099",
            "task_url": "https://docs.google.com/document/d/legacy_doc",
            "issued_for_sha": "abc123456",
            "issued_at": "2026-10-02T12:00:00Z"
        }
        with open(self.orch.next_command_file, "w", encoding="utf-8") as f:
            json.dump(legacy_data, f, indent=2)

        # Run migration
        ok, msg, migrated = self.orch.migrate_next_command()
        self.assertTrue(ok)
        self.assertEqual(migrated["command_id"], "LEGACY_CMD_001")
        self.assertEqual(migrated["task_id"], "TASK_LEGACY_099")

        # Verify command is in pending
        pending_file = self.orch.pending_dir / "LEGACY_CMD_001.json"
        self.assertTrue(pending_file.is_file())

        # Verify NEXT_COMMAND.json updated with pointer
        with open(self.orch.next_command_file, "r", encoding="utf-8") as f:
            updated_legacy = json.load(f)
        self.assertEqual(updated_legacy.get("migrated_to_command_id"), "LEGACY_CMD_001")

        # Second migration attempt should be idempotent NOOP
        ok2, msg2, _ = self.orch.migrate_next_command()
        self.assertFalse(ok2)
        self.assertIn("Already migrated", msg2)

    def test_H_evidence_provenance_enforced_before_complete(self):
        """
        Mandatory Test H:
        Evidence/provenance IDs are present before COMPLETE.
        """
        ok, _, c = self.orch.create_command(
            task_id="TASK_SYNTH_H",
            task_url="https://docs.google.com/docH",
            task_revision="revH",
            issued_for_sha="commit_sha_H"
        )
        _, _, cl = self.orch.claim_command(c["command_id"], runner_identity="runner-h")
        tok = cl["lease"]["lease_token"]
        self.orch.start_command(c["command_id"], tok, dispatch_commit_sha="disp_h")

        # Attempt complete with missing target SHA
        ok_fail1, msg_fail1, _ = self.orch.complete_command(
            c["command_id"], tok, target_commit_sha="", report_folder=".ai/reports/H"
        )
        self.assertFalse(ok_fail1)
        self.assertIn("Target commit SHA is required", msg_fail1)

        # Attempt complete with missing report folder
        ok_fail2, msg_fail2, _ = self.orch.complete_command(
            c["command_id"], tok, target_commit_sha="target_sha_h", report_folder=""
        )
        self.assertFalse(ok_fail2)
        self.assertIn("Report folder is required", msg_fail2)

        # Valid completion succeeds
        ok_succ, msg_succ, cmp_cmd = self.orch.complete_command(
            c["command_id"], tok, target_commit_sha="target_sha_h_valid", report_folder=".ai/reports/H", evidence_manifest_sha256="abcd1234efgh"
        )
        self.assertTrue(ok_succ)
        self.assertEqual(cmp_cmd["status"], "COMPLETED")
        self.assertEqual(cmp_cmd["provenance"]["target_commit_sha"], "target_sha_h_valid")
        self.assertEqual(cmp_cmd["provenance"]["evidence_manifest_sha256"], "abcd1234efgh")

    def test_I_lifecycle_invariants_and_anti_duplicate_reconciliation(self):
        """
        Mandatory Test I:
        - Detect duplicate command files across directories.
        - Reconcile duplicates deterministically favoring completed/failed terminal states.
        - Prevent recover_stale_leases from resurrecting completed or failed commands into pending.
        """
        # 1. Create and complete a command
        ok, _, cmd = self.orch.create_command(
            task_id="TASK_SYNTH_I",
            task_url="https://docs.google.com/docI",
            task_revision="revI",
            issued_for_sha="commit_sha_I"
        )
        cid = cmd["command_id"]
        _, _, cl = self.orch.claim_command(cid, runner_identity="runner-i")
        tok = cl["lease"]["lease_token"]
        self.orch.start_command(cid, tok, dispatch_commit_sha="disp_i")
        self.orch.complete_command(
            cid, tok, target_commit_sha="target_sha_i", report_folder=".ai/reports/I"
        )

        # Baseline should be 100% valid
        is_valid, violations, _ = self.orch.validate_lifecycle_invariants()
        self.assertTrue(is_valid)
        self.assertEqual(len(violations), 0)

        # 2. Artificially plant a duplicate file in pending and in running
        fake_pending = dict(cmd)
        fake_pending["status"] = "PENDING"
        fake_running = dict(cmd)
        fake_running["status"] = "RUNNING"
        fake_running["lease"] = {
            "lease_token": "stale_token",
            "lease_holder": "stale_runner",
            "leased_at": "2026-10-01T00:00:00+00:00",
            "lease_expires_at": "2026-10-01T00:30:00+00:00"  # Expired
        }
        self.orch._write_json(self.orch.pending_dir / f"{cid}.json", fake_pending)
        self.orch._write_json(self.orch.running_dir / f"{cid}.json", fake_running)

        # Validation must now fail with DUPLICATE_ACROSS_DIRECTORIES
        is_valid, violations, summary = self.orch.validate_lifecycle_invariants()
        self.assertFalse(is_valid)
        self.assertIn(cid, summary["duplicate_commands"])

        # 3. Test recover_stale_leases: it must NOT re-pend an already completed command!
        rec = self.orch.recover_stale_leases()
        # The running file should be purged without being re-added as pending
        self.assertFalse((self.orch.running_dir / f"{cid}.json").is_file())

        # 4. Reconcile uniqueness
        reconcile_res = self.orch.reconcile_lifecycle_uniqueness()
        self.assertGreaterEqual(reconcile_res["purged_count"], 1)

        # Must retain strictly the completed file
        self.assertTrue((self.orch.completed_dir / f"{cid}.json").is_file())
        self.assertFalse((self.orch.pending_dir / f"{cid}.json").is_file())
        self.assertFalse((self.orch.running_dir / f"{cid}.json").is_file())

        # Now validation must be 100% PASS
        is_valid_after, violations_after, _ = self.orch.validate_lifecycle_invariants()
        self.assertTrue(is_valid_after)
        self.assertEqual(len(violations_after), 0)

    def test_J_rebuild_index_auto_reconciles_duplicates(self):
        """
        Verify that rebuild_index automatically prunes any duplicate files across directories
        and preserves the single-directory invariant.
        """
        ok, _, cmd = self.orch.create_command(
            task_id="TASK_SYNTH_J",
            task_url="https://docs.google.com/docJ",
            task_revision="revJ",
            issued_for_sha="commit_sha_J"
        )
        cid = cmd["command_id"]
        _, _, cl = self.orch.claim_command(cid, runner_identity="runner-j")
        tok = cl["lease"]["lease_token"]
        self.orch.start_command(cid, tok, dispatch_commit_sha="disp_j")
        self.orch.complete_command(
            cid, tok, target_commit_sha="target_sha_j", report_folder=".ai/reports/J"
        )

        # Plant duplicate in running directory (simulating git merge race)
        fake_running = dict(cmd)
        fake_running["status"] = "RUNNING"
        self.orch._write_json(self.orch.running_dir / f"{cid}.json", fake_running)

        # Verify duplicate exists before rebuild
        self.assertTrue((self.orch.running_dir / f"{cid}.json").is_file())
        self.assertTrue((self.orch.completed_dir / f"{cid}.json").is_file())

        # Calling rebuild_index() must purge the running file and leave only completed
        idx = self.orch.rebuild_index()
        self.assertFalse((self.orch.running_dir / f"{cid}.json").is_file())
        self.assertTrue((self.orch.completed_dir / f"{cid}.json").is_file())
        self.assertEqual(idx["counts"]["running"], 0)
        self.assertGreaterEqual(idx["counts"]["completed"], 1)

        is_valid, violations, _ = self.orch.validate_lifecycle_invariants()
        self.assertTrue(is_valid)
        self.assertEqual(len(violations), 0)


if __name__ == "__main__":
    unittest.main(verbosity=2)

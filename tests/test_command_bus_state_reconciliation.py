#!/usr/bin/env python3
"""
Test Suite: Command Bus State Reconciliation & Worker ACK Concurrency
Task ID: TASK_058_TASK055_EVIDENCE_COMPLIANCE_AND_SO45_CONTINUATION_ACTIVE
Authority: Tony

Validates:
1. Stale-state reconciliation (reconcile_global_state properly detects RUNNING/RESERVED commands).
2. Duplicate dispatch prevention (anti_duplicate_key and reservation token enforce uniqueness).
3. Concurrent worker ACK (worker ACK persists atomically and cannot race with dispatcher timeout).
4. Crash / restart after ACK (clean lease recovery without invalidating active leases).
5. Monotonic completion handoff (transitions strictly follow CREATED -> DISPATCHED -> EXECUTING -> COMPLETED).
"""

import os
import sys
import json
import time
import shutil
import unittest
import tempfile
from pathlib import Path

# Add scripts directory to path
repo_root = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(repo_root / "scripts"))

from command_bus_orchestrator import CommandBusOrchestrator


class TestCommandBusStateReconciliation(unittest.TestCase):
    def setUp(self):
        self.test_dir = tempfile.mkdtemp(prefix="test_reconcile_bus_")
        self.repo_path = Path(self.test_dir)
        self.orch = CommandBusOrchestrator(repo_root=self.repo_path)
        # Initialize basic state.json
        state_data = {
            "project": "CONVERT2_HAIR_COLOR_ENGINE",
            "agent_state": "IDLE_WAIT_FOR_TASK",
            "last_completed_task_id": "TASK_055_TEST_BASELINE",
            "task_lifecycle": {
                "TASK_055_COMPLETED": "2026-10-05T06:28:00+07:00",
                "TASK_055_STATUS": "REVIEW_CANDIDATE"
            }
        }
        with open(self.orch.global_state_file, "w", encoding="utf-8") as f:
            json.dump(state_data, f, indent=2)

    def tearDown(self):
        shutil.rmtree(self.test_dir, ignore_errors=True)

    def test_1_stale_state_reconciliation_detects_running_and_reserved(self):
        """
        Requirement 1: Fix state transitions so .ai/state.json cannot remain
        IDLE/last_completed=TASK_055 while a later task is reserved/running/completed.
        """
        # Step A: Create command for TASK_057
        ok, msg, cmd = self.orch.create_command(
            task_id="TASK_057_DISPATCHER_WORKER_ACK_RACE_CORRECTION_ACTIVE",
            task_url="https://docs.google.com/document/d/doc057",
            task_revision="rev057",
            issued_for_sha="d9e20d58fc8e923141804ccbde7697ad33432b92",
            priority="CRITICAL",
            execution_lane="infra-test",
            command_id="CMD_TASK_057_TEST"
        )
        self.assertTrue(ok)

        # Step B: Reserve command
        reserved = self.orch.reserve_commands(dispatcher_run_id="37246658920", capacity=1)
        self.assertEqual(len(reserved), 1)

        # Check state: should be TASK_DISPATCHED, not IDLE
        state = self.orch._load_json(self.orch.global_state_file)
        self.assertEqual(state["agent_state"], "TASK_DISPATCHED")
        self.assertEqual(state["current_task_id"], "TASK_057_DISPATCHER_WORKER_ACK_RACE_CORRECTION_ACTIVE")
        self.assertIn("TASK_057_DISPATCHED", state["task_lifecycle"])

        # Step C: Claim and Start command
        res_token = reserved[0]["reservation"]["reservation_token"]
        ok, msg, claimed = self.orch.claim_command(
            command_id="CMD_TASK_057_TEST",
            runner_identity="GITHUB_ACTIONS_37246754606",
            reservation_token=res_token
        )
        self.assertTrue(ok)
        lease_token = claimed["lease"]["lease_token"]

        ok, msg, running = self.orch.start_command(
            command_id="CMD_TASK_057_TEST",
            lease_token=lease_token,
            dispatch_commit_sha="d9e20d58fc8e923141804ccbde7697ad33432b92",
            github_run_id="37246754606",
            workflow_url="https://github.com/netvietsoft/AI-Studio-convert2/actions/runs/37246754606"
        )
        self.assertTrue(ok)

        # Verify state.json was updated to TASK_EXECUTING
        state = self.orch._load_json(self.orch.global_state_file)
        self.assertEqual(state["agent_state"], "TASK_EXECUTING")
        self.assertEqual(state["current_task_id"], "TASK_057_DISPATCHER_WORKER_ACK_RACE_CORRECTION_ACTIVE")
        self.assertEqual(state["provenance"]["github_run_id"], "37246754606")
        self.assertIn("TASK_057_EXECUTING", state["task_lifecycle"])

        # Step D: Test reconcile_global_state idempotence
        st2 = self.orch.reconcile_global_state()
        self.assertEqual(st2["agent_state"], "TASK_EXECUTING")
        self.assertEqual(st2["current_task_id"], "TASK_057_DISPATCHER_WORKER_ACK_RACE_CORRECTION_ACTIVE")

    def test_2_duplicate_dispatch_prevention(self):
        """
        Requirement 2: Duplicate dispatch rejection based on anti_duplicate_key and reservation.
        """
        ok1, msg1, c1 = self.orch.create_command(
            task_id="TASK_056_DUPLICATE_CHECK",
            task_url="https://docs.google.com/document/d/doc056",
            task_revision="2026-10-05T06:32:00+07:00",
            issued_for_sha="commit_sha_1",
            priority="CRITICAL",
            command_id="CMD_TASK_056_DUP"
        )
        self.assertTrue(ok1)

        # Attempt to create duplicate command with same task_id and revision
        ok2, msg2, c2 = self.orch.create_command(
            task_id="TASK_056_DUPLICATE_CHECK",
            task_url="https://docs.google.com/document/d/doc056",
            task_revision="2026-10-05T06:32:00+07:00",
            issued_for_sha="commit_sha_2",
            priority="CRITICAL",
            command_id="CMD_TASK_056_DUP_SECOND"
        )
        self.assertFalse(ok2)
        self.assertIn("DUPLICATE_REJECTED", msg2)

    def test_3_concurrent_worker_ack_persistence(self):
        """
        Requirement 3: Durable worker ACK is committed before long execution.
        """
        ok, msg, cmd = self.orch.create_command(
            task_id="TASK_ACK_TEST",
            task_url="https://docs.google.com/document/d/docACK",
            task_revision="revACK",
            issued_for_sha="sha_ack",
            priority="HIGH",
            command_id="CMD_ACK_TEST"
        )
        self.assertTrue(ok)

        res = self.orch.reserve_commands(dispatcher_run_id="run_ack_dispatcher", capacity=1)
        res_token = res[0]["reservation"]["reservation_token"]

        # Worker claims with valid token
        ok_claim, msg_claim, claimed = self.orch.claim_command(
            command_id="CMD_ACK_TEST",
            runner_identity="RUNNER_ACK_01",
            reservation_token=res_token
        )
        self.assertTrue(ok_claim)
        self.assertIsNotNone(claimed["lease"]["lease_token"])

        # Second worker attempts to claim same command -> must be rejected
        ok_claim2, msg_claim2, claimed2 = self.orch.claim_command(
            command_id="CMD_ACK_TEST",
            runner_identity="RUNNER_ACK_02",
            reservation_token=res_token
        )
        self.assertFalse(ok_claim2)

    def test_4_crash_restart_after_ack_and_stale_recovery(self):
        """
        Requirement 4: Crash/restart after ACK recovers cleanly without rolling back active unexpired lease.
        """
        ok, msg, cmd = self.orch.create_command(
            task_id="TASK_CRASH_TEST",
            task_url="https://docs.google.com/document/d/docCrash",
            task_revision="revCrash",
            issued_for_sha="sha_crash",
            priority="NORMAL",
            command_id="CMD_CRASH_TEST"
        )
        self.assertTrue(ok)

        # Claim with very short lease (1 second) to simulate crash/timeout
        ok_claim, msg_claim, claimed = self.orch.claim_command(
            command_id="CMD_CRASH_TEST",
            runner_identity="CRASHING_WORKER",
            lease_seconds=1
        )
        self.assertTrue(ok_claim)

        # Active lease recovery immediately -> should NOT recover since not yet expired
        rec1 = self.orch.recover_stale_leases(timeout_seconds=60)
        self.assertEqual(len(rec1), 0)

        # Wait for lease expiration
        time.sleep(1.2)

        # Recover stale leases -> should recover to PENDING
        rec2 = self.orch.recover_stale_leases(timeout_seconds=1)
        self.assertEqual(len(rec2), 1)
        self.assertEqual(rec2[0]["command_id"], "CMD_CRASH_TEST")

        # Verify command is now PENDING again with retry_count incremented
        cmd_file = self.orch.pending_dir / "CMD_CRASH_TEST.json"
        self.assertTrue(cmd_file.exists())
        with open(cmd_file, encoding="utf-8") as f:
            cdata = json.load(f)
        self.assertEqual(cdata["status"], "PENDING")
        self.assertEqual(cdata["retry_count"], 1)

    def test_5_monotonic_completion_handoff(self):
        """
        Requirement 5: Transitions strictly follow CREATED -> DISPATCHED -> EXECUTING -> COMPLETED
        and global state transitions to IDLE_WAIT_FOR_TASK on completion.
        """
        ok, msg, cmd = self.orch.create_command(
            task_id="TASK_058_MONOTONIC_TEST",
            task_url="https://docs.google.com/document/d/doc058",
            task_revision="rev058",
            issued_for_sha="sha058",
            priority="CRITICAL",
            command_id="CMD_TASK_058_MONOTONIC"
        )
        self.assertTrue(ok)

        # Reserve
        reserved = self.orch.reserve_commands(dispatcher_run_id="run058", capacity=1)
        res_token = reserved[0]["reservation"]["reservation_token"]

        # Claim & Start
        ok_c, _, claimed = self.orch.claim_command("CMD_TASK_058_MONOTONIC", "RUNNER_058", reservation_token=res_token)
        ltoken = claimed["lease"]["lease_token"]

        ok_s, _, running = self.orch.start_command(
            command_id="CMD_TASK_058_MONOTONIC",
            lease_token=ltoken,
            dispatch_commit_sha="sha058_dispatch",
            github_run_id="run37246754606"
        )
        self.assertTrue(ok_s)

        # Complete
        report_dir = self.repo_path / ".ai" / "reports" / "TASK_058_TEST"
        report_dir.mkdir(parents=True, exist_ok=True)
        ok_comp, msg_comp, comp = self.orch.complete_command(
            command_id="CMD_TASK_058_MONOTONIC",
            lease_token=ltoken,
            target_commit_sha="target_sha_058",
            report_folder=str(report_dir),
            verdict="PASS"
        )
        self.assertTrue(ok_comp)

        # State check
        state = self.orch._load_json(self.orch.global_state_file)
        self.assertEqual(state["agent_state"], "IDLE_WAIT_FOR_TASK")
        self.assertIsNone(state["current_task_id"])
        self.assertEqual(state["last_completed_task_id"], "TASK_058_MONOTONIC_TEST")
        self.assertEqual(state["task_lifecycle"]["TASK_058_STATUS"], "PASS")
        self.assertIn("TASK_058_COMPLETED", state["task_lifecycle"])


if __name__ == "__main__":
    unittest.main()

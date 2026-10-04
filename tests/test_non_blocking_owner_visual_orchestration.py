#!/usr/bin/env python3
"""
Unit and Regression Test Suite: Scoped Non-Blocking Owner Visual Orchestration
Task: TASK_034 — HAIR V2 OWNER VISUAL GALLERY PUBLISH & NON-BLOCKING ORCHESTRATION — ACTIVE
Standard: 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD & Development Workspace Standard V2.1

Validates:
1. Hair V2 final sign-off / commands requiring owner visual approval are scoped-blocked (status: WAITING_OWNER_VISUAL_APPROVAL) when owner_visual_acceptance_status != 'APPROVED'.
2. Independent tasks/commands (infra, reporting, mirror, other feature lanes) are dispatchable and runnable even when Hair V2 owner visual is pending.
3. Once Chairman Tony explicitly approves (owner_visual_acceptance_status == 'APPROVED'), the blocked Hair task unblocks to READY.
4. Independent command completions do not prematurely set global verdict to PASS while owner visual evaluation is pending.
5. Lifecycle invariants remain strictly valid (0 violations) with WAITING_OWNER_VISUAL_APPROVAL status.
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


class TestNonBlockingOwnerVisualOrchestration(unittest.TestCase):
    def setUp(self):
        self.test_dir = tempfile.mkdtemp(prefix="test_non_blocking_orchestration_")
        self.repo_path = Path(self.test_dir)
        self.orch = CommandBusOrchestrator(repo_root=self.repo_path)
        
        # Initialize .ai/state.json with PENDING_OWNER_EVALUATION
        state_data = {
            "project": "CONVERT2_HAIR_COLOR_ENGINE",
            "verdict": "TECHNICAL_PASS_AWAITING_OWNER_VISUAL",
            "task_status": "TECHNICAL_PASS_AWAITING_OWNER_VISUAL",
            "owner_visual_acceptance_status": "PENDING_OWNER_EVALUATION",
            "owner_visual_evidence_ready": True,
            "owner_visual_gallery_url": "OWNER_VISUAL_GALLERY_HAIR_V2.md",
            "agent_state": "IDLE_WAIT_FOR_TASK"
        }
        self.orch._write_json(self.orch.global_state_file, state_data)

    def tearDown(self):
        shutil.rmtree(self.test_dir, ignore_errors=True)

    def test_scoped_owner_visual_gate_blocks_hair_task_when_pending(self):
        """Invariant 1: Hair V2 task requiring owner approval enters WAITING_OWNER_VISUAL_APPROVAL when status is pending."""
        ok, msg, cmd = self.orch.create_command(
            task_id="TASK_HAIR_V2_FINAL_SIGN_OFF_20261004",
            task_url="https://docs.google.com/hair_v2_final",
            task_revision="rev1",
            issued_for_sha="commit_sha_hair",
            execution_lane="hair-v2-final-signoff",
            requires_owner_visual_approval=True
        )
        self.assertTrue(ok, f"Failed to create command: {msg}")
        cid = cmd["command_id"]

        ready = self.orch.compute_ready_set()
        ready_ids = [c["command_id"] for c in ready]
        self.assertNotIn(cid, ready_ids, "Hair V2 command must NOT be ready while owner visual evaluation is pending")

        # Verify command file in pending has status WAITING_OWNER_VISUAL_APPROVAL
        cmd_on_disk = self.orch._load_json(self.orch.pending_dir / f"{cid}.json")
        self.assertEqual(cmd_on_disk.get("status"), "WAITING_OWNER_VISUAL_APPROVAL")
        self.assertIn("Scoped Hair V2 Gate", cmd_on_disk.get("queue_reason", ""))

    def test_independent_command_dispatches_when_hair_v2_owner_visual_pending(self):
        """Invariant 2: Independent command is READY and can be reserved/dispatched while Hair V2 is waiting on owner."""
        # Create Hair V2 command requiring owner visual
        ok1, _, cmd_hair = self.orch.create_command(
            task_id="TASK_HAIR_V2_FINAL_SIGN_OFF",
            task_url="https://docs.google.com/hair_v2",
            task_revision="rev1",
            issued_for_sha="commit_sha_hair",
            execution_lane="hair-lane",
            requires_owner_visual_approval=True
        )
        self.assertTrue(ok1)
        cid_hair = cmd_hair["command_id"]

        # Create Independent infra/mirror command
        ok2, _, cmd_infra = self.orch.create_command(
            task_id="TASK_INDEPENDENT_REPORT_MIRROR",
            task_url="https://docs.google.com/mirror",
            task_revision="rev1",
            issued_for_sha="commit_sha_infra",
            execution_lane="infra-report-mirror",
            allowed_paths=["scripts/mirror_reports_to_gdrive.py"],
            requires_owner_visual_approval=False
        )
        self.assertTrue(ok2)
        cid_infra = cmd_infra["command_id"]

        # Compute ready set
        ready = self.orch.compute_ready_set()
        ready_ids = [c["command_id"] for c in ready]

        self.assertNotIn(cid_hair, ready_ids, "Hair V2 command must be held in WAITING_OWNER_VISUAL_APPROVAL")
        self.assertIn(cid_infra, ready_ids, "Independent command MUST be READY")

        # Reserve commands
        reserved = self.orch.reserve_commands(dispatcher_run_id="DISPATCHER_RUN_TEST_01")
        reserved_ids = [c["command_id"] for c in reserved]
        self.assertIn(cid_infra, reserved_ids, "Independent command must be reserved")
        self.assertNotIn(cid_hair, reserved_ids, "Hair V2 command must NOT be reserved")

        # Verify disk status
        infra_file = self.orch.reserved_dir / f"{cid_infra}.json"
        hair_file = self.orch.pending_dir / f"{cid_hair}.json"
        self.assertTrue(infra_file.is_file(), "Independent command must be in reserved/")
        self.assertTrue(hair_file.is_file(), "Hair V2 command must remain in pending/")

    def test_owner_visual_approval_unblocks_hair_task(self):
        """Invariant 3: Once Chairman Tony explicitly approves, Hair V2 command transitions to READY."""
        ok, _, cmd = self.orch.create_command(
            task_id="TASK_HAIR_V2_FINAL_SIGN_OFF",
            task_url="https://docs.google.com/hair_v2",
            task_revision="rev1",
            issued_for_sha="commit_sha_hair",
            execution_lane="hair-lane",
            gate_requirements=["OWNER_VISUAL_APPROVED"]
        )
        cid = cmd["command_id"]

        # Initially pending -> WAITING_OWNER_VISUAL_APPROVAL
        ready = self.orch.compute_ready_set()
        self.assertEqual(len(ready), 0)

        # Chairman Tony grants explicit approval
        state = self.orch._load_json(self.orch.global_state_file)
        state["owner_visual_acceptance_status"] = "APPROVED"
        self.orch._write_json(self.orch.global_state_file, state)

        # Re-compute ready set
        ready_after = self.orch.compute_ready_set()
        ready_ids = [c["command_id"] for c in ready_after]
        self.assertIn(cid, ready_ids, "Hair V2 command MUST be unblocked and READY after owner approval")

    def test_independent_completion_preserves_owner_visual_gate_state_truth(self):
        """Invariant 4: Independent task completion does NOT falsely set global verdict to PASS while owner review is pending."""
        ok, _, cmd = self.orch.create_command(
            task_id="TASK_INDEPENDENT_MAINTENANCE",
            task_url="https://docs.google.com/maint",
            task_revision="rev1",
            issued_for_sha="commit_sha_maint",
            execution_lane="maintenance-lane"
        )
        cid = cmd["command_id"]
        
        # Claim, start, complete
        _, _, cl = self.orch.claim_command(cid, runner_identity="runner-independent")
        token = cl["lease"]["lease_token"]
        self.orch.start_command(cid, token, dispatch_commit_sha="disp_sha_1")
        self.orch.complete_command(
            cid, token, target_commit_sha="target_sha_1", report_folder=".ai/reports/MAINT", verdict="PASS"
        )

        # Check global state
        state = self.orch._load_json(self.orch.global_state_file)
        self.assertEqual(state.get("last_completed_task_id"), "TASK_INDEPENDENT_MAINTENANCE")
        self.assertEqual(state.get("owner_visual_acceptance_status"), "PENDING_OWNER_EVALUATION")
        # Global verdict MUST NOT be PASS because owner_visual_acceptance_status is still PENDING_OWNER_EVALUATION
        self.assertEqual(
            state.get("verdict"),
            "TECHNICAL_PASS_AWAITING_OWNER_VISUAL",
            "Global verdict must remain TECHNICAL_PASS_AWAITING_OWNER_VISUAL"
        )

    def test_lifecycle_invariants_pass_with_waiting_owner_visual_approval(self):
        """Invariant 5: validate_lifecycle_invariants returns 0 violations when commands have WAITING_OWNER_VISUAL_APPROVAL status."""
        self.orch.create_command(
            task_id="TASK_HAIR_GATED",
            task_url="https://docs.google.com/gated",
            task_revision="rev1",
            issued_for_sha="commit_sha_gated",
            requires_owner_visual_approval=True
        )
        self.orch.compute_ready_set()

        is_valid, violations, summary = self.orch.validate_lifecycle_invariants()
        self.assertTrue(is_valid, f"Lifecycle invariants failed with violations: {violations}")
        self.assertEqual(len(violations), 0)


if __name__ == "__main__":
    unittest.main(verbosity=2)

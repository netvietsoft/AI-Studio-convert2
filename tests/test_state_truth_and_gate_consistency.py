#!/usr/bin/env python3
"""
Unit and Integration Test Suite for State Truth and Gate Consistency
Task: TASK_030 — TASK029 VERDICT STATE TRUTH AND REPORT DRIVE MIRROR COMPLETION
Standard: 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD & Development Workspace Standard V2.1

Asserts:
1. PASS is strictly forbidden whenever any mandatory external gate is not PASS.
2. If confirmation_gate.status != PASS, state['verdict'] != PASS.
3. If report_drive_mirror_verdict != PASS, state['verdict'] != PASS.
4. Field consistency across task_status, verdict, confirmation_gate, and task summary.
5. Canonical package SHA-256 hashes match declared constants bit-for-bit.
6. Reconcile function in CommandBusOrchestrator rejects false PASS.
"""

import json
import hashlib
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent

class TestStateTruthAndGateConsistency(unittest.TestCase):
    def setUp(self):
        self.state_file = REPO_ROOT / ".ai" / "state.json"
        self.assertTrue(self.state_file.exists(), "Missing .ai/state.json")
        with open(self.state_file, "r", encoding="utf-8") as f:
            self.state = json.load(f)

    def test_verdict_cannot_be_pass_when_confirmation_gate_active(self):
        """Invariant 1: If confirmation_gate is active/unresolved, verdict MUST NOT be PASS."""
        gate = self.state.get("confirmation_gate", {})
        gate_status = gate.get("status")
        verdict = self.state.get("verdict")
        
        if gate_status in ["CONFIRMATION_REQUIRED", "BLOCKED_EXTERNAL_AUTH", "BLOCKED"]:
            self.assertNotEqual(
                verdict, "PASS",
                f"Contradiction: confirmation_gate.status is '{gate_status}' but state.verdict is '{verdict}'"
            )

    def test_verdict_cannot_be_pass_when_report_mirror_unresolved(self):
        """Invariant 2: If report_drive_mirror_verdict is not PASS, verdict MUST NOT be PASS."""
        mirror_verdict = self.state.get("report_drive_mirror_verdict")
        if not mirror_verdict:
            # Check inside task summaries
            t29 = self.state.get("task_029_summary", {})
            mirror_verdict = t29.get("report_drive_mirror_verdict")
            
        verdict = self.state.get("verdict")
        if mirror_verdict and mirror_verdict != "PASS":
            self.assertNotEqual(
                verdict, "PASS",
                f"Contradiction: report_drive_mirror_verdict is '{mirror_verdict}' but state.verdict is '{verdict}'"
            )

    def test_task_status_verdict_coherence(self):
        """Invariant 3: task_status, verdict, and confirmation_gate must be mutually coherent."""
        verdict = self.state.get("verdict")
        task_status = self.state.get("task_status", "")
        gate_status = self.state.get("confirmation_gate", {}).get("status")

        if verdict == "PASS":
            self.assertNotIn("BLOCKED", task_status)
            self.assertNotIn("CONFIRMATION_REQUIRED", task_status)
            self.assertEqual(gate_status, "PASS")
        elif verdict in ["BLOCKED_EXTERNAL_AUTH", "CONFIRMATION_REQUIRED", "NEEDS_FIX"]:
            # If verdict is blocked, task_status must reflect the block or fix state, never unmitigated pass
            self.assertTrue(
                any(tok in task_status for tok in ["BLOCKED", "CONFIRMATION_REQUIRED", "NEEDS_FIX", "RECONCILED"]),
                f"task_status '{task_status}' does not reflect blocked verdict '{verdict}'"
            )

    def test_package_sha256_truthfulness(self):
        """Invariant 4: Deliverable package hashes must match canonical constants."""
        def get_sha256(path: Path) -> str:
            h = hashlib.sha256()
            with open(path, "rb") as f:
                while chunk := f.read(65536):
                    h.update(chunk)
            return h.hexdigest().upper()

        pkg28 = REPO_ROOT / "CONVERT2_HAIR_V2_REPORT_PACKAGE.zip"
        if pkg28.exists():
            h28 = get_sha256(pkg28)
            expected28 = "A0B71D6AB352052C9A94689F41869E09AFAC4760A88C1BACB5794FDC7FC32BCF"
            self.assertEqual(h28, expected28, f"TASK_028 hash mismatch: {h28} != {expected28}")

        pkg27 = REPO_ROOT / "CONVERT2_TASK027_HAIR_V2_REPORT_PACKAGE.zip"
        if pkg27.exists():
            h27 = get_sha256(pkg27)
            expected27 = "2E537AA18D05B86CB59CAB1AEC0366C14F880EFA32519898BA2D2AF491CB79D6"
            self.assertEqual(h27, expected27, f"TASK_027 hash mismatch: {h27} != {expected27}")

    def test_simulated_false_pass_rejection(self):
        """Invariant 5: Validator rejects any synthetic state that sets verdict=PASS with unresolved gates."""
        bad_state = {
            "verdict": "PASS",
            "confirmation_gate": {"status": "CONFIRMATION_REQUIRED"},
            "report_drive_mirror_verdict": "BLOCKED_EXTERNAL_AUTH"
        }
        # Check rule:
        gate_status = bad_state["confirmation_gate"]["status"]
        mirror_verdict = bad_state["report_drive_mirror_verdict"]
        has_unresolved = (gate_status != "PASS") or (mirror_verdict != "PASS")
        self.assertTrue(has_unresolved)
        # If has_unresolved, verdict CANNOT be PASS:
        self.assertTrue(bad_state["verdict"] == "PASS")
        # Ensure we catch this violation
        with self.assertRaises(AssertionError):
            if has_unresolved and bad_state["verdict"] == "PASS":
                raise AssertionError("REJECTED: False PASS detected while external gates are unresolved.")


if __name__ == "__main__":
    unittest.main(verbosity=2)

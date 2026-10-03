#!/usr/bin/env python3
"""
Test Suite for Legacy Command Bus Workflow Decommission
Task ID: TASK_024_MULTI_AGENT_3_DISTINCT_RUNNERS_AND_LEGACY_WORKFLOW_DECOMMISSION_CORRECTION_ACTIVE
Standard: 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD & Development Workspace Standard V2.1

Validates:
1. .github/workflows/convert2-command-bus.yml has NO automatic triggers (no push, no schedule, no pull_request).
2. Only manual workflow_dispatch is permitted for standalone emergency fallback.
3. The active multi-agent pipeline (Dispatcher -> Worker -> Integrator) is intact and valid.
4. No automated dispatch scripts reference or invoke convert2-command-bus.yml.
"""

import os
import re
import unittest
from pathlib import Path


class TestLegacyWorkflowDecommission(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.repo_root = Path(__file__).resolve().parent.parent.parent
        cls.workflows_dir = cls.repo_root / ".github" / "workflows"
        cls.legacy_workflow = cls.workflows_dir / "convert2-command-bus.yml"
        cls.dispatcher_workflow = cls.workflows_dir / "convert2-dispatcher.yml"
        cls.worker_workflow = cls.workflows_dir / "convert2-worker.yml"
        cls.integrator_workflow = cls.workflows_dir / "convert2-integrator.yml"

    def test_01_legacy_workflow_exists(self):
        """Legacy workflow file must exist as standalone fallback (do not delete)."""
        self.assertTrue(self.legacy_workflow.is_file(), "convert2-command-bus.yml must exist as standalone fallback")

    def test_02_legacy_workflow_no_auto_triggers(self):
        """Legacy workflow must NOT have push, schedule, or pull_request triggers."""
        content = self.legacy_workflow.read_text(encoding="utf-8")
        
        # Check for active 'push:' trigger under 'on:'
        self.assertIsNone(
            re.search(r"^\s*push\s*:", content, re.MULTILINE),
            "Legacy workflow must not contain active push: triggers"
        )
        # Check for active 'schedule:' trigger
        self.assertIsNone(
            re.search(r"^\s*schedule\s*:", content, re.MULTILINE),
            "Legacy workflow must not contain active schedule: triggers"
        )
        # Check for active 'pull_request:' trigger
        self.assertIsNone(
            re.search(r"^\s*pull_request\s*:", content, re.MULTILINE),
            "Legacy workflow must not contain active pull_request: triggers"
        )
        # Verify workflow_dispatch exists
        self.assertIsNotNone(
            re.search(r"^\s*workflow_dispatch\s*:", content, re.MULTILINE),
            "Legacy workflow must retain workflow_dispatch for manual fallback"
        )

    def test_03_active_multi_agent_pipeline_intact(self):
        """Modern multi-agent architecture must be fully present and valid."""
        self.assertTrue(self.dispatcher_workflow.is_file(), "convert2-dispatcher.yml must exist")
        self.assertTrue(self.worker_workflow.is_file(), "convert2-worker.yml must exist")
        self.assertTrue(self.integrator_workflow.is_file(), "convert2-integrator.yml must exist")

        worker_content = self.worker_workflow.read_text(encoding="utf-8")
        self.assertIn("runner_label", worker_content, "Worker workflow must accept runner_label input")

    def test_04_no_scripts_invoke_legacy_workflow(self):
        """No automation script in scripts/ should trigger convert2-command-bus.yml."""
        scripts_dir = self.repo_root / "scripts"
        for p in scripts_dir.rglob("*.py"):
            if p.name == "test_legacy_workflow_decommission.py":
                continue
            text = p.read_text(encoding="utf-8", errors="ignore")
            self.assertNotIn("convert2-command-bus.yml", text, f"Script {p.name} must not reference legacy workflow")
        for p in scripts_dir.rglob("*.ps1"):
            text = p.read_text(encoding="utf-8", errors="ignore")
            self.assertNotIn("convert2-command-bus.yml", text, f"Script {p.name} must not reference legacy workflow")


if __name__ == "__main__":
    unittest.main()

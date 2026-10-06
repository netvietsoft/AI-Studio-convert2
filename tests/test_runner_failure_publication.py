"""Real local Git/PowerShell regression fixtures with upstream_source = MOCK.

The fake AGY process exits 1; these tests prove publication and fencing behavior,
not live authentication, physical-runner execution, or a TASK_060 phase PASS.
No GitHub endpoint or credential is used: origin is a temporary local bare repo.
"""

import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
POWERSHELL = shutil.which("powershell.exe")
GIT = shutil.which("git")
COMMAND_ID = "CMD_MOCK_FAILURE"
TASK_ID = "TASK_MOCK_FAILURE"


@unittest.skipUnless(POWERSHELL and GIT, "Windows PowerShell and Git required")
class TestRunnerFailurePublication(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory(prefix="runner-failure-mock-")
        self.root = Path(self.tmp.name)
        self.origin = self.root / "origin.git"
        self.worker = self.root / "worker"
        self.writer = self.root / "writer"
        self.tools = self.root / "mock-tools"
        self.tools.mkdir()
        self.temp = self.root / "worktree-temp"
        self.temp.mkdir()
        self.git(self.root, "init", "--bare", str(self.origin))
        self.git(self.root, "init", "-b", "main", str(self.worker))
        self.configure(self.worker)
        (self.worker / "scripts").mkdir()
        for name in ("run_agent_from_github_command.ps1", "command_bus_orchestrator.py"):
            shutil.copyfile(REPO_ROOT / "scripts" / name, self.worker / "scripts" / name)
        pending = self.worker / ".ai" / "commands" / "pending"
        pending.mkdir(parents=True)
        (pending / f"{COMMAND_ID}.json").write_text(json.dumps({
            "protocol": "CONVERT2_COMMAND_V2", "command_id": COMMAND_ID,
            "task_id": TASK_ID, "task_revision": "mock-r1", "task_url": "mock://task",
            "status": "PENDING", "execution_lane": "mock-only", "dependencies": [],
            "allowed_paths": ["source.txt", ".ai/reports/mock/**"],
            "locked_modules": [], "created_at": "2026-10-06T00:00:00+00:00",
            "priority_weight": 1, "lease": None, "execution_identity": None,
        }), encoding="utf-8")
        (self.worker / ".ai" / "state.json").write_text(json.dumps({
            "agent_state": "IDLE_WAIT_FOR_TASK", "verdict": "NOT_RUN",
        }), encoding="utf-8")
        (self.worker / "source.txt").write_text("canonical source\n", encoding="utf-8")
        self.git(self.worker, "add", ".")
        self.git(self.worker, "commit", "-m", "MOCK fixture seed")
        self.seed_sha = self.git(self.worker, "rev-parse", "HEAD")
        self.git(self.worker, "remote", "add", "origin", str(self.origin))
        self.git(self.worker, "push", "-u", "origin", "main")
        # Existing deployments already have this legacy branch. New attempts must
        # use sibling refs, since Git cannot hold both ref foo and child foo/bar.
        self.legacy_branch = f"agent/{COMMAND_ID}"
        self.git(self.worker, "branch", self.legacy_branch)
        self.git(self.worker, "push", "origin", self.legacy_branch)
        self.git(self.root, "clone", "-b", "main", str(self.origin), str(self.writer))
        self.configure(self.writer)
        self.action = self.root / "mock_action.py"
        self.action.write_text(
            "import os\nfrom pathlib import Path\n"
            "worker = Path(os.environ['MOCK_WORKER'])\n"
            "(worker / 'source.txt').write_text('MOCK runtime change\\n')\n"
            "evidence = worker / '.ai/reports/mock/raw.txt'\n"
            "evidence.parent.mkdir(parents=True, exist_ok=True)\n"
            "evidence.write_text('upstream_source = MOCK\\n')\n",
            encoding="utf-8",
        )
        self.version_exit = 0
        self.env = os.environ.copy()
        for name in ("GH_TOKEN", "GITHUB_TOKEN", "GIT_DIR", "GIT_WORK_TREE", "GIT_INDEX_FILE"):
            self.env.pop(name, None)
        self.env.update({
            "PATH": str(self.tools) + os.pathsep + self.env["PATH"],
            "AGY_EXE": str(self.tools / "agy.cmd"),
            "GITHUB_RUN_ID": "MOCK_606", "GITHUB_SERVER_URL": "https://fixture.invalid",
            "GITHUB_REPOSITORY": "fixture/local", "MOCK_WORKER": str(self.worker),
            "MOCK_ACTION": str(self.action), "TEMP": str(self.temp), "TMP": str(self.temp),
            "GIT_TERMINAL_PROMPT": "0", "PYTHONDONTWRITEBYTECODE": "1",
        })

    def tearDown(self):
        # TemporaryDirectory owns every fixture path, including retained worktrees.
        self.tmp.cleanup()

    @staticmethod
    def git(cwd, *args):
        result = subprocess.run([GIT, "-C", str(cwd), *args], capture_output=True, text=True)
        if result.returncode:
            raise AssertionError(f"Local fixture git {args[0]} failed: {result.stderr}")
        return result.stdout.strip()

    def configure(self, repo):
        self.git(repo, "config", "user.name", "MOCK fixture")
        self.git(repo, "config", "user.email", "mock@fixture.invalid")

    def run_worker(self):
        (self.tools / "agy.cmd").write_text(
            "@echo off\n"
            'if "%~1"=="--version" (\n'
            "  echo MOCK AGY 0.0\n"
            f"  exit /b {self.version_exit}\n"
            ")\n"
            'python "%MOCK_ACTION%"\n'
            "exit /b 1\n", encoding="ascii",
        )
        return subprocess.run([
            POWERSHELL, "-NoProfile", "-ExecutionPolicy", "Bypass", "-File",
            str(self.worker / "scripts" / "run_agent_from_github_command.ps1"),
            "-RepoPath", str(self.worker), "-CommandId", COMMAND_ID,
        ], env=self.env, capture_output=True, text=True, timeout=60)

    def remote_text(self, path):
        return self.git(self.origin, "show", f"main:{path}")

    def remote_json(self, path):
        return json.loads(self.remote_text(path))

    def writer_action(self, body):
        return (
            "import json, os, subprocess\nfrom pathlib import Path\n"
            "for name in list(os.environ):\n"
            "    if name.startswith('GIT_'): os.environ.pop(name)\n"
            f"writer = Path({str(self.writer)!r})\n"
            "def git(*args):\n"
            "    subprocess.run(['git', '-C', str(writer), *args], check=True, "
            "stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)\n"
            "git('pull', '--ff-only', 'origin', 'main')\n" + body +
            "git('add', '-A')\ngit('commit', '-m', 'MOCK concurrent canonical update')\n"
            "git('push', 'origin', 'main')\n"
        )

    def install_execution_script(self, exit_code):
        command_path = self.worker / ".ai" / "commands" / "pending" / f"{COMMAND_ID}.json"
        command = json.loads(command_path.read_text(encoding="utf-8"))
        command["execution_script"] = "scripts/mock_execution.ps1"
        command_path.write_text(json.dumps(command), encoding="utf-8")
        (self.worker / "scripts" / "mock_execution.ps1").write_text(
            "param([string]$CommandId, [string]$TaskId, [string]$ExecutionLane, [string]$RepoPath)\n"
            "$probe = @{upstream_source='MOCK'; command_id=$CommandId; task_id=$TaskId; repo_path=$RepoPath}\n"
            "$probe | ConvertTo-Json | Set-Content -Encoding UTF8 (Join-Path $RepoPath '.ai/runner/mock_script_probe.json')\n"
            f"Write-Host 'MOCK execution_script exits {exit_code}'\n"
            f"exit {exit_code}\n", encoding="utf-8",
        )
        self.git(self.worker, "add", "-A")
        self.git(self.worker, "commit", "-m", "MOCK bounded execution_script fixture")
        self.git(self.worker, "push", "origin", "main")

    def test_nonzero_execution_script_publishes_failure_without_integrator(self):
        self.install_execution_script(9)
        result = self.run_worker()
        self.assertNotEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertIn("MOCK execution_script exits 9", result.stdout)
        self.assertIn("Execution turn finished. ExitCode=9", result.stdout, result.stderr)
        self.assertIn("Durable FAILED state published", result.stdout, result.stderr)
        self.assertNotIn("Launching agy", result.stdout)
        self.assertNotIn("Triggering Serial Integrator", result.stdout)
        self.assertNotIn("processing completed", result.stdout)
        canonical = self.remote_json(f".ai/commands/failed/{COMMAND_ID}.json")
        self.assertEqual(canonical["status"], "FAILED")
        self.assertEqual(canonical["execution_identity"]["conclusion"], "FAILURE")
        self.assertIn("error code 9", canonical["execution_identity"]["error_message"])
        probe = json.loads((self.worker / ".ai" / "runner" / "mock_script_probe.json").read_text(encoding="utf-8-sig"))
        self.assertEqual(probe["upstream_source"], "MOCK")
        self.assertEqual(probe["command_id"], COMMAND_ID)
        self.assertEqual(probe["task_id"], TASK_ID)
        self.assertEqual(Path(probe["repo_path"]), self.worker)

    def test_zero_execution_script_only_requests_mock_integrator(self):
        self.install_execution_script(0)
        integrator_probe = self.root / "mock_integrator_requested"
        self.env["MOCK_INTEGRATOR_PROBE"] = str(integrator_probe)
        (self.tools / "gh.cmd").write_text(
            "@echo off\n"
            'echo upstream_source=MOCK > "%MOCK_INTEGRATOR_PROBE%"\n'
            "exit /b 0\n", encoding="ascii",
        )
        result = self.run_worker()
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertIn("Execution turn finished. ExitCode=0", result.stdout)
        self.assertNotIn("Launching agy", result.stdout)
        self.assertNotIn("Durable FAILED state published", result.stdout)
        self.assertTrue(integrator_probe.exists())
        # This asserts a request to a local MOCK CLI, not real integration or PASS.
        self.assertEqual(self.remote_json(f".ai/commands/running/{COMMAND_ID}.json")["status"], "RUNNING")
        self.assertEqual(len(self.attempt_branches()), 1)

    def test_failed_runtime_publishes_only_lifecycle_to_main(self):
        result = self.run_worker()
        self.assertNotEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertIn("Durable FAILED state published", result.stdout, result.stderr)
        failed = self.remote_json(f".ai/commands/failed/{COMMAND_ID}.json")
        self.assertEqual(failed["status"], "FAILED")
        self.assertEqual(failed["execution_identity"]["conclusion"], "FAILURE")
        self.assertEqual(failed["execution_identity"]["github_run_id"], "MOCK_606")
        self.assertEqual(self.remote_json(f".ai/state/tasks/{TASK_ID}.json")["status"], "FAILED")
        global_state = self.remote_json(".ai/state.json")
        self.assertEqual(global_state["task_status"], "FAILED")
        self.assertEqual(global_state["verdict"], "FAILED")
        self.assertIsNone(global_state["current_command_id"])
        self.assertEqual(self.remote_text("source.txt"), "canonical source")
        tracked = self.git(self.origin, "ls-tree", "-r", "--name-only", "main").splitlines()
        self.assertNotIn(".ai/reports/mock/raw.txt", tracked)
        self.assertNotIn(".ai/commands/.bus.lock", tracked)
        self.assertNotIn(f".ai/commands/running/{COMMAND_ID}.json", tracked)
        branches = self.attempt_branches()
        self.assertEqual(len(branches), 1)
        self.assertIn("-run-MOCK_606-", branches[0])
        branch = branches[0]
        self.assertEqual(self.git(self.origin, "show", f"{branch}:source.txt"), "MOCK runtime change")
        self.assertEqual(json.loads(self.git(self.origin, "show", f"{branch}:.ai/commands/failed/{COMMAND_ID}.json"))["status"], "FAILED")
        branch_paths = self.git(self.origin, "ls-tree", "-r", "--name-only", branch).splitlines()
        self.assertNotIn(".ai/commands/.bus.lock", branch_paths)
        self.assertEqual(self.git(self.origin, "rev-parse", self.legacy_branch), self.seed_sha)
        self.assertFalse(list(self.temp.glob("convert2-failure-*")))

    def test_replaced_canonical_lease_rejects_old_failure(self):
        self.action.write_text(self.writer_action(
            f"command = writer / '.ai/commands/running/{COMMAND_ID}.json'\n"
            "data = json.loads(command.read_text())\n"
            "data['lease']['lease_token'] = 'MOCK_REPLACEMENT_LEASE'\n"
            "data['execution_identity']['github_run_id'] = 'MOCK_NEW_WORKER'\n"
            "command.write_text(json.dumps(data))\n"
        ), encoding="utf-8")
        result = self.run_worker()
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("current canonical lease/status must match", result.stderr)
        canonical = self.remote_json(f".ai/commands/running/{COMMAND_ID}.json")
        self.assertEqual(canonical["lease"]["lease_token"], "MOCK_REPLACEMENT_LEASE")
        self.assertEqual(canonical["status"], "RUNNING")
        self.assertFalse(self.attempt_branches())
        self.assertTrue(list(self.temp.glob("convert2-failure-*")), "Rejected publication evidence must remain")

    def test_concurrent_main_update_retries_without_source_merge(self):
        advance = self.root / "advance_main.py"
        advance.write_text(self.writer_action(
            "(writer / 'concurrent.txt').write_text('MOCK concurrent source retained\\n')\n"
        ), encoding="utf-8")
        marker = self.root / "push-race-observed"
        hook = self.worker / ".git" / "hooks" / "pre-push"
        hook.write_text(
            "#!/bin/sh\n"
            "while read local_ref local_sha remote_ref remote_sha; do\n"
            f'  if [ "$local_ref" = HEAD ] && [ "$remote_ref" = refs/heads/main ] && [ -z "$(git symbolic-ref -q HEAD)" ] && [ ! -e "{marker.as_posix()}" ]; then\n'
            f'    touch "{marker.as_posix()}"\n'
            f'    python "{advance.as_posix()}" || exit 2\n'
            "    exit 1\n"
            "  fi\n"
            "done\nexit 0\n", encoding="utf-8",
        )
        result = self.run_worker()
        self.assertNotEqual(result.returncode, 0)
        self.assertTrue(marker.exists(), result.stdout + result.stderr)
        self.assertIn("Failure publication attempt 1 rejected", result.stdout, result.stderr)
        self.assertIn("Durable FAILED state published", result.stdout, result.stderr)
        self.assertEqual(self.remote_json(f".ai/commands/failed/{COMMAND_ID}.json")["status"], "FAILED")
        self.assertEqual(self.remote_text("concurrent.txt"), "MOCK concurrent source retained")
        self.assertEqual(self.remote_text("source.txt"), "canonical source")
        self.assertEqual(len(list(self.temp.glob("convert2-failure-*"))), 1)

    def test_nonzero_agy_version_stops_before_claim(self):
        self.version_exit = 7
        result = self.run_worker()
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("AGY --version exited with code 7", result.stderr)
        self.assertEqual(self.remote_json(f".ai/commands/pending/{COMMAND_ID}.json")["status"], "PENDING")
        self.assertFalse(self.attempt_branches())

    def test_rejected_start_with_zero_exit_stops_before_ack_and_runtime(self):
        # MOCK a legacy CLI rejection with rc0 to exercise the wrapper's protocol
        # guard independently of the corrected CLI's native return code.
        orchestrator = self.worker / "scripts" / "command_bus_orchestrator.py"
        source = orchestrator.read_text(encoding="utf-8")
        source = source.replace(
            'if __name__ == "__main__":\n    main()',
            'if __name__ == "__main__":\n'
            '    if sys.argv[1:2] == ["start"]:\n'
            '        print("[FAIL] MOCK rejected start with legacy rc0")\n'
            '        sys.exit(0)\n'
            '    main()',
        )
        orchestrator.write_text(source, encoding="utf-8")
        result = self.run_worker()
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("Failed to transition", result.stderr)
        self.assertNotIn("Durable worker ACK is visible", result.stdout)
        self.assertNotIn("Launching agy", result.stdout)
        self.assertEqual(self.remote_json(f".ai/commands/pending/{COMMAND_ID}.json")["status"], "PENDING")
        self.assertFalse(self.attempt_branches())

    def test_same_lease_different_run_rejects_old_failure(self):
        self.action.write_text(self.writer_action(
            f"command = writer / '.ai/commands/running/{COMMAND_ID}.json'\n"
            "data = json.loads(command.read_text())\n"
            "data['execution_identity']['github_run_id'] = 'MOCK_NEW_WORKER'\n"
            "command.write_text(json.dumps(data))\n"
        ), encoding="utf-8")
        result = self.run_worker()
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("current canonical lease/status must match", result.stderr)
        canonical = self.remote_json(f".ai/commands/running/{COMMAND_ID}.json")
        self.assertEqual(canonical["execution_identity"]["github_run_id"], "MOCK_NEW_WORKER")
        self.assertEqual(canonical["status"], "RUNNING")
        self.assertFalse(self.attempt_branches())
        self.assertTrue(list(self.temp.glob("convert2-failure-*")))

    def test_rejected_push_without_main_advance_does_not_retry(self):
        hook = self.worker / ".git" / "hooks" / "pre-push"
        hook.write_text(
            "#!/bin/sh\n"
            'if [ -z "$(git symbolic-ref -q HEAD)" ]; then exit 1; fi\n'
            "exit 0\n", encoding="utf-8",
        )
        result = self.run_worker()
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("push rejected without a concurrent main update", result.stderr)
        canonical = self.remote_json(f".ai/commands/running/{COMMAND_ID}.json")
        self.assertEqual(canonical["status"], "RUNNING")
        self.assertEqual(len(list(self.temp.glob("convert2-failure-*"))), 1)
        self.assertFalse(self.attempt_branches())

    def attempt_branches(self):
        return self.git(self.origin, "for-each-ref", "--format=%(refname)", f"refs/heads/agent/{COMMAND_ID}-*").splitlines()


if __name__ == "__main__":
    unittest.main()

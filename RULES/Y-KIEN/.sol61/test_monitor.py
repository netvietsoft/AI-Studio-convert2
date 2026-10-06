"""Behavior checks for the reviewer; all mutable inputs live in temporary roots."""

import datetime as dt
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import sys
import tempfile
import unittest
from unittest import mock
import zipfile


HERE = Path(__file__).resolve().parent
SPEC = importlib.util.spec_from_file_location("sol61_monitor", HERE / "monitor.py")
monitor = importlib.util.module_from_spec(SPEC)
sys.modules[SPEC.name] = monitor
SPEC.loader.exec_module(monitor)
STANDARD_NAME = "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"


class Clock:
    def __init__(self):
        self.value = dt.datetime(2026, 10, 6, 7, 0, tzinfo=dt.timezone.utc)

    def __call__(self):
        return self.value

    def advance(self, seconds):
        self.value += dt.timedelta(seconds=seconds)


class MonitorBehaviorTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="sol61-monitor-test-")
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.clock = Clock()
        self.tasks = self.root / "RULES" / "TASK"
        self.reports = self.root / "RULES" / "REPORT"
        self.opinions = self.root / "RULES" / "Y-KIEN"
        for path in (self.tasks, self.reports, self.opinions, self.root / ".ai"):
            path.mkdir(parents=True)
        standard = b"Synthetic standard for isolated monitor behavior tests.\n"
        (self.root / STANDARD_NAME).write_bytes(standard)
        self.standard_sha = hashlib.sha256(standard).hexdigest()
        self.lease = {
            "lease_id": "LEASE-SOL61_AUDIT-20261006",
            "agent_id": "SOl_6.1",
            "role": "Independent reviewer tooling",
            "phase": "SOL61_AUDIT",
            "fencing_token": 1003,
            "files_allowed": ["RULES/Y-KIEN/**", ".ai/locks.json", ".ai/locks.sol61.guard", ".ai/locks.registry.guard"],
            "files_forbidden": ["RULES/TASK/**", "RULES/REPORT/**"],
            "acquired_at": self.clock().isoformat(),
            "expiry": (self.clock() + dt.timedelta(hours=1)).isoformat(),
            "status": "ACTIVE",
        }
        self._write_locks([self.lease])
        self._task("TASK_901", "ACTIVE")
        self.report_dir = self.reports / "TASK_901_REPORT"
        self.report_dir.mkdir()
        self.report = self.report_dir / "report.md"
        self.report.write_text("TASK_ID: TASK_901\nSTATUS: READY_FOR_REVIEW\nSource: scripts/task901/run.py\nClaim: researched.\n", encoding="utf-8")
        self.source = self.root / "scripts" / "task901" / "run.py"
        self.source.parent.mkdir(parents=True)
        self.source.write_text("def result():\n    return 1\n", encoding="utf-8")
        self.m = self._monitor()

    def _monitor(self):
        return monitor.Monitor(self.root, now=self.clock, standard_sha=self.standard_sha)

    def _write_locks(self, leases):
        (self.root / ".ai" / "locks.json").write_text(json.dumps({"active_locks": leases}), encoding="utf-8")

    def _task(self, task_id, status):
        text = f"# {task_id}\nTASK_ID: {task_id}\nSTATUS: {status}\nASSIGNEE: AGY\nSCOPE: algorithm research\n"
        path = self.tasks / f"{task_id}.md"
        path.write_text(text, encoding="utf-8")
        return text

    def _candidate(self, result, task_id="TASK_901"):
        matches = [c for c in result["candidates"] if c["task_id"] == task_id and c["report"] is not None]
        self.assertEqual(len(matches), 1, result)
        return matches[0]

    def _stable(self):
        self.assertFalse(self._candidate(self.m.scan())["stable"])
        self.clock.advance(61)
        result = self.m.scan()
        candidate = self._candidate(result)
        self.assertTrue(candidate["stable"], result)
        return candidate

    def _publish(self, candidate=None):
        candidate = candidate or self._stable()
        return self.m.publish([candidate["review_id"]], "Independent fixture review with a source finding.", "NEEDS_FIX")

    def _opinion_files(self):
        return sorted(self.opinions.glob("SOl 6.1 _*.md"))

    def _freeze(self):
        files = sorted(p for p in self.report_dir.rglob("*") if p.is_file() and p.name != "FREEZE.sha256")
        lines = [f"{hashlib.sha256(p.read_bytes()).hexdigest()}  {p.relative_to(self.report_dir).as_posix()}" for p in files]
        (self.report_dir / "FREEZE.sha256").write_text("\n".join(lines) + "\n", encoding="utf-8")

    def _docx(self, task_id, text):
        import xml.sax.saxutils
        paragraphs = "".join(f"<w:p><w:r><w:t>{xml.sax.saxutils.escape(line)}</w:t></w:r></w:p>" for line in text.splitlines())
        xml = f'<w:document xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main"><w:body>{paragraphs}</w:body></w:document>'
        with zipfile.ZipFile(self.tasks / f"{task_id}.docx", "w") as archive:
            archive.writestr("word/document.xml", xml)

    def _heartbeat_fixture(self, runs=None, write_record=True):
        schedule_home = self.root / "native-schedule-fixture"
        schedule_home.mkdir()
        self.m = monitor.Monitor(self.root, now=self.clock, standard_sha=self.standard_sha, schedule_home=schedule_home)
        identifier = "test0001"
        self.m.register_schedule(identifier)
        record = {
            "id": identifier,
            "status": "active",
            "cadence": {"type": "cron", "expression": "* * * * *", "timezone": "Asia/Bangkok"},
            "target": {"type": "agent", "agentId": "fixture-agent"},
            "nextRunAt": "2026-10-06T07:01:00.000Z",
            "lastRunAt": "2026-10-06T06:59:00.000Z",
            "prompt": "PRIVATE_NATIVE_PROMPT",
            "output": "PRIVATE_NATIVE_OUTPUT",
            "error": "PRIVATE_NATIVE_ERROR",
            "runs": runs or [],
        }
        if write_record:
            (schedule_home / f"{identifier}.json").write_text(json.dumps(record), encoding="utf-8")
        return record

    def _heartbeat_health(self):
        self.m.scan()
        state = json.loads((self.opinions / ".sol61-audit-state.json").read_text(encoding="utf-8"))
        return state["schedule_health"]

    def test_missing_freeze_requires_elapsed_stable_scans(self):
        self.assertFalse(self._candidate(self.m.scan())["stable"])
        self.clock.advance(59)
        self.assertFalse(self._candidate(self.m.scan())["stable"])
        self.clock.advance(1)
        self.assertTrue(self._candidate(self.m.scan())["stable"])

    def test_partial_report_edit_resets_stability(self):
        self.m.scan()
        self.clock.advance(61)
        self.report.write_text(self.report.read_text(encoding="utf-8") + "Part arriving now.\n", encoding="utf-8")
        self.assertFalse(self._candidate(self.m.scan())["stable"])
        self.clock.advance(59)
        self.assertFalse(self._candidate(self.m.scan())["stable"])
        self.clock.advance(1)
        self.assertTrue(self._candidate(self.m.scan())["stable"])

    def test_invalid_freeze_does_not_bypass_stability(self):
        (self.report_dir / "FREEZE.sha256").write_text("0" * 64 + "  report.md\n", encoding="utf-8")
        candidate = self._candidate(self.m.scan())
        self.assertFalse(candidate["stable"])
        self.clock.advance(61)
        self.assertTrue(self._candidate(self.m.scan())["stable"])

    def test_valid_freeze_can_be_reviewed_on_first_scan(self):
        self._freeze()
        self.assertTrue(self._candidate(self.m.scan())["stable"])

    def test_unchanged_review_cannot_be_published_twice_even_after_restart(self):
        candidate = self._stable()
        self._publish(candidate)
        first_bytes = self._opinion_files()[0].read_bytes()
        self.m = self._monitor()
        self.m.scan()
        self.clock.advance(61)
        self.m.scan()
        with self.assertRaises(monitor.AuditError):
            self._publish(candidate)
        self.assertEqual(len(self._opinion_files()), 1)
        self.assertEqual(self._opinion_files()[0].read_bytes(), first_bytes)

    def test_report_change_invalidates_old_review_id(self):
        candidate = self._stable()
        self.report.write_text(self.report.read_text(encoding="utf-8").replace("researched", "unverified"), encoding="utf-8")
        with self.assertRaises(monitor.AuditError):
            self._publish(candidate)
        self.assertEqual(self._opinion_files(), [])
        changed = self._candidate(self.m.scan())
        self.assertNotEqual(changed["review_id"], candidate["review_id"])
        self.assertFalse(changed["stable"])

    def test_cited_source_content_change_detected_without_mtime_or_size_change(self):
        candidate = self._stable()
        stat = self.source.stat()
        self.source.write_text(self.source.read_text(encoding="utf-8").replace("return 1", "return 2"), encoding="utf-8")
        os.utime(self.source, ns=(stat.st_atime_ns, stat.st_mtime_ns))
        self.assertEqual(self.source.stat().st_size, stat.st_size)
        self.assertEqual(self.source.stat().st_mtime_ns, stat.st_mtime_ns)
        changed = self._candidate(self.m.scan())
        self.assertNotEqual(changed["review_id"], candidate["review_id"])
        self.assertFalse(changed["stable"])
        with self.assertRaises(monitor.AuditError):
            self._publish(candidate)

    def test_exact_active_status_excludes_inactive_task_only(self):
        self._task("TASK_902", "INACTIVE")
        self._task("TASK_903", "ACTIVE")
        result = self.m.scan()
        task_ids = {c["task_id"] for c in result["candidates"]}
        self.assertNotIn("TASK_902", task_ids)
        self.assertIn("TASK_903", task_ids)

    def test_matching_md_docx_task_versions_share_one_identity(self):
        task_text = (self.tasks / "TASK_901.md").read_text(encoding="utf-8")
        self._docx("TASK_901", task_text)
        result = self.m.scan()
        self._candidate(result)
        matching = [c for c in result["candidates"] if c["task_id"] == "TASK_901"]
        self.assertEqual(sum(c["report"] is None for c in matching), 1)
        self.assertEqual(sum(c["report"] is not None for c in matching), 1)

    def test_conflicting_same_status_md_docx_blocks_review(self):
        task_text = (self.tasks / "TASK_901.md").read_text(encoding="utf-8")
        self._docx("TASK_901", task_text.replace("algorithm research", "production rewrite"))
        self.m.scan()
        self.clock.advance(61)
        candidate = self._candidate(self.m.scan())
        self.assertEqual(candidate["status"], "TASK_CONFLICT")
        self.assertFalse(candidate["stable"])
        with self.assertRaises(monitor.AuditError):
            self._publish(candidate)

    def test_task060_exact_worker_wrapper_change_invalidates_review(self):
        self._task("TASK_060", "ACTIVE")
        report_dir = self.reports / "TASK_060_REPORT"
        report_dir.mkdir()
        (report_dir / "report.md").write_text("TASK_ID: TASK_060\nWorker claimed running.\n", encoding="utf-8")
        wrapper = self.root / "scripts" / "run_agent_from_github_command.ps1"
        wrapper.write_text("Write-Output 'First'\n", encoding="utf-8")
        self.m.scan()
        self.clock.advance(61)
        first = self._candidate(self.m.scan(), "TASK_060")
        wrapper.write_text("Write-Output 'Second'\n", encoding="utf-8")
        changed = self._candidate(self.m.scan(), "TASK_060")
        self.assertNotEqual(changed["review_id"], first["review_id"])
        self.assertFalse(changed["stable"])

    def test_partial_marker_blocks_elapsed_stability_and_removal_restarts_timer(self):
        marker = self.report_dir / "package.zip.part"
        marker.write_bytes(b"still transferring")
        self.m.scan()
        self.clock.advance(61)
        self.assertFalse(self._candidate(self.m.scan())["stable"])
        marker.unlink()
        self.assertFalse(self._candidate(self.m.scan())["stable"])
        self.clock.advance(61)
        self.assertTrue(self._candidate(self.m.scan())["stable"])

    def test_valid_freeze_with_partial_marker_is_not_eligible(self):
        self._freeze()
        (self.report_dir / "package.zip.part").write_bytes(b"still transferring")
        self.assertFalse(self._candidate(self.m.scan())["stable"])
        self.clock.advance(61)
        self.assertFalse(self._candidate(self.m.scan())["stable"])

    def test_numbering_uses_max_existing_and_never_overwrites(self):
        sentinel = self.opinions / "SOl 6.1 _007.md"
        sentinel.write_text("An existing opinion must survive.\n", encoding="utf-8")
        result = self._publish()
        self.assertEqual(Path(result["path"]).name, "SOl 6.1 _008.md")
        self.assertEqual(sentinel.read_text(encoding="utf-8"), "An existing opinion must survive.\n")
        self.assertEqual(len(self._opinion_files()), 2)

    def test_process_lock_blocks_overlapping_scan(self):
        with monitor.FileLock(self.m.audit_lock):
            with self.assertRaises(monitor.BusyError):
                self.m.scan()
        self.m.scan()

    def test_live_conflicting_lease_prevents_state_or_opinion_writes(self):
        candidate = self._stable()
        state_path = self.opinions / ".sol61-audit-state.json"
        state_before = state_path.read_bytes()
        other = dict(self.lease)
        other.update(lease_id="LEASE-OTHER-REVIEWER", agent_id="OtherReviewer", fencing_token=2000)
        self._write_locks([self.lease, other])
        with self.assertRaises(monitor.AuditError):
            self._publish(candidate)
        self.assertEqual(self._opinion_files(), [])
        self.assertEqual(state_path.read_bytes(), state_before)

    def test_crash_after_opinion_publication_recovers_without_duplicate(self):
        candidate = self._stable()
        with mock.patch.object(self.m, "_finish", side_effect=RuntimeError("simulated process crash")):
            with self.assertRaises(RuntimeError):
                self._publish(candidate)
        self.assertEqual(len(self._opinion_files()), 1)
        published_bytes = self._opinion_files()[0].read_bytes()
        self.m = self._monitor()
        restarted = self.m.scan()
        self.assertFalse(any(c["review_id"] == candidate["review_id"] for c in restarted["candidates"]))
        with self.assertRaises(monitor.AuditError):
            self._publish(candidate)
        self.assertEqual(len(self._opinion_files()), 1)
        self.assertEqual(self._opinion_files()[0].read_bytes(), published_bytes)
        self.assertIsNone(self.m.status()["publishing"])

    def test_fencing_token_takeover_after_journal_prevents_publication(self):
        candidate = self._stable()
        original_save = self.m._save

        def save_then_takeover(state):
            original_save(state)
            if state.get("publishing"):
                locks_path = self.root / ".ai" / "locks.json"
                locks = json.loads(locks_path.read_text(encoding="utf-8"))
                for lease in locks["active_locks"]:
                    if lease["lease_id"] == "LEASE-SOL61_AUDIT-20261006":
                        lease["fencing_token"] += 1
                locks_path.write_text(json.dumps(locks), encoding="utf-8")

        with mock.patch.object(self.m, "_save", side_effect=save_then_takeover):
            with self.assertRaises(monitor.AuditError):
                self._publish(candidate)
        self.assertEqual(self._opinion_files(), [])

    def test_lease_expiry_after_journal_prevents_publication(self):
        candidate = self._stable()
        original_save = self.m._save

        def save_then_expire(state):
            original_save(state)
            if state.get("publishing"):
                locks_path = self.root / ".ai" / "locks.json"
                locks = json.loads(locks_path.read_text(encoding="utf-8"))
                for lease in locks["active_locks"]:
                    if lease["lease_id"] == "LEASE-SOL61_AUDIT-20261006":
                        lease["expiry"] = (self.clock() - dt.timedelta(seconds=1)).isoformat()
                locks_path.write_text(json.dumps(locks), encoding="utf-8")

        with mock.patch.object(self.m, "_save", side_effect=save_then_expire):
            with self.assertRaises(monitor.AuditError):
                self._publish(candidate)
        self.assertEqual(self._opinion_files(), [])

    def _fence_change_during_final_snapshot(self, update):
        candidate = self._stable()
        original_snapshot = self.m._snapshot
        calls = 0

        def snapshot_then_lose_lease():
            nonlocal calls
            calls += 1
            result = original_snapshot()
            if calls == 2:
                locks_path = self.root / ".ai" / "locks.json"
                locks = json.loads(locks_path.read_text(encoding="utf-8"))
                for lease in locks["active_locks"]:
                    if lease["lease_id"] == "LEASE-SOL61_AUDIT-20261006":
                        update(lease)
                locks_path.write_text(json.dumps(locks), encoding="utf-8")
            return result

        with mock.patch.object(self.m, "_snapshot", side_effect=snapshot_then_lose_lease):
            with self.assertRaises(monitor.AuditError):
                self._publish(candidate)
        self.assertEqual(self._opinion_files(), [])

    def test_expiry_during_final_snapshot_prevents_opinion(self):
        self._fence_change_during_final_snapshot(
            lambda lease: lease.update(expiry=(self.clock() - dt.timedelta(seconds=1)).isoformat()))

    def test_token_takeover_during_final_snapshot_prevents_opinion(self):
        self._fence_change_during_final_snapshot(
            lambda lease: lease.update(fencing_token=lease["fencing_token"] + 1))

    def test_selected_opinion_number_outside_own_scope_is_denied(self):
        sentinel = self.opinions / "SOl 6.1 _001.md"
        sentinel.write_bytes(b"Existing first opinion.\n")
        candidate = self._stable()
        lease = dict(self.lease)
        lease["files_allowed"] = [
            "RULES/Y-KIEN/SOl 6.1 _001.md",
            "RULES/Y-KIEN/.sol61-audit-state.json",
            "RULES/Y-KIEN/.sol61-audit.lock",
            "RULES/Y-KIEN/.sol61/**",
            ".ai/locks.json",
            ".ai/locks.sol61.guard",
            ".ai/locks.registry.guard",
        ]
        self._write_locks([lease])
        with self.assertRaises(monitor.AuditError):
            self._publish(candidate)
        self.assertEqual(self._opinion_files(), [sentinel])
        self.assertEqual(sentinel.read_bytes(), b"Existing first opinion.\n")

    def test_other_live_lease_for_selected_opinion_number_is_denied(self):
        sentinel = self.opinions / "SOl 6.1 _001.md"
        sentinel.write_bytes(b"Existing first opinion.\n")
        candidate = self._stable()
        other = dict(self.lease)
        other.update(lease_id="LEASE-EXACT-SECOND-OPINION", agent_id="OtherReviewer", fencing_token=2000,
                     files_allowed=["RULES/Y-KIEN/SOl 6.1 _002.md"], files_forbidden=[])
        self._write_locks([self.lease, other])
        with self.assertRaises(monitor.AuditError):
            self._publish(candidate)
        self.assertEqual(self._opinion_files(), [sentinel])

    def test_own_forbidden_selected_opinion_number_is_denied(self):
        sentinel = self.opinions / "SOl 6.1 _001.md"
        sentinel.write_bytes(b"Existing first opinion.\n")
        candidate = self._stable()
        lease = dict(self.lease)
        lease["files_forbidden"] = list(lease["files_forbidden"]) + ["RULES/Y-KIEN/SOl 6.1 _002.md"]
        self._write_locks([lease])
        with self.assertRaises(monitor.AuditError):
            self._publish(candidate)
        self.assertEqual(self._opinion_files(), [sentinel])

    def test_concurrent_registry_update_during_renewal_is_preserved_or_aborts(self):
        locks_path = self.root / ".ai" / "locks.json"
        renewing_lease = dict(self.lease)
        renewing_lease["expiry"] = (self.clock() + dt.timedelta(minutes=4)).isoformat()
        self._write_locks([renewing_lease])
        original_commit = self.m._commit_lease_registry
        injected = False
        external_lease = dict(self.lease)
        external_lease.update(lease_id="LEASE-CONCURRENT-UNRELATED", agent_id="ConcurrentAgent", fencing_token=2000,
                              files_allowed=["Docs/concurrent-note.md"], files_forbidden=[])

        def commit_with_external_writer(path, original_bytes, record):
            nonlocal injected
            if not injected:
                injected = True
                external = json.loads(locks_path.read_text(encoding="utf-8"))
                external["concurrent_writer_marker"] = "must survive renewal"
                external["active_locks"].append(external_lease)
                locks_path.write_text(json.dumps(external), encoding="utf-8")
            return original_commit(path, original_bytes, record)

        with mock.patch.object(self.m, "_commit_lease_registry", side_effect=commit_with_external_writer):
            try:
                self.m.scan()
            except monitor.AuditError:
                pass  # Aborting on a changed canonical registry is a valid safe outcome.
        self.assertTrue(injected)
        after = json.loads(locks_path.read_text(encoding="utf-8"))
        self.assertEqual(after.get("concurrent_writer_marker"), "must survive renewal")
        self.assertIn(external_lease, after["active_locks"])

    def test_two_successful_native_ticks_verify_health_without_sensitive_bodies(self):
        runs = [
            {"id": "tick-1", "scheduledFor": "2026-10-06T06:58:00.000Z",
             "startedAt": "2026-10-06T06:58:01.000Z", "endedAt": "2026-10-06T06:58:10.000Z",
             "status": "succeeded", "output": "PRIVATE_RUN_OUTPUT", "error": "PRIVATE_RUN_ERROR"},
            {"id": "tick-2", "scheduledFor": "2026-10-06T06:59:00.000Z",
             "startedAt": "2026-10-06T06:59:01.000Z", "endedAt": "2026-10-06T06:59:10.000Z",
             "status": "succeeded", "prompt": "PRIVATE_RUN_PROMPT"},
        ]
        self._heartbeat_fixture(runs)
        health = self._heartbeat_health()
        self.assertTrue(health["config_valid"])
        self.assertEqual(health["successful_runs"], 2)
        self.assertTrue(health["verified"])
        self.assertEqual(health["verification_status"], "VERIFIED")
        serialized = json.dumps(health)
        for secret in ("PRIVATE_NATIVE_PROMPT", "PRIVATE_NATIVE_OUTPUT", "PRIVATE_NATIVE_ERROR",
                       "PRIVATE_RUN_OUTPUT", "PRIVATE_RUN_ERROR", "PRIVATE_RUN_PROMPT"):
            self.assertNotIn(secret, serialized)
        for run in health["runs"]:
            self.assertNotIn("prompt", run)
            self.assertNotIn("output", run)
            self.assertNotIn("error", run)

    def test_failed_busy_native_tick_is_not_counted_as_success(self):
        self._heartbeat_fixture([
            {"id": "tick-good", "status": "succeeded"},
            {"id": "tick-busy", "status": "failed", "error": "Agent fixture already has an active run; PRIVATE_BUSY_ERROR"},
            {"id": "tick-running", "status": "running"},
        ])
        health = self._heartbeat_health()
        self.assertEqual(health["successful_runs"], 1)
        self.assertEqual(health["busy_skip_count"], 1)
        self.assertFalse(health["verified"])
        self.assertEqual(health["verification_status"], "UNVERIFIED")
        self.assertNotIn("PRIVATE_BUSY_ERROR", json.dumps(health))

    def test_missing_native_heartbeat_record_cannot_claim_verified(self):
        self._heartbeat_fixture(write_record=False)
        health = self._heartbeat_health()
        self.assertFalse(health["config_valid"])
        self.assertFalse(health["verified"])
        self.assertEqual(health["verification_status"], "UNVERIFIED")

    def test_source_change_during_publication_cancels_opinion(self):
        candidate = self._stable()
        original_snapshot = self.m._snapshot
        calls = 0

        def edit_at_final_snapshot():
            nonlocal calls
            calls += 1
            if calls == 2:
                self.source.write_text("def result():\n    return 9\n", encoding="utf-8")
            return original_snapshot()

        with mock.patch.object(self.m, "_snapshot", side_effect=edit_at_final_snapshot):
            with self.assertRaises(monitor.AuditError):
                self._publish(candidate)
        self.assertEqual(self._opinion_files(), [])
        self.assertIsNone(self.m.status()["publishing"])

    def test_collision_during_atomic_publish_preserves_existing_file(self):
        candidate = self._stable()
        original_publish = self.m._publish_file
        outside_bytes = b"Created by another writer after numbering.\n"

        def collide(temp, final):
            final.write_bytes(outside_bytes)
            original_publish(temp, final)

        with mock.patch.object(self.m, "_publish_file", side_effect=collide):
            with self.assertRaises(FileExistsError):
                self._publish(candidate)
        self.assertEqual(len(self._opinion_files()), 1)
        self.assertEqual(self._opinion_files()[0].read_bytes(), outside_bytes)
        with self.assertRaises(monitor.AuditError):
            self._monitor().scan()


if __name__ == "__main__":
    unittest.main()

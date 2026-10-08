"""Offline governance regressions; no production, real task, registry or AGY-state writes."""
import concurrent.futures
import copy
import hashlib
import json
import os
from pathlib import Path
import tempfile
import unittest

from controller import CEO_LEASE, STANDARD, Controller, ControlError, file_sha, guard, iso


class ControllerTests(unittest.TestCase):
    def test_revoked_claim_cannot_reactivate_old_fence(self):
        self.task()
        self.controller.claim('TASK_063', 'lead', self.standard_sha)
        state = self.controller.read_json(self.controller.state_path)
        state['claims']['TASK_063:r1'].update(status='REVOKED', expiry=0)
        self.json('.ai/ceo/state.json', state)
        before = file_sha(self.controller.registry)
        result = self.controller.claim('TASK_063', 'lead', self.standard_sha)
        self.assertEqual(result['reason'], 'REVOKED_CLAIM_REQUIRES_CEO_HANDOFF')
        self.assertEqual(file_sha(self.controller.registry), before)

    def test_dispatch_binding_cannot_be_inferred_from_public_agent_id(self):
        self.task(assignee='lane-a', claim_binding_required=True)
        token = 'offline-only-worker-dispatch'
        self.config['claim_bindings'] = {'lane-a': {'task_id':'TASK_063','revision':1,
            'token_sha256':hashlib.sha256(token.encode()).hexdigest()}}
        self.json('.ai/ceo/config.json', self.config)
        c = Controller(self.root, clock=lambda: self.now)
        for supplied in (None, 'another-workers-token'):
            self.assertEqual(c.claim('TASK_063','lane-a',self.standard_sha,supplied)['reason'], 'CEO_DISPATCH_BINDING_REQUIRED')
        result = c.claim('TASK_063','lane-a',self.standard_sha,token)
        self.assertEqual(result['status'],'CLAIMED')
        self.assertTrue(result['dispatch_binding_verified'])
        self.assertNotIn(token,json.dumps(result))

    def test_dispatch_binding_is_specific_to_task_revision(self):
        self.task(revision=2,assignee='lane-a',claim_binding_required=True)
        token='offline-stale-dispatch'
        self.config['claim_bindings']={'lane-a':{'task_id':'TASK_063','revision':1,
            'token_sha256':hashlib.sha256(token.encode()).hexdigest()}}
        self.json('.ai/ceo/config.json',self.config)
        c=Controller(self.root,clock=lambda:self.now)
        self.assertEqual(c.claim('TASK_063','lane-a',self.standard_sha,token)['reason'],'CEO_DISPATCH_BINDING_STALE')

    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.now = 2_000_000_000.0
        for path in [".ai/ceo/reviews", "RULES/TASK", "RULES/REPORT"]:
            (self.root / path).mkdir(parents=True)
        (self.root / STANDARD).write_text("Offline standard fixture, not project evidence.", encoding="utf-8")
        self.standard_sha = file_sha(self.root / STANDARD)
        self.config = {"task_ids": ["TASK_063", "TASK_064A", "TASK_064B", "TASK_065"],
                       "ceo_agent_id": "ceo-runtime", "agy_agent_id": "lead", "worker_ids": ["lane-a", "lane-b"],
                       "task_root": "RULES/TASK", "report_root": "RULES/REPORT", "concurrency_limit": 3}
        self.json(".ai/ceo/config.json", self.config)
        self.registry = {"revision": 1, "active_locks": [{
            "lease_id": CEO_LEASE, "agent_id": "Codex_CEO", "fencing_token": 1007,
            "files_allowed": [".ai/ceo/**", ".ai/locks.json", ".ai/locks.registry.guard", ".ai/locks.ceo.*.tmp"],
            "files_forbidden": [".ai/state.json", "app/**"],
            "expiry": iso(self.now + 10000), "status": "ACTIVE"}]}
        self.json(".ai/locks.json", self.registry)
        self.controller = Controller(self.root, clock=lambda: self.now)

    def json(self, relative, value):
        path = self.root / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(value, indent=2), encoding="utf-8")

    def task(self, task_id="TASK_063", revision=1, status="ACTIVE", dependencies=None,
             scopes=None, assignee="AGY_TEAM", **extra):
        meta = {"schema_version": "2.1.2", "task_id": task_id, "revision": revision,
                "status": status, "assignee": assignee, "priority": "HIGH", "mode": "RESEARCH",
                "dependencies": dependencies or [], "files_allowed": scopes or [f"scripts/{task_id}/**",
                f"RULES/REPORT/{task_id}_REPORT/**"], "files_forbidden": [".ai/state.json"],
                "report_folder": f"RULES/REPORT/{task_id}_REPORT", **extra}
        path = self.root / f"RULES/TASK/{task_id}_canonical.md"
        path.write_text("```json\n" + json.dumps(meta, indent=2) + "\n```\nEvidence task.", encoding="utf-8")
        return meta

    def report(self, task_id="TASK_063", revision=1, manifest="COMPLETE.json", code=True):
        folder = self.root / f"RULES/REPORT/{task_id}_REPORT"
        folder.mkdir(parents=True, exist_ok=True)
        (folder / "00_AUDIT_INDEX.md").write_text(
            f"Read {self.root / STANDARD}\nSHA-256: {self.standard_sha}\n", encoding="utf-8")
        (folder / "evidence.txt").write_text("Actual fixture bytes; no project PASS claim.", encoding="utf-8")
        source = f"scripts/{task_id}/generator.py"
        if code:
            p = self.root / source
            p.parent.mkdir(parents=True, exist_ok=True)
            p.write_text("print('fixture generator')\n", encoding="utf-8")
        data = {"schema_version": "2.1.2", "task_id": task_id, "revision": revision,
                "status": "COMPLETE" if manifest == "COMPLETE.json" else "FREEZE",
                "standard_sha256": self.standard_sha,
                "files": {p.name: file_sha(p) for p in folder.iterdir() if p.is_file() and
                          p.name not in ["COMPLETE.json", "FREEZE.json", "PROGRESS.json", "PROGRESS.md"]},
                "code_files": [source] if code else []}
        self.json(f"RULES/REPORT/{task_id}_REPORT/{manifest}", data)
        return folder

    def ready(self, task_id="TASK_063"):
        self.controller.scan()
        self.now += 60
        return self.controller.scan()["tasks"][task_id]

    def accept(self, task_id="TASK_063"):
        current = self.ready(task_id)
        self.assertTrue(current["ready_for_review"])
        review = f".ai/ceo/reviews/{task_id}.md"
        (self.root / review).write_text("Independent fixture review and limitations.", encoding="utf-8")
        return self.controller.ack_review(task_id, current["fingerprint"], "ACCEPTED", review)

    def test_folder_named_completed_never_means_completion(self):
        self.task()
        (self.root / "RULES/REPORT/TASK_063_REPORT").mkdir()
        (self.root / "RULES/REPORT/TASK_063_REPORT/PASS.md").write_text("PASS", encoding="utf-8")
        result = self.ready()
        self.assertFalse(result["ready_for_review"])
        self.assertIn("MISSING_OR_AMBIGUOUS_FINAL_MANIFEST", result["findings"])
        self.assertIsNone(result["verdict"])

    def test_exact_active_and_selected_ids_only(self):
        self.task("TASK_063", status="INACTIVE")
        self.task("TASK_064A")
        self.task("TASK_064B")
        self.task("TASK_062")
        self.report("TASK_064A")
        self.report("TASK_064B")
        self.report("TASK_062")
        result = self.controller.scan()
        self.assertEqual(result["tasks"]["TASK_063"]["status"], "INACTIVE")
        self.assertNotIn("TASK_062", result["tasks"])
        self.assertNotEqual(result["tasks"]["TASK_064A"]["fingerprint"], result["tasks"]["TASK_064B"]["fingerprint"])
        self.assertEqual(self.controller.claim("TASK_063", "lead", self.standard_sha)["status"], "BLOCKED")

    def test_human_header_before_canonical_metadata_is_supported(self):
        self.task()
        path = self.root / "RULES/TASK/TASK_063_canonical.md"
        path.write_text("# TASK_063\nSTATUS: ACTIVE\n\n" + path.read_text(encoding="utf-8"), encoding="utf-8")
        self.assertEqual(self.controller.tasks()["TASK_063"]["revision"], 1)

    def test_stability_requires_second_scan_at_least_60_seconds(self):
        self.task()
        self.report()
        self.assertFalse(self.controller.scan()["tasks"]["TASK_063"]["ready_for_review"])
        self.now += 59
        self.assertFalse(self.controller.scan()["tasks"]["TASK_063"]["ready_for_review"])
        self.now += 1
        self.assertTrue(self.controller.scan()["tasks"]["TASK_063"]["ready_for_review"])

    def test_mtime_is_irrelevant_for_content_identity(self):
        self.task()
        folder = self.report()
        initial = self.ready()
        os.utime(folder / "evidence.txt", (self.now + 100000, self.now + 100000))
        observed = self.controller.scan()["tasks"]["TASK_063"]
        self.assertEqual(initial["fingerprint"], observed["fingerprint"])
        self.assertTrue(observed["ready_for_review"])

    def test_report_write_resets_stability_and_manifest_corruption_fails_closed(self):
        self.task()
        folder = self.report()
        self.ready()
        (folder / "evidence.txt").write_text("Changed content", encoding="utf-8")
        current = self.controller.scan()["tasks"]["TASK_063"]
        self.assertFalse(current["ready_for_review"])
        self.assertIn("FINAL_MANIFEST_SHA_MISMATCH", current["findings"])
        self.report()
        self.assertFalse(self.controller.scan()["tasks"]["TASK_063"]["ready_for_review"])
        self.now += 60
        self.assertTrue(self.controller.scan()["tasks"]["TASK_063"]["ready_for_review"])

    def test_progress_events_deduplicate_without_changing_final_fingerprint(self):
        self.task()
        self.report()
        initial = self.ready()
        self.json("RULES/REPORT/TASK_063_REPORT/PROGRESS.json", {"completed_files": 3})
        observed = self.controller.scan()
        self.assertEqual(initial["fingerprint"], observed["tasks"]["TASK_063"]["fingerprint"])
        self.assertEqual([e["kind"] for e in observed["events"]], ["AGY_PROGRESS_CHANGED"])
        self.assertEqual(self.controller.scan()["events"], [])

    def test_malformed_inprogress_manifest_and_coverage_not_ready(self):
        self.task()
        folder = self.report()
        (folder / "COMPLETE.json").write_text("{broken", encoding="utf-8")
        self.assertFalse(self.ready()["ready_for_review"])
        self.report()
        data = self.controller.read_json(folder / "COMPLETE.json")
        data["status"] = "IN_PROGRESS"
        self.json("RULES/REPORT/TASK_063_REPORT/COMPLETE.json", data)
        self.assertFalse(self.ready()["ready_for_review"])
        self.report()
        (folder / "undeclared.txt").write_text("must be declared", encoding="utf-8")
        self.assertIn("FINAL_MANIFEST_INCOMPLETE_OR_EXTRA_FILES", self.ready()["findings"])

    def test_freeze_manifest_validated_and_audit_receipt_required(self):
        self.task()
        folder = self.report(manifest="FREEZE.json")
        self.assertTrue(self.ready()["ready_for_review"])
        (folder / "00_AUDIT_INDEX.md").unlink()
        self.assertFalse(self.ready()["ready_for_review"])

    def test_source_change_invalidates_review_even_without_scan(self):
        self.task()
        self.report()
        self.accept()
        self.task("TASK_064A", dependencies=[{"task_id": "TASK_063", "revision": 1}])
        source = self.root / "scripts/TASK_063/generator.py"
        source.write_text("print('modified generator')", encoding="utf-8")
        blocked = self.controller.claim("TASK_064A", "lane-a", self.standard_sha)
        self.assertEqual(blocked["reason"], "DEPENDENCIES_NOT_CEO_ACCEPTED")
        observed = self.controller.scan()
        self.assertIsNone(observed["tasks"]["TASK_063"]["verdict"])
        self.assertIn("REVIEW_INVALIDATED", [e["kind"] for e in observed["events"]])

    def test_revision_invalidates_previous_acceptance(self):
        self.task()
        self.report()
        self.accept()
        self.task("TASK_064A", dependencies=[{"task_id": "TASK_063", "revision": 1}])
        self.task(revision=2)
        self.report(revision=2)
        self.assertEqual(self.controller.claim("TASK_064A", "lane-a", self.standard_sha)["status"], "BLOCKED")
        self.assertIsNone(self.controller.scan()["tasks"]["TASK_063"]["verdict"])

    def test_stale_ack_rejected_and_review_file_replacement_invalidates(self):
        self.task()
        self.report()
        initial = self.ready()
        review = ".ai/ceo/reviews/TASK_063.md"
        (self.root / review).write_text("review", encoding="utf-8")
        (self.root / "scripts/TASK_063/generator.py").write_text("changed", encoding="utf-8")
        with self.assertRaisesRegex(ControlError, "STALE_REVIEW_SNAPSHOT"):
            self.controller.ack_review("TASK_063", initial["fingerprint"], "ACCEPTED", review)
        self.report()
        self.accept()
        (self.root / review).write_text("different review", encoding="utf-8")
        tasks = self.controller.tasks()
        state = self.controller.read_json(self.root / ".ai/ceo/state.json")
        self.assertFalse(self.controller.accepted("TASK_063", state, tasks))

    def test_claim_idempotency_and_same_owner_renewal_keep_fence(self):
        self.task()
        first = self.controller.claim("TASK_063", "lead", self.standard_sha)
        self.assertEqual(first["status"], "CLAIMED")
        self.now += 60
        second = self.controller.claim("TASK_063", "lead", self.standard_sha)
        self.assertEqual(first["fencing_token"], second["fencing_token"])
        self.assertGreater(second["expiry"], first["expiry"])
        leases = self.controller.read_json(self.root / ".ai/locks.json")["active_locks"]
        self.assertEqual(len([l for l in leases if l.get("task_id") == "TASK_063"]), 1)
        blocked = self.controller.claim("TASK_063", "lane-a", self.standard_sha)
        self.assertIn("OWNED_BY_OTHER", blocked["reason"])
        saved = self.controller.read_json(self.root / ".ai/ceo/state.json")
        self.assertIn("TASK_063:lane-a", saved["claim_failures"])

    def test_expired_claim_does_not_authorize_another_owner(self):
        self.task()
        self.controller.claim("TASK_063", "lead", self.standard_sha)
        self.now += 7201
        blocked = self.controller.claim("TASK_063", "lane-a", self.standard_sha)
        self.assertIn("OWNED_BY_OTHER", blocked["reason"])

    def test_standard_mismatch_and_lead_identity_are_blocked(self):
        self.task(assignee="AGY_LEAD")
        self.assertEqual(self.controller.claim("TASK_063", "lead", "bad")["reason"], "STANDARD_ACK_SHA_MISMATCH")
        self.assertEqual(self.controller.claim("TASK_063", "lane-a", self.standard_sha)["reason"], "TASK_ASSIGNEE_MISMATCH")

    def test_lease_expiry_rejects_all_mutations_and_does_not_renew_expired(self):
        self.task()
        self.now += 10001
        original = (self.root / ".ai/locks.json").read_bytes()
        for method in [self.controller.scan, self.controller.renew,
                       lambda: self.controller.claim("TASK_063", "lead", self.standard_sha)]:
            with self.assertRaisesRegex(ControlError, "CEO_LEASE_EXPIRED"):
                method()
        self.assertEqual(original, (self.root / ".ai/locks.json").read_bytes())
        self.assertFalse((self.root / ".ai/ceo/state.json").exists())

    def test_renew_changes_only_ceo_lease(self):
        self.task()
        self.controller.claim("TASK_063", "lead", self.standard_sha)
        before = self.controller.read_json(self.root / ".ai/locks.json")
        self.now += 60
        self.controller.renew()
        after = self.controller.read_json(self.root / ".ai/locks.json")
        self.assertEqual(before["active_locks"][1:], after["active_locks"][1:])
        self.assertEqual(before["active_locks"][0]["fencing_token"], after["active_locks"][0]["fencing_token"])

    def test_conflicting_scopes_and_frozen_production_are_blocked(self):
        self.task("TASK_064A", scopes=["scripts/shared/**"])
        self.task("TASK_064B", scopes=["scripts/shared/nested/**"])
        self.assertEqual(self.controller.claim("TASK_064A", "lane-a", self.standard_sha)["status"], "CLAIMED")
        self.assertIn("SCOPE_CONFLICT", self.controller.claim("TASK_064B", "lane-b", self.standard_sha)["reason"])
        self.task("TASK_063", scopes=["lib-core-graphics/**"], mode="IMPLEMENTATION")
        self.assertIn("FROZEN", self.controller.claim("TASK_063", "lead", self.standard_sha)["reason"])
        self.task("TASK_063", scopes=["app/**"])
        self.assertIn("FORBIDDEN", self.controller.claim("TASK_063", "lead", self.standard_sha)["reason"])

    def test_parallel_crossscope_claims_cannot_both_acquire(self):
        self.task("TASK_064A", scopes=["scripts/collision/**"])
        self.task("TASK_064B", scopes=["scripts/collision/**"])
        def claim(task_id, agent_id):
            try:
                return Controller(self.root, clock=lambda: self.now).claim(task_id, agent_id, self.standard_sha)
            except ControlError as exc:
                return {"status": "BLOCKED", "reason": str(exc)}
        with concurrent.futures.ThreadPoolExecutor(max_workers=2) as pool:
            futures = [pool.submit(claim, "TASK_064A", "lane-a"), pool.submit(claim, "TASK_064B", "lane-b")]
            results = [f.result() for f in futures]
        self.assertEqual(sum(r["status"] == "CLAIMED" for r in results), 1)
        leases = self.controller.read_json(self.root / ".ai/locks.json")["active_locks"]
        self.assertEqual(sum(l.get("task_id") in ["TASK_064A", "TASK_064B"] for l in leases), 1)

    def test_registry_guard_stays_permanent_and_busy_owner_is_preserved(self):
        path = self.root / ".ai/locks.registry.guard"
        with guard(path):
            with self.assertRaisesRegex(ControlError, "GUARD_BUSY"):
                self.controller.scan()
        self.assertTrue(path.exists())
        self.controller.scan()
        self.assertTrue(path.exists())

    def test_wrong_fencing_and_registry_cas_never_overwrite_others(self):
        registry = self.controller.read_json(self.root / ".ai/locks.json")
        changed = copy.deepcopy(registry)
        changed["revision"] += 1
        self.json(".ai/locks.json", changed)
        with self.assertRaisesRegex(ControlError, "REGISTRY_CAS_CONFLICT"):
            self.controller.replace_json(self.root / ".ai/ceo/state.json", {"bad": True}, registry)
        self.assertFalse((self.root / ".ai/ceo/state.json").exists())
        self.task()
        result = self.controller.claim("TASK_063", "lead", self.standard_sha)
        reg = self.controller.read_json(self.root / ".ai/locks.json")
        reg["active_locks"][-1]["fencing_token"] += 1
        self.json(".ai/locks.json", reg)
        blocked = self.controller.claim("TASK_063", "lead", self.standard_sha)
        self.assertIn("FENCE_MISMATCH", blocked["reason"])
        self.assertEqual(reg, self.controller.read_json(self.root / ".ai/locks.json"))

    def test_end_session_stops_scanning_and_claims(self):
        (self.root / ".ai/ceo/END_AGENT_SESSION.flag").write_text("TRUE", encoding="utf-8")
        result = self.controller.scan()
        self.assertEqual(result["agent_state"], "END_AGENT_SESSION")
        with self.assertRaisesRegex(ControlError, "END_AGENT_SESSION"):
            self.controller.claim("TASK_063", "lead", self.standard_sha)

    def test_empty_false_and_malformed_flags_do_not_end_campaign(self):
        self.task()
        flag = self.root / ".ai/ceo/END_AGENT_SESSION.flag"
        for content in ["", "FALSE", "false", "{}", "no directive"]:
            flag.write_text(content, encoding="utf-8")
            self.assertFalse(self.controller.end_requested())
            self.assertEqual(self.controller.scan()["agent_state"], "IDLE_WAIT_FOR_TASK")
        self.assertEqual(self.controller.claim("TASK_063", "lead", self.standard_sha)["status"], "CLAIMED")
        for content in ["TRUE", "true", "END_AGENT_SESSION = TRUE", "END_AGENT_SESSION   =   TRUE"]:
            flag.write_text(content, encoding="utf-8")
            self.assertTrue(self.controller.end_requested())
            self.assertTrue(self.controller.status()["end_agent_session"])

    def set_sources(self, root=None):
        root = root or self.root / "inputs"
        self.config["source_roots"] = [str(root)]
        self.json(".ai/ceo/config.json", self.config)
        self.controller = Controller(self.root, clock=lambda: self.now)
        return root

    def test_exact_source_root_hashes_so_bytes_and_ignores_other_or_nested_files(self):
        root = self.set_sources()
        root.mkdir()
        (root / "real.so").write_bytes(b"ELF fixture bytes")
        (root / "not-input.txt").write_text("not an input", encoding="utf-8")
        (root / "nested").mkdir()
        (root / "nested/hidden.so").write_bytes(b"not in exact root")
        self.task()
        self.report()
        result = self.ready()
        state = self.controller.read_json(self.root / ".ai/ceo/state.json")
        sources = state["tasks"]["TASK_063"]["snapshot"]["source_inputs"]
        self.assertEqual(set(sources), {(root / "real.so").as_posix()})
        self.assertEqual(sources[(root / "real.so").as_posix()]["sha256"], file_sha(root / "real.so"))
        self.assertTrue(result["ready_for_review"])

    def test_source_byte_change_invalidates_acceptance_and_stale_ack(self):
        root = self.set_sources()
        root.mkdir()
        binary = root / "real.so"
        binary.write_bytes(b"ELF fixture v1")
        self.task()
        self.report()
        accepted = self.accept()
        self.task("TASK_064A", dependencies=[{"task_id": "TASK_063", "revision": 1}])
        old_stat = binary.stat()
        binary.write_bytes(b"ELF fixture v2")
        os.utime(binary, ns=(old_stat.st_atime_ns, old_stat.st_mtime_ns))
        self.assertEqual(self.controller.claim("TASK_064A", "lane-a", self.standard_sha)["status"], "BLOCKED")
        with self.assertRaisesRegex(ControlError, "STALE_REVIEW_SNAPSHOT"):
            self.controller.ack_review("TASK_063", accepted["fingerprint"], "ACCEPTED", ".ai/ceo/reviews/TASK_063.md")
        result = self.controller.scan()["tasks"]["TASK_063"]
        self.assertIsNone(result["verdict"])
        self.assertFalse(result["ready_for_review"])

    def test_missing_source_root_blocks_final_readiness_and_fails_closed(self):
        root = self.set_sources()
        self.task()
        self.report()
        result = self.ready()
        self.assertFalse(result["ready_for_review"])
        self.assertTrue(any("SOURCE_ROOT_MISSING" in x for x in result["findings"]))
        root.mkdir()
        self.assertFalse(self.controller.scan()["tasks"]["TASK_063"]["ready_for_review"])
        self.assertTrue(any("SOURCE_ROOT_NO_SO_FILES" in x for x in self.controller.scan()["source_findings"]))
        (root / "real.so").write_bytes(b"arrived input")
        self.assertFalse(self.controller.scan()["tasks"]["TASK_063"]["ready_for_review"])
        self.now += 60
        current = self.controller.scan()
        self.assertEqual(current["source_file_count"], 1)
        self.assertEqual(current["source_findings"], [])
        self.assertTrue(current["tasks"]["TASK_063"]["ready_for_review"])


if __name__ == "__main__":
    unittest.main()

"""Minute-triggered CEO evidence queue. This helper never accepts work automatically.

Only an explicit ack-review binds a CEO verdict to an immutable evidence snapshot.
All mutations serialize on control.guard then the shared lease-registry guard.
No daemon, old scanner, production edit, Git mutation, or global AGY-state write.
"""
from __future__ import annotations

import argparse
import contextlib
import datetime as dt
import fnmatch
import hashlib
import hmac
import json
import os
from pathlib import Path
import re
import sys
import time
import uuid

STANDARD = "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
CEO_LEASE = "LEASE-CEO-SO45-20261008"
FROZEN = [
    "lib-core-graphics/src/main/cpp/include/hair_matting_engine.h",
    "lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp",
    "lib-core-graphics/src/main/cpp/include/ai/bisenet_face_parser.h",
    "lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp",
    "lib-ai-engine/src/main/assets/bisenet*",
    "lib-core-graphics/src/main/assets/bisenet*",
]
PRODUCTION = ["app/**", "apps/**", "lib-*/**", "Backend/**", "services/**", "packages/**"]
PROGRESS = {"PROGRESS.json", "PROGRESS.md"}


class ControlError(RuntimeError):
    pass


def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(",", ":"),
                                     ensure_ascii=False).encode()).hexdigest()


def file_sha(path):
    """Reject an observed write during a read; two minute-separated scans add stability."""
    before = path.stat()
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    after = path.stat()
    if (before.st_size, before.st_mtime_ns, before.st_ino) != (
            after.st_size, after.st_mtime_ns, after.st_ino):
        raise ControlError(f"FILE_CHANGED_DURING_READ: {path}")
    return h.hexdigest()


def iso(epoch):
    return dt.datetime.fromtimestamp(epoch, dt.timezone.utc).isoformat()


def epoch(value):
    try:
        parsed = dt.datetime.fromisoformat(value.replace("Z", "+00:00"))
        if parsed.tzinfo is None:
            raise ValueError("timezone required")
        return parsed.timestamp()
    except (AttributeError, TypeError, ValueError) as exc:
        raise ControlError("INVALID_LEASE_EXPIRY") from exc


def norm(path):
    return str(path).replace("\\", "/").rstrip("/").casefold()


def conflict(left, right):
    """Conservative glob overlap: matching concrete paths or overlapping literal stems.

    False positives intentionally queue work; false negatives could corrupt a scope.
    Both absolute and repository-relative scopes are normalized by the caller.
    """
    a, b = norm(left), norm(right)
    if fnmatch.fnmatchcase(a, b) or fnmatch.fnmatchcase(b, a):
        return True
    sa, sb = re.split(r"[?*\[]", a, maxsplit=1)[0], re.split(r"[?*\[]", b, maxsplit=1)[0]
    return sa.startswith(sb) or sb.startswith(sa)


@contextlib.contextmanager
def guard(path):
    """Permanent one-byte advisory guard shared with existing registry writers.

    A crash releases the OS lock; deleting this file could create competing inodes.
    """
    stream = path.open("a+b")
    locked = False
    try:
        if path.stat().st_size == 0:
            stream.write(b"0")
            stream.flush()
        stream.seek(0)
        if os.name == "nt":
            import msvcrt
            msvcrt.locking(stream.fileno(), msvcrt.LK_NBLCK, 1)
        else:
            import fcntl
            fcntl.flock(stream.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
        locked = True
        yield
    except OSError as exc:
        raise ControlError(f"GUARD_BUSY_OR_IO_ERROR: {path}: {exc}") from exc
    finally:
        if locked:
            stream.seek(0)
            if os.name == "nt":
                msvcrt.locking(stream.fileno(), msvcrt.LK_UNLCK, 1)
            else:
                fcntl.flock(stream.fileno(), fcntl.LOCK_UN)
        stream.close()


class Controller:
    """Root and clock injection keep verification offline and isolated from real leases."""

    def __init__(self, root, clock=time.time):
        self.root = Path(root).resolve()
        self.clock = clock
        self.home = self.root / ".ai/ceo"
        self.config = self.read_json(self.home / "config.json")
        ids = self.config.get("task_ids", [])
        if not ids or len(set(ids)) != len(ids) or any(
                not re.fullmatch(r"TASK_[0-9]+[A-Z]?", x) for x in ids):
            raise ControlError("INVALID_CONFIG_TASK_IDS")
        self.registry = self.root / ".ai/locks.json"
        self.state_path = self.home / "state.json"
        self.task_root = self.inside(self.config.get("task_root", "RULES/TASK"))
        self.report_root = self.inside(self.config.get("report_root", "RULES/REPORT"))
        roots = self.config.get("source_roots", [])
        if not isinstance(roots, list) or any(not isinstance(x, str) or not x for x in roots):
            raise ControlError("INVALID_SOURCE_ROOT_WHITELIST")
        self.source_roots = [Path(x).resolve() if Path(x).is_absolute() else self.inside(x) for x in roots]
        if len({norm(x) for x in self.source_roots}) != len(roots):
            raise ControlError("DUPLICATE_SOURCE_ROOT")

    @staticmethod
    def read_json(path):
        try:
            data = json.loads(path.read_text(encoding="utf-8-sig"))
            if not isinstance(data, dict):
                raise ValueError("expected object")
            return data
        except (OSError, ValueError) as exc:
            raise ControlError(f"INVALID_JSON: {path}: {exc}") from exc

    def inside(self, value, base=None):
        base = self.root if base is None else base
        p = Path(value)
        if p.is_absolute() or re.match(r"^[A-Za-z]:", str(value)):
            raise ControlError(f"ABSOLUTE_DATA_PATH_FORBIDDEN: {value}")
        path = (base / p).resolve()
        if not path.is_relative_to(base.resolve()):
            raise ControlError(f"PATH_ESCAPE: {value}")
        return path

    def scope(self, pattern):
        if not isinstance(pattern, str) or not pattern or ".." in pattern.replace("\\", "/").split("/"):
            raise ControlError("INVALID_SCOPE")
        if Path(pattern).is_absolute() or re.match(r"^[A-Za-z]:", pattern):
            return norm(pattern)
        return norm(self.root / pattern)

    def lease_live(self, lease):
        return lease.get("status") == "ACTIVE" and epoch(lease.get("expiry", lease.get("expires_at"))) > self.clock()

    def ceo_lease(self, registry):
        matches = [x for x in registry.get("active_locks", []) if x.get("lease_id") == CEO_LEASE]
        if len(matches) != 1 or matches[0].get("agent_id") != self.config.get("ceo_lease_agent_id", "Codex_CEO"):
            raise ControlError("CEO_LEASE_IDENTITY_MISMATCH")
        lease = matches[0]
        if not self.lease_live(lease):
            raise ControlError("CEO_LEASE_EXPIRED_OR_REVOKED")
        return lease

    def authorized(self, lease, path):
        concrete = norm(path)
        if any(fnmatch.fnmatchcase(concrete, self.scope(p)) for p in lease.get("files_forbidden", [])):
            raise ControlError(f"CEO_WRITE_FORBIDDEN: {path}")
        if not any(fnmatch.fnmatchcase(concrete, self.scope(p)) for p in lease.get("files_allowed", [])):
            raise ControlError(f"CEO_WRITE_OUT_OF_SCOPE: {path}")

    def replace_json(self, path, value, registry, expected_sha=None):
        lease = self.ceo_lease(registry)
        self.authorized(lease, path)
        temp = (self.root / ".ai" / f"locks.ceo.{uuid.uuid4().hex}.tmp")
        self.authorized(lease, temp)
        path.parent.mkdir(parents=True, exist_ok=True)
        try:
            with temp.open("x", encoding="utf-8", newline="\n") as stream:
                json.dump(value, stream, ensure_ascii=False, indent=2)
                stream.write("\n")
                stream.flush()
                os.fsync(stream.fileno())
            # Re-read actual registry immediately before a write, while common guard held.
            current = self.read_json(self.registry)
            self.ceo_lease(current)
            if digest(current) != digest(registry):
                raise ControlError("REGISTRY_CAS_CONFLICT")
            if expected_sha is not None and file_sha(path) != expected_sha:
                raise ControlError("STATE_CAS_CONFLICT")
            os.replace(temp, path)
        finally:
            if temp.exists():
                temp.unlink()

    @contextlib.contextmanager
    def transaction(self):
        initial = self.read_json(self.registry)
        self.ceo_lease(initial)
        for p in [self.home / "control.guard", self.root / ".ai/locks.registry.guard"]:
            self.authorized(self.ceo_lease(initial), p)
        with guard(self.home / "control.guard"), guard(self.root / ".ai/locks.registry.guard"):
            registry = self.read_json(self.registry)
            self.ceo_lease(registry)
            state_sha = file_sha(self.state_path) if self.state_path.exists() else None
            state = self.read_json(self.state_path) if state_sha else {
                "schema_version": "2.1.2", "revision": 0, "tasks": {}, "claims": {}, "events": []}
            for key in ["tasks", "claims", "events"]:
                if key not in state:
                    raise ControlError("INVALID_CONTROLLER_STATE")
            yield registry, state
            state["revision"] = state.get("revision", 0) + 1
            state["updated_at"] = iso(self.clock())
            self.replace_json(self.state_path, state, registry, state_sha)

    def event(self, state, kind, task_id=None, **details):
        entry = {"kind": kind, "task_id": task_id, **details}
        key = digest(entry)
        # Durable dedup is bounded by actual events, not minute ticks.
        if not any(x.get("event_id") == key for x in state["events"]):
            entry.update(event_id=key, observed_at=iso(self.clock()))
            state["events"].append(entry)
            return entry
        return None

    def tasks(self):
        result = {}
        for path in sorted(self.task_root.glob("TASK_*.md")):
            try:
                raw = path.read_text(encoding="utf-8-sig")
                # Canonical tasks may put a human-readable title/status above metadata.
                match = re.search(r"^```json\s*\n(.*?)\n```", raw, re.S | re.M)
                if not match:
                    continue  # Legacy unstructured tasks are never eligible.
                meta = json.loads(match[1])
                task_id = meta.get("task_id")
                if task_id not in self.config["task_ids"]:
                    continue
                if task_id in result:
                    raise ControlError(f"DUPLICATE_TASK_ID: {task_id}")
                required = ["schema_version", "revision", "status", "assignee", "priority",
                            "dependencies", "files_allowed", "files_forbidden", "report_folder"]
                if any(k not in meta for k in required) or meta["schema_version"] != "2.1.2":
                    raise ControlError(f"INVALID_TASK_METADATA: {task_id}")
                if not isinstance(meta["revision"], int) or isinstance(meta["revision"], bool) or meta["revision"] < 1:
                    raise ControlError(f"INVALID_TASK_REVISION: {task_id}")
                for field in ["dependencies", "files_allowed", "files_forbidden"]:
                    if not isinstance(meta[field], list):
                        raise ControlError(f"INVALID_TASK_LIST: {task_id}:{field}")
                report = self.inside(meta["report_folder"])
                if not report.is_relative_to(self.report_root):
                    raise ControlError(f"INVALID_REPORT_FOLDER: {task_id}")
                meta["_task_sha"] = file_sha(path)
                meta["_path"] = str(path.relative_to(self.root)).replace("\\", "/")
                result[task_id] = meta
            except (ValueError, AttributeError) as exc:
                raise ControlError(f"INVALID_TASK_JSON: {path}") from exc
        return result

    def end_requested(self):
        """Only an explicit TRUE directive ends the campaign; empty flags are harmless."""
        flag = self.home / "END_AGENT_SESSION.flag"
        if not flag.is_file():
            return False
        text = flag.read_text(encoding="utf-8-sig").strip()
        if text.upper() == "TRUE" or re.fullmatch(r"END_AGENT_SESSION\s*=\s*TRUE", text, re.I):
            return True
        try:
            return json.loads(text) is True
        except ValueError:
            return False

    def source_snapshot(self):
        """Read only immediate *.so files inside exact configured input roots.

        Missing input is a blocker, never evidence that the input count is zero.
        Whitelist membership permits reading these artifacts, not modifying them.
        """
        sources, findings = {}, []
        for root in self.source_roots:
            if not root.is_dir():
                findings.append(f"SOURCE_ROOT_MISSING: {root}")
                continue
            paths = sorted(root.glob("*.so"))
            if not paths:
                findings.append(f"SOURCE_ROOT_NO_SO_FILES: {root}")
            for path in paths:
                if path.is_symlink() or not path.resolve().is_relative_to(root) or not path.is_file():
                    findings.append(f"SOURCE_INPUT_LINK_OR_NOT_FILE: {path}")
                    continue
                try:
                    sources[path.as_posix()] = {"sha256": file_sha(path), "bytes": path.stat().st_size}
                except (ControlError, OSError) as exc:
                    findings.append(str(exc))
        return {"files": sources, "findings": findings}

    def report_snapshot(self, meta, sources=None):
        sources = self.source_snapshot() if sources is None else sources
        report = self.inside(meta["report_folder"])
        files, progress = {}, {}
        findings = list(sources["findings"])
        if report.exists():
            for path in sorted(report.rglob("*")):
                if path.is_symlink() or not path.resolve().is_relative_to(report):
                    raise ControlError(f"REPORT_LINK_FORBIDDEN: {path}")
                if path.is_file():
                    relative = path.relative_to(report).as_posix()
                    target = progress if relative in PROGRESS else files
                    target[relative] = file_sha(path)
        manifests = [n for n in ["COMPLETE.json", "FREEZE.json"] if n in files]
        valid = bool(manifests)
        code_files = {}
        if len(manifests) != 1:
            findings.append("MISSING_OR_AMBIGUOUS_FINAL_MANIFEST")
            valid = False
        else:
            try:
                manifest = self.read_json(report / manifests[0])
                expected_status = "COMPLETE" if manifests[0] == "COMPLETE.json" else "FREEZE"
                if (manifest.get("task_id") != meta["task_id"] or
                        manifest.get("revision") != meta["revision"] or
                        manifest.get("status") != expected_status or
                        manifest.get("schema_version", "2.1.2") != "2.1.2"):
                    raise ControlError("FINAL_MANIFEST_ID_REVISION_STATUS_MISMATCH")
                standard_sha = file_sha(self.root / STANDARD)
                if manifest.get("standard_sha256", "").lower() != standard_sha:
                    raise ControlError("FINAL_MANIFEST_STANDARD_MISMATCH")
                declared = manifest.get("files")
                if not isinstance(declared, dict) or not declared:
                    raise ControlError("FINAL_MANIFEST_FILES_REQUIRED")
                actual = {k: v for k, v in files.items() if k not in manifests}
                if set(declared) != set(actual):
                    raise ControlError("FINAL_MANIFEST_INCOMPLETE_OR_EXTRA_FILES")
                if any(not isinstance(v, str) or v.lower() != actual[k] for k, v in declared.items()):
                    raise ControlError("FINAL_MANIFEST_SHA_MISMATCH")
                audit = report / "00_AUDIT_INDEX.md"
                if not audit.is_file():
                    raise ControlError("AUDIT_INDEX_REQUIRED")
                audit_text = audit.read_text(encoding="utf-8-sig")
                if standard_sha not in audit_text.lower() or STANDARD not in audit_text:
                    raise ControlError("AUDIT_STANDARD_READ_RECEIPT_MISSING")
                listed = manifest.get("code_files")
                if not isinstance(listed, (list, dict)):
                    raise ControlError("CODE_FILES_LIST_REQUIRED")
                for relative in listed:
                    p = self.inside(relative)
                    if not p.is_file():
                        raise ControlError(f"CODE_FILE_MISSING: {relative}")
                    code_files[relative] = file_sha(p)
                    if isinstance(listed, dict) and listed[relative].lower() != code_files[relative]:
                        raise ControlError(f"CODE_FILE_SHA_MISMATCH: {relative}")
                # Include each generator script even if the manifest omitted it.
                for pattern in meta["files_allowed"]:
                    if pattern.replace("\\", "/").startswith("scripts/"):
                        expanded = pattern + "/*" if pattern.endswith("/**") else pattern
                        for p in sorted(self.root.glob(expanded)):
                            if p.is_file():
                                code_files[p.relative_to(self.root).as_posix()] = file_sha(p)
                for relative in meta.get("source_files", []):
                    code_files[relative] = file_sha(self.inside(relative))
            except (ControlError, OSError, ValueError, AttributeError, TypeError) as exc:
                findings.append(str(exc))
                valid = False
        valid = valid and not sources["findings"]
        snapshot = {"task_sha": meta["_task_sha"], "report_files": files, "code_files": code_files,
                    "standard_sha256": file_sha(self.root / STANDARD), "source_inputs": sources["files"],
                    "source_findings": sources["findings"]}
        return {"fingerprint": digest(snapshot), "snapshot": snapshot, "progress_fingerprint": digest(progress),
                "progress_present": bool(progress), "manifest_valid": valid, "findings": findings}

    def accepted(self, task_id, state, tasks, required_revision=None, sources=None):
        meta = tasks.get(task_id)
        if meta is None or (required_revision is not None and required_revision != meta["revision"]):
            return False
        previous = state["tasks"].get(task_id, {})
        verdict = previous.get("verdict") or {}
        if verdict.get("disposition") != "ACCEPTED" or verdict.get("revision") != meta["revision"]:
            return False
        # Actual files, not a stale last-scan record, determine dependency freshness.
        current = self.report_snapshot(meta, sources)
        review = self.inside(verdict.get("review_file", ""))
        return (current["manifest_valid"] and verdict.get("fingerprint") == current["fingerprint"]
                and review.is_file() and file_sha(review) == verdict.get("review_sha256"))

    def dependency_failures(self, meta, state, tasks, sources=None):
        failures = []
        for dep in meta["dependencies"]:
            if not isinstance(dep, dict) or not isinstance(dep.get("revision"), int) or not dep.get("task_id"):
                failures.append({"dependency": dep, "reason": "EXPLICIT_REQUIRED_REVISION_MISSING"})
            elif not self.accepted(dep["task_id"], state, tasks, dep["revision"], sources):
                failures.append({"dependency": dep, "reason": "CEO_ACCEPTANCE_MISSING_OR_STALE"})
        return failures

    def scan(self):
        with self.transaction() as (registry, state):
            if self.end_requested():
                state["agent_state"] = "END_AGENT_SESSION"
                return {"agent_state": "END_AGENT_SESSION", "events": []}
            before = len(state["events"])
            tasks = self.tasks()
            sources = self.source_snapshot()
            summaries = {}
            for task_id in self.config["task_ids"]:
                meta = tasks.get(task_id)
                if meta is None:
                    summaries[task_id] = {"status": "PLANNED_DOCUMENT_MISSING"}
                    continue
                if meta["status"] != "ACTIVE":
                    summaries[task_id] = {"status": meta["status"], "revision": meta["revision"]}
                    continue
                current = self.report_snapshot(meta, sources)
                previous = state["tasks"].get(task_id, {})
                unchanged = previous.get("fingerprint") == current["fingerprint"]
                stable_since = previous.get("stable_since", self.clock()) if unchanged else self.clock()
                ready = current["manifest_valid"] and unchanged and self.clock() - stable_since >= 60
                verdict = previous.get("verdict")
                review = self.inside(verdict.get("review_file", "")) if verdict else None
                if verdict and (verdict.get("fingerprint") != current["fingerprint"] or not current["manifest_valid"]
                                or not review.is_file() or file_sha(review) != verdict.get("review_sha256")):
                    self.event(state, "REVIEW_INVALIDATED", task_id, previous_fingerprint=verdict["fingerprint"],
                               fingerprint=current["fingerprint"], revision=meta["revision"])
                    previous.setdefault("verdict_history", []).append(verdict)
                    verdict = None
                dependencies = self.dependency_failures(meta, state, tasks, sources)
                observation = {**current, "revision": meta["revision"], "stable_since": stable_since,
                               "ready_for_review": ready, "dependencies_blocked": dependencies,
                               "verdict": verdict, "verdict_history": previous.get("verdict_history", [])}
                state["tasks"][task_id] = observation
                if current["progress_present"] and current["progress_fingerprint"] != previous.get("progress_fingerprint"):
                    self.event(state, "AGY_PROGRESS_CHANGED", task_id, fingerprint=current["progress_fingerprint"])
                if current["snapshot"]["report_files"] and not unchanged:
                    self.event(state, "REPORT_CHANGED", task_id, fingerprint=current["fingerprint"], findings=current["findings"])
                if ready and not verdict:
                    self.event(state, "REPORT_READY_FOR_CEO_REVIEW", task_id, fingerprint=current["fingerprint"],
                               revision=meta["revision"])
                summaries[task_id] = {"revision": meta["revision"], "ready_for_review": ready,
                                      "fingerprint": current["fingerprint"], "findings": current["findings"],
                                      "dependencies_blocked": dependencies, "verdict": verdict}
            state["last_scan_time"] = iso(self.clock())
            state["agent_state"] = "IDLE_WAIT_FOR_TASK"
            return {"agent_state": state["agent_state"], "tasks": summaries,
                    "source_findings": sources["findings"], "source_file_count": len(sources["files"]),
                    "events": state["events"][before:]}

    def renew(self):
        with self.transaction() as (registry, state):
            lease = self.ceo_lease(registry)
            updated = json.loads(json.dumps(registry))
            target = self.ceo_lease(updated)
            target.update(expiry=iso(self.clock() + 12 * 3600), renewed_at=iso(self.clock()))
            updated["revision"] = registry.get("revision", 0) + 1
            self.replace_json(self.registry, updated, registry)
            registry.clear()
            registry.update(updated)
            self.event(state, "CEO_LEASE_RENEWED", expiry=target["expiry"], fencing_token=lease["fencing_token"])
            return {"lease_id": CEO_LEASE, "expiry": target["expiry"], "fencing_token": target["fencing_token"]}

    def claim(self, task_id, agent_id, standard_sha, dispatch_token=None):
        with self.transaction() as (registry, state):
            if self.end_requested():
                raise ControlError("END_AGENT_SESSION")
            tasks = self.tasks()
            try:
                return self._claim(task_id, agent_id, standard_sha, registry, state, tasks, dispatch_token)
            except ControlError as exc:
                self.event(state, "CLAIM_BLOCKED", task_id, agent_id=agent_id, reason=str(exc))
                state.setdefault("claim_failures", {})[f"{task_id}:{agent_id}"] = {
                    "reason": str(exc), "observed_at": iso(self.clock())}
                # Return persisted failure; raising inside transaction would skip the save.
                return {"status": "BLOCKED", "task_id": task_id, "reason": str(exc)}

    def _claim(self, task_id, agent_id, standard_sha, registry, state, tasks, dispatch_token=None):
        meta = tasks.get(task_id)
        if meta is None or meta["status"] != "ACTIVE":
            raise ControlError("TASK_NOT_ACTIVE_OR_NOT_SELECTED")
        required_sha = file_sha(self.root / STANDARD)
        if standard_sha.lower() != required_sha:
            raise ControlError("STANDARD_ACK_SHA_MISMATCH")
        assignee = meta["assignee"]
        allowed_ids = self.config.get("worker_ids", []) + [self.config.get("agy_agent_id")]
        assigned = assignee == agent_id or meta.get("agent_id") == agent_id
        if assignee == "AGY_LEAD":
            assigned = agent_id == meta.get("agent_id", self.config.get("agy_agent_id"))
        elif assignee in ["AGY", "AGY_TEAM"]:
            assigned = agent_id in allowed_ids
        if not assigned:
            raise ControlError("TASK_ASSIGNEE_MISMATCH")
        binding = self.config.get("claim_bindings", {}).get(agent_id)
        if meta.get("claim_binding_required") and not binding:
            raise ControlError("CEO_DISPATCH_BINDING_MISSING")
        if binding:
            if binding.get("task_id") != task_id or binding.get("revision") != meta["revision"]:
                raise ControlError("CEO_DISPATCH_BINDING_STALE")
            supplied = hashlib.sha256((dispatch_token or "").encode("utf-8")).hexdigest()
            if not dispatch_token or not hmac.compare_digest(supplied, binding.get("token_sha256", "")):
                raise ControlError("CEO_DISPATCH_BINDING_REQUIRED")
        if self.accepted(task_id, state, tasks):
            raise ControlError("TASK_ALREADY_CEO_ACCEPTED")
        if self.dependency_failures(meta, state, tasks):
            raise ControlError("DEPENDENCIES_NOT_CEO_ACCEPTED")
        scopes = [self.scope(x) for x in meta["files_allowed"]]
        if not scopes:
            raise ControlError("EMPTY_WORKER_SCOPE")
        forbidden = FROZEN + meta["files_forbidden"]
        if meta.get("mode") in ["RESEARCH", "READ_ONLY_AUDIT", "DIAGNOSTIC", "REVIEW"]:
            forbidden += PRODUCTION
        if any(conflict(s, self.scope(f)) for s in scopes for f in forbidden):
            raise ControlError("FORBIDDEN_OR_FROZEN_WORKER_SCOPE")
        key = f"{task_id}:r{meta['revision']}"
        existing = state["claims"].get(key)
        if existing and existing.get("status") == "REVOKED":
            raise ControlError("REVOKED_CLAIM_REQUIRES_CEO_HANDOFF")
        if existing and existing.get("agent_id") != agent_id:
            raise ControlError("CLAIM_OWNED_BY_OTHER_AGENT_REQUIRES_CEO_HANDOFF")
        if existing and existing.get("task_sha") != meta["_task_sha"]:
            raise ControlError("TASK_CHANGED_WITHOUT_REVISION_REQUIRES_CEO_HANDOFF")
        lease_id = existing["lease_id"] if existing else f"LEASE-CEO-WORKER-{task_id}-R{meta['revision']}"
        matches = [x for x in registry.get("active_locks", []) if x.get("lease_id") == lease_id]
        if matches and any(x.get("status") == "REVOKED" for x in matches):
            raise ControlError("REVOKED_LEASE_REQUIRES_CEO_HANDOFF")
        if matches and (len(matches) != 1 or not existing or matches[0].get("agent_id") != agent_id or
                        matches[0].get("fencing_token") != existing.get("fencing_token")):
            raise ControlError("WORKER_LEASE_IDENTITY_OR_FENCE_MISMATCH")
        active_workers = [c for k, c in state["claims"].items() if k != key and c.get("expiry", 0) > self.clock()]
        if len(active_workers) >= int(self.config.get("concurrency_limit", 3)):
            raise ControlError("CONCURRENCY_LIMIT")
        for other in registry.get("active_locks", []):
            if other.get("lease_id") == lease_id or not self.lease_live(other):
                continue
            if any(conflict(a, self.scope(b)) for a in scopes for b in other.get("files_allowed", [])):
                raise ControlError(f"WORKER_SCOPE_CONFLICT: {other['lease_id']}")
        updated = json.loads(json.dumps(registry))
        fencing = existing["fencing_token"] if existing else max(
            [int(x.get("fencing_token", 0)) for x in updated.get("active_locks", [])] + [0]) + 1
        expiry = self.clock() + 2 * 3600
        lease = {"lease_id": lease_id, "agent_id": agent_id, "task_id": task_id,
                 "task_revision": meta["revision"], "task_sha": meta["_task_sha"], "fencing_token": fencing,
                 "files_allowed": meta["files_allowed"], "files_forbidden": forbidden, "status": "ACTIVE",
                 "acquired_at": matches[0]["acquired_at"] if matches else iso(self.clock()),
                 "renewed_at": iso(self.clock()), "expiry": iso(expiry), "standard_sha256": required_sha}
        if matches:
            updated["active_locks"][registry["active_locks"].index(matches[0])] = lease
        else:
            updated.setdefault("active_locks", []).append(lease)
        updated["revision"] = registry.get("revision", 0) + 1
        self.replace_json(self.registry, updated, registry)
        registry.clear()
        registry.update(updated)
        claim = {"task_id": task_id, "revision": meta["revision"], "agent_id": agent_id,
                 "lease_id": lease_id, "fencing_token": fencing, "task_sha": meta["_task_sha"],
                 "dispatch_binding_verified": bool(binding),
                 "expiry": expiry, "standard_read_ack": {"path": str(self.root / STANDARD),
                    "sha256": required_sha, "acknowledged_at": iso(self.clock()),
                    "meaning": "Agent assertion of reading; hash verification is not proof of reading"}}
        state["claims"][key] = claim
        self.event(state, "WORKER_CLAIMED" if not existing else "WORKER_CLAIM_RENEWED", task_id,
                   agent_id=agent_id, revision=meta["revision"], fencing_token=fencing)
        return {"status": "CLAIMED", **claim}

    def ack_review(self, task_id, fingerprint, disposition, review_file):
        if disposition not in ["ACCEPTED", "NEEDS_FIX", "BLOCKED_INPUT"]:
            raise ControlError("INVALID_REVIEW_DISPOSITION")
        with self.transaction() as (registry, state):
            if self.end_requested():
                raise ControlError("END_AGENT_SESSION")
            tasks = self.tasks()
            meta = tasks.get(task_id)
            previous = state["tasks"].get(task_id, {})
            if meta is None or meta["status"] != "ACTIVE":
                raise ControlError("TASK_NOT_ACTIVE")
            current = self.report_snapshot(meta)
            if fingerprint != current["fingerprint"] or previous.get("fingerprint") != fingerprint:
                raise ControlError("STALE_REVIEW_SNAPSHOT")
            if not previous.get("ready_for_review") or not current["manifest_valid"]:
                raise ControlError("REPORT_NOT_READY_FOR_REVIEW")
            if disposition == "ACCEPTED" and self.dependency_failures(meta, state, tasks):
                raise ControlError("DEPENDENCIES_NOT_CEO_ACCEPTED")
            path = self.inside(review_file)
            reviews = self.home / "reviews"
            if not path.is_relative_to(reviews) or not path.is_file() or not path.read_text(encoding="utf-8-sig").strip():
                raise ControlError("NONEMPTY_CEO_REVIEW_FILE_REQUIRED")
            verdict = {"disposition": disposition, "revision": meta["revision"], "fingerprint": fingerprint,
                       "review_file": path.relative_to(self.root).as_posix(), "review_sha256": file_sha(path),
                       "reviewed_by": self.config.get("ceo_agent_id", "Codex_CEO"),
                       "reviewed_at": iso(self.clock()), "fencing_token": self.ceo_lease(registry)["fencing_token"]}
            previous["verdict"] = verdict
            self.event(state, "CEO_REVIEW_ACKNOWLEDGED", task_id, **verdict)
            return verdict

    def status(self):
        lease = self.ceo_lease(self.read_json(self.registry))
        state = self.read_json(self.state_path) if self.state_path.exists() else {"agent_state": "BOOTING"}
        return {"ceo_lease_expiry": lease["expiry"], "end_agent_session": self.end_requested(),
                "state": state, "note": "Stored observations; run scan before making current decisions."}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", default=str(Path(__file__).resolve().parents[2]))
    commands = parser.add_subparsers(dest="command", required=True)
    for name in ["scan", "status", "renew"]:
        commands.add_parser(name)
    claim = commands.add_parser("claim")
    claim.add_argument("--task-id", required=True)
    claim.add_argument("--agent-id", required=True)
    claim.add_argument("--standard-sha", required=True)
    claim.add_argument("--dispatch-token", help="CEO-delivered binding for workers that require it; never stored in results")
    ack = commands.add_parser("ack-review")
    ack.add_argument("--task-id", required=True)
    ack.add_argument("--fingerprint", required=True)
    ack.add_argument("--disposition", required=True, choices=["ACCEPTED", "NEEDS_FIX", "BLOCKED_INPUT"])
    ack.add_argument("--review-file", required=True)
    args = parser.parse_args(argv)
    try:
        c = Controller(args.root)
        if args.command == "claim":
            result = c.claim(args.task_id, args.agent_id, args.standard_sha, args.dispatch_token)
        elif args.command == "ack-review":
            result = c.ack_review(args.task_id, args.fingerprint, args.disposition, args.review_file)
        else:
            result = getattr(c, args.command)()
        print(json.dumps(result, ensure_ascii=False, indent=2))
        return 2 if result.get("status") == "BLOCKED" else 0
    except (ControlError, OSError) as exc:
        print(json.dumps({"error": str(exc)}, ensure_ascii=False))
        return 2


if __name__ == "__main__":
    sys.exit(main())

"""SOl 6.1 local audit queue. It records evidence revisions, never accepts AGY work.

Only a human/agent-authored review body can publish an opinion. Repository task,
report, and product files are read-only inputs. Run with Python's -B option.
"""
from __future__ import annotations

import argparse
import contextlib
import datetime as dt
import fnmatch
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import uuid
import xml.etree.ElementTree as ET
import zipfile

STANDARD_NAME = "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
LEASE_ID = "LEASE-SOL61_AUDIT-20261006"
OWNER = "SOl_6.1"
TASK_RE = re.compile(r"TASK_(\d+)([A-Z]?)(?=[_\W]|$)", re.I)
VERDICTS = {"NEEDS_FIX", "OBSERVED", "RESEARCH_PENDING", "AWAITING_CEO_AUDIT"}
SKIP = ("LEGACY_", "SUPERSEDED_", "ARCHIVED_")
TEXT_SUFFIXES = {".md", ".txt", ".py", ".ps1", ".yml", ".yaml", ".cpp", ".h", ".kt", ".java", ".c"}


class AuditError(RuntimeError):
    pass


class BusyError(AuditError):
    pass


def digest(data):
    if not isinstance(data, bytes):
        data = json.dumps(data, ensure_ascii=False, sort_keys=True, separators=(",", ":")).encode()
    return hashlib.sha256(data).hexdigest()


def iso(value):
    return value.astimezone(dt.timezone.utc).isoformat()


def timestamp(value):
    return dt.datetime.fromisoformat(value.replace("Z", "+00:00"))


class FileLock:
    """Kernel lock: automatically released on process death; never waits."""
    def __init__(self, path):
        self.path = Path(path)
        self.stream = None

    def __enter__(self):
        self.path.parent.mkdir(parents=True, exist_ok=True)
        self.stream = self.path.open("a+b")
        if self.path.stat().st_size == 0:
            self.stream.write(b"\0")
            self.stream.flush()
        self.stream.seek(0)
        try:
            if os.name == "nt":
                import msvcrt
                msvcrt.locking(self.stream.fileno(), msvcrt.LK_NBLCK, 1)
            else:
                import fcntl
                fcntl.flock(self.stream, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except OSError as exc:
            self.stream.close()
            self.stream = None
            raise BusyError(f"Audit already running: {self.path}") from exc
        return self

    def __exit__(self, *args):
        if self.stream is not None:
            if os.name == "nt":
                import msvcrt
                self.stream.seek(0)
                msvcrt.locking(self.stream.fileno(), msvcrt.LK_UNLCK, 1)
            else:
                import fcntl
                fcntl.flock(self.stream, fcntl.LOCK_UN)
            self.stream.close()
            self.stream = None


def atomic_json(path, value, authorize=None):
    path = Path(path)
    temp = path.parent / ".sol61" / ("state-" + uuid.uuid4().hex + ".tmp")
    if authorize is not None:
        authorize((path, temp))
    temp.parent.mkdir(parents=True, exist_ok=True)
    with temp.open("x", encoding="utf-8", newline="\n") as stream:
        json.dump(value, stream, ensure_ascii=False, indent=2, sort_keys=True)
        stream.write("\n")
        stream.flush()
        os.fsync(stream.fileno())
    if authorize is not None:
        authorize((path, temp))
    os.replace(temp, path)


def task_id(text):
    match = TASK_RE.search(text)
    return "TASK_" + match.group(1).zfill(3) + match.group(2).upper() if match else None


def document_text(path):
    if path.suffix.lower() == ".docx":
        with zipfile.ZipFile(path) as archive:
            tree = ET.fromstring(archive.read("word/document.xml"))
        ns = {"w": "http://schemas.openxmlformats.org/wordprocessingml/2006/main"}
        return "\n".join("".join(node.itertext()) for node in tree.findall(".//w:p", ns))
    return path.read_text(encoding="utf-8-sig", errors="replace")


def normalize_text(text):
    return re.sub(r"\s+", " ", text.replace("\ufeff", "")).strip()


def ignored(path):
    return any(part.upper().startswith(SKIP) for part in path.parts)


class Monitor:
    def __init__(self, root, now=None, standard_sha=STANDARD_SHA, schedule_home=None):
        self.root = Path(root).resolve()
        self.directory = self.root / "RULES/Y-KIEN"
        self.state_path = self.directory / ".sol61-audit-state.json"
        self.audit_lock = self.directory / ".sol61-audit.lock"
        self.now = now or (lambda: dt.datetime.now(dt.timezone.utc))
        self.standard_sha = standard_sha.lower()
        self.schedule_home = Path(schedule_home) if schedule_home is not None else Path.home() / ".paseo/schedules"

    def _time(self):
        now = self.now()
        if now.tzinfo is None:
            raise AuditError("Audit timestamp must include timezone")
        return now

    def _standard(self):
        path = self.root / STANDARD_NAME
        data = path.read_bytes()  # mandatory full read, not just stat metadata
        actual = digest(data)
        if actual != self.standard_sha:
            raise AuditError(f"Canonical workspace standard hash mismatch: {actual}")
        return {"path": str(path), "sha256": actual, "read_at": iso(self._time())}

    def _state(self):
        if self.state_path.exists():
            state = json.loads(self.state_path.read_text(encoding="utf-8-sig"))
            if state.get("schema_version") != 1:
                raise AuditError("Unsupported state schema; preserve state for independent review")
            return state
        return {"schema_version": 1, "observed": {}, "pending": {}, "reviewed": {},
                "next_number": 1, "schedule": None, "publishing": None}

    def _save(self, state):
        self._check_fence(state)
        atomic_json(self.state_path, state, authorize=lambda paths: self._check_fence(state, paths))

    def _lease(self):
        """Read a healthy lease; renew only when five minutes or less remain.

        Registry writers must honor locks.registry.guard for serialization.
        Byte comparisons detect non-cooperative writes outside the small CAS gap;
        no Python atomic replace can guarantee CAS against arbitrary raw writers.
        """
        locks_path = self.root / ".ai/locks.json"
        if not locks_path.exists():
            raise AuditError("Canonical .ai/locks.json is required")
        initial = json.loads(locks_path.read_text(encoding="utf-8-sig"))
        current = next((entry for entry in initial.get("active_locks", []) if entry.get("lease_id") == LEASE_ID), None)
        if current is not None and current.get("agent_id") != OWNER:
            raise AuditError("Reviewer lease belongs to another owner")
        if (current is not None and current.get("status") == "ACTIVE"
                and timestamp(current.get("expiry", "1970-01-01T00:00:00+00:00")) > self._time() + dt.timedelta(minutes=5)):
            self.fencing_token = current["fencing_token"]
            self._check_fence({}, (self.audit_lock, self.state_path))
            return
        if current is not None:
            for relative in (".ai/locks.registry.guard", ".ai/locks.sol61.guard"):
                if (not any(fnmatch.fnmatch(relative, pattern.replace("\\", "/")) for pattern in current.get("files_allowed", []))
                        or any(fnmatch.fnmatch(relative, pattern.replace("\\", "/")) for pattern in current.get("files_forbidden", []))):
                    raise AuditError(f"Reviewer lease does not allow registry guard: {relative}")
        with FileLock(self.root / ".ai/locks.registry.guard"), FileLock(self.root / ".ai/locks.sol61.guard"):
            original_bytes = locks_path.read_bytes()
            record = json.loads(original_bytes.decode("utf-8-sig"))
            entries = record.get("active_locks")
            if not isinstance(entries, list):
                raise AuditError("Invalid canonical lease registry")
            current = next((entry for entry in entries if entry.get("lease_id") == LEASE_ID), None)
            if current is not None and current.get("agent_id") != OWNER:
                raise AuditError("Reviewer lease belongs to another owner")
            now = self._time()
            for entry in entries:
                if entry is current or entry.get("status") != "ACTIVE":
                    continue
                try:
                    live = timestamp(entry["expiry"]) > now
                except (KeyError, ValueError):
                    raise AuditError("Malformed active lease expiry")
                # Implementation/test workers own only their exact source files.
                if live and any(fnmatch.fnmatch("RULES/Y-KIEN/.sol61-audit-state.json", pattern.replace("\\", "/"))
                                for pattern in entry.get("files_allowed", [])):
                    raise AuditError(f"Conflicting live reviewer lease: {entry.get('lease_id')}")
            if current is None:
                current = {"lease_id": LEASE_ID, "agent_id": OWNER, "role": "Independent reviewer tooling",
                           "phase": "SOL61_AUDIT", "files_allowed": ["RULES/Y-KIEN/SOl 6.1 _*.md",
                           "RULES/Y-KIEN/.sol61-audit-state.json", "RULES/Y-KIEN/.sol61-audit.lock",
                           "RULES/Y-KIEN/.sol61/**", ".ai/locks.json", ".ai/locks.sol61.guard", ".ai/locks.registry.guard"],
                           "files_forbidden": ["app/**", "lib-*/**", "RULES/TASK/**", "RULES/REPORT/**"]}
                entries.append(current)
            transient_scope = ".ai/locks.sol61.*.tmp"
            if transient_scope not in current.get("files_allowed", []):
                current.setdefault("files_allowed", []).append(transient_scope)
            required = ("RULES/Y-KIEN/.sol61-audit-state.json",
                        "RULES/Y-KIEN/.sol61-audit.lock", "RULES/Y-KIEN/.sol61/publish-check.tmp",
                        ".ai/locks.json", ".ai/locks.sol61.guard", ".ai/locks.registry.guard", ".ai/locks.sol61.check.tmp")
            for relative in required:
                if (not any(fnmatch.fnmatch(relative, pattern.replace("\\", "/")) for pattern in current.get("files_allowed", []))
                        or any(fnmatch.fnmatch(relative, pattern.replace("\\", "/")) for pattern in current.get("files_forbidden", []))):
                    raise AuditError(f"Reviewer lease does not allow required path: {relative}")
            if current.get("status") != "ACTIVE" or timestamp(current.get("expiry", "1970-01-01T00:00:00+00:00")) <= now:
                current["fencing_token"] = max([entry.get("fencing_token", 0) for entry in entries] + [0]) + 1
                current["acquired_at"] = iso(now)
            current["status"] = "ACTIVE"
            current["expiry"] = iso(now + dt.timedelta(minutes=30))
            current["renewed_at"] = iso(now)
            self._commit_lease_registry(locks_path, original_bytes, record)
            self.fencing_token = current["fencing_token"]

    def _commit_lease_registry(self, locks_path, original_bytes, record):
        """Called only with common/private registry guards held; fail on races."""
        temp = locks_path.parent / ("locks.sol61." + uuid.uuid4().hex + ".tmp")
        payload = (json.dumps(record, ensure_ascii=False, indent=2) + "\n").encode("utf-8")
        try:
            with temp.open("xb") as stream:
                stream.write(payload)
                stream.flush()
                os.fsync(stream.fileno())
            if locks_path.read_bytes() != original_bytes:
                raise AuditError("Canonical lease registry changed concurrently; renewal aborted")
            os.replace(temp, locks_path)
            if locks_path.read_bytes() != payload:
                raise AuditError("Canonical lease registry changed after renewal; refusing audit writes")
        finally:
            if temp.exists():
                temp.unlink()

    def _check_fence(self, state, paths=None):
        record = json.loads((self.root / ".ai/locks.json").read_text(encoding="utf-8-sig"))
        entry = next((entry for entry in record.get("active_locks", []) if entry.get("lease_id") == LEASE_ID), {})
        if (entry.get("agent_id") != OWNER or entry.get("status") != "ACTIVE"
                or entry.get("fencing_token") != self.fencing_token
                or timestamp(entry.get("expiry", "1970-01-01T00:00:00+00:00")) <= self._time()):
            raise AuditError("Reviewer lease lost or expired; refusing output publication")
        relative_paths = []
        for path in paths or (self.state_path,):
            path = Path(path).resolve()
            if not path.is_relative_to(self.root):
                raise AuditError(f"Output path outside reviewer workspace: {path}")
            relative_paths.append(path.relative_to(self.root).as_posix())
        for relative in relative_paths:
            if (not any(fnmatch.fnmatch(relative, pattern.replace("\\", "/")) for pattern in entry.get("files_allowed", []))
                    or any(fnmatch.fnmatch(relative, pattern.replace("\\", "/")) for pattern in entry.get("files_forbidden", []))):
                raise AuditError(f"Reviewer lease does not allow selected output: {relative}")
            for other in record.get("active_locks", []):
                if other is entry or other.get("status") != "ACTIVE":
                    continue
                try:
                    live = timestamp(other["expiry"]) > self._time()
                except (KeyError, ValueError):
                    raise AuditError("Malformed active lease expiry")
                if live and any(fnmatch.fnmatch(relative, pattern.replace("\\", "/"))
                                for pattern in other.get("files_allowed", [])):
                    raise AuditError(f"Selected output owned by live lease {other.get('lease_id')}: {relative}")
        state["fencing_token"] = self.fencing_token

    @contextlib.contextmanager
    def _transaction(self):
        self._standard()
        self._lease()
        with FileLock(self.audit_lock):
            state = self._state()
            self._recover(state)
            yield state

    def _files(self, directory):
        result = {}
        if not directory.exists():
            return result
        for path in sorted(directory.rglob("*")):
            if not path.is_file() or ignored(path.relative_to(directory)) or path.name.endswith((".tmp", ".part")):
                continue
            if path.is_symlink():
                raise AuditError(f"Symlink input not permitted: {path}")
            before = path.stat()
            value = digest(path.read_bytes())
            after = path.stat()
            if (before.st_size, before.st_mtime_ns) != (after.st_size, after.st_mtime_ns):
                raise AuditError(f"Input changed while reading: {path}")
            result[path.relative_to(self.root).as_posix()] = value
        return result

    def _tasks(self):
        tasks = {}
        directory = self.root / "RULES/TASK"
        if not directory.exists():
            return tasks
        for path in sorted(directory.rglob("*")):
            if not path.is_file() or ignored(path.relative_to(directory)) or path.suffix.lower() not in {".md", ".docx"}:
                continue
            identifier = task_id(path.name)
            if not identifier:
                continue
            before = path.stat()
            text = document_text(path)
            raw_hash = digest(path.read_bytes())
            after = path.stat()
            if (before.st_size, before.st_mtime_ns) != (after.st_size, after.st_mtime_ns):
                raise AuditError(f"Task changed while reading: {path}")
            statuses = re.findall(r"^\s*(?:#+\s*)?STATUS\s*:\s*([A-Z_]+)\s*$", text, re.M | re.I)
            status = statuses[0].upper() if len(set(value.upper() for value in statuses)) == 1 else "UNKNOWN"
            supersedes = re.findall(r"^\s*SUPERSEDES\s*:\s*(.*)$", text, re.M | re.I)
            item = tasks.setdefault(identifier, {"documents": {}, "statuses": [], "texts": [], "supersedes": []})
            item["documents"][path.relative_to(self.root).as_posix()] = {"sha256": raw_hash,
                "normalized_text_sha256": digest(normalize_text(text).encode()), "status": status}
            item["statuses"].append(status)
            item["texts"].append(text)
            item["supersedes"].extend(task_id(match.group(0)) for line in supersedes for match in TASK_RE.finditer(line))
        for identifier, item in tasks.items():
            statuses = set(item.pop("statuses"))
            text_hashes = {document["normalized_text_sha256"] for document in item["documents"].values()}
            item["status"] = next(iter(statuses)) if len(statuses) == 1 and len(text_hashes) == 1 else "CONFLICT"
        superseded = {identifier for item in tasks.values() if item["status"] == "ACTIVE" for identifier in item["supersedes"]}
        for identifier, item in tasks.items():
            item["superseded"] = identifier in superseded
        return tasks

    def _sources(self, identifier, texts):
        paths = set()
        # Task-specific generators are audited, never executed.
        if identifier and identifier.startswith("TASK_"):
            digits = identifier[5:].lower()
            directory = self.root / "scripts" / ("task" + digits)
            if directory.exists():
                paths.update(path for path in directory.rglob("*") if path.is_file() and path.suffix.lower() in TEXT_SUFFIXES)
        if identifier == "TASK_060":
            paths.update(self.root / name for name in ("scripts/command_bus_orchestrator.py",
                                                       "scripts/run_agent_from_github_command.ps1"))
            for pattern in (".github/workflows/*convert2*.yml", "scripts/*runner*.ps1", "scripts/*scanner*.py"):
                paths.update(self.root.glob(pattern))
        if identifier == "TASK_061":
            for name in ("scripts/run_ghidra_decompilation.py", "scripts/build_reference_implementation.py"):
                paths.add(self.root / name)
            directory = self.root / "scripts/ghidra_scripts"
            if directory.exists():
                paths.update(path for path in directory.rglob("*") if path.is_file())
            for name in ("ghidra_decompiled", "decoded_shaders", "decoded_spirv"):
                directory = self.root / ".ai/reconstruction/evidence/TASK_061" / name
                if directory.exists():
                    paths.update(path for path in directory.rglob("*") if path.is_file()
                                 and path.suffix.lower() in {".c", ".h", ".glsl", ".fs", ".txt", ".raw", ".spirv", ".json", ".csv"})
        # P0 code is hashed as a boundary; the monitor cannot write it.
        for name in ("lib-core-graphics/src/main/cpp/include/ai/bisenet_face_parser.h",
                     "lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp",
                     "lib-core-graphics/src/main/cpp/src/hair_pipeline_v2.cpp"):
            paths.add(self.root / name)
        for text in texts:
            for match in re.finditer(r"(?:scripts|app|lib-[\w-]+|\.github)/[\w./\\ -]+?\.(?:py|ps1|cpp|h|kt|java|yml|yaml|c)(?=[:\s`'\"),]|$)", text.replace("\\", "/")):
                relative = match.group(0).strip()
                path = (self.root / relative).resolve()
                if path.is_relative_to(self.root):
                    paths.add(path)
        result = {}
        for path in sorted(paths):
            if path.is_file() and path.resolve().is_relative_to(self.root):
                result[path.relative_to(self.root).as_posix()] = self._input_hash(path)
            elif path.is_relative_to(self.root):
                result[path.relative_to(self.root).as_posix()] = "MISSING"
        if identifier == "TASK_061":
            source = self.root.parent / "SOURCE"
            full = source / "input_full"
            result["EXTERNAL:SOURCE/input_full"] = "DIRECTORY_PRESENT" if full.is_dir() else "MISSING"
            if full.is_dir():
                for path in sorted(full.iterdir()):
                    if path.is_file() and path.suffix.lower() in {".apk", ".xapk", ".zip", ".so"}:
                        result["EXTERNAL:SOURCE/input_full/" + path.name] = {"sha256": self._input_hash(path), "size": path.stat().st_size}
            targets = ("libmtImageKit.so", "libmfxkit.so", "libARKernelInterface.so", "libarkernel3.so",
                       "libMTFilterKernel.so", "libLayerFlow.so")
            for directory in (source / "extracted_native_libs", source / "extracted_native_libs_full"):
                for name in targets:
                    path = directory / name
                    result["EXTERNAL:SOURCE/" + directory.name + "/" + name] = (
                        {"sha256": self._input_hash(path), "size": path.stat().st_size} if path.is_file() else "MISSING")
        return result

    def _input_hash(self, path):
        # Reuse a read only within one snapshot. Every scan rehashes final bytes,
        # including edits deliberately preserving timestamps and file length.
        cache = getattr(self, "_snapshot_hash_cache", None)
        key = str(path.resolve())
        if cache is not None and key in cache:
            return cache[key]
        before = path.stat()
        value = digest(path.read_bytes())
        after = path.stat()
        if (before.st_size, before.st_mtime_ns) != (after.st_size, after.st_mtime_ns):
            raise AuditError(f"Source changed while reading: {path}")
        if cache is not None:
            cache[key] = value
        return value

    def _freeze(self, report, files):
        freeze = report / "FREEZE.sha256"
        if not freeze.is_file():
            return False, "No FREEZE.sha256; requires two unchanged scans at least 60 seconds apart"
        expected = {path: value for path, value in files.items() if path != freeze.relative_to(self.root).as_posix()}
        actual = {}
        try:
            for line in freeze.read_text(encoding="utf-8-sig").splitlines():
                if not line.strip() or line.lstrip().startswith("#"):
                    continue
                match = re.fullmatch(r"([a-fA-F0-9]{64})\s+\*?(.+)", line)
                if not match:
                    return False, "Malformed FREEZE.sha256"
                raw = match.group(2).replace("\\", "/")
                path = (report / raw).resolve()
                if not path.is_relative_to(report.resolve()):
                    return False, "Freeze path escapes report directory"
                key = path.relative_to(self.root).as_posix()
                if key in actual:
                    return False, "Duplicate freeze path"
                actual[key] = match.group(1).lower()
            if actual != expected or not actual:
                return False, "Freeze entries do not match all final report bytes"
            return True, "All FREEZE.sha256 entries and coverage verified"
        except (OSError, ValueError):
            return False, "Cannot verify FREEZE.sha256"

    def _snapshot(self):
        self._snapshot_hash_cache = {}
        tasks = self._tasks()
        items = {}
        reports = self.root / "RULES/REPORT"
        report_paths = sorted(path for path in reports.iterdir() if path.is_dir() and not ignored(Path(path.name))) if reports.exists() else []
        represented = set()
        for report in report_paths:
            identifier = task_id(report.name)
            if identifier:
                represented.add(identifier)
            files = self._files(report)
            texts = []
            for path in report.rglob("*.md"):
                if path.stat().st_size <= 2_000_000:
                    texts.append(path.read_text(encoding="utf-8-sig", errors="replace"))
            task = tasks.get(identifier, {})
            source = self._sources(identifier, texts + task.get("texts", []))
            frozen, reason = self._freeze(report, files)
            writing_markers = [path.relative_to(self.root).as_posix() for path in report.rglob("*")
                               if path.is_file() and path.name.lower().endswith((".tmp", ".part", ".partial", ".crdownload"))]
            key = report.relative_to(self.root).as_posix()
            snapshot = {"task": {key: value for key, value in task.items() if key != "texts"}, "report": files,
                        "source": source, "writing_markers": writing_markers}
            items[key] = {"item_key": key, "task_id": identifier or report.name, "report": key,
                "fingerprint": digest(snapshot), "snapshot": snapshot, "freeze_valid": frozen,
                "reason": reason, "task_status": task.get("status", "NO_LOCAL_TASK"),
                "superseded": task.get("superseded", False), "writing_markers": writing_markers}
        for identifier, task in tasks.items():
            if task["status"] not in {"ACTIVE", "CONFLICT"} or task["superseded"]:
                continue
            key = identifier + ":TASK_INTAKE"
            snapshot = {"task": {key: value for key, value in task.items() if key != "texts"},
                        "report": {}, "source": self._sources(identifier, task["texts"])}
            items[key] = {"item_key": key, "task_id": identifier, "report": None,
                "fingerprint": digest(snapshot), "snapshot": snapshot, "freeze_valid": False,
                "reason": "Active task intake; no report yet", "task_status": task["status"], "superseded": False}
        return items

    def _scan(self, state):
        now = self._time()
        items = self._snapshot()
        if "historical_intake_baseline" not in state:
            # Existing historical tasks are observed, never falsely marked reviewed.
            # The latest current task is queued; future tasks and revisions also queue.
            intakes = [item for item in items.values() if item["report"] is None]
            latest = max((item["task_id"] for item in intakes),
                         key=lambda value: (int(TASK_RE.search(value).group(1)), value), default=None)
            state["historical_intake_baseline"] = {item["item_key"]: item["fingerprint"]
                for item in intakes if item["task_id"] != latest}
        pending = {}
        for key, item in items.items():
            fingerprint = item["fingerprint"]
            observed = state["observed"].get(key)
            if not observed or observed["fingerprint"] != fingerprint:
                observed = {"fingerprint": fingerprint, "first_seen": iso(now), "scans": 0}
            observed["scans"] += 1
            observed["last_seen"] = iso(now)
            state["observed"][key] = observed
            stable = item["freeze_valid"] or (observed["scans"] >= 2 and (now - timestamp(observed["first_seen"])).total_seconds() >= 60)
            conflict = item["task_status"] == "CONFLICT"
            writing = bool(item.get("writing_markers"))
            item.update(review_id=digest({"item_key": key, "fingerprint": fingerprint}), stable=stable and not conflict and not writing,
                        status="TASK_CONFLICT" if conflict else "PACKAGE_WRITING" if writing else "READY_FOR_REVIEW" if stable else "WAITING_STABLE")
            baseline = state["historical_intake_baseline"].get(key)
            if baseline == fingerprint:
                observed["status"] = "OBSERVED_UNREVIEWED_HISTORICAL"
                continue
            if baseline is not None:
                del state["historical_intake_baseline"][key]
            if item["review_id"] not in state["reviewed"]:
                pending[item["review_id"]] = item
        state["pending"] = pending
        state["last_scan_at"] = iso(now)
        state["standard"] = self._standard()
        state["agent_state"] = "SCANNING_TASKS" if pending else "IDLE_WAIT_FOR_TASK"
        try:
            state["source_checkout_head"] = subprocess.run(["git", "rev-parse", "HEAD"], cwd=self.root,
                capture_output=True, text=True, check=False).stdout.strip() or None
        except OSError:
            state["source_checkout_head"] = None
        self._heartbeat_health(state)
        return {"last_scan_at": state["last_scan_at"], "candidates": list(pending.values()),
                "reviewed_count": len(state["reviewed"]), "schedule": state.get("schedule"),
                "schedule_health": state.get("schedule_health")}

    def _heartbeat_health(self, state):
        """Inspect only the registered native heartbeat; never expose its prompt.

        Heartbeats may be absent from generic schedule listing APIs. Native run
        status provides delivery evidence; a busy failure does not count as one.
        """
        health = {"source": "native_owned_record", "checked_at": iso(self._time()),
                  "status": "UNKNOWN", "config_valid": False, "successful_runs": 0,
                  "busy_skip_count": 0, "verified": False, "verification_status": "UNVERIFIED", "runs": []}
        schedule = state.get("schedule") or {}
        identifier = schedule.get("id")
        if not isinstance(identifier, str) or not re.fullmatch(
                r"(?:[A-Za-z0-9]{8}|[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12})", identifier):
            health["reason"] = "NO_REGISTERED_SAFE_SCHEDULE_ID"
            state["schedule_health"] = health
            return health
        path = self.schedule_home / (identifier + ".json")
        health["id"] = identifier
        try:
            if path.is_symlink():
                raise AuditError("Native heartbeat record must not be a symlink")
            record = json.loads(path.read_text(encoding="utf-8-sig"))
            if not isinstance(record, dict):
                raise ValueError("Invalid heartbeat record")
            cadence = record.get("cadence") or {}
            target = record.get("target") or {}
            if not isinstance(cadence, dict) or not isinstance(target, dict):
                raise ValueError("Invalid heartbeat metadata")
            health["cadence"] = {key: cadence.get(key) for key in ("type", "expression", "timezone")}
            health["target"] = {key: target.get(key) for key in ("type", "agentId")}
            health["status"] = record.get("status", "UNKNOWN")
            health["last_run_at"] = record.get("lastRunAt")
            health["next_run_at"] = record.get("nextRunAt")
            health["config_valid"] = (record.get("id") == identifier and record.get("status") == "active"
                and cadence.get("type") == "cron" and cadence.get("expression") == "* * * * *"
                and cadence.get("timezone") == "Asia/Bangkok" and target.get("type") == "agent"
                and isinstance(target.get("agentId"), str) and bool(target["agentId"])
                and record.get("expiresAt") is None and record.get("maxRuns") is None)
            runs = record.get("runs") or []
            if not isinstance(runs, list):
                raise ValueError("Invalid heartbeat history")
            for run in runs:
                if not isinstance(run, dict):
                    continue
                status = run.get("status")
                if status not in {"running", "succeeded", "failed"}:
                    continue
                error = run.get("error")
                busy = status == "failed" and isinstance(error, str) and "already has an active run" in error.casefold()
                health["runs"].append({"id": run.get("id"), "status": status,
                    "scheduled_for": run.get("scheduledFor"), "started_at": run.get("startedAt"),
                    "ended_at": run.get("endedAt"), "busy_skip": busy})
                health["successful_runs"] += status == "succeeded"
                health["busy_skip_count"] += busy
            health["verified"] = health["config_valid"] and health["successful_runs"] >= 2
            health["verification_status"] = "VERIFIED" if health["verified"] else "UNVERIFIED"
            health["reason"] = "TWO_NATIVE_DELIVERIES_CONFIRMED" if health["verified"] else "AWAITING_TWO_SUCCESSFUL_DELIVERIES"
        except FileNotFoundError:
            health["reason"] = "NATIVE_RECORD_NOT_FOUND"
        except (OSError, ValueError, AuditError):
            # A scheduler-side partial write must never prevent task/report scans.
            health["reason"] = "NATIVE_RECORD_UNAVAILABLE_OR_INVALID"
        state["schedule_health"] = health
        return health

    def scan(self):
        with self._transaction() as state:
            result = self._scan(state)
            self._save(state)
            return result

    def status(self):
        state = self._state()
        self._heartbeat_health(state)
        return {key: state.get(key) for key in ("schema_version", "last_scan_at", "agent_state", "schedule", "next_number", "publishing")} | {
            "candidates": list(state["pending"].values()), "reviewed_count": len(state["reviewed"]),
            "schedule_health": state.get("schedule_health")}

    def _recover(self, state):
        journal = state.get("publishing")
        if not journal:
            return
        opinion = self.directory / journal["opinion"]
        if opinion.is_file():
            if digest(opinion.read_bytes()) != journal["body_sha256"]:
                raise AuditError("Publish journal target occupied by different bytes; preserve evidence")
            self._finish(state, journal)
            self._save(state)
        else:
            # No final output: inputs must be re-audited on a subsequent publish.
            state["publishing"] = None
            self._save(state)

    def _finish(self, state, journal):
        for review_id, item in journal["items"].items():
            state["reviewed"][review_id] = {"opinion": journal["opinion"], "published_at": journal["published_at"],
                "verdict": journal["verdict"], "snapshot": item["snapshot"], "fingerprint": item["fingerprint"], "item_key": item["item_key"]}
            state["pending"].pop(review_id, None)
        state["next_number"] = max(state["next_number"], journal["number"] + 1)
        state["publishing"] = None

    def _publish_file(self, temp, final):
        if os.name == "nt":
            os.rename(temp, final)  # Windows rename refuses an existing destination.
        else:
            os.link(temp, final)  # POSIX rename would overwrite, link creates exclusively.
            temp.unlink()

    def publish(self, review_ids, body, verdict):
        if verdict not in VERDICTS:
            raise AuditError("An explicit review verdict is required; PASS/ACCEPTED are forbidden")
        if not body.strip() or not review_ids:
            raise AuditError("Publish requires a manually authored body and explicit review IDs")
        with self._transaction() as state:
            self._scan(state)
            items = {}
            for review_id in dict.fromkeys(review_ids):
                item = state["pending"].get(review_id)
                if item is None:
                    raise AuditError(f"Review revision changed or already published: {review_id}")
                if not item["stable"]:
                    raise AuditError(f"Review inputs are not stable: {review_id}")
                items[review_id] = item
            occupied = [int(match.group(1)) for path in self.directory.glob("SOl 6.1 _*.md")
                        if (match := re.fullmatch(r"SOl 6\.1 _(\d+)\.md", path.name))]
            number = max([state["next_number"], 1] + [value + 1 for value in occupied])
            name = f"SOl 6.1 _{number:03d}.md"
            final = self.directory / name
            temp = self.directory / ".sol61" / ("publish-" + uuid.uuid4().hex + ".tmp")
            self._check_fence(state, (final, temp, self.state_path))
            published_at = iso(self._time())
            marker = {"review_ids": list(items), "fingerprints": {key: item["fingerprint"] for key, item in items.items()},
                      "published_at": published_at, "verdict": verdict}
            content = (body.rstrip() + "\n\n<!-- SOL61_REVIEW " + json.dumps(marker, sort_keys=True) + " -->\n").encode("utf-8")
            journal = {"opinion": name, "number": number, "published_at": published_at, "verdict": verdict,
                       "items": items, "body_sha256": digest(content)}
            state["publishing"] = journal
            self._save(state)
            with temp.open("xb") as stream:
                stream.write(content)
                stream.flush()
                os.fsync(stream.fileno())
            self._check_fence(state, (final, temp, self.state_path))
            # A final snapshot fences evidence modifications made during opinion writing.
            current = self._snapshot()
            if any(current.get(item["item_key"], {}).get("fingerprint") != item["fingerprint"] for item in items.values()):
                state["publishing"] = None
                self._save(state)
                temp.unlink()
                raise AuditError("Inputs changed during publication; review the new revision")
            self._check_fence(state, (final, temp, self.state_path))
            self._publish_file(temp, final)
            self._finish(state, journal)
            self._save(state)
            return {"opinion": name, "path": str(self.directory / name), "review_ids": list(items), "verdict": verdict}

    def register_schedule(self, schedule_id):
        if not schedule_id.strip():
            raise AuditError("Schedule ID is required")
        with self._transaction() as state:
            state["schedule"] = {"id": schedule_id, "cron": "* * * * *", "timezone": "Asia/Bangkok", "registered_at": iso(self._time())}
            self._save(state)
            return state["schedule"]


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("command", choices=("scan", "status", "publish", "bootstrap", "register-schedule"))
    parser.add_argument("--root", default=str(Path(__file__).resolve().parents[3]))
    parser.add_argument("--review-id", action="append", default=[])
    parser.add_argument("--body-file")
    parser.add_argument("--verdict", choices=sorted(VERDICTS))
    parser.add_argument("--schedule-id")
    args = parser.parse_args(argv)
    monitor = Monitor(args.root)
    try:
        if args.command == "scan":
            result = monitor.scan()
        elif args.command == "status":
            result = monitor.status()
        elif args.command == "register-schedule":
            result = monitor.register_schedule(args.schedule_id or "")
        else:
            if not args.body_file:
                raise AuditError("--body-file is required")
            result = monitor.publish(args.review_id, Path(args.body_file).read_text(encoding="utf-8-sig"), args.verdict)
        print(json.dumps(result, ensure_ascii=False, indent=2))
        return 0
    except (AuditError, OSError, ValueError, zipfile.BadZipFile) as exc:
        print(json.dumps({"error": str(exc), "status": "BUSY" if isinstance(exc, BusyError) else "NEEDS_ATTENTION"}), file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())

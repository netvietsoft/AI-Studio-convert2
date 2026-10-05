#!/usr/bin/env python3
"""
CONVERT2 Multi-Agent / Multi-Task Command Bus Orchestrator
Authority: Tony
Protocol: CONVERT2_COMMAND_V2
Task ID: TASK_011_MULTI_AGENT_MULTI_TASK_COMMAND_BUS_ORCHESTRATOR_ACTIVE

Provides an immutable, per-task command lifecycle with:
- Strict state machine: PENDING -> QUEUED -> CLAIMED -> RUNNING -> COMPLETED / FAILED
- Concurrency control with module & path-level lock conflict detection
- Dependency DAG evaluation (waiting for upstream completion)
- Atomic claims and lease-based anti-double-execution with stale recovery
- Idempotent anti-duplicate gating based on (task_id, task_revision)
- Multi-lane execution and honest capacity reporting (QUEUED, not RUNNING)
- Per-task durable state (.ai/state/tasks/<task_id>.json) + safe aggregate reconciliation
- Full provenance enforcement (dispatch commit SHA + run_id + target commit SHA + report)
- Backward compatibility and lossless migration for legacy NEXT_COMMAND.json
"""

import os
import sys
import re
import json
import time
import uuid
import fnmatch
import argparse
import datetime
from pathlib import Path
from typing import Dict, List, Optional, Any, Tuple, Set

# Priority mapping
PRIORITY_MAP = {
    "CRITICAL": 100,
    "HIGH": 80,
    "NORMAL": 50,
    "LOW": 20
}

VALID_STATUSES = {
    "PENDING",
    "RESERVED",
    "QUEUED",
    "WAITING_DEPENDENCY",
    "CLAIMED",
    "RUNNING",
    "REPORT_READY",
    "COMPLETED",
    "FAILED",
    "BLOCKED",
    "BLOCKED_BINDING_MISMATCH",
    "BLOCKED_MERGE_CONFLICT",
    "BLOCKED_UNAUTHORIZED_PATH",
    "STALE_RECOVERABLE"
}


import threading

class FileLock:
    """Cross-platform advisory reentrant file lock for atomic command bus mutations."""
    _local = threading.local()

    def __init__(self, lock_file: Path, timeout: float = 15.0):
        self.lock_file = lock_file.resolve()
        self.timeout = timeout

    def __enter__(self):
        locks = getattr(self._local, "locks", None)
        if locks is None:
            locks = {}
            self._local.locks = locks

        key = str(self.lock_file)
        if key in locks:
            locks[key]["count"] += 1
            return self

        start_time = time.time()
        self.lock_file.parent.mkdir(parents=True, exist_ok=True)
        while True:
            try:
                if os.name == 'nt':
                    import msvcrt
                    fd = os.open(str(self.lock_file), os.O_RDWR | os.O_CREAT | getattr(os, 'O_BINARY', 0))
                    if os.path.getsize(str(self.lock_file)) == 0:
                        os.write(fd, b'0')
                    os.lseek(fd, 0, os.SEEK_SET)
                    msvcrt.locking(fd, msvcrt.LK_NBLCK, 1)
                else:
                    import fcntl
                    fd = os.open(str(self.lock_file), os.O_RDWR | os.O_CREAT)
                    fcntl.flock(fd, fcntl.LOCK_EX | fcntl.LOCK_NB)

                locks[key] = {"fd": fd, "count": 1}
                return self
            except (BlockingIOError, OSError, PermissionError):
                if time.time() - start_time > self.timeout:
                    raise TimeoutError(f"Timed out acquiring lock on {self.lock_file} after {self.timeout}s")
                time.sleep(0.05)

    def __exit__(self, exc_type, exc_val, exc_tb):
        locks = getattr(self._local, "locks", {})
        key = str(self.lock_file)
        if key in locks:
            locks[key]["count"] -= 1
            if locks[key]["count"] <= 0:
                fd = locks[key]["fd"]
                try:
                    if os.name == 'nt':
                        import msvcrt
                        try:
                            os.lseek(fd, 0, os.SEEK_SET)
                            msvcrt.locking(fd, msvcrt.LK_UNLCK, 1)
                        except Exception:
                            pass
                    else:
                        import fcntl
                        try:
                            fcntl.flock(fd, fcntl.LOCK_UN)
                        except Exception:
                            pass
                    os.close(fd)
                except Exception:
                    pass
                del locks[key]


def get_iso_now() -> str:
    """Return ISO 8601 current timestamp with timezone."""
    return datetime.datetime.now(datetime.timezone.utc).astimezone().isoformat()


def normalize_path_pattern(pattern: str) -> str:
    """Normalize path slashes and strip leading/trailing slashes."""
    return pattern.replace('\\', '/').strip('/')


SHARED_RECONCILED_PATHS = {
    ".ai/state",
    ".ai/state/*",
    ".ai/state/**",
    ".ai/commands",
    ".ai/commands/*",
    ".ai/commands/**",
    ".ai/runner",
    ".ai/runner/*",
    ".ai/runner/**",
    "project_memory.md",
    "project_error.md",
    "task_log.md"
}


def is_shared_reconciled_path(p: str) -> bool:
    norm = normalize_path_pattern(p).lower()
    if norm in SHARED_RECONCILED_PATHS:
        return True
    if norm.startswith(".ai/state") or norm.startswith(".ai/commands") or norm.startswith(".ai/runner"):
        return True
    if norm in ["task_log.md", "project_memory.md", "project_error.md"]:
        return True
    return False


def paths_conflict(p1: str, p2: str) -> bool:
    """
    Check if two file path patterns conflict (overlap).
    Handles globbing (*, **) and prefix / exact matches.
    Shared integrator-reconciled paths (.ai/state/**, .ai/commands/**, TASK_LOG.md, PROJECT_MEMORY.md)
    do not block concurrency as they are safely serialized and reconciled by the Integrator.
    Disjoint task reports (.ai/reports/TASK_A/** vs .ai/reports/TASK_B/**) do not conflict.
    """
    p1 = normalize_path_pattern(p1)
    p2 = normalize_path_pattern(p2)

    # If both are shared integrator-reconciled metadata paths, no conflict
    if is_shared_reconciled_path(p1) and is_shared_reconciled_path(p2):
        return False

    # Disjoint task-specific report directories do not conflict
    if p1.lower().startswith(".ai/reports/") and p2.lower().startswith(".ai/reports/"):
        parts1 = p1.split('/')
        parts2 = p2.split('/')
        f1 = parts1[2] if len(parts1) > 2 else ""
        f2 = parts2[2] if len(parts2) > 2 else ""
        if f1 and f2 and f1 != f2:
            return False

    if p1 == p2:
        return True

    # Check prefix overlap
    p1_clean = p1.rstrip('/*')
    p2_clean = p2.rstrip('/*')

    if p1_clean == p2_clean:
        return True

    if p1.endswith('/*') or p1.endswith('/**'):
        prefix = p1.split('/*')[0].split('/**')[0]
        if p2 == prefix or p2.startswith(prefix + '/'):
            return True

    if p2.endswith('/*') or p2.endswith('/**'):
        prefix = p2.split('/*')[0].split('/**')[0]
        if p1 == prefix or p1.startswith(prefix + '/'):
            return True

    if fnmatch.fnmatch(p1, p2) or fnmatch.fnmatch(p2, p1):
        return True

    return False


def file_matches_allowed_path(filepath: str, allowed_pattern: str) -> bool:
    """
    Check if a specific file path falls within an allowed path pattern.
    Supports exact path, prefix directory (dir/**, dir/*), and fnmatch wildcards.
    """
    f = normalize_path_pattern(filepath).lower()
    p = normalize_path_pattern(allowed_pattern).lower()

    if f == p:
        return True

    if p.endswith("/**"):
        prefix = p[:-3]
        if f == prefix or f.startswith(prefix + "/"):
            return True

    if p.endswith("/*"):
        prefix = p[:-2]
        if f == prefix or f.startswith(prefix + "/"):
            return True

    return fnmatch.fnmatch(f, p)


class CommandBusOrchestrator:
    """
    Manages the multi-agent / multi-task command lifecycle and dispatch.
    """
    def __init__(self, repo_root: Optional[Path] = None):
        if repo_root is None:
            self.repo_root = Path(__file__).resolve().parent.parent
        else:
            self.repo_root = Path(repo_root).resolve()

        self.bus_dir = self.repo_root / ".ai" / "commands"
        self.pending_dir = self.bus_dir / "pending"
        self.reserved_dir = self.bus_dir / "reserved"
        self.claimed_dir = self.bus_dir / "claimed"
        self.running_dir = self.bus_dir / "running"
        self.completed_dir = self.bus_dir / "completed"
        self.failed_dir = self.bus_dir / "failed"
        self.history_dir = self.bus_dir / "history"
        self.index_file = self.bus_dir / "index.json"
        self.lock_file = self.bus_dir / ".bus.lock"
        self.next_command_file = self.bus_dir / "NEXT_COMMAND.json"

        self.state_dir = self.repo_root / ".ai" / "state"
        self.tasks_state_dir = self.state_dir / "tasks"
        self.global_state_file = self.repo_root / ".ai" / "state.json"
        self.locks_json_file = self.repo_root / ".ai" / "locks.json"

        self._ensure_dirs()

    def _ensure_dirs(self):
        for d in [self.pending_dir, self.reserved_dir, self.claimed_dir, self.running_dir,
                  self.completed_dir, self.failed_dir, self.history_dir,
                  self.tasks_state_dir]:
            d.mkdir(parents=True, exist_ok=True)

    def _load_json(self, path: Path) -> Optional[Dict[str, Any]]:
        if not path.is_file():
            return None
        try:
            with open(path, "r", encoding="utf-8") as f:
                return json.load(f)
        except Exception:
            return None

    def _write_json(self, path: Path, data: Dict[str, Any]):
        path.parent.mkdir(parents=True, exist_ok=True)
        temp_path = path.with_suffix(path.suffix + f".tmp.{uuid.uuid4().hex[:8]}")
        with open(temp_path, "w", encoding="utf-8") as f:
            json.dump(data, f, indent=2, ensure_ascii=False)
        # Atomic rename
        os.replace(str(temp_path), str(path))

    def _unlink_and_git_rm(self, path: Path):
        """Removes a file from disk and stages removal in git if in a git worktree."""
        import subprocess
        try:
            path.unlink(missing_ok=True)
        except Exception:
            pass
        if (self.repo_root / ".git").exists():
            try:
                rel = path.relative_to(self.repo_root)
                subprocess.run(
                    ["git", "rm", "-f", "--ignore-unmatch", str(rel)],
                    cwd=str(self.repo_root),
                    capture_output=True
                )
            except Exception:
                pass

    def _find_command_file(self, command_id: str) -> Optional[Tuple[Path, str]]:
        for status_dir, status_name in [
            (self.completed_dir, "COMPLETED"),
            (self.failed_dir, "FAILED"),
            (self.running_dir, "RUNNING"),
            (self.claimed_dir, "CLAIMED"),
            (self.reserved_dir, "RESERVED"),
            (self.pending_dir, "PENDING"),
        ]:
            target = status_dir / f"{command_id}.json"
            if target.is_file():
                return target, status_name
        return None

    def _get_all_commands(self) -> Dict[str, Dict[str, Any]]:
        """Return dict of command_id -> command dict for all active and completed commands."""
        commands = {}
        for status_dir in [self.pending_dir, self.reserved_dir, self.claimed_dir, self.running_dir, self.completed_dir, self.failed_dir]:
            for p in status_dir.glob("*.json"):
                cmd = self._load_json(p)
                if cmd and "command_id" in cmd:
                    commands[cmd["command_id"]] = cmd
        return commands

    def rebuild_index(self) -> Dict[str, Any]:
        """Rebuilds .ai/commands/index.json from disk state."""
        with FileLock(self.lock_file):
            self._reconcile_uniqueness_internal()
            commands = self._get_all_commands()
            index_data = {
                "version": "2.0.0",
                "updated_at": get_iso_now(),
                "counts": {
                    "pending": len(list(self.pending_dir.glob("*.json"))),
                    "reserved": len(list(self.reserved_dir.glob("*.json"))),
                    "claimed": len(list(self.claimed_dir.glob("*.json"))),
                    "running": len(list(self.running_dir.glob("*.json"))),
                    "completed": len(list(self.completed_dir.glob("*.json"))),
                    "failed": len(list(self.failed_dir.glob("*.json"))),
                },
                "commands": {
                    cid: {
                        "task_id": c.get("task_id"),
                        "task_revision": c.get("task_revision"),
                        "priority": c.get("priority"),
                        "status": c.get("status"),
                        "execution_lane": c.get("execution_lane"),
                        "created_at": c.get("created_at"),
                        "anti_duplicate_key": c.get("anti_duplicate_key")
                    } for cid, c in commands.items()
                }
            }
            self._write_json(self.index_file, index_data)
            return index_data

    def validate_lifecycle_invariants(self) -> Tuple[bool, List[str], Dict[str, Any]]:
        """
        Validates the fundamental command lifecycle invariants:
        1. Single-Directory Invariant: Each command ID must exist in strictly ONE directory among:
           [pending, reserved, claimed, running, completed, failed].
        2. Status Alignment: Internal command status must match directory semantics:
           - pending: PENDING, QUEUED, WAITING_DEPENDENCY
           - reserved: RESERVED
           - claimed: CLAIMED
           - running: RUNNING
           - completed: COMPLETED
           - failed: FAILED, BLOCKED, BLOCKED_*
        """
        with FileLock(self.lock_file):
            valid_statuses = {
                "pending": {"PENDING", "QUEUED", "WAITING_DEPENDENCY", "WAITING_OWNER_VISUAL_APPROVAL", "WAITING_GATE"},
                "reserved": {"RESERVED"},
                "claimed": {"CLAIMED"},
                "running": {"RUNNING"},
                "completed": {"COMPLETED"},
                "failed": {"FAILED", "BLOCKED", "BLOCKED_BINDING_MISMATCH", "BLOCKED_MERGE_CONFLICT", "BLOCKED_UNAUTHORIZED_PATH", "STALE_RECOVERABLE", "BLOCKED_EXTERNAL_AUTH"}
            }

            dir_map = {
                "pending": self.pending_dir,
                "reserved": self.reserved_dir,
                "claimed": self.claimed_dir,
                "running": self.running_dir,
                "completed": self.completed_dir,
                "failed": self.failed_dir,
            }

            command_locations: Dict[str, List[Dict[str, Any]]] = {}
            for d_name, d_path in dir_map.items():
                for p in d_path.glob("*.json"):
                    cmd = self._load_json(p)
                    cid = p.stem
                    if cmd and "command_id" in cmd:
                        cid = cmd["command_id"]
                    if cid not in command_locations:
                        command_locations[cid] = []
                    command_locations[cid].append({
                        "dir": d_name,
                        "path": str(p),
                        "status": cmd.get("status") if cmd else None
                    })

            violations: List[str] = []
            duplicate_commands: Dict[str, List[str]] = {}
            status_mismatches: List[Dict[str, Any]] = []

            for cid, locs in command_locations.items():
                if len(locs) > 1:
                    dirs_found = [loc["dir"] for loc in locs]
                    duplicate_commands[cid] = dirs_found
                    violations.append(
                        f"DUPLICATE_ACROSS_DIRECTORIES: Command '{cid}' exists in multiple directories: {dirs_found}"
                    )
                for loc in locs:
                    d_name = loc["dir"]
                    st = loc["status"]
                    if st and st not in valid_statuses.get(d_name, set()):
                        status_mismatches.append({
                            "command_id": cid,
                            "directory": d_name,
                            "status": st
                        })
                        violations.append(
                            f"STATUS_MISMATCH: Command '{cid}' in directory '{d_name}' has invalid status '{st}'"
                        )

            # Invariant 3: Git index tracking invariant (if in git worktree)
            git_duplicates: Dict[str, List[str]] = {}
            if (self.repo_root / ".git").exists():
                try:
                    import subprocess, collections
                    proc = subprocess.run(
                        ["git", "ls-files", ".ai/commands"],
                        cwd=str(self.repo_root),
                        capture_output=True,
                        text=True
                    )
                    if proc.returncode == 0:
                        dirs = {"pending", "reserved", "claimed", "running", "completed", "failed"}
                        git_map = collections.defaultdict(list)
                        for line in proc.stdout.splitlines():
                            parts = line.replace("\\", "/").split("/")
                            if len(parts) >= 4 and parts[1] == "commands" and parts[2] in dirs and parts[3].endswith(".json"):
                                cid = os.path.splitext(parts[3])[0]
                                git_map[cid].append(parts[2])
                        git_dups = {cid: ds for cid, ds in git_map.items() if len(ds) > 1}
                        if git_dups:
                            git_duplicates = git_dups
                            violations.append(
                                f"GIT_INDEX_DUPLICATE_ACROSS_DIRECTORIES: Commands tracked in multiple directories in Git index: {git_dups}"
                            )
                except Exception:
                    pass

            is_valid = len(violations) == 0
            summary = {
                "is_valid": is_valid,
                "total_unique_commands": len(command_locations),
                "violation_count": len(violations),
                "violations": violations,
                "duplicate_commands": duplicate_commands,
                "git_duplicates": git_duplicates,
                "status_mismatches": status_mismatches
            }
            return is_valid, violations, summary

    def _reconcile_uniqueness_internal(self) -> Dict[str, Any]:
        """
        Internal implementation of single-directory lifecycle enforcement without rebuilding index.
        Applies deterministic precedence:
          completed (100) > failed (90) > running (80) > claimed (70) > reserved (60) > pending (50)
        Deletes losing duplicate files.
        """
        precedence = {
            "completed": 100,
            "failed": 90,
            "running": 80,
            "claimed": 70,
            "reserved": 60,
            "pending": 50
        }

        dir_map = {
            "pending": self.pending_dir,
            "reserved": self.reserved_dir,
            "claimed": self.claimed_dir,
            "running": self.running_dir,
            "completed": self.completed_dir,
            "failed": self.failed_dir,
        }

        command_files: Dict[str, List[Tuple[str, Path, int]]] = {}
        for d_name, d_path in dir_map.items():
            for p in d_path.glob("*.json"):
                cmd = self._load_json(p)
                cid = p.stem
                if cmd and "command_id" in cmd:
                    cid = cmd["command_id"]
                if cid not in command_files:
                    command_files[cid] = []
                command_files[cid].append((d_name, p, precedence.get(d_name, 0)))

        purged = []
        retained = {}

        for cid, locs in command_files.items():
            if len(locs) > 1:
                locs.sort(key=lambda x: -x[2])
                winner_dir, winner_path, _ = locs[0]
                retained[cid] = winner_dir

                for loser_dir, loser_path, _ in locs[1:]:
                    try:
                        self._unlink_and_git_rm(loser_path)
                        purged.append({
                            "command_id": cid,
                            "purged_from": loser_dir,
                            "purged_path": str(loser_path),
                            "retained_in": winner_dir
                        })
                    except Exception as e:
                        print(f"[RECONCILE_WARN] Failed to unlink {loser_path}: {e}")
            else:
                retained[cid] = locs[0][0]

        return {
            "purged_count": len(purged),
            "purged": purged,
            "total_commands": len(retained)
        }

    def reconcile_lifecycle_uniqueness(self) -> Dict[str, Any]:
        """
        Enforces that each command ID exists in strictly ONE directory.
        If duplicates are found across directories, applies deterministic precedence:
          completed (100) > failed (90) > running (80) > claimed (70) > reserved (60) > pending (50)
        Deletes losing duplicate files and reconciles state.
        """
        with FileLock(self.lock_file):
            res = self._reconcile_uniqueness_internal()
            self.rebuild_index()
            return res

    # -------------------------------------------------------------------------
    # Core Command Lifecycle
    # -------------------------------------------------------------------------

    def create_command(self,
                       task_id: str,
                       task_url: str,
                       task_revision: str,
                       issued_for_sha: str,
                       priority: str = "NORMAL",
                       dependencies: Optional[List[str]] = None,
                       execution_lane: str = "default",
                       allowed_paths: Optional[List[str]] = None,
                       locked_modules: Optional[List[str]] = None,
                        command_id: Optional[str] = None,
                        requires_owner_visual_approval: bool = False,
                        gate_requirements: Optional[List[str]] = None) -> Tuple[bool, str, Dict[str, Any]]:
        """
        Creates an immutable pending command.
        Enforces anti-duplicate gating based on (task_id, task_revision).
        """
        with FileLock(self.lock_file):
            priority = priority.upper()
            if priority not in PRIORITY_MAP:
                priority = "NORMAL"

            dependencies = dependencies or []
            allowed_paths = allowed_paths or []
            locked_modules = locked_modules or []
            gate_requirements = gate_requirements or []

            anti_dup_key = f"{task_id}:{task_revision}"

            # Check existing commands for identical anti-duplicate key
            all_cmds = self._get_all_commands()
            for cid, existing in all_cmds.items():
                if existing.get("anti_duplicate_key") == anti_dup_key:
                    st = existing.get("status")
                    if st in ["PENDING", "CLAIMED", "RUNNING", "COMPLETED"]:
                        return False, f"DUPLICATE_REJECTED: Command {cid} already exists with status {st} for {anti_dup_key}", existing

            if not command_id:
                stamp = datetime.datetime.now().strftime("%Y%m%dT%H%M%S")
                short_id = uuid.uuid4().hex[:6].upper()
                command_id = f"CMD_{task_id}_{stamp}_{short_id}"

            cmd_data = {
                "protocol": "CONVERT2_COMMAND_V2",
                "command_id": command_id,
                "task_id": task_id,
                "task_revision": task_revision,
                "task_url": task_url,
                "issued_for_sha": issued_for_sha,
                "priority": priority,
                "priority_weight": PRIORITY_MAP[priority],
                "dependencies": dependencies,
                "execution_lane": execution_lane,
                "allowed_paths": allowed_paths,
                "locked_modules": locked_modules,
                "requires_owner_visual_approval": bool(requires_owner_visual_approval),
                "gate_requirements": gate_requirements,
                "anti_duplicate_key": anti_dup_key,
                "created_at": get_iso_now(),
                "status": "PENDING",
                "retry_count": 0,
                "lease": None,
                "execution_identity": None,
                "provenance": None
            }

            dest = self.pending_dir / f"{command_id}.json"
            self._write_json(dest, cmd_data)

            # Record per-task state
            self._update_task_state(task_id, {
                "task_id": task_id,
                "task_revision": task_revision,
                "command_id": command_id,
                "status": "PENDING",
                "created_at": cmd_data["created_at"],
                "updated_at": get_iso_now(),
                "execution_lane": execution_lane
            })

            self.rebuild_index()
            return True, f"CREATED: {command_id}", cmd_data

    def compute_ready_set(self,
                          lane: Optional[str] = None,
                          lane_capacity: int = 2) -> List[Dict[str, Any]]:
        """
        Calculates the set of commands ready for execution.
        Evaluates:
        1. Upstream dependencies (all must be in COMPLETED status)
        2. Module & Path locks against currently CLAIMED or RUNNING commands
        3. Runner lane capacity (marks QUEUED honestly when capacity is reached)
        """
        with FileLock(self.lock_file):
            all_cmds = self._get_all_commands()

            # Active commands holding locks
            active_cmds = [
                c for c in all_cmds.values()
                if c.get("status") in ["RESERVED", "CLAIMED", "RUNNING"]
            ]

            # Completed tasks for dependency resolution
            completed_task_ids = {
                c.get("task_id") for c in all_cmds.values()
                if c.get("status") == "COMPLETED"
            }
            completed_command_ids = {
                c.get("command_id") for c in all_cmds.values()
                if c.get("status") == "COMPLETED"
            }

            # Pending commands
            pending_cmds = [
                c for c in all_cmds.values()
                if c.get("status") in ["PENDING", "QUEUED", "WAITING_DEPENDENCY", "WAITING_OWNER_VISUAL_APPROVAL", "WAITING_GATE"]
            ]

            # Filter by lane if specified
            if lane:
                pending_cmds = [c for c in pending_cmds if c.get("execution_lane") == lane]

            # Sort pending by priority weight descending, then created_at ascending
            pending_cmds.sort(
                key=lambda x: (-x.get("priority_weight", 50), x.get("created_at", ""))
            )

            ready_list = []
            selected_active = list(active_cmds)
            lane_counts: Dict[str, int] = {}
            for c in active_cmds:
                cl = c.get("execution_lane", "default")
                lane_counts[cl] = lane_counts.get(cl, 0) + 1

            for candidate in pending_cmds:
                cid = candidate["command_id"]
                cand_lane = candidate.get("execution_lane", "default")

                # 1. Dependency Check
                deps = candidate.get("dependencies", [])
                unmet_deps = []
                for d in deps:
                    if d not in completed_task_ids and d not in completed_command_ids:
                        unmet_deps.append(d)

                if unmet_deps:
                    candidate["status"] = "WAITING_DEPENDENCY"
                    candidate["blocked_by_dependencies"] = unmet_deps
                    self._write_json(self.pending_dir / f"{cid}.json", candidate)
                    continue

                # 1.5 Scoped Gate Check
                # Owner visual review is a scoped gate for Hair V2 final sign-off, NOT a global stop.
                gate_reqs = candidate.get("gate_requirements", [])
                requires_owner_visual = (
                    candidate.get("requires_owner_visual_approval", False)
                    or "OWNER_VISUAL_APPROVED" in gate_reqs
                    or "HAIR_V2_FINAL_APPROVAL" in gate_reqs
                    or candidate.get("task_id", "").startswith("TASK_HAIR_V2_FINAL_SIGN_OFF")
                )

                if requires_owner_visual:
                    global_state = self._load_json(self.global_state_file) or {}
                    owner_status = global_state.get("owner_visual_acceptance_status", "PENDING_OWNER_EVALUATION")
                    if owner_status != "APPROVED":
                        candidate["status"] = "WAITING_OWNER_VISUAL_APPROVAL"
                        candidate["queue_reason"] = (
                            f"Scoped Hair V2 Gate: Awaiting Chairman Tony visual evaluation (status: {owner_status})"
                        )
                        self._write_json(self.pending_dir / f"{cid}.json", candidate)
                        continue

                # 2. Lock Conflict Check
                conflict_reason = None
                cand_modules = set(candidate.get("locked_modules", []))
                cand_paths = candidate.get("allowed_paths", [])

                for running in selected_active:
                    # Module conflict
                    running_modules = set(running.get("locked_modules", []))
                    common_modules = cand_modules.intersection(running_modules)
                    if common_modules:
                        conflict_reason = f"Module lock conflict on {sorted(list(common_modules))} with active {running['command_id']}"
                        break

                    # Path conflict
                    running_paths = running.get("allowed_paths", [])
                    overlapping_path = None
                    for cp in cand_paths:
                        for rp in running_paths:
                            if paths_conflict(cp, rp):
                                overlapping_path = (cp, rp)
                                break
                        if overlapping_path:
                            break

                    if overlapping_path:
                        conflict_reason = f"Path lock conflict ({overlapping_path[0]} vs {overlapping_path[1]}) with active {running['command_id']}"
                        break

                if conflict_reason:
                    candidate["status"] = "QUEUED"
                    candidate["queue_reason"] = conflict_reason
                    self._write_json(self.pending_dir / f"{cid}.json", candidate)
                    continue

                # 3. Capacity Check
                current_lane_count = lane_counts.get(cand_lane, 0)
                if current_lane_count >= lane_capacity:
                    candidate["status"] = "QUEUED"
                    candidate["queue_reason"] = f"Runner lane '{cand_lane}' at capacity ({current_lane_count}/{lane_capacity})"
                    self._write_json(self.pending_dir / f"{cid}.json", candidate)
                    continue

                # Eligible!
                candidate["status"] = "READY"
                candidate.pop("queue_reason", None)
                candidate.pop("blocked_by_dependencies", None)
                ready_list.append(candidate)
                selected_active.append(candidate)
                lane_counts[cand_lane] = current_lane_count + 1

            return ready_list

    def reserve_commands(self,
                         dispatcher_run_id: str,
                         specific_command_id: Optional[str] = None,
                         lane: Optional[str] = None,
                         capacity: int = 3) -> List[Dict[str, Any]]:
        """
        Atomically transitions eligible pending commands from PENDING to RESERVED.
        Moves pending/<command_id>.json -> reserved/<command_id>.json.
        Records reservation metadata:
          - reservation_token
          - dispatcher_run_id
          - reserved_at
        Returns list of reserved command dicts.
        """
        with FileLock(self.lock_file):
            ready_cmds = self.compute_ready_set(lane=lane, lane_capacity=capacity)
            if specific_command_id:
                ready_cmds = [c for c in ready_cmds if c["command_id"] == specific_command_id]

            reserved_list = []
            now = get_iso_now()

            for cmd in ready_cmds[:capacity]:
                cid = cmd["command_id"]
                tid = cmd["task_id"]
                pending_file = self.pending_dir / f"{cid}.json"
                if not pending_file.is_file():
                    continue

                res_token = uuid.uuid4().hex
                cmd["status"] = "RESERVED"
                cmd["reservation"] = {
                    "reservation_token": res_token,
                    "dispatcher_run_id": dispatcher_run_id,
                    "reserved_at": now,
                    "reservation_sha": None
                }

                dest = self.reserved_dir / f"{cid}.json"
                self._write_json(dest, cmd)
                try:
                    pending_file.unlink(missing_ok=True)
                except Exception:
                    pass

                self._update_task_state(tid, {
                    "command_id": cid,
                    "status": "RESERVED",
                    "reservation_token": res_token,
                    "dispatcher_run_id": dispatcher_run_id,
                    "reserved_at": now,
                    "updated_at": now
                })

                reserved_list.append(cmd)

            if reserved_list:
                self._reconcile_global_state_on_reserved(reserved_list)
                self.rebuild_index()

            return reserved_list

    def claim_command(self,
                      command_id: str,
                      runner_identity: str,
                      lease_seconds: int = 1800,
                      reservation_token: Optional[str] = None) -> Tuple[bool, str, Optional[Dict[str, Any]]]:
        """
        Atomically claims a pending or reserved command for a runner.
        Moves reserved/<command_id>.json (or pending) -> claimed/<command_id>.json.
        """
        with FileLock(self.lock_file):
            src_file = self.reserved_dir / f"{command_id}.json"
            if not src_file.is_file():
                src_file = self.pending_dir / f"{command_id}.json"

            if not src_file.is_file():
                # Check where it currently is
                res = self._find_command_file(command_id)
                if res:
                    return False, f"Cannot claim command {command_id}: currently in status {res[1]}", None
                return False, f"Command {command_id} not found", None

            cmd = self._load_json(src_file)
            if not cmd:
                return False, f"Command {command_id} unreadable", None

            # Verify reservation token if command was reserved
            if cmd.get("status") == "RESERVED":
                expected_token = cmd.get("reservation", {}).get("reservation_token")
                if reservation_token and expected_token and reservation_token != expected_token:
                    return False, f"BLOCKED_BINDING_MISMATCH: Provided reservation token does not match reservation for {command_id}", None

            lease_token = uuid.uuid4().hex
            now = datetime.datetime.now(datetime.timezone.utc)
            expires = now + datetime.timedelta(seconds=lease_seconds)

            cmd["status"] = "CLAIMED"
            cmd["lease"] = {
                "lease_token": lease_token,
                "lease_holder": runner_identity,
                "leased_at": now.astimezone().isoformat(),
                "lease_expires_at": expires.astimezone().isoformat(),
                "heartbeat_at": now.astimezone().isoformat()
            }

            dest = self.claimed_dir / f"{command_id}.json"
            self._write_json(dest, cmd)
            self._unlink_and_git_rm(src_file)

            self._update_task_state(cmd["task_id"], {
                "command_id": command_id,
                "status": "CLAIMED",
                "runner_identity": runner_identity,
                "leased_at": cmd["lease"]["leased_at"],
                "lease_expires_at": cmd["lease"]["lease_expires_at"],
                "updated_at": get_iso_now()
            })

            self.rebuild_index()
            return True, f"CLAIMED: {command_id} by {runner_identity}", cmd

    def start_command(self,
                      command_id: str,
                      lease_token: str,
                      dispatch_commit_sha: str,
                      github_run_id: Optional[str] = None,
                      workflow_url: Optional[str] = None) -> Tuple[bool, str, Optional[Dict[str, Any]]]:
        """
        Transitions command from CLAIMED to RUNNING.
        Attaches execution identity (dispatch commit SHA, run_id, workflow URL).
        """
        with FileLock(self.lock_file):
            claimed_file = self.claimed_dir / f"{command_id}.json"
            if not claimed_file.is_file():
                return False, f"Command {command_id} not in claimed directory", None

            cmd = self._load_json(claimed_file)
            if not cmd or not cmd.get("lease") or cmd["lease"].get("lease_token") != lease_token:
                return False, f"Invalid or missing lease token for command {command_id}", None

            cmd["status"] = "RUNNING"
            cmd["execution_identity"] = {
                "dispatch_commit_sha": dispatch_commit_sha,
                "github_run_id": github_run_id,
                "workflow_url": workflow_url,
                "runner_lane": cmd.get("execution_lane", "default"),
                "started_at": get_iso_now(),
                "finished_at": None,
                "conclusion": "RUNNING"
            }

            dest = self.running_dir / f"{command_id}.json"
            self._write_json(dest, cmd)
            self._unlink_and_git_rm(claimed_file)

            self._update_task_state(cmd["task_id"], {
                "command_id": command_id,
                "status": "RUNNING",
                "dispatch_commit_sha": dispatch_commit_sha,
                "github_run_id": github_run_id,
                "workflow_url": workflow_url,
                "started_at": cmd["execution_identity"]["started_at"],
                "updated_at": get_iso_now()
            })

            self._reconcile_global_state_on_running(cmd)
            self.rebuild_index()
            return True, f"RUNNING: {command_id}", cmd

    def heartbeat_command(self,
                          command_id: str,
                          lease_token: str,
                          extend_seconds: int = 1800) -> Tuple[bool, str]:
        """Extends lease for a running or claimed command."""
        with FileLock(self.lock_file):
            res = self._find_command_file(command_id)
            if not res:
                return False, f"Command {command_id} not found"

            path, status = res
            if status not in ["CLAIMED", "RUNNING"]:
                return False, f"Cannot heartbeat command in status {status}"

            cmd = self._load_json(path)
            if not cmd or not cmd.get("lease") or cmd["lease"].get("lease_token") != lease_token:
                return False, "Invalid lease token"

            now = datetime.datetime.now(datetime.timezone.utc)
            expires = now + datetime.timedelta(seconds=extend_seconds)

            cmd["lease"]["heartbeat_at"] = now.astimezone().isoformat()
            cmd["lease"]["lease_expires_at"] = expires.astimezone().isoformat()
            self._write_json(path, cmd)
            return True, f"Heartbeat recorded for {command_id}"

    def complete_command(self,
                         command_id: str,
                         lease_token: str,
                         target_commit_sha: str,
                         report_folder: str,
                         evidence_manifest_sha256: Optional[str] = None,
                         conclusion: str = "SUCCESS",
                         verdict: Optional[str] = None) -> Tuple[bool, str, Optional[Dict[str, Any]]]:
        """
        Marks command COMPLETED with mandatory provenance.
        Enforces:
        - Target commit SHA present
        - Report folder path present
        - Execution identity (dispatch SHA) verified
        """
        with FileLock(self.lock_file):
            running_file = self.running_dir / f"{command_id}.json"
            if not running_file.is_file():
                return False, f"Command {command_id} not in running directory", None

            cmd = self._load_json(running_file)
            if not cmd or not cmd.get("lease") or cmd["lease"].get("lease_token") != lease_token:
                return False, f"Invalid or missing lease token for command {command_id}", None

            # Provenance guard
            if not target_commit_sha or len(target_commit_sha) < 7:
                return False, "Target commit SHA is required for completion", None
            if not report_folder:
                return False, "Report folder is required for completion", None

            exec_id = cmd.get("execution_identity") or {}
            if not exec_id.get("dispatch_commit_sha"):
                return False, "Missing dispatch_commit_sha in execution identity", None

            now = get_iso_now()
            exec_id["finished_at"] = now
            exec_id["conclusion"] = conclusion

            cmd["status"] = "COMPLETED"
            cmd["execution_identity"] = exec_id
            if verdict:
                cmd["verdict"] = verdict
            cmd["provenance"] = {
                "target_commit_sha": target_commit_sha,
                "report_folder": report_folder,
                "evidence_manifest_sha256": evidence_manifest_sha256 or "NOT_SPECIFIED",
                "completed_at": now
            }

            dest = self.completed_dir / f"{command_id}.json"
            self._write_json(dest, cmd)
            self._unlink_and_git_rm(running_file)

            # Purge duplicate files across all other directories
            for other_dir in [self.pending_dir, self.reserved_dir, self.claimed_dir, self.running_dir, self.failed_dir]:
                dup = other_dir / f"{command_id}.json"
                self._unlink_and_git_rm(dup)

            # Archive to history
            hist = self.history_dir / f"{command_id}.json"
            self._write_json(hist, cmd)

            # Update per-task state
            self._update_task_state(cmd["task_id"], {
                "command_id": command_id,
                "status": "COMPLETED",
                "dispatch_commit_sha": exec_id.get("dispatch_commit_sha"),
                "target_commit_sha": target_commit_sha,
                "report_folder": report_folder,
                "finished_at": now,
                "conclusion": conclusion,
                "verdict": verdict or "PASS",
                "updated_at": now
            })

            # Safely reconcile global state without overwriting other tasks
            self._reconcile_global_state_on_completion(cmd, verdict=verdict)

            self.rebuild_index()
            return True, f"COMPLETED: {command_id}", cmd

    def fail_command(self,
                     command_id: str,
                     lease_token: str,
                     error_message: str) -> Tuple[bool, str, Optional[Dict[str, Any]]]:
        """Marks a claimed or running command as FAILED."""
        with FileLock(self.lock_file):
            res = self._find_command_file(command_id)
            if not res:
                return False, f"Command {command_id} not found", None

            path, status = res
            if status not in ["CLAIMED", "RUNNING"]:
                return False, f"Cannot fail command in status {status}", None

            cmd = self._load_json(path)
            if not cmd or not cmd.get("lease") or cmd["lease"].get("lease_token") != lease_token:
                return False, "Invalid lease token", None

            now = get_iso_now()
            exec_id = cmd.get("execution_identity") or {}
            exec_id["finished_at"] = now
            exec_id["conclusion"] = "FAILURE"
            exec_id["error_message"] = error_message

            cmd["status"] = "FAILED"
            cmd["execution_identity"] = exec_id

            dest = self.failed_dir / f"{command_id}.json"
            self._write_json(dest, cmd)
            self._unlink_and_git_rm(path)

            # Purge duplicate files across all other transient directories
            for other_dir in [self.pending_dir, self.reserved_dir, self.claimed_dir, self.running_dir]:
                dup = other_dir / f"{command_id}.json"
                self._unlink_and_git_rm(dup)

            hist = self.history_dir / f"{command_id}.json"
            self._write_json(hist, cmd)

            self._update_task_state(cmd["task_id"], {
                "command_id": command_id,
                "status": "FAILED",
                "error_message": error_message,
                "finished_at": now,
                "updated_at": now
            })

            self.rebuild_index()
            return True, f"FAILED: {command_id} with error: {error_message}", cmd

    def recover_stale_leases(self, timeout_seconds: int = 1800) -> List[Dict[str, Any]]:
        """
        Scans CLAIMED and RUNNING commands.
        If a lease has expired without heartbeat, resets it to PENDING (or STALE_RECOVERABLE).
        Never duplicates completed tasks or resurrects terminal commands.
        """
        recovered = []
        with FileLock(self.lock_file):
            now = datetime.datetime.now(datetime.timezone.utc)

            for target_dir in [self.claimed_dir, self.running_dir]:
                for p in target_dir.glob("*.json"):
                    cmd = self._load_json(p)
                    if not cmd or not cmd.get("lease"):
                        continue

                    lease = cmd["lease"]
                    exp_str = lease.get("lease_expires_at")
                    if not exp_str:
                        continue

                    try:
                        exp_dt = datetime.datetime.fromisoformat(exp_str)
                    except Exception:
                        continue

                    if now > exp_dt:
                        cid = cmd["command_id"]
                        tid = cmd["task_id"]

                        # Check if command is already in a terminal directory
                        if (self.completed_dir / f"{cid}.json").is_file():
                            self._unlink_and_git_rm(p)
                            continue
                        if (self.failed_dir / f"{cid}.json").is_file():
                            self._unlink_and_git_rm(p)
                            continue

                        retries = cmd.get("retry_count", 0) + 1
                        cmd["retry_count"] = retries
                        cmd["status"] = "PENDING"
                        cmd["lease"] = None
                        cmd["stale_recovery_record"] = {
                            "recovered_at": get_iso_now(),
                            "previous_holder": lease.get("lease_holder"),
                            "expired_at": exp_str,
                            "attempt": retries
                        }

                        dest = self.pending_dir / f"{cid}.json"
                        self._write_json(dest, cmd)
                        self._unlink_and_git_rm(p)

                        self._update_task_state(tid, {
                            "command_id": cid,
                            "status": "PENDING",
                            "recovered_stale_at": get_iso_now(),
                            "retry_count": retries
                        })

                        recovered.append({
                            "command_id": cid,
                            "task_id": tid,
                            "retries": retries
                        })

            # Check reserved commands for stale reservation timeout (15 mins)
            for p in self.reserved_dir.glob("*.json"):
                cmd = self._load_json(p)
                if not cmd or not cmd.get("reservation"):
                    continue
                res_time_str = cmd["reservation"].get("reserved_at")
                if not res_time_str:
                    continue
                try:
                    res_time = datetime.datetime.fromisoformat(res_time_str)
                    if now - res_time > datetime.timedelta(seconds=900):
                        cid = cmd["command_id"]
                        tid = cmd["task_id"]

                        # Check if command is already in a terminal directory
                        if (self.completed_dir / f"{cid}.json").is_file() or (self.failed_dir / f"{cid}.json").is_file():
                            self._unlink_and_git_rm(p)
                            continue

                        cmd["status"] = "PENDING"
                        cmd["reservation"] = None
                        dest = self.pending_dir / f"{cid}.json"
                        self._write_json(dest, cmd)
                        self._unlink_and_git_rm(p)
                        self._update_task_state(tid, {
                            "command_id": cid,
                            "status": "PENDING",
                            "recovered_stale_at": get_iso_now()
                        })
                        recovered.append({"command_id": cid, "task_id": tid, "reason": "expired_reservation"})
                except Exception:
                    pass

            if recovered:
                self.rebuild_index()
            self.reconcile_global_state()
        return recovered

    def integrate_branch(self,
                         command_id: str,
                         branch: str,
                         lease_token: Optional[str] = None) -> Tuple[bool, str, Optional[Dict[str, Any]]]:
        """
        Serial Integrator:
        1. Checks out main and pulls latest.
        2. Inspects branch diff against main to verify allowed_paths and locked_modules.
        3. Merges branch into main.
        4. In case of merge conflict, records BLOCKED_MERGE_CONFLICT and aborts merge safely.
        5. In case of success, records completion, pushes main, and reconciles state.
        """
        import subprocess

        with FileLock(self.lock_file):
            res = self._find_command_file(command_id)
            if not res:
                return False, f"Command {command_id} not found", None

            path, status = res
            cmd = self._load_json(path)
            if not cmd:
                return False, f"Command {command_id} unreadable", None

            if status == "COMPLETED":
                self._reconcile_uniqueness_internal()
                self.rebuild_index()
                return True, f"Command {command_id} already COMPLETED", cmd

            task_id = cmd.get("task_id", "")
            allowed_paths = cmd.get("allowed_paths", [])

            # 1. Fetch origin and inspect diff
            try:
                # Explicitly fetch the target branch to ensure it exists locally under refs/remotes/origin/
                subprocess.run(
                    ["git", "fetch", "origin", f"+refs/heads/{branch}:refs/remotes/origin/{branch}"],
                    cwd=str(self.repo_root), capture_output=True
                )
                subprocess.run(["git", "fetch", "origin"], check=True, cwd=str(self.repo_root), capture_output=True)
                subprocess.run(["git", "checkout", "main"], check=True, cwd=str(self.repo_root), capture_output=True)
                subprocess.run(["git", "pull", "--rebase", "origin", "main"], check=True, cwd=str(self.repo_root), capture_output=True)
            except Exception as e:
                return False, f"Git fetch/checkout main failed: {e}", None

            # Get list of changed files
            diff_ref = f"origin/{branch}"
            if subprocess.run(["git", "rev-parse", "--verify", diff_ref], cwd=str(self.repo_root), capture_output=True).returncode != 0:
                if subprocess.run(["git", "rev-parse", "--verify", branch], cwd=str(self.repo_root), capture_output=True).returncode == 0:
                    diff_ref = branch
                else:
                    return False, f"FETCH_ERROR: Target branch '{branch}' not found on origin or locally", None

            diff_proc = subprocess.run(["git", "diff", "--name-only", "main..." + diff_ref], cwd=str(self.repo_root), capture_output=True, text=True)
            changed_files = [line.strip() for line in diff_proc.stdout.splitlines() if line.strip()]

            # 2. Path gate: verify each file against allowed_paths
            if allowed_paths:
                unauthorized = []
                for cf in changed_files:
                    norm_cf = normalize_path_pattern(cf)
                    if is_shared_reconciled_path(norm_cf):
                        continue
                    matched = any(file_matches_allowed_path(norm_cf, ap) for ap in allowed_paths)
                    if not matched:
                        unauthorized.append(cf)

                if unauthorized:
                    err_msg = f"BLOCKED_UNAUTHORIZED_PATH: Modified files outside allowed_paths: {unauthorized}"
                    self._update_task_state(task_id, {
                        "status": "BLOCKED_UNAUTHORIZED_PATH",
                        "error_message": err_msg,
                        "updated_at": get_iso_now()
                    })
                    cmd["status"] = "BLOCKED_UNAUTHORIZED_PATH"
                    cmd["error_message"] = err_msg
                    self._write_json(path, cmd)
                    self.rebuild_index()
                    return False, err_msg, cmd

            # 3. Attempt merge
            merge_msg = f"chore(integrate): merge {branch} for {command_id}"
            merge_proc = subprocess.run(["git", "merge", "--no-ff", "-X", "no-renames", diff_ref, "-m", merge_msg], cwd=str(self.repo_root), capture_output=True, text=True)
            if merge_proc.returncode != 0:
                # Check if conflicts are strictly within shared reconciled metadata
                status_proc = subprocess.run(["git", "status", "--porcelain"], cwd=str(self.repo_root), capture_output=True, text=True)
                conflicts = [line for line in status_proc.stdout.splitlines() if line.startswith("UU ") or line.startswith("AA ") or line.startswith("DU ") or line.startswith("UD ")]
                auto_resolvable = bool(conflicts)
                for c in conflicts:
                    c_file = c[3:].strip()
                    if not is_shared_reconciled_path(c_file):
                        auto_resolvable = False
                        break

                if auto_resolvable and conflicts:
                    for c in conflicts:
                        c_file = c[3:].strip()
                        subprocess.run(["git", "checkout", "--theirs", c_file], cwd=str(self.repo_root), capture_output=True)
                        subprocess.run(["git", "add", c_file], cwd=str(self.repo_root), capture_output=True)
                    self.rebuild_index()
                    subprocess.run(["git", "add", ".ai/commands", ".ai/state"], cwd=str(self.repo_root), capture_output=True)
                    subprocess.run(["git", "commit", "-m", merge_msg], cwd=str(self.repo_root), capture_output=True)
                elif conflicts:
                    subprocess.run(["git", "merge", "--abort"], cwd=str(self.repo_root), capture_output=True)
                    err_msg = f"BLOCKED_MERGE_CONFLICT: Merge conflict merging {branch} into main: {merge_proc.stderr or merge_proc.stdout}"
                    self._update_task_state(task_id, {
                        "status": "BLOCKED_MERGE_CONFLICT",
                        "error_message": err_msg,
                        "updated_at": get_iso_now()
                    })
                    cmd["status"] = "BLOCKED_MERGE_CONFLICT"
                    cmd["error_message"] = err_msg
                    self._write_json(path, cmd)
                    self.rebuild_index()
                    return False, err_msg, cmd
                else:
                    subprocess.run(["git", "merge", "--abort"], cwd=str(self.repo_root), capture_output=True)
                    err_msg = f"MERGE_ERROR: Failed to merge {diff_ref} into main: {(merge_proc.stderr or merge_proc.stdout).strip()}"
                    return False, err_msg, cmd

            # 4. Successful merge: get target commit SHA
            target_sha = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=str(self.repo_root), text=True).strip()

            # Find report folder from task state
            task_state_file = self.tasks_state_dir / f"{task_id}.json"
            ts_data = self._load_json(task_state_file) or {}
            report_folder = ts_data.get("report_folder") or f".ai/reports/{task_id}"
            evidence_hash = ts_data.get("evidence_manifest_sha256") or "NOT_SPECIFIED"

            # Ensure command file is in running directory after merge
            running_file = self.running_dir / f"{command_id}.json"
            if not running_file.is_file():
                found_res = self._find_command_file(command_id)
                if found_res:
                    f_path, f_status = found_res
                    c_data = self._load_json(f_path)
                    if c_data:
                        c_data["status"] = "RUNNING"
                        self._write_json(running_file, c_data)
                        try:
                            f_path.unlink(missing_ok=True)
                        except Exception:
                            pass

            # Complete command
            cmd_curr = self._load_json(running_file) or cmd
            actual_lease = lease_token or (cmd_curr.get("lease") or {}).get("lease_token") or "SERIAL_INTEGRATOR_LEASE"
            if cmd_curr.get("lease"):
                cmd_curr["lease"]["lease_token"] = actual_lease
                self._write_json(running_file, cmd_curr)

            ok, comp_msg, comp_cmd = self.complete_command(
                command_id=command_id,
                lease_token=actual_lease,
                target_commit_sha=target_sha,
                report_folder=report_folder,
                evidence_manifest_sha256=evidence_hash
            )

            # Push merged main with guaranteed lifecycle uniqueness
            try:
                self._reconcile_uniqueness_internal()
                self.rebuild_index()
                subprocess.run(["git", "add", "-A", ".ai/commands", ".ai/state"], check=True, cwd=str(self.repo_root))
                st_proc = subprocess.run(["git", "status", "--porcelain", ".ai/commands", ".ai/state"], cwd=str(self.repo_root), capture_output=True, text=True)
                if st_proc.stdout.strip():
                    subprocess.run(["git", "commit", "-m", f"chore(command-bus): complete {command_id} and reconcile lifecycle"], check=True, cwd=str(self.repo_root))
                subprocess.run(["git", "push", "origin", "main"], check=True, cwd=str(self.repo_root))
                # Delete remote branch
                clean_branch = branch.replace("origin/", "")
                subprocess.run(["git", "push", "origin", "--delete", clean_branch], cwd=str(self.repo_root), capture_output=True)
            except Exception as e:
                print(f"Warning during push/branch cleanup: {e}")

            return True, f"INTEGRATED: {branch} merged into main at {target_sha}", comp_cmd

    def dispatch_commands(self,
                          dispatcher_run_id: str,
                          specific_command_id: Optional[str] = None,
                          lane: Optional[str] = None,
                          max_dispatch: int = 3) -> List[Dict[str, Any]]:
        """
        Dispatcher Gate:
        1. Evaluates ready commands and reserves up to capacity.
        2. Commits and pushes reservations atomically to main.
        3. Dispatches convert2-worker.yml for each reserved command with explicit binding.
        """
        import subprocess

        # Step 1: Reserve commands
        reserved = self.reserve_commands(
            dispatcher_run_id=dispatcher_run_id,
            specific_command_id=specific_command_id,
            lane=lane,
            capacity=max_dispatch
        )

        if not reserved:
            print(f"[DISPATCH] No eligible commands ready for dispatch.")
            return []

        # Step 2: Push reservations atomically to main
        try:
            subprocess.run(["git", "add", ".ai/commands", ".ai/state", ".ai/state.json"], check=True, cwd=str(self.repo_root))
            commit_msg = f"chore(command-bus): reserve {len(reserved)} command(s) for dispatch [run {dispatcher_run_id}]"
            subprocess.run(["git", "commit", "-m", commit_msg], check=True, cwd=str(self.repo_root))

            # Push with retry
            pushed = False
            for attempt in range(3):
                p_res = subprocess.run(["git", "push", "origin", "main"], cwd=str(self.repo_root))
                if p_res.returncode == 0:
                    pushed = True
                    break
                subprocess.run(["git", "pull", "--rebase", "origin", "main"], cwd=str(self.repo_root))

            if not pushed:
                print("[DISPATCH_ERROR] Failed to push reservations to main after 3 attempts.")
                return []
        except Exception as e:
            print(f"[DISPATCH_ERROR] Git commit/push failed: {e}")
            return []

        res_sha = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=str(self.repo_root), text=True).strip()

        # Step 3: Dispatch worker workflows
        dispatched = []
        for cmd in reserved:
            cid = cmd["command_id"]
            cmd_lane = cmd.get("execution_lane", "default")
            res_token = cmd.get("reservation", {}).get("reservation_token", "")

            # Update reservation_sha in command file
            res_file = self.reserved_dir / f"{cid}.json"
            if res_file.is_file():
                c_data = self._load_json(res_file)
                if c_data and c_data.get("reservation"):
                    c_data["reservation"]["reservation_sha"] = res_sha
                    self._write_json(res_file, c_data)

            # Trigger worker workflow via gh CLI
            dispatch_args = [
                "gh", "workflow", "run", "convert2-worker.yml",
                "-f", f"command_id={cid}",
                "-f", f"reservation_token={res_token}",
                "-f", f"execution_lane={cmd_lane}",
                "-r", "main"
            ]
            runner_label = cmd.get("runner_label")
            if runner_label:
                dispatch_args.extend(["-f", f"runner_label={runner_label}"])
            print(f"[DISPATCH] Triggering worker for {cid} (lane={cmd_lane}, reservation_token={res_token[:8]}...)...")
            res = subprocess.run(dispatch_args, capture_output=True, text=True)
            dispatch_error = None
            if res.returncode == 0:
                # gh workflow run returning 0 only proves that GitHub accepted the
                # workflow_dispatch request.  It does NOT prove that a self-hosted
                # Worker was assigned or that the command was claimed.
                #
                # Require a durable ACK written by the Worker to origin/main:
                # lease + execution_identity and CLAIMED/RUNNING status.  Without
                # this handshake a command must never remain RESERVED forever.
                ack_deadline = time.time() + 90
                acked = False
                while time.time() < ack_deadline:
                    subprocess.run(
                        ["git", "fetch", "origin", "main"],
                        cwd=str(self.repo_root),
                        capture_output=True,
                        text=True
                    )
                    remote_path = f".ai/commands/reserved/{cid}.json"
                    remote = subprocess.run(
                        ["git", "show", f"origin/main:{remote_path}"],
                        cwd=str(self.repo_root),
                        capture_output=True,
                        text=True
                    )
                    if remote.returncode == 0:
                        try:
                            remote_cmd = json.loads(remote.stdout)
                            lease = remote_cmd.get("lease")
                            exec_id = remote_cmd.get("execution_identity")
                            remote_status = remote_cmd.get("status")
                            if lease and exec_id and remote_status in {"CLAIMED", "RUNNING"}:
                                acked = True
                                print(
                                    f"[DISPATCH_ACK] Worker claimed {cid} "
                                    f"(status={remote_status}, run_id={exec_id.get('run_id')})."
                                )
                                break
                        except (json.JSONDecodeError, TypeError):
                            pass
                    else:
                        # The Worker may move the command out of reserved very
                        # quickly. Check running/completed as positive ACK paths.
                        for remote_dir in ("running", "completed"):
                            moved = subprocess.run(
                                ["git", "show", f"origin/main:.ai/commands/{remote_dir}/{cid}.json"],
                                cwd=str(self.repo_root),
                                capture_output=True,
                                text=True
                            )
                            if moved.returncode == 0:
                                try:
                                    moved_cmd = json.loads(moved.stdout)
                                    if moved_cmd.get("execution_identity"):
                                        acked = True
                                        print(f"[DISPATCH_ACK] Worker advanced {cid} to {remote_dir}.")
                                        break
                                except (json.JSONDecodeError, TypeError):
                                    pass
                        if acked:
                            break
                    time.sleep(5)

                if acked:
                    print(f"[DISPATCH_OK] Dispatched and acknowledged {cid}.")
                    dispatched.append(cmd)
                else:
                    dispatch_error = (
                        "Worker ACK timeout after workflow_dispatch: no durable "
                        "lease/execution_identity CLAIM observed within 90s"
                    )
            else:
                dispatch_error = (
                    res.stderr or res.stdout or "unknown gh workflow dispatch error"
                ).strip()

            if dispatch_error:
                # Never report a green dispatcher when no Worker actually claimed
                # the command. Roll the reservation back to pending so the next
                # dispatcher cycle can retry instead of leaving a dead reservation.
                print(f"[DISPATCH_ERROR] {cid}: {dispatch_error}")
                current = self._load_json(res_file) if res_file.is_file() else cmd
                if current:
                    current["status"] = "PENDING"
                    current["reservation"] = None
                    current["dispatch_error"] = {
                        "dispatcher_run_id": dispatcher_run_id,
                        "failed_at": get_iso_now(),
                        "error": dispatch_error
                    }
                    self._write_json(self.pending_dir / f"{cid}.json", current)
                    try:
                        res_file.unlink(missing_ok=True)
                    except Exception:
                        pass
                    self._update_task_state(current.get("task_id", ""), {
                        "command_id": cid,
                        "status": "PENDING",
                        "dispatch_error": dispatch_error,
                        "updated_at": get_iso_now()
                    })
                self.rebuild_index()

        # Persist reservation SHA / rollback state and fail loudly if any worker dispatch failed.
        subprocess.run(["git", "add", ".ai/commands", ".ai/state"], check=True, cwd=str(self.repo_root))
        if subprocess.run(["git", "diff", "--cached", "--quiet"], cwd=str(self.repo_root)).returncode != 0:
            subprocess.run(["git", "commit", "-m",
                            f"chore(command-bus): persist dispatch outcome [run {dispatcher_run_id}]"],
                           check=True, cwd=str(self.repo_root))
            subprocess.run(["git", "pull", "--rebase", "origin", "main"], check=True, cwd=str(self.repo_root))
            subprocess.run(["git", "push", "origin", "main"], check=True, cwd=str(self.repo_root))

        if len(dispatched) != len(reserved):
            failed_count = len(reserved) - len(dispatched)
            raise RuntimeError(
                f"Worker dispatch failed for {failed_count}/{len(reserved)} reserved command(s); "
                "failed commands were returned to pending."
            )

        return dispatched

    # -------------------------------------------------------------------------
    # Legacy Migration (NEXT_COMMAND.json)
    # -------------------------------------------------------------------------

    def migrate_next_command(self) -> Tuple[bool, str, Optional[Dict[str, Any]]]:
        """
        Safely migrates legacy NEXT_COMMAND.json into an immutable pending command.
        Prevents dropping active tasks during rollout.
        """
        with FileLock(self.lock_file):
            if not self.next_command_file.is_file():
                return False, "No NEXT_COMMAND.json to migrate", None

            legacy = self._load_json(self.next_command_file)
            if not legacy:
                return False, "NEXT_COMMAND.json is empty or invalid JSON", None

            # Check if already migrated
            if legacy.get("migrated_to_command_id"):
                return False, f"Already migrated to {legacy['migrated_to_command_id']}", None

            action = legacy.get("action")
            if action != "EXECUTE_TASK":
                return False, f"NEXT_COMMAND action '{action}' is not EXECUTE_TASK", None

            task_id = legacy.get("task_id")
            if not task_id:
                return False, "NEXT_COMMAND missing task_id", None

            task_url = legacy.get("task_url", "")
            issued_for_sha = legacy.get("issued_for_sha", "HEAD")
            legacy_cmd_id = legacy.get("command_id") or f"CMD_{task_id}_MIGRATED"
            revision = legacy.get("issued_at", "V1_LEGACY")

            # Check if this task was already completed in state.json
            global_state = self._load_json(self.global_state_file)
            if global_state and global_state.get("last_completed_task_id") == task_id:
                return False, f"Task {task_id} was already completed in state.json", None

            ok, msg, cmd = self.create_command(
                task_id=task_id,
                task_url=task_url,
                task_revision=revision,
                issued_for_sha=issued_for_sha,
                priority="HIGH",
                dependencies=[],
                execution_lane="default",
                command_id=legacy_cmd_id
            )

            if ok or "DUPLICATE_REJECTED" in msg:
                # Update legacy file with forward pointer
                legacy["migrated_to_command_id"] = legacy_cmd_id
                legacy["migrated_at"] = get_iso_now()
                legacy["protocol_status"] = "MIGRATED_TO_CONVERT2_COMMAND_V2"
                self._write_json(self.next_command_file, legacy)
                return True, f"Migrated {task_id} to {legacy_cmd_id}", cmd
            else:
                return False, f"Failed migration: {msg}", None

    # -------------------------------------------------------------------------
    # State & Provenance Management
    # -------------------------------------------------------------------------

    def _update_task_state(self, task_id: str, updates: Dict[str, Any]):
        """Updates per-task durable state file in .ai/state/tasks/<task_id>.json."""
        state_file = self.tasks_state_dir / f"{task_id}.json"
        current = self._load_json(state_file) or {}
        current.update(updates)
        self._write_json(state_file, current)

    def _extract_task_prefix(self, task_id: str) -> str:
        """Extracts short task prefix e.g. TASK_057 from task_id."""
        if not task_id:
            return "TASK_UNKNOWN"
        m = re.match(r"(TASK_[0-9A-Za-z]+)", task_id)
        return m.group(1) if m else task_id

    def _reconcile_global_state_on_running(self, running_cmd: Dict[str, Any]):
        """
        Updates global .ai/state.json when a command starts executing.
        Ensures agent_state becomes TASK_EXECUTING and current_task_id points to active task.
        """
        task_id = running_cmd.get("task_id", "")
        task_prefix = self._extract_task_prefix(task_id)
        exec_id = running_cmd.get("execution_identity", {})
        now = get_iso_now()

        state = self._load_json(self.global_state_file) or {}
        state["agent_state"] = "TASK_EXECUTING"
        state["current_task_id"] = task_id
        state["current_command_id"] = running_cmd.get("command_id")
        state["last_scan_time"] = now

        if "task_lifecycle" not in state or not isinstance(state["task_lifecycle"], dict):
            state["task_lifecycle"] = {}

        if f"{task_prefix}_DISPATCHED" not in state["task_lifecycle"]:
            state["task_lifecycle"][f"{task_prefix}_DISPATCHED"] = running_cmd.get("created_at") or now
        state["task_lifecycle"][f"{task_prefix}_EXECUTING"] = exec_id.get("started_at") or now
        state["task_lifecycle"][f"{task_prefix}_STATUS"] = "RUNNING"

        if "provenance" not in state or not isinstance(state["provenance"], dict):
            state["provenance"] = {}

        state["provenance"].update({
            "execution_lane": running_cmd.get("execution_lane"),
            "dispatch_command_id": running_cmd.get("command_id"),
            "dispatch_commit_sha": exec_id.get("dispatch_commit_sha"),
            "github_run_id": exec_id.get("github_run_id"),
            "anti_duplicate_key": running_cmd.get("anti_duplicate_key")
        })

        self._write_json(self.global_state_file, state)

    def _reconcile_global_state_on_reserved(self, reserved_cmds: List[Dict[str, Any]]):
        """
        Updates global .ai/state.json when commands are reserved.
        Sets agent_state to TASK_DISPATCHED if not already executing.
        """
        if not reserved_cmds:
            return
        state = self._load_json(self.global_state_file) or {}
        now = get_iso_now()

        if "task_lifecycle" not in state or not isinstance(state["task_lifecycle"], dict):
            state["task_lifecycle"] = {}

        for cmd in reserved_cmds:
            task_id = cmd.get("task_id", "")
            task_prefix = self._extract_task_prefix(task_id)
            if f"{task_prefix}_DISPATCHED" not in state["task_lifecycle"]:
                state["task_lifecycle"][f"{task_prefix}_DISPATCHED"] = cmd.get("created_at") or now
            state["task_lifecycle"][f"{task_prefix}_STATUS"] = "RESERVED"

        if state.get("agent_state") != "TASK_EXECUTING":
            state["agent_state"] = "TASK_DISPATCHED"
            state["current_task_id"] = reserved_cmds[0].get("task_id")
            state["current_command_id"] = reserved_cmds[0].get("command_id")

        state["last_scan_time"] = now
        self._write_json(self.global_state_file, state)

    def reconcile_global_state(self) -> Dict[str, Any]:
        """
        Comprehensive idempotent and monotonic reconciliation of global .ai/state.json:
        1. Reflects running/claimed/reserved commands in agent_state and current_task_id.
        2. Monotonically tracks last_completed_task_id from completed_dir.
        3. Fills missing task_lifecycle entries for all known commands.
        """
        state = self._load_json(self.global_state_file) or {}
        now = get_iso_now()

        if "task_lifecycle" not in state or not isinstance(state["task_lifecycle"], dict):
            state["task_lifecycle"] = {}
        if "provenance" not in state or not isinstance(state["provenance"], dict):
            state["provenance"] = {}

        running_files = sorted(list(self.running_dir.glob("*.json")))
        claimed_files = sorted(list(self.claimed_dir.glob("*.json")))
        reserved_files = sorted(list(self.reserved_dir.glob("*.json")))
        completed_files = sorted(list(self.completed_dir.glob("*.json")))

        # Record all lifecycle events from completed files
        for p in completed_files:
            c = self._load_json(p)
            if c:
                tid = c.get("task_id", "")
                tp = self._extract_task_prefix(tid)
                if f"{tp}_DISPATCHED" not in state["task_lifecycle"]:
                    state["task_lifecycle"][f"{tp}_DISPATCHED"] = c.get("created_at") or now
                if f"{tp}_COMPLETED" not in state["task_lifecycle"]:
                    state["task_lifecycle"][f"{tp}_COMPLETED"] = c.get("completed_at") or now
                if f"{tp}_STATUS" not in state["task_lifecycle"]:
                    state["task_lifecycle"][f"{tp}_STATUS"] = c.get("verdict") or "COMPLETED"

        for p in reserved_files + claimed_files:
            c = self._load_json(p)
            if c:
                tid = c.get("task_id", "")
                tp = self._extract_task_prefix(tid)
                if f"{tp}_DISPATCHED" not in state["task_lifecycle"]:
                    state["task_lifecycle"][f"{tp}_DISPATCHED"] = c.get("created_at") or now
                state["task_lifecycle"][f"{tp}_STATUS"] = c.get("status") or "DISPATCHED"

        for p in running_files:
            c = self._load_json(p)
            if c:
                tid = c.get("task_id", "")
                tp = self._extract_task_prefix(tid)
                if f"{tp}_DISPATCHED" not in state["task_lifecycle"]:
                    state["task_lifecycle"][f"{tp}_DISPATCHED"] = c.get("created_at") or now
                if f"{tp}_EXECUTING" not in state["task_lifecycle"]:
                    exec_id = c.get("execution_identity", {})
                    state["task_lifecycle"][f"{tp}_EXECUTING"] = exec_id.get("started_at") or now
                state["task_lifecycle"][f"{tp}_STATUS"] = "RUNNING"

        # Determine active state
        if running_files:
            rcmd = self._load_json(running_files[-1])
            state["agent_state"] = "TASK_EXECUTING"
            state["current_task_id"] = rcmd.get("task_id")
            state["current_command_id"] = rcmd.get("command_id")
            exec_id = rcmd.get("execution_identity", {})
            state["provenance"]["execution_lane"] = rcmd.get("execution_lane")
            state["provenance"]["dispatch_command_id"] = rcmd.get("command_id")
            if exec_id.get("dispatch_commit_sha"):
                state["provenance"]["dispatch_commit_sha"] = exec_id.get("dispatch_commit_sha")
            if exec_id.get("github_run_id"):
                state["provenance"]["github_run_id"] = exec_id.get("github_run_id")
        elif claimed_files or reserved_files:
            acmd = self._load_json((claimed_files or reserved_files)[-1])
            state["agent_state"] = "TASK_DISPATCHED"
            state["current_task_id"] = acmd.get("task_id")
            state["current_command_id"] = acmd.get("command_id")
        else:
            state["agent_state"] = "IDLE_WAIT_FOR_TASK"
            state["current_task_id"] = None
            state["current_command_id"] = None

        state["last_scan_time"] = now
        self._write_json(self.global_state_file, state)
        return state

    def _reconcile_global_state_on_completion(self, completed_cmd: Dict[str, Any], verdict: Optional[str] = None):
        """
        Safely reconciles global .ai/state.json without race conditions or overwriting other tasks.
        Enforces STATE TRUTH: verdict cannot be blindly PASS if mandatory external gates are unresolved.
        """
        task_id = completed_cmd.get("task_id", "")
        task_prefix = self._extract_task_prefix(task_id)
        provenance = completed_cmd.get("provenance", {})
        exec_id = completed_cmd.get("execution_identity", {})
        now = get_iso_now()

        state = self._load_json(self.global_state_file) or {}
        state["last_completed_task_id"] = task_id
        state["last_completed_task_modified_time"] = completed_cmd.get("task_revision")
        state["last_report_folder"] = provenance.get("report_folder")
        state["last_target_commit_sha"] = provenance.get("target_commit_sha")
        state["last_scan_time"] = now

        # Determine truthful verdict
        resolved_verdict = verdict or completed_cmd.get("verdict")
        confirmation_status = state.get("confirmation_gate", {}).get("status")
        mirror_verdict = state.get("report_drive_mirror_verdict")
        owner_visual_status = state.get("owner_visual_acceptance_status")

        if not resolved_verdict:
            if confirmation_status in ["CONFIRMATION_REQUIRED", "BLOCKED_EXTERNAL_AUTH"]:
                resolved_verdict = confirmation_status
            elif mirror_verdict in ["CONFIRMATION_REQUIRED", "BLOCKED_EXTERNAL_AUTH", "NEEDS_FIX"]:
                resolved_verdict = mirror_verdict
            elif exec_id.get("conclusion") not in [None, "SUCCESS"]:
                resolved_verdict = "NEEDS_FIX"
            elif owner_visual_status == "PENDING_OWNER_EVALUATION":
                resolved_verdict = "TECHNICAL_PASS_AWAITING_OWNER_VISUAL"
            else:
                resolved_verdict = "PASS"

        # Invariant: PASS is strictly forbidden when mandatory external gates are unresolved
        if (confirmation_status and confirmation_status not in ["PASS", "COMPLETED"]) or \
           (mirror_verdict and mirror_verdict not in ["PASS", "COMPLETED"]) or \
           (owner_visual_status and owner_visual_status != "APPROVED"):
            if resolved_verdict in ["PASS", "FINAL_PASS"]:
                if owner_visual_status and owner_visual_status != "APPROVED":
                    resolved_verdict = "TECHNICAL_PASS_AWAITING_OWNER_VISUAL"
                else:
                    resolved_verdict = confirmation_status or mirror_verdict or "BLOCKED_EXTERNAL_AUTH"

        state["verdict"] = resolved_verdict

        # Update lifecycle
        if "task_lifecycle" not in state or not isinstance(state["task_lifecycle"], dict):
            state["task_lifecycle"] = {}
        state["task_lifecycle"][f"{task_prefix}_COMPLETED"] = completed_cmd.get("completed_at") or now
        state["task_lifecycle"][f"{task_prefix}_STATUS"] = resolved_verdict

        # Check if any remaining command is running or claimed
        running_files = list(self.running_dir.glob("*.json"))
        claimed_files = list(self.claimed_dir.glob("*.json"))
        reserved_files = list(self.reserved_dir.glob("*.json"))

        if running_files:
            rcmd = self._load_json(running_files[-1])
            state["agent_state"] = "TASK_EXECUTING"
            state["current_task_id"] = rcmd.get("task_id")
            state["current_command_id"] = rcmd.get("command_id")
        elif claimed_files or reserved_files:
            acmd = self._load_json((claimed_files or reserved_files)[-1])
            state["agent_state"] = "TASK_DISPATCHED"
            state["current_task_id"] = acmd.get("task_id")
            state["current_command_id"] = acmd.get("command_id")
        else:
            state["agent_state"] = "IDLE_WAIT_FOR_TASK"
            state["current_task_id"] = None
            state["current_command_id"] = None

        # Update provenance block
        if "provenance" not in state or not isinstance(state["provenance"], dict):
            state["provenance"] = {}

        state["provenance"].update({
            "execution_lane": completed_cmd.get("execution_lane"),
            "dispatch_command_id": completed_cmd.get("command_id"),
            "dispatch_commit_sha": exec_id.get("dispatch_commit_sha"),
            "target_commit_sha": provenance.get("target_commit_sha"),
            "github_run_id": exec_id.get("github_run_id"),
            "anti_duplicate_key": completed_cmd.get("anti_duplicate_key")
        })

        self._write_json(self.global_state_file, state)

    def print_status_summary(self):
        """Prints a human-readable summary of the command bus state."""
        index = self.rebuild_index()
        counts = index.get("counts", {})
        print("=" * 60)
        print("CONVERT2 COMMAND BUS ORCHESTRATOR STATUS")
        print("=" * 60)
        print(f"Pending:   {counts.get('pending', 0)}")
        print(f"Claimed:   {counts.get('claimed', 0)}")
        print(f"Running:   {counts.get('running', 0)}")
        print(f"Completed: {counts.get('completed', 0)}")
        print(f"Failed:    {counts.get('failed', 0)}")
        print("-" * 60)
        all_cmds = self._get_all_commands()
        for cid, c in sorted(all_cmds.items(), key=lambda x: x[1].get("created_at", "")):
            print(f"[{c.get('status', 'UNKNOWN'):<10}] {cid:<40} lane={c.get('execution_lane')} prio={c.get('priority')}")
        print("=" * 60)


def main():
    parser = argparse.ArgumentParser(description="CONVERT2 Command Bus Orchestrator")
    subparsers = parser.add_subparsers(dest="action", help="Subcommands")

    # status
    subparsers.add_parser("status", help="Print status summary")

    # rebuild-index
    subparsers.add_parser("rebuild-index", help="Rebuild command index")

    # migrate
    subparsers.add_parser("migrate", help="Migrate legacy NEXT_COMMAND.json")

    # recover
    parser_recover = subparsers.add_parser("recover", help="Recover stale leases")
    parser_recover.add_argument("--timeout", type=int, default=1800, help="Lease timeout in seconds")

    # ready
    parser_ready = subparsers.add_parser("ready", help="Compute ready commands")
    parser_ready.add_argument("--lane", type=str, default=None, help="Execution lane")
    parser_ready.add_argument("--capacity", type=int, default=2, help="Runner capacity per lane")
    parser_ready.add_argument("--json", action="store_true", help="Output ready commands as JSON")

    # create
    parser_create = subparsers.add_parser("create", help="Create new command")
    parser_create.add_argument("--task-id", required=True, help="Task ID")
    parser_create.add_argument("--task-url", required=True, help="Task Document URL")
    parser_create.add_argument("--revision", required=True, help="Task revision or hash")
    parser_create.add_argument("--sha", required=True, help="Issued for Git SHA")
    parser_create.add_argument("--priority", default="NORMAL", help="Priority (CRITICAL, HIGH, NORMAL, LOW)")
    parser_create.add_argument("--lane", default="default", help="Execution lane")
    parser_create.add_argument("--dependencies", default="", help="Comma-separated dependencies")
    parser_create.add_argument("--allowed-paths", default="", help="Comma-separated allowed file paths/globs")
    parser_create.add_argument("--locked-modules", default="", help="Comma-separated locked module names")
    parser_create.add_argument("--command-id", default=None, help="Optional specific command ID")

    # reserve
    parser_reserve = subparsers.add_parser("reserve", help="Reserve eligible ready commands")
    parser_reserve.add_argument("--dispatcher-run-id", required=True, help="Dispatcher run ID")
    parser_reserve.add_argument("--command-id", default=None, help="Specific command ID")
    parser_reserve.add_argument("--lane", default=None, help="Execution lane")
    parser_reserve.add_argument("--capacity", type=int, default=3, help="Max reservation capacity")

    # dispatch
    parser_dispatch = subparsers.add_parser("dispatch", help="Reserve and dispatch eligible commands")
    parser_dispatch.add_argument("--dispatcher-run-id", required=True, help="Dispatcher run ID")
    parser_dispatch.add_argument("--command-id", default=None, help="Specific command ID")
    parser_dispatch.add_argument("--lane", default=None, help="Execution lane")
    parser_dispatch.add_argument("--max-dispatch", type=int, default=3, help="Max concurrent dispatch count")

    # integrate
    parser_integrate = subparsers.add_parser("integrate", help="Serial branch integration gate")
    parser_integrate.add_argument("--command-id", required=True, help="Command ID to integrate")
    parser_integrate.add_argument("--branch", required=True, help="Branch to integrate into main")
    parser_integrate.add_argument("--lease-token", default=None, help="Lease token")

    # claim
    parser_claim = subparsers.add_parser("claim", help="Claim a pending or reserved command")
    parser_claim.add_argument("--command-id", required=True, help="Command ID to claim")
    parser_claim.add_argument("--runner", required=True, help="Runner identity")
    parser_claim.add_argument("--lease", type=int, default=1800, help="Lease duration in seconds")
    parser_claim.add_argument("--reservation-token", default=None, help="Reservation token if command was reserved")

    # start
    parser_start = subparsers.add_parser("start", help="Start execution of a claimed command")
    parser_start.add_argument("--command-id", required=True, help="Command ID")
    parser_start.add_argument("--lease-token", required=True, help="Lease token")
    parser_start.add_argument("--dispatch-sha", required=True, help="Dispatch commit SHA")
    parser_start.add_argument("--run-id", default=None, help="GitHub Actions run_id")
    parser_start.add_argument("--url", default=None, help="Workflow run URL")

    # complete
    parser_complete = subparsers.add_parser("complete", help="Complete a running command")
    parser_complete.add_argument("--command-id", required=True, help="Command ID")
    parser_complete.add_argument("--lease-token", required=True, help="Lease token")
    parser_complete.add_argument("--target-sha", required=True, help="Target commit SHA")
    parser_complete.add_argument("--report", required=True, help="Report folder path")
    parser_complete.add_argument("--manifest-hash", default=None, help="Evidence manifest SHA-256")
    parser_complete.add_argument("--verdict", default=None, help="Explicit final task verdict")

    # fail
    parser_fail = subparsers.add_parser("fail", help="Mark a command failed")
    parser_fail.add_argument("--command-id", required=True, help="Command ID")
    parser_fail.add_argument("--lease-token", required=True, help="Lease token")
    parser_fail.add_argument("--error", required=True, help="Error message")

    # validate-lifecycle
    subparsers.add_parser("validate-lifecycle", help="Validate single-directory lifecycle invariants")

    # reconcile-lifecycle
    subparsers.add_parser("reconcile-lifecycle", help="Reconcile lifecycle uniqueness across directories")

    # reconcile-state
    subparsers.add_parser("reconcile-state", help="Reconcile global .ai/state.json with command bus")

    # heartbeat
    parser_heartbeat = subparsers.add_parser("heartbeat", help="Send heartbeat to extend lease")
    parser_heartbeat.add_argument("--command-id", required=True, help="Command ID")
    parser_heartbeat.add_argument("--lease-token", required=True, help="Lease token")
    parser_heartbeat.add_argument("--extend", type=int, default=1800, help="Seconds to extend lease")

    args = parser.parse_args()
    if not args.action:
        parser.print_help()
        sys.exit(1)

    orch = CommandBusOrchestrator()

    if args.action == "status":
        orch.print_status_summary()

    elif args.action == "reconcile-state":
        st = orch.reconcile_global_state()
        print(f"[OK] Reconciled state.json: agent_state={st.get('agent_state')}, current_task={st.get('current_task_id')}")

    elif args.action == "rebuild-index":
        idx = orch.rebuild_index()
        print(json.dumps(idx, indent=2))

    elif args.action == "migrate":
        ok, msg, data = orch.migrate_next_command()
        print(f"[{'OK' if ok else 'FAIL'}] {msg}")
        if data:
            print(json.dumps(data, indent=2))

    elif args.action == "recover":
        rec = orch.recover_stale_leases(timeout_seconds=args.timeout)
        print(f"Recovered {len(rec)} stale command(s): {rec}")

    elif args.action == "ready":
        ready = orch.compute_ready_set(lane=args.lane, lane_capacity=args.capacity)
        if getattr(args, "json", False):
            print(json.dumps(ready, indent=2))
        else:
            print(f"Ready commands count: {len(ready)}")
            for r in ready:
                print(f"  READY: {r['command_id']} (task={r['task_id']}, lane={r.get('execution_lane')}, prio={r.get('priority')})")

    elif args.action == "reserve":
        res = orch.reserve_commands(
            dispatcher_run_id=args.dispatcher_run_id,
            specific_command_id=args.command_id,
            lane=args.lane,
            capacity=args.capacity
        )
        print(f"Reserved {len(res)} command(s):")
        for r in res:
            print(f"  RESERVED: {r['command_id']} (task={r['task_id']}, token={r['reservation']['reservation_token']})")

    elif args.action == "dispatch":
        disp = orch.dispatch_commands(
            dispatcher_run_id=args.dispatcher_run_id,
            specific_command_id=args.command_id,
            lane=args.lane,
            max_dispatch=args.max_dispatch
        )
        print(f"Dispatched {len(disp)} command(s).")

    elif args.action == "integrate":
        ok, msg, data = orch.integrate_branch(
            command_id=args.command_id,
            branch=args.branch,
            lease_token=args.lease_token
        )
        print(f"[{'OK' if ok else 'FAIL'}] {msg}")
        if not ok:
            sys.exit(1)

    elif args.action == "create":
        deps = [d.strip() for d in args.dependencies.split(",") if d.strip()]
        paths = [p.strip() for p in args.allowed_paths.split(",") if p.strip()]
        modules = [m.strip() for m in args.locked_modules.split(",") if m.strip()]
        ok, msg, data = orch.create_command(
            task_id=args.task_id,
            task_url=args.task_url,
            task_revision=args.revision,
            issued_for_sha=args.sha,
            priority=args.priority,
            dependencies=deps,
            execution_lane=args.lane,
            allowed_paths=paths,
            locked_modules=modules,
            command_id=args.command_id
        )
        print(f"[{'OK' if ok else 'REJECTED'}] {msg}")
        if data:
            print(json.dumps(data, indent=2))

    elif args.action == "claim":
        ok, msg, data = orch.claim_command(
            args.command_id,
            args.runner,
            args.lease,
            reservation_token=args.reservation_token
        )
        print(f"[{'OK' if ok else 'FAIL'}] {msg}")
        if data:
            print(json.dumps(data, indent=2))

    elif args.action == "start":
        ok, msg, data = orch.start_command(args.command_id, args.lease_token, args.dispatch_sha, args.run_id, args.url)
        print(f"[{'OK' if ok else 'FAIL'}] {msg}")

    elif args.action == "complete":
        ok, msg, data = orch.complete_command(
            args.command_id, args.lease_token, args.target_sha, args.report, args.manifest_hash,
            conclusion="SUCCESS", verdict=args.verdict
        )
        print(f"[{'OK' if ok else 'FAIL'}] {msg}")

    elif args.action == "fail":
        ok, msg, data = orch.fail_command(args.command_id, args.lease_token, args.error)
        print(f"[{'OK' if ok else 'FAIL'}] {msg}")

    elif args.action == "validate-lifecycle":
        is_valid, violations, summary = orch.validate_lifecycle_invariants()
        print(f"[{'PASS' if is_valid else 'FAIL'}] Lifecycle Invariant Validation")
        if violations:
            print(f"Found {len(violations)} violation(s):")
            for v in violations:
                print(f"  - {v}")
            sys.exit(1)
        else:
            print("All command lifecycle invariants satisfied: each command in strictly one directory.")

    elif args.action == "reconcile-lifecycle":
        res = orch.reconcile_lifecycle_uniqueness()
        print(f"Reconciled lifecycle uniqueness: purged {res['purged_count']} duplicate(s).")
        for p in res.get("purged", []):
            print(f"  - Purged {p['command_id']} from {p['purged_from']} (retained in {p['retained_in']})")

    elif args.action == "heartbeat":
        ok, msg = orch.heartbeat_command(args.command_id, args.lease_token, args.extend)
        print(f"[{'OK' if ok else 'FAIL'}] {msg}")


if __name__ == "__main__":
    main()

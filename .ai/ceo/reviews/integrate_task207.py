"""Stage only accepted TASK_207 research evidence on the CEO-owned branch."""

import json
import shutil
import sys
from datetime import datetime, timezone
from pathlib import Path

from integrate_tasks162_167 import BRANCH, ROOT, STANDARD_SHA, WORKTREE, git, git_blob_sha, safe_path, sha

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402
from prepare_publish_tasks189_190 import atomic_file  # noqa: E402

TASK = "TASK_207"
REPORT = "RULES/REPORT/TASK_207_REPORT_R1"
SO = "lib-core-graphics/src/main/jniLibs/arm64-v8a/libLayerFlow.so"
ARCHIVE = ".ai/ceo/reviews/TASK_206_GHIDRA_TECHNICAL_CACHE.zip"
ARCHIVE_SHA = "ab79218d80871b4eb3bc7471717324d73dde6defef18c72ee759cbbb8bdcee99"
REPLAY_SOURCE = Path("F:/CONVERT_WORKTREES/ceo-so45-20261008/TASK_207_CEO_REPLAY_19")
REPLAY_DEST = ".ai/ceo/reviews/TASK_207_CEO_REPLAY_SUCCESS"
REPLAY_SHA = "a5c973ff1dab25b351dfda3dbf6a7f68a93312adbe5c13dd2737b83b62c7ed3c"
LEDGER = "RULES/REPORT/CEO_SO45_ORCHESTRATION/ACCEPTED_INTERNAL_FDE_RESEARCH_207_R1.json"


def main():
    ctl = Controller(ROOT)
    lease = ctl.ceo_lease(ctl.read_json(ROOT / ".ai/locks.json"))
    if ctl.end_requested() or sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END or canonical changed")
    if git("branch", "--show-current").decode().strip() != BRANCH:
        raise RuntimeError("wrong owned branch")
    if git("diff", "--cached", "--name-only", "-z").strip(b"\0"):
        raise RuntimeError("owned index already staged")
    if git("status", "--short", "--", ".gitattributes").strip():
        raise RuntimeError("attributes have unrelated changes")
    state, tasks = ctl.read_json(ROOT / ".ai/ceo/state.json"), ctl.tasks()
    if not ctl.accepted(TASK, state, tasks, required_revision=1):
        raise RuntimeError("current accepted fingerprint absent")
    verdict = state["tasks"][TASK]["verdict"]
    report = safe_path(ROOT, REPORT)
    seal = json.loads((report / "COMPLETE.json").read_text(encoding="utf-8"))
    if (seal["task_id"], seal["revision"], seal["status"], seal["standard_sha256"],
            seal["target_fde_candidate_count"], seal["whole_fde_exact_body_c_like_count"],
            seal["rows_with_missing_fde_bytes"]) != (TASK, 1, "COMPLETE", STANDARD_SHA, 128, 122, 6):
        raise RuntimeError("critical seal fields changed")
    if sha(report / "COMPLETE.json") != "abe172a57571f93c0781e45d6dd193910021b9f49717df2222779ce72f8f6964":
        raise RuntimeError("seal bytes changed")
    if sha(safe_path(ROOT, SO)) != seal["original_so_sha256"]:
        raise RuntimeError("source SO differs")
    tree = git("ls-tree", "HEAD", "--", SO).decode().split()
    if len(tree) < 3 or tree[2] != git_blob_sha(safe_path(ROOT, SO)):
        raise RuntimeError("owned branch SO differs")
    if sha(safe_path(ROOT, ARCHIVE)) != ARCHIVE_SHA or not git("ls-tree", "HEAD", "--", ARCHIVE).strip():
        raise RuntimeError("existing unreviewed technical-cache archive differs")
    actual = {p.relative_to(report).as_posix() for p in report.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json", "PROGRESS.md"}
    if actual != set(seal["files"]):
        raise RuntimeError("report inventory differs")
    replay = json.loads((REPLAY_SOURCE / "summary.json").read_text(encoding="utf-8"))
    if (sha(REPLAY_SOURCE / "summary.json") != REPLAY_SHA or replay["exit_code"] != 0
            or replay["rows"] != 19 or replay["mismatches_excluding_elapsed_ms"]):
        raise RuntimeError("independent replay differs")
    paths = {}

    def add(relative, expected=None):
        path = safe_path(ROOT, relative)
        if not path.is_file():
            raise RuntimeError("missing: " + relative)
        digest = sha(path)
        if expected is not None and digest != expected:
            raise RuntimeError("hash differs: " + relative)
        if relative in paths and paths[relative] != digest:
            raise RuntimeError("path conflict: " + relative)
        paths[relative] = digest

    for relative, digest in seal["files"].items():
        add(REPORT + "/" + relative, digest)
    for relative, digest in seal["code_files"].items():
        add(relative, digest)
    add(REPORT + "/COMPLETE.json")
    add("RULES/TASK/TASK_207_SO45_CODEX_INTERNAL_ACTIVE.md", seal["task_sha256"])
    add(".ai/ceo/reviews/TASK_207_internal_targets.json", seal["target_manifest_sha256"])
    add(verdict["review_file"], verdict["review_sha256"])
    for relative in (".ai/ceo/reviews/publish_task207.py", ".ai/ceo/reviews/audit_task207.py",
                     ".ai/ceo/reviews/replay_task207_19.py", ".ai/ceo/reviews/integrate_task207.py"):
        add(relative)
    for name in ("ghidra_raw.ndjson", "stdout.log", "stderr.log", "summary.json", "targets.tsv"):
        destination = safe_path(ROOT, REPLAY_DEST + "/" + name)
        ctl.authorized(lease, destination)
        destination.parent.mkdir(parents=True, exist_ok=True)
        if destination.exists() and sha(destination) != sha(REPLAY_SOURCE / name):
            raise RuntimeError("replay destination differs: " + name)
        if not destination.exists():
            shutil.copyfile(REPLAY_SOURCE / name, destination)
        add(REPLAY_DEST + "/" + name, sha(REPLAY_SOURCE / name))
    for relative, digest in paths.items():
        destination = safe_path(WORKTREE, relative)
        ctl.authorized(lease, destination)
        if destination.exists() and sha(destination) != digest:
            raise RuntimeError("owned destination differs: " + relative)
        if git("ls-tree", "HEAD", "--", relative).strip():
            raise RuntimeError("path already tracked: " + relative)
    ledger_path = safe_path(ROOT, LEDGER)
    ctl.authorized(lease, ledger_path)
    if ledger_path.exists():
        raise RuntimeError("ledger already exists")
    ledger = {
        "schema_version": "2.1.2", "generated_at": datetime.now(timezone.utc).isoformat(),
        "task_id": TASK, "revision": 1, "branch": BRANCH,
        "ceo_fencing_token": lease["fencing_token"], "fingerprint": verdict["fingerprint"],
        "review_sha256": verdict["review_sha256"], "complete_sha256": sha(report / "COMPLETE.json"),
        "research_disposition": "ACCEPTED_BOUNDED_PARTIAL_STATIC_FDE_BOUNDARY",
        "source_so_sha256": seal["original_so_sha256"], "source_so_git_blob": tree[2],
        "target_candidates": 128, "whole_fde_exact_body_c_like_count": 122,
        "missing_fde_byte_rows": 6, "missing_fde_bytes": 368,
        "technical_cache_status": "UNREVIEWED_INPUT_ONLY", "technical_cache_archive": ARCHIVE,
        "technical_cache_archive_sha256": ARCHIVE_SHA,
        "independent_replay": REPLAY_DEST + "/summary.json", "independent_replay_sha256": REPLAY_SHA,
        "files": paths, "behavior_equivalence_proven": False,
        "all_45_so_complete": False, "product_phase_pass": False, "v4_opened": False,
    }
    atomic_file(ledger_path, (json.dumps(ledger, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))
    add(LEDGER)
    for relative, digest in paths.items():
        destination = safe_path(WORKTREE, relative)
        destination.parent.mkdir(parents=True, exist_ok=True)
        if not destination.exists():
            shutil.copyfile(safe_path(ROOT, relative), destination)
        if sha(destination) != digest:
            raise RuntimeError("copy differs: " + relative)
    attributes = WORKTREE / ".gitattributes"
    ctl.authorized(lease, attributes)
    original = attributes.read_bytes()
    lines = set(original.decode("utf-8").splitlines())
    additions = [f"/{relative} -text" for relative in sorted(paths)
                 if f"/{relative} -text" not in lines]
    if additions:
        attributes.write_bytes(original + ("\n".join(additions) + "\n").encode("utf-8"))
    git("add", "--", ".gitattributes")
    ordered = sorted(paths)
    for start in range(0, len(ordered), 75):
        git("add", "--", *ordered[start:start + 75])
    staged = {x for x in git("diff", "--cached", "--name-only", "-z").decode().split("\0") if x}
    if staged != set(paths) | {".gitattributes"}:
        raise RuntimeError("unexpected staged paths")
    for relative in paths:
        row = git("ls-files", "--stage", "--", relative).decode().split()
        if len(row) < 2 or row[1] != git_blob_sha(safe_path(ROOT, relative)):
            raise RuntimeError("index blob mismatch: " + relative)
    print(json.dumps({"status": "STAGED_EXACT_BYTES", "task_id": TASK,
                      "paths": len(paths), "ledger_sha256": sha(ledger_path),
                      "replay_rows": 19}))


if __name__ == "__main__":
    main()

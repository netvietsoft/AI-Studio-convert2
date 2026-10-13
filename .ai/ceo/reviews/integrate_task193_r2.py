"""Stage accepted TASK_193 raw R1 evidence and R2 label overlay exactly."""

import json
import shutil
import sys
from datetime import datetime, timezone
from pathlib import Path

from integrate_tasks162_167 import BRANCH, ROOT, STANDARD_SHA, WORKTREE, git, git_blob_sha, safe_path, sha

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402


R1 = "RULES/REPORT/TASK_193_REPORT_R1"
R2 = "RULES/REPORT/TASK_193_REPORT_R2"
R1_ARCHIVE = ".ai/ceo/reviews/TASK_193_R1_TASK_ARCHIVE_2b54c486f2acb3702bb966d65809381c75121825a35c13592e217d7e5769e9f0.md"
R1_REVIEW = ".ai/ceo/reviews/TASK_193-1949fc2bf631717871e80b7e35f862f9d9c0232084184ce8d0cb78d6957d5202.md"
LEDGER = "RULES/REPORT/CEO_SO45_ORCHESTRATION/ACCEPTED_INTERNAL_FDE_RESEARCH_193_R2.json"


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical changed")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    if git("branch", "--show-current").decode().strip() != BRANCH:
        raise RuntimeError("wrong owned branch")
    if not WORKTREE.resolve().is_relative_to(Path("F:/CONVERT_WORKTREES/ceo-so45-20261008").resolve()):
        raise RuntimeError("unexpected owned worktree")
    if git("diff", "--cached", "--name-only", "-z").strip(b"\0"):
        raise RuntimeError("index already staged")
    state = ctl.read_json(ROOT / ".ai/ceo/state.json")
    if not ctl.accepted("TASK_193", state, ctl.tasks(), required_revision=2):
        raise RuntimeError("current R2 acceptance absent")
    verdict = state["tasks"]["TASK_193"]["verdict"]
    if verdict["disposition"] != "ACCEPTED" or verdict["revision"] != 2:
        raise RuntimeError("wrong R2 verdict")
    seal1 = json.loads(safe_path(ROOT, R1 + "/COMPLETE.json").read_text(encoding="utf8"))
    seal2 = json.loads(safe_path(ROOT, R2 + "/COMPLETE.json").read_text(encoding="utf8"))
    if (seal1["task_id"], seal1["revision"], seal1["status"]) != ("TASK_193", 1, "COMPLETE"):
        raise RuntimeError("R1 seal invalid")
    if (seal2["task_id"], seal2["revision"], seal2["status"]) != ("TASK_193", 2, "COMPLETE"):
        raise RuntimeError("R2 seal invalid")
    if seal1["standard_sha256"] != STANDARD_SHA or seal2["standard_sha256"] != STANDARD_SHA:
        raise RuntimeError("standard hash mismatch")
    if sha(safe_path(ROOT, R1 + "/COMPLETE.json")) != seal2["r1_complete_sha256"]:
        raise RuntimeError("R1 baseline changed")
    if sha(safe_path(ROOT, R1_ARCHIVE)) != seal1["task_sha256"]:
        raise RuntimeError("R1 task archive changed")
    if sha(safe_path(ROOT, R1_REVIEW)) != seal2["ceo_r1_review_sha256"]:
        raise RuntimeError("R1 review changed")
    if sha(safe_path(ROOT, "RULES/TASK/TASK_193_SO45_CODEX_INTERNAL_ACTIVE.md")) != seal2["task_sha256"]:
        raise RuntimeError("R2 task changed")
    if sha(safe_path(ROOT, ".ai/ceo/reviews/TASK_193_internal_targets.json")) != seal2["target_manifest_sha256"]:
        raise RuntimeError("manifest changed")
    if sha(safe_path(ROOT, verdict["review_file"])) != verdict["review_sha256"]:
        raise RuntimeError("R2 review changed")
    paths = {}

    def add(relative, expected=None):
        path = safe_path(ROOT, relative)
        if not path.is_file():
            raise RuntimeError("missing source: " + relative)
        digest = sha(path)
        if expected is not None and digest != expected:
            raise RuntimeError("source hash changed: " + relative)
        if relative in paths and paths[relative] != digest:
            raise RuntimeError("path hash conflict: " + relative)
        paths[relative] = digest

    report1 = safe_path(ROOT, R1)
    actual1 = {p.relative_to(report1).as_posix() for p in report1.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json", "PROGRESS.md"}
    if actual1 != set(seal1["files"]) or len(actual1) != 143:
        raise RuntimeError("R1 inventory changed")
    for relative, expected in seal1["files"].items():
        add(R1 + "/" + relative, expected)
    for relative, expected in seal1["code_files"].items():
        add(relative, expected)
    for relative, expected in seal1["scratch_files"].items():
        add(relative, expected)
    add(R1 + "/COMPLETE.json")
    report2 = safe_path(ROOT, R2)
    actual2 = {p.relative_to(report2).as_posix() for p in report2.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json", "PROGRESS.md"}
    if actual2 != set(seal2["files"]) or len(actual2) != 4:
        raise RuntimeError("R2 inventory changed")
    for relative, expected in seal2["files"].items():
        add(R2 + "/" + relative, expected)
    for relative, expected in seal2["code_files"].items():
        add(relative, expected)
    add(R2 + "/COMPLETE.json")
    for relative in (R1_ARCHIVE, R1_REVIEW,
                     "RULES/TASK/TASK_193_SO45_CODEX_INTERNAL_ACTIVE.md",
                     ".ai/ceo/reviews/TASK_193_internal_targets.json",
                     verdict["review_file"],
                     ".ai/ceo/reviews/prepare_publish_task193.py",
                     ".ai/ceo/reviews/publish_task193_r2.py",
                     ".ai/ceo/reviews/verify_task193_r1.py",
                     ".ai/ceo/reviews/verify_task193_r2.py",
                     ".ai/ceo/reviews/rerun_task193_ghidra.py",
                     ".ai/ceo/reviews/integrate_task193_r2.py"):
        add(relative)
    for folder in (".ai/ceo/reviews/TASK_193_CEO_REPLAY",
                   ".ai/ceo/reviews/TASK_193_CEO_REPLAY_RETRY"):
        for path in sorted(safe_path(ROOT, folder).rglob("*")):
            if path.is_file():
                add(path.relative_to(ROOT).as_posix())
    for relative, expected in paths.items():
        destination = safe_path(WORKTREE, relative)
        ctl.authorized(lease, destination)
        if destination.exists() and sha(destination) != expected:
            raise RuntimeError("destination differs: " + relative)
        if git("ls-tree", "HEAD", "--", relative).strip():
            raise RuntimeError("path already tracked: " + relative)
    ledger_path = safe_path(ROOT, LEDGER)
    ctl.authorized(lease, ledger_path)
    if ledger_path.exists():
        raise RuntimeError("ledger exists")
    ledger = {"schema_version": "2.1.2", "generated_at": datetime.now(timezone.utc).isoformat(),
              "branch": BRANCH, "task_id": "TASK_193", "accepted_revision": 2,
              "fingerprint": verdict["fingerprint"], "review_sha256": verdict["review_sha256"],
              "r1_complete_sha256": sha(report1 / "COMPLETE.json"),
              "r2_complete_sha256": sha(report2 / "COMPLETE.json"),
              "research_disposition": "ACCEPTED_BOUNDED_PARTIAL_STATIC_RESEARCH_LABEL_OVERLAY",
              "candidates": 60, "corrected_summary_labels": 60,
              "oversized_excluded_indices": [201,211,216,235],
              "behavior_equivalence_proven": False, "all_45_so_complete": False,
              "product_phase_pass": False, "v4_opened": False, "files": paths}
    ledger_path.write_text(json.dumps(ledger, ensure_ascii=False, indent=2) + "\n", encoding="utf8")
    add(LEDGER)
    for relative, expected in paths.items():
        destination = safe_path(WORKTREE, relative)
        destination.parent.mkdir(parents=True, exist_ok=True)
        if not destination.exists():
            shutil.copyfile(safe_path(ROOT, relative), destination)
        if sha(destination) != expected:
            raise RuntimeError("copy differs: " + relative)
    attributes = WORKTREE / ".gitattributes"
    ctl.authorized(lease, attributes)
    original = attributes.read_bytes()
    lines = set(original.decode("utf8").splitlines())
    additions = [f"/{relative} -text" for relative in sorted(paths) if f"/{relative} -text" not in lines]
    attributes.write_bytes(original + ("\n".join(additions) + "\n").encode("utf8"))
    git("add", "--", ".gitattributes")
    ordered = sorted(paths)
    for start in range(0, len(ordered), 75):
        git("add", "--", *ordered[start:start+75])
    staged = {x for x in git("diff", "--cached", "--name-only", "-z").decode().split("\0") if x}
    if staged != set(paths) | {".gitattributes"}:
        raise RuntimeError("unexpected staged paths")
    for relative in paths:
        row = git("ls-files", "--stage", "--", relative).decode().split()
        if len(row) < 2 or row[1] != git_blob_sha(safe_path(ROOT, relative)):
            raise RuntimeError("index blob mismatch: " + relative)
    print(json.dumps({"status": "STAGED_EXACT_BYTES", "task": "TASK_193", "revision": 2,
                      "paths": len(paths), "ledger_sha256": sha(ledger_path)}))


if __name__ == "__main__":
    main()

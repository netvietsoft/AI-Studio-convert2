"""Copy the accepted pinned Ghidra project and emit the exact seven-row input."""
from __future__ import annotations

import json
from pathlib import Path
import shutil

from extract_original import ROOT, REPORT, TARGETS, check_lease, sha, write_json

SOURCE_PROJECT = ROOT / "RESEARCH_WORK/TASK_204_R1/ghidra_project"
PROJECT_INDEX = ROOT / "RULES/REPORT/TASK_204_REPORT_R1/source_project_index.json"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_210_R1"
COPY = SCRATCH / "ghidra_project"


def main() -> None:
    check_lease()
    if SCRATCH.exists() or (REPORT / "project_copy_index.json").exists():
        raise RuntimeError("TASK_210 private project already started")
    reference = json.loads(PROJECT_INDEX.read_text(encoding="utf-8"))
    if reference["source_sha256"] != "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4":
        raise RuntimeError("accepted project source identity mismatch")
    files = reference["project_files"]
    for entry in files:
        path = SOURCE_PROJECT / entry["relative_path"]
        if not path.is_file() or sha(path) != entry["sha256"]:
            raise RuntimeError(f"accepted private project changed: {path}")
    check_lease()
    shutil.copytree(SOURCE_PROJECT, COPY)
    for entry in files:
        path = COPY / entry["relative_path"]
        if not path.is_file() or sha(path) != entry["sha256"]:
            raise RuntimeError(f"copied project differs: {path}")
    targets = json.loads(TARGETS.read_text(encoding="utf-8"))["targets"]
    lines = [f"{t['global_nonexport_fde_index']}\t{t['elf_va']}\t{t['size_bytes']}\t{t['body_sha256']}"
             for t in targets]
    tsv = SCRATCH / "targets.tsv"
    tsv.write_text("\n".join(lines) + "\n", encoding="ascii", newline="\n")
    write_json(REPORT / "project_copy_index.json", {
        "task_id": "TASK_210", "revision": 1,
        "accepted_reference": str(PROJECT_INDEX.relative_to(ROOT)).replace("\\", "/"),
        "accepted_reference_sha256": sha(PROJECT_INDEX),
        "project_source": str(SOURCE_PROJECT), "project_copy": str(COPY),
        "project_name": reference["project_name"], "project_files": files,
        "targets_tsv": str(tsv), "targets_tsv_sha256": sha(tsv),
        "target_count": len(targets),
        "claim_limit": "technical byte-identical project input, not semantic proof"})
    print(json.dumps({"project_files": len(files), "targets": len(targets), "tsv_sha256": sha(tsv)}))


if __name__ == "__main__":
    main()

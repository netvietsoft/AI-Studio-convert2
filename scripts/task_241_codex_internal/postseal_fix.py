"""Correct a TASK_241 progress metadata field, then reseal task-owned hashes."""
import json
from pathlib import Path

from run import AGENT, FENCE, HERE, LEASE, REPORT, ROOT, guard, json_write, now, sha, write


def main() -> None:
    guard()
    complete_path = REPORT / "COMPLETE.json"
    complete = json.loads(complete_path.read_text(encoding="utf-8"))
    assert (complete["task_id"], complete["revision"], complete["lease_id"],
            complete["fencing_token"]) == ("TASK_241", 1, LEASE, FENCE)
    for rel, digest in complete["files"].items():
        assert sha(REPORT / rel) == digest, rel
    for rel, digest in complete["code_files"].items():
        if not rel.endswith("seal.py"):
            assert sha(ROOT / rel) == digest, rel
    progress = json.loads((REPORT / "PROGRESS.json").read_text(encoding="utf-8"))
    assert progress.pop("prior_deferred_oversized_global_indices") == []
    progress["prior_disposition_reference"] = (
        "Prior oversized cases retain their own task dispositions; not reassessed in TASK_241"
    )
    progress["generated_at"] = now()
    json_write(REPORT / "PROGRESS.json", progress)
    write(REPORT / "02_CORRECTION.md", (
        "# TASK_241 progress metadata correction\n\n"
        "Removed an empty prior-deferred list that could imply prior oversized cases had been cleared. "
        "Earlier tasks retain their own dispositions; TASK_241 has zero current-slice oversized skips. "
        "Raw Ghidra and original-source evidence are unchanged.\n"
    ).encode("utf-8"))
    complete["files"] = {p.relative_to(REPORT).as_posix(): sha(p)
                         for p in sorted(REPORT.rglob("*"))
                         if p.is_file() and p.name not in ("COMPLETE.json", "PROGRESS.json")}
    complete["code_files"] = {p.relative_to(ROOT).as_posix(): sha(p)
                              for p in sorted(HERE.rglob("*")) if p.is_file()}
    complete["generated_at"] = now()
    json_write(complete_path, complete)
    assert all(sha(REPORT / rel) == digest for rel, digest in complete["files"].items())
    assert all(sha(ROOT / rel) == digest for rel, digest in complete["code_files"].items())
    print(json.dumps({"complete_sha256": sha(complete_path),
                      "report_files": len(complete["files"]),
                      "code_files": len(complete["code_files"])}))


if __name__ == "__main__":
    main()

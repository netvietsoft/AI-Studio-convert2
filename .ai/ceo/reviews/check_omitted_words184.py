"""Run the independent omitted-word check on the CEO's immutable project copy."""
import json
import sys

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested():
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    project = WORKTREE / "review_task184_ghidra_project"
    area = OUT / "TASK_184_CEO_REPLAY"
    target = area / "all_targets.tsv"
    output = area / "omitted_words.ndjson"
    script = OUT / "ReviewOmittedWords184.java"
    ctl.authorized(lease, output)
    if not target.is_file() or output.exists():
        raise RuntimeError("target missing or output exists")
    before = hashes(project)
    run(ctl, lease, area / "omitted_words", project, "Task184", "libVERenderer.so",
        script, [str(target), str(output)])
    if hashes(project) != before:
        raise RuntimeError("project changed")
    rows = [json.loads(line) for line in output.read_text(encoding="utf8").splitlines() if line]
    if len(rows) != 141:
        raise RuntimeError("row count mismatch")
    print(json.dumps({"rows": len(rows), "missing": sum(row["missing_instruction_slots"] for row in rows),
                      "nonexact_indices": [row["index"] for row in rows if row["missing_instruction_slots"]]}))


if __name__ == "__main__":
    main()

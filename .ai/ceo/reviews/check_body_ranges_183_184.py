"""Independently check Ghidra function-body membership beyond min/max endpoints."""

import json
import sys
from pathlib import Path

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, run

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402


def main() -> None:
    ctl = Controller(ROOT)
    if ctl.end_requested():
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    assert lease["fencing_token"] == 1133
    script = OUT / "ReviewBodyRanges.java"
    for number, project_name, program in ((183, "SmallLib153", "libMTGif.so"),
                                          (184, "Task184", "libVERenderer.so")):
        root = OUT / f"TASK_{number}_CEO_REPLAY"
        project = WORKTREE / f"review_task{number}_ghidra_project"
        if number == 183:
            target = ROOT / "RESEARCH_WORK/TASK_183_R1/target_batch.tsv"
        else:
            target = root / "all_targets.tsv"
            ctl.authorized(lease, target)
            assert not target.exists()
            parts = [ROOT / f"RULES/REPORT/TASK_184_REPORT_R1/ghidra/chunk_{i:02d}/targets.tsv"
                     for i in (1, 2, 3)]
            target.write_bytes(b"".join(p.read_bytes() for p in parts))
        output = root / "body_ranges.ndjson"
        ctl.authorized(lease, output)
        assert not output.exists()
        run(ctl, lease, root / "body_ranges", project, project_name, program,
            script, [str(target), str(output)])
        rows = [json.loads(s) for s in output.read_text(encoding="utf-8").splitlines() if s]
        assert len(rows) == (51 if number == 183 else 141)
        result = {"task": number, "rows": len(rows),
                  "function_entries": sum(x["function_at_start"] for x in rows),
                  "body_exact_fde": sum(x["body_equals_fde"] for x in rows),
                  "not_exact": [x["index"] for x in rows if not x["body_equals_fde"]]}
        print(json.dumps(result), flush=True)


if __name__ == "__main__":
    main()

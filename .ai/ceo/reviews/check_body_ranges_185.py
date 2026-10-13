"""Audit TASK_185 Ghidra body membership independently after finding endpoint masking."""
import json
import sys
from pathlib import Path

from rerun_task183_184_ghidra import ROOT, OUT, run, hashes
from rerun_task185_ghidra import DEST

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested():
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    area = OUT / "TASK_185_CEO_REPLAY"
    target = area / "targets.tsv"
    output = area / "body_ranges.ndjson"
    ctl.authorized(lease, output)
    if not target.exists() or output.exists():
        raise RuntimeError("target absent or output exists")
    before = hashes(DEST)
    script = OUT / "ReviewBodyRanges.java"
    run(ctl, lease, area / "body_ranges", DEST, "PVGColor168",
        "libPVGColorFunctions.so", script, [str(target), str(output)])
    if hashes(DEST) != before:
        raise RuntimeError("project changed")
    rows = [json.loads(line) for line in output.read_text(encoding="utf8").splitlines() if line]
    if len(rows) != 128:
        raise RuntimeError("row count mismatch")
    print(json.dumps({"rows": len(rows), "exact": sum(r["body_equals_fde"] for r in rows),
                      "nonexact_indices": [r["index"] for r in rows if not r["body_equals_fde"]]}))


if __name__ == "__main__":
    main()

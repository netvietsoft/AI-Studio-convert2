"""CEO replay of TASK_185 in the extractor's supported 32-row chunks."""

import json
import os
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

from rerun_task185_ghidra import (ROOT, DEST, SOURCE_PROJECT, OUT, MANIFEST,
                                  SCRIPT, GHIDRA, JAVA, STANDARD_SHA, sha)

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402


def utc() -> str:
    return datetime.now(timezone.utc).isoformat()


def main() -> None:
    ctl = Controller(ROOT)
    if ctl.end_requested():
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    assert lease["fencing_token"] == 1133
    assert sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == STANDARD_SHA
    prior = json.loads((OUT / "command.json").read_text(encoding="utf-8"))
    assert prior["exit_code"] == 0 and prior["raw_output_sha256"] is None
    assert "expected 1..32 candidates" in (OUT / "stdout.log").read_text(encoding="utf-8")
    original_project = {p.relative_to(SOURCE_PROJECT).as_posix(): sha(p)
                        for p in SOURCE_PROJECT.rglob("*") if p.is_file()}
    copy_before = {p.relative_to(DEST).as_posix(): sha(p)
                   for p in DEST.rglob("*") if p.is_file()}
    assert original_project == copy_before and len(copy_before) == 9
    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    assert len(manifest["targets"]) == 128

    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA)
    env["PATH"] = str(JAVA / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    receipts = []
    for chunk in range(4):
        if ctl.end_requested():
            raise RuntimeError("END_AGENT_SESSION=TRUE")
        area = OUT / f"round2_chunk_{chunk:02d}"
        assert not area.exists()
        for path in (area, area / "targets.tsv", area / "ghidra_raw.ndjson",
                     area / "stdout.log", area / "stderr.log", area / "command.json"):
            ctl.authorized(lease, path)
        area.mkdir()
        subset = manifest["targets"][32 * chunk:32 * (chunk + 1)]
        target = area / "targets.tsv"
        target.write_text("".join(
            f"{32 * chunk + i}\t{row['elf_va']}\t{row['size_bytes']}\t{row['body_sha256']}\n"
            for i, row in enumerate(subset, 1)), encoding="utf-8", newline="\n")
        raw = area / "ghidra_raw.ndjson"
        command = [str(GHIDRA), str(DEST), "PVGColor168", "-process",
                   "libPVGColorFunctions.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
                   "-scriptPath", str(SCRIPT.parent), "-postScript", SCRIPT.name,
                   str(target), str(raw)]
        started = utc()
        tick = time.monotonic()
        with (area / "stdout.log").open("wb") as stdout, (area / "stderr.log").open("wb") as stderr:
            process = subprocess.Popen(command, stdin=subprocess.DEVNULL, stdout=stdout,
                                       stderr=stderr, env=env)
            try:
                code = process.wait(timeout=1200)
            except subprocess.TimeoutExpired:
                process.kill()
                process.wait()
                code = -1
        receipt = {"task_id": "TASK_185", "review_actor": "Codex_CEO",
                   "fencing_token": lease["fencing_token"], "chunk": chunk,
                   "started_at": started, "ended_at": utc(),
                   "elapsed_seconds": time.monotonic() - tick,
                   "exit_code": code, "command": command,
                   "targets_sha256": sha(target), "script_sha256": sha(SCRIPT),
                   "manifest_sha256": sha(MANIFEST),
                   "stdout_sha256": sha(area / "stdout.log"),
                   "stderr_sha256": sha(area / "stderr.log"),
                   "raw_output_sha256": sha(raw) if raw.exists() else None}
        (area / "command.json").write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + "\n",
                                           encoding="utf-8", newline="\n")
        assert code == 0 and raw.exists(), receipt
        assert "REPORT SCRIPT ERROR" not in (area / "stdout.log").read_text(encoding="utf-8")
        rows = [json.loads(line) for line in raw.read_text(encoding="utf-8").splitlines() if line]
        assert len(rows) == 32 and [x["index"] for x in rows] == list(range(32 * chunk + 1, 32 * chunk + 33))
        receipts.append(receipt)
        print(json.dumps({"chunk": chunk, "rows": len(rows),
                          "c_like": sum(x["c_like_present"] for x in rows),
                          "exact_fde": sum(x["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE" for x in rows),
                          "elapsed_seconds": round(receipt["elapsed_seconds"], 3)}), flush=True)
    copy_after = {p.relative_to(DEST).as_posix(): sha(p)
                  for p in DEST.rglob("*") if p.is_file()}
    assert copy_after == copy_before
    summary = {"result": "PASS", "task_id": "TASK_185", "chunks": len(receipts),
               "project_source_and_copy_sha256": copy_before,
               "total_seconds": sum(x["elapsed_seconds"] for x in receipts),
               "receipts_sha256": [sha(OUT / f"round2_chunk_{i:02d}/command.json") for i in range(4)]}
    path = OUT / "round2_summary.json"
    ctl.authorized(lease, path)
    path.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n",
                    encoding="utf-8", newline="\n")
    print(json.dumps(summary, sort_keys=True), flush=True)


if __name__ == "__main__":
    main()

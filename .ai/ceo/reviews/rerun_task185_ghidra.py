"""CEO replay of all TASK_185 Ghidra rows on a separate owned project copy."""

import hashlib
import json
import os
import shutil
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402

DEST = Path("F:/CONVERT_WORKTREES/ceo-so45-20261008/review_task185_ghidra_project")
SOURCE_PROJECT = ROOT / "RESEARCH_WORK/TASK_185_R1/ghidra_project"
OUT = ROOT / ".ai/ceo/reviews/TASK_185_CEO_REPLAY"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_185_internal_targets.json"
SCRIPT = ROOT / "scripts/task_185_codex_internal/ExportInternal185.java"
GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC/support/analyzeHeadless.bat")
JAVA = Path("F:/TOOLS/jdk-21.0.12.1+1")
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def utc() -> str:
    return datetime.now(timezone.utc).isoformat()


def main() -> None:
    ctl = Controller(ROOT)
    if ctl.end_requested():
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    assert lease["fencing_token"] == 1133
    assert sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == STANDARD_SHA
    assert not DEST.exists() and not OUT.exists()
    for path in [DEST, OUT, OUT / "targets.tsv", OUT / "ghidra_raw.ndjson",
                 OUT / "stdout.log", OUT / "stderr.log", OUT / "command.json"]:
        ctl.authorized(lease, path)
    assert GHIDRA.is_file() and (JAVA / "bin/java.exe").is_file() and SCRIPT.is_file()

    source_files = {p.relative_to(SOURCE_PROJECT).as_posix(): sha(p)
                    for p in SOURCE_PROJECT.rglob("*") if p.is_file()}
    assert len(source_files) == 9
    shutil.copytree(SOURCE_PROJECT, DEST)
    copied_files = {p.relative_to(DEST).as_posix(): sha(p) for p in DEST.rglob("*") if p.is_file()}
    assert copied_files == source_files

    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    assert manifest["task_id"] == "TASK_185" and len(manifest["targets"]) == 128
    OUT.mkdir()
    target = OUT / "targets.tsv"
    target.write_text("".join(
        f"{i}\t{row['elf_va']}\t{row['size_bytes']}\t{row['body_sha256']}\n"
        for i, row in enumerate(manifest["targets"], 1)), encoding="utf-8", newline="\n")
    raw = OUT / "ghidra_raw.ndjson"
    command = [str(GHIDRA), str(DEST), "PVGColor168", "-process",
               "libPVGColorFunctions.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPT.parent), "-postScript", SCRIPT.name,
               str(target), str(raw)]
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA)
    env["PATH"] = str(JAVA / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    started = utc()
    tick = time.monotonic()
    with (OUT / "stdout.log").open("wb") as stdout, (OUT / "stderr.log").open("wb") as stderr:
        process = subprocess.Popen(command, stdin=subprocess.DEVNULL, stdout=stdout,
                                   stderr=stderr, env=env)
        try:
            code = process.wait(timeout=1200)
        except subprocess.TimeoutExpired:
            process.kill()
            process.wait()
            code = -1
    elapsed = time.monotonic() - tick
    receipt = {"task_id": "TASK_185", "review_actor": "Codex_CEO",
               "fencing_token": lease["fencing_token"], "started_at": started,
               "ended_at": utc(), "elapsed_seconds": elapsed, "exit_code": code,
               "command": command, "source_project_files_sha256": source_files,
               "copied_project_files_sha256_before": copied_files,
               "copied_project_files_sha256_after": {
                   p.relative_to(DEST).as_posix(): sha(p) for p in DEST.rglob("*") if p.is_file()},
               "targets_sha256": sha(target), "script_sha256": sha(SCRIPT),
               "manifest_sha256": sha(MANIFEST),
               "stdout_sha256": sha(OUT / "stdout.log"),
               "stderr_sha256": sha(OUT / "stderr.log"),
               "raw_output_sha256": sha(raw) if raw.exists() else None}
    (OUT / "command.json").write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + "\n",
                                      encoding="utf-8", newline="\n")
    assert code == 0 and raw.exists(), receipt
    assert receipt["copied_project_files_sha256_after"] == copied_files
    rows = [json.loads(line) for line in raw.read_text(encoding="utf-8").splitlines() if line]
    assert len(rows) == 128 and [x["index"] for x in rows] == list(range(1, 129))
    print(json.dumps({"result": "PASS", "rows": len(rows), "c_like": sum(x["c_like_present"] for x in rows),
                      "exact_fde": sum(x["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE"
                                       for x in rows), "elapsed_seconds": round(elapsed, 3),
                      "raw_sha256": receipt["raw_output_sha256"]}, sort_keys=True))


if __name__ == "__main__":
    main()

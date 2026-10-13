"""CEO-only, read-only Ghidra replay of TASK_183 and TASK_184 evidence."""

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

WORKTREE = Path("F:/CONVERT_WORKTREES/ceo-so45-20261008")
OUT = ROOT / ".ai/ceo/reviews"
GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC/support/analyzeHeadless.bat")
JAVA = Path("F:/TOOLS/jdk-21.0.12.1+1")
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def hashes(folder: Path) -> dict:
    return {p.relative_to(folder).as_posix(): sha(p)
            for p in folder.rglob("*") if p.is_file()}


def utc() -> str:
    return datetime.now(timezone.utc).isoformat()


def run(ctl: Controller, lease: dict, area: Path, project: Path,
        project_name: str, program: str, script: Path, args: list[str]) -> dict:
    if ctl.end_requested():
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    assert not area.exists()
    for path in [area, area / "stdout.log", area / "stderr.log", area / "command.json"]:
        ctl.authorized(lease, path)
    area.mkdir(parents=True)
    command = [str(GHIDRA), str(project), project_name, "-process", program,
               "-noanalysis", "-readOnly", "-max-cpu", "1", "-scriptPath", str(script.parent),
               "-postScript", script.name, *args]
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA)
    env["PATH"] = str(JAVA / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    start = utc()
    tick = time.monotonic()
    with (area / "stdout.log").open("wb") as stdout, (area / "stderr.log").open("wb") as stderr:
        proc = subprocess.Popen(command, stdin=subprocess.DEVNULL, stdout=stdout, stderr=stderr, env=env)
        try:
            exit_code = proc.wait(timeout=1200)
        except subprocess.TimeoutExpired:
            proc.kill()
            proc.wait()
            exit_code = -1
    result = {"started_at": start, "ended_at": utc(),
              "elapsed_seconds": time.monotonic() - tick,
              "exit_code": exit_code, "command": command,
              "script_sha256": sha(script),
              "stdout_sha256": sha(area / "stdout.log"),
              "stderr_sha256": sha(area / "stderr.log")}
    (area / "command.json").write_text(json.dumps(result, indent=2, ensure_ascii=False) + "\n",
                                       encoding="utf-8", newline="\n")
    assert exit_code == 0, result
    assert "REPORT SCRIPT ERROR" not in (area / "stdout.log").read_text(encoding="utf-8")
    return result


def project_copy(ctl: Controller, lease: dict, number: int) -> tuple[Path, dict]:
    source = ROOT / f"RESEARCH_WORK/TASK_{number}_R1/ghidra_project"
    dest = WORKTREE / f"review_task{number}_ghidra_project"
    assert not dest.exists()
    ctl.authorized(lease, dest)
    src_hash = hashes(source)
    assert len(src_hash) == 9
    shutil.copytree(source, dest)
    assert hashes(dest) == src_hash
    return dest, src_hash


def main() -> None:
    ctl = Controller(ROOT)
    if ctl.end_requested():
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    assert lease["fencing_token"] == 1133
    assert sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == STANDARD_SHA
    assert GHIDRA.is_file() and (JAVA / "bin/java.exe").is_file()

    for number in (183, 184):
        project, project_hash = project_copy(ctl, lease, number)
        root = OUT / f"TASK_{number}_CEO_REPLAY"
        assert not root.exists()
        ctl.authorized(lease, root)
        root.mkdir()
        if number == 183:
            script_dir = ROOT / "scripts/task_183_codex_internal"
            tsv = ROOT / "RESEARCH_WORK/TASK_183_R1/target_batch.tsv"
            raw = root / "ghidra_raw"
            ctl.authorized(lease, raw)
            result = run(ctl, lease, root / "extract", project, "SmallLib153", "libMTGif.so",
                         script_dir / "ExtractInternal183.java", [str(tsv), str(raw)])
            rows = sorted(raw.glob("*.json"))
            assert len(rows) == 51
            print(json.dumps({"task": number, "stage": "extract", "rows": len(rows),
                              "seconds": round(result["elapsed_seconds"], 3)}), flush=True)
            boundary = root / "ghidra_boundary_10.json"
            ctl.authorized(lease, boundary)
            result = run(ctl, lease, root / "boundary_10", project, "SmallLib153", "libMTGif.so",
                         script_dir / "RepairBoundary183.java", [str(boundary)])
            assert boundary.is_file()
            print(json.dumps({"task": number, "stage": "boundary_10",
                              "seconds": round(result["elapsed_seconds"], 3)}), flush=True)
            output_count = len(rows)
        else:
            script_dir = ROOT / "scripts/task_184_codex_internal"
            report = ROOT / "RULES/REPORT/TASK_184_REPORT_R1/ghidra"
            output_count = 0
            for chunk in (1, 2, 3):
                area = root / f"chunk_{chunk:02d}"
                target = report / f"chunk_{chunk:02d}/targets.tsv"
                candidates = area / "candidates"
                ctl.authorized(lease, candidates)
                result = run(ctl, lease, area, project, "Task184", "libVERenderer.so",
                             script_dir / "ExtractInternal184.java", [str(target), str(candidates)])
                rows = list(candidates.glob("candidate_*.json"))
                assert len(rows) == 47
                output_count += len(rows)
                print(json.dumps({"task": number, "chunk": chunk,
                                  "rows": len(rows), "seconds": round(result["elapsed_seconds"], 3)}), flush=True)
        assert hashes(project) == project_hash
        summary = {"task": number, "result": "PASS", "rows": output_count,
                   "source_project_files_sha256": project_hash,
                   "replay_project_files_sha256": hashes(project)}
        path = root / "summary.json"
        ctl.authorized(lease, path)
        path.write_text(json.dumps(summary, indent=2, ensure_ascii=False) + "\n",
                        encoding="utf-8", newline="\n")
        print(json.dumps({"task": number, "result": "PASS", "rows": output_count}), flush=True)


if __name__ == "__main__":
    main()

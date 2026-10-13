"""TASK_181 source/fragment verification and exactly one isolated Ghidra pass per target."""

from __future__ import annotations

import hashlib
import json
import os
import shutil
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
REPORT = ROOT / "RULES/REPORT/TASK_181_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_181_R1"
SCRIPT = ROOT / "scripts/task_181_codex_exports/Fragment181.java"
TASK = ROOT / "RULES/TASK/TASK_181_SO45_CODEX_CORRECTION_ACTIVE.md"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libffmpeg.so")
HIST_PROJECT = ROOT / "RESEARCH_WORK/TASK_173_R1/ghidra_project"
HIST_MANIFEST = ROOT / "RULES/REPORT/TASK_173_REPORT_R1/project_copy_manifest.json"
GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SOURCE_SHA = "d8df8c5cb7a6b5a7eb771782d74a38e0b8d3cfacd1fbef1ae67a96171e3325c9"
TASK_SHA = "be4d2d6bee8698f9920a24cc14e5657669649f536a7f885679d01b7eab638dbd"
LEASE = "LEASE-CEO-WORKER-TASK_181-R1"
DEADLINE = datetime.fromisoformat("2026-10-13T10:32:48.417200+00:00")
TARGETS = {
    2283: {"va": 0x658FE8, "size": 736, "sha": "94017dc1deb91f10d8a4fd18f131f5d7741d0512c73c533de6d9845fbe095cee", "fragment_start": 0x659200, "fragment_end": 0x6592C4},
    2330: {"va": 0x65AEA8, "size": 232, "sha": "0b7e289d57ad0368923c5a802869b755b47eb70e43ff290fcd1096388ca46439", "fragment_start": 0x65AF24, "fragment_end": 0x65AF8C},
}


def now() -> str:
    return datetime.now(timezone.utc).isoformat()


def digest(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def write_json(path: Path, value: dict) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def require_lease() -> dict:
    if TASK.exists() is False or digest(TASK) != TASK_SHA:
        raise RuntimeError("exact ACTIVE task text changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.exists() and "TRUE" in flag.read_text(encoding="utf-8").upper().split():
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    data = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [x for x in data["active_locks"] if x.get("lease_id") == LEASE]
    if len(matches) != 1:
        raise RuntimeError("exact lease missing")
    lock = matches[0]
    if (lock.get("agent_id") != "/root/so45_ai_model_search" or lock.get("status") != "ACTIVE"
            or lock.get("task_sha") != TASK_SHA or lock.get("fencing_token") != 1211
            or datetime.fromisoformat(lock["expiry"]) <= datetime.now(timezone.utc)):
        raise RuntimeError("exact lease invalid/expired")
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError("task deadline reached")
    return lock


def validate_source() -> dict:
    if digest(SOURCE) != SOURCE_SHA:
        raise RuntimeError("pinned original source SHA mismatch")
    results = []
    dis = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        dynsym = elf.get_section_by_name(".dynsym")
        if dynsym is None:
            raise RuntimeError("original dynsym missing")
        export_vas = {s["st_value"] for s in dynsym.iter_symbols() if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF" and s["st_size"] > 0 and s["st_value"] > 0}
        if len(export_vas) != 2461:
            raise RuntimeError("original unique export VA count changed")
        loads = [s for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
        for index, item in TARGETS.items():
            va, size = item["va"], item["size"]
            if va not in export_vas:
                raise RuntimeError(f"target {index} not an original exported VA")
            symbols = [s for s in dynsym.iter_symbols() if s["st_value"] == va and s["st_info"]["type"] == "STT_FUNC" and s["st_size"] == size]
            if not symbols:
                raise RuntimeError(f"target {index} size/symbol not in dynsym")
            matches = [s for s in loads if s["p_vaddr"] <= va and va + size <= s["p_vaddr"] + s["p_filesz"]]
            if len(matches) != 1:
                raise RuntimeError(f"target {index} not within exactly one file-backed PT_LOAD")
            segment = matches[0]
            offset = segment["p_offset"] + va - segment["p_vaddr"]
            stream.seek(offset)
            body = stream.read(size)
            if hashlib.sha256(body).hexdigest() != item["sha"]:
                raise RuntimeError(f"target {index} original body SHA mismatch")
            instructions = list(dis.disasm(body, va))
            if len(instructions) != size // 4 or any(x.address != va + 4 * i or x.size != 4 for i, x in enumerate(instructions)):
                raise RuntimeError(f"target {index} original instruction coverage incomplete")
            fstart, fend = item["fragment_start"], item["fragment_end"]
            frag = body[fstart - va:fend - va + 4]
            assembled = [f"0x{x.address:x}: {x.mnemonic} {x.op_str}".rstrip() for x in instructions]
            (REPORT / f"source_assembly_{index}.txt").write_text("\n".join(assembled) + "\n", encoding="utf-8")
            results.append({"index": index, "elf_va": hex(va), "symbol_names": sorted({s.name for s in symbols}), "size_bytes": size,
                            "source_file_offset": hex(offset), "pt_load_vaddr": hex(segment["p_vaddr"]), "pt_load_offset": hex(segment["p_offset"]),
                            "body_sha256": item["sha"], "instruction_count": len(instructions), "fragment_start": hex(fstart), "fragment_end": hex(fend),
                            "fragment_size_bytes": len(frag), "original_fragment_sha256": hashlib.sha256(frag).hexdigest()})
    receipt = {"task_id": "TASK_181", "revision": 1, "verified_at": now(), "source_path": str(SOURCE), "source_sha256": SOURCE_SHA,
               "unique_export_vas": 2461, "elf_class": 64, "elf_machine": "AArch64", "targets": results}
    write_json(REPORT / "source_verification.json", receipt)
    return receipt


def copy_project() -> dict:
    manifest = json.loads(HIST_MANIFEST.read_text(encoding="utf-8"))
    expected = manifest["files"]
    if len(expected) != 9:
        raise RuntimeError("historical Ghidra project manifest not 9 files")
    for item in expected:
        path = HIST_PROJECT / item["relative_path"]
        if not path.is_file() or digest(path) != item["copy_sha256"]:
            raise RuntimeError(f"historical project changed: {path}")
    project = SCRATCH / "ghidra_project"
    if project.exists():
        raise RuntimeError("owned project copy already exists; do not repeat")
    shutil.copytree(HIST_PROJECT, project, copy_function=shutil.copy2)
    copied = []
    for item in expected:
        path = project / item["relative_path"]
        if digest(path) != item["copy_sha256"]:
            raise RuntimeError(f"owned copy mismatch: {path}")
        copied.append({"relative_path": item["relative_path"], "size_bytes": path.stat().st_size, "sha256": item["copy_sha256"]})
    receipt = {"task_id": "TASK_181", "revision": 1, "copied_at": now(), "historical_project": str(HIST_PROJECT),
               "historical_manifest_sha256": digest(HIST_MANIFEST), "owned_copy": str(project), "file_count": len(copied), "files": copied}
    write_json(REPORT / "project_copy_manifest.json", receipt)
    return receipt


def run_one(index: int) -> dict:
    lock = require_lease()
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(SCRATCH / "ghidra_project"), "Task170",
               "-process", "libffmpeg.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPT.parent), "-postScript", SCRIPT.name, str(index), str(REPORT / f"fragment_{index}_raw.json")]
    path = REPORT / f"attempt_{index}_command.json"
    stdout = REPORT / f"attempt_{index}_stdout.log"
    stderr = REPORT / f"attempt_{index}_stderr.log"
    result = REPORT / f"fragment_{index}_raw.json"
    if path.exists() or stdout.exists() or stderr.exists() or result.exists():
        raise RuntimeError(f"target {index} already attempted")
    rec = {"task_id": "TASK_181", "revision": 1, "index": index, "lease_id": LEASE,
           "fencing_token": lock["fencing_token"], "started_at": now(), "task_sha256": TASK_SHA,
           "source_sha256": SOURCE_SHA, "project_manifest_sha256": digest(REPORT / "project_copy_manifest.json"),
           "script_sha256": digest(SCRIPT), "command": command, "status": "STARTING"}
    write_json(path, rec)
    remaining = (DEADLINE - datetime.now(timezone.utc)).total_seconds()
    if remaining <= 0:
        raise RuntimeError("deadline before execution")
    env = os.environ.copy()
    env.update({"JAVA_HOME": str(JAVA_HOME), "GHIDRA_HEADLESS_MAXMEM": "1G", "DOUBLE_CLICKED": "n"})
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    started = time.monotonic()
    code = None
    status = "FAILED"
    with stdout.open("wb") as out, stderr.open("wb") as err:
        proc = subprocess.Popen(command, env=env, stdin=subprocess.DEVNULL, stdout=out, stderr=err,
                                creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
        try:
            code = proc.wait(timeout=min(210, remaining))
        except subprocess.TimeoutExpired:
            proc.kill()
            code = proc.wait(timeout=15)
            status = "PROCESS_TIMEOUT"
    observed = None
    if result.is_file():
        raw = json.loads(result.read_text(encoding="utf-8"))
        observed = {"source_body_match": raw.get("copied_memory_body_sha256") == TARGETS[index]["sha"],
                    "fragment_source_match": raw.get("fragment_sha256") == next(x for x in json.loads((REPORT / "source_verification.json").read_text())["targets"] if x["index"] == index)["original_fragment_sha256"],
                    "decompile_completed": raw.get("decompile_completed"), "fragment_c_like_nonempty": bool(raw.get("fragment_c_like", "").strip()),
                    "error": raw.get("error")}
    if code == 0 and observed and all((observed["source_body_match"], observed["fragment_source_match"])):
        status = "OUTPUT_READY"
    rec.update({"ended_at": now(), "wall_seconds": round(time.monotonic() - started, 3), "exit_code": code,
                "status": status, "stdout_sha256": digest(stdout), "stderr_sha256": digest(stderr),
                "result_sha256": digest(result) if result.is_file() else None, "observed": observed})
    write_json(path, rec)
    return rec


def main() -> None:
    require_lease()
    if not SCRIPT.is_file() or not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("tool/script missing")
    REPORT.mkdir(parents=True, exist_ok=True)
    SCRATCH.mkdir(parents=True, exist_ok=True)
    validate_source()
    copy_project()
    outcomes = []
    for index in TARGETS:
        result = run_one(index)
        outcomes.append(result)
        write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_181", "revision": 1, "status": "FRAGMENT_PROBES_RUNNING",
                 "updated_at": now(), "finished_targets": len(outcomes), "target_indices": [x["index"] for x in outcomes],
                 "fragment_c_like_count": sum(bool((x.get("observed") or {}).get("fragment_c_like_nonempty")) for x in outcomes),
                 "lease_id": LEASE, "fencing_token": 1211})
        print(json.dumps({"index": index, "status": result["status"], "observed": result["observed"]}), flush=True)
    print(json.dumps({"task_id": "TASK_181", "finished_targets": len(outcomes)}), flush=True)


if __name__ == "__main__":
    main()

"""Source-pinned TASK_240 extraction; original binaries/projects stay read-only."""

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

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
HERE = Path(__file__).resolve().parent
REPORT = ROOT / "RULES/REPORT/TASK_240_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_240_R1"
ORIGINAL = ROOT / "RESEARCH_WORK/TASK_216_R1/ghidra_project"
PROJECT = SCRATCH / "ghidra_project"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGImageCodec.so")
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_240_SO45_INTERNAL_CONTINUATION_ACTIVE.md"
TARGETS = ROOT / ".ai/ceo/reviews/TASK_240_internal_targets.json"
GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SHA = {
    STANDARD: "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
    TASK: "819acdf539a2c1ddd3d543ee32058e933ad279bd37c9610f4fdf054a12c1bcbd",
    TARGETS: "7e9c85cd13115ca039eb81397b0a926cefcb3e412720537fd466ce6f2ce1c781",
    SOURCE: "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b",
}
LEASE = "LEASE-CEO-WORKER-TASK_240-R1"
AGENT = "/root/audit_157_158"
FENCE = 1277
DEADLINE = datetime.fromisoformat("2026-10-15T12:25:54.581770+00:00")


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def guard() -> None:
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError("absolute task deadline elapsed")
    for path, expected in SHA.items():
        if sha(path) != expected:
            raise RuntimeError(f"pinned identity mismatch: {path}")
    end = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if end.is_file() and end.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION TRUE")
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matching = [x for x in locks["active_locks"] if x.get("lease_id") == LEASE]
    if len(matching) != 1:
        raise RuntimeError("lease missing or duplicated")
    entry = matching[0]
    if (entry.get("status"), entry.get("task_id"), entry.get("task_revision"),
        entry.get("agent_id"), entry.get("task_sha"), entry.get("fencing_token")) != (
        "ACTIVE", "TASK_240", 1, AGENT, SHA[TASK], FENCE):
        raise RuntimeError("lease binding/fence mismatch")
    if datetime.fromisoformat(entry["expiry"].replace("Z", "+00:00")) <= datetime.now(timezone.utc):
        raise RuntimeError("lease expired")
    expected = {"RULES/REPORT/TASK_240_REPORT_R1/**", "scripts/task_240_codex_internal/**",
                "RESEARCH_WORK/TASK_240_R1/**"}
    if not expected.issubset(set(entry.get("files_allowed", []))):
        raise RuntimeError("lease scope mismatch")


def write(path: Path, content: bytes) -> None:
    guard()
    allowed = [REPORT, SCRATCH, HERE]
    if not any(path.resolve().is_relative_to(p.resolve()) for p in allowed):
        raise RuntimeError(f"out of scope: {path}")
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + ".tmp240")
    with temp.open("wb") as stream:
        stream.write(content)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, path)


def json_write(path: Path, value: object) -> None:
    write(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))


def project_hashes(path: Path) -> dict[str, str]:
    return {p.relative_to(path).as_posix(): sha(p) for p in sorted(path.rglob("*")) if p.is_file()}


def prepare() -> None:
    guard()
    if REPORT.exists() or PROJECT.exists():
        raise RuntimeError("no duplicate preparation")
    manifest = json.loads(TARGETS.read_text(encoding="utf-8"))
    targets = manifest["targets"]
    skipped = {4105, 4110, 4231, 4235, 4243, 4249, 4266, 4269, 4470, 4523}
    expected_indices = [x for x in range(4097, 4609) if x not in skipped]
    if len(targets) != 502 or [x["global_index"] for x in targets] != expected_indices:
        raise RuntimeError("target manifest selection mismatch")
    expected_skips = [
        {"global_index": 4105, "elf_va": "0x3be638", "size_bytes": 7108},
        {"global_index": 4110, "elf_va": "0x3c1320", "size_bytes": 20184},
        {"global_index": 4231, "elf_va": "0x3d331c", "size_bytes": 11976},
        {"global_index": 4235, "elf_va": "0x3d6458", "size_bytes": 5400},
        {"global_index": 4243, "elf_va": "0x3d8d80", "size_bytes": 7344},
        {"global_index": 4249, "elf_va": "0x3daf54", "size_bytes": 18432},
        {"global_index": 4266, "elf_va": "0x3e1ba4", "size_bytes": 8952},
        {"global_index": 4269, "elf_va": "0x3e4514", "size_bytes": 4984},
        {"global_index": 4470, "elf_va": "0x3fe2b0", "size_bytes": 4472},
        {"global_index": 4523, "elf_va": "0x407cd4", "size_bytes": 5184},
    ]
    if manifest.get("skipped_in_slice") != expected_skips:
        raise RuntimeError("oversized candidate pending set mismatch")
    for previous in ("TASK_234", "TASK_235", "TASK_236", "TASK_237", "TASK_238", "TASK_239"):
        prior = json.loads((ROOT / f".ai/ceo/reviews/{previous}_internal_targets.json").read_text(encoding="utf-8"))
        if {x["elf_va"] for x in targets} & {x["elf_va"] for x in prior["targets"]}:
            raise RuntimeError(f"TASK_240 target overlap with {previous}")
    if manifest["source_sha256"] != SHA[SOURCE] or manifest["all_nonexport_fde_candidates"] != 6655:
        raise RuntimeError("manifest source/census mismatch")
    source = SOURCE.read_bytes()
    sys.path.insert(0, str(ROOT / "scripts/task_174_codex_exports"))
    from unwind import parse_unwind
    unwind = parse_unwind(source)
    fde = {r["function_va"]: r for r in unwind["records"]}
    if len(fde) != 9981:
        raise RuntimeError("FDE count mismatch")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("not ARM64")
        dyn = elf.get_section_by_name(".dynsym")
        exports = {int(s["st_value"]) for s in dyn.iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_size"]) > 0 and int(s["st_value"]) != 0}
        loads = [seg for seg in elf.iter_segments()
                 if seg["p_type"] == "PT_LOAD" and (int(seg["p_flags"]) & 1)]
    if len(exports) != 3326 or len(set(fde) - exports) != 6655:
        raise RuntimeError("export/nonexport census mismatch")
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoder.skipdata = True
    rows = []
    assembly = []
    lines = []
    for index, item in enumerate(targets, 1):
        va = int(item["elf_va"], 16)
        offset = int(item["file_offset"], 16)
        size = int(item["size_bytes"])
        digest = item["body_sha256"]
        original = fde.get(va)
        if va in exports or original is None or original["function_size"] != size:
            raise RuntimeError(f"source FDE mismatch at {index}")
        if original["body_file_offset"] != offset or original["retained_body_sha256"] != digest:
            raise RuntimeError(f"source body metadata mismatch at {index}")
        load = next((x for x in loads if int(x["p_vaddr"]) <= va
                     and va + size <= int(x["p_vaddr"]) + int(x["p_filesz"])
                     and offset == int(x["p_offset"]) + va - int(x["p_vaddr"])), None)
        if load is None:
            raise RuntimeError(f"PT_LOAD mapping absent at {index}")
        body = source[offset:offset + size]
        if hashlib.sha256(body).hexdigest() != digest or size % 4:
            raise RuntimeError(f"body SHA/alignment mismatch at {index}")
        instructions = list(decoder.disasm(body, va))
        if len(instructions) != item["instruction_slots"] or sum(x.size for x in instructions) != size:
            raise RuntimeError(f"Capstone decode mismatch at {index}")
        rows.append({"index": index, **item, "fde_offset": original["fde_offset"],
                     "instruction_count": len(instructions), "pt_load_file_offset": int(load["p_offset"])})
        assembly.append({"index": index, "elf_va": item["elf_va"], "body_sha256": digest,
                         "instructions": [{"va": f"0x{x.address:x}", "word_le": body[x.address-va:x.address-va+4].hex(),
                                           "mnemonic": x.mnemonic, "operands": x.op_str} for x in instructions]})
        lines.append(f"{index}\t{item['elf_va']}\t{size}\t{digest}\t{item['file_offset']}\n")
    if any(int(a["elf_va"], 16) + a["size_bytes"] > int(b["elf_va"], 16)
           for a, b in zip(rows, rows[1:])):
        raise RuntimeError("overlapping candidate spans")
    json_write(REPORT / "source_index.json", {"task_id": "TASK_240", "source_sha256": SHA[SOURCE],
               "all_fde_ranges": len(fde), "exports": len(exports), "nonexport_candidates": len(fde)-len(exports),
               "selected": len(rows), "body_bytes": sum(x["size_bytes"] for x in rows),
               "instruction_slots": sum(x["instruction_count"] for x in rows), "rows": rows})
    write(REPORT / "assembly.ndjson", ("\n".join(json.dumps(x, separators=(",", ":")) for x in assembly) + "\n").encode("utf-8"))
    write(REPORT / "targets.tsv", "".join(lines).encode("utf-8"))
    original_before = project_hashes(ORIGINAL)
    if not (ORIGINAL / "Task160.gpr").is_file() or len(original_before) < 5:
        raise RuntimeError("accepted analyzed project absent")
    guard()
    shutil.copytree(ORIGINAL, PROJECT)
    original_after = project_hashes(ORIGINAL)
    copied = project_hashes(PROJECT)
    if original_before != original_after or copied != original_before:
        raise RuntimeError("private project copy identity mismatch")
    json_write(REPORT / "project_copy_receipt.json", {"original": str(ORIGINAL), "private": str(PROJECT),
               "original_unchanged": True, "file_count": len(copied), "copied_hashes": copied})
    write(REPORT / "00_AUDIT_INDEX.md", (f"# TASK_240 R1 audit index\n\nFully read canonical `{STANDARD}` "
         f"SHA-256 `{SHA[STANDARD]}`. Task `{TASK}` SHA-256 `{SHA[TASK]}`. Manifest `{TARGETS}` "
         f"SHA-256 `{SHA[TARGETS]}`. Actor `{AGENT}`; lease `{LEASE}` fence `{FENCE}`. "
         f"Pinned original `{SOURCE}` SHA-256 `{SHA[SOURCE]}`. Static FDE candidates only; "
         "no proven source boundaries, semantics, device parity, product Phase PASS or V4 authorization.\n").encode("utf-8"))
    json_write(REPORT / "PROGRESS.json", {"task_id": "TASK_240", "revision": 1,
               "status": "SOURCE_AND_PROJECT_VERIFIED", "generated_at": now(), "lease_id": LEASE,
               "fencing_token": FENCE, "selected": len(rows), "source_bodies_rehashed": len(rows)})
    print(json.dumps({"stage": "PREPARED", "selected": len(rows),
                      "body_bytes": sum(x["size_bytes"] for x in rows),
                      "instruction_slots": sum(x["instruction_count"] for x in rows)}), flush=True)


def extract() -> None:
    guard()
    if not (REPORT / "targets.tsv").is_file() or not (PROJECT / "Task160.gpr").is_file():
        raise RuntimeError("not prepared")
    output = REPORT / "ghidra"
    if output.exists():
        raise RuntimeError("no duplicate extraction attempt")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file():
        raise RuntimeError("Ghidra absent")
    output.mkdir(parents=True)
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT), "Task160", "-process",
               "libPVGImageCodec.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(HERE), "-postScript", "ExtractInternal240.java",
               str(REPORT / "targets.tsv"), str(output / "candidates")]
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    timeout = min(2400.0, (DEADLINE - datetime.now(timezone.utc)).total_seconds() - 120)
    if timeout <= 0:
        raise RuntimeError("insufficient remaining budget")
    base = {"task_id": "TASK_240", "revision": 1, "lease_id": LEASE,
            "fencing_token": FENCE, "source_sha256": SHA[SOURCE], "target_manifest_sha256": SHA[TARGETS],
            "target_tsv_sha256": sha(REPORT / "targets.tsv"), "java_script_sha256": sha(HERE / "ExtractInternal240.java"),
            "fresh_imports": 0, "operation": "PRIVATE_COPIED_PROJECT_READ_ONLY_PROCESS", "max_cpu": 1,
            "max_heap": "1G", "per_candidate_decompile_timeout_seconds": 15,
            "command": command, "started_at": now(), "timeout_seconds": timeout}
    json_write(output / "command.json", {**base, "status": "STARTING"})
    start = time.monotonic()
    status = "ERROR"
    code = None
    pid = None
    kill = None
    try:
        with (output / "stdout.log").open("wb") as stdout, (output / "stderr.log").open("wb") as stderr:
            proc = subprocess.Popen(command, stdin=subprocess.DEVNULL, stdout=stdout, stderr=stderr,
                                    env=env, creationflags=(getattr(subprocess, "CREATE_NO_WINDOW", 0) |
                                                            getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)))
            pid = proc.pid
            try:
                code = proc.wait(timeout=timeout)
                status = "EXIT_ZERO" if code == 0 else "EXIT_NONZERO"
            except subprocess.TimeoutExpired:
                terminated = subprocess.run(["taskkill", "/PID", str(pid), "/T", "/F"],
                                            capture_output=True, text=True, timeout=30)
                kill = {"exit_code": terminated.returncode, "stdout": terminated.stdout[-1000:],
                        "stderr": terminated.stderr[-1000:]}
                code = proc.wait(timeout=30)
                status = "TIMEOUT"
    finally:
        paths = sorted((output / "candidates").glob("candidate_*.json"))
        rows = []
        for path in paths:
            try:
                rows.append(json.loads(path.read_text(encoding="utf-8")))
            except Exception:
                pass
        observed = {"candidate_files": len(paths), "parseable_rows": len(rows),
                    "memory_hash_matched": sum(x.get("source_bytes_match") is True for x in rows),
                    "c_like_rows": sum(x.get("decompile_success") is True for x in rows),
                    "listing_slots": sum(x.get("instruction_count", 0) for x in rows),
                    "pcode_slots": sum(x.get("pcode_instruction_slots", 0) for x in rows)}
        if status == "EXIT_ZERO" and len(rows) == 502:
            status = "OUTPUT_READY"
        json_write(output / "command.json", {**base, "status": status, "ended_at": now(),
                   "elapsed_seconds": round(time.monotonic() - start, 3), "launcher_pid": pid,
                   "exit_code": code, "kill_receipt": kill, "observed": observed,
                   "stdout_sha256": sha(output / "stdout.log") if (output / "stdout.log").is_file() else None,
                   "stderr_sha256": sha(output / "stderr.log") if (output / "stderr.log").is_file() else None,
                   "output_files": {p.name: sha(p) for p in paths}})
        json_write(REPORT / "PROGRESS.json", {"task_id": "TASK_240", "revision": 1,
                   "status": "GHIDRA_" + status, "generated_at": now(), "lease_id": LEASE,
                   "fencing_token": FENCE, **observed})
    print(json.dumps({"stage": "EXTRACTED", "status": status, "elapsed_seconds": round(time.monotonic()-start, 3),
                      "observed": observed}), flush=True)


if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("stage", choices=("prepare", "extract"))
    args = parser.parse_args()
    (prepare if args.stage == "prepare" else extract)()

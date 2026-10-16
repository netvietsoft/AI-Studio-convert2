"""TASK_248: original-byte CFG and bounded alternate Ghidra diagnostics."""

from __future__ import annotations

import hashlib
import json
import os
import re
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
REPORT = ROOT / "RULES/REPORT/TASK_248_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_248_R1"
ORIGINAL = ROOT / "RESEARCH_WORK/TASK_233_R1/ghidra_project"
PROJECT = SCRATCH / "ghidra_project"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGCodec.so")
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_248_SO45_INTERNAL_CONTINUATION_ACTIVE.md"
TARGETS = ROOT / ".ai/ceo/reviews/TASK_248_internal_targets.json"
PRIOR_RAW = ROOT / "RULES/REPORT/TASK_233_REPORT_R1/ghidra_raw_batch5/253_a8b08.json"
GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SHA = {
    STANDARD: "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
    TASK: "037fd12b7a89944c44bb07520a7a7b0d41e88fab54bad3f459abcdeacbc7a71b",
    TARGETS: "f82ab134d8431e825622e31574324679eff9045b1b2660acd87961670a7ab7ee",
    SOURCE: "4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc",
}
LEASE = "LEASE-CEO-WORKER-TASK_248-R1"
AGENT = "/root/audit_157_158"
FENCE = 1287
DEADLINE = datetime.fromisoformat("2026-10-16T01:43:21.143094+00:00")


def sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for b in iter(lambda: f.read(1 << 20), b""):
            h.update(b)
    return h.hexdigest()


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def guard() -> None:
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError("absolute deadline elapsed")
    for p, digest in SHA.items():
        if sha(p) != digest:
            raise RuntimeError(f"identity changed: {p}")
    end = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if end.is_file() and end.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION TRUE")
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [x for x in locks["active_locks"] if x.get("lease_id") == LEASE]
    if len(matches) != 1:
        raise RuntimeError("exact lease absent or duplicated")
    x = matches[0]
    if (x.get("status"), x.get("task_id"), x.get("task_revision"), x.get("agent_id"),
        x.get("task_sha"), x.get("fencing_token")) != (
        "ACTIVE", "TASK_248", 1, AGENT, SHA[TASK], FENCE):
        raise RuntimeError("lease binding/fence mismatch")
    if datetime.fromisoformat(x["expiry"].replace("Z", "+00:00")) <= datetime.now(timezone.utc):
        raise RuntimeError("lease expired")
    expected = {"RULES/REPORT/TASK_248_REPORT_R1/**", "scripts/task_248_codex_internal/**",
                "RESEARCH_WORK/TASK_248_R1/**"}
    if not expected.issubset(set(x.get("files_allowed", []))):
        raise RuntimeError("lease scope mismatch")


def write(path: Path, data: bytes) -> None:
    guard()
    if not any(path.resolve().is_relative_to(x.resolve()) for x in (REPORT, SCRATCH, HERE)):
        raise RuntimeError(f"out of scope: {path}")
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(path.name + ".tmp248")
    with tmp.open("wb") as f:
        f.write(data)
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)


def json_write(path: Path, value: object) -> None:
    write(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))


def project_hashes(path: Path) -> dict[str, str]:
    return {p.relative_to(path).as_posix(): sha(p) for p in sorted(path.rglob("*")) if p.is_file()}


def branch_target(ins) -> int | None:
    token = ins.op_str.rsplit(",", 1)[-1].strip().removeprefix("#")
    if re.fullmatch(r"0x[0-9a-fA-F]+", token):
        return int(token, 16)
    return None


def make_cfg(insns, body: bytes, va: int) -> dict:
    stop = va + len(body)
    leaders = {va}
    branch_sites = []
    for ins in insns:
        m = ins.mnemonic.lower()
        direct = m == "b" or m.startswith("b.") or m in ("cbz", "cbnz", "tbz", "tbnz")
        terminal = direct or m in ("br", "ret", "eret")
        target = branch_target(ins) if direct else None
        if target is not None and va <= target < stop and target % 4 == 0:
            leaders.add(target)
        if terminal and ins.address + 4 < stop:
            leaders.add(ins.address + 4)
        if direct or terminal:
            branch_sites.append({"va": f"0x{ins.address:x}", "mnemonic": m,
                                 "target": f"0x{target:x}" if target is not None else None,
                                 "target_in_fde": target is not None and va <= target < stop})
    ordered = sorted(leaders)
    blocks = []
    for index, start in enumerate(ordered):
        end = ordered[index + 1] if index + 1 < len(ordered) else stop
        members = [x for x in insns if start <= x.address < end]
        if not members:
            continue
        last = members[-1]
        m = last.mnemonic.lower()
        direct = m == "b" or m.startswith("b.") or m in ("cbz", "cbnz", "tbz", "tbnz")
        conditional = m.startswith("b.") or m in ("cbz", "cbnz", "tbz", "tbnz")
        target = branch_target(last) if direct else None
        edges = []
        if direct:
            edges.append({"kind": "direct_taken", "target": f"0x{target:x}" if target is not None else None,
                          "in_fde": target is not None and va <= target < stop})
        if conditional or not (direct or m in ("br", "ret", "eret")):
            if end < stop:
                edges.append({"kind": "fallthrough", "target": f"0x{end:x}", "in_fde": True})
        if m == "br":
            edges.append({"kind": "indirect_unresolved", "target": None, "in_fde": None})
        block_bytes = body[start - va:end - va]
        blocks.append({"start_va": f"0x{start:x}", "end_exclusive_va": f"0x{end:x}",
                       "instruction_count": len(members), "body_sha256": hashlib.sha256(block_bytes).hexdigest(),
                       "terminal_mnemonic": m, "edges": edges})
    words = [{"va": f"0x{x.address:x}", "word_le": body[x.address-va:x.address-va+4].hex(),
              "mnemonic": x.mnemonic, "operands": x.op_str} for x in insns]
    return {"scope": "CONSERVATIVE_STATIC_CFG_NOT_DECOMPILED_SOURCE", "start_va": f"0x{va:x}",
            "end_exclusive_va": f"0x{stop:x}", "source_sha256": hashlib.sha256(body).hexdigest(),
            "source_bytes": len(body), "source_words": len(insns), "blocks": blocks,
            "branch_sites": branch_sites, "instructions": words,
            "limitations": ["indirect branches unresolved", "call side effects unknown",
                            "FDE bounds do not prove source function bounds"]}


def prepare() -> None:
    guard()
    if REPORT.exists() or PROJECT.exists():
        raise RuntimeError("no duplicate preparation")
    manifest = json.loads(TARGETS.read_text(encoding="utf-8"))
    target = manifest["targets"]
    expected = {"global_index": 253, "elf_va": "0xa8b08", "size_bytes": 27524,
                "file_offset": "0xa8b08", "body_sha256": "7c65b7edc58d97da61177d6c07fe5579bf950074592f79dc0bb6d4499e904fb5",
                "instruction_slots": 6881}
    if (target != [expected] or manifest["skipped_in_slice"] != [] or
        manifest["source_sha256"] != SHA[SOURCE] or manifest["all_nonexport_fde_candidates"] != 906):
        raise RuntimeError("pinned singleton mismatch")
    source = SOURCE.read_bytes()
    body = source[0xa8b08:0xa8b08 + 27524]
    if hashlib.sha256(body).hexdigest() != expected["body_sha256"]:
        raise RuntimeError("source body hash mismatch")
    sys.path.insert(0, str(ROOT / "scripts/task_174_codex_exports"))
    from unwind import parse_unwind
    unwind = parse_unwind(source)
    rows = [r for r in unwind["records"] if r["function_va"] == 0xa8b08]
    if len(unwind["records"]) != 1323 or len(rows) != 1 or rows[0]["function_size"] != 27524 or rows[0]["body_file_offset"] != 0xa8b08:
        raise RuntimeError("original FDE mismatch")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("not AArch64")
        dyn = elf.get_section_by_name(".dynsym")
        exports = {int(s["st_value"]) for s in dyn.iter_symbols() if s["st_info"]["type"] == "STT_FUNC"
                   and s["st_shndx"] != "SHN_UNDEF" and int(s["st_size"]) > 0 and int(s["st_value"]) != 0}
        loads = [x for x in elf.iter_segments() if x["p_type"] == "PT_LOAD" and int(x["p_flags"]) & 1]
    if 0xa8b08 in exports or len(exports) != 417:
        raise RuntimeError("target export classification mismatch")
    nonexport = sorted((x for x in unwind["records"] if x["function_va"] not in exports),
                       key=lambda x: x["function_va"])
    if len(nonexport) != 906 or nonexport[253]["function_va"] != 0xa8b08:
        raise RuntimeError("zero-based nonexport FDE index mismatch")
    if not any(int(x["p_vaddr"]) <= 0xa8b08 and 0xa8b08 + 27524 <= int(x["p_vaddr"]) + int(x["p_filesz"])
               and 0xa8b08 == int(x["p_offset"]) + 0xa8b08 - int(x["p_vaddr"]) for x in loads):
        raise RuntimeError("executable PT_LOAD mapping missing")
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    insns = list(decoder.disasm(body, 0xa8b08))
    if len(insns) != 6881 or sum(x.size for x in insns) != 27524:
        raise RuntimeError("full ARM64 decode failed")
    prior = json.loads(PRIOR_RAW.read_text(encoding="utf-8"))
    if (prior["ghidra_memory_sha256"] != expected["body_sha256"] or
        prior["ghidra_instruction_count"] != 6479 or
        prior["missing_analyzed_instruction_count"] != 402 or
        prior["fde_byte_membership_count"] != 25916 or
        prior["fde_missing_body_ranges"] != [{"start_offset": 25912, "end_exclusive": 27520}] or
        "timeout" not in prior["decompile_error"].lower() or prior["c_like_nonempty"]):
        raise RuntimeError("historical failure evidence mismatch")
    cfg = make_cfg(insns, body, 0xa8b08)
    # Independent stream and second decoder for >=10% spread ordinary provenance.
    sample = sorted({0, 6880, *[round(i * 6880 / 689) for i in range(690)]})
    with SOURCE.open("rb") as stream:
        stream.seek(0xa8b08)
        independent = stream.read(27524)
    again = list(Cs(CS_ARCH_ARM64, CS_MODE_ARM).disasm(independent, 0xa8b08))
    if hashlib.sha256(independent).hexdigest() != expected["body_sha256"] or len(again) != 6881:
        raise RuntimeError("independent full-body sample failed")
    for i in sample:
        if again[i].bytes != insns[i].bytes or again[i].address != insns[i].address:
            raise RuntimeError(f"independent word check failed at {i}")
    original_before = project_hashes(ORIGINAL)
    if not (ORIGINAL / "Task158.gpr").is_file() or len(original_before) < 5:
        raise RuntimeError("accepted project missing")
    guard()
    shutil.copytree(ORIGINAL, PROJECT)
    if project_hashes(ORIGINAL) != original_before or project_hashes(PROJECT) != original_before:
        raise RuntimeError("private project copy mismatch")
    json_write(REPORT / "source_cfg.json", cfg)
    json_write(REPORT / "source_and_prior_receipt.json", {"task_id": "TASK_248", "target": expected,
        "source_sha256": SHA[SOURCE], "fde_offset": rows[0]["fde_offset"],
        "pt_load_verified": True, "source_bytes_verified": 27524, "source_words_verified": 6881,
        "independent_full_body_reread": True, "independent_spread_word_indices": sample,
        "independent_spread_words_checked": len(sample),
        "prior_raw_sha256": sha(PRIOR_RAW),
        "prior_error": prior["decompile_error"],
        "prior_missing_body_range": prior["fde_missing_body_ranges"],
        "prior_missing_analyzed_slots": 402,
        "original_project_file_hashes": original_before})
    write(REPORT / "00_AUDIT_INDEX.md", (f"# TASK_248 R1 audit index\n\nFully read canonical `{STANDARD}` SHA-256 `{SHA[STANDARD]}`.\n"
        f"Task `{TASK}` SHA-256 `{SHA[TASK]}`; manifest `{TARGETS}` SHA-256 `{SHA[TARGETS]}`.\n"
        f"Actor `{AGENT}`, lease `{LEASE}`, fence `{FENCE}`. Original `{SOURCE}` SHA-256 `{SHA[SOURCE]}`.\n"
        "Single static oversized FDE253 correction only; no claimed source semantics, device parity, Phase PASS, or V4.\n").encode("utf-8"))
    json_write(REPORT / "PROGRESS.json", {"task_id": "TASK_248", "revision": 1,
        "status": "SOURCE_CFG_AND_PROJECT_VERIFIED", "generated_at": now(),
        "lease_id": LEASE, "fencing_token": FENCE, "source_words": 6881,
        "independent_spread_words": len(sample)})
    print(json.dumps({"stage": "PREPARED", "source_words": 6881, "blocks": len(cfg["blocks"]),
                      "branches": len(cfg["branch_sites"]), "independent_spread_words": len(sample)}), flush=True)


def extract() -> None:
    guard()
    if not (REPORT / "source_cfg.json").is_file() or not (PROJECT / "Task158.gpr").is_file():
        raise RuntimeError("not prepared")
    out = REPORT / "alternate"
    if out.exists():
        raise RuntimeError("no duplicate alternate attempt")
    out.mkdir(parents=True)
    result = out / "styles.json"
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT), "Task158",
        "-process", "libPVGCodec.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
        "-scriptPath", str(HERE), "-postScript", "Alternate248.java", str(result)]
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    timeout = min(900.0, (DEADLINE - datetime.now(timezone.utc)).total_seconds() - 120)
    if timeout <= 0:
        raise RuntimeError("insufficient remaining time")
    base = {"task_id": "TASK_248", "revision": 1, "lease_id": LEASE, "fencing_token": FENCE,
            "operation": "PRIVATE_COPIED_PROJECT_ALTERNATE_STYLE_DIAGNOSTICS", "max_cpu": 1,
            "max_heap": "1G", "per_decompile_timeout_seconds": 15, "styles": ["firstpass", "register", "normalize"],
            "command": command, "java_script_sha256": sha(HERE / "Alternate248.java"),
            "started_at": now(), "timeout_seconds": timeout}
    json_write(out / "command.json", {**base, "status": "STARTING"})
    started = time.monotonic()
    code = None
    status = "ERROR"
    pid = None
    with (out / "stdout.log").open("wb") as stdout, (out / "stderr.log").open("wb") as stderr:
        proc = subprocess.Popen(command, stdin=subprocess.DEVNULL, stdout=stdout, stderr=stderr,
            env=env, creationflags=(getattr(subprocess, "CREATE_NO_WINDOW", 0) |
                                    getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)))
        pid = proc.pid
        try:
            code = proc.wait(timeout=timeout)
            status = "EXIT_ZERO" if code == 0 else "EXIT_NONZERO"
        except subprocess.TimeoutExpired:
            subprocess.run(["taskkill", "/PID", str(pid), "/T", "/F"], capture_output=True, timeout=30)
            code = proc.wait(timeout=30)
            status = "TIMEOUT"
    if status == "EXIT_ZERO" and result.is_file():
        status = "OUTPUT_READY"
    json_write(out / "command.json", {**base, "status": status, "ended_at": now(),
        "elapsed_seconds": round(time.monotonic() - started, 3), "launcher_pid": pid,
        "exit_code": code, "stdout_sha256": sha(out / "stdout.log"),
        "stderr_sha256": sha(out / "stderr.log"),
        "result_sha256": sha(result) if result.is_file() else None})
    json_write(REPORT / "PROGRESS.json", {"task_id": "TASK_248", "revision": 1,
        "status": "ALTERNATE_" + status, "generated_at": now(), "lease_id": LEASE,
        "fencing_token": FENCE, "result_exists": result.is_file()})
    print(json.dumps({"stage": "EXTRACTED", "status": status,
                      "elapsed_seconds": round(time.monotonic() - started, 3),
                      "result_exists": result.is_file()}), flush=True)


if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("stage", choices=("prepare", "extract"))
    args = parser.parse_args()
    (prepare if args.stage == "prepare" else extract)()

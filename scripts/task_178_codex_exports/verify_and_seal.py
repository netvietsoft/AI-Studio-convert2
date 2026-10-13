"""Independently verify and seal TASK_178 static research evidence."""

from __future__ import annotations

import csv
import hashlib
import json
import math
import os
import sys
import tempfile
from datetime import datetime, timezone
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from capstone.arm64 import ARM64_OP_IMM
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
REPORT = ROOT / "RULES/REPORT/TASK_178_REPORT_R1"
SCRIPTS = ROOT / "scripts/task_178_codex_exports"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libdexvmp.so")
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_178_SO45_CODEX_GAP_RECOVERY_ACTIVE.md"
SOURCE_SHA = "b4a46520ec989fef5346833db8f9a1bd6a6690902731414ed26f65cc529cc06e"
BODY_SHA = "ffe6c5558f71b31ead9ce7055ecea778379cccd409978b5502c9cb39ff272654"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "df47d97e77ec29934f7dde417737f70a34e9007be106992a20cdd4fb015b31dc"
START = 0x29CD4
END = 0x6098C
SIZE = END - START
LEASE = "LEASE-CEO-WORKER-TASK_178-R1"
FENCE = 1207


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def file_sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(part)
    return h.hexdigest()


def iso() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def atomic(path: Path, data: bytes) -> None:
    fd, tmp = tempfile.mkstemp(prefix=".task178-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(data)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(tmp, path)
    finally:
        if os.path.exists(tmp):
            os.unlink(tmp)


def write_json(path: Path, value: object) -> None:
    atomic(path, (json.dumps(value, indent=2, ensure_ascii=False) + "\n").encode())


def guard() -> None:
    if (file_sha(STANDARD), file_sha(TASK), file_sha(SOURCE)) != (
            STANDARD_SHA, TASK_SHA, SOURCE_SHA):
        raise RuntimeError("canonical/task/source hash mismatch")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    hits = [x for x in locks["active_locks"] if x.get("lease_id") == LEASE]
    if len(hits) != 1:
        raise RuntimeError("lease not unique")
    x = hits[0]
    if (x.get("status"), x.get("agent_id"), x.get("task_id"), x.get("task_revision"),
            x.get("fencing_token"), x.get("task_sha")) != (
            "ACTIVE", "/root/so45_dexvmp_correction", "TASK_178", 1, FENCE, TASK_SHA):
        raise RuntimeError("lease identity changed")
    expiry = datetime.fromisoformat(x["expiry"].replace("Z", "+00:00"))
    deadline = datetime.fromisoformat("2026-10-13T10:25:57.657908+00:00")
    if datetime.now(timezone.utc) >= min(expiry, deadline):
        raise RuntimeError("lease/deadline expired")


def verify() -> dict:
    guard()
    original = SOURCE.read_bytes()
    body = original[START:END]
    if len(body) != SIZE or sha(body) != BODY_SHA or (REPORT / "source_body.bin").read_bytes() != body:
        raise RuntimeError("original body provenance failed")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        loads = [{"vaddr": int(p["p_vaddr"]), "offset": int(p["p_offset"]),
                  "file_size": int(p["p_filesz"]), "flags": int(p["p_flags"])}
                 for p in elf.iter_segments() if p["p_type"] == "PT_LOAD"]
    if not any(x["vaddr"] <= START and END <= x["vaddr"] + x["file_size"]
               and x["vaddr"] == x["offset"] for x in loads):
        raise RuntimeError("VA=file-offset mapping not proven for body")
    rows = list(csv.DictReader((REPORT / "instruction_stream.tsv").open(encoding="utf-8"), delimiter="\t"))
    if len(rows) != SIZE // 4:
        raise RuntimeError("word row count")
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoder.detail = True
    undecoded = 0
    for index, row in enumerate(rows):
        va = START + index * 4
        word = body[index * 4:index * 4 + 4]
        if int(row["elf_va"], 16) != va or int(row["file_offset"], 16) != va:
            raise RuntimeError(f"word address mismatch index={index}")
        if row["word_hex_le"] != word.hex():
            raise RuntimeError(f"source opcode mismatch index={index}")
        decoded = list(decoder.disasm(word, va, count=1))
        if not decoded:
            undecoded += 1
            if row["mnemonic"] != "UNDECODED_WORD":
                raise RuntimeError(f"invalid word mislabeled index={index}")
            continue
        ins = decoded[0]
        if ins.size != 4 or ins.mnemonic != row["mnemonic"] or ins.op_str != row["op_str"]:
            raise RuntimeError(f"decoded word mismatch index={index}")
        if row["direct_target_va"]:
            if not ins.operands or ins.operands[-1].type != ARM64_OP_IMM:
                raise RuntimeError(f"direct target non-immediate index={index}")
            if int(row["direct_target_va"], 16) != int(ins.operands[-1].imm):
                raise RuntimeError(f"direct target changed index={index}")
    blocks = [json.loads(line) for line in (REPORT / "candidate_blocks.jsonl").read_text().splitlines()]
    if not blocks or int(blocks[0]["start_va"], 16) != START or int(blocks[-1]["end_va_exclusive"], 16) != END:
        raise RuntimeError("block range")
    prev = START
    lookup = {}
    for block in blocks:
        a, z = int(block["start_va"], 16), int(block["end_va_exclusive"], 16)
        if a != prev or z <= a or (z - a) // 4 != block["instruction_words"]:
            raise RuntimeError("block partition")
        if sha(body[a - START:z - START]) != block["source_sha256"]:
            raise RuntimeError("block source hash")
        for va in range(a, z, 4):
            lookup[va] = block["id"]
        prev = z
    edges = list(csv.DictReader((REPORT / "edge_inventory.tsv").open(encoding="utf-8"), delimiter="\t"))
    if not edges:
        raise RuntimeError("empty edge inventory")
    for edge in edges:
        source = int(edge["source_block"])
        if source < 0 or source >= len(blocks):
            raise RuntimeError("edge source block")
        if int(edge["source_tail_va"], 16) != int(blocks[source]["tail_va"], 16):
            raise RuntimeError("edge tail VA")
        if edge["target_block"]:
            if int(edge["target_block"]) != lookup.get(int(edge["target_va"], 16)):
                raise RuntimeError("edge target block")
    tables = json.loads((REPORT / "jump_tables.json").read_text())["tables"]
    if len(tables) != 2:
        raise RuntimeError("jump table count")
    for table in tables:
        base, count = table["table_va"], table["entries"]
        if not any(x["vaddr"] <= base and base + count * 4 <= x["vaddr"] + x["file_size"]
                   and x["vaddr"] == x["offset"] for x in loads):
            raise RuntimeError("jump table outside identity-mapped PT_LOAD")
        raw = original[base:base + count * 4]
        if raw != (REPORT / f"jump_table_{base:x}.bin").read_bytes() or sha(raw) != table["table_sha256"]:
            raise RuntimeError("jump table source bytes")
        if len(table["entries_detail"]) != count:
            raise RuntimeError("jump table detail count")
        for index, entry in enumerate(table["entries_detail"]):
            rel = int.from_bytes(raw[index * 4:index * 4 + 4], "little", signed=True)
            target = base + rel
            if (entry["index"], entry["signed_relative_32"], int(entry["target_va"], 16),
                    entry["target_block"]) != (index, rel, target, lookup.get(target)):
                raise RuntimeError("jump table target provenance")
    sample = json.loads((REPORT / "spread_block_sample.json").read_text())
    if sample["sample_count"] < math.ceil(len(blocks) * .10):
        raise RuntimeError("ordinary sample below 10%")
    for item in sample["samples"]:
        block = blocks[item["block_id"]]
        if (item["start_va"], item["end_va_exclusive"], item["sha256"]) != (
                block["start_va"], block["end_va_exclusive"], block["source_sha256"]):
            raise RuntimeError("spread sample block mismatch")
    prior = json.loads((REPORT / "historical_raw/task159_huge_ghidra_raw.json").read_text())["targets"][0]
    anchors = json.loads((REPORT / "ghidra_anchor_audit.json").read_text())["anchors"]
    if len(anchors) != len(prior["instructions"]):
        raise RuntimeError("historical anchor count mismatch")
    for anchor in anchors:
        va = int(anchor["elf_va"], 16)
        if anchor["source_word_hex_le"] != body[va - START:va - START + 4].hex():
            raise RuntimeError("historical anchor source word")
    summary = json.loads((REPORT / "inventory_summary.json").read_text())
    if (summary["words"], summary["undecoded_words"], summary["candidate_basic_blocks"],
            summary["candidate_edges"], summary["byte_proven_guarded_jump_table_entries"],
            summary["historical_ghidra_instruction_anchors"]) != (
            len(rows), undecoded, len(blocks), len(edges), 2823, len(anchors)):
        raise RuntimeError("summary count mismatch")
    receipt = {"task_id": "TASK_178", "revision": 1, "verified_at": iso(),
               "original_source_sha256": file_sha(SOURCE), "body_sha256": sha(body),
               "original_pt_load_segments": loads,
               "all_source_words_reverified": len(rows), "undecoded_words": undecoded,
               "all_candidate_block_body_hashes_reverified": len(blocks),
               "all_edges_target_block_reverified": len(edges),
               "all_guarded_table_entries_reverified": 2823,
               "all_prior_ghidra_anchors_source_reverified": len(anchors),
               "spread_block_samples_reverified": sample["sample_count"],
               "spread_block_sample_fraction": sample["sample_count"] / len(blocks),
               "ghidra_c_like_whole_function": False,
               "runtime_behavior_verified": False,
               "status": "STATIC_EVIDENCE_VERIFIED_WITH_UNRESOLVED_INDIRECT_FLOW"}
    write_json(REPORT / "independent_verification.json", receipt)
    return receipt


def seal(receipt: dict) -> None:
    guard()
    summary = json.loads((REPORT / "inventory_summary.json").read_text())
    standard_path = str(STANDARD)
    audit = f"""# TASK_178 R1 audit index

Canonical standard fully read: `{standard_path}`; SHA-256 `{STANDARD_SHA}`. Exact TASK_178 R1 SHA-256 `{TASK_SHA}`. Lease `{LEASE}`, fencing token `{FENCE}`. Actual executor: real Codex subagent `/root/so45_dexvmp_correction`; AGY was not used.

Original SO: `{SOURCE}` SHA-256 `{SOURCE_SHA}`. Target ELF VA `0x29cd4`, size `224440`, SHA-256 `{BODY_SHA}`. Source function bytes and two adjacent original jump tables are retained in this report. All outputs are static research, not product implementation.

Reproduction: `python -X utf8 -B scripts/task_178_codex_exports/block_inventory.py`, then `python -X utf8 -B scripts/task_178_codex_exports/verify_and_seal.py`. See `raw_command.json`, `run_stdout.log`, historical raw Ghidra receipt/log/output, `instruction_stream.tsv`, `candidate_blocks.jsonl`, `edge_inventory.tsv`, `jump_tables.json`, `independent_verification.json` and `spread_block_sample.json`. No Ghidra process or fresh import was launched for TASK_178.
"""
    atomic(REPORT / "00_AUDIT_INDEX.md", audit.encode())
    report = f"""# TASK_178 R1 - oversized libdexvmp export block research

**Disposition: PARTIAL static recovery.** The original 224,440-byte body is fully preserved by SHA-256 and split into {summary['candidate_basic_blocks']:,} source-byte-anchored candidate blocks. Whole-function Ghidra C-like output remains absent; behavioral equivalence and runtime path coverage are unknown.

## Observed from original bytes

- Original source SHA-256 `{SOURCE_SHA}` and body SHA-256 `{BODY_SHA}` independently match. An identity-mapped ELF PT_LOAD segment covers the body and both table byte ranges.
- Fixed four-byte AArch64 linear sweep gives {summary['capstone_decoded_candidate_words']:,} decodable candidate words and {summary['undecoded_words']} explicit undecoded words across {summary['words']:,} words. Decodable does not mean executable or reachable; embedded data may also decode.
- The candidate partition has {summary['candidate_basic_blocks']:,} blocks and {summary['candidate_edges']:,} edges including guarded table cases. Independent verifier rechecked all {receipt['all_source_words_reverified']:,} source words, {receipt['all_candidate_block_body_hashes_reverified']:,} block hashes, {receipt['all_edges_target_block_reverified']:,} edge destinations, all 2,823 table entries, all {receipt['all_prior_ghidra_anchors_source_reverified']:,} historical Ghidra anchor opcodes, and {receipt['spread_block_samples_reverified']} spread blocks ({receipt['spread_block_sample_fraction']:.2%}).
- At `0x2a844`, `cmp w9,#0x707` / `b.ls` guards a table at `0x6098c` with 1,800 signed relative entries, all aligned and inside this function. At `0x4e0c4`, `sub w9,w8,#0x708` / `cmp w9,#0x3fe` / `b.hi` guards a second table at `0x63574` with 1,023 such entries, likewise inside. The table bytes start beyond the dynamic symbol's declared function end and are copied verbatim; they do not extend claimed function-body coverage.
- Traversing only directly encoded branches from the entry reaches {summary['entry_direct_reachable_candidate_blocks']} candidate blocks. Including these two byte-proven table target sets reaches {summary['entry_static_table_aware_candidate_blocks']:,} candidate blocks. This is a static possible-target closure, not evidence that a runtime input visits all those cases.
- Historical TASK_159 Ghidra output read-only shows the same body hash, only 1,692 instruction addresses, and decompiler `process: timeout`. Four Capstone/Ghidra mnemonic differences are syntax aliases (`orr`/`mov`, `bfm`/`bfi`); all 1,692 anchor source words are verified.

## Boundaries and unresolved evidence

There are {summary['unresolved_indirect_jump_sites']} indirect jump instructions in the candidate sweep. Exactly two have guarded original-byte table targets in this report; {summary['other_indirect_jump_sites_unresolved']} others remain unresolved. There are {summary['unresolved_indirect_call_sites']} indirect call candidates and {summary['undecoded_words']} undecoded words. Static parsing may include data or decoy code, and target sets do not establish path feasibility. No whole-function C-like, P-code reconstruction, semantic equivalence, runtime behavior, test PASS, product Phase PASS or V4 claim is made. The block and edge files are forensic source maps; `control_flow_skeleton.txt` records control transfers only and is not C-like decompilation.

Only TASK_178 scoped research/report/script files were written. Prior 283 ordinary export bodies and existing Ghidra projects were left untouched. No AGY, fresh import, Ghidra process, product/P0 edit, commit or push occurred. PROJECT_ERROR.md and ACQUIREMENTS.md were reviewed; durable updates require CEO-owned scope or a later task.
"""
    atomic(REPORT / "01_MASTER_REPORT.md", report.encode())
    write_json(REPORT / "PROGRESS.json", {
        "schema_version": "2.1.2", "task_id": "TASK_178", "revision": 1,
        "state": "FINAL_CANDIDATE", "generated_at": iso(), "lease_id": LEASE,
        "fencing_token": FENCE, "source_sha256": SOURCE_SHA,
        "body_sha256": BODY_SHA, "candidate_blocks": summary["candidate_basic_blocks"],
        "guarded_table_entries": 2823, "whole_function_c_like": False,
        "unresolved_indirect_jumps": summary["other_indirect_jump_sites_unresolved"]})
    files = {p.relative_to(REPORT).as_posix(): file_sha(p) for p in sorted(REPORT.rglob("*"))
             if p.is_file() and p.name not in ("COMPLETE.json", "PROGRESS.json")}
    code = {p.relative_to(ROOT).as_posix(): file_sha(p) for p in sorted(SCRIPTS.rglob("*"))
            if p.is_file()}
    total = sum((REPORT / k).stat().st_size for k in files)
    if total > 134217728:
        raise RuntimeError("report cap exceeded")
    complete = {"schema_version": "2.1.2", "task_id": "TASK_178", "revision": 1,
                "status": "COMPLETE", "semantic_disposition": "PARTIAL_STATIC_BLOCK_AND_GUARDED_TABLE_RECOVERY",
                "generated_at": iso(), "standard_sha256": STANDARD_SHA,
                "task_sha256": TASK_SHA, "source_sha256": SOURCE_SHA, "body_sha256": BODY_SHA,
                "lease_id": LEASE, "fencing_token": FENCE,
                "execution_mode": "REAL_CODEX_SUBAGENT_NO_AGY",
                "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW",
                "candidate_blocks": summary["candidate_basic_blocks"],
                "candidate_edges": summary["candidate_edges"],
                "guarded_jump_table_entries": 2823,
                "unresolved_indirect_jump_sites": summary["other_indirect_jump_sites_unresolved"],
                "source_words_reverified": receipt["all_source_words_reverified"],
                "spread_block_samples": receipt["spread_block_samples_reverified"],
                "ghidra_c_like_whole_function": False, "behavior_verified": False,
                "phase_pass": False, "fresh_imports": 0, "heavy_ghidra_processes": 0,
                "report_bytes_excluding_seal_and_progress": total,
                "files": files, "code_files": code, "research_files": {}}
    write_json(REPORT / "COMPLETE.json", complete)
    print("TASK_178 VERIFIED AND SEALED", summary["candidate_basic_blocks"],
          "blocks", len(files), "report files", "seal", file_sha(REPORT / "COMPLETE.json"))


if __name__ == "__main__":
    result = verify()
    seal(result)

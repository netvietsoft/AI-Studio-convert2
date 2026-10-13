"""TASK_178: source-byte-anchored AArch64 candidate block and edge inventory.

This intentionally does not decompile, execute, or infer indirect branch targets.
The linear sweep can decode embedded data as instructions. Its output is therefore
candidate assembly, not verified behavior or a recovered C function.
"""

from __future__ import annotations

import hashlib
import json
import math
import os
import sys
import tempfile
from collections import Counter, deque
from datetime import datetime, timezone
from pathlib import Path

import capstone
from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from capstone.arm64 import ARM64_OP_IMM

ROOT = Path(__file__).resolve().parents[2]
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_178_SO45_CODEX_GAP_RECOVERY_ACTIVE.md"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libdexvmp.so")
REPORT = ROOT / "RULES/REPORT/TASK_178_REPORT_R1"
PRIOR = ROOT / "RULES/REPORT/TASK_159_REPORT_R1"
START = 0x29CD4
SIZE = 224440
END = START + SIZE
STD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "df47d97e77ec29934f7dde417737f70a34e9007be106992a20cdd4fb015b31dc"
SOURCE_SHA = "b4a46520ec989fef5346833db8f9a1bd6a6690902731414ed26f65cc529cc06e"
BODY_SHA = "ffe6c5558f71b31ead9ce7055ecea778379cccd409978b5502c9cb39ff272654"
LEASE = "LEASE-CEO-WORKER-TASK_178-R1"
FENCE = 1207


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def file_sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(part)
    return h.hexdigest()


def atomic(path: Path, data: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix=".task178-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(data)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def write_json(path: Path, value: object) -> None:
    atomic(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))


def guard() -> None:
    if file_sha(STANDARD) != STD_SHA or file_sha(TASK) != TASK_SHA or file_sha(SOURCE) != SOURCE_SHA:
        raise RuntimeError("canonical/task/source SHA drift")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    hits = [x for x in locks["active_locks"] if x.get("lease_id") == LEASE]
    if len(hits) != 1:
        raise RuntimeError("assigned lease absent/duplicate")
    x = hits[0]
    if (x.get("status"), x.get("agent_id"), x.get("task_id"), x.get("task_revision"),
            x.get("fencing_token"), x.get("task_sha")) != (
            "ACTIVE", "/root/so45_dexvmp_correction", "TASK_178", 1, FENCE, TASK_SHA):
        raise RuntimeError("lease identity/fence invalid")
    deadline = datetime.fromisoformat("2026-10-13T10:25:57.657908+00:00")
    expiry = datetime.fromisoformat(x["expiry"].replace("Z", "+00:00"))
    if datetime.now(timezone.utc) >= min(deadline, expiry):
        raise RuntimeError("lease or deadline expired")
    if "RULES/REPORT/TASK_178_REPORT_R1/**" not in x["files_allowed"]:
        raise RuntimeError("report scope not leased")


def classify(ins: object | None) -> tuple[str, int | None, bool]:
    if ins is None:
        return "invalid_word", None, False
    name = ins.mnemonic.lower()
    direct = name == "b" or name == "bl" or name.startswith("b.") or name in (
        "cbz", "cbnz", "tbz", "tbnz")
    target = None
    if direct and ins.operands and ins.operands[-1].type == ARM64_OP_IMM:
        target = int(ins.operands[-1].imm)
    if name == "b":
        return "direct_jump", target, False
    if name == "bl":
        return "direct_call", target, True
    if name.startswith("b.") or name in ("cbz", "cbnz", "tbz", "tbnz"):
        return "conditional_jump", target, True
    if name == "br":
        return "indirect_jump", None, False
    if name in ("blr", "blraa", "blrab"):
        return "indirect_call", None, True
    if name in ("ret", "retab", "retaa", "eret", "drps"):
        return "return", None, False
    if name in ("brk", "hlt", "udf"):
        return "trap", None, False
    return "ordinary", None, True


def main() -> None:
    guard()
    body = SOURCE.read_bytes()[START:END]
    if len(body) != SIZE or sha(body) != BODY_SHA:
        raise RuntimeError("target body mismatch")
    REPORT.mkdir(parents=True, exist_ok=True)
    atomic(REPORT / "source_body.bin", body)
    rawdir = REPORT / "historical_raw"
    prior_names = [
        ("huge_232/ghidra_raw.json", "task159_huge_ghidra_raw.json"),
        ("huge_232/ghidra_command.json", "task159_huge_ghidra_command.json"),
        ("huge_232/ghidra_stdout.log", "task159_huge_ghidra_stdout.log"),
        ("prior_task156_ghidra_stdout.log", "task156_ghidra_stdout.log"),
    ]
    for src, name in prior_names:
        atomic(rawdir / name, (PRIOR / src).read_bytes())
    prior_row = json.loads((rawdir / "task159_huge_ghidra_raw.json").read_text(encoding="utf-8"))["targets"][0]
    if (prior_row["elf_va"], prior_row["size_bytes"], prior_row["ghidra_memory_sha256"],
            prior_row["decompile_success"]) != ("0x29cd4", SIZE, BODY_SHA, False):
        raise RuntimeError("historical failure identity changed")

    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoder.detail = True
    rows: list[dict] = []
    decoded_by_va: dict[int, dict] = {}
    kinds = Counter()
    for off in range(0, SIZE, 4):
        va = START + off
        word = body[off:off + 4]
        got = list(decoder.disasm(word, va, count=1))
        ins = got[0] if len(got) == 1 and got[0].size == 4 else None
        kind, target, fallthrough = classify(ins)
        row = {"va": va, "file_offset": va, "word_hex_le": word.hex(),
               "mnemonic": ins.mnemonic if ins else "UNDECODED_WORD",
               "op_str": ins.op_str if ins else "", "kind": kind,
               "direct_target_va": target, "fallthrough": fallthrough}
        rows.append(row)
        decoded_by_va[va] = row
        kinds[kind] += 1
    header = "elf_va\tfile_offset\tword_hex_le\tmnemonic\top_str\tflow_kind\tdirect_target_va\n"
    lines = [header] + [f"0x{r['va']:x}\t0x{r['file_offset']:x}\t{r['word_hex_le']}\t"
                        f"{r['mnemonic']}\t{r['op_str']}\t{r['kind']}\t"
                        f"{'' if r['direct_target_va'] is None else hex(r['direct_target_va'])}\n"
                        for r in rows]
    atomic(REPORT / "instruction_stream.tsv", "".join(lines).encode("utf-8"))

    control = {"invalid_word", "direct_jump", "direct_call", "conditional_jump",
               "indirect_jump", "indirect_call", "return", "trap"}
    boundaries = {START, END}
    for r in rows:
        if r["kind"] in control:
            boundaries.add(r["va"] + 4)
        t = r["direct_target_va"]
        if t is not None and START <= t < END and (t - START) % 4 == 0:
            boundaries.add(t)
    boundaries = sorted(boundaries)
    blocks = []
    block_of: dict[int, int] = {}
    for i, (a, z) in enumerate(zip(boundaries[:-1], boundaries[1:])):
        if z <= a:
            continue
        first = (a - START) // 4
        count = (z - a) // 4
        tail = rows[(z - START) // 4 - 1]
        block = {"id": i, "start_va": hex(a), "end_va_exclusive": hex(z),
                 "instruction_words": count, "source_sha256": sha(body[a - START:z - START]),
                 "tail_va": hex(tail["va"]), "tail_kind": tail["kind"],
                 "tail_text": (tail["mnemonic"] + " " + tail["op_str"]).strip()}
        blocks.append(block)
        for j in range(first, first + count):
            block_of[rows[j]["va"]] = i
    if sum(b["instruction_words"] for b in blocks) != SIZE // 4:
        raise RuntimeError("block coverage partition failure")

    edge_rows = []
    outgoing: dict[int, list[dict]] = {}
    for b in blocks:
        tail = decoded_by_va[int(b["tail_va"], 16)]
        origin = b["id"]
        kind = tail["kind"]
        targets: list[tuple[str, int | None]] = []
        if kind == "direct_jump":
            targets.append(("direct_jump", tail["direct_target_va"]))
        elif kind == "conditional_jump":
            targets.extend([("taken", tail["direct_target_va"]), ("not_taken", tail["va"] + 4)])
        elif kind == "direct_call":
            targets.extend([("call_target", tail["direct_target_va"]), ("return_site", tail["va"] + 4)])
        elif kind == "indirect_call":
            targets.extend([("unresolved_indirect_call", None), ("return_site", tail["va"] + 4)])
        elif kind == "indirect_jump":
            targets.append(("unresolved_indirect_jump", None))
        elif kind == "ordinary":
            targets.append(("sequential", tail["va"] + 4))
        elif kind == "invalid_word":
            targets.append(("unresolved_invalid_word", None))
        else:
            targets.append((kind, None))
        for edge_kind, target in targets:
            destination = block_of.get(target) if target is not None else None
            edge = {"source_block": origin, "source_tail_va": hex(tail["va"]),
                    "kind": edge_kind, "target_va": hex(target) if target is not None else None,
                    "target_block": destination,
                    "resolution": "in_range_candidate_block" if destination is not None else
                    ("out_of_range" if target is not None else "unresolved_or_terminal")}
            edge_rows.append(edge)
            outgoing.setdefault(origin, []).append(edge)

    # Two selector ranges are established by nearby CMP/B.LS and SUB/CMP/B.HI
    # guards. Both tables start beyond the function's dynsym size. Preserve the
    # exact original table bytes and all signed, base-relative targets.
    source_all = SOURCE.read_bytes()
    table_specs = [
        {"branch_va": 0x2A844, "table_va": 0x6098C, "entries": 0x708,
         "range_guard_va": "0x2a7f0..0x2a7f4", "selector": "unsigned w9 <= 0x707"},
        {"branch_va": 0x4E0C4, "table_va": 0x63574, "entries": 0x3FF,
         "range_guard_va": "0x4e09c..0x4e0a4", "selector": "unsigned (w8 - 0x708) <= 0x3fe"},
    ]
    table_receipts = []
    for spec in table_specs:
        br = decoded_by_va[spec["branch_va"]]
        if br["mnemonic"] != "br" or br["op_str"] != "x8":
            raise RuntimeError("pinned dispatcher branch changed")
        base = spec["table_va"]
        count = spec["entries"]
        raw = source_all[base:base + 4 * count]
        if len(raw) != 4 * count:
            raise RuntimeError("jump table source truncated")
        atomic(REPORT / f"jump_table_{base:x}.bin", raw)
        entries = []
        origin = block_of[spec["branch_va"]]
        for index in range(count):
            rel = int.from_bytes(raw[index * 4:index * 4 + 4], "little", signed=True)
            target = base + rel
            dest = block_of.get(target)
            entries.append({"index": index, "entry_file_offset": hex(base + index * 4),
                            "signed_relative_32": rel, "target_va": hex(target),
                            "target_block": dest})
            edge = {"source_block": origin, "source_tail_va": hex(spec["branch_va"]),
                    "kind": "bounded_table_case", "target_va": hex(target),
                    "target_block": dest,
                    "resolution": "in_range_candidate_block" if dest is not None else "out_of_range"}
            edge_rows.append(edge)
            outgoing.setdefault(origin, []).append(edge)
        if any(x["target_block"] is None or not (START <= int(x["target_va"], 16) < END)
               for x in entries):
            raise RuntimeError("jump table target escaped original function")
        table_receipts.append({**spec, "table_sha256": sha(raw),
                               "table_end_exclusive": hex(base + len(raw)),
                               "unique_targets": len({e["target_va"] for e in entries}),
                               "all_targets_in_source_function": True,
                               "entries_detail": entries})
    write_json(REPORT / "jump_tables.json", {"source_sha256": SOURCE_SHA,
               "note": "static signed offsets and guarded selector ranges; no runtime case coverage claimed",
               "tables": table_receipts})
    atomic(REPORT / "candidate_blocks.jsonl", ("\n".join(json.dumps(b) for b in blocks) + "\n").encode())
    atomic(REPORT / "edge_inventory.tsv", ("source_block\tsource_tail_va\tkind\ttarget_va\ttarget_block\tresolution\n" +
           "".join(f"{e['source_block']}\t{e['source_tail_va']}\t{e['kind']}\t{e['target_va'] or ''}\t"
                   f"{'' if e['target_block'] is None else e['target_block']}\t{e['resolution']}\n"
                   for e in edge_rows)).encode())
    skeleton = []
    for b in blocks:
        targets = ", ".join(f"{e['kind']}->{e['target_va'] or '?'}" for e in outgoing[b["id"]])
        skeleton.append(f"B{b['id']} [{b['start_va']},{b['end_va_exclusive']}) words={b['instruction_words']} "
                        f"tail={b['tail_text']} | {targets}\n")
    atomic(REPORT / "control_flow_skeleton.txt", "".join(skeleton).encode())

    def reachable(include_tables: bool) -> set[int]:
        seen = set()
        queue = deque([block_of[START]])
        while queue:
            current = queue.popleft()
            if current in seen:
                continue
            seen.add(current)
            for edge in outgoing.get(current, []):
                if edge["target_block"] is None or edge["kind"] == "call_target":
                    continue
                if edge["kind"] == "bounded_table_case" and not include_tables:
                    continue
                queue.append(edge["target_block"])
        return seen
    direct_seen = reachable(False)
    table_seen = reachable(True)
    unknowns = [e for e in edge_rows if e["kind"].startswith("unresolved")]
    anchors = []
    anchor_bad = []
    for item in prior_row["instructions"]:
        addr_text, _, text = item.partition(": ")
        dbva = int(addr_text, 16)
        va = dbva - 0x100000
        row = decoded_by_va.get(va)
        if row is None:
            anchor_bad.append(item)
            continue
        gh_mnemonic = text.split(" ", 1)[0].lower()
        anchors.append({"elf_va": hex(va), "ghidra_text": text,
                        "capstone_text": (row["mnemonic"] + " " + row["op_str"]).strip(),
                        "mnemonic_equal": gh_mnemonic == row["mnemonic"].lower(),
                        "source_word_hex_le": row["word_hex_le"]})
    sample_size = max(1, math.ceil(len(blocks) * .10))
    sample_indices = sorted({round(i * (len(blocks) - 1) / (sample_size - 1))
                             for i in range(sample_size)}) if sample_size > 1 else [0]
    sample = []
    check_decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    for i in sample_indices:
        b = blocks[i]
        a, z = int(b["start_va"], 16), int(b["end_va_exclusive"], 16)
        raw = body[a - START:z - START]
        if sha(raw) != b["source_sha256"]:
            raise RuntimeError("sample block source hash drift")
        first = list(check_decoder.disasm(raw[:4], a, count=1))
        observed = rows[(a - START) // 4]
        if bool(first) != (observed["kind"] != "invalid_word"):
            raise RuntimeError("sample decode mismatch")
        if first and first[0].mnemonic != observed["mnemonic"]:
            raise RuntimeError("sample instruction mnemonic mismatch")
        sample.append({"block_id": i, "start_va": hex(a), "end_va_exclusive": hex(z),
                       "sha256": b["source_sha256"], "first_word_hex_le": raw[:4].hex(),
                       "first_mnemonic": observed["mnemonic"]})
    if anchor_bad:
        raise RuntimeError("historical Ghidra anchor outside original body")
    write_json(REPORT / "ghidra_anchor_audit.json", {
        "historical_raw_sha256": file_sha(rawdir / "task159_huge_ghidra_raw.json"),
        "anchor_count": len(anchors), "addresses_in_original_range": len(anchors),
        "mnemonic_equal_count": sum(a["mnemonic_equal"] for a in anchors),
        "note": "Ghidra listing is prior partial analysis, not complete function coverage",
        "anchors": anchors})
    write_json(REPORT / "spread_block_sample.json", {"sample_count": len(sample),
               "block_count": len(blocks), "fraction": len(sample) / len(blocks), "samples": sample})
    write_json(REPORT / "inventory_summary.json", {
        "schema_version": "2.1.2", "task_id": "TASK_178", "revision": 1,
        "source_sha256": SOURCE_SHA, "body_sha256": BODY_SHA,
        "elf_va_start": hex(START), "elf_va_end_exclusive": hex(END), "size_bytes": SIZE,
        "words": len(rows), "capstone_decoded_candidate_words": len(rows) - kinds["invalid_word"],
        "undecoded_words": kinds["invalid_word"], "word_kinds": dict(kinds),
        "candidate_basic_blocks": len(blocks), "candidate_edges": len(edge_rows),
        "unresolved_or_terminal_edges": len([e for e in edge_rows if e["target_va"] is None]),
        "unresolved_indirect_jump_sites": kinds["indirect_jump"],
        "unresolved_indirect_call_sites": kinds["indirect_call"],
        "out_of_range_target_edges": len([e for e in edge_rows if e["resolution"] == "out_of_range"]),
        "entry_direct_reachable_candidate_blocks": len(direct_seen),
        "entry_static_table_aware_candidate_blocks": len(table_seen),
        "byte_proven_guarded_jump_tables": len(table_receipts),
        "byte_proven_guarded_jump_table_entries": sum(x["entries"] for x in table_receipts),
        "other_indirect_jump_sites_unresolved": kinds["indirect_jump"] - len(table_receipts),
        "historical_ghidra_instruction_anchors": len(anchors),
        "historical_ghidra_anchor_mnemonic_equal": sum(a["mnemonic_equal"] for a in anchors),
        "spread_sampled_blocks": len(sample), "sample_fraction": len(sample) / len(blocks),
        "ghidra_c_like_whole_function": False, "runtime_behavior_verified": False,
        "critical_limitation": "linear sweep may decode embedded data; indirect targets and runtime behavior unresolved"})
    write_json(REPORT / "raw_command.json", {
        "generated_at": now(), "argv": sys.argv, "python": sys.version,
        "capstone_version": capstone.__version__, "source": str(SOURCE),
        "source_sha256": SOURCE_SHA, "script_sha256": file_sha(Path(__file__)),
        "heavy_ghidra_processes": 0, "fresh_imports": 0, "cpu_threads": 1})
    print(f"TASK_178 candidate blocks={len(blocks)} edges={len(edge_rows)} "
          f"undecoded_words={kinds['invalid_word']} direct_reachable={len(direct_seen)} "
          f"table_aware_reachable={len(table_seen)} table_entries=2823 "
          f"spread_sample={len(sample)} historical_anchors={len(anchors)}")


if __name__ == "__main__":
    main()

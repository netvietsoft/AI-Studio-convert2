"""Recheck TASK_186 R1 bytes and seal its bounded report correction."""

from __future__ import annotations

import hashlib
import io
import json
import math
import re
import sys
from datetime import datetime, timezone
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[2]
R1 = ROOT / "RULES/REPORT/TASK_186_REPORT_R1"
R2 = ROOT / "RULES/REPORT/TASK_186_REPORT_R2"
SOURCE = Path(
    "F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGColorFunctions.so"
)
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_186_SO45_CODEX_INTERNAL_ACTIVE.md"
TARGET = ROOT / ".ai/ceo/reviews/TASK_186_internal_targets.json"
REVIEW = ROOT / ".ai/ceo/reviews/TASK_186-183e5c90186b686653e445b13f6fc090afbf0d08f07644e2b5be40718f899a22.md"
R1_SEAL_SHA = "1e9d937903327bef0e9532c83efdee8cb246f18c2be5b2b237afcf24bbe77c30"
TASK_SHA = "a14434ce3ae2ea7314649a41ce0c7171cb17ea3dc1d746e6424cd3e608c43b32"
TARGET_SHA = "55ca7de32dc6a55aab0ce8605360f5350924192500ff33de0e814060ce0b6865"
SOURCE_SHA = "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def digest_file(path: Path) -> str:
    return digest(path.read_bytes())


def load_json(path: Path):
    return json.loads(path.read_text(encoding="utf-8"))


def write_json(path: Path, value) -> None:
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def require(condition: bool, message: str) -> None:
    if not condition:
        raise RuntimeError(message)


def main() -> None:
    now = datetime.now(timezone.utc)
    require(digest_file(STANDARD) == STANDARD_SHA, "canonical standard changed")
    require(digest_file(TASK) == TASK_SHA, "ACTIVE R2 task changed")
    require(digest_file(TARGET) == TARGET_SHA, "target manifest changed")
    require(digest_file(SOURCE) == SOURCE_SHA, "original source changed")
    require(digest_file(R1 / "COMPLETE.json") == R1_SEAL_SHA, "R1 seal changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    require(not flag.exists() or flag.read_text(encoding="utf-8").strip().upper() != "TRUE", "END_AGENT_SESSION true")
    locks = load_json(ROOT / ".ai/locks.json")
    lease = [x for x in locks["active_locks"] if x.get("lease_id") == "LEASE-CEO-WORKER-TASK_186-R2"]
    require(len(lease) == 1, "R2 lease absent/duplicate")
    lease = lease[0]
    require(
        lease["agent_id"] == "/root/so45_dexvmp_correction"
        and lease["task_revision"] == 2
        and lease["task_sha"] == TASK_SHA
        and lease["status"] == "ACTIVE"
        and lease["fencing_token"] == 1219,
        "R2 lease identity/revision/fence/status mismatch",
    )
    require(now.timestamp() < datetime.fromisoformat(lease["expiry"]).timestamp(), "R2 lease expired")
    task_text = TASK.read_text(encoding="utf-8")
    require("STATUS: ACTIVE" in task_text and '"revision": 2' in task_text, "task is not ACTIVE R2")
    require(now < datetime.fromisoformat("2026-10-13T11:30:36.135839+00:00"), "task deadline elapsed")

    seal1 = load_json(R1 / "COMPLETE.json")
    require(seal1["status"] == "COMPLETE" and seal1["revision"] == 1, "R1 seal status changed")
    r1_inventory = {"report_files": {}, "code_files": {}, "project_files": {}}
    for rel, expected in seal1["files"].items():
        path = R1 / rel
        actual = digest_file(path)
        require(actual == expected, f"R1 report changed: {rel}")
        r1_inventory["report_files"][rel] = actual
    for rel, expected in seal1["code_files"].items():
        path = ROOT / rel
        actual = digest_file(path)
        require(actual == expected, f"R1 code changed: {rel}")
        r1_inventory["code_files"][rel] = actual
    for rel, expected in seal1["scratch_project_files"].items():
        path = ROOT / rel
        actual = digest_file(path)
        require(actual == expected, f"R1 copied project changed: {rel}")
        r1_inventory["project_files"][rel] = actual
    require(len(r1_inventory["report_files"]) == 35, "unexpected R1 report inventory")
    require(len(r1_inventory["code_files"]) == 6, "unexpected R1 code inventory")
    require(len(r1_inventory["project_files"]) == 9, "unexpected R1 project inventory")

    manifest = load_json(TARGET)
    source_index = load_json(R1 / "source_index.json")
    candidate_index = load_json(R1 / "candidate_index.json")
    asm_rows = [json.loads(line) for line in (R1 / "source_assembly.ndjson").read_text(encoding="utf-8").splitlines() if line]
    raw_rows = []
    for chunk in ("chunk_00_retry1", "chunk_01", "chunk_02", "chunk_03"):
        raw_rows.extend(json.loads(line) for line in (R1 / chunk / "ghidra_raw.ndjson").read_text(encoding="utf-8").splitlines() if line)
    require(len(manifest["targets"]) == len(source_index["targets"]) == len(candidate_index["candidates"]) == len(asm_rows) == len(raw_rows) == 128, "128-row coverage changed")

    source_bytes = SOURCE.read_bytes()
    elf = ELFFile(io.BytesIO(source_bytes))
    loads = [
        (idx, int(seg["p_vaddr"]), int(seg["p_offset"]), int(seg["p_filesz"]))
        for idx, seg in enumerate(elf.iter_segments())
        if seg["p_type"] == "PT_LOAD"
    ]
    dynsym = elf.get_section_by_name(".dynsym")
    exports = {
        int(sym["st_value"])
        for sym in dynsym.iter_symbols()
        if sym["st_info"]["type"] == "STT_FUNC"
        and sym["st_shndx"] != "SHN_UNDEF"
        and int(sym["st_size"]) > 0
    }
    fdes = [
        (int(entry["initial_location"]), int(entry["address_range"]))
        for entry in elf.get_dwarf_info().EH_CFI_entries()
        if isinstance(entry, FDE) and int(entry["address_range"]) > 0
    ]
    nonexports = sorted((va, size) for va, size in fdes if va not in exports)
    require((len(exports), len(fdes), len(nonexports)) == (81, 753, 672), "ELF export/FDE population changed")
    require(
        [(int(x["elf_va"], 16), x["size_bytes"]) for x in manifest["targets"]] == nonexports[128:256],
        "R2 pinned FDE slice mismatch",
    )

    disasm = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    body_rows = []
    all_slots = []
    pcode_slots = 0
    for row_id, (target, src, candidate, asm, raw) in enumerate(
        zip(manifest["targets"], source_index["targets"], candidate_index["candidates"], asm_rows, raw_rows), start=1
    ):
        va, size = int(target["elf_va"], 16), int(target["size_bytes"])
        offset = int(target["file_offset"], 16)
        require(all(x["index"] == row_id for x in (src, candidate, asm, raw)), f"row {row_id} index")
        require(
            (int(src["elf_va"], 16), src["size_bytes"])
            == (int(candidate["elf_va"], 16), candidate["fde_size_bytes"])
            == (int(raw["elf_va"], 16), raw["fde_size_bytes"])
            == (va, size),
            f"row {row_id} identity",
        )
        matching_loads = [
            idx
            for idx, seg_va, seg_off, seg_size in loads
            if seg_va <= va and va + size <= seg_va + seg_size and offset == seg_off + va - seg_va
        ]
        require(len(matching_loads) == 1, f"row {row_id} PT_LOAD mapping")
        body = source_bytes[offset : offset + size]
        body_sha = digest(body)
        require(
            body_sha
            == target["body_sha256"]
            == src["source_body_sha256"]
            == candidate["original_body_sha256"]
            == candidate["copy_memory_body_sha256"]
            == raw["original_body_sha256"]
            == raw["copy_memory_body_sha256"],
            f"row {row_id} original/Ghidra body SHA",
        )
        require(va not in exports, f"row {row_id} is export")
        require(
            raw["fde_member_bytes"] == size
            and raw["fde_missing_bytes"] == 0
            and raw["extra_body_bytes"] == 0
            and raw["function_body_address_count"] == size
            and raw["fde_missing_ranges"] == []
            and raw["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE",
            f"row {row_id} Ghidra FDE body-membership accounting",
        )
        require(raw["body_bytes_match"] and raw["c_like_present"] and not raw["failure"], f"row {row_id} Ghidra status")
        require(digest(raw["c_like_text"].encode("utf-8")) == raw["c_like_sha256"] == candidate["c_like_sha256"], f"row {row_id} C-like SHA")
        insns = list(disasm.disasm(body, va))
        require(len(insns) == size // 4 and sum(ins.size for ins in insns) == size, f"row {row_id} full AArch64 decode")
        require(len(asm["instructions"]) == len(raw["instructions"]) == raw["instruction_count_observed"] == raw["instruction_slots"] == candidate["instruction_slots"] == len(insns), f"row {row_id} instruction count")
        pcode_slots += raw["pcode_instruction_count"]
        for local_slot, ins in enumerate(insns):
            src_ins = asm["instructions"][local_slot]
            word = body[local_slot * 4 : local_slot * 4 + 4].hex()
            require(
                src_ins["va"] == hex(ins.address)
                and src_ins["word_le"] == word
                and src_ins["mnemonic"] == ins.mnemonic
                and src_ins["operands"] == ins.op_str,
                f"row {row_id} source instruction slot {local_slot}",
            )
            ghidra_text = raw["instructions"][local_slot]
            match = re.match(r"([0-9a-fA-F]+):\s*(\S+)", ghidra_text)
            require(
                match is not None
                and int(match.group(1), 16) == ins.address + 0x100000
                and match.group(2).lower() == ins.mnemonic.lower(),
                f"row {row_id} Ghidra listing slot {local_slot}",
            )
            all_slots.append(
                {
                    "index": row_id,
                    "local_slot": local_slot,
                    "elf_va": hex(ins.address),
                    "source_file_offset": hex(offset + local_slot * 4),
                    "original_word_le": word,
                    "capstone_mnemonic": ins.mnemonic,
                    "capstone_operands": ins.op_str,
                    "source_assembly_sha256": digest(json.dumps(src_ins, sort_keys=True).encode("utf-8")),
                    "ghidra_listing_text": ghidra_text,
                }
            )
        body_rows.append(
            {
                "index": row_id,
                "elf_va": hex(va),
                "fde_size_bytes": size,
                "file_offset": hex(offset),
                "pt_load_index": matching_loads[0],
                "original_body_sha256": body_sha,
                "ghidra_raw_memory_body_sha256": raw["copy_memory_body_sha256"],
                "c_like_sha256": raw["c_like_sha256"],
                "fde_member_bytes": raw["fde_member_bytes"],
                "fde_missing_bytes": raw["fde_missing_bytes"],
                "ghidra_extra_body_bytes": raw["extra_body_bytes"],
                "ghidra_body_address_count": raw["function_body_address_count"],
                "boundary_classification": raw["boundary_classification"],
                "instruction_slots": len(insns),
                "pcode_instruction_slots": raw["pcode_instruction_count"],
            }
        )
    require(len(all_slots) == 790 and pcode_slots == 758, "instruction/pcode totals changed")
    sample_positions = [k * (len(all_slots) - 1) // (79 - 1) for k in range(79)]
    require(len(set(sample_positions)) == 79, "sample positions are not distinct")
    sample = [dict(global_slot=pos, **all_slots[pos]) for pos in sample_positions]
    require(len({item["elf_va"] for item in sample}) == 79, "sample VAs are not distinct")

    reference = {
        "task_id": "TASK_186",
        "correction_revision": 2,
        "immutable_r1_seal_sha256": R1_SEAL_SHA,
        "r1_ceo_needs_fix_review": str(REVIEW.relative_to(ROOT)).replace("\\", "/"),
        "r1_ceo_needs_fix_review_sha256": digest_file(REVIEW),
        "source_sha256": SOURCE_SHA,
        "target_manifest_sha256": TARGET_SHA,
        "failed_serializer_attempt": {
            "chunk": "chunk_00",
            "raw_sha256": r1_inventory["report_files"]["chunk_00/ghidra_raw.ndjson"],
            "status": load_json(R1 / "chunk_00/ghidra_command.json")["status"],
        },
        "successful_corrected_retry": {
            "chunk": "chunk_00_retry1",
            "raw_sha256": r1_inventory["report_files"]["chunk_00_retry1/ghidra_raw.ndjson"],
            "status": load_json(R1 / "chunk_00_retry1/ghidra_command.json")["status"],
        },
        "inventory": r1_inventory,
    }
    require(reference["failed_serializer_attempt"]["status"] == "PARTIAL_OR_FAILED", "failed R1 attempt mislabeled")
    require(reference["successful_corrected_retry"]["status"] == "OUTPUT_READY", "R1 retry not ready")
    body_report = {
        "task_id": "TASK_186",
        "revision": 2,
        "source_sha256": SOURCE_SHA,
        "target_manifest_sha256": TARGET_SHA,
        "r1_seal_sha256": R1_SEAL_SHA,
        "elf_defined_nonzero_export_vas": len(exports),
        "elf_fde_ranges": len(fdes),
        "elf_nonexport_fde_candidates": len(nonexports),
        "selected_fde_slice": "sorted nonexport indices 128..255 inclusive",
        "verified_original_body_hashes": len(body_rows),
        "matching_ghidra_raw_memory_hashes": len(body_rows),
        "matching_c_like_hashes": len(body_rows),
        "reported_exact_ghidra_fde_body_membership_rows": len(body_rows),
        "rows_with_missing_fde_bytes": 0,
        "rows_with_extra_ghidra_body_bytes": 0,
        "interpretation_limit": "Per-byte Ghidra membership is checked against the immutable R1 script and raw emitted counts; R2 did not rerun Ghidra. An unwind FDE range is a candidate boundary and not proof of unique complete source semantics or behavioral equivalence.",
        "rows": body_rows,
    }
    instruction_report = {
        "task_id": "TASK_186",
        "revision": 2,
        "original_source_sha256": SOURCE_SHA,
        "source_assembly_sha256": digest_file(R1 / "source_assembly.ndjson"),
        "r1_seal_sha256": R1_SEAL_SHA,
        "decoder": "Capstone AArch64 v5.0.7",
        "all_original_instruction_slots_redecoded": len(all_slots),
        "all_source_assembly_and_ghidra_listing_addresses_mnemonics_matched": len(all_slots),
        "sample_selection": "For k=0..78, global slot=floor(k*(790-1)/(79-1)) in increasing VA/index/local-slot order",
        "sampled_distinct_instruction_slots": len(sample),
        "sampled_fraction": len(sample) / len(all_slots),
        "sampled_distinct_candidates": len({x["index"] for x in sample}),
        "first_sample_va": sample[0]["elf_va"],
        "last_sample_va": sample[-1]["elf_va"],
        "samples": sample,
    }
    R2.mkdir(parents=True, exist_ok=True)
    write_json(R2 / "r1_reference_inventory.json", reference)
    write_json(R2 / "body_verification.json", body_report)
    write_json(R2 / "instruction_verification.json", instruction_report)
    write_json(
        R2 / "command_receipt.json",
        {
            "task_id": "TASK_186",
            "revision": 2,
            "command": [sys.executable, "-X", "utf8", "-B", str(Path(__file__).resolve())],
            "generated_at": now.isoformat(),
            "lease_id": lease["lease_id"],
            "fencing_token": lease["fencing_token"],
            "standard_sha256": STANDARD_SHA,
            "task_sha256": TASK_SHA,
            "source_sha256": SOURCE_SHA,
            "target_manifest_sha256": TARGET_SHA,
            "r1_seal_sha256": R1_SEAL_SHA,
            "ghidra_processes_spawned": 0,
            "fresh_imports": 0,
            "product_files_changed": 0,
        },
    )
    (R2 / "00_AUDIT_INDEX.md").write_text(
        "# TASK_186 R2 audit index\n\n"
        f"- Fully read canonical `{STANDARD}`; verified SHA-256 `{STANDARD_SHA}`.\n"
        "- Re-read `AGENTS.md`, `Docs/rules.md`, `.ai/ceo/SO45_TO_V4_PLAN.md`, `PROJECT_ERROR.md`, `ACQUIREMENTS.md`, exact task, manifest, config/state/locks/END and git status before writing.\n"
        f"- Exact ACTIVE R2 task SHA-256 `{TASK_SHA}`; target manifest SHA-256 `{TARGET_SHA}`.\n"
        f"- Claimed `{lease['lease_id']}` fence `{lease['fencing_token']}` as `{lease['agent_id']}`.\n"
        f"- Original source `{SOURCE}` SHA-256 `{SOURCE_SHA}`. R1 seal SHA-256 `{R1_SEAL_SHA}`.\n"
        "- R2 artifacts: `01_MASTER_REPORT.md`, `r1_reference_inventory.json`, `body_verification.json`, `instruction_verification.json`, `command_receipt.json`, `COMPLETE.json`.\n"
        "- All R1 evidence is immutable; no Ghidra replay, fresh import, product edit, commit or push in R2.\n",
        encoding="utf-8",
    )
    (R2 / "01_MASTER_REPORT.md").write_text(
        "# TASK_186 R2 corrected research report\n\n"
        "This report corrects R1's boundary sentence and instruction-provenance sample while preserving every R1 byte. The failed serializer attempt is retained as immutable `chunk_00`; the valid corrected retry is `chunk_00_retry1`, followed by `chunk_01` through `chunk_03`. Their hashes are in `r1_reference_inventory.json`.\n\n"
        "Independent R2 parsing of the pinned original ELF found 81 defined nonzero-size `.dynsym` STT_FUNC export VAs, 753 unwind FDEs and 672 nonexport FDE candidates. The exact 128 targets are sorted nonexport FDE indices 128..255. All 128 original FDE/PT_LOAD body SHA-256 values match the target manifest, R1 source index and R1 raw Ghidra memory digests. Every C-like text SHA matches its raw content.\n\n"
        "The R1 Ghidra raw rows classify **128/128** function bodies as `GHIDRA_BODY_EQUALS_FDE_RANGE`: for each pinned FDE, reported member bytes equal its size, missing bytes and extra body bytes are both zero, missing intervals are empty, and function-body address count equals FDE size. Thus **all 128 C-like texts correspond to exact pinned FDE bodies according to the R1 per-byte membership capture**. There are **zero boundary-limited exceptional rows** in this batch. This says nothing about whether an unwind FDE denotes a unique complete source function, and does not establish behavioral or pixel equivalence. R2 checks immutable Ghidra raw evidence and does not replay Ghidra.\n\n"
        f"R2 independently re-decoded **{len(all_slots)}/{len(all_slots)}** AArch64 source slots, matching original words, Capstone source assembly and Ghidra listing addresses/mnemonics. It records **{len(sample)}/{len(all_slots)}** distinct, deterministically spread instruction words (**{len(sample)/len(all_slots):.2%}**) across **{len({x['index'] for x in sample})}** candidates, from `{sample[0]['elf_va']}` through `{sample[-1]['elf_va']}`. The selection formula and each VA/word/mnemonic/operands/listing are in `instruction_verification.json`. R1's 36/790-word sample is not reused as sufficient evidence.\n\n"
        "These are bounded static research findings. They do not authorize product Phase PASS, V4/P7, all-45-SO completion, commit or push. The CEO must independently review this R2 fingerprint.\n",
        encoding="utf-8",
    )
    write_json(
        R2 / "PROGRESS.json",
        {
            "task_id": "TASK_186",
            "revision": 2,
            "status": "R2_EVIDENCE_RECHECKED",
            "original_body_rows": len(body_rows),
            "instruction_slots_redecoded": len(all_slots),
            "spread_sample_slots": len(sample),
            "generated_at": datetime.now(timezone.utc).isoformat(),
        },
    )
    files = {
        p.relative_to(R2).as_posix(): digest_file(p)
        for p in sorted(R2.rglob("*"))
        if p.is_file() and p.name not in ("COMPLETE.json", "PROGRESS.json")
    }
    code_rel = Path(__file__).resolve().relative_to(ROOT).as_posix()
    write_json(
        R2 / "COMPLETE.json",
        {
            "schema_version": "2.1.2",
            "task_id": "TASK_186",
            "revision": 2,
            "status": "COMPLETE",
            "research_disposition": "CORRECTED_BOUNDED_STATIC_FDE_MATCH",
            "review_status": "REVIEW_CANDIDATE_AWAITING_CEO",
            "generated_at": datetime.now(timezone.utc).isoformat(),
            "agent_id": lease["agent_id"],
            "lease_id": lease["lease_id"],
            "fencing_token": lease["fencing_token"],
            "standard_sha256": STANDARD_SHA,
            "task_sha256": TASK_SHA,
            "target_manifest_sha256": TARGET_SHA,
            "original_so_sha256": SOURCE_SHA,
            "r1_seal_sha256": R1_SEAL_SHA,
            "target_fde_candidate_count": len(body_rows),
            "original_body_hashes_verified": len(body_rows),
            "ghidra_raw_memory_body_hashes_matched": len(body_rows),
            "c_like_hashes_verified": len(body_rows),
            "reported_exact_fde_body_membership_count": len(body_rows),
            "rows_with_missing_fde_bytes": 0,
            "rows_with_extra_ghidra_body_bytes": 0,
            "source_instruction_slots_redecoded": len(all_slots),
            "ghidra_listing_slots_checked": len(all_slots),
            "spread_instruction_words_recorded": len(sample),
            "spread_candidate_count": len({x["index"] for x in sample}),
            "ghidra_processes_spawned": 0,
            "fresh_imports": 0,
            "behavior_equivalence_tested": False,
            "product_phase_pass": False,
            "commit_sha": None,
            "push_receipt": None,
            "report_bytes_excluding_progress_and_seal": sum((R2 / rel).stat().st_size for rel in files),
            "files": files,
            "code_files": {code_rel: digest_file(Path(__file__).resolve())},
        },
    )
    print(
        json.dumps(
            {
                "status": "SEALED",
                "task_id": "TASK_186",
                "revision": 2,
                "lease_id": lease["lease_id"],
                "fencing_token": lease["fencing_token"],
                "body_rows": len(body_rows),
                "decoded_slots": len(all_slots),
                "spread_sample": len(sample),
                "seal_sha256": digest_file(R2 / "COMPLETE.json"),
            }
        )
    )


if __name__ == "__main__":
    main()

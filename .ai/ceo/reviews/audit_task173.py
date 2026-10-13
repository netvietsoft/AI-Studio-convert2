"""Independent two-VA source/pcode/provenance audit for TASK_173."""

import hashlib
import json
import re
from datetime import datetime, timezone
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

ROOT = Path("F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2")
REPORT = ROOT / "RULES/REPORT/TASK_173_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_173_SO45_FFMPEG_NEON_CORRECTION_ACTIVE.md"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libffmpeg.so")
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
PRIOR = ROOT / "RULES/REPORT/TASK_170_REPORT_R1/COMPLETE.json"
STD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "b263e583054cad24d4f93bbf42f169706b35505437213a6d6e015c768e7cafc0"
SOURCE_SHA = "d8df8c5cb7a6b5a7eb771782d74a38e0b8d3cfacd1fbef1ae67a96171e3325c9"
PRIOR_SHA = "03c9e94b2363ca7108d9c78ea5f1d602a6e1c7dbe5ba2aa335443cf651772e20"
TARGETS = {2283: (0x658fe8, 736, "x264_8_deblock_h_luma_intra_neon",
                  "94017dc1deb91f10d8a4fd18f131f5d7741d0512c73c533de6d9845fbe095cee"),
           2330: (0x65aea8, 232, "x264_8_frame_init_lowres_core_neon",
                  "0b7e289d57ad0368923c5a802869b755b47eb70e43ff290fcd1096388ca46439")}


def sha(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def ck(ok, label):
    if not ok:
        raise AssertionError(label)


def main():
    ck((sha(STANDARD), sha(TASK), sha(SOURCE), sha(PRIOR)) ==
       (STD_SHA, TASK_SHA, SOURCE_SHA, PRIOR_SHA), "canonical/task/source/prior hashes")
    seal_path = REPORT / "COMPLETE.json"
    ck((datetime.now(timezone.utc) - datetime.fromtimestamp(seal_path.stat().st_mtime, timezone.utc)).total_seconds() >= 60,
       "stable seal >=60s")
    fingerprint = sha(seal_path)
    seal = read(seal_path)
    ck(seal["task_id"] == "TASK_173" and seal["revision"] == 1 and
       seal["status"] == "COMPLETE" and
       seal["semantic_disposition"] == "PARTIAL_STATIC_RESEARCH_CANDIDATE" and
       seal["standard_sha256"] == STD_SHA and seal["task_sha256"] == TASK_SHA and
       seal["source_sha256"] == SOURCE_SHA and
       seal["accepted_prior_complete_sha256"] == PRIOR_SHA and
       seal["fencing_token"] == 1202 and seal["target_count"] == 2 and
       seal["c_like_recovered_count"] == 0 and
       seal["register_level_manual_fallback_count"] == 2 and
       seal["behavioral_equivalence_tested"] is False and
       seal["product_phase_pass"] is False and seal["v4_authorized"] is False,
       "truthful bounded final seal")
    inventory = seal["artifact_sha256"]
    for rel, expected in inventory.items():
        ck(sha(ROOT / rel) == expected, "manifest artifact " + rel)
    actual_report = {p.relative_to(ROOT).as_posix() for p in REPORT.rglob("*") if p.is_file()}
    ck(actual_report - {"RULES/REPORT/TASK_173_REPORT_R1/COMPLETE.json"} ==
       {rel for rel in inventory if rel.startswith("RULES/REPORT/TASK_173_REPORT_R1/")},
       "report inventory")
    ck(sum((REPORT / Path(rel).name).stat().st_size for rel in inventory
           if rel.startswith("RULES/REPORT/TASK_173_REPORT_R1/")) <= 33554432,
       "report byte budget")
    code = {rel: (ROOT / rel).read_text(encoding="utf-8") for rel in inventory
            if rel.startswith("scripts/task_173_codex_exports/")}
    ck(len(code) == 6 and "setSimplificationStyle(\"normalize\")" in
       next(value for key, value in code.items() if key.endswith(".java")),
       "referenced alternative exporter source inspected")
    index = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    master = (REPORT / "01_MASTER_REPORT.md").read_text(encoding="utf-8")
    manual = (REPORT / "manual_register_pseudocode.md").read_text(encoding="utf-8")
    ck(STD_SHA in index and TASK_SHA in index and "PARTIAL" in master and
       "not" in manual.lower() and "behavioral equivalence" in manual.lower(),
       "full report and manual disclaimer")
    project = read(REPORT / "project_copy_manifest.json")
    ck(project["file_count"] == len(project["files"]) == 9 and
       project["prior_complete_sha256"] == PRIOR_SHA, "project copy manifest")
    for item in project["files"]:
        rel = item["relative_path"]
        ck(item["source_sha256"] == item["copy_sha256"] ==
           sha(Path(project["source_project"]) / rel) ==
           sha(Path(project["copy_project"]) / rel), "analyzed project exact copy " + rel)
    prior_index = read(ROOT / "RULES/REPORT/TASK_170_REPORT_R1/libffmpeg.so/target_index.json")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        ck(elf["e_machine"] == "EM_AARCH64", "original AArch64")
        by_va = {}
        for sym in elf.get_section_by_name(".dynsym").iter_symbols():
            if (sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and
                    int(sym["st_size"]) and int(sym["st_value"])):
                by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
        loads = [(int(seg["p_vaddr"]), int(seg["p_offset"]), int(seg["p_filesz"]))
                 for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
    ck(len(by_va) == 2461, "original export census")
    prepared = read(REPORT / "source_targets.json")
    verified = read(REPORT / "verification.json")
    batch = read(REPORT / "batch_run_receipt.json")
    ck(prepared["source_sha256"] == verified["original_so_sha256"] == SOURCE_SHA and
       verified["prior_accepted_complete_sha256"] == PRIOR_SHA and
       verified["target_count"] == 2 and verified["original_instruction_rows_verified"] == 242 and
       verified["c_like_recovered_count"] == 0 and batch["status"] == "OUTPUT_READY" and
       len(batch["targets"]) == 2, "preparation/verification/batch identity")
    source = SOURCE.read_bytes()
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    previous_end = None
    total_instructions = 0
    for i, (index, (va, size, symbol, body_sha)) in enumerate(TARGETS.items()):
        prior_target = prior_index["targets"][index - 1]
        ck((int(prior_target["elf_va"], 16), prior_target["size_bytes"],
            prior_target["symbol"], prior_target["source_body_sha256"]) ==
           (va, size, symbol, body_sha), "accepted prior target identity")
        source_target = next(item for item in prepared["targets"] if item["index"] == index)
        offsets = [off + va - base for base, off, file_size in loads
                   if base <= va and va + size <= base + file_size]
        ck(len(offsets) == 1 and source_target["file_offset"] == f"0x{offsets[0]:x}" and
           (symbol, size) in by_va[va], "original PT_LOAD and symbol")
        body = source[offsets[0]:offsets[0] + size]
        ck(hashlib.sha256(body).hexdigest() == body_sha, "original body")
        decoded = list(cap.disasm(body, va))
        ck(sum(ins.size for ins in decoded) == size == len(decoded) * 4 and
           len(decoded) == source_target["capstone_instruction_count"], "full original AArch64 decode")
        with SOURCE.open("rb") as stream:
            stream.seek(offsets[0])
            ck(hashlib.sha256(stream.read(size)).hexdigest() == body_sha,
               "second independent critical source read")
        total_instructions += len(decoded)
        prior_raw = read(ROOT / "RULES/REPORT/TASK_170_REPORT_R1/libffmpeg.so" /
                         f"chunk_{(index - 1) // 256 + 1:02d}/ghidra_raw.json")
        prior_row = next(item for item in prior_raw["targets"] if item["index"] == index)
        ck(prior_row["elf_va"] == f"0x{va:x}" and prior_row["error"] and
           not prior_row["decompile_success"], "original failed C-like row")
        rec = read(REPORT / f"alternative_{index}_command.json")
        raw = read(REPORT / f"alternative_{index}_raw.json")
        outcome = batch["targets"][i]
        ck(rec["target_index"] == raw["target_index"] == outcome["target_index"] == index and
           rec["operation"] == "READ_ONLY_PROCESS_ONE_NORMALIZE_ATTEMPT" and
           rec["status"] == outcome["status"] == "OUTPUT_READY" and
           rec["exit_code"] == outcome["exit_code"] == 0 and
           rec["source_body_sha256"] == body_sha and
           0 < rec["elapsed_seconds"] <= 180 and
           0 < raw["alternative_decompile_seconds"] <= 180 and
           raw["source_bytes_match"] is True and
           raw["expected_source_sha256"] == raw["ghidra_memory_sha256"] == body_sha and
           raw["alternative_style"] == "normalize" and
           raw["decompile_completed"] is True and not raw["c_like"].strip() and
           raw["decompile_error"] == "", "one truthful alternative attempt")
        if previous_end is not None:
            ck(datetime.fromisoformat(rec["started_at"].replace("Z", "+00:00")) >= previous_end,
               "sequential alternatives")
        previous_end = datetime.fromisoformat(rec["ended_at"].replace("Z", "+00:00"))
        cmd = rec["command"]
        ck("-process" in cmd and "-noanalysis" in cmd and "-readOnly" in cmd and
           "-import" not in cmd and cmd[cmd.index("-max-cpu") + 1] == "1" and
           cmd[cmd.index("-postScript") + 1] == "AltNeon173.java", "bounded Ghidra command")
        for suffix, key in (("raw.json", "result_sha256"), ("stdout.log", "stdout_sha256"),
                            ("stderr.log", "stderr_sha256")):
            ck(sha(REPORT / f"alternative_{index}_{suffix}") == rec[key], "raw/log hash")
        assembly = (REPORT / f"source_assembly_{index}.txt").read_text(encoding="utf-8").splitlines()
        source_lines = [f"0x{ins.address:x}: {ins.mnemonic} {ins.op_str}".rstrip()
                        for ins in decoded]
        ck(assembly == source_lines, "complete original assembly")
        listing_pcs = [int(re.match(r"^([0-9a-fA-F]+):", line).group(1), 16)
                       for line in raw["instructions"]]
        ck(len(listing_pcs) == len(decoded) and
           listing_pcs == [ins.address + 0x100000 for ins in decoded],
           "complete Ghidra instruction PCs")
        raw_pcs = {int(re.match(r"^([0-9a-fA-F]+):", line).group(1), 16)
                   for line in raw["raw_pcode"]}
        normalized_pcs = {int(re.match(r"^([0-9a-fA-F]+):", line).group(1), 16)
                          for line in raw["normalized_high_pcode"]}
        ck(raw_pcs == set(listing_pcs) and normalized_pcs <= raw_pcs and
           len(raw["raw_pcode"]) > len(decoded) and
           len(raw["normalized_high_pcode"]) > len(decoded), "p-code provenance PCs")
        instruction_check = read(REPORT / f"instruction_verification_{index}.json")
        ck(instruction_check["all_original_instructions_verified"] == len(decoded) and
           len(instruction_check["rows"]) == len(decoded), "per-instruction verification")
        for ins, row in zip(decoded, instruction_check["rows"]):
            ck(int(row["elf_pc"], 16) == ins.address and
               int(row["ghidra_pc"], 16) == ins.address + 0x100000 and
               row["source_assembly"] ==
               f"0x{ins.address:x}: {ins.mnemonic} {ins.op_str}".rstrip() and
               row["raw_pcode_ops"] > 0, "individual instruction provenance")
        result = verified["target_results"][i]
        ck(result["index"] == index and result["source_instruction_count"] == len(decoded) and
           result["ghidra_instruction_count"] == len(decoded) and
           result["c_like_recovered"] is False and result["source_body_sha256"] == body_sha,
           "worker summary against critical result")
        ck(f"0x{va:x}" in manual and body_sha in manual,
           "manual interpretation explicitly bounded to source")
    ck(total_instructions == seal["critical_original_instruction_rows_verified"] == 242 and
       seal["alternative_attempts"] == 2 and
       sha(seal_path) == fingerprint, "stable final critical claims")
    print(json.dumps({"status": "INDEPENDENT_PARTIAL_AUDIT_PASS", "task": "TASK_173",
                      "seal_sha256": fingerprint, "critical_vas": 2,
                      "original_instructions": total_instructions,
                      "c_like_new": 0, "manual_static_fallback": 2,
                      "artifacts": len(inventory)}))


if __name__ == "__main__":
    main()

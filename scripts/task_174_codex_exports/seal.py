"""Write truthful TASK_174 research report and exact immutable hash manifest."""

from __future__ import annotations

import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

from forensic import PINNED_SHA, SOURCE
from package import require_lease


ROOT = Path(__file__).resolve().parents[2]
REPORT = ROOT / "RULES/REPORT/TASK_174_REPORT_R1"
RESEARCH = ROOT / "RESEARCH_WORK/TASK_174_R1"
SCRIPTS = ROOT / "scripts/task_174_codex_exports"
TASK = ROOT / "RULES/TASK/TASK_174_SO45_MFXKIT_ELF_FORENSIC_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK_SHA = "845c14cb04ef4c8bcec8eef4763075d8bba691f0f30897ca0cff0b26fbf24252"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def write(path: Path, body: str) -> None:
    if path.exists():
        raise RuntimeError("report already sealed/created: " + str(path))
    path.write_text(body, encoding="utf-8")


def main() -> None:
    require_lease()
    if sha(STANDARD) != STANDARD_SHA or sha(TASK) != TASK_SHA or sha(SOURCE) != PINNED_SHA:
        raise ValueError("canonical task/source pin changed")
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("already sealed")
    verified = json.loads((REPORT / "raw/verification.json").read_text(encoding="utf-8"))
    if verified.get("verified") is not True or verified["ghidra_c_like_bodies"] != 1010:
        raise ValueError("verification not complete")
    now = datetime.now(timezone.utc).isoformat()
    audit = f"""# TASK_174 R1 audit index

- Exact ACTIVE task: `RULES/TASK/TASK_174_SO45_MFXKIT_ELF_FORENSIC_ACTIVE.md`, SHA-256 `{TASK_SHA}`.
- Canonical standard fully re-read: `F:\\CONVERT\\com.mt.mtxx.mtxx\\CONVERT2\\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`, SHA-256 `{STANDARD_SHA}`. AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, config/state, locks, END flag and git status were checked before claim.
- Original input: `{SOURCE}`, SHA-256 `{PINNED_SHA}`, 773,652 bytes; original read only and rehashed after extraction.
- Actual agent: `/root/so45_dexvmp_correction` (real Codex subagent), lease `LEASE-CEO-WORKER-TASK_174-R1`, fencing token `1203`; AGY was not used.
- Owned report evidence: `raw/elf_forensics.json`, `raw/unwind_ranges.json`, `raw/verification.json`, `raw/ghidra_sample_raw.json`, five `raw/ghidra_chunks/chunk_*/ghidra_raw.json`, exact command receipts and logs. The scratch repair description is `raw/scratch_repair.json`.
- Owned research artifacts: `RESEARCH_WORK/TASK_174_R1/complete_fde_bodies.bin`, `complete_fde_index.json`, `complete_fde_assembly.ndjson`, plus the explicitly mutated scratch-only ELF and one Ghidra project.
- Reproduce bounded parsing/package/verification: `python -X utf8 -B scripts/task_174_codex_exports/forensic.py --output RULES/REPORT/TASK_174_REPORT_R1/raw/elf_forensics.json`; `python -X utf8 -B scripts/task_174_codex_exports/unwind.py --output RULES/REPORT/TASK_174_REPORT_R1/raw/unwind_ranges.json`; `python -X utf8 -B scripts/task_174_codex_exports/package.py --output-dir RESEARCH_WORK/TASK_174_R1`; `python -X utf8 -B scripts/task_174_codex_exports/verify.py`. Existing outputs must be copied to a new authorized scope before regeneration; this task deliberately rejects duplicate processing.
- Build, Android device, product UI, Design Gate and Phase PASS: `not_required` for static research only. Independent CEO review remains pending. No commit/push or product/source modification was performed.
"""
    report = f"""# TASK_174 R1 — libmfxkit.so original ELF forensics

**Disposition: PARTIAL static recovery.** The original is truncated. Its export census is **UNKNOWN**, not zero, because all 560 declared PT_DYNAMIC bytes and all 1,792 section-table bytes lie beyond EOF. No 45/45 claim, runtime behavior equivalence, product Phase PASS or V4 readiness is established.

| Original structure | Declared | Retained | Finding |
|---|---:|---:|---|
| File | 1,354,736 bytes through section table end | 773,652 bytes | Original SHA-256 `{PINNED_SHA}` |
| RX PT_LOAD body | 1,307,184 bytes | 773,652 bytes | 533,532 bytes missing |
| PT_DYNAMIC at offset 1,330,424 | 560 bytes | 0 | No DT_SYMTAB/STRTAB/HASH/GNU_HASH pointer can be read |
| Section table at offset 1,352,944 | 1,792 bytes | 0 | `.dynsym` cannot be enumerated |
| PT_GNU_EH_FRAME at offset 237,000 | 12,116 bytes | 12,116 bytes | Complete table of 1,513 unwind FDEs |

The GNU unwind table and FDE/CIE pairs independently resolve 1,513 code ranges. Their starts agree record by record. **1,020 ranges** have complete original RX bytes (447,620 bytes total), **one** has only 2,448 of 5,284 bytes, and **492** have no body bytes in this file. These FDE ranges are not evidence that the functions were exported; the missing dynamic table prevents that classification.

The exact 1,020 complete bodies and Capstone ARM64 disassembly are in `RESEARCH_WORK/TASK_174_R1/complete_fde_bodies.bin`, `complete_fde_index.json`, and `complete_fde_assembly.ndjson`. Every body hash and offset was independently rechecked against the pinned original, with 103 spread assembly rows regenerated (more than 10%). No undecodable `.byte` instructions were emitted by Capstone for the packaged complete ranges.

One scratch-only ELF copy was made. Its missing section-table pointer/count were cleared, the RX segment was clamped to retained EOF, and four wholly unbacked program headers were made inert **only in that copy**. The repaired copy is explicitly unsuitable for runtime or export census. One 1CPU/1GiB Ghidra 12.1.4 import completed; five sequential read-only processes reused the same project. A 20-range spread sample and five disjoint 200-range chunks covered all 1,020 complete FDEs without repeated target processing. All 1,020 Ghidra memory SHA values matched original body SHA values. Ghidra produced **1,010 nonempty C-like bodies**; ten nearby ranges timed out under the 15-second-per-function limit. Total six process time was {verified['total_ghidra_process_seconds']:.3f} seconds. Raw command receipts, stdout/stderr, per-function errors and C-like output remain under `raw/`.

The Ghidra logs contain {verified['ghidra_decompilation_warning_lines']} decompilation warning lines, including flows to missing memory. C-like text is a static reconstruction of retained bytes, **not** proven algorithmic or semantic parity. The ten timeouts are preserved rather than replaced with guessed pseudocode. Functions in the truncated tail cannot be recovered from this input. A complete same-build original with independently checked provenance would be required for a reliable dynamic export census and those missing bodies.

Validation: reran header/PT_DYNAMIC/unwind parsing, all 1,020 original body hashes, exact scratch metadata delta, all 1,020 Ghidra/source SHA claims, and 103 spread Capstone assembly rows. `raw/verification.json` records the checks. The original source SHA matched before and after. PROJECT_ERROR.md and ACQUIREMENTS.md were read; their update was outside this task's files_allowed, and no resolved root-cause remedy or product change is claimed. Existing dirty workspace files were untouched. CEO review is pending; no self-review, commit or push.
"""
    write(REPORT / "00_AUDIT_INDEX.md", audit)
    write(REPORT / "01_MASTER_REPORT.md", report)
    progress = {
        "schema_version": "2.1.2", "task_id": "TASK_174", "revision": 1,
        "state": "FINAL_CANDIDATE", "generated_at": now,
        "lease_id": "LEASE-CEO-WORKER-TASK_174-R1", "fencing_token": 1203,
        "source_sha256": PINNED_SHA,
        "unwind_fde_count": 1513,
        "complete_original_body_ranges": 1020,
        "ghidra_source_memory_matches": 1020,
        "ghidra_c_like_bodies": 1010,
        "ghidra_timeouts": 10,
        "dynamic_export_census": "UNKNOWN",
        "limitation": "original source truncated; no complete PT_DYNAMIC or section table",
    }
    (REPORT / "PROGRESS.json").write_text(json.dumps(progress, indent=2) + "\n", encoding="utf-8")

    # The controller requires every nested, nonvolatile report file name and SHA.
    files = {}
    for path in sorted(REPORT.rglob("*")):
        if path.is_file() and path.name not in ("COMPLETE.json", "PROGRESS.json"):
            files[path.relative_to(REPORT).as_posix()] = sha(path)
    scripts = {p.relative_to(ROOT).as_posix(): sha(p) for p in sorted(SCRIPTS.glob("*")) if p.is_file()}
    research = {p.relative_to(ROOT).as_posix(): sha(p) for p in sorted(RESEARCH.rglob("*")) if p.is_file()}
    report_bytes = sum((REPORT / relative).stat().st_size for relative in files)
    if report_bytes > 33554432:
        raise RuntimeError("report exceeds task byte cap")
    seal = {
        "schema_version": "2.1.2",
        "task_id": "TASK_174", "revision": 1, "status": "COMPLETE",
        "semantic_disposition": "PARTIAL_ORIGINAL_INPUT_TRUNCATED_EXPORT_CENSUS_UNKNOWN",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "standard_sha256": STANDARD_SHA, "task_sha256": TASK_SHA,
        "source_sha256": PINNED_SHA,
        "lease_id": "LEASE-CEO-WORKER-TASK_174-R1", "fencing_token": 1203,
        "execution_mode": "REAL_CODEX_SUBAGENT_NO_AGY",
        "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW",
        "dynamic_export_census": "UNKNOWN",
        "unwind_fde_count": 1513,
        "complete_original_body_ranges": 1020,
        "complete_original_body_bytes": 447620,
        "partial_original_body_ranges": 1,
        "absent_original_body_ranges": 492,
        "ghidra_source_memory_bodies_rehashed": 1020,
        "ghidra_c_like_bodies_recovered": 1010,
        "ghidra_decompile_timeouts": 10,
        "ordinary_spread_assembly_samples": 103,
        "fresh_scratch_imports": 1,
        "read_only_ghidra_chunks": 5,
        "semantic_equivalence_proven": False,
        "phase_pass": False,
        "report_bytes_excluding_seal_and_progress": report_bytes,
        "files": files,
        "code_files": scripts,
        "research_files": research,
    }
    write(REPORT / "COMPLETE.json", json.dumps(seal, indent=2) + "\n")
    print(json.dumps({
        "seal_sha256": sha(REPORT / "COMPLETE.json"),
        "report_file_count": len(files), "report_bytes": report_bytes,
        "code_file_count": len(scripts), "research_file_count": len(research),
        "status": seal["semantic_disposition"],
    }))


if __name__ == "__main__":
    main()

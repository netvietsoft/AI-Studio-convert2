"""Seal TASK_162 R2 by rehashing the frozen R1 evidence without re-analysis."""
from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
REPORT = Path(__file__).resolve().parent
R1 = ROOT / "RULES/REPORT/TASK_162_REPORT_R1"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK = ROOT / "RULES/TASK/TASK_162_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
TASK_SHA = "23571a8a1869894c5ada93866f95429b9a497262141f717d2980b01a8be0df70"
ARCHIVED_TASK = ROOT / "RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_162_R1_TASK_ARCHIVE.md"
ARCHIVED_TASK_SHA = "22e38e8081d202d558704a99fb1d5cc6ea9e30a1a8267f44467ab15320e52942"
R1_SEAL_SHA = "eecb9f3bcb4e1d14449ab4416b3cb597a55b53cc75cc30c8593f765b24ab2d18"
REVIEW = ROOT / ".ai/ceo/reviews/TASK_162-e8a76d0e023915577fe217c714f1017c20d7ad15598491946ace637e1e445ba8.md"
REVIEW_FINGERPRINT = "e8a76d0e023915577fe217c714f1017c20d7ad15598491946ace637e1e445ba8"
LEASE_ID = "LEASE-CEO-WORKER-TASK_162-R2"
AGENT_ID = "/root/so45_dexvmp_correction"
FENCE = 1191
DEADLINE = datetime.fromisoformat("2026-10-13T08:40:36.662647+00:00")
CODE_DIR = ROOT / "scripts/task_162_codex_exports"
SOURCES = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
LIBRARIES = {
    "libhiai_ir.so": ("c96af03947bde73255f4b77e3c253ae63130fdfed8b259196d24bbf3ba84a7d1", 1002),
    "libkoom-strip-dump.so": ("db0db1bdef5f51386ea2036682c0129b842aa5e3445a26d60ea6c5d29113faa3", 668),
}

def digest(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()

def load(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))

def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")

def atomic(path: Path, data: bytes) -> None:
    fd, temporary = tempfile.mkstemp(prefix=".task162-r2-", dir=REPORT)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(data)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temporary, path)
    finally:
        if os.path.exists(temporary):
            os.unlink(temporary)

def write_json(path: Path, value: object) -> None:
    atomic(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))

def require(condition: bool, message: str) -> None:
    if not condition:
        raise RuntimeError(message)

def guard() -> None:
    require(digest(STANDARD) == STANDARD_SHA and digest(TASK) == TASK_SHA,
            "canonical/task identity changed")
    require(datetime.now(timezone.utc) < DEADLINE, "original absolute deadline elapsed")
    end_flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    require(not end_flag.exists() or end_flag.read_text(encoding="utf-8-sig").strip().upper() != "TRUE",
            "END_AGENT_SESSION=TRUE")
    locks = load(ROOT / ".ai/locks.json")
    matches = [x for x in locks["active_locks"] if x.get("lease_id") == LEASE_ID]
    require(len(matches) == 1, "exact R2 lease missing/duplicated")
    lease = matches[0]
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    require((lease.get("status"), lease.get("agent_id"), lease.get("fencing_token"),
             lease.get("task_sha")) == ("ACTIVE", AGENT_ID, FENCE, TASK_SHA),
            "R2 lease identity changed")
    require(expiry > datetime.now(timezone.utc) and
            "RULES/REPORT/TASK_162_REPORT_R2/**" in lease["files_allowed"],
            "R2 lease expiry/scope invalid")

def main() -> None:
    guard()
    require(not (REPORT / "COMPLETE.json").exists(), "R2 already sealed")
    require(digest(ARCHIVED_TASK) == ARCHIVED_TASK_SHA, "archived exact R1 task changed")
    seal_path = R1 / "COMPLETE.json"
    require(digest(seal_path) == R1_SEAL_SHA, "frozen R1 seal changed")
    old_seal = load(seal_path)
    require(old_seal.get("task_id") == "TASK_162" and old_seal.get("revision") == 1 and
            old_seal.get("status") == "COMPLETE_CANDIDATE" and
            old_seal.get("task_sha256") == ARCHIVED_TASK_SHA,
            "frozen R1 seal identity changed")
    old_files = old_seal["file_sha256"]
    actual_files = {p.relative_to(R1).as_posix(): digest(p)
                    for p in R1.rglob("*") if p.is_file() and p != seal_path}
    require(len(old_files) == len(actual_files) == 87 and old_files == actual_files,
            "frozen 87-file R1 map/contents changed")
    expected_codes = {"common.py", "prepare.py", "run.py", "verify_and_seal.py", "ExportSo162.java"}
    found_codes = {p.name for p in CODE_DIR.iterdir() if p.is_file()}
    require(found_codes == expected_codes, "frozen R1 generator inventory changed")
    code_files = {p.relative_to(ROOT).as_posix(): digest(p) for p in CODE_DIR.iterdir() if p.is_file()}
    source_files = {}
    for name, (expected_sha, expected_count) in LIBRARIES.items():
        source = SOURCES / name
        require(digest(source) == expected_sha, "pinned original SO changed: " + name)
        source_files[str(source)] = {"sha256": expected_sha, "expected_unique_export_vas": expected_count}
    require(REVIEW.is_file(), "independent R1 diagnostic review missing")
    listing_full = 0
    listing_partial = 0
    c_warning = 0
    c_like = 0
    ghidra_memory_match = 0
    total_rows = 0
    for name, (_sha, expected_count) in LIBRARIES.items():
        source_index = load(R1 / name / "source_index.json")
        assembly_rows = [json.loads(line) for line in (R1 / name / "source_assembly.ndjson").read_text(encoding="utf-8").splitlines()]
        require(len(source_index["targets"]) == len(assembly_rows) == expected_count,
                "frozen source index/assembly count changed: " + name)
        for chunk in source_index["chunks"]:
            result = load(R1 / chunk["folder"] / "ghidra_raw.json")
            require(result.get("task_id") == "TASK_162" and result.get("program_name") == name and
                    len(result["targets"]) == chunk["count"], "frozen raw chunk identity changed")
            for row in result["targets"]:
                index = row["index"]
                require(1 <= index <= expected_count and row["elf_va"] == source_index["targets"][index - 1]["elf_va"],
                        "frozen export target index changed")
                retained_asm_count = len(assembly_rows[index - 1]["capstone_source_assembly"])
                listed_count = len(row["instructions"])
                require(listed_count == row["instruction_count_observed"] and listed_count <= retained_asm_count,
                        "listing count inconsistent with frozen source")
                listing_full += listed_count == retained_asm_count
                listing_partial += listed_count < retained_asm_count
                c_warning += "WARNING:" in row["pseudocode"]
                c_like += row["decompile_success"] is True and bool(row["pseudocode"].strip())
                ghidra_memory_match += row["source_bytes_match"] is True and (
                    row["expected_source_sha256"] == row["ghidra_memory_sha256"])
                total_rows += 1
    require(total_rows == c_like == ghidra_memory_match == 1670, "R1 bounded export coverage changed")
    require(listing_partial == 87 and c_warning == 704 and listing_full == 1583,
            "R1 quality limitation census changed")
    require(old_seal["source_export_vas"] == old_seal["ghidra_memory_matched"] ==
            old_seal["c_like_export_bodies"] == 1670, "R1 claimed count changed")
    receipt = {"schema_version": "2.1.2", "task_id": "TASK_162", "revision": 2,
        "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
        "method": "read-only rehash and frozen R1 raw JSON census; no Ghidra/source changes",
        "original_absolute_deadline_utc": DEADLINE.isoformat().replace("+00:00", "Z"),
        "archived_r1_task": {"path": ARCHIVED_TASK.relative_to(ROOT).as_posix(), "sha256": ARCHIVED_TASK_SHA},
        "r1_seal": {"path": seal_path.relative_to(ROOT).as_posix(), "sha256": R1_SEAL_SHA},
        "r1_report_root": R1.relative_to(ROOT).as_posix(), "r1_report_files": actual_files,
        "r1_report_file_count_excluding_seal": len(actual_files),
        "r1_generator_code_files": code_files,
        "r1_diagnostic_review": {"path": REVIEW.relative_to(ROOT).as_posix(),
                                 "sha256": digest(REVIEW), "fingerprint": REVIEW_FINGERPRINT},
        "pinned_original_sources": source_files,
        "retained_r1_observations": {"export_vas": total_rows,
            "source_and_ghidra_memory_matched": ghidra_memory_match,
            "nonempty_c_like_outputs": c_like, "full_instruction_listings": listing_full,
            "partial_instruction_listings": listing_partial, "warning_bearing_c_like_outputs": c_warning},
        "new_imports": 0, "new_decompilation_calls": 0, "new_source_or_product_writes": 0}
    write_json(REPORT / "02_PROVENANCE_RECEIPT.json", receipt)
    audit = ("# TASK_162 R2 audit index\n\n"
             f"Fully read canonical standard `{STANDARD}`; SHA-256 `{STANDARD_SHA}`.\n\n"
             f"Exact R2 task SHA-256 `{TASK_SHA}`; lease `{LEASE_ID}`; fence `{FENCE}`.\n\n"
             f"Archived exact R1 task SHA-256 `{ARCHIVED_TASK_SHA}`; frozen R1 seal SHA-256 "
             f"`{R1_SEAL_SHA}`. All 87 legacy R1 report entries and five R1 generators were "
             "rehashes; see `02_PROVENANCE_RECEIPT.json` for exact paths and hashes.\n")
    audit = audit.replace("were rehashes", "were rehashed")
    atomic(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    master = ("# TASK_162 R2 — report manifest correction\n\n"
              "Status: **COMPLETE report candidate; independent CEO review pending**. "
              "This revision corrected only R1 report provenance and controller manifest schema.\n\n"
              "The frozen R1 raw package contains 1,670 defined nonzero-size `.dynsym` "
              "STT_FUNC export VAs across `libhiai_ir.so` (1,002) and `libkoom-strip-dump.so` (668). "
              "All 1,670 retained source-body hashes match their Ghidra-memory hashes, and "
              "all 1,670 rows have nonempty static C-like text. These are observations of "
              "the already frozen R1 run; R2 performed no import or decompilation.\n\n"
              "**Limits:** 87 exports have partial instruction listings versus retained source assembly; "
              "704 C-like outputs contain decompiler warnings. Static export text does not establish "
              "complete function semantics, all internal functions, runtime behavior, native parity, "
              "product Phase PASS or V4 readiness. TASK_063/064A-G/065/066 and P0/P7 gates are unchanged.\n\n"
              "`02_PROVENANCE_RECEIPT.json` links every one of the 87 frozen R1 report files, "
              "the R1 seal, archived R1 task, five generator files, original SO hashes and CEO "
              "diagnostic review. The R1 package itself remains byte-for-byte unchanged.\n")
    atomic(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    own_files = {p.relative_to(REPORT).as_posix(): digest(p)
                 for p in REPORT.rglob("*") if p.is_file() and p.name != "COMPLETE.json"
                 and p.name not in ("PROGRESS.json", "PROGRESS.md")}
    require(set(own_files) == {"build_report.py", "00_AUDIT_INDEX.md", "01_MASTER_REPORT.md",
                               "02_PROVENANCE_RECEIPT.json"}, "R2 own report inventory changed")
    require(sum((REPORT / name).stat().st_size for name in own_files) < 4194304,
            "R2 report exceeds 4 MiB cap")
    seal = {"schema_version": "2.1.2", "task_id": "TASK_162", "revision": 2,
            "status": "COMPLETE", "generated_at": now(), "lease_id": LEASE_ID,
            "fencing_token": FENCE, "task_sha256": TASK_SHA,
            "standard_sha256": STANDARD_SHA, "files": own_files, "code_files": code_files,
            "r1_task_sha256": ARCHIVED_TASK_SHA, "r1_seal_sha256": R1_SEAL_SHA,
            "r1_report_files_rehashed": len(actual_files),
            "research_gate": "REVIEW_CANDIDATE_AWAITING_CEO",
            "commit_push_pending": True}
    guard()
    write_json(REPORT / "COMPLETE.json", seal)
    print(json.dumps({"status": "COMPLETE", "r1_files": 87, "r1_generators": 5,
                      "partial_listings": listing_partial, "c_warning_outputs": c_warning,
                      "r2_files": len(own_files), "seal_sha256": digest(REPORT / "COMPLETE.json")}), flush=True)

if __name__ == "__main__":
    main()

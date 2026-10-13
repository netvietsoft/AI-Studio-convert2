"""Independent read-only audit of TASK_162 report-only R2 and frozen R1 links."""

from __future__ import annotations

import hashlib
import json
import re
import sys
import time
from pathlib import Path

ROOT = Path("F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2")
sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402

REPORT = ROOT / "RULES/REPORT/TASK_162_REPORT_R2"
R1 = ROOT / "RULES/REPORT/TASK_162_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_162_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
EXPECTED_STANDARD = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
EXPECTED_TASK = "23571a8a1869894c5ada93866f95429b9a497262141f717d2980b01a8be0df70"
EXPECTED_R1_TASK = "22e38e8081d202d558704a99fb1d5cc6ea9e30a1a8267f44467ab15320e52942"
EXPECTED_R1_SEAL = "eecb9f3bcb4e1d14449ab4416b3cb597a55b53cc75cc30c8593f765b24ab2d18"
EXPECTED_R2_SEAL = "1874ff0bfd6facf6ce7a5d75fac75a5620ed933d45b82e218c27b2bfcdf610f5"
EXPECTED_FINGERPRINT = "d2a73068e619b39f029fb6aeea738bbb34bb1c4973805d1c6c67622899460acf"


def sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def load(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def require(ok: bool, message: str) -> None:
    if not ok:
        raise AssertionError(message)


def main() -> None:
    require(sha(STANDARD) == EXPECTED_STANDARD and sha(TASK) == EXPECTED_TASK,
            "canonical or R2 task changed")
    seal_path = REPORT / "COMPLETE.json"
    require(sha(seal_path) == EXPECTED_R2_SEAL, "R2 seal changed")
    seal = load(seal_path)
    require((seal["schema_version"], seal["task_id"], seal["revision"], seal["status"],
             seal["lease_id"], seal["fencing_token"], seal["task_sha256"],
             seal["standard_sha256"]) ==
            ("2.1.2", "TASK_162", 2, "COMPLETE", "LEASE-CEO-WORKER-TASK_162-R2",
             1191, EXPECTED_TASK, EXPECTED_STANDARD), "R2 manifest identity")
    all_own = {p.relative_to(REPORT).as_posix(): sha(p) for p in REPORT.rglob("*") if p.is_file()}
    require(set(all_own) == {"00_AUDIT_INDEX.md", "01_MASTER_REPORT.md",
                             "02_PROVENANCE_RECEIPT.json", "build_report.py", "COMPLETE.json"},
            "R2 report inventory")
    require(seal["files"] == {k: v for k, v in all_own.items() if k != "COMPLETE.json"},
            "R2 exact file hashes")
    require(sum((REPORT / k).stat().st_size for k in seal["files"]) <= 4194304,
            "R2 report cap")
    audit_text = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8")
    master_text = (REPORT / "01_MASTER_REPORT.md").read_text(encoding="utf-8")
    require(EXPECTED_STANDARD in audit_text and STANDARD.name in audit_text and
            EXPECTED_TASK in audit_text and "1191" in audit_text, "R2 audit index")
    for phrase in ("87 exports", "704 C-like", "all internal functions", "Phase PASS", "V4"):
        require(phrase in master_text, "R2 limitation missing: " + phrase)
    receipt = load(REPORT / "02_PROVENANCE_RECEIPT.json")
    require((receipt["schema_version"], receipt["task_id"], receipt["revision"],
             receipt["lease_id"], receipt["fencing_token"]) ==
            ("2.1.2", "TASK_162", 2, "LEASE-CEO-WORKER-TASK_162-R2", 1191),
            "R2 receipt identity")
    require(receipt["original_absolute_deadline_utc"] == "2026-10-13T08:40:36.662647Z",
            "deadline reset")
    for field in ("new_imports", "new_decompilation_calls", "new_source_or_product_writes"):
        require(receipt[field] == 0, "R2 action claim")
    archived = receipt["archived_r1_task"]
    r1_seal_ref = receipt["r1_seal"]
    require(archived["sha256"] == EXPECTED_R1_TASK and
            sha(ROOT / archived["path"]) == EXPECTED_R1_TASK, "R1 task archive")
    require(r1_seal_ref["sha256"] == EXPECTED_R1_SEAL and
            sha(ROOT / r1_seal_ref["path"]) == EXPECTED_R1_SEAL, "R1 seal")
    old = load(R1 / "COMPLETE.json")
    require(old["task_id"] == "TASK_162" and old["revision"] == 1 and
            old["status"] == "COMPLETE_CANDIDATE", "known R1 schema defect")
    r1_files = {p.relative_to(R1).as_posix(): sha(p) for p in R1.rglob("*")
                if p.is_file() and p.name != "COMPLETE.json"}
    require(len(r1_files) == 87 and old["file_sha256"] == receipt["r1_report_files"] == r1_files,
            "all R1 report bytes")
    codes = {p.relative_to(ROOT).as_posix(): sha(p)
             for p in (ROOT / "scripts/task_162_codex_exports").iterdir() if p.is_file()}
    require(len(codes) == 5 and receipt["r1_generator_code_files"] == seal["code_files"] == codes,
            "all frozen R1 generators")
    review = receipt["r1_diagnostic_review"]
    require(review["fingerprint"] == "e8a76d0e023915577fe217c714f1017c20d7ad15598491946ace637e1e445ba8"
            and sha(ROOT / review["path"]) == review["sha256"], "R1 diagnostic review link")
    expected_sources = {
        "libhiai_ir.so": ("c96af03947bde73255f4b77e3c253ae63130fdfed8b259196d24bbf3ba84a7d1", 1002),
        "libkoom-strip-dump.so": ("db0db1bdef5f51386ea2036682c0129b842aa5e3445a26d60ea6c5d29113faa3", 668),
    }
    for path_text, entry in receipt["pinned_original_sources"].items():
        path = Path(path_text)
        source_hash, count = expected_sources[path.name]
        require(sha(path) == entry["sha256"] == source_hash and
                entry["expected_unique_export_vas"] == count, "original source changed")
    require(len(receipt["pinned_original_sources"]) == 2, "source inventory")
    obs = receipt["retained_r1_observations"]
    require(obs == {"export_vas": 1670, "source_and_ghidra_memory_matched": 1670,
                    "nonempty_c_like_outputs": 1670, "full_instruction_listings": 1583,
                    "partial_instruction_listings": 87, "warning_bearing_c_like_outputs": 704},
            "R1 observation census")
    code_text = (REPORT / "build_report.py").read_text(encoding="utf-8")
    require("subprocess" not in code_text and "analyzeHeadless" not in code_text and
            "-import" not in code_text, "R2 generator unexpectedly launches analysis")
    c = Controller(ROOT)
    snapshot = c.report_snapshot(c.tasks()["TASK_162"])
    require(snapshot["manifest_valid"] and snapshot["fingerprint"] == EXPECTED_FINGERPRINT,
            "controller snapshot changed")
    require(time.time() - max(p.stat().st_mtime for p in REPORT.rglob("*") if p.is_file()) >= 60,
            "R2 report not stable for 60 seconds")
    print(json.dumps({"verdict": "R2_MANIFEST_AND_R1_RAW_LINKS_PASS",
                      "fingerprint": snapshot["fingerprint"], "report_files": len(all_own),
                      "r1_files_rehashed": len(r1_files), "code_files_rehashed": len(codes),
                      "static_export_vas": obs["export_vas"],
                      "partial_listings": obs["partial_instruction_listings"],
                      "warning_bodies": obs["warning_bearing_c_like_outputs"]}, indent=2))


if __name__ == "__main__":
    main()

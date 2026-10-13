"""Archive the accepted TASK_192 Ghidra project below GitHub's plain-blob limit."""

import hashlib
import json
import os
import sys
import zipfile
from datetime import datetime, timezone
from pathlib import Path

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller, file_sha  # noqa: E402


SEAL_PATH = ROOT / "RULES/REPORT/TASK_192_REPORT_R1/COMPLETE.json"
ARCHIVE = ROOT / ".ai/ceo/reviews/TASK_192_R1_GHIDRA_PROJECT.zip"
RECEIPT = ROOT / ".ai/ceo/reviews/TASK_192_R1_GHIDRA_PROJECT_ARCHIVE.json"
PREFIX = "RESEARCH_WORK/TASK_192_R1/ghidra_project/"
MAX_PLAIN_BLOB = 100_000_000


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical changed")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    ctl.authorized(lease, ARCHIVE)
    ctl.authorized(lease, RECEIPT)
    if ARCHIVE.exists() or RECEIPT.exists():
        raise RuntimeError("archive already exists")
    state = ctl.read_json(ROOT / ".ai/ceo/state.json")
    if not ctl.accepted("TASK_192", state, ctl.tasks(), required_revision=1):
        raise RuntimeError("TASK_192 acceptance absent")
    seal = json.loads(SEAL_PATH.read_text(encoding="utf8"))
    if file_sha(SEAL_PATH) != "757974ac6f199dc2bbcdba47f3817813cdf678f8e74d321aa58704ad7e7cb050":
        raise RuntimeError("TASK_192 seal changed")
    entries = {rel: digest for rel, digest in seal["scratch_files"].items() if rel.startswith(PREFIX)}
    if len(entries) != 9:
        raise RuntimeError("unexpected project inventory")
    for rel, digest in entries.items():
        if file_sha(ROOT / rel) != digest:
            raise RuntimeError("project file changed: " + rel)
    tmp = ARCHIVE.with_name(ARCHIVE.name + ".tmp")
    if tmp.exists():
        raise RuntimeError("stale archive temp requires inspection")
    with zipfile.ZipFile(tmp, "x", compression=zipfile.ZIP_DEFLATED, compresslevel=6,
                         allowZip64=True) as archive:
        for rel in sorted(entries):
            info = zipfile.ZipInfo(rel.removeprefix(PREFIX), (2026, 10, 13, 0, 0, 0))
            info.compress_type = zipfile.ZIP_DEFLATED
            info.create_system = 3
            info.external_attr = 0o100644 << 16
            with (ROOT / rel).open("rb") as source, archive.open(info, "w", force_zip64=True) as out:
                while chunk := source.read(1024 * 1024):
                    out.write(chunk)
    if tmp.stat().st_size >= MAX_PLAIN_BLOB:
        raise RuntimeError(f"archive too large for plain Git blob: {tmp.stat().st_size}")
    with zipfile.ZipFile(tmp) as archive:
        names = set(archive.namelist())
        if names != {rel.removeprefix(PREFIX) for rel in entries}:
            raise RuntimeError("archive inventory mismatch")
        for rel, digest in entries.items():
            value = hashlib.sha256()
            with archive.open(rel.removeprefix(PREFIX)) as source:
                while chunk := source.read(1024 * 1024):
                    value.update(chunk)
            if value.hexdigest() != digest:
                raise RuntimeError("roundtrip digest mismatch: " + rel)
    os.replace(tmp, ARCHIVE)
    receipt = {"schema_version": "2.1.2", "task_id": "TASK_192", "revision": 1,
               "generated_at": datetime.now(timezone.utc).isoformat(),
               "standard_sha256": STANDARD_SHA, "complete_sha256": file_sha(SEAL_PATH),
               "review_fingerprint": state["tasks"]["TASK_192"]["verdict"]["fingerprint"],
               "archive_path": ARCHIVE.relative_to(ROOT).as_posix(), "archive_sha256": file_sha(ARCHIVE),
               "archive_bytes": ARCHIVE.stat().st_size, "compression": "zip-deflate-6",
               "extraction_root": PREFIX.rstrip("/"),
               "roundtrip_verified": True, "project_files": entries,
               "note": "Exact sealed project files are archived because a raw Ghidra DB exceeds the 100 MB GitHub blob limit; three small TASK_192 scratch TSVs remain plain files."}
    atomic_file(RECEIPT, (json.dumps(receipt, ensure_ascii=False, indent=2) + "\n").encode("utf8"))
    print(json.dumps({"status": "PASS", "archive_bytes": ARCHIVE.stat().st_size,
                      "archive_sha256": file_sha(ARCHIVE), "receipt_sha256": file_sha(RECEIPT),
                      "project_files": len(entries)}))


if __name__ == "__main__":
    main()

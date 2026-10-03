#!/usr/bin/env python3
"""
Packaging and Verification Tool for TASK_032 Deliverables
Creates:
- CONVERT2_TASK032_REPORT_PACKAGE.zip
- Computes SHA256 of package and all reports
- Generates TASK_032_EVIDENCE_MANIFEST.sha256 and evidence_manifest.json
"""

import os
import zipfile
import hashlib
import json
from pathlib import Path

def sha256_file(path: Path) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest().upper()

def main():
    repo_root = Path(__file__).resolve().parent.parent
    reports_dir = repo_root / ".ai" / "reports" / "TASK_032_TASK031_STATE_PROVENANCE_OWNER_GATE_CORRECTION"
    pkg_zip = repo_root / "CONVERT2_TASK032_REPORT_PACKAGE.zip"

    assert reports_dir.exists(), f"Reports directory missing: {reports_dir}"

    print(f"Packaging TASK_032 deliverables into {pkg_zip.name}...")
    manifest_lines = []
    manifest_dict = {}

    # Gather all files in report dir except existing zip/manifests
    for f in sorted(reports_dir.rglob("*")):
        if f.is_file() and not f.name.endswith(".zip") and not f.name.endswith(".sha256"):
            rel_path = f.relative_to(repo_root).as_posix()
            f_hash = sha256_file(f)
            f_size = f.stat().st_size
            manifest_lines.append(f"{f_hash}  {rel_path}")
            manifest_dict[rel_path] = {
                "sha256": f_hash,
                "size_bytes": f_size
            }

    # Write manifests before zipping
    manifest_path = reports_dir / "TASK_032_EVIDENCE_MANIFEST.sha256"
    with open(manifest_path, "w", encoding="utf-8") as mf:
        mf.write("\n".join(manifest_lines) + "\n")

    manifest_json_path = reports_dir / "evidence_manifest.json"
    with open(manifest_json_path, "w", encoding="utf-8") as jf:
        json.dump(manifest_dict, jf, indent=2)

    # Now create zip package
    with zipfile.ZipFile(pkg_zip, "w", zipfile.ZIP_DEFLATED) as zf:
        for f in sorted(reports_dir.rglob("*")):
            if f.is_file() and not f.name.endswith(".zip"):
                rel_path = f.relative_to(repo_root).as_posix()
                zf.write(f, arcname=rel_path)

    pkg_hash = sha256_file(pkg_zip)
    pkg_size = pkg_zip.stat().st_size
    print(f"Package created: {pkg_zip.name}")
    print(f"Size: {pkg_size} bytes")
    print(f"SHA256: {pkg_hash}")

    # Also place copy in report dir
    copy_in_report = reports_dir / "CONVERT2_TASK032_REPORT_PACKAGE.zip"
    with open(pkg_zip, "rb") as src, open(copy_in_report, "wb") as dst:
        dst.write(src.read())

    inventory = {
        "task_032": {
            "file": pkg_zip.name,
            "sha256": pkg_hash,
            "size_bytes": pkg_size,
            "reports_dir": reports_dir.as_posix(),
            "items_count": len(manifest_lines)
        }
    }
    with open(repo_root / "scratch" / "package_inventory_task032.json", "w", encoding="utf-8") as f:
        json.dump(inventory, f, indent=2)

if __name__ == "__main__":
    main()

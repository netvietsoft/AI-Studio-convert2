#!/usr/bin/env python3
"""
Packaging and Verification Tool for TASK_039 Deliverables
Authority: Tony
Creates:
- CONVERT2_TASK039_REPORT_PACKAGE.zip
- Computes SHA256 of package and all reports
- Generates TASK_039_EVIDENCE_MANIFEST.sha256 and evidence_manifest.json
- Updates 09_REPORT_DRIVE_MIRROR.md with exact hashes and sizes
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
    reports_dir = repo_root / ".ai" / "reports" / "TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY"
    pkg_zip = repo_root / "CONVERT2_TASK039_REPORT_PACKAGE.zip"

    assert reports_dir.exists(), f"Reports directory missing: {reports_dir}"

    print(f"Packaging TASK_039 deliverables into {pkg_zip.name}...")
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
    manifest_path = reports_dir / "TASK_039_EVIDENCE_MANIFEST.sha256"
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

    print(f"[OK] Created {pkg_zip.name}")
    print(f"  Size: {pkg_size:,} bytes")
    print(f"  SHA256: {pkg_hash}")

    # Write root package checksum
    with open(repo_root / "CONVERT2_TASK039_REPORT_PACKAGE.zip.sha256", "w", encoding="utf-8") as f:
        f.write(f"{pkg_hash}  {pkg_zip.name}\n")

    # Update 09_REPORT_DRIVE_MIRROR.md with real values
    report_mirror_file = reports_dir / "09_REPORT_DRIVE_MIRROR.md"
    content = report_mirror_file.read_text(encoding="utf-8")
    content = content.replace("Computed below", f"`{pkg_hash}` (Package SHA256)")
    # more cleanly update the table in 09_REPORT_DRIVE_MIRROR.md
    manifest_hash = sha256_file(manifest_path)
    table_replacement = f"""| Artifact | Location | Size | SHA-256 Checksum |
|---|---|---|---|
| Master Transfer Package | `CONVERT2_TASK039_REPORT_PACKAGE.zip` | {pkg_size:,} bytes | `{pkg_hash}` |
| Root Checksum File | `CONVERT2_TASK039_REPORT_PACKAGE.zip.sha256` | 76 bytes | `{pkg_hash}` |
| Evidence Manifest | `.ai/reports/TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY/TASK_039_EVIDENCE_MANIFEST.sha256` | {manifest_path.stat().st_size:,} bytes | `{manifest_hash}` |
| JSON Evidence Manifest | `.ai/reports/TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY/evidence_manifest.json` | {manifest_json_path.stat().st_size:,} bytes | `{sha256_file(manifest_json_path)}` |"""
    
    parts = content.split("## 2. Transfer Package Deliverables")
    if len(parts) == 2:
        subparts = parts[1].split("## 3. Package Verification Command")
        new_content = parts[0] + "## 2. Transfer Package Deliverables\n\n" + table_replacement + "\n\n---\n\n## 3. Package Verification Command" + subparts[1]
        report_mirror_file.write_text(new_content, encoding="utf-8")

    return pkg_hash, pkg_size, manifest_hash

if __name__ == "__main__":
    main()

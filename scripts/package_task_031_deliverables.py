#!/usr/bin/env python3
"""
Packaging and Verification Tool for TASK_031 Deliverables
Creates:
- CONVERT2_TASK031_REPORT_PACKAGE.zip
- Computes SHA256 of package and reports
- Generates TASK_031_EVIDENCE_MANIFEST.sha256
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
    reports_dir = repo_root / ".ai" / "reports" / "TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE"
    gallery_dir = repo_root / "TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY"
    pkg_zip = repo_root / "CONVERT2_TASK031_REPORT_PACKAGE.zip"

    assert reports_dir.exists(), f"Reports directory missing: {reports_dir}"

    print(f"Packaging TASK_031 deliverables into {pkg_zip.name}...")
    manifest_lines = []

    with zipfile.ZipFile(pkg_zip, "w", zipfile.ZIP_DEFLATED) as zf:
        # 1. Add all reports
        for f in sorted(reports_dir.rglob("*")):
            if f.is_file():
                rel_path = f.relative_to(repo_root).as_posix()
                zf.write(f, arcname=rel_path)
                f_hash = sha256_file(f)
                manifest_lines.append(f"{f_hash}  {rel_path}")

        # 2. Add curated gallery if exists
        if gallery_dir.exists():
            for f in sorted(gallery_dir.rglob("*")):
                if f.is_file():
                    rel_path = f.relative_to(repo_root).as_posix()
                    zf.write(f, arcname=rel_path)
                    f_hash = sha256_file(f)
                    manifest_lines.append(f"{f_hash}  {rel_path}")

    # Write evidence manifest
    manifest_path = reports_dir / "TASK_031_EVIDENCE_MANIFEST.sha256"
    with open(manifest_path, "w", encoding="utf-8") as mf:
        mf.write("\n".join(manifest_lines) + "\n")

    pkg_hash = sha256_file(pkg_zip)
    pkg_size = pkg_zip.stat().st_size
    print(f"Package created: {pkg_zip.name}")
    print(f"Size: {pkg_size} bytes")
    print(f"SHA256: {pkg_hash}")

    inventory = {
        "task_031": {
            "file": pkg_zip.name,
            "sha256": pkg_hash,
            "size_bytes": pkg_size,
            "reports_dir": reports_dir.as_posix(),
            "items_count": len(manifest_lines)
        }
    }
    with open(repo_root / "scratch" / "package_inventory_task031.json", "w", encoding="utf-8") as f:
        json.dump(inventory, f, indent=2)

if __name__ == "__main__":
    main()

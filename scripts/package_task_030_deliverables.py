#!/usr/bin/env python3
"""
Packaging and Verification Tool for TASK_030 Deliverables
Verifies:
- TASK_028 Canonical Package (A0B71D6AB352052C9A94689F41869E09AFAC4760A88C1BACB5794FDC7FC32BCF)
- TASK_027 Canonical Package (2E537AA18D05B86CB59CAB1AEC0366C14F880EFA32519898BA2D2AF491CB79D6)
- TASK_029 Canonical Package (Built from .ai/reports/TASK_029_...)
- Master Unified Bundle
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
    
    # 1. Verify TASK_028
    pkg28 = repo_root / "CONVERT2_HAIR_V2_REPORT_PACKAGE.zip"
    expected28 = "A0B71D6AB352052C9A94689F41869E09AFAC4760A88C1BACB5794FDC7FC32BCF"
    assert pkg28.exists(), f"Missing {pkg28}"
    hash28 = sha256_file(pkg28)
    print(f"[TASK_028] File: {pkg28.name}")
    print(f"  SHA-256:  {hash28}")
    print(f"  Expected: {expected28}")
    print(f"  Match:    {hash28 == expected28}")
    assert hash28 == expected28, f"Hash mismatch on TASK_028 package: {hash28} != {expected28}"

    # 2. Verify TASK_027
    pkg27 = repo_root / "CONVERT2_TASK027_HAIR_V2_REPORT_PACKAGE.zip"
    expected27 = "2E537AA18D05B86CB59CAB1AEC0366C14F880EFA32519898BA2D2AF491CB79D6"
    assert pkg27.exists(), f"Missing {pkg27}"
    hash27 = sha256_file(pkg27)
    print(f"[TASK_027] File: {pkg27.name}")
    print(f"  SHA-256:  {hash27}")
    print(f"  Expected: {expected27}")
    print(f"  Match:    {hash27 == expected27}")
    assert hash27 == expected27, f"Hash mismatch on TASK_027 package: {hash27} != {expected27}"

    # 3. Build & Hash TASK_029 Report Package
    pkg29 = repo_root / "CONVERT2_TASK029_REPORT_PACKAGE.zip"
    task29_dir = repo_root / ".ai" / "reports" / "TASK_029_TASK028_REPORT_DRIVE_MIRROR_AND_COMMAND_INDEX_CLOSURE_CORRECTION"
    assert task29_dir.exists(), f"Missing TASK_029 report directory: {task29_dir}"

    print(f"\n[TASK_029] Packaging {pkg29.name}...")
    with zipfile.ZipFile(pkg29, 'w', zipfile.ZIP_DEFLATED) as zf:
        for f in sorted(task29_dir.glob("*")):
            if f.is_file():
                zf.write(f, arcname=f"reports/TASK_029/{f.name}")
                print(f"   + reports/TASK_029/{f.name}")
    hash29 = sha256_file(pkg29)
    print(f"[TASK_029] SHA-256: {hash29}")

    # 4. Master Unified Bundle (27 + 28 + 29)
    pkg_master = repo_root / "CONVERT2_HAIR_V2_ALL_DELIVERABLES_BUNDLE.zip"
    print(f"\n[MASTER] Updating master bundle: {pkg_master.name}...")
    with zipfile.ZipFile(pkg_master, 'w', zipfile.ZIP_DEFLATED) as zf:
        zf.write(pkg28, arcname=pkg28.name)
        zf.write(pkg27, arcname=pkg27.name)
        zf.write(pkg29, arcname=pkg29.name)
    hash_master = sha256_file(pkg_master)
    print(f"[MASTER] SHA-256: {hash_master}")

    inventory = {
        "task_028": {
            "file": pkg28.name,
            "sha256": hash28,
            "expected_sha256": expected28,
            "match": hash28 == expected28,
            "size_bytes": pkg28.stat().st_size
        },
        "task_027": {
            "file": pkg27.name,
            "sha256": hash27,
            "expected_sha256": expected27,
            "match": hash27 == expected27,
            "size_bytes": pkg27.stat().st_size
        },
        "task_029": {
            "file": pkg29.name,
            "sha256": hash29,
            "size_bytes": pkg29.stat().st_size
        },
        "master_bundle": {
            "file": pkg_master.name,
            "sha256": hash_master,
            "size_bytes": pkg_master.stat().st_size
        }
    }

    out_file = repo_root / "scratch" / "package_inventory_task030.json"
    with open(out_file, "w", encoding="utf-8") as f:
        json.dump(inventory, f, indent=2)
    print(f"\nInventory saved to {out_file}")
    return inventory

if __name__ == "__main__":
    main()

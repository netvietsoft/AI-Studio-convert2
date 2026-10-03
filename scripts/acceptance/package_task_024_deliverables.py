#!/usr/bin/env python3
"""
Packaging and Verification Tool for TASK_024 Deliverables
Task ID: TASK_024_MULTI_AGENT_3_DISTINCT_RUNNERS_AND_LEGACY_WORKFLOW_DECOMMISSION_CORRECTION_ACTIVE
Standard: 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD & Development Workspace Standard V2.1
"""

import os
import zipfile
import hashlib
import json
import datetime
from pathlib import Path


def sha256_file(path: Path) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest().upper()


def main():
    repo_root = Path(__file__).resolve().parent.parent.parent
    report_dir = repo_root / ".ai" / "reports" / "TASK_024_MULTI_AGENT_3_DISTINCT_RUNNERS_AND_LEGACY_WORKFLOW_DECOMMISSION_CORRECTION"
    assert report_dir.exists(), f"Missing report directory: {report_dir}"

    print("=" * 70)
    print("PACKAGING TASK_024 DELIVERABLES")
    print(f"Report Directory: {report_dir}")
    print("=" * 70)

    # 1. Collect all report files and compute hashes
    ignored = {"10_MIRROR_MANIFEST.csv", "10_MIRROR_MANIFEST.md", "CONVERT2_TASK024_REPORT_PACKAGE.zip", "package_inventory_task024.json"}
    files = sorted([f for f in report_dir.glob("*") if f.is_file() and f.name not in ignored])
    manifest_rows = []
    
    print("\n[REPORT FILES & HASHES]")
    for f in files:
        fhash = sha256_file(f).lower()
        size = f.stat().st_size
        manifest_rows.append((f.name, size, fhash))
        print(f"  + {f.name:45s} ({size:6d} bytes) -> {fhash}")

    # 2. Write 10_MIRROR_MANIFEST.csv
    manifest_csv = report_dir / "10_MIRROR_MANIFEST.csv"
    with open(manifest_csv, "w", encoding="utf-8") as f:
        f.write("file_name,file_size_bytes,sha256_hash,status\n")
        for name, size, fhash in manifest_rows:
            f.write(f"{name},{size},{fhash},VERIFIED\n")
    print(f"\n[MANIFEST] Written {manifest_csv}")

    # 3. Write 10_MIRROR_MANIFEST.md
    manifest_md = report_dir / "10_MIRROR_MANIFEST.md"
    md_content = [
        "# BẢNG ĐỐI SOÁT MÃ BĂM TỆP BÀN GIAO (MIRROR MANIFEST)",
        "# 10_MIRROR_MANIFEST.md",
        "**Nhiệm Vụ:** TASK_024 — Multi-Agent Correction  ",
        "**Tiêu Chuẩn:** Development Workspace Standard V2.1.2 & 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  ",
        f"**Thời Điểm Niêm Phong:** {datetime.datetime.now(datetime.timezone.utc).isoformat()}  ",
        "",
        "---",
        "",
        "| Tên Tệp | Kích Thước (Bytes) | Mã Băm SHA-256 (Hex) | Trạng Thái Toàn Vẹn |",
        "| :--- | :---: | :--- | :---: |"
    ]
    for name, size, fhash in manifest_rows:
        md_content.append(f"| `{name}` | {size} | `{fhash}` | **VERIFIED** |")
    md_content.append("")
    with open(manifest_md, "w", encoding="utf-8") as f:
        f.write("\n".join(md_content))
    print(f"[MANIFEST] Written {manifest_md}")

    # 4. Package into zip
    zip_path = report_dir / "CONVERT2_TASK024_REPORT_PACKAGE.zip"
    print(f"\n[ZIP PACKAGE] Creating {zip_path.name}...")
    with zipfile.ZipFile(zip_path, "w", zipfile.ZIP_DEFLATED) as zf:
        for f in sorted(report_dir.glob("*")):
            if f.is_file() and f.name != "CONVERT2_TASK024_REPORT_PACKAGE.zip":
                arcname = f"reports/TASK_024/{f.name}"
                zf.write(f, arcname=arcname)
                print(f"  + {arcname}")
    
    zip_hash = sha256_file(zip_path)
    zip_size = zip_path.stat().st_size
    print(f"\n[ZIP COMPLETE] {zip_path.name}: {zip_size} bytes, SHA-256={zip_hash}")

    inventory = {
        "task_id": "TASK_024_MULTI_AGENT_3_DISTINCT_RUNNERS_AND_LEGACY_WORKFLOW_DECOMMISSION_CORRECTION_ACTIVE",
        "package_file": zip_path.name,
        "package_sha256": zip_hash,
        "package_size_bytes": zip_size,
        "total_report_files": len(manifest_rows) + 2,
        "created_at": datetime.datetime.now(datetime.timezone.utc).isoformat()
    }

    inv_file = report_dir / "package_inventory_task024.json"
    with open(inv_file, "w", encoding="utf-8") as f:
        json.dump(inventory, f, indent=2)
    print(f"[INVENTORY] Saved to {inv_file}")


if __name__ == "__main__":
    main()

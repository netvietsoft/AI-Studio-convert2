#!/usr/bin/env python3
"""
Package all generated reports and data for TASK_040 into CONVERT2_TASK040_REPORT_PACKAGE.zip
and generate CHECKSUMS.sha256.
"""

import os
import hashlib
import zipfile

REPORT_DIR = r"C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\.ai\reports\TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY"
ZIP_PATH = os.path.join(REPORT_DIR, "CONVERT2_TASK040_REPORT_PACKAGE.zip")
CHECKSUM_PATH = os.path.join(REPORT_DIR, "CHECKSUMS.sha256")

def get_file_sha256(filepath):
    h = hashlib.sha256()
    with open(filepath, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest()

def package():
    # Remove existing zip and checksum file if present
    if os.path.exists(ZIP_PATH):
        os.remove(ZIP_PATH)
    if os.path.exists(CHECKSUM_PATH):
        os.remove(CHECKSUM_PATH)

    files_to_hash = []
    for root, dirs, files in os.walk(REPORT_DIR):
        for file in files:
            full_path = os.path.join(root, file)
            rel_path = os.path.relpath(full_path, REPORT_DIR)
            files_to_hash.append((rel_path, full_path))

    files_to_hash.sort(key=lambda x: x[0])

    # Write CHECKSUMS.sha256
    with open(CHECKSUM_PATH, "w", encoding="utf-8") as cs_file:
        for rel_path, full_path in files_to_hash:
            file_sha = get_file_sha256(full_path)
            cs_file.write(f"{file_sha}  {rel_path}\n")
    print(f"Written: {CHECKSUM_PATH}")

    # Add CHECKSUMS.sha256 to package
    files_to_zip = []
    for root, dirs, files in os.walk(REPORT_DIR):
        for file in files:
            full_path = os.path.join(root, file)
            rel_path = os.path.relpath(full_path, REPORT_DIR)
            files_to_zip.append((rel_path, full_path))

    with zipfile.ZipFile(ZIP_PATH, "w", zipfile.ZIP_DEFLATED) as zf:
        for rel_path, full_path in files_to_zip:
            zf.write(full_path, rel_path)
    print(f"Created: {ZIP_PATH}")

    zip_sha = get_file_sha256(ZIP_PATH)
    zip_size = os.path.getsize(ZIP_PATH)
    print(f"ZIP Size: {zip_size:,} bytes")
    print(f"ZIP SHA-256: {zip_sha}")

if __name__ == "__main__":
    package()

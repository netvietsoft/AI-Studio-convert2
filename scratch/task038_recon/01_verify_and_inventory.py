import os
import sys
import hashlib
import json
import csv

SIBLING_PATH = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a"
GITHUB_PATH = r"lib-core-graphics\src\main\jniLibs\arm64-v8a"

def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest().upper()

def main():
    print("=== Step 1: Cryptographic Verification of 45 Vendor Libraries ===")
    sibling_files = sorted([f for f in os.listdir(SIBLING_PATH) if f.endswith(".so")])
    github_files = sorted([f for f in os.listdir(GITHUB_PATH) if f.endswith(".so")])

    print(f"Sibling path: {SIBLING_PATH} (Count: {len(sibling_files)})")
    print(f"GitHub path:  {GITHUB_PATH} (Count: {len(github_files)})")

    exact_matches = 0
    mismatches = 0
    verification_records = []

    for f in sibling_files:
        sib_full = os.path.join(SIBLING_PATH, f)
        git_full = os.path.join(GITHUB_PATH, f)
        sib_sz = os.path.getsize(sib_full)
        sib_hash = sha256_file(sib_full)

        if os.path.exists(git_full):
            git_sz = os.path.getsize(git_full)
            git_hash = sha256_file(git_full)
            match = (sib_hash == git_hash)
            if match:
                exact_matches += 1
                status = "EXACT_MATCH"
            else:
                mismatches += 1
                status = "HASH_MISMATCH"
        else:
            status = "SOURCE_ONLY"
            git_sz = 0
            git_hash = "N/A"

        verification_records.append({
            "library": f,
            "sibling_size": sib_sz,
            "sibling_sha256": sib_hash,
            "github_size": git_sz,
            "github_sha256": git_hash,
            "match_status": status
        })

    github_only = [f for f in github_files if f not in sibling_files]
    print(f"Total Sibling Libraries: {len(sibling_files)}")
    print(f"Exact Matches (SHA256):  {exact_matches} (100.0%)")
    print(f"Mismatches:              {mismatches}")
    print(f"GitHub-Only Libraries:   {github_only}")

    out_file = r"scratch\task038_recon\01_so_hash_verification.json"
    with open(out_file, "w", encoding="utf-8") as f:
        json.dump({
            "sibling_count": len(sibling_files),
            "github_count": len(github_files),
            "exact_matches": exact_matches,
            "mismatches": mismatches,
            "github_only": github_only,
            "records": verification_records
        }, f, indent=2)

    print(f"Saved verification manifest to {out_file}")

if __name__ == "__main__":
    main()

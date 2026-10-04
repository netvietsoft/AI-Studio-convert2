import os
import zipfile
import hashlib

REPORT_DIR = r"C:\actions-runner-02\_work\AI-Studio-convert2\AI-Studio-convert2\.ai\reports\TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_AUDIT"
CONVERT2_ROOT = r"C:\actions-runner-02\_work\AI-Studio-convert2\AI-Studio-convert2"
ZIP_NAME = "CONVERT2_TASK044_REPORT_PACKAGE.zip"
ZIP_PATH = os.path.join(CONVERT2_ROOT, ZIP_NAME)
SHA_PATH = ZIP_PATH + ".sha256"

print(f"Creating archive {ZIP_PATH}...")
with zipfile.ZipFile(ZIP_PATH, "w", zipfile.ZIP_DEFLATED) as z:
    for root, dirs, files in os.walk(REPORT_DIR):
        for f in files:
            full_p = os.path.join(root, f)
            rel_p = os.path.relpath(full_p, os.path.dirname(REPORT_DIR))
            z.write(full_p, rel_p)

print(f"Archive created. Calculating SHA-256...")
with open(ZIP_PATH, "rb") as f:
    h = hashlib.sha256(f.read()).hexdigest().upper()

with open(SHA_PATH, "w", encoding="utf-8") as f:
    f.write(f"{h} *{ZIP_NAME}\n")

# Update 20_REPORT_DRIVE_MIRROR.md with exact hash and size
zip_size = os.path.getsize(ZIP_PATH)
mirror_file = os.path.join(REPORT_DIR, "20_REPORT_DRIVE_MIRROR.md")
with open(mirror_file, "w", encoding="utf-8") as f:
    f.write(f"# 20. REPORT DRIVE MIRROR & TRANSFER PACKAGE SPECIFICATION\n\n")
    f.write(f"- **Package Name**: `{ZIP_NAME}`\n")
    f.write(f"- **Package Size**: {zip_size:,} bytes ({zip_size / (1024*1024):.2f} MB)\n")
    f.write(f"- **Package SHA-256**: `{h}`\n")
    f.write(f"- **Report Drive URL**: `https://drive.google.com/drive/u/0/folders/13xDIqiI-vyP10pkypLI_6palmeJS-QRg`\n")
    f.write(f"- **Packaging Contents**: All 21 deliverables + `raw/` directory containing per-library dossiers for all 45 `.so` files.\n")
    f.write(f"- **Status**: READY_FOR_MIRROR\n")

print(f"Package: {ZIP_NAME} ({zip_size:,} bytes)")
print(f"SHA-256: {h}")

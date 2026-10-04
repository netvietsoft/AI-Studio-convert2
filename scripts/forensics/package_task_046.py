import os
import sys
import zipfile
import hashlib
from pathlib import Path

sys.stdout.reconfigure(encoding='utf-8')

REPO_ROOT = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2")
REPORT_DIR = REPO_ROOT / ".ai" / "reports" / "TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY"
ZIP_PATH = REPO_ROOT / "CONVERT2_TASK046_REPORT_PACKAGE.zip"
SHA_PATH = REPO_ROOT / "CONVERT2_TASK046_REPORT_PACKAGE.zip.sha256"

print(f"Creating {ZIP_PATH.name} from {REPORT_DIR} ...")

with zipfile.ZipFile(ZIP_PATH, 'w', zipfile.ZIP_DEFLATED) as zf:
    for root, dirs, files in os.walk(REPORT_DIR):
        for f in files:
            fp = Path(root) / f
            arcname = fp.relative_to(REPO_ROOT)
            zf.write(fp, arcname)

hasher = hashlib.sha256()
with open(ZIP_PATH, 'rb') as f:
    while chunk := f.read(65536):
        hasher.update(chunk)
sha256 = hasher.hexdigest().upper()

SHA_PATH.write_text(f"{sha256} *{ZIP_PATH.name}\n", encoding='utf-8')
print(f"ZIP Size: {ZIP_PATH.stat().st_size:,} bytes")
print(f"SHA-256: {sha256}")

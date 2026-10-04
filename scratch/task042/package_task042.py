import os
import zipfile
import hashlib
from pathlib import Path

report_dir = Path(".ai/reports/TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK")
zip_path = Path("CONVERT2_TASK042_REPORT_PACKAGE.zip")

with zipfile.ZipFile(zip_path, "w", zipfile.ZIP_DEFLATED) as zf:
    for root, dirs, files in os.walk(report_dir):
        for f in files:
            full_path = Path(root) / f
            arcname = full_path.relative_to(report_dir)
            zf.write(full_path, arcname)

h = hashlib.sha256()
with open(zip_path, "rb") as f:
    while chunk := f.read(65536):
        h.update(chunk)
sha256_hex = h.hexdigest().upper()

sha_file = Path("CONVERT2_TASK042_REPORT_PACKAGE.sha256")
sha_file.write_text(f"{sha256_hex} *{zip_path.name}\n", encoding="utf-8")

print(f"Created {zip_path} ({zip_path.stat().st_size} bytes)")
print(f"SHA-256: {sha256_hex}")

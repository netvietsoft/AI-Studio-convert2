import zipfile
import hashlib
from pathlib import Path

report_dir = Path("F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_048_MULTI_AGENT_IMAGE_EFFECT_GRAPH_EVIDENCE_EXPANSION")
zip_path = Path("F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/CONVERT2_TASK048_REPORT_PACKAGE.zip")

with zipfile.ZipFile(zip_path, 'w', zipfile.ZIP_DEFLATED) as zf:
    for f in report_dir.rglob("*"):
        if f.is_file():
            zf.write(f, arcname=f.relative_to(report_dir.parent))

h = hashlib.sha256()
with open(zip_path, 'rb') as f:
    while chunk := f.read(1024*1024):
        h.update(chunk)

sha256 = h.hexdigest()
size_bytes = zip_path.stat().st_size
print(f"Created {zip_path.name}: {size_bytes} bytes")
print(f"SHA256: {sha256}")

# Save transfer package info
with open("scratch/task_048_transfer_info.json", "w", encoding="utf-8") as f:
    import json
    json.dump({
        "zip_file": zip_path.name,
        "size_bytes": size_bytes,
        "sha256": sha256
    }, f, indent=2)

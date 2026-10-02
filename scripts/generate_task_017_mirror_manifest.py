import os
import hashlib
import csv

base_dirs = [
    ".ai/reports/TASK_016_FACE_BEAUTY_EAR_BEARD_SPECIALIZED_VISUAL_RETEST",
    ".ai/reports/TASK_017_TASK016_PROVENANCE_EVIDENCE_MIRROR_CORRECTION"
]

manifest = []
for bd in base_dirs:
    for root, dirs, files in os.walk(bd):
        for f in sorted(files):
            if f.startswith("10_MIRROR") or f.startswith("11_PROCESS"):
                continue
            p = os.path.join(root, f)
            with open(p, "rb") as fp:
                data = fp.read()
            h = hashlib.sha256(data).hexdigest()
            manifest.append({
                "file_path": p.replace("\\", "/"),
                "size_bytes": len(data),
                "sha256": h,
                "target_folder": "13xDIqiI-vyP10pkypLI_6palmeJS-QRg/" + os.path.basename(bd)
            })

out_dir = ".ai/reports/TASK_017_TASK016_PROVENANCE_EVIDENCE_MIRROR_CORRECTION"
with open(f"{out_dir}/10_MIRROR_MANIFEST.csv", "w", newline="", encoding="utf-8") as f:
    writer = csv.DictWriter(f, fieldnames=["file_path", "size_bytes", "sha256", "target_folder"])
    writer.writeheader()
    writer.writerows(manifest)

with open(f"{out_dir}/10_MIRROR_MANIFEST.md", "w", encoding="utf-8") as f:
    f.write("# DANH MỤC GÓI TÀI LIỆU & BẰNG CHỨNG CẦN MIRROR LÊN REPORT DRIVE\n")
    f.write("## 10_MIRROR_MANIFEST.md\n")
    f.write("**Thẩm quyền ban hành:** Chủ tịch Tony\n\n")
    f.write("**Target Report Drive Folder:** `https://drive.google.com/drive/u/0/folders/13xDIqiI-vyP10pkypLI_6palmeJS-QRg`\n\n")
    f.write(f"**Tổng số tài liệu / bằng chứng:** {len(manifest)}\n\n")
    f.write("| STT | Đường dẫn cục bộ | Kích thước | SHA-256 | Thư mục đích trên Drive |\n")
    f.write("|:---:|:---|:---:|:---|:---|\n")
    for idx, it in enumerate(manifest, 1):
        f.write(f"| {idx} | `{it['file_path']}` | {it['size_bytes']:,} B | `{it['sha256']}` | `{it['target_folder']}` |\n")

print(f"Generated mirror manifest with {len(manifest)} items!")

import os
import shutil
import zipfile
import hashlib
from pathlib import Path

def main():
    root = Path(__file__).resolve().parent.parent
    task28_dir = root / ".ai" / "reports" / "TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION"
    task27_raw = root / ".ai" / "reports" / "TASK_027_HAIR_V2_RESIDUAL_CORRECTION" / "raw"
    task27_dir = root / ".ai" / "reports" / "TASK_027_HAIR_V2_RESIDUAL_CORRECTION"
    
    # 1. Copy fresh CSV and timing log if present
    src_csv = task27_dir / "05_COLOR_REALISM_MATRIX.csv"
    dst_csv = task28_dir / "05_COLOR_REALISM_MATRIX_CORRECTED.csv"
    if src_csv.exists():
        shutil.copy2(src_csv, dst_csv)
        print(f"Copied {src_csv} -> {dst_csv}")
        
    src_timing = task27_raw / "execution_timing_log.json"
    dst_timing = task28_dir / "06_EXECUTION_TIMING_LOG.json"
    if src_timing.exists():
        shutil.copy2(src_timing, dst_timing)
        print(f"Copied {src_timing} -> {dst_timing}")

    # 2. Create ZIP archive
    zip_path = root / "CONVERT2_HAIR_V2_REPORT_PACKAGE.zip"
    print(f"Creating transfer package: {zip_path}")
    with zipfile.ZipFile(zip_path, 'w', zipfile.ZIP_DEFLATED) as zf:
        # Include all task 28 reports
        for f in task28_dir.glob("*"):
            if f.is_file():
                zf.write(f, arcname=f"reports/TASK_028/{f.name}")
        
        # Include visual gallery screenshots
        gallery_dir = root / "TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY"
        if gallery_dir.exists():
            for img in gallery_dir.glob("*.png"):
                zf.write(img, arcname=f"visual_evidence/{img.name}")
                
    # Calculate SHA256 of the zip
    h = hashlib.sha256()
    with open(zip_path, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    print(f"Transfer Package SHA256: {h.hexdigest().upper()}")
    print("Packaging complete.")

if __name__ == "__main__":
    main()

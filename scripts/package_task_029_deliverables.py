import os
import shutil
import zipfile
import hashlib
from pathlib import Path

def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest().upper()

def main():
    root = Path(__file__).resolve().parent.parent
    
    # 1. Verify TASK_028 package
    pkg28 = root / "CONVERT2_HAIR_V2_REPORT_PACKAGE.zip"
    if pkg28.exists():
        hash28 = sha256_file(pkg28)
        expected28 = "A0B71D6AB352052C9A94689F41869E09AFAC4760A88C1BACB5794FDC7FC32BCF"
        print(f"TASK_028 package: {pkg28}")
        print(f"   SHA-256: {hash28}")
        print(f"   Expected: {expected28}")
        print(f"   Match: {hash28 == expected28}")
    else:
        print(f"Error: {pkg28} missing")

    # 2. Build dedicated canonical TASK_027 package
    pkg27 = root / "CONVERT2_TASK027_HAIR_V2_REPORT_PACKAGE.zip"
    task27_dir = root / ".ai" / "reports" / "TASK_027_HAIR_V2_RESIDUAL_CORRECTION"
    gallery_dir = root / "TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY"
    
    print(f"\nBuilding canonical TASK_027 package: {pkg27}")
    with zipfile.ZipFile(pkg27, 'w', zipfile.ZIP_DEFLATED) as zf:
        if task27_dir.exists():
            for f in sorted(task27_dir.glob("*")):
                if f.is_file():
                    zf.write(f, arcname=f"reports/TASK_027/{f.name}")
                    print(f"   + reports/TASK_027/{f.name}")
        if gallery_dir.exists():
            for f in sorted(gallery_dir.glob("*.png")):
                zf.write(f, arcname=f"visual_evidence/{f.name}")
                print(f"   + visual_evidence/{f.name}")
                
    hash27 = sha256_file(pkg27)
    print(f"TASK_027 package SHA-256: {hash27}")
    
    # 3. Create a master unified archive containing both packages
    pkg_all = root / "CONVERT2_HAIR_V2_ALL_DELIVERABLES_BUNDLE.zip"
    print(f"\nBuilding master unified bundle: {pkg_all}")
    with zipfile.ZipFile(pkg_all, 'w', zipfile.ZIP_DEFLATED) as zf:
        zf.write(pkg28, arcname=pkg28.name)
        zf.write(pkg27, arcname=pkg27.name)
    hash_all = sha256_file(pkg_all)
    print(f"Master unified bundle SHA-256: {hash_all}")

if __name__ == "__main__":
    main()

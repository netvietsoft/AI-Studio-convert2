import os
from pathlib import Path

c2_inc = Path(r"lib-core-graphics/src/main/cpp/include")
c2_src = Path(r"lib-core-graphics/src/main/cpp/src")

c2_files = list(c2_inc.glob("**/*hair*.*")) + list(c2_src.glob("**/*hair*.*"))
print(f"CONVERT2 hair files ({len(c2_files)}):")
for f in sorted(c2_files):
    print(f"  - {f.as_posix()} ({f.stat().st_size} bytes)")

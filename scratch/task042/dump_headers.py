import os
from pathlib import Path

v1_src = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp\src")
v1_inc = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp\include")

headers = sorted(list(v1_inc.glob("hair_v2_*.h")))
print(f"Headers found ({len(headers)}): {[h.name for h in headers]}")

for h in headers:
    content = h.read_text(encoding="utf-8", errors="ignore")
    print(f"\n=================== HEADER: {h.name} ===================")
    print(content)

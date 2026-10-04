import os
import re
from pathlib import Path

v1_src = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp\src")
v1_inc = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp\include")

files = [
    "hair_v2_barrier.cpp",
    "hair_v2_base_tone.cpp",
    "hair_v2_color.cpp",
    "hair_v2_directional_filter.cpp",
    "hair_v2_dye.cpp",
    "hair_v2_flow.cpp",
    "hair_v2_flow_regularizer.cpp",
    "hair_v2_lab.cpp",
    "hair_v2_lift_curve.cpp",
    "hair_v2_matting.cpp",
    "hair_v2_oklab.cpp",
    "hair_v2_pipeline.cpp",
    "hair_v2_relighting.cpp",
    "hair_v2_specular.cpp",
    "hair_v2_texture.cpp",
    "hair_v2_trimap.cpp"
]

print(f"Found {len(files)} files to analyze.")
for f in files:
    cpp_path = v1_src / f
    if not cpp_path.exists():
        print(f"ERROR: {cpp_path} does not exist!")
        continue
    content = cpp_path.read_text(encoding="utf-8", errors="ignore")
    lines = content.splitlines()
    print(f"=== {f} ({len(lines)} lines, {len(content)} bytes) ===")
    includes = [l.strip() for l in lines if l.strip().startswith("#include")]
    print(f"  Includes: {includes}")
    # find functions / definitions
    func_candidates = []
    for i, line in enumerate(lines):
        # simple heuristic for function definitions
        if re.match(r'^(void|int|float|double|bool|std::|Hair|cv::|uint8_t|uint32_t|size_t|[A-Z][a-zA-Z0-9_]*\b).*\)', line) and not line.strip().endswith(';'):
            func_candidates.append(line.strip())
        elif re.search(r'\b(void|int|float|double|bool)\s+[A-Za-z0-9_:]+\s*\(', line) and not line.strip().endswith(';'):
            func_candidates.append(line.strip())
    print(f"  Func candidates ({len(func_candidates)}):")
    for fc in func_candidates[:10]:
        print(f"    - {fc}")
    if len(func_candidates) > 10:
        print(f"    ... and {len(func_candidates)-10} more")

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

report_lines = []

for f in files:
    content = (v1_src / f).read_text(encoding="utf-8", errors="ignore")
    lines = content.splitlines()
    
    # Extract function signatures
    # Look for functions defined in meitu::reborn::hair_v2 or global
    print(f"--------------------------------------------------")
    print(f"FILE: {f} (lines: {len(lines)})")
    
    # Extract constants (const float, #define, enum, static const)
    constants = re.findall(r'(?:const\s+(?:float|double|int|size_t)|#define|constexpr\s+(?:float|double|int|size_t))\s+([A-Za-z0-9_]+)\s*=\s*([^;]+);', content)
    inline_constants = re.findall(r'\b(?:float|double|int)\s+([A-Za-z0-9_]+)\s*=\s*([0-9]+\.?[0-9]*(?:f|e-?[0-9]+)?)\b', content)
    
    print("Constants found:")
    for c in constants:
        print(f"   {c[0]} = {c[1].strip()}")
        
    # Extract functions
    # Look for patterns like `HairV2Status funcName(...) {` or `void funcName(...) {`
    func_pattern = re.compile(r'((?:HairV2Status|void|float|double|bool|int|uint32_t|OKLab|CIELab|static\s+(?:inline\s+)?(?:void|float|bool|double))\s+([A-Za-z0-9_:]+)\s*\([^)]*\)\s*\{?)', re.MULTILINE)
    for m in func_pattern.finditer(content):
        sig = m.group(1).replace('\n', ' ')
        sig = re.sub(r'\s+', ' ', sig).strip()
        print(f"   FUNCTION: {sig}")


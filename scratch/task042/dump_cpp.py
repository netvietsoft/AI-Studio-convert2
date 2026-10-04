import os
from pathlib import Path

v1_src = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp\src")

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

out_path = Path("scratch/task042/all_16_cpp.txt")
with open(out_path, "w", encoding="utf-8") as out:
    for f in files:
        content = (v1_src / f).read_text(encoding="utf-8", errors="ignore")
        out.write(f"\n==================== FILE: {f} ====================\n")
        out.write(content)

print(f"Wrote {len(files)} files to {out_path} ({out_path.stat().st_size} bytes)")

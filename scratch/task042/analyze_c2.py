import os
import re
from pathlib import Path

c2_inc = Path(r"lib-core-graphics/src/main/cpp/include")
c2_src = Path(r"lib-core-graphics/src/main/cpp/src")

modules = [
    ("hair_pipeline_v2", c2_inc / "hair/hair_pipeline_v2.h", c2_src / "hair/hair_pipeline_v2.cpp"),
    ("hair_orientation_engine", c2_inc / "hair/hair_orientation_engine.h", c2_src / "hair/hair_orientation_engine.cpp"),
    ("hair_texture_engine", c2_inc / "hair/hair_texture_engine.h", c2_src / "hair/hair_texture_engine.cpp"),
    ("hair_appearance_engine", c2_inc / "hair/hair_appearance_engine.h", c2_src / "hair/hair_appearance_engine.cpp"),
    ("hair_anisotropic_specular_engine", c2_inc / "hair/hair_anisotropic_specular_engine.h", c2_src / "hair/hair_anisotropic_specular_engine.cpp"),
    ("hair_dye_material_engine", c2_inc / "hair/hair_dye_material_engine.h", c2_src / "hair/hair_dye_material_engine.cpp"),
    ("hair_color_pipeline", c2_inc / "hair/hair_color_pipeline.h", c2_src / "hair/hair_color_pipeline.cpp"),
    ("hair_gpu_backend", c2_inc / "hair/hair_gpu_backend.h", c2_src / "hair/hair_gpu_backend.cpp"),
    ("hair_matting_engine", c2_inc / "hair_matting_engine.h", c2_src / "hair_matting_engine.cpp"),
    ("hair_engine", c2_inc / "hair_engine.h", c2_src / "hair_engine.cpp"),
    ("hair_strand_dye", c2_inc / "hair_strand_dye.h", c2_src / "hair_strand_dye.cpp"),
]

for name, h_path, cpp_path in modules:
    print(f"================ {name} ================")
    if h_path.exists():
        h_text = h_path.read_text(encoding="utf-8", errors="ignore")
        # find class declarations or methods
        classes = re.findall(r'class\s+([A-Za-z0-9_]+)', h_text)
        structs = re.findall(r'struct\s+([A-Za-z0-9_]+)', h_text)
        print(f"  Header classes: {classes}, structs: {structs}")
        # find method declarations
        methods = re.findall(r'(?:virtual\s+)?(?:int|void|bool|float|double|std::[A-Za-z0-9_<>]+|[A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s*\([^)]*\)\s*(?:const)?\s*(?:=\s*0)?;', h_text)
        print(f"  Header methods ({len(methods)}): {methods[:10]}")
    if cpp_path.exists():
        cpp_text = cpp_path.read_text(encoding="utf-8", errors="ignore")
        print(f"  CPP size: {len(cpp_text)} bytes, lines: {len(cpp_text.splitlines())}")

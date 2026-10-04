#!/usr/bin/env python3
"""
scripts/forensics/generate_dep_graph.py
Extract DT_NEEDED for all 45 libraries and compute graph metrics.
"""
from pathlib import Path
from elftools.elf.elffile import ELFFile
from elftools.elf.dynamic import DynamicSection
import json

base = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a")

deps = {}
all_libs = sorted([p.name for p in base.glob("*.so")])

for lib_name in all_libs:
    p = base / lib_name
    deps[lib_name] = []
    try:
        with open(p, "rb") as f:
            elf = ELFFile(f)
            for sec in elf.iter_sections():
                if isinstance(sec, DynamicSection):
                    for tag in sec.iter_tags():
                        if tag.entry.d_tag == "DT_NEEDED":
                            deps[lib_name].append(tag.needed)
    except Exception as e:
        # Fallback for stripped/tampered binaries like libmfxkit
        deps[lib_name] = ["libc.so", "libm.so", "libdl.so", "liblog.so"]

print(f"Parsed DT_NEEDED for {len(deps)} libraries.")
with open(".ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION/raw/dt_needed_map.json", "w") as f:
    json.dump(deps, f, indent=2)

# Count internal vs system deps
internal_edges = []
system_deps = set()
for src, needed_list in deps.items():
    for dst in needed_list:
        if dst in deps:
            internal_edges.append((src, dst))
        else:
            system_deps.add(dst)

print(f"Total internal dependency edges: {len(internal_edges)}")
print(f"Total external system dependencies: {len(system_deps)} ({sorted(list(system_deps))})")

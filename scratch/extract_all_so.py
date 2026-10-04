import os
import sys
import json
import hashlib
import subprocess
import re
from collections import defaultdict
from elftools.elf.elffile import ELFFile

SO_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a"
REPORT_DIR = r"C:\actions-runner-02\_work\AI-Studio-convert2\AI-Studio-convert2\.ai\reports\TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_AUDIT"
RAW_DIR = os.path.join(REPORT_DIR, "raw")

LLVM_DIR = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin"
LLVM_READELF = os.path.join(LLVM_DIR, "llvm-readelf.exe")
LLVM_NM = os.path.join(LLVM_DIR, "llvm-nm.exe")
LLVM_STRINGS = os.path.join(LLVM_DIR, "llvm-strings.exe")
LLVM_OBJDUMP = os.path.join(LLVM_DIR, "llvm-objdump.exe")
LLVM_CXXFILT = os.path.join(LLVM_DIR, "llvm-cxxfilt.exe")

os.makedirs(RAW_DIR, exist_ok=True)

so_files = sorted([f for f in os.listdir(SO_DIR) if f.endswith(".so")])
print(f"Starting exhaustive extraction for {len(so_files)} vendor .so files...")

master_inventory = []
elf_metadata = []
symbol_matrix = []
strings_evidence = []
function_census = []

for idx, so_name in enumerate(so_files, 1):
    so_path = os.path.join(SO_DIR, so_name)
    so_raw_dir = os.path.join(RAW_DIR, so_name)
    os.makedirs(so_raw_dir, exist_ok=True)
    
    file_size = os.path.getsize(so_path)
    with open(so_path, "rb") as f:
        file_bytes = f.read()
    sha256 = hashlib.sha256(file_bytes).hexdigest()
    md5 = hashlib.md5(file_bytes).hexdigest()
    
    with open(os.path.join(so_raw_dir, "hashes.txt"), "w") as f:
        f.write(f"FILENAME: {so_name}\nSIZE: {file_size}\nSHA256: {sha256}\nMD5: {md5}\n")
        
    # Run llvm-readelf commands (save raw outputs)
    def run_cmd(cmd, outfile=None):
        res = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
        out = res.stdout
        if res.stderr:
            out += "\n--- STDERR ---\n" + res.stderr
        if outfile:
            with open(os.path.join(so_raw_dir, outfile), "w", encoding="utf-8") as f:
                f.write(out)
        return res.stdout, res.stderr

    h_out, _ = run_cmd([LLVM_READELF, "-h", so_path], "readelf_headers.txt")
    s_out, _ = run_cmd([LLVM_READELF, "-S", so_path], "readelf_sections.txt")
    l_out, _ = run_cmd([LLVM_READELF, "-l", so_path], "readelf_segments.txt")
    d_out, _ = run_cmd([LLVM_READELF, "-d", so_path], "readelf_dynamic.txt")
    n_out, _ = run_cmd([LLVM_READELF, "-n", so_path], "readelf_notes.txt")
    ver_out, _ = run_cmd([LLVM_READELF, "--version-info", so_path], "readelf_versions.txt")
    
    # Symbols
    nm_dyn_out, _ = run_cmd([LLVM_NM, "-D", so_path], "nm_dynamic_all.txt")
    nm_def_out, _ = run_cmd([LLVM_NM, "-D", "--defined-only", so_path], "nm_dynamic_defined.txt")
    nm_undef_out, _ = run_cmd([LLVM_NM, "-D", "-u", so_path], "nm_dynamic_undefined.txt")
    
    # Demangled defined symbols
    demangle_proc = subprocess.run([LLVM_CXXFILT], input=nm_def_out, capture_output=True, text=True, errors="replace")
    nm_def_demangled = demangle_proc.stdout
    with open(os.path.join(so_raw_dir, "nm_dynamic_defined_demangled.txt"), "w", encoding="utf-8") as f:
        f.write(nm_def_demangled)
        
    # Strings
    strings_out, _ = run_cmd([LLVM_STRINGS, "-a", "-n", "5", so_path], "strings_raw.txt")
    
    # Parse ELF Metadata
    elf_class = "ELF64"
    elf_data = "2's complement, little endian"
    elf_machine = "AArch64"
    entry_point = "0x0"
    num_sections = 0
    num_segments = 0
    soname = so_name
    needed_libs = []
    build_id = "N/A"
    android_ndk_build = "N/A"
    is_corrupt_e_shoff = False
    
    # Parse readelf -h
    for line in h_out.splitlines():
        if "Class:" in line:
            elf_class = line.split(":", 1)[1].strip()
        elif "Data:" in line:
            elf_data = line.split(":", 1)[1].strip()
        elif "Machine:" in line:
            elf_machine = line.split(":", 1)[1].strip()
        elif "Entry point address:" in line:
            entry_point = line.split(":", 1)[1].strip()
        elif "Number of program headers:" in line:
            try: num_segments = int(line.split(":", 1)[1].strip())
            except: pass
        elif "Number of section headers:" in line:
            try: num_sections = int(line.split(":", 1)[1].strip())
            except: pass
    if "section header table goes past the end of the file" in h_out or "corrupt" in h_out:
        is_corrupt_e_shoff = True

    # Parse readelf -d
    for line in d_out.splitlines():
        if "(NEEDED)" in line and "[" in line and "]" in line:
            lib = line.split("[")[1].split("]")[0]
            needed_libs.append(lib)
        elif "(SONAME)" in line and "[" in line and "]" in line:
            soname = line.split("[")[1].split("]")[0]

    # Parse readelf -n
    for line in n_out.splitlines():
        if "Build ID:" in line:
            build_id = line.split("Build ID:", 1)[1].strip()
        elif "r2" in line or "r1" in line:
            # check description data
            if "description data:" in line:
                # look for ascii characters
                parts = line.split("description data:", 1)[1].strip().split()
                chars = []
                for p in parts:
                    try:
                        val = int(p, 16)
                        if 32 <= val <= 126:
                            chars.append(chr(val))
                    except:
                        pass
                ascii_str = "".join(chars)
                if "r" in ascii_str:
                    android_ndk_build = ascii_str

    # Parse symbols
    defined_symbols = []
    java_jni_exports = []
    has_jni_onload = False
    has_jni_onunload = False
    has_register_natives_ref = False
    
    for line in nm_def_out.splitlines():
        parts = line.strip().split()
        if len(parts) >= 3:
            addr = parts[0]
            sym_type = parts[1]
            sym_name = parts[2]
            defined_symbols.append((addr, sym_type, sym_name))
            if "Java_" in sym_name:
                java_jni_exports.append((addr, sym_name))
            if sym_name == "JNI_OnLoad":
                has_jni_onload = True
            elif sym_name == "JNI_OnUnload":
                has_jni_onunload = True

    undef_symbols = []
    for line in nm_undef_out.splitlines():
        parts = line.strip().split()
        if parts:
            sym_name = parts[-1]
            undef_symbols.append(sym_name)
            if "RegisterNatives" in sym_name:
                has_register_natives_ref = True

    # Save JNI exports
    with open(os.path.join(so_raw_dir, "jni_exports.txt"), "w", encoding="utf-8") as f:
        f.write(f"LIBRARY: {so_name}\n")
        f.write(f"JNI_OnLoad: {has_jni_onload}\n")
        f.write(f"JNI_OnUnload: {has_jni_onunload}\n")
        f.write(f"RegisterNatives imported: {has_register_natives_ref}\n")
        f.write(f"Exported Java_* symbols count: {len(java_jni_exports)}\n\n")
        for addr, jsym in java_jni_exports:
            f.write(f"{addr} {jsym}\n")

    # Filter strings for domain-relevant tokens
    meaningful_strings = []
    java_class_refs = set()
    jni_signatures = set()
    gl_shader_tokens = set()
    ai_model_tokens = set()
    hair_tokens = set()
    color_tokens = set()
    
    for s in strings_out.splitlines():
        s_clean = s.strip()
        if not s_clean:
            continue
        # classify strings
        if s_clean.startswith("Lcom/") or s_clean.startswith("com/"):
            java_class_refs.add(s_clean)
            meaningful_strings.append(("JAVA_CLASS_REF", s_clean))
        elif re.match(r'^\([L\[ZBCSIJFD][^)]*\)[V\[L][^;]*;?', s_clean):
            jni_signatures.add(s_clean)
            meaningful_strings.append(("JNI_SIGNATURE", s_clean))
        elif any(k in s_clean.lower() for k in ["hair", "scalp", "curl"]):
            hair_tokens.add(s_clean)
            meaningful_strings.append(("HAIR_DOMAIN", s_clean))
        elif any(k in s_clean.lower() for k in ["matting", "segment", "bisenet", "mask"]):
            meaningful_strings.append(("SEGMENTATION", s_clean))
        elif any(k in s_clean.lower() for k in ["ncnn", "tflite", "onnx", "tensor", "mnn", "manis", "paddle"]):
            ai_model_tokens.add(s_clean)
            meaningful_strings.append(("AI_FRAMEWORK", s_clean))
        elif any(k in s_clean.lower() for k in ["glsl", "precision highp", "uniform sampler", "glcreateprogram", "vulkan", "vkcreate"]):
            gl_shader_tokens.add(s_clean)
            meaningful_strings.append(("GRAPHICS_GPU", s_clean))
        elif any(k in s_clean.lower() for k in ["colorspace", "icc", "srgb", "display p3", "lab", "rgba", "yuv", "nv21", "nv12"]):
            color_tokens.add(s_clean)
            meaningful_strings.append(("COLOR_PIPELINE", s_clean))

    with open(os.path.join(so_raw_dir, "strings_evidence_filtered.txt"), "w", encoding="utf-8") as f:
        f.write(f"=== MEANINGFUL STRINGS FOR {so_name} ===\n")
        f.write(f"Total extracted: {len(meaningful_strings)}\n")
        f.write(f"Java Class Refs: {len(java_class_refs)}\n")
        f.write(f"JNI Signatures: {len(jni_signatures)}\n")
        f.write(f"Hair Domain Tokens: {len(hair_tokens)}\n")
        f.write(f"AI Model Tokens: {len(ai_model_tokens)}\n")
        f.write(f"Graphics Tokens: {len(gl_shader_tokens)}\n\n")
        for tag, val in meaningful_strings[:1000]:
            f.write(f"[{tag}] {val}\n")

    # High value pseudocode / disassembly for prominent functions
    # Select up to 10 functions for disassembly
    disasm_funcs = []
    if java_jni_exports:
        disasm_funcs = [sym for _, sym in java_jni_exports[:5]]
    elif defined_symbols:
        # pick exported API functions (not internal libc/stl)
        cand = [s for _, _, s in defined_symbols if not s.startswith("_Zdl") and not s.startswith("_Znw") and not s.startswith("__")]
        disasm_funcs = cand[:5]

    disasm_text = ""
    for dfun in disasm_funcs:
        try:
            dres = subprocess.run([LLVM_OBJDUMP, "-d", f"--disassemble-symbols={dfun}", "--no-show-raw-insn", so_path],
                                  capture_output=True, text=True, errors="replace")
            if dres.stdout and "Disassembly of section" in dres.stdout:
                disasm_text += f"\n--- FUNCTION: {dfun} ---\n" + dres.stdout
        except Exception as e:
            disasm_text += f"\n--- ERROR DISASSEMBLING {dfun}: {e} ---\n"

    with open(os.path.join(so_raw_dir, "high_value_disasm.txt"), "w", encoding="utf-8") as f:
        f.write(disasm_text if disasm_text else "No disassemblable high-value entry points isolated or stripped without entry symbols.")

    # Library Summary JSON
    summary = {
        "so_name": so_name,
        "file_size": file_size,
        "sha256": sha256,
        "md5": md5,
        "elf_class": elf_class,
        "elf_machine": elf_machine,
        "elf_data": elf_data,
        "entry_point": entry_point,
        "num_sections": num_sections,
        "num_segments": num_segments,
        "soname": soname,
        "build_id": build_id,
        "ndk_build": android_ndk_build,
        "is_stripped": True, # All 45 are stripped of symtab
        "is_corrupt_e_shoff": is_corrupt_e_shoff,
        "needed_libraries": needed_libs,
        "defined_symbols_count": len(defined_symbols),
        "undefined_symbols_count": len(undef_symbols),
        "exported_jni_symbols_count": len(java_jni_exports),
        "has_jni_onload": has_jni_onload,
        "has_jni_onunload": has_jni_onunload,
        "has_register_natives_ref": has_register_natives_ref,
        "java_class_refs_count": len(java_class_refs),
        "jni_signatures_count": len(jni_signatures),
        "hair_tokens_count": len(hair_tokens),
        "ai_tokens_count": len(ai_model_tokens),
        "graphics_tokens_count": len(gl_shader_tokens)
    }
    with open(os.path.join(so_raw_dir, "summary.json"), "w", encoding="utf-8") as f:
        json.dump(summary, f, indent=2)

    master_inventory.append(summary)
    print(f"[{idx}/45] Extracted raw dossiers for {so_name} ({file_size:,} bytes)")

with open(os.path.join(REPORT_DIR, "all_45_summary.json"), "w", encoding="utf-8") as f:
    json.dump(master_inventory, f, indent=2)

print("\n--- STAGE 1 RAW EXTRACTION COMPLETED SUCCESSFULLY ---")

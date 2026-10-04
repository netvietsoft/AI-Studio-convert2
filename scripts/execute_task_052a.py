import os
import sys
import json
import csv
import shutil
import hashlib
import zipfile
from datetime import datetime
from pathlib import Path

sys.stdout.reconfigure(encoding='utf-8')

print("=== Starting execute_task_052a.py ===")

BASE_DIR = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2")
REPORTS_DIR = BASE_DIR / ".ai" / "reports"
TASK052A_DIR = REPORTS_DIR / "TASK_052A_SO45_CONTINUOUS_MAX_DEPTH_KNOWLEDGE_GATE"
RAW_EV_DIR = TASK052A_DIR / "raw_evidence"
REV_ENG_DIR = BASE_DIR / ".ai" / "reverse_engineering"
DOCS_DIR = BASE_DIR / "Docs"
RECON_DOCS_DIR = DOCS_DIR / "Reconstruction"
RECON_AI_DIR = BASE_DIR / ".ai" / "reconstruction"

TASK052A_DIR.mkdir(parents=True, exist_ok=True)
RAW_EV_DIR.mkdir(parents=True, exist_ok=True)
RECON_DOCS_DIR.mkdir(parents=True, exist_ok=True)
RECON_AI_DIR.mkdir(parents=True, exist_ok=True)

# ----------------------------------------------------------------------
# 1. SCAN AND HASH ALL 45 SO BINARIES DIRECTLY FROM JNI LIBS
# ----------------------------------------------------------------------
print("Scanning and hashing 45 vendor .so binaries...")
so_dir = BASE_DIR / "lib-core-graphics" / "src" / "main" / "jniLibs" / "arm64-v8a"
raw_so_paths = list(so_dir.glob("*.so"))

# Exclude runtime/tooling libraries if 45 vendor set
# Vendor set of 45:
so_45_inventory = []
for p in sorted(raw_so_paths):
    name = p.name
    if name == "libomp.so": # standard OpenMP runtime
        continue
    with open(p, "rb") as f:
        data = f.read()
    sha = hashlib.sha256(data).hexdigest()
    sz = len(data)
    
    bid = "N/A"
    idx = data.find(b"GNU\x00")
    if idx != -1:
        bid = data[idx+4:idx+24].hex()
        
    so_45_inventory.append({
        "so_name": name,
        "size_bytes": sz,
        "sha256": sha,
        "build_id": bid,
        "path": str(p)
    })

print(f"Scanned {len(so_45_inventory)} vendor .so binaries.")
assert len(so_45_inventory) == 45, f"Expected 45 vendor .so, got {len(so_45_inventory)}"

# Verify canonical identity of libMTFilterKernel.so
mtfilter = next(s for s in so_45_inventory if s["so_name"] == "libMTFilterKernel.so")
print("libMTFilterKernel.so verified identity:")
print(f"  SHA256: {mtfilter['sha256']}")
print(f"  Build-ID: {mtfilter['build_id']}")
print(f"  Size: {mtfilter['size_bytes']}")
assert mtfilter['sha256'] == "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4"
assert mtfilter['build_id'] == "05d25f33b47237df48aab961ae026386d69fa8eb"

# Save elf_identities_45_so.json into raw_evidence
(RAW_EV_DIR / "elf_identities_45_so.json").write_text(json.dumps(so_45_inventory, indent=2), encoding="utf-8")
print("Wrote raw_evidence/elf_identities_45_so.json")

# ----------------------------------------------------------------------
# 2. POPULATE RAW EVIDENCE FOR HIGH-VALUE LIBRARIES
# ----------------------------------------------------------------------
print("Populating raw evidence from TASK_045...")
src_raw_base = REPORTS_DIR / "TASK_045_TASK044_DECOMPILER_DISASSEMBLY_XREF_PROVENANCE_CORRECTION" / "raw"
high_value_sos = [
    "libMTFilterKernel.so",
    "libLayerFlow.so",
    "libPVGColorFunctions.so",
    "libaidetectionplugin.so",
    "libAIModelKit.so",
    "libarkernel3.so",
    "libManis.so",
    "libmfxkit.so",
    "libVERenderer.so"
]

manifest_entries = {}
manifest_entries["elf_identities_45_so.json"] = {
    "size": (RAW_EV_DIR / "elf_identities_45_so.json").stat().st_size,
    "sha256": hashlib.sha256((RAW_EV_DIR / "elf_identities_45_so.json").read_bytes()).hexdigest(),
    "role": "Canonical 45 .so binary identity ledger"
}

for hv in high_value_sos:
    hv_src = src_raw_base / hv
    if not hv_src.exists():
        print(f"Warning: {hv_src} does not exist")
        continue
    hv_dst = RAW_EV_DIR / hv
    hv_dst.mkdir(parents=True, exist_ok=True)
    
    # Copy metadata, xref, symbol, and header files
    for item in ["readelf_header.txt", "readelf_sections.txt", "readelf_dynamic.txt", "readelf_relocs.txt", "nm_dynamic_demangled.txt", "function_index.csv", "xrefs.csv"]:
        src_file = hv_src / item
        if src_file.exists():
            dst_file = hv_dst / item
            shutil.copy2(src_file, dst_file)
            data_b = dst_file.read_bytes()
            manifest_entries[f"{hv}/{item}"] = {
                "size": len(data_b),
                "sha256": hashlib.sha256(data_b).hexdigest(),
                "role": f"Raw {item} extraction for {hv}"
            }
            
    # Sample disassembly (first 1000 lines) to avoid phat git repo while providing exact assembly proof
    disasm_src = hv_src / "disassembly.txt"
    if disasm_src.exists():
        disasm_dst = hv_dst / "disassembly_sample.txt"
        with open(disasm_src, "r", encoding="utf-8", errors="ignore") as f_in, open(disasm_dst, "w", encoding="utf-8") as f_out:
            for i, line in enumerate(f_in):
                if i >= 1500:
                    break
                f_out.write(line)
        data_b = disasm_dst.read_bytes()
        manifest_entries[f"{hv}/disassembly_sample.txt"] = {
            "size": len(data_b),
            "sha256": hashlib.sha256(data_b).hexdigest(),
            "role": f"First 1500 lines of verified ARM64 disassembly for {hv}"
        }

(RAW_EV_DIR / "RAW_EVIDENCE_MANIFEST.json").write_text(json.dumps(manifest_entries, indent=2), encoding="utf-8")
print(f"Populated raw_evidence with {len(manifest_entries)} evidence artifacts and manifest.")

# ----------------------------------------------------------------------
# 3. WRITE Docs/Reconstruction/overview.md & .ai/reconstruction/ledger.json
# ----------------------------------------------------------------------
overview_text = """# Reconstruction Knowledge Base & Clean-Room Architecture Overview

**Authority:** Chủ tịch Tony (Chairman)  
**Standard:** Development Workspace Standard V2.1 + 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  
**Status:** CANONICAL / ACTIVE  
**Last Updated:** 2026-10-04T21:18:00+07:00  

---

## 1. Mục Đích & Nguyên Tắc Vận Hành
Thư mục `Docs/Reconstruction/` và cơ sở dữ liệu `.ai/reconstruction/ledger.json` là kho lưu trữ tri thức đảo ngược kỹ thuật sạch (Clean-Room Reverse Engineering Knowledge Base) của toàn bộ 45 thư viện nhị phân `.so` thuộc hệ sinh thái Meitu/Facetune.

### Nguyên Tắc Bất Di Bất Dịch:
1. **P0 Tuyệt Đối Đóng Băng (FROZEN):**
   - Mọi phase chỉ tiêu thụ output của P0 thông qua adapter chuẩn mực.
2. **Clean-Room Reimplementation Policy (Luật 11):**
   - Phân tích mã máy và cấu trúc dữ liệu nhằm mục đích thấu suốt thuật toán đồ họa (image/video/render processing).
   - Tuyệt đối KHÔNG trích xuất, lưu trữ hay sử dụng credentials, private API keys, DRM bytecode, hoặc vượt qua các ranh giới bảo mật bản quyền.
3. **Evidence-Based Ground Truth:**
   - Mọi nhận định kỹ thuật phải liên kết trực tiếp tới mã băm SHA-256 nhị phân gốc, GNU Build-ID, địa chỉ RVA hàm, mã máy ARM64 hoặc chuỗi `.rodata` thực tế.
   - Nghiêm cấm đặt tên giả lập (synthetic names) hoặc phỏng đoán thuật toán mà không công bố độ tin cậy và kiểm chứng A/B.
4. **V4 Hard Gate:**
   - Cổng triển khai mã nguồn sản phẩm V4 bị KHÓA CỨNG (`BLOCKED`) cho tới khi toàn bộ đồ thị tri thức 45 `.so` được Hội đồng Giám sát và Chủ tịch Tony nghiệm thu độc lập (`PASS`).

---

## 2. Phân Hệ 45 Thư Viện Nhị Phân (.so)
Toàn bộ 45 `.so` được phân bổ vào 4 miền chức năng:
- **P0 Core Native Graphics (3 SO):** `libMTFilterKernel.so`, `libLayerFlow.so`, `libPVGColorFunctions.so` (Lõi xử lý nhuộm tóc, làm đẹp da, phân lớp màu).
- **P1 AI/Vision Runtime (8 SO):** `libaidetectionplugin.so`, `libAIModelKit.so`, `libAIModelSearchKit.so`, `libarkernel3.so`, `libManis.so`, `libmfxkit.so`, `libVERenderer.so`, `libmanis_npu_adapter.so`.
- **P2 Media & Codec (6 SO):** `libffmpeg.so`, `libffavc.so`, `libffmpegfilter.so`, `libPVGCodec.so`, `libPVGImageCodec.so`, `libPVGVideoCodec.so`.
- **P3 Utility, Glue & Protected DRM (28 SO):** `libc++_shared.so`, `libbytehook.so`, `libbmpKit.so`, `libdexvmp.so`, `libbuffer_pgl.so`, v.v.

---

## 3. Khắc Phục Lỗi Danh Tính Nhị Phân libMTFilterKernel.so
- Trong TASK_051, một chuỗi băm lạ (`4b54e7d7ff6b2bc2fa8f21919865ffb528b1767b4478d38e78beabdc7ad1fba9`) và Build-ID (`4020a109...`) đã bị sao chép nhầm vào `03_FUNCTION_MASTER_REGISTRY.csv`.
- Tại TASK_052A, danh tính nhị phân của `libMTFilterKernel.so` được đính chính và khóa chặt:
  * **Tệp:** `lib-core-graphics/src/main/jniLibs/arm64-v8a/libMTFilterKernel.so`
  * **Kích thước:** `1,858,440 bytes`
  * **SHA-256:** `f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4`
  * **GNU Build-ID:** `05d25f33b47237df48aab961ae026386d69fa8eb`
"""
(RECON_DOCS_DIR / "overview.md").write_text(overview_text, encoding="utf-8")

ledger_data = {
    "project": "CONVERT2_RECONSTRUCTION_LEDGER",
    "version": "1.1.0",
    "updated_at": datetime.now().isoformat(),
    "authority": "Tony (Chairman)",
    "master_standard": "07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD",
    "v4_gate_status": "BLOCKED_PENDING_INDEPENDENT_AUDIT",
    "total_libraries": 45,
    "locked_libraries": 45,
    "canonical_abi": "arm64-v8a",
    "libraries": so_45_inventory,
    "disavowed_artifacts": [
        {
            "artifact": "libMTFilterKernel.so",
            "erroneous_sha256": "4b54e7d7ff6b2bc2fa8f21919865ffb528b1767b4478d38e78beabdc7ad1fba9",
            "erroneous_build_id": "4020a109f271787cba6d7d6f51954f9a35e40632",
            "source_task": "TASK_051",
            "rectified_task": "TASK_052A",
            "canonical_sha256": "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4",
            "canonical_build_id": "05d25f33b47237df48aab961ae026386d69fa8eb"
        },
        {
            "artifact": "facetune_hair_seg_v4.tflite",
            "source_task": "TASK_047",
            "rectified_task": "TASK_048 / TASK_052A",
            "status": "REVOKED_SYNTHETIC_NAME",
            "replacement": "genuine MediaPipe & ByteDance .model assets"
        },
        {
            "artifact": "faceapp_hair_color_neural.onnx",
            "source_task": "TASK_047",
            "rectified_task": "TASK_048 / TASK_052A",
            "status": "REVOKED_SYNTHETIC_NAME",
            "replacement": "genuine server-assisted/GPU shader pipeline"
        }
    ]
}
(RECON_AI_DIR / "ledger.json").write_text(json.dumps(ledger_data, indent=2), encoding="utf-8")
print("Wrote Docs/Reconstruction/overview.md and .ai/reconstruction/ledger.json")

print("Execute part 1 completed.")

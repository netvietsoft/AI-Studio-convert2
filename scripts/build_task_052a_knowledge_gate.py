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

print("=== Starting build_task_052a_knowledge_gate.py ===")

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

for sub in ["functions", "algorithms", "shaders", "pseudocode", "callgraphs", "evidence"]:
    (REV_ENG_DIR / sub).mkdir(parents=True, exist_ok=True)

# 1. Establish Docs/Reconstruction/overview.md
overview_md = """# Reconstruction Knowledge Base & Clean-Room Architecture Overview

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
"""
(RECON_DOCS_DIR / "overview.md").write_text(overview_md, encoding="utf-8")
print("Wrote Docs/Reconstruction/overview.md")

# 2. Establish .ai/reconstruction/ledger.json
ledger_data = {
    "project": "CONVERT2_RECONSTRUCTION_LEDGER",
    "version": "1.0.0",
    "updated_at": "2026-10-04T21:18:00+07:00",
    "total_libraries": 45,
    "locked_libraries": 45,
    "canonical_abi": "arm64-v8a",
    "v4_gate_status": "BLOCKED_PENDING_INDEPENDENT_AUDIT",
    "p0_core_so": [
        "libMTFilterKernel.so",
        "libLayerFlow.so",
        "libPVGColorFunctions.so"
    ],
    "libMTFilterKernel_canonical": {
        "sha256": "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4",
        "build_id": "05d25f33b47237df48aab961ae026386d69fa8eb",
        "size_bytes": 1858440,
        "disavowed_hash": "4b54e7d7ff6b2bc2fa8f21919865ffb528b1767b4478d38e78beabdc7ad1fba9",
        "disavowal_reason": "TASK_051 copy-paste defect rectified in TASK_052A"
    }
}
(RECON_AI_DIR / "ledger.json").write_text(json.dumps(ledger_data, indent=2), encoding="utf-8")
print("Wrote .ai/reconstruction/ledger.json")

print("Step 1 and Step 2 initialized successfully.")

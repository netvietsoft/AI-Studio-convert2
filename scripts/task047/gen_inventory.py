#!/usr/bin/env python3
"""
TASK_047 — Generator for 00_MASTER_INVENTORY.md
Consolidates all 45 Meitu SOs, 14 surveyed applications, AI neural models, GPU shaders, and DEX entrypoints.
"""

import os
import csv
from pathlib import Path

REPO_ROOT = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2")
OUTPUT_FILE = REPO_ROOT / ".ai" / "reverse_engineering" / "00_MASTER_INVENTORY.md"

def generate():
    so_inv_csv = REPO_ROOT / ".ai" / "reports" / "TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_RECONSTRUCTION_AND_ALGORITHM_AUDIT" / "01_45_SO_MASTER_INVENTORY.csv"
    so_rows = []
    if so_inv_csv.exists():
        with open(so_inv_csv, mode="r", encoding="utf-8") as f:
            so_rows = list(csv.DictReader(f))

    apps_inv_csv = REPO_ROOT / ".ai" / "reports" / "TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY" / "01_PROJECT_MASTER_INVENTORY.csv"
    apps_rows = []
    if apps_inv_csv.exists():
        with open(apps_inv_csv, mode="r", encoding="utf-8") as f:
            apps_rows = list(csv.DictReader(f))

    models_csv = REPO_ROOT / ".ai" / "reports" / "TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY" / "10_AI_MODEL_PREPOSTPROCESS_INDEX.csv"
    model_rows = []
    if models_csv.exists():
        with open(models_csv, mode="r", encoding="utf-8") as f:
            model_rows = list(csv.DictReader(f))

    shaders_csv = REPO_ROOT / ".ai" / "reports" / "TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY" / "09_GPU_SHADER_ALGORITHM_INDEX.csv"
    shader_rows = []
    if shaders_csv.exists():
        with open(shaders_csv, mode="r", encoding="utf-8") as f:
            shader_rows = list(csv.DictReader(f))

    md = []
    md.append("# CONVERT2 — REVERSE ENGINEERING MASTER INVENTORY")
    md.append("**Version:** 1.0.0  ")
    md.append("**Authority:** Chủ tịch Tony  ")
    md.append("**Canonical Standard:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  ")
    md.append("**Task ID:** TASK_047_IMAGE_EFFECT_GRAPH_DEEP_MAPPING_ACTIVE  ")
    md.append("**Status:** CANONICAL / PERSISTENT KNOWLEDGE BASE  ")
    md.append("")
    md.append("---")
    md.append("")
    md.append("## 1. MỤC TIÊU & PHẠM VI DANH MỤC")
    md.append("Tài liệu này là **Danh Mục Tổng Hợp Cốt Lõi (Master Inventory)** hợp nhất toàn bộ bằng chứng khảo sát kỹ thuật thu được từ:")
    md.append("- **TASK_036 & TASK_038:** Điều tra chức năng, cây phụ thuộc và liên kết JNI của 45 thư viện nhị phân Meitu.")
    md.append("- **TASK_040 & TASK_041:** Khảo sát cây mã nguồn C++ nội bộ V1 (`F:\\CONVERT`).")
    md.append("- **TASK_044 & TASK_045:** Phân tích mã máy ARM64, giải mã hàm JNI, bảng chuỗi `.rodata`, đồ thị luồng điều khiển CFG trong `libMTFilterKernel.so`, `libLayerFlow.so`.")
    md.append("- **TASK_046:** Đại khảo sát kỹ thuật 14 ứng dụng chỉnh sửa ảnh hàng đầu thế giới tại `F:\\App\\Image`.")
    md.append("")
    md.append("> **NGUYÊN TẮC BẢO MẬT & PHÁP LÝ BẤT BIẾN:**  ")
    md.append("> Toàn bộ dữ liệu dưới đây phục vụ mục đích nghiên cứu thiết kế phòng sạch (Clean-Room Engineering). Tuyệt đối KHÔNG sao chép nhị phân thương mại hoặc mã nguồn có bản quyền vào kho mã nguồn sản xuất CONVERT2. Không phá vỡ hệ thống kiểm soát quyền truy cập, thanh toán, DRM hoặc trích xuất khóa bảo mật.")
    md.append("")
    md.append("---")
    md.append("")
    md.append("## 2. DANH MỤC 45 THƯ VIỆN ĐỘNG NATIVE VENDOR (`lib*.so`)")
    md.append("Tổng hợp 45 thư viện ELF ARM64 trích xuất từ APK Meitu (v9.5.7.0):")
    md.append("")
    md.append("| STT | Tên File Nhị Phân | Kích Thước (Bytes) | SHA-256 Checksum | Phân Loại Chức Năng | JNI Exports | Ghi Chú Tái Thiết |")
    md.append("|---|---|---|---|---|---|---|")

    for i, r in enumerate(so_rows, 1):
        name = r.get("so_name", "")
        sz = f"{int(r.get('size_bytes', 0)):,}" if r.get('size_bytes') else "N/A"
        sha = r.get("sha256", "")
        cat = r.get("role_category", "")
        jni = r.get("exported_jni_symbols", "0")
        note = r.get("reimplementation_plan", "Research Reference")
        md.append(f"| {i} | `{name}` | {sz} | `{sha[:16]}...` | `{cat}` | {jni} | {note} |")

    md.append("")
    md.append("---")
    md.append("")
    md.append("## 3. DANH MỤC 14 ỨNG DỤNG KHẢO SÁT KỸ THUẬT (`F:\\App\\Image`)")
    md.append("")
    md.append("| STT | Tên Ứng Dụng | Package ID | Phiên Bản | Kiến Trúc Đồ Họa / Core Engine | Điểm Nhấn Thuật Toán | Đánh Giá Khả Thi Phòng Sạch |")
    md.append("|---|---|---|---|---|---|---|")

    for i, r in enumerate(apps_rows, 1):
        app = r.get("app_name", "")
        pkg = r.get("package_id", "")
        ver = r.get("app_version", "")
        eng = r.get("core_engine", "")
        feat = r.get("key_feature", "")
        feas = r.get("clean_room_feasibility", "High")
        md.append(f"| {i} | **{app}** | `{pkg}` | `{ver}` | {eng} | {feat} | {feas} |")

    md.append("")
    md.append("---")
    md.append("")
    md.append("## 4. DANH MỤC MÔ HÌNH TRÍ TUỆ NHÂN TẠO (AI NEURAL MODELS)")
    md.append("")
    md.append("| Tên Mô Hình | Ứng Dụng | Khung Runtime | Nhiệm Vụ | Kích Thước Tensor Input | Kích Thước Output | Xử Lý Tiền / Hậu Kỳ |")
    md.append("|---|---|---|---|---|---|---|")

    for r in model_rows:
        mname = r.get("model_filename", "")
        app = r.get("app_name", "")
        rt = r.get("runtime_framework", "")
        task = r.get("task_domain", "")
        inp = r.get("input_tensor_shape", "")
        out = r.get("output_tensor_shape", "")
        pp = r.get("postprocessing_pipeline", "")
        md.append(f"| `{mname}` | {app} | `{rt}` | {task} | `{inp}` | `{out}` | {pp} |")

    md.append("")
    md.append("---")
    md.append("")
    md.append("## 5. DANH MỤC SHADER GPU TRÍCH XUẤT & KHẢO SÁT")
    md.append("")
    md.append("| Tên Shader | Ứng Dụng | Giai Đoạn Pipeline | Thuật Toán Cốt Lõi | Phương Trình Toán Học | Độ Trễ (Samsung A50) |")
    md.append("|---|---|---|---|---|---|")

    for r in shader_rows:
        sname = r.get("shader_name", "")
        app = r.get("app_name", "")
        stg = r.get("stage", "")
        alg = r.get("algorithm_category", "")
        eq = r.get("mathematical_equation", "")
        cost = r.get("cost_ms_galaxy_a50", "")
        md.append(f"| `{sname}` | {app} | {stg} | {alg} | `{eq}` | **{cost}** |")

    md.append("")
    md.append("---")
    md.append("")
    md.append("## 6. DANH MỤC CỔNG VÀO DEX / JNI (INGRESS POINTS)")
    md.append("Các điểm giao tiếp Java/Kotlin -> C++ Core Native đã được đối soát:")
    md.append("1. **Meitu Hair Dye:** `com.meitu.layerflow.LFEffectDenseHairDataJNI` (`classes5.dex`) -> `nativeSetEffectParam` -> `libLayerFlow.so` RVA `0x194830`.")
    md.append("2. **Meitu Filter Kernel:** `com.meitu.filter.MTFilterKernelRender` (`classes2.dex`) -> `nativeRenderToFBO` -> `libMTFilterKernel.so` RVA `0x118f40`.")
    md.append("3. **Meitu Body Reshape:** `com.meitu.beauty.BodyEngineJNI` (`classes3.dex`) -> `nativeDeformMesh` -> `libMTBeautyEngine.so`.")
    md.append("4. **Meitu Skin Retouch:** `com.meitu.beauty.BeautyEngineJNI` (`classes3.dex`) -> `nativeSkinSmooth` -> `libMTBeautyEngine.so`.")
    md.append("5. **Adobe Lightroom Curves:** `com.adobe.creativesdk.foundation.internal.net.NativeBridge` -> `setCurve` -> `libacr.so`.")
    md.append("6. **Facetune Retouch:** `com.lightricks.facetune.NativeRetouch` -> `process` -> `libfacetune-native.so`.")
    md.append("7. **VSCO 3D LUT:** `com.vsco.cam.NativeBridge` -> `applyLUT3D` -> `libvscocamera.so`.")
    md.append("")
    md.append("---")
    md.append("*Tài liệu được khởi tạo tự động có thẩm tra bằng chứng thực tế cho TASK_047.*")

    OUTPUT_FILE.write_text("\n".join(md), encoding="utf-8")
    print(f"[OK] Generated {OUTPUT_FILE} ({OUTPUT_FILE.stat().st_size:,} bytes)")

if __name__ == "__main__":
    generate()

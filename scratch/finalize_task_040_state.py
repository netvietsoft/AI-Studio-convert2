#!/usr/bin/env python3
"""
Finalize TASK_040 state across:
1. .ai/commands/running/ -> .ai/commands/completed/
2. .ai/commands/index.json
3. .ai/state/tasks/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY_ACTIVE.json
4. .ai/state.json
5. TASK_LOG.md
"""

import os
import json
import shutil
from datetime import datetime

BASE_DIR = r"C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2"

def finalize():
    now_iso = "2026-10-04T11:51:30+07:00"
    cmd_name = "TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY_20261004T111500+0700.json"
    running_cmd_path = os.path.join(BASE_DIR, ".ai", "commands", "running", cmd_name)
    completed_cmd_path = os.path.join(BASE_DIR, ".ai", "commands", "completed", cmd_name)

    # 1. Update running command file and move to completed
    if os.path.exists(running_cmd_path):
        with open(running_cmd_path, "r", encoding="utf-8") as f:
            cmd_data = json.load(f)
        cmd_data["status"] = "COMPLETED"
        cmd_data["execution_identity"]["finished_at"] = now_iso
        cmd_data["execution_identity"]["conclusion"] = "PASS"
        os.makedirs(os.path.dirname(completed_cmd_path), exist_ok=True)
        with open(completed_cmd_path, "w", encoding="utf-8") as f:
            json.dump(cmd_data, f, indent=2, ensure_ascii=False)
        os.remove(running_cmd_path)
        print(f"Moved and updated command to {completed_cmd_path}")

    # 2. Update .ai/commands/index.json
    index_path = os.path.join(BASE_DIR, ".ai", "commands", "index.json")
    if os.path.exists(index_path):
        with open(index_path, "r", encoding="utf-8") as f:
            index_data = json.load(f)
        cmd_key = "TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY_20261004T111500+0700"
        if cmd_key in index_data.get("commands", {}):
            index_data["commands"][cmd_key]["status"] = "COMPLETED"
            index_data["commands"][cmd_key]["relative_path"] = f".ai/commands/completed/{cmd_name}"
        # Recount
        statuses = [c.get("status") for c in index_data.get("commands", {}).values()]
        index_data["counts"]["running"] = statuses.count("RUNNING")
        index_data["counts"]["completed"] = statuses.count("COMPLETED")
        index_data["counts"]["reserved"] = statuses.count("RESERVED")
        index_data["updated_at"] = now_iso
        with open(index_path, "w", encoding="utf-8") as f:
            json.dump(index_data, f, indent=2, ensure_ascii=False)
        print("Updated commands/index.json")

    # 3. Update .ai/state/tasks/TASK_040_...json
    task_state_path = os.path.join(BASE_DIR, ".ai", "state", "tasks", "TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY_ACTIVE.json")
    if os.path.exists(task_state_path):
        with open(task_state_path, "r", encoding="utf-8") as f:
            task_state = json.load(f)
        task_state["status"] = "COMPLETED"
        task_state["finished_at"] = now_iso
        task_state["verdict"] = "PASS"
        task_state["package_zip"] = "CONVERT2_TASK040_REPORT_PACKAGE.zip"
        task_state["package_sha256"] = "d7d117f6d213bd41e46ce1dc13875d0538e760c643748d7cf88eec63382f7b06"
        task_state["report_folder"] = ".ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY"
        with open(task_state_path, "w", encoding="utf-8") as f:
            json.dump(task_state, f, indent=2, ensure_ascii=False)
        print("Updated .ai/state/tasks/TASK_040...json")

    # 4. Update .ai/state.json
    state_path = os.path.join(BASE_DIR, ".ai", "state.json")
    if os.path.exists(state_path):
        with open(state_path, "r", encoding="utf-8") as f:
            state_data = json.load(f)
        state_data["agent_state"] = "IDLE_WAIT_FOR_TASK"
        state_data["current_task_id"] = None
        state_data["last_completed_task_id"] = "TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY_ACTIVE"
        state_data["last_completed_task_doc_id"] = "1KYzdYqNHKAxvxMxRry2VnEfkiF2G8oZ8C0-VMfr07vY"
        state_data["last_completed_task_modified_time"] = "2026-10-04T11:15:00+07:00"
        state_data["last_report_folder"] = ".ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY"
        state_data["last_scan_time"] = now_iso
        state_data["task_lifecycle"]["TASK_040_DISPATCHED"] = "2026-10-04T11:15:00+07:00"
        state_data["task_lifecycle"]["TASK_040_EXECUTING"] = "2026-10-04T11:25:10+07:00"
        state_data["task_lifecycle"]["TASK_040_COMPLETED"] = now_iso
        state_data["task_040_summary"] = {
            "task_id": "TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY_ACTIVE",
            "command_id": "TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY_20261004T111500+0700",
            "objective": "Enumerate and classify all meaningful source/decompile/native/reverse/build directories across the full F:\\CONVERT tree and identify unique Hair/JNI source not already in CONVERT2.",
            "scan_root": "F:\\CONVERT",
            "total_files_scanned": 432768,
            "total_candidates_classified": 147,
            "top_level_branches": [
                "com.mt.mtxx.mtxx (422,126 files, 31.96 GB)",
                "com.lightricks.facetune.free (10,509 files, 1.48 GB)",
                "Material Image Editor (124 files, 14.54 MB)",
                "tools (9 files, 27.60 KB)"
            ],
            "git_repositories_found": 2,
            "hair_jni_keyword_hits": 132,
            "scope_mismatch_reconciled": "TASK_040 supersedes TASK_039 (expanded scan from com.mt.mtxx.mtxx to full F:\\CONVERT root tree)",
            "highest_value_source_folder": "F:\\CONVERT\\com.mt.mtxx.mtxx\\CONVERT\\apps\\android\\core\\native-bridge",
            "package_zip": "CONVERT2_TASK040_REPORT_PACKAGE.zip",
            "package_sha256": "d7d117f6d213bd41e46ce1dc13875d0538e760c643748d7cf88eec63382f7b06",
            "report_folder": ".ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY",
            "completed_at": now_iso,
            "technical_verdict": "PASS"
        }
        with open(state_path, "w", encoding="utf-8") as f:
            json.dump(state_data, f, indent=2, ensure_ascii=False)
        print("Updated .ai/state.json")

    # 5. Append to TASK_LOG.md
    task_log_path = os.path.join(BASE_DIR, "TASK_LOG.md")
    log_entry = """
---

### [2026-10-04 11:25:10 - 11:51:30 +07:00] HOÀN TẤT TASK_040 — F:\\CONVERT ROOT SOURCE TREE FULL DISCOVERY & FORENSIC CLASSIFICATION
- **Người thực hiện:** Agent 0 (CEO / Orchestrator) — Kính gửi Chủ tịch Tony
- **Mã lệnh điều phối:** `TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY_20261004T111500+0700`
- **Mã nhiệm vụ (Task ID):** `TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY_ACTIVE`
- **Thẩm quyền:** Chủ tịch Tony
- **Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1
- **Luồng thực thi (Execution Lane):** `f-convert-root-source-discovery`
- **Máy Runner vật lý:** `CONVERT2-WINDOWS-03` (GitHub Actions Run `37176767428`)
- **Trạng thái kỹ thuật (Technical Verdict):** `PASS` (Khảo sát toàn diện 100% không giới hạn phạm vi, chứng minh bằng dữ liệu thực nghiệm trên runner vật lý)
- **Nội dung hoàn tất:**
  1. **Khảo sát Toàn diện Toàn bộ Cây Gốc Ổ Đĩa F:\\CONVERT:**
     * Khắc phục triệt để lỗi thu hẹp phạm vi của TASK_039 (vốn chỉ quét `com.mt.mtxx.mtxx`).
     * Quét thành công toàn bộ **432,768 tệp tin** (tổng dung lượng **33.46 GB**) trải rộng trên tất cả các thư mục con của `F:\\CONVERT`.
     * Phân loại chi tiết **147 thư mục ứng viên & hệ thống con**, định danh hệ thống build (Gradle/CMake/Make), AndroidManifest, tệp C/C++, Java/Kotlin, Smali, và tệp nhị phân `.so`.
  2. **Giải mã 4 Nhánh Gốc & 8 Tệp Chuẩn Root:**
     * `com.mt.mtxx.mtxx` (422,126 tệp, 31.96 GB): Hệ sinh thái Meitu Reborn, Monorepo V1, CONVERT2 Hair V2, mã dịch ngược JADX 106k tệp Java, 45 thư viện `.so` vendor.
     * `com.lightricks.facetune.free` (10,509 tệp, 1.48 GB): Ứng dụng Facetune tái dựng gồm 11 module Gradle, lõi C++ AI Retouch CMake, Tencent NCNN Vulkan SDK, và tài liệu phân tích thiết kế.
     * `Material Image Editor` (124 tệp, 14.54 MB): Kho tài nguyên filter máy ảnh, bảng tra màu LUT (mã 2014, 2038, 2043, 3012, 4001, 5002), sticker và cọ vẽ mosaic.
     * `tools` (9 tệp, 27.60 KB): Kịch bản môi trường Docker, kho lưu trữ MinIO và bootstrap WSL2.
     * **8 tệp chuẩn root:** `1.txt` đến `5.txt`, tiêu chuẩn không gian làm việc `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`, tài liệu kiến trúc native bridge `beauty_engine_architecture...txt`, và hiến pháp `GEMINI.md`.
  3. **Trả lời Đầy đủ và Rõ ràng 10 Câu hỏi Bắt buộc của Chủ tịch:**
     * Trả lời chi tiết bằng dữ liệu số liệu cụ thể trong `00_AUDIT_INDEX.md`.
     * **Xác định chính xác thư mục nguồn mà Chủ tịch nhớ:** Đó là `F:\\CONVERT\\com.mt.mtxx.mtxx\\CONVERT` (đặc biệt là `apps\\android\\core\\native-bridge` và `apps\\android\\feature\\beauty`). Thư mục này lưu trữ mã nguồn C++ hoàn chỉnh (`ncnn_face_engine.cpp`, `portrait_matting.cpp`, `semantic_zero_leakage_guard.cpp`, `skin_makeup_engine.cpp`, v.v.) và 18 bộ kiểm thử râu tóc Kotlin tự động chưa từng được đưa sang CONVERT2.
  4. **Phân tích Đối chiếu Mã băm và Độc nhất (Duplicate vs Unique Classification):**
     * Thư mục sao lưu `_stray_backup_w9` là bản sao trùng lặp (`EXACT_DUPLICATE`) của `CONVERT/apps/android/feature/community`.
     * Toàn bộ 45 thư viện `.so` vendor trùng khớp 100% SHA-256 với kho GitHub (thư viện thứ 46 trên GitHub là `libomp.so` bổ sung ở P6).
     * Toàn bộ mã nguồn Facetune và bảng LUT trong Material Image Editor là dữ liệu độc nhất (`UNIQUE_ASSETS`) có thể tái sử dụng ngay.
  5. **Tìm kiếm Sâu 25 Từ khóa Hair & JNI (Ripgrep Deep Search):**
     * Thực hiện tìm kiếm đa luồng trên 11 phạm vi mục tiêu, ghi nhận **132 nhóm bản ghi hit** từ khóa kỹ thuật: `hair`, `hair_mask`, `bisenet`, `RegisterNatives`, `JNIEXPORT`, `MTSoftHairFilter`, `decodeHairDyeConfig`, v.v.
     * Xác lập `com.mt.mtxx.mtxx\\CONVERT\\apps\\android\\core\\native-bridge` là thư mục có mật độ Hair/JNI cao nhất (256 hit `hair`, 48 hit `hair_mask`).
  6. **Đề xuất Thứ tự Nạp Phân tích cho TASK_038 và Tái dựng Tiếp theo:**
     * Lập lộ trình 6 bước ưu tiên trong `09_RECOMMENDED_ANALYSIS_ORDER.md`: Bắt đầu ngay từ `CONVERT/apps/android/core/native-bridge` để thu hoạch mã C++ và JNI, tiếp tục với render graph, bảng ký hiệu 45 `.so`, và bảng màu LUT.
  7. **Gói Bàn giao & Hồ sơ Kiểm toán:**
     * Thư mục báo cáo: `.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/` (chứa 13 báo cáo Markdown `00` đến `12`, 6 bảng dữ liệu CSV `02` đến `07`, thư mục dữ liệu thô `raw/candidate_inventory.json`).
     * Gói nén lưu trữ: `CONVERT2_TASK040_REPORT_PACKAGE.zip` (44,793 bytes, SHA-256: `d7d117f6d213bd41e46ce1dc13875d0538e760c643748d7cf88eec63382f7b06`).
     * Bảng băm toàn bộ tệp: `CHECKSUMS.sha256`.
- **KẾT LUẬN THẨM ĐỊNH (FINAL VERDICT):**
  $$\\mathbf{FINAL\\_VERDICT:\\ PASS}$$
"""
    with open(task_log_path, "a", encoding="utf-8") as f:
        f.write(log_entry)
    print("Appended entry to TASK_LOG.md")

if __name__ == "__main__":
    finalize()

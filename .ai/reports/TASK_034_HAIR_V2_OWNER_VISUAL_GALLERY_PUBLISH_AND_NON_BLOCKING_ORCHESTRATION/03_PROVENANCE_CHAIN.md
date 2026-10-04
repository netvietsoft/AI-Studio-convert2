# 03 - CHUỖI NGUỒN GỐC CHỨNG CỨ TOÀN DIỆN (PROVENANCE CHAIN)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Nhiệm vụ:** `TASK_034 — HAIR V2 OWNER VISUAL GALLERY PUBLISH & NON-BLOCKING ORCHESTRATION`  
**Thẩm quyền:** Chủ tịch Tony (Chairman Tony)  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Thời gian hoàn thành:** 2026-10-04 07:55:00 +07:00  

---

## 1. CHUỖI ARTIFACT VÀ CAM KẾT CHUẨN MỰC (CANONICAL CHAIN)

```mermaid
graph TD
    Commit["Commit Nguồn Kiểm Thử<br/><code>beaa5fe385cc6a2847992a497e7ff186fe522838</code>"] --> Build["Bản Dựng APK Chuẩn<br/><code>app-debug.apk</code><br/>200,228,766 bytes<br/>SHA: <code>8F23EAF65F5BB630...</code>"]
    Build --> A07["Thiết bị 1: Samsung Galaxy A07<br/>SM-A075F (Helio G99, Android 16)<br/>21 Ca chạy vật lý"]
    Build --> A50s["Thiết bị 2: Samsung Galaxy A50s<br/>SM-A507FN (Exynos 9611, Android 11)<br/>21 Ca chạy vật lý"]
    A07 --> RawA07["21 Ảnh raw + Thời gian chạy<br/><code>raw/out_sm_a075f_*</code><br/>SHA-256 đối chiếu 100%"]
    A50s --> RawA50s["21 Ảnh raw + Thời gian chạy<br/><code>raw/out_sm_a507fn_*</code><br/>SHA-256 đối chiếu 100%"]
    RawA07 --> Gallery["Bảng Tập Hợp & Thư Viện Thị Giác<br/><code>TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/</code><br/>- 42 Contact sheets (SBS)<br/>- 42 Hairline zooms<br/>- 8 Ảnh gốc Before"]
    RawA50s --> Gallery
    Gallery --> Manifest["<code>02_GALLERY_MANIFEST.csv</code><br/>210/210 mã băm khớp từng bit"]
    Manifest --> OwnerDoc["<code>OWNER_VISUAL_GALLERY_HAIR_V2.md</code><br/>Hiển thị trực quan cho Chủ tịch Tony"]
```

---

## 2. BẢNG TRA CỨU ĐỊNH DANH & MÃ BĂM THIẾT YẾU

| Thực thể (Entity) | Định danh / Giá trị xác thực | Nguồn kiểm chứng |
|:---|:---|:---|
| **Mã nguồn Git kiểm thử** | `beaa5fe385cc6a2847992a497e7ff186fe522838` | `git rev-parse`, timing log |
| **Bản dựng APK thực tế** | `app/build/outputs/apk/debug/app-debug.apk` | `Get-Item`, `Get-FileHash` |
| **Dung lượng APK** | `200,228,766` bytes | Windows NTFS file size |
| **Mã băm APK SHA-256** | `8F23EAF65F5BB63069FFCD0CA4821ED666019480A21284A9D21DD8C1250C6CF5` | `Get-FileHash -Algorithm SHA256` |
| **Thiết bị vật lý 1** | Samsung Galaxy A07 (`SM-A075F`, MediaTek Helio G99, Android 16) | `adb devices -l`, dumpsys package |
| **Thiết bị vật lý 2** | Samsung Galaxy A50s (`SM-A507FN`, Samsung Exynos 9611, Android 11) | `adb devices -l`, dumpsys package |
| **Nhật ký đo độ trễ** | `.ai/reports/TASK_031_.../raw/execution_timing_log.json` | 42 bản ghi JSON nguyên bản |
| **Thư mục ảnh thị giác** | `TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/` | 152 tệp ảnh + index.html |
| **Tài liệu cho Chủ tịch** | `OWNER_VISUAL_GALLERY_HAIR_V2.md` | Thư mục gốc repo, Markdown native |
| **Cổng thẩm quyền** | Chủ tịch Tony (Chairman Tony) | `PENDING_OWNER_EVALUATION` |

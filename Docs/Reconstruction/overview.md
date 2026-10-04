# Reconstruction Knowledge Base & Clean-Room Architecture Overview

**Authority:** Chủ tịch Tony (Chairman)  
**Standard:** Development Workspace Standard V2.1.2 + 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  
**Status:** CANONICAL / ACTIVE  
**Last Updated:** 2026-10-04T22:01:40.303444  
**Task Associated:** TASK_052A Continuous Static Image Algorithm Knowledge Gate  

---

## 1. Mục Đích & Nguyên Tắc Vận Hành
Thư mục `Docs/Reconstruction/` và cơ sở dữ liệu `.ai/reconstruction/ledger.json` là kho lưu trữ tri thức đảo ngược kỹ thuật sạch (Clean-Room Reverse Engineering Knowledge Base) của toàn bộ 45 thư viện nhị phân `.so` thuộc hệ sinh thái Meitu/Facetune.

### Nguyên Tắc Bất Di Bất Dịch:
1. **P0 Tuyệt Đối Đóng Băng (FROZEN):**
   - Mọi phase chỉ tiêu thụ output của P0 thông qua adapter chuẩn mực (`tau_aspect = 1.80`).
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
- **P1 AI/Vision Runtime (8 SO):** `libaidetectionplugin.so`, `libAIModelKit.so`, `libAIModelSearchKit.so`, `libarkernel3.so`, `libarkernel3_android.so`, `libarkernel3_c.so`, `libARKernelInterface.so`, `libManis.so`, `libmfxkit.so`, `libVERenderer.so`, `libmanis_npu_adapter.so`.
- **P2 Media & Codec (6 SO):** `libffmpeg.so`, `libffavc.so`, `libffmpegfilter.so`, `libPVGCodec.so`, `libPVGImageCodec.so`, `libPVGVideoCodec.so`.
- **P3 Utility, Glue & Protected DRM (28 SO):** `libc++_shared.so`, `libbytehook.so`, `libbmpKit.so`, `libdexvmp.so`, `libbuffer_pgl.so`, v.v.

---

## 3. Khóa Danh Tính Nhị Phân libMTFilterKernel.so
- Danh tính nhị phân của `libMTFilterKernel.so` được đính chính và khóa chặt:
  * **Tệp:** `lib-core-graphics/src/main/jniLibs/arm64-v8a/libMTFilterKernel.so`
  * **Kích thước:** `1,858,440 bytes`
  * **SHA-256:** `f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4`
  * **GNU Build-ID:** `05d25f33b47237df48aab961ae026386d69fa8eb`

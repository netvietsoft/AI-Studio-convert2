# Reconstruction Knowledge Base & Clean-Room Architecture Overview

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

---

## 4. Mở Rộng Cơ Sở Tri Thức Đa Ứng Dụng (TASK_052B)
- Tại `TASK_052B`, cơ sở tri thức đảo ngược kỹ thuật sạch được mở rộng từ 45 SO của Meitu sang toàn bộ 14 ứng dụng thương mại hàng đầu tại `F:\App\Image` (447 thư viện `.so` nhị phân arm64-v8a):
  * **B612:** SenseTime STMobile 240-landmarks (`libst_mobile.so`, 14.58MB).
  * **Beauty Plus:** PixRenderCore (`libPixRenderCore.so`, 25.2MB), MTAiInterface (`libMTAiInterface.so`, 22.9MB), MTFilterKernel (2.33MB).
  * **Facetune:** 3DMM Face Model (`libfacetune.so`, 1.39MB), Render Core (`librender.so`, 735KB), Color Transfer (`libtech_transfer_color_transfer.so`, 52KB), TFLite SelfieSeg.
  * **Remini:** Microsoft ONNX Runtime (`libonnxruntime.so`, 19.3MB), Javet V8 (`libjavet-v8-android.v.4.1.4.so`, 69.0MB).
  * **Ulike:** ByteDance EffectSDK (`libeffect.so`, 26.89MB), ByteNN (`libbytenn.so`, 2.3MB), TTVESDK (`libttvesdk.so`, 9.78MB).
  * **VSCO:** VSCOCore (`libvscocore.so`, 6.9MB), Rust UniFFI (`libuniffi_cel.so`, 2.1MB), Tetrahedral 3D LUT shader.
  * **PicsArt:** Pilibs Image Processing Core (`libpilibs.so`, 30.48MB), Smudge Tool, Bucket Fill.
  * **Wink:** Meitu VLAI (`libvlai.so`, 18.9MB), ARKernel3 (18.1MB), MTMVCore (6.1MB), MTAurora (5.8MB).
  * **Time Warp Scan:** CVAlgo Slit-Scan (`libcvalgo.so`, 765KB), Face Landmarks (91KB), Alibaba MNN (1.97MB).
- **V4 Hard Gate:** Toàn bộ tri thức đa ứng dụng được lưu trữ tại `.ai/reports/TASK_052B_F_APP_IMAGE_DEEP_MULTI_APP_SO_KNOWLEDGE_BASE/` và đóng băng; cổng code V4 tiếp tục được khóa cứng (`BLOCKED`) cho tới khi Chủ tịch nghiệm thu.

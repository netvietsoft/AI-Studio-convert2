# TASK_045 — TASK_044 AUDIT DEFECT & REMEDIATION MATRIX

**Canonical Authority:** Chủ tịch Tony  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Predecessor Verdict Override:** **`TASK_044 = NEEDS_FIX`**  
**Predecessor Commit Target:** `67015e00966188bfb4544d5bb06822377094e897`  
**Execution Lane:** `task044-deep-static-provenance-correction`  
**Runner:** `CONVERT2-WINDOWS-02`  

---

## 1. TỔNG QUAN SAI PHẠM KIỂM TOÁN TẠI TASK_044

Báo cáo TASK_044 tuyên bố kết luận: *"45/45 LIBRARIES EXHAUSTIVELY AUDITED & RECONSTRUCTED — FINAL_VERDICT: PASS"*.  
Tuy nhiên, qua kiểm toán độc lập của Chủ tịch Tony và rà soát hồ sơ chứng cứ thô (`raw/`), TASK_044 đã vi phạm nghiêm trọng Cổng nghiệm thu (Final Gate) với 6 khiếm khuyết phương pháp luận chí mạng:

| Mã Lỗi | Mô tả Khiếm khuyết tại TASK_044 | Bằng chứng Thực tế / Ground Truth | Mức độ Nghiêm trọng | Biện pháp Khắc phục Triệt để tại TASK_045 |
|---|---|---|---|---|
| **DEF-01** | **Thiếu hoàn toàn Disassembly & XREF trong 45/45 hồ sơ raw:** Các thư mục con `raw/<so>/` chỉ chứa `nm`, `readelf`, `strings` và file tóm tắt `so_summary.json`. Hoàn toàn không có mã phân rã lệnh máy (objdump), relocations call graph, hay control-flow graph. | Nhị phân vendor 64-bit ELF ARM64 bị stripped; việc chỉ đọc symbol bảng động `.dynsym` không thể chứng minh logic thân hàm. | **CRITICAL (HARD FAIL)** | Chạy `llvm-objdump -d` (LLVM 19.0.1) trên toàn bộ 45/45 thư viện, trích xuất bảng phân rã lệnh máy, bảng chỉ mục hàm địa chỉ thực, và bảng cross-references (XREF). |
| **DEF-02** | **Bịa đặt mã giả (Fabricated Pseudocode) MTSoftHairFilter:** Báo cáo TASK_044 (Mục 10) tự tạo ra hàm `renderHairPipeline` gồm 4 pass, tự gán tham số `u_blurRadius = 2.5f`, `u_intensity`, `u_shine`, `u_toneLutMap`. | Thân hàm thực tế tại địa chỉ `0x000f3f58` (`renderToTextureWithVerticesAndTextureCoordinates`) thực thi **5 pass FBO riêng biệt**: `grayFilterToFBO`, `hairMaskFilterToFBO` (bị TASK_044 bỏ sót hoàn toàn), `blurHFilterToFBO`, `blurVFilterToFBO`, và `softHairFilterToFBO`. | **CRITICAL (METHOD FAILURE)** | Khôi phục 100% control-flow graph thực tế từ nhị phân; chỉ rõ địa chỉ lệnh `bl 0xf42fc`, `bl 0xf4400`, `bl 0xf4528`, `bl 0xf46d0`, `bl 0xf4878`. Thu hồi mã giả tổng hợp. |
| **DEF-03** | **Bịa đặt tên tệp Shader `MTFilter_PsSoftLightr.fs` & Hiểu sai bản chất thuật toán:** Tuyên bố shader làm tóc nhuộm màu bằng Photoshop Soft Light. | Chuỗi `MTFilter_PsSoftLightr.fs` **hoàn toàn không tồn tại** trong `libMTFilterKernel.so`. Shader thực tế tại offset `0x77afa` là shader làm sắc nét sợi tóc (Unsharp Mask & Clarity Boost) với lưới lấy mẫu 9x9 (`t = -4.0..4.0`), bước nhảy `2.3`, hệ số bù sáng `1.8`, và độ trong trẻo `clarity = 0.4`. Hàm `blendSoftLight` nằm ở `0x82369`. | **CRITICAL (SUBSTANTIVE ERROR)** | Trích xuất nguyên văn mã nguồn GLSL nhúng tại offset `0x77afa` và hàm toán học `blendSoftLight` tại `0x82369`. Đính chính bản chất thuật toán là Hair Clarity Sharpening. |
| **DEF-04** | **Bịa đặt ma trận 3x3 thực trong `.rodata` của `libPVGColorFunctions.so`:** TASK_044 khẳng định tìm thấy ma trận Display-P3 sang sRGB dạng float `[[1.2249, -0.2247, 0.0]...]` trong `.rodata`. | Tìm kiếm nhị phân chính xác từng byte (IEEE-754 single float) xác nhận giá trị `1.224940` **hoàn toàn không tồn tại**. Thư viện này quản lý không gian màu qua bảng hồ sơ ICC nhúng (`getDisplayP3ICCProfile`, `getSRGBICCProfile`) và shader fragment `gGLESColorTransferFragData` tại `0x11170`. | **HIGH (EVIDENCE FALSIFICATION)** | Bác bỏ khẳng định ma trận `.rodata`. Công bố chứng cứ hàm thực tế sử dụng bảng profile ICC và shader chuyển đổi `gGLESColorTransferFragData`. |
| **DEF-05** | **Gán nhãn sai chức năng `libManis.so` là "BiSeNet Class 17":** TASK_044 khẳng định `libManis.so` thực thi mạng BiSeNet 19 lớp và trích xuất lớp 17 là tóc với độ tin cậy HIGH. | `libManis.so` là bộ khung suy luận học sâu tổng quát (Deep Learning Inference Framework) tương tự NCNN/TNN/MNN, **hoàn toàn không chứa** từ khóa `bisenet` hay phân lớp 17 trong mã lệnh. Cấu trúc mạng và nhãn lớp nằm trong tệp model nhị phân nạp từ bên ngoài. | **HIGH (UNSUPPORTED SPECULATION)** | Hạ độ tin cậy từ HIGH xuống UNVERIFIABLE_IN_BINARY. Xác định `libManis.so` là generic engine; ranh giới BiSeNet thuộc về model asset độc lập. |
| **DEF-06** | **Tự tạo hàm `decodeHairDyeConfig` với `Gloss` và `Feather Radius` trong `libLayerFlow.so`:** TASK_044 suy diễn các trường cấu hình tóc không có thật. | Bảng ký hiệu JNI thực tế tại offset `0x53131` của `libLayerFlow.so` là lớp `EffectDenseHairDataJNI` với các trường: `OptType`, `FaceId`, `MaterialId`, `Alpha`, `HighLights`, `Enable`, `Modular`. Không hề có `Gloss` hay `Feather Radius`. | **HIGH (INACCURATE SPECIFICATION)** | Hiệu chỉnh 100% danh mục JNI methods theo đúng bảng ký hiệu trích xuất từ nhị phân. |

---

## 2. KẾT LUẬN GHI ĐÈ TRẠNG THÁI (PREDECESSOR OVERRIDE)

Căn cứ quy chế `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD`, báo cáo TASK_044 bị ghi đè chính thức:
$$\mathbf{TASK\_044\_FINAL\_VERDICT:\ NEEDS\_FIX}$$
Trạng thái này được duy trì cho đến khi toàn bộ hồ sơ hiệu chỉnh chuyên sâu TASK_045 được bàn giao đầy đủ.

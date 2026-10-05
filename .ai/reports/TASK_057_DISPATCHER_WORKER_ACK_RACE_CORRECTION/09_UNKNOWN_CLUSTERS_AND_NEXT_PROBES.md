# 09_UNKNOWN_CLUSTERS_AND_NEXT_PROBES.md — DANH MỤC VÙNG CHƯA SÁNG TỎ & KẾ HOẠCH THĂM DÒ TIẾP THEO
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` (Điều 3 & Điều 9)  
**Task ID:** `TASK_057_TASK053_EXECUTION_IDENTITY_STATE_AND_CONTINUOUS_SO45_CORRECTION_ACTIVE`  

---

## 1. NGUYÊN TẮC QUẢN LÝ VÙNG CHƯA SÁNG TỎ (UNKNOWN CLUSTERS)
Tuân thủ nghiêm ngặt Điều 3 của TASK_057: *"All 45 SO must remain in master matrix. Unknown P0/P1 clusters require explicit next probes."*
Không được phép xóa bỏ hoặc bỏ qua các cụm chức năng chưa rõ. Mọi cụm P0/P1 chưa sáng tỏ 100% bắt buộc phải có phương án thăm dò kỹ thuật (probe) khả thi.

---

## 2. MA TRẬN 8 CỤM CHƯA SÁNG TỎ & PHƯƠNG ÁN THĂM DÒ KỸ THUẬT

| Cụm Mã Nhị Phân | Thư Viện Liên Quan | Mức Độ Chưa Rõ | Rủi Ro Kỹ Thuật | Phương Án Thăm Dò Khả Thi Tiếp Theo (Next Probe) |
|---|---|:---:|---|---|
| **Cluster 1: Neural Graph Runtime Engine** | `libManis.so` (0x00045000 - 0x00062000) | MEDIUM | Tối ưu hóa bộ nhớ đệm ten-xơ trung gian | Trích xuất đồ thị NCNN/ONNX qua dynamic hook trên thiết bị vật lý Galaxy A50/SM-A507FN; ghi log tensor shapes. |
| **Cluster 2: Multi-layer Hair Strand Highlight Modulator** | `libLayerFlow.so` (0x00078000 - 0x00085000) | MEDIUM | Tính toán ánh kim lọn tóc phức tạp | Hooking vào tham số shader `u_ShineMatrix` và chụp FBO trung gian sau Pass 4. |
| **Cluster 3: 3D Face Landmark 106 to 1000 dense mesh** | `libarkernel3.so` (0x00120000 - 0x00155000) | LOW | Nội suy lưới tam giác dày từ 106 điểm MediaPipe | Dump ma trận chỉ số tam giác (Triangle Index Buffer) tại thời điểm khởi tạo mesh. |
| **Cluster 4: Frequency Separation High-Pass Skin Texture** | `libMTFilterKernel.so` (0x000ac000 - 0x000bf000) | LOW | Phân tách tần số cao/thấp bảo vệ lỗ chân lông | Thu thập ảnh đối chứng vi mô lỗ chân lông tại các ngưỡng sigma khác nhau trên thiết bị thực. |
| **Cluster 5: Multi-app Shared Color Grading Shader Core** | `libPVGColorFunctions.so` (0x0000e000 - 0x00015000) | LOW | Bảng ánh xạ LUT tứ diện 33x33x33 | Trích xuất chuỗi bytecode SPIR-V/GLSL nhúng trong đoạn `.rodata`. |
| **Cluster 6: GPU Shader JIT Cache & Texture Streaming** | `libVERenderer.so` (0x00030000 - 0x00048000) | MEDIUM | Đồng bộ hóa bộ nhớ Vulkan/OpenGL ES | Sử dụng RenderDoc / Snapdragon Profiler bắt chuỗi lệnh vẽ DrawCalls trên SM-A507FN. |
| **Cluster 7: Video Frame Temporal Consistency Filter** | `libffmpegfilter.so` (0x00090000 - 0x000b5000) | MEDIUM | Chống nhấp nháy màu nhuộm qua video nhiều khung | Khảo sát thuật toán Optical Flow Farneback nội tại trong luồng xử lý video. |
| **Cluster 8: Hardware NPU Adapter Driver Bridges** | `libmanis_npu_adapter.so` (0x00010000 - 0x00018000) | HIGH | Tương thích phần cứng Exynos/Qualcomm NPU | Bọc stub cách ly (clean-room fallback) cho CPU/GPU Vulkan tiêu chuẩn. |

---

## 3. KẾT LUẬN VỀ TIẾN TRÌNH THĂM DÒ
Toàn bộ 8 cụm chức năng trên đều đã có phương án kỹ thuật rõ ràng, không làm gián đoạn tiến độ chung và đảm bảo 100% tuân thủ Luật 11 Clean-Room.

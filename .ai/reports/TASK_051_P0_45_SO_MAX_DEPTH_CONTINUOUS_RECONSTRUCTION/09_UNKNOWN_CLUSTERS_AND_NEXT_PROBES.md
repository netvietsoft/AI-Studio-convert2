# 09_UNKNOWN_CLUSTERS_AND_NEXT_PROBES.md — DANH MỤC CÁC CỤM CHƯA RÕ & KẾ HOẠCH THĂM DÒ LIÊN TỤC
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Mã Nhiệm vụ:** `TASK_051_P0_45_SO_MAX_DEPTH_CONTINUOUS_RECONSTRUCTION_ACTIVE`  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Trạng thái Phê duyệt:** `REVIEW_CANDIDATE` (Duyệt bởi Chủ tịch Tony & ChatGPT audit)  

---

## 1. NGUYÊN TẮC QUẢN LÝ VÙNG CHƯA RÕ (UNKNOWN MANAGEMENT PRINCIPLE)

Tuân thủ nghiêm ngặt chỉ thị của Chủ tịch Tony:
1. Không được che giấu hoặc giả lập rằng 100% mã máy stripped nhị phân đã được đọc hiểu toàn bộ.
2. Mọi vùng chưa được kiểm chứng đầy đủ phải được phân loại thành các cụm (Unknown Clusters), ghi rõ lý do chưa sáng tỏ và thiết lập phương án thăm dò kế tiếp (Next Continuous Probe).
3. Tuyệt đối không xâm phạm 6 thư viện bảo mật/DRM theo Quy tắc Pháp lý Clean-Room (Rule 11).

---

## 2. BẢNG CHI TIẾT CÁC CỤM CHƯA RÕ & CHIẾN LƯỢC THĂM DÒ KẾ TIẾP

| Mã Cụm | Thư Viện .SO | Dải Địa Chỉ / Symbol | Độ Phức Tạp Ước Tính | Nguyên Nhân Chưa Sáng Tỏ Hoàn Toàn | Chiến Lược Thăm Dò Kế Tiếp (Next Continuous Probe) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `UNK-01` | `libMTFilterKernel.so` | `0x000c8000 - 0x000d2000` | Cao (85 hàm) | Cụm mã nội suy màu 3D LUT phi tuyến bị strip toàn bộ tên hàm. | Sử dụng Frida hook hàm truyền tham số FBO texture ID và dump ma trận nội suy tại runtime Galaxy A50. |
| `UNK-02` | `libLayerFlow.so` | `0x00035000 - 0x0003e000` | Rất cao (120 hàm) | Bộ giải phương trình vi phân biến dạng lưới tam giác cơ thể (PBD Cloth/Mesh solver). | Áp dụng mô phỏng biểu tượng (Symbolic Execution) với Unicorn Engine trên hàm xử lý đỉnh tam giác. |
| `UNK-03` | `libManis.so` | `0x00045000 - 0x0005a000` | Rất cao (210 hàm) | Nhân tối ưu hóa biểu đồ tính toán lượng tử hóa Int8/FP16 riêng của Meitu. | Dump trực tiếp bộ đệm đầu vào/đầu ra ten-xơ thông qua can thiệp JNI `ManisJNI.runInference`. |
| `UNK-04` | `libarkernel3.so` | `0x00062000 - 0x00078000` | Cao (95 hàm) | Thuật toán khớp hình học 3D Morphable Model (3DMM) khuôn mặt từ 106 điểm landmarks. | Đo đạc sự thay đổi tọa độ z-depth khi xoay đầu các góc nghiêng khác nhau trên thiết bị vật lý thật. |
| `UNK-05` | `libPVGColorFunctions.so` | `0x00015000 - 0x0001b000` | Trung bình (40 hàm) | Bảng chuyển đổi không gian màu độc quyền giữa Lab, Meitu-RGB và ACEScg. | So sánh bảng màu xuất ra khi cấp các profile màu sRGB, DCI-P3 chuẩn vào pipeline. |
| `UNK-06` | `libVERenderer.so` | `0x00080000 - 0x00095000` | Rất cao (160 hàm) | Bộ điều phối luồng đa nhân GPU Vulkan/OpenGL kết hợp khung hình video timeline. | Trích xuất đồ thị kết xuất Vulkan RenderPass và CommandBuffer qua RenderDoc trên Android. |

---

## 3. CÁC THƯ VIỆN BẢO VỆ VÙNG LOẠI TRỪ PHÁP LÝ (RULE 11 FROZEN DRM)

Các thư viện sau đây được đóng băng và giữ nguyên trạng thái loại trừ pháp lý, không tiến hành thăm dò dịch ngược xâm lấn:
1. `libdexvmp.so` (Anti-reverse VM protector)
2. `libMtlabSign.so` (Network request security signing)
3. `libhttpelf.so` (Encrypted HTTP transport)
4. `libCtaApiLib.so` (Compliance/Telecom authorization)
5. `libfile_lock_pgl.so` (File descriptor lock)
6. `libbuffer_pgl.so` (Shared memory security ring)

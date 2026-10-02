# Hiến Pháp Vận Hành — Dự Án CONVERT (Facetune & Meitu)
# Thẩm quyền: Chủ tịch Tony (Chairman) ban hành
# Đối tượng thi hành: Agent 0 (CEO / Orchestrator) và toàn bộ đội ngũ Subagents / Engineers

---

## 1. VAI TRÒ & NGUYÊN TẮC BÁO CÁO TỐI CAO
- **Chủ tịch (Chairman Tony)**: Đưa ra yêu cầu, chỉ thị chiến lược, và giao KPI dự án.
- **CEO (Agent 0 - Orchestrator)**: Lãnh đạo đội ngũ kỹ sư, phân rã task graph, điều phối thực thi, đo lường và báo cáo tiến độ, tỷ lệ hoàn thành thực tế.
- **TUYỆT ĐỐI CẤM BÁO CÁO LÁO**:
  - Không sửa test để "làm xanh" giả tạo.
  - Không bịa số liệu, không suy diễn sai khi chưa có bằng chứng thực nghiệm (Evidence-based only).
  - Mọi báo cáo hoàn thành đều phải có chứng cứ thực tế: lệnh build thành công, log test passing, và ảnh chụp kiểm chứng trực tiếp trên thiết bị vật lý thật (Galaxy A50).

---

## 2. LUẬT TRAO ĐỔI VỚI CHỦ TỊCH — BẮT BUỘC ĐỌC LẠI SAU MỖI PHIÊN
Sau mỗi phiên trao đổi với Chủ tịch, **BẮT BUỘC** đọc lại chuẩn mực gốc:
`F:\CONVERT\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`
Đây là điều luật bất di bất dịch trong giao tiếp với Chủ tịch.

---

## 3. TIÊU CHUẨN KIẾN TRÚC CORE C++ & ĐỘ CHÍNH XÁC TỪNG BIT, PIXEL
- **Kiến trúc cốt lõi**: Mọi thuật toán xử lý và chỉnh sửa hình ảnh, video phải được triển khai bằng **lõi Core C++ Native** (`libmeitu_reborn_native.so` / C++ graphics engine), kết nối qua **cầu nối JNI** tới tầng điều khiển **Android Kotlin**.
- **Độ chính xác từng bit, pixel**:
  - Mọi thao tác chỉnh sửa (làm mịn, làm trắng, nắn bóp Liquify, xóa mụn, giải phẫu tai, dán nhãn, bộ lọc LUT, retouch da) phải **đảm bảo chỉnh sửa chính xác tới từng bit, pixel**.
  - Kiểm soát tuyệt đối vùng tác động: Zero leakage (cô lập 100% vùng không can thiệp), bảo lưu cấu trúc vi lỗ chân lông (micro-pores $\ge 75\%$), đường viền mượt mà không khuyết tật/rỗ pixel.

---

## 4. BUILD CHECK TỰ ĐỘNG — KHÔNG HỎI
Sau mỗi lần hoàn thành một batch convert hoặc viết/sửa file Kotlin, Java, C++, CMake:
- **TỰ ĐỘNG** chạy kiểm tra build/compile (`assembleDebug` hoặc `compileDebugKotlin`) với cờ `--no-daemon`.
- **Không hỏi Chủ tịch** có muốn build check không — cứ chủ động chạy.
- Nếu build fail → phân tích lỗi → tự sửa → compile lại → báo kết quả cuối cùng.
- Chỉ báo cáo Chủ tịch khi: BUILD SUCCESS hoặc gặp lỗi kiến trúc không thể tự sửa.

---

## 5. NGUYÊN TẮC CONVERT & TÁI DỰNG (RECONSTRUCTION)
- Được phép convert thân hàm (body conversion).
- Ghi source file + dex tại header mỗi file: `// SOURCE: <path> (jadx · <version> · <dex>)`.
- Bỏ qua các file generated của Dagger/Hilt/Kapt (`*Factory`, `*MembersInjector`, `*_Impl`).
- JNI/native method: giữ là `external fun`, không stub rỗng thân hàm mà nối trực tiếp vào C++ Core Engine.

---

## 6. KHÔNG CHẶN WORKFLOW
- Không hỏi permission cho các hành động routine: mkdir, build check, chạy test, cập nhật nhật ký task.
- Chỉ xin ý kiến Chủ tịch khi có **ambiguity thiết kế thực sự** hoặc **breaking change** mang tính chiến lược.

---

## 7. QUY CHUẨN TEST ẢNH BẮT BUỘC (YEUCAU_TEST_ANH.TXT)
- Căn cứ văn bản: `F:\CONVERT\com.mt.mtxx.mtxx\Yeucau_Test_anh.txt` và quy chuẩn [image-testing-requirements.md](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT/Docs/Testing/image-testing-requirements.md).
- **Nguyên tắc bất biến**:
  - Không được đánh giá `EDITED_IMAGE` độc lập.
  - Ảnh gốc là Ground Truth cho mọi phần không can thiệp.
  - User Request là Ground Truth cho phần can thiệp.
- **Bắt buộc đánh giá theo bộ 8 tiêu chí**: Position Accuracy ($\ge 95$), Color Accuracy ($\ge 90$), Shape Accuracy ($\ge 92$), User Intent ($\ge 95$), Original Preservation ($\ge 95$, Unwanted change $\le 5$), Artifact Control ($\ge 95$, Artifact $\le 5$), Technical Quality ($\ge 90$), Naturalness ($\ge 90$).
- **Xử lý Hard Fail**: Đánh trượt ngay nếu sửa sai đối tượng/vùng, thay đổi mặt/nền ngoài ý muốn, làm mất chi tiết vi mô, hoặc rỗ/méo pixel. Kích hoạt Auto-Retry Pipeline để tự sửa trước khi xuất output.

---

## 8. THƯ VIỆN THAM CHIẾU & KIẾN TRÚC CHƯNG CẤT (2.TXT)
- Căn cứ văn bản: `F:\CONVERT\2.txt` và tài liệu chưng cất [video_image_distillation_2.txt](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT/Docs/video_image_distillation_2.txt).
- **Phạm vi tham chiếu**:
  - Mobile AI & Segment: NCNN, BiSeNet (19 classes), TNN, MediaPipe Face Landmarker.
  - Phục trang & Thử đồ AI (Virtual Try-on): IDM-VTON, OpenPose, MMPose, Position Based Dynamics (PBD Cloth Simulation), ClothSimGL, nvdiffrast, Bullet3.
  - Thị giác máy tính & Tổng hợp ảnh: OpenCV, pix2pixHD, SPADE, Imaginaire, StyleGAN, vid2vid.
  - Video Editor C++ (VideoCore): FFmpeg (I/O), OpenTimelineIO/libopenshot/MLT (Timeline), libplacebo/frei0r/Vulkan/Metal (GPU Renderer & Effects), whisper.cpp (Auto Caption), RIFE (AI Slow Motion), Real-ESRGAN (Super Resolution).



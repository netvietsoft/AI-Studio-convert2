# BÁO CÁO 19: NGUYÊN TẮC PHÒNG SẠCH VÀ BẢN QUYỀN (DO NOT COPY & CLEAN-ROOM DIRECTIVE)
## DỰ ÁN: CONVERT2 — TECHNICAL BENCHMARK & RECONSTRUCTION STUDY

---

## 1. NGUYÊN TẮC BẤT KHẢ XÂM PHẠM CỦA HIẾN PHÁP

Căn cứ theo Điều 1 và Điều 4 của Hiến pháp Vận hành CONVERT, toàn thể đội ngũ kỹ sư và các Subagents phải tuân thủ nghiêm ngặt các điều khoản sau:

1. **TUYỆT ĐỐI CẤM SAO CHÉP MÃ NGUỒN NHỊ PHÂN HOẶC DECOMPILED:**
   - Cấm sao chép bất kỳ đoạn mã nhị phân (.so) nào từ các ứng dụng thương mại vào kho mã nguồn sản xuất của CONVERT2.
   - Cấm sao chép trực tiếp các đoạn mã Java/Kotlin được dịch ngược bởi JADX/Apktool.
   - Cấm sao chép nguyên trạng các tệp trọng số mạng nơ-ron độc quyền (`.bin` của Meitu, `.model` của ByteDance/SenseTime).

2. **QUY TRÌNH PHÁT TRIỂN PHÒNG SẠCH (CLEAN-ROOM ENGINEERING PROTOCOL):**
   - **Giai đoạn 1 (Khảo sát & Lập đặc tả - Black-box / Forensic Analysis):** Nghiên cứu hành vi, nguyên lý toán học, cấu trúc dữ liệu và công thức giải thuật của đối thủ để lập tài liệu đặc tả kỹ thuật độc lập (Functional Specification).
   - **Giai đoạn 2 (Tái dựng độc lập - Independent Clean-Room Implementation):** Kỹ sư lập trình chỉ dựa trên tài liệu đặc tả toán học để tự viết lại mã nguồn mới hoàn toàn bằng C++20 và Vulkan SPIR-V.
   - Mọi mã nguồn tái dựng phải ghi rõ nguồn gốc xuất xứ tại phần đầu tệp tin theo quy chuẩn:
     `// SOURCE: <path> (jadx · <version> · <dex>)`

3. **BẢO VỆ TUYỆT ĐỐI CÁC THÀNH PHẦN FROZEN:**
   - Không được chạm vào các giá trị ngưỡng đã đóng băng của CONVERT2 (ví dụ: $\tau_{aspect} = 1.80$ của P0 là bất biến). Mọi kỹ thuật mới chỉ được đóng vai trò người tiêu thụ (Consumer) thông qua tầng Adapter.

# Tip/ — Cẩm Nang & Kỹ Thuật Tốc Chiến Convert Mã Nguồn Meitu

Thư mục chứa các **bí kíp kỹ thuật, nguyên tắc tác chiến và công cụ tự động hóa** giúp đội ngũ kỹ sư thực hiện chuyển đổi (convert) mã nguồn từ Java dịch ngược sang dự án **Kotlin chuẩn công nghiệp build xanh ngay lập tức**.

---

## Danh Mục Tài Liệu Hướng Dẫn Tốc Chiến

| Tệp tin | Chủ đề trọng tâm | Mục tiêu giải quyết |
| :--- | :--- | :--- |
| **`01_TIP_KHU_LAM_ROI_VA_CHUYEN_DOI_KOTLIN.md`** | Khử R8/Synthetic & Viết Clean Kotlin | Xử lý lỗi synthetic, khôi phục tên biến từ `@Metadata`, chuyển getters/setters sang properties. |
| **`02_TIP_DONG_GOI_MODULE_VA_CO_LAP_BUILD.md`** | Cô lập Module & Kỹ thuật Stubbing | Chia 7 module độc lập, biên dịch từng phần; dùng Stub class để build xanh 100% không bị chặn bởi lỗi thiếu file. |
| **`03_TIP_JNI_VA_NATIVE_SO_WRAPPER.md`** | Tái sử dụng 45 file `.so` & JNI Bridge | Đóng gói jniLibs, giữ đúng chữ ký hàm native, xử lý thứ tự nạp `loadLibrary`. |
| **`04_SCRIPT_HO_TRO_CONVERT_TU_DONG.py`** | Script Python tự động sinh Kotlin Scaffold | Tự động đọc Java decompiled, lọc class rác, thêm header truy vết nguồn, xuất file `.kt`. |

---

## 3 Nguyên Tắc Cốt Lõi Khi Thực Hiện Convert

1. **Nguyên tắc "Build Xanh Từng Tầng" (Layered Compile-Driven):**
   - Không convert ồ ạt hàng nghìn file cùng lúc.
   - Convert theo thứ tự: **Core Interfaces & Models -> Utils -> JNI Wrappers -> Feature Logic -> UI**.
   - Mỗi khi xong một cụm class, chạy ngay:
     ```bash
     ./gradlew.bat :lib-core-graphics:compileDebugKotlin
     ```
2. **Kỹ thuật Stubbing (Bẻ gãy phụ thuộc vòng tròn):**
   - Nếu class A đang convert phụ thuộc vào class B (mà class B chưa convert), **không được dừng lại để đi tìm class B**.
   - Hãy tạo ngay một file Stub cho class B trong cùng module với các method rỗng:
     ```kotlin
     class ClassBStub {
         fun doSomething(): Boolean = true
     }
     ```
   - Điều này giúp class A biên dịch thành công ngay lập tức!
3. **Bắt buộc gắn Header Truy vết Nguồn gốc:**
   - Mỗi file convert phải có dòng đầu tiên ghi rõ file decompiled gốc:
     ```kotlin
     // Source decompiled: jadx_src/sources/com/meitu/core/ARKernelInterface.java
     ```

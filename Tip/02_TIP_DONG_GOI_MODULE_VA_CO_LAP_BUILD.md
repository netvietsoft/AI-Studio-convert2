# TIP 02: CÔ LẬP MODULE & KỸ THUẬT STUBBING ĐỂ BUILD XANH
## DỰ ÁN: MEITU REBORN (CONVERT2)

---

## 1. CHIẾN LƯỢC CÔ LẬP 7 THƯ VIỆN CHUYÊN BIỆT (MODULARIZATION)

Không bao giờ đổ tất cả 55,000 files vào một module duy nhất! Việc đó sẽ khiến Gradle mất hàng chục phút phân tích, lỗi chồng chéo không thể debug.

Trong `CONVERT2`, chúng ta chia thành **7 modules chuyên trách**:
1. **`:lib-common-ui`:** Nền tảng giao diện (Design Tokens 873 colors, Phông chữ, Theme).
2. **`:lib-core-graphics`:** Chứa 45 thư viện `.so`, ARKernel C++ wrapper, Shaders.
3. **`:lib-ai-engine`:** Manis NPU runtime, Local models loader, Face landmarking 106 điểm.
4. **`:lib-photo-editor`:** Bộ công cụ làm đẹp (Beauty, Retouch, Makeup, Filters, Stickers).
5. **`:lib-roboneo`:** Trợ lý AI Agent đàm thoại đa tác tử, Ktor SSE streaming client.
6. **`:lib-video-engine`:** Biên tập video, timeline đa kênh, Music FX.
7. **`:lib-billing`:** Google Play Billing 7.0, VIP status check, Paywall dialog helpers.
8. **`:app`:** Khung chạy ứng dụng độc lập, kiểm thử tổng hợp (Sample Test Harness).

---

## 2. KỸ THUẬT STUBBING: BẺ GÃY PHỤ THUỘC VÒNG TRÒN

Khi convert class `BeautyProcessor.kt` trong `:lib-photo-editor`, nó gọi `AccountManager.getUserVipStatus()` nằm trong `:lib-billing`. Nếu `:lib-billing` chưa convert xong:
* **Cách làm sai:** Dừng lại, nhảy sang `:lib-billing` convert, rồi bị kéo sang 20 file khác -> Bế tắc (Deadlock).
* **Cách làm chuẩn (Stubbing Technique):**
  Tạo ngay file `AccountManagerStub.kt` ngay trong module hiện tại hoặc file đang làm:
  ```kotlin
  // STUB: Giúp module biên dịch thành công độc lập
  interface AccountManager {
      fun getUserVipStatus(): Boolean = false
  }
  ```
  Khi `:lib-billing` được convert hoàn chỉnh ở giai đoạn sau, ta chỉ cần xóa Stub và trỏ dependency thật!

---

## 3. LỆNH BIÊN DỊCH KIỂM TRA TỪNG MODULE

Luôn kiểm tra từng module nhỏ thay vì build toàn bộ:
```bash
# Kiểm tra module đồ họa lõi JNI
./gradlew.bat :lib-core-graphics:compileDebugKotlin

# Kiểm tra module AI Engine
./gradlew.bat :lib-ai-engine:compileDebugKotlin

# Kiểm tra module chỉnh ảnh
./gradlew.bat :lib-photo-editor:compileDebugKotlin

# Kiểm tra toàn bộ dự án
./gradlew.bat assembleDebug
```
Lần build đầu tiên nếu có báo lỗi thiếu class, danh sách lỗi từ compiler chính là **bản danh sách công việc cần làm tiếp theo**, không phải lỗi cấu hình!

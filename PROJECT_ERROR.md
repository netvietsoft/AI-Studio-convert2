# SỔ TAY QUẢN TRỊ LỖI DỰ ÁN (PROJECT_ERROR.md)
**Dự án:** Meitu Reborn (CONVERT2)  
**Tiêu chuẩn áp dụng:** Development Workspace Standard V2.1.2  
**Nguyên tắc:** Mỗi lỗi đã giải quyết phải được ghi lại thành tri thức để dự án không bao giờ lặp lại sai lầm.

---

### [ERR-001] Runtime Crash: `ClassNotFoundException: com.meitu.labdeviceinfo.LabDeviceModel`
- **Thời điểm phát hiện:** 2026-10-01 khi khởi chạy app trên thiết bị vật lý thật Samsung Galaxy A50.
- **Nguyên nhân gốc rễ:** Thư viện C++ prebuilt của Meitu (`liblabdeviceinfo.so`) khi được nạp qua `System.loadLibrary` trong runtime JNI tự động gọi `FindClass("com/meitu/labdeviceinfo/LabDeviceModel")`. Do tầng Kotlin thiếu file class này, máy ảo ART lập tức ném ngoại lệ và dừng ứng dụng.
- **Giải pháp triệt để:** Tạo file `lib-core-graphics/src/main/kotlin/com/meitu/labdeviceinfo/LabDeviceModel.kt` khai báo model data class tương thích với các trường thông tin phần cứng mà C++ truy vấn.
- **Quy tắc phòng ngừa:** Mọi thư viện prebuilt `.so` của Meitu cần được rà soát chuỗi ký tự JNI string (`strings lib*.so | grep FindClass`) để đảm bảo các class Kotlin tương ứng luôn hiện diện trong classpath.

---

### [ERR-002] Runtime Crash: `UnsatisfiedLinkError` trên `MTMVGroup` và `MTMVTimeLine`
- **Thời điểm phát hiện:** 2026-10-01 khi mở `VideoEditorActivity`.
- **Nguyên nhân gốc rễ:** Tầng Kotlin gọi các phương thức quản lý clip và track video (`MTMVGroup.native_setup`, `retainGroup`, `MTMVTimeLine.invalidate`, `getGroupNum`, `removeAllGroups`...), nhưng trong thư viện C++ NDK `libmeitu_reborn_native.so` chưa export các ký hiệu hàm JNI tương ứng.
- **Giải pháp triệt để:** Triển khai đầy đủ trọn bộ JNI implementation stubs an toàn trong `jni_bridge.cpp` cho cả `MTMVGroup` và `MTMVTimeLine`, đảm bảo con trỏ C++ hợp lệ và không gây memory leak.
- **Quy tắc phòng ngừa:** Khi khai báo bất kỳ `external fun` nào trong Kotlin hoặc kế thừa từ mã nguồn decompile, phải kiểm tra đối chiếu ngay với bảng xuất khẩu ký hiệu trong `jni_bridge.cpp`.

---

### [ERR-003] Biên dịch NDK thất bại: `multiple definition of Java_...` trong `jni_bridge.cpp`
- **Thời điểm phát hiện:** 2026-10-01 trong quá trình build C++ NDK.
- **Nguyên nhân gốc rễ:** Các hàm JNI `Java_com_meitu_media_mtmvcore_MTMVGroup_*` và `MTMVTimeLine_*` vô tình bị khai báo tại 2 vị trí khác nhau trong cùng một file `jni_bridge.cpp` (khối đầu file và khối cuối file), dẫn đến xung đột ký hiệu tại bước liên kết `ld.lld`.
- **Giải pháp triệt để:** Hợp nhất toàn bộ định nghĩa vào một khối duy nhất, loại bỏ triệt để các phần trùng lặp.
- **Quy tắc phòng ngừa:** Kiểm tra grep tên hàm JNI trong toàn bộ project C++ trước khi build để đảm bảo mỗi hàm JNI chỉ có duy nhất 1 định nghĩa thực thi.

---

### [ERR-004] UI Automator Dump Treo: `ERROR: could not get idle state`
- **Thời điểm phát hiện:** 2026-10-01 khi chạy `uiautomator dump` trong lúc video đang phát playback.
- **Nguyên nhân gốc rễ:** Vòng lặp phát video `playbackHandler.postDelayed(playbackRunnable, 33)` chạy liên tục 60 FPS khiến hàng đợi thông điệp chính của Android (Main Looper) không bao giờ rơi vào trạng thái rảnh (Idle), khiến UI Automator chờ đợi đến khi timeout.
- **Giải pháp triệt để:** Tạm dừng playback trước khi dump UI, hoặc truy vấn trực tiếp tọa độ của các layout view cố định (`bounds="[22,974][202,1120]"`...) đã được xác định trước đó.
- **Quy tắc phòng ngừa:** Trong các test tự động ADB, luôn gửi lệnh tạm dừng các vòng lặp animation/looper liên tục trước khi chụp hierarchy XML.

---

### [ERR-005] Lỗi nhận dạng Activity qua ADB: `Activity class does not exist`
- **Thời điểm phát hiện:** 2026-10-01 khi gọi `am start -n com.mt.mtxx.mtxx.convert/...`.
- **Nguyên nhân gốc rễ:** Trong `app/build.gradle.kts`, `applicationIdSuffix = ".convert"`, do đó package name trên thiết bị là `com.mt.mtxx.mtxx.convert`. Tuy nhiên class name giữ nguyên namespace gốc: `com.mt.mtxx.mtxx.video.VideoEditorActivity` và `com.mt.mtxx.mtxx.editor.PhotoEditorActivity` (không có chữ `.convert` trong đường dẫn class Java).
- **Giải pháp triệt để:** Lệnh gọi chuẩn xác là:
  `am start -S -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.video.VideoEditorActivity`
  và `am start -S -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity`.
- **Quy tắc phòng ngừa:** Luôn tra cứu `AndroidManifest.xml` kết hợp `namespace` và `applicationIdSuffix` để xác định chính xác Intent target component.

---

### [ERR-006] Lock Recursion Deadlock trên Windows `msvcrt.locking`
- **Thời điểm phát hiện:** 2026-10-02 trong quá trình triển khai `CommandBusOrchestrator` (`TASK_011`).
- **Nguyên nhân gốc rễ:** Trên hệ điều hành Windows, thư viện chuẩn C runtime `msvcrt.locking` khóa tệp tin theo vùng byte cố định. Khi một hàm gọi lồng (`migrate_next_command()` gọi `create_command()`), cả hai cùng cố gắng acquire `FileLock` trên cùng một tệp `.bus.lock`. Do `msvcrt.locking` không tự động hỗ trợ reentrancy trên cùng tiến trình, tiến trình tự chặn chính nó và rơi vào deadlock chờ timeout.
- **Giải pháp triệt để:** Triển khai lớp `FileLock` hỗ trợ reentrancy (`threading.local()` lưu trữ độ sâu lồng `count`), đồng thời khởi tạo ghi 1 byte ban đầu (`os.write(fd, b'0')`) và `os.lseek(fd, 0, os.SEEK_SET)` để `msvcrt.locking` luôn khóa trên byte tồn tại hợp lệ.
- **Quy tắc phòng ngừa:** Mọi cơ chế FileLock đa nền tảng (Windows/POSIX) trong dự án phải được thiết kế reentrant và kiểm thử với các hàm gọi lồng trước khi đưa vào vận hành.

# TIP 03: TÁI SỬ DỤNG 45 FILE `.SO` & THIẾT LẬP JNI BRIDGES
## DỰ ÁN: MEITU REBORN (CONVERT2)

---

## 1. NGUYÊN TẮC BẤT BIẾN KHI GỌI C++ NATIVE

1. **Giữ nguyên 100% Package Name và Class Name:**
   - Hàm C++ trong file `.so` được liên kết tĩnh theo quy ước đặt tên JNI:
     `Java_com_meitu_core_ARKernelInterface_nativeProcessFrame`
   - Nếu bạn đổi package thành `com.mycompany.arkernel`, máy ảo Android Runtime (ART) sẽ báo lỗi:
     `java.lang.UnsatisfiedLinkError: No implementation found for native void ...`
   - **Giải pháp:** Trong module `:lib-core-graphics`, bắt buộc đặt package của lớp wrapper là `com.meitu.core` hoặc `com.layer.flow` đúng như trong `03_jni_bridge.md`!

2. **Giữ nguyên kiểu tham số (Signature):**
   - Tham số `long` trong Java là con trỏ bộ nhớ `jlong` (64-bit pointer) trong C++. Không được đổi sang `int`.
   - Tham số mảng `byte[]` hoặc `float[]` phải truyền đúng mảng nguyên thủy.

---

## 2. THỨ TỰ NẠP THƯ VIỆN (`SYSTEM.LOADLIBRARY`) CHUẨN XÁC

Các thư viện C++ của Meitu có sự phụ thuộc lẫn nhau. Thứ tự nạp thư viện bắt buộc trong khối static initializer:

```kotlin
package com.meitu.core

object MeituNativeLoader {
    private var isLoaded = false

    @Synchronized
    fun loadLibraries() {
        if (isLoaded) return
        try {
            // 1. Nạp LLVM C++ runtime
            System.loadLibrary("c++_shared")
            
            // 2. Nạp các bộ codec hình ảnh & giải thuật toán học
            System.loadLibrary("PVGCodec")
            System.loadLibrary("fftw3")
            
            // 3. Nạp nhân xử lý đồ họa ARKernel
            System.loadLibrary("arkernel3")
            System.loadLibrary("ARKernelInterface")
            
            // 4. Nạp nhân Deep Learning Manis
            System.loadLibrary("Manis")
            
            // 5. Nạp nhân quản lý Layer Compositor
            System.loadLibrary("LayerFlow")
            
            isLoaded = true
            android.util.Log.i("MeituNativeLoader", "45 Native libraries loaded successfully!")
        } catch (e: UnsatisfiedLinkError) {
            android.util.Log.e("MeituNativeLoader", "Failed to load C++ libs: ${e.message}")
        }
    }
}
```

---

## 3. CẤU HÌNH PACKAGING TRONG `BUILD.GRADLE.KTS`

Trong module `:lib-core-graphics/build.gradle.kts`:
```kotlin
android {
    sourceSets["main"].jniLibs.srcDir("src/main/jniLibs")
    packaging {
        jniLibs {
            useLegacyPackaging = true
        }
    }
}
```
Đặt 45 file `.so` vào thư mục:
`lib-core-graphics/src/main/jniLibs/arm64-v8a/`

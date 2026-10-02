// Source decompiled: com.meitu.media.PVGCodec.NativeLoader.java
package com.meitu.media.PVGCodec

import android.util.Log
import androidx.annotation.Keep
import com.meitu.core.MeituNativeLoader

/**
 * Lớp nạp thư viện C++ native cho hệ thống PVGCodec và Video Engine Reborn.
 * Native library loader for PVGCodec, Video Engine, and Core Native C++.
 */
@Keep
object NativeLoader {
    private const val TAG = "PVGNativeLoader"

    @JvmField
    var a: LoadLibraryDelegate? = null

    @FunctionalInterface
    @Keep
    fun interface LoadLibraryDelegate {
        fun loadLibrary(libName: String)
    }

    /**
     * Nạp toàn bộ các thư viện .so cần thiết cho xử lý video.
     * Đảm bảo meitu_reborn_native luôn được nạp an toàn trước tiên.
     */
    @JvmStatic
    @Synchronized
    fun a() {
        // Nạp meitu_reborn_native qua MeituNativeLoader chuẩn
        MeituNativeLoader.loadLibraries()

        val delegate = a
        val coreLib = "meitu_reborn_native"
        try {
            if (delegate != null) {
                delegate.loadLibrary(coreLib)
            } else {
                System.loadLibrary(coreLib)
            }
            Log.i(TAG, "Lõi native $coreLib đã nạp thành công.")
        } catch (e: UnsatisfiedLinkError) {
            Log.w(TAG, "Cảnh báo nạp $coreLib: ${e.message}")
        }

        // Tùy chọn nạp thêm các thư viện legacy nếu có sẵn trên thiết bị arm64
        val optionalLibs = arrayOf(
            "c++_shared",
            "PVGCodec",
            "PVGVideoCodec"
        )

        for (lib in optionalLibs) {
            try {
                if (delegate != null) {
                    delegate.loadLibrary(lib)
                } else {
                    System.loadLibrary(lib)
                }
            } catch (e: Throwable) {
                // Nuốt lỗi an toàn, không để văng UnsatisfiedLinkError làm crash app
                Log.d(TAG, "Legacy lib $lib skipped safely on this device architecture: ${e.message}")
            }
        }
    }

    /**
     * Khởi tạo nạp thư viện / Initialize native loading.
     */
    fun init() {
        a()
    }
}

package com.meitu.core

import android.os.Build
import android.util.Log

/**
 * Trình quản lý nạp thư viện C++ (.so) an toàn cho Meitu Reborn.
 * Cơ chế Lazy-Loading bảo vệ ứng dụng không bị Crash SIGSEGV khi khởi động.
 *
 * Safe Native C++ Shared Object (.so) Loader for Meitu Reborn.
 * Protects application against startup SIGSEGV crashes via resilient Lazy-Loading.
 */
object MeituNativeLoader {
    private const val TAG = "MeituNativeLoader"

    private val loadedLibraries = mutableSetOf<String>()

    /**
     * Thư viện native thiết yếu tối thiểu nạp lúc khởi động / Minimal bootstrap native libraries
     */
    private val BOOTSTRAP_LIBRARIES = listOf(
        "c++_shared",
        "meitu_reborn_native"
    )

    /**
     * Danh sách các thư viện C++ chuyên sâu nạp theo yêu cầu (On-Demand Lazy Loading)
     */
    private val EXTENDED_LIBRARIES = listOf(
        "labdeviceinfo",
        "bmpKit",
        "fftw3",
        "ffmpeg",
        "ffavc",
        "ffmpegfilter",
        "MTFilterKernel",
        "arkernel3",
        "ARKernelInterface",
        "Manis",
        "manis_npu_adapter",
        "AIModelKit",
        "aidetectionplugin",
        "LayerFlow",
        "VERenderer",
        "PVGCodec",
        "PVGImageCodec",
        "PVGVideoCodec",
        "PVGColorFunctions",
        "PVGLive",
        "KKMusicFX",
        "mfxkit",
        "fantasy"
    )

    private fun logInfo(tag: String, msg: String) {
        try {
            Log.i(tag, msg)
        } catch (_: Throwable) {
            println("[$tag] $msg")
        }
    }

    private fun logWarn(tag: String, msg: String) {
        try {
            Log.w(tag, msg)
        } catch (_: Throwable) {
            println("[$tag] $msg")
        }
    }

    @Synchronized
    fun loadLibrary(libName: String): Boolean {
        if (loadedLibraries.contains(libName)) {
            return true
        }

        return try {
            System.loadLibrary(libName)
            loadedLibraries.add(libName)
            logInfo(TAG, "Successfully loaded native library: lib$libName.so")
            true
        } catch (e: Throwable) {
            logWarn(TAG, "Optional native library lib$libName.so deferred/skipped: ${e.message}")
            false
        }
    }

    @Synchronized
    fun loadBootstrapLibraries(): Boolean {
        val abis = try {
            Build.SUPPORTED_ABIS?.joinToString() ?: "unknown"
        } catch (_: Throwable) {
            "unknown"
        }
        logInfo(TAG, "Initializing Meitu Native Bootstrap on ABI: $abis")
        var allSuccess = true
        for (lib in BOOTSTRAP_LIBRARIES) {
            if (!loadLibrary(lib)) {
                allSuccess = false
            }
        }
        return allSuccess
    }

    @Synchronized
    fun loadAllCoreLibraries(): Boolean {
        loadBootstrapLibraries()
        var allSuccess = true
        for (lib in EXTENDED_LIBRARIES) {
            if (!loadLibrary(lib)) {
                allSuccess = false
            }
        }
        return allSuccess
    }

    @Synchronized
    fun loadLibraries(): Boolean = loadAllCoreLibraries()

    fun isLibraryLoaded(libName: String): Boolean = loadedLibraries.contains(libName)
}

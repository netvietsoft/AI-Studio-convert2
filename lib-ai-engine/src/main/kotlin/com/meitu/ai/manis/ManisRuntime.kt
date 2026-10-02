package com.meitu.ai.manis

import android.content.Context
import android.graphics.Bitmap
import android.util.Log
import androidx.annotation.Keep
import com.meitu.core.MeituNativeLoader
import java.nio.ByteBuffer

/**
 * Lớp điều khiển Manis Deep Learning Runtime C++.
 * Hỗ trợ tăng tốc suy luận trên NPU/GPU hoặc CPU Fallback.
 * Nguồn: com.meitu.manis.* & libManis.so
 */
@Keep
class ManisRuntime {

    private var nativeHandle: Long = 0L

    companion object {
        private const val TAG = "ManisRuntime"

        init {
            MeituNativeLoader.loadLibrary("c++_shared")
            MeituNativeLoader.loadLibrary("manis_npu_adapter")
            MeituNativeLoader.loadLibrary("Manis")
        }
    }

    fun initModel(modelPath: String, useGpu: Boolean = true): Boolean {
        if (modelPath.isEmpty()) return false
        nativeHandle = nativeInitModel(modelPath, useGpu)
        Log.i(TAG, "Initialized Manis model at: $modelPath (Handle: $nativeHandle)")
        return nativeHandle != 0L
    }

    fun forwardBitmap(bitmap: Bitmap, outputBuffer: ByteBuffer): Boolean {
        if (nativeHandle == 0L) return false
        return nativeForwardBitmap(nativeHandle, bitmap, outputBuffer)
    }

    fun release() {
        if (nativeHandle != 0L) {
            nativeRelease(nativeHandle)
            nativeHandle = 0L
        }
    }

    protected fun finalize() {
        release()
    }

    // --- NATIVE CALLS ---
    private external fun nativeInitModel(path: String, useGpu: Boolean): Long
    private external fun nativeForwardBitmap(handle: Long, bitmap: Bitmap, out: ByteBuffer): Boolean
    private external fun nativeRelease(handle: Long)
}

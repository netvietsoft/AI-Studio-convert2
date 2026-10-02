// Source decompiled: com.meitu.media.PVGCodec.AudioNoiseReduction.java
package com.meitu.media.PVGCodec

import androidx.annotation.Keep

/**
 * Bộ lọc khử tiếng ồn âm thanh video (Audio Noise Reduction).
 * Denoises audio streams using spectral subtraction algorithms.
 */
@Keep
class AudioNoiseReduction(nativeHandle: Long) : IProcessor(nativeHandle) {

    companion object {
        @JvmStatic
        fun a(): AudioNoiseReduction? {
            val handle = native_setup()
            if (handle == 0L) {
                return null
            }
            return AudioNoiseReduction(handle)
        }

        @JvmStatic
        fun create(): AudioNoiseReduction? = a()

        @JvmStatic
        private external fun native_setup(): Long
    }

    private external fun native_finalize(handle: Long): Int
    private external fun native_setListener(handle: Long, enable: Boolean): Int
    external fun native_process(handle: Long, srcPath: String?, dstPath: String?, level: Int): Int

    fun b(level: Int, srcPath: String?, dstPath: String?): Int {
        return if (mNativeContext != 0L) {
            native_process(mNativeContext, srcPath, dstPath, level)
        } else {
            -1
        }
    }

    fun reduceNoise(srcPath: String?, dstPath: String?, level: Int = 1): Int = b(level, srcPath, dstPath)

    override fun nativeFinalize(handle: Long) {
        native_finalize(handle)
    }

    override fun nativeSetListener(handle: Long, enable: Boolean): Int {
        return native_setListener(handle, enable)
    }
}

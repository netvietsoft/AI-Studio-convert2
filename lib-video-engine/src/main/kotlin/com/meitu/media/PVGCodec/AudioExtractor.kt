// Source decompiled: com.meitu.media.PVGCodec.AudioExtractor.java
package com.meitu.media.PVGCodec

import androidx.annotation.Keep

/**
 * Trích xuất dải âm thanh từ tệp video (Audio Extractor).
 * Extracts audio tracks from video files.
 */
@Keep
class AudioExtractor(nativeHandle: Long) : IProcessor(nativeHandle) {

    companion object {
        @JvmStatic
        fun a(): AudioExtractor? {
            val handle = native_setup()
            if (handle == 0L) {
                return null
            }
            return AudioExtractor(handle)
        }

        @JvmStatic
        fun create(): AudioExtractor? = a()

        @JvmStatic
        private external fun native_setup(): Long
    }

    private external fun native_abort(handle: Long): Int
    private external fun native_finalize(handle: Long): Int
    private external fun native_process(handle: Long, srcPath: String?, dstPath: String?): Int
    private external fun native_setListener(handle: Long, enable: Boolean): Int
    private external fun native_setTimeParam(handle: Long, startUs: Long, endUs: Long): Int

    fun abort(): Int {
        return if (mNativeContext != 0L) {
            native_abort(mNativeContext)
        } else {
            -1
        }
    }

    fun b(srcPath: String?, dstPath: String?): Int {
        return if (mNativeContext != 0L) {
            native_process(mNativeContext, srcPath, dstPath)
        } else {
            -1
        }
    }

    fun extract(srcPath: String?, dstPath: String?): Int = b(srcPath, dstPath)

    fun c(startUs: Long, endUs: Long): Int {
        return if (mNativeContext != 0L) {
            native_setTimeParam(mNativeContext, startUs, endUs)
        } else {
            -1
        }
    }

    fun setTimeRange(startUs: Long, endUs: Long): Int = c(startUs, endUs)

    override fun nativeFinalize(handle: Long) {
        native_finalize(handle)
    }

    override fun nativeSetListener(handle: Long, enable: Boolean): Int {
        return native_setListener(handle, enable)
    }
}

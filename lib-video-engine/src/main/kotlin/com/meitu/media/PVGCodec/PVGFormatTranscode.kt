// Source decompiled: com.meitu.media.PVGCodec.PVGFormatTranscode.java
package com.meitu.media.PVGCodec

import androidx.annotation.Keep

/**
 * Trình chuyển đổi định dạng và độ phân giải video (FFmpeg Format Transcoder).
 * Video format, codec and bitrate transcoding engine.
 */
@Keep
class PVGFormatTranscode(nativeHandle: Long = 0L) : IProcessor(nativeHandle) {

    companion object {
        @JvmStatic
        fun create(): PVGFormatTranscode? {
            val handle = native_setup()
            if (handle == 0L) {
                return null
            }
            return PVGFormatTranscode(handle)
        }

        @JvmStatic
        private external fun native_setup(): Long
    }

    private external fun native_abort(handle: Long): Int
    private external fun native_finalize(handle: Long): Int
    private external fun native_getMediaInfo(handle: Long, filePath: String?): String?
    private external fun native_open(handle: Long, srcPath: String?): Int
    private external fun native_process(handle: Long, dstPath: String?): Int
    private external fun native_setListener(handle: Long, enable: Boolean): Int
    private external fun native_setParameter(handle: Long, key: String?, value: String?): Int

    fun abort(): Int {
        return if (mNativeContext != 0L) {
            native_abort(mNativeContext)
        } else {
            -1
        }
    }

    fun open(srcPath: String?): Int {
        return if (mNativeContext != 0L) {
            native_open(mNativeContext, srcPath)
        } else {
            -1
        }
    }

    fun process(dstPath: String?): Int {
        return if (mNativeContext != 0L) {
            native_process(mNativeContext, dstPath)
        } else {
            -1
        }
    }

    fun setParameter(key: String?, value: String?): Int {
        return if (mNativeContext != 0L) {
            native_setParameter(mNativeContext, key, value)
        } else {
            -1
        }
    }

    fun getMediaInfo(filePath: String?): String? {
        return if (mNativeContext != 0L) {
            native_getMediaInfo(mNativeContext, filePath)
        } else {
            null
        }
    }

    override fun nativeFinalize(handle: Long) {
        native_finalize(handle)
    }

    override fun nativeSetListener(handle: Long, enable: Boolean): Int {
        return native_setListener(handle, enable)
    }
}

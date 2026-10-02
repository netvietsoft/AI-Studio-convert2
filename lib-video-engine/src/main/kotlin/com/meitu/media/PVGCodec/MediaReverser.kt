// Source decompiled: com.meitu.media.PVGCodec.MediaReverser.java
package com.meitu.media.PVGCodec

import androidx.annotation.Keep

/**
 * Đảo ngược thời gian video (Video Reverser FX).
 * Reverses video playback sequence for time-reversal video effect.
 */
@Keep
class MediaReverser(nativeHandle: Long) : IProcessor(nativeHandle) {

    companion object {
        @JvmStatic
        fun create(): MediaReverser? {
            val handle = native_setup()
            if (handle == 0L) {
                return null
            }
            return MediaReverser(handle)
        }

        @JvmStatic
        private external fun native_setup(): Long
    }

    private external fun native_abort(handle: Long): Int
    private external fun native_finalize(handle: Long): Int
    private external fun native_open(handle: Long, srcPath: String?): Int
    private external fun native_process(handle: Long, dstPath: String?): Int
    private external fun native_setListener(handle: Long, enable: Boolean): Int

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

    override fun nativeFinalize(handle: Long) {
        native_finalize(handle)
    }

    override fun nativeSetListener(handle: Long, enable: Boolean): Int {
        return native_setListener(handle, enable)
    }
}

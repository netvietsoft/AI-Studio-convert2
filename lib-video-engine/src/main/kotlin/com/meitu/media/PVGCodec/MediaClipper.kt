// Source decompiled: com.meitu.media.PVGCodec.MediaClipper.java
package com.meitu.media.PVGCodec

import androidx.annotation.Keep

/**
 * Cắt tỉa và ghép đoạn video (Media Clipper & Trimmer).
 * Clips, trims and slices media files with precise time offsets.
 */
@Keep
class MediaClipper(nativeHandle: Long) : IProcessor(nativeHandle) {

    companion object {
        @JvmStatic
        fun create(): MediaClipper? {
            val handle = native_setup()
            if (handle == 0L) {
                return null
            }
            return MediaClipper(handle)
        }

        @JvmStatic
        private external fun native_setup(): Long
    }

    private external fun native_abort(handle: Long): Int
    private external fun native_addMedia(handle: Long, srcPath: String?, startSec: Double, endSec: Double, offsetSec: Double, speed: Double): Int
    private external fun native_finalize(handle: Long): Int
    private external fun native_getDuration(handle: Long): Double
    private external fun native_process(handle: Long, dstPath: String?): Int
    private external fun native_setListener(handle: Long, enable: Boolean): Int

    fun abort(): Int {
        return if (mNativeContext != 0L) {
            native_abort(mNativeContext)
        } else {
            -1
        }
    }

    fun addMedia(srcPath: String?, startSec: Double, endSec: Double, offsetSec: Double): Int {
        return addMedia(srcPath, startSec, endSec, offsetSec, 1.0)
    }

    fun addMedia(srcPath: String?, startSec: Double, endSec: Double, offsetSec: Double, speed: Double): Int {
        return if (mNativeContext != 0L) {
            native_addMedia(mNativeContext, srcPath, startSec, endSec, offsetSec, speed)
        } else {
            -1
        }
    }

    fun getDuration(): Double {
        return if (mNativeContext != 0L) {
            native_getDuration(mNativeContext)
        } else {
            0.0
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

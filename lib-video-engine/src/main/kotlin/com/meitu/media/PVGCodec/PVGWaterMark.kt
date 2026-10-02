// Source decompiled: com.meitu.media.PVGCodec.PVGWaterMark.java
package com.meitu.media.PVGCodec

import androidx.annotation.Keep

/**
 * Đóng dấu bản quyền và hình mờ lên video (Video Watermark Overlay).
 * Renders watermark image overlay onto processed video files.
 */
@Keep
class PVGWaterMark(nativeHandle: Long) : IProcessor(nativeHandle) {

    companion object {
        @JvmStatic
        fun a(): PVGWaterMark? {
            val handle = native_setup()
            if (handle == 0L) {
                return null
            }
            return PVGWaterMark(handle)
        }

        @JvmStatic
        fun create(): PVGWaterMark? = a()

        @JvmStatic
        private external fun native_setup(): Long
    }

    private external fun native_abort(handle: Long): Int
    private external fun native_finalize(handle: Long): Int
    private external fun native_open(handle: Long, srcPath: String?): Int
    private external fun native_process(handle: Long, dstPath: String?): Int
    private external fun native_setListener(handle: Long, enable: Boolean): Int
    private external fun native_setParameter(handle: Long, key: String?, value: String?): Int
    private external fun native_setWatermark(
        handle: Long,
        imagePath: String?,
        blendMode: Int,
        x: Int,
        y: Int,
        width: Int,
        height: Int,
        alpha: Float
    ): Int

    fun b(alpha: Float, imagePath: String?, x: Int, y: Int, width: Int): Int {
        return if (mNativeContext != 0L) {
            native_setWatermark(mNativeContext, imagePath, 0, x, y, width, 0, alpha)
        } else {
            -1
        }
    }

    fun setWatermark(imagePath: String?, x: Int, y: Int, width: Int, height: Int = 0, alpha: Float = 1.0f): Int {
        return if (mNativeContext != 0L) {
            native_setWatermark(mNativeContext, imagePath, 0, x, y, width, height, alpha)
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

    @Synchronized
    override fun release() {
        super.release()
    }
}

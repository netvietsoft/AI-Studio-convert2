// Source decompiled: com.meitu.media.PVGCodec.PVGCodec.java
package com.meitu.media.PVGCodec

import android.graphics.Bitmap
import android.util.Log
import androidx.annotation.Keep

/**
 * Trình giải mã/mã hóa và trích xuất khung hình video thời gian thực (FFmpeg + PVGCodec).
 * Real-time video codec, frame extractor and media inspector powered by FFmpeg/PVG.
 */
@Keep
class PVGCodec(nativeHandle: Long) : IProcessor(nativeHandle) {

    @JvmField
    var a: Int = 0 // frameWidth (Legacy)

    @JvmField
    var b: Int = 0 // frameHeight (Legacy)

    /** Chiều rộng khung hình video / Video frame width */
    var frameWidth: Int
        get() = a
        set(value) { a = value }

    /** Chiều cao khung hình video / Video frame height */
    var frameHeight: Int
        get() = b
        set(value) { b = value }

    companion object {
        private const val TAG = "PVGCodec"

        /**
         * Tạo instance PVGCodec mới qua tầng C++.
         * Factory method creating a new native PVGCodec instance.
         */
        @JvmStatic
        fun a(): PVGCodec? {
            val handle = native_setup(1)
            if (handle == 0L) {
                return null
            }
            val codec = PVGCodec(handle)
            codec.a = 0
            codec.b = 0
            return codec
        }

        @JvmStatic
        fun create(): PVGCodec? = a()

        @JvmStatic
        private external fun native_setup(mode: Int): Long
    }

    private external fun native_abort(handle: Long): Int
    private external fun native_finalize(handle: Long): Int
    private external fun native_getFrame(handle: Long, timeSec: Double, width: Int, height: Int): Bitmap?
    private external fun native_getMediaInfo(handle: Long, filePath: String?): String?
    private external fun native_open(handle: Long, filePath: String?): Int
    private external fun native_process(handle: Long, outputPath: String?): Int
    private external fun native_seekGetFrame(handle: Long, timeSec: Double): Int
    private external fun native_setListener(handle: Long, enable: Boolean): Int
    private external fun native_setParameter(handle: Long, key: String?, value: String?): Int
    private external fun native_startGetFrame(handle: Long, outWidth: IntArray?, outHeight: IntArray?): Int

    fun abort() {
        if (mNativeContext != 0L) {
            native_abort(mNativeContext)
        }
    }

    /**
     * Lấy Bitmap khung hình tại thời điểm giây d.
     * Retrieve video frame bitmap at timestamp d (seconds).
     */
    @Synchronized
    fun b(timeSec: Double): Bitmap? {
        val w = a
        val h = b
        if (w > 0 && h > 0 && mNativeContext != 0L) {
            return native_getFrame(mNativeContext, timeSec, w, h)
        }
        Log.e(TAG, "getFrame: not startGetFrame or size not set ($w x $h)")
        return null
    }

    fun getFrame(timeSec: Double): Bitmap? = b(timeSec)

    /**
     * Lấy thông tin metadata của video (JSON/chuỗi).
     * Retrieve media metadata string.
     */
    fun c(filePath: String?): String? {
        return if (mNativeContext != 0L) {
            native_getMediaInfo(mNativeContext, filePath)
        } else {
            null
        }
    }

    fun getMediaInfo(filePath: String?): String? = c(filePath)

    /**
     * Tua đến khung hình mong muốn / Seek to frame at timeSec.
     */
    @Synchronized
    fun d(timeSec: Double) {
        if (a > 0 && b > 0 && mNativeContext != 0L) {
            native_seekGetFrame(mNativeContext, timeSec)
        } else {
            Log.e(TAG, "seekGetFrame: not startGetFrame")
        }
    }

    fun seekGetFrame(timeSec: Double) = d(timeSec)

    /**
     * Cấu hình tham số codec / Set codec parameter.
     */
    fun e(key: String?, value: String?): Int {
        return if (mNativeContext != 0L) {
            native_setParameter(mNativeContext, key, value)
        } else {
            -1
        }
    }

    fun setParameter(key: String?, value: String?): Int = e(key, value)

    /**
     * Bắt đầu phiên trích xuất khung hình / Initialize frame extraction session.
     */
    @Synchronized
    fun f(inOutWidth: IntArray?, inOutHeight: IntArray?): Int {
        if (mNativeContext == 0L) return -1
        val wArr = inOutWidth ?: intArrayOf(0)
        val hArr = inOutHeight ?: intArrayOf(0)
        val ret = native_startGetFrame(mNativeContext, wArr, hArr)
        if (wArr.isNotEmpty()) a = wArr[0]
        if (hArr.isNotEmpty()) b = hArr[0]
        return ret
    }

    fun startGetFrame(inOutWidth: IntArray?, inOutHeight: IntArray?): Int = f(inOutWidth, inOutHeight)

    fun open(filePath: String?): Int {
        return if (mNativeContext != 0L) {
            native_open(mNativeContext, filePath)
        } else {
            -1
        }
    }

    fun process(outputPath: String?): Int {
        return if (mNativeContext != 0L) {
            native_process(mNativeContext, outputPath)
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

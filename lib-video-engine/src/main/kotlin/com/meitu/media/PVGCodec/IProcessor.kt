// Source decompiled: com.meitu.media.PVGCodec.IProcessor.java
package com.meitu.media.PVGCodec

import android.content.Context
import androidx.annotation.Keep

/**
 * Lớp trừu tượng cơ sở cho toàn bộ các bộ xử lý Media của Meitu PVGCodec.
 * Abstract base class for all Meitu PVGCodec media processors.
 */
@Keep
abstract class IProcessor(protected var mNativeContext: Long = 0L) {

    @Keep
    protected var mListener: w? = null

    @FunctionalInterface
    @Keep
    fun interface LogCallback {
        fun log(level: Int, message: String?)
    }

    companion object {
        const val ANDROID_LISTENER_INFO_BEGAN = 1
        const val ANDROID_LISTENER_INFO_CHANGED = 2
        const val ANDROID_LISTENER_INFO_ENDED = 3
        const val ANDROID_LISTENER_INFO_CANCELED = 4
        const val ANDROID_LISTENER_INFO_FAILED = 5

        const val kColorRangeRESERVED0 = 0
        const val kColorRangeMpeg = 1
        const val kColorRangeJpeg = 2

        const val kPVGColorMatrixRGB = 0
        const val kPVGColorMatrixBT709 = 1
        const val kPVGColorMatrixUNSPECIFIED = 2
        const val kPVGColorMatrixBT2020_NCL = 9
        const val kPVGColorMatrixBT2020_CL = 10

        const val kPVGColorSpacesBT709 = 5
        const val kPVGColorSpacesBT2020 = 8
        const val kPVGColorSpacesDisplayP3 = 12
        const val kPVGColorSpacesDCIP3 = 13

        const val kPVGFormatPCMFormatS16 = 1

        private val sAndroidContextLock = Any()
        private var sAndroidContextSet = false

        init {
            NativeLoader.a()
        }

        @JvmStatic
        external fun checkIsSupportCudaDecode(str: String?, str2: String?): Int

        @JvmStatic
        external fun getPVGColorFunctionVersion(): String?

        @JvmStatic
        external fun getPVGImageCodecVersion(): String?

        @JvmStatic
        external fun getPVGVideoCodecVersion(): String?

        @JvmStatic
        external fun getVersion(): String?

        @JvmStatic
        external fun setAndroidContext(context: Context?)

        @JvmStatic
        external fun setLogCallback(logCallback: LogCallback?)

        @JvmStatic
        external fun setLogCallbackLevel(level: Int)

        @JvmStatic
        external fun setLogLevel(level: Int)
    }

    init {
        val appCtx = q.a
        if (appCtx != null && !sAndroidContextSet) {
            synchronized(sAndroidContextLock) {
                if (!sAndroidContextSet) {
                    try {
                        setAndroidContext(appCtx)
                        sAndroidContextSet = true
                    } catch (e: Throwable) {
                        // Ignore or log
                    }
                }
            }
        }
    }

    /**
     * Thu hồi tài nguyên C++ native / Finalize native handle.
     */
    abstract fun nativeFinalize(handle: Long)

    /**
     * Gắn cờ lắng nghe sự kiện tầng C++ / Set native listener flag.
     */
    abstract fun nativeSetListener(handle: Long, enable: Boolean): Int

    /**
     * Phản hồi sự kiện từ tầng native C++ / Dispatch native info to listener.
     */
    fun postNativeInfo(type: Int, val1: Double, val2: Double) {
        val listener = mListener ?: return
        when (type) {
            ANDROID_LISTENER_INFO_BEGAN -> listener.b()
            ANDROID_LISTENER_INFO_CHANGED -> listener.e(this, val1)
            ANDROID_LISTENER_INFO_ENDED -> listener.c()
            ANDROID_LISTENER_INFO_CANCELED -> listener.f()
            ANDROID_LISTENER_INFO_FAILED -> listener.g(val1, val2)
        }
    }

    /**
     * Giải phóng bộ xử lý / Release processor resources.
     */
    open fun release() {
        val handle = mNativeContext
        if (handle != 0L) {
            mNativeContext = 0L
            try {
                nativeFinalize(handle)
            } catch (e: Throwable) {
                // Ignore during cleanup
            }
        }
    }

    /**
     * Đăng ký bộ lắng nghe sự kiện / Register event listener.
     */
    open fun setListener(listener: w?): Int {
        this.mListener = listener
        return if (mNativeContext != 0L) {
            nativeSetListener(mNativeContext, listener != null)
        } else {
            0
        }
    }

    fun getNativeContext(): Long = mNativeContext
}

// Source decompiled: com.meitu.media.PVGCodec.AudioDecoder.java
package com.meitu.media.PVGCodec

import android.util.Log
import androidx.annotation.Keep

/**
 * Trình giải mã âm thanh từ luồng video/audio (Audio Decoder).
 * Audio decoder for extracting PCM audio frames and waveforms.
 */
@Keep
class AudioDecoder(nativeHandle: Long) : IProcessor(nativeHandle) {

    @JvmField
    var a: String? = null // filePath (Legacy)

    /** Đường dẫn tệp âm thanh nguồn / Source audio file path */
    var filePath: String?
        get() = a
        set(value) { a = value }

    companion object {
        private const val TAG = "AudioDecoder"

        @JvmStatic
        fun a(filePath: String?): AudioDecoder? {
            val handle = native_setup()
            if (handle == 0L) {
                return null
            }
            val decoder = AudioDecoder(handle)
            decoder.a = filePath
            return decoder
        }

        @JvmStatic
        fun create(filePath: String?): AudioDecoder? = a(filePath)

        @JvmStatic
        private external fun native_setup(): Long
    }

    private external fun native_finalize(handle: Long): Int
    private external fun native_getAudioFrame(handle: Long): IntArray?
    private external fun native_open(handle: Long, filePath: String?): Int
    private external fun native_setAudioDecoderParam(handle: Long, startTimeUs: Long, endTimeUs: Long): Int
    private external fun native_setAudioOutParameter(handle: Long, channels: Int, sampleRate: Int, format: Int): Int
    private external fun native_setAudioSmoothingTime(handle: Long, smoothingMs: Int): Int
    private external fun native_setEnablePositiveValue(handle: Long, enable: Boolean): Int

    fun b(): IntArray? {
        return if (mNativeContext != 0L) {
            native_getAudioFrame(mNativeContext)
        } else {
            null
        }
    }

    fun getAudioFrame(): IntArray? = b()

    fun c(): Int {
        return if (mNativeContext != 0L) {
            native_open(mNativeContext, a)
        } else {
            -1
        }
    }

    fun open(): Int = c()

    fun d() {
        if (mNativeContext != 0L) {
            native_setAudioOutParameter(mNativeContext, 1, 16000, kPVGFormatPCMFormatS16)
        }
    }

    fun setDefaultAudioOut() = d()

    fun e() {
        if (mNativeContext != 0L) {
            native_setAudioSmoothingTime(mNativeContext, 100)
        }
    }

    fun setAudioSmoothingTime(ms: Int = 100) {
        if (mNativeContext != 0L) {
            native_setAudioSmoothingTime(mNativeContext, ms)
        }
    }

    fun f() {
        if (mNativeContext != 0L) {
            native_setEnablePositiveValue(mNativeContext, true)
        }
    }

    fun setEnablePositiveValue(enable: Boolean) {
        if (mNativeContext != 0L) {
            native_setEnablePositiveValue(mNativeContext, enable)
        }
    }

    override fun nativeFinalize(handle: Long) {
        native_finalize(handle)
    }

    override fun nativeSetListener(handle: Long, enable: Boolean): Int = 1

    override fun setListener(listener: w?): Int {
        Log.w(TAG, "AudioDecoder setListener unsupported")
        return 1
    }
}

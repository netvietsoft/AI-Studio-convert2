// Source decompiled: com.meitu.media.PVGCodec.MediaCombiner.java
package com.meitu.media.PVGCodec

import androidx.annotation.Keep

/**
 * Hợp nhất âm thanh và hình ảnh video (Audio-Video Muxer & Combiner).
 * Combines separate video stream and audio stream into a single MP4 container.
 */
@Keep
class MediaCombiner(nativeHandle: Long) : IProcessor(nativeHandle) {

    companion object {
        @JvmStatic
        fun create(): MediaCombiner? {
            val handle = native_setup()
            if (handle == 0L) {
                return null
            }
            return MediaCombiner(handle)
        }

        @JvmStatic
        private external fun native_setup(): Long
    }

    private external fun native_finalize(handle: Long): Int
    private external fun native_getOutDuration(handle: Long): Double
    private external fun native_init(handle: Long, videoPath: String?, audioPath: String?, outputPath: String?, muteOriginal: Boolean): Int
    private external fun native_process(handle: Long): Int
    private external fun native_setListener(handle: Long, enable: Boolean): Int

    fun getOutDuration(): Double {
        return if (mNativeContext != 0L) {
            native_getOutDuration(mNativeContext)
        } else {
            0.0
        }
    }

    fun init(videoPath: String?, audioPath: String?, outputPath: String?, muteOriginal: Boolean): Int {
        return if (mNativeContext != 0L) {
            native_init(mNativeContext, videoPath, audioPath, outputPath, muteOriginal)
        } else {
            -1
        }
    }

    fun process(): Int {
        return if (mNativeContext != 0L) {
            native_process(mNativeContext)
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

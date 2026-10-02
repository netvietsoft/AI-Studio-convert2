// Source decompiled: com.meitu.media.mtmvcore.MTVideoEffectExportTask.java
package com.meitu.media.mtmvcore

import androidx.annotation.Keep
import com.meitu.core.MeituNativeLoader

/**
 * Tác vụ kết xuất và xuất file video kèm hiệu ứng (Video FX Export Task).
 * Hardware-accelerated video rendering and export task with customizable bitrates and frame rates.
 */
@Keep
class MTVideoEffectExportTask(nativeHandle: Long = 0L) {

    @Keep
    private var mNativeContext: Long = nativeHandle

    companion object {
        const val STATE_IDLE = 0
        const val STATE_RUNNING = 1
        const val STATE_PAUSED = 2
        const val STATE_COMPLETED = 3
        const val STATE_FAILED = 4
        const val STATE_CANCELED = 5

        init {
            MeituNativeLoader.loadLibraries()
        }

        @JvmStatic
        private external fun nativeCancel(handle: Long)

        @JvmStatic
        private external fun nativeGetProgress(handle: Long): Float

        @JvmStatic
        private external fun nativeGetState(handle: Long): Int

        @JvmStatic
        private external fun nativeRelease(handle: Long)

        @JvmStatic
        private external fun nativeResume(handle: Long)

        @JvmStatic
        private external fun nativeSetAudioFormat(handle: Long, sampleRate: Int, channels: Int, format: Int)

        @JvmStatic
        private external fun nativeSetAudioOutputBitrate(handle: Long, bitrate: Long)

        @JvmStatic
        private external fun nativeSetCodecParam(handle: Long, key: String?, value: String?)

        @JvmStatic
        private external fun nativeSetFaceMode(handle: Long, mode: Int)

        @JvmStatic
        private external fun nativeSetMetadata(handle: Long, key: String?, value: String?)

        @JvmStatic
        private external fun nativeSetOutputSize(handle: Long, width: Int, height: Int)

        @JvmStatic
        private external fun nativeSetPtsToleranceUs(handle: Long, toleranceUs: Long)

        @JvmStatic
        private external fun nativeSetStrategyConfig(handle: Long, config: Long)

        @JvmStatic
        private external fun nativeSetVideoCodec(handle: Long, codecName: String?)

        @JvmStatic
        private external fun nativeSetVideoOutputBitrate(handle: Long, bitrate: Long)

        @JvmStatic
        private external fun nativeSetVideoOutputFrameRate(handle: Long, fps: Float)

        @JvmStatic
        private external fun nativeStart(handle: Long): Boolean

        @JvmStatic
        private external fun nativeStop(handle: Long)

        @JvmStatic
        private external fun nativeSuspend(handle: Long)
    }

    private external fun nativeCreateFusionWithoutMask(videoPath: String?, audioPath: String?, volume: Float, outputPath: String?): Long
    private external fun nativeCreatePictureEnhance(srcPath: String?, dstPath: String?, lutPath: String?, modelPath: String?, sharpness: Float, contrast: Float, extra: String?): Long

    fun initFusionTask(videoPath: String?, audioPath: String?, volume: Float, outputPath: String?) {
        mNativeContext = nativeCreateFusionWithoutMask(videoPath, audioPath, volume, outputPath)
    }

    fun initEnhanceTask(srcPath: String?, dstPath: String?, lutPath: String?, modelPath: String?, sharpness: Float, contrast: Float, extra: String?) {
        mNativeContext = nativeCreatePictureEnhance(srcPath, dstPath, lutPath, modelPath, sharpness, contrast, extra)
    }

    fun setVideoCodec(codecName: String?) {
        if (mNativeContext != 0L) nativeSetVideoCodec(mNativeContext, codecName)
    }

    fun setVideoOutputBitrate(bitrate: Long) {
        if (mNativeContext != 0L) nativeSetVideoOutputBitrate(mNativeContext, bitrate)
    }

    fun setVideoOutputFrameRate(fps: Float) {
        if (mNativeContext != 0L) nativeSetVideoOutputFrameRate(mNativeContext, fps)
    }

    fun setOutputSize(width: Int, height: Int) {
        if (mNativeContext != 0L) nativeSetOutputSize(mNativeContext, width, height)
    }

    fun setAudioFormat(sampleRate: Int, channels: Int, format: Int) {
        if (mNativeContext != 0L) nativeSetAudioFormat(mNativeContext, sampleRate, channels, format)
    }

    fun setAudioOutputBitrate(bitrate: Long) {
        if (mNativeContext != 0L) nativeSetAudioOutputBitrate(mNativeContext, bitrate)
    }

    fun start(): Boolean = if (mNativeContext != 0L) nativeStart(mNativeContext) else false

    fun pause() {
        if (mNativeContext != 0L) nativeSuspend(mNativeContext)
    }

    fun resume() {
        if (mNativeContext != 0L) nativeResume(mNativeContext)
    }

    fun stop() {
        if (mNativeContext != 0L) nativeStop(mNativeContext)
    }

    fun cancel() {
        if (mNativeContext != 0L) nativeCancel(mNativeContext)
    }

    fun getProgress(): Float = if (mNativeContext != 0L) nativeGetProgress(mNativeContext) else 0.0f

    fun getState(): Int = if (mNativeContext != 0L) nativeGetState(mNativeContext) else STATE_IDLE

    fun release() {
        val h = mNativeContext
        if (h != 0L) {
            mNativeContext = 0L
            nativeRelease(h)
        }
    }
}

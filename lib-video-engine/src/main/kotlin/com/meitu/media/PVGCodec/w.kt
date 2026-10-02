package com.meitu.media.PVGCodec

import androidx.annotation.Keep

/**
 * Interface lắng nghe sự kiện xử lý của IProcessor (Legacy Bridge).
 * Backwards-compatible listener bridging to IProcessorListener.
 */
@Keep
interface w : IProcessorListener {
    /** Bắt đầu xử lý / Processing started */
    fun b()

    /** Hoàn tất xử lý / Processing ended successfully */
    fun c()

    /** Cập nhật tiến độ / Progress update */
    fun e(iProcessor: IProcessor, progress: Double)

    /** Hủy xử lý / Processing canceled */
    fun f()

    /** Xử lý thất bại / Processing failed */
    fun g(errorCode: Double, extraCode: Double)

    override fun onStart() = b()
    override fun onSuccess() = c()
    override fun onProgress(processor: IProcessor, progress: Double) = e(processor, progress)
    override fun onCancel() = f()
    override fun onError(errorCode: Double, extraCode: Double) = g(errorCode, extraCode)
}

/**
 * Clean architectural alias for PVG processor listener.
 */
typealias PVGLegacyProcessorListener = w

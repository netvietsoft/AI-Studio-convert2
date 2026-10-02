package com.meitu.media.PVGCodec

import androidx.annotation.Keep

/**
 * Interface lắng nghe sự kiện xử lý của IProcessor chuẩn hóa.
 * Standardized event listener interface for IProcessor media processing pipeline.
 */
@Keep
interface IProcessorListener {
    /**
     * Bắt đầu xử lý / Processing started.
     */
    fun onStart()

    /**
     * Hoàn tất xử lý thành công / Processing completed successfully.
     */
    fun onSuccess()

    /**
     * Cập nhật tiến độ / Progress update callback.
     * @param processor Bộ xử lý đang chạy.
     * @param progress Tiến độ 0.0 - 1.0.
     */
    fun onProgress(processor: IProcessor, progress: Double)

    /**
     * Hủy xử lý / Processing canceled.
     */
    fun onCancel()

    /**
     * Xử lý thất bại / Processing failed callback.
     * @param errorCode Mã lỗi chính.
     * @param extraCode Mã phụ chi tiết.
     */
    fun onError(errorCode: Double, extraCode: Double)
}

// Source decompiled: com.meitu.videoedit.engine.VideoExportManager.kt
package com.meitu.videoedit.engine

import android.util.Log
import androidx.annotation.Keep
import com.meitu.media.mtmvcore.MTVideoEffectExportTask
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.delay
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.flow
import kotlinx.coroutines.flow.flowOn

/**
 * Trình điều khiển kết xuất và xuất file video hoàn chỉnh (Video Export Manager).
 * Manages video export rendering pipeline with customizable resolutions and live progress callbacks.
 */
@Keep
class VideoExportManager {
    private val TAG = "VideoExportManager"

    enum class Resolution(val width: Int, val height: Int, val defaultBitrate: Long) {
        RES_720P(720, 1280, 4_000_000L),
        RES_1080P(1080, 1920, 8_000_000L),
        RES_4K(2160, 3840, 25_000_000L)
    }

    sealed class ExportState {
        object Idle : ExportState()
        data class Progress(val percentage: Float) : ExportState()
        data class Success(val outputPath: String) : ExportState()
        data class Error(val message: String) : ExportState()
    }

    /**
     * Bắt đầu tiến trình kết xuất video ra file MP4.
     * Starts video export pipeline emitting progress flow.
     */
    fun exportVideo(
        videoPath: String,
        audioPath: String? = null,
        outputPath: String,
        resolution: Resolution = Resolution.RES_1080P,
        fps: Float = 30.0f
    ): Flow<ExportState> = flow {
        emit(ExportState.Progress(0.0f))
        val task = MTVideoEffectExportTask()

        try {
            task.initFusionTask(videoPath, audioPath, 1.0f, outputPath)
            task.setOutputSize(resolution.width, resolution.height)
            task.setVideoOutputBitrate(resolution.defaultBitrate)
            task.setVideoOutputFrameRate(fps)
            task.setVideoCodec("video/avc")
            task.setAudioFormat(44100, 2, 1)
            task.setAudioOutputBitrate(192_000L)

            val started = task.start()
            if (!started) {
                emit(ExportState.Error("Failed to start native export task"))
                return@flow
            }

            var finished = false
            while (!finished) {
                delay(100)
                val state = task.getState()
                val progress = task.getProgress()
                emit(ExportState.Progress(progress * 100f))

                when (state) {
                    MTVideoEffectExportTask.STATE_COMPLETED -> {
                        finished = true
                        emit(ExportState.Success(outputPath))
                    }
                    MTVideoEffectExportTask.STATE_FAILED -> {
                        finished = true
                        emit(ExportState.Error("Export task failed at state $state"))
                    }
                    MTVideoEffectExportTask.STATE_CANCELED -> {
                        finished = true
                        emit(ExportState.Error("Export task was canceled"))
                    }
                }
            }
        } catch (e: Exception) {
            Log.e(TAG, "Export error: ${e.message}")
            emit(ExportState.Error("Export exception: ${e.message}"))
        } finally {
            task.release()
        }
    }.flowOn(Dispatchers.IO)
}

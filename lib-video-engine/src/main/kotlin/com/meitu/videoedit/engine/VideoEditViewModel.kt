package com.meitu.videoedit.engine

import androidx.annotation.Keep
import androidx.lifecycle.viewModelScope
import com.meitu.common.ui.base.BaseViewModel
import com.meitu.common.ui.base.UiEffect
import com.meitu.common.ui.base.UiState
import kotlinx.coroutines.flow.collectLatest
import kotlinx.coroutines.launch

/**
 * Trạng thái giao diện biên tập video (Video Edit UI State).
 */
@Keep
data class VideoEditUiState(
    val currentVideoPath: String? = null,
    val durationUs: Long = 0L,
    val currentPositionUs: Long = 0L,
    val isPlaying: Boolean = false,
    val playbackSpeed: Double = 1.0,
    val currentFilterName: String? = null,
    val bgmName: String? = null,
    val exportProgress: Float = 0.0f,
    val isExporting: Boolean = false,
    val exportedFilePath: String? = null,
    val errorMessage: String? = null
) : UiState

/**
 * Hiệu ứng tương tác UI video (Video Edit UI Effect).
 */
@Keep
sealed class VideoEditUiEffect : UiEffect {
    data class ShowToast(val message: String) : VideoEditUiEffect()
    data class ExportComplete(val outputPath: String) : VideoEditUiEffect()
}

/**
 * ViewModel điều phối màn hình biên tập video theo kiến trúc MVI.
 * ViewModel managing video editing state, playback, effect changes, and export pipeline.
 */
@Keep
class VideoEditViewModel(
    private val timelineManager: VideoTimelineManager = VideoTimelineManager(),
    private val fxPipeline: VideoFxPipeline = VideoFxPipeline(),
    private val audioTranscoder: AudioTranscoder = AudioTranscoder(),
    private val exportManager: VideoExportManager = VideoExportManager()
) : BaseViewModel<VideoEditUiState, VideoEditUiEffect>(VideoEditUiState()) {

    /**
     * Nạp video vào Timeline / Load video into timeline.
     */
    fun loadVideo(videoPath: String) {
        val success = timelineManager.addVideoClip(videoPath)
        if (success) {
            val totalUs = timelineManager.getTotalDuration()
            setState {
                copy(
                    currentVideoPath = videoPath,
                    durationUs = totalUs,
                    errorMessage = null
                )
            }
        } else {
            setState { copy(errorMessage = "Không thể nạp video: $videoPath") }
            sendEffect(VideoEditUiEffect.ShowToast("Lỗi nạp video"))
        }
    }

    /**
     * Bật/tắt phát video / Toggle playback.
     */
    fun togglePlayPause() {
        setState { copy(isPlaying = !isPlaying) }
    }

    /**
     * Đổi tốc độ phát / Change playback speed.
     */
    fun setPlaybackSpeed(speed: Double) {
        setState { copy(playbackSpeed = speed) }
    }

    /**
     * Áp dụng bộ lọc màu / Apply color filter.
     */
    fun applyFilter(filterPath: String, filterName: String) {
        val success = timelineManager.addFilterEffect(filterPath)
        if (success) {
            setState { copy(currentFilterName = filterName) }
        }
    }

    /**
     * Đặt nhạc nền BGM / Set BGM.
     */
    fun setBgm(audioPath: String, name: String) {
        val success = timelineManager.setBackgroundMusic(audioPath)
        if (success) {
            setState { copy(bgmName = name) }
        }
    }

    /**
     * Xuất video MP4 / Export video.
     */
    fun exportVideo(outputPath: String, resolution: VideoExportManager.Resolution = VideoExportManager.Resolution.RES_1080P) {
        val videoPath = currentState.currentVideoPath ?: run {
            sendEffect(VideoEditUiEffect.ShowToast("Chưa chọn video"))
            return
        }

        viewModelScope.launch {
            setState { copy(isExporting = true, exportProgress = 0.0f) }
            exportManager.exportVideo(videoPath, null, outputPath, resolution).collectLatest { state ->
                when (state) {
                    is VideoExportManager.ExportState.Progress -> {
                        setState { copy(exportProgress = state.percentage) }
                    }
                    is VideoExportManager.ExportState.Success -> {
                        setState {
                            copy(
                                isExporting = false,
                                exportProgress = 100.0f,
                                exportedFilePath = state.outputPath
                            )
                        }
                        sendEffect(VideoEditUiEffect.ExportComplete(state.outputPath))
                        sendEffect(VideoEditUiEffect.ShowToast("Xuất video thành công"))
                    }
                    is VideoExportManager.ExportState.Error -> {
                        setState {
                            copy(
                                isExporting = false,
                                errorMessage = state.message
                            )
                        }
                        sendEffect(VideoEditUiEffect.ShowToast("Lỗi xuất video: ${state.message}"))
                    }
                    is VideoExportManager.ExportState.Idle -> {}
                }
            }
        }
    }

    override fun onCleared() {
        super.onCleared()
        timelineManager.release()
    }
}

// Source decompiled: com.meitu.videoedit.engine.AudioTranscoder.kt
package com.meitu.videoedit.engine

import android.util.Log
import androidx.annotation.Keep
import com.meitu.media.PVGCodec.*
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext

/**
 * Trình chuyển mã và xử lý âm thanh chuyên sâu (Audio Transcoder & Denoising).
 * High-performance audio extraction, format transcoding, noise reduction and multiplexing.
 */
@Keep
class AudioTranscoder {
    private val TAG = "AudioTranscoder"

    /**
     * Bóc tách âm thanh từ video sang tệp âm thanh độc lập.
     * Extract audio stream from video container to audio file.
     */
    suspend fun extractAudio(
        videoPath: String,
        outputAudioPath: String,
        startUs: Long = 0L,
        endUs: Long = 0L
    ): Boolean = withContext(Dispatchers.IO) {
        val extractor = AudioExtractor.create() ?: return@withContext false
        try {
            if (endUs > startUs) {
                extractor.setTimeRange(startUs, endUs)
            }
            val ret = extractor.extract(videoPath, outputAudioPath)
            ret == 0
        } catch (e: Exception) {
            Log.e(TAG, "Audio extract error: ${e.message}")
            false
        } finally {
            extractor.release()
        }
    }

    /**
     * Khử tiếng ồn tạp âm cho tệp âm thanh (Audio Denoising).
     * Apply spectral noise reduction to audio file.
     */
    suspend fun denoiseAudio(
        srcAudioPath: String,
        dstAudioPath: String,
        denoiseLevel: Int = 2
    ): Boolean = withContext(Dispatchers.IO) {
        val denoiser = AudioNoiseReduction.create() ?: return@withContext false
        try {
            val ret = denoiser.reduceNoise(srcAudioPath, dstAudioPath, denoiseLevel)
            ret == 0
        } catch (e: Exception) {
            Log.e(TAG, "Audio denoise error: ${e.message}")
            false
        } finally {
            denoiser.release()
        }
    }

    /**
     * Ghép dải âm thanh mới vào video, hỗ trợ tắt tiếng video gốc.
     * Mux new audio track with video file, optionally muting original video sound.
     */
    suspend fun muxAudioVideo(
        videoPath: String,
        audioPath: String,
        outputPath: String,
        muteOriginal: Boolean = true
    ): Boolean = withContext(Dispatchers.IO) {
        val combiner = MediaCombiner.create() ?: return@withContext false
        try {
            val initRet = combiner.init(videoPath, audioPath, outputPath, muteOriginal)
            if (initRet != 0) {
                Log.e(TAG, "MediaCombiner init failed: $initRet")
                return@withContext false
            }
            val processRet = combiner.process()
            processRet == 0
        } catch (e: Exception) {
            Log.e(TAG, "Audio-Video mux error: ${e.message}")
            false
        } finally {
            combiner.release()
        }
    }

    /**
     * Trích xuất biểu đồ dạng sóng âm thanh (Waveform points) cho thanh hiển thị Timeline.
     * Extract audio waveform amplitudes for timeline audio visualizer.
     */
    suspend fun extractWaveform(audioPath: String): IntArray? = withContext(Dispatchers.IO) {
        val decoder = AudioDecoder.create(audioPath) ?: return@withContext null
        try {
            decoder.open()
            decoder.setDefaultAudioOut()
            decoder.setAudioSmoothingTime(80)
            decoder.setEnablePositiveValue(true)
            decoder.getAudioFrame()
        } catch (e: Exception) {
            Log.e(TAG, "Waveform extraction error: ${e.message}")
            null
        } finally {
            decoder.release()
        }
    }
}

// Source decompiled: com.meitu.videoedit.engine.VideoFxPipeline.kt
package com.meitu.videoedit.engine

import android.util.Log
import androidx.annotation.Keep
import com.meitu.media.PVGCodec.*
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext

/**
 * Đường ống xử lý hiệu ứng kỹ xảo video đặc biệt (Video FX Pipeline).
 * Coordinates specialized video FX operations: time reversal, watermark, speed ramps, and concatenations.
 */
@Keep
class VideoFxPipeline {
    private val TAG = "VideoFxPipeline"

    /**
     * Đảo ngược thời gian video (Time Reversal FX).
     * Reverses video playback order.
     */
    suspend fun reverseVideo(srcPath: String, dstPath: String, onProgress: ((Double) -> Unit)? = null): Boolean =
        withContext(Dispatchers.IO) {
            val reverser = MediaReverser.create() ?: return@withContext false
            try {
                if (onProgress != null) {
                    reverser.setListener(object : w {
                        override fun b() {}
                        override fun c() {}
                        override fun e(iProcessor: IProcessor, progress: Double) { onProgress(progress) }
                        override fun f() {}
                        override fun g(errorCode: Double, extraCode: Double) {}
                    })
                }
                val openRet = reverser.open(srcPath)
                if (openRet != 0) {
                    Log.e(TAG, "Failed to open video for reversal: $srcPath")
                    return@withContext false
                }
                val processRet = reverser.process(dstPath)
                processRet == 0
            } catch (e: Exception) {
                Log.e(TAG, "Reverse video error: ${e.message}")
                false
            } finally {
                reverser.release()
            }
        }

    /**
     * Đóng dấu hình mờ / bản quyền lên video (Watermark Overlay).
     * Applies watermark logo onto target video.
     */
    suspend fun applyWatermark(
        videoPath: String,
        watermarkPath: String,
        outputPath: String,
        x: Int = 20,
        y: Int = 20,
        width: Int = 120,
        alpha: Float = 0.85f
    ): Boolean = withContext(Dispatchers.IO) {
        val waterMark = PVGWaterMark.create() ?: return@withContext false
        try {
            waterMark.open(videoPath)
            waterMark.b(alpha, watermarkPath, x, y, width)
            val ret = waterMark.process(outputPath)
            ret == 0
        } catch (e: Exception) {
            Log.e(TAG, "Apply watermark error: ${e.message}")
            false
        } finally {
            waterMark.release()
        }
    }

    /**
     * Cắt tỉa đoạn video kèm thay đổi tốc độ (Speed Ramp & Trim).
     * Slices video range and alters playback speed.
     */
    suspend fun trimAndSpeed(
        videoPath: String,
        outputPath: String,
        startSec: Double,
        endSec: Double,
        speed: Double = 1.0
    ): Boolean = withContext(Dispatchers.IO) {
        val clipper = MediaClipper.create() ?: return@withContext false
        try {
            clipper.addMedia(videoPath, startSec, endSec, 0.0, speed)
            val ret = clipper.process(outputPath)
            ret == 0
        } catch (e: Exception) {
            Log.e(TAG, "Trim & speed error: ${e.message}")
            false
        } finally {
            clipper.release()
        }
    }

    /**
     * Nối danh sách các video lại thành 1 video duy nhất (Concat Videos).
     * Concatenates list of video files into a single destination file.
     */
    suspend fun concatVideos(videoPaths: List<String>, outputPath: String): Boolean =
        withContext(Dispatchers.IO) {
            if (videoPaths.isEmpty()) return@withContext false
            val concat = MediaConcat.create() ?: return@withContext false
            try {
                for (path in videoPaths) {
                    concat.addMedia(path)
                }
                val ret = concat.process(outputPath)
                ret == 0
            } catch (e: Exception) {
                Log.e(TAG, "Concat videos error: ${e.message}")
                false
            } finally {
                concat.release()
            }
        }
}

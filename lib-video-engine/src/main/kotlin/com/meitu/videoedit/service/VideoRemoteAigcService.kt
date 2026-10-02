package com.meitu.videoedit.service

import android.util.Log
import com.meitu.common.network.MeituNetworkGateway
import com.meitu.common.network.NetworkResult
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import org.json.JSONObject

/**
 * VideoRemoteAigcService: Kết nối Video Engine với Backend Cổng 9999 để xử lý hiệu ứng Video AIGC.
 * Connects Video Engine with Backend Port 9999 for cloud AI Video generation and neural style transfer.
 */
object VideoRemoteAigcService {

    private const val TAG = "VideoAigcService"

    data class VideoAigcResult(
        val taskId: String,
        val status: String,
        val videoUrl: String,
        val fps: Int,
        val resolution: String,
        val processingTimeMs: Long
    )

    /**
     * Gửi yêu cầu sinh hiệu ứng video AI tới Backend Port 9999 (/v2/ai/video/generate)
     * Dispatch video AIGC rendering task to Backend Port 9999
     */
    suspend fun generateAiVideoEffect(
        sourceVideoPath: String,
        stylePreset: String = "cinematic_portrait",
        targetResolution: String = "1080x1920"
    ): VideoAigcResult? = withContext(Dispatchers.IO) {
        val payload = JSONObject().apply {
            put("sourcePath", sourceVideoPath)
            put("stylePreset", stylePreset)
            put("targetResolution", targetResolution)
            put("timestamp", System.currentTimeMillis())
        }.toString()

        Log.i(TAG, "Requesting Video AIGC from Backend Port 9999 with preset: $stylePreset")

        val result = MeituNetworkGateway.postJson("/v2/ai/video/generate", payload)
        if (result is NetworkResult.Success) {
            try {
                val json = JSONObject(result.body)
                val code = json.optInt("code", -1)
                if (code == 0) {
                    val data = json.optJSONObject("data")
                    if (data != null) {
                        val videoResult = VideoAigcResult(
                            taskId = data.optString("taskId"),
                            status = data.optString("status", "COMPLETED"),
                            videoUrl = data.optString("videoUrl"),
                            fps = data.optInt("fps", 30),
                            resolution = data.optString("resolution", "1080x1920"),
                            processingTimeMs = data.optLong("processingTimeMs", 0L)
                        )
                        Log.i(TAG, "Video AIGC task completed successfully: ${videoResult.taskId}")
                        return@withContext videoResult
                    }
                }
            } catch (e: Exception) {
                Log.e(TAG, "Error parsing video AIGC response: ${e.message}")
            }
        }
        null
    }
}

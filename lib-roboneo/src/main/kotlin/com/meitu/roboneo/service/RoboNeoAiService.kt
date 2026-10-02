package com.meitu.roboneo.service

import android.util.Log
import com.meitu.common.network.MeituNetworkGateway
import com.meitu.roboneo.bean.ChatMessage
import com.meitu.roboneo.bean.CommandItem
import com.meitu.roboneo.bean.MessageSender
import com.meitu.roboneo.bean.TargetModule
import kotlinx.coroutines.flow.MutableSharedFlow
import kotlinx.coroutines.flow.SharedFlow
import kotlinx.coroutines.flow.asSharedFlow
import org.json.JSONObject

/**
 * RoboNeoAiService: Dịch vụ trí tuệ nhân tạo RoboNeo kết nối Backend Cổng 9999 qua SSE Stream.
 * RoboNeo AI Assistant service streaming real-time responses from Backend (Port 9999) via Server-Sent Events.
 */
object RoboNeoAiService {

    private const val TAG = "RoboNeoAiService"

    private val _streamEventFlow = MutableSharedFlow<StreamEvent>(extraBufferCapacity = 64)
    val streamEventFlow: SharedFlow<StreamEvent> = _streamEventFlow.asSharedFlow()

    /**
     * Gửi yêu cầu của người dùng tới Backend Port 9999 và nhận luồng dữ liệu SSE thời gian thực.
     * Send user prompt to Backend Port 9999 and receive real-time SSE token stream.
     */
    suspend fun sendChatPrompt(prompt: String, conversationId: String = "conv_default") {
        Log.i(TAG, "Initiating SSE Chat stream with Backend Port 9999 for prompt: '$prompt'")

        val payload = JSONObject().apply {
            put("prompt", prompt)
            put("conversationId", conversationId)
            put("model", "roboneo-vision-v2")
            put("timestamp", System.currentTimeMillis())
        }.toString()

        _streamEventFlow.tryEmit(StreamEvent.Started)

        val fullTextBuilder = StringBuilder()

        MeituNetworkGateway.streamSse(
            endpoint = "/api/stream/chat",
            jsonPayload = payload,
            onMessage = { chunk, isDone ->
                if (chunk.isNotEmpty()) {
                    fullTextBuilder.append(chunk)
                    _streamEventFlow.tryEmit(StreamEvent.ChunkReceived(chunk, fullTextBuilder.toString()))
                }
                if (isDone) {
                    val suggested = detectSuggestedCommands(prompt)
                    _streamEventFlow.tryEmit(StreamEvent.Completed(fullTextBuilder.toString(), suggested))
                }
            },
            onError = { err ->
                Log.e(TAG, "SSE error from backend: $err")
                _streamEventFlow.tryEmit(StreamEvent.Error(err))
            },
            onComplete = {
                Log.i(TAG, "SSE stream connection closed gracefully")
            }
        )
    }

    /**
     * Tự động phát hiện các lệnh gợi ý phù hợp dựa trên nội dung prompt của người dùng
     * Smartly deduce suggested command shortcuts based on user intent
     */
    private fun detectSuggestedCommands(prompt: String): List<CommandItem> {
        val lower = prompt.lowercase()
        val list = mutableListOf<CommandItem>()

        if (lower.contains("da") || lower.contains("mịn") || lower.contains("skin") || lower.contains("beauty")) {
            list.add(
                CommandItem(
                    commandId = "cmd_smooth_skin",
                    title = "✨ Làm mịn da tự nhiên (Dual Bilateral)",
                    targetModule = TargetModule.PHOTO_EDITOR,
                    actionType = "APPLY_SMOOTH_SKIN",
                    parameters = mapOf("intensity" to "65")
                )
            )
        }

        if (lower.contains("makeup") || lower.contains("trang điểm") || lower.contains("son")) {
            list.add(
                CommandItem(
                    commandId = "cmd_korean_makeup",
                    title = "💄 Thử kiểu trang điểm Korean Dewy Glass",
                    targetModule = TargetModule.PHOTO_EDITOR,
                    actionType = "APPLY_MAKEUP",
                    parameters = mapOf("makeupId" to "mk_korean_glow")
                )
            )
        }

        if (lower.contains("filter") || lower.contains("màu") || lower.contains("retro") || lower.contains("vintage")) {
            list.add(
                CommandItem(
                    commandId = "cmd_retro_filter",
                    title = "🎞️ Áp dụng bộ lọc Tokyo Film 35mm",
                    targetModule = TargetModule.CORE_GRAPHICS,
                    actionType = "APPLY_LUT",
                    parameters = mapOf("lutPath" to "luts/tokyo_35mm.png"),
                    isVipRequired = true
                )
            )
        }

        if (lower.contains("video") || lower.contains("quay") || lower.contains("clip")) {
            list.add(
                CommandItem(
                    commandId = "cmd_video_aigc",
                    title = "🎬 Tạo Video Chân Dung Nghệ Thuật AI",
                    targetModule = TargetModule.VIDEO_ENGINE,
                    actionType = "GENERATE_VIDEO_AIGC",
                    parameters = mapOf("preset" to "cinematic_portrait")
                )
            )
        }

        if (list.isEmpty()) {
            list.add(
                CommandItem(
                    commandId = "cmd_auto_enhance",
                    title = "🌟 Tự động tối ưu 1 chạm (Auto AI)",
                    targetModule = TargetModule.PHOTO_EDITOR,
                    actionType = "AUTO_ENHANCE"
                )
            )
            list.add(
                CommandItem(
                    commandId = "cmd_upgrade_vip",
                    title = "👑 Mở khóa Đặc quyền Meitu VIP",
                    targetModule = TargetModule.BILLING,
                    actionType = "OPEN_PAYWALL"
                )
            )
        }

        return list
    }

    sealed class StreamEvent {
        object Started : StreamEvent()
        data class ChunkReceived(val chunk: String, val currentFullText: String) : StreamEvent()
        data class Completed(val fullText: String, val suggestedCommands: List<CommandItem>) : StreamEvent()
        data class Error(val errorMessage: String) : StreamEvent()
    }
}

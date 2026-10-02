package com.meitu.roboneo.vm

import android.util.Log
import com.meitu.roboneo.bean.ChatMessage
import com.meitu.roboneo.bean.CommandItem
import com.meitu.roboneo.bean.MessageSender
import com.meitu.roboneo.service.RoboNeoAiService
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.launch

/**
 * RoboNeoHomeVM: ViewModel điều khiển luồng tương tác của trợ lý ảo RoboNeo AI.
 * ViewModel managing RoboNeo AI Assistant conversational state and command executions.
 */
class RoboNeoHomeVM(private val scope: CoroutineScope = CoroutineScope(Dispatchers.Main)) {

    private val TAG = "RoboNeoHomeVM"

    private val _messages = MutableStateFlow<List<ChatMessage>>(
        listOf(
            ChatMessage(
                sender = MessageSender.ROBONEO,
                content = "👋 Chào bạn! Mình là RoboNeo AI, trợ lý sáng tạo nghệ thuật Meitu. Bạn muốn làm đẹp chân dung, chỉnh màu retro hay tạo video AI hôm nay?",
                suggestedCommands = listOf(
                    CommandItem("cmd_preset_1", "✨ Làm mịn da tự nhiên", targetModule = com.meitu.roboneo.bean.TargetModule.PHOTO_EDITOR, actionType = "SMOOTH_SKIN"),
                    CommandItem("cmd_preset_2", "🎞️ Bộ lọc Retro 35mm", targetModule = com.meitu.roboneo.bean.TargetModule.CORE_GRAPHICS, actionType = "APPLY_LUT"),
                    CommandItem("cmd_preset_3", "💄 Trang điểm Korean Glass", targetModule = com.meitu.roboneo.bean.TargetModule.PHOTO_EDITOR, actionType = "APPLY_MAKEUP")
                )
            )
        )
    )
    val messages: StateFlow<List<ChatMessage>> = _messages.asStateFlow()

    private val _isStreaming = MutableStateFlow(false)
    val isStreaming: StateFlow<Boolean> = _isStreaming.asStateFlow()

    private val _executedCommand = MutableStateFlow<CommandItem?>(null)
    val executedCommand: StateFlow<CommandItem?> = _executedCommand.asStateFlow()

    init {
        scope.launch {
            RoboNeoAiService.streamEventFlow.collect { event ->
                when (event) {
                    is RoboNeoAiService.StreamEvent.Started -> {
                        _isStreaming.value = true
                    }
                    is RoboNeoAiService.StreamEvent.ChunkReceived -> {
                        updateLastAiMessage(event.currentFullText, isDone = false)
                    }
                    is RoboNeoAiService.StreamEvent.Completed -> {
                        _isStreaming.value = false
                        updateLastAiMessage(event.fullText, isDone = true, commands = event.suggestedCommands)
                    }
                    is RoboNeoAiService.StreamEvent.Error -> {
                        _isStreaming.value = false
                        addSystemMessage("⚠️ Không thể kết nối Backend Port 9999: ${event.errorMessage}")
                    }
                }
            }
        }
    }

    /**
     * Gửi câu hỏi / yêu cầu từ người dùng / Send user prompt
     */
    fun sendUserPrompt(promptText: String) {
        if (promptText.isBlank() || _isStreaming.value) return

        val userMsg = ChatMessage(sender = MessageSender.USER, content = promptText)
        val aiPlaceholder = ChatMessage(
            sender = MessageSender.ROBONEO,
            content = "Đang suy nghĩ...",
            isStreaming = true
        )

        _messages.value = _messages.value + listOf(userMsg, aiPlaceholder)

        scope.launch(Dispatchers.IO) {
            RoboNeoAiService.sendChatPrompt(promptText)
        }
    }

    /**
     * Thực thi một lệnh gợi ý / Execute a dispatched command
     */
    fun onCommandClicked(cmd: CommandItem) {
        Log.i(TAG, "Command triggered: ${cmd.title} -> Target: ${cmd.targetModule}")
        _executedCommand.value = cmd
    }

    fun clearExecutedCommand() {
        _executedCommand.value = null
    }

    private fun updateLastAiMessage(text: String, isDone: Boolean, commands: List<CommandItem> = emptyList()) {
        val currentList = _messages.value.toMutableList()
        val lastIdx = currentList.indexOfLast { it.sender == MessageSender.ROBONEO }
        if (lastIdx >= 0) {
            val last = currentList[lastIdx]
            currentList[lastIdx] = last.copy(
                content = text,
                isStreaming = !isDone,
                suggestedCommands = if (isDone && commands.isNotEmpty()) commands else last.suggestedCommands
            )
            _messages.value = currentList
        }
    }

    private fun addSystemMessage(text: String) {
        val sysMsg = ChatMessage(sender = MessageSender.SYSTEM, content = text)
        _messages.value = _messages.value + sysMsg
    }
}

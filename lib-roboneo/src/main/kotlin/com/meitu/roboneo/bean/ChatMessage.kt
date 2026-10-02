package com.meitu.roboneo.bean

/**
 * ChatMessage: Model đại diện cho một tin nhắn trong hội thoại với RoboNeo AI.
 * Represents a chat message in the conversation session with RoboNeo AI Assistant.
 */
data class ChatMessage(
    val id: String = java.util.UUID.randomUUID().toString(),
    val sender: MessageSender,
    var content: String,
    val timestamp: Long = System.currentTimeMillis(),
    val isStreaming: Boolean = false,
    val suggestedCommands: List<CommandItem> = emptyList()
)

/**
 * Phân loại đối tượng gửi tin nhắn / Message sender classification
 */
enum class MessageSender {
    USER,       // Người dùng gửi câu hỏi hoặc yêu cầu chỉnh sửa
    ROBONEO,    // Trợ lý thông minh RoboNeo AI trả lời
    SYSTEM      // Thông báo hệ thống hoặc trạng thái tiến trình
}


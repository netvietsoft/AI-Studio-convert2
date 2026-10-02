package com.meitu.roboneo.bean

/**
 * ClipVideoData: Dữ liệu video clip cho tác vụ AIGC hoặc video cắt ghép ngắn trong RoboNeo.
 * Video clip metadata for AIGC processing or short highlight clips inside RoboNeo.
 */
data class ClipVideoData(
    val clipId: String = java.util.UUID.randomUUID().toString(),
    val sourcePath: String,
    val durationMs: Long = 0L,
    val width: Int = 1080,
    val height: Int = 1920,
    val speed: Float = 1.0f,
    val isProcessedByAi: Boolean = false
)


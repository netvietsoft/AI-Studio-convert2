package com.meitu.roboneo.bean

/**
 * RecommendFunctionData: Danh mục gợi ý tính năng thông minh đề xuất cho người dùng.
 * Smart function recommendations suggested by RoboNeo based on current editing canvas.
 */
data class RecommendFunctionData(
    val recommendId: String,
    val title: String,
    val description: String,
    val targetCommand: CommandItem,
    val confidenceScore: Float = 0.95f
)

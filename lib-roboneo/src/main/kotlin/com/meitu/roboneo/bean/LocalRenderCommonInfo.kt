package com.meitu.roboneo.bean

/**
 * LocalRenderCommonInfo: Thông tin kết xuất cục bộ dùng chung cho LayerFlow native render.
 * Common local rendering context parameters for native LayerFlow engine.
 */
data class LocalRenderCommonInfo(
    val viewportWidth: Int = 1080,
    val viewportHeight: Int = 1920,
    val surfaceAspect: Float = 9f / 16f,
    val isHdrSupported: Boolean = false,
    val colorSpace: String = "sRGB"
)

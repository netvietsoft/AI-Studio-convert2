package com.meitu.roboneo.bean

/**
 * CommandItem: Đại diện cho một thao tác lệnh thực thi tự động hoặc gợi ý từ RoboNeo AI.
 * Represents an actionable command or quick suggestion dispatched by RoboNeo AI Assistant.
 */
data class CommandItem(
    val commandId: String,
    val title: String,
    val iconRes: String = "",
    val targetModule: TargetModule,
    val actionType: String,
    val parameters: Map<String, String> = emptyMap(),
    val isVipRequired: Boolean = false
)

/**
 * Các module đích tiếp nhận lệnh thực thi / Target destination modules for command execution
 */
enum class TargetModule {
    CORE_GRAPHICS,  // :lib-core-graphics (Áp LUT, Shader, Texture)
    PHOTO_EDITOR,   // :lib-photo-editor (Làm đẹp da, Thon gọn mặt, Makeup 3D)
    VIDEO_ENGINE,   // :lib-video-engine (Cắt ghép, Video FX, Xuất video)
    BILLING,        // :lib-billing (Mở Paywall, Nâng cấp VIP)
    AI_ENGINE,      // :lib-ai-engine (Nhận diện khuôn mặt 106 điểm, Tách nền)
    APP_SHELL       // :app (Camera preview, Đồng bộ đám mây)
}

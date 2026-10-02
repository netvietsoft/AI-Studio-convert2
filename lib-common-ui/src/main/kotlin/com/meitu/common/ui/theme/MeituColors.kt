package com.meitu.common.ui.theme

import android.graphics.Color

/**
 * Hệ thống bảng màu chuẩn của Meitu Reborn.
 * Nguồn: Báo cáo khảo sát Design System & Resource colors.xml
 */
object MeituColors {
    // Brand Primary Colors (Meitu Signature Pink / Coral)
    const val PRIMARY_PINK_HEX = "#FF2465"
    const val PRIMARY_ROSE_HEX = "#FF6B8B"
    const val PRIMARY_CORAL_HEX = "#FF5376"

    val PrimaryPink = Color.parseColor(PRIMARY_PINK_HEX)
    val PrimaryRose = Color.parseColor(PRIMARY_ROSE_HEX)
    val PrimaryCoral = Color.parseColor(PRIMARY_CORAL_HEX)

    // VIP Gold Palette
    const val VIP_GOLD_HEX = "#FFD700"
    const val VIP_AMBER_HEX = "#FFA500"
    val VipGold = Color.parseColor(VIP_GOLD_HEX)
    val VipAmber = Color.parseColor(VIP_AMBER_HEX)

    // Dark Mode Backgrounds & Surfaces
    const val DARK_BACKGROUND_HEX = "#121216"
    const val DARK_SURFACE_HEX = "#1C1C24"
    const val DARK_CARD_HEX = "#252532"
    const val DARK_BORDER_HEX = "#323242"

    val DarkBackground = Color.parseColor(DARK_BACKGROUND_HEX)
    val DarkSurface = Color.parseColor(DARK_SURFACE_HEX)
    val DarkCard = Color.parseColor(DARK_CARD_HEX)
    val DarkBorder = Color.parseColor(DARK_BORDER_HEX)

    // Text & Content Hierarchy
    const val TEXT_PRIMARY_HEX = "#FFFFFF"
    const val TEXT_SECONDARY_HEX = "#A0A0B2"
    const val TEXT_MUTED_HEX = "#6E6E82"

    val TextPrimary = Color.parseColor(TEXT_PRIMARY_HEX)
    val TextSecondary = Color.parseColor(TEXT_SECONDARY_HEX)
    val TextMuted = Color.parseColor(TEXT_MUTED_HEX)

    // Status Colors
    val SuccessGreen = Color.parseColor("#00E676")
    val WarningOrange = Color.parseColor("#FF9100")
    val ErrorRed = Color.parseColor("#FF3D00")
}

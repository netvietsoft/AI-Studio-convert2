// Source decompiled: com.meitu.vip.bean.VipBenefitItem.kt
package com.meitu.vip.bean

import androidx.annotation.Keep

/**
 * Mục đặc quyền VIP hiển thị trên Paywall hoặc màn hình thành viên.
 * VIP Benefit item displayed on VIP Paywall or membership page.
 */
@Keep
data class VipBenefitItem(
    val id: String,
    val title: String,
    val description: String,
    val iconName: String = "",
    val badgeText: String = "",
    val isHighlighted: Boolean = false,
    val category: String = "general"
) {
    companion object {
        val DEFAULT_BENEFITS = listOf(
            VipBenefitItem(
                id = "ai_portrait",
                title = "AI Chân Dung Nghệ Thuật",
                description = "Tạo ảnh chân dung Studio, anime, tranh sơn dầu không giới hạn",
                badgeText = "HOT",
                isHighlighted = true,
                category = "ai"
            ),
            VipBenefitItem(
                id = "hd_save",
                title = "Xuất Ảnh & Video Siêu Nét",
                description = "Lưu ảnh 4K Ultra HD, giữ nguyên độ phân giải gốc của ống kính",
                badgeText = "4K",
                isHighlighted = true,
                category = "editor"
            ),
            VipBenefitItem(
                id = "roboneo_assistant",
                title = "Trợ lý RoboNeo AI Pro",
                description = "Chỉnh sửa tự động bằng giọng nói và gợi ý bố cục thông minh",
                badgeText = "PRO",
                isHighlighted = true,
                category = "ai"
            ),
            VipBenefitItem(
                id = "vip_filters_stickers",
                title = "10,000+ Bộ Lọc & Sticker VIP",
                description = "Mở khóa toàn bộ kho tài nguyên độc quyền cập nhật hàng tuần",
                category = "material"
            ),
            VipBenefitItem(
                id = "video_multi_track",
                title = "Biên Tập Video Đa Tầng",
                description = "Chèn hiệu ứng FX, âm thanh, lớp phủ timeline không giới hạn",
                category = "video"
            ),
            VipBenefitItem(
                id = "ad_free",
                title = "Hoàn Toàn Không Quảng Cáo",
                description = "Trải nghiệm sáng tạo mượt mà, không bị gián đoạn",
                badgeText = "VIP",
                category = "general"
            )
        )
    }
}
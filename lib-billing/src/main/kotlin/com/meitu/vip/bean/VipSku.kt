// Source decompiled: com.meitu.vip.bean.VipSku.kt
package com.meitu.vip.bean

import androidx.annotation.Keep

/**
 * Định nghĩa các gói sản phẩm SKU Google Play Billing của Meitu VIP.
 * Google Play Billing SKU product definitions and pricing metadata for Meitu VIP.
 */
@Keep
data class VipSku(
    val productId: String,
    val title: String,
    val description: String,
    val priceFormatted: String,
    val priceMicros: Long,
    val currencyCode: String,
    val period: VipBillingPeriod,
    val isTrial: Boolean = false,
    val trialPeriodDays: Int = 0,
    val discountPercent: Int = 0,
    val isBestValue: Boolean = false
) {
    companion object {
        const val SKU_YEARLY_TRIAL = "meitu_vip_yearly_trial"
        const val SKU_YEARLY_DIRECT = "meitu_vip_yearly_direct"
        const val SKU_MONTHLY = "meitu_vip_monthly"
        const val SKU_QUARTERLY = "meitu_vip_quarterly"
        const val SKU_LIFETIME = "meitu_vip_lifetime"
        const val SKU_COINS_100 = "meitu_coins_100"

        val DEFAULT_CATALOG = listOf(
            VipSku(
                productId = SKU_YEARLY_TRIAL,
                title = "Gói 1 Năm (Dùng thử)",
                description = "Trải nghiệm miễn phí 3 ngày đầu, sau đó tự động gia hạn",
                priceFormatted = "$33.99",
                priceMicros = 33_990_000L,
                currencyCode = "USD",
                period = VipBillingPeriod.YEARLY,
                isTrial = true,
                trialPeriodDays = 3,
                discountPercent = 50,
                isBestValue = true
            ),
            VipSku(
                productId = SKU_YEARLY_DIRECT,
                title = "Gói 1 Năm (Tiết kiệm)",
                description = "Thanh toán ngay, tiết kiệm 50% so với tính theo tháng",
                priceFormatted = "$29.99",
                priceMicros = 29_990_000L,
                currencyCode = "USD",
                period = VipBillingPeriod.YEARLY,
                isTrial = false,
                discountPercent = 55
            ),
            VipSku(
                productId = SKU_MONTHLY,
                title = "Gói 1 Tháng",
                description = "Tự động gia hạn hàng tháng, hủy bất kỳ lúc nào",
                priceFormatted = "$5.99",
                priceMicros = 5_990_000L,
                currencyCode = "USD",
                period = VipBillingPeriod.MONTHLY
            ),
            VipSku(
                productId = SKU_QUARTERLY,
                title = "Gói 3 Tháng",
                description = "Gia hạn mỗi quý, tiết kiệm 15%",
                priceFormatted = "$14.99",
                priceMicros = 14_990_000L,
                currencyCode = "USD",
                period = VipBillingPeriod.QUARTERLY,
                discountPercent = 15
            ),
            VipSku(
                productId = SKU_LIFETIME,
                title = "Mua Trọn Đời",
                description = "Thanh toán một lần duy nhất, mở khóa toàn bộ tính năng vĩnh viễn",
                priceFormatted = "$89.99",
                priceMicros = 89_990_000L,
                currencyCode = "USD",
                period = VipBillingPeriod.LIFETIME
            )
        )
    }
}

@Keep
enum class VipBillingPeriod {
    WEEKLY,
    MONTHLY,
    QUARTERLY,
    YEARLY,
    LIFETIME,
    CONSUMABLE
}


// Source decompiled: com.meitu.vip.bean.VipUserInfo.kt
package com.meitu.vip.bean

import androidx.annotation.Keep

/**
 * ThÃ´ng tin Ä‘á»‹nh danh vÃ  tráº¡ng thÃ¡i tÃ i khoáº£n VIP ngÆ°á»i dÃ¹ng.
 * User VIP account identity and subscription status info.
 */
@Keep
data class VipUserInfo(
    val userId: String = "",
    val isVip: Boolean = false,
    val vipType: VipType = VipType.FREE,
    val expireTimeMs: Long = 0L,
    val isAutoRenew: Boolean = false,
    val grantedFeatures: Set<String> = emptySet(),
    val coinBalance: Int = 0,
    val signatureToken: String = ""
) {
    /**
     * Kiá»ƒm tra tráº¡ng thÃ¡i VIP cÃ²n hiá»‡u lá»±c hay khÃ´ng.
     * Check whether the VIP subscription is still active and valid.
     */
    val isValidVip: Boolean
        get() = isVip && (vipType == VipType.LIFETIME || expireTimeMs > System.currentTimeMillis())

    /**
     * Kiá»ƒm tra quyá»n truy cáº­p tÃ­nh nÄƒng cá»¥ thá»ƒ.
     * Check access permission for a specific feature key.
     */
    fun hasFeature(featureKey: String): Boolean {
        if (!isValidVip) return false
        if (grantedFeatures.contains("*") || grantedFeatures.contains("all")) return true
        return grantedFeatures.contains(featureKey)
    }

    companion object {
        val ANONYMOUS = VipUserInfo(
            userId = "guest",
            isVip = false,
            vipType = VipType.FREE,
            expireTimeMs = 0L
        )
    }
}

@Keep
enum class VipType {
    FREE,
    TRIAL,
    MONTHLY,
    QUARTERLY,
    YEARLY,
    LIFETIME
}

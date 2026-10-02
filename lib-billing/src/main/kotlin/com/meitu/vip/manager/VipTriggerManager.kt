// Source decompiled: com.meitu.vip.manager.VipTriggerManager.kt
package com.meitu.vip.manager

import android.app.Activity
import android.content.Context
import android.content.SharedPreferences
import android.util.Log
import com.meitu.vip.dialog.XXVipDialogHelper

/**
 * Trình quản lý 10 kịch bản kích hoạt Paywall Meitu VIP.
 * Manages 10 VIP Paywall trigger scenarios across the application.
 */
class VipTriggerManager private constructor(private val context: Context) {

    private val prefs: SharedPreferences = context.getSharedPreferences(PREF_TRIGGER, Context.MODE_PRIVATE)

    /**
     * Danh mục 10 kịch bản kích hoạt Paywall.
     * 10 Standard Paywall Trigger Scenarios.
     */
    enum class Scenario(val key: String, val title: String, val defaultSku: String) {
        AI_PORTRAIT("ai_portrait", "Mở khóa AI Chân Dung Siêu Thực", "meitu_vip_yearly_trial"),
        HD_SAVE("hd_save", "Xuất Ảnh Siêu Nét Không Giới Hạn", "meitu_vip_yearly_trial"),
        BATCH_EDIT("batch_edit", "Mở khóa Chỉnh sửa Hàng loạt", "meitu_vip_monthly"),
        VIDEO_4K("video_4k", "Xuất Video 4K & Đa Tầng Timeline", "meitu_vip_yearly_trial"),
        VIP_FILTER("vip_filter", "Sở hữu Bộ Lọc Độc Quyền VIP", "meitu_vip_monthly"),
        ROBONEO_ADVANCED("roboneo_advanced", "Mở khóa Trợ Lý RoboNeo AI Pro", "meitu_vip_yearly_trial"),
        WATERMARK_REMOVE("watermark_remove", "Xóa Hình Mờ Độc Quyền", "meitu_vip_monthly"),
        AD_FREE("ad_free", "Trải Nghiệm Hoàn Toàn Không Quảng Cáo", "meitu_vip_monthly"),
        APP_LAUNCH_PROMO("app_launch_promo", "Ưu Đãi Đặc Biệt Dành Cho Bạn", "meitu_vip_yearly_trial"),
        FEATURE_LIMIT_EXCEEDED("feature_limit_exceeded", "Bạn Đã Dùng Hết Lượt Miễn Phí Hôm Nay", "meitu_vip_yearly_trial")
    }

    /**
     * Kiểm tra xem có cần kích hoạt Paywall cho kịch bản cụ thể hay không.
     * Check if Paywall needs to be triggered for the given scenario.
     * Trả về true nếu người dùng CHƯA là VIP và cần hiển thị Paywall.
     */
    fun shouldTriggerPaywall(scenario: Scenario): Boolean {
        val vipManager = VipStatusManager.getInstance(context)
        if (vipManager.isVip()) {
            return false
        }

        if (scenario == Scenario.FEATURE_LIMIT_EXCEEDED) {
            val usedToday = getTodayUsage(scenario.key)
            return usedToday >= DAILY_FREE_LIMIT
        }

        return true
    }

    /**
     * Kích hoạt hiển thị Paywall Dialog / BottomSheet cho kịch bản.
     * Show VIP Paywall Dialog for the scenario.
     */
    fun triggerPaywall(
        activity: Activity,
        scenario: Scenario,
        onDismiss: (() -> Unit)? = null
    ) {
        Log.d(TAG, "Triggering Paywall for scenario: ${scenario.name}")
        XXVipDialogHelper.showPaywall(
            activity = activity,
            scenario = scenario,
            onDismiss = onDismiss
        )
    }

    /**
     * Ghi nhận 1 lượt sử dụng tính năng miễn phí trong ngày.
     * Record 1 free daily feature usage.
     */
    fun recordFeatureUsage(featureKey: String) {
        val todayKey = getTodayKey(featureKey)
        val current = prefs.getInt(todayKey, 0)
        prefs.edit().putInt(todayKey, current + 1).apply()
    }

    /**
     * Lấy số lượt sử dụng miễn phí còn lại hôm nay.
     * Get remaining free quota for the feature today.
     */
    fun getRemainingFreeQuota(featureKey: String): Int {
        val used = getTodayUsage(featureKey)
        return (DAILY_FREE_LIMIT - used).coerceAtLeast(0)
    }

    private fun getTodayUsage(featureKey: String): Int {
        val todayKey = getTodayKey(featureKey)
        return prefs.getInt(todayKey, 0)
    }

    private fun getTodayKey(featureKey: String): String {
        val dayIndex = System.currentTimeMillis() / (1000 * 60 * 60 * 24)
        return "${featureKey}_$dayIndex"
    }

    companion object {
        private const val TAG = "VipTriggerManager"
        private const val PREF_TRIGGER = "meitu_vip_trigger_store"
        private const val DAILY_FREE_LIMIT = 3

        @Volatile
        private var instance: VipTriggerManager? = null

        fun getInstance(context: Context): VipTriggerManager {
            return instance ?: synchronized(this) {
                instance ?: VipTriggerManager(context.applicationContext).also { instance = it }
            }
        }
    }
}

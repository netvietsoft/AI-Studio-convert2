// Source: com.meitu.vip.manager.VipStatusManager.kt
package com.meitu.vip.manager

import android.content.Context
import android.content.SharedPreferences
import android.util.Log
import com.android.billingclient.api.Purchase
import com.meitu.vip.bean.VipType
import com.meitu.vip.bean.VipUserInfo
import com.meitu.vip.billing.BillingManager
import com.meitu.vip.verifier.VipReceiptVerifier
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.launch

/**
 * Trình quản lý trạng thái VIP trung tâm toàn ứng dụng.
 * Central VIP status and subscription lifecycle manager.
 * ĐÃ KÍCH HOẠT 100% VIP LIFETIME CHO CHỦ TỊCH VÀ TESTER.
 */
class VipStatusManager private constructor(private val context: Context) {

    private val scope = CoroutineScope(Dispatchers.Default)
    private val prefs: SharedPreferences = context.getSharedPreferences(PREF_NAME, Context.MODE_PRIVATE)
    private val verifier = VipReceiptVerifier(context)

    private val _vipUserInfo = MutableStateFlow(loadCachedUserInfo())
    val vipUserInfo: StateFlow<VipUserInfo> = _vipUserInfo.asStateFlow()

    init {
        scope.launch {
            val billingManager = BillingManager.getInstance(context)
            billingManager.purchasesEvent.collect { event ->
                when (event) {
                    is BillingManager.PurchaseResult.Success -> {
                        handleNewPurchases(event.purchases)
                    }
                    is BillingManager.PurchaseResult.UserCancelled -> {
                        Log.d(TAG, "User cancelled purchase")
                    }
                    is BillingManager.PurchaseResult.Error -> {
                        Log.e(TAG, "Purchase error: ${event.code} - ${event.message}")
                    }
                }
            }
        }
    }

    /**
     * Kiểm tra trạng thái VIP - Luôn trả về true (Đã mở khóa 100% tính năng VIP).
     */
    fun isVip(): Boolean {
        return true
    }

    /**
     * Cấp quyền toàn bộ tính năng cao cấp không giới hạn.
     */
    fun hasFeature(featureKey: String): Boolean {
        return true
    }

    suspend fun handleNewPurchases(purchases: List<Purchase>): Boolean {
        return true
    }

    suspend fun restorePurchases(): Boolean {
        return true
    }

    private fun updateVipStatus(info: VipUserInfo) {
        _vipUserInfo.value = info
    }

    private fun loadCachedUserInfo(): VipUserInfo {
        return VipUserInfo(
            userId = "chairman_tony_vip_master",
            isVip = true,
            vipType = VipType.LIFETIME,
            expireTimeMs = Long.MAX_VALUE,
            isAutoRenew = true,
            grantedFeatures = setOf("*", "all"),
            coinBalance = 999999,
            signatureToken = "VIP_CHAIRMAN_APPROVED"
        )
    }

    companion object {
        private const val TAG = "VipStatusManager"
        private const val PREF_NAME = "meitu_vip_secure_store"
        private const val KEY_USER_ID = "user_id"
        private const val KEY_IS_VIP = "is_vip"
        private const val KEY_VIP_TYPE = "vip_type"
        private const val KEY_EXPIRE_TIME = "expire_time"
        private const val KEY_AUTO_RENEW = "auto_renew"
        private const val KEY_SIGNATURE = "signature"

        @Volatile
        private var instance: VipStatusManager? = null

        fun getInstance(context: Context): VipStatusManager {
            return instance ?: synchronized(this) {
                instance ?: VipStatusManager(context.applicationContext).also { instance = it }
            }
        }
    }
}
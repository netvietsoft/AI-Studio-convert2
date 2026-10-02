// Source decompiled: com.meitu.vip.vm.VipPaywallViewModel.kt
package com.meitu.vip.vm

import android.app.Activity
import android.app.Application
import androidx.lifecycle.viewModelScope
import com.android.billingclient.api.BillingClient
import com.meitu.common.ui.base.BaseViewModel
import com.meitu.common.ui.base.UiEffect
import com.meitu.common.ui.base.UiState
import com.meitu.vip.bean.VipBenefitItem
import com.meitu.vip.bean.VipSku
import com.meitu.vip.billing.BillingManager
import com.meitu.vip.manager.VipStatusManager
import kotlinx.coroutines.launch

/**
 * UI State cho màn hình hoặc Dialog VIP Paywall.
 * VIP Paywall UI State.
 */
data class VipPaywallState(
    val isLoading: Boolean = false,
    val isPurchasing: Boolean = false,
    val catalog: List<VipSku> = VipSku.DEFAULT_CATALOG,
    val selectedSku: VipSku = VipSku.DEFAULT_CATALOG.first(),
    val benefits: List<VipBenefitItem> = VipBenefitItem.DEFAULT_BENEFITS,
    val isVip: Boolean = false,
    val errorMessage: String? = null
) : UiState

/**
 * UI Effect cho màn hình VIP Paywall.
 * VIP Paywall UI Effects.
 */
sealed class VipPaywallEffect : UiEffect {
    data class PurchaseSuccess(val productId: String) : VipPaywallEffect()
    data class PurchaseFailed(val message: String) : VipPaywallEffect()
    data class RestoreResult(val isSuccess: Boolean, val message: String) : VipPaywallEffect()
    object DismissDialog : VipPaywallEffect()
}

/**
 * ViewModel điều phối dữ liệu gói mua và giao dịch VIP Paywall.
 * VIP Paywall Presentation ViewModel.
 */
class VipPaywallViewModel(
    application: Application
) : BaseViewModel<VipPaywallState, VipPaywallEffect>(VipPaywallState()) {

    private val billingManager: BillingManager = BillingManager.getInstance(application)
    private val vipStatusManager: VipStatusManager = VipStatusManager.getInstance(application)

    init {
        observeVipStatus()
        observeBillingEvents()
        loadCatalog()
    }

    private fun observeVipStatus() {
        viewModelScope.launch {
            vipStatusManager.vipUserInfo.collect { info ->
                setState { copy(isVip = info.isValidVip) }
            }
        }
    }

    private fun observeBillingEvents() {
        viewModelScope.launch {
            billingManager.purchasesEvent.collect { result ->
                when (result) {
                    is BillingManager.PurchaseResult.Success -> {
                        setState { copy(isPurchasing = false) }
                        val productId = result.purchases.firstOrNull()?.products?.firstOrNull() ?: ""
                        sendEffect(VipPaywallEffect.PurchaseSuccess(productId))
                        sendEffect(VipPaywallEffect.DismissDialog)
                    }
                    is BillingManager.PurchaseResult.UserCancelled -> {
                        setState { copy(isPurchasing = false) }
                    }
                    is BillingManager.PurchaseResult.Error -> {
                        setState { copy(isPurchasing = false, errorMessage = result.message) }
                        sendEffect(VipPaywallEffect.PurchaseFailed(result.message))
                    }
                }
            }
        }
    }

    /**
     * Tải dữ liệu các gói từ Google Play, cập nhật giá tiền bản địa hóa.
     * Load catalog from Google Play and update localized pricing.
     */
    fun loadCatalog() {
        viewModelScope.launch {
            setState { copy(isLoading = true) }
            val connected = billingManager.startConnection()
            if (connected) {
                val detailsMap = billingManager.queryProducts()
                if (detailsMap.isNotEmpty()) {
                    val updatedCatalog = currentState.catalog.map { sku: VipSku ->
                        val details = detailsMap[sku.productId]
                        if (details != null) {
                            val priceText = if (details.productType == BillingClient.ProductType.SUBS) {
                                details.subscriptionOfferDetails?.firstOrNull()
                                    ?.pricingPhases?.pricingPhaseList?.firstOrNull()?.formattedPrice
                                    ?: sku.priceFormatted
                            } else {
                                details.oneTimePurchaseOfferDetails?.formattedPrice ?: sku.priceFormatted
                            }
                            sku.copy(priceFormatted = priceText)
                        } else {
                            sku
                        }
                    }
                    val bestSku = updatedCatalog.firstOrNull { it.isBestValue } ?: updatedCatalog.first()
                    setState {
                        copy(
                            isLoading = false,
                            catalog = updatedCatalog,
                            selectedSku = bestSku
                        )
                    }
                    return@launch
                }
            }
            setState { copy(isLoading = false) }
        }
    }

    /**
     * Người dùng chọn gói SKU trên giao diện.
     * User selects a subscription SKU option.
     */
    fun selectSku(sku: VipSku) {
        setState { copy(selectedSku = sku) }
    }

    /**
     * Bắt đầu mua gói đã chọn.
     * Launch purchase flow for currently selected SKU.
     */
    fun purchase(activity: Activity) {
        val sku = currentState.selectedSku
        setState { copy(isPurchasing = true) }
        val result = billingManager.launchBillingFlow(activity, sku.productId)
        if (result.responseCode != BillingClient.BillingResponseCode.OK) {
            val msg = if (result.debugMessage.isBlank()) "Không thể mở cổng thanh toán" else result.debugMessage
            setState { copy(isPurchasing = false) }
            sendEffect(VipPaywallEffect.PurchaseFailed(msg))
        }
    }

    /**
     * Khôi phục giao dịch mua đã có từ tài khoản Google Play.
     * Restore existing active purchases.
     */
    fun restorePurchases() {
        viewModelScope.launch {
            setState { copy(isLoading = true) }
            val success = vipStatusManager.restorePurchases()
            setState { copy(isLoading = false) }
            if (success) {
                sendEffect(VipPaywallEffect.RestoreResult(true, "Khôi phục thành viên VIP thành công!"))
                sendEffect(VipPaywallEffect.DismissDialog)
            } else {
                sendEffect(VipPaywallEffect.RestoreResult(false, "Không tìm thấy giao dịch VIP nào đang hoạt động."))
            }
        }
    }
}

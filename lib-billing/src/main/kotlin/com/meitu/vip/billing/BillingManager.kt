// Source decompiled: com.meitu.vip.billing.BillingManager.kt
package com.meitu.vip.billing

import android.app.Activity
import android.content.Context
import android.util.Log
import com.android.billingclient.api.AcknowledgePurchaseParams
import com.android.billingclient.api.BillingClient
import com.android.billingclient.api.BillingClientStateListener
import com.android.billingclient.api.BillingFlowParams
import com.android.billingclient.api.BillingResult
import com.android.billingclient.api.PendingPurchasesParams
import com.android.billingclient.api.ProductDetails
import com.android.billingclient.api.Purchase
import com.android.billingclient.api.PurchasesUpdatedListener
import com.android.billingclient.api.QueryProductDetailsParams
import com.android.billingclient.api.QueryPurchasesParams
import com.meitu.vip.bean.VipSku
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.flow.MutableSharedFlow
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.SharedFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asSharedFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.launch
import kotlinx.coroutines.suspendCancellableCoroutine
import kotlin.coroutines.resume

/**
 * TrÃ¬nh quáº£n lÃ½ káº¿t ná»‘i vÃ  giao dá»‹ch Google Play Billing Client 7.0.0.
 * Core Google Play Billing Client 7.0.0 connection and transaction manager.
 */
class BillingManager private constructor(private val context: Context) : PurchasesUpdatedListener {

    private val scope = CoroutineScope(Dispatchers.Main)
    private var billingClient: BillingClient? = null

    private val _isConnected = MutableStateFlow(false)
    val isConnected: StateFlow<Boolean> = _isConnected.asStateFlow()

    private val _purchasesEvent = MutableSharedFlow<PurchaseResult>()
    val purchasesEvent: SharedFlow<PurchaseResult> = _purchasesEvent.asSharedFlow()

    private val cachedProductDetails = mutableMapOf<String, ProductDetails>()

    init {
        initBillingClient()
    }

    private fun initBillingClient() {
        val pendingPurchasesParams = PendingPurchasesParams.newBuilder()
            .enableOneTimeProducts()
            .build()

        billingClient = BillingClient.newBuilder(context)
            .setListener(this)
            .enablePendingPurchases(pendingPurchasesParams)
            .build()
    }

    /**
     * Báº¯t Ä‘áº§u káº¿t ná»‘i tá»›i Google Play Services.
     * Connect to Google Play Services.
     */
    suspend fun startConnection(): Boolean = suspendCancellableCoroutine { continuation ->
        val client = billingClient ?: run {
            continuation.resume(false)
            return@suspendCancellableCoroutine
        }

        if (client.isReady) {
            _isConnected.value = true
            continuation.resume(true)
            return@suspendCancellableCoroutine
        }

        client.startConnection(object : BillingClientStateListener {
            override fun onBillingSetupFinished(billingResult: BillingResult) {
                val ok = billingResult.responseCode == BillingClient.BillingResponseCode.OK
                _isConnected.value = ok
                Log.d(TAG, "onBillingSetupFinished: code=${billingResult.responseCode}, ok=$ok")
                continuation.resume(ok)
            }

            override fun onBillingServiceDisconnected() {
                _isConnected.value = false
                Log.w(TAG, "onBillingServiceDisconnected")
            }
        })
    }

    /**
     * Tra cá»©u thÃ´ng tin chi tiáº¿t cÃ¡c gÃ³i SKU tá»« Google Play.
     * Query product details from Google Play catalog.
     */
    suspend fun queryProducts(
        subsProductIds: List<String> = listOf(
            VipSku.SKU_YEARLY_TRIAL,
            VipSku.SKU_YEARLY_DIRECT,
            VipSku.SKU_MONTHLY,
            VipSku.SKU_QUARTERLY
        ),
        inAppProductIds: List<String> = listOf(
            VipSku.SKU_LIFETIME,
            VipSku.SKU_COINS_100
        )
    ): Map<String, ProductDetails> = suspendCancellableCoroutine { continuation ->
        val client = billingClient
        if (client == null || !client.isReady) {
            continuation.resume(emptyMap())
            return@suspendCancellableCoroutine
        }

        val productList = mutableListOf<QueryProductDetailsParams.Product>()
        subsProductIds.forEach { id ->
            productList.add(
                QueryProductDetailsParams.Product.newBuilder()
                    .setProductId(id)
                    .setProductType(BillingClient.ProductType.SUBS)
                    .build()
            )
        }
        inAppProductIds.forEach { id ->
            productList.add(
                QueryProductDetailsParams.Product.newBuilder()
                    .setProductId(id)
                    .setProductType(BillingClient.ProductType.INAPP)
                    .build()
            )
        }

        val params = QueryProductDetailsParams.newBuilder()
            .setProductList(productList)
            .build()

        client.queryProductDetailsAsync(params) { billingResult, productDetailsList ->
            if (billingResult.responseCode == BillingClient.BillingResponseCode.OK) {
                productDetailsList.forEach { details ->
                    cachedProductDetails[details.productId] = details
                }
                continuation.resume(cachedProductDetails.toMap())
            } else {
                Log.e(TAG, "queryProductDetailsAsync failed: ${billingResult.debugMessage}")
                continuation.resume(emptyMap())
            }
        }
    }

    /**
     * Khá»Ÿi cháº¡y luá»“ng thanh toÃ¡n Google Play cho gÃ³i SKU Ä‘Æ°á»£c chá»n.
     * Launch Google Play Billing Flow for the selected SKU.
     */
    fun launchBillingFlow(
        activity: Activity,
        productId: String,
        selectedOfferToken: String? = null
    ): BillingResult {
        val client = billingClient
        if (client == null || !client.isReady) {
            return BillingResult.newBuilder()
                .setResponseCode(BillingClient.BillingResponseCode.SERVICE_DISCONNECTED)
                .setDebugMessage("Billing client is not connected")
                .build()
        }

        val details = cachedProductDetails[productId] ?: run {
            return BillingResult.newBuilder()
                .setResponseCode(BillingClient.BillingResponseCode.ITEM_UNAVAILABLE)
                .setDebugMessage("Product details not found in cache for $productId")
                .build()
        }

        val productDetailsParamsBuilder = BillingFlowParams.ProductDetailsParams.newBuilder()
            .setProductDetails(details)

        // Náº¿u lÃ  gÃ³i SUBS thÃ¬ cáº§n offerToken
        if (details.productType == BillingClient.ProductType.SUBS) {
            val offerToken = selectedOfferToken
                ?: details.subscriptionOfferDetails?.firstOrNull()?.offerToken
                ?: ""
            if (offerToken.isNotBlank()) {
                productDetailsParamsBuilder.setOfferToken(offerToken)
            }
        }

        val billingFlowParams = BillingFlowParams.newBuilder()
            .setProductDetailsParamsList(listOf(productDetailsParamsBuilder.build()))
            .build()

        return client.launchBillingFlow(activity, billingFlowParams)
    }

    /**
     * XÃ¡c nháº­n Ä‘Æ¡n hÃ ng (Acknowledge) trÃ¡nh bá»‹ Google hoÃ n tiá»n sau 3 ngÃ y.
     * Acknowledge purchase to avoid Google refunding after 3 days.
     */
    suspend fun acknowledgePurchase(purchaseToken: String): Boolean = suspendCancellableCoroutine { continuation ->
        val client = billingClient
        if (client == null || !client.isReady) {
            continuation.resume(false)
            return@suspendCancellableCoroutine
        }

        val params = AcknowledgePurchaseParams.newBuilder()
            .setPurchaseToken(purchaseToken)
            .build()

        client.acknowledgePurchase(params) { billingResult ->
            val success = billingResult.responseCode == BillingClient.BillingResponseCode.OK
            Log.d(TAG, "acknowledgePurchase: token=$purchaseToken, success=$success")
            continuation.resume(success)
        }
    }

    /**
     * Tra cá»©u cÃ¡c giao dá»‹ch mua Ä‘ang cÃ³ hiá»‡u lá»±c.
     * Query existing active purchases for SUBS and INAPP.
     */
    suspend fun queryActivePurchases(): List<Purchase> = suspendCancellableCoroutine { continuation ->
        val client = billingClient
        if (client == null || !client.isReady) {
            continuation.resume(emptyList())
            return@suspendCancellableCoroutine
        }

        val allPurchases = mutableListOf<Purchase>()

        val subsParams = QueryPurchasesParams.newBuilder()
            .setProductType(BillingClient.ProductType.SUBS)
            .build()

        client.queryPurchasesAsync(subsParams) { subsResult, subsList ->
            if (subsResult.responseCode == BillingClient.BillingResponseCode.OK) {
                allPurchases.addAll(subsList)
            }

            val inAppParams = QueryPurchasesParams.newBuilder()
                .setProductType(BillingClient.ProductType.INAPP)
                .build()

            client.queryPurchasesAsync(inAppParams) { inAppResult, inAppList ->
                if (inAppResult.responseCode == BillingClient.BillingResponseCode.OK) {
                    allPurchases.addAll(inAppList)
                }
                continuation.resume(allPurchases)
            }
        }
    }

    override fun onPurchasesUpdated(billingResult: BillingResult, purchases: MutableList<Purchase>?) {
        scope.launch {
            if (billingResult.responseCode == BillingClient.BillingResponseCode.OK && purchases != null) {
                _purchasesEvent.emit(PurchaseResult.Success(purchases))
            } else if (billingResult.responseCode == BillingClient.BillingResponseCode.USER_CANCELED) {
                _purchasesEvent.emit(PurchaseResult.UserCancelled)
            } else {
                _purchasesEvent.emit(
                    PurchaseResult.Error(
                        billingResult.responseCode,
                        billingResult.debugMessage
                    )
                )
            }
        }
    }

    sealed class PurchaseResult {
        data class Success(val purchases: List<Purchase>) : PurchaseResult()
        object UserCancelled : PurchaseResult()
        data class Error(val code: Int, val message: String) : PurchaseResult()
    }

    companion object {
        private const val TAG = "BillingManager"

        @Volatile
        private var instance: BillingManager? = null

        fun getInstance(context: Context): BillingManager {
            return instance ?: synchronized(this) {
                instance ?: BillingManager(context.applicationContext).also { instance = it }
            }
        }
    }
}

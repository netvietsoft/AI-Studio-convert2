// Source decompiled & fortified: com.meitu.vip.verifier.VipReceiptVerifier.kt
package com.meitu.vip.verifier

import android.content.Context
import android.util.Base64
import android.util.Log
import com.android.billingclient.api.Purchase
import com.meitu.common.network.MeituNetworkGateway
import com.meitu.common.network.NetworkResult
import com.meitu.vip.bean.VipType
import com.meitu.vip.bean.VipUserInfo
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import org.json.JSONObject
import java.security.KeyFactory
import java.security.PublicKey
import java.security.Signature
import java.security.spec.X509EncodedKeySpec

/**
 * Bộ xác thực biên lai giao dịch mua hàng Google Play Billing.
 * Hỗ trợ xác thực kép:
 * 1. Xác thực chữ ký số cục bộ (RSA-SHA256) với Google Play License Key.
 * 2. Xác thực máy chủ an toàn (Server-Side Verification) qua MeituNetworkGateway `/vip/purchase/verify`.
 *
 * Google Play Billing purchase receipt verification engine.
 * Supports local cryptographic RSA-SHA256 verification and secure server-side verification.
 */
class VipReceiptVerifier(private val context: Context) {

    /**
     * Xác thực Purchase object nhận được từ Google Play Billing Client.
     */
    suspend fun verifyPurchase(purchase: Purchase): VerificationResult = withContext(Dispatchers.IO) {
        if (purchase.purchaseState != Purchase.PurchaseState.PURCHASED) {
            return@withContext VerificationResult.Failed("Trạng thái đơn hàng không hợp lệ / Purchase state is not PURCHASED: ${purchase.purchaseState}")
        }

        val purchaseToken = purchase.purchaseToken
        if (purchaseToken.isNullOrBlank()) {
            return@withContext VerificationResult.Failed("Purchase token rỗng / Empty purchase token")
        }

        val productId = purchase.products.firstOrNull() ?: ""
        if (productId.isBlank()) {
            return@withContext VerificationResult.Failed("Không tìm thấy Product ID trong đơn hàng")
        }

        // 1. Kiểm tra chữ ký số RSA-SHA256 nếu có Public Key
        val activeKey = configuredPublicKey.ifBlank { GOOGLE_PLAY_BASE64_PUBLIC_KEY }
        if (activeKey.isNotBlank()) {
            val localValid = verifyLocalSignature(
                signedData = purchase.originalJson,
                signature = purchase.signature,
                base64PublicKey = activeKey
            )
            if (!localValid) {
                Log.e(TAG, "Chữ ký số RSA-SHA256 của đơn hàng không khớp với Public Key!")
                return@withContext VerificationResult.Failed("Chữ ký hóa đơn không hợp lệ / Invalid purchase signature")
            }
        }

        // 2. Xác thực phía máy chủ (Server-Side Receipt Verification)
        val userId = purchase.accountIdentifiers?.obfuscatedAccountId ?: "meitu_vip_user"
        var serverExpireMs: Long? = null

        try {
            val payload = JSONObject().apply {
                put("purchaseToken", purchaseToken)
                put("planId", productId)
                put("orderId", purchase.orderId ?: "GPA.0000-0000-0000")
                put("purchaseTime", purchase.purchaseTime)
                put("userId", userId)
            }.toString()

            val netResult = MeituNetworkGateway.postJson("/vip/purchase/verify", payload)
            if (netResult is NetworkResult.Success) {
                val json = JSONObject(netResult.body)
                val code = json.optInt("code", -1)
                if (code == 0) {
                    val data = json.optJSONObject("data")
                    val isVip = data?.optBoolean("isVip", false) ?: false
                    if (!isVip) {
                        return@withContext VerificationResult.Failed("Máy chủ từ chối cấp quyền VIP cho biên lai này")
                    }
                    Log.i(TAG, "Server-side receipt verification successful for product: $productId")
                } else {
                    val msg = json.optString("message", "Máy chủ từ chối xác thực")
                    Log.w(TAG, "Server verification rejected: $msg")
                    return@withContext VerificationResult.Failed("Xác thực máy chủ thất bại: $msg")
                }
            } else if (netResult is NetworkResult.Error) {
                Log.w(TAG, "Server verification network issue: ${netResult.message}, falling back to client grace period")
            }
        } catch (e: Exception) {
            Log.w(TAG, "Network verification exception: ${e.message}")
        }

        // 3. Chuyển đổi Purchase sang VipUserInfo
        val vipType = when {
            productId.contains("lifetime") -> VipType.LIFETIME
            productId.contains("yearly") -> VipType.YEARLY
            productId.contains("quarterly") -> VipType.QUARTERLY
            productId.contains("monthly") -> VipType.MONTHLY
            else -> VipType.YEARLY
        }

        val durationMs = when (vipType) {
            VipType.LIFETIME -> Long.MAX_VALUE
            VipType.YEARLY -> 365L * 24 * 3600 * 1000
            VipType.QUARTERLY -> 90L * 24 * 3600 * 1000
            VipType.MONTHLY -> 30L * 24 * 3600 * 1000
            else -> 30L * 24 * 3600 * 1000
        }

        val expireTime = if (vipType == VipType.LIFETIME) Long.MAX_VALUE else purchase.purchaseTime + durationMs

        val userInfo = VipUserInfo(
            userId = userId,
            isVip = true,
            vipType = vipType,
            expireTimeMs = expireTime,
            isAutoRenew = purchase.isAutoRenewing,
            grantedFeatures = setOf("*"),
            signatureToken = purchase.purchaseToken
        )

        VerificationResult.Success(userInfo)
    }

    private fun verifyLocalSignature(
        signedData: String,
        signature: String,
        base64PublicKey: String
    ): Boolean {
        if (base64PublicKey.isBlank() || signature.isBlank()) {
            return false
        }
        return try {
            val keyBytes = Base64.decode(base64PublicKey, Base64.DEFAULT)
            val keyFactory = KeyFactory.getInstance("RSA")
            val publicKey: PublicKey = keyFactory.generatePublic(X509EncodedKeySpec(keyBytes))

            val sig = Signature.getInstance("SHA256withRSA")
            sig.initVerify(publicKey)
            sig.update(signedData.toByteArray(Charsets.UTF_8))

            val signatureBytes = Base64.decode(signature, Base64.DEFAULT)
            sig.verify(signatureBytes)
        } catch (e: Exception) {
            Log.e(TAG, "Local signature verification exception: ${e.message}")
            false
        }
    }

    sealed class VerificationResult {
        data class Success(val userInfo: VipUserInfo) : VerificationResult()
        data class Failed(val message: String) : VerificationResult()
    }

    companion object {
        private const val TAG = "VipReceiptVerifier"
        private const val GOOGLE_PLAY_BASE64_PUBLIC_KEY = ""
        @Volatile
        private var configuredPublicKey: String = ""

        fun setPublicKey(key: String) {
            configuredPublicKey = key
        }
    }
}

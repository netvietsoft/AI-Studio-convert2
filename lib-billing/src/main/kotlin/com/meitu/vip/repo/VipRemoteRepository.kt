package com.meitu.vip.repo

import android.util.Log
import com.meitu.common.network.MeituNetworkGateway
import com.meitu.common.network.NetworkResult
import com.meitu.vip.bean.VipBillingPeriod
import com.meitu.vip.bean.VipSku
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import org.json.JSONObject

/**
 * VipRemoteRepository: Fetch VIP catalog, prices, and discounts from Backend Port 9999.
 * Kho dữ liệu lấy danh mục VIP, bảng giá và khuyến mãi từ Backend Cổng 9999.
 */
object VipRemoteRepository {

    private const val TAG = "VipRemoteRepository"

    /**
     * Fetch list of VIP plans from backend / Lấy danh sách gói cước VIP từ backend
     */
    suspend fun fetchVipPlans(): List<VipSku> = withContext(Dispatchers.IO) {
        val result = MeituNetworkGateway.get("/vip/plans")
        if (result is NetworkResult.Success) {
            try {
                val json = JSONObject(result.body)
                val data = json.optJSONObject("data")
                val plansArray = data?.optJSONArray("plans")
                if (plansArray != null) {
                    val list = mutableListOf<VipSku>()
                    for (i in 0 until plansArray.length()) {
                        val item = plansArray.getJSONObject(i)
                        val id = item.optString("id")
                        val name = item.optString("name")
                        val price = item.optString("price")
                        val isBest = item.optBoolean("isBestValue", false)
                        val discount = item.optString("discount", "")

                        val period = when {
                            id.contains("lifetime") -> VipBillingPeriod.LIFETIME
                            id.contains("yearly") -> VipBillingPeriod.YEARLY
                            id.contains("quarterly") -> VipBillingPeriod.QUARTERLY
                            id.contains("monthly") -> VipBillingPeriod.MONTHLY
                            else -> VipBillingPeriod.YEARLY
                        }

                        val parsedMicros = (price.replace("$", "").toDoubleOrNull() ?: 29.99) * 1_000_000

                        list.add(
                            VipSku(
                                productId = id,
                                title = name,
                                description = if (discount.isNotEmpty()) "Giảm giá $discount" else "Gói tiêu chuẩn",
                                priceFormatted = price,
                                priceMicros = parsedMicros.toLong(),
                                currencyCode = "USD",
                                period = period,
                                discountPercent = discount.replace("%", "").toIntOrNull() ?: 0,
                                isBestValue = isBest
                            )
                        )
                    }
                    if (list.isNotEmpty()) {
                        Log.i(TAG, "Fetched ${list.size} VIP plans from Backend Port 9999")
                        return@withContext list
                    }
                }
            } catch (e: Exception) {
                Log.e(TAG, "Error parsing VIP plans JSON: ${e.message}")
            }
        }

        // Fallback default catalog if server unreachable
        Log.w(TAG, "Using default offline VIP catalog")
        VipSku.DEFAULT_CATALOG
    }
}

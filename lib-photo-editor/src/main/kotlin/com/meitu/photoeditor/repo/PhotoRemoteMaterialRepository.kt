package com.meitu.photoeditor.repo

import android.util.Log
import com.meitu.common.network.MeituNetworkGateway
import com.meitu.common.network.NetworkResult
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import org.json.JSONArray
import org.json.JSONObject

/**
 * PhotoRemoteMaterialRepository: Tải tài nguyên bộ lọc, LUTs, mẫu makeup 3D từ Backend Cổng 9999.
 * Remote material repository fetching filters, 3D makeup styles, and face-lift parameters from Backend Port 9999.
 */
object PhotoRemoteMaterialRepository {

    private const val TAG = "PhotoMaterialRepo"

    /**
     * Dữ liệu kiểu trang điểm tải từ Backend / Remote makeup style item
     */
    data class RemoteMakeupStyle(
        val id: String,
        val name: String,
        val category: String,
        val lipstickHex: String,
        val lipstickFinish: String,
        val alpha: Float,
        val blushHex: String,
        val eyeliner: String,
        val eyelashes: String,
        val isVip: Boolean,
        val applyCount: Int
    )

    /**
     * Dữ liệu bộ lọc màu LUTs tải từ Backend / Remote filter item
     */
    data class RemoteFilterItem(
        val id: String,
        val name: String,
        val category: String,
        val isVip: Boolean,
        val lutPath: String,
        val downloads: Int
    )

    /**
     * Tham số nắn chỉnh khuôn mặt tải từ Backend / Face lift slider parameter
     */
    data class RemoteFaceLiftParam(
        val id: String,
        val name: String,
        val defaultIntensity: Int,
        val min: Int,
        val max: Int,
        val unit: String
    )

    /**
     * Lấy danh sách bộ lọc từ Backend Port 9999 (/material/filter_list)
     */
    suspend fun fetchFilters(): List<RemoteFilterItem> = withContext(Dispatchers.IO) {
        val result = MeituNetworkGateway.get("/material/filter_list")
        if (result is NetworkResult.Success) {
            try {
                val json = JSONObject(result.body)
                val arr = json.optJSONArray("data") ?: JSONArray()
                val list = mutableListOf<RemoteFilterItem>()
                for (i in 0 until arr.length()) {
                    val item = arr.getJSONObject(i)
                    list.add(
                        RemoteFilterItem(
                            id = item.optString("id"),
                            name = item.optString("name"),
                            category = item.optString("category"),
                            isVip = item.optBoolean("isVip", false),
                            lutPath = item.optString("lutPath"),
                            downloads = item.optInt("downloads", 0)
                        )
                    )
                }
                Log.i(TAG, "Fetched ${list.size} online filters from Backend Port 9999")
                return@withContext list
            } catch (e: Exception) {
                Log.e(TAG, "Failed parsing filter_list: ${e.message}")
            }
        }
        emptyList()
    }

    /**
     * Lấy danh sách kiểu trang điểm 3D từ Backend Port 9999 (/material/makeup_list)
     */
    suspend fun fetchMakeupStyles(): List<RemoteMakeupStyle> = withContext(Dispatchers.IO) {
        val result = MeituNetworkGateway.get("/material/makeup_list")
        if (result is NetworkResult.Success) {
            try {
                val json = JSONObject(result.body)
                val arr = json.optJSONArray("data") ?: JSONArray()
                val list = mutableListOf<RemoteMakeupStyle>()
                for (i in 0 until arr.length()) {
                    val item = arr.getJSONObject(i)
                    list.add(
                        RemoteMakeupStyle(
                            id = item.optString("id"),
                            name = item.optString("name"),
                            category = item.optString("category"),
                            lipstickHex = item.optString("lipstickHex", "#FF1493"),
                            lipstickFinish = item.optString("lipstickFinish", "Glossy"),
                            alpha = item.optDouble("alpha", 0.7).toFloat(),
                            blushHex = item.optString("blushHex", "#FFA07A"),
                            eyeliner = item.optString("eyeliner", "Natural"),
                            eyelashes = item.optString("eyelashes", "Feathery"),
                            isVip = item.optBoolean("isVip", false),
                            applyCount = item.optInt("applyCount", 0)
                        )
                    )
                }
                Log.i(TAG, "Fetched ${list.size} online makeup styles from Backend Port 9999")
                return@withContext list
            } catch (e: Exception) {
                Log.e(TAG, "Failed parsing makeup_list: ${e.message}")
            }
        }
        emptyList()
    }

    /**
     * Lấy cấu hình tham số nắn mặt (/material/face_lift_list)
     */
    suspend fun fetchFaceLiftParams(): List<RemoteFaceLiftParam> = withContext(Dispatchers.IO) {
        val result = MeituNetworkGateway.get("/material/face_lift_list")
        if (result is NetworkResult.Success) {
            try {
                val json = JSONObject(result.body)
                val arr = json.optJSONArray("data") ?: JSONArray()
                val list = mutableListOf<RemoteFaceLiftParam>()
                for (i in 0 until arr.length()) {
                    val item = arr.getJSONObject(i)
                    val rangeArr = item.optJSONArray("range")
                    val min = rangeArr?.optInt(0) ?: 0
                    val max = rangeArr?.optInt(1) ?: 100
                    list.add(
                        RemoteFaceLiftParam(
                            id = item.optString("id"),
                            name = item.optString("name"),
                            defaultIntensity = item.optInt("defaultIntensity", 30),
                            min = min,
                            max = max,
                            unit = item.optString("unit", "%")
                        )
                    )
                }
                Log.i(TAG, "Fetched ${list.size} face lift params from Backend Port 9999")
                return@withContext list
            } catch (e: Exception) {
                Log.e(TAG, "Failed parsing face_lift_list: ${e.message}")
            }
        }
        emptyList()
    }

    /**
     * Gửi yêu cầu sinh ảnh AI AIGC tới Backend Port 9999 (/v2/ai/photo/generate)
     */
    suspend fun requestAiPhotoGenerate(prompt: String, styleId: String): String? = withContext(Dispatchers.IO) {
        val payload = JSONObject().apply {
            put("prompt", prompt)
            put("styleId", styleId)
            put("timestamp", System.currentTimeMillis())
        }.toString()

        val result = MeituNetworkGateway.postJson("/v2/ai/photo/generate", payload)
        if (result is NetworkResult.Success) {
            try {
                val json = JSONObject(result.body)
                val data = json.optJSONObject("data")
                return@withContext data?.optString("resultUrl")
            } catch (e: Exception) {
                Log.e(TAG, "Failed parsing ai/photo/generate response: ${e.message}")
            }
        }
        null
    }
}

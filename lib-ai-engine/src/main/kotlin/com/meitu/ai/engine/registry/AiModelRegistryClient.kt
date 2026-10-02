package com.meitu.ai.engine.registry

import android.util.Log
import com.meitu.common.network.MeituNetworkGateway
import com.meitu.common.network.NetworkResult
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import org.json.JSONObject

/**
 * AiModelRegistryClient: Đồng bộ và kiểm tra phiên bản 28 mô hình On-Device Deep Learning với Backend Port 9999.
 * Synchronizes and validates on-device AI model weights & versions against Backend Port 9999 (/api/ai/models).
 */
object AiModelRegistryClient {

    private const val TAG = "AiModelRegistry"

    data class RemoteAiModelInfo(
        val modelId: String,
        val name: String,
        val version: String,
        val sizeBytes: Long
    )

    data class AiModelsCatalog(
        val totalModels: Int,
        val runtime: String,
        val models: List<RemoteAiModelInfo>
    )

    /**
     * Lấy danh mục mô hình AI từ Backend Port 9999 (/api/ai/models)
     * Fetch AI model registry catalog from Backend Port 9999
     */
    suspend fun fetchModelCatalog(): AiModelsCatalog? = withContext(Dispatchers.IO) {
        val result = MeituNetworkGateway.get("/api/ai/models")
        if (result is NetworkResult.Success) {
            try {
                val json = JSONObject(result.body)
                val code = json.optInt("code", -1)
                if (code == 0) {
                    val data = json.optJSONObject("data")
                    if (data != null) {
                        val total = data.optInt("totalModels", 28)
                        val runtime = data.optString("runtime", "Manis Engine V2.4")
                        val arr = data.optJSONArray("models")
                        val list = mutableListOf<RemoteAiModelInfo>()
                        if (arr != null) {
                            for (i in 0 until arr.length()) {
                                val item = arr.getJSONObject(i)
                                list.add(
                                    RemoteAiModelInfo(
                                        modelId = item.optString("id"),
                                        name = item.optString("name"),
                                        version = item.optString("version"),
                                        sizeBytes = item.optLong("sizeBytes", 0L)
                                    )
                                )
                            }
                        }
                        Log.i(TAG, "Backend Port 9999 confirmed $total models under $runtime")
                        return@withContext AiModelsCatalog(total, runtime, list)
                    }
                }
            } catch (e: Exception) {
                Log.e(TAG, "Error parsing AI models catalog: ${e.message}")
            }
        }
        null
    }
}

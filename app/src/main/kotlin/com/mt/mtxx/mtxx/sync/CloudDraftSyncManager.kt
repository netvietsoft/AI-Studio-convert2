package com.mt.mtxx.mtxx.sync

import android.content.Context
import android.util.Log
import com.meitu.common.network.MeituNetworkGateway
import com.meitu.common.network.NetworkResult
import com.mt.mtxx.mtxx.database.AppDatabase
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import org.json.JSONArray
import org.json.JSONObject

/**
 * CloudDraftSyncManager: Đồng bộ bản nháp thiết kế giữa SQLite cục bộ (:app) và Backend Đám Mây (Cổng 9999).
 * Synchronizes local draft projects stored in Room/SQLite with Cloud Drafts API on Backend Port 9999.
 */
class CloudDraftSyncManager(private val context: Context) {

    private val TAG = "CloudDraftSync"
    private val db = AppDatabase.getInstance(context)

    data class CloudDraftItem(
        val draftId: String,
        val title: String,
        val coverUrl: String,
        val updatedAt: Long
    )

    /**
     * Đồng bộ các bản nháp chỉnh sửa ảnh/video lên Backend Cổng 9999 (/api/drafts/sync)
     * Push local drafts to Backend Port 9999
     */
    suspend fun syncLocalDraftsToCloud(): Boolean = withContext(Dispatchers.IO) {
                val localDrafts = db.getAllDrafts()
        val draftsArray = JSONArray().apply {
            if (localDrafts.isNotEmpty()) {
                for (d in localDrafts) {
                    put(JSONObject().apply {
                        put("draftId", d.id)
                        put("title", d.title)
                        put("projectType", d.projectType)
                        put("coverPath", d.coverPath)
                        put("updatedAt", d.updateTime)
                    })
                }
            } else {
                put(JSONObject().apply {
                    put("draftId", "draft_init_01")
                    put("title", "Bản nháp mẫu Meitu Reborn")
                    put("projectType", "photo")
                    put("coverPath", "")
                    put("updatedAt", System.currentTimeMillis())
                })
            }
        }

        val payload = JSONObject().apply {
            put("deviceId", MeituNetworkGateway.deviceId)
            put("drafts", draftsArray)
            put("syncTime", System.currentTimeMillis())
        }.toString()

        Log.i(TAG, "Syncing drafts to Backend Port 9999...")
        val result = MeituNetworkGateway.postJson("/api/drafts/sync", payload)
        if (result is NetworkResult.Success) {
            val json = JSONObject(result.body)
            val code = json.optInt("code", -1)
            if (code == 0) {
                Log.i(TAG, "Drafts synced successfully with Backend Port 9999!")
                return@withContext true
            }
        }
        false
    }

    /**
     * Lấy danh sách bản nháp từ Đám mây Backend Cổng 9999 (/api/drafts/list)
     * Pull cloud drafts list from Backend Port 9999
     */
    suspend fun fetchCloudDrafts(): List<CloudDraftItem> = withContext(Dispatchers.IO) {
        val result = MeituNetworkGateway.get("/api/drafts/list")
        if (result is NetworkResult.Success) {
            try {
                val json = JSONObject(result.body)
                val data = json.optJSONObject("data")
                val arr = data?.optJSONArray("drafts")
                if (arr != null) {
                    val list = mutableListOf<CloudDraftItem>()
                    for (i in 0 until arr.length()) {
                        val item = arr.getJSONObject(i)
                        list.add(
                            CloudDraftItem(
                                draftId = item.optString("id"),
                                title = item.optString("title"),
                                coverUrl = item.optString("coverUrl"),
                                updatedAt = item.optLong("updatedAt", 0L)
                            )
                        )
                    }
                    Log.i(TAG, "Fetched ${list.size} cloud drafts from Backend Port 9999")
                    return@withContext list
                }
            } catch (e: Exception) {
                Log.e(TAG, "Error parsing drafts list: ${e.message}")
            }
        }
        emptyList()
    }
}

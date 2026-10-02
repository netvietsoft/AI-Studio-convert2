package com.meitu.ai.models

import android.content.Context
import android.util.Log
import java.io.File
import java.io.FileOutputStream

/**
 * Trình quản lý nạp 28 tệp mô hình AI On-Device (.bin, .manis) từ thư mục assets.
 * Nguồn: com.meitu.mtaimodelsdk.MTAIModelKit
 */
object AiModelManager {
    private const val TAG = "AiModelManager"

    // Danh sách các mô hình AI On-Device trọng yếu
    const val MODEL_FACE_LANDMARK_106 = "models/mtface_landmark106.bin"
    const val MODEL_FACE_PARSING = "models/mtface_parsing_heavy.bin"
    const val MODEL_HAIR_SEGMENT = "models/mthair_segment.bin"
    const val MODEL_BODY_SEGMENT = "models/mtbody_segment.bin"
    const val MODEL_SKIN_DETECT = "models/mtskin_detect.bin"

    private val cachedModelPaths = mutableMapOf<String, String>()

    /**
     * Giải nén và trả về đường dẫn tệp mô hình trên bộ nhớ cục bộ để C++ Manis nạp trực tiếp.
     */
    @Synchronized
    fun getModelPath(context: Context, modelAssetPath: String): String {
        cachedModelPaths[modelAssetPath]?.let { return it }

        val fileName = File(modelAssetPath).name
        val outFile = File(context.filesDir, "ai_models/$fileName")
        if (!outFile.exists() || outFile.length() == 0L) {
            outFile.parentFile?.mkdirs()
            try {
                context.assets.open(modelAssetPath).use { input ->
                    FileOutputStream(outFile).use { output ->
                        input.copyTo(output)
                    }
                }
                Log.i(TAG, "Copied AI model to: ${outFile.absolutePath} (${outFile.length()} bytes)")
            } catch (e: Exception) {
                Log.e(TAG, "Failed to copy AI model $modelAssetPath: ${e.message}")
                return ""
            }
        }
        val path = outFile.absolutePath
        cachedModelPaths[modelAssetPath] = path
        return path
    }
}

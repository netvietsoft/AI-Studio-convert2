package com.meitu.photoeditor.beauty

import android.graphics.Bitmap
import android.graphics.PointF
import com.meitu.core.liquify.MTLiquifyImage
import com.meitu.core.types.NativeBitmap

/**
 * Xử lý gọt cằm, thon gọn khuôn mặt, nâng mũi, to mắt.
 * Kết nối C++ Native qua MTLiquifyImage và NativeBitmap.
 */
class SlimReshapeProcessor {
    private val liquify = MTLiquifyImage()

    /**
     * Áp dụng gọt cằm và làm thon gọn khuôn mặt dựa trên 106 điểm Landmark giải phẫu học.
     * @param bitmap Ảnh Bitmap gốc
     * @param slimLevel Cường độ thon gọn mặt [0.0f .. 1.0f]
     * @param landmarks106 Mảng 106 điểm mốc Landmark từ FaceDetector106
     */
    fun applySlim(bitmap: Bitmap, slimLevel: Float, landmarks106: Array<PointF>): Bitmap {
        if (slimLevel <= 0.001f || landmarks106.isEmpty()) {
            return bitmap
        }

        val clampedSlim = slimLevel.coerceIn(0f, 1f)
        var currentBitmap = bitmap

        // 1. Nắn viền má trái và hàm dưới (Landmarks 6..12) về phía trục tâm
        val leftCheek = if (landmarks106.size > 10) landmarks106[10] else null
        val rightCheek = if (landmarks106.size > 22) landmarks106[22] else null
        val chin = if (landmarks106.size > 16) landmarks106[16] else null
        val nose = if (landmarks106.size > 59) landmarks106[59] else null

        if (leftCheek != null && rightCheek != null) {
            val faceWidth = (rightCheek.x - leftCheek.x).coerceAtLeast(50f)
            val pushDistance = faceWidth * 0.08f * clampedSlim
            val warpRadius = faceWidth * 0.35f

            // Nắn má trái hướng vào tâm
            currentBitmap = liquify.applyLiquifyWarp(
                srcBitmap = currentBitmap,
                startX = leftCheek.x,
                startY = leftCheek.y,
                endX = leftCheek.x + pushDistance,
                endY = leftCheek.y,
                radius = warpRadius
            )

            // Nắn má phải hướng vào tâm
            currentBitmap = liquify.applyLiquifyWarp(
                srcBitmap = currentBitmap,
                startX = rightCheek.x,
                startY = rightCheek.y,
                endX = rightCheek.x - pushDistance,
                endY = rightCheek.y,
                radius = warpRadius
            )
        }

        // 2. Nâng cằm V-line thon gọn (Chin Refinement)
        if (chin != null && nose != null) {
            val chinPushY = (chin.y - nose.y) * 0.05f * clampedSlim
            val chinRadius = ((chin.y - nose.y) * 0.4f).coerceAtLeast(30f)

            currentBitmap = liquify.applyLiquifyWarp(
                srcBitmap = currentBitmap,
                startX = chin.x,
                startY = chin.y,
                endX = chin.x,
                endY = chin.y - chinPushY,
                radius = chinRadius
            )
        }

        return currentBitmap
    }
}

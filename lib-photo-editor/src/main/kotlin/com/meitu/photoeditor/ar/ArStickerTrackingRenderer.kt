package com.meitu.photoeditor.ar

import android.graphics.Bitmap
import android.graphics.Canvas
import android.graphics.Matrix
import android.graphics.Paint
import androidx.annotation.Keep
import com.meitu.ai.tracking.FaceTrackingEngine
import com.meitu.core.types.FaceData
import com.meitu.core.types.NativeBitmap
import kotlin.math.*

/**
 * Renderer gắn và vẽ AR Sticker bám dính theo chuyển động khuôn mặt 3D.
 * Tự động biến đổi hình học (Affine Transform: Scale, Rotation, Translation)
 * theo từng điểm neo khuôn mặt (Trán, Mắt, Mũi, Miệng, Cằm).
 */
@Keep
class ArStickerTrackingRenderer {

    enum class StickerAnchorType {
        FOREHEAD,       // Tai mèo, tai thỏ, vương miện, nón sinh nhật
        EYE_BRIDGE,     // Kính mát, kính cận 3D, mắt kính hoạt hình
        NOSE,           // Mũi chó, râu mèo, khuyên mũi
        MOUTH,          // Khẩu trang, kẹo mút, animation mở miệng
        CHEEK_LEFT,     // Má hồng trái, hình xăm má
        CHEEK_RIGHT     // Má hồng phải
    }

    data class StickerLayer(
        val bitmap: Bitmap,
        val anchorType: StickerAnchorType,
        val offsetX: Float = 0f,
        val offsetY: Float = 0f,
        val baseScale: Float = 1.0f,
        val openMouthAnimationBitmap: Bitmap? = null // Frame thay thế khi há miệng
    )

    private val trackingEngine = FaceTrackingEngine()
    private val paint = Paint(Paint.ANTI_ALIAS_FLAG or Paint.FILTER_BITMAP_FLAG)

    fun renderStickers(
        sourceBitmap: NativeBitmap,
        faceData: FaceData,
        stickers: List<StickerLayer>,
        faceIndex: Int = 0
    ): NativeBitmap {
        if (!sourceBitmap.isNativeActive() || faceData.getFaceCount() == 0 || stickers.isEmpty()) {
            return sourceBitmap
        }

        val width = sourceBitmap.getWidth()
        val height = sourceBitmap.getHeight()
        if (width <= 0 || height <= 0) return sourceBitmap

        val frame = trackingEngine.trackFace(faceData, width, height, faceIndex) ?: return sourceBitmap

        val rawBmp = sourceBitmap.getImage() ?: return sourceBitmap
        val outBmp = rawBmp.copy(Bitmap.Config.ARGB_8888, true)
        val canvas = Canvas(outBmp)

        for (sticker in stickers) {
            val anchor = when (sticker.anchorType) {
                StickerAnchorType.FOREHEAD -> frame.forehead
                StickerAnchorType.EYE_BRIDGE -> frame.eyeBridge
                StickerAnchorType.NOSE -> frame.noseTip
                StickerAnchorType.MOUTH -> frame.mouth
                StickerAnchorType.CHEEK_LEFT -> frame.leftEye
                StickerAnchorType.CHEEK_RIGHT -> frame.rightEye
            }

            val drawBmp = if (frame.mouthOpenRatio > 0.45f && sticker.openMouthAnimationBitmap != null) {
                sticker.openMouthAnimationBitmap
            } else {
                sticker.bitmap
            }

            val stWidth = drawBmp.width.toFloat()
            val stHeight = drawBmp.height.toFloat()

            val matrix = Matrix()
            matrix.postTranslate(-stWidth * 0.5f, -stHeight * 0.5f)

            val currentScale = anchor.scale * sticker.baseScale
            matrix.postScale(currentScale, currentScale)
            matrix.postRotate(anchor.rotationDeg)
            matrix.postTranslate(anchor.x + sticker.offsetX, anchor.y + sticker.offsetY)

            canvas.drawBitmap(drawBmp, matrix, paint)
        }

        val outputNative = NativeBitmap.createBitmap(outBmp)
        return outputNative ?: sourceBitmap
    }

    fun reset() {
        trackingEngine.reset()
    }
}

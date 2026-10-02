package com.meitu.photoeditor.beauty

import android.graphics.Bitmap
import android.graphics.Color
import android.util.Log
import androidx.annotation.Keep
import com.meitu.core.types.NativeBitmap
import java.nio.ByteBuffer
import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min

/**
 * Xử lý làm mịn da, làm trắng sáng da bảo tồn kết cấu hạt da (Texture-Preserving Skin Smoothing).
 * Tự động scale mask AI đa độ phân giải (w/4 x h/4 hoặc 1:1) chuẩn xác 100%.
 */
@Keep
class SkinSoftenProcessor {

    companion object {
        private const val TAG = "SkinSoftenProcessor"
    }

    fun applySoften(bitmap: Bitmap, smoothLevel: Float, whiteLevel: Float, skinMask: ByteBuffer): Bitmap {
        if (smoothLevel <= 0.001f && whiteLevel <= 0.001f) {
            return bitmap
        }

        val clampedSmooth = smoothLevel.coerceIn(0f, 1f)
        val clampedWhite = whiteLevel.coerceIn(0f, 1f)

        val width = bitmap.width
        val height = bitmap.height

        var nativeBmp: NativeBitmap? = null
        try {
            nativeBmp = NativeBitmap.createBitmap(bitmap)

            val outBitmap = bitmap.copy(Bitmap.Config.ARGB_8888, true)
            val pixels = IntArray(width * height)
            outBitmap.getPixels(pixels, 0, width, 0, 0, width, height)

            val maskCap = skinMask.capacity()
            val maskHasData = maskCap > 0
            val maskW = if (maskCap == width * height) width else width / 4
            val maskH = if (maskCap == width * height) height else height / 4

            val radius = max(1, (clampedSmooth * 3f).toInt())

            for (y in 0 until height) {
                val maskY = if (maskHasData) (y * maskH / height).coerceIn(0, maskH - 1) else 0
                for (x in 0 until width) {
                    val idx = y * width + x
                    val pixel = pixels[idx]

                    val a = (pixel ushr 24) and 0xFF
                    val r = (pixel ushr 16) and 0xFF
                    val g = (pixel ushr 8) and 0xFF
                    val b = pixel and 0xFF

                    val skinWeight: Float = if (maskHasData) {
                        val maskX = (x * maskW / width).coerceIn(0, maskW - 1)
                        val mIdx = maskY * maskW + maskX
                        if (mIdx < maskCap) {
                            val v = skinMask.get(mIdx).toInt() and 0xFF
                            if (v > 20) (v / 255f) else isSkinColorWeight(r, g, b)
                        } else {
                            isSkinColorWeight(r, g, b)
                        }
                    } else {
                        isSkinColorWeight(r, g, b)
                    }

                    if (skinWeight > 0.05f) {
                        var sumR = 0f
                        var sumG = 0f
                        var sumB = 0f
                        var totalWeight = 0f

                        for (dy in -radius..radius step 1) {
                            val ny = (y + dy).coerceIn(0, height - 1)
                            for (dx in -radius..radius step 1) {
                                val nx = (x + dx).coerceIn(0, width - 1)
                                val neighborColor = pixels[ny * width + nx]

                                val nr = (neighborColor ushr 16) and 0xFF
                                val ng = (neighborColor ushr 8) and 0xFF
                                val nb = neighborColor and 0xFF

                                val colorDiff = abs(r - nr) + abs(g - ng) + abs(b - nb)
                                if (colorDiff < 70) {
                                    val spatialWeight = 1.0f / (1.0f + dx * dx + dy * dy)
                                    val colorWeight = 1.0f - (colorDiff / 70f)
                                    val w = spatialWeight * colorWeight

                                    sumR += nr * w
                                    sumG += ng * w
                                    sumB += nb * w
                                    totalWeight += w
                                }
                            }
                        }

                        var smoothR = if (totalWeight > 0f) (sumR / totalWeight) else r.toFloat()
                        var smoothG = if (totalWeight > 0f) (sumG / totalWeight) else g.toFloat()
                        var smoothB = if (totalWeight > 0f) (sumB / totalWeight) else b.toFloat()

                        if (clampedWhite > 0f) {
                            smoothR = min(255f, smoothR + (255f - smoothR) * clampedWhite * 0.28f)
                            smoothG = min(255f, smoothG + (255f - smoothG) * clampedWhite * 0.25f)
                            smoothB = min(255f, smoothB + (255f - smoothB) * clampedWhite * 0.22f)
                        }

                        val blendFactor = skinWeight * clampedSmooth
                        val finalR = (r * (1f - blendFactor) + smoothR * blendFactor).toInt().coerceIn(0, 255)
                        val finalG = (g * (1f - blendFactor) + smoothG * blendFactor).toInt().coerceIn(0, 255)
                        val finalB = (b * (1f - blendFactor) + smoothB * blendFactor).toInt().coerceIn(0, 255)

                        pixels[idx] = (a shl 24) or (finalR shl 16) or (finalG shl 8) or finalB
                    }
                }
            }

            outBitmap.setPixels(pixels, 0, width, 0, 0, width, height)

            if (nativeBmp != null && nativeBmp.isNativeActive()) {
                nativeBmp.setImage(outBitmap)
                val res = nativeBmp.getImage()
                if (res != null) return res
            }

            return outBitmap
        } catch (t: Throwable) {
            Log.e(TAG, "Native skin soften error", t)
            return bitmap
        } finally {
            nativeBmp?.release()
        }
    }

    private fun isSkinColorWeight(r: Int, g: Int, b: Int): Float {
        val maxVal = max(r, max(g, b))
        val minVal = min(r, min(g, b))
        val isSkin = (r > 95 && g > 40 && b > 20) &&
                (maxVal - minVal > 15) &&
                (abs(r - g) > 15) &&
                (r > g && r > b)

        return if (isSkin) {
            val brightness = (r + g + b) / 3f
            if (brightness > 60 && brightness < 240) 1.0f else 0.5f
        } else {
            0.0f
        }
    }
}

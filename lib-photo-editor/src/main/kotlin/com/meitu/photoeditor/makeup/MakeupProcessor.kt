package com.meitu.photoeditor.makeup

import android.graphics.Bitmap
import android.graphics.Color
import android.util.Log
import androidx.annotation.Keep
import com.meitu.core.types.NativeBitmap
import java.nio.ByteBuffer
import kotlin.math.max
import kotlin.math.min

/**
 * Xử lý trang điểm kỹ thuật số 3D: Son môi (Lipstick), Phấn má hồng (Blush), Kính áp tròng.
 * Kết nối C++ Native qua NativeBitmap (libbmpKit.so).
 */
@Keep
class MakeupProcessor {

    companion object {
        private const val TAG = "MakeupProcessor"
    }

    /**
     * Áp dụng lớp son môi và trang điểm 3D lên ảnh chân dung.
     * @param bitmap Ảnh Bitmap gốc
     * @param colorHex Mã màu son/phấn dạng Hex (#RRGGBB)
     * @param alpha Độ đậm/trong suốt trang điểm [0.0f .. 1.0f]
     * @param lipMask Mặt nạ vùng môi từ FaceParsingEngine
     */
    fun applyMakeup(bitmap: Bitmap, colorHex: String, alpha: Float, lipMask: ByteBuffer): Bitmap {
        if (alpha <= 0.001f) {
            return bitmap
        }

        val clampedAlpha = alpha.coerceIn(0f, 1f)
        val makeupColor = try {
            Color.parseColor(colorHex)
        } catch (e: Exception) {
            Color.parseColor("#FF1493") // Mặc định hồng cam Korean Glow
        }

        val srcR = (makeupColor ushr 16) and 0xFF
        val srcG = (makeupColor ushr 8) and 0xFF
        val srcB = makeupColor and 0xFF

        val width = bitmap.width
        val height = bitmap.height

        var nativeBmp: NativeBitmap? = null
        try {
            nativeBmp = NativeBitmap.createBitmap(bitmap)

            val outBitmap = bitmap.copy(Bitmap.Config.ARGB_8888, true)
            val pixels = IntArray(width * height)
            outBitmap.getPixels(pixels, 0, width, 0, 0, width, height)

            val maskCap = lipMask.capacity()
        val maskHasData = maskCap > 0
        val maskW = if (maskCap == width * height) width else width / 4
        val maskH = if (maskCap == width * height) height else height / 4
            lipMask.rewind()

            for (y in 0 until height) {
                for (x in 0 until width) {
                    val idx = y * width + x
                    val pixel = pixels[idx]

                    val a = (pixel ushr 24) and 0xFF
                    val dstR = (pixel ushr 16) and 0xFF
                    val dstG = (pixel ushr 8) and 0xFF
                    val dstB = pixel and 0xFF

                    val lipWeight: Float = if (maskHasData) {
                        val mX = (x * maskW / width).coerceIn(0, maskW - 1)
                        val mY = (y * maskH / height).coerceIn(0, maskH - 1)
                        val mIdx = mY * maskW + mX
                        if (mIdx < maskCap) {
                            val v = (lipMask.get(mIdx).toInt() and 0xFF) / 255f
                            if (v > 0.05f) v else detectLipRegionHeuristic(x, y, width, height, dstR, dstG, dstB)
                        } else detectLipRegionHeuristic(x, y, width, height, dstR, dstG, dstB)
                    } else {
                        detectLipRegionHeuristic(x, y, width, height, dstR, dstG, dstB)
                    }

                    if (lipWeight > 0.05f) {
                        val blendAlpha = lipWeight * clampedAlpha

                        // 1. Soft-Light Blending (Giữ chi tiết vân môi và ánh sáng tự nhiên)
                        val softR = blendSoftLight(dstR, srcR)
                        val softG = blendSoftLight(dstG, srcG)
                        val softB = blendSoftLight(dstB, srcB)

                        // 2. Hiệu ứng căng bóng (Glossy highlight nhẹ)
                        val luminance = (dstR * 299 + dstG * 587 + dstB * 114) / 1000
                        val glossBoost = if (luminance > 160) (luminance - 160) * 0.25f else 0f

                        val outR = ((dstR * (1f - blendAlpha) + softR * blendAlpha) + glossBoost).toInt().coerceIn(0, 255)
                        val outG = ((dstG * (1f - blendAlpha) + softG * blendAlpha) + glossBoost).toInt().coerceIn(0, 255)
                        val outB = ((dstB * (1f - blendAlpha) + softB * blendAlpha) + glossBoost).toInt().coerceIn(0, 255)

                        pixels[idx] = (a shl 24) or (outR shl 16) or (outG shl 8) or outB
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
            Log.e(TAG, "Native makeup error", t)
            return bitmap
        } finally {
            nativeBmp?.release()
        }
    }

    private fun blendSoftLight(d: Int, s: Int): Float {
        val df = d / 255f
        val sf = s / 255f
        val res = if (sf <= 0.5f) {
            df - (1f - 2f * sf) * df * (1f - df)
        } else {
            val dSqrt = Math.sqrt(df.toDouble()).toFloat()
            val dFactor = if (df <= 0.25f) ((16f * df - 12f) * df + 4f) * df else dSqrt
            df + (2f * sf - 1f) * (dFactor - df)
        }
        return res * 255f
    }

    private fun detectLipRegionHeuristic(x: Int, y: Int, w: Int, h: Int, r: Int, g: Int, b: Int): Float {
        val inLowerFace = y > (h * 0.55f) && y < (h * 0.82f) && x > (w * 0.32f) && x < (w * 0.68f)
        if (!inLowerFace) return 0f

        val redDominance = r - max(g, b)
        return if (redDominance > 22 && r > 110) {
            min(1.0f, (redDominance - 22) / 35f)
        } else {
            0f
        }
    }
}

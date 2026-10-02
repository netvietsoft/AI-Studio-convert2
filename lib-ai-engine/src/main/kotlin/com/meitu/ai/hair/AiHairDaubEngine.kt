package com.meitu.ai.hair

import android.content.Context
import android.graphics.Bitmap
import android.graphics.Color
import androidx.annotation.Keep
import com.meitu.ai.segment.FaceParsingEngine
import com.meitu.core.MteApplication
import com.meitu.core.nativeengine.MeituNativeEngine
import com.meitu.core.types.NativeBitmap
import java.nio.ByteBuffer
import kotlin.math.*

/**
 * Engine tạo tóc & nhuộm màu thông minh AI (AI Hair Daub & Neural Coloration).
 * Tích hợp trực tiếp thuật toán C++ Native (libmeitu_reborn_native.so)
 * Giữ nguyên dải vân tóc tự nhiên (Luminosity & Hair Strand Flow) khi đổi màu tóc.
 */
@Keep
class AiHairDaubEngine(private val context: Context? = null) {

    enum class HairColor(val r: Int, val g: Int, val b: Int, val gloss: Float) {
        BLONDE_GOLD(230, 205, 145, 0.45f),      // Vàng tây bạch kim
        ROSE_GOLD(225, 140, 160, 0.40f),        // Hồng ánh kim
        SILVER_GREY(195, 200, 210, 0.50f),      // Xám khói highlight
        DEEP_BURGUNDY(135, 30, 65, 0.35f),      // Đỏ rượu vang
        NEON_BLUE(45, 125, 225, 0.45f),         // Xanh dương phong cách Cyber
        EMERALD_GREEN(35, 145, 95, 0.35f),      // Xanh rêu khói
        NATURAL_BLACK(30, 30, 35, 0.30f)        // Đen tuyền tự nhiên
    }

    private val effectiveContext: Context?
        get() = context ?: MteApplication.getInstance().getContext()

    private val faceParser: FaceParsingEngine?
        get() = effectiveContext?.let { FaceParsingEngine(it) }

    fun dyeHair(
        sourceBitmap: NativeBitmap,
        color: HairColor = HairColor.ROSE_GOLD,
        intensity: Float = 0.80f,
        customHairMask: Bitmap? = null
    ): NativeBitmap {
        if (!sourceBitmap.isNativeActive()) return sourceBitmap

        val width = sourceBitmap.getWidth()
        val height = sourceBitmap.getHeight()
        if (width <= 0 || height <= 0) return sourceBitmap

        val rawBmp = sourceBitmap.getImage() ?: return sourceBitmap
        val outBmp = rawBmp.copy(Bitmap.Config.ARGB_8888, true)

        // 1. ƯU TIÊN 1: Chạy trực tiếp qua C++ Native Engine (libmeitu_reborn_native.so)
        if (MeituNativeEngine.isLoaded()) {
            val maskBytes = if (customHairMask != null) {
                val maskScaled = Bitmap.createScaledBitmap(customHairMask, width, height, true)
                val mp = IntArray(width * height)
                maskScaled.getPixels(mp, 0, width, 0, 0, width, height)
                val b = ByteArray(width * height)
                for (i in mp.indices) {
                    b[i] = ((mp[i] ushr 24) and 0xFF).toByte()
                }
                b
            } else {
                null
            }

            val success = MeituNativeEngine.nativeDyeHair(
                outBmp, maskBytes, color.r, color.g, color.b, color.gloss, intensity
            )
            if (success) {
                val outputNative = NativeBitmap.createBitmap(outBmp)
                return outputNative ?: sourceBitmap
            }
        }

        // 2. Dự phòng Fallback: Chạy thuật toán mô phỏng nếu chưa link C++
        val pixels = IntArray(width * height)
        outBmp.getPixels(pixels, 0, width, 0, 0, width, height)

        val targetHsl = FloatArray(3)
        Color.RGBToHSV(color.r, color.g, color.b, targetHsl)

        val hairMaskBuffer: ByteBuffer? = if (customHairMask == null && faceParser != null) {
            faceParser?.parseFace(rawBmp)?.hairMask
        } else {
            null
        }

        val customMaskPixels = if (customHairMask != null) {
            val maskScaled = Bitmap.createScaledBitmap(customHairMask, width, height, true)
            val mp = IntArray(width * height)
            maskScaled.getPixels(mp, 0, width, 0, 0, width, height)
            mp
        } else {
            null
        }

        for (y in 0 until height) {
            val rowOffset = y * width
            for (x in 0 until width) {
                val idx = rowOffset + x

                val maskAlpha: Float = when {
                    customMaskPixels != null -> {
                        ((customMaskPixels[idx] ushr 24) and 0xFF) / 255.0f * intensity
                    }
                    hairMaskBuffer != null -> {
                        val mw = width / 4
                        val mh = height / 4
                        val mx = (x / 4).coerceIn(0, mw - 1)
                        val my = (y / 4).coerceIn(0, mh - 1)
                        val mVal = hairMaskBuffer.get(my * mw + mx).toInt() and 0xFF
                        (mVal / 255.0f) * intensity
                    }
                    else -> {
                        if (y < height * 0.45f) {
                            val edge = 1.0f - (y / (height * 0.45f))
                            (edge * 0.7f * intensity).coerceIn(0f, 1f)
                        } else {
                            0.0f
                        }
                    }
                }

                if (maskAlpha < 0.05f) continue

                val pixel = pixels[idx]
                val a = (pixel ushr 24) and 0xFF
                val r = (pixel ushr 16) and 0xFF
                val g = (pixel ushr 8) and 0xFF
                val b = pixel and 0xFF

                val origLum = (0.299f * r + 0.587f * g + 0.114f * b) / 255.0f

                val blendedH = targetHsl[0]
                val blendedS = min(1.0f, targetHsl[1] * 1.15f)
                val blendedV = min(1.0f, origLum * 1.10f + (origLum * origLum * color.gloss))

                val newRgb = Color.HSVToColor(floatArrayOf(blendedH, blendedS, blendedV))
                val nR = (newRgb ushr 16) and 0xFF
                val nG = (newRgb ushr 8) and 0xFF
                val nB = newRgb and 0xFF

                val outR = (r * (1.0f - maskAlpha) + nR * maskAlpha).toInt().coerceIn(0, 255)
                val outG = (g * (1.0f - maskAlpha) + nG * maskAlpha).toInt().coerceIn(0, 255)
                val outB = (b * (1.0f - maskAlpha) + nB * maskAlpha).toInt().coerceIn(0, 255)

                pixels[idx] = (a shl 24) or (outR shl 16) or (outG shl 8) or outB
            }
        }

        outBmp.setPixels(pixels, 0, width, 0, 0, width, height)
        val outputNative = NativeBitmap.createBitmap(outBmp)
        return outputNative ?: sourceBitmap
    }
}

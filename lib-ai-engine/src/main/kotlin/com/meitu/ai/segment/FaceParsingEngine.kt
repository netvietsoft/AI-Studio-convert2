package com.meitu.ai.segment

import android.content.Context
import android.graphics.Bitmap
import androidx.annotation.Keep
import com.meitu.core.nativeengine.MeituNativeEngine
import java.nio.ByteBuffer

/**
 * Phân đoạn và Tách nền Chân dung (Portrait Matting & Parsing).
 * Kết nối trực tiếp thuật toán C++ Native Alpha Feathering từ MeituNativeEngine.
 */
@Keep
class FaceParsingEngine(private val context: Context) {

    data class ParsingMasks(
        val lipMask: ByteBuffer,
        val skinMask: ByteBuffer,
        val hairMask: ByteBuffer,
        val portraitAlphaMask: ByteArray?,
        val maskWidth: Int,
        val maskHeight: Int
    )

    fun parseFace(bitmap: Bitmap, landmarks106: FloatArray? = null): ParsingMasks {
        val width = bitmap.width
        val height = bitmap.height
        val maskW = width / 4
        val maskH = height / 4
        val size = maskW * maskH

        val lipBuffer = ByteBuffer.allocateDirect(size)
        val skinBuffer = ByteBuffer.allocateDirect(size)
        val hairBuffer = ByteBuffer.allocateDirect(size)

        // 1. Tạo 8-bit Alpha Mask có viền tóc mềm mại bằng C++ Native
        var alphaMaskBytes: ByteArray? = null
        if (MeituNativeEngine.isLoaded()) {
            alphaMaskBytes = MeituNativeEngine.nativeGeneratePortraitAlphaMask(bitmap, landmarks106)
        }

        // 2. Thử nghiệm phân đoạn chuẩn xác cao bằng C++ Native BiSeNet 19-Class Engine
        var bisenetParsed = false
        if (MeituNativeEngine.isLoaded()) {
            try {
                val fullMask512 = ByteArray(512 * 512)
                if (MeituNativeEngine.nativeParseFace19(bitmap, fullMask512)) {
                    // Trích xuất trực tiếp các lớp giải phẫu chính xác từng bit/pixel từ BiSeNet
                    for (y in 0 until maskH) {
                        val srcY = (y * 512) / maskH
                        for (x in 0 until maskW) {
                            val srcX = (x * 512) / maskW
                            val cls = fullMask512[srcY * 512 + srcX].toInt() and 0xFF

                            // 12: U_LIP, 13: L_LIP, 11: MOUTH
                            val isLip = (cls == MeituNativeEngine.BISENET_CLASS_U_LIP || 
                                         cls == MeituNativeEngine.BISENET_CLASS_L_LIP ||
                                         cls == MeituNativeEngine.BISENET_CLASS_MOUTH)

                            // 1: SKIN, 10: NOSE, 14: NECK
                            val isSkin = (cls == MeituNativeEngine.BISENET_CLASS_SKIN || 
                                          cls == MeituNativeEngine.BISENET_CLASS_NOSE || 
                                          cls == MeituNativeEngine.BISENET_CLASS_NECK)

                            // 17: HAIR
                            val isHair = (cls == MeituNativeEngine.BISENET_CLASS_HAIR)

                            lipBuffer.put(if (isLip) 255.toByte() else 0.toByte())
                            skinBuffer.put(if (isSkin && !isLip) 255.toByte() else 0.toByte())
                            hairBuffer.put(if (isHair) 255.toByte() else 0.toByte())
                        }
                    }
                    bisenetParsed = true
                }
            } catch (e: Throwable) {
                bisenetParsed = false
            }
        }

        // 3. Fallback Heuristic nếu BiSeNet native không khả dụng
        if (!bisenetParsed) {
            lipBuffer.position(0)
            skinBuffer.position(0)
            hairBuffer.position(0)

            val samplePixels = IntArray(maskW * maskH)
            val scaledBitmap = Bitmap.createScaledBitmap(bitmap, maskW, maskH, false)
            scaledBitmap.getPixels(samplePixels, 0, maskW, 0, 0, maskW, maskH)
            if (scaledBitmap != bitmap) {
                scaledBitmap.recycle()
            }

            for (y in 0 until maskH) {
                val normY = y.toFloat() / maskH
                for (x in 0 until maskW) {
                    val normX = x.toFloat() / maskW
                    val color = samplePixels[y * maskW + x]
                    val r = (color ushr 16) and 0xFF
                    val g = (color ushr 8) and 0xFF
                    val b = color and 0xFF

                    val maxC = kotlin.math.max(r, kotlin.math.max(g, b))
                    val minC = kotlin.math.min(r, kotlin.math.min(g, b))
                    val isSkin = (r > 95 && g > 40 && b > 20) &&
                            (maxC - minC > 15) &&
                            (kotlin.math.abs(r - g) > 15) &&
                            (r > g && r > b)

                    val isLipRegion = (normY in 0.55f..0.85f) && (normX in 0.35f..0.65f)
                    val isLipColor = (r > 110 && r > g * 1.20f && r > b * 1.20f && (g - b) < 45)
                    val isLip = isLipRegion && isLipColor

                    val lum = (0.299f * r + 0.587f * g + 0.114f * b).toInt()
                    val isHairRegion = (normY < 0.45f) || (normX < 0.25f || normX > 0.75f)
                    val isHair = isHairRegion && (lum < 85)

                    lipBuffer.put(if (isLip) 255.toByte() else 0.toByte())
                    skinBuffer.put(if (isSkin && !isLip) 255.toByte() else 0.toByte())
                    hairBuffer.put(if (isHair) 255.toByte() else 0.toByte())
                }
            }
        }

        lipBuffer.rewind()
        skinBuffer.rewind()
        hairBuffer.rewind()

        return ParsingMasks(
            lipMask = lipBuffer,
            skinMask = skinBuffer,
            hairMask = hairBuffer,
            portraitAlphaMask = alphaMaskBytes,
            maskWidth = maskW,
            maskHeight = maskH
        )
    }

    /**
     * Phân đoạn trực tiếp 19 lớp Semantic BiSeNet kích thước 512x512.
     * Trả về mảng 512x512 phần tử nhãn từ 0..18 (Mục tiêu từng bit/pixel).
     */
    fun parseFace19BiSeNet(bitmap: Bitmap): ByteArray? {
        if (!MeituNativeEngine.isLoaded()) return null
        val mask512 = ByteArray(512 * 512)
        val ok = MeituNativeEngine.nativeParseFace19(bitmap, mask512)
        return if (ok) mask512 else null
    }

    /**
     * Trích xuất mặt nạ đơn lớp 512x512 từ nhãn BiSeNet classId.
     */
    fun extractClassAlpha(mask512: ByteArray, classId: Int): ByteArray? {
        if (!MeituNativeEngine.isLoaded()) return null
        val alpha512 = ByteArray(512 * 512)
        val ok = MeituNativeEngine.nativeExtractBiSeNetClassMask(mask512, classId, alpha512)
        return if (ok) alpha512 else null
    }


    /**
     * Ghép phông nền mới chuẩn C++ Alpha Blending.
     */
    fun replaceBackground(fgBitmap: Bitmap, bgBitmap: Bitmap, alphaMask: ByteArray): Boolean {
        return if (MeituNativeEngine.isLoaded()) {
            MeituNativeEngine.nativeCompositeBackground(fgBitmap, alphaMask, bgBitmap)
        } else false
    }

    /**
     * Xóa phông Bokeh DSLR chuẩn quang học điều chế độ sâu C++.
     */
    fun applyBokehBlur(bitmap: Bitmap, alphaMask: ByteArray, maxRadius: Float = 16f): Boolean {
        return if (MeituNativeEngine.isLoaded()) {
            MeituNativeEngine.nativeApplyBokehBlur(bitmap, alphaMask, maxRadius)
        } else false
    }
}

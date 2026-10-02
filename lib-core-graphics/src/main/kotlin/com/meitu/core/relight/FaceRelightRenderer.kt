package com.meitu.core.relight

import android.graphics.Bitmap
import android.graphics.PointF
import androidx.annotation.Keep
import com.meitu.core.ar.Face3DMeshReconstructor
import com.meitu.core.nativeengine.MeituNativeEngine
import com.meitu.core.types.FaceData
import com.meitu.core.types.NativeBitmap
import kotlin.math.*

/**
 * Engine chiếu sáng khuôn mặt 3D chuẩn Studio (3D Face Relighting Engine).
 * Tích hợp song song 2 tầng:
 * 1. Tầng C++ Native độc lập (MeituNativeEngine - libmeitu_reborn_native.so, OpenMP đa luồng, Little-Endian chuẩn)
 * 2. Tầng fallback giải tích toán học nếu thư viện chưa tải.
 */
@Keep
class FaceRelightRenderer {

    enum class LightPreset(
        val presetId: Int,
        val azimuthDeg: Float,
        val elevationDeg: Float,
        val ambient: Float,
        val diffuse: Float,
        val specular: Float,
        val shininess: Float
    ) {
        REMBRANDT(0, -45.0f, 35.0f, 0.40f, 0.75f, 0.35f, 16.0f),
        CONTOUR(1, 60.0f, 15.0f, 0.35f, 0.80f, 0.40f, 24.0f),
        STAGE(2, 0.0f, 50.0f, 0.20f, 0.95f, 0.50f, 32.0f),
        RING_LIGHT(3, 0.0f, 0.0f, 0.65f, 0.45f, 0.25f, 8.0f),
        CUSTOM(0, 0.0f, 25.0f, 0.40f, 0.70f, 0.30f, 16.0f)
    }

    fun applyRelighting(
        sourceBitmap: NativeBitmap,
        faceData: FaceData,
        preset: LightPreset = LightPreset.REMBRANDT,
        intensity: Float = 0.75f,
        faceIndex: Int = 0,
        skinMask: Bitmap? = null
    ): NativeBitmap {
        if (!sourceBitmap.isNativeActive() || faceData.getFaceCount() == 0) {
            return sourceBitmap
        }

        val width = sourceBitmap.getWidth()
        val height = sourceBitmap.getHeight()
        if (width <= 0 || height <= 0) return sourceBitmap

        val landmarks = faceData.getFaceLandmark(faceIndex, 106, width, height) ?: return sourceBitmap
        val faceRect = faceData.getFaceRect(faceIndex, width, height) ?: return sourceBitmap

        val rawBmp = sourceBitmap.getImage() ?: return sourceBitmap
        val outBmp = rawBmp.copy(Bitmap.Config.ARGB_8888, true)

        val lmArray = FloatArray(106 * 2)
        for (i in 0 until min(106, landmarks.size)) {
            lmArray[i * 2] = landmarks[i].x
            lmArray[i * 2 + 1] = landmarks[i].y
        }

        // Chuẩn bị mảng byte mask da (Skin Mask) nếu có
        val maskBytes = if (skinMask != null) {
            val maskScaled = Bitmap.createScaledBitmap(skinMask, width, height, true)
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

        // 1. ƯU TIÊN 1: Chạy trực tiếp C++ Native Engine (libmeitu_reborn_native.so)
        if (MeituNativeEngine.isLoaded()) {
            val success = MeituNativeEngine.nativeApply3DRelight(
                outBmp, lmArray, maskBytes, preset.presetId, intensity
            )
            if (success) {
                val outputNative = NativeBitmap.createBitmap(outBmp)
                return outputNative ?: sourceBitmap
            }
        }

        // 2. Dự phòng Fallback
        val azRad = Math.toRadians(preset.azimuthDeg.toDouble())
        val elRad = Math.toRadians(preset.elevationDeg.toDouble())
        val lx = (cos(elRad) * sin(azRad)).toFloat()
        val ly = (-sin(elRad)).toFloat()
        val lz = (cos(elRad) * cos(azRad)).toFloat()

        val noseCenter = landmarks[46]
        val faceRadius = max(faceRect.width().toFloat(), faceRect.height().toFloat()) * 0.65f
        val faceRadiusSq = faceRadius * faceRadius

        val pixels = IntArray(width * height)
        outBmp.getPixels(pixels, 0, width, 0, 0, width, height)

        val minX = max(0, faceRect.left - 20)
        val maxX = min(width - 1, faceRect.right + 20)
        val minY = max(0, faceRect.top - 20)
        val maxY = min(height - 1, faceRect.bottom + 20)

        for (y in minY..maxY) {
            val rowOffset = y * width
            val dy = y - noseCenter.y
            for (x in minX..maxX) {
                val dx = x - noseCenter.x
                val distSq = dx * dx + dy * dy
                if (distSq > faceRadiusSq) continue

                val idx = rowOffset + x
                val skinWeight = if (maskBytes != null) {
                    (maskBytes[idx].toInt() and 0xFF) / 255.0f
                } else {
                    1.0f
                }
                if (skinWeight < 0.05f) continue

                val edgeWeight = (1.0f - distSq / faceRadiusSq).pow(2) * intensity * skinWeight
                val nx = dx / faceRadius
                val ny = dy / faceRadius
                val nzSq = max(0.04f, 1.0f - nx * nx - ny * ny)
                val nz = sqrt(nzSq)

                val nDotL = max(0.0f, nx * lx + ny * ly + nz * lz)

                val hx = lx
                val hy = ly
                val hz = lz + 1.0f
                val hLen = max(0.001f, sqrt(hx * hx + hy * hy + hz * hz))
                val nDotH = max(0.0f, (nx * hx + ny * hy + nz * hz) / hLen)
                val specularVal = nDotH.pow(preset.shininess) * preset.specular

                val lightFactor = preset.ambient + (preset.diffuse * nDotL) + specularVal

                val color = pixels[idx]
                val a = (color ushr 24) and 0xFF
                val r = (color ushr 16) and 0xFF
                val g = (color ushr 8) and 0xFF
                val b = color and 0xFF

                val newR = min(255, (r * (1.0f - edgeWeight) + r * lightFactor * edgeWeight).toInt())
                val newG = min(255, (g * (1.0f - edgeWeight) + g * lightFactor * edgeWeight).toInt())
                val newB = min(255, (b * (1.0f - edgeWeight) + b * lightFactor * edgeWeight).toInt())

                pixels[idx] = (a shl 24) or (newR shl 16) or (newG shl 8) or newB
            }
        }
        outBmp.setPixels(pixels, 0, width, 0, 0, width, height)
        val outputNative = NativeBitmap.createBitmap(outBmp)
        return outputNative ?: sourceBitmap
    }
}

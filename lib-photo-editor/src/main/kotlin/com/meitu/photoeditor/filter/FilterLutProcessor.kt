package com.meitu.photoeditor.filter

import android.content.Context
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.util.Log
import android.util.LruCache
import androidx.annotation.Keep
import com.meitu.core.nativeengine.MeituNativeEngine
import java.io.InputStream
import kotlin.math.max
import kotlin.math.min

/**
 * Bộ xử lý Filter và LUT chuẩn C++ Native và 3D Cube Color Grading.
 * Kết nối C++ Trilinear 3D Interpolation qua MeituNativeEngine.
 */
@Keep
class FilterLutProcessor(private val context: Context) {

    private val lutCache = LruCache<String, Bitmap>(15)

    companion object {
        private const val TAG = "FilterLutProcessor"
    }

    fun applyFilter(bitmap: Bitmap, filterName: String, intensity: Float): Bitmap {
        if (intensity <= 0.001f || filterName.isEmpty() || filterName.equals("original", ignoreCase = true)) {
            return bitmap
        }

        val clampedIntensity = intensity.coerceIn(0f, 1f)
        val lutAssetPath = if (filterName.startsWith("luts/")) filterName else "luts/$filterName"

        try {
            val lutBitmap = getLutBitmap(lutAssetPath)
            val outBitmap = if (bitmap.isMutable) bitmap else bitmap.copy(Bitmap.Config.ARGB_8888, true)

            if (lutBitmap != null && MeituNativeEngine.isLoaded()) {
                val success = MeituNativeEngine.nativeApply3DLut(outBitmap, lutBitmap, clampedIntensity)
                if (success) return outBitmap
            }

            // Studio-Grade 12 Aesthetic Filter Presets with C++ Native Color Engine
            if (MeituNativeEngine.isLoaded()) {
                val lower = filterName.lowercase()
                var b = 0f; var c = 0f; var s = 0f; var t = 0f; var tint = 0f; var exp = 0f
                when {
                    lower.contains("fuji") || lower.contains("velvia") -> {
                        t = 10f * clampedIntensity; s = 25f * clampedIntensity; c = 18f * clampedIntensity; tint = -10f * clampedIntensity
                    }
                    lower.contains("kodak") || lower.contains("portra") -> {
                        t = 18f * clampedIntensity; s = 10f * clampedIntensity; c = 12f * clampedIntensity; tint = 8f * clampedIntensity; exp = 4f * clampedIntensity
                    }
                    lower.contains("cyber") || lower.contains("neon") -> {
                        t = -30f * clampedIntensity; s = 45f * clampedIntensity; c = 25f * clampedIntensity; tint = 35f * clampedIntensity
                    }
                    lower.contains("vintage") || lower.contains("1970") || lower.contains("retro") || lower.contains("vhs") -> {
                        t = 30f * clampedIntensity; s = -10f * clampedIntensity; c = -8f * clampedIntensity; tint = 12f * clampedIntensity; exp = 6f * clampedIntensity
                    }
                    lower.contains("bw") || lower.contains("black") || lower.contains("monochrome") -> {
                        s = -100f * clampedIntensity; c = 32f * clampedIntensity; b = 4f * clampedIntensity
                    }
                    lower.contains("morandi") || lower.contains("pastel") -> {
                        s = -28f * clampedIntensity; c = 8f * clampedIntensity; b = 10f * clampedIntensity; t = 5f * clampedIntensity
                    }
                    lower.contains("nordic") || lower.contains("cold") || lower.contains("cool") -> {
                        t = -35f * clampedIntensity; s = -8f * clampedIntensity; c = 15f * clampedIntensity; tint = -12f * clampedIntensity
                    }
                    lower.contains("sunset") || lower.contains("golden") || lower.contains("warm") -> {
                        t = 40f * clampedIntensity; s = 20f * clampedIntensity; c = 14f * clampedIntensity; tint = 15f * clampedIntensity; b = 6f * clampedIntensity
                    }
                    lower.contains("french") || lower.contains("romance") -> {
                        tint = 22f * clampedIntensity; t = 12f * clampedIntensity; s = 14f * clampedIntensity; b = 12f * clampedIntensity; c = -6f * clampedIntensity
                    }
                    lower.contains("japanese") || lower.contains("clean") -> {
                        exp = 15f * clampedIntensity; b = 14f * clampedIntensity; c = -5f * clampedIntensity; s = 8f * clampedIntensity; t = -8f * clampedIntensity
                    }
                    lower.contains("cinematic") || lower.contains("film") -> {
                        c = 28f * clampedIntensity; s = 18f * clampedIntensity; t = 12f * clampedIntensity; tint = -15f * clampedIntensity
                    }
                    else -> {
                        b = 8f * clampedIntensity; c = 12f * clampedIntensity; s = 15f * clampedIntensity; t = 6f * clampedIntensity
                    }
                }
                val tuned = MeituNativeEngine.nativeApplyColorTuning(outBitmap, b, c, s, t, tint, exp)
                if (tuned) return outBitmap
            }

            return outBitmap
        } catch (t: Throwable) {
            Log.e(TAG, "Native filter processing error, fallback", t)
            return bitmap
        }
    }

    private fun getLutBitmap(assetPath: String): Bitmap? {
        val cached = lutCache.get(assetPath)
        if (cached != null) return cached

        return try {
            val isStream: InputStream = context.assets.open(assetPath)
            val bmp = BitmapFactory.decodeStream(isStream)
            isStream.close()
            if (bmp != null) {
                lutCache.put(assetPath, bmp)
            }
            bmp
        } catch (e: Exception) {
            null
        }
    }
}

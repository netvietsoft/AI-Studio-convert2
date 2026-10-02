package com.meitu.core.types

import android.graphics.Bitmap
import android.graphics.Color
import android.graphics.RectF
import androidx.annotation.Keep
import com.meitu.core.MteApplication

/**
 * Canvas Native vẽ trực tiếp lên bộ nhớ C++ của NativeBitmap.
 * Nguồn: com.meitu.core.types.NativeCanvas.java
 * Kết nối trực tiếp với libbmpKit.so
 */
@Keep
class NativeCanvas(private var mBitmap: NativeBitmap?) {

    companion object {
        init {
            MteApplication.loadLibrary()
        }

        @JvmStatic
        private external fun nativeDraw(j: Long, j2: Long, fArr: FloatArray, fArr2: FloatArray): Boolean

        @JvmStatic
        private external fun nativeDraw_bitmap(j: Long, bitmap: Bitmap, fArr: FloatArray, fArr2: FloatArray): Boolean

        @JvmStatic
        private external fun nativeDraw_color(j: Long, fArr: FloatArray, i: Int): Boolean
    }

    fun drawARGB(rectF: RectF?, i: Int, i2: Int, i3: Int, i4: Int) {
        drawColor(rectF, Color.argb(i, i2, i3, i4))
    }

    fun drawBitmap(srcNativeBitmap: NativeBitmap?, srcRect: RectF?, dstRect: RectF?): Boolean {
        val target = this.mBitmap ?: return false
        if (srcNativeBitmap == null) return false

        val fSrc = if (srcRect != null) {
            floatArrayOf(srcRect.left, srcRect.top, srcRect.right, srcRect.bottom)
        } else {
            floatArrayOf(0.0f, 0.0f, 1.0f, 1.0f)
        }

        val fDst = if (dstRect != null) {
            floatArrayOf(dstRect.left, dstRect.top, dstRect.right, dstRect.bottom)
        } else {
            floatArrayOf(0.0f, 0.0f, 1.0f, 1.0f)
        }

        return try {
            nativeDraw(target.nativeInstance(), srcNativeBitmap.nativeInstance(), fSrc, fDst)
        } catch (e: UnsatisfiedLinkError) {
            false
        }
    }

    fun drawColor(rectF: RectF?, colorInt: Int) {
        val target = this.mBitmap ?: return
        val fRect = if (rectF != null) {
            floatArrayOf(rectF.left, rectF.top, rectF.right, rectF.bottom)
        } else {
            floatArrayOf(0.0f, 0.0f, 1.0f, 1.0f)
        }
        try {
            nativeDraw_color(target.nativeInstance(), fRect, colorInt)
        } catch (ignored: UnsatisfiedLinkError) {
        }
    }

    fun drawRGB(rectF: RectF?, r: Int, g: Int, b: Int) {
        drawColor(rectF, Color.rgb(r, g, b))
    }

    fun drawARGB(a: Int, r: Int, g: Int, b: Int) {
        drawColor(null, Color.argb(a, r, g, b))
    }

    fun drawRGB(r: Int, g: Int, b: Int) {
        drawColor(null, Color.rgb(r, g, b))
    }

    fun drawColor(colorInt: Int) {
        drawColor(null, colorInt)
    }

    fun drawBitmap(bitmap: Bitmap?, srcRect: RectF?, dstRect: RectF?): Boolean {
        val target = this.mBitmap ?: return false
        if (bitmap == null) return false

        val fSrc = if (srcRect != null) {
            floatArrayOf(srcRect.left, srcRect.top, srcRect.right, srcRect.bottom)
        } else {
            floatArrayOf(0.0f, 0.0f, 1.0f, 1.0f)
        }

        val fDst = if (dstRect != null) {
            floatArrayOf(dstRect.left, dstRect.top, dstRect.right, dstRect.bottom)
        } else {
            floatArrayOf(0.0f, 0.0f, 1.0f, 1.0f)
        }

        return try {
            nativeDraw_bitmap(target.nativeInstance(), bitmap, fSrc, fDst)
        } catch (e: UnsatisfiedLinkError) {
            false
        }
    }
}

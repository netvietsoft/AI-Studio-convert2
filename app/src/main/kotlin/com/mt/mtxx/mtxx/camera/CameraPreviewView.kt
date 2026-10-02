// Source decompiled: com.mt.mtxx.mtxx.camera.CameraPreviewView.kt
package com.mt.mtxx.mtxx.camera

import android.content.Context
import android.graphics.SurfaceTexture
import android.util.AttributeSet
import android.util.Log
import android.view.TextureView
import android.view.ViewGroup

/**
 * View hiển thị luồng Camera thời gian thực (Camera Preview).
 * Hỗ trợ tỉ lệ khung hình (1:1, 4:3, 16:9, Full Screen) và bộ đệm SurfaceTexture.
 *
 * Real-time camera preview rendering view using TextureView.
 * Supports standard aspect ratios and texture callbacks.
 */
class CameraPreviewView @JvmOverloads constructor(
    context: Context,
    attrs: AttributeSet? = null,
    defStyleAttr: Int = 0
) : TextureView(context, attrs, defStyleAttr), TextureView.SurfaceTextureListener {

    private var aspectRatioWidth = 3
    private var aspectRatioHeight = 4
    private var previewCallback: PreviewCallback? = null

    interface PreviewCallback {
        fun onSurfaceReady(surfaceTexture: SurfaceTexture, width: Int, height: Int)
        fun onSurfaceDestroyed()
    }

    init {
        surfaceTextureListener = this
    }

    fun setPreviewCallback(callback: PreviewCallback) {
        this.previewCallback = callback
    }

    fun setAspectRatio(width: Int, height: Int) {
        if (width <= 0 || height <= 0) return
        this.aspectRatioWidth = width
        this.aspectRatioHeight = height
        requestLayout()
    }

    override fun onMeasure(widthMeasureSpec: Int, heightMeasureSpec: Int) {
        super.onMeasure(widthMeasureSpec, heightMeasureSpec)
        val width = MeasureSpec.getSize(widthMeasureSpec)
        val height = MeasureSpec.getSize(heightMeasureSpec)

        if (aspectRatioWidth == 0 || aspectRatioHeight == 0) {
            setMeasuredDimension(width, height)
        } else {
            if (width < height * aspectRatioWidth / aspectRatioHeight) {
                setMeasuredDimension(width, width * aspectRatioHeight / aspectRatioWidth)
            } else {
                setMeasuredDimension(height * aspectRatioWidth / aspectRatioHeight, height)
            }
        }
    }

    override fun onSurfaceTextureAvailable(surface: SurfaceTexture, width: Int, height: Int) {
        Log.d(TAG, "onSurfaceTextureAvailable: $width x $height")
        previewCallback?.onSurfaceReady(surface, width, height)
    }

    override fun onSurfaceTextureSizeChanged(surface: SurfaceTexture, width: Int, height: Int) {
        Log.d(TAG, "onSurfaceTextureSizeChanged: $width x $height")
    }

    override fun onSurfaceTextureDestroyed(surface: SurfaceTexture): Boolean {
        Log.d(TAG, "onSurfaceTextureDestroyed")
        previewCallback?.onSurfaceDestroyed()
        return true
    }

    override fun onSurfaceTextureUpdated(surface: SurfaceTexture) {
        // Khung hình mới được render
    }

    companion object {
        private const val TAG = "CameraPreviewView"
    }
}
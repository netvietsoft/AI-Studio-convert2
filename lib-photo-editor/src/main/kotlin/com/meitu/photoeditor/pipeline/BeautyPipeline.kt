package com.meitu.photoeditor.pipeline

import android.content.Context
import android.graphics.Bitmap
import com.meitu.ai.facedetect.FaceDetector106
import com.meitu.ai.segment.FaceParsingEngine
import com.meitu.core.MTFilterKernelRender
import com.meitu.photoeditor.beauty.SkinSoftenProcessor
import com.meitu.photoeditor.beauty.SlimReshapeProcessor
import com.meitu.photoeditor.makeup.MakeupProcessor
import com.meitu.photoeditor.filter.FilterLutProcessor

/**
 * Pipeline xử lý ảnh chân dung đa tầng của Meitu Reborn.
 * Quy trình:
 * 1. AI Phân tích khuôn mặt 106 điểm & Mặt nạ da.
 * 2. Làm mịn da & Tẩy khuyết điểm (SkinSoften).
 * 3. Gọt mặt & nắn bóp (Slim/Reshape).
 * 4. Trang điểm kỹ thuật số (Makeup son, phấn, mắt).
 * 5. Bộ lọc màu (3D LUT Filter).
 */
class BeautyPipeline(private val context: Context) {

    private val faceDetector = FaceDetector106(context)
    private val faceParsing = FaceParsingEngine(context)
    private val skinSoften = SkinSoftenProcessor()
    private val slimReshape = SlimReshapeProcessor()
    private val makeup = MakeupProcessor()
    private val filterLut = FilterLutProcessor(context)

    data class BeautyParams(
        val smoothLevel: Float = 0.5f,
        val whiteLevel: Float = 0.3f,
        val slimLevel: Float = 0.4f,
        val lipstickAlpha: Float = 0.6f,
        val lipstickColorHex: String = "#FF1493",
        val filterName: String? = null,
        val filterIntensity: Float = 1.0f
    )

    fun processImage(sourceBitmap: Bitmap, params: BeautyParams): Bitmap {
        var currentBitmap = sourceBitmap.copy(Bitmap.Config.ARGB_8888, true)

        // 1. Phân tích AI
        val faceResult = faceDetector.detect(currentBitmap)
        val parsingResult = faceParsing.parseFace(currentBitmap)

        // 2. Làm mịn da
        if (params.smoothLevel > 0f || params.whiteLevel > 0f) {
            currentBitmap = skinSoften.applySoften(currentBitmap, params.smoothLevel, params.whiteLevel, parsingResult.skinMask)
        }

        // 3. Gọt mặt & nắn bóp
        if (params.slimLevel > 0f && faceResult != null) {
            currentBitmap = slimReshape.applySlim(currentBitmap, params.slimLevel, faceResult.landmarks106)
        }

        // 4. Trang điểm
        if (params.lipstickAlpha > 0f) {
            currentBitmap = makeup.applyMakeup(currentBitmap, params.lipstickColorHex, params.lipstickAlpha, parsingResult.lipMask)
        }

        // 5. Bộ lọc 3D LUT
        if (!params.filterName.isNullOrEmpty()) {
            currentBitmap = filterLut.applyFilter(currentBitmap, params.filterName, params.filterIntensity)
        }

        return currentBitmap
    }
}

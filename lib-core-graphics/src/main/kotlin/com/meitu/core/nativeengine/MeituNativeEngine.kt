package com.meitu.core.nativeengine

import android.graphics.Bitmap
import androidx.annotation.Keep

/**
 * Engine xử lý C++ Native tự phát triển (100% Native C++ Source Code).
 * Độc lập hoàn toàn, không phụ thuộc vào các file .so đóng kín của Meitu.
 * Tải thư viện libmeitu_reborn_native.so được biên dịch trực tiếp từ NDK CMake.
 */
@Keep
object MeituNativeEngine {

    private var isNativeLoaded = false

    init {
        try {
            System.loadLibrary("omp")
        } catch (e: Throwable) {}
        try {
            System.loadLibrary("meitu_reborn_native")
            isNativeLoaded = true
            android.util.Log.i("MeituNativeEngine", "✅ libmeitu_reborn_native.so loaded successfully!")
        } catch (e: Throwable) {
            isNativeLoaded = false
            android.util.Log.e("MeituNativeEngine", "❌ Failed to load libmeitu_reborn_native.so: " + e.message)
        }
    }

    fun isLoaded(): Boolean = isNativeLoaded

    // 1. 3D Face Relighting (C++ Blinn-Phong Shading on Direct Bitmap Pointers with OpenMP & Skin Mask)
    @JvmStatic
    external fun nativeApply3DRelight(
        bitmap: Bitmap,
        landmarks106: FloatArray,
        skinMaskArray: ByteArray?,
        preset: Int,
        intensity: Float
    ): Boolean

    // 2. AI Hair Daub (C++ Luminosity-Preserving Color Blend with OpenMP)
    @JvmStatic
    external fun nativeDyeHair(
        bitmap: Bitmap,
        maskArray: ByteArray?,
        targetR: Int,
        targetG: Int,
        targetB: Int,
        gloss: Float,
        intensity: Float
    ): Boolean

    // 2.1 Hair Engine Material-Aware Recolor (SPEC Mục 5: Tóc)
    @JvmStatic
    external fun nativeApplyHairMaterialRecolor(
        bitmap: Bitmap,
        rootR: Int, rootG: Int, rootB: Int,
        tipR: Int, tipG: Int, tipB: Int,
        ombrePos: Float,
        intensity: Float,
        shineBoost: Float,
        isHighlight: Boolean
    ): Boolean

    // 2.2 Hair Engine Volume & Density (Làm phồng chân tóc & dày mỏng biểu kiến)
    @JvmStatic
    external fun nativeAdjustHairVolumeDensity(
        bitmap: Bitmap,
        volumeDelta: Float,
        densityDelta: Float
    ): Boolean

    // 2.3 Hair Engine Curl & Wave (Duỗi thẳng / uốn xoăn sóng)
    @JvmStatic
    external fun nativeAdjustHairCurlWave(
        bitmap: Bitmap,
        curlDelta: Float
    ): Boolean

    // 2.4 Hair Engine Bangs & Hairline (Tóc mái & hạ chân tóc)
    @JvmStatic
    external fun nativeAdjustHairlineBangs(
        bitmap: Bitmap,
        bangShape: Int,
        hairlineDelta: Float
    ): Boolean

    // 2.5 Hair Engine Scalp Reconstruction (Xóa tóc & tái tạo da đầu)
    @JvmStatic
    external fun nativeRemoveHairScalp(
        bitmap: Bitmap,
        removalStrength: Float
    ): Boolean

    // 2.6 Cắt tóc ngắn & Tạo kiểu tóc (Short Haircut & Hairstyle Suite)
    // styleCode: 1: Pixie/Short Crop, 2: Buzzcut, 3: Fade Undercut, 4: Short Bob, 5: Korean Side Part, 6: Layer Cut
    @JvmStatic
    external fun nativeApplyHairstyleTrim(
        bitmap: Bitmap,
        styleCode: Int,
        intensity: Float
    ): Boolean

    // 2.7 Đồng bộ hóa Face Geometry & Landmarks giữa Kotlin và C++ LandmarkFusionEngine
    @JvmStatic
    external fun nativeUpdateFaceGeometry(
        landmarks106: FloatArray?,
        denseMesh478: FloatArray?,
        boxX1: Float,
        boxY1: Float,
        boxX2: Float,
        boxY2: Float
    ): Boolean

    @JvmStatic
    external fun nativeResetFusedGeometry(): Boolean

    // 3. AR Face Tracking Anchors (C++ 5-Anchor Real-time Tracking & Gesture Detection)
    @JvmStatic
    external fun nativeTrackFaceAnchors(
        landmarks106: FloatArray,
        width: Int,
        height: Int,
        roll: Float,
        pitch: Float,
        yaw: Float
    ): FloatArray?

    // 4. 3D Mesh & Head Pose Matrix (C++ 3DMM Mesh & 4x4 Model-View Matrix with Full Delaunay Topology)
    @JvmStatic
    external fun nativeReconstruct3DMeshPose(
        landmarks106: FloatArray,
        width: Int,
        height: Int,
        pitch: Float,
        yaw: Float,
        roll: Float
    ): FloatArray?

    // 5. C++ Native Liquify Warp (Nắn bóp mặt, gọt cằm, to mắt, thon mũi - OpenMP 60 FPS)
    @JvmStatic
    external fun nativeApplyLiquifyWarp(
        bitmap: Bitmap,
        startX: Float,
        startY: Float,
        endX: Float,
        endY: Float,
        radius: Float,
        intensity: Float,
        mode: Int
    ): Boolean

    // 6. C++ Native 3D LUT Interpolation (Trilinear 512x512 HALD / 256x16 Strip)
    @JvmStatic
    external fun nativeApply3DLut(
        bitmap: Bitmap,
        lutBitmap: Bitmap,
        intensity: Float
    ): Boolean

    // 7. C++ Native 6-Channel Color Tuning (Brightness, Contrast, Saturation, Temp, Tint, Exposure)
    @JvmStatic
    external fun nativeApplyColorTuning(
        bitmap: Bitmap,
        brightness: Float,
        contrast: Float,
        saturation: Float,
        temperature: Float,
        tint: Float,
        exposure: Float
    ): Boolean

    // 8. C++ Native AI Portrait Matting (Tạo 8-bit Alpha Mask tóc mềm mượt)
    @JvmStatic
    external fun nativeGeneratePortraitAlphaMask(
        bitmap: Bitmap,
        landmarks106: FloatArray?
    ): ByteArray?

    // 9. C++ Native Composite Background (Ghép nền mới không lem viền)
    @JvmStatic
    external fun nativeCompositeBackground(
        fgBitmap: Bitmap,
        alphaMask: ByteArray,
        bgBitmap: Bitmap
    ): Boolean

    // 10. C++ Native Depth Bokeh Blur (Xóa phông xóa mù mịt chuẩn khẩu độ DSLR)
    @JvmStatic
    external fun nativeApplyBokehBlur(
        bitmap: Bitmap,
        alphaMask: ByteArray,
        maxBlurRadius: Float
    ): Boolean

    // 11. C++ Native Teeth Whitening (Trắng sứ, Trắng ngà, Men sứ, Tông sẫm)
    @JvmStatic
    external fun nativeApplyTeethWhitening(
        bitmap: Bitmap,
        mouthCenterX: Float,
        mouthCenterY: Float,
        radiusX: Float,
        radiusY: Float,
        shadeMode: Int,
        intensity: Float
    ): Boolean

    // 12. C++ Native Teeth Reshape (To/Nhỏ, Đều/Thưa, Hô/Vâu/Quặp)
    @JvmStatic
    external fun nativeApplyTeethReshape(
        bitmap: Bitmap,
        mouthCenterX: Float,
        mouthCenterY: Float,
        radiusX: Float,
        radiusY: Float,
        shapeMode: Int,
        value: Float
    ): Boolean

    // 13. C++ Native Ear Reshape (To/Nhỏ/Ép tai vểnh, Dái tai Dày/Mỏng)
    @JvmStatic
    external fun nativeApplyEarReshape(
        bitmap: Bitmap,
        leftEarX: Float,
        leftEarY: Float,
        rightEarX: Float,
        rightEarY: Float,
        radius: Float,
        shapeMode: Int,
        value: Float,
        isLeftVisible: Boolean = true,
        isRightVisible: Boolean = true
    ): Boolean

    // 14. C++ Native Ear Color Tuning (Hồng hào ↔ Nhợt nhạt)
    @JvmStatic
    external fun nativeApplyEarColorTuning(
        bitmap: Bitmap,
        landmarks106: FloatArray?,
        leftEarX: Float,
        leftEarY: Float,
        rightEarX: Float,
        rightEarY: Float,
        radius: Float,
        colorTone: Float,
        isLeftVisible: Boolean = true,
        isRightVisible: Boolean = true
    ): Boolean
// 15. C++ Native Camera Shutter Pipeline (AWB Gray-World, Bilateral Denoise, JPEG Lossless 98%)
    @JvmStatic
    external fun nativeProcessShutterCapture(
        bitmap: Bitmap,
        awbMode: Int,
        skinSmooth: Float,
        skinWhitening: Float,
        vLineJaw: Float,
        bigEyes: Float,
        teethShade: Int,
        teethWhitening: Float,
        earReshape: Float,
        earTone: Float,
        landmarks106: FloatArray? = null
    ): Boolean

    // 16. C++ Native Camera Real-time Preview Processor (YUV to RGB, Live 3D LUT, Realtime Smooth)
        @JvmStatic
    external fun nativeProcessCameraPreviewFrame(
        bitmap: Bitmap,
        lutType: Int,
        lutIntensity: Float,
        skinSmooth: Float
    ): Boolean

    // 16b. C++ Native Live Preview Multi-Feature Engine (Full Real-time 0-100% Visual Scaling)
    @JvmStatic
    external fun nativeProcessCameraPreviewFrameFull(
        bitmap: Bitmap,
        lutType: Int,
        lutIntensity: Float,
        skinSmooth: Float,
        skinWhiten: Float,
        faceVLine: Float,
        bigEyes: Float,
        noseShrink: Float,
        lipPlump: Float
    ): Boolean

    // 16c. C++ Native Live Preview Advanced Multi-Feature Engine (All 12 Real-Time Beauty Sliders)
    @JvmStatic
    external fun nativeProcessCameraPreviewFrameAdvanced(
        bitmap: Bitmap,
        lutType: Int,
        lutIntensity: Float,
        skinSmooth: Float,
        skinWhiten: Float,
        faceVLine: Float,
        bigEyes: Float,
        noseShrink: Float,
        lipPlump: Float,
        teethWhiten: Float,
        eyeBags: Float,
        skinClear: Float,
        landmarks106: FloatArray? = null
    ): Boolean

@JvmStatic
    external fun nativeGetVideoCompositedFrame(
        compositorHandle: Long,
        timeUs: Long,
        outBitmap: Bitmap,
        filterType: Int,
        filterIntensity: Float,
        transitionType: Int,
        transitionProgress: Float
    ): Boolean
// 18. C++ Native Ultra-fast YUV420 to RGBA8888 SIMD Converter (NV21 / NV12 / I420)
    @JvmStatic
    external fun nativeConvertYUVToRGBA(
        yuvBytes: ByteArray,
        width: Int,
        height: Int,
        format: Int,
        outBitmap: Bitmap
    ): Boolean

    // 19. C++ Native Localized Color Tuning (Chỉ tác động vùng chọn, không ảnh hưởng nền/tóc/áo)
    @JvmStatic
    external fun nativeApplyLocalizedTuning(
        bitmap: Bitmap,
        centerX: Float,
        centerY: Float,
        radiusX: Float,
        radiusY: Float,
        brightness: Float,
        contrast: Float,
        saturation: Float,
        temperature: Float,
        tint: Float,
        exposure: Float,
        skinToneOnly: Boolean
    ): Boolean

    // 20. C++ Native Localized Skin Bilateral Filter (Làm mịn da, xóa thâm mụn giữ nguyên ánh sáng toàn ảnh)
    @JvmStatic
    external fun nativeApplyLocalizedSkinBilateral(
        bitmap: Bitmap,
        centerX: Float,
        centerY: Float,
        radiusX: Float,
        radiusY: Float,
        smoothStrength: Float,
        brightenStrength: Float
    ): Boolean

    // 21. C++ Native 3DMM Face Reshape (FACE & RATIO 3DMM)
    @JvmStatic
    external fun nativeApply3DMMParam(
        bitmap: Bitmap,
        landmarks106: FloatArray?,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 22. C++ Native Face Presets (Loại khuôn mặt Origin, FineTuning, PhotoGenic, Round, Square, Long, Short)
    @JvmStatic
    external fun nativeApplyFacePreset(
        bitmap: Bitmap,
        landmarks106: FloatArray?,
        presetId: Int,
        intensity: Float
    ): Boolean

    // 23. C++ Native Freeform Mesh Warp & Resizes (Nắn bóp tự do & Thay đổi kích thước)
    @JvmStatic
    external fun nativeApplyFreeformReshape(
        bitmap: Bitmap,
        touchX: Float,
        touchY: Float,
        targetX: Float,
        targetY: Float,
        radius: Float,
        reshapeType: Int,
        intensity: Float
    ): Boolean

    // 24. C++ Native Eye Shape & Morphing
    @JvmStatic
    external fun nativeApplyEyeShape(
        bitmap: Bitmap,
        lxEye: Float, lyEye: Float,
        rxEye: Float, ryEye: Float,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 25. C++ Native Eye Effects (Bright Eye, Whiten Sclera, Remove Redness, Double Eyelid, Sharpen, Clarity, Red Eye)
    @JvmStatic
    external fun nativeApplyEyeEffect(
        bitmap: Bitmap,
        lxEye: Float, lyEye: Float,
        rxEye: Float, ryEye: Float,
        effectId: Int,
        intensity: Float
    ): Boolean

    // 26. C++ Native Eye Color (8 Tones)
    @JvmStatic
    external fun nativeApplyEyeColor(
        bitmap: Bitmap,
        lxEye: Float, lyEye: Float,
        rxEye: Float, ryEye: Float,
        colorId: Int,
        intensity: Float
    ): Boolean

    // 27. C++ Native Eye Catchlight (Studio Sparkle 8 Styles)
    @JvmStatic
    external fun nativeApplyEyeCatchlight(
        bitmap: Bitmap,
        lxEye: Float, lyEye: Float,
        rxEye: Float, ryEye: Float,
        styleId: Int,
        intensity: Float
    ): Boolean

    // 28. C++ Native Eyebrow Shape & Adjustments
    @JvmStatic
    external fun nativeApplyEyebrow(
        bitmap: Bitmap,
        lxEye: Float, lyEye: Float,
        rxEye: Float, ryEye: Float,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 29. C++ Native Eyebrow Color (5 Shades)
    @JvmStatic
    external fun nativeApplyEyebrowColor(
        bitmap: Bitmap,
        lxEye: Float, lyEye: Float,
        rxEye: Float, ryEye: Float,
        colorId: Int,
        intensity: Float
    ): Boolean

    // 30. C++ Native Eye Presets (Photo_13)
    @JvmStatic
    external fun nativeApplyEyePreset(
        bitmap: Bitmap,
        lxEye: Float, lyEye: Float,
        rxEye: Float, ryEye: Float,
        presetId: Int,
        intensity: Float
    ): Boolean

    // 31. C++ Native Nose Reshape (2.5 NOSE)
    @JvmStatic
    external fun nativeApplyNoseReshape(
        bitmap: Bitmap,
        noseX: Float, noseY: Float,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 32. C++ Native Mouth / Lips Reshape (2.6 MOUTH)
    @JvmStatic
    external fun nativeApplyMouthReshape(
        bitmap: Bitmap,
        mouthX: Float, mouthY: Float,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 33. C++ Native Skin Type (2.7.1 SKIN TYPE)
    @JvmStatic
    external fun nativeApplySkinType(
        bitmap: Bitmap,
        faceCenterX: Float, faceCenterY: Float,
        faceRadiusX: Float, faceRadiusY: Float,
        skinTypeId: Int,
        intensity: Float,
        landmarks106: FloatArray? = null
    ): Boolean

    // 34. C++ Native Skin Tools (2.7.2 SKIN TOOLS)
    @JvmStatic
    external fun nativeApplySkinTool(
        bitmap: Bitmap,
        faceCenterX: Float, faceCenterY: Float,
        noseX: Float, noseY: Float,
        mouthX: Float, mouthY: Float,
        lxEye: Float, lyEye: Float,
        rxEye: Float, ryEye: Float,
        toolId: Int,
        intensity: Float,
        landmarks106: FloatArray? = null
    ): Boolean

    // 35. C++ Native Lipstick Makeup (2.8.2 LIPSTICK)
    @JvmStatic
    external fun nativeApplyLipstick(
        bitmap: Bitmap,
        landmarks106: FloatArray?,
        mouthX: Float, mouthY: Float,
        colorId: Int,
        textureId: Int,
        intensity: Float
    ): Boolean

    // 36. C++ Native Blush Makeup (2.8.5 BLUSH)
    @JvmStatic
    external fun nativeApplyBlush(
        bitmap: Bitmap,
        cheekLeftX: Float, cheekLeftY: Float,
        cheekRightX: Float, cheekRightY: Float,
        styleId: Int,
        intensity: Float
    ): Boolean

    // 37. C++ Native EyeShadow Makeup (2.8.4 EYESHADOW)
    @JvmStatic
    external fun nativeApplyEyeShadow(
        bitmap: Bitmap,
        lxEye: Float, lyEye: Float,
        rxEye: Float, ryEye: Float,
        toneId: Int,
        intensity: Float
    ): Boolean

    // 38. C++ Native Contour 3D & Wocan (2.8.5 CONTOUR)
    @JvmStatic
    external fun nativeApplyContour3D(
        bitmap: Bitmap,
        noseX: Float, noseY: Float,
        lxEye: Float, lyEye: Float,
        rxEye: Float, ryEye: Float,
        contourType: Int,
        intensity: Float
    ): Boolean

    // 39. C++ Native Hair Studio (2.9 HAIR)
    @JvmStatic
    external fun nativeApplyHair(
        bitmap: Bitmap,
        foreheadX: Float, foreheadY: Float,
        paramId: Int,
        colorToneId: Int,
        intensity: Float
    ): Boolean

    // 40. C++ Native Body Reshape (2.10 BODY RESHAPE)
    @JvmStatic
    external fun nativeApplyBodyReshape(
        bitmap: Bitmap,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 41. C++ Native HSL 8 Channels (2.14 HSL)
    @JvmStatic
    external fun nativeApplyHslChannel(
        bitmap: Bitmap,
        channelId: Int,
        hueShift: Float,
        satShift: Float,
        lumShift: Float
    ): Boolean

    // 42. C++ Native Tone Param (2.14 TONE)
    @JvmStatic
    external fun nativeApplyToneParam(
        bitmap: Bitmap,
        paramId: Int,
        value: Float
    ): Boolean

    // 43. C++ Native 3D LUT Filter (2.14 FILTERS)
    @JvmStatic
    external fun nativeApplyFilter(
        bitmap: Bitmap,
        filterId: Int,
        intensity: Float
    ): Boolean

    // 44. C++ Native AI Retouch (2.12 SMART BEAUTIFY)
    @JvmStatic
    external fun nativeApplyAiRetouch(
        bitmap: Bitmap,
        presetId: Int,
        intensity: Float
    ): Boolean

    // 45. C++ Native Portrait Defocus (2.14 / 2.15 BOKEH)
    @JvmStatic
    external fun nativeApplyPortraitDefocus(
        bitmap: Bitmap,
        focusX: Float, focusY: Float,
        focusRadiusX: Float, focusRadiusY: Float,
        blurStrength: Float
    ): Boolean

    // 46. C++ NCNN Face Engine Init
    @JvmStatic
    external fun nativeInitNcnnFaceEngine(assetManager: Any): Boolean

    // 47. C++ NCNN Face & 106 Landmarks Detection
    @JvmStatic
    external fun nativeDetect106Ncnn(
        bitmap: Bitmap,
        landmarksOut: FloatArray,
        faceBoundsOut: FloatArray
    ): Boolean

    // 48. C++ NCNN Dense FaceMesh 478 & Iris Detection
    @JvmStatic
    external fun nativeDetectDenseMesh478(
        bitmap: Bitmap,
        outMesh478: FloatArray,
        outIrisInfo: FloatArray?,
        outFaceBounds: FloatArray?
    ): Boolean

    // 49. C++ NCNN Fused Geometry Detection (106 Anchors + 478 Dense Mesh + Temporal Stabilizer)
    @JvmStatic
    external fun nativeDetectFusedGeometry(
        bitmap: Bitmap,
        out106: FloatArray,
        outMesh478: FloatArray,
        outFaceBounds: FloatArray?
    ): Boolean

    // 50. C++ Native Iris Makeup & Catchlight & Limbal Ring Retouch
    @JvmStatic
    external fun nativeApplyIrisMakeup(
        bitmap: Bitmap,
        leftIrisX: Float, leftIrisY: Float, leftIrisRadius: Float,
        rightIrisX: Float, rightIrisY: Float, rightIrisRadius: Float,
        pupilScale: Float, glowIntensity: Float,
        toneId: Int, toneIntensity: Float,
        catchlightType: Int, catchlightIntensity: Float
    ): Boolean

    // 51. C++ Native Canthus Adjustment (Zero-Ripple Spline Reshape)
    @JvmStatic
    external fun nativeAdjustCanthusDetail(
        bitmap: Bitmap,
        canthusPoints: FloatArray,
        innerCanthusOpen: Float,
        outerCanthusLift: Float,
        eyeSpan: Float
    ): Boolean

    // 52. C++ Native Nasolabial Fold Smoothing & Lifting (Zero-Crease Bilateral)
    @JvmStatic
    external fun nativeApplyNasolabialSmoothing(
        bitmap: Bitmap,
        leftSmilePts: FloatArray?,
        rightSmilePts: FloatArray?,
        intensity: Float
    ): Boolean

    @JvmStatic
    external fun nativeInitHairMatting(
        paramPath: String,
        binPath: String
    ): Boolean

    // 53B. C++ Native Hair Matting Feature Flag & Matte Extraction
    @JvmStatic
    external fun nativeSetP0B2REnabled(enabled: Boolean)

    @JvmStatic
    external fun nativeIsP0B2REnabled(): Boolean

    @JvmStatic
    external fun nativeExtractHairMatte(bitmap: Bitmap): FloatArray?

    // 54. C++ Native Hair Strand Dye (4-Tier Micro-Strand Separation & Specular Preservation)
    @JvmStatic
    external fun nativeApplyHairStrandDye(
        bitmap: Bitmap,
        presetId: Int,
        intensity: Float,
        gloss: Float = 0.5f
    ): Boolean

    // 55. C++ Native Custom Hair Dye (Target RGB + Bleaching Power)
    @JvmStatic
    external fun nativeApplyCustomHairDye(
        bitmap: Bitmap,
        targetR: Int, targetG: Int, targetB: Int,
        bleachPower: Float,
        intensity: Float,
        gloss: Float = 0.5f
    ): Boolean

    // 56. C++ Native Beard Gray Away (Target Gray Strands, Zero Skin Bleed)
    @JvmStatic
    external fun nativeApplyBeardGrayAway(
        bitmap: Bitmap,
        intensity: Float,
        thickness: Float = 1.0f,
        heightOffset: Float = 0.0f,
        widthScale: Float = 1.0f,
        beardStyle: Int = 0
    ): Boolean

    // 57. C++ Native Beard Dye (Target Beard Strands Only)
    @JvmStatic
    external fun nativeApplyBeardDye(
        bitmap: Bitmap,
        targetR: Int, targetG: Int, targetB: Int,
        intensity: Float,
        thickness: Float = 1.0f,
        heightOffset: Float = 0.0f,
        widthScale: Float = 1.0f,
        beardStyle: Int = 0,
        horizontalOffset: Float = 0.0f
    ): Boolean

    // 57B. C++ Native Preset Beard Overlay & Dye (Resize & Warp to Face 478 Landmarks)
    @JvmStatic
    external fun nativeApplyPresetBeard(
        bitmap: Bitmap,
        beardBitmap: Bitmap,
        intensity: Float,
        targetR: Int, targetG: Int, targetB: Int,
        isDyeActive: Boolean,
        thickness: Float = 1.0f,
        heightOffset: Float = 0.0f,
        widthScale: Float = 1.0f,
        horizontalOffset: Float = 0.0f
    ): Boolean

    // 58. C++ Native ID Photo Background Replacement (Phông nền chuẩn quốc tế)
    @JvmStatic
    external fun nativeApplyIdPhotoBackground(
        bitmap: Bitmap,
        targetR: Int, targetG: Int, targetB: Int,
        smoothBorder: Float = 2.5f
    ): Boolean

    // 59. C++ Native Collage Grid Compositor (Ghép ảnh nghệ thuật đa khung)
    @JvmStatic
    external fun nativeApplyCollageGrid(
        bitmap: Bitmap,
        gridType: Int,
        spacing: Int,
        radius: Int,
        borderColor: Int
    ): Boolean

    // 60. C++ Native Video Beauty Frame Processor (Làm đẹp video đa tầng)
    @JvmStatic
    external fun nativeApplyVideoBeautyFrame(
        bitmap: Bitmap,
        smoothLevel: Float,
        slimLevel: Float,
        eyeLevel: Float,
        toothLevel: Float
    ): Boolean

    // 61. C++ Native Body Contour & Symmetry / Defect Analysis (Bo viền, kiểm tra lệch/khuyết/thiếu)
    @JvmStatic
    external fun nativeAnalyzeBodyContour(
        bitmap: Bitmap,
        landmarks106: FloatArray?
    ): FloatArray?

    data class BodyContourReport(
        val isValid: Boolean,
        val topY: Int,
        val bottomY: Int,
        val bodyCenterX: Float,
        val maxLeftWidth: Float,
        val maxRightWidth: Float,
        val symmetryRatio: Float,
        val isAsymmetric: Boolean,
        val hasChippedParts: Boolean,
        val internalHoleCount: Int,
        val defectCount: Int,
        val totalBodyArea: Float
    )

    @JvmStatic
    fun getBodyContourReport(bitmap: Bitmap, landmarks106: FloatArray?): BodyContourReport? {
        val arr = nativeAnalyzeBodyContour(bitmap, landmarks106) ?: return null
        if (arr.size < 12) return null
        return BodyContourReport(
            isValid = arr[0] > 0.5f,
            topY = arr[1].toInt(),
            bottomY = arr[2].toInt(),
            bodyCenterX = arr[3],
            maxLeftWidth = arr[4],
            maxRightWidth = arr[5],
            symmetryRatio = arr[6],
            isAsymmetric = arr[7] > 0.5f,
            hasChippedParts = arr[8] > 0.5f,
            internalHoleCount = arr[9].toInt(),
            defectCount = arr[10].toInt(),
            totalBodyArea = arr[11]
        )
    }

    // 65. C++ Native Ear Style (Tai Phật, Tai Chuột, Tai Heo, Tai Yêu Tinh, Ép Tai Vểnh)
    @JvmStatic
    external fun nativeApplyEarStyle(
        bitmap: Bitmap,
        landmarks106: FloatArray?,
        leftEarX: Float,
        leftEarY: Float,
        rightEarX: Float,
        rightEarY: Float,
        radius: Float,
        earStyle: Int,
        intensity: Float,
        isLeftVisible: Boolean = true,
        isRightVisible: Boolean = true
    ): Boolean

    // 66. C++ Native Ear Anatomy Analysis
    @JvmStatic
    external fun nativeAnalyzeEarAnatomy(
        bitmap: Bitmap?,
        landmarks106: FloatArray?,
        imageWidth: Int,
        imageHeight: Int
    ): FloatArray?

    data class EarAnatomyReport(
        val isValid: Boolean,
        val leftEarCenterX: Float,
        val leftEarCenterY: Float,
        val rightEarCenterX: Float,
        val rightEarCenterY: Float,
        val earRadius: Float,
        val leftEyeToEarDist: Float,
        val rightEyeToEarDist: Float,
        val earToEyeElevation: Float,
        val earToCheekDistance: Float,
        val earToChinVertical: Float,
        val leftEarAngleDeg: Float,
        val rightEarAngleDeg: Float,
        val earProtrusionRatio: Float,
        val leftHelixTopX: Float,
        val leftHelixTopY: Float,
        val leftLobeBottomX: Float,
        val leftLobeBottomY: Float,
        val rightHelixTopX: Float,
        val rightHelixTopY: Float,
        val rightLobeBottomX: Float,
        val rightLobeBottomY: Float,
        val isLeftEarVisible: Boolean = true,
        val isRightEarVisible: Boolean = true,
        val headYawAngleDeg: Float = 0.0f,
        val leftLobeCenterX: Float = 0.0f,
        val leftLobeCenterY: Float = 0.0f,
        val rightLobeCenterX: Float = 0.0f,
        val rightLobeCenterY: Float = 0.0f
    )

    @JvmStatic
    fun getEarAnatomyReport(bitmap: Bitmap?, landmarks106: FloatArray?, width: Int, height: Int): EarAnatomyReport? {
        if (width <= 0 || height <= 0) return null
        if (landmarks106 == null && bitmap == null) return null
        val raw = nativeAnalyzeEarAnatomy(bitmap, landmarks106, width, height) ?: return null
        if (raw.size < 22 || raw[0] == 0.0f) return null
        return EarAnatomyReport(
            isValid = raw[0] != 0.0f,
            leftEarCenterX = raw[1],
            leftEarCenterY = raw[2],
            rightEarCenterX = raw[3],
            rightEarCenterY = raw[4],
            earRadius = raw[5],
            leftEyeToEarDist = raw[6],
            rightEyeToEarDist = raw[7],
            earToEyeElevation = raw[8],
            earToCheekDistance = raw[9],
            earToChinVertical = raw[10],
            leftEarAngleDeg = raw[11],
            rightEarAngleDeg = raw[12],
            earProtrusionRatio = raw[13],
            leftHelixTopX = raw[14],
            leftHelixTopY = raw[15],
            leftLobeBottomX = raw[16],
            leftLobeBottomY = raw[17],
            rightHelixTopX = raw[18],
            rightHelixTopY = raw[19],
            rightLobeBottomX = raw[20],
            rightLobeBottomY = raw[21],
            isLeftEarVisible = if (raw.size >= 25) raw[22] > 0.5f else true,
            isRightEarVisible = if (raw.size >= 25) raw[23] > 0.5f else true,
            headYawAngleDeg = if (raw.size >= 25) raw[24] else 0.0f,
            leftLobeCenterX = if (raw.size >= 29) raw[25] else 0.0f,
            leftLobeCenterY = if (raw.size >= 29) raw[26] else 0.0f,
            rightLobeCenterX = if (raw.size >= 29) raw[27] else 0.0f,
            rightLobeCenterY = if (raw.size >= 29) raw[28] else 0.0f
        )
    }

    @JvmStatic
    fun getEarAnatomyReport(landmarks106: FloatArray?, width: Int, height: Int): EarAnatomyReport? {
        return getEarAnatomyReport(null, landmarks106, width, height)
    }

    // 76. C++ Native Head Skull Engine (SPEC Sections 3, 7)
    @JvmStatic
    external fun nativeApplyHeadSkull(
        bitmap: Bitmap,
        landmarks: FloatArray?,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 77. C++ Native Neck & Clavicle Engine (SPEC Sections 21, 22)
    @JvmStatic
    external fun nativeApplyNeckClavicle(
        bitmap: Bitmap,
        landmarks: FloatArray?,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 78. C++ Native Eyebrow & Eyelash Engine (SPEC Sections 10, 11)
    @JvmStatic
    external fun nativeApplyEyebrowLash(
        bitmap: Bitmap,
        landmarks: FloatArray?,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 79. C++ Native Scalp Reconstruction & Generative Inpaint (SPEC Sections 4, 29)
    @JvmStatic
    external fun nativeApplyScalpReconstruction(
        bitmap: Bitmap,
        landmarks: FloatArray?,
        blendStrength: Float
    ): Boolean

    // 80. C++ Native Master Beauty Pipeline (SPEC Sections 30, 37)
    @JvmStatic
    external fun nativeApplyMasterBeautyPipeline(
        bitmap: Bitmap,
        landmarks: FloatArray?,
        params: FloatArray
    ): Boolean

    // 81. C++ Native Semantic Head Model Extraction Report
    @JvmStatic
    external fun nativeExtractHeadSemanticReport(
        landmarks: FloatArray?,
        imageWidth: Int,
        imageHeight: Int
    ): FloatArray?

    // 82. C++ Native Eyelash Styling & Anti-aliased Keratin Fibers (SPEC Section 11)
    @JvmStatic
    external fun nativeApplyEyelash(
        bitmap: Bitmap,
        landmarks: FloatArray?,
        styleId: Int,
        intensity: Float,
        lengthScale: Float = 1.0f,
        densityScale: Float = 1.0f,
        curlAngle: Float = 0.0f
    ): Boolean

    // 83. C++ Native Philtrum Reshaping & 3D Groove Shading (SPEC Section 17)
    @JvmStatic
    external fun nativeApplyPhiltrumEdit(
        bitmap: Bitmap,
        landmarks: FloatArray?,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 84. C++ Native Clavicle & Upper Shoulder Sculpting (SPEC Section 22)
    @JvmStatic
    external fun nativeApplyClavicleShoulderEdit(
        bitmap: Bitmap,
        landmarks: FloatArray?,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 85. C++ Native Accessory Anti-Warp Protection (SPEC Section 23)
    @JvmStatic
    external fun nativeProtectRigidAccessories(
        warpedBitmap: Bitmap,
        originalBitmap: Bitmap,
        landmarks: FloatArray?,
        rigidStrength: Float = 1.0f
    ): Boolean

    // 86. C++ Native Surface Normal & 3D Shading Sculpting (SPEC Section 24)
    @JvmStatic
    external fun nativeApplyNormalSculpting(
        bitmap: Bitmap,
        landmarks: FloatArray?,
        paramId: Int,
        intensity: Float
    ): Boolean

    // 87. C++ Native Body Beauty Pipeline (SPEC Sections 41-87)
    @JvmStatic
    external fun nativeApplyBodyBeauty(
        bitmap: Bitmap,
        posePoints: FloatArray?,
        headLandmarks: FloatArray?,
        params: FloatArray
    ): Boolean

    // 88. C++ Native Master Full Human Beauty Pipeline (SPEC Section 91)
    @JvmStatic
    external fun nativeApplyFullHumanBeauty(
        bitmap: Bitmap,
        headLandmarks: FloatArray?,
        posePoints: FloatArray?,
        headParams: FloatArray,
        bodyParams: FloatArray
    ): Boolean

    // 89. C++ Native Full Human Report (SPEC Section 90)
    @JvmStatic
    external fun nativeExtractFullHumanReport(
        posePoints: FloatArray?,
        headLandmarks: FloatArray?,
        imageWidth: Int,
        imageHeight: Int
    ): FloatArray?

    // 90. BiSeNet 19-Class Face Parsing NCNN Engine (CoinCheung/BiSeNet)
    // 0: background, 1: skin, 2: l_brow, 3: r_brow, 4: l_eye, 5: r_eye, 6: eye_g, 7: l_ear, 8: r_ear, 9: ear_r,
    // 10: nose, 11: mouth, 12: u_lip, 13: l_lip, 14: neck, 15: neck_l, 16: cloth, 17: hair, 18: hat
    const val BISENET_CLASS_BACKGROUND = 0
    const val BISENET_CLASS_SKIN = 1
    const val BISENET_CLASS_L_BROW = 2
    const val BISENET_CLASS_R_BROW = 3
    const val BISENET_CLASS_L_EYE = 4
    const val BISENET_CLASS_R_EYE = 5
    const val BISENET_CLASS_EYE_GLASSES = 6
    const val BISENET_CLASS_L_EAR = 7
    const val BISENET_CLASS_R_EAR = 8
    const val BISENET_CLASS_EAR_RING = 9
    const val BISENET_CLASS_NOSE = 10
    const val BISENET_CLASS_MOUTH = 11
    const val BISENET_CLASS_U_LIP = 12
    const val BISENET_CLASS_L_LIP = 13
    const val BISENET_CLASS_NECK = 14
    const val BISENET_CLASS_NECK_L = 15
    const val BISENET_CLASS_CLOTH = 16
    const val BISENET_CLASS_HAIR = 17
    const val BISENET_CLASS_HAT = 18

    @JvmStatic
    external fun nativeInitBiSeNetParser(paramPath: String, binPath: String): Boolean

    @JvmStatic
    external fun nativeParseFace19(bitmap: Bitmap, outMask512: ByteArray): Boolean

    @JvmStatic
    external fun nativeExtractBiSeNetClassMask(mask512: ByteArray, classId: Int, outAlpha512: ByteArray): Boolean

    // 91. C++ Video Timeline Compositor (NDK MediaCodec + Optical Flow + LUT Filters)
    @JvmStatic
    external fun nativeVideoInitCompositor(): Boolean

    @JvmStatic
    external fun nativeVideoAddClip(videoPath: String, startUs: Long, durationUs: Long): Boolean

    @JvmStatic
    external fun nativeVideoRenderFrame(
        targetBitmap: Bitmap,
        timeUs: Long,
        filterType: Int = 0,
        filterIntensity: Float = 1.0f,
        transitionType: Int = 0,
        transitionProgress: Float = 0.0f
    ): Boolean

    @JvmStatic
    external fun nativeVideoGetDurationUs(): Long

    @JvmStatic
    external fun nativeVideoClear(): Boolean


    data class HeadSemanticReport(
        val isValid: Boolean,
        val headWidth: Float,
        val headHeight: Float,
        val crownHeight: Float,
        val foreheadHeight: Float,
        val templeWidth: Float,
        val faceToHeadRatio: Float,
        val faceWidth: Float,
        val faceHeight: Float,
        val neckWidth: Float,
        val neckLength: Float,
        val leftBrowThickness: Float,
        val rightBrowThickness: Float,
        val leftEyeAperture: Float,
        val rightEyeAperture: Float,
        val noseWidth: Float,
        val noseBridgeLength: Float,
        val mouthWidth: Float,
        val hasGlasses: Boolean,
        val hasEarring: Boolean
    )

    data class FullHumanReport(
        val isValid: Boolean,
        val isHeadValid: Boolean,
        val isPoseValid: Boolean,
        val shoulderWidth: Float,
        val chestWidth: Float,
        val waistWidth: Float,
        val hipWidth: Float,
        val waistToHipRatio: Float,
        val leftArmWidth: Float,
        val leftArmLength: Float,
        val rightArmWidth: Float,
        val rightArmLength: Float,
        val leftThighWidth: Float,
        val leftThighLength: Float,
        val leftLowerLegLength: Float,
        val rightThighWidth: Float,
        val rightThighLength: Float,
        val rightLowerLegLength: Float,
        val bodyMinX: Float,
        val bodyMinY: Float,
        val bodyMaxX: Float,
        val bodyMaxY: Float,
        val isLeftArmOccludingTorso: Boolean,
        val isRightArmOccludingTorso: Boolean
    )

    @JvmStatic
    fun getHeadSemanticReport(landmarks: FloatArray?, width: Int, height: Int): HeadSemanticReport? {
        val raw = nativeExtractHeadSemanticReport(landmarks, width, height) ?: return null
        if (raw.size < 20 || raw[0] == 0.0f) return null
        return HeadSemanticReport(
            isValid = raw[0] != 0.0f,
            headWidth = raw[1],
            headHeight = raw[2],
            crownHeight = raw[3],
            foreheadHeight = raw[4],
            templeWidth = raw[5],
            faceToHeadRatio = raw[6],
            faceWidth = raw[7],
            faceHeight = raw[8],
            neckWidth = raw[9],
            neckLength = raw[10],
            leftBrowThickness = raw[11],
            rightBrowThickness = raw[12],
            leftEyeAperture = raw[13],
            rightEyeAperture = raw[14],
            noseWidth = raw[15],
            noseBridgeLength = raw[16],
            mouthWidth = raw[17],
            hasGlasses = raw[18] > 0.5f,
            hasEarring = raw[19] > 0.5f
        )
    }

    @JvmStatic
    fun getFullHumanReport(posePoints: FloatArray?, headLandmarks: FloatArray?, width: Int, height: Int): FullHumanReport? {
        val raw = nativeExtractFullHumanReport(posePoints, headLandmarks, width, height) ?: return null
        if (raw.size < 24 || raw[0] == 0.0f) return null
        return FullHumanReport(
            isValid = raw[0] != 0.0f,
            isHeadValid = raw[1] != 0.0f,
            isPoseValid = raw[2] != 0.0f,
            shoulderWidth = raw[3],
            chestWidth = raw[4],
            waistWidth = raw[5],
            hipWidth = raw[6],
            waistToHipRatio = raw[7],
            leftArmWidth = raw[8],
            leftArmLength = raw[9],
            rightArmWidth = raw[10],
            rightArmLength = raw[11],
            leftThighWidth = raw[12],
            leftThighLength = raw[13],
            leftLowerLegLength = raw[14],
            rightThighWidth = raw[15],
            rightThighLength = raw[16],
            rightLowerLegLength = raw[17],
            bodyMinX = raw[18],
            bodyMinY = raw[19],
            bodyMaxX = raw[20],
            bodyMaxY = raw[21],
            isLeftArmOccludingTorso = raw[22] > 0.5f,
            isRightArmOccludingTorso = raw[23] > 0.5f
        )
    }
}





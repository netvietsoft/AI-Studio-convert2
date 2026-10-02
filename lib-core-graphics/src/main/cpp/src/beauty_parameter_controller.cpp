#include "beauty_parameter_controller.h"
#include <vector>
#include <iostream>
#include <algorithm>

namespace meitu_native {

BeautyParameterController::BeautyParameterController()
    : mSkullEngine(std::make_unique<HeadSkullEngine>()),
      mNeckEngine(std::make_unique<NeckClavicleEngine>()),
      mBrowLashEngine(std::make_unique<EyebrowLashEngine>()),
      mScalpEngine(std::make_unique<ScalpReconstructionEngine>()) {
}

BeautyParameterController::~BeautyParameterController() = default;

bool BeautyParameterController::applyBeautyPipeline(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const std::vector<float>& landmarkPoints,
    const BeautyParameters& params
) {
    if (!rgbaImage || width <= 0 || height <= 0 || stride < width * 4) {
        return false;
    }

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);

    // Giai doan 1: Trich xuat Semantic Head Model tu Landmarks (SPEC Muc 1, 2, 32, 37)
    HeadFrameResult headResult = HeadSemanticEngine::extractSemanticModel(
        landmarkPoints, pixels, width, height
    );

    // Giai doan 2: Snapshot nguyen ban de bao ve phu kien cung (SPEC Muc 23)
    std::vector<uint32_t> origSnapshot(width * height);
    std::copy(pixels, pixels + (width * height), origSnapshot.begin());

    AccessoryOcclusionEngine::analyzeAccessories(pixels, width, height, headResult);

    // Giai doan 3: Hinh hoc vom dau, vom so, thai duong, tran (SPEC Muc 3, 7)
    if (params.skullCrown > 0.001f) {
        mSkullEngine->processSkullCrown(rgbaImage, width, height, stride, headResult, params.skullCrown);
    }
    if (params.headSize > 0.001f) {
        mSkullEngine->processHeadSize(rgbaImage, width, height, stride, headResult, params.headSize);
    }
    if (params.templeWidth > 0.001f) {
        mSkullEngine->processTempleWidth(rgbaImage, width, height, stride, headResult, params.templeWidth);
    }
    if (params.foreheadHeight > 0.001f) {
        mSkullEngine->processForeheadHeight(rgbaImage, width, height, stride, headResult, params.foreheadHeight);
    }

    // Giai doan 4: Chinh hinh Tai / Tai Phat (SPEC Muc 8)
    if (params.earSize > 0.001f) {
        float lx = headResult.ear.left.center.x;
        float ly = headResult.ear.left.center.y;
        float rx = headResult.ear.right.center.x;
        float ry = headResult.ear.right.center.y;
        float r = std::max(headResult.ear.left.height, headResult.ear.right.height) * 0.5f;
        const float* lmPtr = landmarkPoints.empty() ? nullptr : landmarkPoints.data();
        TeethEarEngine::applyEarStyle(
            pixels, width, height, lmPtr,
            lx, ly, rx, ry, r,
            EAR_STYLE_BUDDHA, params.earSize,
            headResult.ear.left.isVisible, headResult.ear.right.isVisible
        );
    }

    // Giai doan 5: Vung Co & Xuong quai xanh (SPEC Muc 21, 22)
    if (params.neckSlim > 0.001f) {
        mNeckEngine->processNeckClavicle(rgbaImage, width, height, stride, headResult,
                                       NeckClavicleEngine::PARAM_NECK_SLIM, params.neckSlim);
    }
    if (params.neckLength > 0.001f) {
        mNeckEngine->processNeckClavicle(rgbaImage, width, height, stride, headResult,
                                       NeckClavicleEngine::PARAM_NECK_LENGTH, params.neckLength);
    }
    if (params.neckWrinkles > 0.001f) {
        mNeckEngine->processNeckClavicle(rgbaImage, width, height, stride, headResult,
                                       NeckClavicleEngine::PARAM_NECK_WRINKLE_SMOOTH, params.neckWrinkles);
    }
    if (params.clavicleEnhance > 0.001f) {
        mNeckEngine->processNeckClavicle(rgbaImage, width, height, stride, headResult,
                                       NeckClavicleEngine::PARAM_CLAVICLE_ENHANCE, params.clavicleEnhance);
    }
    if (params.faceNeckToneMatch > 0.001f) {
        mNeckEngine->processNeckClavicle(rgbaImage, width, height, stride, headResult,
                                       NeckClavicleEngine::PARAM_FACE_NECK_TONE, params.faceNeckToneMatch);
    }

    // Giai doan 6: Long may & Long mi (SPEC Muc 10, 11)
    if (params.browThickness > 0.001f) {
        mBrowLashEngine->processEyebrowLash(rgbaImage, width, height, stride, headResult,
                                           EyebrowLashEngine::PARAM_BROW_THICKNESS, params.browThickness);
    }
    if (params.browArch > 0.001f) {
        mBrowLashEngine->processEyebrowLash(rgbaImage, width, height, stride, headResult,
                                           EyebrowLashEngine::PARAM_BROW_ARCH, params.browArch);
    }
    if (params.browDensityFill > 0.001f) {
        mBrowLashEngine->processEyebrowLash(rgbaImage, width, height, stride, headResult,
                                           EyebrowLashEngine::PARAM_BROW_DENSITY_FILL, params.browDensityFill);
    }
    if (params.lashDensity > 0.001f) {
        mBrowLashEngine->processEyebrowLash(rgbaImage, width, height, stride, headResult,
                                           EyebrowLashEngine::PARAM_LASH_DENSITY, params.lashDensity);
    }
    if (params.lashLength > 0.001f) {
        mBrowLashEngine->processEyebrowLash(rgbaImage, width, height, stride, headResult,
                                           EyebrowLashEngine::PARAM_LASH_LENGTH, params.lashLength);
    }
    if (params.lashCurl > 0.001f) {
        mBrowLashEngine->processEyebrowLash(rgbaImage, width, height, stride, headResult,
                                           EyebrowLashEngine::PARAM_LASH_CURL, params.lashCurl);
    }

    // Giai doan 7: Rang trang tu nhien (SPEC Muc 19)
    if (params.teethWhiten > 0.001f) {
        float mx = headResult.mouthLip.center.x;
        float my = headResult.mouthLip.center.y;
        float mw = headResult.mouthLip.mouthWidth;
        float mh = headResult.mouthLip.lowerLipBottom.y - headResult.mouthLip.upperLipTop.y;
        const float* lmPtr = landmarkPoints.empty() ? nullptr : landmarkPoints.data();
        TeethEarEngine::applyTeethWhitening(
            pixels, width, height,
            mx, my, mw * 0.5f, mh * 0.5f,
            0, params.teethWhiten
        );
    }

    // Giai doan 8: Bao ve phu kien cung (Gong kinh, khuyen tai) (SPEC Muc 23)
    if (headResult.accessory.hasGlasses) {
        AccessoryOcclusionEngine::protectRigidAccessories(
            pixels, origSnapshot.data(), width, height, headResult, 1.0f
        );
    }

    return true;
}

} // namespace meitu_native

#include "head_semantic_model.h"
#include <cmath>
#include <algorithm>
#include <android/log.h>

#define LOG_TAG "HeadSemanticModel"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)

namespace meitu_native {

HeadSemanticEngine& HeadSemanticEngine::getInstance() {
    static HeadSemanticEngine sInstance;
    return sInstance;
}

HeadFrameResult HeadSemanticEngine::extractSemanticModel(
    const uint32_t* pixels,
    int width,
    int height,
    const MeituReborn::FusedFaceGeometry& fused
) {
    HeadFrameResult res;
    res.imageWidth = width;
    res.imageHeight = height;

    if (!pixels || width <= 0 || height <= 0) {
        return res;
    }

    bool hasDense = (fused.dense478.size() >= 468);
    bool hasAnchors = (fused.anchors106.size() >= 212);

    if (!hasDense && !hasAnchors) {
        res.isFaceDetected = false;
        res.overallConfidence = 0.0f;
        mLastResult = res;
        return res;
    }

    res.isFaceDetected = true;
    res.overallConfidence = 0.95f;

    // 1. TRÍCH XUẤT CÁC ĐIỂM GIẢI PHẪU THEN CHỐT TỪ DENSE 478 HOẶC ANCHORS 106
    float noseTipX = 0.5f * width, noseTipY = 0.5f * height;
    float chinX = 0.5f * width, chinY = 0.75f * height;
    float foreheadX = 0.5f * width, foreheadY = 0.28f * height;
    float lJawX = 0.28f * width, lJawY = 0.65f * height;
    float rJawX = 0.72f * width, rJawY = 0.65f * height;
    float lxEye = 0.38f * width, lyEye = 0.42f * height;
    float rxEye = 0.62f * width, ryEye = 0.42f * height;
    float mouthX = 0.5f * width, mouthY = 0.65f * height;

    if (hasDense) {
        noseTipX = fused.dense478[1].x;
        noseTipY = fused.dense478[1].y;
        chinX = fused.dense478[152].x;
        chinY = fused.dense478[152].y;
        foreheadX = fused.dense478[10].x;
        foreheadY = fused.dense478[10].y;
        lJawX = fused.dense478[234].x;
        lJawY = fused.dense478[234].y;
        rJawX = fused.dense478[454].x;
        rJawY = fused.dense478[454].y;
        lxEye = fused.dense478[468].x;
        lyEye = fused.dense478[468].y;
        rxEye = fused.dense478[473].x;
        ryEye = fused.dense478[473].y;
        mouthX = (fused.dense478[61].x + fused.dense478[291].x) * 0.5f;
        mouthY = (fused.dense478[0].y + fused.dense478[17].y) * 0.5f;
    } else if (hasAnchors) {
        noseTipX = fused.anchors106[46 * 2];
        noseTipY = fused.anchors106[46 * 2 + 1];
        chinX = fused.anchors106[16 * 2];
        chinY = fused.anchors106[16 * 2 + 1];
        lxEye = fused.anchors106[104 * 2];
        lyEye = fused.anchors106[104 * 2 + 1];
        rxEye = fused.anchors106[105 * 2];
        ryEye = fused.anchors106[105 * 2 + 1];
        lJawX = fused.anchors106[0 * 2];
        lJawY = fused.anchors106[0 * 2 + 1];
        rJawX = fused.anchors106[32 * 2];
        rJawY = fused.anchors106[32 * 2 + 1];
        mouthX = (fused.anchors106[84 * 2] + fused.anchors106[90 * 2]) * 0.5f;
        mouthY = (fused.anchors106[87 * 2 + 1] + fused.anchors106[93 * 2 + 1]) * 0.5f;
        float midBrowY = (fused.anchors106[37 * 2 + 1] + fused.anchors106[70 * 2 + 1]) * 0.5f;
        foreheadX = (fused.anchors106[37 * 2] + fused.anchors106[70 * 2]) * 0.5f;
        foreheadY = midBrowY - 0.40f * (chinY - midBrowY);
    }

    float faceWidth = std::abs(rJawX - lJawX);
    float faceHeight = std::abs(chinY - foreheadY);
    float eyeDist = std::hypot(rxEye - lxEye, ryEye - lyEye);

    // 2. HEAD GEOMETRY (Kích thước đầu, vòm sọ, vòm trán, tỷ lệ đầu/mặt — Mục 2, 3)
    res.headGeometry.headWidth = faceWidth * 1.30f;
    res.headGeometry.crownHeight = faceHeight * 0.38f;
    res.headGeometry.headHeight = faceHeight + res.headGeometry.crownHeight;
    res.headGeometry.foreheadHeight = std::abs(lyEye - foreheadY);
    res.headGeometry.foreheadWidth = faceWidth * 0.85f;
    res.headGeometry.templeWidth = faceWidth * 0.95f;
    res.headGeometry.faceToHeadRatio = (faceWidth * faceHeight) / (res.headGeometry.headWidth * res.headGeometry.headHeight + 0.001f);

    float skullTopY = std::max(0.0f, foreheadY - res.headGeometry.crownHeight);
    res.headGeometry.headBox = {
        std::max(0.0f, noseTipX - res.headGeometry.headWidth * 0.5f),
        skullTopY,
        std::min(static_cast<float>(width), noseTipX + res.headGeometry.headWidth * 0.5f),
        std::min(static_cast<float>(height), chinY + faceHeight * 0.25f)
    };
    res.headGeometry.yaw = (rxEye - lxEye != 0.0f) ? std::atan2(ryEye - lyEye, rxEye - lxEye) * 180.0f / 3.14159f : 0.0f;
    res.headGeometry.visibleContourConfidence = 0.92f;
    res.headGeometry.isValid = true;

    // 3. HAIR & SCALP MODEL (Mục 4, 5)
    res.hair.hairlineCenter = {foreheadX, foreheadY};
    res.hair.apparentVolume = 0.75f;
    res.hair.apparentDensity = 0.85f;
    res.hair.shineLevel = 0.60f;
    res.hair.isValid = true;

    res.scalp.scalpBox = {res.headGeometry.headBox.x1, skullTopY, res.headGeometry.headBox.x2, foreheadY + 20.0f};
    res.scalp.isVisible = false;
    res.scalp.hairOcclusionRatio = 0.90f;

    // 4. FOREHEAD & TEMPLE (Mục 7)
    res.foreheadTemple.center = {foreheadX, (foreheadY + lyEye) * 0.5f};
    res.foreheadTemple.leftTempleX = lJawX + 15.0f;
    res.foreheadTemple.leftTempleY = (foreheadY + lyEye) * 0.5f;
    res.foreheadTemple.rightTempleX = rJawX - 15.0f;
    res.foreheadTemple.rightTempleY = (foreheadY + ryEye) * 0.5f;
    res.foreheadTemple.curvature = 0.55f;

    // 5. EAR MODEL (Mục 8)
    res.ear.left.isVisible = true;
    res.ear.left.tragus = {lJawX - 0.15f * eyeDist, (lyEye + lJawY) * 0.5f};
    res.ear.left.center = {lJawX - 0.35f * eyeDist, (lyEye + lJawY) * 0.5f};
    res.ear.left.lobeCenter = {lJawX - 0.30f * eyeDist, lJawY};
    res.ear.left.width = 0.40f * eyeDist;
    res.ear.left.height = 0.75f * eyeDist;

    res.ear.right.isVisible = true;
    res.ear.right.tragus = {rJawX + 0.15f * eyeDist, (ryEye + rJawY) * 0.5f};
    res.ear.right.center = {rJawX + 0.35f * eyeDist, (ryEye + rJawY) * 0.5f};
    res.ear.right.lobeCenter = {rJawX + 0.30f * eyeDist, rJawY};
    res.ear.right.width = 0.40f * eyeDist;
    res.ear.right.height = 0.75f * eyeDist;

    // 6. EYE & BROW & LASH (Mục 10, 11, 12)
    res.eye.eyeDistance = eyeDist;
    res.eye.left.isVisible = true;
    res.eye.left.center = {lxEye, lyEye};
    res.eye.left.irisCenter = {lxEye, lyEye};
    res.eye.left.irisRadius = eyeDist * 0.12f;
    res.eye.left.innerCanthus = {lxEye + 0.25f * eyeDist, lyEye};
    res.eye.left.outerCanthus = {lxEye - 0.25f * eyeDist, lyEye};
    res.eye.left.width = 0.50f * eyeDist;
    res.eye.left.height = 0.25f * eyeDist;
    res.eye.left.scleraWhiteness = 0.85f;

    res.eye.right.isVisible = true;
    res.eye.right.center = {rxEye, ryEye};
    res.eye.right.irisCenter = {rxEye, ryEye};
    res.eye.right.irisRadius = eyeDist * 0.12f;
    res.eye.right.innerCanthus = {rxEye - 0.25f * eyeDist, ryEye};
    res.eye.right.outerCanthus = {rxEye + 0.25f * eyeDist, ryEye};
    res.eye.right.width = 0.50f * eyeDist;
    res.eye.right.height = 0.25f * eyeDist;
    res.eye.right.scleraWhiteness = 0.85f;

    res.brow.left.isVisible = true;
    res.brow.left.head = {lxEye + 0.18f * eyeDist, lyEye - 0.25f * eyeDist};
    res.brow.left.arch = {lxEye - 0.05f * eyeDist, lyEye - 0.32f * eyeDist};
    res.brow.left.tail = {lxEye - 0.28f * eyeDist, lyEye - 0.22f * eyeDist};
    res.brow.left.thickness = eyeDist * 0.08f;
    res.brow.left.length = eyeDist * 0.55f;

    res.brow.right.isVisible = true;
    res.brow.right.head = {rxEye - 0.18f * eyeDist, ryEye - 0.25f * eyeDist};
    res.brow.right.arch = {rxEye + 0.05f * eyeDist, ryEye - 0.32f * eyeDist};
    res.brow.right.tail = {rxEye + 0.28f * eyeDist, ryEye - 0.22f * eyeDist};
    res.brow.right.thickness = eyeDist * 0.08f;
    res.brow.right.length = eyeDist * 0.55f;
    res.brow.interBrowDistance = std::abs(res.brow.right.head.x - res.brow.left.head.x);

    res.lash.left.length = eyeDist * 0.07f;
    res.lash.left.curlAngle = 45.0f;
    res.lash.right.length = eyeDist * 0.07f;
    res.lash.right.curlAngle = 45.0f;

    // 7. NOSE MODEL (Mục 13)
    res.nose.tip = {noseTipX, noseTipY};
    res.nose.root = {noseTipX, (lyEye + ryEye) * 0.5f};
    res.nose.bridge = {noseTipX, (res.nose.root.y + noseTipY) * 0.5f};
    res.nose.leftAla = {noseTipX - 0.22f * eyeDist, noseTipY};
    res.nose.rightAla = {noseTipX + 0.22f * eyeDist, noseTipY};
    res.nose.length = std::abs(noseTipY - res.nose.root.y);
    res.nose.alaWidth = 0.44f * eyeDist;
    res.nose.bridgeWidth = 0.18f * eyeDist;

    // 8. CHEEK & JAW & CHIN (Mục 14, 15, 16)
    res.cheek.leftCheekbone = {lJawX + 0.20f * eyeDist, (noseTipY + lyEye) * 0.5f};
    res.cheek.rightCheekbone = {rJawX - 0.20f * eyeDist, (noseTipY + ryEye) * 0.5f};
    res.cheek.cheekWidth = faceWidth * 0.88f;

    res.jawChin.leftJawAngle = {lJawX, lJawY};
    res.jawChin.rightJawAngle = {rJawX, rJawY};
    res.jawChin.chinTip = {chinX, chinY};
    res.jawChin.jawWidth = faceWidth;
    res.jawChin.chinLength = std::abs(chinY - mouthY);
    res.jawChin.chinWidth = faceWidth * 0.32f;
    res.jawChin.jawAngleDegrees = 118.0f;

    // 9. PHILTRUM & MOUTH & TEETH (Mục 17, 18, 19)
    res.philtrum.baseNose = {noseTipX, noseTipY + 5.0f};
    res.philtrum.cupidsBowCenter = {mouthX, mouthY - 0.12f * eyeDist};
    res.philtrum.length = std::abs(res.philtrum.cupidsBowCenter.y - res.philtrum.baseNose.y);
    res.philtrum.width = eyeDist * 0.15f;

    res.mouthLip.center = {mouthX, mouthY};
    res.mouthLip.leftCorner = {mouthX - 0.35f * eyeDist, mouthY};
    res.mouthLip.rightCorner = {mouthX + 0.35f * eyeDist, mouthY};
    res.mouthLip.upperLipTop = {mouthX, mouthY - 0.12f * eyeDist};
    res.mouthLip.lowerLipBottom = {mouthX, mouthY + 0.14f * eyeDist};
    res.mouthLip.mouthWidth = 0.70f * eyeDist;
    res.mouthLip.upperLipThickness = 0.12f * eyeDist;
    res.mouthLip.lowerLipThickness = 0.14f * eyeDist;
    res.mouthLip.lipGloss = 0.50f;

    res.teeth.isVisible = false;
    res.teeth.whitenessLevel = 0.80f;

    // 10. NECK & CLAVICLE (Mục 21, 22)
    res.neckClavicle.throatCenter = {chinX, chinY + 0.35f * faceHeight};
    res.neckClavicle.neckWidth = faceWidth * 0.65f;
    res.neckClavicle.neckLength = faceHeight * 0.45f;
    res.neckClavicle.leftClavicle = {chinX - 0.70f * faceWidth, chinY + faceHeight * 0.60f};
    res.neckClavicle.rightClavicle = {chinX + 0.70f * faceWidth, chinY + faceHeight * 0.60f};

    // 11. SKIN SAMPLING (Mục 6)
    int sampleX = std::clamp(static_cast<int>(noseTipX), 0, width - 1);
    int sampleY = std::clamp(static_cast<int>(noseTipY), 0, height - 1);
    uint32_t sc = pixels[sampleY * width + sampleX];
    int sr = RGBA_R(sc), sg = RGBA_G(sc), sb = RGBA_B(sc);
    res.skin.averageLuminance = (0.299f * sr + 0.587f * sg + 0.114f * sb) / 255.0f;
    res.skin.rednessIndex = static_cast<float>(sr - sg) / 255.0f;

    LOGI("✅ HeadSemanticEngine extracted HeadFrameResult successfully: headW=%.1f, headH=%.1f, crownH=%.1f, ratio=%.2f",
         res.headGeometry.headWidth, res.headGeometry.headHeight, res.headGeometry.crownHeight, res.headGeometry.faceToHeadRatio);

    res.isValid = res.isFaceDetected;
    res.browLeft = res.brow.left;
    res.browRight = res.brow.right;
    res.eyeLeft = res.eye.left;
    res.eyeRight = res.eye.right;

    mLastResult = res;
    return res;
}

} // namespace meitu_native

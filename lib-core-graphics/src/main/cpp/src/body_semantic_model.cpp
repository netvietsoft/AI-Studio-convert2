#include "body_semantic_model.h"
#include "background_protection_engine.h"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <omp.h>

namespace meitu {
namespace body {

BodySemanticModel::BodySemanticModel() = default;
BodySemanticModel::~BodySemanticModel() = default;

static inline float dist(const BodyKeypoint& a, const BodyKeypoint& b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

static inline float angleBetween(const BodyKeypoint& a, const BodyKeypoint& b, const BodyKeypoint& c) {
    float v1x = a.x - b.x;
    float v1y = a.y - b.y;
    float v2x = c.x - b.x;
    float v2y = c.y - b.y;
    float len1 = std::sqrt(v1x * v1x + v1y * v1y);
    float len2 = std::sqrt(v2x * v2x + v2y * v2y);
    if (len1 < 1e-4f || len2 < 1e-4f) return 180.0f;
    float dot = (v1x * v2x + v1y * v2y) / (len1 * len2);
    dot = std::max(-1.0f, std::min(1.0f, dot));
    return std::acos(dot) * (180.0f / 3.1415926535f);
}

bool BodySemanticModel::extractGeometry(
    int width, int height,
    const std::vector<BodyKeypoint>& keypoints,
    const uint8_t* parsingMask,
    HumanFrameResult& outResult
) {
    if (keypoints.size() < JOINT_COUNT) return false;

    // Torso Geometry (Sections 49-53)
    const auto& sL = keypoints[JOINT_SHOULDER_LEFT];
    const auto& sR = keypoints[JOINT_SHOULDER_RIGHT];
    const auto& hL = keypoints[JOINT_HIP_LEFT];
    const auto& hR = keypoints[JOINT_HIP_RIGHT];
    const auto& neck = keypoints[JOINT_NECK];

    outResult.torso.chestWidth = dist(sL, sR);
    outResult.torso.hipWidthObserved = dist(hL, hR);
    outResult.torso.hipWidthEstimated = outResult.torso.hipWidthObserved * 1.05f;

    float shoulderMidX = (sL.x + sR.x) * 0.5f;
    float shoulderMidY = (sL.y + sR.y) * 0.5f;
    float hipMidX = (hL.x + hR.x) * 0.5f;
    float hipMidY = (hL.y + hR.y) * 0.5f;

    outResult.torso.centerX = (shoulderMidX + hipMidX) * 0.5f;
    outResult.torso.centerY = (shoulderMidY + hipMidY) * 0.5f;
    outResult.torso.waistCenterY = shoulderMidY + (hipMidY - shoulderMidY) * 0.60f;
    outResult.torso.hipCenterY = hipMidY;

    float avgTorso = (outResult.torso.chestWidth + outResult.torso.hipWidthObserved) * 0.5f;
    outResult.torso.waistWidthObserved = avgTorso * 0.72f;
    outResult.torso.waistWidthEstimated = outResult.torso.waistWidthObserved;
    outResult.torso.waistHipRatio = (outResult.torso.hipWidthObserved > 1e-3f) ?
        (outResult.torso.waistWidthObserved / outResult.torso.hipWidthObserved) : 0.75f;

    outResult.torso.chestHeight = (hipMidY - shoulderMidY) * 0.55f;
    outResult.torso.abdomenWidth = avgTorso * 0.76f;
    outResult.torso.abdomenCurvature = 0.0f;

    // Arm Geometry (Sections 54-58)
    const auto& eL = keypoints[JOINT_ELBOW_LEFT];
    const auto& wL = keypoints[JOINT_WRIST_LEFT];
    const auto& eR = keypoints[JOINT_ELBOW_RIGHT];
    const auto& wR = keypoints[JOINT_WRIST_RIGHT];

    outResult.leftArm.upperArmLength = dist(sL, eL);
    outResult.leftArm.forearmLength = dist(eL, wL);
    outResult.leftArm.upperArmWidth = outResult.torso.chestWidth * 0.22f;
    outResult.leftArm.forearmWidth = outResult.leftArm.upperArmWidth * 0.75f;
    outResult.leftArm.elbowAngleDeg = angleBetween(sL, eL, wL);

    outResult.rightArm.upperArmLength = dist(sR, eR);
    outResult.rightArm.forearmLength = dist(eR, wR);
    outResult.rightArm.upperArmWidth = outResult.torso.chestWidth * 0.22f;
    outResult.rightArm.forearmWidth = outResult.rightArm.upperArmWidth * 0.75f;
    outResult.rightArm.elbowAngleDeg = angleBetween(sR, eR, wR);

    // Leg Geometry (Sections 63-67)
    const auto& kL = keypoints[JOINT_KNEE_LEFT];
    const auto& aL = keypoints[JOINT_ANKLE_LEFT];
    const auto& kR = keypoints[JOINT_KNEE_RIGHT];
    const auto& aR = keypoints[JOINT_ANKLE_RIGHT];

    outResult.leftLeg.thighLength = dist(hL, kL);
    outResult.leftLeg.lowerLegLength = dist(kL, aL);
    outResult.leftLeg.thighMidWidth = outResult.torso.hipWidthObserved * 0.35f;
    outResult.leftLeg.calfMaxWidth = outResult.leftLeg.thighMidWidth * 0.70f;
    outResult.leftLeg.kneeAngleDeg = angleBetween(hL, kL, aL);
    outResult.leftLeg.kneeCenterX = kL.x;
    outResult.leftLeg.kneeCenterY = kL.y;
    outResult.leftLeg.ankleCenterX = aL.x;
    outResult.leftLeg.ankleCenterY = aL.y;

    outResult.rightLeg.thighLength = dist(hR, kR);
    outResult.rightLeg.lowerLegLength = dist(kR, aR);
    outResult.rightLeg.thighMidWidth = outResult.torso.hipWidthObserved * 0.35f;
    outResult.rightLeg.calfMaxWidth = outResult.rightLeg.thighMidWidth * 0.70f;
    outResult.rightLeg.kneeAngleDeg = angleBetween(hR, kR, aR);
    outResult.rightLeg.kneeCenterX = kR.x;
    outResult.rightLeg.kneeCenterY = kR.y;
    outResult.rightLeg.ankleCenterX = aR.x;
    outResult.rightLeg.ankleCenterY = aR.y;

    // Foot Geometry (Sections 68-71)
    const auto& heelL = keypoints[JOINT_HEEL_LEFT];
    const auto& toeL = keypoints[JOINT_BIG_TOE_LEFT];
    const auto& heelR = keypoints[JOINT_HEEL_RIGHT];
    const auto& toeR = keypoints[JOINT_BIG_TOE_RIGHT];

    outResult.leftFoot.footLength = dist(heelL, toeL);
    outResult.leftFoot.heelY = heelL.y;
    outResult.leftFoot.toeY = toeL.y;
    outResult.leftFoot.isFloorContact = (heelL.visible && heelL.confidence > 0.4f);

    outResult.rightFoot.footLength = dist(heelR, toeR);
    outResult.rightFoot.heelY = heelR.y;
    outResult.rightFoot.toeY = toeR.y;
    outResult.rightFoot.isFloorContact = (heelR.visible && heelR.confidence > 0.4f);

    // Full Body Ratios (Sections 78-81)
    float fullHeight = (heelL.y > 0.0f ? heelL.y : aL.y) - neck.y;
    if (fullHeight > 10.0f) {
        outResult.hasFullBodyVisible = true;
    }

    return true;
}

} // namespace body
} // namespace meitu

namespace meitu_native {

HumanFrameResult BodySemanticEngine::extractHumanModel(
    const std::vector<float>& posePoints,
    const std::vector<float>& headLandmarks,
    const uint32_t* pixels,
    int width,
    int height
) {
    HumanFrameResult result;
    result.personId = 1;
    result.frameWidth = width;
    result.frameHeight = height;

    if (!headLandmarks.empty() && pixels) {
        result.head = HeadSemanticEngine::extractSemanticModel(
            headLandmarks, pixels, width, height
        );
    }

    result.keypoints.resize(JOINT_COUNT);
    size_t numGiven = posePoints.size() / 3;
    for (size_t i = 0; i < JOINT_COUNT; ++i) {
        if (i < numGiven) {
            result.keypoints[i].x = posePoints[i * 3 + 0];
            result.keypoints[i].y = posePoints[i * 3 + 1];
            result.keypoints[i].confidence = posePoints[i * 3 + 2];
            result.keypoints[i].visible = (result.keypoints[i].confidence > 0.25f);
            result.keypoints[i].isVisible = result.keypoints[i].visible;
            result.keypoints[i].pos = {result.keypoints[i].x, result.keypoints[i].y};
        }
    }

    if (numGiven == 0 && result.head.isValid) {
        float throatY = result.head.neckClavicle.throatCenter.y;
        float throatX = result.head.neckClavicle.throatCenter.x;
        float neckW = result.head.neckClavicle.neckWidth;

        result.keypoints[JOINT_NOSE].x = result.head.nose.tip.x;
        result.keypoints[JOINT_NOSE].y = result.head.nose.tip.y;
        result.keypoints[JOINT_NOSE].confidence = 0.9f;
        result.keypoints[JOINT_NOSE].visible = true;

        result.keypoints[JOINT_NECK].x = throatX;
        result.keypoints[JOINT_NECK].y = throatY;
        result.keypoints[JOINT_NECK].confidence = 0.85f;
        result.keypoints[JOINT_NECK].visible = true;

        result.keypoints[JOINT_SHOULDER_LEFT].x = throatX - neckW * 1.5f;
        result.keypoints[JOINT_SHOULDER_LEFT].y = throatY + neckW * 0.8f;
        result.keypoints[JOINT_SHOULDER_LEFT].confidence = 0.7f;
        result.keypoints[JOINT_SHOULDER_LEFT].visible = true;

        result.keypoints[JOINT_SHOULDER_RIGHT].x = throatX + neckW * 1.5f;
        result.keypoints[JOINT_SHOULDER_RIGHT].y = throatY + neckW * 0.8f;
        result.keypoints[JOINT_SHOULDER_RIGHT].confidence = 0.7f;
        result.keypoints[JOINT_SHOULDER_RIGHT].visible = true;

        float estTorsoHeight = neckW * 4.0f;
        result.keypoints[JOINT_HIP_LEFT].x = throatX - neckW * 1.2f;
        result.keypoints[JOINT_HIP_LEFT].y = throatY + estTorsoHeight;
        result.keypoints[JOINT_HIP_LEFT].confidence = 0.6f;
        result.keypoints[JOINT_HIP_LEFT].visible = true;

        result.keypoints[JOINT_HIP_RIGHT].x = throatX + neckW * 1.2f;
        result.keypoints[JOINT_HIP_RIGHT].y = throatY + estTorsoHeight;
        result.keypoints[JOINT_HIP_RIGHT].confidence = 0.6f;
        result.keypoints[JOINT_HIP_RIGHT].visible = true;

        for (int j = 0; j < JOINT_COUNT; ++j) {
            result.keypoints[j].pos = {result.keypoints[j].x, result.keypoints[j].y};
            result.keypoints[j].isVisible = result.keypoints[j].visible;
        }
    }

    result.pose.keypoints = result.keypoints;
    result.pose.isValid = (result.keypoints[JOINT_NECK].visible ||
                           (result.keypoints[JOINT_SHOULDER_LEFT].visible &&
                            result.keypoints[JOINT_SHOULDER_RIGHT].visible));

    // Synthesis of parsing mask when not provided
    result.parsingMask.assign(width * height, CLASS_BACKGROUND);

    auto rasterizeCapsule = [&](float x1, float y1, float x2, float y2, float radius, uint8_t classId) {
        float dx = x2 - x1;
        float dy = y2 - y1;
        float len2 = dx * dx + dy * dy;
        if (len2 < 1.0f) return;
        float invLen2 = 1.0f / len2;

        int minX = std::max(0, static_cast<int>(std::min(x1, x2) - radius));
        int maxX = std::min(width - 1, static_cast<int>(std::max(x1, x2) + radius));
        int minY = std::max(0, static_cast<int>(std::min(y1, y2) - radius));
        int maxY = std::min(height - 1, static_cast<int>(std::max(y1, y2) + radius));
        float r2 = radius * radius;

        for (int y = minY; y <= maxY; ++y) {
            for (int x = minX; x <= maxX; ++x) {
                float px = x - x1;
                float py = y - y1;
                float t = (px * dx + py * dy) * invLen2;
                t = std::max(0.0f, std::min(1.0f, t));
                float closeX = x1 + t * dx;
                float closeY = y1 + t * dy;
                float d2 = (x - closeX) * (x - closeX) + (y - closeY) * (y - closeY);
                if (d2 <= r2) {
                    result.parsingMask[y * width + x] = classId;
                }
            }
        }
    };

    if (result.pose.isValid) {
        const auto& sL = result.keypoints[JOINT_SHOULDER_LEFT];
        const auto& sR = result.keypoints[JOINT_SHOULDER_RIGHT];
        const auto& hL = result.keypoints[JOINT_HIP_LEFT];
        const auto& hR = result.keypoints[JOINT_HIP_RIGHT];
        const auto& neck = result.keypoints[JOINT_NECK];

        float chestW = std::max(20.0f, std::hypot(sL.x - sR.x, sL.y - sR.y));
        float hipW = std::max(20.0f, std::hypot(hL.x - hR.x, hL.y - hR.y));
        float neckX = neck.visible ? neck.x : (sL.x + sR.x) * 0.5f;
        float neckY = neck.visible ? neck.y : (sL.y + sR.y) * 0.5f;
        float hipMidX = (hL.x + hR.x) * 0.5f;
        float hipMidY = (hL.y + hR.y) * 0.5f;

        // 1. Than tren (Upper clothes)
        rasterizeCapsule(neckX, neckY, hipMidX, hipMidY, chestW * 0.55f, CLASS_UPPER_CLOTHES);

        // 2. Hong / Xuong chau (Lower clothes)
        rasterizeCapsule(hipMidX, hipMidY, hipMidX, hipMidY + hipW * 0.35f, hipW * 0.60f, CLASS_LOWER_CLOTHES);

        // 3. Canh tay trai & phai
        if (result.keypoints[JOINT_ELBOW_LEFT].visible) {
            rasterizeCapsule(sL.x, sL.y, result.keypoints[JOINT_ELBOW_LEFT].x, result.keypoints[JOINT_ELBOW_LEFT].y,
                             chestW * 0.20f, CLASS_ARM_LEFT);
            if (result.keypoints[JOINT_WRIST_LEFT].visible) {
                rasterizeCapsule(result.keypoints[JOINT_ELBOW_LEFT].x, result.keypoints[JOINT_ELBOW_LEFT].y,
                                 result.keypoints[JOINT_WRIST_LEFT].x, result.keypoints[JOINT_WRIST_LEFT].y,
                                 chestW * 0.16f, CLASS_ARM_LEFT);
                rasterizeCapsule(result.keypoints[JOINT_WRIST_LEFT].x, result.keypoints[JOINT_WRIST_LEFT].y,
                                 result.keypoints[JOINT_WRIST_LEFT].x, result.keypoints[JOINT_WRIST_LEFT].y + 10.0f,
                                 chestW * 0.14f, CLASS_HAND_LEFT);
            }
        }
        if (result.keypoints[JOINT_ELBOW_RIGHT].visible) {
            rasterizeCapsule(sR.x, sR.y, result.keypoints[JOINT_ELBOW_RIGHT].x, result.keypoints[JOINT_ELBOW_RIGHT].y,
                             chestW * 0.20f, CLASS_ARM_RIGHT);
            if (result.keypoints[JOINT_WRIST_RIGHT].visible) {
                rasterizeCapsule(result.keypoints[JOINT_ELBOW_RIGHT].x, result.keypoints[JOINT_ELBOW_RIGHT].y,
                                 result.keypoints[JOINT_WRIST_RIGHT].x, result.keypoints[JOINT_WRIST_RIGHT].y,
                                 chestW * 0.16f, CLASS_ARM_RIGHT);
                rasterizeCapsule(result.keypoints[JOINT_WRIST_RIGHT].x, result.keypoints[JOINT_WRIST_RIGHT].y,
                                 result.keypoints[JOINT_WRIST_RIGHT].x, result.keypoints[JOINT_WRIST_RIGHT].y + 10.0f,
                                 chestW * 0.14f, CLASS_HAND_RIGHT);
            }
        }

        // 4. Chan trai & phai
        if (result.keypoints[JOINT_KNEE_LEFT].visible) {
            rasterizeCapsule(hL.x, hL.y, result.keypoints[JOINT_KNEE_LEFT].x, result.keypoints[JOINT_KNEE_LEFT].y,
                             hipW * 0.35f, CLASS_LOWER_CLOTHES);
            if (result.keypoints[JOINT_ANKLE_LEFT].visible) {
                rasterizeCapsule(result.keypoints[JOINT_KNEE_LEFT].x, result.keypoints[JOINT_KNEE_LEFT].y,
                                 result.keypoints[JOINT_ANKLE_LEFT].x, result.keypoints[JOINT_ANKLE_LEFT].y,
                                 hipW * 0.25f, CLASS_LEG_LEFT_SKIN);
                rasterizeCapsule(result.keypoints[JOINT_ANKLE_LEFT].x, result.keypoints[JOINT_ANKLE_LEFT].y,
                                 result.keypoints[JOINT_ANKLE_LEFT].x, result.keypoints[JOINT_ANKLE_LEFT].y + 12.0f,
                                 hipW * 0.22f, CLASS_SHOE_LEFT);
            }
        }
        if (result.keypoints[JOINT_KNEE_RIGHT].visible) {
            rasterizeCapsule(hR.x, hR.y, result.keypoints[JOINT_KNEE_RIGHT].x, result.keypoints[JOINT_KNEE_RIGHT].y,
                             hipW * 0.35f, CLASS_LOWER_CLOTHES);
            if (result.keypoints[JOINT_ANKLE_RIGHT].visible) {
                rasterizeCapsule(result.keypoints[JOINT_KNEE_RIGHT].x, result.keypoints[JOINT_KNEE_RIGHT].y,
                                 result.keypoints[JOINT_ANKLE_RIGHT].x, result.keypoints[JOINT_ANKLE_RIGHT].y,
                                 hipW * 0.25f, CLASS_LEG_RIGHT_SKIN);
                rasterizeCapsule(result.keypoints[JOINT_ANKLE_RIGHT].x, result.keypoints[JOINT_ANKLE_RIGHT].y,
                                 result.keypoints[JOINT_ANKLE_RIGHT].x, result.keypoints[JOINT_ANKLE_RIGHT].y + 12.0f,
                                 hipW * 0.22f, CLASS_SHOE_RIGHT);
            }
        }
    }

    if (result.head.isValid) {
        int fx1 = std::max(0, static_cast<int>(result.head.headGeometry.headBox.x1));
        int fy1 = std::max(0, static_cast<int>(result.head.headGeometry.headBox.y1));
        int fx2 = std::min(width - 1, static_cast<int>(result.head.headGeometry.headBox.x2));
        int fy2 = std::min(height - 1, static_cast<int>(result.head.headGeometry.headBox.y2));
        for (int y = fy1; y <= fy2; ++y) {
            for (int x = fx1; x <= fx2; ++x) {
                result.parsingMask[y * width + x] = CLASS_FACE;
            }
        }
    }

    // Trich xuat cac duong thang boi canh (Structural Lines)
    meitu::body::BackgroundProtectionEngine bgEngine;
    if (pixels) {
        bgEngine.detectStructuralLines(reinterpret_cast<const uint8_t*>(pixels), width, height, result.structuralLines);
    }

    // Tao mat na bao ve boi canh (Background Protection Mask)
    result.backgroundProtectionMask.resize(width * height);
    bgEngine.generateProtectionMask(
        width, height, result.parsingMask.data(), result.structuralLines, result.backgroundProtectionMask.data()
    );

    meitu::body::BodySemanticModel analyzer;
    analyzer.extractGeometry(width, height, result.keypoints, result.parsingMask.data(), result);

    // Torso fields
    result.torso.shoulderWidth = result.torso.chestWidth;
    result.torso.waistWidth = result.torso.chestWidth * 0.78f;
    result.torso.hipWidth = result.torso.hipWidthObserved;
    result.torso.chestCenter = {result.torso.centerX, result.torso.centerY - result.torso.chestHeight * 0.3f};
    result.torso.waistCenter = {result.torso.centerX, result.torso.centerY};
    result.torso.hipCenter = {result.torso.centerX, result.torso.hipCenterY};

    // Arm fields
    result.leftArm.shoulder = result.keypoints[JOINT_SHOULDER_LEFT].pos;
    result.leftArm.elbow = result.keypoints[JOINT_ELBOW_LEFT].pos;
    result.leftArm.wrist = result.keypoints[JOINT_WRIST_LEFT].pos;
    result.leftArm.armLength = result.leftArm.upperArmLength + result.leftArm.forearmLength;
    result.leftArm.isVisible = result.keypoints[JOINT_ELBOW_LEFT].visible;

    result.rightArm.shoulder = result.keypoints[JOINT_SHOULDER_RIGHT].pos;
    result.rightArm.elbow = result.keypoints[JOINT_ELBOW_RIGHT].pos;
    result.rightArm.wrist = result.keypoints[JOINT_WRIST_RIGHT].pos;
    result.rightArm.armLength = result.rightArm.upperArmLength + result.rightArm.forearmLength;
    result.rightArm.isVisible = result.keypoints[JOINT_ELBOW_RIGHT].visible;

    // Check hand occlusion
    float waistTop = result.torso.waistCenter.y - result.torso.shoulderWidth * 0.4f;
    float waistBottom = result.torso.waistCenter.y + result.torso.shoulderWidth * 0.4f;
    float waistLeft = result.torso.waistCenter.x - result.torso.waistWidth * 0.6f;
    float waistRight = result.torso.waistCenter.x + result.torso.waistWidth * 0.6f;

    if (result.leftArm.wrist.x >= waistLeft && result.leftArm.wrist.x <= waistRight &&
        result.leftArm.wrist.y >= waistTop && result.leftArm.wrist.y <= waistBottom) {
        result.leftArm.isOccludingTorso = true;
    }
    if (result.rightArm.wrist.x >= waistLeft && result.rightArm.wrist.x <= waistRight &&
        result.rightArm.wrist.y >= waistTop && result.rightArm.wrist.y <= waistBottom) {
        result.rightArm.isOccludingTorso = true;
    }

    // Leg fields
    result.leftLeg.hip = result.keypoints[JOINT_HIP_LEFT].pos;
    result.leftLeg.knee = {result.leftLeg.kneeCenterX, result.leftLeg.kneeCenterY};
    result.leftLeg.ankle = {result.leftLeg.ankleCenterX, result.leftLeg.ankleCenterY};
    result.leftLeg.thighWidth = result.leftLeg.thighMidWidth;
    result.leftLeg.calfWidth = result.leftLeg.calfMaxWidth;
    result.leftLeg.isVisible = result.keypoints[JOINT_KNEE_LEFT].visible;

    result.rightLeg.hip = result.keypoints[JOINT_HIP_RIGHT].pos;
    result.rightLeg.knee = {result.rightLeg.kneeCenterX, result.rightLeg.kneeCenterY};
    result.rightLeg.ankle = {result.rightLeg.ankleCenterX, result.rightLeg.ankleCenterY};
    result.rightLeg.thighWidth = result.rightLeg.thighMidWidth;
    result.rightLeg.calfWidth = result.rightLeg.calfMaxWidth;
    result.rightLeg.isVisible = result.keypoints[JOINT_KNEE_RIGHT].visible;

    // Background bounding box
    float minX = static_cast<float>(width), maxX = 0.0f;
    float minY = static_cast<float>(height), maxY = 0.0f;
    for (const auto& kp : result.keypoints) {
        if (kp.visible) {
            minX = std::min(minX, kp.x);
            maxX = std::max(maxX, kp.x);
            minY = std::min(minY, kp.y);
            maxY = std::max(maxY, kp.y);
        }
    }
    if (result.head.isValid) {
        minX = std::min(minX, result.head.headGeometry.headBox.x1);
        maxX = std::max(maxX, result.head.headGeometry.headBox.x2);
        minY = std::min(minY, result.head.headGeometry.headBox.y1);
        maxY = std::max(maxY, result.head.headGeometry.headBox.y2);
    }
    float marginX = (maxX - minX) * 0.2f;
    float marginY = (maxY - minY) * 0.1f;
    result.background.bodyBoundingBox = {
        std::max(0.0f, minX - marginX),
        std::max(0.0f, minY - marginY),
        std::min(static_cast<float>(width - 1), maxX + marginX),
        std::min(static_cast<float>(height - 1), maxY + marginY)
    };
    result.background.backgroundRigidity = 1.0f;

    result.isValid = (result.pose.isValid || result.head.isValid);
    result.overallConfidence = result.isValid ? 0.95f : 0.0f;

    return result;
}

} // namespace meitu_native

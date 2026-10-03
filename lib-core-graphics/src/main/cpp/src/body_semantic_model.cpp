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
    bool hasKnees = (kL.visible || kR.visible);
    bool hasAnkles = (aL.visible || aR.visible);
    outResult.hasLegsVisible = hasKnees || hasAnkles;
    outResult.hasFullBodyVisible = outResult.hasLegsVisible && ((heelL.visible && heelL.confidence > 0.3f) || (heelR.visible && heelR.confidence > 0.3f) || hasAnkles);

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
            float kx = posePoints[i * 3 + 0];
            float ky = posePoints[i * 3 + 1];
            float conf = posePoints[i * 3 + 2];
            result.keypoints[i].x = kx;
            result.keypoints[i].y = ky;
            result.keypoints[i].confidence = conf;
            bool inBounds = (kx >= 0.0f && kx < static_cast<float>(width) &&
                             ky >= 0.0f && ky < static_cast<float>(height));
            result.keypoints[i].visible = (conf > 0.25f && inBounds);
            result.keypoints[i].isVisible = result.keypoints[i].visible;
            result.keypoints[i].pos = {kx, ky};
        }
    }

    if (numGiven == 0 && result.head.isValid) {
        float throatY = result.head.neckClavicle.throatCenter.y;
        float throatX = result.head.neckClavicle.throatCenter.x;
        float neckW = std::max(20.0f, result.head.neckClavicle.neckWidth);
        float headH = std::max(25.0f, result.head.headGeometry.headBox.y2 - result.head.headGeometry.headBox.y1);
        float availableH = static_cast<float>(height) - throatY;
        float headUnits = availableH / headH;

        // Head and Neck
        result.keypoints[JOINT_NOSE].x = result.head.nose.tip.x;
        result.keypoints[JOINT_NOSE].y = result.head.nose.tip.y;
        result.keypoints[JOINT_NOSE].confidence = 0.95f;
        result.keypoints[JOINT_NOSE].visible = true;

        result.keypoints[JOINT_NECK].x = throatX;
        result.keypoints[JOINT_NECK].y = throatY;
        result.keypoints[JOINT_NECK].confidence = 0.90f;
        result.keypoints[JOINT_NECK].visible = true;

        // Shoulders
        float shoulderY = throatY + neckW * 0.8f;
        float sLX = throatX - neckW * 1.5f;
        float sRX = throatX + neckW * 1.5f;
        bool shoulderInBounds = (shoulderY < static_cast<float>(height) - 5.0f);

        result.keypoints[JOINT_SHOULDER_LEFT].x = sLX;
        result.keypoints[JOINT_SHOULDER_LEFT].y = shoulderY;
        result.keypoints[JOINT_SHOULDER_LEFT].confidence = shoulderInBounds ? 0.75f : 0.0f;
        result.keypoints[JOINT_SHOULDER_LEFT].visible = shoulderInBounds;

        result.keypoints[JOINT_SHOULDER_RIGHT].x = sRX;
        result.keypoints[JOINT_SHOULDER_RIGHT].y = shoulderY;
        result.keypoints[JOINT_SHOULDER_RIGHT].confidence = shoulderInBounds ? 0.75f : 0.0f;
        result.keypoints[JOINT_SHOULDER_RIGHT].visible = shoulderInBounds;

        // Torso / Hips: Requires headUnits >= 2.2f and within image bounds
        float estTorsoHeight = headH * 2.2f;
        float hipY = throatY + estTorsoHeight;
        bool hipInBounds = (headUnits >= 2.2f && hipY < static_cast<float>(height) - 15.0f);

        result.keypoints[JOINT_SPINE_MID].x = throatX;
        result.keypoints[JOINT_SPINE_MID].y = throatY + estTorsoHeight * 0.5f;
        result.keypoints[JOINT_SPINE_MID].confidence = hipInBounds ? 0.65f : 0.0f;
        result.keypoints[JOINT_SPINE_MID].visible = hipInBounds;

        result.keypoints[JOINT_PELVIS_CENTER].x = throatX;
        result.keypoints[JOINT_PELVIS_CENTER].y = hipY;
        result.keypoints[JOINT_PELVIS_CENTER].confidence = hipInBounds ? 0.65f : 0.0f;
        result.keypoints[JOINT_PELVIS_CENTER].visible = hipInBounds;

        result.keypoints[JOINT_HIP_LEFT].x = throatX - neckW * 1.2f;
        result.keypoints[JOINT_HIP_LEFT].y = hipY;
        result.keypoints[JOINT_HIP_LEFT].confidence = hipInBounds ? 0.60f : 0.0f;
        result.keypoints[JOINT_HIP_LEFT].visible = hipInBounds;

        result.keypoints[JOINT_HIP_RIGHT].x = throatX + neckW * 1.2f;
        result.keypoints[JOINT_HIP_RIGHT].y = hipY;
        result.keypoints[JOINT_HIP_RIGHT].confidence = hipInBounds ? 0.60f : 0.0f;
        result.keypoints[JOINT_HIP_RIGHT].visible = hipInBounds;

        // Arms: Elbows and Wrists
        float elbowY = throatY + headH * 1.3f;
        float wristY = throatY + headH * 2.3f;
        bool elbowInBounds = (headUnits >= 1.5f && elbowY < static_cast<float>(height) - 10.0f);
        bool wristInBounds = (headUnits >= 2.5f && wristY < static_cast<float>(height) - 10.0f);

        result.keypoints[JOINT_ELBOW_LEFT].x = sLX - neckW * 0.5f;
        result.keypoints[JOINT_ELBOW_LEFT].y = elbowY;
        result.keypoints[JOINT_ELBOW_LEFT].confidence = elbowInBounds ? 0.55f : 0.0f;
        result.keypoints[JOINT_ELBOW_LEFT].visible = elbowInBounds;

        result.keypoints[JOINT_ELBOW_RIGHT].x = sRX + neckW * 0.5f;
        result.keypoints[JOINT_ELBOW_RIGHT].y = elbowY;
        result.keypoints[JOINT_ELBOW_RIGHT].confidence = elbowInBounds ? 0.55f : 0.0f;
        result.keypoints[JOINT_ELBOW_RIGHT].visible = elbowInBounds;

        result.keypoints[JOINT_WRIST_LEFT].x = sLX - neckW * 0.4f;
        result.keypoints[JOINT_WRIST_LEFT].y = wristY;
        result.keypoints[JOINT_WRIST_LEFT].confidence = wristInBounds ? 0.50f : 0.0f;
        result.keypoints[JOINT_WRIST_LEFT].visible = wristInBounds;

        result.keypoints[JOINT_WRIST_RIGHT].x = sRX + neckW * 0.4f;
        result.keypoints[JOINT_WRIST_RIGHT].y = wristY;
        result.keypoints[JOINT_WRIST_RIGHT].confidence = wristInBounds ? 0.50f : 0.0f;
        result.keypoints[JOINT_WRIST_RIGHT].visible = wristInBounds;

        // Legs: Knees and Ankles
        float kneeY = hipY + headH * 1.8f;
        float ankleY = kneeY + headH * 1.8f;
        bool kneeInBounds = (headUnits >= 4.2f && kneeY < static_cast<float>(height) - 20.0f);
        bool ankleInBounds = (headUnits >= 6.0f && ankleY < static_cast<float>(height) - 10.0f);

        result.keypoints[JOINT_KNEE_LEFT].x = throatX - neckW * 1.0f;
        result.keypoints[JOINT_KNEE_LEFT].y = kneeY;
        result.keypoints[JOINT_KNEE_LEFT].confidence = kneeInBounds ? 0.55f : 0.0f;
        result.keypoints[JOINT_KNEE_LEFT].visible = kneeInBounds;

        result.keypoints[JOINT_KNEE_RIGHT].x = throatX + neckW * 1.0f;
        result.keypoints[JOINT_KNEE_RIGHT].y = kneeY;
        result.keypoints[JOINT_KNEE_RIGHT].confidence = kneeInBounds ? 0.55f : 0.0f;
        result.keypoints[JOINT_KNEE_RIGHT].visible = kneeInBounds;

        result.keypoints[JOINT_ANKLE_LEFT].x = throatX - neckW * 0.9f;
        result.keypoints[JOINT_ANKLE_LEFT].y = ankleY;
        result.keypoints[JOINT_ANKLE_LEFT].confidence = ankleInBounds ? 0.50f : 0.0f;
        result.keypoints[JOINT_ANKLE_LEFT].visible = ankleInBounds;

        result.keypoints[JOINT_ANKLE_RIGHT].x = throatX + neckW * 0.9f;
        result.keypoints[JOINT_ANKLE_RIGHT].y = ankleY;
        result.keypoints[JOINT_ANKLE_RIGHT].confidence = ankleInBounds ? 0.50f : 0.0f;
        result.keypoints[JOINT_ANKLE_RIGHT].visible = ankleInBounds;

        // Feet
        result.keypoints[JOINT_HEEL_LEFT].x = result.keypoints[JOINT_ANKLE_LEFT].x;
        result.keypoints[JOINT_HEEL_LEFT].y = ankleY + 15.0f;
        result.keypoints[JOINT_HEEL_LEFT].confidence = (ankleInBounds && result.keypoints[JOINT_HEEL_LEFT].y < static_cast<float>(height)) ? 0.45f : 0.0f;
        result.keypoints[JOINT_HEEL_LEFT].visible = (result.keypoints[JOINT_HEEL_LEFT].confidence > 0.0f);

        result.keypoints[JOINT_HEEL_RIGHT].x = result.keypoints[JOINT_ANKLE_RIGHT].x;
        result.keypoints[JOINT_HEEL_RIGHT].y = ankleY + 15.0f;
        result.keypoints[JOINT_HEEL_RIGHT].confidence = (ankleInBounds && result.keypoints[JOINT_HEEL_RIGHT].y < static_cast<float>(height)) ? 0.45f : 0.0f;
        result.keypoints[JOINT_HEEL_RIGHT].visible = (result.keypoints[JOINT_HEEL_RIGHT].confidence > 0.0f);

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
    result.leftLeg.isVisible = result.keypoints[JOINT_HIP_LEFT].visible && result.keypoints[JOINT_KNEE_LEFT].visible;

    result.rightLeg.hip = result.keypoints[JOINT_HIP_RIGHT].pos;
    result.rightLeg.knee = {result.rightLeg.kneeCenterX, result.rightLeg.kneeCenterY};
    result.rightLeg.ankle = {result.rightLeg.ankleCenterX, result.rightLeg.ankleCenterY};
    result.rightLeg.thighWidth = result.rightLeg.thighMidWidth;
    result.rightLeg.calfWidth = result.rightLeg.calfMaxWidth;
    result.rightLeg.isVisible = result.keypoints[JOINT_HIP_RIGHT].visible && result.keypoints[JOINT_KNEE_RIGHT].visible;

    result.hasLegsVisible = (result.leftLeg.isVisible || result.rightLeg.isVisible);
    result.hasFullBodyVisible = result.hasLegsVisible && (result.keypoints[JOINT_ANKLE_LEFT].visible || result.keypoints[JOINT_ANKLE_RIGHT].visible);

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

int BodySemanticEngine::checkToolApplicability(
    const std::string& toolId,
    const HumanFrameResult& human
) {
    if (!human.isValid) return APPLICABILITY_INVALID;

    if (toolId == "tool_body_legs" || toolId == "tool_long_legs" || toolId == "tool_leg_length") {
        return (human.hasLegsVisible || human.leftLeg.isVisible || human.rightLeg.isVisible) ? APPLICABILITY_APPLICABLE : APPLICABILITY_NOT_APPLICABLE;
    }
    if (toolId == "tool_leg_slim" || toolId == "tool_body_legs_slim") {
        return (human.leftLeg.isVisible || human.rightLeg.isVisible) ? APPLICABILITY_APPLICABLE : APPLICABILITY_NOT_APPLICABLE;
    }
    if (toolId == "tool_body_height" || toolId == "tool_height") {
        bool hasTorso = human.keypoints[JOINT_HIP_LEFT].visible && human.keypoints[JOINT_HIP_RIGHT].visible;
        return (hasTorso || human.hasLegsVisible) ? APPLICABILITY_APPLICABLE : APPLICABILITY_NOT_APPLICABLE;
    }
    if (toolId == "tool_body_waist" || toolId == "tool_body_slim" || toolId == "tool_body_hip" || toolId == "tool_hip_enhance") {
        bool hasWaist = human.keypoints[JOINT_HIP_LEFT].visible || human.keypoints[JOINT_HIP_RIGHT].visible ||
                        (human.torso.waistCenterY > 0.0f && human.torso.waistCenterY < static_cast<float>(human.frameHeight) - 20.0f);
        return hasWaist ? APPLICABILITY_APPLICABLE : APPLICABILITY_NOT_APPLICABLE;
    }
    if (toolId == "tool_body_chest") {
        bool hasChest = (human.keypoints[JOINT_SHOULDER_LEFT].visible && human.keypoints[JOINT_SHOULDER_RIGHT].visible &&
                         human.torso.chestCenter.y < static_cast<float>(human.frameHeight) - 15.0f);
        return hasChest ? APPLICABILITY_APPLICABLE : APPLICABILITY_NOT_APPLICABLE;
    }
    if (toolId == "tool_body_shoulder" || toolId == "tool_neck_slim" || toolId == "tool_body_neck" ||
        toolId == "tool_neck_length" || toolId == "tool_swan_neck" || toolId == "tool_clavicle_enhance" ||
        toolId == "tool_face_neck_tone") {
        return human.keypoints[JOINT_NECK].visible ? APPLICABILITY_APPLICABLE : APPLICABILITY_NOT_APPLICABLE;
    }
    if (toolId == "tool_body_arm" || toolId == "tool_arm_slim") {
        return (human.leftArm.isVisible || human.rightArm.isVisible) ? APPLICABILITY_APPLICABLE : APPLICABILITY_NOT_APPLICABLE;
    }
    if (toolId == "tool_body_skin_smooth" || toolId == "tool_body_skin_whiten") {
        return APPLICABILITY_APPLICABLE;
    }

    return APPLICABILITY_APPLICABLE;
}

} // namespace meitu_native

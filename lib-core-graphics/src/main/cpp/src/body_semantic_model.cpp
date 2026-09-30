#include "body_semantic_model.h"
#include <cmath>
#include <algorithm>

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
    if (keypoints.size() < JOINT_COUNT || width <= 0 || height <= 0) {
        return false;
    }

    outResult.frameWidth = width;
    outResult.frameHeight = height;
    outResult.keypoints = keypoints;

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

    outResult.torso.chestHeight = std::abs(shoulderMidY - outResult.torso.waistCenterY);
    outResult.torso.abdomenWidth = outResult.torso.waistWidthObserved * 0.95f;
    outResult.torso.confidence = std::min({sL.confidence, sR.confidence, hL.confidence, hR.confidence});

    // Left Arm (Sections 54-58)
    const auto& eL = keypoints[JOINT_ELBOW_LEFT];
    const auto& wL = keypoints[JOINT_WRIST_LEFT];
    outResult.leftArm.isLeft = true;
    outResult.leftArm.upperArmLength = dist(sL, eL);
    outResult.leftArm.forearmLength = dist(eL, wL);
    outResult.leftArm.upperArmWidth = outResult.leftArm.upperArmLength * 0.26f;
    outResult.leftArm.forearmWidth = outResult.leftArm.forearmLength * 0.22f;
    outResult.leftArm.wristWidth = outResult.leftArm.forearmWidth * 0.65f;
    outResult.leftArm.elbowAngleDeg = angleBetween(sL, eL, wL);
    outResult.leftArm.confidence = std::min({sL.confidence, eL.confidence, wL.confidence});

    // Right Arm
    const auto& eR = keypoints[JOINT_ELBOW_RIGHT];
    const auto& wR = keypoints[JOINT_WRIST_RIGHT];
    outResult.rightArm.isLeft = false;
    outResult.rightArm.upperArmLength = dist(sR, eR);
    outResult.rightArm.forearmLength = dist(eR, wR);
    outResult.rightArm.upperArmWidth = outResult.rightArm.upperArmLength * 0.26f;
    outResult.rightArm.forearmWidth = outResult.rightArm.forearmLength * 0.22f;
    outResult.rightArm.wristWidth = outResult.rightArm.forearmWidth * 0.65f;
    outResult.rightArm.elbowAngleDeg = angleBetween(sR, eR, wR);
    outResult.rightArm.confidence = std::min({sR.confidence, eR.confidence, wR.confidence});

    // Left Leg (Sections 63-68)
    const auto& kL = keypoints[JOINT_KNEE_LEFT];
    const auto& aL = keypoints[JOINT_ANKLE_LEFT];
    outResult.leftLeg.isLeft = true;
    outResult.leftLeg.thighLength = dist(hL, kL);
    outResult.leftLeg.lowerLegLength = dist(kL, aL);
    outResult.leftLeg.thighUpperWidth = outResult.leftLeg.thighLength * 0.32f;
    outResult.leftLeg.thighMidWidth = outResult.leftLeg.thighLength * 0.27f;
    outResult.leftLeg.thighLowerWidth = outResult.leftLeg.thighLength * 0.20f;
    outResult.leftLeg.calfMaxWidth = outResult.leftLeg.lowerLegLength * 0.23f;
    outResult.leftLeg.ankleWidth = outResult.leftLeg.calfMaxWidth * 0.58f;
    outResult.leftLeg.kneeCenterX = kL.x;
    outResult.leftLeg.kneeCenterY = kL.y;
    outResult.leftLeg.ankleCenterX = aL.x;
    outResult.leftLeg.ankleCenterY = aL.y;
    outResult.leftLeg.kneeAngleDeg = angleBetween(hL, kL, aL);
    outResult.leftLeg.confidence = std::min({hL.confidence, kL.confidence, aL.confidence});

    // Right Leg
    const auto& kR = keypoints[JOINT_KNEE_RIGHT];
    const auto& aR = keypoints[JOINT_ANKLE_RIGHT];
    outResult.rightLeg.isLeft = false;
    outResult.rightLeg.thighLength = dist(hR, kR);
    outResult.rightLeg.lowerLegLength = dist(kR, aR);
    outResult.rightLeg.thighUpperWidth = outResult.rightLeg.thighLength * 0.32f;
    outResult.rightLeg.thighMidWidth = outResult.rightLeg.thighLength * 0.27f;
    outResult.rightLeg.thighLowerWidth = outResult.rightLeg.thighLength * 0.20f;
    outResult.rightLeg.calfMaxWidth = outResult.rightLeg.lowerLegLength * 0.23f;
    outResult.rightLeg.ankleWidth = outResult.rightLeg.calfMaxWidth * 0.58f;
    outResult.rightLeg.kneeCenterX = kR.x;
    outResult.rightLeg.kneeCenterY = kR.y;
    outResult.rightLeg.ankleCenterX = aR.x;
    outResult.rightLeg.ankleCenterY = aR.y;
    outResult.rightLeg.kneeAngleDeg = angleBetween(hR, kR, aR);
    outResult.rightLeg.confidence = std::min({hR.confidence, kR.confidence, aR.confidence});

    // Feet (Sections 69-71)
    const auto& heelL = keypoints[JOINT_HEEL_LEFT];
    const auto& toeL = keypoints[JOINT_BIG_TOE_LEFT];
    outResult.leftFoot.isLeft = true;
    outResult.leftFoot.heelX = heelL.x;
    outResult.leftFoot.heelY = heelL.y;
    outResult.leftFoot.toeX = toeL.x;
    outResult.leftFoot.toeY = toeL.y;
    outResult.leftFoot.footLength = dist(heelL, toeL);
    outResult.leftFoot.footWidth = outResult.leftFoot.footLength * 0.38f;
    outResult.leftFoot.confidence = std::min(heelL.confidence, toeL.confidence);

    const auto& heelR = keypoints[JOINT_HEEL_RIGHT];
    const auto& toeR = keypoints[JOINT_BIG_TOE_RIGHT];
    outResult.rightFoot.isLeft = false;
    outResult.rightFoot.heelX = heelR.x;
    outResult.rightFoot.heelY = heelR.y;
    outResult.rightFoot.toeX = toeR.x;
    outResult.rightFoot.toeY = toeR.y;
    outResult.rightFoot.footLength = dist(heelR, toeR);
    outResult.rightFoot.footWidth = outResult.rightFoot.footLength * 0.38f;
    outResult.rightFoot.confidence = std::min(heelR.confidence, toeR.confidence);

    outResult.hasLegsVisible = (outResult.leftLeg.confidence > 0.3f && outResult.rightLeg.confidence > 0.3f);
    outResult.hasFullBodyVisible = outResult.hasLegsVisible && (outResult.torso.confidence > 0.4f);
    outResult.overallConfidence = (outResult.torso.confidence + outResult.leftLeg.confidence + outResult.rightLeg.confidence) / 3.0f;

    return true;
}

float BodySemanticModel::computeLegToBodyRatio(const HumanFrameResult& result) {
    float torsoLen = std::abs(result.torso.hipCenterY - ((result.keypoints[JOINT_SHOULDER_LEFT].y + result.keypoints[JOINT_SHOULDER_RIGHT].y) * 0.5f));
    float legLen = (result.leftLeg.thighLength + result.leftLeg.lowerLegLength + result.rightLeg.thighLength + result.rightLeg.lowerLegLength) * 0.5f;
    float totalBody = torsoLen + legLen;
    if (totalBody < 1e-3f) return 0.55f;
    return legLen / totalBody;
}

float BodySemanticModel::computeWaistToHipRatio(const HumanFrameResult& result) {
    return result.torso.waistHipRatio;
}

float BodySemanticModel::computeShoulderToHipRatio(const HumanFrameResult& result) {
    if (result.torso.hipWidthObserved < 1e-3f) return 1.0f;
    return result.torso.chestWidth / result.torso.hipWidthObserved;
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

    meitu::body::BodySemanticModel analyzer;
    analyzer.extractGeometry(width, height, result.keypoints, nullptr, result);

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


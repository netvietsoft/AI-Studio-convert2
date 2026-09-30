#ifndef MEITU_BODY_SEMANTIC_MODEL_H
#define MEITU_BODY_SEMANTIC_MODEL_H

#include <vector>
#include <string>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include "head_semantic_model.h"

namespace meitu_native {

enum WholeBodyJoint {
    JOINT_NOSE = 0,
    JOINT_NECK = 1,
    JOINT_SHOULDER_LEFT = 2,
    JOINT_SHOULDER_RIGHT = 3,
    JOINT_ELBOW_LEFT = 4,
    JOINT_ELBOW_RIGHT = 5,
    JOINT_WRIST_LEFT = 6,
    JOINT_WRIST_RIGHT = 7,
    JOINT_HIP_LEFT = 8,
    JOINT_HIP_RIGHT = 9,
    JOINT_KNEE_LEFT = 10,
    JOINT_KNEE_RIGHT = 11,
    JOINT_ANKLE_LEFT = 12,
    JOINT_ANKLE_RIGHT = 13,
    JOINT_HEEL_LEFT = 14,
    JOINT_HEEL_RIGHT = 15,
    JOINT_BIG_TOE_LEFT = 16,
    JOINT_BIG_TOE_RIGHT = 17,
    JOINT_SMALL_TOE_LEFT = 18,
    JOINT_SMALL_TOE_RIGHT = 19,
    JOINT_PELVIS_CENTER = 20,
    JOINT_SPINE_MID = 21,
    JOINT_COUNT = 22
};

struct BodyKeypoint {
    float x{0.0f};
    float y{0.0f};
    float z{0.0f};
    float confidence{0.0f};
    bool visible{false};
    bool isVisible{false};
    Point2DF pos{0.0f, 0.0f};
};

struct BodyPose {
    bool isValid{false};
    std::vector<BodyKeypoint> keypoints;
};

enum BodyParsingClass {
    CLASS_BACKGROUND = 0,
    CLASS_HAIR = 1,
    CLASS_FACE = 2,
    CLASS_NECK = 3,
    CLASS_TORSO_SKIN = 4,
    CLASS_UPPER_CLOTHES = 5,
    CLASS_LOWER_CLOTHES = 6,
    CLASS_DRESS = 7,
    CLASS_ARM_LEFT = 8,
    CLASS_ARM_RIGHT = 9,
    CLASS_HAND_LEFT = 10,
    CLASS_HAND_RIGHT = 11,
    CLASS_LEG_LEFT_SKIN = 12,
    CLASS_LEG_RIGHT_SKIN = 13,
    CLASS_FOOT_LEFT = 14,
    CLASS_FOOT_RIGHT = 15,
    CLASS_SHOE_LEFT = 16,
    CLASS_SHOE_RIGHT = 17,
    CLASS_ACCESSORY = 18,
    CLASS_FOREGROUND_OBJ = 19,
    CLASS_COUNT = 20
};

struct TorsoGeometry {
    float centerX{0.0f};
    float centerY{0.0f};
    float shoulderWidth{0.0f};
    float chestWidth{0.0f};
    float chestHeight{0.0f};
    float waistWidth{0.0f};
    float waistWidthObserved{0.0f};
    float waistWidthEstimated{0.0f};
    float waistCenterY{0.0f};
    float leftWaistCurve{0.0f};
    float rightWaistCurve{0.0f};
    float waistHipRatio{0.7f};
    float abdomenWidth{0.0f};
    float abdomenCurvature{0.0f};
    float hipWidth{0.0f};
    float hipWidthObserved{0.0f};
    float hipWidthEstimated{0.0f};
    float hipCenterY{0.0f};
    float leftHipCurve{0.0f};
    float rightHipCurve{0.0f};
    float torsoRotationAngle{0.0f};
    float torsoTiltAngle{0.0f};
    float depthEstimate{0.0f};
    float confidence{0.0f};
    Point2DF waistCenter{0.0f, 0.0f};
    Point2DF chestCenter{0.0f, 0.0f};
    Point2DF hipCenter{0.0f, 0.0f};
};

struct ArmGeometry {
    bool isLeft{true};
    Point2DF shoulder{0.0f, 0.0f};
    Point2DF elbow{0.0f, 0.0f};
    Point2DF wrist{0.0f, 0.0f};
    float upperArmLength{0.0f};
    float upperArmWidth{0.0f};
    float forearmLength{0.0f};
    float forearmWidth{0.0f};
    float armLength{0.0f};
    float elbowAngleDeg{0.0f};
    float wristWidth{0.0f};
    float depthOrder{0.0f};
    float confidence{0.0f};
    bool isVisible{false};
    bool isOccludingTorso{false};
};

struct FingerGeometry {
    float length{0.0f};
    float baseWidth{0.0f};
    float midWidth{0.0f};
    float tipWidth{0.0f};
    float curvature{0.0f};
    bool nailVisible{false};
};

struct HandGeometry {
    bool isLeft{true};
    float palmCenterX{0.0f};
    float palmCenterY{0.0f};
    float palmWidth{0.0f};
    float palmLength{0.0f};
    FingerGeometry fingers[5];
    bool isPalmFacing{true};
    float confidence{0.0f};
    bool isVisible{false};
};

struct LegGeometry {
    bool isLeft{true};
    Point2DF hip{0.0f, 0.0f};
    Point2DF knee{0.0f, 0.0f};
    Point2DF ankle{0.0f, 0.0f};
    float thighLength{0.0f};
    float lowerLegLength{0.0f};
    float legLength{0.0f};
    float thighUpperWidth{0.0f};
    float thighMidWidth{0.0f};
    float thighLowerWidth{0.0f};
    float thighWidth{0.0f};
    float kneeWidth{0.0f};
    float calfMaxWidth{0.0f};
    float calfWidth{0.0f};
    float ankleWidth{0.0f};
    float kneeCenterX{0.0f};
    float kneeCenterY{0.0f};
    float ankleCenterX{0.0f};
    float ankleCenterY{0.0f};
    float kneeAngleDeg{0.0f};
    float confidence{0.0f};
    bool isVisible{false};
};

struct FootGeometry {
    bool isLeft{true};
    Point2DF heel{0.0f, 0.0f};
    Point2DF bigToe{0.0f, 0.0f};
    Point2DF smallToe{0.0f, 0.0f};
    float heelX{0.0f};
    float heelY{0.0f};
    float toeX{0.0f};
    float toeY{0.0f};
    float footLength{0.0f};
    float footWidth{0.0f};
    bool isShoe{false};
    bool isFloorContact{true};
    float confidence{0.0f};
    bool isVisible{false};
};

enum StructuralLineType {
    LINE_WALL_VERTICAL = 0,
    LINE_FLOOR_HORIZONTAL = 1,
    LINE_DIAGONAL = 2
};

struct StructuralLine {
    float x1{0.0f}, y1{0.0f};
    float x2{0.0f}, y2{0.0f};
    bool isVertical{false};
    float confidence{0.0f};
    float length{0.0f};
    float angleDeg{0.0f};
    float stiffness{1.0f};
    StructuralLineType type{LINE_WALL_VERTICAL};
};

struct BackgroundGeometry {
    BoundingBox2D bodyBoundingBox{0.0f, 0.0f, 0.0f, 0.0f};
    std::vector<StructuralLine> structuralLines;
    float backgroundRigidity{1.0f};
    bool hasComplexScene{false};
};

struct HumanFrameResult {
    int personId{1};
    int frameWidth{0};
    int frameHeight{0};
    bool isValid{false};
    HeadFrameResult head;
    std::vector<BodyKeypoint> keypoints;
    BodyPose pose;
    TorsoGeometry torso;
    ArmGeometry leftArm;
    ArmGeometry rightArm;
    HandGeometry leftHand;
    HandGeometry rightHand;
    LegGeometry leftLeg;
    LegGeometry rightLeg;
    FootGeometry leftFoot;
    FootGeometry rightFoot;
    BackgroundGeometry background;
    std::vector<uint8_t> parsingMask;
    std::vector<uint8_t> backgroundProtectionMask;
    std::vector<StructuralLine> structuralLines;
    bool hasLegsVisible{false};
    bool hasFullBodyVisible{false};
    float overallConfidence{0.0f};
};

class BodySemanticEngine {
public:
    static HumanFrameResult extractHumanModel(
        const std::vector<float>& posePoints,
        const std::vector<float>& headLandmarks,
        const uint32_t* pixels,
        int width,
        int height
    );
};

} // namespace meitu_native

namespace meitu {
namespace body {

using namespace meitu_native;

using WholeBodyJoint = meitu_native::WholeBodyJoint;
using BodyKeypoint = meitu_native::BodyKeypoint;
using BodyPose = meitu_native::BodyPose;
using BodyParsingClass = meitu_native::BodyParsingClass;
using TorsoGeometry = meitu_native::TorsoGeometry;
using ArmGeometry = meitu_native::ArmGeometry;
using FingerGeometry = meitu_native::FingerGeometry;
using HandGeometry = meitu_native::HandGeometry;
using LegGeometry = meitu_native::LegGeometry;
using FootGeometry = meitu_native::FootGeometry;
using StructuralLine = meitu_native::StructuralLine;
using StructuralLineType = meitu_native::StructuralLineType;
using meitu_native::LINE_WALL_VERTICAL;
using meitu_native::LINE_FLOOR_HORIZONTAL;
using meitu_native::LINE_DIAGONAL;
using BackgroundGeometry = meitu_native::BackgroundGeometry;
using HumanFrameResult = meitu_native::HumanFrameResult;

class BodySemanticModel {
public:
    BodySemanticModel();
    ~BodySemanticModel();

    bool extractGeometry(
        int width, int height,
        const std::vector<BodyKeypoint>& keypoints,
        const uint8_t* parsingMask,
        HumanFrameResult& outResult
    );

    float computeLegToBodyRatio(const HumanFrameResult& result) const;
    float computeWaistToHipRatio(const HumanFrameResult& result) const;
    float computeShoulderToHipRatio(const HumanFrameResult& result) const;
};

} // namespace body
} // namespace meitu

#endif // MEITU_BODY_SEMANTIC_MODEL_H

#include "face_tracking.h"
#include <cmath>
#include <algorithm>

namespace meitu_native {

constexpr float DEG2RAD = 3.14159265358979323846f / 180.0f;

TrackingResult FaceTrackingEngine::track(
    const float* landmarks106, int width, int height,
    float roll, float pitch, float yaw
) {
    TrackingResult res{};
    if (!landmarks106) return res;

    float leftEyeX = landmarks106[39 * 2];
    float leftEyeY = landmarks106[39 * 2 + 1];
    float rightEyeX = landmarks106[56 * 2];
    float rightEyeY = landmarks106[56 * 2 + 1];

    float eyeDist = std::hypot(rightEyeX - leftEyeX, rightEyeY - leftEyeY);
    float eyeCenterX = (leftEyeX + rightEyeX) * 0.5f;
    float eyeCenterY = (leftEyeY + rightEyeY) * 0.5f;

    float radRoll = roll * DEG2RAD;
    float upX = -std::sin(radRoll);
    float upY = -std::cos(radRoll);

    // 1. Forehead Anchor
    float foreDist = eyeDist * 0.85f;
    res.forehead.x = eyeCenterX + upX * foreDist;
    res.forehead.y = eyeCenterY + upY * foreDist;
    res.forehead.z = 0.1f;
    res.forehead.rotationDeg = roll;
    res.forehead.scale = eyeDist / 100.0f;

    // 2. EyeBridge Anchor
    res.eyeBridge.x = eyeCenterX;
    res.eyeBridge.y = eyeCenterY;
    res.eyeBridge.z = 0.3f;
    res.eyeBridge.rotationDeg = roll;
    res.eyeBridge.scale = eyeDist / 120.0f;

    // 3. Eyes
    res.leftEye.x = landmarks106[38 * 2];
    res.leftEye.y = landmarks106[38 * 2 + 1];
    res.leftEye.z = 0.2f;
    res.leftEye.rotationDeg = roll;
    res.leftEye.scale = eyeDist / 150.0f;

    res.rightEye.x = landmarks106[57 * 2];
    res.rightEye.y = landmarks106[57 * 2 + 1];
    res.rightEye.z = 0.2f;
    res.rightEye.rotationDeg = roll;
    res.rightEye.scale = eyeDist / 150.0f;

    // 4. NoseTip
    res.noseTip.x = landmarks106[46 * 2];
    res.noseTip.y = landmarks106[46 * 2 + 1];
    res.noseTip.z = 0.8f;
    res.noseTip.rotationDeg = roll;
    res.noseTip.scale = eyeDist / 180.0f;

    // 5. Mouth & blendshape
    float upperLipX = landmarks106[86 * 2];
    float upperLipY = landmarks106[86 * 2 + 1];
    float lowerLipX = landmarks106[92 * 2];
    float lowerLipY = landmarks106[92 * 2 + 1];

    res.mouth.x = (upperLipX + lowerLipX) * 0.5f;
    res.mouth.y = (upperLipY + lowerLipY) * 0.5f;
    res.mouth.z = 0.4f;
    res.mouth.rotationDeg = roll;
    res.mouth.scale = eyeDist / 140.0f;

    float lipGap = std::hypot(lowerLipX - upperLipX, lowerLipY - upperLipY);
    res.mouthOpenRatio = std::clamp((lipGap / (eyeDist * 0.28f)) - 0.15f, 0.0f, 1.0f);

    // 6. Chin
    res.chin.x = landmarks106[16 * 2];
    res.chin.y = landmarks106[16 * 2 + 1];
    res.chin.z = 0.0f;
    res.chin.rotationDeg = roll;
    res.chin.scale = eyeDist / 150.0f;

    // 7. Blink detection
    float leftH = std::hypot(landmarks106[41 * 2] - landmarks106[37 * 2], landmarks106[41 * 2 + 1] - landmarks106[37 * 2 + 1]);
    res.leftBlink = (leftH / eyeDist < 0.06f) ? 1.0f : 0.0f;

    float rightH = std::hypot(landmarks106[54 * 2] - landmarks106[58 * 2], landmarks106[54 * 2 + 1] - landmarks106[58 * 2 + 1]);
    res.rightBlink = (rightH / eyeDist < 0.06f) ? 1.0f : 0.0f;

    // Bo loc muot EMA chong rung
    if (hasLastResult) {
        float alpha = 0.35f;
        auto smoothA = [alpha](TrackingAnchor& cur, const TrackingAnchor& prev) {
            cur.x = prev.x + (cur.x - prev.x) * alpha;
            cur.y = prev.y + (cur.y - prev.y) * alpha;
            cur.z = prev.z + (cur.z - prev.z) * alpha;
            cur.rotationDeg = prev.rotationDeg + (cur.rotationDeg - prev.rotationDeg) * alpha;
            cur.scale = prev.scale + (cur.scale - prev.scale) * alpha;
        };
        smoothA(res.forehead, lastResult.forehead);
        smoothA(res.eyeBridge, lastResult.eyeBridge);
        smoothA(res.leftEye, lastResult.leftEye);
        smoothA(res.rightEye, lastResult.rightEye);
        smoothA(res.noseTip, lastResult.noseTip);
        smoothA(res.mouth, lastResult.mouth);
        smoothA(res.chin, lastResult.chin);
    }

    lastResult = res;
    hasLastResult = true;
    return res;
}

TrackingResult FaceTrackingEngine::trackFused(
    const MeituReborn::FusedFaceGeometry& geo, int width, int height,
    float roll, float pitch, float yaw
) {
    TrackingResult res = track(geo.anchors106.data(), width, height, roll, pitch, yaw);

    // Bo sung 3D Anchors tu FusedFaceGeometry
    // 1. Iris Track Anchors
    res.leftIris.x = geo.iris.leftCenter.x;
    res.leftIris.y = geo.iris.leftCenter.y;
    res.leftIris.z = geo.iris.leftCenter.z;
    res.leftIris.rotationDeg = roll;
    res.leftIris.scale = geo.iris.leftRadius;

    res.rightIris.x = geo.iris.rightCenter.x;
    res.rightIris.y = geo.iris.rightCenter.y;
    res.rightIris.z = geo.iris.rightCenter.z;
    res.rightIris.rotationDeg = roll;
    res.rightIris.scale = geo.iris.rightRadius;

    // 2. Canthus Anchors
    res.leftCanthusInner.x = geo.leftInnerCanthus.x;
    res.leftCanthusInner.y = geo.leftInnerCanthus.y;
    res.leftCanthusInner.z = geo.leftInnerCanthus.z;
    res.leftCanthusInner.rotationDeg = roll;

    res.leftCanthusOuter.x = geo.leftOuterCanthus.x;
    res.leftCanthusOuter.y = geo.leftOuterCanthus.y;
    res.leftCanthusOuter.z = geo.leftOuterCanthus.z;
    res.leftCanthusOuter.rotationDeg = roll;

    res.rightCanthusInner.x = geo.rightInnerCanthus.x;
    res.rightCanthusInner.y = geo.rightInnerCanthus.y;
    res.rightCanthusInner.z = geo.rightInnerCanthus.z;
    res.rightCanthusInner.rotationDeg = roll;

    res.rightCanthusOuter.x = geo.rightOuterCanthus.x;
    res.rightCanthusOuter.y = geo.rightOuterCanthus.y;
    res.rightCanthusOuter.z = geo.rightOuterCanthus.z;
    res.rightCanthusOuter.rotationDeg = roll;

    // 3. Nasolabial Smile Anchors (Tam ranh cuoi)
    if (geo.leftSmileLine.size() >= 2) {
        res.leftSmileAnchor.x = (geo.leftSmileLine.front().x + geo.leftSmileLine.back().x) * 0.5f;
        res.leftSmileAnchor.y = (geo.leftSmileLine.front().y + geo.leftSmileLine.back().y) * 0.5f;
        res.leftSmileAnchor.z = (geo.leftSmileLine.front().z + geo.leftSmileLine.back().z) * 0.5f;
        res.leftSmileAnchor.rotationDeg = roll;
    }

    if (geo.rightSmileLine.size() >= 2) {
        res.rightSmileAnchor.x = (geo.rightSmileLine.front().x + geo.rightSmileLine.back().x) * 0.5f;
        res.rightSmileAnchor.y = (geo.rightSmileLine.front().y + geo.rightSmileLine.back().y) * 0.5f;
        res.rightSmileAnchor.z = (geo.rightSmileLine.front().z + geo.rightSmileLine.back().z) * 0.5f;
        res.rightSmileAnchor.rotationDeg = roll;
    }

    return res;
}

} // namespace meitu_native

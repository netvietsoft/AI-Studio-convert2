#ifndef FACE_TRACKING_H
#define FACE_TRACKING_H

#include "landmark_fusion.h"

namespace meitu_native {

struct TrackingAnchor {
    float x;
    float y;
    float z;
    float rotationDeg;
    float scale;
};

struct TrackingResult {
    TrackingAnchor forehead;
    TrackingAnchor eyeBridge;
    TrackingAnchor leftEye;
    TrackingAnchor rightEye;
    TrackingAnchor noseTip;
    TrackingAnchor mouth;
    TrackingAnchor chin;
    // Giai doan 2: Bo sung Anchors Iris, Canthus va Smile Line tu FusedFaceGeometry
    TrackingAnchor leftIris;
    TrackingAnchor rightIris;
    TrackingAnchor leftCanthusInner;
    TrackingAnchor leftCanthusOuter;
    TrackingAnchor rightCanthusInner;
    TrackingAnchor rightCanthusOuter;
    TrackingAnchor leftSmileAnchor;
    TrackingAnchor rightSmileAnchor;
    float mouthOpenRatio;
    float leftBlink;
    float rightBlink;
};

class FaceTrackingEngine {
public:
    FaceTrackingEngine() = default;
    TrackingResult track(const float* landmarks106, int width, int height, float roll, float pitch, float yaw);
    TrackingResult trackFused(const MeituReborn::FusedFaceGeometry& geo, int width, int height, float roll, float pitch, float yaw);

private:
    TrackingResult lastResult;
    bool hasLastResult = false;
};

} // namespace meitu_native

#endif // FACE_TRACKING_H

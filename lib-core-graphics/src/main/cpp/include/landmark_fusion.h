#ifndef MEITU_LANDMARK_FUSION_H
#define MEITU_LANDMARK_FUSION_H

#include "dense_facemesh_478.h"
#include <vector>

namespace MeituReborn {

struct FusedFaceGeometry {
    // 478 diem Dense Mesh (x, y, z)
    std::vector<Point3D> dense478;
    // 106 diem Semantic Anchors (x, y)
    std::vector<float> anchors106;
    // Thong tin con nguoi mat
    IrisTrackResult iris;
    // Toa do ranh cuoi (Nasolabial folds)
    std::vector<Point3D> leftSmileLine;
    std::vector<Point3D> rightSmileLine;
    // Khoe mat trong & ngoai
    Point3D leftOuterCanthus, leftInnerCanthus;
    Point3D rightInnerCanthus, rightOuterCanthus;
    // Bounding Box
    float boxX1, boxY1, boxX2, boxY2;
};

class LandmarkFusionEngine {
public:
    static LandmarkFusionEngine& getInstance();

    // Xoa sach du lieu geometry khi nap anh moi
    void reset();

    // Lay ket qua fused gan nhat
    const FusedFaceGeometry& getLastFusedGeometry() const { return mLastFused; }

    bool hasValidGeometry() const {
        return (!mLastFused.dense478.empty() && mLastFused.dense478.size() >= 468) ||
               (!mLastFused.anchors106.empty() && mLastFused.anchors106.size() >= 212);
    }

    // Hop nhat 106 Semantic Anchors voi 478 Dense Landmarks
    FusedFaceGeometry fuse(
        const float* stabilized106,
        const float* stabilized478,
        float faceX1, float faceY1, float faceX2, float faceY2
    );

private:
    FusedFaceGeometry mLastFused;
};

} // namespace MeituReborn

#endif // MEITU_LANDMARK_FUSION_H

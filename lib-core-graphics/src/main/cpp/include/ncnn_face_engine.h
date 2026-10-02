#ifndef MEITU_NCNN_FACE_ENGINE_H
#define MEITU_NCNN_FACE_ENGINE_H

#include <android/asset_manager.h>
#include <vector>
#include <cstdint>
#include <memory>
#include "dense_facemesh_478.h"
#include "adaptive_temporal_stabilizer.h"
#include "landmark_fusion.h"

namespace MeituReborn {

struct NcnnFaceBox {
    float x1;
    float y1;
    float x2;
    float y2;
    float score;
    float kps[10]; // 5 facial keypoints: left eye, right eye, nose, left mouth, right mouth
};

class NcnnFaceEngine {
public:
    static NcnnFaceEngine& getInstance();

    // Khoi tao va nap trong so mang SCRFD, InsightFace 106, va Dense FaceMesh 478
    bool init(AAssetManager* mgr);
    bool isLoaded() const;

    // Nhan dien khuon mat (SCRFD Face Detector)
    bool detectFace(const uint8_t* rgba, int width, int height, NcnnFaceBox& bestFace);

    // Trich xuat 106 diem Landmark (InsightFace 2d106det)
    bool detect106Landmarks(const uint8_t* rgba, int width, int height, float* outLandmarks, float* outFaceBox = nullptr);

    // Trich xuat 478 diem Dense Face Mesh + Iris Tracking (MediaPipe NCNN)
    // outMesh478: mang float chua toi thieu 478 * 3 (1434 floats: x, y, z)
    bool detectDenseMesh478(
        const uint8_t* rgba, int width, int height,
        float* outMesh478, IrisTrackResult* outIris = nullptr,
        float* outFaceBox = nullptr
    );

    // Hop nhat toan dien: SCRFD + 106 Anchors + 478 Dense Mesh + Temporal Stabilizer
    bool detectFusedGeometry(
        const uint8_t* rgba, int width, int height,
        float* out106, float* outMesh478, float* outFaceBox
    );

    void resetStabilizer();
    void release();

private:
    NcnnFaceEngine();
    ~NcnnFaceEngine();

    NcnnFaceEngine(const NcnnFaceEngine&) = delete;
    NcnnFaceEngine& operator=(const NcnnFaceEngine&) = delete;

    class Impl;
    std::unique_ptr<Impl> pImpl;
};

} // namespace MeituReborn

#endif // MEITU_NCNN_FACE_ENGINE_H

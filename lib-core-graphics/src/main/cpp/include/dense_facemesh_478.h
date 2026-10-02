#ifndef MEITU_DENSE_FACEMESH_478_H
#define MEITU_DENSE_FACEMESH_478_H

#include <android/asset_manager.h>
#include <vector>
#include <cstdint>
#include <memory>

namespace MeituReborn {

struct Point3D {
    float x;
    float y;
    float z;
};

struct IrisTrackResult {
    Point3D leftCenter;
    float leftRadius;
    Point3D rightCenter;
    float rightRadius;
};

class DenseFaceMesh478 {
public:
    static DenseFaceMesh478& getInstance();

    bool init(AAssetManager* mgr);
    bool isLoaded() const;

    // Suy luan 478 diem (468 diem luoi mat + 10 diem Iris)
    // outPoints478: mang chua toi thieu 478 * 3 (1434 floats: x, y, z)
    bool detectMesh478(
        const uint8_t* rgba, int width, int height,
        float faceX1, float faceY1, float faceX2, float faceY2,
        float* outPoints478, IrisTrackResult* outIris = nullptr
    );

    void release();

private:
    DenseFaceMesh478();
    ~DenseFaceMesh478();

    class Impl;
    std::unique_ptr<Impl> pImpl;
};

} // namespace MeituReborn

#endif // MEITU_DENSE_FACEMESH_478_H

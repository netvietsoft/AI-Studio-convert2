#ifndef FACE_MESH_3D_H
#define FACE_MESH_3D_H

#include <vector>
#include <cmath>

namespace meitu_native {

struct Point3D {
    float x;
    float y;
    float z;
};

struct Normal3D {
    float nx;
    float ny;
    float nz;
};

struct HeadPose3D {
    float pitch;
    float yaw;
    float roll;
    float tx;
    float ty;
    float tz;
    float matrix[16];
};

struct DenseFaceMesh3D {
    std::vector<Point3D> vertices;
    std::vector<Normal3D> normals;
    std::vector<float> texCoords;
    std::vector<uint16_t> indices;
    HeadPose3D pose;
};

class FaceMesh3DReconstructor {
public:
    FaceMesh3DReconstructor() = default;
    DenseFaceMesh3D reconstruct(const float* landmarks106, int width, int height, float pitch, float yaw, float roll);

private:
    void calculatePoseMatrix(float pitch, float yaw, float roll, float dist, float* outMatrix);
};

} // namespace meitu_native

#endif // FACE_MESH_3D_H

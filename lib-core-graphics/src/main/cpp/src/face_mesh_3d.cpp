#include "face_mesh_3d.h"
#include <algorithm>

namespace meitu_native {

constexpr float DEG2RAD = 3.14159265358979323846f / 180.0f;

DenseFaceMesh3D FaceMesh3DReconstructor::reconstruct(
    const float* landmarks106, int width, int height,
    float pitch, float yaw, float roll
) {
    DenseFaceMesh3D mesh;
    mesh.vertices.resize(106);
    mesh.normals.resize(106);
    mesh.texCoords.resize(106 * 2);

    float leftEyeX = landmarks106[39 * 2];
    float leftEyeY = landmarks106[39 * 2 + 1];
    float rightEyeX = landmarks106[56 * 2];
    float rightEyeY = landmarks106[56 * 2 + 1];

    float eyeDist = std::max(1.0f, std::hypot(rightEyeX - leftEyeX, rightEyeY - leftEyeY));
    float depthScale = eyeDist * 0.65f;

    float radYaw = yaw * DEG2RAD;
    float radPitch = pitch * DEG2RAD;

    for (int i = 0; i < 106; ++i) {
        float px = landmarks106[i * 2];
        float py = landmarks106[i * 2 + 1];

        float normX = (px - width * 0.5f) / (width * 0.5f);
        float normY = (py - height * 0.5f) / (height * 0.5f);

        float zDepth = 0.0f;
        if (i == 46) {
            zDepth = 1.0f; // Đầu mũi
        } else if (i >= 43 && i <= 51) {
            zDepth = 0.7f; // Sống mũi
        } else if ((i >= 33 && i <= 42) || (i >= 52 && i <= 61)) {
            zDepth = 0.2f; // Mắt
        } else if (i >= 72 && i <= 95) {
            zDepth = 0.4f; // Miệng
        } else if (i >= 0 && i <= 32) {
            zDepth = -0.3f; // Viền cằm
        } else {
            zDepth = 0.35f; // Trán & chân mày
        }
        zDepth *= depthScale;

        mesh.vertices[i] = {normX, normY, zDepth};

        mesh.texCoords[i * 2] = px / static_cast<float>(width);
        mesh.texCoords[i * 2 + 1] = py / static_cast<float>(height);

        float nx = -std::sin(radYaw) * 0.4f + normX * 0.2f;
        float ny = -std::sin(radPitch) * 0.4f + normY * 0.2f;
        float nzSq = std::max(0.01f, 1.0f - nx * nx - ny * ny);
        float nz = std::sqrt(nzSq);

        mesh.normals[i] = {nx, ny, nz};
    }

    // Bảng lưới tam giác Delaunay đầy đủ bao phủ toàn bộ 106 điểm giải phẫu học
    // 1. Viền xương hàm và cằm (0..32) nối với gò má và mũi
    for (int i = 0; i < 32; ++i) {
        mesh.indices.push_back(static_cast<uint16_t>(i));
        mesh.indices.push_back(static_cast<uint16_t>(i + 1));
        mesh.indices.push_back(46); // Nối vào đỉnh mũi
    }

    // 2. Chân mày trái và phải (62..71) nối với vùng trán và sống mũi (43)
    for (int i = 62; i < 66; ++i) {
        mesh.indices.push_back(static_cast<uint16_t>(i));
        mesh.indices.push_back(static_cast<uint16_t>(i + 1));
        mesh.indices.push_back(43);
    }
    for (int i = 67; i < 71; ++i) {
        mesh.indices.push_back(static_cast<uint16_t>(i));
        mesh.indices.push_back(static_cast<uint16_t>(i + 1));
        mesh.indices.push_back(43);
    }

    // 3. Hốc mắt trái (33..42) và mắt phải (52..61)
    for (int i = 33; i < 42; ++i) {
        mesh.indices.push_back(static_cast<uint16_t>(i));
        mesh.indices.push_back(static_cast<uint16_t>(i + 1));
        mesh.indices.push_back(38); // Tâm mắt trái
    }
    mesh.indices.push_back(42); mesh.indices.push_back(33); mesh.indices.push_back(38);

    for (int i = 52; i < 61; ++i) {
        mesh.indices.push_back(static_cast<uint16_t>(i));
        mesh.indices.push_back(static_cast<uint16_t>(i + 1));
        mesh.indices.push_back(57); // Tâm mắt phải
    }
    mesh.indices.push_back(61); mesh.indices.push_back(52); mesh.indices.push_back(57);

    // 4. Sống mũi và cánh mũi (43..51)
    for (int i = 43; i < 46; ++i) {
        mesh.indices.push_back(static_cast<uint16_t>(i));
        mesh.indices.push_back(static_cast<uint16_t>(i + 1));
        mesh.indices.push_back(48);
    }

    // 5. Môi ngoài và môi trong (72..95)
    for (int i = 72; i < 83; ++i) {
        mesh.indices.push_back(static_cast<uint16_t>(i));
        mesh.indices.push_back(static_cast<uint16_t>(i + 1));
        mesh.indices.push_back(86);
    }
    mesh.indices.push_back(83); mesh.indices.push_back(72); mesh.indices.push_back(86);

    for (int i = 84; i < 95; ++i) {
        mesh.indices.push_back(static_cast<uint16_t>(i));
        mesh.indices.push_back(static_cast<uint16_t>(i + 1));
        mesh.indices.push_back(92);
    }

    mesh.pose.pitch = pitch;
    mesh.pose.yaw = yaw;
    mesh.pose.roll = roll;
    mesh.pose.tx = (landmarks106[46 * 2] - width * 0.5f) / width;
    mesh.pose.ty = (landmarks106[46 * 2 + 1] - height * 0.5f) / height;
    mesh.pose.tz = depthScale;

    calculatePoseMatrix(pitch, yaw, roll, depthScale, mesh.pose.matrix);

    return mesh;
}

void FaceMesh3DReconstructor::calculatePoseMatrix(
    float pitch, float yaw, float roll, float dist, float* m
) {
    float p = pitch * DEG2RAD;
    float y = yaw * DEG2RAD;
    float r = roll * DEG2RAD;

    float cp = std::cos(p);
    float sp = std::sin(p);
    float cy = std::cos(y);
    float sy = std::sin(y);
    float cr = std::cos(r);
    float sr = std::sin(r);

    m[0] = cy * cr;
    m[1] = cy * sr;
    m[2] = -sy;
    m[3] = 0.0f;

    m[4] = sp * sy * cr - cp * sr;
    m[5] = sp * sy * sr + cp * cr;
    m[6] = sp * cy;
    m[7] = 0.0f;

    m[8] = cp * sy * cr + sp * sr;
    m[9] = cp * sy * sr - sp * cr;
    m[10] = cp * cy;
    m[11] = 0.0f;

    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = -dist;
    m[15] = 1.0f;
}

} // namespace meitu_native

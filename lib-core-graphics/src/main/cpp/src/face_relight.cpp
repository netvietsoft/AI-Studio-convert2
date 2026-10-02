#include "face_relight.h"
#include <cmath>
#include <algorithm>
#include <omp.h>

namespace meitu_native {

constexpr float DEG2RAD = 3.14159265358979323846f / 180.0f;

// Chuẩn hóa trích xuất kênh màu trên chip ARM Little-Endian (ANDROID_BITMAP_FORMAT_RGBA_8888)
// Byte 0: Red (bits 0..7), Byte 1: Green (bits 8..15), Byte 2: Blue (bits 16..23), Byte 3: Alpha (bits 24..31)
#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define PACK_RGBA(r, g, b, a) (((static_cast<uint32_t>(a) & 0xFF) << 24) |                                ((static_cast<uint32_t>(b) & 0xFF) << 16) |                                ((static_cast<uint32_t>(g) & 0xFF) << 8)  |                                ((static_cast<uint32_t>(r) & 0xFF) << 0))

bool FaceRelightEngine::applyRelight(
    uint32_t* pixels, int width, int height,
    const float* landmarks106, const uint8_t* skinMask,
    int preset, float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || !landmarks106) return false;

    float azimuthDeg = -45.0f;
    float elevationDeg = 35.0f;
    float ambient = 0.40f;
    float diffuse = 0.75f;
    float specular = 0.35f;
    float shininess = 16.0f;

    switch (preset) {
        case PRESET_CONTOUR:
            azimuthDeg = 60.0f; elevationDeg = 15.0f;
            ambient = 0.35f; diffuse = 0.80f; specular = 0.40f; shininess = 24.0f;
            break;
        case PRESET_STAGE:
            azimuthDeg = 0.0f; elevationDeg = 50.0f;
            ambient = 0.20f; diffuse = 0.95f; specular = 0.50f; shininess = 32.0f;
            break;
        case PRESET_RING_LIGHT:
            azimuthDeg = 0.0f; elevationDeg = 0.0f;
            ambient = 0.65f; diffuse = 0.45f; specular = 0.25f; shininess = 8.0f;
            break;
        case PRESET_REMBRANDT:
        default:
            azimuthDeg = -45.0f; elevationDeg = 35.0f;
            ambient = 0.40f; diffuse = 0.75f; specular = 0.35f; shininess = 16.0f;
            break;
    }

    float azRad = azimuthDeg * DEG2RAD;
    float elRad = elevationDeg * DEG2RAD;
    float lx = std::cos(elRad) * std::sin(azRad);
    float ly = -std::sin(elRad);
    float lz = std::cos(elRad) * std::cos(azRad);

    float noseX = landmarks106[46 * 2];
    float noseY = landmarks106[46 * 2 + 1];

    float minX = landmarks106[0], maxX = landmarks106[0];
    float minY = landmarks106[1], maxY = landmarks106[1];
    for (int i = 1; i < 106; ++i) {
        float x = landmarks106[i * 2];
        float y = landmarks106[i * 2 + 1];
        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }

    float faceRadius = std::max(maxX - minX, maxY - minY) * 0.65f;
    float faceRadiusSq = faceRadius * faceRadius;

    int boundMinX = std::max(0, static_cast<int>(minX - 20));
    int boundMaxX = std::min(width - 1, static_cast<int>(maxX + 20));
    int boundMinY = std::max(0, static_cast<int>(minY - 20));
    int boundMaxY = std::min(height - 1, static_cast<int>(maxY + 20));

    // Song song hóa đa luồng trên CPU ARM bằng OpenMP
    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = boundMinY; y <= boundMaxY; ++y) {
        int rowOffset = y * width;
        float dy = y - noseY;
        for (int x = boundMinX; x <= boundMaxX; ++x) {
            float dx = x - noseX;
            float distSq = dx * dx + dy * dy;
            if (distSq > faceRadiusSq) continue;

            int idx = rowOffset + x;

            // Kiểm tra mặt nạ phân đoạn da (Skin Mask) để bảo vệ tóc và cổ áo
            float skinWeight = 1.0f;
            if (skinMask != nullptr) {
                uint8_t maskVal = skinMask[idx];
                if (maskVal < 10) continue; // Bỏ qua nếu là tóc, áo hoặc nền
                skinWeight = maskVal / 255.0f;
            }

            float edgeRatio = 1.0f - distSq / faceRadiusSq;
            float edgeWeight = edgeRatio * edgeRatio * intensity * skinWeight;

            float nx = dx / faceRadius;
            float ny = dy / faceRadius;
            float nzSq = std::max(0.04f, 1.0f - nx * nx - ny * ny);
            float nz = std::sqrt(nzSq);

            // 1. Lambertian diffuse
            float nDotL = std::max(0.0f, nx * lx + ny * ly + nz * lz);

            // 2. Blinn-Phong specular
            float hx = lx;
            float hy = ly;
            float hz = lz + 1.0f;
            float hLen = std::max(0.001f, std::sqrt(hx * hx + hy * hy + hz * hz));
            float nDotH = std::max(0.0f, (nx * hx + ny * hy + nz * hz) / hLen);
            float specularVal = std::pow(nDotH, shininess) * specular;

            float lightFactor = ambient + (diffuse * nDotL) + specularVal;

            uint32_t color = pixels[idx];
            uint32_t r = RGBA_R(color);
            uint32_t g = RGBA_G(color);
            uint32_t b = RGBA_B(color);
            uint32_t a = RGBA_A(color);

            float newR = r * (1.0f - edgeWeight) + r * lightFactor * edgeWeight;
            float newG = g * (1.0f - edgeWeight) + g * lightFactor * edgeWeight;
            float newB = b * (1.0f - edgeWeight) + b * lightFactor * edgeWeight;

            uint32_t outR = static_cast<uint32_t>(std::clamp(newR, 0.0f, 255.0f));
            uint32_t outG = static_cast<uint32_t>(std::clamp(newG, 0.0f, 255.0f));
            uint32_t outB = static_cast<uint32_t>(std::clamp(newB, 0.0f, 255.0f));

            pixels[idx] = PACK_RGBA(outR, outG, outB, a);
        }
    }

    return true;
}

} // namespace meitu_native

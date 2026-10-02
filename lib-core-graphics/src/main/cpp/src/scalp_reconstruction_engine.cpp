#include "scalp_reconstruction_engine.h"
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

namespace meitu_native {

ScalpReconstructionEngine::ScalpReconstructionEngine() = default;
ScalpReconstructionEngine::~ScalpReconstructionEngine() = default;

// Simple deterministic hash for micro-pore noise synthesis
static inline float hashCoord(int x, int y) {
    uint32_t n = static_cast<uint32_t>(x * 374761393 + y * 668265263);
    n = (n ^ (n >> 13)) * 1274126177;
    return static_cast<float>(n & 0xFFFF) / 65535.0f - 0.5f;
}

bool ScalpReconstructionEngine::reconstructScalp(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const HeadFrameResult& headResult,
    const uint8_t* hairMask,
    float blendStrength
) {
    if (!rgbaImage || width <= 0 || height <= 0 || stride < width * 4) {
        return false;
    }
    if (blendStrength <= 0.001f) {
        return true;
    }

    // 1. Lấy mẫu màu da và ánh sáng từ trán
    float foreheadX = headResult.foreheadTemple.center.x;
    float foreheadY = headResult.foreheadTemple.center.y;
    if (foreheadX <= 0.0f || foreheadY <= 0.0f) {
        foreheadX = headResult.headGeometry.headBox.centerX();
        foreheadY = headResult.headGeometry.headBox.y1 + headResult.headGeometry.headHeight * 0.2f;
    }

    // Sample 5 điểm trên trán để lấy giá trị da trung bình
    float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f;
    int samples = 0;
    for (int dy = -10; dy <= 10; dy += 5) {
        int sy = clampF(foreheadY + dy, 0, height - 1);
        for (int dx = -10; dx <= 10; dx += 5) {
            int sx = clampF(foreheadX + dx, 0, width - 1);
            const uint8_t* p = rgbaImage + sy * stride + sx * 4;
            sumR += p[0];
            sumG += p[1];
            sumB += p[2];
            samples++;
        }
    }
    float baseR = sumR / std::max(1, samples);
    float baseG = sumG / std::max(1, samples);
    float baseB = sumB / std::max(1, samples);

    // 2. Vùng hộp sọ / scalp box
    float skullCenterX = headResult.headGeometry.headBox.centerX();
    float skullTopY = headResult.headGeometry.headBox.y1;
    float skullRadiusX = headResult.headGeometry.headWidth * 0.48f;
    float skullRadiusY = headResult.headGeometry.headHeight * 0.45f;

    if (skullRadiusX <= 10.0f || skullRadiusY <= 10.0f) {
        skullCenterX = foreheadX;
        skullTopY = std::max(0.0f, foreheadY - 100.0f);
        skullRadiusX = headResult.headGeometry.headWidth * 0.5f;
        skullRadiusY = 100.0f;
    }

    int rx1 = std::max(0, static_cast<int>(skullCenterX - skullRadiusX));
    int rx2 = std::min(width - 1, static_cast<int>(skullCenterX + skullRadiusX));
    int ry1 = std::max(0, static_cast<int>(skullTopY));
    int ry2 = std::min(height - 1, static_cast<int>(foreheadY + 20.0f));

    for (int y = ry1; y <= ry2; ++y) {
        float ny = (static_cast<float>(y) - skullTopY) / (skullRadiusY + 1e-4f); // 0 ở đỉnh đầu, 1 ở trán
        // Vòm sọ cong: Shading cosine theo góc nghiêng mặt phẳng sọ 3D
        float angleZ = std::acos(clampF(ny, 0.0f, 1.0f));
        float diffuseShading = std::sin(angleZ); // Tự nhiên giảm nhẹ khi về phía đỉnh vòm sọ

        for (int x = rx1; x <= rx2; ++x) {
            float nx = (static_cast<float>(x) - skullCenterX) / (skullRadiusX + 1e-4f);
            float distSq = nx * nx + (ny - 0.5f) * (ny - 0.5f);
            if (distSq > 1.2f) continue; // Ngoài vòm sọ

            // Độ bao phủ tóc: nếu có hairMask truyền vào thì lấy theo mask, ngược lại lấy vùng trên trán
            float hairWeight = 0.0f;
            if (hairMask) {
                hairWeight = hairMask[y * width + x] / 255.0f;
            } else {
                // Fallback: vùng trên trán thuộc vòm đầu
                if (static_cast<float>(y) < foreheadY) {
                    hairWeight = 1.0f - std::max(0.0f, static_cast<float>(y) - skullTopY) / (foreheadY - skullTopY + 1e-4f) * 0.3f;
                }
            }

            if (hairWeight <= 0.01f) continue;

            // Micro-pore noise: tạo kết cấu lỗ chân lông vi mô tự nhiên để tránh bết phẳng
            float noise = hashCoord(x, y) * 8.0f;

            float scalpR = baseR * (0.88f + 0.12f * diffuseShading) + noise;
            float scalpG = baseG * (0.88f + 0.12f * diffuseShading) + noise;
            float scalpB = baseB * (0.88f + 0.12f * diffuseShading) + noise;

            uint8_t* dst = rgbaImage + y * stride + x * 4;
            float alpha = hairWeight * blendStrength;

            dst[0] = clampU8(static_cast<int>(dst[0] * (1.0f - alpha) + scalpR * alpha + 0.5f));
            dst[1] = clampU8(static_cast<int>(dst[1] * (1.0f - alpha) + scalpG * alpha + 0.5f));
            dst[2] = clampU8(static_cast<int>(dst[2] * (1.0f - alpha) + scalpB * alpha + 0.5f));
        }
    }
    return true;
}

} // namespace meitu_native

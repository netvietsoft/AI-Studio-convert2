#include "accessory_occlusion_engine.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <omp.h>
#include <android/log.h>

#define LOG_TAG AccessoryEngine
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define MAKE_RGBA(r, g, b, a) (((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(g) << 8) | ((uint32_t)(r)))

namespace meitu_native {

bool AccessoryOcclusionEngine::analyzeAccessories(
    const uint32_t* pixels,
    int width,
    int height,
    HeadFrameResult& headModel
) {
    if (!pixels || width <= 0 || height <= 0 || !headModel.isFaceDetected) {
        return false;
    }

    const auto& lEye = headModel.eye.left;
    const auto& rEye = headModel.eye.right;
    const auto& nose = headModel.nose;

    // Ước lượng hộp bao kính mắt (Eyeglasses Bounding Box)
    float minX = std::min(lEye.outerCanthus.x, rEye.outerCanthus.x) - lEye.width * 0.35f;
    float maxX = std::max(lEye.outerCanthus.x, rEye.outerCanthus.x) + rEye.width * 0.35f;
    float minY = std::min(lEye.center.y, rEye.center.y) - lEye.height * 1.2f;
    float maxY = std::max(lEye.center.y, rEye.center.y) + lEye.height * 1.1f;

    BoundingBox2D gBox;
    gBox.x1 = std::clamp(minX, 0.0f, static_cast<float>(width - 1));
    gBox.y1 = std::clamp(minY, 0.0f, static_cast<float>(height - 1));
    gBox.x2 = std::clamp(maxX, 0.0f, static_cast<float>(width - 1));
    gBox.y2 = std::clamp(maxY, 0.0f, static_cast<float>(height - 1));

    headModel.accessory.hasGlasses = true;
    headModel.accessory.glassesBox = gBox;

    // Khuyên tai trái & phải dựa trên vị trí dái tai (Ear Lobes)
    if (headModel.ear.left.isVisible) {
        headModel.accessory.hasEarrings = true;
        BoundingBox2D eBox;
        eBox.x1 = headModel.ear.left.lobeCenter.x - 12.0f;
        eBox.y1 = headModel.ear.left.lobeCenter.y - 6.0f;
        eBox.x2 = headModel.ear.left.lobeCenter.x + 12.0f;
        eBox.y2 = headModel.ear.left.lobeCenter.y + 24.0f;
        headModel.accessory.leftEarringBox = eBox;
    }

    return true;
}

bool AccessoryOcclusionEngine::protectRigidAccessories(
    uint32_t* warpedPixels,
    const uint32_t* originalPixels,
    int width,
    int height,
    const HeadFrameResult& headModel,
    float rigidStrength
) {
    if (!warpedPixels || !originalPixels || width <= 0 || height <= 0 || rigidStrength < 0.01f) {
        return false;
    }
    if (!headModel.isFaceDetected || !headModel.accessory.hasGlasses) {
        return false;
    }

    float strength = std::clamp(rigidStrength, 0.0f, 1.0f);
    const auto& gBox = headModel.accessory.glassesBox;

    int minX = static_cast<int>(std::floor(gBox.x1));
    int maxX = static_cast<int>(std::ceil(gBox.x2));
    int minY = static_cast<int>(std::floor(gBox.y1));
    int maxY = static_cast<int>(std::ceil(gBox.y2));

    minX = std::clamp(minX, 0, width - 1);
    maxX = std::clamp(maxX, 0, width - 1);
    minY = std::clamp(minY, 0, height - 1);
    maxY = std::clamp(maxY, 0, height - 1);

    Point2DF lCenter = headModel.eye.left.center;
    Point2DF rCenter = headModel.eye.right.center;
    float lRad = headModel.eye.left.width * 0.55f;
    float rRad = headModel.eye.right.width * 0.55f;
    Point2DF bridgePt = headModel.nose.root;

    // Bảo vệ gọng kính và tròng kính khỏi bị uốn cong (Anti-warp Rigid Protection)
    #pragma omp parallel for schedule(dynamic, 32)
    for (int y = minY; y <= maxY; ++y) {
        float fy = static_cast<float>(y);
        for (int x = minX; x <= maxX; ++x) {
            float fx = static_cast<float>(x);

            // Kiểm tra xem pixel có thuộc vùng tròng kính / vành gọng kính không
            float dl = std::hypot((fx - lCenter.x) / lRad, (fy - lCenter.y) / (lRad * 0.85f));
            float dr = std::hypot((fx - rCenter.x) / rRad, (fy - rCenter.y) / (rRad * 0.85f));
            float db = std::hypot(fx - bridgePt.x, (fy - bridgePt.y) * 1.5f);

            float glassWeight = 0.0f;
            // Vùng tròng kính trái & phải (Lens regions)
            if (dl <= 1.15f) {
                glassWeight = std::max(glassWeight, (1.15f - dl) / 0.15f);
            }
            if (dr <= 1.15f) {
                glassWeight = std::max(glassWeight, (1.15f - dr) / 0.15f);
            }
            // Vùng cầu nối giữa sống mũi (Bridge)
            if (db <= 18.0f) {
                glassWeight = std::max(glassWeight, (18.0f - db) / 18.0f);
            }

            glassWeight = std::clamp(glassWeight, 0.0f, 1.0f);

            if (glassWeight > 0.01f) {
                float alpha = glassWeight * strength;
                int idx = y * width + x;

                uint32_t wPix = warpedPixels[idx];
                uint32_t oPix = originalPixels[idx];

                uint8_t wR = RGBA_R(wPix), wG = RGBA_G(wPix), wB = RGBA_B(wPix), wA = RGBA_A(wPix);
                uint8_t oR = RGBA_R(oPix), oG = RGBA_G(oPix), oB = RGBA_B(oPix);

                // Khôi phục hình học gốc cứng rắn của gọng kính, loại bỏ hoàn toàn biến dạng méo gọng
                uint8_t r = static_cast<uint8_t>(wR * (1.0f - alpha) + oR * alpha);
                uint8_t g = static_cast<uint8_t>(wG * (1.0f - alpha) + oG * alpha);
                uint8_t b = static_cast<uint8_t>(wB * (1.0f - alpha) + oB * alpha);

                warpedPixels[idx] = MAKE_RGBA(r, g, b, wA);
            }
        }
    }

    return true;
}

} // namespace meitu_native
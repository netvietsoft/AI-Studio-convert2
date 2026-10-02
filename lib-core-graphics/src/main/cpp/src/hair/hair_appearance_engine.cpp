#include "hair/hair_appearance_engine.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <omp.h>

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)

namespace meitu_native::hce {

HairAppearanceEngine& HairAppearanceEngine::getInstance() {
    static HairAppearanceEngine instance;
    return instance;
}

bool HairAppearanceEngine::extractAppearance(
    const uint32_t* srcPixels,
    int width,
    int height,
    const P0HairMatteAdapter& p0Matte,
    HairAppearanceContext& outAppearance
) {
    if (!srcPixels || width <= 0 || height <= 0 || !p0Matte.alphaData) {
        outAppearance.isValid = false;
        return false;
    }

    const int total = width * height;
    outAppearance.width = width;
    outAppearance.height = height;
    outAppearance.baseLuminance.assign(total, 0.0f);
    outAppearance.shadowFactor.assign(total, 1.0f);
    outAppearance.highlightMask.assign(total, 0.0f);
    outAppearance.localContrast.assign(total, 0.0f);
    outAppearance.rootDepthContext.assign(total, 0.0f);

    std::vector<float> lum(total, 0.0f);
    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < total; ++i) {
        uint32_t c = srcPixels[i];
        lum[i] = 0.299f * RGBA_R(c) + 0.587f * RGBA_G(c) + 0.114f * RGBA_B(c);
        outAppearance.baseLuminance[i] = lum[i];
    }

    int roiMinX = (p0Matte.roiMaxX > p0Matte.roiMinX) ? std::max(2, p0Matte.roiMinX) : 2;
    int roiMaxX = (p0Matte.roiMaxX > p0Matte.roiMinX) ? std::min(width - 3, p0Matte.roiMaxX) : width - 3;
    int roiMinY = (p0Matte.roiMaxY > p0Matte.roiMinY) ? std::max(2, p0Matte.roiMinY) : 2;
    int roiMaxY = (p0Matte.roiMaxY > p0Matte.roiMinY) ? std::min(height - 3, p0Matte.roiMaxY) : height - 3;

    const float* alpha = p0Matte.alphaData;

    // 1. Tính toán ánh sáng môi trường vĩ mô (Macro Ambient Base) bằng bộ lọc rộng (bán kính 12)
    std::vector<float> macroBase(total, 0.0f);
    std::vector<float> tempH(total, 0.0f);
    const int r = std::max(6, static_cast<int>(width * 0.015f));

    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            float sum = 0.0f; int count = 0;
            int xStart = std::max(0, x - r);
            int xEnd = std::min(width - 1, x + r);
            for (int kx = xStart; kx <= xEnd; ++kx) {
                sum += lum[yOff + kx]; count++;
            }
            tempH[yOff + x] = sum / count;
        }
    }

    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            float sum = 0.0f; int count = 0;
            int yStart = std::max(0, y - r);
            int yEnd = std::min(height - 1, y + r);
            for (int ky = yStart; ky <= yEnd; ++ky) {
                sum += tempH[ky * width + x]; count++;
            }
            macroBase[yOff + x] = sum / count;
        }
    }

    // 2. Ước lượng khe bóng đổ lọn tóc (Deep Shadow Crevices)
    estimateShadowCrevices(
        lum.data(), macroBase.data(),
        width, height,
        roiMinX, roiMinY, roiMaxX, roiMaxY,
        alpha,
        outAppearance.shadowFactor
    );

    // 3. Phát hiện và bảo tồn vệt sáng tự nhiên (Highlight Mask)
    estimateHighlightMask(
        lum.data(), macroBase.data(),
        width, height,
        roiMinX, roiMinY, roiMaxX, roiMaxY,
        alpha,
        outAppearance.highlightMask
    );

    // 4. Ước lượng độ tương phản cục bộ và chiều sâu chân tóc (Local Contrast & Root Depth)
    float hairTopY = static_cast<float>(roiMinY);
    float hairBottomY = static_cast<float>(roiMaxY);
    float hairHeightSpan = std::max(10.0f, hairBottomY - hairTopY);

    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        float depthFraction = std::clamp((y - hairTopY) / hairHeightSpan, 0.0f, 1.0f);
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            int idx = yOff + x;
            if (alpha[idx] < 0.05f) continue;

            float l = lum[idx];
            float b = macroBase[idx];
            float contrast = std::abs(l - b) / (b + 1e-4f);
            outAppearance.localContrast[idx] = std::clamp(contrast, 0.0f, 1.0f);
            outAppearance.rootDepthContext[idx] = depthFraction;
        }
    }

    outAppearance.isValid = true;
    return true;
}

void HairAppearanceEngine::estimateShadowCrevices(
    const float* lum,
    const float* baseL,
    int width,
    int height,
    int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
    const float* alpha,
    std::vector<float>& outShadowFactor
) {
    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            int idx = yOff + x;
            if (alpha[idx] < 0.05f) {
                outShadowFactor[idx] = 1.0f;
                continue;
            }

            float origLum = lum[idx];
            float localMacro = baseL[idx];

            // Tỷ lệ độ sáng so với nền vĩ mô
            // Khe bóng tối sâu (crevices) sẽ có origLum << localMacro
            float factor = std::clamp((origLum - 2.0f) / std::max(1.0f, localMacro * 0.92f), 0.0f, 1.0f);
            outShadowFactor[idx] = factor;
        }
    }
}

void HairAppearanceEngine::estimateHighlightMask(
    const float* lum,
    const float* baseL,
    int width,
    int height,
    int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
    const float* alpha,
    std::vector<float>& outHighlightMask
) {
    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            int idx = yOff + x;
            if (alpha[idx] < 0.05f) {
                outHighlightMask[idx] = 0.0f;
                continue;
            }

            float origLum = lum[idx];
            float localMacro = baseL[idx];

            // Điểm sáng tự nhiên: độ sáng vượt trên mức nền cục bộ
            if (origLum > localMacro * 1.15f && origLum > 110.0f) {
                float hl = std::clamp((origLum - localMacro * 1.15f) / std::max(1.0f, 255.0f - localMacro * 1.15f), 0.0f, 1.0f);
                outHighlightMask[idx] = hl;
            } else {
                outHighlightMask[idx] = 0.0f;
            }
        }
    }
}

} // namespace meitu_native::hce

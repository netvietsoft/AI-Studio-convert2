#include "hair/hair_anisotropic_specular_engine.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <omp.h>

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)

#define PACK_RGBA(r, g, b, a) (((static_cast<uint32_t>(a) & 0xFF) << 24) | \
                               ((static_cast<uint32_t>(b) & 0xFF) << 16) | \
                               ((static_cast<uint32_t>(g) & 0xFF) << 8)  | \
                               ((static_cast<uint32_t>(r) & 0xFF) << 0))

namespace meitu_native::hce {

HairAnisotropicSpecularEngine& HairAnisotropicSpecularEngine::getInstance() {
    static HairAnisotropicSpecularEngine instance;
    return instance;
}

bool HairAnisotropicSpecularEngine::applySpecular(
    const std::vector<uint32_t>& recoloredPixels,
    int width,
    int height,
    const P0HairMatteAdapter& p0Matte,
    const HairOrientationField& orientation,
    const HairAppearanceContext& appearance,
    const HairSpecularParams& params,
    std::vector<uint32_t>& inoutFinalPixels
) {
    if (recoloredPixels.empty() || width <= 0 || height <= 0 || !p0Matte.alphaData) {
        return false;
    }

    const int total = width * height;
    inoutFinalPixels = recoloredPixels;

    const float* alpha = p0Matte.alphaData;

    int roiMinX = (p0Matte.roiMaxX > p0Matte.roiMinX) ? std::max(0, p0Matte.roiMinX) : 0;
    int roiMaxX = (p0Matte.roiMaxX > p0Matte.roiMinX) ? std::min(width - 1, p0Matte.roiMaxX) : width - 1;
    int roiMinY = (p0Matte.roiMaxY > p0Matte.roiMinY) ? std::max(0, p0Matte.roiMinY) : 0;
    int roiMaxY = (p0Matte.roiMaxY > p0Matte.roiMinY) ? std::min(height - 1, p0Matte.roiMaxY) : height - 1;

    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            int idx = yOff + x;
            float aVal = alpha[idx];
            if (aVal < 0.02f) continue;

            uint32_t c = recoloredPixels[idx];
            float r = RGBA_R(c);
            float g = RGBA_G(c);
            float b = RGBA_B(c);
            uint32_t a = RGBA_A(c);

            // 1. Lấy neo ánh sáng thực tế từ P3 (Highlight Anchor)
            float hlMask = appearance.isValid ? appearance.highlightMask[idx] : 0.0f;
            float shadowF = appearance.isValid ? appearance.shadowFactor[idx] : 1.0f;
            float flowConf = orientation.isValid ? orientation.confidence[idx] : 0.5f;

            // Trong khe bóng tối sâu, triệt tiêu hoàn toàn specular để tránh bóng giả dạng mũ bảo hiểm
            if (shadowF < 0.25f) continue;

            // 2. Tính toán phản xạ dị hướng Marschner R-Lobe
            // Cường độ phản quang tăng khi bám dọc theo sống lọn tóc và độ bóng biểu kiến cao
            float specularLobe = hlMask * params.apparentShine * (0.65f + 0.35f * flowConf);
            if (specularLobe <= 0.005f) continue;

            // 3. Phối trộn vệt bóng biểu bì (Cuticle Glint): Một phần phản xạ điện môi trắng bạc, một phần ánh màu nhuộm
            float tint = std::clamp(params.specularTint, 0.0f, 1.0f);
            float glintR = 255.0f * (1.0f - tint) + r * tint;
            float glintG = 255.0f * (1.0f - tint) + g * tint;
            float glintB = 255.0f * (1.0f - tint) + b * tint;

            // 4. Cộng dồn ánh sáng có giới hạn clipping
            float specWeight = std::clamp(specularLobe * aVal, 0.0f, 0.85f);
            float finalR = r + (glintR - r) * specWeight;
            float finalG = g + (glintG - g) * specWeight;
            float finalB = b + (glintB - b) * specWeight;

            inoutFinalPixels[idx] = PACK_RGBA(
                clampU8(static_cast<int>(std::round(finalR))),
                clampU8(static_cast<int>(std::round(finalG))),
                clampU8(static_cast<int>(std::round(finalB))),
                a
            );
        }
    }

    return true;
}

} // namespace meitu_native::hce

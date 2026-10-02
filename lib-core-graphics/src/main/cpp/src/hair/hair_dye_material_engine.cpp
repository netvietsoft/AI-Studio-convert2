#include "hair/hair_dye_material_engine.h"
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

HairDyeMaterialEngine& HairDyeMaterialEngine::getInstance() {
    static HairDyeMaterialEngine instance;
    return instance;
}

void HairDyeMaterialEngine::sRGBToOKLab(float r, float g, float b, float& L, float& a, float& bCoord) {
    // 1. Tuyến tính hóa sRGB sang Linear sRGB
    auto toLinear = [](float c) {
        return (c <= 0.04045f) ? (c / 12.92f) : std::pow((c + 0.055f) / 1.055f, 2.4f);
    };
    float lr = toLinear(r);
    float lg = toLinear(g);
    float lb = toLinear(b);

    // 2. Chuyển sang LMS
    float l = std::cbrt(0.4122214708f * lr + 0.5363325363f * lg + 0.0514459929f * lb);
    float m = std::cbrt(0.2119034982f * lr + 0.6806995451f * lg + 0.1073969566f * lb);
    float s = std::cbrt(0.0883024619f * lr + 0.2817188376f * lg + 0.6299787005f * lb);

    // 3. Chuyển sang OKLab
    L = 0.2104542553f * l + 0.7936177850f * m - 0.0040720468f * s;
    a = 1.9779984951f * l - 2.4285922050f * m + 0.4505937099f * s;
    bCoord = 0.0259040371f * l + 0.7827717662f * m - 0.8086757660f * s;
}

void HairDyeMaterialEngine::oklabTosRGB(float L, float a, float bCoord, float& r, float& g, float& b) {
    float l = L + 0.3963377774f * a + 0.2158037573f * bCoord;
    float m = L - 0.1055613458f * a - 0.0638541728f * bCoord;
    float s = L - 0.0894841775f * a - 1.2914855480f * bCoord;

    float l3 = l * l * l;
    float m3 = m * m * m;
    float s3 = s * s * s;

    float lr = +4.0767434721f * l3 - 3.3077115913f * m3 + 0.2309699292f * s3;
    float lg = -1.2684380046f * l3 + 2.6097574011f * m3 - 0.3413193965f * s3;
    float lb = -0.0041960863f * l3 - 0.7034186147f * m3 + 1.7076147010f * s3;

    auto fromLinear = [](float c) {
        float clamped = std::clamp(c, 0.0f, 1.0f);
        return (clamped <= 0.0031308f) ? (clamped * 12.92f) : (1.055f * std::pow(clamped, 1.0f / 2.4f) - 0.055f);
    };

    r = fromLinear(lr);
    g = fromLinear(lg);
    b = fromLinear(lb);
}

bool HairDyeMaterialEngine::applyDye(
    const uint32_t* srcPixels,
    int width,
    int height,
    const P0HairMatteAdapter& p0Matte,
    const HairAppearanceContext& appearance,
    const HairTextureContext& texture,
    const HairDyeMaterialParams& params,
    std::vector<uint32_t>& outRecoloredPixels
) {
    if (!srcPixels || width <= 0 || height <= 0 || !p0Matte.alphaData) {
        return false;
    }

    const int total = width * height;
    outRecoloredPixels.assign(srcPixels, srcPixels + total);

    const float* alpha = p0Matte.alphaData;

    // Tính toán tọa độ màu đích OKLab từ Target Hue & Chroma
    float hueRad = params.targetHue * 0.0174532925f; // Deg to Rad
    float targetC = std::clamp(params.targetChroma / 100.0f * 0.28f, 0.0f, 0.35f);
    float targetA = targetC * std::cos(hueRad);
    float targetBCoord = targetC * std::sin(hueRad);
    float targetL = std::clamp(params.targetLightness / 100.0f, 0.05f, 0.95f);

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
            if (aVal < 0.01f) continue;

            uint32_t c = srcPixels[idx];
            float origR = RGBA_R(c) / 255.0f;
            float origG = RGBA_G(c) / 255.0f;
            float origB = RGBA_B(c) / 255.0f;
            uint32_t origA = RGBA_A(c);

            // Chuyển pixel gốc sang OKLab
            float origL, origOklabA, origOklabB;
            sRGBToOKLab(origR, origG, origB, origL, origOklabA, origOklabB);

            // 1. Bảo tồn chiều sâu bóng đổ (P3 Shadow Crevices)
            float shadowF = appearance.isValid ? appearance.shadowFactor[idx] : 1.0f;
            float creviceFactor = std::pow(shadowF, 1.35f);
            float effectiveDepth = creviceFactor * params.shadowPreservation + (1.0f - params.shadowPreservation);

            // 2. Bảo tồn chiều sâu chân tóc (Root darkness)
            float rootF = appearance.isValid ? appearance.rootDepthContext[idx] : 0.5f;
            float rootDarknessScale = 1.0f - (1.0f - rootF) * (1.0f - params.rootStrength) * 0.4f;

            // 3. Nâng tông màu Melanin (Bleach / Tone Lift)
            float liftAmount = (targetL - origL);
            float finalL = origL + liftAmount * params.bleachPower * effectiveDepth * rootDarknessScale;

            // 4. Bù đắp vi chi tiết sợi tóc từ P2 Texture
            if (texture.isValid) {
                float microDetail = (texture.highFreqDetail[idx] * 0.6f + texture.directionalResponse[idx] * 0.4f) / 255.0f;
                finalL += microDetail * (1.2f * effectiveDepth);
            }
            finalL = std::clamp(finalL, 0.01f, 0.99f);

            // 5. Hòa trộn sắc tố màu salon (Chroma / Hue blend)
            float dyeA = targetA * effectiveDepth;
            float dyeB = targetBCoord * effectiveDepth;

            float blendedA = origOklabA * (1.0f - params.blendIntensity) + dyeA * params.blendIntensity;
            float blendedB = origOklabB * (1.0f - params.blendIntensity) + dyeB * params.blendIntensity;

            // 6. Chuyển ngược về sRGB
            float outR, outG, outB;
            oklabTosRGB(finalL, blendedA, blendedB, outR, outG, outB);

            // 7. Alpha compositing an toàn
            float blendWeight = std::clamp(aVal * params.blendIntensity, 0.0f, 1.0f);
            uint8_t finalR = clampU8(static_cast<int>(std::round((origR * (1.0f - blendWeight) + outR * blendWeight) * 255.0f)));
            uint8_t finalG = clampU8(static_cast<int>(std::round((origG * (1.0f - blendWeight) + outG * blendWeight) * 255.0f)));
            uint8_t finalB = clampU8(static_cast<int>(std::round((origB * (1.0f - blendWeight) + outB * blendWeight) * 255.0f)));

            outRecoloredPixels[idx] = PACK_RGBA(finalR, finalG, finalB, origA);
        }
    }

    return true;
}

} // namespace meitu_native::hce

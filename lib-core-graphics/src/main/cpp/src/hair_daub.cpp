#include "hair_daub.h"
#include <cmath>
#include <algorithm>
#include <omp.h>

namespace meitu_native {

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define PACK_RGBA(r, g, b, a) (((static_cast<uint32_t>(a) & 0xFF) << 24) |                                ((static_cast<uint32_t>(b) & 0xFF) << 16) |                                ((static_cast<uint32_t>(g) & 0xFF) << 8)  |                                ((static_cast<uint32_t>(r) & 0xFF) << 0))

static inline void rgbToHsv(float r, float g, float b, float& h, float& s, float& v) {
    float maxVal = std::max({r, g, b});
    float minVal = std::min({r, g, b});
    float delta = maxVal - minVal;

    v = maxVal;
    s = (maxVal > 0.0001f) ? (delta / maxVal) : 0.0f;

    if (delta < 0.0001f) {
        h = 0.0f;
    } else {
        if (maxVal == r) {
            h = 60.0f * (std::fmod(((g - b) / delta), 6.0f));
        } else if (maxVal == g) {
            h = 60.0f * (((b - r) / delta) + 2.0f);
        } else {
            h = 60.0f * (((r - g) / delta) + 4.0f);
        }
        if (h < 0.0f) h += 360.0f;
    }
}

static inline void hsvToRgb(float h, float s, float v, float& r, float& g, float& b) {
    float c = v * s;
    float x = c * (1.0f - std::abs(std::fmod(h / 60.0f, 2.0f) - 1.0f));
    float m = v - c;

    float rPrime = 0, gPrime = 0, bPrime = 0;
    if (h >= 0 && h < 60) {
        rPrime = c; gPrime = x; bPrime = 0;
    } else if (h >= 60 && h < 120) {
        rPrime = x; gPrime = c; bPrime = 0;
    } else if (h >= 120 && h < 180) {
        rPrime = 0; gPrime = c; bPrime = x;
    } else if (h >= 180 && h < 240) {
        rPrime = 0; gPrime = x; bPrime = c;
    } else if (h >= 240 && h < 300) {
        rPrime = x; gPrime = 0; bPrime = c;
    } else {
        rPrime = c; gPrime = 0; bPrime = x;
    }

    r = rPrime + m;
    g = gPrime + m;
    b = bPrime + m;
}

bool HairDaubEngine::dyeHair(
    uint32_t* pixels, int width, int height,
    const uint8_t* mask, int targetR, int targetG, int targetB,
    float gloss, float intensity
) {
    if (!pixels || width <= 0 || height <= 0) return false;

    float targetH, targetS, targetV;
    rgbToHsv(targetR / 255.0f, targetG / 255.0f, targetB / 255.0f, targetH, targetS, targetV);

    int totalPixels = width * height;

    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < totalPixels; ++i) {
        float maskAlpha = 0.0f;
        if (mask) {
            maskAlpha = (mask[i] / 255.0f) * intensity;
        } else {
            maskAlpha = 0.0f;
        }

        if (maskAlpha < 0.05f) continue;

        uint32_t pixel = pixels[i];
        uint32_t r = RGBA_R(pixel);
        uint32_t g = RGBA_G(pixel);
        uint32_t b = RGBA_B(pixel);
        uint32_t a = RGBA_A(pixel);

        // Tính độ sáng tự nhiên của sợi tóc
        float origLum = (0.299f * r + 0.587f * g + 0.114f * b) / 255.0f;

        float blendedH = targetH;
        float blendedS = std::min(1.0f, targetS * 1.15f);
        float blendedV = std::min(1.0f, origLum * 1.10f + (origLum * origLum * gloss));

        float outRf, outGf, outBf;
        hsvToRgb(blendedH, blendedS, blendedV, outRf, outGf, outBf);

        float nR = outRf * 255.0f;
        float nG = outGf * 255.0f;
        float nB = outBf * 255.0f;

        uint32_t finalR = static_cast<uint32_t>(std::clamp(r * (1.0f - maskAlpha) + nR * maskAlpha, 0.0f, 255.0f));
        uint32_t finalG = static_cast<uint32_t>(std::clamp(g * (1.0f - maskAlpha) + nG * maskAlpha, 0.0f, 255.0f));
        uint32_t finalB = static_cast<uint32_t>(std::clamp(b * (1.0f - maskAlpha) + nB * maskAlpha, 0.0f, 255.0f));

        pixels[i] = PACK_RGBA(finalR, finalG, finalB, a);
    }

    return true;
}

} // namespace meitu_native

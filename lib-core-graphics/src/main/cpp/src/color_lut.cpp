#include "color_lut.h"
#include <cmath>
#include <algorithm>
#include <omp.h>

#define RGBA_R(c) ((c) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define PACK_RGBA(r, g, b, a) (((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(g) << 8) | (uint32_t)(r))

namespace meitu_native {

static inline uint32_t sampleLutTrilinear512(const uint32_t* lut, float r, float g, float b) {
    float bSlice = std::clamp(b * 63.0f / 255.0f, 0.0f, 62.999f);
    int s0 = (int)bSlice;
    int s1 = std::min(s0 + 1, 63);
    float db = bSlice - (float)s0;

    float rCoord = std::clamp(r * 63.0f / 255.0f, 0.0f, 63.0f);
    float gCoord = std::clamp(g * 63.0f / 255.0f, 0.0f, 63.0f);

    int r0 = (int)rCoord;
    int r1 = std::min(r0 + 1, 63);
    float dr = rCoord - (float)r0;

    int g0 = (int)gCoord;
    int g1 = std::min(g0 + 1, 63);
    float dg = gCoord - (float)g0;

    auto getSlicePixel = [&](int slice, int rx, int gy) -> uint32_t {
        int tileX = (slice % 8) * 64;
        int tileY = (slice / 8) * 64;
        return lut[(tileY + gy) * 512 + (tileX + rx)];
    };

    uint32_t p000 = getSlicePixel(s0, r0, g0);
    uint32_t p100 = getSlicePixel(s0, r1, g0);
    uint32_t p010 = getSlicePixel(s0, r0, g1);
    uint32_t p110 = getSlicePixel(s0, r1, g1);

    uint32_t p001 = getSlicePixel(s1, r0, g0);
    uint32_t p101 = getSlicePixel(s1, r1, g0);
    uint32_t p011 = getSlicePixel(s1, r0, g1);
    uint32_t p111 = getSlicePixel(s1, r1, g1);

    auto trilerp = [&](float c000, float c100, float c010, float c110,
                       float c001, float c101, float c011, float c111) -> float {
        float c00 = c000 * (1.0f - dr) + c100 * dr;
        float c10 = c010 * (1.0f - dr) + c110 * dr;
        float c01 = c001 * (1.0f - dr) + c101 * dr;
        float c11 = c011 * (1.0f - dr) + c111 * dr;

        float c0 = c00 * (1.0f - dg) + c10 * dg;
        float c1 = c01 * (1.0f - dg) + c11 * dg;

        return c0 * (1.0f - db) + c1 * db;
    };

    float outR = trilerp(RGBA_R(p000), RGBA_R(p100), RGBA_R(p010), RGBA_R(p110),
                         RGBA_R(p001), RGBA_R(p101), RGBA_R(p011), RGBA_R(p111));
    float outG = trilerp(RGBA_G(p000), RGBA_G(p100), RGBA_G(p010), RGBA_G(p110),
                         RGBA_G(p001), RGBA_G(p101), RGBA_G(p011), RGBA_G(p111));
    float outB = trilerp(RGBA_B(p000), RGBA_B(p100), RGBA_B(p010), RGBA_B(p110),
                         RGBA_B(p001), RGBA_B(p101), RGBA_B(p011), RGBA_B(p111));

    return PACK_RGBA(
        (uint32_t)std::clamp((int)std::round(outR), 0, 255),
        (uint32_t)std::clamp((int)std::round(outG), 0, 255),
        (uint32_t)std::clamp((int)std::round(outB), 0, 255),
        255
    );
}

static inline uint32_t sampleLutStrip256(const uint32_t* lut, int lutW, int lutH, float r, float g, float b) {
    float bSlice = std::clamp(b * 15.0f / 255.0f, 0.0f, 14.999f);
    int s0 = (int)bSlice;
    int s1 = std::min(s0 + 1, 15);
    float db = bSlice - (float)s0;

    int rCoord = std::clamp((int)(r * 15.0f / 255.0f), 0, 15);
    int gCoord = std::clamp((int)(g * (float)(lutH - 1) / 255.0f), 0, lutH - 1);

    uint32_t c0 = lut[gCoord * lutW + (s0 * 16 + rCoord)];
    uint32_t c1 = lut[gCoord * lutW + (s1 * 16 + rCoord)];

    float outR = (float)RGBA_R(c0) * (1.0f - db) + (float)RGBA_R(c1) * db;
    float outG = (float)RGBA_G(c0) * (1.0f - db) + (float)RGBA_G(c1) * db;
    float outB = (float)RGBA_B(c0) * (1.0f - db) + (float)RGBA_B(c1) * db;

    return PACK_RGBA(
        (uint32_t)std::clamp((int)std::round(outR), 0, 255),
        (uint32_t)std::clamp((int)std::round(outG), 0, 255),
        (uint32_t)std::clamp((int)std::round(outB), 0, 255),
        255
    );
}

bool ColorLutEngine::applyLut(
    uint32_t* pixels,
    int width,
    int height,
    const uint32_t* lutPixels,
    int lutW,
    int lutH,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || !lutPixels || lutW <= 0 || lutH <= 0) {
        return false;
    }

    float alpha = std::clamp(intensity, 0.0f, 1.0f);
    if (alpha <= 0.001f) return true;

    bool isHald512 = (lutW == 512 && lutH == 512);

    #pragma omp parallel for schedule(static)
    for (int y = 0; y < height; ++y) {
        int rowIdx = y * width;
        for (int x = 0; x < width; ++x) {
            uint32_t c = pixels[rowIdx + x];
            float r = (float)RGBA_R(c);
            float g = (float)RGBA_G(c);
            float b = (float)RGBA_B(c);
            uint32_t a = RGBA_A(c);

            uint32_t lutColor = isHald512
                ? sampleLutTrilinear512(lutPixels, r, g, b)
                : sampleLutStrip256(lutPixels, lutW, lutH, r, g, b);

            float outR = r * (1.0f - alpha) + (float)RGBA_R(lutColor) * alpha;
            float outG = g * (1.0f - alpha) + (float)RGBA_G(lutColor) * alpha;
            float outB = b * (1.0f - alpha) + (float)RGBA_B(lutColor) * alpha;

            pixels[rowIdx + x] = PACK_RGBA(
                (uint32_t)std::clamp((int)std::round(outR), 0, 255),
                (uint32_t)std::clamp((int)std::round(outG), 0, 255),
                (uint32_t)std::clamp((int)std::round(outB), 0, 255),
                a
            );
        }
    }

    return true;
}

bool ColorLutEngine::applyColorTuning(
    uint32_t* pixels,
    int width,
    int height,
    const ColorTuningParams& params
) {
    if (!pixels || width <= 0 || height <= 0) return false;

    float brightOffset = (params.brightness / 100.0f) * 255.0f;
    float contrastFactor = (params.contrast > 0.0f)
        ? (1.0f + params.contrast / 100.0f)
        : (1.0f + params.contrast / 200.0f);
    float satFactor = 1.0f + (params.saturation / 100.0f);
    float tempShift = (params.temperature / 100.0f) * 35.0f;
    float tintShift = (params.tint / 100.0f) * 25.0f;
    float exposureMult = std::pow(2.0f, (params.exposure / 50.0f));

    #pragma omp parallel for schedule(static)
    for (int y = 0; y < height; ++y) {
        int rowIdx = y * width;
        for (int x = 0; x < width; ++x) {
            uint32_t c = pixels[rowIdx + x];
            float r = (float)RGBA_R(c);
            float g = (float)RGBA_G(c);
            float b = (float)RGBA_B(c);
            uint32_t a = RGBA_A(c);

            // 1. Exposure & Brightness
            r = r * exposureMult + brightOffset;
            g = g * exposureMult + brightOffset;
            b = b * exposureMult + brightOffset;

            // 2. Contrast
            r = (r - 128.0f) * contrastFactor + 128.0f;
            g = (g - 128.0f) * contrastFactor + 128.0f;
            b = (b - 128.0f) * contrastFactor + 128.0f;

            // 3. Temperature & Tint
            r += tempShift - tintShift * 0.5f;
            g += tintShift;
            b += -tempShift - tintShift * 0.5f;

            // 4. Saturation
            float lum = 0.2126f * r + 0.7152f * g + 0.0722f * b;
            r = lum + (r - lum) * satFactor;
            g = lum + (g - lum) * satFactor;
            b = lum + (b - lum) * satFactor;

            pixels[rowIdx + x] = PACK_RGBA(
                (uint32_t)std::clamp((int)std::round(r), 0, 255),
                (uint32_t)std::clamp((int)std::round(g), 0, 255),
                (uint32_t)std::clamp((int)std::round(b), 0, 255),
                a
            );
        }
    }

    return true;
}




bool ColorLutEngine::applyLocalizedColorTuning(
    uint32_t* pixels,
    int width,
    int height,
    float centerX,
    float centerY,
    float radiusX,
    float radiusY,
    const ColorTuningParams& params,
    bool skinToneOnly
) {
    if (!pixels || width <= 0 || height <= 0 || radiusX <= 1.0f || radiusY <= 1.0f) return false;

    int minX = std::max(0, static_cast<int>(centerX - radiusX));
    int maxX = std::min(width - 1, static_cast<int>(centerX + radiusX));
    int minY = std::max(0, static_cast<int>(centerY - radiusY));
    int maxY = std::min(height - 1, static_cast<int>(centerY + radiusY));

    float brightOffset = (params.brightness / 100.0f) * 255.0f;
    float contrastFactor = (params.contrast > 0.0f)
        ? (1.0f + params.contrast / 100.0f)
        : (1.0f + params.contrast / 200.0f);
    float satFactor = 1.0f + (params.saturation / 100.0f);
    float tempShift = (params.temperature / 100.0f) * 35.0f;
    float tintShift = (params.tint / 100.0f) * 25.0f;
    float exposureMult = std::pow(2.0f, (params.exposure / 50.0f));

    float radXInv = 1.0f / radiusX;
    float radYInv = 1.0f / radiusY;

    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = minY; y <= maxY; ++y) {
        int rowIdx = y * width;
        float dy = (y - centerY) * radYInv;
        float dySq = dy * dy;

        for (int x = minX; x <= maxX; ++x) {
            float dx = (x - centerX) * radXInv;
            float distSq = dx * dx + dySq;
            if (distSq >= 1.0f) continue;

            uint32_t c = pixels[rowIdx + x];
            float r = static_cast<float>(RGBA_R(c));
            float g = static_cast<float>(RGBA_G(c));
            float b = static_cast<float>(RGBA_B(c));
            uint32_t a = RGBA_A(c);

            // Kiểm tra chỉ tác động lên màu da (bảo vệ tóc, mắt, cổ áo, nền)
            if (skinToneOnly) {
                float maxRGB = std::max(r, std::max(g, b));
                float minRGB = std::min(r, std::min(g, b));
                bool isSkin = (r > 70.0f && g > 30.0f && b > 15.0f) &&
                              (maxRGB - minRGB > 10.0f) &&
                              (r > g) && (g >= b * 0.80f);
                if (!isSkin) continue;
            }

            // Mượt mà biên (smooth hermite feathering: (1 - d^2)^2)
            float edgeDist = 1.0f - distSq;
            float featherWeight = edgeDist * edgeDist;

            // 1. Exposure & Brightness
            float tunedR = r * exposureMult + brightOffset;
            float tunedG = g * exposureMult + brightOffset;
            float tunedB = b * exposureMult + brightOffset;

            // 2. Contrast
            tunedR = (tunedR - 128.0f) * contrastFactor + 128.0f;
            tunedG = (tunedG - 128.0f) * contrastFactor + 128.0f;
            tunedB = (tunedB - 128.0f) * contrastFactor + 128.0f;

            // 3. Temperature & Tint
            tunedR += tempShift - tintShift * 0.5f;
            tunedG += tintShift;
            tunedB += -tempShift - tintShift * 0.5f;

            // 4. Saturation
            float lum = 0.2126f * tunedR + 0.7152f * tunedG + 0.0722f * tunedB;
            tunedR = lum + (tunedR - lum) * satFactor;
            tunedG = lum + (tunedG - lum) * satFactor;
            tunedB = lum + (tunedB - lum) * satFactor;

            // Blend nhẹ nhàng với ảnh gốc theo featherWeight
            float finalR = r * (1.0f - featherWeight) + tunedR * featherWeight;
            float finalG = g * (1.0f - featherWeight) + tunedG * featherWeight;
            float finalB = b * (1.0f - featherWeight) + tunedB * featherWeight;

            pixels[rowIdx + x] = PACK_RGBA(
                static_cast<uint32_t>(std::clamp(static_cast<int>(std::round(finalR)), 0, 255)),
                static_cast<uint32_t>(std::clamp(static_cast<int>(std::round(finalG)), 0, 255)),
                static_cast<uint32_t>(std::clamp(static_cast<int>(std::round(finalB)), 0, 255)),
                a
            );
        }
    }

    return true;
}

bool ColorLutEngine::applyLocalizedSkinBilateral(
    uint32_t* pixels,
    int width,
    int height,
    float centerX,
    float centerY,
    float radiusX,
    float radiusY,
    float smoothStrength,
    float brightenStrength
) {
    if (!pixels || width <= 0 || height <= 0 || radiusX <= 1.0f || radiusY <= 1.0f) return false;

    int minX = std::max(0, static_cast<int>(centerX - radiusX));
    int maxX = std::min(width - 1, static_cast<int>(centerX + radiusX));
    int minY = std::max(0, static_cast<int>(centerY - radiusY));
    int maxY = std::min(height - 1, static_cast<int>(centerY + radiusY));

    int filterRadius = std::clamp(static_cast<int>(smoothStrength * 4.0f) + 1, 1, 5);
    float radXInv = 1.0f / radiusX;
    float radYInv = 1.0f / radiusY;

    int patchWidth = maxX - minX + 1;
    int patchHeight = maxY - minY + 1;
    std::vector<uint32_t> origPatch(patchWidth * patchHeight);

    for (int y = minY; y <= maxY; ++y) {
        int patchRow = (y - minY) * patchWidth;
        int srcRow = y * width;
        for (int x = minX; x <= maxX; ++x) {
            origPatch[patchRow + (x - minX)] = pixels[srcRow + x];
        }
    }

    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = minY; y <= maxY; ++y) {
        int rowIdx = y * width;
        int patchRow = (y - minY) * patchWidth;
        float dy = (y - centerY) * radYInv;
        float dySq = dy * dy;

        for (int x = minX; x <= maxX; ++x) {
            float dx = (x - centerX) * radXInv;
            float distSq = dx * dx + dySq;
            if (distSq >= 1.0f) continue;

            uint32_t c = origPatch[patchRow + (x - minX)];
            float r = static_cast<float>(RGBA_R(c));
            float g = static_cast<float>(RGBA_G(c));
            float b = static_cast<float>(RGBA_B(c));
            uint32_t a = RGBA_A(c);

            // Kiểm tra sắc tố da
            float maxRGB = std::max(r, std::max(g, b));
            float minRGB = std::min(r, std::min(g, b));
            bool isSkin = (r > 70.0f && g > 30.0f && b > 15.0f) &&
                          (maxRGB - minRGB > 10.0f) &&
                          (r > g) && (g >= b * 0.80f);
            if (!isSkin) continue;

            float edgeDist = 1.0f - distSq;
            float featherWeight = edgeDist * edgeDist * smoothStrength;

            // Bilateral filter trong vùng lân cận
            float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f;
            float totalWeight = 0.0f;

            for (int fdy = -filterRadius; fdy <= filterRadius; ++fdy) {
                int ny = std::clamp(y + fdy, minY, maxY);
                int nPatchRow = (ny - minY) * patchWidth;
                for (int fdx = -filterRadius; fdx <= filterRadius; ++fdx) {
                    int nx = std::clamp(x + fdx, minX, maxX);
                    uint32_t nc = origPatch[nPatchRow + (nx - minX)];

                    float nr = static_cast<float>(RGBA_R(nc));
                    float ng = static_cast<float>(RGBA_G(nc));
                    float nb = static_cast<float>(RGBA_B(nc));

                    float colorDiff = std::abs(r - nr) + std::abs(g - ng) + std::abs(b - nb);
                    if (colorDiff < 65.0f) {
                        float spatialW = 1.0f / (1.0f + fdx * fdx + fdy * fdy);
                        float rangeW = 1.0f - (colorDiff / 65.0f);
                        float w = spatialW * rangeW;

                        sumR += nr * w;
                        sumG += ng * w;
                        sumB += nb * w;
                        totalWeight += w;
                    }
                }
            }

            float smoothR = (totalWeight > 0.0f) ? (sumR / totalWeight) : r;
            float smoothG = (totalWeight > 0.0f) ? (sumG / totalWeight) : g;
            float smoothB = (totalWeight > 0.0f) ? (sumB / totalWeight) : b;

            // Nâng tông trắng sứ cục bộ trên da nếu có brightenStrength
            if (brightenStrength > 0.0f) {
                smoothR = std::min(255.0f, smoothR + (255.0f - smoothR) * brightenStrength * 0.25f);
                smoothG = std::min(255.0f, smoothG + (255.0f - smoothG) * brightenStrength * 0.22f);
                smoothB = std::min(255.0f, smoothB + (255.0f - smoothB) * brightenStrength * 0.20f);
            }

            float finalR = r * (1.0f - featherWeight) + smoothR * featherWeight;
            float finalG = g * (1.0f - featherWeight) + smoothG * featherWeight;
            float finalB = b * (1.0f - featherWeight) + smoothB * featherWeight;

            pixels[rowIdx + x] = PACK_RGBA(
                static_cast<uint32_t>(std::clamp(static_cast<int>(std::round(finalR)), 0, 255)),
                static_cast<uint32_t>(std::clamp(static_cast<int>(std::round(finalG)), 0, 255)),
                static_cast<uint32_t>(std::clamp(static_cast<int>(std::round(finalB)), 0, 255)),
                a
            );
        }
    }

    return true;
}

} // namespace meitu_native

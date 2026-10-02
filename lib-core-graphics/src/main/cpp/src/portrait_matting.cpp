#include "portrait_matting.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <omp.h>

#define RGBA_R(c) ((c) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define PACK_RGBA(r, g, b, a) (((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(g) << 8) | (uint32_t)(r))

namespace meitu_native {

bool PortraitMattingEngine::generatePortraitAlphaMask(
    const uint32_t* srcPixels,
    int width,
    int height,
    const float* landmarks106,
    uint8_t* outAlphaMask
) {
    if (!srcPixels || width <= 0 || height <= 0 || !outAlphaMask) {
        return false;
    }

    float minX = (float)width, maxX = 0.0f;
    float minY = (float)height, maxY = 0.0f;

    if (landmarks106 != nullptr) {
        for (int i = 0; i < 106; ++i) {
            float lx = landmarks106[i * 2];
            float ly = landmarks106[i * 2 + 1];
            if (lx < minX) minX = lx;
            if (lx > maxX) maxX = lx;
            if (ly < minY) minY = ly;
            if (ly > maxY) maxY = ly;
        }
    } else {
        minX = width * 0.2f;
        maxX = width * 0.8f;
        minY = height * 0.1f;
        maxY = height * 0.85f;
    }

    float faceW = maxX - minX;
    float faceH = maxY - minY;
    float centerX = (minX + maxX) * 0.5f;
    float centerY = (minY + maxY) * 0.5f;

    float headRadiusX = faceW * 0.85f;
    float headRadiusY = faceH * 0.95f;
    float bodyRadiusX = faceW * 1.5f;

    int sampleX = std::clamp((int)centerX, 0, width - 1);
    int sampleY = std::clamp((int)centerY, 0, height - 1);
    uint32_t sampleC = srcPixels[sampleY * width + sampleX];
    float skinR = (float)RGBA_R(sampleC);
    float skinG = (float)RGBA_G(sampleC);
    float skinB = (float)RGBA_B(sampleC);

    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = 0; y < height; ++y) {
        int rowIdx = y * width;
        for (int x = 0; x < width; ++x) {
            float dx = (float)x - centerX;
            float dy = (float)y - centerY;

            float headDistSq = (dx * dx) / (headRadiusX * headRadiusX) + (dy * dy) / (headRadiusY * headRadiusY);
            
            float bodyDistSq = 999.0f;
            if (y > centerY) {
                float torsoY = (float)(y - centerY) / ((float)height - centerY);
                float allowedW = bodyRadiusX * (1.0f + torsoY * 0.8f);
                bodyDistSq = (dx * dx) / (allowedW * allowedW);
            }

            float geoConfidence = 0.0f;
            if (headDistSq <= 1.0f) {
                geoConfidence = 1.0f - headDistSq * 0.4f;
            } else if (y > centerY && bodyDistSq <= 1.0f) {
                geoConfidence = 0.9f - bodyDistSq * 0.3f;
            } else {
                float outsideDist = std::min(headDistSq, bodyDistSq);
                geoConfidence = std::max(0.0f, 1.0f - (outsideDist - 1.0f) * 2.5f);
            }

            uint32_t cur = srcPixels[rowIdx + x];
            float r = (float)RGBA_R(cur);
            float g = (float)RGBA_G(cur);
            float b = (float)RGBA_B(cur);

            float colorDist = std::sqrt((r - skinR) * (r - skinR) + (g - skinG) * (g - skinG) + (b - skinB) * (b - skinB));
            float skinWeight = std::max(0.0f, 1.0f - colorDist / 180.0f);

            float alphaVal = geoConfidence * 0.85f + (geoConfidence > 0.1f ? skinWeight * 0.15f : 0.0f);
            alphaVal = std::clamp(alphaVal, 0.0f, 1.0f);

            outAlphaMask[rowIdx + x] = (uint8_t)std::round(alphaVal * 255.0f);
        }
    }

    return true;
}

bool PortraitMattingEngine::compositeBackground(
    uint32_t* fgPixels,
    int fgW,
    int fgH,
    const uint8_t* alphaMask,
    const uint32_t* bgPixels,
    int bgW,
    int bgH
) {
    if (!fgPixels || fgW <= 0 || fgH <= 0 || !alphaMask || !bgPixels || bgW <= 0 || bgH <= 0) {
        return false;
    }

    #pragma omp parallel for schedule(static)
    for (int y = 0; y < fgH; ++y) {
        int fgRow = y * fgW;
        int bgY = std::clamp((int)((float)y * bgH / (float)fgH), 0, bgH - 1);
        int bgRow = bgY * bgW;

        for (int x = 0; x < fgW; ++x) {
            uint8_t alpha = alphaMask[fgRow + x];
            if (alpha == 255) {
                continue;
            }

            int bgX = std::clamp((int)((float)x * bgW / (float)fgW), 0, bgW - 1);
            uint32_t bgC = bgPixels[bgRow + bgX];

            if (alpha == 0) {
                fgPixels[fgRow + x] = bgC;
            } else {
                uint32_t fgC = fgPixels[fgRow + x];
                float fa = (float)alpha / 255.0f;
                float invA = 1.0f - fa;

                uint32_t r = (uint32_t)std::round((float)RGBA_R(fgC) * fa + (float)RGBA_R(bgC) * invA);
                uint32_t g = (uint32_t)std::round((float)RGBA_G(fgC) * fa + (float)RGBA_G(bgC) * invA);
                uint32_t b = (uint32_t)std::round((float)RGBA_B(fgC) * fa + (float)RGBA_B(bgC) * invA);

                fgPixels[fgRow + x] = PACK_RGBA(r, g, b, 255);
            }
        }
    }

    return true;
}

bool PortraitMattingEngine::applyBokehBlur(
    uint32_t* pixels,
    int width,
    int height,
    const uint8_t* alphaMask,
    float maxBlurRadius
) {
    if (!pixels || width <= 0 || height <= 0 || !alphaMask || maxBlurRadius <= 0.5f) {
        return false;
    }

    int iRadius = std::min((int)std::round(maxBlurRadius), 32);
    std::vector<uint32_t> temp(width * height);

    #pragma omp parallel for schedule(static)
    for (int y = 0; y < height; ++y) {
        int rowIdx = y * width;
        for (int x = 0; x < width; ++x) {
            uint8_t alpha = alphaMask[rowIdx + x];
            int localR = (int)std::round((float)iRadius * (1.0f - (float)alpha / 255.0f));

            if (localR <= 0) {
                temp[rowIdx + x] = pixels[rowIdx + x];
                continue;
            }

            int count = 0;
            float sumR = 0, sumG = 0, sumB = 0;
            for (int kx = -localR; kx <= localR; ++kx) {
                int nx = x + kx;
                if (nx >= 0 && nx < width) {
                    uint32_t c = pixels[rowIdx + nx];
                    sumR += (float)RGBA_R(c);
                    sumG += (float)RGBA_G(c);
                    sumB += (float)RGBA_B(c);
                    count++;
                }
            }

            if (count > 0) {
                temp[rowIdx + x] = PACK_RGBA(
                    (uint32_t)std::round(sumR / count),
                    (uint32_t)std::round(sumG / count),
                    (uint32_t)std::round(sumB / count),
                    RGBA_A(pixels[rowIdx + x])
                );
            } else {
                temp[rowIdx + x] = pixels[rowIdx + x];
            }
        }
    }

    #pragma omp parallel for schedule(static)
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            int rowIdx = y * width;
            uint8_t alpha = alphaMask[rowIdx + x];
            int localR = (int)std::round((float)iRadius * (1.0f - (float)alpha / 255.0f));

            if (localR <= 0) {
                continue;
            }

            int count = 0;
            float sumR = 0, sumG = 0, sumB = 0;
            for (int ky = -localR; ky <= localR; ++ky) {
                int ny = y + ky;
                if (ny >= 0 && ny < height) {
                    uint32_t c = temp[ny * width + x];
                    sumR += (float)RGBA_R(c);
                    sumG += (float)RGBA_G(c);
                    sumB += (float)RGBA_B(c);
                    count++;
                }
            }

            if (count > 0) {
                pixels[rowIdx + x] = PACK_RGBA(
                    (uint32_t)std::round(sumR / count),
                    (uint32_t)std::round(sumG / count),
                    (uint32_t)std::round(sumB / count),
                    RGBA_A(pixels[rowIdx + x])
                );
            }
        }
    }

    return true;
}

} // namespace meitu_native

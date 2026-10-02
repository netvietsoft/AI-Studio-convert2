#include "neck_clavicle_engine.h"
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

namespace meitu_native {

NeckClavicleEngine::NeckClavicleEngine() = default;
NeckClavicleEngine::~NeckClavicleEngine() = default;

void NeckClavicleEngine::sampleBilinear(const uint8_t* src, int w, int h, int stride, float x, float y, uint8_t out[4]) {
    x = clampF(x, 0.0f, static_cast<float>(w - 1));
    y = clampF(y, 0.0f, static_cast<float>(h - 1));

    int x0 = static_cast<int>(std::floor(x));
    int y0 = static_cast<int>(std::floor(y));
    int x1 = std::min(x0 + 1, w - 1);
    int y1 = std::min(y0 + 1, h - 1);

    float fx = x - static_cast<float>(x0);
    float fy = y - static_cast<float>(y0);
    float w00 = (1.0f - fx) * (1.0f - fy);
    float w10 = fx * (1.0f - fy);
    float w01 = (1.0f - fx) * fy;
    float w11 = fx * fy;

    const uint8_t* p00 = src + y0 * stride + x0 * 4;
    const uint8_t* p10 = src + y0 * stride + x1 * 4;
    const uint8_t* p01 = src + y1 * stride + x0 * 4;
    const uint8_t* p11 = src + y1 * stride + x1 * 4;

    for (int c = 0; c < 4; ++c) {
        float val = p00[c] * w00 + p10[c] * w10 + p01[c] * w01 + p11[c] * w11;
        out[c] = clampU8(static_cast<int>(val + 0.5f));
    }
}

bool NeckClavicleEngine::processNeckClavicle(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const HeadFrameResult& headResult,
    int paramId,
    float intensity
) {
    if (!rgbaImage || width <= 0 || height <= 0 || stride < width * 4) {
        return false;
    }
    if (intensity <= 0.001f) {
        return true; // No-op
    }

    switch (paramId) {
        case PARAM_NECK_SLIM:
            return applyNeckSlimming(rgbaImage, width, height, stride, headResult, intensity);
        case PARAM_NECK_LENGTH:
            return applyNeckLength(rgbaImage, width, height, stride, headResult, intensity);
        case PARAM_NECK_WRINKLE_SMOOTH:
            return applyNeckWrinkleSmoothing(rgbaImage, width, height, stride, headResult, intensity);
        case PARAM_CLAVICLE_ENHANCE:
            return applyClavicleEnhancement(rgbaImage, width, height, stride, headResult, intensity);
        case PARAM_FACE_NECK_TONE:
            return applyFaceNeckToneMatching(rgbaImage, width, height, stride, headResult, intensity);
        default:
            return false;
    }
}

// -----------------------------------------------------------------------------
// 1. PARAM_NECK_SLIM: Thon cổ với bảo vệ viền cổ áo và background
// -----------------------------------------------------------------------------
bool NeckClavicleEngine::applyNeckSlimming(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
    float neckX1 = head.neckClavicle.leftClavicle.x;
    float neckX2 = head.neckClavicle.rightClavicle.x;
    float neckY1 = head.jawChin.chinTip.y;
    float neckY2 = head.neckClavicle.throatCenter.y + head.neckClavicle.neckLength;

    if (neckX2 <= neckX1 || neckY2 <= neckY1) {
        neckX1 = head.jawChin.chinTip.x - head.jawChin.jawWidth * 0.45f;
        neckX2 = head.jawChin.chinTip.x + head.jawChin.jawWidth * 0.45f;
        neckY1 = head.jawChin.chinTip.y;
        neckY2 = std::min(static_cast<float>(h - 1), neckY1 + 180.0f);
    }

    float centerX = (neckX1 + neckX2) * 0.5f;
    float neckWidth = neckX2 - neckX1;
    float neckHeight = neckY2 - neckY1;
    if (neckWidth <= 10.0f || neckHeight <= 10.0f) return true;

    std::vector<uint8_t> backup(w * h * 4);
    std::memcpy(backup.data(), rgba, w * h * 4);

    float maxDisplacement = neckWidth * 0.12f * std::min(1.0f, intensity);

    int roiX1 = std::max(0, static_cast<int>(neckX1 - 20));
    int roiX2 = std::min(w - 1, static_cast<int>(neckX2 + 20));
    int roiY1 = std::max(0, static_cast<int>(neckY1));
    int roiY2 = std::min(h - 1, static_cast<int>(neckY2));

    for (int y = roiY1; y <= roiY2; ++y) {
        float ny = (static_cast<float>(y) - neckY1) / neckHeight;
        float vertWeight = std::sin(ny * 3.14159265f);

        for (int x = roiX1; x <= roiX2; ++x) {
            float distFromCenter = static_cast<float>(x) - centerX;
            float normDist = std::abs(distFromCenter) / (neckWidth * 0.5f + 1e-4f);

            if (normDist > 1.2f) continue;

            float horizWeight = (normDist < 1.0f) ? (1.0f - normDist * normDist * (3.0f - 2.0f * normDist)) : 0.0f;
            float totalWeight = vertWeight * horizWeight;

            if (totalWeight <= 0.001f) continue;

            float sign = (distFromCenter >= 0.0f) ? 1.0f : -1.0f;
            float srcX = static_cast<float>(x) + sign * maxDisplacement * totalWeight;
            float srcY = static_cast<float>(y);

            uint8_t sampled[4];
            sampleBilinear(backup.data(), w, h, stride, srcX, srcY, sampled);

            uint8_t* dst = rgba + y * stride + x * 4;
            for (int c = 0; c < 4; ++c) {
                dst[c] = sampled[c];
            }
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
// 2. PARAM_NECK_LENGTH: Cổ thiên nga / Kéo dài cổ
// -----------------------------------------------------------------------------
bool NeckClavicleEngine::applyNeckLength(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
    float neckX1 = head.neckClavicle.leftClavicle.x;
    float neckX2 = head.neckClavicle.rightClavicle.x;
    float neckY1 = head.jawChin.chinTip.y;
    float neckY2 = head.neckClavicle.throatCenter.y + head.neckClavicle.neckLength;

    if (neckX2 <= neckX1 || neckY2 <= neckY1) {
        neckX1 = head.jawChin.chinTip.x - head.jawChin.jawWidth * 0.45f;
        neckX2 = head.jawChin.chinTip.x + head.jawChin.jawWidth * 0.45f;
        neckY1 = head.jawChin.chinTip.y;
        neckY2 = std::min(static_cast<float>(h - 1), neckY1 + 180.0f);
    }

    float neckHeight = neckY2 - neckY1;
    float neckWidth = neckX2 - neckX1;
    if (neckHeight <= 10.0f || neckWidth <= 10.0f) return true;

    std::vector<uint8_t> backup(w * h * 4);
    std::memcpy(backup.data(), rgba, w * h * 4);

    float maxVerticalStretch = neckHeight * 0.10f * std::min(1.0f, intensity);

    int roiX1 = std::max(0, static_cast<int>(neckX1));
    int roiX2 = std::min(w - 1, static_cast<int>(neckX2));
    int roiY1 = std::max(0, static_cast<int>(neckY1));
    int roiY2 = std::min(h - 1, static_cast<int>(neckY2));

    for (int y = roiY1; y <= roiY2; ++y) {
        float ny = (static_cast<float>(y) - neckY1) / neckHeight;
        float vertWeight = std::sin(ny * 3.14159265f);

        for (int x = roiX1; x <= roiX2; ++x) {
            float distFromCenter = std::abs(static_cast<float>(x) - (neckX1 + neckX2) * 0.5f);
            float normDist = distFromCenter / (neckWidth * 0.5f + 1e-4f);
            if (normDist > 1.0f) continue;

            float horizWeight = 1.0f - normDist * normDist;
            float totalWeight = vertWeight * horizWeight;
            if (totalWeight <= 0.001f) continue;

            float srcX = static_cast<float>(x);
            float srcY = static_cast<float>(y) - maxVerticalStretch * totalWeight;

            uint8_t sampled[4];
            sampleBilinear(backup.data(), w, h, stride, srcX, srcY, sampled);

            uint8_t* dst = rgba + y * stride + x * 4;
            for (int c = 0; c < 4; ++c) {
                dst[c] = sampled[c];
            }
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
// 3. PARAM_NECK_WRINKLE_SMOOTH: Xóa nếp nhăn cổ (Bảo lưu vi lỗ chân lông)
// -----------------------------------------------------------------------------
bool NeckClavicleEngine::applyNeckWrinkleSmoothing(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
    float neckX1 = head.neckClavicle.leftClavicle.x;
    float neckX2 = head.neckClavicle.rightClavicle.x;
    float neckY1 = head.jawChin.chinTip.y;
    float neckY2 = head.neckClavicle.throatCenter.y + head.neckClavicle.neckLength;

    if (neckX2 <= neckX1 || neckY2 <= neckY1) {
        neckX1 = std::max(0.0f, head.jawChin.chinTip.x - head.jawChin.jawWidth * 0.40f);
        neckX2 = std::min(static_cast<float>(w - 1), head.jawChin.chinTip.x + head.jawChin.jawWidth * 0.40f);
        neckY1 = std::max(0.0f, head.jawChin.chinTip.y);
        neckY2 = std::min(static_cast<float>(h - 1), neckY1 + 180.0f);
    }

    int rx1 = static_cast<int>(neckX1);
    int rx2 = static_cast<int>(neckX2);
    int ry1 = static_cast<int>(neckY1);
    int ry2 = static_cast<int>(neckY2);

    std::vector<uint8_t> backup(w * h * 4);
    std::memcpy(backup.data(), rgba, w * h * 4);

    float blendAlpha = std::min(1.0f, intensity * 0.85f);
    int kRadiusX = 5;
    int kRadiusY = 2;

    for (int y = ry1; y <= ry2; ++y) {
        float ny = (static_cast<float>(y) - neckY1) / (neckY2 - neckY1 + 1e-4f);
        float edgeDamp = std::sin(ny * 3.14159265f);

        for (int x = rx1; x <= rx2; ++x) {
            const uint8_t* centerPix = backup.data() + y * stride + x * 4;
            int cR = centerPix[0], cG = centerPix[1], cB = centerPix[2];
            int cLum = (cR * 299 + cG * 587 + cB * 114) / 1000;

            if (cR <= cG || cR <= cB || cLum < 30 || cLum > 240) continue;

            float sumWeights = 0.0f;
            float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f;

            for (int dy = -kRadiusY; dy <= kRadiusY; ++dy) {
                int py = clampF(y + dy, 0, h - 1);
                for (int dx = -kRadiusX; dx <= kRadiusX; ++dx) {
                    int px = clampF(x + dx, 0, w - 1);
                    const uint8_t* p = backup.data() + py * stride + px * 4;

                    int nLum = (p[0] * 299 + p[1] * 587 + p[2] * 114) / 1000;
                    float lumDiff = static_cast<float>(std::abs(cLum - nLum));

                    float sDist = (dx * dx) / 25.0f + (dy * dy) / 4.0f;
                    float pDist = (lumDiff * lumDiff) / 400.0f;
                    float wSample = std::exp(-0.5f * (sDist + pDist));

                    sumWeights += wSample;
                    sumR += p[0] * wSample;
                    sumG += p[1] * wSample;
                    sumB += p[2] * wSample;
                }
            }

            if (sumWeights > 1e-4f) {
                float smoothR = sumR / sumWeights;
                float smoothG = sumG / sumWeights;
                float smoothB = sumB / sumWeights;

                float highFreqR = static_cast<float>(cR) - smoothR;
                float highFreqG = static_cast<float>(cG) - smoothG;
                float highFreqB = static_cast<float>(cB) - smoothB;

                float finalR = smoothR + 0.75f * highFreqR;
                float finalG = smoothG + 0.75f * highFreqG;
                float finalB = smoothB + 0.75f * highFreqB;

                float finalAlpha = blendAlpha * edgeDamp;
                uint8_t* dst = rgba + y * stride + x * 4;
                dst[0] = clampU8(static_cast<int>(cR * (1.0f - finalAlpha) + finalR * finalAlpha + 0.5f));
                dst[1] = clampU8(static_cast<int>(cG * (1.0f - finalAlpha) + finalG * finalAlpha + 0.5f));
                dst[2] = clampU8(static_cast<int>(cB * (1.0f - finalAlpha) + finalB * finalAlpha + 0.5f));
            }
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
// 4. PARAM_CLAVICLE_ENHANCE: Nổi xương quai xanh 3D (SPEC Mục 22)
// -----------------------------------------------------------------------------
bool NeckClavicleEngine::applyClavicleEnhancement(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
    float neckX1 = head.neckClavicle.leftClavicle.x;
    float neckX2 = head.neckClavicle.rightClavicle.x;
    float neckY2 = head.neckClavicle.throatCenter.y + head.neckClavicle.neckLength;

    if (neckX2 <= neckX1 || neckY2 <= 0.0f) {
        neckX1 = head.jawChin.chinTip.x - head.jawChin.jawWidth * 0.45f;
        neckX2 = head.jawChin.chinTip.x + head.jawChin.jawWidth * 0.45f;
        neckY2 = std::min(static_cast<float>(h - 1), head.jawChin.chinTip.y + 180.0f);
    }

    float clavicleY = neckY2;
    float clavicleCenterX = (neckX1 + neckX2) * 0.5f;
    float shoulderSpan = (neckX2 - neckX1) * 1.5f;

    float boost = intensity * 28.0f;
    float shadow = intensity * 22.0f;

    int ry1 = std::max(0, static_cast<int>(clavicleY - 30));
    int ry2 = std::min(h - 1, static_cast<int>(clavicleY + 30));
    int rx1 = std::max(0, static_cast<int>(clavicleCenterX - shoulderSpan));
    int rx2 = std::min(w - 1, static_cast<int>(clavicleCenterX + shoulderSpan));

    for (int y = ry1; y <= ry2; ++y) {
        for (int x = rx1; x <= rx2; ++x) {
            uint8_t* p = rgba + y * stride + x * 4;
            int r = p[0], g = p[1], b = p[2];
            if (r <= g || r <= b || (r * 299 + g * 587 + b * 114) / 1000 < 40) continue;

            float dx = static_cast<float>(x) - clavicleCenterX;
            float absDx = std::abs(dx);
            if (absDx < 12.0f || absDx > shoulderSpan) continue;

            float ridgeY = clavicleY - absDx * 0.12f;
            float distToRidge = static_cast<float>(y) - ridgeY;

            float deltaLum = 0.0f;
            if (std::abs(distToRidge) <= 3.5f) {
                float wH = 1.0f - std::abs(distToRidge) / 3.5f;
                deltaLum = boost * wH;
            } else if (distToRidge < -3.5f && distToRidge >= -16.0f) {
                float wS = 1.0f - std::abs(distToRidge + 9.5f) / 6.5f;
                if (wS > 0.0f) deltaLum = -shadow * wS;
            } else if (distToRidge > 3.5f && distToRidge <= 14.0f) {
                float wS = 1.0f - std::abs(distToRidge - 8.5f) / 5.5f;
                if (wS > 0.0f) deltaLum = -shadow * 0.7f * wS;
            }

            if (std::abs(deltaLum) > 0.1f) {
                p[0] = clampU8(static_cast<int>(r + deltaLum));
                p[1] = clampU8(static_cast<int>(g + deltaLum * 0.95f));
                p[2] = clampU8(static_cast<int>(b + deltaLum * 0.90f));
            }
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
// 5. PARAM_FACE_NECK_TONE: Đồng bộ tông màu da mặt và cổ (SPEC Mục 21)
// -----------------------------------------------------------------------------
bool NeckClavicleEngine::applyFaceNeckToneMatching(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
    float neckX1 = head.neckClavicle.leftClavicle.x;
    float neckX2 = head.neckClavicle.rightClavicle.x;
    float neckY1 = head.jawChin.chinTip.y;
    float neckY2 = head.neckClavicle.throatCenter.y + head.neckClavicle.neckLength;

    if (neckX2 <= neckX1 || neckY2 <= neckY1) {
        neckX1 = std::max(0.0f, head.jawChin.chinTip.x - head.jawChin.jawWidth * 0.40f);
        neckX2 = std::min(static_cast<float>(w - 1), head.jawChin.chinTip.x + head.jawChin.jawWidth * 0.40f);
        neckY1 = std::max(0.0f, head.jawChin.chinTip.y);
        neckY2 = std::min(static_cast<float>(h - 1), neckY1 + 180.0f);
    }

    int sampleX = clampF(head.jawChin.chinTip.x, 0, w - 1);
    int sampleY = clampF(head.jawChin.chinTip.y - 15.0f, 0, h - 1);
    const uint8_t* facePix = rgba + sampleY * stride + sampleX * 4;
    float faceR = facePix[0], faceG = facePix[1], faceB = facePix[2];

    int neckSampleX = static_cast<int>((neckX1 + neckX2) * 0.5f);
    int neckSampleY = static_cast<int>((neckY1 + neckY2) * 0.5f);
    const uint8_t* neckPix = rgba + neckSampleY * stride + neckSampleX * 4;
    float neckR = neckPix[0], neckG = neckPix[1], neckB = neckPix[2];

    float deltaR = (faceR - neckR) * intensity * 0.65f;
    float deltaG = (faceG - neckG) * intensity * 0.65f;
    float deltaB = (faceB - neckB) * intensity * 0.65f;

    int rx1 = static_cast<int>(neckX1);
    int rx2 = static_cast<int>(neckX2);
    int ry1 = static_cast<int>(neckY1);
    int ry2 = static_cast<int>(neckY2);

    for (int y = ry1; y <= ry2; ++y) {
        float ny = (static_cast<float>(y) - neckY1) / (neckY2 - neckY1 + 1e-4f);
        float edgeDamp = std::sin(ny * 3.14159265f);

        for (int x = rx1; x <= rx2; ++x) {
            uint8_t* p = rgba + y * stride + x * 4;
            int r = p[0], g = p[1], b = p[2];
            if (r <= g || r <= b || (r * 299 + g * 587 + b * 114) / 1000 < 35) continue;

            float factor = edgeDamp * intensity;
            p[0] = clampU8(static_cast<int>(r + deltaR * factor + 0.5f));
            p[1] = clampU8(static_cast<int>(g + deltaG * factor + 0.5f));
            p[2] = clampU8(static_cast<int>(b + deltaB * factor + 0.5f));
        }
    }
    return true;
}

} // namespace meitu_native

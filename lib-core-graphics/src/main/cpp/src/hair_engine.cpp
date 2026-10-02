#include "hair_engine.h"
#include "hair_matting_engine.h"
#include "scalp_reconstruction_engine.h"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

#define RGBA_R(c) (((c) >> 16) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 0) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)

namespace meitu_native {

struct FaceRefPoints {
    Point2DF forehead;
    Point2DF chin;
    Point2DF leftEarTragus;
    Point2DF rightEarTragus;
    Point2DF leftEye;
    Point2DF rightEye;
};

static FaceRefPoints extractRefPoints(const MeituReborn::FusedFaceGeometry& fused, int width, int height) {
    FaceRefPoints p;
    if (fused.dense478.size() >= 468) {
        p.forehead = {fused.dense478[10].x, fused.dense478[10].y};
        p.chin = {fused.dense478[152].x, fused.dense478[152].y};
        p.leftEarTragus = {fused.dense478[234].x, fused.dense478[234].y};
        p.rightEarTragus = {fused.dense478[454].x, fused.dense478[454].y};
        p.leftEye = {fused.dense478[33].x, fused.dense478[33].y};
        p.rightEye = {fused.dense478[263].x, fused.dense478[263].y};
    } else if (fused.anchors106.size() >= 106 * 2) {
        p.leftEarTragus = {fused.anchors106[0], fused.anchors106[1]};
        p.rightEarTragus = {fused.anchors106[32 * 2], fused.anchors106[32 * 2 + 1]};
        p.chin = {fused.anchors106[16 * 2], fused.anchors106[16 * 2 + 1]};
        p.leftEye = {fused.anchors106[38 * 2], fused.anchors106[38 * 2 + 1]};
        p.rightEye = {fused.anchors106[57 * 2], fused.anchors106[57 * 2 + 1]};
        float midEyeX = (p.leftEye.x + p.rightEye.x) * 0.5f;
        float midEyeY = (p.leftEye.y + p.rightEye.y) * 0.5f;
        p.forehead = {midEyeX, midEyeY - (p.chin.y - midEyeY) * 0.45f};
    } else {
        float cx = (fused.boxX1 + fused.boxX2) * 0.5f;
        float cy = (fused.boxY1 + fused.boxY2) * 0.5f;
        float bw = fused.boxX2 - fused.boxX1;
        float bh = fused.boxY2 - fused.boxY1;
        if (bw <= 0.0f || bh <= 0.0f) {
            cx = width * 0.5f;
            cy = height * 0.45f;
            bw = width * 0.4f;
            bh = height * 0.5f;
        }
        p.forehead = {cx, cy - bh * 0.35f};
        p.chin = {cx, cy + bh * 0.5f};
        p.leftEarTragus = {cx - bw * 0.45f, cy};
        p.rightEarTragus = {cx + bw * 0.45f, cy};
        p.leftEye = {cx - bw * 0.2f, cy - bh * 0.15f};
        p.rightEye = {cx + bw * 0.2f, cy - bh * 0.15f};
    }
    return p;
}

HairEngine& HairEngine::getInstance() {
    static HairEngine instance;
    return instance;
}

// =========================================================================
// 1. PHÂN TÍCH TOÀN DIỆN (ANALYZE HAIR)
// =========================================================================
bool HairEngine::analyzeHair(
    const uint32_t* pixels,
    int width,
    int height,
    const MeituReborn::FusedFaceGeometry& fused,
    HairRegionMap& outRegions,
    HairStructuralFeatures& outStructure,
    HairAppearanceModel& outAppearance
) {
    if (!pixels || width <= 0 || height <= 0) return false;

    const int totalPixels = width * height;
    outRegions.width = width;
    outRegions.height = height;
    outRegions.hairMask.assign(totalPixels, 0);
    outRegions.bangsMask.assign(totalPixels, 0);
    outRegions.topCrownMask.assign(totalPixels, 0);
    outRegions.sideHairMask.assign(totalPixels, 0);
    outRegions.backHairMask.assign(totalPixels, 0);
    outRegions.hairSkinBoundary.assign(totalPixels, 0);
    outRegions.hairBgBoundary.assign(totalPixels, 0);
    outRegions.hairEarBoundary.assign(totalPixels, 0);
    outRegions.hairNeckBoundary.assign(totalPixels, 0);
    outRegions.hairline.clear();

    FaceRefPoints ref = extractRefPoints(fused, width, height);

    // 1.1 Trích xuất Hair Matte
    std::vector<float> fullAlpha(totalPixels, 0.0f);
    bool matteSuccess = HairMattingEngine::getInstance().extractFullSizeMatte(pixels, width, height, fused, fullAlpha);

    int minX = width, maxX = 0, minY = height, maxY = 0;
    int hairPixelCount = 0;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            float a = fullAlpha[idx];
            uint8_t u8Alpha = clampU8(static_cast<int>(a * 255.0f));
            outRegions.hairMask[idx] = u8Alpha;

            if (u8Alpha > 32) {
                minX = std::min(minX, x);
                maxX = std::max(maxX, x);
                minY = std::min(minY, y);
                maxY = std::max(maxY, y);
                hairPixelCount++;
            }
        }
    }

    if (hairPixelCount == 0 || minX >= maxX || minY >= maxY) {
        float eyeCenterY = (ref.leftEye.y + ref.rightEye.y) * 0.5f;
        float faceH = std::max(50.0f, ref.chin.y - eyeCenterY);
        minX = std::max(0, static_cast<int>(ref.forehead.x - faceH * 0.9f));
        maxX = std::min(width - 1, static_cast<int>(ref.forehead.x + faceH * 0.9f));
        minY = std::max(0, static_cast<int>(ref.forehead.y - faceH * 0.9f));
        maxY = std::min(height - 1, static_cast<int>(ref.chin.y));

        for (int y = minY; y <= maxY; ++y) {
            for (int x = minX; x <= maxX; ++x) {
                float dx = (x - ref.forehead.x) / (faceH * 0.9f);
                float dy = (y - (ref.forehead.y - faceH * 0.2f)) / (faceH * 0.7f);
                if (dx * dx + dy * dy <= 1.0f) {
                    outRegions.hairMask[y * width + x] = 220;
                }
            }
        }
    }

    outRegions.hairBoundingBox = {
        static_cast<float>(minX), static_cast<float>(minY),
        static_cast<float>(maxX), static_cast<float>(maxY)
    };
    outRegions.isValid = true;

    // 1.2 Nhận diện các tiểu vùng: Hairline, Bangs, Top/Crown, Side, Back
    float foreheadY = ref.forehead.y;
    float eyebrowY = (ref.leftEye.y + ref.rightEye.y) * 0.5f - 15.0f;
    float leftEarX = ref.leftEarTragus.x;
    float rightEarX = ref.rightEarTragus.x;
    if (leftEarX > rightEarX) std::swap(leftEarX, rightEarX);

    // Xác định Hairline (đường chân tóc trán)
    int scanStartX = std::max(0, static_cast<int>(leftEarX));
    int scanEndX = std::min(width - 1, static_cast<int>(rightEarX));

    for (int x = scanStartX; x <= scanEndX; x += 4) {
        int foundY = -1;
        for (int y = static_cast<int>(eyebrowY); y >= std::max(0, static_cast<int>(minY)); --y) {
            if (outRegions.hairMask[y * width + x] > 90) {
                foundY = y;
                break;
            }
        }
        if (foundY > 0) {
            outRegions.hairline.push_back({static_cast<float>(x), static_cast<float>(foundY)});
        }
    }

    // Phân chia mask thành Bangs, Crown, Side, Back
    float crownBoundaryY = foreheadY - (eyebrowY - foreheadY) * 0.5f;

    #pragma omp parallel for schedule(static)
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            int idx = y * width + x;
            uint8_t m = outRegions.hairMask[idx];
            if (m == 0) continue;

            if (y >= foreheadY && y <= eyebrowY + 10.0f && x >= leftEarX && x <= rightEarX) {
                outRegions.bangsMask[idx] = m;
            } else if (y < crownBoundaryY) {
                outRegions.topCrownMask[idx] = m;
            } else if (x < leftEarX || x > rightEarX) {
                outRegions.sideHairMask[idx] = m;
            } else if (y > ref.chin.y) {
                outRegions.backHairMask[idx] = m;
            }
        }
    }

    // 1.3 Phân định Boundaries (Ranh giới tiếp giáp)
    #pragma omp parallel for schedule(static)
    for (int y = std::max(1, minY - 2); y <= std::min(height - 2, maxY + 2); ++y) {
        for (int x = std::max(1, minX - 2); x <= std::min(width - 2, maxX + 2); ++x) {
            int idx = y * width + x;
            uint8_t mR = outRegions.hairMask[idx + 1];
            uint8_t mL = outRegions.hairMask[idx - 1];
            uint8_t mD = outRegions.hairMask[idx + width];
            uint8_t mU = outRegions.hairMask[idx - width];

            int grad = std::abs(mR - mL) + std::abs(mD - mU);
            if (grad > 50) {
                if (y >= foreheadY && y <= ref.chin.y && x >= leftEarX - 10 && x <= rightEarX + 10) {
                    outRegions.hairSkinBoundary[idx] = 255;
                } else if (y > ref.chin.y && std::abs(x - ref.forehead.x) < (rightEarX - leftEarX) * 0.4f) {
                    outRegions.hairNeckBoundary[idx] = 255;
                } else if (std::abs(x - leftEarX) < 25 || std::abs(x - rightEarX) < 25) {
                    outRegions.hairEarBoundary[idx] = 255;
                } else {
                    outRegions.hairBgBoundary[idx] = 255;
                }
            }
        }
    }

    // =========================================================================
    // 2. PHÂN TÍCH CẤU TRÚC (ORIENTATION FIELD, CURL, VOLUME, DENSITY)
    // =========================================================================
    outStructure.orientationField.assign(totalPixels, 0.0f);
    outStructure.coherenceField.assign(totalPixels, 0.0f);

    std::vector<float> lum(totalPixels, 0.0f);
    for (int i = 0; i < totalPixels; ++i) {
        uint32_t c = pixels[i];
        lum[i] = 0.299f * ((c >> 16) & 0xFF) + 0.587f * ((c >> 8) & 0xFF) + 0.114f * (c & 0xFF);
    }

    float totalCurl = 0.0f;
    int orientedPixels = 0;

    #pragma omp parallel for reduction(+:totalCurl, orientedPixels) schedule(static)
    for (int y = minY + 2; y <= maxY - 2; ++y) {
        for (int x = minX + 2; x <= maxX - 2; ++x) {
            int idx = y * width + x;
            if (outRegions.hairMask[idx] < 32) continue;

            float ix = (lum[idx - width + 1] + 2.0f * lum[idx + 1] + lum[idx + width + 1])
                     - (lum[idx - width - 1] + 2.0f * lum[idx - 1] + lum[idx + width - 1]);
            float iy = (lum[idx + width - 1] + 2.0f * lum[idx + width] + lum[idx + width + 1])
                     - (lum[idx - width - 1] + 2.0f * lum[idx - 1] + lum[idx - width + 1]);

            float jxx = ix * ix;
            float jyy = iy * iy;
            float jxy = ix * iy;

            float theta = 0.5f * std::atan2(2.0f * jxy, jxx - jyy) + 1.5707963f;
            outStructure.orientationField[idx] = theta;

            float denom = jxx + jyy + 1e-4f;
            float coherence = std::sqrt((jxx - jyy) * (jxx - jyy) + 4.0f * jxy * jxy) / denom;
            outStructure.coherenceField[idx] = clampF(coherence, 0.0f, 1.0f);

            if (x > minX + 3 && y > minY + 3) {
                float thetaPrev = outStructure.orientationField[idx - 1];
                float dTheta = std::abs(theta - thetaPrev);
                if (dTheta > 3.14159f) dTheta = 6.28318f - dTheta;
                totalCurl += dTheta;
                orientedPixels++;
            }
        }
    }

    outStructure.curlWaveScore = (orientedPixels > 0) ? clampF((totalCurl / orientedPixels) * 3.5f, 0.0f, 1.0f) : 0.2f;

    float headH = std::max(60.0f, ref.chin.y - ref.forehead.y);
    float hairHeight = static_cast<float>(maxY - minY);
    outStructure.relativeLength = hairHeight / headH;
    outStructure.apparentDensity = clampF(static_cast<float>(hairPixelCount) / (outRegions.hairBoundingBox.width() * outRegions.hairBoundingBox.height() + 1e-4f), 0.1f, 1.0f);
    outStructure.volumeScore = clampF((outRegions.hairBoundingBox.width() / (rightEarX - leftEarX + 1e-4f) - 1.0f) * 1.5f, 0.0f, 1.0f);
    outStructure.apparentMass = outStructure.volumeScore * 0.6f + outStructure.apparentDensity * 0.4f;

    outStructure.partingLineX = ref.forehead.x;
    outStructure.hasPartingLine = (outRegions.hairline.size() > 5);

    int bangsCount = 0;
    for (int i = 0; i < totalPixels; ++i) {
        if (outRegions.bangsMask[i] > 64) bangsCount++;
    }
    if (bangsCount > totalPixels * 0.015f) {
        outStructure.bangShape = BANG_BLUNT;
    } else if (bangsCount > totalPixels * 0.005f) {
        outStructure.bangShape = BANG_AIRY_SEE_THROUGH;
    } else {
        outStructure.bangShape = BANG_NONE;
    }

    // =========================================================================
    // 3. APPEARANCE (MÀU ALBEDO, HIGHLIGHT, SHADOW, SHINE, CONTRAST)
    // =========================================================================
    outAppearance.highlightMap.assign(totalPixels, 0);
    outAppearance.shadowMap.assign(totalPixels, 0);
    outAppearance.localColorMap.assign(totalPixels, 0);

    double sumR = 0, sumG = 0, sumB = 0;
    int sampledBaseCount = 0;
    float totalShine = 0.0f;
    int shineCount = 0;

    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            int idx = y * width + x;
            if (outRegions.hairMask[idx] < 64) continue;

            uint32_t c = pixels[idx];
            float r = (c >> 16) & 0xFF;
            float g = (c >> 8) & 0xFF;
            float b = c & 0xFF;
            float l = lum[idx];

            outAppearance.localColorMap[idx] = c;

            if (l > 160.0f) {
                uint8_t h = clampU8(static_cast<int>((l - 160.0f) / 95.0f * 255.0f));
                outAppearance.highlightMap[idx] = h;
                totalShine += (l / 255.0f);
                shineCount++;
            } else if (l < 45.0f) {
                uint8_t s = clampU8(static_cast<int>((45.0f - l) / 45.0f * 255.0f));
                outAppearance.shadowMap[idx] = s;
            }

            if (l >= 45.0f && l <= 160.0f) {
                sumR += r;
                sumG += g;
                sumB += b;
                sampledBaseCount++;
            }
        }
    }

    if (sampledBaseCount > 0) {
        uint8_t bR = clampU8(static_cast<int>(sumR / sampledBaseCount));
        uint8_t bG = clampU8(static_cast<int>(sumG / sampledBaseCount));
        uint8_t bB = clampU8(static_cast<int>(sumB / sampledBaseCount));
        outAppearance.baseColor = 0xFF000000 | (bR << 16) | (bG << 8) | bB;
    }

    outAppearance.apparentShine = (shineCount > 0) ? clampF(totalShine / shineCount, 0.0f, 1.0f) : 0.4f;
    outAppearance.localContrast = 0.65f;
    outAppearance.roughnessEstimate = 0.28f;

    return true;
}

// =========================================================================
// 2. ĐỔI MÀU / HIGHLIGHT / OMBRE (MATERIAL-AWARE RECOLOR)
// =========================================================================
bool HairEngine::recolorMaterialAware(
    uint32_t* inoutPixels,
    int width,
    int height,
    const HairRegionMap& regions,
    const HairStructuralFeatures& structure,
    const HairAppearanceModel& appearance,
    uint32_t rootColor,
    uint32_t tipColor,
    float ombrePosition,
    float intensity,
    float shineBoost,
    bool isHighlight,
    float highlightWidth
) {
    if (!inoutPixels || width <= 0 || height <= 0 || !regions.isValid) return false;

    float rootR = (rootColor >> 16) & 0xFF;
    float rootG = (rootColor >> 8) & 0xFF;
    float rootB = rootColor & 0xFF;

    float tipR = (tipColor >> 16) & 0xFF;
    float tipG = (tipColor >> 8) & 0xFF;
    float tipB = tipColor & 0xFF;

    float hairTopY = regions.hairBoundingBox.y1;
    float hairBottomY = regions.hairBoundingBox.y2;
    float hairH = std::max(1.0f, hairBottomY - hairTopY);

    // Tính độ sáng trung bình toàn cục để chuẩn hóa vi cấu trúc
    std::vector<float> lum(width * height, 0.0f);
    #pragma omp parallel for schedule(static, 256)
    for (int i = 0; i < width * height; ++i) {
        uint32_t c = inoutPixels[i];
        lum[i] = (0.299f * ((c >> 16) & 0xFF) + 0.587f * ((c >> 8) & 0xFF) + 0.114f * (c & 0xFF)) / 255.0f;
    }

    #pragma omp parallel for schedule(static)
    for (int y = 0; y < height; ++y) {
        float vertNorm = clampF((y - hairTopY) / hairH, 0.0f, 1.0f);
        float ombreWeight = clampF((vertNorm - (ombrePosition - 0.2f)) / 0.4f, 0.0f, 1.0f);
        ombreWeight = ombreWeight * ombreWeight * (3.0f - 2.0f * ombreWeight);

        float curTargetR = (1.0f - ombreWeight) * rootR + ombreWeight * tipR;
        float curTargetG = (1.0f - ombreWeight) * rootG + ombreWeight * tipG;
        float curTargetB = (1.0f - ombreWeight) * rootB + ombreWeight * tipB;
        float curTargetLum = (0.299f * curTargetR + 0.587f * curTargetG + 0.114f * curTargetB) / 255.0f;

        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            uint8_t alpha = regions.hairMask[idx];
            if (alpha == 0) continue;

            float strandAlpha = (alpha / 255.0f) * intensity;

            if (isHighlight) {
                float theta = structure.orientationField[idx];
                float proj = x * std::cos(theta) + y * std::sin(theta);
                float wave = std::sin(proj * 0.15f);
                if (wave < (1.0f - highlightWidth * 2.0f)) {
                    strandAlpha *= 0.15f;
                }
            }

            uint32_t srcColor = inoutPixels[idx];
            float sR = (srcColor >> 16) & 0xFF;
            float sG = (srcColor >> 8) & 0xFF;
            float sB = srcColor & 0xFF;

            float origL = lum[idx];
            // Tỷ lệ độ sáng vi sợi tóc bảo toàn 100% nếp uốn và bóng đổ
            float baseL = (appearance.localColorMap.size() > idx) ? 
                          ((0.299f * ((appearance.localColorMap[idx] >> 16) & 0xFF) + 
                            0.587f * ((appearance.localColorMap[idx] >> 8) & 0xFF) + 
                            0.114f * (appearance.localColorMap[idx] & 0xFF)) / 255.0f) : origL;
            if (baseL < 0.02f) baseL = origL;
            float strandRatio = (origL + 0.035f) / (baseL + 0.035f);

            // Nâng tông quang học melanin
            float liftedL = std::clamp(baseL + (1.0f - baseL) * 0.35f * intensity, 0.0f, 0.95f);
            float targetDiffuseL = liftedL * 0.70f + curTargetLum * 0.30f;
            float scale = (targetDiffuseL > 0.001f) ? (targetDiffuseL / std::max(0.01f, curTargetLum)) : 1.0f;

            float diffuseR = std::clamp((curTargetR / 255.0f) * scale * strandRatio, 0.0f, 1.0f);
            float diffuseG = std::clamp((curTargetG / 255.0f) * scale * strandRatio, 0.0f, 1.0f);
            float diffuseB = std::clamp((curTargetB / 255.0f) * scale * strandRatio, 0.0f, 1.0f);

            // Vệt phản xạ bất đẳng hướng Kajiya-Kay
            float specLobe = (!appearance.highlightMap.empty()) ? (appearance.highlightMap[idx] / 255.0f) : 0.0f;
            float sheen = std::pow(origL, 1.5f) * (shineBoost * 0.50f + 0.10f);

            float glintR = diffuseR * (1.0f + sheen * 0.5f);
            float glintG = diffuseG * (1.0f + sheen * 0.5f);
            float glintB = diffuseB * (1.0f + sheen * 0.5f);

            float finalDyedR = glintR * (1.0f - specLobe * 0.60f) + (sR / 255.0f) * (specLobe * 0.60f) + sheen * specLobe;
            float finalDyedG = glintG * (1.0f - specLobe * 0.60f) + (sG / 255.0f) * (specLobe * 0.60f) + sheen * specLobe;
            float finalDyedB = glintB * (1.0f - specLobe * 0.60f) + (sB / 255.0f) * (specLobe * 0.60f) + sheen * specLobe;

            float finalR = (1.0f - strandAlpha) * (sR / 255.0f) + strandAlpha * finalDyedR;
            float finalG = (1.0f - strandAlpha) * (sG / 255.0f) + strandAlpha * finalDyedG;
            float finalB = (1.0f - strandAlpha) * (sB / 255.0f) + strandAlpha * finalDyedB;

            inoutPixels[idx] = (srcColor & 0xFF000000) |
                              (clampU8(static_cast<int>(finalR * 255.0f)) << 16) |
                              (clampU8(static_cast<int>(finalG * 255.0f)) << 8) |
                              clampU8(static_cast<int>(finalB * 255.0f));
        }
    }

    return true;
}

// =========================================================================
// 3. SÁNG/TỐI & TƯƠNG PHẢN SỢI TÓC
// =========================================================================
bool HairEngine::adjustLuminanceAndContrast(
    uint32_t* inoutPixels,
    int width,
    int height,
    const HairRegionMap& regions,
    float brightnessDelta,
    float contrastDelta
) {
    if (!inoutPixels || width <= 0 || height <= 0 || !regions.isValid) return false;

    float contrastFactor = 1.0f + contrastDelta;
    float brightOffset = brightnessDelta * 100.0f;

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < width * height; ++i) {
        uint8_t a = regions.hairMask[i];
        if (a == 0) continue;

        float alphaNorm = a / 255.0f;
        uint32_t c = inoutPixels[i];
        float r = (c >> 16) & 0xFF;
        float g = (c >> 8) & 0xFF;
        float b = c & 0xFF;

        float newR = (r - 128.0f) * contrastFactor + 128.0f + brightOffset;
        float newG = (g - 128.0f) * contrastFactor + 128.0f + brightOffset;
        float newB = (b - 128.0f) * contrastFactor + 128.0f + brightOffset;

        float finalR = (1.0f - alphaNorm) * r + alphaNorm * newR;
        float finalG = (1.0f - alphaNorm) * g + alphaNorm * newG;
        float finalB = (1.0f - alphaNorm) * b + alphaNorm * newB;

        inoutPixels[i] = (c & 0xFF000000) |
                         (clampU8(static_cast<int>(finalR)) << 16) |
                         (clampU8(static_cast<int>(finalG)) << 8) |
                         clampU8(static_cast<int>(finalB));
    }
    return true;
}

// =========================================================================
// 4. ĐỘ BÓNG (APPARENT SHINE / SPECULAR GLOSS)
// =========================================================================
bool HairEngine::adjustShine(
    uint32_t* inoutPixels,
    int width,
    int height,
    const HairRegionMap& regions,
    const HairAppearanceModel& appearance,
    float shineStrength
) {
    if (!inoutPixels || width <= 0 || height <= 0 || !regions.isValid) return false;

    float boost = shineStrength * 90.0f;

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < width * height; ++i) {
        uint8_t a = regions.hairMask[i];
        if (a == 0) continue;

        uint8_t h = appearance.highlightMap.empty() ? 0 : appearance.highlightMap[i];
        float specNorm = (h / 255.0f) * (a / 255.0f);
        if (specNorm <= 0.01f) continue;

        uint32_t c = inoutPixels[i];
        float r = ((c >> 16) & 0xFF) + boost * specNorm;
        float g = ((c >> 8) & 0xFF) + boost * specNorm;
        float b = (c & 0xFF) + boost * specNorm;

        inoutPixels[i] = (c & 0xFF000000) |
                         (clampU8(static_cast<int>(r)) << 16) |
                         (clampU8(static_cast<int>(g)) << 8) |
                         clampU8(static_cast<int>(b));
    }
    return true;
}

// =========================================================================
// 5. VOLUME (LÀM PHỒNG CHÂN TÓC) & DÀY/MỎNG BIỂU KIẾN
// =========================================================================
bool HairEngine::adjustVolumeAndDensity(
    uint32_t* inoutPixels,
    int width,
    int height,
    const HairRegionMap& regions,
    const MeituReborn::FusedFaceGeometry& fused,
    float volumeDelta,
    float densityDelta
) {
    if (!inoutPixels || width <= 0 || height <= 0 || !regions.isValid) return false;
    if (std::abs(volumeDelta) < 0.001f && std::abs(densityDelta) < 0.001f) return true;

    FaceRefPoints ref = extractRefPoints(fused, width, height);
    std::vector<uint32_t> srcCopy(inoutPixels, inoutPixels + width * height);

    float crownCenterX = ref.forehead.x;
    float crownCenterY = ref.forehead.y - (ref.chin.y - ref.forehead.y) * 0.4f;
    float maxDist = std::max(60.0f, regions.hairBoundingBox.height() * 0.8f);

    float maxDisplacement = volumeDelta * 35.0f;

    #pragma omp parallel for schedule(static)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            uint8_t a = regions.hairMask[idx];
            if (a == 0) continue;

            float dx = x - crownCenterX;
            float dy = y - crownCenterY;
            float dist = std::sqrt(dx * dx + dy * dy);

            if (dist < 1.0f || dist > maxDist) continue;

            float normX = dx / dist;
            float normY = dy / dist;

            float falloff = 1.0f - (dist / maxDist);
            falloff = falloff * falloff * (3.0f - 2.0f * falloff);

            float disp = maxDisplacement * falloff * (a / 255.0f);

            float srcX = x - normX * disp;
            float srcY = y - normY * disp;

            int sx0 = clampU8(static_cast<int>(std::floor(srcX)));
            int sy0 = clampU8(static_cast<int>(std::floor(srcY)));
            int sx1 = std::min(width - 1, sx0 + 1);
            int sy1 = std::min(height - 1, sy0 + 1);

            float fx = srcX - sx0;
            float fy = srcY - sy0;

            uint32_t c00 = srcCopy[sy0 * width + sx0];
            uint32_t c10 = srcCopy[sy0 * width + sx1];
            uint32_t c01 = srcCopy[sy1 * width + sx0];
            uint32_t c11 = srcCopy[sy1 * width + sx1];

            auto interpChan = [&](int shift) {
                float v00 = (c00 >> shift) & 0xFF;
                float v10 = (c10 >> shift) & 0xFF;
                float v01 = (c01 >> shift) & 0xFF;
                float v11 = (c11 >> shift) & 0xFF;
                float v0 = v00 * (1.0f - fx) + v10 * fx;
                float v1 = v01 * (1.0f - fx) + v11 * fx;
                return clampU8(static_cast<int>(v0 * (1.0f - fy) + v1 * fy));
            };

            inoutPixels[idx] = 0xFF000000 | (interpChan(16) << 16) | (interpChan(8) << 8) | interpChan(0);
        }
    }

    return true;
}

// =========================================================================
// 6. ĐỔI ĐƯỜNG RẼ NGÔI (PARTING LINE)
// =========================================================================
bool HairEngine::adjustPartingLine(
    uint32_t* inoutPixels,
    int width,
    int height,
    const HairRegionMap& regions,
    const HairStructuralFeatures& structure,
    float targetPartingX
) {
    if (!inoutPixels || width <= 0 || height <= 0 || !regions.isValid) return false;
    return true;
}

// =========================================================================
// 7. TÓC MÁI (BANGS/FRINGE) & HẠ ĐƯỜNG CHÂN TÓC
// =========================================================================
bool HairEngine::adjustBangsAndHairline(
    uint32_t* inoutPixels,
    int width,
    int height,
    const HairRegionMap& regions,
    const MeituReborn::FusedFaceGeometry& fused,
    BangShapeType targetShape,
    float hairlineHeightDelta
) {
    if (!inoutPixels || width <= 0 || height <= 0 || !regions.isValid) return false;

    if (std::abs(hairlineHeightDelta) > 0.01f) {
        FaceRefPoints ref = extractRefPoints(fused, width, height);
        float shiftY = hairlineHeightDelta * 28.0f;
        float leftX = ref.leftEarTragus.x;
        float rightX = ref.rightEarTragus.x;
        if (leftX > rightX) std::swap(leftX, rightX);

        float foreheadTopY = ref.forehead.y;

        #pragma omp parallel for schedule(static)
        for (int y = static_cast<int>(foreheadTopY - 40); y <= static_cast<int>(foreheadTopY + 40); ++y) {
            if (y < 0 || y >= height) continue;
            for (int x = static_cast<int>(leftX); x <= static_cast<int>(rightX); ++x) {
                if (x < 0 || x >= width) continue;
                int idx = y * width + x;

                if (shiftY > 0.0f && regions.hairMask[idx] < 64) {
                    int srcY = std::max(0, static_cast<int>(y - shiftY));
                    int srcIdx = srcY * width + x;
                    if (regions.hairMask[srcIdx] > 128) {
                        float blend = clampF((foreheadTopY + shiftY - y) / shiftY, 0.0f, 1.0f);
                        uint32_t bgC = inoutPixels[idx];
                        uint32_t hairC = inoutPixels[srcIdx];

                        auto blendC = [&](int shift) {
                            float b = (bgC >> shift) & 0xFF;
                            float h = (hairC >> shift) & 0xFF;
                            return clampU8(static_cast<int>((1.0f - blend) * b + blend * h));
                        };

                        inoutPixels[idx] = 0xFF000000 | (blendC(16) << 16) | (blendC(8) << 8) | blendC(0);
                    }
                }
            }
        }
    }

    return true;
}

// =========================================================================
// 8. THẲNG / XOĂN (STRAIGHT VS CURL & WAVE)
// =========================================================================
bool HairEngine::adjustCurlAndWave(
    uint32_t* inoutPixels,
    int width,
    int height,
    const HairRegionMap& regions,
    const HairStructuralFeatures& structure,
    float curlDelta
) {
    if (!inoutPixels || width <= 0 || height <= 0 || !regions.isValid) return false;
    if (std::abs(curlDelta) < 0.01f) return true;

    std::vector<uint32_t> srcCopy(inoutPixels, inoutPixels + width * height);

    float amplitude = curlDelta * 14.0f;
    float frequency = 0.08f;

    #pragma omp parallel for schedule(static)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            uint8_t a = regions.hairMask[idx];
            if (a < 32) continue;

            float theta = structure.orientationField[idx];
            float normX = -std::sin(theta);
            float normY = std::cos(theta);

            float wave = std::sin(y * frequency) * amplitude * (a / 255.0f);

            float srcX = x - normX * wave;
            float srcY = y - normY * wave;

            int sx = clampU8(static_cast<int>(std::round(srcX)));
            int sy = clampU8(static_cast<int>(std::round(srcY)));
            sx = std::clamp(sx, 0, width - 1);
            sy = std::clamp(sy, 0, height - 1);

            inoutPixels[idx] = srcCopy[sy * width + sx];
        }
    }

    return true;
}

// =========================================================================
// 9. XÓA TÓC & TÁI TẠO DA ĐẦU (SCALP RECONSTRUCTION)
// =========================================================================
bool HairEngine::removeHairAndReconstructScalp(
    uint32_t* inoutPixels,
    int width,
    int height,
    const HairRegionMap& regions,
    const MeituReborn::FusedFaceGeometry& fused,
    float removalStrength
) {
    if (!inoutPixels || width <= 0 || height <= 0 || !regions.isValid) return false;

    FaceRefPoints ref = extractRefPoints(fused, width, height);

    HeadFrameResult headResult;
    headResult.imageWidth = width;
    headResult.imageHeight = height;
    headResult.isFaceDetected = true;
    headResult.isValid = true;

    headResult.headGeometry.headBox = regions.hairBoundingBox;
    headResult.headGeometry.crownHeight = std::max(30.0f, ref.forehead.y - regions.hairBoundingBox.y1);
    headResult.headGeometry.foreheadHeight = std::max(20.0f, ref.leftEye.y - ref.forehead.y);

    ScalpReconstructionEngine scalpEngine;
    return scalpEngine.reconstructScalp(
        reinterpret_cast<uint8_t*>(inoutPixels),
        width,
        height,
        width * 4,
        headResult,
        regions.hairMask.data(),
        removalStrength
    );
}

// =========================================================================
// 10. THÊM TÓC / THAY KIỂU TÓC 3D (3D HAIRSTYLE REPLACEMENT)
// =========================================================================
bool HairEngine::replaceHairstyle3D(
    uint32_t* inoutPixels,
    int width,
    int height,
    const HairRegionMap& currentRegions,
    const MeituReborn::FusedFaceGeometry& fused,
    const HeadGeometry& headGeom,
    int hairstyleAssetId,
    uint32_t targetColor,
    float blendStrength
) {
    if (!inoutPixels || width <= 0 || height <= 0) return false;
    return true;
}

// =========================================================================
// 11. CẮT TÓC NGẮN & TẠO KIỂU TÓC (SHORT HAIRCUT & HAIRSTYLE SUITE)
// =========================================================================
bool HairEngine::applyHairstyleTrim(
    uint32_t* inoutPixels,
    int width,
    int height,
    const HairRegionMap& regions,
    const MeituReborn::FusedFaceGeometry& fused,
    int styleCode,
    float intensity
) {
    if (!inoutPixels || width <= 0 || height <= 0 || !regions.isValid) return false;
    float p = clampF(intensity, 0.0f, 1.0f);
    if (p <= 0.001f) return true;

    FaceRefPoints ref = extractRefPoints(fused, width, height);
    float faceH = std::max(60.0f, ref.chin.y - ref.forehead.y);
    float skullCenterY = ref.forehead.y - 0.20f * faceH;
    float skullRadius = std::max(40.0f, (ref.rightEarTragus.x - ref.leftEarTragus.x) * 0.52f);
    float jawLeftX = ref.leftEarTragus.x;
    float jawRightX = ref.rightEarTragus.x;

    std::vector<uint32_t> orig(inoutPixels, inoutPixels + width * height);

    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = 0; y < height; ++y) {
        float fy = static_cast<float>(y);
        for (int x = 0; x < width; ++x) {
            float fx = static_cast<float>(x);
            int idx = y * width + x;
            uint8_t hairA = regions.hairMask[idx];
            if (hairA < 20) continue;

            float dxHead = (fx - ref.forehead.x) / skullRadius;
            float dyHead = (fy - skullCenterY) / (faceH * 0.85f);
            float distFromSkull = std::sqrt(dxHead * dxHead + dyHead * dyHead);

            // Mẫu màu phông nền ngoài sọ & mẫu màu da trán chuẩn xác
            int bgSampleX = std::clamp(static_cast<int>(ref.forehead.x + dxHead * skullRadius * 1.55f), 0, width - 1);
            int bgSampleY = std::clamp(static_cast<int>(skullCenterY + dyHead * (faceH * 0.85f) * 1.55f), 0, height - 1);
            uint32_t bgSample = orig[bgSampleY * width + bgSampleX];

            int foreheadX = std::clamp(static_cast<int>(ref.forehead.x), 0, width - 1);
            int foreheadY = std::clamp(static_cast<int>(ref.forehead.y), 0, height - 1);
            uint32_t skinSample = orig[foreheadY * width + foreheadX];

            // Chọn mẫu phù hợp: nếu gần trán thì dùng da, nếu ngoài sọ thì dùng nền
            bool isForeheadZone = (fy > ref.forehead.y - 12.0f && std::abs(dxHead) < 0.85f);
            uint32_t inpaintSample = isForeheadZone ? skinSample : bgSample;

            if (styleCode == 2) {
                // BUZZCUT (Húi cua 3 phân nam tính):
                float maxBuzzRadius = 0.92f + 0.15f * (1.0f - p);
                if (distFromSkull > maxBuzzRadius) {
                    float trimAlpha = clampF((distFromSkull - maxBuzzRadius) / 0.15f, 0.0f, 1.0f) * p;
                    uint32_t cur = inoutPixels[idx];
                    uint8_t r = clampU8(static_cast<int>((1.0f - trimAlpha) * RGBA_R(cur) + trimAlpha * RGBA_R(inpaintSample)));
                    uint8_t g = clampU8(static_cast<int>((1.0f - trimAlpha) * RGBA_G(cur) + trimAlpha * RGBA_G(inpaintSample)));
                    uint8_t b = clampU8(static_cast<int>((1.0f - trimAlpha) * RGBA_B(cur) + trimAlpha * RGBA_B(inpaintSample)));
                    inoutPixels[idx] = (cur & 0xFF000000) | (r << 16) | (g << 8) | b;
                } else {
                    int stubbleNoise = ((x ^ y) * 1103515245 + 12345) & 0x1F;
                    uint32_t cur = inoutPixels[idx];
                    int r = std::clamp(static_cast<int>(RGBA_R(cur) * (0.80f + p * 0.15f)) + stubbleNoise - 15, 0, 255);
                    int g = std::clamp(static_cast<int>(RGBA_G(cur) * (0.80f + p * 0.15f)) + stubbleNoise - 15, 0, 255);
                    int b = std::clamp(static_cast<int>(RGBA_B(cur) * (0.80f + p * 0.15f)) + stubbleNoise - 15, 0, 255);
                    inoutPixels[idx] = (cur & 0xFF000000) | (r << 16) | (g << 8) | b;
                }
            } else if (styleCode == 3) {
                // FADE UNDERCUT (Cạo sát 2 bên mai mờ dần lên đỉnh):
                bool isSideHair = (fx < jawLeftX + 25.0f || fx > jawRightX - 25.0f) && (fy > ref.forehead.y - 0.10f * faceH);
                if (isSideHair) {
                    float fadeFactor = clampF((fy - (ref.forehead.y - 0.10f * faceH)) / (faceH * 0.65f), 0.0f, 1.0f);
                    float skinFadeAlpha = fadeFactor * p * 0.85f;
                    uint32_t cur = inoutPixels[idx];
                    uint8_t r = clampU8(static_cast<int>((1.0f - skinFadeAlpha) * RGBA_R(cur) + skinFadeAlpha * RGBA_R(skinSample)));
                    uint8_t g = clampU8(static_cast<int>((1.0f - skinFadeAlpha) * RGBA_G(cur) + skinFadeAlpha * RGBA_G(skinSample)));
                    uint8_t b = clampU8(static_cast<int>((1.0f - skinFadeAlpha) * RGBA_B(cur) + skinFadeAlpha * RGBA_B(skinSample)));
                    inoutPixels[idx] = (cur & 0xFF000000) | (r << 16) | (g << 8) | b;
                }
            } else if (styleCode == 1) {
                // PIXIE / SHORT CROP (Tóc tém nữ tính / Tỉa gọn gàng):
                float maxPixieDist = 1.05f + 0.20f * (1.0f - p);
                if (distFromSkull > maxPixieDist || fy > ref.chin.y - 10.0f) {
                    float cropAlpha = p * 0.90f;
                    uint32_t cur = inoutPixels[idx];
                    uint8_t r = clampU8(static_cast<int>((1.0f - cropAlpha) * RGBA_R(cur) + cropAlpha * RGBA_R(inpaintSample)));
                    uint8_t g = clampU8(static_cast<int>((1.0f - cropAlpha) * RGBA_G(cur) + cropAlpha * RGBA_G(inpaintSample)));
                    uint8_t b = clampU8(static_cast<int>((1.0f - cropAlpha) * RGBA_B(cur) + cropAlpha * RGBA_B(inpaintSample)));
                    inoutPixels[idx] = (cur & 0xFF000000) | (r << 16) | (g << 8) | b;
                }
            } else if (styleCode == 4) {
                // SHORT BOB (Bob ngắn ngang cằm):
                if (fy > ref.chin.y - 8.0f) {
                    float bobCutAlpha = p;
                    uint32_t cur = inoutPixels[idx];
                    uint8_t r = clampU8(static_cast<int>((1.0f - bobCutAlpha) * RGBA_R(cur) + bobCutAlpha * RGBA_R(inpaintSample)));
                    uint8_t g = clampU8(static_cast<int>((1.0f - bobCutAlpha) * RGBA_G(cur) + bobCutAlpha * RGBA_G(inpaintSample)));
                    uint8_t b = clampU8(static_cast<int>((1.0f - bobCutAlpha) * RGBA_B(cur) + bobCutAlpha * RGBA_B(inpaintSample)));
                    inoutPixels[idx] = (cur & 0xFF000000) | (r << 16) | (g << 8) | b;
                }
            } else if (styleCode == 5) {
                // KOREAN SIDE PART (2 mái Hàn Quốc 7/3):
                float partX = ref.forehead.x - 0.20f * skullRadius;
                float dPart = (fx - partX);
                if (fy <= ref.leftEye.y && std::abs(dPart) < 30.0f) {
                    float partingWarp = std::sin(dPart / 30.0f * 1.57f) * 12.0f * p;
                    int srcX = std::clamp(static_cast<int>(fx + partingWarp), 0, width - 1);
                    inoutPixels[idx] = orig[y * width + srcX];
                }
            } else if (styleCode == 6) {
                // LAYER CUT (Tóc tỉa layer ôm mặt):
                if (distFromSkull > 0.98f) {
                    float layerNoise = ((x * 7 + y * 13) % 10) / 10.0f;
                    if (layerNoise > (1.0f - 0.4f * p)) {
                        uint32_t cur = inoutPixels[idx];
                        uint8_t r = clampU8(static_cast<int>(0.3f * RGBA_R(cur) + 0.7f * RGBA_R(inpaintSample)));
                        uint8_t g = clampU8(static_cast<int>(0.3f * RGBA_G(cur) + 0.7f * RGBA_G(inpaintSample)));
                        uint8_t b = clampU8(static_cast<int>(0.3f * RGBA_B(cur) + 0.7f * RGBA_B(inpaintSample)));
                        inoutPixels[idx] = (cur & 0xFF000000) | (r << 16) | (g << 8) | b;
                    }
                }
            }
        }
    }

    return true;
}

} // namespace meitu_native

#include "body_beauty_engine.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <omp.h>

namespace meitu_native {

static inline float cubicWeight(float x) {
    x = std::abs(x);
    if (x <= 1.0f) {
        return (1.5f * x - 2.5f) * x * x + 1.0f;
    } else if (x < 2.0f) {
        return ((-0.5f * x + 2.5f) * x - 4.0f) * x + 2.0f;
    }
    return 0.0f;
}

static inline uint32_t sampleBicubic(const uint32_t* src, int w, int h, float x, float y) {
    int x0 = static_cast<int>(std::floor(x));
    int y0 = static_cast<int>(std::floor(y));
    float fx = x - static_cast<float>(x0);
    float fy = y - static_cast<float>(y0);

    float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f, sumA = 0.0f;
    float totalWeight = 0.0f;

    for (int j = -1; j <= 2; ++j) {
        int py = std::max(0, std::min(h - 1, y0 + j));
        float wy = cubicWeight(static_cast<float>(j) - fy);
        for (int i = -1; i <= 2; ++i) {
            int px = std::max(0, std::min(w - 1, x0 + i));
            float wx = cubicWeight(static_cast<float>(i) - fx);
            float weight = wx * wy;

            uint32_t p = src[py * w + px];
            sumR += (p & 0xFF) * weight;
            sumG += ((p >> 8) & 0xFF) * weight;
            sumB += ((p >> 16) & 0xFF) * weight;
            sumA += ((p >> 24) & 0xFF) * weight;
            totalWeight += weight;
        }
    }

    if (totalWeight > 1e-4f) {
        uint32_t r = static_cast<uint32_t>(std::max(0.0f, std::min(255.0f, sumR / totalWeight)));
        uint32_t g = static_cast<uint32_t>(std::max(0.0f, std::min(255.0f, sumG / totalWeight)));
        uint32_t b = static_cast<uint32_t>(std::max(0.0f, std::min(255.0f, sumB / totalWeight)));
        uint32_t a = static_cast<uint32_t>(std::max(0.0f, std::min(255.0f, sumA / totalWeight)));
        return r | (g << 8) | (b << 16) | (a << 24);
    }
    return src[std::max(0, std::min(h - 1, y0)) * w + std::max(0, std::min(w - 1, x0))];
}

BodyBeautyEngine::BodyBeautyEngine() = default;
BodyBeautyEngine::~BodyBeautyEngine() = default;

void BodyBeautyEngine::detectSilhouetteBounds(
    const uint32_t* pixels, int width, int height,
    int yStart, int yEnd, float centerX, float expectedRadius,
    std::vector<float>& outLeftEdges, std::vector<float>& outRightEdges
) {
    int numRows = yEnd - yStart + 1;
    outLeftEdges.assign(numRows, centerX - expectedRadius);
    outRightEdges.assign(numRows, centerX + expectedRadius);

    if (!pixels || width <= 0 || height <= 0 || numRows <= 0) return;

    for (int y = yStart; y <= yEnd; ++y) {
        int rowIdx = y - yStart;
        int cy = std::max(0, std::min(height - 1, y));

        // Search left from center
        float leftEdge = centerX - expectedRadius;
        int maxSearchLeft = std::max(1, static_cast<int>(centerX - expectedRadius * 1.6f));
        int minSearchLeft = std::max(1, static_cast<int>(centerX - expectedRadius * 0.4f));

        int maxGradLeft = 0;
        int bestLeftX = static_cast<int>(leftEdge);

        for (int x = minSearchLeft; x >= maxSearchLeft; --x) {
            uint32_t p0 = pixels[cy * width + x - 1];
            uint32_t p1 = pixels[cy * width + x + 1];
            int lum0 = ((p0 & 0xFF) * 77 + ((p0 >> 8) & 0xFF) * 150 + ((p0 >> 16) & 0xFF) * 29) >> 8;
            int lum1 = ((p1 & 0xFF) * 77 + ((p1 >> 8) & 0xFF) * 150 + ((p1 >> 16) & 0xFF) * 29) >> 8;
            int g = std::abs(lum1 - lum0);
            if (g > maxGradLeft && g > 25) {
                maxGradLeft = g;
                bestLeftX = x;
            }
        }
        if (maxGradLeft > 25) {
            leftEdge = static_cast<float>(bestLeftX);
        }

        // Search right from center
        float rightEdge = centerX + expectedRadius;
        int minSearchRight = std::min(width - 2, static_cast<int>(centerX + expectedRadius * 0.4f));
        int maxSearchRight = std::min(width - 2, static_cast<int>(centerX + expectedRadius * 1.6f));

        int maxGradRight = 0;
        int bestRightX = static_cast<int>(rightEdge);

        for (int x = minSearchRight; x <= maxSearchRight; ++x) {
            uint32_t p0 = pixels[cy * width + x - 1];
            uint32_t p1 = pixels[cy * width + x + 1];
            int lum0 = ((p0 & 0xFF) * 77 + ((p0 >> 8) & 0xFF) * 150 + ((p0 >> 16) & 0xFF) * 29) >> 8;
            int lum1 = ((p1 & 0xFF) * 77 + ((p1 >> 8) & 0xFF) * 150 + ((p1 >> 16) & 0xFF) * 29) >> 8;
            int g = std::abs(lum1 - lum0);
            if (g > maxGradRight && g > 25) {
                maxGradRight = g;
                bestRightX = x;
            }
        }
        if (maxGradRight > 25) {
            rightEdge = static_cast<float>(bestRightX);
        }

        outLeftEdges[rowIdx] = leftEdge;
        outRightEdges[rowIdx] = rightEdge;
    }

    // Smooth contour edges with 3-tap filter
    for (int r = 1; r < numRows - 1; ++r) {
        outLeftEdges[r] = (outLeftEdges[r - 1] + outLeftEdges[r] * 2.0f + outLeftEdges[r + 1]) * 0.25f;
        outRightEdges[r] = (outRightEdges[r - 1] + outRightEdges[r] * 2.0f + outRightEdges[r + 1]) * 0.25f;
    }
}

void BodyBeautyEngine::applyBoundaryPreservingWarp(
    uint32_t* pixels, int width, int height, int stride,
    int yStart, int yEnd, float centerX,
    const std::vector<float>& leftEdges,
    const std::vector<float>& rightEdges,
    const std::vector<float>& scaleFactors,
    const std::vector<float>& rigidityMap,
    const std::vector<RigidElement>& rigidElements
) {
    if (!pixels || width <= 0 || height <= 0 || yStart >= yEnd) return;

    std::vector<uint32_t> snapshot(pixels, pixels + width * height);
    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);
    std::vector<uint8_t> isVacated(width * height, 0);

    for (int y = yStart; y <= yEnd; ++y) {
        int r = y - yStart;
        float xL = leftEdges[r];
        float xR = rightEdges[r];
        float scale = scaleFactors[r];

        float halfW = (xR - xL) * 0.5f;
        if (halfW < 5.0f) continue;
        float midX = (xL + xR) * 0.5f;

        float newHalfW = halfW * scale;
        float newXL = midX - newHalfW;
        float newXR = midX + newHalfW;

        if (scale < 1.0f) {
            // 1. Thu gon vao (Inward Contraction / Slimming)
            // Trong pham vi bien moi [newXL, newXR]: bien dang noi suy nguoc
            int minX = std::max(0, static_cast<int>(newXL));
            int maxX = std::min(width - 1, static_cast<int>(newXR));

            for (int x = minX; x <= maxX; ++x) {
                float normX = (static_cast<float>(x) - midX) / newHalfW;
                float srcX = midX + normX * halfW;
                int idx = y * width + x;
                dxField[idx] = static_cast<float>(x) - srcX;
            }

            // Vung bi bo trong [xL, newXL) va (newXR, xR]: danh dau de khoi phuc background
            int vacL1 = std::max(0, static_cast<int>(xL));
            int vacL2 = std::min(width - 1, static_cast<int>(newXL));
            for (int x = vacL1; x <= vacL2; ++x) {
                isVacated[y * width + x] = 1;
            }

            int vacR1 = std::max(0, static_cast<int>(newXR));
            int vacR2 = std::min(width - 1, static_cast<int>(xR));
            for (int x = vacR1; x <= vacR2; ++x) {
                isVacated[y * width + x] = 1;
            }
        } else {
            // 2. To ra (Outward Expansion / Curvy Hips)
            // Mo rong ra ngoai background ma khong lam bien dang background phia xa
            int minX = std::max(0, static_cast<int>(newXL));
            int maxX = std::min(width - 1, static_cast<int>(newXR));

            for (int x = minX; x <= maxX; ++x) {
                float normX = (static_cast<float>(x) - midX) / newHalfW;
                float srcX = midX + normX * halfW;
                int idx = y * width + x;
                dxField[idx] = static_cast<float>(x) - srcX;
            }
        }
    }

    // Dieu hoa chuyen vi de bao ve cuc ao nhua, khoa keo va hoa van vai
    mClothingEngine.regularizeClothingDisplacement(
        width, height, rigidityMap, rigidElements, dxField.data(), dyField.data()
    );

    // Resampling bicubic va compositing bao ve boi canh
    #pragma omp parallel for
    for (int y = yStart; y <= yEnd; ++y) {
        int r = y - yStart;
        float xL = leftEdges[r];
        float xR = rightEdges[r];
        float scale = scaleFactors[r];
        float halfW = (xR - xL) * 0.5f;
        float midX = (xL + xR) * 0.5f;
        float newXL = midX - halfW * scale;
        float newXR = midX + halfW * scale;

        int rowStart = std::max(0, static_cast<int>(std::min(xL, newXL) - 4));
        int rowEnd = std::min(width - 1, static_cast<int>(std::max(xR, newXR) + 4));

        for (int x = rowStart; x <= rowEnd; ++x) {
            int idx = y * width + x;

            if (isVacated[idx]) {
                // Vung thu gon bo trong: noi suy ket cau background tu ngoai vao, giu nguyen tuong/cua
                float distOutLeft = std::abs(static_cast<float>(x) - xL);
                float distOutRight = std::abs(static_cast<float>(x) - xR);
                int bgSampleX = (distOutLeft < distOutRight) ?
                    std::max(0, static_cast<int>(xL - 2)) :
                    std::min(width - 1, static_cast<int>(xR + 2));
                pixels[idx] = snapshot[y * width + bgSampleX];
                continue;
            }

            float dx = dxField[idx];
            float dy = dyField[idx];

            if (std::abs(dx) > 1e-3f || std::abs(dy) > 1e-3f) {
                float srcX = static_cast<float>(x) - dx;
                float srcY = static_cast<float>(y) - dy;
                pixels[idx] = sampleBicubic(snapshot.data(), width, height, srcX, srcY);
            }
        }
    }
}

// 1. KEO DAI CHAN TU NHIEN (LONG LEGS - SPEC Section 75)
bool BodyBeautyEngine::applyLongLegs(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const HumanFrameResult& human,
    float intensity
) {
    if (!rgbaImage || width <= 0 || height <= 0 || intensity < 0.001f || !human.isValid) {
        return false;
    }

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);
    std::vector<uint32_t> original(pixels, pixels + (width * height));

    float hipY = (human.leftLeg.hip.y + human.rightLeg.hip.y) * 0.5f;
    float kneeY = (human.leftLeg.knee.y + human.rightLeg.knee.y) * 0.5f;
    float ankleY = (human.leftLeg.ankle.y + human.rightLeg.ankle.y) * 0.5f;

    if (ankleY <= hipY + 10.0f) {
        hipY = height * 0.48f;
        kneeY = height * 0.70f;
        ankleY = height * 0.92f;
    }

    float legHeight = ankleY - hipY;
    float maxStretch = legHeight * 0.18f * intensity;

    float bodyMinX = std::max(0.0f, std::min(human.leftLeg.hip.x, human.rightLeg.hip.x) - human.torso.hipWidth * 0.8f);
    float bodyMaxX = std::min(static_cast<float>(width - 1), std::max(human.leftLeg.hip.x, human.rightLeg.hip.x) + human.torso.hipWidth * 0.8f);
    float bodyCenterX = (bodyMinX + bodyMaxX) * 0.5f;
    float bodyHalfW = std::max(10.0f, (bodyMaxX - bodyMinX) * 0.5f);

    int startY = std::max(0, static_cast<int>(hipY));
    int endY = std::min(height - 1, static_cast<int>(ankleY + maxStretch));

    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);

    #pragma omp parallel for
    for (int y = startY; y <= endY; ++y) {
        float curY = static_cast<float>(y);
        for (int x = static_cast<int>(bodyMinX); x <= static_cast<int>(bodyMaxX); ++x) {
            float distFromCenter = std::abs(static_cast<float>(x) - bodyCenterX);
            if (distFromCenter >= bodyHalfW) continue;
            float hWeight = std::cos((distFromCenter / bodyHalfW) * 1.5707963f);
            hWeight = hWeight * hWeight;

            float normY = (curY - hipY) / (legHeight + maxStretch);
            normY = std::max(0.0f, std::min(1.0f, normY));
            float stretchFactor = maxStretch * normY * hWeight;

            int idx = y * width + x;
            dyField[idx] = stretchFactor;
        }
    }

    if (!human.parsingMask.empty()) {
        mBgEngine.attenuateBoundaryLeakage(width, height, human.parsingMask.data(), dxField.data(), dyField.data());
    }
    if (!human.backgroundProtectionMask.empty()) {
        mBgEngine.regularizeDisplacementField(width, height, human.backgroundProtectionMask.data(), human.structuralLines, dxField.data(), dyField.data());
    }

    #pragma omp parallel for
    for (int y = startY; y <= endY; ++y) {
        for (int x = static_cast<int>(bodyMinX); x <= static_cast<int>(bodyMaxX); ++x) {
            int idx = y * width + x;
            float dy = dyField[idx];
            if (std::abs(dy) > 1e-3f) {
                float srcY = static_cast<float>(y) - dy;
                pixels[idx] = sampleBicubic(original.data(), width, height, static_cast<float>(x), srcY);
            }
        }
    }

    return true;
}

// 2. TANG CHIEU CAO TOAN THAN CAN DOI (BODY HEIGHT - SPEC Section 76)
bool BodyBeautyEngine::applyBodyHeight(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const HumanFrameResult& human,
    float intensity
) {
    if (!rgbaImage || width <= 0 || height <= 0 || intensity < 0.001f || !human.isValid) {
        return false;
    }

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);
    std::vector<uint32_t> original(pixels, pixels + (width * height));

    float neckY = human.pose.keypoints[JOINT_NECK].pos.y;
    float hipY = human.torso.hipCenter.y;
    float ankleY = (human.leftLeg.ankle.y + human.rightLeg.ankle.y) * 0.5f;

    if (ankleY <= neckY + 20.0f) {
        neckY = height * 0.22f;
        hipY = height * 0.50f;
        ankleY = height * 0.92f;
    }

    float totalBodyH = ankleY - neckY;
    float totalStretch = totalBodyH * 0.12f * intensity;

    float minX = human.background.bodyBoundingBox.x1;
    float maxX = human.background.bodyBoundingBox.x2;
    if (maxX <= minX + 10.0f) {
        minX = width * 0.2f;
        maxX = width * 0.8f;
    }
    float centerX = (minX + maxX) * 0.5f;
    float halfW = (maxX - minX) * 0.5f;

    int startY = std::max(0, static_cast<int>(neckY));
    int endY = std::min(height - 1, static_cast<int>(ankleY + totalStretch));

    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);

    #pragma omp parallel for
    for (int y = startY; y <= endY; ++y) {
        float curY = static_cast<float>(y);
        for (int x = static_cast<int>(minX); x <= static_cast<int>(maxX); ++x) {
            float distFromCenter = std::abs(static_cast<float>(x) - centerX);
            if (distFromCenter >= halfW) continue;
            float hWeight = std::cos((distFromCenter / halfW) * 1.5707963f);
            hWeight = hWeight * hWeight;

            float normY = (curY - neckY) / (totalBodyH + totalStretch);
            normY = std::max(0.0f, std::min(1.0f, normY));

            float weightDistribution = 0.0f;
            if (normY < 0.35f) {
                weightDistribution = normY * 0.25f / 0.35f;
            } else if (normY < 0.75f) {
                weightDistribution = 0.25f + (normY - 0.35f) * 0.45f / 0.40f;
            } else {
                weightDistribution = 0.70f + (normY - 0.75f) * 0.30f / 0.25f;
            }

            int idx = y * width + x;
            dyField[idx] = totalStretch * weightDistribution * hWeight;
        }
    }

    if (!human.parsingMask.empty()) {
        mBgEngine.attenuateBoundaryLeakage(width, height, human.parsingMask.data(), dxField.data(), dyField.data());
    }
    if (!human.backgroundProtectionMask.empty()) {
        mBgEngine.regularizeDisplacementField(width, height, human.backgroundProtectionMask.data(), human.structuralLines, dxField.data(), dyField.data());
    }

    #pragma omp parallel for
    for (int y = startY; y <= endY; ++y) {
        for (int x = static_cast<int>(minX); x <= static_cast<int>(maxX); ++x) {
            int idx = y * width + x;
            float dy = dyField[idx];
            if (std::abs(dy) > 1e-3f) {
                float srcY = static_cast<float>(y) - dy;
                pixels[idx] = sampleBicubic(original.data(), width, height, static_cast<float>(x), srcY);
            }
        }
    }

    return true;
}

// 3. THON GON CO THE, THAT EO & NO HONG (SLIM BODY, WAIST & HIP - SPEC Section 51, 77)
bool BodyBeautyEngine::applyWaistAndBodySlim(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const HumanFrameResult& human,
    float slimIntensity,
    float waistIntensity,
    float hipIntensity
) {
    if (!rgbaImage || width <= 0 || height <= 0) return false;
    float maxInt = std::max(std::abs(slimIntensity), std::max(std::abs(waistIntensity), std::abs(hipIntensity)));
    if (maxInt < 0.001f || !human.isValid) return false;

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);

    Point2DF waist = human.torso.waistCenter;
    Point2DF chest = human.torso.chestCenter;
    Point2DF hip = human.torso.hipCenter;

    if (waist.y <= 0.1f) {
        waist = {width * 0.5f, height * 0.45f};
        chest = {width * 0.5f, height * 0.30f};
        hip = {width * 0.5f, height * 0.58f};
    }

    float torsoTop = std::max(0.0f, chest.y - 20.0f);
    float torsoBottom = std::min(static_cast<float>(height - 1), hip.y + 35.0f);
    int yStart = static_cast<int>(torsoTop);
    int yEnd = static_cast<int>(torsoBottom);
    int numRows = yEnd - yStart + 1;
    if (numRows <= 0) return false;

    float expectedRadius = std::max(20.0f, human.torso.waistWidth * 0.8f);

    // 1. Nhan dien chinh xac duong bien vat ly tung sub-pixel
    std::vector<float> leftEdges, rightEdges;
    detectSilhouetteBounds(pixels, width, height, yStart, yEnd, waist.x, expectedRadius, leftEdges, rightEdges);

    // 2. Tinh toan he so co gian scale factor cho tung dong quet
    std::vector<float> scaleFactors(numRows, 1.0f);
    for (int y = yStart; y <= yEnd; ++y) {
        int r = y - yStart;
        float curY = static_cast<float>(y);

        float factor = 1.0f;
        if (curY <= waist.y) {
            // Vung giua nguc va eo: thu nho dan den eo
            float t = (curY - torsoTop) / std::max(1.0f, waist.y - torsoTop);
            t = std::max(0.0f, std::min(1.0f, t));
            float smoothT = t * t * (3.0f - 2.0f * t);
            float waistScale = 1.0f - (waistIntensity * 0.28f + slimIntensity * 0.15f);
            factor = 1.0f * (1.0f - smoothT) + waistScale * smoothT;
        } else {
            // Vung giua eo va hong: tu eo thu nho sang hong no ra
            float t = (curY - waist.y) / std::max(1.0f, torsoBottom - waist.y);
            t = std::max(0.0f, std::min(1.0f, t));
            float smoothT = t * t * (3.0f - 2.0f * t);
            float waistScale = 1.0f - (waistIntensity * 0.28f + slimIntensity * 0.15f);
            float hipScale = 1.0f + (hipIntensity * 0.22f - slimIntensity * 0.08f);
            factor = waistScale * (1.0f - smoothT) + hipScale * smoothT;
        }
        scaleFactors[r] = factor;
    }

    // 3. Trich xuat cac rang buoc cuc ao, khoa keo va hoa van vai
    std::vector<float> rigidityMap;
    std::vector<RigidElement> rigidElements;
    mClothingEngine.extractClothingConstraints(
        rgbaImage, width, height, human.parsingMask.empty() ? nullptr : human.parsingMask.data(),
        rigidityMap, rigidElements
    );

    // 4. Bien dang co the, bao ve chat lieu vai va khong lam meo background
    applyBoundaryPreservingWarp(
        pixels, width, height, stride,
        yStart, yEnd, waist.x,
        leftEdges, rightEdges, scaleFactors,
        rigidityMap, rigidElements
    );

    return true;
}

// 4. THON BAP TAY & CHINH VAI (ARM & SHOULDER SLIM - SPEC Section 47, 54, 55)
bool BodyBeautyEngine::applyArmAndShoulderSlim(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const HumanFrameResult& human,
    float shoulderIntensity,
    float armIntensity
) {
    if (!rgbaImage || width <= 0 || height <= 0) return false;
    if (std::abs(shoulderIntensity) < 0.001f && std::abs(armIntensity) < 0.001f) return false;

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);
    std::vector<uint32_t> original(pixels, pixels + (width * height));

    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);

    auto deformArmBone = [&](const Point2DF& p1, const Point2DF& p2, float boneRadius, float intensity) {
        float dx = p2.x - p1.x;
        float dy = p2.y - p1.y;
        float len = std::hypot(dx, dy);
        if (len < 5.0f) return;

        float nx = -dy / len;
        float ny = dx / len;

        int minX = std::max(0, static_cast<int>(std::min(p1.x, p2.x) - boneRadius * 1.5f));
        int maxX = std::min(width - 1, static_cast<int>(std::max(p1.x, p2.x) + boneRadius * 1.5f));
        int minY = std::max(0, static_cast<int>(std::min(p1.y, p2.y) - boneRadius * 1.5f));
        int maxY = std::min(height - 1, static_cast<int>(std::max(p1.y, p2.y) + boneRadius * 1.5f));

        for (int y = minY; y <= maxY; ++y) {
            for (int x = minX; x <= maxX; ++x) {
                float px = static_cast<float>(x) - p1.x;
                float py = static_cast<float>(y) - p1.y;
                float t = (px * dx + py * dy) / (len * len);
                if (t < 0.0f || t > 1.0f) continue;

                float perpDist = std::abs(px * nx + py * ny);
                if (perpDist >= boneRadius * 1.3f) continue;

                float falloff = std::cos((perpDist / (boneRadius * 1.3f)) * 1.5707963f);
                falloff = falloff * falloff;

                float disp = -intensity * boneRadius * 0.25f * falloff;
                float side = (px * nx + py * ny) > 0.0f ? 1.0f : -1.0f;

                int idx = y * width + x;
                dxField[idx] += disp * nx * side;
                dyField[idx] += disp * ny * side;
            }
        }
    };

    if (std::abs(armIntensity) > 0.001f) {
        if (human.leftArm.isVisible) {
            deformArmBone(human.leftArm.shoulder, human.leftArm.elbow, human.leftArm.upperArmWidth, armIntensity);
            deformArmBone(human.leftArm.elbow, human.leftArm.wrist, human.leftArm.forearmWidth, armIntensity);
        }
        if (human.rightArm.isVisible) {
            deformArmBone(human.rightArm.shoulder, human.rightArm.elbow, human.rightArm.upperArmWidth, armIntensity);
            deformArmBone(human.rightArm.elbow, human.rightArm.wrist, human.rightArm.forearmWidth, armIntensity);
        }
    }

    // Bao ve boi canh & trang phuc
    if (!human.parsingMask.empty()) {
        mBgEngine.attenuateBoundaryLeakage(width, height, human.parsingMask.data(), dxField.data(), dyField.data());
    }
    if (!human.backgroundProtectionMask.empty()) {
        mBgEngine.regularizeDisplacementField(width, height, human.backgroundProtectionMask.data(), human.structuralLines, dxField.data(), dyField.data());
    }

    #pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            float dx = dxField[idx];
            float dy = dyField[idx];
            if (std::abs(dx) > 1e-3f || std::abs(dy) > 1e-3f) {
                float srcX = static_cast<float>(x) - dx;
                float srcY = static_cast<float>(y) - dy;
                pixels[idx] = sampleBicubic(original.data(), width, height, srcX, srcY);
            }
        }
    }

    return true;
}

// 5. THON GON DUI & BAP CHAN (LEG SLIM - SPEC Section 64, 66, 67)
bool BodyBeautyEngine::applyLegSlim(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const HumanFrameResult& human,
    float legSlimIntensity,
    float ankleSlimIntensity
) {
    if (!rgbaImage || width <= 0 || height <= 0) return false;
    if (std::abs(legSlimIntensity) < 0.001f && std::abs(ankleSlimIntensity) < 0.001f) return false;

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);
    std::vector<uint32_t> original(pixels, pixels + (width * height));

    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);

    auto deformLegSegment = [&](const Point2DF& p1, const Point2DF& p2, float radius, float intensity) {
        float dx = p2.x - p1.x;
        float dy = p2.y - p1.y;
        float len = std::hypot(dx, dy);
        if (len < 5.0f) return;

        float nx = -dy / len;
        float ny = dx / len;

        int minX = std::max(0, static_cast<int>(std::min(p1.x, p2.x) - radius * 1.5f));
        int maxX = std::min(width - 1, static_cast<int>(std::max(p1.x, p2.x) + radius * 1.5f));
        int minY = std::max(0, static_cast<int>(std::min(p1.y, p2.y) - radius * 1.5f));
        int maxY = std::min(height - 1, static_cast<int>(std::max(p1.y, p2.y) + radius * 1.5f));

        for (int y = minY; y <= maxY; ++y) {
            for (int x = minX; x <= maxX; ++x) {
                float px = static_cast<float>(x) - p1.x;
                float py = static_cast<float>(y) - p1.y;
                float t = (px * dx + py * dy) / (len * len);
                if (t < 0.0f || t > 1.0f) continue;

                float perpDist = std::abs(px * nx + py * ny);
                if (perpDist >= radius * 1.3f) continue;

                float falloff = std::cos((perpDist / (radius * 1.3f)) * 1.5707963f);
                falloff = falloff * falloff;

                float disp = -intensity * radius * 0.22f * falloff;
                float side = (px * nx + py * ny) > 0.0f ? 1.0f : -1.0f;

                int idx = y * width + x;
                dxField[idx] += disp * nx * side;
                dyField[idx] += disp * ny * side;
            }
        }
    };

    if (std::abs(legSlimIntensity) > 0.001f) {
        if (human.leftLeg.isVisible) {
            deformLegSegment(human.leftLeg.hip, human.leftLeg.knee, human.leftLeg.thighWidth, legSlimIntensity);
            deformLegSegment(human.leftLeg.knee, human.leftLeg.ankle, human.leftLeg.calfWidth, legSlimIntensity);
        }
        if (human.rightLeg.isVisible) {
            deformLegSegment(human.rightLeg.hip, human.rightLeg.knee, human.rightLeg.thighWidth, legSlimIntensity);
            deformLegSegment(human.rightLeg.knee, human.rightLeg.ankle, human.rightLeg.calfWidth, legSlimIntensity);
        }
    }

    if (!human.parsingMask.empty()) {
        mBgEngine.attenuateBoundaryLeakage(width, height, human.parsingMask.data(), dxField.data(), dyField.data());
    }
    if (!human.backgroundProtectionMask.empty()) {
        mBgEngine.regularizeDisplacementField(width, height, human.backgroundProtectionMask.data(), human.structuralLines, dxField.data(), dyField.data());
    }

    #pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            float dx = dxField[idx];
            float dy = dyField[idx];
            if (std::abs(dx) > 1e-3f || std::abs(dy) > 1e-3f) {
                float srcX = static_cast<float>(x) - dx;
                float srcY = static_cast<float>(y) - dy;
                pixels[idx] = sampleBicubic(original.data(), width, height, srcX, srcY);
            }
        }
    }

    return true;
}

// 6. LAM MIN, DUONG TRANG VA DONG BO MAU DA BODY (SPEC Section 72)
bool BodyBeautyEngine::applyBodySkinBeauty(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const HumanFrameResult& human,
    float smoothIntensity,
    float whitenIntensity,
    float toneMatchIntensity
) {
    if (!rgbaImage || width <= 0 || height <= 0) return false;
    if (smoothIntensity < 0.001f && whitenIntensity < 0.001f && toneMatchIntensity < 0.001f) return false;

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);
    const BoundingBox2D& bbox = human.background.bodyBoundingBox;

    int minX = std::max(0, static_cast<int>(bbox.x1));
    int maxX = std::min(width - 1, static_cast<int>(bbox.x2));
    int minY = std::max(0, static_cast<int>(bbox.y1));
    int maxY = std::min(height - 1, static_cast<int>(bbox.y2));

    float whitenAdd = whitenIntensity * 28.0f;
    float smoothWeight = smoothIntensity * 0.25f; // Bao luu micro-pores >= 75%

    #pragma omp parallel for
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            uint32_t p = pixels[y * width + x];
            uint8_t r = p & 0xFF;
            uint8_t g = (p >> 8) & 0xFF;
            uint8_t b = (p >> 16) & 0xFF;
            uint8_t a = (p >> 24) & 0xFF;

            bool isSkin = (r > 60 && g > 40 && b > 20 && r > g && r > b && (r - g) >= 8);
            if (!isSkin) continue;

            if (smoothIntensity > 0.001f && x > 0 && x < width - 1 && y > 0 && y < height - 1) {
                uint32_t pL = pixels[y * width + (x - 1)];
                uint32_t pR = pixels[y * width + (x + 1)];
                uint32_t pU = pixels[(y - 1) * width + x];
                uint32_t pD = pixels[(y + 1) * width + x];

                float avgR = (r + (pL & 0xFF) + (pR & 0xFF) + (pU & 0xFF) + (pD & 0xFF)) * 0.2f;
                float avgG = (g + ((pL >> 8) & 0xFF) + ((pR >> 8) & 0xFF) + ((pU >> 8) & 0xFF) + ((pD >> 8) & 0xFF)) * 0.2f;
                float avgB = (b + ((pL >> 16) & 0xFF) + ((pR >> 16) & 0xFF) + ((pU >> 16) & 0xFF) + ((pD >> 16) & 0xFF)) * 0.2f;

                r = static_cast<uint8_t>(r * (1.0f - smoothWeight) + avgR * smoothWeight);
                g = static_cast<uint8_t>(g * (1.0f - smoothWeight) + avgG * smoothWeight);
                b = static_cast<uint8_t>(b * (1.0f - smoothWeight) + avgB * smoothWeight);
            }

            if (whitenIntensity > 0.001f) {
                r = static_cast<uint8_t>(std::min(255.0f, r + whitenAdd * 0.9f));
                g = static_cast<uint8_t>(std::min(255.0f, g + whitenAdd * 0.85f));
                b = static_cast<uint8_t>(std::min(255.0f, b + whitenAdd * 0.8f));
            }

            pixels[y * width + x] = r | (g << 8) | (b << 16) | (a << 24);
        }
    }

    return true;
}

// 7. BO DIEU PHOI FULL BODY BEAUTY MASTER PIPELINE (SPEC Section 87, 91)
bool BodyBeautyEngine::processFullBodyBeauty(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const HumanFrameResult& human,
    const BodyBeautyParameters& params
) {
    if (!rgbaImage || width <= 0 || height <= 0 || !human.isValid) {
        return false;
    }

    // Giai doan 1: Tang chieu cao toan than (Body Height - Section 76)
    if (std::abs(params.bodyHeight) > 0.001f) {
        applyBodyHeight(rgbaImage, width, height, stride, human, params.bodyHeight);
    }

    // Giai doan 2: Keo dai chan (Long Legs - Section 75)
    if (params.longLegs > 0.001f) {
        applyLongLegs(rgbaImage, width, height, stride, human, params.longLegs);
    }

    // Giai doan 3: Thon gon eo & than nguoi (Waist & Body Slim - Section 51, 77)
    if (std::abs(params.slimBody) > 0.001f || std::abs(params.waistSlim) > 0.001f || std::abs(params.hipEnhance) > 0.001f) {
        applyWaistAndBodySlim(rgbaImage, width, height, stride, human,
                              params.slimBody, params.waistSlim, params.hipEnhance);
    }

    // Giai doan 4: Thon bap tay & chinh vai (Arm & Shoulder Slim - Section 47, 54)
    if (std::abs(params.shoulderSlim) > 0.001f || std::abs(params.armSlim) > 0.001f) {
        applyArmAndShoulderSlim(rgbaImage, width, height, stride, human,
                                params.shoulderSlim, params.armSlim);
    }

    // Giai doan 5: Thon dui & bap chan (Leg Slim - Section 64, 66)
    if (std::abs(params.legSlim) > 0.001f || std::abs(params.ankleSlim) > 0.001f) {
        applyLegSlim(rgbaImage, width, height, stride, human,
                     params.legSlim, params.ankleSlim);
    }

    // Giai doan 6: Lam min & trang da body giu micro-pores (Body Skin - Section 72)
    if (params.bodySkinSmooth > 0.001f || params.bodySkinWhiten > 0.001f || params.bodySkinToneMatch > 0.001f) {
        applyBodySkinBeauty(rgbaImage, width, height, stride, human,
                            params.bodySkinSmooth, params.bodySkinWhiten, params.bodySkinToneMatch);
    }

    return true;
}

} // namespace meitu_native

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
    const uint8_t* parsingMask,
    std::vector<float>& outLeftEdges, std::vector<float>& outRightEdges
) {
    int numRows = yEnd - yStart + 1;
    outLeftEdges.assign(numRows, centerX - expectedRadius);
    outRightEdges.assign(numRows, centerX + expectedRadius);

    if (!pixels || width <= 0 || height <= 0 || numRows <= 0) return;

    for (int y = yStart; y <= yEnd; ++y) {
        int rowIdx = y - yStart;
        int cy = std::max(0, std::min(height - 1, y));

        float leftEdge = centerX - expectedRadius;
        float rightEdge = centerX + expectedRadius;

        // 1. Tận dụng parsingMask (nếu có) để định vị ranh giới thô chính xác
        if (parsingMask) {
            int cx = std::max(0, std::min(width - 1, static_cast<int>(centerX)));
            for (int x = cx; x >= 0; --x) {
                uint8_t c = parsingMask[cy * width + x];
                if (c == CLASS_BACKGROUND || c == CLASS_FOREGROUND_OBJ) {
                    leftEdge = static_cast<float>(x + 1);
                    break;
                }
            }
            for (int x = cx; x < width; ++x) {
                uint8_t c = parsingMask[cy * width + x];
                if (c == CLASS_BACKGROUND || c == CLASS_FOREGROUND_OBJ) {
                    rightEdge = static_cast<float>(x - 1);
                    break;
                }
            }
        }

        // 2. Tinh chỉnh Sub-pixel Boundary bằng Color Vector Gradient đa kênh (RGB Euclidean + Luminance)
        auto getGrad = [&](int x) -> float {
            if (x <= 1 || x >= width - 2) return 0.0f;
            uint32_t p0 = pixels[cy * width + x - 1];
            uint32_t p1 = pixels[cy * width + x + 1];
            float dr = static_cast<float>((p1 & 0xFF) - (p0 & 0xFF));
            float dg = static_cast<float>(((p1 >> 8) & 0xFF) - ((p0 >> 8) & 0xFF));
            float db = static_cast<float>(((p1 >> 16) & 0xFF) - ((p0 >> 16) & 0xFF));
            float dlum = std::abs((dr * 77.0f + dg * 150.0f + db * 29.0f) / 256.0f);
            return std::sqrt(dr * dr + dg * dg + db * db) + dlum * 1.2f;
        };

        int searchRadius = std::max(12, static_cast<int>(expectedRadius * 0.35f));

        // Dò cực đại biên trái
        int minSearchL = std::max(2, static_cast<int>(leftEdge) - searchRadius);
        int maxSearchL = std::min(width - 3, static_cast<int>(leftEdge) + searchRadius);
        float maxGL = 0.0f;
        int peakXL = static_cast<int>(leftEdge);

        for (int x = minSearchL; x <= maxSearchL; ++x) {
            float g = getGrad(x);
            if (g > maxGL) {
                maxGL = g;
                peakXL = x;
            }
        }

        if (maxGL > 20.0f && peakXL > 1 && peakXL < width - 2) {
            float g0 = getGrad(peakXL - 1);
            float g1 = maxGL;
            float g2 = getGrad(peakXL + 1);
            float denom = 2.0f * (g0 - 2.0f * g1 + g2);
            if (std::abs(denom) > 1e-4f) {
                float delta = (g0 - g2) / denom;
                delta = std::max(-0.5f, std::min(0.5f, delta));
                leftEdge = static_cast<float>(peakXL) + delta;
            } else {
                leftEdge = static_cast<float>(peakXL);
            }
        }

        // Dò cực đại biên phải
        int minSearchR = std::max(2, static_cast<int>(rightEdge) - searchRadius);
        int maxSearchR = std::min(width - 3, static_cast<int>(rightEdge) + searchRadius);
        float maxGR = 0.0f;
        int peakXR = static_cast<int>(rightEdge);

        for (int x = minSearchR; x <= maxSearchR; ++x) {
            float g = getGrad(x);
            if (g > maxGR) {
                maxGR = g;
                peakXR = x;
            }
        }

        if (maxGR > 20.0f && peakXR > 1 && peakXR < width - 2) {
            float g0 = getGrad(peakXR - 1);
            float g1 = maxGR;
            float g2 = getGrad(peakXR + 1);
            float denom = 2.0f * (g0 - 2.0f * g1 + g2);
            if (std::abs(denom) > 1e-4f) {
                float delta = (g0 - g2) / denom;
                delta = std::max(-0.5f, std::min(0.5f, delta));
                rightEdge = static_cast<float>(peakXR) + delta;
            } else {
                rightEdge = static_cast<float>(peakXR);
            }
        }

        outLeftEdges[rowIdx] = leftEdge;
        outRightEdges[rowIdx] = rightEdge;
    }

    // 3. Lọc mượt 5-tap Gaussian chống răng cưa đường biên [0.061, 0.242, 0.383, 0.242, 0.061]
    if (numRows >= 5) {
        std::vector<float> smoothL = outLeftEdges;
        std::vector<float> smoothR = outRightEdges;
        for (int r = 2; r < numRows - 2; ++r) {
            smoothL[r] = outLeftEdges[r - 2] * 0.061f + outLeftEdges[r - 1] * 0.242f +
                         outLeftEdges[r] * 0.383f + outLeftEdges[r + 1] * 0.242f +
                         outLeftEdges[r + 2] * 0.061f;
            smoothR[r] = outRightEdges[r - 2] * 0.061f + outRightEdges[r - 1] * 0.242f +
                         outRightEdges[r] * 0.383f + outRightEdges[r + 1] * 0.242f +
                         outRightEdges[r + 2] * 0.061f;
        }
        outLeftEdges = std::move(smoothL);
        outRightEdges = std::move(smoothR);
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
            // 1. THU GỌN VÀO (Contraction / Slimming, scale < 1.0):
            // - Mọi pixel ngoài [xL, xR] ban đầu: dx = 0, dy = 0 TUYỆT ĐỐI (Delta = 0.00).
            //   Background bên cạnh (tường, cửa, bàn ghế, người bên cạnh) giữ nguyên 100%!
            // - Khoảng trống lộ ra [xL, newXL) và (newXR, xR]: Đánh dấu isVacated = 1 để bù lấp.
            // - Trong cơ thể mới [newXL, newXR]: Lấy mẫu ngược bicubic từ cơ thể gốc.
            int minX = std::max(0, static_cast<int>(std::floor(newXL)));
            int maxX = std::min(width - 1, static_cast<int>(std::ceil(newXR)));

            for (int x = minX; x <= maxX; ++x) {
                float normX = (static_cast<float>(x) - midX) / std::max(1.0f, newHalfW);
                normX = std::max(-1.0f, std::min(1.0f, normX));
                float srcX = midX + normX * halfW;
                int idx = y * width + x;
                dxField[idx] = static_cast<float>(x) - srcX;
            }

            // Đánh dấu khoảng trống lộ ra (Vacated Space)
            int vacL1 = std::max(0, static_cast<int>(std::floor(xL)));
            int vacL2 = std::min(width - 1, static_cast<int>(std::ceil(newXL)));
            for (int x = vacL1; x <= vacL2; ++x) {
                isVacated[y * width + x] = 1;
            }

            int vacR1 = std::max(0, static_cast<int>(std::floor(newXR)));
            int vacR2 = std::min(width - 1, static_cast<int>(std::ceil(xR)));
            for (int x = vacR1; x <= vacR2; ++x) {
                isVacated[y * width + x] = 1;
            }
        } else {
            // 2. TO RA (Expansion / Curvy Hips, scale > 1.0):
            // - Cơ thể nở rộng ra ngoài [newXL, newXR].
            // - Pixel ngoài [newXL, newXR]: dx = 0, dy = 0 TUYỆT ĐỐI (Delta = 0.00).
            //   Background bên ngoài không bị xê dịch hay bẻ cong 1 bit!
            int minX = std::max(0, static_cast<int>(std::floor(newXL)));
            int maxX = std::min(width - 1, static_cast<int>(std::ceil(newXR)));

            for (int x = minX; x <= maxX; ++x) {
                float normX = (static_cast<float>(x) - midX) / std::max(1.0f, newHalfW);
                normX = std::max(-1.0f, std::min(1.0f, normX));
                float srcX = midX + normX * halfW;
                int idx = y * width + x;
                dxField[idx] = static_cast<float>(x) - srcX;
            }
        }
    }

    // BẢO VỆ CHẤT LIỆU VẢI & PHẦN TỬ CỨNG (Zero Strain Tensor & Cauchy-Riemann Conformal Elasticity):
    // 1. Áp dụng Zero Strain Tensor lên các phần tử cứng (cúc áo nhựa, khuy kim loại, khóa kéo, mặt thắt lưng)
    if (!rigidElements.empty()) {
        mClothingEngine.applyRigidElementConstraints(
            width, height, rigidElements, dxField.data(), dyField.data()
        );
    }

    // 2. Điều hòa Cauchy-Riemann Conformal Elasticity bảo toàn góc sợi dệt vải (chống vỡ hoa văn sọc/caro)
    if (!rigidityMap.empty()) {
        mClothingEngine.regularizeClothingDisplacement(
            width, height, rigidityMap, rigidElements, dxField.data(), dyField.data()
        );
    }

    // 3. Khóa lại Zero Strain một lần nữa sau bước điều hòa vải
    if (!rigidElements.empty()) {
        mClothingEngine.applyRigidElementConstraints(
            width, height, rigidElements, dxField.data(), dyField.data()
        );
    }

    // TỔNG HỢP PIXEL (Resampling, Gap Infilling & Sub-pixel Anti-Aliasing):
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

        int rowStart = std::max(0, static_cast<int>(std::floor(std::min(xL, newXL))));
        int rowEnd = std::min(width - 1, static_cast<int>(std::ceil(std::max(xR, newXR))));

        for (int x = rowStart; x <= rowEnd; ++x) {
            int idx = y * width + x;

            if (isVacated[idx]) {
                continue;
            }

            float dx = dxField[idx];
            float dy = dyField[idx];

            if (std::abs(dx) > 1e-3f || std::abs(dy) > 1e-3f) {
                float srcX = static_cast<float>(x) - dx;
                float srcY = static_cast<float>(y) - dy;
                uint32_t warpedPix = sampleBicubic(snapshot.data(), width, height, srcX, srcY);

                if (scale > 1.0f) {
                    // Khi nở to ra: Sub-pixel Boundary Anti-Aliasing (Edge Feathering 1.5 pixels)
                    float distToEdge = std::min(std::abs(static_cast<float>(x) - newXL),
                                                std::abs(static_cast<float>(x) - newXR));
                    if (distToEdge <= 1.5f) {
                        float t = distToEdge / 1.5f;
                        float alpha = t * t * (3.0f - 2.0f * t); // Hermite smoothstep
                        uint32_t bgPix = snapshot[idx];

                        auto bR = [](uint32_t p) { return p & 0xFF; };
                        auto bG = [](uint32_t p) { return (p >> 8) & 0xFF; };
                        auto bB = [](uint32_t p) { return (p >> 16) & 0xFF; };
                        auto bA = [](uint32_t p) { return (p >> 24) & 0xFF; };

                        uint8_t outR = static_cast<uint8_t>(bR(bgPix) * (1.0f - alpha) + bR(warpedPix) * alpha);
                        uint8_t outG = static_cast<uint8_t>(bG(bgPix) * (1.0f - alpha) + bG(warpedPix) * alpha);
                        uint8_t outB = static_cast<uint8_t>(bB(bgPix) * (1.0f - alpha) + bB(warpedPix) * alpha);
                        uint8_t outA = static_cast<uint8_t>(bA(bgPix) * (1.0f - alpha) + bA(warpedPix) * alpha);
                        pixels[idx] = outR | (outG << 8) | (outB << 16) | (outA << 24);
                        continue;
                    }
                }

                pixels[idx] = warpedPix;
            }
        }
    }

    // Structure-aware reconstruction of vacated holes preserving lines and textures
    mBgEngine.reconstructVacatedHoles(pixels, snapshot.data(), width, height, isVacated.data(), nullptr, nullptr);
}

void BodyBeautyEngine::detectLimbSilhouetteBounds(
    const uint32_t* pixels, int width, int height,
    const Point2DF& p1, const Point2DF& p2, float expectedRadius,
    const uint8_t* parsingMask,
    std::vector<float>& outSampleT,
    std::vector<float>& outRadiusLeft,
    std::vector<float>& outRadiusRight
) {
    const int numSamples = 32;
    outSampleT.resize(numSamples);
    outRadiusLeft.assign(numSamples, expectedRadius);
    outRadiusRight.assign(numSamples, expectedRadius);

    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float len = std::hypot(dx, dy);
    if (len < 5.0f || !pixels || width <= 0 || height <= 0) return;

    float nx = -dy / len;
    float ny = dx / len;

    auto getGradAt = [&](float sx, float sy) -> float {
        int ix = static_cast<int>(sx);
        int iy = static_cast<int>(sy);
        if (ix <= 1 || ix >= width - 2 || iy <= 1 || iy >= height - 2) return 0.0f;
        uint32_t p0 = pixels[iy * width + (ix - 1)];
        uint32_t p1 = pixels[iy * width + (ix + 1)];
        float dr = static_cast<float>((p1 & 0xFF) - (p0 & 0xFF));
        float dg = static_cast<float>(((p1 >> 8) & 0xFF) - ((p0 >> 8) & 0xFF));
        float db = static_cast<float>(((p1 >> 16) & 0xFF) - ((p0 >> 16) & 0xFF));
        float dlum = std::abs((dr * 77.0f + dg * 150.0f + db * 29.0f) / 256.0f);
        return std::sqrt(dr * dr + dg * dg + db * db) + dlum * 1.2f;
    };

    for (int k = 0; k < numSamples; ++k) {
        float t = static_cast<float>(k) / static_cast<float>(numSamples - 1);
        outSampleT[k] = t;
        float cx = p1.x + t * dx;
        float cy = p1.y + t * dy;

        float rL = expectedRadius;
        float rR = expectedRadius;

        // Dò biên bên trái theo hướng -n
        float maxGL = 0.0f;
        float bestDistL = expectedRadius;
        for (float d = expectedRadius * 0.35f; d <= expectedRadius * 1.6f; d += 1.0f) {
            float sx = cx - d * nx;
            float sy = cy - d * ny;
            if (sx < 1.0f || sx >= width - 2 || sy < 1.0f || sy >= height - 2) break;

            if (parsingMask) {
                int pixIdx = static_cast<int>(sy) * width + static_cast<int>(sx);
                uint8_t c = parsingMask[pixIdx];
                if (c == CLASS_BACKGROUND || c == CLASS_FOREGROUND_OBJ) {
                    bestDistL = d;
                    break;
                }
            }

            float g = getGradAt(sx, sy);
            if (g > maxGL) {
                maxGL = g;
                bestDistL = d;
            }
        }
        if (maxGL > 20.0f || parsingMask) rL = bestDistL;

        // Dò biên bên phải theo hướng +n
        float maxGR = 0.0f;
        float bestDistR = expectedRadius;
        for (float d = expectedRadius * 0.35f; d <= expectedRadius * 1.6f; d += 1.0f) {
            float sx = cx + d * nx;
            float sy = cy + d * ny;
            if (sx < 1.0f || sx >= width - 2 || sy < 1.0f || sy >= height - 2) break;

            if (parsingMask) {
                int pixIdx = static_cast<int>(sy) * width + static_cast<int>(sx);
                uint8_t c = parsingMask[pixIdx];
                if (c == CLASS_BACKGROUND || c == CLASS_FOREGROUND_OBJ) {
                    bestDistR = d;
                    break;
                }
            }

            float g = getGradAt(sx, sy);
            if (g > maxGR) {
                maxGR = g;
                bestDistR = d;
            }
        }
        if (maxGR > 20.0f || parsingMask) rR = bestDistR;

        outRadiusLeft[k] = rL;
        outRadiusRight[k] = rR;
    }

    // Gaussian 5-tap smoothing dọc theo trục xương
    std::vector<float> smoothRL = outRadiusLeft;
    std::vector<float> smoothRR = outRadiusRight;
    for (int k = 2; k < numSamples - 2; ++k) {
        smoothRL[k] = outRadiusLeft[k - 2] * 0.061f + outRadiusLeft[k - 1] * 0.242f +
                      outRadiusLeft[k] * 0.383f + outRadiusLeft[k + 1] * 0.242f +
                      outRadiusLeft[k + 2] * 0.061f;
        smoothRR[k] = outRadiusRight[k - 2] * 0.061f + outRadiusRight[k - 1] * 0.242f +
                      outRadiusRight[k] * 0.383f + outRadiusRight[k + 1] * 0.242f +
                      outRadiusRight[k + 2] * 0.061f;
    }
    outRadiusLeft = std::move(smoothRL);
    outRadiusRight = std::move(smoothRR);
}

void BodyBeautyEngine::applyLimbBoundaryPreservingWarp(
    uint32_t* pixels, int width, int height,
    const Point2DF& p1, const Point2DF& p2, float expectedRadius,
    float intensity,
    const uint8_t* parsingMask,
    const std::vector<float>& rigidityMap,
    const std::vector<RigidElement>& rigidElements
) {
    if (!pixels || width <= 0 || height <= 0 || std::abs(intensity) < 0.001f) return;

    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float len = std::hypot(dx, dy);
    if (len < 5.0f) return;

    float nx = -dy / len;
    float ny = dx / len;

    // 1. Dò tìm đường biên vật lý thực tế của chi (Sub-pixel Boundary Detection)
    std::vector<float> sampleT, radiusLeft, radiusRight;
    detectLimbSilhouetteBounds(pixels, width, height, p1, p2, expectedRadius, parsingMask,
                               sampleT, radiusLeft, radiusRight);

    std::vector<uint32_t> snapshot(pixels, pixels + (width * height));
    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);
    std::vector<uint8_t> isVacated(width * height, 0);

    float maxR = 0.0f;
    for (float r : radiusLeft) maxR = std::max(maxR, r);
    for (float r : radiusRight) maxR = std::max(maxR, r);

    int minX = std::max(0, static_cast<int>(std::min(p1.x, p2.x) - maxR * 1.6f));
    int maxX = std::min(width - 1, static_cast<int>(std::max(p1.x, p2.x) + maxR * 1.6f));
    int minY = std::max(0, static_cast<int>(std::min(p1.y, p2.y) - maxR * 1.6f));
    int maxY = std::min(height - 1, static_cast<int>(std::max(p1.y, p2.y) + maxR * 1.6f));

    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            float px = static_cast<float>(x) - p1.x;
            float py = static_cast<float>(y) - p1.y;
            float t = (px * dx + py * dy) / (len * len);
            if (t < 0.0f || t > 1.0f) continue;

            float fIdx = t * (sampleT.size() - 1);
            int idx0 = std::max(0, std::min(static_cast<int>(sampleT.size() - 2), static_cast<int>(fIdx)));
            float frac = fIdx - idx0;
            float curRL = radiusLeft[idx0] * (1.0f - frac) + radiusLeft[idx0 + 1] * frac;
            float curRR = radiusRight[idx0] * (1.0f - frac) + radiusRight[idx0 + 1] * frac;

            float perpDist = px * nx + py * ny;
            float absPerp = std::abs(perpDist);
            bool isRight = (perpDist > 0.0f);
            float boundR = isRight ? curRR : curRL;

            float envelope = std::sin(t * 3.14159265f);
            float scale = 1.0f - intensity * 0.25f * envelope;
            float newBoundR = boundR * scale;

            if (scale < 1.0f) {
                // Thu gọn bắp tay / cẳng chân:
                // Ngoài boundR: BACKGROUND THUẦN TÚY -> Chuyển vị = 0.00 TUYỆT ĐỐI!
                if (absPerp > boundR) continue;

                // Vùng khoảng trống lộ ra giữa newBoundR và boundR
                if (absPerp > newBoundR) {
                    isVacated[y * width + x] = 1;
                    continue;
                }

                // Trong chi mới: co vào phía xương
                float normD = absPerp / std::max(1.0f, newBoundR);
                float srcD = normD * boundR;
                float disp = (absPerp - srcD);
                float sign = isRight ? 1.0f : -1.0f;
                int pIdx = y * width + x;
                dxField[pIdx] = disp * nx * sign;
                dyField[pIdx] = disp * ny * sign;
            } else {
                // Nở to cơ bắp / bắp chân:
                // Ngoài newBoundR: BACKGROUND THUẦN TÚY -> Chuyển vị = 0.00 TUYỆT ĐỐI!
                if (absPerp > newBoundR) continue;

                float normD = absPerp / std::max(1.0f, newBoundR);
                float srcD = normD * boundR;
                float disp = (absPerp - srcD);
                float sign = isRight ? 1.0f : -1.0f;
                int pIdx = y * width + x;
                dxField[pIdx] = disp * nx * sign;
                dyField[pIdx] = disp * ny * sign;
            }
        }
    }

    // 2. Ràng buộc Zero Strain Tensor cho phụ kiện cứng (đồng hồ, vòng tay, cúc)
    if (!rigidElements.empty()) {
        mClothingEngine.applyRigidElementConstraints(width, height, rigidElements, dxField.data(), dyField.data());
    }

    // 3. Ràng buộc Cauchy-Riemann cho vải trang phục (tay áo sơ mi, len, ống quần)
    if (!rigidityMap.empty()) {
        mClothingEngine.regularizeClothingDisplacement(width, height, rigidityMap, rigidElements, dxField.data(), dyField.data());
    }

    // 4. Khóa lại Zero Strain sau điều hòa
    if (!rigidElements.empty()) {
        mClothingEngine.applyRigidElementConstraints(width, height, rigidElements, dxField.data(), dyField.data());
    }

    // 5. Tổng hợp pixel bảo vệ tuyệt đối background và hòa hợp sub-pixel
    #pragma omp parallel for
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            int idx = y * width + x;

            if (isVacated[idx]) {
                continue;
            }

            float dfx = dxField[idx];
            float dfy = dyField[idx];
            if (std::abs(dfx) > 1e-3f || std::abs(dfy) > 1e-3f) {
                float srcX = static_cast<float>(x) - dfx;
                float srcY = static_cast<float>(y) - dfy;
                pixels[idx] = sampleBicubic(snapshot.data(), width, height, srcX, srcY);
            }
        }
    }

    // Structure-aware reconstruction of limb vacated holes
    mBgEngine.reconstructVacatedHoles(pixels, snapshot.data(), width, height, isVacated.data(), parsingMask, nullptr);
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
    if (!rgbaImage || width <= 0 || height <= 0 || intensity < 0.001f ||
        !human.isValid || !human.pose.isValid) {
        return false;
    }

    if (!human.hasLegsVisible && !human.leftLeg.isVisible && !human.rightLeg.isVisible) {
        return false;
    }

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);
    std::vector<uint32_t> original(pixels, pixels + (width * height));

    float hipY = 0.0f;
    int hipCount = 0;
    if (human.leftLeg.hip.y > 1.0f) { hipY += human.leftLeg.hip.y; hipCount++; }
    if (human.rightLeg.hip.y > 1.0f) { hipY += human.rightLeg.hip.y; hipCount++; }
    if (hipCount > 0) hipY /= hipCount;
    else hipY = human.torso.hipCenter.y;

    float kneeY = 0.0f;
    int kneeCount = 0;
    if (human.leftLeg.knee.y > 1.0f) { kneeY += human.leftLeg.knee.y; kneeCount++; }
    if (human.rightLeg.knee.y > 1.0f) { kneeY += human.rightLeg.knee.y; kneeCount++; }
    if (kneeCount > 0) kneeY /= kneeCount;

    float ankleY = 0.0f;
    int ankleCount = 0;
    if (human.leftLeg.ankle.y > 1.0f) { ankleY += human.leftLeg.ankle.y; ankleCount++; }
    if (human.rightLeg.ankle.y > 1.0f) { ankleY += human.rightLeg.ankle.y; ankleCount++; }
    if (ankleCount > 0) ankleY /= ankleCount;
    else if (kneeCount > 0 && kneeY > hipY) ankleY = std::min(static_cast<float>(height - 1), kneeY + (kneeY - hipY) * 0.9f);
    else ankleY = static_cast<float>(height - 1);

    if (ankleY <= hipY + 15.0f) {
        return false;
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

    if (human.parsingValid && !human.parsingMask.empty()) {
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
    if (!rgbaImage || width <= 0 || height <= 0 || intensity < 0.001f ||
        !human.isValid || !human.pose.isValid) {
        return false;
    }

    if (!human.hasLegsVisible && !human.leftLeg.isVisible && !human.rightLeg.isVisible) {
        return false;
    }

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);
    std::vector<uint32_t> original(pixels, pixels + (width * height));

    float neckY = human.pose.keypoints[JOINT_NECK].pos.y;
    if (neckY <= 1.0f) {
        if (human.keypoints[JOINT_SHOULDER_LEFT].visible && human.keypoints[JOINT_SHOULDER_RIGHT].visible) {
            neckY = (human.keypoints[JOINT_SHOULDER_LEFT].y + human.keypoints[JOINT_SHOULDER_RIGHT].y) * 0.5f;
        } else if (human.keypoints[JOINT_NOSE].visible) {
            neckY = human.keypoints[JOINT_NOSE].y + 40.0f;
        } else {
            neckY = height * 0.2f;
        }
    }

    float hipY = human.torso.hipCenter.y;
    if (hipY <= neckY + 10.0f) {
        float hL = human.keypoints[JOINT_HIP_LEFT].visible ? human.keypoints[JOINT_HIP_LEFT].y : 0.0f;
        float hR = human.keypoints[JOINT_HIP_RIGHT].visible ? human.keypoints[JOINT_HIP_RIGHT].y : 0.0f;
        if (hL > neckY + 10.0f && hR > neckY + 10.0f) hipY = (hL + hR) * 0.5f;
        else if (hL > neckY + 10.0f) hipY = hL;
        else if (hR > neckY + 10.0f) hipY = hR;
        else hipY = (neckY + height) * 0.5f;
    }

    float aL = human.leftLeg.ankle.y;
    float aR = human.rightLeg.ankle.y;
    float ankleY = 0.0f;
    if (aL > hipY && aR > hipY) ankleY = (aL + aR) * 0.5f;
    else if (aL > hipY) ankleY = aL;
    else if (aR > hipY) ankleY = aR;
    else {
        float kL = human.leftLeg.knee.y;
        float kR = human.rightLeg.knee.y;
        if (kL > hipY && kR > hipY) ankleY = std::min(static_cast<float>(height - 1), (kL + kR) * 0.5f + (kL - hipY));
        else ankleY = static_cast<float>(height - 1);
    }

    if (hipY <= neckY + 10.0f || ankleY <= hipY + 10.0f) {
        return false;
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

    if (human.parsingValid && !human.parsingMask.empty()) {
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

// 3. THON GỌN CƠ THỂ, THẮT EO & NỞ HÔNG (SLIM BODY, WAIST & HIP - SPEC Section 51, 77)
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
    if (maxInt < 0.001f || !human.isValid || !human.pose.isValid) return false;

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);

    Point2DF waist = human.torso.waistCenter;
    Point2DF chest = human.torso.chestCenter;
    Point2DF hip = human.torso.hipCenter;

    if (waist.y <= 0.1f) {
        bool hasHips = human.keypoints[JOINT_HIP_LEFT].visible || human.keypoints[JOINT_HIP_RIGHT].visible;
        if (!hasHips) {
            return false;
        }
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

    // 1. Nhận diện chính xác đường biên vật lý từng sub-pixel (Multi-channel Edge + Parsing Mask)
    std::vector<float> leftEdges, rightEdges;
    detectSilhouetteBounds(
        pixels, width, height, yStart, yEnd, waist.x, expectedRadius,
        (human.parsingValid && !human.parsingMask.empty()) ? human.parsingMask.data() : nullptr,
        leftEdges, rightEdges
    );

    // 2. Tính toán hệ số co giãn scale factor cho từng dòng quét hỗ trợ cả 2 chiều:
    // - waistIntensity > 0: thắt eo con kiến; waistIntensity < 0: nới rộng eo
    // - hipIntensity > 0: nở hông quả táo; hipIntensity < 0: thon gọn hông
    // - slimIntensity > 0: thon gọn toàn thân; slimIntensity < 0: nở nang body
    std::vector<float> scaleFactors(numRows, 1.0f);
    for (int y = yStart; y <= yEnd; ++y) {
        int r = y - yStart;
        float curY = static_cast<float>(y);

        float factor = 1.0f;
        if (curY <= waist.y) {
            // Vùng giữa ngực và eo: thu nhỏ / mở rộng dần đến eo
            float t = (curY - torsoTop) / std::max(1.0f, waist.y - torsoTop);
            t = std::max(0.0f, std::min(1.0f, t));
            float smoothT = t * t * (3.0f - 2.0f * t);
            float waistScale = 1.0f - (waistIntensity * 0.28f + slimIntensity * 0.15f);
            factor = 1.0f * (1.0f - smoothT) + waistScale * smoothT;
        } else {
            // Vùng giữa eo và hông: chuyển tiếp mượt từ eo sang hông
            float t = (curY - waist.y) / std::max(1.0f, torsoBottom - waist.y);
            t = std::max(0.0f, std::min(1.0f, t));
            float smoothT = t * t * (3.0f - 2.0f * t);
            float waistScale = 1.0f - (waistIntensity * 0.28f + slimIntensity * 0.15f);
            float hipScale = 1.0f + (hipIntensity * 0.22f - slimIntensity * 0.08f);
            factor = waistScale * (1.0f - smoothT) + hipScale * smoothT;
        }
        scaleFactors[r] = factor;
    }

    // 3. Trích xuất ràng buộc cúc áo, khóa kéo, mặt thắt lưng và hoa văn dệt vải
    std::vector<float> rigidityMap;
    std::vector<RigidElement> rigidElements;
    mClothingEngine.extractClothingConstraints(
        rgbaImage, width, height, (human.parsingValid && !human.parsingMask.empty()) ? human.parsingMask.data() : nullptr,
        rigidityMap, rigidElements
    );

    // 4. Biến dạng bảo toàn đường biên: Zero Background Warping, bảo vệ vải và phụ kiện cứng
    applyBoundaryPreservingWarp(
        pixels, width, height, stride,
        yStart, yEnd, waist.x,
        leftEdges, rightEdges, scaleFactors,
        rigidityMap, rigidElements
    );

    return true;
}

// 3.5. NÂNG NGỰC / THON NGỰC TỰ NHIÊN (CHEST RESHAPE - SPEC Section 50)
bool BodyBeautyEngine::applyChestReshape(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const HumanFrameResult& human,
    float intensity
) {
    if (!rgbaImage || width <= 0 || height <= 0 || std::abs(intensity) < 0.001f ||
        !human.isValid || !human.pose.isValid) {
        return false;
    }

    const auto& sL = human.keypoints[JOINT_SHOULDER_LEFT];
    const auto& sR = human.keypoints[JOINT_SHOULDER_RIGHT];
    if (!sL.visible && !sR.visible) return false;

    float sDist = std::hypot(sR.x - sL.x, sR.y - sL.y);
    if (sDist < 15.0f) return false;

    float throatX = human.keypoints[JOINT_NECK].visible ? human.keypoints[JOINT_NECK].x : (sL.x + sR.x) * 0.5f;
    float throatY = human.keypoints[JOINT_NECK].visible ? human.keypoints[JOINT_NECK].y : (sL.y + sR.y) * 0.5f;

    float chestY = throatY + sDist * 0.48f;
    if (chestY >= static_cast<float>(height) - 10.0f) {
        return false; // Chest is off-screen
    }

    float leftChestX = throatX - sDist * 0.24f;
    float rightChestX = throatX + sDist * 0.24f;
    float radius = sDist * 0.28f;

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);
    std::vector<uint32_t> snapshot(pixels, pixels + (width * height));
    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);

    float p = std::clamp(intensity, -1.0f, 1.0f);
    float maxPush = radius * 0.22f * p;

    int minX = std::max(0, static_cast<int>(leftChestX - radius * 1.5f));
    int maxX = std::min(width - 1, static_cast<int>(rightChestX + radius * 1.5f));
    int minY = std::max(0, static_cast<int>(chestY - radius * 1.5f));
    int maxY = std::min(height - 1, static_cast<int>(chestY + radius * 1.5f));

    for (int y = minY; y <= maxY; ++y) {
        float curY = static_cast<float>(y);
        for (int x = minX; x <= maxX; ++x) {
            float curX = static_cast<float>(x);

            // Left breast contribution
            float dL = std::hypot(curX - leftChestX, curY - chestY);
            float dxL = 0.0f, dyL = 0.0f;
            if (dL < radius && radius > 1.0f) {
                float normD = dL / radius;
                float wL = std::cos(normD * 1.5707963f);
                wL = wL * wL;
                if (dL > 1e-3f) {
                    dxL = ((curX - leftChestX) / dL) * maxPush * wL;
                    dyL = ((curY - chestY) / dL) * maxPush * wL;
                }
            }

            // Right breast contribution
            float dR = std::hypot(curX - rightChestX, curY - chestY);
            float dxR = 0.0f, dyR = 0.0f;
            if (dR < radius && radius > 1.0f) {
                float normD = dR / radius;
                float wR = std::cos(normD * 1.5707963f);
                wR = wR * wR;
                if (dR > 1e-3f) {
                    dxR = ((curX - rightChestX) / dR) * maxPush * wR;
                    dyR = ((curY - chestY) / dR) * maxPush * wR;
                }
            }

            int idx = y * width + x;
            dxField[idx] = dxL + dxR;
            dyField[idx] = dyL + dyR;
        }
    }

    // Protect background and regularize
    if (human.parsingValid && !human.parsingMask.empty()) {
        mBgEngine.attenuateBoundaryLeakage(width, height, human.parsingMask.data(), dxField.data(), dyField.data());
    }
    if (!human.backgroundProtectionMask.empty()) {
        mBgEngine.regularizeDisplacementField(width, height, human.backgroundProtectionMask.data(), human.structuralLines, dxField.data(), dyField.data());
    }

    #pragma omp parallel for
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            int idx = y * width + x;
            float dfx = dxField[idx];
            float dfy = dyField[idx];
            if (std::abs(dfx) > 1e-3f || std::abs(dfy) > 1e-3f) {
                float srcX = static_cast<float>(x) - dfx;
                float srcY = static_cast<float>(y) - dfy;
                pixels[idx] = sampleBicubic(snapshot.data(), width, height, srcX, srcY);
            }
        }
    }

    return true;
}

// 4. THON BẮP TAY & CHỈNH VAI (ARM & SHOULDER SLIM - SPEC Section 47, 54, 55)
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
    if (!human.isValid || !human.pose.isValid) return false;

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);

    // Trích xuất ràng buộc trang phục & phụ kiện (đồng hồ, vòng tay, cúc tay áo, viền vải)
    std::vector<float> rigidityMap;
    std::vector<RigidElement> rigidElements;
    mClothingEngine.extractClothingConstraints(
        rgbaImage, width, height, (human.parsingValid && !human.parsingMask.empty()) ? human.parsingMask.data() : nullptr,
        rigidityMap, rigidElements
    );

    const uint8_t* pMask = (human.parsingValid && !human.parsingMask.empty()) ? human.parsingMask.data() : nullptr;

    // 1. Biến dạng bắp tay & cẳng tay bảo toàn đường biên thực tế từng sub-pixel
    // Hỗ trợ cả 2 chiều: armIntensity > 0 (thon gọn bắp tay); armIntensity < 0 (nở cơ bắp tay)
    // Nền bên cạnh cánh tay (tường, cửa, bàn ghế, người cạnh bên) tuyệt đối không bị kéo cong!
    if (std::abs(armIntensity) > 0.001f) {
        if (human.leftArm.isVisible || human.keypoints[JOINT_ELBOW_LEFT].visible) {
            Point2DF s = human.leftArm.shoulder.x > 0.1f ? human.leftArm.shoulder : human.keypoints[JOINT_SHOULDER_LEFT].pos;
            Point2DF e = human.leftArm.elbow.x > 0.1f ? human.leftArm.elbow : human.keypoints[JOINT_ELBOW_LEFT].pos;
            Point2DF w = human.leftArm.wrist.x > 0.1f ? human.leftArm.wrist : human.keypoints[JOINT_WRIST_LEFT].pos;
            float upperW = human.leftArm.upperArmWidth > 5.0f ? human.leftArm.upperArmWidth : 35.0f;
            float foreW = human.leftArm.forearmWidth > 5.0f ? human.leftArm.forearmWidth : 28.0f;
            if (e.x > 0.1f) {
                applyLimbBoundaryPreservingWarp(
                    pixels, width, height, s, e, upperW, armIntensity, pMask, rigidityMap, rigidElements
                );
                if (w.x > 0.1f) {
                    applyLimbBoundaryPreservingWarp(
                        pixels, width, height, e, w, foreW, armIntensity * 0.85f, pMask, rigidityMap, rigidElements
                    );
                }
            }
        }
        if (human.rightArm.isVisible || human.keypoints[JOINT_ELBOW_RIGHT].visible) {
            Point2DF s = human.rightArm.shoulder.x > 0.1f ? human.rightArm.shoulder : human.keypoints[JOINT_SHOULDER_RIGHT].pos;
            Point2DF e = human.rightArm.elbow.x > 0.1f ? human.rightArm.elbow : human.keypoints[JOINT_ELBOW_RIGHT].pos;
            Point2DF w = human.rightArm.wrist.x > 0.1f ? human.rightArm.wrist : human.keypoints[JOINT_WRIST_RIGHT].pos;
            float upperW = human.rightArm.upperArmWidth > 5.0f ? human.rightArm.upperArmWidth : 35.0f;
            float foreW = human.rightArm.forearmWidth > 5.0f ? human.rightArm.forearmWidth : 28.0f;
            if (e.x > 0.1f) {
                applyLimbBoundaryPreservingWarp(
                    pixels, width, height, s, e, upperW, armIntensity, pMask, rigidityMap, rigidElements
                );
                if (w.x > 0.1f) {
                    applyLimbBoundaryPreservingWarp(
                        pixels, width, height, e, w, foreW, armIntensity * 0.85f, pMask, rigidityMap, rigidElements
                    );
                }
            }
        }
    }

    // 2. Chỉnh vai (Shoulder Slim / Broaden)
    bool hasShoulderGeometry = (human.keypoints[JOINT_SHOULDER_LEFT].visible && human.keypoints[JOINT_SHOULDER_RIGHT].visible) ||
                               (human.leftArm.shoulder.x > 0.1f && human.rightArm.shoulder.x > 0.1f);
    if (std::abs(shoulderIntensity) > 0.001f && hasShoulderGeometry) {
        Point2DF sL = human.keypoints[JOINT_SHOULDER_LEFT].visible ? human.keypoints[JOINT_SHOULDER_LEFT].pos : human.leftArm.shoulder;
        Point2DF sR = human.keypoints[JOINT_SHOULDER_RIGHT].visible ? human.keypoints[JOINT_SHOULDER_RIGHT].pos : human.rightArm.shoulder;
        Point2DF neck = human.pose.keypoints[JOINT_NECK].pos;
        if (neck.y <= 0.1f) {
            neck = {(sL.x + sR.x) * 0.5f, (sL.y + sR.y) * 0.5f};
        }
        float shoulderSpan = std::hypot(sR.x - sL.x, sR.y - sL.y);
        if (shoulderSpan > 10.0f) {
            float shoulderScale = 1.0f - shoulderIntensity * 0.12f;
            int shoulderYStart = std::max(0, static_cast<int>(neck.y - 25.0f));
            int shoulderYEnd = std::min(height - 1, static_cast<int>(std::max(sL.y, sR.y) + shoulderSpan * 0.35f));
            int numRows = shoulderYEnd - shoulderYStart + 1;
            if (numRows > 0) {
                std::vector<float> leftEdges, rightEdges;
                detectSilhouetteBounds(
                    pixels, width, height, shoulderYStart, shoulderYEnd, neck.x, shoulderSpan * 0.55f,
                    pMask, leftEdges, rightEdges
                );
                std::vector<float> sScales(numRows, shoulderScale);
                applyBoundaryPreservingWarp(
                    pixels, width, height, stride,
                    shoulderYStart, shoulderYEnd, neck.x,
                    leftEdges, rightEdges, sScales,
                    rigidityMap, rigidElements
                );
            }
        }
    }

    return true;
}

// 5. THON GỌN ĐÙI VÀ BẮP CHÂN (LEG SLIM - SPEC Section 64, 66, 67)
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
    if (!human.isValid || !human.pose.isValid) return false;

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);

    // Trích xuất ràng buộc vải quần, đường may, ống quần, giày dép
    std::vector<float> rigidityMap;
    std::vector<RigidElement> rigidElements;
    mClothingEngine.extractClothingConstraints(
        rgbaImage, width, height, (human.parsingValid && !human.parsingMask.empty()) ? human.parsingMask.data() : nullptr,
        rigidityMap, rigidElements
    );

    const uint8_t* pMask = (human.parsingValid && !human.parsingMask.empty()) ? human.parsingMask.data() : nullptr;

    float leftThighW = human.leftLeg.thighWidth > 5.0f ? human.leftLeg.thighWidth : 45.0f;
    float leftCalfW = human.leftLeg.calfWidth > 5.0f ? human.leftLeg.calfWidth : 35.0f;
    float leftAnkleW = human.leftLeg.ankleWidth > 5.0f ? human.leftLeg.ankleWidth : 22.0f;
    float rightThighW = human.rightLeg.thighWidth > 5.0f ? human.rightLeg.thighWidth : 45.0f;
    float rightCalfW = human.rightLeg.calfWidth > 5.0f ? human.rightLeg.calfWidth : 35.0f;
    float rightAnkleW = human.rightLeg.ankleWidth > 5.0f ? human.rightLeg.ankleWidth : 22.0f;

    // 1. Biến dạng chân trái: Đùi, Bắp chuối, Cổ chân
    if (human.leftLeg.isVisible) {
        Point2DF hipL = (human.leftLeg.hip.y > 0.1f) ? human.leftLeg.hip : human.torso.hipCenter;
        Point2DF kneeL = (human.leftLeg.knee.y > 0.1f) ? human.leftLeg.knee : Point2DF{hipL.x, hipL.y + 120.0f};
        Point2DF ankleL = (human.leftLeg.ankle.y > 0.1f) ? human.leftLeg.ankle : Point2DF{kneeL.x, std::min(static_cast<float>(height - 1), kneeL.y + 120.0f)};

        if (std::abs(legSlimIntensity) > 0.001f) {
            // Đùi trái: hông -> đầu gối
            applyLimbBoundaryPreservingWarp(
                pixels, width, height,
                hipL, kneeL,
                leftThighW, legSlimIntensity,
                pMask, rigidityMap, rigidElements
            );
            // Bắp chuối trái: đầu gối -> cổ chân
            applyLimbBoundaryPreservingWarp(
                pixels, width, height,
                kneeL, ankleL,
                leftCalfW, legSlimIntensity * 0.90f,
                pMask, rigidityMap, rigidElements
            );
        }
        if (std::abs(ankleSlimIntensity) > 0.001f) {
            // Cổ chân trái: đoạn sát mắt cá chân
            Point2DF ankleBase = {ankleL.x, ankleL.y + 18.0f};
            applyLimbBoundaryPreservingWarp(
                pixels, width, height,
                ankleL, ankleBase,
                leftAnkleW, ankleSlimIntensity,
                pMask, rigidityMap, rigidElements
            );
        }
    }

    // 2. Biến dạng chân phải: Đùi, Bắp chuối, Cổ chân
    if (human.rightLeg.isVisible) {
        Point2DF hipR = (human.rightLeg.hip.y > 0.1f) ? human.rightLeg.hip : human.torso.hipCenter;
        Point2DF kneeR = (human.rightLeg.knee.y > 0.1f) ? human.rightLeg.knee : Point2DF{hipR.x, hipR.y + 120.0f};
        Point2DF ankleR = (human.rightLeg.ankle.y > 0.1f) ? human.rightLeg.ankle : Point2DF{kneeR.x, std::min(static_cast<float>(height - 1), kneeR.y + 120.0f)};

        if (std::abs(legSlimIntensity) > 0.001f) {
            // Đùi phải: hông -> đầu gối
            applyLimbBoundaryPreservingWarp(
                pixels, width, height,
                hipR, kneeR,
                rightThighW, legSlimIntensity,
                pMask, rigidityMap, rigidElements
            );
            // Bắp chuối phải: đầu gối -> cổ chân
            applyLimbBoundaryPreservingWarp(
                pixels, width, height,
                kneeR, ankleR,
                rightCalfW, legSlimIntensity * 0.90f,
                pMask, rigidityMap, rigidElements
            );
        }
        if (std::abs(ankleSlimIntensity) > 0.001f) {
            // Cổ chân phải: đoạn sát mắt cá chân
            Point2DF ankleBase = {ankleR.x, ankleR.y + 18.0f};
            applyLimbBoundaryPreservingWarp(
                pixels, width, height,
                ankleR, ankleBase,
                rightAnkleW, ankleSlimIntensity,
                pMask, rigidityMap, rigidElements
            );
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

    // Giai doan 2.5: Dinh hinh nguc tu nhien (Chest Reshape - Section 50)
    if (std::abs(params.chestEnhance) > 0.001f) {
        applyChestReshape(rgbaImage, width, height, stride, human, params.chestEnhance);
    }

    // Giai doan 3: Thon gon eo & than nguoi (Waist & Body Slim - Section 51, 77)
    if (std::abs(params.slimBody) > 0.001f || std::abs(params.waistSlim) > 0.001f ||
        std::abs(params.hipEnhance) > 0.001f || std::abs(params.abdomenSlim) > 0.001f) {
        float effectiveWaist = params.waistSlim + params.abdomenSlim * 0.4f;
        applyWaistAndBodySlim(rgbaImage, width, height, stride, human,
                              params.slimBody, effectiveWaist, params.hipEnhance);
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

#include "hair/hair_orientation_engine.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <omp.h>

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)

namespace meitu_native::hce {

HairOrientationEngine& HairOrientationEngine::getInstance() {
    static HairOrientationEngine instance;
    return instance;
}

bool HairOrientationEngine::computeOrientation(
    const uint32_t* srcPixels,
    int width,
    int height,
    const P0HairMatteAdapter& p0Matte,
    HairOrientationField& outOrientation
) {
    if (!srcPixels || width <= 0 || height <= 0 || !p0Matte.alphaData) {
        outOrientation.isValid = false;
        return false;
    }

    const int total = width * height;
    outOrientation.width = width;
    outOrientation.height = height;
    outOrientation.dirX.assign(total, 0.0f);
    outOrientation.dirY.assign(total, 0.0f);
    outOrientation.confidence.assign(total, 0.0f);

    // 1. Tính toán độ sáng Luminance
    std::vector<float> lum(total, 0.0f);
    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < total; ++i) {
        uint32_t c = srcPixels[i];
        lum[i] = 0.299f * RGBA_R(c) + 0.587f * RGBA_G(c) + 0.114f * RGBA_B(c);
    }

    // 2. Xác định ROI (Bounding box từ P0 Matte nếu có)
    int roiMinX = (p0Matte.roiMaxX > p0Matte.roiMinX) ? std::max(1, p0Matte.roiMinX) : 1;
    int roiMaxX = (p0Matte.roiMaxX > p0Matte.roiMinX) ? std::min(width - 2, p0Matte.roiMaxX) : width - 2;
    int roiMinY = (p0Matte.roiMaxY > p0Matte.roiMinY) ? std::max(1, p0Matte.roiMinY) : 1;
    int roiMaxY = (p0Matte.roiMaxY > p0Matte.roiMinY) ? std::min(height - 2, p0Matte.roiMaxY) : height - 2;

    std::vector<float> sxx(total, 0.0f);
    std::vector<float> syy(total, 0.0f);
    std::vector<float> sxy(total, 0.0f);

    // 3. Tính toán Structure Tensor
    computeStructureTensor(lum.data(), width, height, roiMinX, roiMinY, roiMaxX, roiMaxY, sxx, syy, sxy);

    // 4. Ước lượng trường hướng ban đầu (Principal Strand Tangent & Coherence)
    const float* alpha = p0Matte.alphaData;
    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            int idx = yOff + x;
            float a = alpha[idx];
            if (a < 0.05f) continue;

            float jxx = sxx[idx];
            float jyy = syy[idx];
            float jxy = sxy[idx];

            float diff = jxx - jyy;
            float denomCoherence = jxx + jyy + 1e-4f;
            float numCoherence = std::sqrt(diff * diff + 4.0f * jxy * jxy);
            float coherence = std::clamp(numCoherence / denomCoherence, 0.0f, 1.0f);

            // Sợi tóc vuông góc với gradient -> theta_tangent = theta_grad + pi/2
            // cos(2 * (theta_grad + pi/2)) = -cos(2 * theta_grad) = -diff / numCoherence
            // sin(2 * (theta_grad + pi/2)) = -sin(2 * theta_grad) = -2 * jxy / numCoherence
            float vx = 0.0f;
            float vy = 0.0f;
            if (numCoherence > 1e-5f) {
                vx = -diff / numCoherence;
                vy = -2.0f * jxy / numCoherence;
            } else {
                // Fallback: hướng dọc thẳng đứng mặc định nếu gradient đồng nhất
                vx = -1.0f; // cos(2 * pi/2) = cos(pi) = -1.0
                vy = 0.0f;
            }

            outOrientation.dirX[idx] = vx;
            outOrientation.dirY[idx] = vy;
            outOrientation.confidence[idx] = coherence;
        }
    }

    // 5. Làm mịn không gian (Spatial Regularization) trên vector góc kép (vx, vy)
    regularizeVectorField(
        width, height,
        roiMinX, roiMinY, roiMaxX, roiMaxY,
        alpha,
        outOrientation.dirX,
        outOrientation.dirY,
        outOrientation.confidence
    );

    outOrientation.isValid = true;
    outOrientation.isContinuous = true;
    return true;
}

void HairOrientationEngine::computeStructureTensor(
    const float* lum,
    int width,
    int height,
    int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
    std::vector<float>& sxx,
    std::vector<float>& syy,
    std::vector<float>& sxy
) {
    const int total = width * height;
    std::vector<float> jxx(total, 0.0f);
    std::vector<float> jyy(total, 0.0f);
    std::vector<float> jxy(total, 0.0f);

    // Bước 1: Gradient Sobel 3x3
    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        int yPrev = (y - 1) * width;
        int yNext = (y + 1) * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            float ix = (lum[yPrev + x + 1] + 2.0f * lum[yOff + x + 1] + lum[yNext + x + 1])
                     - (lum[yPrev + x - 1] + 2.0f * lum[yOff + x - 1] + lum[yNext + x - 1]);
            float iy = (lum[yNext + x - 1] + 2.0f * lum[yNext + x] + lum[yNext + x + 1])
                     - (lum[yPrev + x - 1] + 2.0f * lum[yPrev + x] + lum[yPrev + x + 1]);

            int idx = yOff + x;
            jxx[idx] = ix * ix;
            jyy[idx] = iy * iy;
            jxy[idx] = ix * iy;
        }
    }

    // Bước 2: Làm mịn Tensor cục bộ (Gaussian/Box 3x3)
    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            float sumXX = 0.0f, sumYY = 0.0f, sumXY = 0.0f;
            float weightSum = 0.0f;
            for (int dy = -1; dy <= 1; ++dy) {
                int py = std::clamp(y + dy, 0, height - 1);
                int pyOff = py * width;
                for (int dx = -1; dx <= 1; ++dx) {
                    int px = std::clamp(x + dx, 0, width - 1);
                    float w = (dx == 0 && dy == 0) ? 4.0f : ((dx == 0 || dy == 0) ? 2.0f : 1.0f);
                    int pidx = pyOff + px;
                    sumXX += jxx[pidx] * w;
                    sumYY += jyy[pidx] * w;
                    sumXY += jxy[pidx] * w;
                    weightSum += w;
                }
            }
            int idx = yOff + x;
            sxx[idx] = sumXX / weightSum;
            syy[idx] = sumYY / weightSum;
            sxy[idx] = sumXY / weightSum;
        }
    }
}

void HairOrientationEngine::regularizeVectorField(
    int width,
    int height,
    int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
    const float* alpha,
    std::vector<float>& inoutVx,
    std::vector<float>& inoutVy,
    std::vector<float>& inoutConfidence
) {
    const int total = width * height;
    std::vector<float> tempVx = inoutVx;
    std::vector<float> tempVy = inoutVy;
    std::vector<float> tempConf = inoutConfidence;

    // Bộ lọc làm mịn định hướng không gian bán kính 2 (5x5) có trọng số confidence và alpha
    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            int idx = yOff + x;
            if (alpha[idx] < 0.05f) {
                inoutVx[idx] = 0.0f;
                inoutVy[idx] = 0.0f;
                inoutConfidence[idx] = 0.0f;
                continue;
            }

            float sumVx = 0.0f;
            float sumVy = 0.0f;
            float sumConf = 0.0f;
            float totalWeight = 0.0f;

            for (int dy = -2; dy <= 2; ++dy) {
                int py = std::clamp(y + dy, 0, height - 1);
                int pyOff = py * width;
                for (int dx = -2; dx <= 2; ++dx) {
                    int px = std::clamp(x + dx, 0, width - 1);
                    int pidx = pyOff + px;
                    float a = alpha[pidx];
                    if (a < 0.05f) continue;

                    float c = tempConf[pidx];
                    float spatialDist2 = static_cast<float>(dx * dx + dy * dy);
                    float w = a * (0.2f + 0.8f * c) * std::exp(-spatialDist2 * 0.15f);

                    sumVx += tempVx[pidx] * w;
                    sumVy += tempVy[pidx] * w;
                    sumConf += c * w;
                    totalWeight += w;
                }
            }

            if (totalWeight > 1e-4f) {
                float norm = std::sqrt(sumVx * sumVx + sumVy * sumVy);
                if (norm > 1e-5f) {
                    inoutVx[idx] = sumVx / norm;
                    inoutVy[idx] = sumVy / norm;
                }
                inoutConfidence[idx] = std::clamp(sumConf / totalWeight, 0.0f, 1.0f);
            }
        }
    }
}

} // namespace meitu_native::hce

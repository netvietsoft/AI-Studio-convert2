#include "hair/hair_texture_engine.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <omp.h>

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)

namespace meitu_native::hce {

HairTextureEngine& HairTextureEngine::getInstance() {
    static HairTextureEngine instance;
    return instance;
}

bool HairTextureEngine::extractTexture(
    const uint32_t* srcPixels,
    int width,
    int height,
    const P0HairMatteAdapter& p0Matte,
    const HairOrientationField& orientation,
    HairTextureContext& outTexture
) {
    if (!srcPixels || width <= 0 || height <= 0 || !p0Matte.alphaData) {
        outTexture.isValid = false;
        return false;
    }

    const int total = width * height;
    outTexture.width = width;
    outTexture.height = height;
    outTexture.lowFreqBase.assign(total, 0.0f);
    outTexture.highFreqDetail.assign(total, 0.0f);
    outTexture.directionalResponse.assign(total, 0.0f);
    outTexture.textureConfidence.assign(total, 0.0f);

    std::vector<float> lum(total, 0.0f);
    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < total; ++i) {
        uint32_t c = srcPixels[i];
        lum[i] = 0.299f * RGBA_R(c) + 0.587f * RGBA_G(c) + 0.114f * RGBA_B(c);
    }

    int roiMinX = (p0Matte.roiMaxX > p0Matte.roiMinX) ? std::max(2, p0Matte.roiMinX) : 2;
    int roiMaxX = (p0Matte.roiMaxX > p0Matte.roiMinX) ? std::min(width - 3, p0Matte.roiMaxX) : width - 3;
    int roiMinY = (p0Matte.roiMaxY > p0Matte.roiMinY) ? std::max(2, p0Matte.roiMinY) : 2;
    int roiMaxY = (p0Matte.roiMaxY > p0Matte.roiMinY) ? std::min(height - 3, p0Matte.roiMaxY) : height - 3;

    const float* alpha = p0Matte.alphaData;

    // 1. Phân tách tần số đa tỉ lệ (Multi-scale decomposition)
    decomposeFrequencies(
        lum.data(), width, height,
        roiMinX, roiMinY, roiMaxX, roiMaxY,
        alpha,
        outTexture.lowFreqBase,
        outTexture.highFreqDetail
    );

    // 2. Lọc định hướng theo trường dòng chảy P1 (Directional Filtering)
    computeDirectionalFilter(
        outTexture.highFreqDetail.data(),
        width, height,
        roiMinX, roiMinY, roiMaxX, roiMaxY,
        orientation,
        alpha,
        outTexture.directionalResponse
    );

    // 3. Tính toán độ tin cậy kết cấu (Texture Confidence)
    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            int idx = yOff + x;
            float a = alpha[idx];
            if (a < 0.05f) continue;

            float hfMag = std::abs(outTexture.highFreqDetail[idx]);
            float dirMag = std::abs(outTexture.directionalResponse[idx]);
            float flowConf = orientation.isValid ? orientation.confidence[idx] : 0.5f;

            // Kết hợp năng lượng tần số cao và độ đồng hướng của sợi
            float conf = std::clamp((hfMag * 0.03f + dirMag * 0.05f) * (0.4f + 0.6f * flowConf), 0.0f, 1.0f);
            outTexture.textureConfidence[idx] = conf;
        }
    }

    outTexture.isValid = true;
    return true;
}

void HairTextureEngine::decomposeFrequencies(
    const float* lum,
    int width,
    int height,
    int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
    const float* alpha,
    std::vector<float>& outLowFreq,
    std::vector<float>& outHighFreq
) {
    const int total = width * height;
    std::vector<float> tempH(total, 0.0f);

    // Bộ lọc tách nền không gian 2 chiều bán kính 4 pixel
    const int r = 4;
    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            float sum = 0.0f;
            int count = 0;
            int xStart = std::max(0, x - r);
            int xEnd = std::min(width - 1, x + r);
            for (int kx = xStart; kx <= xEnd; ++kx) {
                sum += lum[yOff + kx];
                count++;
            }
            tempH[yOff + x] = sum / count;
        }
    }

    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            float sum = 0.0f;
            int count = 0;
            int yStart = std::max(0, y - r);
            int yEnd = std::min(height - 1, y + r);
            for (int ky = yStart; ky <= yEnd; ++ky) {
                sum += tempH[ky * width + x];
                count++;
            }
            int idx = yOff + x;
            float low = sum / count;
            outLowFreq[idx] = low;
            outHighFreq[idx] = lum[idx] - low; // Chi tiết vi mô
        }
    }
}

void HairTextureEngine::computeDirectionalFilter(
    const float* highFreq,
    int width,
    int height,
    int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
    const HairOrientationField& orientation,
    const float* alpha,
    std::vector<float>& outDirectional
) {
    #pragma omp parallel for schedule(static, 16)
    for (int y = roiMinY; y <= roiMaxY; ++y) {
        int yOff = y * width;
        for (int x = roiMinX; x <= roiMaxX; ++x) {
            int idx = yOff + x;
            if (alpha[idx] < 0.05f) continue;

            float vx = orientation.isValid ? orientation.dirX[idx] : -1.0f;
            float vy = orientation.isValid ? orientation.dirY[idx] : 0.0f;

            // Khôi phục góc theta từ góc kép: theta = 0.5 * atan2(vy, vx)
            float theta = 0.5f * std::atan2(vy, vx);
            float cosT = std::cos(theta);
            float sinT = std::sin(theta);

            // Vector pháp tuyến ngang sợi tóc (across flow): normal = (-sinT, cosT)
            float nx = -sinT;
            float ny = cosT;

            // Lấy mẫu đạo hàm cấp 2 ngang qua sợi tóc (Laplacian of Gaussian định hướng)
            int step = 2;
            int xP = std::clamp(static_cast<int>(std::round(x + step * nx)), 0, width - 1);
            int yP = std::clamp(static_cast<int>(std::round(y + step * ny)), 0, height - 1);
            int xM = std::clamp(static_cast<int>(std::round(x - step * nx)), 0, width - 1);
            int yM = std::clamp(static_cast<int>(std::round(y - step * ny)), 0, height - 1);

            float centerVal = highFreq[idx];
            float valP = highFreq[yP * width + xP];
            float valM = highFreq[yM * width + xM];

            // Tăng cường tương phản sống sợi tóc
            float ridgeResponse = 2.0f * centerVal - (valP + valM);
            outDirectional[idx] = ridgeResponse;
        }
    }
}

} // namespace meitu_native::hce

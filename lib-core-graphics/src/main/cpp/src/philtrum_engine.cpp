#include "philtrum_engine.h"
#include "liquify_warp.h"
#include "head_semantic_model.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <omp.h>
#include <android/log.h>

#define LOG_TAG PhiltrumEngine
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define MAKE_RGBA(r, g, b, a) (((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(g) << 8) | ((uint32_t)(r)))

namespace meitu_native {

namespace {

inline void rgb2yuv(uint8_t r, uint8_t g, uint8_t b, float& y, float& u, float& v) {
    y = 0.299f * r + 0.587f * g + 0.114f * b;
    u = -0.14713f * r - 0.28886f * g + 0.436f * b;
    v = 0.615f * r - 0.51499f * g - 0.10001f * b;
}

inline void yuv2rgb(float y, float u, float v, uint8_t& r, uint8_t& g, uint8_t& b) {
    float rf = y + 1.13983f * v;
    float gf = y - 0.39465f * u - 0.58060f * v;
    float bf = y + 2.03211f * u;
    r = static_cast<uint8_t>(std::clamp(rf, 0.0f, 255.0f));
    g = static_cast<uint8_t>(std::clamp(gf, 0.0f, 255.0f));
    b = static_cast<uint8_t>(std::clamp(bf, 0.0f, 255.0f));
}

} // namespace

bool PhiltrumEngine::applyPhiltrumEdit(
    uint32_t* pixels,
    int width,
    int height,
    const HeadFrameResult& headModel,
    int paramId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || std::abs(intensity) < 0.001f) {
        return false;
    }
    if (!headModel.isFaceDetected) {
        return false;
    }

    float p = std::clamp(intensity, -1.0f, 1.0f);
    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;

    Point2DF baseNose = headModel.philtrum.baseNose;
    Point2DF cupidBow = headModel.philtrum.cupidsBowCenter;
    float pLen = headModel.philtrum.length;
    float pWidth = headModel.philtrum.width;

    if (pLen <= 2.0f || pWidth <= 2.0f) {
        // Fallback xap xi tu mui va mieng neu model chua trinh dien day du
        baseNose = headModel.nose.tip;
        cupidBow = headModel.mouthLip.upperLipTop;
        pLen = std::abs(cupidBow.y - baseNose.y);
        pWidth = headModel.mouthLip.mouthWidth * 0.28f;
    }

    float philtrumMidX = (baseNose.x + cupidBow.x) * 0.5f;
    float philtrumMidY = (baseNose.y + cupidBow.y) * 0.5f;

    // Snapshot goc de bao ve pixel ngoai le vi pham ROI
    std::vector<uint32_t> origSnapshot(width * height);
    std::copy(pixels, pixels + (width * height), origSnapshot.begin());

    switch (paramId) {
        case PARAM_PHILTRUM_LENGTH: {
            // 1. THU NGẮN / KÉO DÀI NHÂN TRUNG
            // Thu ngắn nhân trung nâng nhẹ viền môi trên và trụ nhân trung lên sát chân mũi
            float warpStr = std::clamp(p * 1.35f, -1.5f, 1.5f);
            float radius = std::max(22.0f * sx, pLen * 0.75f);

            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                philtrumMidX, cupidBow.y - 4.0f * sy,
                philtrumMidX, cupidBow.y - 4.0f * sy - 15.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            break;
        }

        case PARAM_PHILTRUM_WIDTH: {
            // 2. THU HẸP / MỞ RỘNG HAI TRỤ NHÂN TRUNG
            float warpStr = std::clamp(p * 1.25f, -1.5f, 1.5f);
            float radius = std::max(18.0f * sx, pWidth * 0.65f);

            // Ép trụ trái vào tâm
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                philtrumMidX - pWidth * 0.45f, philtrumMidY,
                philtrumMidX - pWidth * 0.45f + 8.0f * sx * p, philtrumMidY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );

            // Ép trụ phải vào tâm
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                philtrumMidX + pWidth * 0.45f, philtrumMidY,
                philtrumMidX + pWidth * 0.45f - 8.0f * sx * p, philtrumMidY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            break;
        }

        case PARAM_PHILTRUM_GROOVE_DEPTH: {
            // 3. ĐỘ SÂU RÃNH NHÂN TRUNG (3D Photometric Shading & Highlight Sculpture)
            // Tạo rãnh lõm sâu thanh tú tự nhiên bằng cách điều chỉnh độ sáng bề mặt (Y channel)
            float axisDx = cupidBow.x - baseNose.x;
            float axisDy = cupidBow.y - baseNose.y;
            float axisLen = std::sqrt(axisDx * axisDx + axisDy * axisDy);
            if (axisLen < 1.0f) axisLen = 1.0f;
            float normX = -axisDy / axisLen;
            float normY = axisDx / axisLen;

            int minX = std::clamp(static_cast<int>(std::floor(philtrumMidX - pWidth * 1.2f)), 0, width - 1);
            int maxX = std::clamp(static_cast<int>(std::ceil(philtrumMidX + pWidth * 1.2f)), 0, width - 1);
            int minY = std::clamp(static_cast<int>(std::floor(baseNose.y + 2.0f)), 0, height - 1);
            int maxY = std::clamp(static_cast<int>(std::ceil(cupidBow.y - 1.0f)), 0, height - 1);

            float halfColW = pWidth * 0.5f;

            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = minY; y <= maxY; ++y) {
                float fy = static_cast<float>(y);
                for (int x = minX; x <= maxX; ++x) {
                    float fx = static_cast<float>(x);

                    // Chiếu điểm (fx, fy) lên trục nhân trung
                    float vx = fx - baseNose.x;
                    float vy = fy - baseNose.y;
                    float axialT = (vx * axisDx + vy * axisDy) / (axisLen * axisLen);

                    // Chỉ xử lý trong khoảng giữa chân mũi và viền môi trên
                    if (axialT <= 0.05f || axialT >= 0.95f) continue;

                    // Khoảng cách ngang từ trục tâm (theo phương pháp tuyến)
                    float lateralDist = (vx * normX + vy * normY);
                    float normDist = lateralDist / halfColW; // -1.0 tới +1.0 là lòng rãnh

                    // Trọng số dọc (dạng hình chuông mượt)
                    float axialWeight = std::sin(axialT * 3.14159265f);

                    float deltaL = 0.0f;
                    if (std::abs(normDist) < 0.45f) {
                        // Vùng lòng rãnh trung tâm: Đổ bóng nhẹ tạo chiều sâu (Shadow)
                        float grooveDepthShape = (1.0f - std::abs(normDist) / 0.45f);
                        deltaL = -18.0f * p * grooveDepthShape * axialWeight;
                    } else if (std::abs(normDist) >= 0.45f && std::abs(normDist) <= 1.0f) {
                        // Hai gờ trụ nhân trung bên cạnh: Tăng sáng nổi khối (Highlight)
                        float ridgeShape = std::sin(((std::abs(normDist) - 0.45f) / 0.55f) * 3.14159265f);
                        deltaL = +15.0f * p * ridgeShape * axialWeight;
                    }

                    if (std::abs(deltaL) > 0.05f) {
                        int idx = y * width + x;
                        uint32_t c = pixels[idx];
                        uint8_t r = RGBA_R(c), g = RGBA_G(c), b = RGBA_B(c), a = RGBA_A(c);

                        float Y, U, V;
                        rgb2yuv(r, g, b, Y, U, V);
                        Y = std::clamp(Y + deltaL, 0.0f, 255.0f);

                        uint8_t outR, outG, outB;
                        yuv2rgb(Y, U, V, outR, outG, outB);
                        pixels[idx] = MAKE_RGBA(outR, outG, outB, a);
                    }
                }
            }
            break;
        }

        case PARAM_PHILTRUM_CUPID_ACCENT: {
            // 4. ĐỊNH HÌNH ĐỈNH CHỮ M CUNG MÔI CUPID'S BOW
            float warpStr = std::clamp(p * 1.35f, -1.5f, 1.5f);
            float radius = std::max(16.0f * sx, pWidth * 0.5f);

            // Nâng nhẹ 2 đỉnh cánh tiên chữ M
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                philtrumMidX - pWidth * 0.35f, cupidBow.y,
                philtrumMidX - pWidth * 0.35f, cupidBow.y - 7.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );

            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                philtrumMidX + pWidth * 0.35f, cupidBow.y,
                philtrumMidX + pWidth * 0.35f, cupidBow.y - 7.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            break;
        }

        default:
            return false;
    }

    // Bảo vệ nền và vùng xung quanh nhân trung (Bit-exact boundary protection)
    float safeBoxX1 = philtrumMidX - pWidth * 2.2f;
    float safeBoxX2 = philtrumMidX + pWidth * 2.2f;
    float safeBoxY1 = baseNose.y - 8.0f * sy;
    float safeBoxY2 = cupidBow.y + pLen * 0.8f;

    #pragma omp parallel for schedule(dynamic, 64)
    for (int y = 0; y < height; ++y) {
        float fy = static_cast<float>(y);
        for (int x = 0; x < width; ++x) {
            float fx = static_cast<float>(x);
            int idx = y * width + x;

            if (fx < safeBoxX1 || fx > safeBoxX2 || fy < safeBoxY1 || fy > safeBoxY2) {
                pixels[idx] = origSnapshot[idx];
            }
        }
    }

    return true;
}

} // namespace meitu_native

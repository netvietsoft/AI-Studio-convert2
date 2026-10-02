#include "head_skull_engine.h"
#include "liquify_warp.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <omp.h>
#include <android/log.h>

#define LOG_TAG "HeadSkullEngine"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

namespace meitu_native {

bool HeadSkullEngine::applyHeadSkullReshape(
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
    if (!headModel.isFaceDetected || !headModel.headGeometry.isValid) {
        return false;
    }

    float p = std::clamp(intensity, -1.0f, 1.0f);
    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;

    const auto& geo = headModel.headGeometry;
    const auto& fhead = headModel.foreheadTemple;
    const auto& jchin = headModel.jawChin;

    float headCenterX = geo.headBox.centerX();
    float foreheadY = fhead.center.y;
    float crownTopY = geo.headBox.y1;
    float chinY = jchin.chinTip.y;
    float headW = geo.headWidth;
    float headH = geo.headHeight;

    // Chup snapshot nguyen ban de bao toan 100% bat bien nen ben ngoai
    std::vector<uint32_t> origSnapshot(width * height);
    std::copy(pixels, pixels + (width * height), origSnapshot.begin());

    switch (paramId) {
        case PARAM_HEAD_SIZE: {
            // 1. THU NHỎ ĐẦU / ĐẦU TO TỶ LỆ VÀNG (Mục 3 SPEC)
            // Ép đỉnh sọ, hai bên thái dương và cung xương sọ vào tâm
            float warpStr = std::clamp(p * 1.35f, -1.6f, 1.6f);
            float crownR = std::max(60.0f * sx, headW * 0.35f);

            // Đỉnh sọ (Crown Top)
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                headCenterX, crownTopY + 15.0f * sy,
                headCenterX, crownTopY + 15.0f * sy + 25.0f * sy * p,
                crownR, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );

            // Thái dương & vòm sọ trái (Left Temple & Parietal)
            float lParietalX = headCenterX - headW * 0.40f;
            float lParietalY = (crownTopY + foreheadY) * 0.5f;
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                lParietalX, lParietalY,
                lParietalX + 22.0f * sx * p, lParietalY + 10.0f * sy * p,
                crownR * 0.85f, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );

            // Thái dương & vòm sọ phải (Right Parietal)
            float rParietalX = headCenterX + headW * 0.40f;
            float rParietalY = (crownTopY + foreheadY) * 0.5f;
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                rParietalX, rParietalY,
                rParietalX - 22.0f * sx * p, rParietalY + 10.0f * sy * p,
                crownR * 0.85f, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            break;
        }

        case PARAM_SKULL_CROWN: {
            // 2. NÂNG VÒM SỌ / ĐẦU TRÒN ĐẦY (Calvarium Skull Crown Reshape — Mục 3 SPEC)
            // Nâng vòm đỉnh sọ lên trên tạo dáng đầu tròn quý phái, thanh tú
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = std::max(55.0f * sx, headW * 0.32f);

            // Đỉnh giữa
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                headCenterX, crownTopY + 20.0f * sy,
                headCenterX, crownTopY + 20.0f * sy - 30.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );

            // Vòm sọ bên trái
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                headCenterX - headW * 0.25f, crownTopY + 30.0f * sy,
                headCenterX - headW * 0.25f - 10.0f * sx * p, crownTopY + 30.0f * sy - 22.0f * sy * p,
                radius * 0.9f, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );

            // Vòm sọ bên phải
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                headCenterX + headW * 0.25f, crownTopY + 30.0f * sy,
                headCenterX + headW * 0.25f + 10.0f * sx * p, crownTopY + 30.0f * sy - 22.0f * sy * p,
                radius * 0.9f, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            break;
        }

        case PARAM_TEMPLE_WIDTH: {
            // 3. CHIỀU RỘNG THÁI DƯƠNG (Temple Width — Mục 7 SPEC)
            float warpStr = std::clamp(p * 1.3f, -1.5f, 1.5f);
            float radius = std::max(45.0f * sx, headW * 0.22f);

            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                fhead.leftTempleX, fhead.leftTempleY,
                fhead.leftTempleX - 25.0f * sx * p, fhead.leftTempleY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );

            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                fhead.rightTempleX, fhead.rightTempleY,
                fhead.rightTempleX + 25.0f * sx * p, fhead.rightTempleY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            break;
        }

        case PARAM_FOREHEAD_RESHAPE: {
            // 4. CHIỀU CAO & VÒM TRÁN (Forehead Height & Curvature — Mục 7 SPEC)
            float warpStr = std::clamp(p * 1.35f, -1.5f, 1.5f);
            float radius = std::max(50.0f * sx, headW * 0.28f);

            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                headCenterX, foreheadY,
                headCenterX, foreheadY - 25.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            break;
        }

        case PARAM_FACE_HEAD_RATIO: {
            // 5. CÂN BẰNG TỶ LỆ MẶT/ĐẦU (Face-to-Head Ratio — Mục 3 SPEC)
            float warpStr = std::clamp(p * 1.25f, -1.4f, 1.4f);
            float radius = std::max(50.0f * sx, headW * 0.30f);

            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                headCenterX, crownTopY + 15.0f * sy,
                headCenterX, crownTopY + 15.0f * sy - 20.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            break;
        }

        default:
            return false;
    }

    // BẢO VỆ PHÔNG NỀN TUYỆT ĐỐI (BACKGROUND INVARIANCE):
    // Các điểm nằm ngoài vùng ảnh hưởng của đầu và tóc được phục hồi nguyên trạng 100% bit-exact
    float safeMarginX = headW * 0.65f;
    float safeTopY = std::max(0.0f, crownTopY - 45.0f * sy);
    float safeBottomY = chinY + 50.0f * sy;

    #pragma omp parallel for schedule(dynamic, 64)
    for (int y = 0; y < height; ++y) {
        float fy = static_cast<float>(y);
        for (int x = 0; x < width; ++x) {
            float fx = static_cast<float>(x);
            int idx = y * width + x;

            // Nằm ngoài hộp bao đầu mở rộng: Khôi phục bit-exact
            if (fy < safeTopY || fy > safeBottomY ||
                fx < (headCenterX - safeMarginX) || fx > (headCenterX + safeMarginX)) {
                pixels[idx] = origSnapshot[idx];
            }
        }
    }

    LOGI("✅ HeadSkullEngine applied param %d successfully, intensity=%.2f", paramId, intensity);
    return true;
}

} // namespace meitu_native

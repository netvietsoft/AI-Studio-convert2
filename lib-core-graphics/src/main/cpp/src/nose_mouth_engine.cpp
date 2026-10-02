#include "nose_mouth_engine.h"
#include "liquify_warp.h"
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

// =========================================================================
// 1. CHỈNH HÌNH DÁNG MŨI (2.5 NOSE)
// =========================================================================
bool NoseMouthEngine::applyNoseReshape(
    uint32_t* pixels,
    int width,
    int height,
    float noseX, float noseY,
    int paramId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || std::abs(intensity) < 0.001f) {
        return false;
    }

    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;
    float p = std::clamp(intensity, -1.0f, 1.0f);

    switch (paramId) {
        case PARAM_NOSE_SHRINK: {
            // Thu 2 cánh mũi vào tâm: song song 2 bên cánh mũi
            float warpStr = std::clamp(p * 1.5f, -1.8f, 1.8f);
            float radius = 55.0f * sx;
            float wingOffset = 38.0f * sx;

            // Cánh mũi trái đẩy sang phải
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                noseX - wingOffset, noseY,
                noseX - wingOffset + 18.0f * sx * p, noseY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            // Cánh mũi phải đẩy sang trái
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                noseX + wingOffset, noseY,
                noseX + wingOffset - 18.0f * sx * p, noseY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_NOSE_TIP: {
            // Thu nhỏ và nâng đầu mũi: PINCH tại chóp mũi
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = 48.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                noseX, noseY + 6.0f * sy,
                noseX, noseY + 6.0f * sy,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PINCH
            );
            // Đẩy nhẹ chóp mũi lên tạo độ thon thanh tú
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                noseX, noseY + 12.0f * sy,
                noseX, noseY + 12.0f * sy - 8.0f * sy * p,
                radius * 0.8f, warpStr * 0.7f,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_NOSE_ROOT: {
            // Nâng sống mũi và chân mũi (Nasal Root): Nén hẹp sống mũi 2 bên tạo khối cao
            float warpStr = std::clamp(p * 1.3f, -1.5f, 1.5f);
            float radius = 45.0f * sx;
            float rootY = noseY - 55.0f * sy;

            // Sống mũi trái ép vào
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                noseX - 25.0f * sx, rootY,
                noseX - 25.0f * sx + 10.0f * sx * p, rootY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            // Sống mũi phải ép vào
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                noseX + 25.0f * sx, rootY,
                noseX + 25.0f * sx - 10.0f * sx * p, rootY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_NOSE_LONGER: {
            // Kéo dài đầu mũi xuống dưới
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = 55.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                noseX, noseY,
                noseX, noseY + 18.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_NOSE_RESIZE: {
            // Thu nhỏ tổng thể mũi (Pinch toàn bộ vùng mũi)
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = 75.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                noseX, noseY - 15.0f * sy,
                noseX, noseY - 15.0f * sy,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PINCH
            );
            return true;
        }

        case PARAM_NOSE_DISTANCE: {
            // Điều chỉnh khoảng cách mũi - trán: Đẩy toàn bộ gốc mũi lên trên hoặc xuống dưới
            float warpStr = std::clamp(p * 1.2f, -1.5f, 1.5f);
            float radius = 80.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                noseX, noseY - 30.0f * sy,
                noseX, noseY - 30.0f * sy - 14.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_NOSE_NARROW: {
            // Thu hẹp tổng thể cả tháp mũi (Dorsal hump + Wings)
            float warpStr = std::clamp(p * 1.5f, -1.8f, 1.8f);
            float radius = 60.0f * sx;

            // Ép từ 2 bên tháp mũi
            for (int step = -2; step <= 1; ++step) {
                float curY = noseY + static_cast<float>(step) * 25.0f * sy;
                MTLiquifyImage::applyWarp(
                    pixels, width, height,
                    noseX - 35.0f * sx, curY,
                    noseX - 35.0f * sx + 12.0f * sx * p, curY,
                    radius, warpStr * 0.8f,
                    MTLiquifyImage::WARP_MODE_PUSH
                );
                MTLiquifyImage::applyWarp(
                    pixels, width, height,
                    noseX + 35.0f * sx, curY,
                    noseX + 35.0f * sx - 12.0f * sx * p, curY,
                    radius, warpStr * 0.8f,
                    MTLiquifyImage::WARP_MODE_PUSH
                );
            }
            return true;
        }

        default:
            return false;
    }
}

// =========================================================================
// 2. CHỈNH HÌNH DÁNG MÔI & MIỆNG (2.6 MOUTH / LIPS)
// =========================================================================
bool NoseMouthEngine::applyMouthReshape(
    uint32_t* pixels,
    int width,
    int height,
    float mouthX, float mouthY,
    int paramId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || std::abs(intensity) < 0.001f) {
        return false;
    }

    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;
    float p = std::clamp(intensity, -1.0f, 1.0f);

    switch (paramId) {
        case PARAM_LIP_OVERALL: {
            // Làm căng mọng cả môi trên và môi dưới
            float warpStr = std::clamp(p * 1.5f, -1.8f, 1.8f);
            float radius = 65.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX, mouthY,
                mouthX, mouthY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_EXPAND
            );
            return true;
        }

        case PARAM_UPPER_LIP: {
            // Môi trên dày hơn: Đẩy viền môi trên lên và nở nhẹ
            float warpStr = std::clamp(p * 1.3f, -1.5f, 1.5f);
            float radius = 50.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX, mouthY - 12.0f * sy,
                mouthX, mouthY - 12.0f * sy - 8.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_LOWER_LIP: {
            // Môi dưới dày hơn: Đẩy bờ môi dưới xuống tạo độ mọng hờ hững
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = 55.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX, mouthY + 16.0f * sy,
                mouthX, mouthY + 16.0f * sy + 10.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_MOUTH_WIDTH: {
            // Thu nhỏ / nới rộng chiều ngang khóe miệng
            float warpStr = std::clamp(p * 1.4f, -1.7f, 1.7f);
            float radius = 45.0f * sx;
            float cornerOffset = 52.0f * sx;

            // Khóe miệng trái ép vào tâm (hoặc kéo ra)
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX - cornerOffset, mouthY,
                mouthX - cornerOffset + 14.0f * sx * p, mouthY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            // Khóe miệng phải ép vào tâm (hoặc kéo ra)
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX + cornerOffset, mouthY,
                mouthX + cornerOffset - 14.0f * sx * p, mouthY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_MOUTH_ROTATE: {
            // Xoay nhẹ khuôn miệng cân chỉnh méo
            float warpStr = std::clamp(p * 1.2f, -1.5f, 1.5f);
            float radius = 45.0f * sx;
            float cornerOffset = 50.0f * sx;

            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX - cornerOffset, mouthY,
                mouthX - cornerOffset, mouthY + 8.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX + cornerOffset, mouthY,
                mouthX + cornerOffset, mouthY - 8.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_MOUTH_LATERAL: {
            // Dịch chuyển khuôn miệng sang trái/phải
            float warpStr = std::clamp(p * 1.3f, -1.5f, 1.5f);
            float radius = 70.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX, mouthY,
                mouthX + 16.0f * sx * p, mouthY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_PHILTRUM_HIGH: {
            // Thu ngắn nhân trung: Kéo toàn bộ môi trên lên gần chân mũi
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = 60.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX, mouthY - 18.0f * sy,
                mouthX, mouthY - 18.0f * sy - 12.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_PHILTRUM_WARP: {
            // Tạo rãnh nhân trung sâu và nét Cupid's Bow
            float warpStr = std::clamp(p * 1.3f, -1.5f, 1.5f);
            float radius = 35.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX, mouthY - 20.0f * sy,
                mouthX, mouthY - 20.0f * sy,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PINCH
            );
            return true;
        }

        case PARAM_COMIC_MOUTH_M: {
            // Môi kiểu M (môi cánh én / trái tim): Nhấn đỉnh nhân trung và 2 bên khóe cười
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = 38.0f * sx;

            // Nhấn đỉnh giữa môi trên xuống nhẹ
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX, mouthY - 10.0f * sy,
                mouthX, mouthY - 10.0f * sy + 5.0f * sy * p,
                radius, warpStr * 0.8f,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            // Nâng 2 gờ cánh môi 2 bên lên
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX - 18.0f * sx, mouthY - 14.0f * sy,
                mouthX - 18.0f * sx, mouthY - 14.0f * sy - 6.0f * sy * p,
                radius, warpStr * 0.9f,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX + 18.0f * sx, mouthY - 14.0f * sy,
                mouthX + 18.0f * sx, mouthY - 14.0f * sy - 6.0f * sy * p,
                radius, warpStr * 0.9f,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_CONVEX_MOUTH: {
            // Thu môi vổ / giảm nhô môi: Đẩy môi vào trong và thu gọn
            float warpStr = std::clamp(p * 1.3f, -1.5f, 1.5f);
            float radius = 65.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX, mouthY,
                mouthX, mouthY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PINCH
            );
            return true;
        }

        case PARAM_SMILE: {
            // Nụ cười rạng rỡ: Nâng 2 khóe miệng lên trên và ra ngoài
            float warpStr = std::clamp(p * 1.4f, -1.7f, 1.7f);
            float radius = 50.0f * sx;
            float cornerOffset = 52.0f * sx;

            // Khóe môi trái kéo lên chếch 45 độ
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX - cornerOffset, mouthY,
                mouthX - cornerOffset - 4.0f * sx * p, mouthY - 16.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            // Khóe môi phải kéo lên chếch 45 độ
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX + cornerOffset, mouthY,
                mouthX + cornerOffset + 4.0f * sx * p, mouthY - 16.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_LIP_BUNNY: {
            // Môi thỏ tròn đầy (Bunny Lips): Nở 2 hạt ngọc môi trên và làm mọng môi dưới
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = 35.0f * sx;

            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX - 10.0f * sx, mouthY - 8.0f * sy,
                mouthX - 10.0f * sx, mouthY - 8.0f * sy,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_EXPAND
            );
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX + 10.0f * sx, mouthY - 8.0f * sy,
                mouthX + 10.0f * sx, mouthY - 8.0f * sy,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_EXPAND
            );
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                mouthX, mouthY + 12.0f * sy,
                mouthX, mouthY + 12.0f * sy,
                radius * 1.2f, warpStr * 0.9f,
                MTLiquifyImage::WARP_MODE_EXPAND
            );
            return true;
        }

        default:
            return false;
    }
}

} // namespace meitu_native

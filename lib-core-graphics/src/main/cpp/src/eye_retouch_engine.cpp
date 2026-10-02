#include "eye_retouch_engine.h"
#include "liquify_warp.h"
#include "color_lut.h"
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
// 1. CHỈNH HÌNH DÁNG MẮT (EYE SHAPE & MORPH)
// =========================================================================
bool EyeRetouchEngine::applyEyeShape(
    uint32_t* pixels,
    int width,
    int height,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
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
        case PARAM_EYE_ENLARGE: {
            // Mắt to tự nhiên: bán kính hốc mắt 65*sx, độ biến dạng chuẩn
            float eyeRadius = 65.0f * sx;
            float eyeWarp = std::abs(p) * 1.0f;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye, lyEye, lxEye, lyEye, eyeRadius, eyeWarp, (p >= 0 ? WARP_EXPAND : WARP_PINCH));
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye, ryEye, rxEye, ryEye, eyeRadius, eyeWarp, (p >= 0 ? WARP_EXPAND : WARP_PINCH));
            break;
        }
        case PARAM_EYE_HEIGHT: {
            // Chiều cao mắt: Đẩy mí trên lên và mí dưới xuống
            float pushY = 22.0f * sy * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye, lyEye - 20.0f * sy, lxEye, lyEye - 20.0f * sy - pushY, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye, lyEye + 18.0f * sy, lxEye, lyEye + 18.0f * sy + pushY, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye, ryEye - 20.0f * sy, rxEye, ryEye - 20.0f * sy - pushY, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye, ryEye + 18.0f * sy, rxEye, ryEye + 18.0f * sy + pushY, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_EYE_WIDTH: {
            // Chiều rộng mắt: Kéo dài hai khóe mắt
            float pushX = 26.0f * sx * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye - 40.0f * sx, lyEye, lxEye - 40.0f * sx - pushX, lyEye, 50.0f * sx, std::abs(p) * 1.3f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye + 40.0f * sx, lyEye, lxEye + 40.0f * sx + pushX * 0.6f, lyEye, 50.0f * sx, std::abs(p) * 1.3f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye + 40.0f * sx, ryEye, rxEye + 40.0f * sx + pushX, ryEye, 50.0f * sx, std::abs(p) * 1.3f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye - 40.0f * sx, ryEye, rxEye - 40.0f * sx - pushX * 0.6f, ryEye, 50.0f * sx, std::abs(p) * 1.3f, WARP_PUSH);
            break;
        }
        case PARAM_EYE_TILT: {
            // Góc nghiêng mắt (Nâng/Hạ đuôi mắt)
            float tiltShift = 28.0f * sy * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye - 45.0f * sx, lyEye, lxEye - 45.0f * sx, lyEye - tiltShift, 55.0f * sx, std::abs(p) * 1.5f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye + 45.0f * sx, ryEye, rxEye + 45.0f * sx, ryEye - tiltShift, 55.0f * sx, std::abs(p) * 1.5f, WARP_PUSH);
            break;
        }
        case PARAM_EYE_UPDOWN: {
            // Vị trí mắt cao/thấp
            float shiftY = 30.0f * sy * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye, lyEye, lxEye, lyEye + shiftY, 95.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye, ryEye, rxEye, ryEye + shiftY, 95.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_EYE_LONGER: {
            // Mắt dài hơn (Kéo đuôi mắt ngang)
            float stretch = 35.0f * sx * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye - 45.0f * sx, lyEye, lxEye - 45.0f * sx - stretch, lyEye, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye + 45.0f * sx, ryEye, rxEye + 45.0f * sx + stretch, ryEye, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_EYE_END: {
            // Đuôi mắt: Nâng nhẹ và mở đuôi
            float endShiftX = 25.0f * sx * p;
            float endShiftY = 22.0f * sy * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye - 50.0f * sx, lyEye, lxEye - 50.0f * sx - endShiftX, lyEye - endShiftY, 50.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye + 50.0f * sx, ryEye, rxEye + 50.0f * sx + endShiftX, ryEye - endShiftY, 50.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_EYE_EYELID: {
            // Mí mắt: Nâng mí trên
            float creaseShift = 24.0f * sy * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye, lyEye - 25.0f * sy, lxEye, lyEye - 25.0f * sy - creaseShift, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye, ryEye - 25.0f * sy, rxEye, ryEye - 25.0f * sy - creaseShift, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_EYE_INNER_CORNER: {
            // Góc mắt trong: Mở rộng khóe mắt trong
            float cornerShift = 22.0f * sx * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye + 45.0f * sx, lyEye, lxEye + 45.0f * sx + cornerShift, lyEye + cornerShift * 0.3f, 45.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye - 45.0f * sx, ryEye, rxEye - 45.0f * sx - cornerShift, ryEye + cornerShift * 0.3f, 45.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_EYE_OUTER_CORNER: {
            // Góc mắt ngoài: Mở góc mắt ngoài
            float cornerShift = 26.0f * sx * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye - 50.0f * sx, lyEye, lxEye - 50.0f * sx - cornerShift, lyEye, 48.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye + 50.0f * sx, ryEye, rxEye + 50.0f * sx + cornerShift, ryEye, 48.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_EYE_INNER_CANTHUS_ADJ: {
            // Mắt phượng: Khóe trong hạ nhọn xuống + Đuôi mắt xếch vút lên
            float inY = 18.0f * sy * p;
            float outY = 32.0f * sy * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye + 45.0f * sx, lyEye, lxEye + 45.0f * sx + 10.0f * sx * p, lyEye + inY, 45.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye - 50.0f * sx, lyEye, lxEye - 50.0f * sx - 15.0f * sx * p, lyEye - outY, 52.0f * sx, std::abs(p) * 1.5f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye - 45.0f * sx, ryEye, rxEye - 45.0f * sx - 10.0f * sx * p, ryEye + inY, 45.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye + 50.0f * sx, ryEye, rxEye + 50.0f * sx + 15.0f * sx * p, ryEye - outY, 52.0f * sx, std::abs(p) * 1.5f, WARP_PUSH);
            break;
        }
        case PARAM_EYE_DISTANCE: {
            // Khoảng cách mắt: Kéo 2 mắt gần lại hoặc xa nhau
            float distShift = 30.0f * sx * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye, lyEye, lxEye - distShift, lyEye, 100.0f * sx, std::abs(p) * 1.3f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye, ryEye, rxEye + distShift, ryEye, 100.0f * sx, std::abs(p) * 1.3f, WARP_PUSH);
            break;
        }
        case PARAM_EYE_PUPIL_ENLARGE: {
            // Giãn tròng đồng tử: Phóng to tròng mắt vừa phải tự nhiên
            float pupilRadius = 32.0f * sx;
            float pupilWarp = std::abs(p) * 1.0f;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye, lyEye, lxEye, lyEye, pupilRadius, pupilWarp, (p >= 0 ? WARP_EXPAND : WARP_PINCH));
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye, ryEye, rxEye, ryEye, pupilRadius, pupilWarp, (p >= 0 ? WARP_EXPAND : WARP_PINCH));
            break;
        }
        default:
            return false;
    }

    return true;
}

// =========================================================================
// 2. HIỆU ỨNG MẮT (ĐỘ SÁNG, TRẮNG LÒNG TRẮNG, MÍ ĐÔI, XÓA ĐỎ)
// =========================================================================
bool EyeRetouchEngine::applyEyeEffect(
    uint32_t* pixels,
    int width,
    int height,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
    int effectId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || std::abs(intensity) < 0.001f) {
        return false;
    }

    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;
    float factor = std::clamp(intensity, 0.0f, 1.0f);

    auto processEye = [&](float cx, float cy) {
        float radX = 65.0f * sx;
        float radY = 40.0f * sy;
        int minX = std::max(0, static_cast<int>(cx - radX));
        int maxX = std::min(width - 1, static_cast<int>(cx + radX));
        int minY = std::max(0, static_cast<int>(cy - radY));
        int maxY = std::min(height - 1, static_cast<int>(cy + radY));

        #pragma omp parallel for schedule(dynamic, 8)
        for (int y = minY; y <= maxY; ++y) {
            float dy = (y - cy) / radY;
            float dySq = dy * dy;
            int rowIdx = y * width;

            for (int x = minX; x <= maxX; ++x) {
                float dx = (x - cx) / radX;
                float distSq = dx * dx + dySq;
                if (distSq >= 1.0f) continue;

                float spatialWeight = (1.0f - distSq) * factor;
                uint32_t c = pixels[rowIdx + x];
                float r = static_cast<float>(RGBA_R(c));
                float g = static_cast<float>(RGBA_G(c));
                float b = static_cast<float>(RGBA_B(c));
                uint32_t a = RGBA_A(c);

                float lum = 0.299f * r + 0.587f * g + 0.114f * b;

                switch (effectId) {
                    case PARAM_EYE_BRIGHT: {
                        // Sáng mắt: Tăng sáng và vi tương phản vùng mắt
                        float bright = r * (1.0f + 0.25f * spatialWeight) + 20.0f * spatialWeight;
                        float brightG = g * (1.0f + 0.25f * spatialWeight) + 20.0f * spatialWeight;
                        float brightB = b * (1.0f + 0.25f * spatialWeight) + 20.0f * spatialWeight;
                        pixels[rowIdx + x] = PACK_RGBA(
                            std::clamp(static_cast<int>(std::round(bright)), 0, 255),
                            std::clamp(static_cast<int>(std::round(brightG)), 0, 255),
                            std::clamp(static_cast<int>(std::round(brightB)), 0, 255),
                            a
                        );
                        break;
                    }
                    case PARAM_EYE_WHITEN_SCLERA: {
                        // Làm trắng lòng trắng mắt: Phát hiện củng mạc (lum > 70, r/g/b cân bằng)
                        float diffRGB = std::max({r, g, b}) - std::min({r, g, b});
                        if (lum > 65.0f && diffRGB < 45.0f) {
                            float whiteLum = std::min(255.0f, lum * (1.0f + 0.35f * spatialWeight) + 25.0f * spatialWeight);
                            // Triệt tiêu sắc vàng (tăng nhẹ xanh lam, cân bằng R, G)
                            float targetR = whiteLum;
                            float targetG = whiteLum * 0.98f;
                            float targetB = std::min(255.0f, whiteLum * 1.04f);
                            float w = spatialWeight * 0.85f;
                            pixels[rowIdx + x] = PACK_RGBA(
                                std::clamp(static_cast<int>(std::round(r * (1.0f - w) + targetR * w)), 0, 255),
                                std::clamp(static_cast<int>(std::round(g * (1.0f - w) + targetG * w)), 0, 255),
                                std::clamp(static_cast<int>(std::round(b * (1.0f - w) + targetB * w)), 0, 255),
                                a
                            );
                        }
                        break;
                    }
                    case PARAM_EYE_REMOVE_REDNESS: {
                        // Xóa tia máu đỏ trong mắt: r > g+10 và r > b+10
                        if (r > g + 8.0f && r > b + 8.0f && lum > 50.0f) {
                            float avgGB = (g + b) * 0.5f;
                            float targetR = avgGB + 3.0f;
                            float w = spatialWeight * 0.90f;
                            pixels[rowIdx + x] = PACK_RGBA(
                                std::clamp(static_cast<int>(std::round(r * (1.0f - w) + targetR * w)), 0, 255),
                                std::clamp(static_cast<int>(std::round(g)), 0, 255),
                                std::clamp(static_cast<int>(std::round(b)), 0, 255),
                                a
                            );
                        }
                        break;
                    }
                    case PARAM_EYE_SHARPEN:
                    case PARAM_EYE_CLARITY: {
                        // Làm nét & làm trong mắt: Tăng micro-contrast
                        float contrastFactor = 1.0f + 0.55f * spatialWeight;
                        float nr = (r - 128.0f) * contrastFactor + 128.0f;
                        float ng = (g - 128.0f) * contrastFactor + 128.0f;
                        float nb = (b - 128.0f) * contrastFactor + 128.0f;
                        pixels[rowIdx + x] = PACK_RGBA(
                            std::clamp(static_cast<int>(std::round(nr)), 0, 255),
                            std::clamp(static_cast<int>(std::round(ng)), 0, 255),
                            std::clamp(static_cast<int>(std::round(nb)), 0, 255),
                            a
                        );
                        break;
                    }
                    case PARAM_EYE_RED_EYE_REMOVE: {
                        // Khử mắt đỏ do flash máy ảnh (Red Eye Flash)
                        float distCenter = std::sqrt((x - cx)*(x - cx) + (y - cy)*(y - cy));
                        if (distCenter < 20.0f * sx && r > 110.0f && r > g * 1.6f && r > b * 1.6f) {
                            float darkPupil = (g + b) * 0.35f;
                            pixels[rowIdx + x] = PACK_RGBA(
                                std::clamp(static_cast<int>(std::round(darkPupil)), 0, 255),
                                std::clamp(static_cast<int>(std::round(darkPupil)), 0, 255),
                                std::clamp(static_cast<int>(std::round(darkPupil)), 0, 255),
                                a
                            );
                        }
                        break;
                    }
                }
            }
        }
    };

    // Áp dụng cho cả hai mắt
    processEye(lxEye, lyEye);
    processEye(rxEye, ryEye);

    // Xử lý tạo mí đôi (Double Eyelid)
    if (effectId == PARAM_EYE_DOUBLE_EYELID) {
        auto drawCrease = [&](float cx, float cy) {
            float creaseY = cy - 20.0f * sy;
            int halfW = static_cast<int>(35.0f * sx);
            for (int dx = -halfW; dx <= halfW; ++dx) {
                int px = static_cast<int>(cx + dx);
                if (px < 0 || px >= width) continue;

                // Độ cong parabol tự nhiên của mí mắt
                float t = static_cast<float>(dx) / halfW;
                float arcY = creaseY - (1.0f - t * t) * 8.0f * sy;
                int py = static_cast<int>(std::round(arcY));
                if (py < 1 || py >= height - 2) continue;

                float lineWeight = (1.0f - t * t) * factor * 0.75f;

                // 1. Đường rãnh bóng tối mí mắt (crease shadow)
                for (int dy = -1; dy <= 0; ++dy) {
                    int yPos = py + dy;
                    uint32_t orig = pixels[yPos * width + px];
                    float r = RGBA_R(orig) * (1.0f - lineWeight * 0.45f);
                    float g = RGBA_G(orig) * (1.0f - lineWeight * 0.48f);
                    float b = RGBA_B(orig) * (1.0f - lineWeight * 0.45f);
                    pixels[yPos * width + px] = PACK_RGBA(
                        std::clamp(static_cast<int>(std::round(r)), 0, 255),
                        std::clamp(static_cast<int>(std::round(g)), 0, 255),
                        std::clamp(static_cast<int>(std::round(b)), 0, 255),
                        RGBA_A(orig)
                    );
                }

                // 2. Viền sáng bắt sáng nhẹ phía trên mí đôi (crease highlight)
                int hlY = py - 2;
                uint32_t origHl = pixels[hlY * width + px];
                float hr = RGBA_R(origHl) + 18.0f * lineWeight;
                float hg = RGBA_G(origHl) + 18.0f * lineWeight;
                float hb = RGBA_B(origHl) + 18.0f * lineWeight;
                pixels[hlY * width + px] = PACK_RGBA(
                    std::clamp(static_cast<int>(std::round(hr)), 0, 255),
                    std::clamp(static_cast<int>(std::round(hg)), 0, 255),
                    std::clamp(static_cast<int>(std::round(hb)), 0, 255),
                    RGBA_A(origHl)
                );
            }
        };

        drawCrease(lxEye, lyEye);
        drawCrease(rxEye, ryEye);
    }

    return true;
}

// =========================================================================
// 3. ĐỔI MÀU MẮT (EYE COLOR PRESETS - 8 MÀU)
// =========================================================================
bool EyeRetouchEngine::applyEyeColor(
    uint32_t* pixels,
    int width,
    int height,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
    int colorId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;

    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;
    float factor = std::clamp(intensity, 0.0f, 1.0f);

    auto colorizeIris = [&](float cx, float cy) {
        float innerR = 6.0f * sx;   // Vùng con ngươi đen
        float outerR = 25.0f * sx;  // Vòng ngoài mống mắt iris
        float innerRSq = innerR * innerR;
        float outerRSq = outerR * outerR;

        int minX = std::max(0, static_cast<int>(cx - outerR));
        int maxX = std::min(width - 1, static_cast<int>(cx + outerR));
        int minY = std::max(0, static_cast<int>(cy - outerR));
        int maxY = std::min(height - 1, static_cast<int>(cy + outerR));

        #pragma omp parallel for schedule(dynamic, 8)
        for (int y = minY; y <= maxY; ++y) {
            float dy = y - cy;
            int rowIdx = y * width;
            for (int x = minX; x <= maxX; ++x) {
                float dx = x - cx;
                float dSq = dx * dx + dy * dy;

                // Chỉ đổi màu trong dải mống mắt (iris ring)
                if (dSq >= innerRSq && dSq <= outerRSq) {
                    float dist = std::sqrt(dSq);
                    float feather = (1.0f - std::abs(dist - (innerR + outerR) * 0.5f) / ((outerR - innerR) * 0.5f));
                    float blendWeight = std::clamp(feather, 0.0f, 1.0f) * factor * 0.85f;

                    uint32_t c = pixels[rowIdx + x];
                    float r = RGBA_R(c);
                    float g = RGBA_G(c);
                    float b = RGBA_B(c);
                    uint32_t a = RGBA_A(c);

                    float origLum = 0.299f * r + 0.587f * g + 0.114f * b;

                    // 1. Corneal Specular Gloss & Wetness Shield (Bảo tồn độ bóng ướt giác mạc tự nhiên)
                    // Điểm sáng phản chiếu giác mạc có độ sáng cao (lum > 150) phải được giữ nguyên 100% để mắt long lanh
                    float specularShield = std::clamp((origLum - 150.0f) / 65.0f, 0.0f, 1.0f);

                    // 2. Iris Base Lifting: Nâng độ sáng nền cho mắt đen châu Á để màu lens lên rõ rệt và lung linh
                    float liftedLum = std::max(origLum, 35.0f + 85.0f * factor);

                    // 3. Vân tia mống mắt 3D (Iris Radial Fiber Texture)
                    float angle = std::atan2(dy, dx);
                    float radialFiber = 0.90f + 0.20f * std::abs(std::sin(angle * 14.0f));

                    // 4. Bảng màu kính áp tròng cao cấp (Vibrant Professional Lens Pigments)
                    float tr = r, tg = g, tb = b;
                    switch (colorId) {
                        case EYE_COLOR_BLUE: // Xanh biển Sapphire Crystal
                            tr = 30.0f + liftedLum * 0.25f;
                            tg = 110.0f + liftedLum * 0.55f;
                            tb = 235.0f + liftedLum * 0.15f;
                            break;
                        case EYE_COLOR_GREEN: // Xanh ngọc lục bảo Emerald Glow
                            tr = 25.0f + liftedLum * 0.20f;
                            tg = 205.0f + liftedLum * 0.25f;
                            tb = 110.0f + liftedLum * 0.35f;
                            break;
                        case EYE_COLOR_HAZEL: // Nâu hạt dẻ mật ong Honey Hazel
                            tr = 215.0f + liftedLum * 0.18f;
                            tg = 155.0f + liftedLum * 0.30f;
                            tb = 65.0f + liftedLum * 0.25f;
                            break;
                        case EYE_COLOR_GRAY: // Xám khói pha lê Smokey Diamond
                            tr = 180.0f + liftedLum * 0.30f;
                            tg = 190.0f + liftedLum * 0.30f;
                            tb = 215.0f + liftedLum * 0.20f;
                            break;
                        case EYE_COLOR_VIOLET: // Tím thạch anh Amethyst
                            tr = 185.0f + liftedLum * 0.25f;
                            tg = 90.0f + liftedLum * 0.30f;
                            tb = 240.0f + liftedLum * 0.10f;
                            break;
                        case EYE_COLOR_AMBER: // Nâu vàng hoàng gia Amber Gold
                            tr = 230.0f + liftedLum * 0.15f;
                            tg = 165.0f + liftedLum * 0.25f;
                            tb = 40.0f + liftedLum * 0.20f;
                            break;
                        case EYE_COLOR_HONEY: // Nâu mật ong hổ phách Warm Honey
                            tr = 225.0f + liftedLum * 0.15f;
                            tg = 175.0f + liftedLum * 0.25f;
                            tb = 60.0f + liftedLum * 0.25f;
                            break;
                        default: // Tự nhiên
                            tr = r; tg = g; tb = b;
                            break;
                    }

                    // Áp dụng vân tia mống mắt
                    tr = std::min(255.0f, tr * radialFiber);
                    tg = std::min(255.0f, tg * radialFiber);
                    tb = std::min(255.0f, tb * radialFiber);

                    // 5. Viền con ngươi Limbal Ring quyến rũ ở mép ngoài (r > 0.85 outerR)
                    float distNorm = dist / outerR;
                    float limbalShade = (distNorm > 0.85f) ? (1.0f - (distNorm - 0.85f) / 0.15f * 0.40f) : 1.0f;
                    tr *= limbalShade;
                    tg *= limbalShade;
                    tb *= limbalShade;

                    // Blend màu lens vào mắt
                    float blendR = r * (1.0f - blendWeight) + tr * blendWeight;
                    float blendG = g * (1.0f - blendWeight) + tg * blendWeight;
                    float blendB = b * (1.0f - blendWeight) + tb * blendWeight;

                    // 6. Tái bảo tồn độ bóng giác mạc lên trên cùng (Specular Gloss Shield)
                    float finalR = blendR * (1.0f - specularShield) + r * specularShield;
                    float finalG = blendG * (1.0f - specularShield) + g * specularShield;
                    float finalB = blendB * (1.0f - specularShield) + b * specularShield;

                    pixels[rowIdx + x] = PACK_RGBA(
                        std::clamp(static_cast<int>(std::round(finalR)), 0, 255),
                        std::clamp(static_cast<int>(std::round(finalG)), 0, 255),
                        std::clamp(static_cast<int>(std::round(finalB)), 0, 255),
                        a
                    );
                }
            }
        }
    };

    colorizeIris(lxEye, lyEye);
    colorizeIris(rxEye, ryEye);
    return true;
}

// =========================================================================
// 4. ÁNH PHẢN XẠ ĐỒNG TỬ CATCHLIGHT (15 KIỂU)
// =========================================================================
bool EyeRetouchEngine::applyEyeCatchlight(
    uint32_t* pixels,
    int width,
    int height,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
    int styleId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;

    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;
    float factor = std::clamp(intensity, 0.0f, 1.0f);

    auto renderCatchlight = [&](float cx, float cy) {
        // Tọa độ phản xạ ánh sáng tự nhiên (góc 10 giờ trên con ngươi)
        float lightX = cx + 5.0f * sx;
        float lightY = cy - 6.0f * sy;
        float baseR = 10.0f * sx;
        int rad = static_cast<int>(std::ceil(baseR * 1.5f));

        int minX = std::max(0, static_cast<int>(lightX - rad));
        int maxX = std::min(width - 1, static_cast<int>(lightX + rad));
        int minY = std::max(0, static_cast<int>(lightY - rad));
        int maxY = std::min(height - 1, static_cast<int>(lightY + rad));

        for (int y = minY; y <= maxY; ++y) {
            float dy = (y - lightY);
            int rowIdx = y * width;
            for (int x = minX; x <= maxX; ++x) {
                float dx = (x - lightX);
                float dist = std::sqrt(dx * dx + dy * dy);
                float shapeAlpha = 0.0f;

                switch (styleId) {
                    case CATCHLIGHT_CIRCLE: { // Vòng tròn Ring Light Studio
                        float ringR = 6.0f * sx;
                        float dRing = std::abs(dist - ringR);
                        if (dRing < 2.5f * sx) {
                            shapeAlpha = (1.0f - dRing / (2.5f * sx));
                        }
                        break;
                    }
                    case CATCHLIGHT_STAR: { // Ngôi sao 4 cánh lấp lánh
                        float crossX = std::abs(dx);
                        float crossY = std::abs(dy);
                        if ((crossX < 1.8f * sx && crossY < 8.0f * sx) || (crossY < 1.8f * sx && crossX < 8.0f * sx)) {
                            shapeAlpha = std::max(1.0f - crossY / (8.0f * sx), 1.0f - crossX / (8.0f * sx));
                        }
                        break;
                    }
                    case CATCHLIGHT_HEART: { // Trái tim tình yêu
                        float hx = dx / (5.0f * sx);
                        float hy = -dy / (5.0f * sx);
                        float f = (hx*hx + hy*hy - 1.0f);
                        if (f*f*f - hx*hx*hy*hy*hy <= 0.05f && dist < 7.0f * sx) {
                            shapeAlpha = 1.0f - dist / (7.0f * sx);
                        }
                        break;
                    }
                    case CATCHLIGHT_SOFTBOX: { // Hình vuông Softbox chụp Studio
                        if (std::abs(dx) < 5.0f * sx && std::abs(dy) < 5.0f * sx) {
                            shapeAlpha = (1.0f - std::max(std::abs(dx), std::abs(dy)) / (5.0f * sx));
                        }
                        break;
                    }
                    case CATCHLIGHT_DOUBLE_DOT: { // Chấm đôi Anime
                        float d1 = std::sqrt(dx*dx + dy*dy);
                        float d2 = std::sqrt((dx - 5.0f*sx)*(dx - 5.0f*sx) + (dy + 4.0f*sy)*(dy + 4.0f*sy));
                        if (d1 < 4.0f * sx) shapeAlpha = 1.0f - d1 / (4.0f * sx);
                        else if (d2 < 2.5f * sx) shapeAlpha = (1.0f - d2 / (2.5f * sx)) * 0.7f;
                        break;
                    }
                    case CATCHLIGHT_CRESCENT: { // Trăng khuyết huyền ảo
                        float dMain = std::sqrt(dx*dx + dy*dy);
                        float dCut = std::sqrt((dx + 3.0f*sx)*(dx + 3.0f*sx) + (dy - 2.0f*sy)*(dy - 2.0f*sy));
                        if (dMain < 6.0f * sx && dCut > 4.5f * sx) {
                            shapeAlpha = 1.0f - dMain / (6.0f * sx);
                        }
                        break;
                    }
                    case CATCHLIGHT_DIAMOND: { // Kim cương
                        float diamondD = std::abs(dx) + std::abs(dy);
                        if (diamondD < 7.0f * sx) {
                            shapeAlpha = 1.0f - diamondD / (7.0f * sx);
                        }
                        break;
                    }
                    default: { // Cánh hoa Flower
                        float angle = std::atan2(dy, dx);
                        float rFlower = (4.5f + 2.0f * std::cos(5.0f * angle)) * sx;
                        if (dist < rFlower) {
                            shapeAlpha = 1.0f - dist / rFlower;
                        }
                        break;
                    }
                }

                if (shapeAlpha > 0.0f) {
                    float add = shapeAlpha * factor * 255.0f;
                    uint32_t orig = pixels[rowIdx + x];
                    float r = std::min(255.0f, RGBA_R(orig) + add);
                    float g = std::min(255.0f, RGBA_G(orig) + add);
                    float b = std::min(255.0f, RGBA_B(orig) + add);
                    pixels[rowIdx + x] = PACK_RGBA(static_cast<uint32_t>(r), static_cast<uint32_t>(g), static_cast<uint32_t>(b), RGBA_A(orig));
                }
            }
        }
    };

    renderCatchlight(lxEye, lyEye);
    renderCatchlight(rxEye, ryEye);
    return true;
}

// =========================================================================
// 5. CHỈNH HÌNH DÁNG & CHI TIẾT LÔNG MÀY (EYEBROWS)
// =========================================================================
bool EyeRetouchEngine::applyEyebrow(
    uint32_t* pixels,
    int width,
    int height,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
    int paramId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || std::abs(intensity) < 0.001f) return false;

    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;
    float p = std::clamp(intensity, -1.0f, 1.0f);

    float lBrowY = lyEye - 42.0f * sy;
    float rBrowY = ryEye - 42.0f * sy;

    switch (paramId) {
        case PARAM_BROW_SHAPE_TAIL: {
            // Nâng đuôi mày sắc sảo
            float tailLift = 28.0f * sy * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye - 55.0f * sx, lBrowY, lxEye - 55.0f * sx, lBrowY - tailLift, 55.0f * sx, std::abs(p) * 1.5f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye + 55.0f * sx, rBrowY, rxEye + 55.0f * sx, rBrowY - tailLift, 55.0f * sx, std::abs(p) * 1.5f, WARP_PUSH);
            break;
        }
        case PARAM_BROW_SHAPE_CURVED: {
            // Mày cong mềm mại (đẩy đỉnh vòm lên)
            float archLift = 30.0f * sy * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye, lBrowY - 5.0f * sy, lxEye, lBrowY - 5.0f * sy - archLift, 60.0f * sx, std::abs(p) * 1.5f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye, rBrowY - 5.0f * sy, rxEye, rBrowY - 5.0f * sy - archLift, 60.0f * sx, std::abs(p) * 1.5f, WARP_PUSH);
            break;
        }
        case PARAM_BROW_SHAPE_DENSE:
        case PARAM_BROW_SIZE: {
            // Độ dày mày / Mày rậm: Mở rộng viền lông mày
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye, lBrowY, lxEye, lBrowY, 65.0f * sx, std::abs(p) * 1.5f, (p >= 0 ? WARP_EXPAND : WARP_PINCH));
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye, rBrowY, rxEye, rBrowY, 65.0f * sx, std::abs(p) * 1.5f, (p >= 0 ? WARP_EXPAND : WARP_PINCH));
            break;
        }
        case PARAM_BROW_SHAPE_STRAIGHT: {
            // Mày ngang K-Beauty: Hạ thấp vòm cong tạo đường ngang thẳng
            float dropArch = 25.0f * sy * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye, lBrowY, lxEye, lBrowY + dropArch, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye, rBrowY, rxEye, rBrowY + dropArch, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_BROW_HEIGHT:
        case PARAM_BROW_RAISE: {
            // Vị trí cao/thấp lông mày
            float shiftY = 32.0f * sy * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye, lBrowY, lxEye, lBrowY - shiftY, 75.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye, rBrowY, rxEye, rBrowY - shiftY, 75.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_BROW_TILT: {
            // Góc nghiêng mày
            float tiltY = 28.0f * sy * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye - 40.0f * sx, lBrowY, lxEye - 40.0f * sx, lBrowY - tiltY, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye + 40.0f * sx, rBrowY, rxEye + 40.0f * sx, rBrowY - tiltY, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_BROW_DISTANCE:
        case PARAM_BROW_HEAD_SPACING: {
            // Khoảng cách giữa 2 đầu mày
            float distShift = 25.0f * sx * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye + 45.0f * sx, lBrowY, lxEye + 45.0f * sx - distShift, lBrowY, 50.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye - 45.0f * sx, rBrowY, rxEye - 45.0f * sx + distShift, rBrowY, 50.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_BROW_LENGTH: {
            // Độ dài đuôi mày
            float lenShift = 30.0f * sx * p;
            LiquifyWarpEngine::applyWarp(pixels, width, height, lxEye - 55.0f * sx, lBrowY, lxEye - 55.0f * sx - lenShift, lBrowY, 50.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            LiquifyWarpEngine::applyWarp(pixels, width, height, rxEye + 55.0f * sx, rBrowY, rxEye + 55.0f * sx + lenShift, rBrowY, 50.0f * sx, std::abs(p) * 1.4f, WARP_PUSH);
            break;
        }
        case PARAM_BROW_ALPHA: {
            // Độ đậm nhạt / mờ mày
            ColorTuningParams params = { -p * 20.0f, p * 25.0f, 0.0f, 0.0f, 0.0f, 0.0f };
            ColorLutEngine::applyLocalizedColorTuning(pixels, width, height, lxEye, lBrowY, 65.0f * sx, 30.0f * sy, params, false);
            ColorLutEngine::applyLocalizedColorTuning(pixels, width, height, rxEye, rBrowY, 65.0f * sx, 30.0f * sy, params, false);
            break;
        }
        default:
            return false;
    }

    return true;
}

// =========================================================================
// 6. ĐỔI MÀU LÔNG MÀY
// =========================================================================
bool EyeRetouchEngine::applyEyebrowColor(
    uint32_t* pixels,
    int width,
    int height,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
    int colorId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;

    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;
    float factor = std::clamp(intensity, 0.0f, 1.0f);

    auto colorizeBrow = [&](float cx, float cy) {
        float radX = 65.0f * sx;
        float radY = 28.0f * sy;
        int minX = std::max(0, static_cast<int>(cx - radX));
        int maxX = std::min(width - 1, static_cast<int>(cx + radX));
        int minY = std::max(0, static_cast<int>(cy - radY));
        int maxY = std::min(height - 1, static_cast<int>(cy + radY));

        #pragma omp parallel for schedule(dynamic, 8)
        for (int y = minY; y <= maxY; ++y) {
            float dy = (y - cy) / radY;
            float dySq = dy * dy;
            int rowIdx = y * width;
            for (int x = minX; x <= maxX; ++x) {
                float dx = (x - cx) / radX;
                float dSq = dx * dx + dySq;
                if (dSq >= 1.0f) continue;

                uint32_t c = pixels[rowIdx + x];
                float r = RGBA_R(c);
                float g = RGBA_G(c);
                float b = RGBA_B(c);
                uint32_t a = RGBA_A(c);
                float lum = 0.299f * r + 0.587f * g + 0.114f * b;

                // Chỉ tác động sợi lông mày sẫm màu
                if (lum < 130.0f) {
                    float spatialW = (1.0f - dSq) * factor * 0.85f;
                    float tr = r, tg = g, tb = b;
                    switch (colorId) {
                        case BROW_COLOR_DARK_BROWN: // Nâu đen
                            tr = lum * 0.95f + 15.0f;
                            tg = lum * 0.75f + 8.0f;
                            tb = lum * 0.60f;
                            break;
                        case BROW_COLOR_LIGHT_BROWN: // Nâu sáng hạt dẻ
                            tr = lum * 1.25f + 25.0f;
                            tg = lum * 0.95f + 15.0f;
                            tb = lum * 0.65f;
                            break;
                        case BROW_COLOR_ASH_GRAY: // Xám tro
                            tr = lum * 1.05f;
                            tg = lum * 1.05f;
                            tb = lum * 1.10f;
                            break;
                        case BROW_COLOR_AUBURN: // Nâu đỏ ánh đồng
                            tr = lum * 1.35f + 30.0f;
                            tg = lum * 0.80f + 10.0f;
                            tb = lum * 0.60f;
                            break;
                        default: // Đen tự nhiên
                            tr = lum * 0.70f;
                            tg = lum * 0.70f;
                            tb = lum * 0.70f;
                            break;
                    }

                    pixels[rowIdx + x] = PACK_RGBA(
                        std::clamp(static_cast<int>(std::round(r * (1.0f - spatialW) + tr * spatialW)), 0, 255),
                        std::clamp(static_cast<int>(std::round(g * (1.0f - spatialW) + tg * spatialW)), 0, 255),
                        std::clamp(static_cast<int>(std::round(b * (1.0f - spatialW) + tb * spatialW)), 0, 255),
                        a
                    );
                }
            }
        }
    };

    colorizeBrow(lxEye, lyEye - 42.0f * sy);
    colorizeBrow(rxEye, ryEye - 42.0f * sy);
    return true;
}

// =========================================================================
// 7. PRESET MẮT KẾT HỢP (PHOTO_13)
// =========================================================================
bool EyeRetouchEngine::applyEyePreset(
    uint32_t* pixels,
    int width,
    int height,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
    int presetId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);

    switch (presetId) {
        case EYE_PRESET_SPICED_TEA: {
            applyEyeShape(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_ENLARGE, p * 0.50f);
            applyEyeEffect(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_BRIGHT, p * 0.60f);
            applyEyeColor(pixels, width, height, lxEye, lyEye, rxEye, ryEye, EYE_COLOR_HONEY, p * 0.70f);
            applyEyeCatchlight(pixels, width, height, lxEye, lyEye, rxEye, ryEye, CATCHLIGHT_CIRCLE, p * 0.75f);
            break;
        }
        case EYE_PRESET_TENDER_AI: {
            applyEyeShape(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_ENLARGE, p * 0.75f);
            applyEyeShape(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_PUPIL_ENLARGE, p * 0.50f);
            applyEyeEffect(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_DOUBLE_EYELID, p * 0.80f);
            applyEyeCatchlight(pixels, width, height, lxEye, lyEye, rxEye, ryEye, CATCHLIGHT_STAR, p * 0.85f);
            break;
        }
        case EYE_PRESET_SOFT_GRACE: {
            applyEyeShape(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_INNER_CANTHUS_ADJ, p * 0.65f);
            applyEyeShape(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_LONGER, p * 0.55f);
            applyEyeColor(pixels, width, height, lxEye, lyEye, rxEye, ryEye, EYE_COLOR_AMBER, p * 0.65f);
            applyEyeCatchlight(pixels, width, height, lxEye, lyEye, rxEye, ryEye, CATCHLIGHT_SOFTBOX, p * 0.75f);
            break;
        }
        case EYE_PRESET_PINK_TALE: {
            applyEyeShape(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_ENLARGE, p * 0.70f);
            applyEyeEffect(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_BRIGHT, p * 0.70f);
            applyEyeCatchlight(pixels, width, height, lxEye, lyEye, rxEye, ryEye, CATCHLIGHT_HEART, p * 0.90f);
            break;
        }
        case EYE_PRESET_PURE_CRYSTAL: {
            applyEyeEffect(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_WHITEN_SCLERA, p * 0.85f);
            applyEyeEffect(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_CLARITY, p * 0.80f);
            applyEyeEffect(pixels, width, height, lxEye, lyEye, rxEye, ryEye, PARAM_EYE_SHARPEN, p * 0.75f);
            applyEyeCatchlight(pixels, width, height, lxEye, lyEye, rxEye, ryEye, CATCHLIGHT_CIRCLE, p * 0.85f);
            break;
        }
        default:
            return true;
    }

    return true;
}

} // namespace meitu_native

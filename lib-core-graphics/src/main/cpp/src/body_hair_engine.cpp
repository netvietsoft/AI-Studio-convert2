#include "body_hair_engine.h"
#include "liquify_warp.h"
#include "hair_matting_engine.h"
#include "hair_strand_dye.h"
#include "landmark_fusion.h"
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

// 1. Chỉnh tóc & Nhuộm tóc (2.9)
bool BodyHairEngine::applyHair(
    uint32_t* pixels,
    int width,
    int height,
    float foreheadX, float foreheadY,
    int paramId,
    int colorToneId,
    float intensity,
    const MeituReborn::FusedFaceGeometry* fused
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);
    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;

    // Tu dong hieu chinh toa do tran theo Fused Face Mesh neu toa do truyen vao chua chuan
    if (fused != nullptr) {
        if (foreheadX <= 10.0f || foreheadY <= 10.0f || foreheadY > height * 0.6f) {
            if (fused->dense478.size() >= 468) {
                foreheadX = fused->dense478[10].x;
                foreheadY = fused->dense478[10].y;
            } else if (fused->anchors106.size() >= 212) {
                foreheadX = (fused->anchors106[38 * 2] + fused->anchors106[57 * 2]) * 0.5f;
                foreheadY = std::min(fused->anchors106[38 * 2 + 1], fused->anchors106[57 * 2 + 1]) - 35.0f * sy;
            }
        }
    }

    switch (paramId) {
        case PARAM_HAIR_LINE: {
            // Hạ đường chân tóc xuống trán (giảm trán dô)
            float warpStr = std::clamp(p * 1.5f, -1.8f, 1.8f);
            float radius = 80.0f * sx;
            for (int dx = -2; dx <= 2; ++dx) {
                float hx = foreheadX + static_cast<float>(dx) * 40.0f * sx;
                float hy = foreheadY - 35.0f * sy;
                MTLiquifyImage::applyWarp(
                    pixels, width, height,
                    hx, hy,
                    hx, hy + 24.0f * sy * p,
                    radius, warpStr * 0.85f,
                    MTLiquifyImage::WARP_MODE_PUSH
                );
            }
            return true;
        }

        case PARAM_HAIR_VOLUME: {
            // Làm phồng chân tóc trên đỉnh đầu và 2 bên thái dương
            // BẢO VỆ NỀN NGOẠI CẢNH 100%: Nền không bị xô lệch/biến dạng theo tóc
            std::vector<uint32_t> origSnapshot(pixels, pixels + (width * height));
            std::vector<float> hairMatte;
            bool hasHairMatte = false;
            if (fused != nullptr) {
                hasHairMatte = HairMattingEngine::getInstance().extractFullSizeMatte(origSnapshot.data(), width, height, *fused, hairMatte);
            }

            float warpStr = std::clamp(p * 1.5f, -1.8f, 1.8f);
            float radius = 120.0f * sx;
            // Đỉnh đầu nâng lên
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                foreheadX, foreheadY - 140.0f * sy,
                foreheadX, foreheadY - 140.0f * sy - 28.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            // 2 bên phồng ra
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                foreheadX - 140.0f * sx, foreheadY - 90.0f * sy,
                foreheadX - 140.0f * sx - 22.0f * sx * p, foreheadY - 90.0f * sy,
                radius * 0.9f, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                foreheadX + 140.0f * sx, foreheadY - 90.0f * sy,
                foreheadX + 140.0f * sx + 22.0f * sx * p, foreheadY - 90.0f * sy,
                radius * 0.9f, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );

            // Phục hồi nguyên bản 100% bit-exact mọi điểm ảnh nền không tiếp giáp tóc phồng
            if (hasHairMatte) {
                int checkR = static_cast<int>(32.0f * sy * p) + 3;
                #pragma omp parallel for schedule(dynamic, 64)
                for (int i = 0; i < width * height; ++i) {
                    float origHairAlpha = hairMatte[i];
                    if (origHairAlpha < 0.03f) {
                        int px = i % width;
                        int py = i / width;
                        bool nearHair = false;
                        for (int dy = -checkR; dy <= checkR && !nearHair; dy += 2) {
                            int ny = py + dy;
                            if (ny < 0 || ny >= height) continue;
                            for (int dx = -checkR; dx <= checkR; dx += 2) {
                                int nx = px + dx;
                                if (nx < 0 || nx >= width) continue;
                                if (hairMatte[ny * width + nx] > 0.35f) {
                                    nearHair = true;
                                    break;
                                }
                            }
                        }
                        if (!nearHair) {
                            pixels[i] = origSnapshot[i];
                        }
                    }
                }
            }
            return true;
        }

        case PARAM_HAIR_WRAPPED: {
            // Tóc ôm sát mặt: Ép 2 bên tóc mai vào che gò má và xương hàm
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = 80.0f * sx;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                foreheadX - 150.0f * sx, foreheadY + 80.0f * sy,
                foreheadX - 150.0f * sx + 25.0f * sx * p, foreheadY + 80.0f * sy,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                foreheadX + 150.0f * sx, foreheadY + 80.0f * sy,
                foreheadX + 150.0f * sx - 25.0f * sx * p, foreheadY + 80.0f * sy,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_HAIR_COLOR: {
            // Nhuộm tóc thời trang: Uu tien su dung HairStrandDyeEngine tieu chuan salon
            if (fused != nullptr) {
                return HairStrandDyeEngine::applyStrandDye(pixels, width, height, *fused, colorToneId, intensity, 0.65f);
            }
            struct HairColorRGB { int r, g, b; };
            static const HairColorRGB hairTones[8] = {
                {220, 190, 150}, // 0: Platinum Blonde
                {225, 140, 150}, // 1: Rose Gold
                {240, 160, 200}, // 2: Pink Pastel
                {130, 25, 50},   // 3: Wine Burgundy
                {110, 85, 70},   // 4: Ash Brown
                {40, 80, 140},   // 5: Navy Blue
                {180, 185, 195}, // 6: Smokey Silver
                {210, 145, 75}   // 7: Caramel Honey
            };
            HairColorRGB tone = hairTones[std::clamp(colorToneId, 0, 7)];

            // Quét nửa trên ảnh (vùng tóc xung quanh đầu)
            int maxY = static_cast<int>(foreheadY + 120.0f * sy);
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = 0; y < maxY; ++y) {
                for (int x = 0; x < width; ++x) {
                    int idx = y * width + x;
                    uint32_t c = pixels[idx];
                    int r = RGBA_R(c);
                    int g = RGBA_G(c);
                    int b = RGBA_B(c);

                    int lum = (r * 299 + g * 587 + b * 114) / 1000;
                    float dx = (x - foreheadX) / (200.0f * sx);
                    float dy = (y - (foreheadY - 60.0f * sy)) / (220.0f * sy);
                    float faceDist2 = dx * dx + dy * dy;

                    if (lum < 165 && faceDist2 > 0.45f && faceDist2 < 2.5f) {
                        float blend = p * 0.65f * (1.0f - std::abs(faceDist2 - 1.2f) / 1.5f);
                        blend = std::clamp(blend, 0.0f, 0.75f);

                        int nr = static_cast<int>(r + (tone.r - r) * blend);
                        int ng = static_cast<int>(g + (tone.g - g) * blend);
                        int nb = static_cast<int>(b + (tone.b - b) * blend);
                        pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
                    }
                }
            }
            return true;
        }

        default:
            return false;
    }
}

// 2. Định hình vóc dáng cơ thể (2.10 BODY RESHAPE)
bool BodyHairEngine::applyBodyReshape(
    uint32_t* pixels,
    int width,
    int height,
    int paramId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || std::abs(intensity) < 0.001f) return false;
    float p = std::clamp(intensity, -1.0f, 1.0f);
    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;

    switch (paramId) {
        case PARAM_BODY_WAIST: {
            // Eo thon con kiến: Ép 2 bên eo vào trong
            float warpStr = std::clamp(p * 1.5f, -1.8f, 1.8f);
            float radius = 180.0f * sx;
            float waistY = 1040.0f * sy;

            MTLiquifyImage::applyWarp(
                pixels, width, height,
                160.0f * sx, waistY,
                160.0f * sx + 50.0f * sx * p, waistY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                736.0f * sx, waistY,
                736.0f * sx - 50.0f * sx * p, waistY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_BODY_SHOULDER: {
            // Vai vuông móc áo: Nâng và ép phẳng 2 bên bờ vai
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = 150.0f * sx;
            float shoulderY = 820.0f * sy;

            MTLiquifyImage::applyWarp(
                pixels, width, height,
                180.0f * sx, shoulderY,
                180.0f * sx, shoulderY - 30.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                716.0f * sx, shoulderY,
                716.0f * sx, shoulderY - 30.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_BODY_NECK: {
            // Cổ thiên nga thon dài: Kéo dài cổ và thu hẹp bề ngang cổ
            float warpStr = std::clamp(p * 1.3f, -1.5f, 1.5f);
            float radius = 100.0f * sx;
            float neckY = 680.0f * sy;

            MTLiquifyImage::applyWarp(
                pixels, width, height,
                448.0f * sx, neckY,
                448.0f * sx, neckY + 25.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            // Ép hẹp bề ngang cổ 2 bên
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                340.0f * sx, neckY + 20.0f * sy,
                340.0f * sx + 18.0f * sx * p, neckY + 20.0f * sy,
                radius * 0.8f, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                556.0f * sx, neckY + 20.0f * sy,
                556.0f * sx - 18.0f * sx * p, neckY + 20.0f * sy,
                radius * 0.8f, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_BODY_SLIM: {
            // Thon người toàn thân: Ép từ ngực đến hông
            float warpStr = std::clamp(p * 1.5f, -1.8f, 1.8f);
            float radius = 220.0f * sx;
            for (float yPct = 0.65f; yPct <= 0.95f; yPct += 0.12f) {
                float curY = static_cast<float>(height) * yPct;
                MTLiquifyImage::applyWarp(
                    pixels, width, height,
                    150.0f * sx, curY,
                    150.0f * sx + 40.0f * sx * p, curY,
                    radius, warpStr * 0.8f,
                    MTLiquifyImage::WARP_MODE_PUSH
                );
                MTLiquifyImage::applyWarp(
                    pixels, width, height,
                    746.0f * sx, curY,
                    746.0f * sx - 40.0f * sx * p, curY,
                    radius, warpStr * 0.8f,
                    MTLiquifyImage::WARP_MODE_PUSH
                );
            }
            return true;
        }

        case PARAM_BODY_LEGS: {
            // Kéo dài chân: Dịch chuyển phần dưới ảnh theo chiều dọc mượt mà
            float warpStr = std::clamp(p * 1.5f, -1.8f, 1.8f);
            float radius = 240.0f * sx;
            float legY = 1000.0f * sy;
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                448.0f * sx, legY,
                448.0f * sx, legY + 55.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        case PARAM_BODY_CHEST: {
            // Nâng ngực tự nhiên: EXPAND 2 bên ngực
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = 110.0f * sx;
            float chestY = 880.0f * sy;

            MTLiquifyImage::applyWarp(
                pixels, width, height,
                320.0f * sx, chestY,
                320.0f * sx, chestY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_EXPAND
            );
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                576.0f * sx, chestY,
                576.0f * sx, chestY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_EXPAND
            );
            return true;
        }

        case PARAM_BODY_HIP: {
            // Nở nang đường cong hông: Đẩy 2 bên hông ra ngoài
            float warpStr = std::clamp(p * 1.4f, -1.6f, 1.6f);
            float radius = 160.0f * sx;
            float hipY = 1120.0f * sy;

            MTLiquifyImage::applyWarp(
                pixels, width, height,
                160.0f * sx, hipY,
                160.0f * sx - 45.0f * sx * p, hipY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            MTLiquifyImage::applyWarp(
                pixels, width, height,
                736.0f * sx, hipY,
                736.0f * sx + 45.0f * sx * p, hipY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            return true;
        }

        default:
            return false;
    }
}

} // namespace meitu_native

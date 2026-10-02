#include "surface_normal_engine.h"
#include "head_semantic_model.h"
#include <cmath>
#include <algorithm>
#include <omp.h>
#include <android/log.h>

#define LOG_TAG SurfaceNormalEngine
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

bool SurfaceNormalEngine::applyNormalSculpting(
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

    const auto& nose = headModel.nose;
    const auto& cheek = headModel.cheek;
    const auto& jawChin = headModel.jawChin;

    switch (paramId) {
        case PARAM_NORMAL_NOSE_SCULPT: {
            // 1. TẠO KHỐI SỐNG MŨI 3D (3D Nose Ridge Sculpting & Normal Shading)
            Point2DF root = nose.root;
            Point2DF tip = nose.tip;
            float nLen = std::hypot(tip.x - root.x, tip.y - root.y);
            if (nLen < 2.0f) nLen = 40.0f * sy;

            float dirX = (tip.x - root.x) / nLen;
            float dirY = (tip.y - root.y) / nLen;
            float normX = -dirY;
            float normY = dirX;

            float ridgeHalfWidth = std::max(6.0f * sx, nose.bridgeWidth * 0.35f);
            float shadowHalfWidth = ridgeHalfWidth * 2.2f;

            int minX = std::clamp(static_cast<int>(std::min(root.x, tip.x) - shadowHalfWidth - 10.0f), 0, width - 1);
            int maxX = std::clamp(static_cast<int>(std::max(root.x, tip.x) + shadowHalfWidth + 10.0f), 0, width - 1);
            int minY = std::clamp(static_cast<int>(root.y - 5.0f), 0, height - 1);
            int maxY = std::clamp(static_cast<int>(tip.y + 5.0f), 0, height - 1);

            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = minY; y <= maxY; ++y) {
                float fy = static_cast<float>(y);
                for (int x = minX; x <= maxX; ++x) {
                    float fx = static_cast<float>(x);

                    // Chiếu lên trục sống mũi
                    float vx = fx - root.x;
                    float vy = fy - root.y;
                    float axialT = (vx * dirX + vy * dirY) / nLen;
                    if (axialT <= 0.05f || axialT >= 0.95f) continue;

                    float axialWeight = std::sin(axialT * 3.14159265f);
                    float lateralDist = (vx * normX + vy * normY);
                    float absDist = std::abs(lateralDist);

                    float deltaL = 0.0f;
                    if (absDist <= ridgeHalfWidth) {
                        // Vùng sống mũi trung tâm: Highlight tạo cảm giác sống mũi cao, thon
                        float ridgeShape = 1.0f - (absDist / ridgeHalfWidth);
                        deltaL = 20.0f * p * ridgeShape * axialWeight;
                    } else if (absDist > ridgeHalfWidth && absDist <= shadowHalfWidth) {
                        // Vùng cánh bên sống mũi: Shading đổ bóng thanh thoát
                        float shadowShape = std::sin(((absDist - ridgeHalfWidth) / (shadowHalfWidth - ridgeHalfWidth)) * 3.14159265f);
                        deltaL = -14.0f * p * shadowShape * axialWeight;
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

        case PARAM_NORMAL_CHEEKBONE_SCULPT: {
            // 2. TẠO KHỐI GÒ MÁ 3D (Zygomatic Arch Highlight & Contour)
            Point2DF lBone = cheek.leftCheekbone;
            Point2DF rBone = cheek.rightCheekbone;
            float rad = std::max(25.0f * sx, cheek.cheekWidth * 0.18f);

            for (const auto& bone : { lBone, rBone }) {
                int minX = std::clamp(static_cast<int>(bone.x - rad), 0, width - 1);
                int maxX = std::clamp(static_cast<int>(bone.x + rad), 0, width - 1);
                int minY = std::clamp(static_cast<int>(bone.y - rad), 0, height - 1);
                int maxY = std::clamp(static_cast<int>(bone.y + rad), 0, height - 1);

                #pragma omp parallel for schedule(dynamic, 16)
                for (int y = minY; y <= maxY; ++y) {
                    float fy = static_cast<float>(y);
                    for (int x = minX; x <= maxX; ++x) {
                        float fx = static_cast<float>(x);
                        float d = std::hypot(fx - bone.x, fy - bone.y);
                        if (d < rad) {
                            float w = std::exp(- (d * d) / (2.0f * (rad * 0.45f) * (rad * 0.45f)));
                            float deltaL = 16.0f * p * w;

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
            }
            break;
        }

        case PARAM_NORMAL_CHIN_PROJECTION: {
            // 3. ĐỘ NHÔ 3D CHÓP CẰM (Mental Protuberance Highlight)
            Point2DF chin = jawChin.chinTip;
            float rad = std::max(20.0f * sx, jawChin.chinWidth * 0.45f);

            int minX = std::clamp(static_cast<int>(chin.x - rad), 0, width - 1);
            int maxX = std::clamp(static_cast<int>(chin.x + rad), 0, width - 1);
            int minY = std::clamp(static_cast<int>(chin.y - rad), 0, height - 1);
            int maxY = std::clamp(static_cast<int>(chin.y + rad), 0, height - 1);

            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = minY; y <= maxY; ++y) {
                float fy = static_cast<float>(y);
                for (int x = minX; x <= maxX; ++x) {
                    float fx = static_cast<float>(x);
                    float d = std::hypot(fx - chin.x, fy - chin.y);
                    if (d < rad) {
                        float w = std::exp(- (d * d) / (2.0f * (rad * 0.4f) * (rad * 0.4f)));
                        float deltaL = 18.0f * p * w;

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

        default:
            return false;
    }

    return true;
}

} // namespace meitu_native

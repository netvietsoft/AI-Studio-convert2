#include "clavicle_shoulder_engine.h"
#include "liquify_warp.h"
#include "head_semantic_model.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <omp.h>
#include <android/log.h>

#define LOG_TAG ClavicleEngine
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

// Tính khoảng cách từ điểm (px, py) tới đoạn thẳng cong xương quai xanh
float pointToClavicleDist(float px, float py, Point2DF p0, Point2DF p1, float archY) {
    // Ước lượng 10 mẫu trên đường cong S-curve
    float minDist = 1e6f;
    for (int i = 0; i <= 10; ++i) {
        float t = static_cast<float>(i) / 10.0f;
        float cx = p0.x * (1.0f - t) + p1.x * t;
        float cy = p0.y * (1.0f - t) + p1.y * t + archY * std::sin(t * 3.14159265f);
        float d = std::hypot(px - cx, py - cy);
        if (d < minDist) minDist = d;
    }
    return minDist;
}

} // namespace

bool ClavicleShoulderEngine::applyClavicleShoulderEdit(
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

    Point2DF chinTip = headModel.jawChin.chinTip;
    float headW = headModel.headGeometry.headWidth;
    float throatY = chinTip.y + 40.0f * sy;
    float throatX = chinTip.x;

    Point2DF throatCenter = { throatX, throatY };
    Point2DF leftClavicleEnd = { throatX - headW * 0.48f, throatY + 35.0f * sy };
    Point2DF rightClavicleEnd = { throatX + headW * 0.48f, throatY + 35.0f * sy };

    // Snapshot bảo toàn nguyên trạng vùng ngoài ROI
    std::vector<uint32_t> origSnapshot(width * height);
    std::copy(pixels, pixels + (width * height), origSnapshot.begin());

    switch (paramId) {
        case PARAM_CLAVICLE_HIGHLIGHT: {
            // 1. TẠO KHỐI SÁNG SỐNG XƯƠNG QUAI XANH (Clavicle Ridge Highlight)
            float maxDist = 18.0f * sx;
            int minX = std::clamp(static_cast<int>(leftClavicleEnd.x - 20.0f * sx), 0, width - 1);
            int maxX = std::clamp(static_cast<int>(rightClavicleEnd.x + 20.0f * sx), 0, width - 1);
            int minY = std::clamp(static_cast<int>(throatY - 15.0f * sy), 0, height - 1);
            int maxY = std::clamp(static_cast<int>(throatY + 65.0f * sy), 0, height - 1);

            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = minY; y <= maxY; ++y) {
                float fy = static_cast<float>(y);
                for (int x = minX; x <= maxX; ++x) {
                    float fx = static_cast<float>(x);

                    // Khoảng cách tới xương đòn trái hoặc phải
                    float distL = pointToClavicleDist(fx, fy, throatCenter, leftClavicleEnd, -8.0f * sy);
                    float distR = pointToClavicleDist(fx, fy, throatCenter, rightClavicleEnd, -8.0f * sy);
                    float dist = std::min(distL, distR);

                    if (dist < maxDist) {
                        float weight = std::exp(- (dist * dist) / (2.0f * 6.5f * 6.5f * sx * sx));
                        float deltaL = 22.0f * p * weight;

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

        case PARAM_CLAVICLE_SHADOW: {
            // 2. ĐỔ BÓNG HỐ XƯƠNG ĐÒN (Supraclavicular Fossa Shadow)
            // Đổ bóng vùng lõm ngay phía trên và phía dưới xương đòn tạo độ mảnh mai, thanh thoát
            float maxDist = 22.0f * sx;
            int minX = std::clamp(static_cast<int>(leftClavicleEnd.x - 20.0f * sx), 0, width - 1);
            int maxX = std::clamp(static_cast<int>(rightClavicleEnd.x + 20.0f * sx), 0, width - 1);
            int minY = std::clamp(static_cast<int>(throatY - 25.0f * sy), 0, height - 1);
            int maxY = std::clamp(static_cast<int>(throatY + 75.0f * sy), 0, height - 1);

            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = minY; y <= maxY; ++y) {
                float fy = static_cast<float>(y);
                for (int x = minX; x <= maxX; ++x) {
                    float fx = static_cast<float>(x);

                    float distL = pointToClavicleDist(fx, fy, throatCenter, leftClavicleEnd, -8.0f * sy);
                    float distR = pointToClavicleDist(fx, fy, throatCenter, rightClavicleEnd, -8.0f * sy);
                    float dist = std::min(distL, distR);

                    // Vùng đổ bóng nằm ở khoảng cách từ 8px tới 20px so với gờ xương
                    if (dist >= 6.0f * sx && dist <= maxDist) {
                        float ringWeight = std::sin(((dist - 6.0f * sx) / (maxDist - 6.0f * sx)) * 3.14159265f);
                        float deltaL = -18.0f * p * ringWeight;

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

        case PARAM_SHOULDER_SLIM: {
            // 3. HẠ GÓC VAI THIÊN NGA THON THẢ (Swan Shoulder Slimming)
            float warpStr = std::clamp(p * 1.35f, -1.5f, 1.5f);
            float radius = std::max(55.0f * sx, headW * 0.35f);

            // Ép dốc vai trái xuống/vào
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                leftClavicleEnd.x, leftClavicleEnd.y,
                leftClavicleEnd.x + 12.0f * sx * p, leftClavicleEnd.y + 16.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );

            // Ép dốc vai phải xuống/vào
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                rightClavicleEnd.x, rightClavicleEnd.y,
                rightClavicleEnd.x - 12.0f * sx * p, rightClavicleEnd.y + 16.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            break;
        }

        case PARAM_NECK_SLIM: {
            // 4. THON GỌN CƠ CỔ HAI BÊN (Neck Slimming)
            float warpStr = std::clamp(p * 1.25f, -1.5f, 1.5f);
            float radius = std::max(40.0f * sx, headW * 0.25f);
            float midNeckY = (chinTip.y + throatY) * 0.5f;

            // Ép cổ trái vào tâm
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                throatX - headW * 0.28f, midNeckY,
                throatX - headW * 0.28f + 14.0f * sx * p, midNeckY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );

            // Ép cổ phải vào tâm
            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                throatX + headW * 0.28f, midNeckY,
                throatX + headW * 0.28f - 14.0f * sx * p, midNeckY,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            break;
        }

        case PARAM_NECK_LENGTH: {
            // 5. KÉO DÀI CỔ THANH TÚ (Neck Length Extension)
            float warpStr = std::clamp(p * 1.35f, -1.5f, 1.5f);
            float radius = std::max(45.0f * sx, headW * 0.28f);

            LiquifyWarpEngine::applyWarp(
                pixels, width, height,
                throatX, throatY,
                throatX, throatY + 20.0f * sy * p,
                radius, warpStr,
                MTLiquifyImage::WARP_MODE_PUSH
            );
            break;
        }

        default:
            return false;
    }

    // Bảo vệ vùng ngoài cổ & xương quai xanh (ROI Protection)
    float safeBoxX1 = throatX - headW * 0.75f;
    float safeBoxX2 = throatX + headW * 0.75f;
    float safeBoxY1 = chinTip.y - 10.0f * sy;
    float safeBoxY2 = std::min(static_cast<float>(height - 1), throatY + 120.0f * sy);

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

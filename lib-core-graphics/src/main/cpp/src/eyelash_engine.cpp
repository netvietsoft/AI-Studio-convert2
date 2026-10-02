#include "eyelash_engine.h"
#include "head_semantic_model.h"
#include <cmath>
#include <algorithm>
#include <omp.h>
#include <android/log.h>

#define LOG_TAG EyelashEngine
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define MAKE_RGBA(r, g, b, a) (((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(g) << 8) | ((uint32_t)(r)))

namespace meitu_native {

namespace {

struct LashFiber {
    Point2DF p0; // Gốc chân mi
    Point2DF p1; // Điểm uốn cong (Bezier control point)
    Point2DF p2; // Ngọn sợi mi (Tapered tip)
    float baseThickness;
    float tipThickness;
    float opacity;
};

// Vẽ 1 sợi mi bằng đường cong bậc hai Bezier khử răng cưa (Sub-pixel Anti-aliasing)
void renderLashFiber(
    uint32_t* pixels,
    int width,
    int height,
    const LashFiber& lash,
    uint8_t lashR, uint8_t lashG, uint8_t lashB,
    float eyeCenterY
) {
    const int NUM_STEPS = 24;
    Point2DF prevPt = lash.p0;

    for (int step = 1; step <= NUM_STEPS; ++step) {
        float t = static_cast<float>(step) / static_cast<float>(NUM_STEPS);
        float omt = 1.0f - t;
        float b0 = omt * omt;
        float b1 = 2.0f * omt * t;
        float b2 = t * t;

        Point2DF currPt;
        currPt.x = b0 * lash.p0.x + b1 * lash.p1.x + b2 * lash.p2.x;
        currPt.y = b0 * lash.p0.y + b1 * lash.p1.y + b2 * lash.p2.y;

        // Bán kính vuốt nhọn dần từ gốc tới ngọn
        float currRadius = lash.baseThickness * omt + lash.tipThickness * t;
        float currAlpha = lash.opacity * (1.0f - 0.25f * t);

        // Bounding box xung quanh đoạn thẳng
        int minX = std::clamp(static_cast<int>(std::floor(std::min(prevPt.x, currPt.x) - currRadius - 1.0f)), 0, width - 1);
        int maxX = std::clamp(static_cast<int>(std::ceil(std::max(prevPt.x, currPt.x) + currRadius + 1.0f)), 0, width - 1);
        int minY = std::clamp(static_cast<int>(std::floor(std::min(prevPt.y, currPt.y) - currRadius - 1.0f)), 0, height - 1);
        int maxY = std::clamp(static_cast<int>(std::ceil(std::max(prevPt.y, currPt.y) + currRadius + 1.0f)), 0, height - 1);

        float dx = currPt.x - prevPt.x;
        float dy = currPt.y - prevPt.y;
        float lenSq = dx * dx + dy * dy;
        if (lenSq < 1e-5f) {
            prevPt = currPt;
            continue;
        }

        for (int py = minY; py <= maxY; ++py) {
            // Không vẽ xuống dưới vùng lòng đen / lòng trắng
            if (static_cast<float>(py) > eyeCenterY) continue;

            for (int px = minX; px <= maxX; ++px) {
                float pfx = static_cast<float>(px) + 0.5f;
                float pfy = static_cast<float>(py) + 0.5f;

                // Chiếu điểm lên đoạn thẳng
                float u = ((pfx - prevPt.x) * dx + (pfy - prevPt.y) * dy) / lenSq;
                u = std::clamp(u, 0.0f, 1.0f);

                float projX = prevPt.x + u * dx;
                float projY = prevPt.y + u * dy;

                float distSq = (pfx - projX) * (pfx - projX) + (pfy - projY) * (pfy - projY);
                float radSq = currRadius * currRadius;

                if (distSq <= radSq * 1.5f) {
                    float dist = std::sqrt(distSq);
                    float edgeWeight = std::clamp(1.0f - (dist / (currRadius + 0.6f)), 0.0f, 1.0f);
                    float blendAlpha = currAlpha * edgeWeight;

                    if (blendAlpha > 0.01f) {
                        int idx = py * width + px;
                        uint32_t orig = pixels[idx];
                        uint8_t oR = RGBA_R(orig);
                        uint8_t oG = RGBA_G(orig);
                        uint8_t oB = RGBA_B(orig);
                        uint8_t oA = RGBA_A(orig);

                        uint8_t r = static_cast<uint8_t>(oR * (1.0f - blendAlpha) + lashR * blendAlpha);
                        uint8_t g = static_cast<uint8_t>(oG * (1.0f - blendAlpha) + lashG * blendAlpha);
                        uint8_t b = static_cast<uint8_t>(oB * (1.0f - blendAlpha) + lashB * blendAlpha);

                        pixels[idx] = MAKE_RGBA(r, g, b, oA);
                    }
                }
            }
        }

        prevPt = currPt;
    }
}

} // namespace

bool EyelashEngine::applyEyelash(
    uint32_t* pixels,
    int width,
    int height,
    const HeadFrameResult& headModel,
    int styleId,
    float intensity,
    float lengthScale,
    float densityScale,
    float curlAngle
) {
    if (!pixels || width <= 0 || height <= 0 || intensity < 0.01f) {
        return false;
    }
    if (!headModel.isFaceDetected) {
        return false;
    }

    float p = std::clamp(intensity, 0.0f, 1.0f);
    float lScale = std::clamp(lengthScale, 0.5f, 2.2f);
    float dScale = std::clamp(densityScale, 0.5f, 2.0f);

    uint8_t lashR = 20, lashG = 16, lashB = 14; // Keratin Black/Dark Charcoal

    const auto& lEye = headModel.eye.left;
    const auto& rEye = headModel.eye.right;

    std::vector<const SubEyeModel*> eyes;
    if (lEye.isVisible) eyes.push_back(&lEye);
    if (rEye.isVisible) eyes.push_back(&rEye);

    if (eyes.empty()) return false;

    for (const auto* eye : eyes) {
        float eyeW = eye->width;
        float eyeH = eye->height;
        if (eyeW <= 5.0f || eyeH <= 2.0f) continue;

        Point2DF inC = eye->innerCanthus;
        Point2DF outC = eye->outerCanthus;
        Point2DF center = eye->center;

        // Hướng từ góc mắt trong ra góc ngoài
        bool isLeftEye = (outC.x < inC.x); // Phụ thuộc góc chụp
        float dirSign = (outC.x > inC.x) ? 1.0f : -1.0f;

        // Số sợi mi dựa trên mật độ và độ phân giải mắt
        int baseLashCount = static_cast<int>(std::clamp(eyeW * 0.55f * dScale, 20.0f, 55.0f));
        std::vector<LashFiber> fibers;
        fibers.reserve(baseLashCount * 2);

        for (int i = 0; i < baseLashCount; ++i) {
            float t = 0.08f + 0.84f * (static_cast<float>(i) / static_cast<float>(baseLashCount - 1));

            // Vị trí gốc mi theo hình parabol cung mí trên
            // y_lid(t) = center.y - eyeH*0.5f - 4*peak*(t)*(1-t)
            float arcFactor = std::sin(t * 3.14159265f);
            float rootX = inC.x * (1.0f - t) + outC.x * t;
            float rootY = inC.y * (1.0f - t) + outC.y * t - (eyeH * 0.45f) * arcFactor;

            // Độ dài mi phụ thuộc vị trí t và phong cách mi (Style)
            float posWeight = 0.6f + 0.4f * arcFactor;
            if (styleId == LASH_STYLE_CAT_EYE) {
                // Đuôi mắt dài và xếch
                posWeight = 0.4f + 0.9f * (t * t);
            } else if (styleId == LASH_STYLE_DOLL_EYE) {
                // Giữa mắt vươn cao tròn xoe
                posWeight = 0.5f + 0.9f * std::pow(arcFactor, 1.5f);
            } else if (styleId == LASH_STYLE_WISPY_ANIME) {
                // Cụm sợi đan xen so le
                float spike = ((i % 4) == 0) ? 1.35f : 0.75f;
                posWeight = (0.5f + 0.5f * arcFactor) * spike;
            }

            float fiberLen = (eyeH * 0.65f) * posWeight * lScale;
            float flareAngle = (t - 0.5f) * 0.85f * dirSign; // Xòe quạt tự nhiên
            float angle = -1.5707963f + flareAngle + curlAngle * 0.2f;

            Point2DF p0 = { rootX, rootY };
            // Điểm uốn cong Bezier
            Point2DF p1 = {
                rootX + fiberLen * 0.45f * std::cos(angle - 0.2f * dirSign),
                rootY + fiberLen * 0.45f * std::sin(angle - 0.2f * dirSign)
            };
            // Điểm ngọn sợi mi
            Point2DF p2 = {
                rootX + fiberLen * std::cos(angle),
                rootY + fiberLen * std::sin(angle)
            };

            LashFiber fiber;
            fiber.p0 = p0;
            fiber.p1 = p1;
            fiber.p2 = p2;
            fiber.baseThickness = std::max(0.8f, eyeW * 0.022f);
            fiber.tipThickness = 0.25f;
            fiber.opacity = std::clamp(p * (0.65f + 0.35f * arcFactor), 0.1f, 0.95f);

            fibers.push_back(fiber);

            // Nếu kiểu DENSE_GLAM: Thêm một sợi mi chéo đan chân
            if (styleId == LASH_STYLE_DENSE_GLAM && (i % 2 == 0)) {
                LashFiber cross = fiber;
                cross.p1.x += 1.5f * dirSign;
                cross.p2.x += 2.5f * dirSign;
                cross.baseThickness *= 0.75f;
                cross.opacity *= 0.7f;
                fibers.push_back(cross);
            }
        }

        // Render toàn bộ sợi mi với bit/pixel precision
        for (const auto& f : fibers) {
            renderLashFiber(pixels, width, height, f, lashR, lashG, lashB, center.y);
        }
    }

    return true;
}

} // namespace meitu_native

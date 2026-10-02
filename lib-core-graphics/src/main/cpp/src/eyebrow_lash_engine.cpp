#include "eyebrow_lash_engine.h"
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

namespace meitu_native {

EyebrowLashEngine::EyebrowLashEngine() = default;
EyebrowLashEngine::~EyebrowLashEngine() = default;

void EyebrowLashEngine::sampleBilinear(const uint8_t* src, int w, int h, int stride, float x, float y, uint8_t out[4]) {
    x = clampF(x, 0.0f, static_cast<float>(w - 1));
    y = clampF(y, 0.0f, static_cast<float>(h - 1));

    int x0 = static_cast<int>(std::floor(x));
    int y0 = static_cast<int>(std::floor(y));
    int x1 = std::min(x0 + 1, w - 1);
    int y1 = std::min(y0 + 1, h - 1);

    float fx = x - static_cast<float>(x0);
    float fy = y - static_cast<float>(y0);
    float w00 = (1.0f - fx) * (1.0f - fy);
    float w10 = fx * (1.0f - fy);
    float w01 = (1.0f - fx) * fy;
    float w11 = fx * fy;

    const uint8_t* p00 = src + y0 * stride + x0 * 4;
    const uint8_t* p10 = src + y0 * stride + x1 * 4;
    const uint8_t* p01 = src + y1 * stride + x0 * 4;
    const uint8_t* p11 = src + y1 * stride + x1 * 4;

    for (int c = 0; c < 4; ++c) {
        float val = p00[c] * w00 + p10[c] * w10 + p01[c] * w01 + p11[c] * w11;
        out[c] = clampU8(static_cast<int>(val + 0.5f));
    }
}

bool EyebrowLashEngine::processEyebrowLash(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const HeadFrameResult& headResult,
    int paramId,
    float intensity
) {
    if (!rgbaImage || width <= 0 || height <= 0 || stride < width * 4) {
        return false;
    }
    if (intensity <= 0.001f) {
        return true;
    }

    switch (paramId) {
        case PARAM_BROW_THICKNESS:
            return applyBrowThickness(rgbaImage, width, height, stride, headResult, intensity);
        case PARAM_BROW_ARCH:
            return applyBrowArch(rgbaImage, width, height, stride, headResult, intensity);
        case PARAM_BROW_DENSITY_FILL:
            return applyBrowDensityFill(rgbaImage, width, height, stride, headResult, intensity);
        case PARAM_BROW_COLOR:
            return applyBrowColor(rgbaImage, width, height, stride, headResult, intensity);
        case PARAM_LASH_DENSITY:
            return applyLashDensity(rgbaImage, width, height, stride, headResult, intensity);
        case PARAM_LASH_LENGTH:
            return applyLashLengthAndCurl(rgbaImage, width, height, stride, headResult, intensity, false);
        case PARAM_LASH_CURL:
            return applyLashLengthAndCurl(rgbaImage, width, height, stride, headResult, intensity, true);
        default:
            return false;
    }
}

// -----------------------------------------------------------------------------
// 1. PARAM_BROW_THICKNESS: Làm dày/mỏng lông mày
// -----------------------------------------------------------------------------
bool EyebrowLashEngine::applyBrowThickness(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
    const SubBrowModel* brows[2] = { &head.brow.left, &head.brow.right };

    std::vector<uint8_t> backup(w * h * 4);
    std::memcpy(backup.data(), rgba, w * h * 4);

    for (int b = 0; b < 2; ++b) {
        const auto& brow = *brows[b];
        float bx1 = std::min({ brow.head.x, brow.arch.x, brow.tail.x }) - 5.0f;
        float bx2 = std::max({ brow.head.x, brow.arch.x, brow.tail.x }) + 5.0f;
        float by1 = std::min({ brow.head.y, brow.arch.y, brow.tail.y }) - brow.thickness * 0.5f - 8.0f;
        float by2 = std::max({ brow.head.y, brow.arch.y, brow.tail.y }) + brow.thickness * 0.5f + 8.0f;
        if (bx2 <= bx1 || by2 <= by1) continue;

        float centerY = (by1 + by2) * 0.5f;
        float halfH = (by2 - by1) * 0.5f;
        if (halfH <= 2.0f) continue;

        float maxOffset = halfH * 0.35f * intensity;

        int rx1 = std::max(0, static_cast<int>(bx1 - 5));
        int rx2 = std::min(w - 1, static_cast<int>(bx2 + 5));
        int ry1 = std::max(0, static_cast<int>(by1 - 5));
        int ry2 = std::min(h - 1, static_cast<int>(by2 + 5));

        for (int y = ry1; y <= ry2; ++y) {
            float dy = static_cast<float>(y) - centerY;
            float normY = std::abs(dy) / (halfH + 5.0f);
            if (normY > 1.0f) continue;

            float wY = 1.0f - normY * normY * (3.0f - 2.0f * normY);

            for (int x = rx1; x <= rx2; ++x) {
                float normX = (static_cast<float>(x) - bx1) / (bx2 - bx1 + 1e-4f);
                if (normX < 0.0f || normX > 1.0f) continue;
                float wX = std::sin(normX * 3.14159265f);

                float weight = wY * wX;
                if (weight <= 0.001f) continue;

                float srcX = static_cast<float>(x);
                float srcY = static_cast<float>(y) - std::copysign(maxOffset * weight, dy);

                uint8_t sampled[4];
                sampleBilinear(backup.data(), w, h, stride, srcX, srcY, sampled);

                uint8_t* dst = rgba + y * stride + x * 4;
                for (int c = 0; c < 4; ++c) {
                    dst[c] = sampled[c];
                }
            }
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
// 2. PARAM_BROW_ARCH: Nâng đỉnh vòm lông mày
// -----------------------------------------------------------------------------
bool EyebrowLashEngine::applyBrowArch(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
    const SubBrowModel* brows[2] = { &head.brow.left, &head.brow.right };

    std::vector<uint8_t> backup(w * h * 4);
    std::memcpy(backup.data(), rgba, w * h * 4);

    for (int b = 0; b < 2; ++b) {
        const auto& brow = *brows[b];
        Point2DF arch = brow.arch;
        float bx1 = std::min({ brow.head.x, brow.arch.x, brow.tail.x });
        float bx2 = std::max({ brow.head.x, brow.arch.x, brow.tail.x });

        float radius = (bx2 - bx1) * 0.45f;
        if (radius <= 5.0f) radius = 25.0f;

        float maxLift = radius * 0.25f * intensity;

        int rx1 = std::max(0, static_cast<int>(arch.x - radius));
        int rx2 = std::min(w - 1, static_cast<int>(arch.x + radius));
        int ry1 = std::max(0, static_cast<int>(arch.y - radius));
        int ry2 = std::min(h - 1, static_cast<int>(arch.y + radius));

        for (int y = ry1; y <= ry2; ++y) {
            for (int x = rx1; x <= rx2; ++x) {
                float dx = static_cast<float>(x) - arch.x;
                float dy = static_cast<float>(y) - arch.y;
                float dist = std::sqrt(dx * dx + dy * dy);
                if (dist > radius) continue;

                float normDist = dist / radius;
                float wArch = (1.0f - normDist * normDist);
                wArch = wArch * wArch;

                float srcX = static_cast<float>(x);
                float srcY = static_cast<float>(y) + maxLift * wArch;

                uint8_t sampled[4];
                sampleBilinear(backup.data(), w, h, stride, srcX, srcY, sampled);

                uint8_t* dst = rgba + y * stride + x * 4;
                for (int c = 0; c < 4; ++c) {
                    dst[c] = sampled[c];
                }
            }
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
// 3. PARAM_BROW_DENSITY_FILL: Làm rậm & điền sợi lông mày thưa
// -----------------------------------------------------------------------------
bool EyebrowLashEngine::applyBrowDensityFill(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
    const SubBrowModel* brows[2] = { &head.brow.left, &head.brow.right };

    for (int b = 0; b < 2; ++b) {
        const auto& brow = *brows[b];
        float bx1 = std::min({ brow.head.x, brow.arch.x, brow.tail.x }) - 5.0f;
        float bx2 = std::max({ brow.head.x, brow.arch.x, brow.tail.x }) + 5.0f;
        float by1 = std::min({ brow.head.y, brow.arch.y, brow.tail.y }) - brow.thickness * 0.5f - 5.0f;
        float by2 = std::max({ brow.head.y, brow.arch.y, brow.tail.y }) + brow.thickness * 0.5f + 5.0f;
        if (bx2 <= bx1 || by2 <= by1) continue;

        int rx1 = std::max(0, static_cast<int>(bx1));
        int rx2 = std::min(w - 1, static_cast<int>(bx2));
        int ry1 = std::max(0, static_cast<int>(by1));
        int ry2 = std::min(h - 1, static_cast<int>(by2));

        float fillAlpha = intensity * 0.40f;

        for (int y = ry1; y <= ry2; ++y) {
            float ny = (static_cast<float>(y) - by1) / (by2 - by1 + 1e-4f);
            float wY = std::sin(ny * 3.14159265f);

            for (int x = rx1; x <= rx2; ++x) {
                float nx = (static_cast<float>(x) - bx1) / (bx2 - bx1 + 1e-4f);
                float wX = std::sin(nx * 3.14159265f);
                float spatialWeight = wY * wX;

                uint8_t* p = rgba + y * stride + x * 4;
                int r = p[0], g = p[1], bPix = p[2];
                int lum = (r * 299 + g * 587 + bPix * 114) / 1000;

                if (lum < 180) {
                    float darknessFactor = (180.0f - static_cast<float>(lum)) / 180.0f;
                    float effectiveAlpha = fillAlpha * spatialWeight * (0.5f + 0.5f * darknessFactor);

                    p[0] = clampU8(static_cast<int>(r * (1.0f - effectiveAlpha * 0.45f)));
                    p[1] = clampU8(static_cast<int>(g * (1.0f - effectiveAlpha * 0.50f)));
                    p[2] = clampU8(static_cast<int>(bPix * (1.0f - effectiveAlpha * 0.55f)));
                }
            }
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
// 4. PARAM_BROW_COLOR: Nhuộm màu lông mày tự nhiên
// -----------------------------------------------------------------------------
bool EyebrowLashEngine::applyBrowColor(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
    const SubBrowModel* brows[2] = { &head.brow.left, &head.brow.right };

    float targetR = 55.0f;
    float targetG = 42.0f;
    float targetB = 35.0f;

    for (int b = 0; b < 2; ++b) {
        const auto& brow = *brows[b];
        float bx1 = std::min({ brow.head.x, brow.arch.x, brow.tail.x }) - 5.0f;
        float bx2 = std::max({ brow.head.x, brow.arch.x, brow.tail.x }) + 5.0f;
        float by1 = std::min({ brow.head.y, brow.arch.y, brow.tail.y }) - brow.thickness * 0.5f - 5.0f;
        float by2 = std::max({ brow.head.y, brow.arch.y, brow.tail.y }) + brow.thickness * 0.5f + 5.0f;

        int rx1 = std::max(0, static_cast<int>(bx1));
        int rx2 = std::min(w - 1, static_cast<int>(bx2));
        int ry1 = std::max(0, static_cast<int>(by1));
        int ry2 = std::min(h - 1, static_cast<int>(by2));

        for (int y = ry1; y <= ry2; ++y) {
            for (int x = rx1; x <= rx2; ++x) {
                uint8_t* p = rgba + y * stride + x * 4;
                int r = p[0], g = p[1], bPix = p[2];
                int lum = (r * 299 + g * 587 + bPix * 114) / 1000;
                if (lum > 165) continue;

                float alpha = intensity * 0.50f * ((165.0f - lum) / 165.0f);
                p[0] = clampU8(static_cast<int>(r * (1.0f - alpha) + targetR * alpha));
                p[1] = clampU8(static_cast<int>(g * (1.0f - alpha) + targetG * alpha));
                p[2] = clampU8(static_cast<int>(bPix * (1.0f - alpha) + targetB * alpha));
            }
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
// 5. PARAM_LASH_DENSITY: Làm dày gốc mi trên
// -----------------------------------------------------------------------------
bool EyebrowLashEngine::applyLashDensity(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
    const SubEyeModel* eyes[2] = { &head.eye.left, &head.eye.right };

    for (int e = 0; e < 2; ++e) {
        const auto& eye = *eyes[e];
        float inX = eye.innerCanthus.x;
        float inY = eye.innerCanthus.y;
        float outX = eye.outerCanthus.x;
        float outY = eye.outerCanthus.y;
        float midX = (inX + outX) * 0.5f;
        float midY = std::min(inY, outY) - eye.height * 0.25f;

        if (outX <= inX) continue;

        int steps = static_cast<int>(outX - inX);
        float boost = intensity * 0.55f;

        for (int i = 0; i <= steps; ++i) {
            float t = static_cast<float>(i) / (steps + 1e-4f);
            float px = inX * (1.0f - t) + outX * t;
            float py = (1.0f - t) * (1.0f - t) * inY + 2.0f * (1.0f - t) * t * midY + t * t * outY;

            for (int dy = -4; dy <= 0; ++dy) {
                int ix = static_cast<int>(px + 0.5f);
                int iy = static_cast<int>(py + dy + 0.5f);
                if (ix < 0 || ix >= w || iy < 0 || iy >= h) continue;

                if (static_cast<float>(iy) > py + 0.5f) continue;

                uint8_t* p = rgba + iy * stride + ix * 4;
                float falloff = (4.0f + static_cast<float>(dy)) / 4.0f;
                float alpha = boost * falloff;

                p[0] = clampU8(static_cast<int>(p[0] * (1.0f - alpha * 0.65f)));
                p[1] = clampU8(static_cast<int>(p[1] * (1.0f - alpha * 0.65f)));
                p[2] = clampU8(static_cast<int>(p[2] * (1.0f - alpha * 0.65f)));
            }
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
// 6. PARAM_LASH_LENGTH & CURL: Nối dài mi & uốn cong mi 3D
// -----------------------------------------------------------------------------
bool EyebrowLashEngine::applyLashLengthAndCurl(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity, bool curl) {
    const SubEyeModel* eyes[2] = { &head.eye.left, &head.eye.right };

    for (int e = 0; e < 2; ++e) {
        const auto& eye = *eyes[e];
        float inX = eye.innerCanthus.x;
        float inY = eye.innerCanthus.y;
        float outX = eye.outerCanthus.x;
        float outY = eye.outerCanthus.y;
        float midX = (inX + outX) * 0.5f;
        float midY = std::min(inY, outY) - eye.height * 0.25f;

        if (outX <= inX) continue;

        float lashLength = (eye.height * 0.35f + 4.0f) * std::min(1.0f, intensity);
        int numStrands = 24;

        for (int s = 0; s < numStrands; ++s) {
            float t = static_cast<float>(s) / static_cast<float>(numStrands - 1);
            float rootX = inX * (1.0f - t) + outX * t;
            float rootY = (1.0f - t) * (1.0f - t) * inY + 2.0f * (1.0f - t) * t * midY + t * t * outY;

            float dirX = (e == 0) ? -(t - 0.4f) * 0.8f : (t - 0.4f) * 0.8f;
            float dirY = -1.0f;
            float len = std::sqrt(dirX * dirX + dirY * dirY);
            dirX /= len;
            dirY /= len;

            float curlOffset = curl ? (t * 4.0f * (e == 0 ? -1.0f : 1.0f)) : 0.0f;

            int numSubsteps = static_cast<int>(lashLength * 2.0f);
            for (int step = 0; step < numSubsteps; ++step) {
                float frac = static_cast<float>(step) / static_cast<float>(numSubsteps);
                float curX = rootX + dirX * lashLength * frac + curlOffset * frac * frac;
                float curY = rootY + dirY * lashLength * frac;

                if (curY >= rootY) continue;

                int ix = static_cast<int>(curX + 0.5f);
                int iy = static_cast<int>(curY + 0.5f);
                if (ix < 0 || ix >= w || iy < 0 || iy >= h) continue;

                float strandAlpha = (1.0f - frac * 0.7f) * intensity * 0.75f;
                uint8_t* p = rgba + iy * stride + ix * 4;

                p[0] = clampU8(static_cast<int>(p[0] * (1.0f - strandAlpha) + 15.0f * strandAlpha));
                p[1] = clampU8(static_cast<int>(p[1] * (1.0f - strandAlpha) + 12.0f * strandAlpha));
                p[2] = clampU8(static_cast<int>(p[2] * (1.0f - strandAlpha) + 10.0f * strandAlpha));
            }
        }
    }
    return true;
}

} // namespace meitu_native

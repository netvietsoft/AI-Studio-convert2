#include "advanced_tone_engine.h"
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

// Helper: RGB to HSL
static void rgbToHsl(float r, float g, float b, float& h, float& s, float& l) {
    float maxC = std::max({r, g, b});
    float minC = std::min({r, g, b});
    l = (maxC + minC) * 0.5f;

    if (maxC == minC) {
        h = 0.0f;
        s = 0.0f;
    } else {
        float d = maxC - minC;
        s = l > 0.5f ? d / (2.0f - maxC - minC) : d / (maxC + minC);
        if (maxC == r) {
            h = (g - b) / d + (g < b ? 6.0f : 0.0f);
        } else if (maxC == g) {
            h = (b - r) / d + 2.0f;
        } else {
            h = (r - g) / d + 4.0f;
        }
        h /= 6.0f; // 0..1
    }
}

// Helper: HSL to RGB
static float hueToRgb(float p, float q, float t) {
    if (t < 0.0f) t += 1.0f;
    if (t > 1.0f) t -= 1.0f;
    if (t < 1.0f / 6.0f) return p + (q - p) * 6.0f * t;
    if (t < 1.0f / 2.0f) return q;
    if (t < 2.0f / 3.0f) return p + (q - p) * (2.0f / 3.0f - t) * 6.0f;
    return p;
}

static void hslToRgb(float h, float s, float l, float& r, float& g, float& b) {
    if (s == 0.0f) {
        r = g = b = l;
    } else {
        float q = l < 0.5f ? l * (1.0f + s) : l + s - l * s;
        float p = 2.0f * l - q;
        r = hueToRgb(p, q, h + 1.0f / 3.0f);
        g = hueToRgb(p, q, h);
        b = hueToRgb(p, q, h - 1.0f / 3.0f);
    }
}

// 1. Chỉnh màu HSL 8 Kênh độc lập
bool AdvancedToneEngine::applyHslChannel(
    uint32_t* pixels,
    int width,
    int height,
    int channelId,
    float hueShift,
    float satShift,
    float lumShift
) {
    if (!pixels || width <= 0 || height <= 0) return false;

    // Khoảng màu Hue (0..360) tương ứng với 8 kênh
    float centerHue = 0.0f;
    float rangeHue = 35.0f;

    switch (channelId) {
        case HSL_RED:     centerHue = 0.0f;   rangeHue = 25.0f; break;
        case HSL_ORANGE:  centerHue = 30.0f;  rangeHue = 20.0f; break;
        case HSL_YELLOW:  centerHue = 60.0f;  rangeHue = 25.0f; break;
        case HSL_GREEN:   centerHue = 120.0f; rangeHue = 45.0f; break;
        case HSL_CYAN:    centerHue = 180.0f; rangeHue = 35.0f; break;
        case HSL_BLUE:    centerHue = 225.0f; rangeHue = 40.0f; break;
        case HSL_PURPLE:  centerHue = 280.0f; rangeHue = 35.0f; break;
        case HSL_MAGENTA: centerHue = 320.0f; rangeHue = 30.0f; break;
        default: return false;
    }

    float normCenter = centerHue / 360.0f;
    float normRange = rangeHue / 360.0f;

    #pragma omp parallel for schedule(dynamic, 32)
    for (int i = 0; i < width * height; ++i) {
        uint32_t c = pixels[i];
        float r = RGBA_R(c) / 255.0f;
        float g = RGBA_G(c) / 255.0f;
        float b = RGBA_B(c) / 255.0f;

        float h, s, l;
        rgbToHsl(r, g, b, h, s, l);

        float dist = std::abs(h - normCenter);
        if (dist > 0.5f) dist = 1.0f - dist;

        if (dist < normRange) {
            float weight = 1.0f - (dist / normRange);
            h = std::fmod(h + (hueShift / 360.0f) * weight + 1.0f, 1.0f);
            s = std::clamp(s + (satShift * 0.01f) * weight, 0.0f, 1.0f);
            l = std::clamp(l + (lumShift * 0.01f) * weight, 0.0f, 1.0f);

            float nr, ng, nb;
            hslToRgb(h, s, l, nr, ng, nb);
            pixels[i] = PACK_RGBA(
                static_cast<int>(nr * 255.0f),
                static_cast<int>(ng * 255.0f),
                static_cast<int>(nb * 255.0f),
                RGBA_A(c)
            );
        }
    }
    return true;
}

// 2. Chỉnh thông số kỹ thuật màu nhiếp ảnh
bool AdvancedToneEngine::applyToneParam(
    uint32_t* pixels,
    int width,
    int height,
    int paramId,
    float value
) {
    if (!pixels || width <= 0 || height <= 0) return false;

    #pragma omp parallel for schedule(dynamic, 32)
    for (int i = 0; i < width * height; ++i) {
        uint32_t c = pixels[i];
        int r = RGBA_R(c);
        int g = RGBA_G(c);
        int b = RGBA_B(c);

        switch (paramId) {
            case TONE_BRIGHTNESS: {
                int shift = static_cast<int>(value * 2.55f);
                r = std::clamp(r + shift, 0, 255);
                g = std::clamp(g + shift, 0, 255);
                b = std::clamp(b + shift, 0, 255);
                break;
            }
            case TONE_CONTRAST: {
                float factor = (259.0f * (value + 100.0f)) / (100.0f * (259.0f - value));
                r = std::clamp(static_cast<int>(factor * (r - 128) + 128), 0, 255);
                g = std::clamp(static_cast<int>(factor * (g - 128) + 128), 0, 255);
                b = std::clamp(static_cast<int>(factor * (b - 128) + 128), 0, 255);
                break;
            }
            case TONE_SATURATION: {
                float lum = 0.299f * r + 0.587f * g + 0.114f * b;
                float satFactor = 1.0f + value * 0.01f;
                r = std::clamp(static_cast<int>(lum + (r - lum) * satFactor), 0, 255);
                g = std::clamp(static_cast<int>(lum + (g - lum) * satFactor), 0, 255);
                b = std::clamp(static_cast<int>(lum + (b - lum) * satFactor), 0, 255);
                break;
            }
            case TONE_TEMPERATURE: {
                // Nhiệt độ màu: Ấm (Tăng đỏ vàng) / Lạnh (Tăng lam)
                float shift = value * 0.5f;
                r = std::clamp(static_cast<int>(r + shift * 1.1f), 0, 255);
                g = std::clamp(static_cast<int>(g + shift * 0.5f), 0, 255);
                b = std::clamp(static_cast<int>(b - shift * 1.1f), 0, 255);
                break;
            }
            case TONE_TINT: {
                // Sắc thái Tint: Lục / Tím
                float shift = value * 0.5f;
                r = std::clamp(static_cast<int>(r + shift * 0.8f), 0, 255);
                g = std::clamp(static_cast<int>(g - shift * 1.2f), 0, 255);
                b = std::clamp(static_cast<int>(b + shift * 0.8f), 0, 255);
                break;
            }
        }
        pixels[i] = PACK_RGBA(r, g, b, RGBA_A(c));
    }
    return true;
}

// 3. Áp dụng 3D LUT Color Filter
bool AdvancedToneEngine::applyFilter(
    uint32_t* pixels,
    int width,
    int height,
    int filterId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);

    #pragma omp parallel for schedule(dynamic, 32)
    for (int i = 0; i < width * height; ++i) {
        uint32_t c = pixels[i];
        int r = RGBA_R(c);
        int g = RGBA_G(c);
        int b = RGBA_B(c);

        int tr = r, tg = g, tb = b;
        switch (filterId) {
            case FILTER_RETRO_FILM: // Tone ấm hoài niệm 35mm
                tr = std::clamp(static_cast<int>(r * 1.12f + 15), 0, 255);
                tg = std::clamp(static_cast<int>(g * 1.02f + 8), 0, 255);
                tb = std::clamp(static_cast<int>(b * 0.85f - 5), 0, 255);
                break;
            case FILTER_PORTRAIT_GLOW: // Nâng sáng hồng hào rạng ngời
                tr = std::clamp(static_cast<int>(r * 1.08f + 18), 0, 255);
                tg = std::clamp(static_cast<int>(g * 1.04f + 14), 0, 255);
                tb = std::clamp(static_cast<int>(b * 1.06f + 20), 0, 255);
                break;
            case FILTER_CYBERPUNK: // Xanh Teal & Cam Neon tương phản cao
                tr = std::clamp(static_cast<int>(r * 1.25f - 10), 0, 255);
                tg = std::clamp(static_cast<int>(g * 0.90f), 0, 255);
                tb = std::clamp(static_cast<int>(b * 1.35f + 25), 0, 255);
                break;
            case FILTER_MOODY_BW: // Đen trắng nghệ thuật chiều sâu tương phản
                {
                    int gray = (r * 299 + g * 587 + b * 114) / 1000;
                    float f = (gray - 128) * 1.25f + 128;
                    tr = tg = tb = std::clamp(static_cast<int>(f), 0, 255);
                }
                break;
            case FILTER_GOLDEN_HOUR: // Ánh nắng vàng hoàng hôn ấm áp
                tr = std::clamp(static_cast<int>(r * 1.20f + 25), 0, 255);
                tg = std::clamp(static_cast<int>(g * 1.10f + 12), 0, 255);
                tb = std::clamp(static_cast<int>(b * 0.75f - 15), 0, 255);
                break;
        }

        int finalR = static_cast<int>(r + (tr - r) * p);
        int finalG = static_cast<int>(g + (tg - g) * p);
        int finalB = static_cast<int>(b + (tb - b) * p);
        pixels[i] = PACK_RGBA(finalR, finalG, finalB, RGBA_A(c));
    }
    return true;
}

// 4. Áp dụng AI Retouch Preset (2.12)
bool AdvancedToneEngine::applyAiRetouch(
    uint32_t* pixels,
    int width,
    int height,
    int presetId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);

    #pragma omp parallel for schedule(dynamic, 32)
    for (int i = 0; i < width * height; ++i) {
        uint32_t c = pixels[i];
        int r = RGBA_R(c);
        int g = RGBA_G(c);
        int b = RGBA_B(c);

        int tr = r, tg = g, tb = b;
        switch (presetId) {
            case AI_PRESET_IDOL: // Trắng hồng Idol K-Pop
                tr = std::clamp(static_cast<int>(r * 1.06f + 22), 0, 255);
                tg = std::clamp(static_cast<int>(g * 1.05f + 18), 0, 255);
                tb = std::clamp(static_cast<int>(b * 1.12f + 28), 0, 255);
                break;
            case AI_PRESET_SCULPTED: // Tương phản khối 3D sắc nét
                {
                    float factor = 1.18f;
                    tr = std::clamp(static_cast<int>(factor * (r - 128) + 128), 0, 255);
                    tg = std::clamp(static_cast<int>(factor * (g - 128) + 128), 0, 255);
                    tb = std::clamp(static_cast<int>(factor * (b - 128) + 128), 0, 255);
                }
                break;
            case AI_PRESET_NATURAL_DEWY: // Da căng bóng mọng nước tự nhiên
                tr = std::clamp(static_cast<int>(r * 1.04f + 12), 0, 255);
                tg = std::clamp(static_cast<int>(g * 1.04f + 10), 0, 255);
                tb = std::clamp(static_cast<int>(b * 1.02f + 8), 0, 255);
                break;
            case AI_PRESET_FRESH_CLEAN: // Tinh khôi trong trẻo
                tr = std::clamp(static_cast<int>(r * 1.05f + 16), 0, 255);
                tg = std::clamp(static_cast<int>(g * 1.06f + 16), 0, 255);
                tb = std::clamp(static_cast<int>(b * 1.08f + 20), 0, 255);
                break;
        }

        int finalR = static_cast<int>(r + (tr - r) * p);
        int finalG = static_cast<int>(g + (tg - g) * p);
        int finalB = static_cast<int>(b + (tb - b) * p);
        pixels[i] = PACK_RGBA(finalR, finalG, finalB, RGBA_A(c));
    }
    return true;
}

// 5. Xóa phông Portrait Bokeh Defocus
bool AdvancedToneEngine::applyPortraitDefocus(
    uint32_t* pixels,
    int width,
    int height,
    float focusX, float focusY,
    float focusRadiusX, float focusRadiusY,
    float blurStrength
) {
    if (!pixels || width <= 0 || height <= 0 || blurStrength <= 0.001f) return false;
    float p = std::clamp(blurStrength, 0.0f, 1.0f);
    int kSize = std::max(2, static_cast<int>(p * 8.0f));

    std::vector<uint32_t> temp(pixels, pixels + width * height);

    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = 0; y < height; ++y) {
        float ny = (y - focusY) / focusRadiusY;
        float ny2 = ny * ny;
        for (int x = 0; x < width; ++x) {
            float nx = (x - focusX) / focusRadiusX;
            float d2 = nx * nx + ny2;

            // Vùng lấy nét (focus subject): không làm mờ
            if (d2 <= 0.85f) continue;

            float blurAmount = std::min(1.0f, (d2 - 0.85f) * 1.5f) * p;

            int sumR = 0, sumG = 0, sumB = 0, count = 0;
            for (int dy = -kSize; dy <= kSize; dy += 2) {
                int py = std::clamp(y + dy, 0, height - 1);
                for (int dx = -kSize; dx <= kSize; dx += 2) {
                    int px = std::clamp(x + dx, 0, width - 1);
                    uint32_t c = temp[py * width + px];
                    sumR += RGBA_R(c);
                    sumG += RGBA_G(c);
                    sumB += RGBA_B(c);
                    count++;
                }
            }

            int idx = y * width + x;
            uint32_t orig = temp[idx];
            int r0 = RGBA_R(orig);
            int g0 = RGBA_G(orig);
            int b0 = RGBA_B(orig);

            int finalR = static_cast<int>(r0 + (sumR / count - r0) * blurAmount);
            int finalG = static_cast<int>(g0 + (sumG / count - g0) * blurAmount);
            int finalB = static_cast<int>(b0 + (sumB / count - b0) * blurAmount);
            pixels[idx] = PACK_RGBA(finalR, finalG, finalB, RGBA_A(orig));
        }
    }
    return true;
}

} // namespace meitu_native

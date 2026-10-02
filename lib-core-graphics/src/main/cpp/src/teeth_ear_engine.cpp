#include "teeth_ear_engine.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <omp.h>

#define RGBA_R(c) ((c) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define PACK_RGBA(r, g, b, a) (((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(g) << 8) | (uint32_t)(r))

namespace meitu_native {

static inline uint32_t sampleBilinear(const uint32_t* src, int w, int h, float fx, float fy) {
    if (fx < 0.0f) fx = 0.0f;
    if (fy < 0.0f) fy = 0.0f;
    if (fx > (float)(w - 1)) fx = (float)(w - 1);
    if (fy > (float)(h - 1)) fy = (float)(h - 1);

    int x0 = (int)fx;
    int y0 = (int)fy;
    int x1 = (x0 + 1 < w) ? x0 + 1 : x0;
    int y1 = (y0 + 1 < h) ? y0 + 1 : y0;

    float wx = fx - (float)x0;
    float wy = fy - (float)y0;
    float w00 = (1.0f - wx) * (1.0f - wy);
    float w10 = wx * (1.0f - wy);
    float w01 = (1.0f - wx) * wy;
    float w11 = wx * wy;

    uint32_t p00 = src[y0 * w + x0];
    uint32_t p10 = src[y0 * w + x1];
    uint32_t p01 = src[y1 * w + x0];
    uint32_t p11 = src[y1 * w + x1];

    float r = RGBA_R(p00) * w00 + RGBA_R(p10) * w10 + RGBA_R(p01) * w01 + RGBA_R(p11) * w11;
    float g = RGBA_G(p00) * w00 + RGBA_G(p10) * w10 + RGBA_G(p01) * w01 + RGBA_G(p11) * w11;
    float b = RGBA_B(p00) * w00 + RGBA_B(p10) * w10 + RGBA_B(p01) * w01 + RGBA_B(p11) * w11;
    uint32_t a = RGBA_A(p00);

    return PACK_RGBA(
        (uint32_t)std::clamp((int)std::round(r), 0, 255),
        (uint32_t)std::clamp((int)std::round(g), 0, 255),
        (uint32_t)std::clamp((int)std::round(b), 0, 255),
        a
    );
}

// 1. Tẩy trắng và Chỉnh tông màu răng
bool TeethEarEngine::applyTeethWhitening(
    uint32_t* pixels,
    int width,
    int height,
    float mouthCenterX,
    float mouthCenterY,
    float radiusX,
    float radiusY,
    int shadeMode,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || radiusX <= 1.0f || radiusY <= 1.0f) {
        return false;
    }

    int minX = std::max(0, (int)(mouthCenterX - radiusX));
    int maxX = std::min(width - 1, (int)(mouthCenterX + radiusX));
    int minY = std::max(0, (int)(mouthCenterY - radiusY));
    int maxY = std::min(height - 1, (int)(mouthCenterY + radiusY));

    float factor = std::clamp(intensity, 0.0f, 1.0f);
    if (factor <= 0.001f) return true;

    #pragma omp parallel for schedule(dynamic, 8)
    for (int y = minY; y <= maxY; ++y) {
        int rowIdx = y * width;
        for (int x = minX; x <= maxX; ++x) {
            float dx = ((float)x - mouthCenterX) / radiusX;
            float dy = ((float)y - mouthCenterY) / radiusY;
            float distSq = dx * dx + dy * dy;

            if (distSq < 1.0f) {
                float spatialWeight = (1.0f - distSq) * factor;

                uint32_t c = pixels[rowIdx + x];
                float r = (float)RGBA_R(c);
                float g = (float)RGBA_G(c);
                float b = (float)RGBA_B(c);
                uint32_t a = RGBA_A(c);

                // Độ chói răng
                                // Do choi rang
                float lum = 0.299f * r + 0.587f * g + 0.114f * b;

                // 1. Loai bo khoang mieng qua toi
                if (lum < 55.0f || r < 50.0f) continue;

                // 2. Phan biet moi va rang dua tren do do (Redness metric)
                float rMinusG = r - g;
                float rMinusB = r - b;
                float rednessRatio = (r - g) / (r + g + 1.0f);

                // Loai bo moi: Sac do vuot troi
                if (rMinusG > 20.0f && rednessRatio > 0.11f) continue;
                if (rMinusB > 65.0f && rMinusG > 16.0f) continue;

                // 3. Rang nguoi tu nhien: Sac do trung tinh hoac men nga (r - g nho, b du lon)
                bool isTeethPixel = (lum >= 65.0f) && (b >= 35.0f) && (rMinusG <= 20.0f) && (rMinusB <= 65.0f);
                if (!isTeethPixel) continue;

                // 4. Thuat toan lam trang rang tham my: Bu kenh Blue khu vang + Nang sang tu nhien
                float yellowDefect = std::max(0.0f, (r + g) * 0.5f - b);
                float boostedB = b + yellowDefect * (0.65f + 0.35f * factor);

                float lumBoost = 28.0f * factor;
                float targetR = std::min(255.0f, r + lumBoost);
                float targetG = std::min(255.0f, g + lumBoost);
                float targetB = std::min(255.0f, boostedB + lumBoost);

                switch (shadeMode) {
                    case TEETH_SHADE_PORCELAIN: {
                        // Trang su Hollywood: Khu sach anh vang, tang nhe anh ngoc trai
                        targetB = std::min(255.0f, targetB * 1.04f);
                        targetR = std::min(255.0f, targetR * 1.01f);
                        targetG = std::min(255.0f, targetG * 1.01f);
                        break;
                    }
                    case TEETH_SHADE_IVORY: {
                        // Trang nga tu nhien: Giu chut anh am tu nhien
                        targetB = std::min(255.0f, boostedB * 0.94f + lumBoost * 0.8f);
                        break;
                    }
                    case TEETH_SHADE_ENAMEL: {
                        // Men rang sang bong: Tang do phan quang
                        float specularBoost = (lum > 140.0f) ? 15.0f * factor : 0.0f;
                        targetR = std::min(255.0f, targetR + specularBoost);
                        targetG = std::min(255.0f, targetG + specularBoost);
                        targetB = std::min(255.0f, targetB + specularBoost);
                        break;
                    }
                    case TEETH_SHADE_DARK: {
                        targetR = r * 0.75f;
                        targetG = g * 0.75f;
                        targetB = b * 0.75f;
                        break;
                    }
                }

                float finalR = r * (1.0f - spatialWeight) + targetR * spatialWeight;
                float finalG = g * (1.0f - spatialWeight) + targetG * spatialWeight;
                float finalB = b * (1.0f - spatialWeight) + targetB * spatialWeight;

                pixels[rowIdx + x] = PACK_RGBA(
                    (uint32_t)std::clamp((int)std::round(finalR), 0, 255),
                    (uint32_t)std::clamp((int)std::round(finalG), 0, 255),
                    (uint32_t)std::clamp((int)std::round(finalB), 0, 255),
                    a
                );
            }
        }
    }

    return true;
}

// 2. Chỉnh hình dạng răng (Kích thước, Hô/Vâu/Quặp, Đều/Thưa)
bool TeethEarEngine::applyTeethReshape(
    uint32_t* pixels,
    int width,
    int height,
    float mouthCenterX,
    float mouthCenterY,
    float radiusX,
    float radiusY,
    int shapeMode,
    float value
) {
    if (!pixels || width <= 0 || height <= 0 || radiusX <= 1.0f || radiusY <= 1.0f) {
        return false;
    }

    int minX = std::max(0, (int)(mouthCenterX - radiusX * 1.2f));
    int maxX = std::min(width - 1, (int)(mouthCenterX + radiusX * 1.2f));
    int minY = std::max(0, (int)(mouthCenterY - radiusY * 1.2f));
    int maxY = std::min(height - 1, (int)(mouthCenterY + radiusY * 1.2f));

    float normVal = value / 50.0f; // [-1.0f .. 1.0f]

    std::vector<uint32_t> snapshot(width * height);
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            snapshot[y * width + x] = pixels[y * width + x];
        }
    }

    #pragma omp parallel for schedule(dynamic, 8)
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            float dx = ((float)x - mouthCenterX) / radiusX;
            float dy = ((float)y - mouthCenterY) / radiusY;
            float distSq = dx * dx + dy * dy;

            if (distSq < 1.0f) {
                float falloff = (1.0f - distSq) * (1.0f - distSq);
                float sampleX = (float)x;
                float sampleY = (float)y;

                if (shapeMode == TEETH_SHAPE_SIZE) {
                    // Kích thước to (normVal > 0) / nhỏ (normVal < 0)
                    sampleX = (float)x - ((float)x - mouthCenterX) * normVal * falloff * 0.35f;
                    sampleY = (float)y - ((float)y - mouthCenterY) * normVal * falloff * 0.35f;
                } else if (shapeMode == TEETH_SHAPE_PROTRUSION) {
                    // Hô / Vâu (đẩy răng vào, dy âm) vs Quặp (kéo răng ra, dy dương)
                    sampleY = (float)y - normVal * radiusY * falloff * 0.45f;
                } else if (shapeMode == TEETH_SHAPE_ALIGN) {
                    // Chỉnh đều / thưa (Biến dạng tần số ngang răng)
                    float wave = std::sin(((float)x - mouthCenterX) * 0.25f);
                    sampleX = (float)x + wave * normVal * 4.0f * falloff;
                }

                pixels[y * width + x] = sampleBilinear(snapshot.data(), width, height, sampleX, sampleY);
            }
        }
    }

    return true;
}

namespace {
inline bool isEarSkinTone(uint8_t r, uint8_t g, uint8_t b) {
    if (r < 60 || g < 35 || b < 25) return false;
    if (r <= g) return false;
    if ((static_cast<int>(r) - static_cast<int>(g)) < 8) return false;
    if ((static_cast<int>(r) - static_cast<int>(b)) < 14) return false;
    if (r > 250 && g > 250 && b > 250) return false;

    float rf = static_cast<float>(r);
    float gf = static_cast<float>(g);
    float bf = static_cast<float>(b);
    float cr = 128.0f + 0.5f * rf - 0.418688f * gf - 0.081312f * bf;
    float cb = 128.0f - 0.168736f * rf - 0.331264f * gf + 0.5f * bf;
    return (cr >= 132.0f && cr <= 205.0f && cb >= 70.0f && cb <= 135.0f);
}
}

// 3. Chỉnh kích thước và độ dày tai
bool TeethEarEngine::applyEarReshape(
    uint32_t* pixels,
    int width,
    int height,
    float leftEarX,
    float leftEarY,
    float rightEarX,
    float rightEarY,
    float radius,
    int shapeMode,
    float value,
    bool isLeftVisible,
    bool isRightVisible
) {
    if (!pixels || width <= 0 || height <= 0 || radius <= 2.0f) return false;
    if (!isLeftVisible && !isRightVisible) return true; // Zero modification if neither ear is visible

    float normVal = value / 50.0f; // [-1.0f .. 1.0f]
    float rSq = radius * radius;

    // Snapshot buffer
    std::vector<uint32_t> snapshot(width * height);
    for (int i = 0; i < width * height; ++i) {
        snapshot[i] = pixels[i];
    }

    auto warpEar = [&](float earCenterX, float earCenterY, bool isLeft) {
        if (earCenterX <= 5.0f || earCenterY <= 5.0f) return;
        int minX = std::max(0, (int)(earCenterX - radius));
        int maxX = std::min(width - 1, (int)(earCenterX + radius));
        int minY = std::max(0, (int)(earCenterY - radius * 1.3f));
        int maxY = std::min(height - 1, (int)(earCenterY + radius * 1.3f));

        for (int y = minY; y <= maxY; ++y) {
            int rowIdx = y * width;
            for (int x = minX; x <= maxX; ++x) {
                float dx = (float)x - earCenterX;
                float dy = (float)y - earCenterY;
                float distSq = dx * dx + dy * dy;

                if (distSq < rSq) {
                    float falloff = (1.0f - distSq / rSq);
                    float weight = falloff * falloff;

                    float sampleX = (float)x;
                    float sampleY = (float)y;

                    if (shapeMode == EAR_SHAPE_SIZE) {
                        // Tai to (normVal > 0) đẩy ra ngoài, Tai nhỏ / ép tai vểnh (normVal < 0) ép vào hộp sọ
                        float dirX = isLeft ? -1.0f : 1.0f;
                        sampleX = (float)x - dirX * normVal * radius * weight * 0.40f;
                        sampleY = (float)y - normVal * radius * weight * 0.20f;
                    } else if (shapeMode == EAR_SHAPE_THICKNESS) {
                        // Độ dày dái tai (nửa dưới của tai, y > earCenterY)
                        if (y > earCenterY) {
                            float lobeWeight = ((float)(y - earCenterY) / (radius * 1.3f)) * weight;
                            sampleX = (float)x - (isLeft ? -1.0f : 1.0f) * normVal * radius * lobeWeight * 0.35f;
                            sampleY = (float)y - normVal * radius * lobeWeight * 0.35f;
                        }
                    }

                    uint32_t origVal = snapshot[rowIdx + x];
                    bool origSkin = isEarSkinTone(RGBA_R(origVal), RGBA_G(origVal), RGBA_B(origVal));

                    uint32_t sampled = sampleBilinear(snapshot.data(), width, height, sampleX, sampleY);
                    bool sampleSkin = isEarSkinTone(RGBA_R(sampled), RGBA_G(sampled), RGBA_B(sampled));

                    // ZERO BACKGROUND WARPING:
                    // If neither target pixel nor sampled pixel is ear skin tissue, preserve background 100%!
                    if (!origSkin && !sampleSkin) {
                        continue;
                    }

                    pixels[rowIdx + x] = sampled;
                }
            }
        }
    };

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            if (isLeftVisible) {
                warpEar(leftEarX, leftEarY, true);
            }
        }
        #pragma omp section
        {
            if (isRightVisible) {
                warpEar(rightEarX, rightEarY, false);
            }
        }
    }

    return true;
}

inline bool isEarSkinToneRGB(uint8_t r, uint8_t g, uint8_t b) {
    return isEarSkinTone(r, g, b);
}

// 4. Chỉnh sắc thái màu tai (Hồng hào ↔ Nhợt nhạt)
// Bảo vệ 100% gọng kính, mắt, tóc, má, nền - Chỉ tác động lên mô da tai thật
// 4. Chỉnh sắc thái màu tai chuẩn sinh lý học (Physiological Ear Capillary Blush)
// Bảo vệ 100% gọng kính, mắt, tóc, má, nền - Chỉ tác động lên mô sụn và dái tai thật
bool TeethEarEngine::applyEarColorTuning(
    uint32_t* pixels,
    int width,
    int height,
    float leftEarX,
    float leftEarY,
    float rightEarX,
    float rightEarY,
    float radius,
    float colorTone,
    bool isLeftVisible,
    bool isRightVisible,
    const float* landmarks106
) {
    if (!pixels || width <= 0 || height <= 0 || radius <= 2.0f) return false;
    if (!isLeftVisible && !isRightVisible) return true; // Cả hai tai đều khuất -> Bỏ qua 100%

    float normVal = colorTone / 50.0f; // [-1.0f .. 1.0f]
    if (std::abs(normVal) < 0.001f) return true;

    // Trích xuất cấu trúc mốc giải phẫu biên hàm (Jaw boundary) nếu có landmarks106
    struct Point2D { float x, y; };
    Point2D lJaw[5] = {
        { landmarks106 ? landmarks106[0*2] : (leftEarX + radius * 0.45f), landmarks106 ? landmarks106[0*2+1] : (leftEarY - radius * 0.9f) },
        { landmarks106 ? landmarks106[1*2] : (leftEarX + radius * 0.45f), landmarks106 ? landmarks106[1*2+1] : (leftEarY - radius * 0.4f) },
        { landmarks106 ? landmarks106[2*2] : (leftEarX + radius * 0.45f), landmarks106 ? landmarks106[2*2+1] : leftEarY },
        { landmarks106 ? landmarks106[3*2] : (leftEarX + radius * 0.40f), landmarks106 ? landmarks106[3*2+1] : (leftEarY + radius * 0.5f) },
        { landmarks106 ? landmarks106[4*2] : (leftEarX + radius * 0.35f), landmarks106 ? landmarks106[4*2+1] : (leftEarY + radius * 1.0f) }
    };

    Point2D rJaw[5] = {
        { landmarks106 ? landmarks106[32*2] : (rightEarX - radius * 0.45f), landmarks106 ? landmarks106[32*2+1] : (rightEarY - radius * 0.9f) },
        { landmarks106 ? landmarks106[31*2] : (rightEarX - radius * 0.45f), landmarks106 ? landmarks106[31*2+1] : (rightEarY - radius * 0.4f) },
        { landmarks106 ? landmarks106[30*2] : (rightEarX - radius * 0.45f), landmarks106 ? landmarks106[30*2+1] : rightEarY },
        { landmarks106 ? landmarks106[29*2] : (rightEarX - radius * 0.40f), landmarks106 ? landmarks106[29*2+1] : (rightEarY + radius * 0.5f) },
        { landmarks106 ? landmarks106[28*2] : (rightEarX - radius * 0.35f), landmarks106 ? landmarks106[28*2+1] : (rightEarY + radius * 1.0f) }
    };

    auto getJawX = [](const Point2D jaw[5], float y) -> float {
        if (y <= jaw[0].y) return jaw[0].x;
        if (y >= jaw[4].y) return jaw[4].x;
        for (int i = 0; i < 4; ++i) {
            float y1 = jaw[i].y, y2 = jaw[i+1].y;
            if ((y1 <= y && y <= y2) || (y2 <= y && y <= y1)) {
                float t = (y - y1) / (y2 - y1 + 1e-5f);
                return jaw[i].x + t * (jaw[i+1].x - jaw[i].x);
            }
        }
        return jaw[0].x;
    };

    auto colorEar = [&](float earCenterX, float earCenterY, bool isLeft) {
        const Point2D* jaw = isLeft ? lJaw : rJaw;
        float yTop = earCenterY - radius * 1.15f;
        float yBot = earCenterY + radius * 1.30f;
        float hEar = yBot - yTop;
        if (hEar <= 5.0f) return;

        int minY = std::max(0, static_cast<int>(yTop));
        int maxY = std::min(height - 1, static_cast<int>(yBot));
        float maxOutW = radius * 1.05f;

        for (int y = minY; y <= maxY; ++y) {
            float jawX = getJawX(jaw, static_cast<float>(y));
            if (isLeft && (jawX < earCenterX || jawX > earCenterX + radius * 2.0f)) {
                jawX = earCenterX + radius * 0.65f;
            } else if (!isLeft && (jawX > earCenterX || jawX < earCenterX - radius * 2.0f)) {
                jawX = earCenterX - radius * 0.65f;
            }
            float v = (static_cast<float>(y) - yTop) / hEar; // [0.0 .. 1.0] từ đỉnh vành xuống đáy dái tai
            float earSliceW = maxOutW * std::sin(std::clamp(v, 0.05f, 0.95f) * 3.14159265f);
            if (earSliceW < 2.0f) continue;

            int rowIdx = y * width;
            int xStart, xEnd;
            if (isLeft) {
                // Tai trái: Nằm bên TRÁI đường viền hàm (x < jawX)
                xStart = std::max(0, static_cast<int>(jawX - earSliceW * 1.35f));
                xEnd = std::min(width - 1, static_cast<int>(jawX - 1.0f));
            } else {
                // Tai phải: Nằm bên PHẢI đường viền hàm (x > jawX)
                xStart = std::max(0, static_cast<int>(jawX + 1.0f));
                xEnd = std::min(width - 1, static_cast<int>(jawX + earSliceW * 1.35f));
            }

            for (int x = xStart; x <= xEnd; ++x) {
                uint32_t c = pixels[rowIdx + x];
                uint8_t r = RGBA_R(c);
                uint8_t g = RGBA_G(c);
                uint8_t b = RGBA_B(c);
                uint32_t a = RGBA_A(c);

                // 1. Kiểm tra mô da sinh lý học (Loại bỏ nền chùa, tóc đen, quần áo)
                if (!isEarSkinToneRGB(r, g, b)) continue;

                // 2. Bảo vệ 100% gọng kính (Kính kim loại vàng chói hoặc đen gọng)
                float lum = 0.299f * r + 0.587f * g + 0.114f * b;
                if (lum < 32.0f || lum > 225.0f) continue;
                float sat = (std::max({r, g, b}) - std::min({r, g, b})) / (float)std::max({r, g, b, (uint8_t)1});
                if (sat < 0.08f) continue; // Kim loại trơ / màu xám gọng kính

                // 3. Tỷ lệ vị trí ngang u từ chân bám (0.0) đến mép vành tai ngoài (1.0)
                float distFromJaw = isLeft ? (jawX - static_cast<float>(x)) : (static_cast<float>(x) - jawX);
                if (distFromJaw <= 0.0f) continue;
                float u = std::clamp(distFromJaw / (earSliceW + 1e-4f), 0.0f, 1.0f);

                // 4. Trọng số tưới máu mao mạch sinh lý học (Capillary Blood Perfusion):
                // Tập trung cao ở gờ vành ngoài (u: 0.6..0.95) và dái tai (v: 0.6..0.95)
                float edgeFade = std::sin(u * 3.14159265f) * std::sin(v * 3.14159265f);
                float capillaryFactor = 0.65f + 0.35f * u + 0.30f * std::max(0.0f, v - 0.55f);
                float weight = std::clamp(edgeFade * capillaryFactor * std::abs(normVal), 0.0f, 1.0f);

                float targetR = (float)r;
                float targetG = (float)g;
                float targetB = (float)b;

                if (normVal > 0.0f) {
                    // Tai hồng hào tự nhiên sinh lý học
                    targetR = std::min(255.0f, (float)r * 1.18f + 14.0f);
                    targetG = (float)g * 0.94f;
                    targetB = std::min(255.0f, (float)b * 1.03f + 5.0f);
                } else {
                    // Tai nhợt nhạt / hạ tông đều màu da
                    targetR = (float)r * 0.90f + lum * 0.10f;
                    targetG = (float)g * 0.95f + lum * 0.05f;
                    targetB = (float)b * 0.95f + lum * 0.05f;
                }

                float finalR = (float)r * (1.0f - weight) + targetR * weight;
                float finalG = (float)g * (1.0f - weight) + targetG * weight;
                float finalB = (float)b * (1.0f - weight) + targetB * weight;

                pixels[rowIdx + x] = PACK_RGBA(
                    (uint32_t)std::clamp((int)std::round(finalR), 0, 255),
                    (uint32_t)std::clamp((int)std::round(finalG), 0, 255),
                    (uint32_t)std::clamp((int)std::round(finalB), 0, 255),
                    a
                );
            }
        }
    };

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            if (isLeftVisible) {
                colorEar(leftEarX, leftEarY, true);
            }
        }
        #pragma omp section
        {
            if (isRightVisible) {
                colorEar(rightEarX, rightEarY, false);
            }
        }
    }

    return true;
}

// ======================================================================================
// 5. PHÂN TÍCH GIẢI PHẪU TAI CHUẨN XÁC THEO CHỈ THỊ CHỦ TỊCH TONY
// Tính bo viền, vị trí tai so với má, cằm, mắt, hướng tai, nhận diện vành tai & khuôn tai
// ======================================================================================
EarAnatomyReport TeethEarEngine::analyzeEarAnatomy(
    const float* landmarks106,
    int imageWidth,
    int imageHeight,
    const uint32_t* pixels
) {
    EarAnatomyReport rep;
    std::memset(&rep, 0, sizeof(rep));
    if (imageWidth <= 0 || imageHeight <= 0) {
        rep.isValid = false;
        return rep;
    }

    bool hasLandmarks = (landmarks106 != nullptr);
    float eyeDist = static_cast<float>(imageWidth) * 0.25f;
    float lxEye = 0.0f, lyEye = 0.0f, rxEye = 0.0f, ryEye = 0.0f;
    float noseTipX = 0.0f, noseTipY = 0.0f;
    float lTragusX = 0.0f, lTragusY = 0.0f, rTragusX = 0.0f, rTragusY = 0.0f;
    float lLobeAttachX = 0.0f, lLobeAttachY = 0.0f, rLobeAttachX = 0.0f, rLobeAttachY = 0.0f;
    float chinX = 0.0f, chinY = 0.0f;
    float lCheekX = 0.0f, lCheekY = 0.0f, rCheekX = 0.0f, rCheekY = 0.0f;
    bool leftOccludedByGeom = false;
    bool rightOccludedByGeom = false;

    if (hasLandmarks) {
        lxEye = landmarks106[104 * 2];
        lyEye = landmarks106[104 * 2 + 1];
        rxEye = landmarks106[105 * 2];
        ryEye = landmarks106[105 * 2 + 1];

        eyeDist = std::hypot(rxEye - lxEye, ryEye - lyEye);
        bool eyesValid = (rxEye > lxEye) && (eyeDist >= 12.0f) &&
                         (std::abs(lyEye - ryEye) < 0.8f * eyeDist);

        noseTipX = landmarks106[60 * 2];
        noseTipY = landmarks106[60 * 2 + 1];
        if (noseTipY < lyEye || noseTipY < ryEye) {
            noseTipX = landmarks106[46 * 2];
            noseTipY = landmarks106[46 * 2 + 1];
        }
        bool noseValid = (noseTipY > lyEye) && (noseTipY > ryEye);

        if (!eyesValid || !noseValid) {
            hasLandmarks = false;
        }
    }

    if (hasLandmarks) {
        lTragusX = landmarks106[0 * 2];
        lTragusY = landmarks106[0 * 2 + 1];
        rTragusX = landmarks106[32 * 2];
        rTragusY = landmarks106[32 * 2 + 1];
        chinX = landmarks106[16 * 2];
        chinY = landmarks106[16 * 2 + 1];
        lCheekX = landmarks106[4 * 2];
        lCheekY = landmarks106[4 * 2 + 1];
        rCheekX = landmarks106[28 * 2];
        rCheekY = landmarks106[28 * 2 + 1];

        lLobeAttachX = landmarks106[4 * 2];
        lLobeAttachY = landmarks106[4 * 2 + 1];
        rLobeAttachX = landmarks106[28 * 2];
        rLobeAttachY = landmarks106[28 * 2 + 1];

        float eyeMidX = (lxEye + rxEye) * 0.5f;
        float yawOffset = (noseTipX - eyeMidX) / eyeDist;
        rep.headYawAngleDeg = yawOffset * 65.0f;

        float minLeftX = std::min({
            landmarks106[0 * 2], landmarks106[1 * 2], landmarks106[2 * 2],
            landmarks106[3 * 2], landmarks106[4 * 2]
        });
        float maxRightX = std::max({
            landmarks106[28 * 2], landmarks106[29 * 2], landmarks106[30 * 2],
            landmarks106[31 * 2], landmarks106[32 * 2]
        });

        float leftMargin = lxEye - minLeftX;
        float rightMargin = maxRightX - rxEye;
        float wLeftCheek = std::abs(noseTipX - minLeftX);
        float wRightCheek = std::abs(maxRightX - noseTipX);

        // ĐỊNH LUẬT BẤT BIẾN SINH LÝ HỌC & HÌNH HỌC 3D KHÔNG GIAN:
        // Mặt quay nghiêng: yawOffset > 0 nghĩa là mũi dịch sang phải so với trung điểm 2 mắt -> Quay mặt sang phải.
        // Khi quay mặt sang phải, má phải bị thu hẹp hoặc quay ra sau -> Tai phải bị che khuất!
        // Ngược lại khi quay trái, tai trái bị che khuất.
        leftOccludedByGeom = (yawOffset < -0.18f) || (leftMargin < 0.15f * eyeDist) || (wLeftCheek < 0.45f * wRightCheek);
        rightOccludedByGeom = (yawOffset > 0.18f) || (rightMargin < 0.15f * eyeDist) || (wRightCheek < 0.45f * wLeftCheek);

        // Cơ sở tọa độ từ mốc giải phẫu học
        rep.leftEarCenterX = lTragusX - 0.22f * eyeDist;
        rep.leftEarCenterY = (lTragusY + lLobeAttachY) * 0.5f;
        rep.rightEarCenterX = rTragusX + 0.22f * eyeDist;
        rep.rightEarCenterY = (rTragusY + rLobeAttachY) * 0.5f;
        rep.earRadius = std::max(18.0f, std::abs(lLobeAttachY - lTragusY) * 0.65f);
        rep.leftEyeToEarDist = std::hypot(rep.leftEarCenterX - lxEye, rep.leftEarCenterY - lyEye);
        rep.rightEyeToEarDist = std::hypot(rep.rightEarCenterX - rxEye, rep.rightEarCenterY - ryEye);
        float eyeMidY = (lyEye + ryEye) * 0.5f;
        rep.earToEyeElevation = eyeMidY - (rep.leftEarCenterY + rep.rightEarCenterY) * 0.5f;
        rep.earToCheekDistance = (std::abs(rep.leftEarCenterX - lCheekX) + std::abs(rep.rightEarCenterX - rCheekX)) * 0.5f;
        rep.earToChinVertical = (chinY - lTragusY + chinY - rTragusY) * 0.5f;
        rep.leftHelixTopX = lTragusX - 0.18f * eyeDist;
        rep.leftHelixTopY = lTragusY - 0.10f * eyeDist;
        rep.leftLobeBottomX = lTragusX - 0.15f * eyeDist;
        rep.leftLobeBottomY = lLobeAttachY + 0.15f * eyeDist;
        rep.rightHelixTopX = rTragusX + 0.18f * eyeDist;
        rep.rightHelixTopY = rTragusY - 0.10f * eyeDist;
        rep.rightLobeBottomX = rTragusX + 0.15f * eyeDist;
        rep.rightLobeBottomY = rLobeAttachY + 0.15f * eyeDist;
        rep.leftLobeCenterX = lTragusX - 0.18f * eyeDist;
        rep.leftLobeCenterY = lLobeAttachY + 0.05f * eyeDist;
        rep.rightLobeCenterX = rTragusX + 0.18f * eyeDist;
        rep.rightLobeCenterY = rLobeAttachY + 0.05f * eyeDist;
    } else {
        rep.earRadius = static_cast<float>(imageHeight) * 0.20f;
    }

    rep.isLeftEarVisible = !leftOccludedByGeom;
    rep.isRightEarVisible = !rightOccludedByGeom;

    // ==================================================================================
    // 5. THUẬT TOÁN QUÉT BIÊN DÒ VIỀN DA TAI THỰC TẾ & BẢO VỆ CHỐNG NỀN VÀNG (ADAPTIVE SILHOUETTE)
    // ==================================================================================
    if (pixels) {
        // Quét tìm đường viền vành tai ngoài (Outer Helix Rim) quét từ mốc xương hàm hướng ra ngoài
        auto scanOutwardHelix = [&](bool isLeft) -> std::pair<std::vector<std::pair<int, int>>, std::vector<int>> {
            std::vector<std::pair<int, int>> helix;
            std::vector<int> rowWidths;
            float dirX = isLeft ? -1.0f : 1.0f;
            int minY = hasLandmarks ? std::max(0, static_cast<int>((isLeft ? lTragusY : rTragusY) - 0.25f * eyeDist)) : 0;
            int maxY = hasLandmarks ? std::min(imageHeight - 1, static_cast<int>((isLeft ? lLobeAttachY : rLobeAttachY) + 0.35f * eyeDist)) : (imageHeight - 1);
            int maxDist = hasLandmarks ? static_cast<int>(0.65f * eyeDist) : static_cast<int>(imageWidth * 0.25f);

            for (int y = minY; y <= maxY; ++y) {
                float startX = 0.0f;
                if (hasLandmarks) {
                    startX = isLeft ? lTragusX : rTragusX;
                } else {
                    startX = isLeft ? static_cast<float>(imageWidth * 0.35f) : static_cast<float>(imageWidth * 0.65f);
                }

                int consecSkin = 0;
                int foundOuterX = -1;
                for (int d = 1; d <= maxDist; ++d) {
                    int x = static_cast<int>(startX + dirX * static_cast<float>(d));
                    if (x < 0 || x >= imageWidth) break;
                    uint32_t c = pixels[y * imageWidth + x];
                    if (isEarSkinTone(RGBA_R(c), RGBA_G(c), RGBA_B(c))) {
                        consecSkin++;
                        foundOuterX = x;
                    } else {
                        if (consecSkin >= 3) {
                            break;
                        } else if (consecSkin == 0 && d >= 3) {
                            break;
                        }
                    }
                }

                if (foundOuterX >= 0 && consecSkin >= 4) {
                    helix.push_back({foundOuterX, y});
                    rowWidths.push_back(consecSkin);
                }
            }
            return {helix, rowWidths};
        };

        auto [leftHelix, leftWidths] = scanOutwardHelix(true);
        auto [rightHelix, rightWidths] = scanOutwardHelix(false);

        // Đánh giá thực thể giải phẫu tai từ tập điểm viền ngoài
        auto processEarHelix = [&](const std::vector<std::pair<int, int>>& pts, const std::vector<int>& widths, bool isLeft) -> bool {
            int minPtsRequired = hasLandmarks ? 10 : 30;
            if (static_cast<int>(pts.size()) < minPtsRequired) return false;

            int minY = imageHeight, maxY = 0;
            int minX = imageWidth, maxX = 0;
            int maxRowWidth = 0;
            for (size_t i = 0; i < pts.size(); ++i) {
                const auto& p = pts[i];
                minY = std::min(minY, p.second);
                maxY = std::max(maxY, p.second);
                minX = std::min(minX, p.first);
                maxX = std::max(maxX, p.first);
                if (i < widths.size()) {
                    maxRowWidth = std::max(maxRowWidth, widths[i]);
                }
            }
            int hSpan = maxY - minY;
            int wSpan = maxX - minX;
            int minReqHeight = hasLandmarks ? static_cast<int>(eyeDist * 0.18f) : std::max(30, static_cast<int>(imageHeight * 0.10f));
            int minReqWidth = hasLandmarks ? 8 : 14;

            if (hSpan < minReqHeight || wSpan < minReqWidth || maxRowWidth < 8) return false;

            // Dái tai (Lobule): Chiếm 35% phía dưới cùng của vành tai
            int lobeMinY = minY + static_cast<int>(hSpan * 0.65f);
            float sumLobeX = 0.0f, sumLobeY = 0.0f;
            int countLobe = 0;
            float sumAllX = 0.0f;

            for (const auto& p : pts) {
                sumAllX += p.first;
                if (p.second >= lobeMinY) {
                    sumLobeX += p.first;
                    sumLobeY += p.second;
                    countLobe++;
                }
            }

            float cX = sumAllX / static_cast<float>(pts.size());
            float cY = (minY + maxY) * 0.5f;
            float lobeCX = isLeft ? (hasLandmarks ? (static_cast<float>(minX) + lLobeAttachX) * 0.5f : (static_cast<float>(minX) + static_cast<float>(wSpan) * 0.85f))
                                  : (hasLandmarks ? (static_cast<float>(maxX) + rLobeAttachX) * 0.5f : (static_cast<float>(maxX) - static_cast<float>(wSpan) * 0.85f));
            float lobeCY = static_cast<float>(minY) + static_cast<float>(hSpan) * 0.84f;

            if (isLeft) {
                rep.leftEarCenterX = hasLandmarks ? (cX + lTragusX) * 0.5f : (cX + 15.0f);
                rep.leftEarCenterY = cY;
                rep.earRadius = hSpan * 0.52f;
                rep.leftHelixTopX = static_cast<float>(pts.front().first);
                rep.leftHelixTopY = static_cast<float>(minY);
                rep.leftLobeBottomX = static_cast<float>(pts.back().first);
                rep.leftLobeBottomY = static_cast<float>(maxY);
                rep.leftLobeCenterX = lobeCX;
                rep.leftLobeCenterY = lobeCY;
                rep.leftEarMinX = minX;
                rep.leftEarMaxX = maxX + static_cast<int>(wSpan * 0.85f);
                rep.leftEarMinY = minY;
                rep.leftEarMaxY = maxY;
                float dx = rep.leftHelixTopX - rep.leftLobeBottomX;
                float dy = rep.leftLobeBottomY - rep.leftHelixTopY;
                rep.leftEarAngleDeg = (std::atan2(dx, dy) * 180.0f / 3.14159265f);
            } else {
                rep.rightEarCenterX = hasLandmarks ? (cX + rTragusX) * 0.5f : (cX - 15.0f);
                rep.rightEarCenterY = cY;
                rep.earRadius = hSpan * 0.52f;
                rep.rightHelixTopX = static_cast<float>(pts.front().first);
                rep.rightHelixTopY = static_cast<float>(minY);
                rep.rightLobeBottomX = static_cast<float>(pts.back().first);
                rep.rightLobeBottomY = static_cast<float>(maxY);
                rep.rightLobeCenterX = lobeCX;
                rep.rightLobeCenterY = lobeCY;
                rep.rightEarMinX = minX - static_cast<int>(wSpan * 0.85f);
                rep.rightEarMaxX = maxX;
                rep.rightEarMinY = minY;
                rep.rightEarMaxY = maxY;
                float dx = rep.rightHelixTopX - rep.rightLobeBottomX;
                float dy = rep.rightLobeBottomY - rep.rightHelixTopY;
                rep.rightEarAngleDeg = (std::atan2(dx, dy) * 180.0f / 3.14159265f);
            }
            return true;
        };

        bool leftDetected = processEarHelix(leftHelix, leftWidths, true);
        bool rightDetected = processEarHelix(rightHelix, rightWidths, false);

        rep.isLeftEarVisible = leftDetected && !leftOccludedByGeom;
        rep.isRightEarVisible = rightDetected && !rightOccludedByGeom;

        // Khi không nhận diện được tai (chụp nghiêng, che khuất):
        // TRIỆT TIÊU TOÀN BỘ TỌA ĐỘ VỀ 0 - TUYỆT ĐỐI KHÔNG TỰ Ý ĐỐI XỨNG HOẶC THAY ĐỔI
        if (!rep.isLeftEarVisible) {
            rep.leftEarCenterX = 0.0f;
            rep.leftEarCenterY = 0.0f;
            rep.leftLobeCenterX = 0.0f;
            rep.leftLobeCenterY = 0.0f;
            rep.leftHelixTopX = 0.0f;
            rep.leftHelixTopY = 0.0f;
            rep.leftLobeBottomX = 0.0f;
            rep.leftLobeBottomY = 0.0f;
            rep.leftEarMinX = 0; rep.leftEarMaxX = 0;
            rep.leftEarMinY = 0; rep.leftEarMaxY = 0;
            rep.leftEarAngleDeg = 0.0f;
        }

        if (!rep.isRightEarVisible) {
            rep.rightEarCenterX = 0.0f;
            rep.rightEarCenterY = 0.0f;
            rep.rightLobeCenterX = 0.0f;
            rep.rightLobeCenterY = 0.0f;
            rep.rightHelixTopX = 0.0f;
            rep.rightHelixTopY = 0.0f;
            rep.rightLobeBottomX = 0.0f;
            rep.rightLobeBottomY = 0.0f;
            rep.rightEarMinX = 0; rep.rightEarMaxX = 0;
            rep.rightEarMinY = 0; rep.rightEarMaxY = 0;
            rep.rightEarAngleDeg = 0.0f;
        }
    }

    rep.isValid = true;
    return rep;
}

// ======================================================================================
// 6. BIẾN DẠNG TẠO HÌNH TAI NGHỆ THUẬT (ARTISTIC EAR ENGINE)
// 100% Bảo vệ quai hàm, gò má, cổ. Tuyệt đối không có cạnh chữ nhật hay vệt gián đoạn.
// ======================================================================================
bool TeethEarEngine::applyEarStyle(
    uint32_t* pixels,
    int width,
    int height,
    const float* landmarks106,
    float leftEarX, float leftEarY,
    float rightEarX, float rightEarY,
    float radius,
    int earStyle,
    float intensity,
    bool isLeftVisible,
    bool isRightVisible
) {
    if (!pixels || width <= 0 || height <= 0) return false;
    if (!isLeftVisible && !isRightVisible) return true;
    float factor = intensity / 100.0f; // [-1.0 .. +1.0]
    if (std::abs(factor) < 0.001f) return true;

    std::vector<uint32_t> snapshot(width * height);
    std::memcpy(snapshot.data(), pixels, width * height * sizeof(uint32_t));

    float lxEye = 0.0f, lyEye = 0.0f, rxEye = 0.0f, ryEye = 0.0f, eyeDist = 200.0f;
    if (landmarks106) {
        lxEye = landmarks106[104 * 2];
        lyEye = landmarks106[104 * 2 + 1];
        rxEye = landmarks106[105 * 2];
        ryEye = landmarks106[105 * 2 + 1];
        eyeDist = std::hypot(rxEye - lxEye, ryEye - lyEye);
    }
    if (eyeDist < 10.0f) eyeDist = radius > 10.0f ? (radius / 0.45f) : (width * 0.25f);

    struct Point2D { float x, y; };
    Point2D lJaw[7] = {
        { landmarks106 ? landmarks106[0*2] : (leftEarX + 0.08f * eyeDist), landmarks106 ? landmarks106[0*2+1] : (leftEarY - 0.25f * eyeDist) },
        { landmarks106 ? landmarks106[1*2] : (leftEarX + 0.08f * eyeDist), landmarks106 ? landmarks106[1*2+1] : (leftEarY - 0.10f * eyeDist) },
        { landmarks106 ? landmarks106[2*2] : (leftEarX + 0.08f * eyeDist), landmarks106 ? landmarks106[2*2+1] : leftEarY },
        { landmarks106 ? landmarks106[3*2] : (leftEarX + 0.06f * eyeDist), landmarks106 ? landmarks106[3*2+1] : (leftEarY + 0.15f * eyeDist) },
        { landmarks106 ? landmarks106[4*2] : (leftEarX + 0.05f * eyeDist), landmarks106 ? landmarks106[4*2+1] : (leftEarY + 0.30f * eyeDist) },
        { landmarks106 ? landmarks106[5*2] : (leftEarX + 0.05f * eyeDist), landmarks106 ? landmarks106[5*2+1] : (leftEarY + 0.45f * eyeDist) },
        { landmarks106 ? landmarks106[6*2] : (leftEarX + 0.05f * eyeDist), landmarks106 ? landmarks106[6*2+1] : (leftEarY + 0.60f * eyeDist) }
    };

    Point2D rJaw[7] = {
        { landmarks106 ? landmarks106[32*2] : (rightEarX - 0.08f * eyeDist), landmarks106 ? landmarks106[32*2+1] : (rightEarY - 0.25f * eyeDist) },
        { landmarks106 ? landmarks106[31*2] : (rightEarX - 0.08f * eyeDist), landmarks106 ? landmarks106[31*2+1] : (rightEarY - 0.10f * eyeDist) },
        { landmarks106 ? landmarks106[30*2] : (rightEarX - 0.08f * eyeDist), landmarks106 ? landmarks106[30*2+1] : rightEarY },
        { landmarks106 ? landmarks106[29*2] : (rightEarX - 0.06f * eyeDist), landmarks106 ? landmarks106[29*2+1] : (rightEarY + 0.15f * eyeDist) },
        { landmarks106 ? landmarks106[28*2] : (rightEarX - 0.05f * eyeDist), landmarks106 ? landmarks106[28*2+1] : (rightEarY + 0.30f * eyeDist) },
        { landmarks106 ? landmarks106[27*2] : (rightEarX - 0.05f * eyeDist), landmarks106 ? landmarks106[27*2+1] : (rightEarY + 0.45f * eyeDist) },
        { landmarks106 ? landmarks106[26*2] : (rightEarX - 0.05f * eyeDist), landmarks106 ? landmarks106[26*2+1] : (rightEarY + 0.60f * eyeDist) }
    };

    auto getJawX = [](const Point2D jaw[7], float y) -> float {
        if (y <= jaw[0].y) return jaw[0].x;
        if (y >= jaw[6].y) return jaw[6].x;
        for (int i = 0; i < 6; ++i) {
            float y1 = jaw[i].y, y2 = jaw[i+1].y;
            if ((y1 <= y && y <= y2) || (y2 <= y && y <= y1)) {
                float t = (y - y1) / (y2 - y1 + 1e-5f);
                return jaw[i].x + t * (jaw[i+1].x - jaw[i].x);
            }
        }
        return jaw[0].x;
    };

    auto isEarSkin = [](uint8_t r, uint8_t g, uint8_t b) -> bool {
        if (r < 115 || g < 65 || b < 50) return false;
        if (static_cast<int>(r) - static_cast<int>(g) < 14 || static_cast<int>(r) - static_cast<int>(b) < 20) return false;
        return true;
    };

    auto warpStyleEar = [&](bool isLeft) {
        float dirX = isLeft ? -1.0f : 1.0f;
        const Point2D* jaw = isLeft ? lJaw : rJaw;

        int earScanMinY = std::max(0, static_cast<int>(jaw[0].y - 0.50f * eyeDist));
        int earScanMaxY = std::min(height - 1, static_cast<int>(jaw[5].y + 0.40f * eyeDist));

        std::vector<float> origOuterX(height, 0.0f);
        std::vector<bool> hasOuterX(height, false);
        int earMinY = height, earMaxY = 0;
        int validRowCount = 0;
        int maxScanD = static_cast<int>(std::max(20.0f, eyeDist * 0.90f));

        // Quét viền ngoài tai từ quai hàm tiến ra ngoài
        for (int y = earScanMinY; y <= earScanMaxY; ++y) {
            float jx = getJawX(jaw, static_cast<float>(y));
            float edgeX = jx;
            int consecutiveNonSkin = 0;
            for (int d = 1; d <= maxScanD; ++d) {
                int x = static_cast<int>(std::round(jx + dirX * static_cast<float>(d)));
                if (x < 0 || x >= width) break;
                uint32_t c = snapshot[y * width + x];
                if (isEarSkin(RGBA_R(c), RGBA_G(c), RGBA_B(c))) {
                    edgeX = static_cast<float>(x);
                    consecutiveNonSkin = 0;
                } else {
                    consecutiveNonSkin++;
                    if (consecutiveNonSkin >= 2) break;
                }
            }
            float w = isLeft ? (jx - edgeX) : (edgeX - jx);
            if (w >= 3.5f) {
                origOuterX[y] = edgeX;
                hasOuterX[y] = true;
                earMinY = std::min(earMinY, y);
                earMaxY = std::max(earMaxY, y);
                validRowCount++;
            }
        }

        // Nếu tai không tồn tại thực tế trên ảnh (bị che khuất hoặc quay mặt): bảo vệ nền 100%!
        if (validRowCount < 5 || earMinY >= earMaxY) {
            return;
        }

        // Lọc trung vị viền ngoài khử răng cưa
        std::vector<float> smoothOuterX = origOuterX;
        for (int y = earMinY; y <= earMaxY; ++y) {
            std::vector<float> win;
            for (int dy = -2; dy <= 2; ++dy) {
                int wy = y + dy;
                if (wy >= earMinY && wy <= earMaxY && hasOuterX[wy]) {
                    win.push_back(origOuterX[wy]);
                }
            }
            if (!win.empty()) {
                std::sort(win.begin(), win.end());
                smoothOuterX[y] = win[win.size() / 2];
            } else {
                float jx = getJawX(jaw, static_cast<float>(y));
                smoothOuterX[y] = jx + dirX * 15.0f;
            }
        }

        auto getOrigOuterX = [&](int y) -> float {
            int cy = std::min(earMaxY, std::max(earMinY, y));
            return smoothOuterX[cy];
        };

        float origEarH = static_cast<float>(earMaxY - earMinY);
        float lobeTopY = static_cast<float>(earMinY) + origEarH * 0.55f;
        float origLobeH = static_cast<float>(earMaxY) - lobeTopY;

        float maxElong = 0.0f;
        float maxWBoost = 0.0f;
        float newEarMaxY = static_cast<float>(earMaxY);

        if (earStyle == EAR_STYLE_BUDDHA) {
            maxElong = 0.35f * origLobeH * factor;
            maxWBoost = 0.35f * 20.0f * factor;
            newEarMaxY = static_cast<float>(earMaxY) + maxElong;
        } else if (earStyle == EAR_STYLE_THICKNESS) {
            maxElong = 0.15f * origLobeH * factor;
            maxWBoost = 0.25f * 20.0f * factor;
            newEarMaxY = static_cast<float>(earMaxY) + maxElong;
        } else if (earStyle == EAR_STYLE_ELF) {
            maxWBoost = 0.25f * 20.0f * factor;
        } else {
            maxWBoost = 0.20f * 20.0f * factor;
        }

        int renderMinY = earMinY;
        int renderMaxY = std::min(height - 1, static_cast<int>(newEarMaxY) + 2);

        for (int py = renderMinY; py <= renderMaxY; ++py) {
            float yf = static_cast<float>(py);
            float jx = getJawX(jaw, yf);
            float targetOx = jx;

            if (earStyle == EAR_STYLE_BUDDHA || earStyle == EAR_STYLE_THICKNESS) {
                if (yf <= lobeTopY) {
                    targetOx = getOrigOuterX(py);
                } else if (yf <= static_cast<float>(earMaxY)) {
                    float t = (yf - lobeTopY) / (static_cast<float>(earMaxY) - lobeTopY);
                    targetOx = getOrigOuterX(py) + dirX * maxWBoost * std::sin(3.14159265f * t);
                } else {
                    float t = (yf - static_cast<float>(earMaxY)) / (newEarMaxY - static_cast<float>(earMaxY) + 1e-4f);
                    if (t <= 1.0f) {
                        float roundTaper = std::sqrt(std::max(0.0f, 1.0f - t * t));
                        float botOrigOx = getOrigOuterX(earMaxY);
                        float earWAtBot = isLeft ? (getJawX(jaw, static_cast<float>(earMaxY)) - botOrigOx)
                                                 : (botOrigOx - getJawX(jaw, static_cast<float>(earMaxY)));
                        float tipW = earWAtBot * roundTaper;
                        targetOx = jx + dirX * tipW;
                    } else {
                        targetOx = jx;
                    }
                }
            } else if (earStyle == EAR_STYLE_ELF) {
                if (yf <= lobeTopY) {
                    float t = (lobeTopY - yf) / (lobeTopY - static_cast<float>(earMinY) + 1e-4f);
                    targetOx = getOrigOuterX(py) + dirX * maxWBoost * std::sin(3.14159265f * t);
                } else {
                    targetOx = getOrigOuterX(py);
                }
            } else if (earStyle == EAR_STYLE_PRESS) {
                float origOx = getOrigOuterX(py);
                float curW = isLeft ? (jx - origOx) : (origOx - jx);
                targetOx = jx + dirX * std::max(4.0f, curW * (1.0f - 0.35f * factor));
            } else {
                float t = (yf - static_cast<float>(earMinY)) / origEarH;
                targetOx = getOrigOuterX(py) + dirX * maxWBoost * std::sin(3.14159265f * t);
            }

            int minX = std::max(0, static_cast<int>(std::floor(isLeft ? (targetOx - 1.5f) : (jx - 1.5f))));
            int maxX = std::min(width - 1, static_cast<int>(std::ceil(isLeft ? (jx + 1.5f) : (targetOx + 1.5f))));

            int rowIdx = py * width;
            for (int px = minX; px <= maxX; ++px) {
                float distInside = isLeft ? (static_cast<float>(px) - targetOx) : (targetOx - static_cast<float>(px));
                if (distInside < -1.0f) {
                    continue; // 100% BẢO VỆ NỀN: Nằm ngoài tai -> giữ nguyên snapshot gốc!
                }

                float newW = std::max(1.0f, isLeft ? (jx - targetOx) : (targetOx - jx));
                float uW = std::min(1.0f, std::max(0.0f, isLeft ? (jx - static_cast<float>(px)) / newW
                                                                : (static_cast<float>(px) - jx) / newW));

                float sy = yf;
                float sx = static_cast<float>(px);

                if (yf <= lobeTopY || (earStyle != EAR_STYLE_BUDDHA && earStyle != EAR_STYLE_THICKNESS)) {
                    sy = yf;
                    int syInt = std::min(earMaxY, std::max(earMinY, static_cast<int>(std::round(sy))));
                    float origOx = getOrigOuterX(syInt);
                    float origW = std::max(1.0f, isLeft ? (jx - origOx) : (origOx - jx));
                    sx = jx + dirX * (uW * origW);
                } else if (yf <= static_cast<float>(earMaxY)) {
                    sy = lobeTopY + (yf - lobeTopY) * (origLobeH / (newEarMaxY - lobeTopY + 1e-4f));
                    int syInt = std::min(earMaxY, std::max(earMinY, static_cast<int>(std::round(sy))));
                    float origOx = getOrigOuterX(syInt);
                    float srcJx = getJawX(jaw, sy);
                    float origW = std::max(1.0f, isLeft ? (srcJx - origOx) : (origOx - srcJx));
                    sx = srcJx + dirX * (uW * origW);
                } else {
                    float t = (yf - static_cast<float>(earMaxY)) / (newEarMaxY - static_cast<float>(earMaxY) + 1e-4f);
                    sy = static_cast<float>(earMaxY) - 2.0f - 4.0f * (1.0f - t);
                    int syInt = std::min(earMaxY, std::max(earMinY, static_cast<int>(std::round(sy))));
                    float origOx = getOrigOuterX(syInt);
                    float srcJx = getJawX(jaw, sy);
                    float origW = std::max(1.0f, isLeft ? (srcJx - origOx) : (origOx - srcJx));
                    sx = srcJx + dirX * (uW * origW);
                }

                uint32_t sampled = sampleBilinear(snapshot.data(), width, height, sx, sy);

                // Highlight nổi khối ở tâm dái tai tạo độ căng mọng sinh lý học
                if ((earStyle == EAR_STYLE_BUDDHA || earStyle == EAR_STYLE_THICKNESS) && yf > lobeTopY && yf < newEarMaxY && factor > 0.05f) {
                    float tV = (yf - lobeTopY) / (newEarMaxY - lobeTopY);
                    float hl = std::sin(3.14159265f * tV) * std::sin(3.14159265f * uW) * 0.06f * factor;
                    float r = std::min(255.0f, RGBA_R(sampled) * (1.0f + hl) + 2.0f);
                    float g = std::min(255.0f, RGBA_G(sampled) * (1.0f + hl));
                    float b = std::min(255.0f, RGBA_B(sampled) * (1.0f + hl * 0.5f));
                    sampled = PACK_RGBA(static_cast<int>(r), static_cast<int>(g), static_cast<int>(b), RGBA_A(sampled));
                }

                float a = std::min(1.0f, std::max(0.0f, (distInside + 1.0f) / 1.5f));
                float alpha = a * a * (3.0f - 2.0f * a);

                if (alpha < 0.999f) {
                    uint32_t bg = snapshot[rowIdx + px];
                    float r = RGBA_R(bg) * (1.0f - alpha) + RGBA_R(sampled) * alpha;
                    float g = RGBA_G(bg) * (1.0f - alpha) + RGBA_G(sampled) * alpha;
                    float b = RGBA_B(bg) * (1.0f - alpha) + RGBA_B(sampled) * alpha;
                    sampled = PACK_RGBA(static_cast<int>(r), static_cast<int>(g), static_cast<int>(b), RGBA_A(bg));
                }

                pixels[rowIdx + px] = sampled;
            }
        }
    };

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            if (isLeftVisible) {
                warpStyleEar(true);
            }
        }
        #pragma omp section
        {
            if (isRightVisible) {
                warpStyleEar(false);
            }
        }
    }

    return true;
}

} // namespace meitu_native

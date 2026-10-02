#include "face_retouch_detail.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <omp.h>

#define RGBA_R(c) ((c) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define PACK_RGBA(r, g, b, a) (((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(g) << 8) | (uint32_t)(r))

namespace MeituReborn {

namespace {

inline float smoothstep(float edge0, float edge1, float x) {
    float t = std::clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
    return t * t * (3.0f - 2.0f * t);
}

inline uint32_t sampleBilinear(const uint32_t* src, int w, int h, float fx, float fy) {
    if (fx < 0.0f) fx = 0.0f;
    if (fy < 0.0f) fy = 0.0f;
    if (fx > w - 1.001f) fx = w - 1.001f;
    if (fy > h - 1.001f) fy = h - 1.001f;

    int x0 = static_cast<int>(fx);
    int y0 = static_cast<int>(fy);
    int x1 = std::min(x0 + 1, w - 1);
    int y1 = std::min(y0 + 1, h - 1);

    float dx = fx - x0;
    float dy = fy - y0;

    uint32_t c00 = src[y0 * w + x0];
    uint32_t c10 = src[y0 * w + x1];
    uint32_t c01 = src[y1 * w + x0];
    uint32_t c11 = src[y1 * w + x1];

    float w00 = (1.0f - dx) * (1.0f - dy);
    float w10 = dx * (1.0f - dy);
    float w01 = (1.0f - dx) * dy;
    float w11 = dx * dy;

    int r = static_cast<int>(RGBA_R(c00) * w00 + RGBA_R(c10) * w10 + RGBA_R(c01) * w01 + RGBA_R(c11) * w11);
    int g = static_cast<int>(RGBA_G(c00) * w00 + RGBA_G(c10) * w10 + RGBA_G(c01) * w01 + RGBA_G(c11) * w11);
    int b = static_cast<int>(RGBA_B(c00) * w00 + RGBA_B(c10) * w10 + RGBA_B(c01) * w01 + RGBA_B(c11) * w11);
    int a = static_cast<int>(RGBA_A(c00) * w00 + RGBA_A(c10) * w10 + RGBA_A(c01) * w01 + RGBA_A(c11) * w11);

    return PACK_RGBA(std::clamp(r, 0, 255), std::clamp(g, 0, 255), std::clamp(b, 0, 255), std::clamp(a, 0, 255));
}

inline float softLightBlend(float a, float b) {
    // Photoshop Soft-Light formulation normalized [0, 1]
    return (b < 0.5f) ? (2.0f * a * b + a * a * (1.0f - 2.0f * b))
                      : (std::sqrt(a) * (2.0f * b - 1.0f) + 2.0f * a * (1.0f - b));
}

struct LensColorRGB {
    float r, g, b;
};

const LensColorRGB LENS_PALETTE[8] = {
    {135.0f, 90.0f, 60.0f},   // 0: Natural Amber-Brown
    {40.0f, 115.0f, 225.0f},  // 1: Sapphire Blue
    {35.0f, 165.0f, 95.0f},   // 2: Emerald Green
    {185.0f, 135.0f, 60.0f},  // 3: Hazel Amber
    {150.0f, 155.0f, 165.0f}, // 4: Smoky Gray
    {155.0f, 85.0f, 215.0f},  // 5: Royal Violet
    {215.0f, 165.0f, 55.0f},  // 6: Golden Amber
    {180.0f, 110.0f, 50.0f}   // 7: Honey Brown
};

} // namespace

bool FaceRetouchDetail::applyIrisMakeup(
    uint32_t* pixels, int width, int height,
    const IrisTrackResult& iris,
    float pupilScale, float glowIntensity,
    int toneId, float toneIntensity,
    int catchlightType, float catchlightIntensity
) {
    if (!pixels || width <= 0 || height <= 0) return false;
    if (iris.leftRadius <= 1.0f && iris.rightRadius <= 1.0f) return false;

    // Buffer sao chep de bien dang pupil co do muot bilinear cao
    std::vector<uint32_t> tempCopy;
    if (std::abs(pupilScale) > 0.01f) {
        tempCopy.assign(pixels, pixels + width * height);
    }

    struct IrisInstance {
        Point3D center;
        float radius;
        bool isLeft;
    };

    IrisInstance instances[2] = {
        {iris.leftCenter, iris.leftRadius, true},
        {iris.rightCenter, iris.rightRadius, false}
    };

    for (const auto& eye : instances) {
        float cx = eye.center.x;
        float cy = eye.center.y;
        float r = eye.radius;
        if (r < 2.0f) continue;

        float maxSupport = r * 1.25f;
        int minX = std::max(0, static_cast<int>(cx - maxSupport));
        int maxX = std::min(width - 1, static_cast<int>(cx + maxSupport));
        int minY = std::max(0, static_cast<int>(cy - maxSupport));
        int maxY = std::min(height - 1, static_cast<int>(cy + maxSupport));

        // 1. Bien dang gian trong / thu nho dong tu (Pupil Scale Warp)
        if (std::abs(pupilScale) > 0.01f && !tempCopy.empty()) {
            float pWarp = pupilScale * 0.45f;
            for (int y = minY; y <= maxY; ++y) {
                for (int x = minX; x <= maxX; ++x) {
                    float dx = x - cx;
                    float dy = y - cy;
                    float dist = std::hypot(dx, dy);
                    if (dist > maxSupport || dist < 0.001f) continue;

                    float factor = 1.0f;
                    if (dist < r) {
                        float normalized = dist / r;
                        // Smooth cubic displacement
                        float w = (1.0f - normalized * normalized);
                        factor = 1.0f - pWarp * w;
                    }

                    float srcX = cx + dx * factor;
                    float srcY = cy + dy * factor;
                    pixels[y * width + x] = sampleBilinear(tempCopy.data(), width, height, srcX, srcY);
                }
            }
        }

        // 2. To mau kinh ap trong (Iris Color Tint) & Vong vien con nguoi (Limbal Ring)
        if (toneIntensity > 0.01f && toneId >= 0 && toneId < 8) {
            const LensColorRGB& col = LENS_PALETTE[toneId];
            float tr = col.r / 255.0f;
            float tg = col.g / 255.0f;
            float tb = col.b / 255.0f;

            for (int y = minY; y <= maxY; ++y) {
                for (int x = minX; x <= maxX; ++x) {
                    float dx = x - cx;
                    float dy = y - cy;
                    float dist = std::hypot(dx, dy);
                    if (dist > r * 1.08f) continue;

                    // Mat na vung mong mat (Iris Mask): giu lai dong tu den o giua va chan long trang
                    float innerMask = smoothstep(r * 0.20f, r * 0.42f, dist);
                    float outerMask = 1.0f - smoothstep(r * 0.88f, r * 1.02f, dist);
                    float irisMask = innerMask * outerMask;

                    int idx = y * width + x;
                    uint32_t c = pixels[idx];
                    float pr = RGBA_R(c) / 255.0f;
                    float pg = RGBA_G(c) / 255.0f;
                    float pb = RGBA_B(c) / 255.0f;

                    float origLum = 0.299f * pr + 0.587f * pg + 0.114f * pb;

                    // 1. Corneal Specular Gloss Shield (Bảo tồn độ bóng ướt giác mạc tự nhiên)
                    float specularShield = std::clamp((origLum - 0.58f) / 0.25f, 0.0f, 1.0f);

                    // 2. Iris Base Lifting: Nâng độ sáng nền cho mắt sẫm màu châu Á
                    float liftedLum = std::max(origLum, 0.15f + 0.35f * toneIntensity);

                    // 3. Vân tia mống mắt 3D sinh học
                    float angle = std::atan2(dy, dx);
                    float fiber = 0.92f + 0.16f * std::abs(std::sin(angle * 14.0f));

                    // Sắc tố lens sống động
                    float lensR = std::min(1.0f, (tr * 0.70f + liftedLum * 0.30f) * fiber);
                    float lensG = std::min(1.0f, (tg * 0.70f + liftedLum * 0.30f) * fiber);
                    float lensB = std::min(1.0f, (tb * 0.70f + liftedLum * 0.30f) * fiber);

                    // Blend Soft-Light kết hợp với sắc tố lens
                    float blendedR = softLightBlend(pr, lensR);
                    float blendedG = softLightBlend(pg, lensG);
                    float blendedB = softLightBlend(pb, lensB);

                    // Pha màu lens vào mống mắt theo cường độ
                    float alpha = irisMask * (toneIntensity * 0.88f);
                    float fr = pr + (blendedR - pr) * alpha;
                    float fg = pg + (blendedG - pg) * alpha;
                    float fb = pb + (blendedB - pb) * alpha;

                    // 3. Vòng viền con ngươi (Limbal Ring): Viền đen quyến rũ ở ranh giới ngoài
                    float limbalMask = smoothstep(r * 0.82f, r * 0.95f, dist) * (1.0f - smoothstep(r * 0.98f, r * 1.05f, dist));
                    float limbalShade = 1.0f - limbalMask * 0.45f * toneIntensity;
                    fr *= limbalShade;
                    fg *= limbalShade;
                    fb *= limbalShade;

                    // 4. Glow con ngươi trong veo
                    if (glowIntensity > 0.01f) {
                        float glowCenter = (1.0f - smoothstep(0.0f, r * 0.85f, dist)) * (glowIntensity * 0.25f);
                        fr = std::min(1.0f, fr + glowCenter);
                        fg = std::min(1.0f, fg + glowCenter);
                        fb = std::min(1.0f, fb + glowCenter);
                    }

                    // 5. Tái bảo tồn độ bóng ướt giác mạc lên trên cùng (Specular Gloss Preservation)
                    fr = fr * (1.0f - specularShield) + pr * specularShield;
                    fg = fg * (1.0f - specularShield) + pg * specularShield;
                    fb = fb * (1.0f - specularShield) + pb * specularShield;

                    pixels[idx] = PACK_RGBA(
                        static_cast<int>(fr * 255.0f + 0.5f),
                        static_cast<int>(fg * 255.0f + 0.5f),
                        static_cast<int>(fb * 255.0f + 0.5f),
                        RGBA_A(c)
                    );
                }
            }
        }

        // 5. Catchlight (Diem sang phan xa dong tu sac net)
        if (catchlightIntensity > 0.01f && catchlightType > 0) {
            float spotX = cx + r * 0.28f;
            float spotY = cy - r * 0.28f;
            float spotR = r * 0.25f;

            int sMinX = std::max(0, static_cast<int>(spotX - spotR * 2.0f));
            int sMaxX = std::min(width - 1, static_cast<int>(spotX + spotR * 2.0f));
            int sMinY = std::max(0, static_cast<int>(spotY - spotR * 2.0f));
            int sMaxY = std::min(height - 1, static_cast<int>(spotY + spotR * 2.0f));

            for (int y = sMinY; y <= sMaxY; ++y) {
                for (int x = sMinX; x <= sMaxX; ++x) {
                    float sx = (x - spotX);
                    float sy = (y - spotY);
                    float sdist = std::hypot(sx, sy);

                    float flare = 0.0f;
                    switch (catchlightType) {
                        case 1: // Studio Ring
                            flare = std::exp(-std::pow(sdist - spotR * 0.65f, 2.0f) / (spotR * 0.18f));
                            break;
                        case 2: // Star 4-Point
                            flare = std::exp(-sdist / (spotR * 0.45f)) +
                                    std::exp(-std::abs(sx) / (spotR * 0.15f)) * std::exp(-std::abs(sy) / (spotR * 1.2f)) +
                                    std::exp(-std::abs(sy) / (spotR * 0.15f)) * std::exp(-std::abs(sx) / (spotR * 1.2f));
                            flare = std::min(1.0f, flare * 0.6f);
                            break;
                        case 3: // Sweetheart
                            {
                                float nx = sx / spotR;
                                float ny = sy / spotR;
                                float hDist = std::sqrt(nx * nx + std::pow(ny - std::sqrt(std::abs(nx)), 2.0f));
                                flare = (hDist < 0.95f) ? (1.0f - hDist) : 0.0f;
                            }
                            break;
                        case 4: // Softbox Square
                            flare = (std::abs(sx) < spotR * 0.65f && std::abs(sy) < spotR * 0.65f) ?
                                    (1.0f - std::max(std::abs(sx), std::abs(sy)) / (spotR * 0.7f)) : 0.0f;
                            break;
                        case 5: // Double Dot
                            flare = std::exp(-(sx * sx + sy * sy) / (spotR * spotR * 0.22f));
                            break;
                        case 6: // Crescent Moon
                            flare = (sdist < spotR * 0.75f && std::hypot(sx - spotR * 0.25f, sy) > spotR * 0.45f) ? 0.85f : 0.0f;
                            break;
                        case 7: // Diamond
                            flare = (std::abs(sx) + std::abs(sy) < spotR * 0.85f) ? (1.0f - (std::abs(sx) + std::abs(sy)) / (spotR * 0.9f)) : 0.0f;
                            break;
                        case 8: // Flower
                        default:
                            {
                                float angle = std::atan2(sy, sx);
                                float petal = std::cos(5.0f * angle);
                                flare = (sdist < spotR * (0.6f + 0.25f * petal)) ? 0.8f : 0.0f;
                            }
                            break;
                    }

                    flare *= catchlightIntensity;
                    if (flare <= 0.005f) continue;

                    int idx = y * width + x;
                    uint32_t c = pixels[idx];
                    int rval = std::min(255, static_cast<int>(RGBA_R(c) + 245.0f * flare));
                    int gval = std::min(255, static_cast<int>(RGBA_G(c) + 248.0f * flare));
                    int bval = std::min(255, static_cast<int>(RGBA_B(c) + 255.0f * flare));
                    pixels[idx] = PACK_RGBA(rval, gval, bval, RGBA_A(c));
                }
            }
        }
    }

    return true;
}

bool FaceRetouchDetail::adjustCanthusDetail(
    uint32_t* pixels, int width, int height,
    const Point3D& leftOuter, const Point3D& leftInner,
    const Point3D& rightInner, const Point3D& rightOuter,
    float innerCanthusOpen, float outerCanthusLift, float eyeSpan
) {
    if (!pixels || width <= 0 || height <= 0) return false;
    if (std::abs(innerCanthusOpen) < 0.001f && std::abs(outerCanthusLift) < 0.001f) return true;

    std::vector<uint32_t> origPixels(pixels, pixels + width * height);

    float leftEyeW = std::hypot(leftInner.x - leftOuter.x, leftInner.y - leftOuter.y);
    float rightEyeW = std::hypot(rightOuter.x - rightInner.x, rightOuter.y - rightInner.y);
    float avgEyeW = (leftEyeW + rightEyeW) * 0.5f;
    if (avgEyeW < 5.0f) avgEyeW = 60.0f;

    struct CanthusWarpNode {
        float x, y;
        float dx, dy;
        float radius;
    };

    std::vector<CanthusWarpNode> nodes;

    // 1. Khoe mat trong trai (Left Inner Canthus: Point 133): Di chuyen ve phia song mui
    if (std::abs(innerCanthusOpen) > 0.001f) {
        float shift = innerCanthusOpen * avgEyeW * 0.22f;
        nodes.push_back({leftInner.x, leftInner.y, shift, shift * 0.08f, avgEyeW * 0.65f});
        // Khoe mat trong phai (Right Inner Canthus: Point 362): Di chuyen ve phia song mui
        nodes.push_back({rightInner.x, rightInner.y, -shift, shift * 0.08f, avgEyeW * 0.65f});
    }

    // 2. Khoe mat ngoai / Duoi mat (Outer Canthus Lift: Point 33 & Point 263): Nang vuot len va mo rong
    if (std::abs(outerCanthusLift) > 0.001f) {
        float liftY = -outerCanthusLift * avgEyeW * 0.22f;
        float spanX = outerCanthusLift * avgEyeW * 0.15f;
        nodes.push_back({leftOuter.x, leftOuter.y, -spanX, liftY, avgEyeW * 0.75f});
        nodes.push_back({rightOuter.x, rightOuter.y, spanX, liftY, avgEyeW * 0.75f});
    }

    #pragma omp parallel for schedule(dynamic, 16)
    for (size_t n = 0; n < nodes.size(); ++n) {
        const auto& node = nodes[n];
        float rad = node.radius;
        float rad2 = rad * rad;

        int minX = std::max(0, static_cast<int>(node.x - rad));
        int maxX = std::min(width - 1, static_cast<int>(node.x + rad));
        int minY = std::max(0, static_cast<int>(node.y - rad));
        int maxY = std::min(height - 1, static_cast<int>(node.y + rad));

        for (int y = minY; y <= maxY; ++y) {
            for (int x = minX; x <= maxX; ++x) {
                float dist2 = (x - node.x) * (x - node.x) + (y - node.y) * (y - node.y);
                if (dist2 >= rad2) continue;

                // Ham trong so C2 lien tuc triet tieu hoan toan gon song (Zero-Ripple Spline Kernel)
                float u = dist2 / rad2;
                float w = (1.0f - u) * (1.0f - u) * (1.0f - u);

                float srcX = x - node.dx * w;
                float srcY = y - node.dy * w;

                pixels[y * width + x] = sampleBilinear(origPixels.data(), width, height, srcX, srcY);
            }
        }
    }

    return true;
}

bool FaceRetouchDetail::applyNasolabialSmoothing(
    uint32_t* pixels, int width, int height,
    const std::vector<Point3D>& leftSmileLine,
    const std::vector<Point3D>& rightSmileLine,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0) return false;
    if (intensity <= 0.001f) return true;

    std::vector<std::vector<Point3D>> lines;
    if (!leftSmileLine.empty()) lines.push_back(leftSmileLine);
    if (!rightSmileLine.empty()) lines.push_back(rightSmileLine);
    if (lines.empty()) return false;

    std::vector<uint32_t> temp(pixels, pixels + width * height);

    for (const auto& rawLine : lines) {
        if (rawLine.size() < 2) continue;

        // Noi suy duong cong ranh cuoi lien tuc (Continuous Spline Trajectory) voi 32 nut mau
        const int numSamples = 32;
        std::vector<Point3D> curve(numSamples);

        for (int i = 0; i < numSamples; ++i) {
            float t = static_cast<float>(i) / (numSamples - 1);
            float seg = t * (rawLine.size() - 1);
            int idx = std::min(static_cast<int>(seg), static_cast<int>(rawLine.size() - 2));
            float frac = seg - idx;

            curve[i].x = rawLine[idx].x * (1.0f - frac) + rawLine[idx + 1].x * frac;
            curve[i].y = rawLine[idx].y * (1.0f - frac) + rawLine[idx + 1].y * frac;
            curve[i].z = 0.0f;
        }

        float lineLen = std::hypot(curve.back().x - curve.front().x, curve.back().y - curve.front().y);
        float bandRadius = std::max(12.0f, lineLen * 0.16f);
        float bandRadius2 = bandRadius * bandRadius;

        // Vung bao bounding box cua ranh cuoi
        float minCurveX = curve[0].x, maxCurveX = curve[0].x;
        float minCurveY = curve[0].y, maxCurveY = curve[0].y;
        for (const auto& pt : curve) {
            minCurveX = std::min(minCurveX, pt.x);
            maxCurveX = std::max(maxCurveX, pt.x);
            minCurveY = std::min(minCurveY, pt.y);
            maxCurveY = std::max(maxCurveY, pt.y);
        }

        int x0 = std::max(0, static_cast<int>(minCurveX - bandRadius));
        int x1 = std::min(width - 1, static_cast<int>(maxCurveX + bandRadius));
        int y0 = std::max(0, static_cast<int>(minCurveY - bandRadius));
        int y1 = std::min(height - 1, static_cast<int>(maxCurveY + bandRadius));

        #pragma omp parallel for schedule(dynamic, 16)
        for (int y = y0; y <= y1; ++y) {
            for (int x = x0; x <= x1; ++x) {
                // Tinh khoang cach toi thieu toi duong cong ranh cuoi
                float minDist2 = 1e9f;
                for (size_t k = 0; k < curve.size(); ++k) {
                    float d2 = (x - curve[k].x) * (x - curve[k].x) + (y - curve[k].y) * (y - curve[k].y);
                    if (d2 < minDist2) minDist2 = d2;
                }

                if (minDist2 >= bandRadius2) continue;

                float dist = std::sqrt(minDist2);
                float normalizedDist = dist / bandRadius;
                // Cosine Bell Falloff: 1.0 o tam ranh cuoi -> 0.0 o ria ma khong de lai vet ran
                float weight = 0.5f * (1.0f + std::cos(normalizedDist * 3.14159265f)) * intensity;

                int pIdx = y * width + x;
                uint32_t c = temp[pIdx];
                int r = RGBA_R(c);
                int g = RGBA_G(c);
                int b = RGBA_B(c);

                // Kiem tra vung da mat: YCbCr
                float Y = 0.299f * r + 0.587f * g + 0.114f * b;
                float Cb = 128.0f - 0.168736f * r - 0.331264f * g + 0.5f * b;
                float Cr = 128.0f + 0.5f * r - 0.418688f * g - 0.081312f * b;
                bool isSkin = (r > 80 && g > 35 && b > 20 && Cr > 133 && Cr < 173 && Cb > 77 && Cb < 127);
                if (!isSkin) continue;

                // Bilateral Shadow Lifting: Lay mau vung da ma ke can de bu tru vet bong ranh cuoi
                float sumY = 0.0f, sumWeight = 0.0f;
                for (int dy = -3; dy <= 3; dy += 2) {
                    for (int dx = -3; dx <= 3; dx += 2) {
                        int nx = std::clamp(x + dx, 0, width - 1);
                        int ny = std::clamp(y + dy, 0, height - 1);
                        uint32_t nc = temp[ny * width + nx];
                        float nY = 0.299f * RGBA_R(nc) + 0.587f * RGBA_G(nc) + 0.114f * RGBA_B(nc);
                        float spatialW = std::exp(-(dx * dx + dy * dy) / 8.0f);
                        sumY += nY * spatialW;
                        sumWeight += spatialW;
                    }
                }

                float localAvgY = sumY / std::max(0.001f, sumWeight);
                // Vung ranh cuoi la vung toi hon (Y < localAvgY), bu tru sang triet tieu ranh nhung giu lo chan long
                float deltaY = std::max(0.0f, localAvgY - Y) * 1.35f + 14.0f * weight;
                float lift = deltaY * weight;

                int nr = std::clamp(static_cast<int>(r + lift * 1.02f), 0, 255);
                int ng = std::clamp(static_cast<int>(g + lift * 0.98f), 0, 255);
                int nb = std::clamp(static_cast<int>(b + lift * 0.92f), 0, 255);

                pixels[pIdx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
            }
        }
    }

    return true;
}

} // namespace MeituReborn

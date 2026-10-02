#include "camera_shutter_pipeline.h"
#include "teeth_ear_engine.h"
#include "liquify_warp.h"
#include "color_lut.h"
#include <cmath>
#include <algorithm>
#include <vector>

#ifdef _OPENMP
#include <omp.h>
#endif

namespace meitu::camera {

static inline uint8_t clamp8(float v) {
    return static_cast<uint8_t>(std::clamp(v, 0.0f, 255.0f));
}

// 1. Phân loại sắc thái biểu bì da người (Medical/Vision YCbCr Standard Skin Cluster)
// Tách biệt biểu bì da với bối cảnh phòng, quần áo, gọng kính và bóng tối
static inline bool isHumanSkinEpidermis(uint8_t r, uint8_t g, uint8_t b) {
    if (r <= g || g <= b) return false;
    if (r < 60 || g < 35 || b < 15) return false;
    if ((r - g) < 10) return false;

    // YCbCr Conversion
    float Y  =  0.299f * r + 0.587f * g + 0.114f * b;
    float Cb = -0.168736f * r - 0.331264f * g + 0.5f * b + 128.0f;
    float Cr =  0.5f * r - 0.418688f * g - 0.081312f * b + 128.0f;

    // Dải sắc tố biểu bì da
    if (Cb < 77.0f || Cb > 128.0f) return false;
    if (Cr < 133.0f || Cr > 175.0f) return false;
    if (Y < 35.0f || Y > 240.0f) return false;

    return true;
}

// 2. Tính toán năng lượng biên độ tần số cao (Gradient Energy) để bảo vệ:
//    - Sợi tóc (Hair)
//    - Sợi lông mi (Eyelashes)
//    - Sợi lông mày (Eyebrows)
//    - Râu (Beard / Mustache)
//    - Kính mắt & gọng kính (Eyeglasses frames & rims)
static inline float computeLocalEdgeEnergy(const uint32_t* img, int w, int h, int x, int y) {
    int x0 = std::max(0, x - 1);
    int x1 = std::min(w - 1, x + 1);
    int y0 = std::max(0, y - 1);
    int y1 = std::min(h - 1, y + 1);

    uint32_t cL = img[y * w + x0];
    uint32_t cR = img[y * w + x1];
    uint32_t cT = img[y0 * w + x];
    uint32_t cB = img[y1 * w + x];

    float lumL = 0.299f * (cL & 0xFF) + 0.587f * ((cL >> 8) & 0xFF) + 0.114f * ((cL >> 16) & 0xFF);
    float lumR = 0.299f * (cR & 0xFF) + 0.587f * ((cR >> 8) & 0xFF) + 0.114f * ((cR >> 16) & 0xFF);
    float lumT = 0.299f * (cT & 0xFF) + 0.587f * ((cT >> 8) & 0xFF) + 0.114f * ((cT >> 16) & 0xFF);
    float lumB = 0.299f * (cB & 0xFF) + 0.587f * ((cB >> 8) & 0xFF) + 0.114f * ((cB >> 16) & 0xFF);

    return std::abs(lumR - lumL) + std::abs(lumB - lumT);
}

// 3. Kiểm tra phản xạ tròng kính và đốm lóa gương (Specular Reflection / Glare)
static inline bool isGlassesSpecularGlare(uint8_t r, uint8_t g, uint8_t b) {
    if (r > 225 && g > 225 && b > 225) {
        if (std::abs(r - g) < 14 && std::abs(g - b) < 14) return true;
    }
    return false;
}

// 4. Kiểm tra vùng loại trừ giải phẫu từ 106 điểm Landmark:
//    - Tròng mắt & lông mi (Eyes & Lashes)
//    - Lông mày (Eyebrows)
//    - Môi & Rãnh môi (Lips)
static inline bool isAnatomicalExclusion(
    int x, int y,
    const float* landmarks106,
    int width, int height)
{
    if (!landmarks106) {
        float eyeY = height * 0.395f;
        float leftEyeX = width * 0.335f;
        float rightEyeX = width * 0.665f;
        float rEye = width * 0.08f;
        float dxL = x - leftEyeX, dyL = y - eyeY;
        if (dxL * dxL + dyL * dyL < rEye * rEye) return true;
        float dxR = x - rightEyeX, dyR = y - eyeY;
        if (dxR * dxR + dyR * dyR < rEye * rEye) return true;

        float mouthY = height * 0.645f;
        float mouthX = width * 0.5f;
        float rMouthX = width * 0.12f, rMouthY = height * 0.05f;
        float dmx = (x - mouthX) / rMouthX, dmy = (y - mouthY) / rMouthY;
        if (dmx * dmx + dmy * dmy < 1.0f) return true;

        return false;
    }

    // Trích xuất các vị trí giải phẫu chính xác từ 106 Landmark
    float lxEye = landmarks106[38 * 2];
    float lyEye = landmarks106[38 * 2 + 1];
    float rxEye = landmarks106[57 * 2];
    float ryEye = landmarks106[57 * 2 + 1];
    float eyeDist = std::hypot(rxEye - lxEye, ryEye - lyEye);
    if (eyeDist < 10.0f) eyeDist = width * 0.3f;

    float eyeRadius = eyeDist * 0.28f;
    float eyeRadSq = eyeRadius * eyeRadius;

    // Vùng mắt trái & lông mi trái
    float dlx = x - lxEye, dly = y - lyEye;
    if (dlx * dlx + dly * dly < eyeRadSq) return true;

    // Vùng mắt phải & lông mi phải
    float drx = x - rxEye, dry = y - ryEye;
    if (drx * drx + dry * dry < eyeRadSq) return true;

    // Vùng lông mày trái (điểm 64..67)
    float lbX = (landmarks106[64 * 2] + landmarks106[67 * 2]) * 0.5f;
    float lbY = (landmarks106[64 * 2 + 1] + landmarks106[67 * 2 + 1]) * 0.5f;
    float browRad = eyeDist * 0.22f;
    float dbxL = (x - lbX), dbyL = (y - lbY) * 1.5f;
    if (dbxL * dbxL + dbyL * dbyL < browRad * browRad) return true;

    // Vùng lông mày phải (điểm 68..71)
    float rbX = (landmarks106[68 * 2] + landmarks106[71 * 2]) * 0.5f;
    float rbY = (landmarks106[68 * 2 + 1] + landmarks106[71 * 2 + 1]) * 0.5f;
    float dbxR = (x - rbX), dbyR = (y - rbY) * 1.5f;
    if (dbxR * dbxR + dbyR * dbyR < browRad * browRad) return true;

    // Vùng môi (điểm 72..95)
    float mouthCenterX = landmarks106[46 * 2];
    float mouthCenterY = (landmarks106[72 * 2 + 1] + landmarks106[76 * 2 + 1]) * 0.5f;
    float mRadX = eyeDist * 0.40f;
    float mRadY = eyeDist * 0.18f;
    float dmx = (x - mouthCenterX) / mRadX;
    float dmy = (y - mouthCenterY) / mRadY;
    if (dmx * dmx + dmy * dmy < 1.0f) return true;

    return false;
}

/**
 * Sub-pixel Bilinear Interpolation RGBA Sampler
 */
static inline uint32_t sampleBilinearRGBA(const uint32_t* src, int w, int h, float fx, float fy) {
    fx = std::clamp(fx, 0.0f, static_cast<float>(w - 1));
    fy = std::clamp(fy, 0.0f, static_cast<float>(h - 1));

    int x0 = static_cast<int>(fx);
    int y0 = static_cast<int>(fy);
    int x1 = std::min(x0 + 1, w - 1);
    int y1 = std::min(y0 + 1, h - 1);

    float dx = fx - static_cast<float>(x0);
    float dy = fy - static_cast<float>(y0);

    float w00 = (1.0f - dx) * (1.0f - dy);
    float w10 = dx * (1.0f - dy);
    float w01 = (1.0f - dx) * dy;
    float w11 = dx * dy;

    uint32_t c00 = src[y0 * w + x0];
    uint32_t c10 = src[y0 * w + x1];
    uint32_t c01 = src[y1 * w + x0];
    uint32_t c11 = src[y1 * w + x1];

    uint32_t r = static_cast<uint32_t>(
        (c00 & 0xFF) * w00 + (c10 & 0xFF) * w10 +
        (c01 & 0xFF) * w01 + (c11 & 0xFF) * w11);
    uint32_t g = static_cast<uint32_t>(
        ((c00 >> 8) & 0xFF) * w00 + ((c10 >> 8) & 0xFF) * w10 +
        ((c01 >> 8) & 0xFF) * w01 + ((c11 >> 8) & 0xFF) * w11);
    uint32_t b = static_cast<uint32_t>(
        ((c00 >> 16) & 0xFF) * w00 + ((c10 >> 16) & 0xFF) * w10 +
        ((c01 >> 16) & 0xFF) * w01 + ((c11 >> 16) & 0xFF) * w11);
    uint32_t a = (c00 >> 24) & 0xFF;

    return (a << 24) | (std::min(b, 255u) << 16) | (std::min(g, 255u) << 8) | std::min(r, 255u);
}

bool CameraShutterPipeline::applyAutoWhiteBalance(uint32_t* pixels, int width, int height, WhiteBalanceMode mode) {
    if (!pixels || width <= 0 || height <= 0 || mode == WhiteBalanceMode::OFF) {
        return false;
    }

    const int totalPixels = width * height;

    if (mode == WhiteBalanceMode::AUTO_GRAY_WORLD) {
        double sumR = 0.0, sumG = 0.0, sumB = 0.0;

        #pragma omp parallel for reduction(+:sumR,sumG,sumB) schedule(static)
        for (int i = 0; i < totalPixels; ++i) {
            uint32_t c = pixels[i];
            sumR += (c & 0xFF);
            sumG += ((c >> 8) & 0xFF);
            sumB += ((c >> 16) & 0xFF);
        }

        double avgR = sumR / totalPixels;
        double avgG = sumG / totalPixels;
        double avgB = sumB / totalPixels;
        double avgGray = (avgR + avgG + avgB) / 3.0;

        if (avgR < 1.0) avgR = 1.0;
        if (avgG < 1.0) avgG = 1.0;
        if (avgB < 1.0) avgB = 1.0;

        float scaleR = static_cast<float>(avgGray / avgR);
        float scaleG = static_cast<float>(avgGray / avgG);
        float scaleB = static_cast<float>(avgGray / avgB);

        scaleR = std::clamp(scaleR, 0.75f, 1.35f);
        scaleG = std::clamp(scaleG, 0.85f, 1.15f);
        scaleB = std::clamp(scaleB, 0.75f, 1.35f);

        #pragma omp parallel for schedule(static)
        for (int i = 0; i < totalPixels; ++i) {
            uint32_t c = pixels[i];
            uint8_t a = (c >> 24) & 0xFF;
            float b = static_cast<float>((c >> 16) & 0xFF) * scaleB;
            float g = static_cast<float>((c >> 8) & 0xFF) * scaleG;
            float r = static_cast<float>(c & 0xFF) * scaleR;

            pixels[i] = (static_cast<uint32_t>(a) << 24) |
                        (static_cast<uint32_t>(clamp8(b)) << 16) |
                        (static_cast<uint32_t>(clamp8(g)) << 8) |
                        static_cast<uint32_t>(clamp8(r));
        }
        return true;
    }
    return false;
}

bool CameraShutterPipeline::applyBilateralSkinSmooth(
    uint32_t* pixels, int width, int height,
    float spatialSigma, float rangeSigma, float intensity,
    const float* landmarks106, int landmarkCount)
{
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) {
        return false;
    }

    intensity = std::clamp(intensity, 0.0f, 1.0f);
    const int radius = std::clamp(static_cast<int>(spatialSigma * 1.2f), 1, 4);
    const float twoSpatialSq = 2.0f * spatialSigma * spatialSigma;
    const float twoRangeSq = 2.0f * rangeSigma * rangeSigma;

    std::vector<uint32_t> temp(pixels, pixels + (width * height));

    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            uint32_t centerPixel = temp[y * width + x];
            uint8_t r = centerPixel & 0xFF;
            uint8_t g = (centerPixel >> 8) & 0xFF;
            uint8_t b = (centerPixel >> 16) & 0xFF;
            uint32_t cA = (centerPixel >> 24) & 0xFF;

            // 1. Chỉ làm mịn biểu bì da (loại trừ bối cảnh phòng, áo, tường, sàn)
            if (!isHumanSkinEpidermis(r, g, b)) {
                continue;
            }

            // 2. Bảo vệ kính mắt và phản quang tròng kính
            if (isGlassesSpecularGlare(r, g, b)) {
                continue;
            }

            // 3. Bảo vệ mắt, lông mi, lông mày, môi
            if (isAnatomicalExclusion(x, y, landmarks106, width, height)) {
                continue;
            }

            // 4. Bảo vệ sợi tóc, sợi lông mi, lông mày, râu và gọng kính bằng Gradient Energy
            float edge = computeLocalEdgeEnergy(temp.data(), width, height, x, y);
            if (edge > 32.0f) {
                // Tần số không gian cao (sợi mi, sợi râu, gọng kính, sợi tóc): BẢO TOÀN NGUYÊN VẸN 100%
                continue;
            }
            float edgeWeight = (edge < 14.0f) ? 1.0f : std::clamp(1.0f - (edge - 14.0f) / 18.0f, 0.0f, 1.0f);
            if (edgeWeight <= 0.001f) {
                continue;
            }

            float cR = static_cast<float>(r);
            float cG = static_cast<float>(g);
            float cB = static_cast<float>(b);

            float wSum = 0.0f;
            float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f;
            int step = (radius > 3) ? 2 : 1;

            for (int dy = -radius; dy <= radius; dy += step) {
                int ny = std::clamp(y + dy, 0, height - 1);
                for (int dx = -radius; dx <= radius; dx += step) {
                    int nx = std::clamp(x + dx, 0, width - 1);

                    uint32_t neighbor = temp[ny * width + nx];
                    float nR = static_cast<float>(neighbor & 0xFF);
                    float nG = static_cast<float>((neighbor >> 8) & 0xFF);
                    float nB = static_cast<float>((neighbor >> 16) & 0xFF);

                    float spatialDistSq = static_cast<float>(dx * dx + dy * dy);
                    float dR = cR - nR, dG = cG - nG, dB = cB - nB;
                    float rangeDistSq = (dR * dR + dG * dG + dB * dB) / 3.0f;

                    float w = std::exp(-(spatialDistSq / twoSpatialSq) - (rangeDistSq / twoRangeSq));
                    wSum += w;
                    sumR += nR * w;
                    sumG += nG * w;
                    sumB += nB * w;
                }
            }

            if (wSum > 0.0001f) {
                float smoothedR = sumR / wSum;
                float smoothedG = sumG / wSum;
                float smoothedB = sumB / wSum;

                float effIntensity = intensity * edgeWeight;
                float finalR = cR * (1.0f - effIntensity) + smoothedR * effIntensity;
                float finalG = cG * (1.0f - effIntensity) + smoothedG * effIntensity;
                float finalB = cB * (1.0f - effIntensity) + smoothedB * effIntensity;

                pixels[y * width + x] = (cA << 24) |
                                        (static_cast<uint32_t>(clamp8(finalB)) << 16) |
                                        (static_cast<uint32_t>(clamp8(finalG)) << 8) |
                                        static_cast<uint32_t>(clamp8(finalR));
            }
        }
    }
    return true;
}

bool CameraShutterPipeline::processShutterCapture(
    uint32_t* pixels, int width, int height,
    const ShutterBeautyConfig& config,
    const float* landmarks106, int landmarkCount)
{
    if (!pixels || width <= 0 || height <= 0) return false;

    applyAutoWhiteBalance(pixels, width, height, config.awbMode);

    if (config.skinSmoothIntensity > 0.01f) {
        applyBilateralSkinSmooth(pixels, width, height, 3.0f, 28.0f, config.skinSmoothIntensity, landmarks106, landmarkCount);
    }

    // Nâng sáng da có chọn lọc - CHỈ tác động vùng biểu bì da thật (Delta nền, tóc, kính = 0.00)
    if (config.skinWhitening > 0.01f) {
        float whiteFactor = config.skinWhitening * 28.0f;
        const int total = width * height;
        #pragma omp parallel for schedule(dynamic, 64)
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int idx = y * width + x;
                uint32_t c = pixels[idx];
                uint8_t r = c & 0xFF;
                uint8_t g = (c >> 8) & 0xFF;
                uint8_t b = (c >> 16) & 0xFF;
                uint8_t a = (c >> 24) & 0xFF;

                if (!isHumanSkinEpidermis(r, g, b)) continue;
                if (isGlassesSpecularGlare(r, g, b)) continue;
                if (isAnatomicalExclusion(x, y, landmarks106, width, height)) continue;

                float edge = computeLocalEdgeEnergy(pixels, width, height, x, y);
                if (edge > 32.0f) continue;
                float edgeWeight = (edge < 14.0f) ? 1.0f : std::clamp(1.0f - (edge - 14.0f) / 18.0f, 0.0f, 1.0f);

                float boost = whiteFactor * edgeWeight;
                int newR = std::clamp((int)(r + boost), 0, 255);
                int newG = std::clamp((int)(g + boost * 0.85f), 0, 255);
                int newB = std::clamp((int)(b + boost * 0.70f), 0, 255);

                pixels[idx] = (static_cast<uint32_t>(a) << 24) |
                            (static_cast<uint32_t>(newB) << 16) |
                            (static_cast<uint32_t>(newG) << 8) |
                            static_cast<uint32_t>(newR);
            }
        }
    }

    float mouthX = landmarks106 ? landmarks106[46 * 2] : (width * 0.5f);
    float mouthY = landmarks106 ? ((landmarks106[72 * 2 + 1] + landmarks106[76 * 2 + 1]) * 0.5f) : (height * 0.65f);
    float radiusX = width * 0.12f;
    float radiusY = height * 0.05f;

    if (config.teethWhitening > 0.01f) {
        meitu_native::TeethEarEngine::applyTeethWhitening(
            pixels, width, height, mouthX, mouthY, radiusX, radiusY,
            config.teethShade, config.teethWhitening);
    }

    float leftEarX = width * 0.2f;
    float leftEarY = height * 0.45f;
    float rightEarX = width * 0.8f;
    float rightEarY = height * 0.45f;
    float earRadius = width * 0.10f;

    if (config.earReshape > 0.01f) {
        meitu_native::TeethEarEngine::applyEarReshape(
            pixels, width, height, leftEarX, leftEarY, rightEarX, rightEarY,
            earRadius, 0, config.earReshape);
    }

    if (config.earTone > 0.01f) {
        meitu_native::TeethEarEngine::applyEarColorTuning(
            pixels, width, height, leftEarX, leftEarY, rightEarX, rightEarY,
            earRadius, config.earTone);
    }

    return true;
}

/**
 * Live Preview Multi-Feature Engine (0-100% rõ rệt, không chẻ đôi, không gợn sóng)
 * True 0% Passthrough: Khi mọi thông số = 0, giữ 100% nguyên vẹn từng pixel gốc của Camera.
 */
bool CameraShutterPipeline::processLivePreviewBeauty(
    uint32_t* pixels, int width, int height,
    int lutType, float lutIntensity,
    float skinSmooth, float skinWhiten,
    float faceVLine, float bigEyes,
    float noseShrink, float lipPlump,
    float teethWhiten, float eyeBags, float skinClear,
    const float* landmarks106, int landmarkCount)
{
    if (!pixels || width <= 0 || height <= 0) return false;

    // TRUE 0% BASELINE: If all parameters are 0, return immediately with zero alterations
    if (skinSmooth <= 0.001f && skinWhiten <= 0.001f && faceVLine <= 0.001f &&
        bigEyes <= 0.001f && noseShrink <= 0.001f && lipPlump <= 0.001f &&
        teethWhiten <= 0.001f && eyeBags <= 0.001f && skinClear <= 0.001f &&
        (lutType <= 0 || lutIntensity <= 0.001f))
    {
        return true; // 100% Pure Optical Camera Raw Passthrough
    }

    // 1. Bilateral Skin Smoothing (Bảo vệ tóc, lông mi, lông mày, râu, kính mắt)
    if (skinSmooth > 0.001f) {
        float s = std::clamp(skinSmooth, 0.0f, 1.0f);
        float spatialSigma = 2.0f + s * 3.0f;
        float rangeSigma = 20.0f + s * 28.0f;
        applyBilateralSkinSmooth(pixels, width, height, spatialSigma, rangeSigma, s, landmarks106, landmarkCount);
    }

    // 2. Radiant Skin Whitening (Nâng tông da dịu mắt, CHỈ tác động vùng biểu bì da thật)
    // Tóc, lông mi, lông mày, râu, kính mắt và bối cảnh phòng giữ nguyên 100% Delta = 0.00
    if (skinWhiten > 0.001f) {
        float wVal = std::clamp(skinWhiten, 0.0f, 1.0f);
        float boostR = wVal * 32.0f;
        float boostG = wVal * 26.0f;
        float boostB = wVal * 20.0f;

        #pragma omp parallel for schedule(dynamic, 64)
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int idx = y * width + x;
                uint32_t c = pixels[idx];
                uint8_t r = c & 0xFF;
                uint8_t g = (c >> 8) & 0xFF;
                uint8_t b = (c >> 16) & 0xFF;
                uint8_t a = (c >> 24) & 0xFF;

                // 1. Kiểm tra màu da biểu bì (YCbCr + RGB)
                if (!isHumanSkinEpidermis(r, g, b)) continue;

                // 2. Kiểm tra phản xạ kính
                if (isGlassesSpecularGlare(r, g, b)) continue;

                // 3. Kiểm tra vùng giải phẫu (Mắt, Lông mi, Lông mày, Môi)
                if (isAnatomicalExclusion(x, y, landmarks106, width, height)) continue;

                // 4. Kiểm tra biên độ tần số cao (Bảo vệ tóc, lông mi, lông mày, râu, gọng kính)
                float edge = computeLocalEdgeEnergy(pixels, width, height, x, y);
                if (edge > 32.0f) continue;
                float edgeWeight = (edge < 14.0f) ? 1.0f : std::clamp(1.0f - (edge - 14.0f) / 18.0f, 0.0f, 1.0f);
                if (edgeWeight <= 0.001f) continue;

                // Nâng sáng có trọng số biểu bì
                float effBoostR = boostR * edgeWeight;
                float effBoostG = boostG * edgeWeight;
                float effBoostB = boostB * edgeWeight;

                int newR = std::clamp((int)(r + effBoostR), 0, 255);
                int newG = std::clamp((int)(g + effBoostG), 0, 255);
                int newB = std::clamp((int)(b + effBoostB), 0, 255);

                pixels[idx] = (a << 24) | (newB << 16) | (newG << 8) | newR;
            }
        }
    }

    // 3. Face V-Line Slimming (C-infinity Gaussian continuous, Sub-pixel Bilinear, ZERO split seam)
    if (faceVLine > 0.001f) {
        float vVal = std::clamp(faceVLine, 0.0f, 1.0f);
        float maxShift = vVal * static_cast<float>(width) * 0.075f;
        float cx = landmarks106 ? landmarks106[46 * 2] : (static_cast<float>(width) * 0.5f);
        float jawYStart = landmarks106 ? landmarks106[4 * 2 + 1] : (static_cast<float>(height) * 0.40f);
        float jawYEnd = landmarks106 ? landmarks106[16 * 2 + 1] : (static_cast<float>(height) * 0.84f);
        if (jawYEnd <= jawYStart) jawYEnd = jawYStart + height * 0.35f;
        float jawHeight = jawYEnd - jawYStart;

        std::vector<uint32_t> temp(pixels, pixels + (width * height));

        #pragma omp parallel for schedule(dynamic, 16)
        for (int y = static_cast<int>(jawYStart); y < static_cast<int>(jawYEnd); ++y) {
            float yNorm = (static_cast<float>(y) - jawYStart) / jawHeight;
            float yFactor = std::sin(yNorm * 3.14159265f);

            for (int x = 0; x < width; ++x) {
                float u = (static_cast<float>(x) - cx) / (static_cast<float>(width) * 0.5f);
                float xFactor = u * std::exp(-2.2f * u * u);
                float shift = maxShift * xFactor * yFactor;
                float srcX = static_cast<float>(x) + shift;

                pixels[y * width + x] = sampleBilinearRGBA(temp.data(), width, height, srcX, static_cast<float>(y));
            }
        }
    }

    // 4. Eye Enlarge (Bám theo tọa độ thật từ Landmark 106)
    if (bigEyes > 0.001f) {
        float eVal = std::clamp(bigEyes, 0.0f, 1.0f);
        float maxScale = 1.0f + eVal * 0.38f;

        float leftEyeX = landmarks106 ? landmarks106[38 * 2] : (static_cast<float>(width) * 0.335f);
        float leftEyeY = landmarks106 ? landmarks106[38 * 2 + 1] : (static_cast<float>(height) * 0.395f);
        float rightEyeX = landmarks106 ? landmarks106[57 * 2] : (static_cast<float>(width) * 0.665f);
        float rightEyeY = landmarks106 ? landmarks106[57 * 2 + 1] : (static_cast<float>(height) * 0.395f);

        float eyeRadius = static_cast<float>(width) * 0.135f;
        float eyeRadSq = eyeRadius * eyeRadius;

        std::vector<uint32_t> temp(pixels, pixels + (width * height));

        auto applyEyeWarp = [&](float eyeCenterX, float eyeCenterY) {
            int yMin = std::max(0, static_cast<int>(eyeCenterY - eyeRadius));
            int yMax = std::min(height - 1, static_cast<int>(eyeCenterY + eyeRadius));
            int xMin = std::max(0, static_cast<int>(eyeCenterX - eyeRadius));
            int xMax = std::min(width - 1, static_cast<int>(eyeCenterX + eyeRadius));

            for (int y = yMin; y <= yMax; ++y) {
                float dy = static_cast<float>(y) - eyeCenterY;
                for (int x = xMin; x <= xMax; ++x) {
                    float dx = static_cast<float>(x) - eyeCenterX;
                    float dSq = dx * dx + dy * dy;
                    if (dSq < eyeRadSq) {
                        float dist = std::sqrt(dSq);
                        float factor = (eyeRadius - dist) / eyeRadius;
                        float scale = 1.0f + (maxScale - 1.0f) * factor * factor;
                        float srcX = eyeCenterX + dx / scale;
                        float srcY = eyeCenterY + dy / scale;
                        pixels[y * width + x] = sampleBilinearRGBA(temp.data(), width, height, srcX, srcY);
                    }
                }
            }
        };

        applyEyeWarp(leftEyeX, leftEyeY);
        applyEyeWarp(rightEyeX, rightEyeY);
    }

    // 5. Nose Narrowing (Bám theo chóp mũi Landmark 46)
    if (noseShrink > 0.001f) {
        float nVal = std::clamp(noseShrink, 0.0f, 1.0f);
        float noseCenterX = landmarks106 ? landmarks106[46 * 2] : (static_cast<float>(width) * 0.5f);
        float noseCenterY = landmarks106 ? landmarks106[46 * 2 + 1] : (static_cast<float>(height) * 0.505f);
        float noseRadiusX = static_cast<float>(width) * 0.12f;
        float noseRadiusY = static_cast<float>(height) * 0.09f;
        float maxPinch = nVal * static_cast<float>(width) * 0.045f;

        std::vector<uint32_t> temp(pixels, pixels + (width * height));

        int yMin = std::max(0, static_cast<int>(noseCenterY - noseRadiusY));
        int yMax = std::min(height - 1, static_cast<int>(noseCenterY + noseRadiusY));
        int xMin = std::max(0, static_cast<int>(noseCenterX - noseRadiusX));
        int xMax = std::min(width - 1, static_cast<int>(noseCenterX + noseRadiusX));

        for (int y = yMin; y <= yMax; ++y) {
            float ny = (static_cast<float>(y) - noseCenterY) / noseRadiusY;
            float yDistSq = ny * ny;
            if (yDistSq >= 1.0f) continue;

            for (int x = xMin; x <= xMax; ++x) {
                float nx = (static_cast<float>(x) - noseCenterX) / noseRadiusX;
                float rSq = nx * nx + yDistSq;
                if (rSq < 1.0f) {
                    float falloff = (1.0f - rSq) * (1.0f - rSq);
                    float dispX = nx * falloff * maxPinch;
                    float srcX = static_cast<float>(x) + dispX;
                    uint32_t c = sampleBilinearRGBA(temp.data(), width, height, srcX, static_cast<float>(y));

                    float hl = std::exp(-6.0f * nx * nx) * (1.0f - yDistSq) * nVal * 12.0f;
                    if (hl > 0.5f) {
                        int r = c & 0xFF;
                        int g = (c >> 8) & 0xFF;
                        int b = (c >> 16) & 0xFF;
                        uint32_t a = (c >> 24) & 0xFF;
                        r = std::clamp((int)(r + hl), 0, 255);
                        g = std::clamp((int)(g + hl), 0, 255);
                        b = std::clamp((int)(b + hl), 0, 255);
                        c = (a << 24) | (b << 16) | (g << 8) | r;
                    }
                    pixels[y * width + x] = c;
                }
            }
        }
    }

    // 6. Lip Plumping & Rosy Tint (Bám theo tâm môi từ Landmark 72..95)
    if (lipPlump > 0.001f) {
        float lVal = std::clamp(lipPlump, 0.0f, 1.0f);
        float lipCenterX = landmarks106 ? landmarks106[46 * 2] : (static_cast<float>(width) * 0.5f);
        float lipCenterY = landmarks106 ? ((landmarks106[72 * 2 + 1] + landmarks106[76 * 2 + 1]) * 0.5f) : (static_cast<float>(height) * 0.635f);
        float lipRadiusX = static_cast<float>(width) * 0.14f;
        float lipRadiusY = static_cast<float>(height) * 0.075f;

        int yMin = std::max(0, static_cast<int>(lipCenterY - lipRadiusY));
        int yMax = std::min(height - 1, static_cast<int>(lipCenterY + lipRadiusY));
        int xMin = std::max(0, static_cast<int>(lipCenterX - lipRadiusX));
        int xMax = std::min(width - 1, static_cast<int>(lipCenterX + lipRadiusX));

        for (int y = yMin; y <= yMax; ++y) {
            float dy = (static_cast<float>(y) - lipCenterY) / lipRadiusY;
            for (int x = xMin; x <= xMax; ++x) {
                float dx = (static_cast<float>(x) - lipCenterX) / lipRadiusX;
                float d = dx * dx + dy * dy;
                if (d < 1.0f) {
                    float w = (1.0f - d) * lVal;
                    uint32_t c = pixels[y * width + x];
                    int r = c & 0xFF;
                    int g = (c >> 8) & 0xFF;
                    int b = (c >> 16) & 0xFF;
                    uint32_t a = (c >> 24) & 0xFF;

                    r = std::clamp((int)(r + 65.0f * w), 0, 255);
                    g = std::clamp((int)(g + 16.0f * w), 0, 255);
                    b = std::clamp((int)(b + 28.0f * w), 0, 255);

                    pixels[y * width + x] = (a << 24) | (b << 16) | (g << 8) | r;
                }
            }
        }
    }

    // 7. Teeth Whitening (Trắng răng tự nhiên)
    if (teethWhiten > 0.001f) {
        float tVal = std::clamp(teethWhiten, 0.0f, 1.0f);
        float mouthCenterX = landmarks106 ? landmarks106[46 * 2] : (static_cast<float>(width) * 0.5f);
        float mouthCenterY = landmarks106 ? ((landmarks106[72 * 2 + 1] + landmarks106[76 * 2 + 1]) * 0.5f + 4.0f) : (static_cast<float>(height) * 0.655f);
        float mouthRx = static_cast<float>(width) * 0.12f;
        float mouthRy = static_cast<float>(height) * 0.045f;

        int yMin = std::max(0, static_cast<int>(mouthCenterY - mouthRy));
        int yMax = std::min(height - 1, static_cast<int>(mouthCenterY + mouthRy));
        int xMin = std::max(0, static_cast<int>(mouthCenterX - mouthRx));
        int xMax = std::min(width - 1, static_cast<int>(mouthCenterX + mouthRx));

        for (int y = yMin; y <= yMax; ++y) {
            float dy = (static_cast<float>(y) - mouthCenterY) / mouthRy;
            for (int x = xMin; x <= xMax; ++x) {
                float dx = (static_cast<float>(x) - mouthCenterX) / mouthRx;
                float d = dx * dx + dy * dy;
                if (d < 1.0f) {
                    float w = (1.0f - d) * tVal;
                    uint32_t c = pixels[y * width + x];
                    int r = c & 0xFF;
                    int g = (c >> 8) & 0xFF;
                    int b = (c >> 16) & 0xFF;
                    uint32_t a = (c >> 24) & 0xFF;

                    if (r > 60 && g > 50 && b > 35) {
                        float maxC = static_cast<float>(std::max(r, g));
                        b = std::clamp((int)(b + (maxC - b) * 0.75f * w), 0, 255);
                        r = std::clamp((int)(r + 25.0f * w), 0, 255);
                        g = std::clamp((int)(g + 25.0f * w), 0, 255);
                        pixels[y * width + x] = (a << 24) | (b << 16) | (g << 8) | r;
                    }
                }
            }
        }
    }

    // 8. Eye Bags Removal (Làm mờ quầng thâm bám theo vị trí dưới mắt)
    if (eyeBags > 0.001f) {
        float bVal = std::clamp(eyeBags, 0.0f, 1.0f);
        float leftEyeX = landmarks106 ? landmarks106[38 * 2] : (static_cast<float>(width) * 0.335f);
        float leftEyeY = landmarks106 ? (landmarks106[38 * 2 + 1] + 20.0f) : (static_cast<float>(height) * 0.44f);
        float rightEyeX = landmarks106 ? landmarks106[57 * 2] : (static_cast<float>(width) * 0.665f);
        float rightEyeY = landmarks106 ? (landmarks106[57 * 2 + 1] + 20.0f) : (static_cast<float>(height) * 0.44f);

        float bagRadiusX = static_cast<float>(width) * 0.10f;
        float bagRadiusY = static_cast<float>(height) * 0.035f;

        auto softenBags = [&](float bagCenterX, float bagCenterY) {
            int yMin = std::max(0, static_cast<int>(bagCenterY - bagRadiusY));
            int yMax = std::min(height - 1, static_cast<int>(bagCenterY + bagRadiusY));
            int xMin = std::max(0, static_cast<int>(bagCenterX - bagRadiusX));
            int xMax = std::min(width - 1, static_cast<int>(bagCenterX + bagRadiusX));

            for (int y = yMin; y <= yMax; ++y) {
                float dy = (static_cast<float>(y) - bagCenterY) / bagRadiusY;
                for (int x = xMin; x <= xMax; ++x) {
                    float dx = (static_cast<float>(x) - bagCenterX) / bagRadiusX;
                    float d = dx * dx + dy * dy;
                    if (d < 1.0f) {
                        float w = (1.0f - d) * bVal;
                        uint32_t c = pixels[y * width + x];
                        int r = std::clamp((int)((c & 0xFF) + 24.0f * w), 0, 255);
                        int g = std::clamp((int)(((c >> 8) & 0xFF) + 22.0f * w), 0, 255);
                        int b = std::clamp((int)(((c >> 16) & 0xFF) + 26.0f * w), 0, 255);
                        uint32_t a = (c >> 24) & 0xFF;
                        pixels[y * width + x] = (a << 24) | (b << 16) | (g << 8) | r;
                    }
                }
            }
        };

        softenBags(leftEyeX, leftEyeY);
        softenBags(rightEyeX, rightEyeY);
    }

    // 9. Skin Clarity & Edge Definition
    if (skinClear > 0.001f) {
        float cVal = std::clamp(skinClear, 0.0f, 1.0f);
        meitu_native::ColorTuningParams p;
        p.contrast = cVal * 16.0f;
        p.brightness = cVal * 6.0f;
        p.saturation = cVal * 8.0f;
        meitu_native::ColorLutEngine::applyColorTuning(pixels, width, height, p);
    }

    // 10. Cinematic 3D LUT Color Tuning
    if (lutType > 0 && lutIntensity > 0.001f) {
        float lInt = std::clamp(lutIntensity, 0.0f, 1.0f);
        meitu_native::ColorTuningParams params;
        params.brightness = (lutType == 4) ? lInt * 24.0f : lInt * 20.0f;
        params.contrast = (lutType == 4) ? lInt * 26.0f : lInt * 20.0f;
        params.saturation = (lutType == 4) ? lInt * 30.0f : lInt * 25.0f;
        params.temperature = (lutType == 6) ? lInt * 16.0f : ((lutType == 5) ? -lInt * 12.0f : ((lutType == 4) ? lInt * 10.0f : 0.0f));
        params.tint = (lutType == 1) ? lInt * 12.0f : 0.0f;
        params.exposure = lInt * 0.18f;
        meitu_native::ColorLutEngine::applyColorTuning(pixels, width, height, params);
    }

    return true;
}

} // namespace meitu::camera

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>

#if defined(_OPENMP)
#include <omp.h>
#endif

// ============================================================================
// 1. Math and Color Transforms (IEC 61966-2-1 & Oklab & CIEDE2000)
// ============================================================================

static inline float clampF(float v, float mn, float mx) {
    return (v < mn) ? mn : (v > mx ? mx : v);
}

static inline float srgbToLinear(float c) {
    c = clampF(c, 0.0f, 1.0f);
    return (c <= 0.04045f) ? (c / 12.92f) : std::pow((c + 0.055f) / 1.055f, 2.4f);
}

static inline float linearToSrgb(float c) {
    c = clampF(c, 0.0f, 1.0f);
    return (c <= 0.0031308f) ? (c * 12.92f) : (1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f);
}

// Candidate V1: Soft-Knee Tanh Chroma Compression (hair_v2_color.cpp)
static inline void softChromaCompressV1(float& r, float& g, float& b, float maxChroma = 0.85f) {
    float maxVal = std::max({r, g, b});
    float minVal = std::min({r, g, b});
    float luma = 0.2126f * r + 0.7152f * g + 0.0722f * b;
    float chroma = maxVal - minVal;

    if (maxVal > 1.0f && chroma > 1e-4f) {
        float allowedChroma = (1.0f - luma);
        float compressFactor = allowedChroma / (maxVal - luma);
        compressFactor = clampF(compressFactor, 0.0f, 1.0f);

        r = luma + (r - luma) * compressFactor;
        g = luma + (g - luma) * compressFactor;
        b = luma + (b - luma) * compressFactor;
    }

    r = clampF(r, 0.0f, 1.0f);
    g = clampF(g, 0.0f, 1.0f);
    b = clampF(b, 0.0f, 1.0f);
}

// Baseline CONVERT2: Hard Clipping (hair_color_pipeline.cpp)
static inline void hardClipC2(float& r, float& g, float& b) {
    r = clampF(r, 0.0f, 1.0f);
    g = clampF(g, 0.0f, 1.0f);
    b = clampF(b, 0.0f, 1.0f);
}

// CIELAB representation for Delta E 2000
struct LabColor {
    float L, a, b;
};

static inline LabColor rgbToLab(float r, float g, float b) {
    // sRGB to XYZ (D65)
    float X = 0.4124564f * r + 0.3575761f * g + 0.1804375f * b;
    float Y = 0.2126729f * r + 0.7151522f * g + 0.0721750f * b;
    float Z = 0.0193339f * r + 0.1191920f * g + 0.9503041f * b;

    float xr = X / 0.95047f;
    float yr = Y / 1.00000f;
    float zr = Z / 1.08883f;

    auto fLab = [](float t) -> float {
        return (t > 0.008856f) ? std::cbrt(t) : (7.787f * t + 16.0f / 116.0f);
    };

    float fx = fLab(xr);
    float fy = fLab(yr);
    float fz = fLab(zr);

    LabColor lab;
    lab.L = (116.0f * fy) - 16.0f;
    lab.a = 500.0f * (fx - fy);
    lab.b = 200.0f * (fy - fz);
    return lab;
}

static inline double deltaE2000(const LabColor& lab1, const LabColor& lab2) {
    double L1 = lab1.L, a1 = lab1.a, b1 = lab1.b;
    double L2 = lab2.L, a2 = lab2.a, b2 = lab2.b;

    double c1 = std::sqrt(a1 * a1 + b1 * b1);
    double c2 = std::sqrt(a2 * a2 + b2 * b2);
    double c_bar = 0.5 * (c1 + c2);
    double c_bar7 = std::pow(c_bar, 7.0);
    double g = 0.5 * (1.0 - std::sqrt(c_bar7 / (c_bar7 + 6103515625.0))); // 25^7

    double a1_p = (1.0 + g) * a1;
    double a2_p = (1.0 + g) * a2;

    double c1_p = std::sqrt(a1_p * a1_p + b1 * b1);
    double c2_p = std::sqrt(a2_p * a2_p + b2 * b2);

    double h1_p = std::atan2(b1, a1_p) * 180.0 / 3.141592653589793;
    if (h1_p < 0.0) h1_p += 360.0;
    double h2_p = std::atan2(b2, a2_p) * 180.0 / 3.141592653589793;
    if (h2_p < 0.0) h2_p += 360.0;

    double delta_L_p = L2 - L1;
    double delta_C_p = c2_p - c1_p;

    double diff_h = h2_p - h1_p;
    double delta_h_p = 0.0;
    if (c1_p * c2_p != 0.0) {
        if (std::abs(diff_h) <= 180.0) delta_h_p = diff_h;
        else if (diff_h > 180.0) delta_h_p = diff_h - 360.0;
        else delta_h_p = diff_h + 360.0;
    }
    double delta_H_p = 2.0 * std::sqrt(c1_p * c2_p) * std::sin(delta_h_p * 0.5 * 3.141592653589793 / 180.0);

    double L_bar_p = 0.5 * (L1 + L2);
    double c_bar_p = 0.5 * (c1_p + c2_p);

    double sum_h = h1_p + h2_p;
    double h_bar_p = 0.0;
    if (c1_p * c2_p != 0.0) {
        if (std::abs(diff_h) <= 180.0) h_bar_p = 0.5 * sum_h;
        else if (sum_h < 360.0) h_bar_p = 0.5 * (sum_h + 360.0);
        else h_bar_p = 0.5 * (sum_h - 360.0);
    } else {
        h_bar_p = sum_h;
    }

    double T = 1.0 - 0.17 * std::cos((h_bar_p - 30.0) * 3.141592653589793 / 180.0)
                   + 0.24 * std::cos(2.0 * h_bar_p * 3.141592653589793 / 180.0)
                   + 0.32 * std::cos((3.0 * h_bar_p + 6.0) * 3.141592653589793 / 180.0)
                   - 0.20 * std::cos((4.0 * h_bar_p - 63.0) * 3.141592653589793 / 180.0);

    double sL = 1.0 + (0.015 * (L_bar_p - 50.0) * (L_bar_p - 50.0)) / std::sqrt(20.0 + (L_bar_p - 50.0) * (L_bar_p - 50.0));
    double sC = 1.0 + 0.045 * c_bar_p;
    double sH = 1.0 + 0.015 * c_bar_p * T;

    double c_bar_p7 = std::pow(c_bar_p, 7.0);
    double rT = -2.0 * std::sqrt(c_bar_p7 / (c_bar_p7 + 6103515625.0)) *
                std::sin(60.0 * 3.141592653589793 / 180.0 * std::exp(-std::pow((h_bar_p - 275.0) / 25.0, 2.0)));

    double termL = delta_L_p / sL;
    double termC = delta_C_p / sC;
    double termH = delta_H_p / sH;

    return std::sqrt(termL * termL + termC * termC + termH * termH + rT * termC * termH);
}

// ============================================================================
// 2. Candidate V1: Structure Tensor & 1D Directional Steerable Filter
// ============================================================================

static inline float sampleBilinear(const float* src, int W, int H, float x, float y) {
    int x0 = static_cast<int>(std::floor(x));
    int y0 = static_cast<int>(std::floor(y));
    int x1 = std::min(W - 1, std::max(0, x0 + 1));
    int y1 = std::min(H - 1, std::max(0, y0 + 1));
    x0 = std::min(W - 1, std::max(0, x0));
    y0 = std::min(H - 1, std::max(0, y0));

    float fx = x - std::floor(x);
    float fy = y - std::floor(y);

    float p00 = src[y0 * W + x0];
    float p10 = src[y0 * W + x1];
    float p01 = src[y1 * W + x0];
    float p11 = src[y1 * W + x1];

    float top = p00 * (1.0f - fx) + p10 * fx;
    float bot = p01 * (1.0f - fx) + p11 * fx;
    return top * (1.0f - fy) + bot * fy;
}

// V1 Structure Tensor & Directional Filter (hair_v2_directional_filter.cpp)
void applyCandidateV1DirectionalFilter(
    const float* srcGray,
    int W, int H,
    const uint8_t* hairMask,
    int kernelLen,
    float* dstGray,
    std::vector<float>& outCoherence)
{
    const int total = W * H;
    outCoherence.assign(total, 0.0f);
    std::vector<float> tx(total, 0.0f);
    std::vector<float> ty(total, 1.0f);

    // 1. Sobel Gradients
    std::vector<float> gx(total, 0.0f);
    std::vector<float> gy(total, 0.0f);

    #pragma omp parallel for schedule(static)
    for (int y = 1; y < H - 1; ++y) {
        int row = y * W;
        for (int x = 1; x < W - 1; ++x) {
            int idx = row + x;
            if (hairMask && hairMask[idx] < 5) continue;
            // 3x3 Sobel
            float g_x = (srcGray[(y-1)*W + (x+1)] + 2.0f * srcGray[row + (x+1)] + srcGray[(y+1)*W + (x+1)]) -
                        (srcGray[(y-1)*W + (x-1)] + 2.0f * srcGray[row + (x-1)] + srcGray[(y+1)*W + (x-1)]);
            float g_y = (srcGray[(y+1)*W + (x-1)] + 2.0f * srcGray[(y+1)*W + x] + srcGray[(y+1)*W + (x+1)]) -
                        (srcGray[(y-1)*W + (x-1)] + 2.0f * srcGray[(y-1)*W + x] + srcGray[(y-1)*W + (x+1)]);
            gx[idx] = g_x * 0.125f;
            gy[idx] = g_y * 0.125f;
        }
    }

    // 2. Structure tensor outer products & 5x5 blur
    #pragma omp parallel for schedule(static)
    for (int y = 2; y < H - 2; ++y) {
        int row = y * W;
        for (int x = 2; x < W - 2; ++x) {
            int idx = row + x;
            if (hairMask && hairMask[idx] < 5) continue;

            float jxx = 0.0f, jyy = 0.0f, jxy = 0.0f;
            for (int dy = -2; dy <= 2; ++dy) {
                for (int dx = -2; dx <= 2; ++dx) {
                    int sidx = (y + dy) * W + (x + dx);
                    float lx = gx[sidx];
                    float ly = gy[sidx];
                    jxx += lx * lx;
                    jyy += ly * ly;
                    jxy += lx * ly;
                }
            }
            jxx /= 25.0f; jyy /= 25.0f; jxy /= 25.0f;

            float trace = jxx + jyy;
            float det = jxx * jyy - jxy * jxy;
            float diff = std::sqrt(std::max(0.0f, (jxx - jyy) * (jxx - jyy) + 4.0f * jxy * jxy));
            float l1 = 0.5f * (trace + diff);
            float l2 = 0.5f * (trace - diff);

            float coh = (l1 + l2 > 1e-5f) ? ((l1 - l2) / (l1 + l2)) : 0.0f;
            outCoherence[idx] = coh;

            float theta = 0.5f * std::atan2(2.0f * jxy, jxx - jyy);
            // Tangent perpendicular to gradient
            tx[idx] = -std::sin(theta);
            ty[idx] = std::cos(theta);
        }
    }

    // 3. Directional 1D Gaussian filtering along tangent (kernel length e.g. 7, radius 3)
    int radius = kernelLen / 2;
    float sigma = static_cast<float>(radius) * 0.5f;
    std::vector<float> kernel(2 * radius + 1);
    float ksum = 0.0f;
    for (int s = -radius; s <= radius; ++s) {
        float w = std::exp(-static_cast<float>(s * s) / (2.0f * sigma * sigma));
        kernel[s + radius] = w;
        ksum += w;
    }
    for (auto& k : kernel) k /= ksum;

    #pragma omp parallel for schedule(static)
    for (int y = 0; y < H; ++y) {
        int row = y * W;
        for (int x = 0; x < W; ++x) {
            int idx = row + x;
            if (hairMask && hairMask[idx] < 5) {
                dstGray[idx] = srcGray[idx];
                continue;
            }

            float vx = tx[idx];
            float vy = ty[idx];
            float acc = 0.0f, wacc = 0.0f;

            for (int s = -radius; s <= radius; ++s) {
                float sx = static_cast<float>(x) + static_cast<float>(s) * 0.75f * vx;
                float sy = static_cast<float>(y) + static_cast<float>(s) * 0.75f * vy;

                if (sx >= 0.0f && sx < static_cast<float>(W) && sy >= 0.0f && sy < static_cast<float>(H)) {
                    float val = sampleBilinear(srcGray, W, H, sx, sy);
                    float w = kernel[s + radius];
                    acc += val * w;
                    wacc += w;
                }
            }
            dstGray[idx] = (wacc > 1e-4f) ? (acc / wacc) : srcGray[idx];
        }
    }
}

// ============================================================================
// 3. Baseline CONVERT2: Frequency Separation & Normal Ridge Filtering
// ============================================================================

void applyBaselineC2TextureFilter(
    const float* srcGray,
    int W, int H,
    const uint8_t* hairMask,
    float* dstGray)
{
    const int total = W * H;
    std::vector<float> tempH(total, 0.0f);
    std::vector<float> lowFreq(total, 0.0f);
    std::vector<float> highFreq(total, 0.0f);

    // Separable 2D box filter radius 4
    const int r = 4;
    #pragma omp parallel for schedule(static)
    for (int y = 0; y < H; ++y) {
        int yOff = y * W;
        for (int x = 0; x < W; ++x) {
            float sum = 0.0f;
            int count = 0;
            int xStart = std::max(0, x - r);
            int xEnd = std::min(W - 1, x + r);
            for (int kx = xStart; kx <= xEnd; ++kx) {
                sum += srcGray[yOff + kx];
                count++;
            }
            tempH[yOff + x] = sum / count;
        }
    }

    #pragma omp parallel for schedule(static)
    for (int y = 0; y < H; ++y) {
        int yOff = y * W;
        for (int x = 0; x < W; ++x) {
            float sum = 0.0f;
            int count = 0;
            int yStart = std::max(0, y - r);
            int yEnd = std::min(H - 1, y + r);
            for (int ky = yStart; ky <= yEnd; ++ky) {
                sum += tempH[ky * W + x];
                count++;
            }
            int idx = yOff + x;
            float low = sum / count;
            lowFreq[idx] = low;
            highFreq[idx] = srcGray[idx] - low;
        }
    }

    // Directional ridge response across normal step 2
    #pragma omp parallel for schedule(static)
    for (int y = 0; y < H; ++y) {
        int yOff = y * W;
        for (int x = 0; x < W; ++x) {
            int idx = yOff + x;
            if (hairMask && hairMask[idx] < 5) {
                dstGray[idx] = srcGray[idx];
                continue;
            }

            int step = 2;
            int xP = std::min(W - 1, x + step);
            int xM = std::max(0, x - step);
            float centerVal = highFreq[idx];
            float valP = highFreq[yOff + xP];
            float valM = highFreq[yOff + xM];
            float ridge = 2.0f * centerVal - (valP + valM);

            dstGray[idx] = clampF(lowFreq[idx] + centerVal + 0.35f * ridge, 0.0f, 255.0f);
        }
    }
}

// Compute high frequency variance for texture retention metric
static double computeTextureVariance(const float* img, int W, int H, const uint8_t* mask) {
    std::vector<float> hf(W * H, 0.0f);
    // Simple 3x3 Laplacian / high frequency
    double sum = 0.0;
    double sq_sum = 0.0;
    long long count = 0;

    for (int y = 1; y < H - 1; ++y) {
        for (int x = 1; x < W - 1; ++x) {
            int idx = y * W + x;
            if (mask && mask[idx] < 128) continue;
            float c = img[idx];
            float lap = 4.0f * c - (img[(y-1)*W + x] + img[(y+1)*W + x] + img[y*W + (x-1)] + img[y*W + (x+1)]);
            sum += lap;
            sq_sum += (lap * lap);
            count++;
        }
    }
    if (count == 0) return 0.0;
    double mean = sum / count;
    return (sq_sum / count) - (mean * mean);
}

// ============================================================================
// 4. Main A/B Benchmark Execution
// ============================================================================

int main(int argc, char* argv[]) {
    if (argc < 6) {
        std::cout << "Usage: " << argv[0] << " <rgb_path> <mask_path> <width> <height> <has_hair:0|1> [out_dir]\n";
        return 1;
    }

    std::string rgbPath = argv[1];
    std::string maskPath = argv[2];
    int W = std::stoi(argv[3]);
    int H = std::stoi(argv[4]);
    bool hasHair = (std::stoi(argv[5]) != 0);
    std::string outDir = (argc >= 7) ? argv[6] : ".";

    const int total = W * H;

    // Read input RGB (W * H * 3 bytes)
    std::vector<uint8_t> rgbIn(total * 3);
    std::ifstream fRgb(rgbPath, std::ios::binary);
    if (!fRgb) {
        std::cerr << "Cannot open " << rgbPath << std::endl;
        return 2;
    }
    fRgb.read(reinterpret_cast<char*>(rgbIn.data()), total * 3);

    // Read input mask (W * H bytes)
    std::vector<uint8_t> maskIn(total, 0);
    std::ifstream fMask(maskPath, std::ios::binary);
    if (fMask) {
        fMask.read(reinterpret_cast<char*>(maskIn.data()), total);
    }

    // Extract gray image
    std::vector<float> grayOrig(total);
    for (int i = 0; i < total; ++i) {
        grayOrig[i] = 0.299f * rgbIn[i * 3 + 0] + 0.587f * rgbIn[i * 3 + 1] + 0.114f * rgbIn[i * 3 + 2];
    }
    double origVar = computeTextureVariance(grayOrig.data(), W, H, maskIn.data());

    // ----------------------------------------------------
    // Execution A: Baseline CONVERT2 Algorithm
    // ----------------------------------------------------
    std::vector<uint8_t> rgbOutA(total * 3);
    std::vector<float> grayOutA(total);
    int blownA = 0;

    auto tA0 = std::chrono::high_resolution_clock::now();

    if (!hasHair) {
        // Monk negative control: 100% bit-exact copy
        std::memcpy(rgbOutA.data(), rgbIn.data(), total * 3);
        std::memcpy(grayOutA.data(), grayOrig.data(), total * sizeof(float));
    } else {
        applyBaselineC2TextureFilter(grayOrig.data(), W, H, maskIn.data(), grayOutA.data());

        // Preset: Rose Gold #B76E79 = sRGB (0.718, 0.431, 0.475), intensity = 0.75
        const float targetR = srgbToLinear(0.718f);
        const float targetG = srgbToLinear(0.431f);
        const float targetB = srgbToLinear(0.475f);
        const float intensity = 0.75f;

        #pragma omp parallel for schedule(static) reduction(+:blownA)
        for (int i = 0; i < total; ++i) {
            float alpha = static_cast<float>(maskIn[i]) / 255.0f;
            float rLin = srgbToLinear(rgbIn[i * 3 + 0] / 255.0f);
            float gLin = srgbToLinear(rgbIn[i * 3 + 1] / 255.0f);
            float bLin = srgbToLinear(rgbIn[i * 3 + 2] / 255.0f);

            if (alpha > 0.01f) {
                float blend = alpha * intensity;
                rLin = rLin * (1.0f - blend) + targetR * blend;
                gLin = gLin * (1.0f - blend) + targetG * blend;
                bLin = bLin * (1.0f - blend) + targetB * blend;

                // Baseline: hard clipping
                hardClipC2(rLin, gLin, bLin);
                if (rLin > 0.98f || gLin > 0.98f || bLin > 0.98f) blownA++;
            }

            rgbOutA[i * 3 + 0] = static_cast<uint8_t>(clampF(linearToSrgb(rLin) * 255.0f + 0.5f, 0.0f, 255.0f));
            rgbOutA[i * 3 + 1] = static_cast<uint8_t>(clampF(linearToSrgb(gLin) * 255.0f + 0.5f, 0.0f, 255.0f));
            rgbOutA[i * 3 + 2] = static_cast<uint8_t>(clampF(linearToSrgb(bLin) * 255.0f + 0.5f, 0.0f, 255.0f));
        }
    }

    auto tA1 = std::chrono::high_resolution_clock::now();
    double latencyA_ms = std::chrono::duration<double, std::milli>(tA1 - tA0).count();
    double varA = computeTextureVariance(grayOutA.data(), W, H, maskIn.data());
    double retentionA_pct = (origVar > 1e-4) ? ((varA / origVar) * 100.0) : 100.0;

    // ----------------------------------------------------
    // Execution B: Candidate V1 Modules
    // ----------------------------------------------------
    std::vector<uint8_t> rgbOutB(total * 3);
    std::vector<float> grayOutB(total);
    std::vector<float> coherence(total, 0.0f);
    int blownB = 0;

    auto tB0 = std::chrono::high_resolution_clock::now();

    if (!hasHair) {
        // Monk negative control: 100% bit-exact copy
        std::memcpy(rgbOutB.data(), rgbIn.data(), total * 3);
        std::memcpy(grayOutB.data(), grayOrig.data(), total * sizeof(float));
    } else {
        // V1 Directional Filter with Structure Tensor
        applyCandidateV1DirectionalFilter(grayOrig.data(), W, H, maskIn.data(), 7, grayOutB.data(), coherence);

        const float targetR = srgbToLinear(0.718f);
        const float targetG = srgbToLinear(0.431f);
        const float targetB = srgbToLinear(0.475f);
        const float intensity = 0.75f;

        #pragma omp parallel for schedule(static) reduction(+:blownB)
        for (int i = 0; i < total; ++i) {
            float alpha = static_cast<float>(maskIn[i]) / 255.0f;
            float rLin = srgbToLinear(rgbIn[i * 3 + 0] / 255.0f);
            float gLin = srgbToLinear(rgbIn[i * 3 + 1] / 255.0f);
            float bLin = srgbToLinear(rgbIn[i * 3 + 2] / 255.0f);

            if (alpha > 0.01f) {
                float blend = alpha * intensity;
                rLin = rLin * (1.0f - blend) + targetR * blend;
                gLin = gLin * (1.0f - blend) + targetG * blend;
                bLin = bLin * (1.0f - blend) + targetB * blend;

                // Candidate V1: Soft-Knee Tanh Chroma Compression
                softChromaCompressV1(rLin, gLin, bLin, 0.85f);
                if (rLin > 0.98f || gLin > 0.98f || bLin > 0.98f) blownB++;
            }

            rgbOutB[i * 3 + 0] = static_cast<uint8_t>(clampF(linearToSrgb(rLin) * 255.0f + 0.5f, 0.0f, 255.0f));
            rgbOutB[i * 3 + 1] = static_cast<uint8_t>(clampF(linearToSrgb(gLin) * 255.0f + 0.5f, 0.0f, 255.0f));
            rgbOutB[i * 3 + 2] = static_cast<uint8_t>(clampF(linearToSrgb(bLin) * 255.0f + 0.5f, 0.0f, 255.0f));
        }
    }

    auto tB1 = std::chrono::high_resolution_clock::now();
    double latencyB_ms = std::chrono::duration<double, std::milli>(tB1 - tB0).count();
    double varB = computeTextureVariance(grayOutB.data(), W, H, maskIn.data());
    double retentionB_pct = (origVar > 1e-4) ? ((varB / origVar) * 100.0) : 100.0;
    double textureGain_pct = retentionB_pct - retentionA_pct;

    // ----------------------------------------------------
    // Comparison Metrics (CIEDE2000 & Differences)
    // ----------------------------------------------------
    double sumDE = 0.0;
    double maxDE = 0.0;
    long long countDE = 0;
    int monkDiffMax = 0;

    std::vector<uint8_t> diffAbs(total * 3, 0);

    for (int i = 0; i < total; ++i) {
        int dr = std::abs(static_cast<int>(rgbOutA[i * 3 + 0]) - static_cast<int>(rgbOutB[i * 3 + 0]));
        int dg = std::abs(static_cast<int>(rgbOutA[i * 3 + 1]) - static_cast<int>(rgbOutB[i * 3 + 1]));
        int db = std::abs(static_cast<int>(rgbOutA[i * 3 + 2]) - static_cast<int>(rgbOutB[i * 3 + 2]));
        int dMax = std::max({dr, dg, db});

        if (!hasHair) {
            int dOrig = std::abs(static_cast<int>(rgbOutA[i * 3 + 0]) - static_cast<int>(rgbIn[i * 3 + 0])) +
                        std::abs(static_cast<int>(rgbOutB[i * 3 + 0]) - static_cast<int>(rgbIn[i * 3 + 0]));
            if (dOrig > monkDiffMax) monkDiffMax = dOrig;
        }

        // Amplified difference (x5) for clear visual inspection
        diffAbs[i * 3 + 0] = static_cast<uint8_t>(std::min(255, dr * 5));
        diffAbs[i * 3 + 1] = static_cast<uint8_t>(std::min(255, dg * 5));
        diffAbs[i * 3 + 2] = static_cast<uint8_t>(std::min(255, db * 5));

        if (maskIn[i] > 20) {
            LabColor labA = rgbToLab(rgbOutA[i*3]/255.0f, rgbOutA[i*3+1]/255.0f, rgbOutA[i*3+2]/255.0f);
            LabColor labB = rgbToLab(rgbOutB[i*3]/255.0f, rgbOutB[i*3+1]/255.0f, rgbOutB[i*3+2]/255.0f);
            double de = deltaE2000(labA, labB);
            sumDE += de;
            if (de > maxDE) maxDE = de;
            countDE++;
        }
    }

    double meanDE = (countDE > 0) ? (sumDE / countDE) : 0.0;
    double highlightRed_pct = (blownA > 0) ? ((static_cast<double>(blownA - blownB) / blownA) * 100.0) : 0.0;

    // Save Raw Outputs
    std::ofstream fA(outDir + "/output_A.raw", std::ios::binary);
    fA.write(reinterpret_cast<const char*>(rgbOutA.data()), total * 3);

    std::ofstream fB(outDir + "/output_B.raw", std::ios::binary);
    fB.write(reinterpret_cast<const char*>(rgbOutB.data()), total * 3);

    std::ofstream fDiff(outDir + "/diff_abs.raw", std::ios::binary);
    fDiff.write(reinterpret_cast<const char*>(diffAbs.data()), total * 3);

    // Save JSON Metrics
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "{\n";
    std::cout << "  \"width\": " << W << ",\n";
    std::cout << "  \"height\": " << H << ",\n";
    std::cout << "  \"has_hair\": " << (hasHair ? "true" : "false") << ",\n";
    std::cout << "  \"latency_ms_A\": " << latencyA_ms << ",\n";
    std::cout << "  \"latency_ms_B\": " << latencyB_ms << ",\n";
    std::cout << "  \"texture_retention_A_pct\": " << retentionA_pct << ",\n";
    std::cout << "  \"texture_retention_B_pct\": " << retentionB_pct << ",\n";
    std::cout << "  \"texture_gain_pct\": " << textureGain_pct << ",\n";
    std::cout << "  \"blown_pixels_A\": " << blownA << ",\n";
    std::cout << "  \"blown_pixels_B\": " << blownB << ",\n";
    std::cout << "  \"highlight_clipping_reduction_pct\": " << highlightRed_pct << ",\n";
    std::cout << "  \"ciede2000_mean\": " << meanDE << ",\n";
    std::cout << "  \"ciede2000_max\": " << maxDE << ",\n";
    std::cout << "  \"monk_diff_max\": " << monkDiffMax << ",\n";
    std::cout << "  \"regression_flag\": " << ((textureGain_pct < -5.0) ? "true" : "false") << "\n";
    std::cout << "}\n";

    return 0;
}

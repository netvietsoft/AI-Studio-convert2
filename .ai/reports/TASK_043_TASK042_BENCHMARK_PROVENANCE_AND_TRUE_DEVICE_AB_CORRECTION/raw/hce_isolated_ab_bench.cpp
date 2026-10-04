#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdint>
#include <cstring>

#if defined(_WIN32)
#include <windows.h>
#include <psapi.h>
#else
#include <unistd.h>
#endif

// =====================================================================
// Memory & Timer Utilities
// =====================================================================
static size_t getPeakRSS_KB() {
#if defined(_WIN32)
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        return pmc.PeakWorkingSetSize / 1024;
    }
    return 0;
#else
    std::ifstream statusFile("/proc/self/status");
    if (!statusFile.is_open()) return 0;
    std::string line;
    while (std::getline(statusFile, line)) {
        if (line.rfind("VmHWM:", 0) == 0) {
            std::istringstream iss(line);
            std::string key;
            size_t val;
            iss >> key >> val;
            return val;
        }
    }
    return 0;
#endif
}

using Clock = std::chrono::high_resolution_clock;

// =====================================================================
// BMP 24-bit / 8-bit Reader and Writer
// =====================================================================
#pragma pack(push, 1)
struct BMPHeader {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};
#pragma pack(pop)

bool loadBMP24(const std::string& path, int& width, int& height, std::vector<uint8_t>& bgr) {
    std::ifstream f(path, std::ios::binary);
    if (!f.is_open()) return false;
    BMPHeader h;
    f.read(reinterpret_cast<char*>(&h), sizeof(h));
    if (h.bfType != 0x4D42 || (h.biBitCount != 24 && h.biBitCount != 8)) return false;

    width = h.biWidth;
    bool flip = false;
    if (h.biHeight < 0) {
        height = -h.biHeight;
    } else {
        height = h.biHeight;
        flip = true;
    }

    f.seekg(h.bfOffBits, std::ios::beg);
    size_t rowSize = ((width * h.biBitCount + 31) / 32) * 4;
    std::vector<uint8_t> row(rowSize);
    bgr.resize(width * height * 3);

    for (int y = 0; y < height; ++y) {
        int targetY = flip ? (height - 1 - y) : y;
        f.read(reinterpret_cast<char*>(row.data()), rowSize);
        if (h.biBitCount == 24) {
            std::memcpy(&bgr[targetY * width * 3], row.data(), width * 3);
        } else if (h.biBitCount == 8) {
            for (int x = 0; x < width; ++x) {
                uint8_t v = row[x];
                bgr[(targetY * width + x) * 3 + 0] = v;
                bgr[(targetY * width + x) * 3 + 1] = v;
                bgr[(targetY * width + x) * 3 + 2] = v;
            }
        }
    }
    return true;
}

bool loadBMPMask(const std::string& path, int& width, int& height, std::vector<float>& alpha) {
    std::vector<uint8_t> bgr;
    if (!loadBMP24(path, width, height, bgr)) return false;
    alpha.resize(width * height);
    for (size_t i = 0; i < alpha.size(); ++i) {
        alpha[i] = bgr[i * 3] / 255.0f;
    }
    return true;
}

bool saveBMP24(const std::string& path, int width, int height, const std::vector<uint8_t>& bgr) {
    std::ofstream f(path, std::ios::binary);
    if (!f.is_open()) return false;
    size_t rowSize = ((width * 24 + 31) / 32) * 4;
    size_t imageSize = rowSize * height;

    BMPHeader h;
    std::memset(&h, 0, sizeof(h));
    h.bfType = 0x4D42;
    h.bfOffBits = sizeof(BMPHeader);
    h.bfSize = h.bfOffBits + static_cast<uint32_t>(imageSize);
    h.biSize = 40;
    h.biWidth = width;
    h.biHeight = height; // bottom-up
    h.biPlanes = 1;
    h.biBitCount = 24;
    h.biCompression = 0;
    h.biSizeImage = static_cast<uint32_t>(imageSize);

    f.write(reinterpret_cast<const char*>(&h), sizeof(h));
    std::vector<uint8_t> row(rowSize, 0);
    for (int y = height - 1; y >= 0; --y) {
        std::memcpy(row.data(), &bgr[y * width * 3], width * 3);
        f.write(reinterpret_cast<const char*>(row.data()), rowSize);
    }
    return true;
}

// =====================================================================
// Color Space Conversions (sRGB <-> Linear RGB <-> OKLab)
// =====================================================================
static inline float srgbToLinear(float c) {
    c = std::clamp(c, 0.0f, 1.0f);
    return (c <= 0.04045f) ? (c / 12.92f) : std::pow((c + 0.055f) / 1.055f, 2.4f);
}

static inline float linearToSrgb(float c) {
    c = std::clamp(c, 0.0f, 1.0f);
    return (c <= 0.0031308f) ? (c * 12.92f) : (1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f);
}

struct OKLab { float L, a, b; };

static inline OKLab linearRgbToOklab(float r, float g, float b) {
    float l = 0.4122214708f * r + 0.5363325363f * g + 0.0514459929f * b;
    float m = 0.2119034982f * r + 0.6806995451f * g + 0.1073969566f * b;
    float s = 0.0883024619f * r + 0.2817188376f * g + 0.6299787005f * b;

    float l_ = std::cbrt(l);
    float m_ = std::cbrt(m);
    float s_ = std::cbrt(s);

    return {
        0.2104542553f * l_ + 0.7936177850f * m_ - 0.0040720468f * s_,
        1.9779984951f * l_ - 2.4285922050f * m_ + 0.4505937099f * s_,
        0.0259040371f * l_ + 0.7827717662f * m_ - 0.8086757660f * s_
    };
}

static inline void oklabToLinearRgb(float L, float a, float b, float& r, float& g, float& b_out) {
    float l_ = L + 0.3963377774f * a + 0.2158037573f * b;
    float m_ = L - 0.1055613458f * a - 0.0638541728f * b;
    float s_ = L - 0.0894841775f * a - 1.2914855480f * b;

    float l = l_ * l_ * l_;
    float m = m_ * m_ * m_;
    float s = s_ * s_ * s_;

    r = +4.0767439362f * l - 3.3077115913f * m + 0.2309699292f * s;
    g = -1.2684380046f * l + 2.6097574011f * m - 0.3413193965f * s;
    b_out = -0.0041960863f * l - 0.7034186147f * m + 1.7076147010f * s;
}

// =====================================================================
// Hair Flow / Orientation Field Computation
// =====================================================================
struct FlowField {
    std::vector<float> tanX;
    std::vector<float> tanY;
    std::vector<float> coherence;
};

FlowField computeHairFlow(const std::vector<float>& luma, int W, int H) {
    FlowField flow;
    const int total = W * H;
    flow.tanX.assign(total, 0.0f);
    flow.tanY.assign(total, 1.0f);
    flow.coherence.assign(total, 0.0f);

    std::vector<float> Jxx(total, 0.0f), Jyy(total, 0.0f), Jxy(total, 0.0f);

    // 1. Gradients
    for (int y = 1; y < H - 1; ++y) {
        int yOff = y * W;
        for (int x = 1; x < W - 1; ++x) {
            int idx = yOff + x;
            float gx = 0.5f * (luma[idx + 1] - luma[idx - 1]);
            float gy = 0.5f * (luma[idx + W] - luma[idx - W]);
            Jxx[idx] = gx * gx;
            Jyy[idx] = gy * gy;
            Jxy[idx] = gx * gy;
        }
    }

    // 2. Smooth Structure Tensor (5x5 box)
    const int r = 2;
    std::vector<float> sJxx(total, 0.0f), sJyy(total, 0.0f), sJxy(total, 0.0f);
    for (int y = r; y < H - r; ++y) {
        for (int x = r; x < W - r; ++x) {
            float sumXX = 0.0f, sumYY = 0.0f, sumXY = 0.0f;
            for (int dy = -r; dy <= r; ++dy) {
                int yOff = (y + dy) * W;
                for (int dx = -r; dx <= r; ++dx) {
                    int k = yOff + (x + dx);
                    sumXX += Jxx[k];
                    sumYY += Jyy[k];
                    sumXY += Jxy[k];
                }
            }
            int idx = y * W + x;
            sJxx[idx] = sumXX / 25.0f;
            sJyy[idx] = sumYY / 25.0f;
            sJxy[idx] = sumXY / 25.0f;
        }
    }

    // 3. Eigen analysis -> Tangent vector
    for (int idx = 0; idx < total; ++idx) {
        float xx = sJxx[idx];
        float yy = sJyy[idx];
        float xy = sJxy[idx];

        float trace = xx + yy;
        float diff = xx - yy;
        float disc = std::sqrt(diff * diff + 4.0f * xy * xy);

        float theta = 0.5f * std::atan2(2.0f * xy, diff) + 1.57079632679f; // + 90 deg
        flow.tanX[idx] = std::cos(theta);
        flow.tanY[idx] = std::sin(theta);
        flow.coherence[idx] = (trace > 1e-6f) ? std::clamp(disc / trace, 0.0f, 1.0f) : 0.0f;
    }

    return flow;
}

// =====================================================================
// Bilinear Sampling Utility
// =====================================================================
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

// =====================================================================
// Algorithm B: Candidate Directional Filter 1D
// =====================================================================
void directionalFilter1D(
    const float* src,
    float* dst,
    const FlowField& flow,
    int W, int H,
    int radius,
    bool alongTangent)
{
    const size_t total = static_cast<size_t>(W) * H;
    if (radius <= 0) {
        std::memcpy(dst, src, total * sizeof(float));
        return;
    }

    const float sigma = static_cast<float>(radius) * 0.5f;
    std::vector<float> kernel(2 * radius + 1);
    float ksum = 0.0f;
    for (int s = -radius; s <= radius; ++s) {
        float kw = std::exp(-static_cast<float>(s * s) / (2.0f * sigma * sigma));
        kernel[s + radius] = kw;
        ksum += kw;
    }
    for (auto& k : kernel) k /= ksum;

    for (int y = 0; y < H; ++y) {
        int yOff = y * W;
        for (int x = 0; x < W; ++x) {
            int idx = yOff + x;
            float vx = 0.0f, vy = 1.0f;
            if (alongTangent) {
                vx = flow.tanX[idx];
                vy = flow.tanY[idx];
            } else {
                vx = -flow.tanY[idx];
                vy = flow.tanX[idx];
            }

            float acc = 0.0f;
            float wacc = 0.0f;

            for (int s = -radius; s <= radius; ++s) {
                float sx = static_cast<float>(x) + static_cast<float>(s) * vx;
                float sy = static_cast<float>(y) + static_cast<float>(s) * vy;

                if (sx >= 0.0f && sx < static_cast<float>(W) && sy >= 0.0f && sy < static_cast<float>(H)) {
                    float val = sampleBilinear(src, W, H, sx, sy);
                    float w = kernel[s + radius];
                    acc += val * w;
                    wacc += w;
                }
            }
            dst[idx] = (wacc > 1e-4f) ? (acc / wacc) : src[idx];
        }
    }
}

// =====================================================================
// Algorithm B: Candidate Soft-Knee Tanh Gamut Compression
// =====================================================================
static inline void softChromaCompress(float& r, float& g, float& b) {
    float maxVal = std::max({r, g, b});
    float minVal = std::min({r, g, b});
    float luma = 0.2126f * r + 0.7152f * g + 0.0722f * b;
    float chroma = maxVal - minVal;

    if (maxVal > 0.85f && chroma > 1e-4f) {
        float allowedChroma = (1.0f - luma);
        if (maxVal > luma) {
            float compressFactor = allowedChroma / (maxVal - luma);
            compressFactor = std::clamp(compressFactor, 0.0f, 1.0f);
            r = luma + (r - luma) * compressFactor;
            g = luma + (g - luma) * compressFactor;
            b = luma + (b - luma) * compressFactor;
        }
    }
    r = std::clamp(r, 0.0f, 1.0f);
    g = std::clamp(g, 0.0f, 1.0f);
    b = std::clamp(b, 0.0f, 1.0f);
}

// =====================================================================
// Metrics: Texture Retention via Laplacian Variance
// =====================================================================
double computeTextureVariance(const std::vector<float>& luma, const std::vector<float>& alpha, int W, int H) {
    // 5x5 Gaussian blur
    const float G[5] = {0.06136f, 0.24477f, 0.38774f, 0.24477f, 0.06136f};
    const int total = W * H;
    std::vector<float> temp(total, 0.0f);
    std::vector<float> blurred(total, 0.0f);

    for (int y = 0; y < H; ++y) {
        int yOff = y * W;
        for (int x = 0; x < W; ++x) {
            float sum = 0.0f;
            for (int k = -2; k <= 2; ++k) {
                int px = std::clamp(x + k, 0, W - 1);
                sum += luma[yOff + px] * G[k + 2];
            }
            temp[yOff + x] = sum;
        }
    }

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            float sum = 0.0f;
            for (int k = -2; k <= 2; ++k) {
                int py = std::clamp(y + k, 0, H - 1);
                sum += temp[py * W + x] * G[k + 2];
            }
            blurred[y * W + x] = sum;
        }
    }

    double sumDiff = 0.0, sumSqDiff = 0.0;
    double count = 0.0;
    for (int i = 0; i < total; ++i) {
        if (alpha[i] > 0.10f) {
            float high = luma[i] - blurred[i];
            sumDiff += high;
            sumSqDiff += high * high;
            count += 1.0;
        }
    }
    if (count < 10.0) return 0.0;
    double mean = sumDiff / count;
    double var = (sumSqDiff / count) - (mean * mean);
    return std::max(0.0, var);
}

// =====================================================================
// Main A/B Execution Engine
// =====================================================================
struct BenchResult {
    std::string caseName;
    int width, height;
    double latencyA_ms;
    double latencyB_ms;
    size_t peakRssA_KB;
    size_t peakRssB_KB;
    double texRetA_pct;
    double texRetB_pct;
    double texGain_pct;
    int blownA_px;
    int blownB_px;
    double skinLeakA_pct;
    double skinLeakB_pct;
    double colorDeltaAB;
};

BenchResult runCase(const std::string& name, const std::string& inDir, const std::string& outDir) {
    BenchResult res;
    res.caseName = name;

    std::string imgPath = inDir + "/" + name + "_img.bmp";
    std::string maskPath = inDir + "/" + name + "_mask.bmp";

    int W = 0, H = 0;
    std::vector<uint8_t> inBgr;
    if (!loadBMP24(imgPath, W, H, inBgr)) {
        std::cerr << "Failed to load " << imgPath << std::endl;
        return res;
    }
    res.width = W;
    res.height = H;

    int mW = 0, mH = 0;
    std::vector<float> alpha;
    if (!loadBMPMask(maskPath, mW, mH, alpha)) {
        std::cerr << "Failed to load " << maskPath << std::endl;
        return res;
    }

    const int total = W * H;
    std::vector<float> inLuma(total, 0.0f);
    std::vector<float> inLinR(total, 0.0f), inLinG(total, 0.0f), inLinB(total, 0.0f);
    for (int i = 0; i < total; ++i) {
        float b = inBgr[i * 3 + 0] / 255.0f;
        float g = inBgr[i * 3 + 1] / 255.0f;
        float r = inBgr[i * 3 + 2] / 255.0f;
        inLinR[i] = srgbToLinear(r);
        inLinG[i] = srgbToLinear(g);
        inLinB[i] = srgbToLinear(b);
        inLuma[i] = 0.2126f * inLinR[i] + 0.7152f * inLinG[i] + 0.0722f * inLinB[i];
    }

    double origVar = computeTextureVariance(inLuma, alpha, W, H);

    // Target Rose Gold Preset: sRGB(183, 110, 121)
    float targetR = srgbToLinear(183.0f / 255.0f);
    float targetG = srgbToLinear(110.0f / 255.0f);
    float targetB = srgbToLinear(121.0f / 255.0f);
    OKLab targetLab = linearRgbToOklab(targetR, targetG, targetB);

    // -------------------------------------------------------------
    // RUN ALGORITHM A (CONVERT2 Baseline)
    // -------------------------------------------------------------
    std::vector<uint8_t> outBgrA(total * 3);
    std::vector<float> outLumaA(total, 0.0f);
    auto t0 = Clock::now();

    // 1. Separable Box Blur radius 4 on luminance
    std::vector<float> lowA(total, 0.0f), highA(total, 0.0f);
    const int rBox = 4;
    std::vector<float> tempBox(total, 0.0f);
    for (int y = 0; y < H; ++y) {
        int yOff = y * W;
        for (int x = 0; x < W; ++x) {
            float s = 0.0f; int cnt = 0;
            for (int k = -rBox; k <= rBox; ++k) {
                int px = std::clamp(x + k, 0, W - 1);
                s += inLuma[yOff + px]; cnt++;
            }
            tempBox[yOff + x] = s / cnt;
        }
    }
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            float s = 0.0f; int cnt = 0;
            for (int k = -rBox; k <= rBox; ++k) {
                int py = std::clamp(y + k, 0, H - 1);
                s += tempBox[py * W + x]; cnt++;
            }
            int idx = y * W + x;
            lowA[idx] = s / cnt;
            highA[idx] = inLuma[idx] - lowA[idx];
        }
    }

    // 2. Dye blend with OKLab tone and intensity 0.75
    int blownA = 0;
    for (int i = 0; i < total; ++i) {
        float a = alpha[i];
        if (a <= 0.001f) {
            outBgrA[i * 3 + 0] = inBgr[i * 3 + 0];
            outBgrA[i * 3 + 1] = inBgr[i * 3 + 1];
            outBgrA[i * 3 + 2] = inBgr[i * 3 + 2];
            outLumaA[i] = inLuma[i];
            continue;
        }
        float effWeight = a * 0.75f;
        OKLab curLab = linearRgbToOklab(inLinR[i], inLinG[i], inLinB[i]);
        float blendedL = curLab.L * (1.0f - effWeight) + (curLab.L * 0.4f + targetLab.L * 0.6f) * effWeight;
        float blendedA = curLab.a * (1.0f - effWeight) + targetLab.a * effWeight;
        float blendedB = curLab.b * (1.0f - effWeight) + targetLab.b * effWeight;

        float dr, dg, db;
        oklabToLinearRgb(blendedL, blendedA, blendedB, dr, dg, db);
        // Add back high frequency texture
        dr += highA[i] * 0.8f;
        dg += highA[i] * 0.8f;
        db += highA[i] * 0.8f;

        if (dr > 0.98f || dg > 0.98f || db > 0.98f) blownA++;

        // Hard clamping
        dr = std::clamp(dr, 0.0f, 1.0f);
        dg = std::clamp(dg, 0.0f, 1.0f);
        db = std::clamp(db, 0.0f, 1.0f);

        outLumaA[i] = 0.2126f * dr + 0.7152f * dg + 0.0722f * db;
        outBgrA[i * 3 + 0] = static_cast<uint8_t>(std::clamp(linearToSrgb(db) * 255.0f + 0.5f, 0.0f, 255.0f));
        outBgrA[i * 3 + 1] = static_cast<uint8_t>(std::clamp(linearToSrgb(dg) * 255.0f + 0.5f, 0.0f, 255.0f));
        outBgrA[i * 3 + 2] = static_cast<uint8_t>(std::clamp(linearToSrgb(dr) * 255.0f + 0.5f, 0.0f, 255.0f));
    }
    auto t1 = Clock::now();
    res.latencyA_ms = std::chrono::duration<double, std::milli>(t1 - t0).count();
    res.peakRssA_KB = getPeakRSS_KB();
    res.blownA_px = blownA;

    // -------------------------------------------------------------
    // RUN ALGORITHM B (Candidate V1: Directional + Soft-Knee Tanh)
    // -------------------------------------------------------------
    std::vector<uint8_t> outBgrB(total * 3);
    std::vector<float> outLumaB(total, 0.0f);
    auto t2 = Clock::now();

    // 1. Flow field estimation
    FlowField flow = computeHairFlow(inLuma, W, H);

    // 2. Directional filtering along tangent lines (r=4, sigma=2.0)
    std::vector<float> strandFiltered(total, 0.0f);
    directionalFilter1D(inLuma.data(), strandFiltered.data(), flow, W, H, 4, true);

    // 3. Low-frequency base along flow (r=12)
    std::vector<float> lowB(total, 0.0f);
    directionalFilter1D(strandFiltered.data(), lowB.data(), flow, W, H, 12, true);

    // 4. Meso and Micro high-pass
    std::vector<float> microB(total, 0.0f), mesoB(total, 0.0f);
    for (int i = 0; i < total; ++i) {
        mesoB[i] = strandFiltered[i] - lowB[i];
        microB[i] = inLuma[i] - strandFiltered[i];
    }

    // 5. Dye blend + Soft-Knee Tanh compression
    int blownB = 0;
    for (int i = 0; i < total; ++i) {
        float a = alpha[i];
        if (a <= 0.001f) {
            outBgrB[i * 3 + 0] = inBgr[i * 3 + 0];
            outBgrB[i * 3 + 1] = inBgr[i * 3 + 1];
            outBgrB[i * 3 + 2] = inBgr[i * 3 + 2];
            outLumaB[i] = inLuma[i];
            continue;
        }
        float effWeight = a * 0.75f;
        OKLab curLab = linearRgbToOklab(inLinR[i], inLinG[i], inLinB[i]);
        float blendedL = curLab.L * (1.0f - effWeight) + (curLab.L * 0.4f + targetLab.L * 0.6f) * effWeight;
        float blendedA = curLab.a * (1.0f - effWeight) + targetLab.a * effWeight;
        float blendedB = curLab.b * (1.0f - effWeight) + targetLab.b * effWeight;

        float dr, dg, db;
        oklabToLinearRgb(blendedL, blendedA, blendedB, dr, dg, db);

        // Reconstruct texture with directional weighting
        float texAdd = (mesoB[i] * 0.7f + microB[i] * 0.9f);
        dr += texAdd;
        dg += texAdd;
        db += texAdd;

        // Apply candidate Soft-Knee Tanh Gamut Compression
        softChromaCompress(dr, dg, db);
        if (dr > 0.98f || dg > 0.98f || db > 0.98f) blownB++;

        outLumaB[i] = 0.2126f * dr + 0.7152f * dg + 0.0722f * db;
        outBgrB[i * 3 + 0] = static_cast<uint8_t>(std::clamp(linearToSrgb(db) * 255.0f + 0.5f, 0.0f, 255.0f));
        outBgrB[i * 3 + 1] = static_cast<uint8_t>(std::clamp(linearToSrgb(dg) * 255.0f + 0.5f, 0.0f, 255.0f));
        outBgrB[i * 3 + 2] = static_cast<uint8_t>(std::clamp(linearToSrgb(dr) * 255.0f + 0.5f, 0.0f, 255.0f));
    }
    auto t3 = Clock::now();
    res.latencyB_ms = std::chrono::duration<double, std::milli>(t3 - t2).count();
    res.peakRssB_KB = getPeakRSS_KB();
    res.blownB_px = blownB;

    // -------------------------------------------------------------
    // METRICS CALCULATION
    // -------------------------------------------------------------
    if (origVar > 1e-7) {
        double varA = computeTextureVariance(outLumaA, alpha, W, H);
        double varB = computeTextureVariance(outLumaB, alpha, W, H);
        res.texRetA_pct = (varA / origVar) * 100.0;
        res.texRetB_pct = (varB / origVar) * 100.0;
        res.texGain_pct = res.texRetB_pct - res.texRetA_pct;
    } else {
        // Bald monk negative control
        res.texRetA_pct = 100.0;
        res.texRetB_pct = 100.0;
        res.texGain_pct = 0.0;
    }

    // Skin leakage: pixels where alpha == 0 that changed
    double leakA_sum = 0.0, leakB_sum = 0.0;
    double nonHairCount = 0.0;
    double colorDeltaSum = 0.0, hairCount = 0.0;
    for (int i = 0; i < total; ++i) {
        if (alpha[i] <= 0.001f) {
            nonHairCount += 1.0;
            int diffA = std::abs(outBgrA[i * 3 + 0] - inBgr[i * 3 + 0]) +
                        std::abs(outBgrA[i * 3 + 1] - inBgr[i * 3 + 1]) +
                        std::abs(outBgrA[i * 3 + 2] - inBgr[i * 3 + 2]);
            int diffB = std::abs(outBgrB[i * 3 + 0] - inBgr[i * 3 + 0]) +
                        std::abs(outBgrB[i * 3 + 1] - inBgr[i * 3 + 1]) +
                        std::abs(outBgrB[i * 3 + 2] - inBgr[i * 3 + 2]);
            leakA_sum += (diffA / (3.0 * 255.0));
            leakB_sum += (diffB / (3.0 * 255.0));
        } else {
            hairCount += 1.0;
            float rA = srgbToLinear(outBgrA[i * 3 + 2] / 255.0f);
            float gA = srgbToLinear(outBgrA[i * 3 + 1] / 255.0f);
            float bA = srgbToLinear(outBgrA[i * 3 + 0] / 255.0f);
            float rB = srgbToLinear(outBgrB[i * 3 + 2] / 255.0f);
            float gB = srgbToLinear(outBgrB[i * 3 + 1] / 255.0f);
            float bB = srgbToLinear(outBgrB[i * 3 + 0] / 255.0f);
            OKLab labA = linearRgbToOklab(rA, gA, bA);
            OKLab labB = linearRgbToOklab(rB, gB, bB);
            float dL = labA.L - labB.L;
            float da = labA.a - labB.a;
            float db = labA.b - labB.b;
            colorDeltaSum += std::sqrt(dL * dL + da * da + db * db);
        }
    }
    res.skinLeakA_pct = (nonHairCount > 0.0) ? (leakA_sum / nonHairCount) * 100.0 : 0.0;
    res.skinLeakB_pct = (nonHairCount > 0.0) ? (leakB_sum / nonHairCount) * 100.0 : 0.0;
    res.colorDeltaAB = (hairCount > 0.0) ? (colorDeltaSum / hairCount) : 0.0;

    // Save Output Images
    saveBMP24(outDir + "/out_A_" + name + ".bmp", W, H, outBgrA);
    saveBMP24(outDir + "/out_B_" + name + ".bmp", W, H, outBgrB);

    return res;
}

int main(int argc, char** argv) {
    std::string inDir = (argc > 1) ? argv[1] : "scratch/task043/inputs";
    std::string outDir = (argc > 2) ? argv[2] : "scratch/task043/outputs";

    std::vector<std::string> cases = {
        "portrait_0_curly",
        "portrait_1_male_wavy",
        "portrait_model1_blonde",
        "portrait_model2_long_straight",
        "portrait_model3_wavy_curls",
        "portrait_model4_messy_curls",
        "portrait_model6_fringe_bangs",
        "portrait_monk_bald_neg"
    };

    std::cout << ">>> STARTING ISOLATED A/B BENCHMARK HARNESS <<<" << std::endl;
    std::cout << "Input Dir: " << inDir << std::endl;
    std::cout << "Output Dir: " << outDir << std::endl;

    std::vector<BenchResult> results;
    for (const auto& c : cases) {
        std::cout << "Processing " << c << "..." << std::flush;
        BenchResult r = runCase(c, inDir, outDir);
        results.push_back(r);
        std::cout << " Done. (A: " << r.latencyA_ms << "ms, B: " << r.latencyB_ms
                  << "ms, TexGain: " << r.texGain_pct << "%)" << std::endl;
    }

    // Write CSV Output
    std::ofstream csv(outDir + "/bench_results.csv");
    csv << "case_name,resolution,latency_A_ms,latency_B_ms,peak_rss_A_kb,peak_rss_B_kb,"
        << "tex_ret_A_pct,tex_ret_B_pct,tex_gain_pct,blown_A_px,blown_B_px,"
        << "skin_leak_A_pct,skin_leak_B_pct,oklab_delta_AB\n";

    for (const auto& r : results) {
        csv << r.caseName << "," << r.width << "x" << r.height << ","
            << r.latencyA_ms << "," << r.latencyB_ms << ","
            << r.peakRssA_KB << "," << r.peakRssB_KB << ","
            << r.texRetA_pct << "," << r.texRetB_pct << ","
            << r.texGain_pct << "," << r.blownA_px << "," << r.blownB_px << ","
            << r.skinLeakA_pct << "," << r.skinLeakB_pct << ","
            << r.colorDeltaAB << "\n";
    }
    csv.close();

    // Write JSON Output
    std::ofstream js(outDir + "/bench_results.json");
    js << "[\n";
    for (size_t i = 0; i < results.size(); ++i) {
        const auto& r = results[i];
        js << "  {\n"
           << "    \"case_name\": \"" << r.caseName << "\",\n"
           << "    \"resolution\": \"" << r.width << "x" << r.height << "\",\n"
           << "    \"latency_A_ms\": " << r.latencyA_ms << ",\n"
           << "    \"latency_B_ms\": " << r.latencyB_ms << ",\n"
           << "    \"peak_rss_A_kb\": " << r.peakRssA_KB << ",\n"
           << "    \"peak_rss_B_kb\": " << r.peakRssB_KB << ",\n"
           << "    \"tex_ret_A_pct\": " << r.texRetA_pct << ",\n"
           << "    \"tex_ret_B_pct\": " << r.texRetB_pct << ",\n"
           << "    \"tex_gain_pct\": " << r.texGain_pct << ",\n"
           << "    \"blown_A_px\": " << r.blownA_px << ",\n"
           << "    \"blown_B_px\": " << r.blownB_px << ",\n"
           << "    \"skin_leak_A_pct\": " << r.skinLeakA_pct << ",\n"
           << "    \"skin_leak_B_pct\": " << r.skinLeakB_pct << ",\n"
           << "    \"oklab_delta_AB\": " << r.colorDeltaAB << "\n"
           << "  }" << (i + 1 < results.size() ? ",\n" : "\n");
    }
    js << "]\n";
    js.close();

    std::cout << ">>> BENCHMARK EXECUTION COMPLETE <<<" << std::endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>

// Include mathematical structures
struct FrameGeometry {
    int width = 960;
    int height = 1280;
    inline size_t totalPixels() const { return static_cast<size_t>(width) * height; }
};

// 1. Soft Chroma Compression from hair_v2_color.cpp
void softChromaCompress_v1(float& r, float& g, float& b, float maxChroma = 0.95f) {
    float maxC = std::max(r, std::max(g, b));
    float minC = std::min(r, std::min(g, b));
    float chroma = maxC - minC;
    float knee = maxChroma * 0.75f;
    if (chroma > knee) {
        float scale = (knee + (maxChroma - knee) * std::tanh((chroma - knee) / (maxChroma - knee + 1e-6f))) / (chroma + 1e-6f);
        float luma = 0.2126f * r + 0.7152f * g + 0.0722f * b;
        r = luma + (r - luma) * scale;
        g = luma + (g - luma) * scale;
        b = luma + (b - luma) * scale;
    }
}

void hardClamp_c2(float& r, float& g, float& b) {
    r = std::clamp(r, 0.0f, 1.0f);
    g = std::clamp(g, 0.0f, 1.0f);
    b = std::clamp(b, 0.0f, 1.0f);
}

// 2. Axial Vector Regularization from hair_v2_flow_regularizer.cpp
void regularizeFlow_v1(const float* thetaIn, const float* coherence, float* thetaOut, int W, int H) {
    const int radius = 2;
    for (int y = radius; y < H - radius; ++y) {
        for (int x = radius; x < W - radius; ++x) {
            float sumU = 0.0f;
            float sumV = 0.0f;
            float sumW = 0.0f;
            for (int dy = -radius; dy <= radius; ++dy) {
                for (int dx = -radius; dx <= radius; ++dx) {
                    int idx = (y + dy) * W + (x + dx);
                    float th = thetaIn[idx];
                    float c = coherence[idx];
                    sumU += std::cos(2.0f * th) * c;
                    sumV += std::sin(2.0f * th) * c;
                    sumW += c;
                }
            }
            int outIdx = y * W + x;
            if (sumW > 1e-4f) {
                thetaOut[outIdx] = 0.5f * std::atan2(sumV / sumW, sumU / sumW);
                if (thetaOut[outIdx] < 0.0f) thetaOut[outIdx] += 3.14159265f;
            } else {
                thetaOut[outIdx] = thetaIn[outIdx];
            }
        }
    }
}

void regularizeFlow_c2(const float* thetaIn, float* thetaOut, int W, int H) {
    const int radius = 2;
    float weight = 1.0f / 25.0f;
    for (int y = radius; y < H - radius; ++y) {
        for (int x = radius; x < W - radius; ++x) {
            float sum = 0.0f;
            for (int dy = -radius; dy <= radius; ++dy) {
                for (int dx = -radius; dx <= radius; ++dx) {
                    sum += thetaIn[(y + dy) * W + (x + dx)];
                }
            }
            thetaOut[y * W + x] = sum * weight;
        }
    }
}

// 3. Dual-Lobe Specular from hair_v2_specular.cpp
void computeSpecular_v1(const float* tx, const float* ty, float* outSheen, int count, float Lx, float Ly) {
    const float a1 = 3.0f * 0.0174532925f;
    const float a2 = -6.0f * 0.0174532925f;
    const float cosA1 = std::cos(a1), sinA1 = std::sin(a1);
    const float cosA2 = std::cos(a2), sinA2 = std::sin(a2);

    for (int i = 0; i < count; ++i) {
        float cosTd = tx[i] * Lx + ty[i] * Ly;
        float sinTd = std::sqrt(std::max(0.0f, 1.0f - cosTd * cosTd));
        float t1 = std::max(0.0f, sinTd * cosA1 - cosTd * sinA1);
        float t2 = std::max(0.0f, sinTd * cosA2 - cosTd * sinA2);
        outSheen[i] = 0.35f * std::pow(t1, 32.0f) + 0.15f * std::pow(t2, 8.0f);
    }
}

void computeSpecular_c2(const float* tx, const float* ty, float* outSheen, int count, float Lx, float Ly) {
    for (int i = 0; i < count; ++i) {
        float cosTd = tx[i] * Lx + ty[i] * Ly;
        float sinTd = std::sqrt(std::max(0.0f, 1.0f - cosTd * cosTd));
        outSheen[i] = 0.40f * std::pow(sinTd, 16.0f);
    }
}

int main() {
    FrameGeometry geom;
    geom.width = 960;
    geom.height = 1280;
    size_t N = geom.totalPixels();

    std::cout << "================================================================" << std::endl;
    std::cout << "CONVERT2 NATIVE HARDWARE BENCHMARK: V1 CANDIDATES VS CONVERT2 C2" << std::endl;
    std::cout << "Target Resolution: " << geom.width << "x" << geom.height << " (" << N << " pixels)" << std::endl;
    std::cout << "================================================================" << std::endl;

    // Allocate synthetic test buffers
    std::vector<float> r(N, 1.35f), g(N, 0.75f), b(N, 1.60f);
    std::vector<float> thetaIn(N, 1.25f), coherence(N, 0.75f), thetaOut(N, 0.0f);
    std::vector<float> tx(N, 0.315f), ty(N, 0.949f), sheen(N, 0.0f);

    // Warmup
    hardClamp_c2(r[0], g[0], b[0]);
    softChromaCompress_v1(r[0], g[0], b[0]);

    // Benchmark 1: Soft Chroma Compress vs Hard Clamp
    {
        auto t0 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < N; ++i) {
            float tr = r[i], tg = g[i], tb = b[i];
            hardClamp_c2(tr, tg, tb);
        }
        auto t1 = std::chrono::high_resolution_clock::now();
        double dt_c2_chroma = std::chrono::duration<double, std::milli>(t1 - t0).count();

        t0 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < N; ++i) {
            float tr = r[i], tg = g[i], tb = b[i];
            softChromaCompress_v1(tr, tg, tb);
        }
        t1 = std::chrono::high_resolution_clock::now();
        double dt_v1_chroma = std::chrono::duration<double, std::milli>(t1 - t0).count();

        std::cout << "BENCHMARK_1_CHROMA:" << std::endl;
        std::cout << "  C2_HardClamp_Latency_ms=" << dt_c2_chroma << std::endl;
        std::cout << "  V1_SoftCompress_Latency_ms=" << dt_v1_chroma << std::endl;
        std::cout << "  Chroma_Overhead_Ratio=" << (dt_v1_chroma / dt_c2_chroma) << std::endl;
    }

    // Benchmark 2: Flow Regularization (Axial double angle vs naive)
    {
        auto t0 = std::chrono::high_resolution_clock::now();
        regularizeFlow_c2(thetaIn.data(), thetaOut.data(), geom.width, geom.height);
        auto t1 = std::chrono::high_resolution_clock::now();
        double dt_c2_flow = std::chrono::duration<double, std::milli>(t1 - t0).count();

        t0 = std::chrono::high_resolution_clock::now();
        regularizeFlow_v1(thetaIn.data(), coherence.data(), thetaOut.data(), geom.width, geom.height);
        t1 = std::chrono::high_resolution_clock::now();
        double dt_v1_flow = std::chrono::duration<double, std::milli>(t1 - t0).count();

        std::cout << "BENCHMARK_2_FLOW_REGULARIZATION:" << std::endl;
        std::cout << "  C2_NaiveSmooth_Latency_ms=" << dt_c2_flow << std::endl;
        std::cout << "  V1_AxialVector_Latency_ms=" << dt_v1_flow << std::endl;
        std::cout << "  Flow_Overhead_Ratio=" << (dt_v1_flow / dt_c2_flow) << std::endl;
    }

    // Benchmark 3: Specular Sheen (Dual-Lobe vs Single-Lobe)
    {
        auto t0 = std::chrono::high_resolution_clock::now();
        computeSpecular_c2(tx.data(), ty.data(), sheen.data(), N, 0.0f, -0.894f);
        auto t1 = std::chrono::high_resolution_clock::now();
        double dt_c2_spec = std::chrono::duration<double, std::milli>(t1 - t0).count();

        t0 = std::chrono::high_resolution_clock::now();
        computeSpecular_v1(tx.data(), ty.data(), sheen.data(), N, 0.0f, -0.894f);
        t1 = std::chrono::high_resolution_clock::now();
        double dt_v1_spec = std::chrono::duration<double, std::milli>(t1 - t0).count();

        std::cout << "BENCHMARK_3_SPECULAR_SHEEN:" << std::endl;
        std::cout << "  C2_SingleLobe_Latency_ms=" << dt_c2_spec << std::endl;
        std::cout << "  V1_DualLobe_Latency_ms=" << dt_v1_spec << std::endl;
        std::cout << "  Specular_Overhead_Ratio=" << (dt_v1_spec / dt_c2_spec) << std::endl;
    }

    std::cout << "BENCHMARK_COMPLETED_SUCCESSFULLY" << std::endl;
    return 0;
}

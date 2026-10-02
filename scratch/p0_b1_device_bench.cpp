#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>
#include <omp.h>
#include <net.h>
#include <mat.h>

using Clock = std::chrono::high_resolution_clock;

struct TimingStats {
    std::vector<double> bisenet_times;
    std::vector<double> adaptive_seed_times;
    std::vector<double> hat_resolver_times;
    std::vector<double> trimap_times;
    std::vector<double> guided_times;
    std::vector<double> affinity_times;
    std::vector<double> protection_times;
    std::vector<double> ear_resolver_times;
    std::vector<double> refinement_times;
    std::vector<double> total_p0b1_times;
    std::vector<double> total_haircolor_times;
};

static double percentile(std::vector<double> v, double p) {
    if (v.empty()) return 0.0;
    std::sort(v.begin(), v.end());
    size_t idx = static_cast<size_t>(p * (v.size() - 1));
    return v[idx];
}

static size_t getPeakRSS_KB() {
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
}

// Box filter for Fast Guided Filter
static void boxFilter2D(const float* src, float* dst, int w, int h, int r) {
    std::vector<float> temp(w * h, 0.0f);

    #pragma omp parallel for schedule(static, 16)
    for (int y = 0; y < h; ++y) {
        float sum = 0.0f;
        for (int x = -r; x <= r; ++x) {
            int cx = std::clamp(x, 0, w - 1);
            sum += src[y * w + cx];
        }
        temp[y * w] = sum;
        for (int x = 1; x < w; ++x) {
            int prev = std::clamp(x - r - 1, 0, w - 1);
            int next = std::clamp(x + r, 0, w - 1);
            sum += src[y * w + next] - src[y * w + prev];
            temp[y * w + x] = sum;
        }
    }

    float norm = 1.0f / ((2 * r + 1) * (2 * r + 1));
    #pragma omp parallel for schedule(static, 16)
    for (int x = 0; x < w; ++x) {
        float sum = 0.0f;
        for (int y = -r; y <= r; ++y) {
            int cy = std::clamp(y, 0, h - 1);
            sum += temp[cy * w + x];
        }
        dst[x] = sum * norm;
        for (int y = 1; y < h; ++y) {
            int prev = std::clamp(y - r - 1, 0, h - 1);
            int next = std::clamp(y + r, 0, h - 1);
            sum += temp[next * w + x] - temp[prev * w + x];
            dst[y * w + x] = sum * norm;
        }
    }
}

// Bilinear resize helper
static void resizeLinear(const float* src, int sw, int sh, float* dst, int dw, int dh) {
    #pragma omp parallel for schedule(static, 16)
    for (int dy = 0; dy < dh; ++dy) {
        float sy = dy * (float)sh / dh;
        int y0 = std::clamp((int)sy, 0, sh - 1);
        int y1 = std::clamp(y0 + 1, 0, sh - 1);
        float fy = sy - y0;

        for (int dx = 0; dx < dw; ++dx) {
            float sx = dx * (float)sw / dw;
            int x0 = std::clamp((int)sx, 0, sw - 1);
            int x1 = std::clamp(x0 + 1, 0, sw - 1);
            float fx = sx - x0;

            float v00 = src[y0 * sw + x0];
            float v10 = src[y0 * sw + x1];
            float v01 = src[y1 * sw + x0];
            float v11 = src[y1 * sw + x1];

            float v = (1.0f - fx) * (1.0f - fy) * v00 +
                      fx * (1.0f - fy) * v10 +
                      (1.0f - fx) * fy * v01 +
                      fx * fy * v11;
            dst[dy * dw + dx] = v;
        }
    }
}

int main(int argc, char** argv) {
    std::string modelDir = (argc > 1) ? argv[1] : "/data/local/tmp";
    std::string paramPath = modelDir + "/bisenet_face_19.param";
    std::string binPath = modelDir + "/bisenet_face_19.bin";

    std::cout << "=== SAMSUNG GALAXY DEVICE BENCHMARK: P0-B.1 GENERALIZATION ENGINE ===" << std::endl;

    ncnn::Net bisenet;
    bisenet.opt.use_vulkan_compute = false;
    bisenet.opt.num_threads = 4;
    bisenet.opt.use_fp16_packed = true;
    bisenet.opt.use_fp16_storage = true;
    bisenet.opt.use_fp16_arithmetic = true;

    if (bisenet.load_param(paramPath.c_str()) != 0 || bisenet.load_model(binPath.c_str()) != 0) {
        std::cerr << "Failed to load BiSeNet NCNN model from " << modelDir << std::endl;
        return 1;
    }
    std::cout << "BiSeNet NCNN loaded successfully." << std::endl;

    const int W = 960;
    const int H = 1280;
    std::cout << "Target Resolution: " << W << "x" << H << " (" << (W * H / 1e6) << " MP)" << std::endl;

    // Synthetic realistic image buffer (Simulates portrait with hair, face, ears, background)
    std::vector<uint32_t> rgba(W * H);
    #pragma omp parallel for schedule(static, 32)
    for (int y = 0; y < H; ++y) {
        float ny = (float)y / H;
        for (int x = 0; x < W; ++x) {
            float nx = (float)x / W;
            uint8_t r = 180, g = 180, b = 180;
            if (ny < 0.35f && nx > 0.2f && nx < 0.8f) {
                // Hair
                r = 45; g = 38; b = 32;
            } else if (ny >= 0.30f && ny <= 0.70f && nx > 0.3f && nx < 0.7f) {
                // Face skin
                r = 220; g = 185; b = 165;
            } else if (ny >= 0.45f && ny <= 0.60f && ((nx >= 0.25f && nx <= 0.32f) || (nx >= 0.68f && nx <= 0.75f))) {
                // Ears
                r = 210; g = 175; b = 155;
            }
            rgba[y * W + x] = (255 << 24) | (b << 16) | (g << 8) | r;
        }
    }

    TimingStats stats;
    const int ITERATIONS = 50;
    std::cout << "Running " << ITERATIONS << " benchmark iterations..." << std::endl;

    for (int iter = 0; iter < ITERATIONS + 1; ++iter) {
        auto t_start = Clock::now();

        // 1. BiSeNet Face Parsing Inference (512x512)
        auto t0 = Clock::now();
        ncnn::Mat in_mat = ncnn::Mat::from_pixels_resize(
            reinterpret_cast<const unsigned char*>(rgba.data()),
            ncnn::Mat::PIXEL_RGBA2RGB,
            W, H, 512, 512
        );
        const float mean_vals[3] = {123.675f, 116.28f, 103.53f};
        const float norm_vals[3] = {1.0f / 58.395f, 1.0f / 57.12f, 1.0f / 57.375f};
        in_mat.substract_mean_normalize(mean_vals, norm_vals);

        ncnn::Extractor ex = bisenet.create_extractor();
        ex.input("in0", in_mat);
        ncnn::Mat out_mat;
        ex.extract("out0", out_mat);

        std::vector<uint8_t> labels_512(512 * 512, 0);
        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < 512 * 512; ++i) {
            float max_s = -1e9f;
            int best_c = 0;
            for (int c = 0; c < 19; ++c) {
                float s = out_mat.channel(c)[i];
                if (s > max_s) { max_s = s; best_c = c; }
            }
            labels_512[i] = (uint8_t)best_c;
        }
        auto t1 = Clock::now();

        // 2. FIX #1: Adaptive Hair Seed Statistics Calculation
        float seed_mean_r = 0.0f, seed_mean_g = 0.0f, seed_mean_b = 0.0f;
        int seed_count = 0;
        #pragma omp parallel for reduction(+:seed_mean_r, seed_mean_g, seed_mean_b, seed_count) schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            int sy = y * 512 / H;
            for (int x = 0; x < W; ++x) {
                int sx = x * 512 / W;
                if (labels_512[sy * 512 + sx] == 17) {
                    uint32_t px = rgba[y * W + x];
                    seed_mean_r += (px & 0xFF);
                    seed_mean_g += ((px >> 8) & 0xFF);
                    seed_mean_b += ((px >> 16) & 0xFF);
                    seed_count++;
                }
            }
        }
        if (seed_count > 0) {
            seed_mean_r /= seed_count;
            seed_mean_g /= seed_count;
            seed_mean_b /= seed_count;
        }
        auto t2 = Clock::now();

        // 3. FIX #2: Hair / Hat Disambiguation (Class 18)
        std::vector<uint8_t> eff_hair(W * H, 0);
        #pragma omp parallel for schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            int sy = y * 512 / H;
            for (int x = 0; x < W; ++x) {
                int sx = x * 512 / W;
                uint8_t lbl = labels_512[sy * 512 + sx];
                if (lbl == 17) {
                    eff_hair[y * W + x] = 1;
                } else if (lbl == 18) {
                    // Check color consistency with seed
                    uint32_t px = rgba[y * W + x];
                    float dr = (px & 0xFF) - seed_mean_r;
                    float dg = ((px >> 8) & 0xFF) - seed_mean_g;
                    float db = ((px >> 16) & 0xFF) - seed_mean_b;
                    float d_col = std::sqrt(dr*dr + dg*dg + db*db);
                    if (d_col < 35.0f && y < H * 0.45f) {
                        eff_hair[y * W + x] = 1; // Resolved as hair
                    }
                }
            }
        }
        auto t3 = Clock::now();

        // 4. Semantic Trimap Generation
        std::vector<float> trimap(W * H, 0.5f);
        #pragma omp parallel for schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            int sy = y * 512 / H;
            for (int x = 0; x < W; ++x) {
                int sx = x * 512 / W;
                uint8_t lbl = labels_512[sy * 512 + sx];
                if (eff_hair[y * W + x] == 1) {
                    trimap[y * W + x] = 1.0f;
                } else if (lbl == 1 || lbl == 4 || lbl == 5 || lbl == 10 || lbl == 14 || lbl == 16) {
                    trimap[y * W + x] = 0.0f;
                }
            }
        }
        auto t4 = Clock::now();

        // 5. Fast Guided Filter Refinement (scale=2)
        const int sW = W / 2;
        const int sH = H / 2;
        std::vector<float> guide_full(W * H);
        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < W * H; ++i) {
            uint32_t c = rgba[i];
            guide_full[i] = (0.299f * (c & 0xFF) + 0.587f * ((c >> 8) & 0xFF) + 0.114f * ((c >> 16) & 0xFF)) / 255.0f;
        }

        std::vector<float> g_sub(sW * sH), p_sub(sW * sH);
        resizeLinear(guide_full.data(), W, H, g_sub.data(), sW, sH);
        resizeLinear(trimap.data(), W, H, p_sub.data(), sW, sH);

        const int sub_r = 6;
        std::vector<float> mean_I(sW * sH), mean_p(sW * sH), mean_Ip(sW * sH), mean_II(sW * sH);
        std::vector<float> g_sub_sq(sW * sH), gp_sub(sW * sH);

        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < sW * sH; ++i) {
            g_sub_sq[i] = g_sub[i] * g_sub[i];
            gp_sub[i] = g_sub[i] * p_sub[i];
        }

        boxFilter2D(g_sub.data(), mean_I.data(), sW, sH, sub_r);
        boxFilter2D(p_sub.data(), mean_p.data(), sW, sH, sub_r);
        boxFilter2D(gp_sub.data(), mean_Ip.data(), sW, sH, sub_r);
        boxFilter2D(g_sub_sq.data(), mean_II.data(), sW, sH, sub_r);

        std::vector<float> a_sub(sW * sH), b_sub(sW * sH);
        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < sW * sH; ++i) {
            float var_I = mean_II[i] - mean_I[i] * mean_I[i];
            float cov_Ip = mean_Ip[i] - mean_I[i] * mean_p[i];
            float a = cov_Ip / (var_I + 1e-3f);
            float b = mean_p[i] - a * mean_I[i];
            a_sub[i] = a;
            b_sub[i] = b;
        }

        std::vector<float> mean_a_sub(sW * sH), mean_b_sub(sW * sH);
        boxFilter2D(a_sub.data(), mean_a_sub.data(), sW, sH, sub_r);
        boxFilter2D(b_sub.data(), mean_b_sub.data(), sW, sH, sub_r);

        std::vector<float> mean_a(W * H), mean_b(W * H);
        resizeLinear(mean_a_sub.data(), sW, sH, mean_a.data(), W, H);
        resizeLinear(mean_b_sub.data(), sW, sH, mean_b.data(), W, H);

        std::vector<float> alpha_guided(W * H);
        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < W * H; ++i) {
            float q = mean_a[i] * guide_full[i] + mean_b[i];
            alpha_guided[i] = std::clamp(q, 0.0f, 1.0f);
        }
        auto t5 = Clock::now();

        // 6. Local Color Affinity Weighting
        std::vector<float> alpha_affinity = alpha_guided;
        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < W * H; ++i) {
            if (trimap[i] == 0.5f) {
                uint32_t px = rgba[i];
                float dr = (px & 0xFF) - seed_mean_r;
                float dg = ((px >> 8) & 0xFF) - seed_mean_g;
                float db = ((px >> 16) & 0xFF) - seed_mean_b;
                float d_col = std::sqrt(dr*dr + dg*dg + db*db);
                float w_col = std::exp(-d_col / 40.0f);
                alpha_affinity[i] = 0.65f * alpha_guided[i] + 0.35f * w_col;
            }
        }
        auto t6 = Clock::now();

        // 7. Strict Anatomical Semantic Protection
        #pragma omp parallel for schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            int sy = y * 512 / H;
            for (int x = 0; x < W; ++x) {
                int sx = x * 512 / W;
                uint8_t lbl = labels_512[sy * 512 + sx];
                if (lbl == 1 || lbl == 4 || lbl == 5 || lbl == 10 || lbl == 14 || lbl == 16) {
                    alpha_affinity[y * W + x] = 0.0f;
                }
            }
        }
        auto t7 = Clock::now();

        // 8. FIX #3: Ear Occlusion Resolver
        #pragma omp parallel for schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            int sy = y * 512 / H;
            for (int x = 0; x < W; ++x) {
                int sx = x * 512 / W;
                uint8_t lbl = labels_512[sy * 512 + sx];
                if (lbl == 7 || lbl == 8) {
                    uint32_t px = rgba[y * W + x];
                    float dr = (px & 0xFF) - seed_mean_r;
                    float dg = ((px >> 8) & 0xFF) - seed_mean_g;
                    float db = ((px >> 16) & 0xFF) - seed_mean_b;
                    float d_col = std::sqrt(dr*dr + dg*dg + db*db);
                    if (d_col < 35.0f && alpha_affinity[y * W + x] > 0.3f) {
                        // Hair over ear: preserve continuous alpha
                        alpha_affinity[y * W + x] = std::clamp(alpha_affinity[y * W + x], 0.0f, 1.0f);
                    } else {
                        // Bare ear skin: protect
                        alpha_affinity[y * W + x] = 0.0f;
                    }
                }
            }
        }
        auto t8 = Clock::now();

        // 9. Hairline Cosine Softening & Recolor Composite
        std::vector<uint32_t> out_recolored(W * H);
        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < W * H; ++i) {
            float a = alpha_affinity[i] * 0.80f;
            uint32_t orig = rgba[i];
            float lum = guide_full[i];
            float scale = std::clamp(0.35f + 0.65f * lum, 0.0f, 1.0f);
            float dye_r = 218.0f * scale;
            float dye_g = 138.0f * scale;
            float dye_b = 132.0f * scale;

            float r = (orig & 0xFF) * (1.0f - a) + dye_r * a;
            float g = ((orig >> 8) & 0xFF) * (1.0f - a) + dye_g * a;
            float b = ((orig >> 16) & 0xFF) * (1.0f - a) + dye_b * a;
            out_recolored[i] = (255 << 24) | ((uint8_t)b << 16) | ((uint8_t)g << 8) | (uint8_t)r;
        }
        auto t9 = Clock::now();

        if (iter > 0) {
            stats.bisenet_times.push_back(std::chrono::duration<double, std::milli>(t1 - t0).count());
            stats.adaptive_seed_times.push_back(std::chrono::duration<double, std::milli>(t2 - t1).count());
            stats.hat_resolver_times.push_back(std::chrono::duration<double, std::milli>(t3 - t2).count());
            stats.trimap_times.push_back(std::chrono::duration<double, std::milli>(t4 - t3).count());
            stats.guided_times.push_back(std::chrono::duration<double, std::milli>(t5 - t4).count());
            stats.affinity_times.push_back(std::chrono::duration<double, std::milli>(t6 - t5).count());
            stats.protection_times.push_back(std::chrono::duration<double, std::milli>(t7 - t6).count());
            stats.ear_resolver_times.push_back(std::chrono::duration<double, std::milli>(t8 - t7).count());
            stats.refinement_times.push_back(std::chrono::duration<double, std::milli>(t9 - t8).count());
            stats.total_p0b1_times.push_back(std::chrono::duration<double, std::milli>(t9 - t1).count());
            stats.total_haircolor_times.push_back(std::chrono::duration<double, std::milli>(t9 - t_start).count());
        }
    }

    std::cout << "\n=== BENCHMARK RESULTS (P0-B.1 on Device) ===" << std::endl;
    std::cout << "STAGE                               | P50 (ms) | P95 (ms) | P99 (ms)" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    printf("1. BiSeNet Inference                | %7.2f  | %7.2f  | %7.2f\n", percentile(stats.bisenet_times, 0.50), percentile(stats.bisenet_times, 0.95), percentile(stats.bisenet_times, 0.99));
    printf("2. Adaptive Hair Seed Stats         | %7.2f  | %7.2f  | %7.2f\n", percentile(stats.adaptive_seed_times, 0.50), percentile(stats.adaptive_seed_times, 0.95), percentile(stats.adaptive_seed_times, 0.99));
    printf("3. Hair / Hat Resolver              | %7.2f  | %7.2f  | %7.2f\n", percentile(stats.hat_resolver_times, 0.50), percentile(stats.hat_resolver_times, 0.95), percentile(stats.hat_resolver_times, 0.99));
    printf("4. Semantic Trimap                  | %7.2f  | %7.2f  | %7.2f\n", percentile(stats.trimap_times, 0.50), percentile(stats.trimap_times, 0.95), percentile(stats.trimap_times, 0.99));
    printf("5. Fast Guided Filter (scale=2)     | %7.2f  | %7.2f  | %7.2f\n", percentile(stats.guided_times, 0.50), percentile(stats.guided_times, 0.95), percentile(stats.guided_times, 0.99));
    printf("6. Local Color Affinity             | %7.2f  | %7.2f  | %7.2f\n", percentile(stats.affinity_times, 0.50), percentile(stats.affinity_times, 0.95), percentile(stats.affinity_times, 0.99));
    printf("7. Semantic Protection              | %7.2f  | %7.2f  | %7.2f\n", percentile(stats.protection_times, 0.50), percentile(stats.protection_times, 0.95), percentile(stats.protection_times, 0.99));
    printf("8. Ear Occlusion Resolver           | %7.2f  | %7.2f  | %7.2f\n", percentile(stats.ear_resolver_times, 0.50), percentile(stats.ear_resolver_times, 0.95), percentile(stats.ear_resolver_times, 0.99));
    printf("9. Hairline Refinement & Composite  | %7.2f  | %7.2f  | %7.2f\n", percentile(stats.refinement_times, 0.50), percentile(stats.refinement_times, 0.95), percentile(stats.refinement_times, 0.99));
    std::cout << "------------------------------------------------------------------" << std::endl;
    printf("TOTAL P0-B.1 MATTING OVERHEAD       | %7.2f  | %7.2f  | %7.2f\n", percentile(stats.total_p0b1_times, 0.50), percentile(stats.total_p0b1_times, 0.95), percentile(stats.total_p0b1_times, 0.99));
    printf("TOTAL HAIR COLOR (FULL PIPELINE)    | %7.2f  | %7.2f  | %7.2f\n", percentile(stats.total_haircolor_times, 0.50), percentile(stats.total_haircolor_times, 0.95), percentile(stats.total_haircolor_times, 0.99));

    size_t rss = getPeakRSS_KB();
    std::cout << "\nSYSTEM METRICS:" << std::endl;
    std::cout << "  Peak RAM (VmHWM): " << (rss / 1024.0) << " MB" << std::endl;

    // Output CSV
    std::ofstream csv(modelDir + "/P0_B1_DEVICE_BENCHMARK.csv");
    csv << "Stage,P50_ms,P95_ms,P99_ms\n";
    csv << "BiSeNet_Inference," << percentile(stats.bisenet_times, 0.50) << "," << percentile(stats.bisenet_times, 0.95) << "," << percentile(stats.bisenet_times, 0.99) << "\n";
    csv << "Adaptive_Hair_Seed," << percentile(stats.adaptive_seed_times, 0.50) << "," << percentile(stats.adaptive_seed_times, 0.95) << "," << percentile(stats.adaptive_seed_times, 0.99) << "\n";
    csv << "Hair_Hat_Resolver," << percentile(stats.hat_resolver_times, 0.50) << "," << percentile(stats.hat_resolver_times, 0.95) << "," << percentile(stats.hat_resolver_times, 0.99) << "\n";
    csv << "Semantic_Trimap," << percentile(stats.trimap_times, 0.50) << "," << percentile(stats.trimap_times, 0.95) << "," << percentile(stats.trimap_times, 0.99) << "\n";
    csv << "Fast_Guided_Filter," << percentile(stats.guided_times, 0.50) << "," << percentile(stats.guided_times, 0.95) << "," << percentile(stats.guided_times, 0.99) << "\n";
    csv << "Local_Color_Affinity," << percentile(stats.affinity_times, 0.50) << "," << percentile(stats.affinity_times, 0.95) << "," << percentile(stats.affinity_times, 0.99) << "\n";
    csv << "Semantic_Protection," << percentile(stats.protection_times, 0.50) << "," << percentile(stats.protection_times, 0.95) << "," << percentile(stats.protection_times, 0.99) << "\n";
    csv << "Ear_Occlusion_Resolver," << percentile(stats.ear_resolver_times, 0.50) << "," << percentile(stats.ear_resolver_times, 0.95) << "," << percentile(stats.ear_resolver_times, 0.99) << "\n";
    csv << "Hairline_Refinement," << percentile(stats.refinement_times, 0.50) << "," << percentile(stats.refinement_times, 0.95) << "," << percentile(stats.refinement_times, 0.99) << "\n";
    csv << "TOTAL_P0B1_MATTING," << percentile(stats.total_p0b1_times, 0.50) << "," << percentile(stats.total_p0b1_times, 0.95) << "," << percentile(stats.total_p0b1_times, 0.99) << "\n";
    csv << "TOTAL_FULL_PIPELINE," << percentile(stats.total_haircolor_times, 0.50) << "," << percentile(stats.total_haircolor_times, 0.95) << "," << percentile(stats.total_haircolor_times, 0.99) << "\n";
    csv.close();

    return 0;
}

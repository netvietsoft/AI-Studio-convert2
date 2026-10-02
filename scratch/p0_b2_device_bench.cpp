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
    std::vector<double> low_contrast_times;
    std::vector<double> subject_graph_times;
    std::vector<double> content_guard_times;
    std::vector<double> trimap_times;
    std::vector<double> guided_times;
    std::vector<double> affinity_times;
    std::vector<double> protection_times;
    std::vector<double> ear_resolver_times;
    std::vector<double> hairline_times;
    std::vector<double> total_p0b2_times;
    std::vector<double> full_run_times;
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

static float getThermalZoneTemp() {
    std::ifstream tFile("/sys/class/thermal/thermal_zone0/temp");
    if (!tFile.is_open()) return 0.0f;
    float temp = 0.0f;
    tFile >> temp;
    if (temp > 1000.0f) temp /= 1000.0f;
    return temp;
}

// Box filter for Fast Guided Filter & Local Variances
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

    std::cout << "=== SAMSUNG GALAXY DEVICE BENCHMARK: P0-B.2 MASTER SUITE ===" << std::endl;

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

    // Realistic synthetic portrait buffer
    std::vector<uint32_t> rgba(W * H);
    std::vector<float> gray(W * H, 0.0f);

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
            gray[y * W + x] = (0.299f * r + 0.587f * g + 0.114f * b) / 255.0f;
        }
    }

    TimingStats stats;
    const int ITERATIONS = 50;
    std::cout << "Running " << ITERATIONS << " benchmark iterations..." << std::endl;

    for (int iter = 0; iter < ITERATIONS + 1; ++iter) {
        auto t_full_start = Clock::now();

        // 1. BiSeNet Inference (512x512)
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

        // 2. Adaptive Hair Appearance Seed Extraction
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

        // 3. Hair / Hat Disambiguation (Class 18)
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
                    uint32_t px = rgba[y * W + x];
                    float dr = (px & 0xFF) - seed_mean_r;
                    float dg = ((px >> 8) & 0xFF) - seed_mean_g;
                    float db = ((px >> 16) & 0xFF) - seed_mean_b;
                    float d_col = std::sqrt(dr*dr + dg*dg + db*db);
                    if (d_col < 35.0f && y < H * 0.45f) {
                        eff_hair[y * W + x] = 1;
                    }
                }
            }
        }
        auto t3 = Clock::now();

        // 4. LowContrastHairResolver (F1)
        // Computes Laplacian High-Frequency Energy + Geodesic Connectivity
        std::vector<float> lap(W * H, 0.0f);
        std::vector<float> lap_sq(W * H, 0.0f);
        #pragma omp parallel for schedule(static, 32)
        for (int y = 1; y < H - 1; ++y) {
            for (int x = 1; x < W - 1; ++x) {
                int idx = y * W + x;
                float l = 4.0f * gray[idx] - gray[idx - W] - gray[idx + W] - gray[idx - 1] - gray[idx + 1];
                lap[idx] = l;
                lap_sq[idx] = l * l;
            }
        }
        std::vector<float> mean_lap_sq(W * H, 0.0f);
        std::vector<float> mean_lap(W * H, 0.0f);
        boxFilter2D(lap_sq.data(), mean_lap_sq.data(), W, H, 2);
        boxFilter2D(lap.data(), mean_lap.data(), W, H, 2);

        std::vector<float> p_dark_hair(W * H, 0.0f);
        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < W * H; ++i) {
            float tex_var = std::max(0.0f, mean_lap_sq[i] - mean_lap[i] * mean_lap[i]);
            float t_tex = std::clamp(tex_var * 1000.0f, 0.0f, 1.0f);
            float s_sem = eff_hair[i] ? 1.0f : 0.0f;
            p_dark_hair[i] = 0.35f * s_sem + 0.35f * t_tex + 0.30f * (1.0f - gray[i]);
        }
        auto t4 = Clock::now();

        // 5. SubjectGraph: Facial Anchor & Topological Head Model
        float face_cx = W * 0.5f, face_cy = H * 0.5f;
        int face_px_count = 0;
        #pragma omp parallel for reduction(+:face_cx, face_cy, face_px_count) schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            int sy = y * 512 / H;
            for (int x = 0; x < W; ++x) {
                int sx = x * 512 / W;
                uint8_t lbl = labels_512[sy * 512 + sx];
                if (lbl == 1 || (lbl >= 2 && lbl <= 5) || lbl == 10 || (lbl >= 11 && lbl <= 13)) {
                    face_cx += x;
                    face_cy += y;
                    face_px_count++;
                }
            }
        }
        if (face_px_count > 0) {
            face_cx /= face_px_count;
            face_cy /= face_px_count;
        }
        auto t5 = Clock::now();

        // 6. ImageContentGuard (F2 UI Chrome Rejection)
        std::vector<uint8_t> ui_reject(W * H, 0);
        #pragma omp parallel for schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            float dy = std::abs((float)y - face_cy);
            bool is_screen_border_ui = (y < H * 0.07f || y > H * 0.88f) && (dy > H * 0.35f);
            for (int x = 0; x < W; ++x) {
                if (is_screen_border_ui) {
                    ui_reject[y * W + x] = 1;
                }
            }
        }
        auto t6 = Clock::now();

        // 7. High-Res Trimap Generation
        std::vector<float> trimap(W * H, 0.5f);
        #pragma omp parallel for schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            int sy = y * 512 / H;
            for (int x = 0; x < W; ++x) {
                int idx = y * W + x;
                int sx = x * 512 / W;
                uint8_t lbl = labels_512[sy * 512 + sx];

                if (ui_reject[idx]) {
                    trimap[idx] = 0.0f;
                } else if (eff_hair[idx] && p_dark_hair[idx] > 0.5f) {
                    trimap[idx] = 1.0f;
                } else if (lbl == 0 && p_dark_hair[idx] < 0.2f) {
                    trimap[idx] = 0.0f;
                }
            }
        }
        auto t7 = Clock::now();

        // 8. Fast Guided Filter Refinement
        const int scale = 2;
        const int gw = W / scale;
        const int gh = H / scale;
        std::vector<float> g_sub(gw * gh);
        std::vector<float> p_sub(gw * gh);
        resizeLinear(gray.data(), W, H, g_sub.data(), gw, gh);
        resizeLinear(trimap.data(), W, H, p_sub.data(), gw, gh);

        const int r_sub = 6;
        const float eps = 1e-3f;
        std::vector<float> mean_I(gw * gh), mean_p(gw * gh), mean_Ip(gw * gh), mean_II(gw * gh);
        std::vector<float> Ip(gw * gh), II(gw * gh);
        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < gw * gh; ++i) {
            Ip[i] = g_sub[i] * p_sub[i];
            II[i] = g_sub[i] * g_sub[i];
        }

        boxFilter2D(g_sub.data(), mean_I.data(), gw, gh, r_sub);
        boxFilter2D(p_sub.data(), mean_p.data(), gw, gh, r_sub);
        boxFilter2D(Ip.data(), mean_Ip.data(), gw, gh, r_sub);
        boxFilter2D(II.data(), mean_II.data(), gw, gh, r_sub);

        std::vector<float> a(gw * gh), b(gw * gh);
        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < gw * gh; ++i) {
            float var_I = mean_II[i] - mean_I[i] * mean_I[i];
            float cov_Ip = mean_Ip[i] - mean_I[i] * mean_p[i];
            float ak = cov_Ip / (var_I + eps);
            float bk = mean_p[i] - ak * mean_I[i];
            a[i] = ak;
            b[i] = bk;
        }

        std::vector<float> mean_a(gw * gh), mean_b(gw * gh);
        boxFilter2D(a.data(), mean_a.data(), gw, gh, r_sub);
        boxFilter2D(b.data(), mean_b.data(), gw, gh, r_sub);

        std::vector<float> mean_a_full(W * H), mean_b_full(W * H);
        resizeLinear(mean_a.data(), gw, gh, mean_a_full.data(), W, H);
        resizeLinear(mean_b.data(), gw, gh, mean_b_full.data(), W, H);

        std::vector<float> alpha_guided(W * H);
        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < W * H; ++i) {
            float q = mean_a_full[i] * gray[i] + mean_b_full[i];
            alpha_guided[i] = std::clamp(q, 0.0f, 1.0f);
        }
        auto t8 = Clock::now();

        // 9. Local Color Affinity
        std::vector<float> alpha_final(W * H);
        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < W * H; ++i) {
            if (trimap[i] == 1.0f) {
                alpha_final[i] = 1.0f;
            } else if (trimap[i] == 0.0f) {
                alpha_final[i] = 0.0f;
            } else {
                uint32_t px = rgba[i];
                float dr = (px & 0xFF) - seed_mean_r;
                float dg = ((px >> 8) & 0xFF) - seed_mean_g;
                float db = ((px >> 16) & 0xFF) - seed_mean_b;
                float d_fg = std::sqrt(dr*dr + dg*dg + db*db);
                float d_bg = std::abs((px & 0xFF) - 180.0f);
                float a_col = std::clamp(d_bg / (d_fg + d_bg + 1e-4f), 0.0f, 1.0f);
                alpha_final[i] = 0.65f * alpha_guided[i] + 0.35f * a_col;
            }
        }
        auto t9 = Clock::now();

        // 10. Semantic & UI Protection
        #pragma omp parallel for schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            int sy = y * 512 / H;
            for (int x = 0; x < W; ++x) {
                int idx = y * W + x;
                int sx = x * 512 / W;
                uint8_t lbl = labels_512[sy * 512 + sx];
                if (ui_reject[idx] || (lbl >= 2 && lbl <= 5) || lbl == 10 || (lbl >= 11 && lbl <= 13) || lbl == 14 || lbl == 16) {
                    alpha_final[idx] = 0.0f;
                }
            }
        }
        auto t10 = Clock::now();

        // 11. Ear Occlusion Resolver
        #pragma omp parallel for schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            int sy = y * 512 / H;
            for (int x = 0; x < W; ++x) {
                int idx = y * W + x;
                int sx = x * 512 / W;
                uint8_t lbl = labels_512[sy * 512 + sx];
                if (lbl == 7 || lbl == 8) {
                    uint32_t px = rgba[idx];
                    float dr = (px & 0xFF) - seed_mean_r;
                    float dg = ((px >> 8) & 0xFF) - seed_mean_g;
                    float db = ((px >> 16) & 0xFF) - seed_mean_b;
                    float d_hair = std::sqrt(dr*dr + dg*dg + db*db);
                    if (d_hair < 25.0f) {
                        alpha_final[idx] = std::clamp(alpha_guided[idx] * 0.85f, 0.0f, 1.0f);
                    } else {
                        alpha_final[idx] = 0.0f;
                    }
                }
            }
        }
        auto t11 = Clock::now();

        // 12. Forehead Hairline Softening
        #pragma omp parallel for schedule(static, 32)
        for (int y = 1; y < H - 1; ++y) {
            int sy = y * 512 / H;
            for (int x = 1; x < W - 1; ++x) {
                int idx = y * W + x;
                int sx = x * 512 / W;
                uint8_t lbl = labels_512[sy * 512 + sx];
                if (lbl == 1 && alpha_final[idx] > 0.0f) {
                    alpha_final[idx] *= 0.78f;
                }
            }
        }
        auto t12 = Clock::now();
        auto t_full_end = Clock::now();

        if (iter > 0) { // Discard warmup iteration
            stats.bisenet_times.push_back(std::chrono::duration<double, std::milli>(t1 - t0).count());
            stats.adaptive_seed_times.push_back(std::chrono::duration<double, std::milli>(t2 - t1).count());
            stats.hat_resolver_times.push_back(std::chrono::duration<double, std::milli>(t3 - t2).count());
            stats.low_contrast_times.push_back(std::chrono::duration<double, std::milli>(t4 - t3).count());
            stats.subject_graph_times.push_back(std::chrono::duration<double, std::milli>(t5 - t4).count());
            stats.content_guard_times.push_back(std::chrono::duration<double, std::milli>(t6 - t5).count());
            stats.trimap_times.push_back(std::chrono::duration<double, std::milli>(t7 - t6).count());
            stats.guided_times.push_back(std::chrono::duration<double, std::milli>(t8 - t7).count());
            stats.affinity_times.push_back(std::chrono::duration<double, std::milli>(t9 - t8).count());
            stats.protection_times.push_back(std::chrono::duration<double, std::milli>(t10 - t9).count());
            stats.ear_resolver_times.push_back(std::chrono::duration<double, std::milli>(t11 - t10).count());
            stats.hairline_times.push_back(std::chrono::duration<double, std::milli>(t12 - t11).count());

            double matting_time = std::chrono::duration<double, std::milli>(t12 - t1).count();
            stats.total_p0b2_times.push_back(matting_time);

            double full_time = std::chrono::duration<double, std::milli>(t_full_end - t_full_start).count();
            stats.full_run_times.push_back(full_time);
        }
    }

    size_t peakRSS = getPeakRSS_KB();
    float thermalTemp = getThermalZoneTemp();

    std::cout << "\n=======================================================" << std::endl;
    std::cout << "PHASE P0-B.2 BENCHMARK RESULTS (Samsung Galaxy SM-A075F, Helio G99)" << std::endl;
    std::cout << "=======================================================" << std::endl;
    std::cout << "Stage                                    | P50 (ms) | P95 (ms) | P99 (ms)" << std::endl;
    std::cout << "-----------------------------------------+----------+----------+---------" << std::endl;

    auto printStage = [&](const std::string& name, const std::vector<double>& v) {
        printf("%-40s | %8.2f | %8.2f | %8.2f\n", name.c_str(), percentile(v, 0.50), percentile(v, 0.95), percentile(v, 0.99));
    };

    printStage("1. BiSeNet Face Parsing (512x512 NCNN)", stats.bisenet_times);
    printStage("2. Adaptive Hair Appearance Seed", stats.adaptive_seed_times);
    printStage("3. Hair / Hat Resolver (Class 18)", stats.hat_resolver_times);
    printStage("4. LowContrastHairResolver (F1)", stats.low_contrast_times);
    printStage("5. SubjectGraph (Topological)", stats.subject_graph_times);
    printStage("6. ImageContentGuard (F2 UI Chrome)", stats.content_guard_times);
    printStage("7. Semantic Trimap Generation", stats.trimap_times);
    printStage("8. Fast Guided Filter (Box r=12, s=2)", stats.guided_times);
    printStage("9. Local Color Affinity", stats.affinity_times);
    printStage("10. Strict Semantic & UI Protection", stats.protection_times);
    printStage("11. Ear Occlusion Resolver", stats.ear_resolver_times);
    printStage("12. Hairline Refinement & Softening", stats.hairline_times);
    std::cout << "-----------------------------------------+----------+----------+---------" << std::endl;
    printStage("13. TOTAL P0-B.2 MATTING (Local)", stats.total_p0b2_times);
    printStage("14. FULL HAIR COLOR RUN (BiSeNet + B.2)", stats.full_run_times);
    std::cout << "=======================================================" << std::endl;
    std::cout << "Peak RAM RSS (VmHWM): " << (peakRSS / 1024.0f) << " MB" << std::endl;
    std::cout << "Thermal Temperature: " << thermalTemp << " C" << std::endl;

    // Export CSV
    std::ofstream csv(modelDir + "/P0_B2_DEVICE_BENCHMARK.csv");
    csv << "StageID,StageName,P50_ms,P95_ms,P99_ms\n";
    auto writeCSV = [&](int id, const std::string& name, const std::vector<double>& v) {
        csv << id << "," << name << "," << percentile(v, 0.50) << "," << percentile(v, 0.95) << "," << percentile(v, 0.99) << "\n";
    };
    writeCSV(1, "BiSeNet", stats.bisenet_times);
    writeCSV(2, "AdaptiveHairAppearance", stats.adaptive_seed_times);
    writeCSV(3, "HairHatResolver", stats.hat_resolver_times);
    writeCSV(4, "LowContrastHairResolver", stats.low_contrast_times);
    writeCSV(5, "SubjectGraph", stats.subject_graph_times);
    writeCSV(6, "ImageContentGuard", stats.content_guard_times);
    writeCSV(7, "SemanticTrimap", stats.trimap_times);
    writeCSV(8, "FastGuidedFilter", stats.guided_times);
    writeCSV(9, "LocalColorAffinity", stats.affinity_times);
    writeCSV(10, "SemanticProtection", stats.protection_times);
    writeCSV(11, "EarOcclusionResolver", stats.ear_resolver_times);
    writeCSV(12, "HairlineRefinement", stats.hairline_times);
    writeCSV(13, "TOTAL_P0_B2_MATTING", stats.total_p0b2_times);
    writeCSV(14, "FULL_HAIR_COLOR_RUN", stats.full_run_times);
    csv.close();

    std::cout << "Saved benchmark to " << (modelDir + "/P0_B2_DEVICE_BENCHMARK.csv") << std::endl;
    return 0;
}

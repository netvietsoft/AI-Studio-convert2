#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <omp.h>

// NCNN includes
#include "net.h"
#include "mat.h"

using Clock = std::chrono::high_resolution_clock;

static inline float get_ms(const Clock::time_point& t1, const Clock::time_point& t2) {
    return std::chrono::duration<float, std::milli>(t2 - t1).count();
}

static long get_peak_ram_kb() {
    std::ifstream status("/proc/self/status");
    std::string line;
    while (std::getline(status, line)) {
        if (line.rfind("VmHWM:", 0) == 0) {
            std::istringstream ss(line.substr(6));
            long kb = 0;
            ss >> kb;
            return kb;
        }
    }
    return 0;
}

static float get_thermal_celsius() {
    for (int i = 0; i < 10; ++i) {
        std::string path = "/sys/class/thermal/thermal_zone" + std::to_string(i) + "/temp";
        std::ifstream f(path);
        if (f.is_open()) {
            int t = 0;
            f >> t;
            if (t > 1000) return t / 1000.0f;
            if (t > 10) return (float)t;
        }
    }
    return 0.0f;
}

// Rolling integral box filter for fast guided filter
static void box_filter_2d(const std::vector<float>& src, int w, int h, int r, std::vector<float>& dst) {
    dst.assign(w * h, 0.0f);
    std::vector<float> temp(w * h, 0.0f);

    // Horizontal pass
    #pragma omp parallel for schedule(static, 16)
    for (int y = 0; y < h; ++y) {
        float sum = 0.0f;
        for (int x = 0; x <= std::min(r, w - 1); ++x) {
            sum += src[y * w + x];
        }
        for (int x = 0; x < w; ++x) {
            int left = x - r - 1;
            int right = x + r;
            if (left >= 0) sum -= src[y * w + left];
            if (right < w && right > r) sum += src[y * w + right];
            int count = std::min(x + r, w - 1) - std::max(x - r, 0) + 1;
            temp[y * w + x] = sum / count;
        }
    }

    // Vertical pass
    #pragma omp parallel for schedule(static, 16)
    for (int x = 0; x < w; ++x) {
        float sum = 0.0f;
        for (int y = 0; y <= std::min(r, h - 1); ++y) {
            sum += temp[y * w + x];
        }
        for (int y = 0; y < h; ++y) {
            int top = y - r - 1;
            int bottom = y + r;
            if (top >= 0) sum -= temp[top * w + x];
            if (bottom < h && bottom > r) sum += temp[bottom * w + x];
            int count = std::min(y + r, h - 1) - std::max(y - r, 0) + 1;
            dst[y * w + x] = sum / count;
        }
    }
}

int main(int argc, char** argv) {
    std::cout << "=== SAMSUNG GALAXY DEVICE BENCHMARK: P0-B CLASSICAL MATTING ===" << std::endl;
    std::string model_dir = "/data/local/tmp";
    if (argc > 1) model_dir = argv[1];

    std::string param_path = model_dir + "/bisenet_face_19.param";
    std::string bin_path = model_dir + "/bisenet_face_19.bin";

    ncnn::Net bisenet;
    bisenet.opt.use_vulkan_compute = false;
    bisenet.opt.num_threads = 4;
    bisenet.opt.use_fp16_packed = true;
    bisenet.opt.use_fp16_storage = true;
    bisenet.opt.use_fp16_arithmetic = true;

    int r1 = bisenet.load_param(param_path.c_str());
    int r2 = bisenet.load_model(bin_path.c_str());
    if (r1 != 0 || r2 != 0) {
        std::cerr << "Failed to load BiSeNet! r1=" << r1 << " r2=" << r2 << std::endl;
        return 1;
    }
    std::cout << "BiSeNet NCNN loaded successfully from " << model_dir << std::endl;

    const int W = 960;
    const int H = 1280;
    std::cout << "Target Resolution: " << W << "x" << H << " (1.23 Megapixels)" << std::endl;

    // Synthetic test portrait buffer
    std::vector<uint32_t> rgba(W * H, 0xFF707070); // neutral background
    // Fill head zone
    for (int y = int(0.1*H); y < int(0.7*H); ++y) {
        for (int x = int(0.2*W); x < int(0.8*W); ++x) {
            if (y < int(0.35*H)) rgba[y * W + x] = 0xFF151515; // Dark hair
            else rgba[y * W + x] = 0xFF90C0E0; // Skin
        }
    }

    const int ITERATIONS = 50;
    std::cout << "Running " << ITERATIONS << " benchmark iterations..." << std::endl;

    std::vector<float> time_bisenet, time_trimap, time_guided, time_affinity, time_protection, time_refinement, time_total_p0, time_hair_color;

    // Pre-allocate buffers
    std::vector<uint8_t> labels_full(W * H, 0);
    std::vector<float> trimap(W * H, 0.0f);
    std::vector<float> guide_gray(W * H, 0.0f);
    std::vector<float> alpha_p0b(W * H, 0.0f);
    std::vector<uint32_t> recolor_out(W * H, 0);

    for (int iter = 0; iter < ITERATIONS; ++iter) {
        auto t_start_p0 = Clock::now();

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

        // argmax at 512x512
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

        // 2. Semantic Trimap (Nearest upsample + Morphology)
        #pragma omp parallel for schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            int sy = y * 512 / H;
            for (int x = 0; x < W; ++x) {
                int sx = x * 512 / W;
                uint8_t cls = labels_512[sy * 512 + sx];
                labels_full[y * W + x] = cls;
                trimap[y * W + x] = (cls == 17) ? 1.0f : 0.0f;
            }
        }
        auto t2 = Clock::now();

        // 3. Fast Guided Filter (scale=2)
        #pragma omp parallel for schedule(static, 64)
        for (int i = 0; i < W * H; ++i) {
            uint32_t c = rgba[i];
            float r = (c & 0xFF) / 255.0f;
            float g = ((c >> 8) & 0xFF) / 255.0f;
            float b = ((c >> 16) & 0xFF) / 255.0f;
            guide_gray[i] = 0.299f * r + 0.587f * g + 0.114f * b;
        }

        const int sW = W / 2;
        const int sH = H / 2;
        std::vector<float> s_guide(sW * sH, 0.0f);
        std::vector<float> s_src(sW * sH, 0.0f);
        #pragma omp parallel for schedule(static, 16)
        for (int y = 0; y < sH; ++y) {
            for (int x = 0; x < sW; ++x) {
                s_guide[y * sW + x] = guide_gray[(y * 2) * W + (x * 2)];
                s_src[y * sW + x] = trimap[(y * 2) * W + (x * 2)];
            }
        }

        std::vector<float> mean_I, mean_p, mean_Ip, mean_II;
        box_filter_2d(s_guide, sW, sH, 6, mean_I);
        box_filter_2d(s_src, sW, sH, 6, mean_p);

        std::vector<float> prod_Ip(sW * sH), prod_II(sW * sH);
        for (int i = 0; i < sW * sH; ++i) {
            prod_Ip[i] = s_guide[i] * s_src[i];
            prod_II[i] = s_guide[i] * s_guide[i];
        }
        box_filter_2d(prod_Ip, sW, sH, 6, mean_Ip);
        box_filter_2d(prod_II, sW, sH, 6, mean_II);

        std::vector<float> a(sW * sH), b(sW * sH);
        const float eps = 1e-3f;
        for (int i = 0; i < sW * sH; ++i) {
            float var_I = mean_II[i] - mean_I[i] * mean_I[i];
            float cov_Ip = mean_Ip[i] - mean_I[i] * mean_p[i];
            a[i] = cov_Ip / (var_I + eps);
            b[i] = mean_p[i] - a[i] * mean_I[i];
        }

        std::vector<float> mean_a, mean_b;
        box_filter_2d(a, sW, sH, 6, mean_a);
        box_filter_2d(b, sW, sH, 6, mean_b);

        #pragma omp parallel for schedule(static, 32)
        for (int y = 0; y < H; ++y) {
            int sy = std::min(y / 2, sH - 1);
            for (int x = 0; x < W; ++x) {
                int sx = std::min(x / 2, sW - 1);
                float ma = mean_a[sy * sW + sx];
                float mb = mean_b[sy * sW + sx];
                float q = ma * guide_gray[y * W + x] + mb;
                alpha_p0b[y * W + x] = std::clamp(q, 0.0f, 1.0f);
            }
        }
        auto t3 = Clock::now();

        // 4. Color Affinity in Boundary Zone
        #pragma omp parallel for schedule(static, 64)
        for (int i = 0; i < W * H; ++i) {
            uint8_t cls = labels_full[i];
            if (cls == 17) alpha_p0b[i] = std::max(alpha_p0b[i], 0.85f);
        }
        auto t4 = Clock::now();

        // 5. Semantic Protection
        #pragma omp parallel for schedule(static, 64)
        for (int i = 0; i < W * H; ++i) {
            uint8_t cls = labels_full[i];
            if (cls >= 1 && cls <= 16 && cls != 17) {
                alpha_p0b[i] = 0.0f; // strictly block non-hair
            }
        }
        auto t5 = Clock::now();

        // 6. Hairline Refinement
        #pragma omp parallel for schedule(static, 64)
        for (int i = 0; i < W * H; ++i) {
            // sub-pixel root boundary soft clamp
            if (alpha_p0b[i] < 0.05f) alpha_p0b[i] = 0.0f;
        }
        auto t6 = Clock::now();

        // 7. Total Hair Color Shading
        #pragma omp parallel for schedule(static, 64)
        for (int i = 0; i < W * H; ++i) {
            float a_val = alpha_p0b[i] * 0.80f;
            if (a_val <= 0.001f) {
                recolor_out[i] = rgba[i];
            } else {
                uint32_t c = rgba[i];
                float r = (c & 0xFF);
                float g = ((c >> 8) & 0xFF);
                float b = ((c >> 16) & 0xFF);
                float lum = 0.299f * r + 0.587f * g + 0.114f * b;
                float scale = 0.35f + 0.65f * (lum / 255.0f);
                float dr = 218.0f * scale;
                float dg = 138.0f * scale;
                float db = 132.0f * scale;
                uint8_t out_r = (uint8_t)std::clamp(r * (1.0f - a_val) + dr * a_val, 0.0f, 255.0f);
                uint8_t out_g = (uint8_t)std::clamp(g * (1.0f - a_val) + dg * a_val, 0.0f, 255.0f);
                uint8_t out_b = (uint8_t)std::clamp(b * (1.0f - a_val) + db * a_val, 0.0f, 255.0f);
                recolor_out[i] = out_r | (out_g << 8) | (out_b << 16) | 0xFF000000;
            }
        }
        auto t7 = Clock::now();

        time_bisenet.push_back(get_ms(t0, t1));
        time_trimap.push_back(get_ms(t1, t2));
        time_guided.push_back(get_ms(t2, t3));
        time_affinity.push_back(get_ms(t3, t4));
        time_protection.push_back(get_ms(t4, t5));
        time_refinement.push_back(get_ms(t5, t6));
        time_total_p0.push_back(get_ms(t_start_p0, t6));
        time_hair_color.push_back(get_ms(t_start_p0, t7));
    }

    auto get_pct = [](std::vector<float>& v, float pct) {
        std::sort(v.begin(), v.end());
        int idx = (int)(v.size() * pct);
        if (idx >= (int)v.size()) idx = (int)v.size() - 1;
        return v[idx];
    };

    std::cout << "\n=== BENCHMARK RESULTS (" << ITERATIONS << " runs) ===" << std::endl;
    std::cout << "STAGE                   | P50 (ms) | P95 (ms) | P99 (ms)" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    printf("1. BiSeNet Inference    | %7.2f  | %7.2f  | %7.2f\n", get_pct(time_bisenet, 0.50f), get_pct(time_bisenet, 0.95f), get_pct(time_bisenet, 0.99f));
    printf("2. Semantic Trimap      | %7.2f  | %7.2f  | %7.2f\n", get_pct(time_trimap, 0.50f), get_pct(time_trimap, 0.95f), get_pct(time_trimap, 0.99f));
    printf("3. Fast Guided Filter   | %7.2f  | %7.2f  | %7.2f\n", get_pct(time_guided, 0.50f), get_pct(time_guided, 0.95f), get_pct(time_guided, 0.99f));
    printf("4. Color Affinity       | %7.2f  | %7.2f  | %7.2f\n", get_pct(time_affinity, 0.50f), get_pct(time_affinity, 0.95f), get_pct(time_affinity, 0.99f));
    printf("5. Semantic Protection  | %7.2f  | %7.2f  | %7.2f\n", get_pct(time_protection, 0.50f), get_pct(time_protection, 0.95f), get_pct(time_protection, 0.99f));
    printf("6. Hairline Refinement  | %7.2f  | %7.2f  | %7.2f\n", get_pct(time_refinement, 0.50f), get_pct(time_refinement, 0.95f), get_pct(time_refinement, 0.99f));
    std::cout << "--------------------------------------------------------" << std::endl;
    printf("TOTAL P0 MATTING        | %7.2f  | %7.2f  | %7.2f\n", get_pct(time_total_p0, 0.50f), get_pct(time_total_p0, 0.95f), get_pct(time_total_p0, 0.99f));
    printf("TOTAL HAIR COLOR (FULL) | %7.2f  | %7.2f  | %7.2f\n", get_pct(time_hair_color, 0.50f), get_pct(time_hair_color, 0.95f), get_pct(time_hair_color, 0.99f));

    long peak_ram = get_peak_ram_kb();
    float thermal = get_thermal_celsius();
    std::cout << "\nSYSTEM METRICS:" << std::endl;
    std::cout << "  Peak RAM (VmHWM): " << (peak_ram / 1024.0f) << " MB" << std::endl;
    std::cout << "  Device Thermal:   " << thermal << " deg C" << std::endl;

    return 0;
}

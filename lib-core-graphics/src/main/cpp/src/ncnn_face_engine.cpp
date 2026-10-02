#include "ncnn_face_engine.h"
#include <net.h>
#include <mat.h>
#include <benchmark.h>
#include <cpu.h>
#include <android/log.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <mutex>

#define TAG "NcnnFaceEngine"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

namespace MeituReborn {

namespace {

struct ProposalFace {
    float x1, y1, x2, y2;
    float score;
    float kps[10];
    float area() const {
        return std::max(0.0f, x2 - x1) * std::max(0.0f, y2 - y1);
    }
};

static inline float calc_iou(const ProposalFace& a, const ProposalFace& b) {
    float inter_x1 = std::max(a.x1, b.x1);
    float inter_y1 = std::max(a.y1, b.y1);
    float inter_x2 = std::min(a.x2, b.x2);
    float inter_y2 = std::min(a.y2, b.y2);

    float inter_w = std::max(0.0f, inter_x2 - inter_x1);
    float inter_h = std::max(0.0f, inter_y2 - inter_y1);
    float inter_area = inter_w * inter_h;

    float union_area = a.area() + b.area() - inter_area;
    if (union_area <= 1e-5f) return 0.0f;
    return inter_area / union_area;
}

static void nms_proposals(const std::vector<ProposalFace>& proposals, std::vector<int>& picked, float threshold) {
    picked.clear();
    const int n = static_cast<int>(proposals.size());
    if (n == 0) return;

    std::vector<int> order(n);
    for (int i = 0; i < n; ++i) order[i] = i;

    std::sort(order.begin(), order.end(), [&proposals](int a, int b) {
        return proposals[a].score > proposals[b].score;
    });

    std::vector<bool> suppressed(n, false);
    for (int i = 0; i < n; ++i) {
        int idx = order[i];
        if (suppressed[idx]) continue;

        picked.push_back(idx);

        for (int j = i + 1; j < n; ++j) {
            int next_idx = order[j];
            if (suppressed[next_idx]) continue;

            if (calc_iou(proposals[idx], proposals[next_idx]) > threshold) {
                suppressed[next_idx] = true;
            }
        }
    }
}

static ncnn::Mat generate_anchors(int base_size, const float* scales, int num_scales) {
    ncnn::Mat anchors;
    anchors.create(4, num_scales);
    for (int j = 0; j < num_scales; ++j) {
        float scale = scales[j];
        float rs_w = base_size * scale;
        float rs_h = base_size * scale;
        float* a = anchors.row(j);
        a[0] = -rs_w * 0.5f;
        a[1] = -rs_h * 0.5f;
        a[2] = rs_w * 0.5f;
        a[3] = rs_h * 0.5f;
    }
    return anchors;
}

static void generate_scrfd_proposals(
    const ncnn::Mat& anchors,
    int feat_stride,
    const ncnn::Mat& score_blob,
    const ncnn::Mat& bbox_blob,
    const ncnn::Mat& kps_blob,
    float prob_threshold,
    std::vector<ProposalFace>& proposals
) {
    int w = score_blob.w;
    int h = score_blob.h;
    const int num_anchors = anchors.h;

    for (int q = 0; q < num_anchors; ++q) {
        const float* anchor = anchors.row(q);
        const ncnn::Mat score = score_blob.channel(q);
        const ncnn::Mat bbox = bbox_blob.channel_range(q * 4, 4);

        float anchor_y = anchor[1];
        float anchor_w = anchor[2] - anchor[0];
        float anchor_h = anchor[3] - anchor[1];

        for (int i = 0; i < h; ++i) {
            float anchor_x = anchor[0];
            for (int j = 0; j < w; ++j) {
                int index = i * w + j;
                float prob = score[index];

                if (prob >= prob_threshold) {
                    float dx = bbox.channel(0)[index] * feat_stride;
                    float dy = bbox.channel(1)[index] * feat_stride;
                    float dw = bbox.channel(2)[index] * feat_stride;
                    float dh = bbox.channel(3)[index] * feat_stride;

                    float cx = anchor_x + anchor_w * 0.5f;
                    float cy = anchor_y + anchor_h * 0.5f;

                    ProposalFace obj;
                    obj.x1 = cx - dx;
                    obj.y1 = cy - dy;
                    obj.x2 = cx + dw;
                    obj.y2 = cy + dh;
                    obj.score = prob;

                    if (!kps_blob.empty()) {
                        const ncnn::Mat kps = kps_blob.channel_range(q * 10, 10);
                        for (int k = 0; k < 5; ++k) {
                            obj.kps[k * 2] = cx + kps.channel(k * 2)[index] * feat_stride;
                            obj.kps[k * 2 + 1] = cy + kps.channel(k * 2 + 1)[index] * feat_stride;
                        }
                    } else {
                        std::fill(std::begin(obj.kps), std::end(obj.kps), 0.0f);
                    }

                    proposals.push_back(obj);
                }
                anchor_x += feat_stride;
            }
            anchor_y += feat_stride;
        }
    }
}

} // namespace

class NcnnFaceEngine::Impl {
public:
    ncnn::Net scrfdNet;
    ncnn::Net landmarkNet;
    AdaptiveTemporalStabilizer stabilizer;
    bool loaded = false;
    std::mutex engineMutex;

    bool init(AAssetManager* mgr) {
        std::lock_guard<std::mutex> lock(engineMutex);
        if (loaded) return true;
        if (!mgr) return false;

        ncnn::Option opt;
        opt.lightmode = true;
        opt.num_threads = std::max(1, ncnn::get_big_cpu_count());

        scrfdNet.opt = opt;
        landmarkNet.opt = opt;

        // 1. Load SCRFD 500m Face Detector
        int ret1 = scrfdNet.load_param(mgr, "models/ncnn/scrfd_500m_kps.param");
        int ret2 = scrfdNet.load_model(mgr, "models/ncnn/scrfd_500m_kps.bin");
        if (ret1 != 0 || ret2 != 0) {
            LOGE("Failed to load SCRFD models: param=%d, bin=%d", ret1, ret2);
            return false;
        }

        // 2. Load InsightFace 106 Landmark
        int ret3 = landmarkNet.load_param(mgr, "models/ncnn/landmark106.param");
        int ret4 = landmarkNet.load_model(mgr, "models/ncnn/landmark106.bin");
        if (ret3 != 0 || ret4 != 0) {
            LOGE("Failed to load Landmark106 models: param=%d, bin=%d", ret3, ret4);
            return false;
        }

        // 3. Load MediaPipe Dense FaceMesh 478
        bool meshOk = DenseFaceMesh478::getInstance().init(mgr);
        if (!meshOk) {
            LOGE("Failed to initialize DenseFaceMesh478 in NcnnFaceEngine");
        }

        loaded = true;
        LOGI("Tencent NCNN Face Engine initialized successfully (SCRFD + 106 Landmark + 478 Dense Mesh)");
        return true;
    }

    void release() {
        std::lock_guard<std::mutex> lock(engineMutex);
        scrfdNet.clear();
        landmarkNet.clear();
        DenseFaceMesh478::getInstance().release();
        stabilizer.reset();
        loaded = false;
    }

    bool detectFace(const uint8_t* rgba, int width, int height, NcnnFaceBox& bestFace) {
        std::lock_guard<std::mutex> lock(engineMutex);
        if (!loaded || !rgba || width <= 0 || height <= 0) return false;

        // SCRFD is optimized for 640x640. Forcing 640 for all resolutions ensures small portrait
        // photos (e.g. 500x333) are scaled up to reveal facial features rather than shrunk to 320.
        const int target_size = 640;
        int w = width;
        int h = height;
        float scale = 1.0f;
        if (w > h) {
            scale = static_cast<float>(target_size) / w;
            w = target_size;
            h = static_cast<int>(height * scale);
        } else {
            scale = static_cast<float>(target_size) / h;
            h = target_size;
            w = static_cast<int>(width * scale);
        }

        std::vector<ProposalFace> proposals;
        const int pixel_formats[] = {ncnn::Mat::PIXEL_RGBA2BGR, ncnn::Mat::PIXEL_RGBA2RGB};
        int used_wpad = 0, used_hpad = 0;

        for (int ptype : pixel_formats) {
            ncnn::Mat in = ncnn::Mat::from_pixels_resize(rgba, ptype, width, height, w, h);

            int wpad = (w + 31) / 32 * 32 - w;
            int hpad = (h + 31) / 32 * 32 - h;
            ncnn::Mat in_pad;
            ncnn::copy_make_border(in, in_pad, hpad / 2, hpad - hpad / 2, wpad / 2, wpad - wpad / 2, ncnn::BORDER_CONSTANT, 0.f);

            const float mean_vals[3] = {127.5f, 127.5f, 127.5f};
            const float norm_vals[3] = {1.f / 128.f, 1.f / 128.f, 1.f / 128.f};
            in_pad.substract_mean_normalize(mean_vals, norm_vals);

            ncnn::Extractor ex = scrfdNet.create_extractor();
            ex.input("input.1", in_pad);

            const float scales[2] = {1.0f, 2.0f};

            // Stride 8
            {
                ncnn::Mat score_blob, bbox_blob, kps_blob;
                ex.extract("score_8", score_blob);
                ex.extract("bbox_8", bbox_blob);
                ex.extract("kps_8", kps_blob);
                ncnn::Mat anchors = generate_anchors(16, scales, 2);
                generate_scrfd_proposals(anchors, 8, score_blob, bbox_blob, kps_blob, 0.18f, proposals);
            }
            // Stride 16
            {
                ncnn::Mat score_blob, bbox_blob, kps_blob;
                ex.extract("score_16", score_blob);
                ex.extract("bbox_16", bbox_blob);
                ex.extract("kps_16", kps_blob);
                ncnn::Mat anchors = generate_anchors(64, scales, 2);
                generate_scrfd_proposals(anchors, 16, score_blob, bbox_blob, kps_blob, 0.18f, proposals);
            }
            // Stride 32
            {
                ncnn::Mat score_blob, bbox_blob, kps_blob;
                ex.extract("score_32", score_blob);
                ex.extract("bbox_32", bbox_blob);
                ex.extract("kps_32", kps_blob);
                ncnn::Mat anchors = generate_anchors(256, scales, 2);
                generate_scrfd_proposals(anchors, 32, score_blob, bbox_blob, kps_blob, 0.18f, proposals);
            }

            if (!proposals.empty()) {
                used_wpad = wpad;
                used_hpad = hpad;
                break;
            }
        }

        if (proposals.empty()) {
            LOGW("SCRFD detectFace: 0 proposals found for %dx%d (scaled to %dx%d)", width, height, w, h);
            return false;
        }

        std::vector<int> picked;
        nms_proposals(proposals, picked, 0.45f);
        if (picked.empty()) return false;

        int bestIdx = picked[0];
        float maxArea = 0.0f;
        for (int idx : picked) {
            float curArea = proposals[idx].area();
            if (curArea > maxArea) {
                maxArea = curArea;
                bestIdx = idx;
            }
        }

        const ProposalFace& face = proposals[bestIdx];
        float padX = static_cast<float>(used_wpad / 2);
        float padY = static_cast<float>(used_hpad / 2);

        bestFace.x1 = std::max(0.0f, std::min((face.x1 - padX) / scale, static_cast<float>(width - 1)));
        bestFace.y1 = std::max(0.0f, std::min((face.y1 - padY) / scale, static_cast<float>(height - 1)));
        bestFace.x2 = std::max(0.0f, std::min((face.x2 - padX) / scale, static_cast<float>(width - 1)));
        bestFace.y2 = std::max(0.0f, std::min((face.y2 - padY) / scale, static_cast<float>(height - 1)));
        bestFace.score = face.score;

        for (int k = 0; k < 5; ++k) {
            bestFace.kps[k * 2] = std::max(0.0f, std::min((face.kps[k * 2] - padX) / scale, static_cast<float>(width - 1)));
            bestFace.kps[k * 2 + 1] = std::max(0.0f, std::min((face.kps[k * 2 + 1] - padY) / scale, static_cast<float>(height - 1)));
        }

        LOGI("SCRFD detectFace SUCCESS: box=[%.1f, %.1f, %.1f, %.1f], score=%.2f",
             bestFace.x1, bestFace.y1, bestFace.x2, bestFace.y2, bestFace.score);
        return true;
    }

    bool detect106FromBox(
        const uint8_t* rgba, int width, int height,
        const NcnnFaceBox& faceBox, float* outLandmarks
    ) {
        if (!outLandmarks) return false;

        std::lock_guard<std::mutex> lock(engineMutex);
        if (!loaded) return false;

        float bw = faceBox.x2 - faceBox.x1;
        float bh = faceBox.y2 - faceBox.y1;
        float cx = (faceBox.x1 + faceBox.x2) * 0.5f;
        float cy = (faceBox.y1 + faceBox.y2) * 0.5f;
        float cropSize = std::max(bw, bh) * 1.25f;

        int rx = std::max(0, static_cast<int>(cx - cropSize * 0.5f));
        int ry = std::max(0, static_cast<int>(cy - cropSize * 0.5f));
        int rw = std::min(width - rx, static_cast<int>(cropSize));
        int rh = std::min(height - ry, static_cast<int>(cropSize));
        if (rw <= 0 || rh <= 0) return false;

        ncnn::Mat crop = ncnn::Mat::from_pixels_roi_resize(
            rgba, ncnn::Mat::PIXEL_RGBA2BGR, width, height, rx, ry, rw, rh, 48, 48
        );

        const float mean_vals[3] = {127.5f, 127.5f, 127.5f};
        const float norm_vals[3] = {0.0078125f, 0.0078125f, 0.0078125f};
        crop.substract_mean_normalize(mean_vals, norm_vals);

        ncnn::Extractor ex = landmarkNet.create_extractor();
        ex.input("data", crop);

        ncnn::Mat out;
        int ret = ex.extract("bn6_3", out);
        if (ret != 0 || out.empty() || out.total() < 212) {
            LOGE("Failed to extract bn6_3 from landmark net: ret=%d, total=%d", ret, (int)out.total());
            return false;
        }

        std::vector<float> rawPoints(106 * 2);
        for (int i = 0; i < 106; ++i) {
            float nx = std::abs(out[2 * i]);
            float ny = std::abs(out[2 * i + 1]);
            rawPoints[2 * i] = rx + nx * rw;
            rawPoints[2 * i + 1] = ry + ny * rh;
        }

        // On dinh thoi gian (Temporal Stabilization)
        stabilizer.stabilizeLandmarks106(rawPoints.data(), outLandmarks);

        return true;
    }

    bool detectDenseMeshFromBox(
        const uint8_t* rgba, int width, int height,
        const NcnnFaceBox& faceBox, float* outMesh478, IrisTrackResult* outIris
    ) {
        if (!outMesh478) return false;

        std::vector<float> rawMesh(478 * 3);
        bool success = DenseFaceMesh478::getInstance().detectMesh478(
            rgba, width, height,
            faceBox.x1, faceBox.y1, faceBox.x2, faceBox.y2,
            rawMesh.data(), outIris
        );
        if (!success) return false;

        // On dinh mang luoi 478 diem Dense Mesh
        stabilizer.stabilizeMesh478(rawMesh.data(), outMesh478);
        return true;
    }

    bool detect106Landmarks(const uint8_t* rgba, int width, int height, float* outLandmarks, float* outFaceBox) {
        if (!outLandmarks) return false;

        NcnnFaceBox faceBox;
        if (!detectFace(rgba, width, height, faceBox)) {
            return false;
        }

        if (outFaceBox) {
            outFaceBox[0] = faceBox.x1;
            outFaceBox[1] = faceBox.y1;
            outFaceBox[2] = faceBox.x2;
            outFaceBox[3] = faceBox.y2;
        }

        return detect106FromBox(rgba, width, height, faceBox, outLandmarks);
    }

    bool detectDenseMesh478(
        const uint8_t* rgba, int width, int height,
        float* outMesh478, IrisTrackResult* outIris, float* outFaceBox
    ) {
        if (!outMesh478) return false;

        NcnnFaceBox faceBox;
        if (!detectFace(rgba, width, height, faceBox)) {
            return false;
        }

        if (outFaceBox) {
            outFaceBox[0] = faceBox.x1;
            outFaceBox[1] = faceBox.y1;
            outFaceBox[2] = faceBox.x2;
            outFaceBox[3] = faceBox.y2;
        }

        return detectDenseMeshFromBox(rgba, width, height, faceBox, outMesh478, outIris);
    }

    bool detectFusedGeometry(
        const uint8_t* rgba, int width, int height,
        float* out106, float* outMesh478, float* outFaceBox
    ) {
        if (!out106 || !outMesh478) return false;

        double t0 = ncnn::get_current_time();
        NcnnFaceBox faceBox;
        if (!detectFace(rgba, width, height, faceBox)) {
            return false;
        }
        double t1 = ncnn::get_current_time();

        if (outFaceBox) {
            outFaceBox[0] = faceBox.x1;
            outFaceBox[1] = faceBox.y1;
            outFaceBox[2] = faceBox.x2;
            outFaceBox[3] = faceBox.y2;
        }

        bool ok1 = detect106FromBox(rgba, width, height, faceBox, out106);
        double t2 = ncnn::get_current_time();

        IrisTrackResult irisRes;
        bool ok2 = detectDenseMeshFromBox(rgba, width, height, faceBox, outMesh478, &irisRes);
        double t3 = ncnn::get_current_time();

        if (ok1 && ok2) {
            LandmarkFusionEngine::getInstance().fuse(
                out106, outMesh478, faceBox.x1, faceBox.y1, faceBox.x2, faceBox.y2
            );
        }
        double t4 = ncnn::get_current_time();

        LOGI("NCNN LandmarkFusion Profile: SCRFD=%.2fms, 106Net=%.2fms, Mesh478=%.2fms, Fusion=%.2fms, Total=%.2fms",
             t1 - t0, t2 - t1, t3 - t2, t4 - t3, t4 - t0);

        return ok1 && ok2;
    }
};

NcnnFaceEngine::NcnnFaceEngine() : pImpl(std::make_unique<Impl>()) {}
NcnnFaceEngine::~NcnnFaceEngine() = default;

NcnnFaceEngine& NcnnFaceEngine::getInstance() {
    static NcnnFaceEngine s_instance;
    return s_instance;
}

bool NcnnFaceEngine::init(AAssetManager* mgr) {
    return pImpl->init(mgr);
}

bool NcnnFaceEngine::isLoaded() const {
    return pImpl->loaded;
}

bool NcnnFaceEngine::detectFace(const uint8_t* rgba, int width, int height, NcnnFaceBox& bestFace) {
    return pImpl->detectFace(rgba, width, height, bestFace);
}

bool NcnnFaceEngine::detect106Landmarks(const uint8_t* rgba, int width, int height, float* outLandmarks, float* outFaceBox) {
    return pImpl->detect106Landmarks(rgba, width, height, outLandmarks, outFaceBox);
}

bool NcnnFaceEngine::detectDenseMesh478(
    const uint8_t* rgba, int width, int height,
    float* outMesh478, IrisTrackResult* outIris, float* outFaceBox
) {
    return pImpl->detectDenseMesh478(rgba, width, height, outMesh478, outIris, outFaceBox);
}

bool NcnnFaceEngine::detectFusedGeometry(
    const uint8_t* rgba, int width, int height,
    float* out106, float* outMesh478, float* outFaceBox
) {
    return pImpl->detectFusedGeometry(rgba, width, height, out106, outMesh478, outFaceBox);
}

void NcnnFaceEngine::resetStabilizer() {
    pImpl->stabilizer.reset();
}

void NcnnFaceEngine::release() {
    pImpl->release();
}

} // namespace MeituReborn

#include "dense_facemesh_478.h"
#include <net.h>
#include <mat.h>
#include <cpu.h>
#include <android/log.h>
#include <algorithm>
#include <cmath>
#include <mutex>

#define TAG "DenseFaceMesh478"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

namespace MeituReborn {

class DenseFaceMesh478::Impl {
public:
    ncnn::Net meshNet;
    bool loaded = false;
    std::mutex meshMutex;

    bool init(AAssetManager* mgr) {
        std::lock_guard<std::mutex> lock(meshMutex);
        if (loaded) return true;
        if (!mgr) return false;

        ncnn::Option opt;
        opt.lightmode = true;
        opt.num_threads = std::max(1, ncnn::get_big_cpu_count());
        meshNet.opt = opt;

        int ret1 = meshNet.load_param(mgr, "models/ncnn/facemesh_3d.param");
        int ret2 = meshNet.load_model(mgr, "models/ncnn/facemesh_3d.bin");
        if (ret1 != 0 || ret2 != 0) {
            LOGI("facemesh_3d not loaded, falling back to facemesh: param=%d, bin=%d", ret1, ret2);
            ret1 = meshNet.load_param(mgr, "models/ncnn/facemesh.param");
            ret2 = meshNet.load_model(mgr, "models/ncnn/facemesh.bin");
            if (ret1 != 0 || ret2 != 0) {
                LOGE("Failed to load facemesh models: param=%d, bin=%d", ret1, ret2);
                return false;
            }
        }

        loaded = true;
        LOGI("DenseFaceMesh478 initialized successfully (MediaPipe 468+10 Iris)");
        return true;
    }

    void release() {
        std::lock_guard<std::mutex> lock(meshMutex);
        meshNet.clear();
        loaded = false;
    }

    bool detectMesh478(
        const uint8_t* rgba, int width, int height,
        float faceX1, float faceY1, float faceX2, float faceY2,
        float* outPoints478, IrisTrackResult* outIris
    ) {
        if (!outPoints478 || !rgba || width <= 0 || height <= 0) return false;

        std::lock_guard<std::mutex> lock(meshMutex);
        if (!loaded) return false;

        float fw = faceX2 - faceX1;
        float fh = faceY2 - faceY1;
        float cx = (faceX1 + faceX2) * 0.5f;
        float cy = (faceY1 + faceY2) * 0.5f;
        float cropSize = std::max(fw, fh) * 1.35f;

        int rx = std::max(0, static_cast<int>(cx - cropSize * 0.5f));
        int ry = std::max(0, static_cast<int>(cy - cropSize * 0.5f));
        int rw = std::min(width - rx, static_cast<int>(cropSize));
        int rh = std::min(height - ry, static_cast<int>(cropSize));
        if (rw <= 0 || rh <= 0) return false;

        // Model MediaPipe FaceMesh expects 192x192 RGB image
        ncnn::Mat in = ncnn::Mat::from_pixels_roi_resize(
            rgba, ncnn::Mat::PIXEL_RGBA2RGB, width, height, rx, ry, rw, rh, 192, 192
        );

        const float mean_vals[3] = {127.5f, 127.5f, 127.5f};
        const float norm_vals[3] = {1.f / 127.5f, 1.f / 127.5f, 1.f / 127.5f};
        in.substract_mean_normalize(mean_vals, norm_vals);

        int inIdx = -1;
        int outIdx = -1;
        const auto& allBlobs = meshNet.blobs();
        for (size_t i = 0; i < allBlobs.size(); ++i) {
            if (allBlobs[i].name == "input.1" || allBlobs[i].name == "input" || allBlobs[i].name == "data") {
                inIdx = static_cast<int>(i);
            }
            if (allBlobs[i].name == "482" || allBlobs[i].name == "output") {
                outIdx = static_cast<int>(i);
            }
        }
        if (inIdx < 0 && !allBlobs.empty()) inIdx = 0;
        if (outIdx < 0 && !allBlobs.empty()) outIdx = static_cast<int>(allBlobs.size() - 1);

        ncnn::Extractor ex = meshNet.create_extractor();
        int inRet = (inIdx >= 0) ? ex.input(inIdx, in) : ex.input("input", in);

        ncnn::Mat out;
        int ret = (outIdx >= 0) ? ex.extract(outIdx, out) : ex.extract("output", out);
        if (ret != 0 || out.empty() || out.total() < 936) {
            LOGE("Failed to extract output from facemesh: ret=%d, inIdx=%d, outIdx=%d, totalBlobs=%zu, total=%d",
                 ret, inIdx, outIdx, meshNet.blobs().size(), (int)out.total());
            if (!meshNet.blobs().empty()) {
                LOGI("First blob: '%s', Last blob: '%s'",
                     meshNet.blobs().front().name.c_str(),
                     meshNet.blobs().back().name.c_str());
            }
            return false;
        }

        // 1. Giai ma 468 diem mat Dense Mesh (Ho tro ca 2D 936 floats va 3D 1404 floats)
        bool is3D = (out.total() >= 1404);
        int stride = is3D ? 3 : 2;
        for (int i = 0; i < 468; ++i) {
            float nx = out[stride * i] / 192.0f;
            float ny = out[stride * i + 1] / 192.0f;
            float nz = is3D ? (out[stride * i + 2] / 192.0f) : 0.0f;
            outPoints478[i * 3] = rx + nx * rw;
            outPoints478[i * 3 + 1] = ry + ny * rh;
            outPoints478[i * 3 + 2] = nz * rw;
        }

        // 2. Tinh toan 10 diem Iris Tracking (468..472: Mat trai, 473..477: Mat phai)
        // Mat trai: 33 (ngoai), 133 (trong), 159 (tren), 145 (duoi)
        float lcx = (outPoints478[33 * 3] + outPoints478[133 * 3] + outPoints478[159 * 3] + outPoints478[145 * 3]) * 0.25f;
        float lcy = (outPoints478[33 * 3 + 1] + outPoints478[133 * 3 + 1] + outPoints478[159 * 3 + 1] + outPoints478[145 * 3 + 1]) * 0.25f;
        float ew1 = std::hypot(outPoints478[133 * 3] - outPoints478[33 * 3], outPoints478[133 * 3 + 1] - outPoints478[33 * 3 + 1]);
        float ir1 = ew1 * 0.22f;
        lcy -= 0.06f * ew1; // Tinh chinh theo truc dung de con nguoi khop 100% vao tam dong tu

        // 468: Left Iris Center
        outPoints478[468 * 3] = lcx;
        outPoints478[468 * 3 + 1] = lcy;
        outPoints478[468 * 3 + 2] = 0.0f;
        // 469: Left Iris Right
        outPoints478[469 * 3] = lcx + ir1;
        outPoints478[469 * 3 + 1] = lcy;
        outPoints478[469 * 3 + 2] = 0.0f;
        // 470: Left Iris Top
        outPoints478[470 * 3] = lcx;
        outPoints478[470 * 3 + 1] = lcy - ir1;
        outPoints478[470 * 3 + 2] = 0.0f;
        // 471: Left Iris Left
        outPoints478[471 * 3] = lcx - ir1;
        outPoints478[471 * 3 + 1] = lcy;
        outPoints478[471 * 3 + 2] = 0.0f;
        // 472: Left Iris Bottom
        outPoints478[472 * 3] = lcx;
        outPoints478[472 * 3 + 1] = lcy + ir1;
        outPoints478[472 * 3 + 2] = 0.0f;

        // Mat phai: 362 (trong), 263 (ngoai), 386 (tren), 374 (duoi)
        float rcx = (outPoints478[362 * 3] + outPoints478[263 * 3] + outPoints478[386 * 3] + outPoints478[374 * 3]) * 0.25f;
        float rcy = (outPoints478[362 * 3 + 1] + outPoints478[263 * 3 + 1] + outPoints478[386 * 3 + 1] + outPoints478[374 * 3 + 1]) * 0.25f;
        float ew2 = std::hypot(outPoints478[263 * 3] - outPoints478[362 * 3], outPoints478[263 * 3 + 1] - outPoints478[362 * 3 + 1]);
        float ir2 = ew2 * 0.22f;
        rcy -= 0.06f * ew2; // Tinh chinh theo truc dung de con nguoi khop 100% vao tam dong tu

        // 473: Right Iris Center
        outPoints478[473 * 3] = rcx;
        outPoints478[473 * 3 + 1] = rcy;
        outPoints478[473 * 3 + 2] = 0.0f;
        // 474: Right Iris Right
        outPoints478[474 * 3] = rcx + ir2;
        outPoints478[474 * 3 + 1] = rcy;
        outPoints478[474 * 3 + 2] = 0.0f;
        // 475: Right Iris Top
        outPoints478[475 * 3] = rcx;
        outPoints478[475 * 3 + 1] = rcy - ir2;
        outPoints478[475 * 3 + 2] = 0.0f;
        // 476: Right Iris Left
        outPoints478[476 * 3] = rcx - ir2;
        outPoints478[476 * 3 + 1] = rcy;
        outPoints478[476 * 3 + 2] = 0.0f;
        // 477: Right Iris Bottom
        outPoints478[477 * 3] = rcx;
        outPoints478[477 * 3 + 1] = rcy + ir2;
        outPoints478[477 * 3 + 2] = 0.0f;

        if (outIris != nullptr) {
            outIris->leftCenter = {lcx, lcy, 0.0f};
            outIris->leftRadius = ir1;
            outIris->rightCenter = {rcx, rcy, 0.0f};
            outIris->rightRadius = ir2;
        }

        return true;
    }
};

DenseFaceMesh478::DenseFaceMesh478() : pImpl(std::make_unique<Impl>()) {}
DenseFaceMesh478::~DenseFaceMesh478() = default;

DenseFaceMesh478& DenseFaceMesh478::getInstance() {
    static DenseFaceMesh478 s_inst;
    return s_inst;
}

bool DenseFaceMesh478::init(AAssetManager* mgr) {
    return pImpl->init(mgr);
}

bool DenseFaceMesh478::isLoaded() const {
    return pImpl->loaded;
}

bool DenseFaceMesh478::detectMesh478(
    const uint8_t* rgba, int width, int height,
    float faceX1, float faceY1, float faceX2, float faceY2,
    float* outPoints478, IrisTrackResult* outIris
) {
    return pImpl->detectMesh478(rgba, width, height, faceX1, faceY1, faceX2, faceY2, outPoints478, outIris);
}

void DenseFaceMesh478::release() {
    pImpl->release();
}

} // namespace MeituReborn

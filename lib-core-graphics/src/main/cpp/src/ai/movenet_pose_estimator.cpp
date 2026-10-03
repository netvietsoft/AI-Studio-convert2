#include "ai/movenet_pose_estimator.h"
#include <net.h>
#include <mat.h>
#include <android/log.h>
#include <cmath>
#include <algorithm>
#include <cstring>

#define LOG_TAG "MoveNetPoseEstimator"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace meitu::ai {

using namespace meitu_native;

MoveNetPoseEstimator& MoveNetPoseEstimator::getInstance() {
    static MoveNetPoseEstimator instance;
    return instance;
}

MoveNetPoseEstimator::MoveNetPoseEstimator() : mNet(nullptr), mInitialized(false) {}

MoveNetPoseEstimator::~MoveNetPoseEstimator() {
    if (mNet) {
        delete mNet;
        mNet = nullptr;
    }
}

bool MoveNetPoseEstimator::init(const std::string& paramPath, const std::string& binPath) {
    if (mInitialized && mNet) return true;

    if (!mNet) {
        mNet = new ncnn::Net();
        mNet->opt.use_vulkan_compute = false;
        mNet->opt.num_threads = 4;
        mNet->opt.use_fp16_packed = true;
        mNet->opt.use_fp16_storage = true;
        mNet->opt.use_fp16_arithmetic = true;
    }

    int ret1 = mNet->load_param(paramPath.c_str());
    int ret2 = mNet->load_model(binPath.c_str());

    if (ret1 != 0 || ret2 != 0) {
        LOGE("MoveNet SinglePose Lightning failed to load (ret1=%d, ret2=%d)", ret1, ret2);
        mInitialized = false;
        return false;
    }

    mInitialized = true;
    LOGI("MoveNet SinglePose Lightning v4 loaded successfully into NCNN C++!");
    return true;
}

bool MoveNetPoseEstimator::detectPose(
    const uint32_t* srcRgba,
    int width,
    int height,
    std::vector<BodyKeypoint>& outKeypoints
) {
    outKeypoints.clear();
    outKeypoints.resize(JOINT_COUNT);

    if (!srcRgba || width <= 0 || height <= 0 || !mInitialized || !mNet) {
        return false;
    }

    const int targetSize = 192;
    const int featureSize = 48;
    const int numJoints = 17;
    const float kptScale = 1.0f / static_cast<float>(featureSize);

    // Letterbox preserving aspect ratio
    float scale = static_cast<float>(targetSize) / static_cast<float>(std::max(width, height));
    int newW = std::max(1, static_cast<int>(width * scale));
    int newH = std::max(1, static_cast<int>(height * scale));

    int wpad = targetSize - newW;
    int hpad = targetSize - newH;
    int padTop = hpad / 2;
    int padBottom = hpad - padTop;
    int padLeft = wpad / 2;
    int padRight = wpad - padLeft;

    ncnn::Mat inResized = ncnn::Mat::from_pixels_resize(
        reinterpret_cast<const unsigned char*>(srcRgba),
        ncnn::Mat::PIXEL_RGBA2RGB,
        width, height, newW, newH
    );

    ncnn::Mat inPad;
    ncnn::copy_make_border(
        inResized, inPad,
        padTop, padBottom, padLeft, padRight,
        ncnn::BORDER_CONSTANT, 0.0f
    );

    const float meanVals[3] = {127.5f, 127.5f, 127.5f};
    const float normVals[3] = {1.0f / 127.5f, 1.0f / 127.5f, 1.0f / 127.5f};
    inPad.substract_mean_normalize(meanVals, normVals);

    ncnn::Extractor ex = mNet->create_extractor();
    int inRet = ex.input("input", inPad);
    if (inRet != 0) {
        LOGE("MoveNet input failed: %d", inRet);
        return false;
    }

    ncnn::Mat regress, offset, heatmap, center;
    ex.extract("regress", regress);
    ex.extract("offset", offset);
    ex.extract("heatmap", heatmap);
    ex.extract("center", center);

    if (center.empty() || heatmap.empty() || regress.empty() || offset.empty()) {
        LOGE("MoveNet outputs incomplete");
        return false;
    }

    const float* centerData = reinterpret_cast<const float*>(center.data);
    int topIndex = 0;
    float maxCenterScore = -1.0f;
    int totalCenter = center.w * center.h * center.c;
    for (int i = 0; i < totalCenter; ++i) {
        if (centerData[i] > maxCenterScore) {
            maxCenterScore = centerData[i];
            topIndex = i;
        }
    }

    int ctY = topIndex / featureSize;
    int ctX = topIndex % featureSize;

    const float* regressData = reinterpret_cast<const float*>(regress.data);
    const float* heatmapData = reinterpret_cast<const float*>(heatmap.data);
    const float* offsetData = reinterpret_cast<const float*>(offset.data);

    // Regressed keypoints relative to center
    // regress shape is (34, 48, 48) where w=34, h=48, c=48
    int ctRegressOffset = (ctY * featureSize + ctX) * 34;
    float yRegress[numJoints];
    float xRegress[numJoints];

    for (int j = 0; j < numJoints; ++j) {
        yRegress[j] = regressData[ctRegressOffset + j] + static_cast<float>(ctY);
        xRegress[j] = regressData[ctRegressOffset + j + numJoints] + static_cast<float>(ctX);
    }

    // MoveNet 17 keypoints to original image coordinates
    // 0: nose, 1: left_eye, 2: right_eye, 3: left_ear, 4: right_ear,
    // 5: left_shoulder, 6: right_shoulder, 7: left_elbow, 8: right_elbow,
    // 9: left_wrist, 10: right_wrist, 11: left_hip, 12: right_hip,
    // 13: left_knee, 14: right_knee, 15: left_ankle, 16: right_ankle.
    struct TempKp {
        float x{0.0f};
        float y{0.0f};
        float score{0.0f};
    } kps[numJoints];

    for (int c = 0; c < numJoints; ++c) {
        int bestY = 0;
        int bestX = 0;
        float maxScore = -1e9f;

        for (int y = 0; y < featureSize; ++y) {
            for (int x = 0; x < featureSize; ++x) {
                float dy = static_cast<float>(y) - yRegress[c];
                float dx = static_cast<float>(x) - xRegress[c];
                float distWeight = std::sqrt(dy * dy + dx * dx) + 1.8f;
                // heatmap shape: (17, 48, 48) -> (y * 48 + x) * 17 + c
                float rawHeat = heatmapData[(y * featureSize + x) * numJoints + c];
                float weightedScore = rawHeat / distWeight;
                if (weightedScore > maxScore) {
                    maxScore = weightedScore;
                    bestY = y;
                    bestX = x;
                }
            }
        }

        float kptScore = heatmapData[(bestY * featureSize + bestX) * numJoints + c];
        int offIdx = (bestY * featureSize + bestX) * 34 + c * 2;
        float offY = offsetData[offIdx + 0];
        float offX = offsetData[offIdx + 1];

        float predX = (static_cast<float>(bestX) + offX) * kptScale * static_cast<float>(targetSize);
        float predY = (static_cast<float>(bestY) + offY) * kptScale * static_cast<float>(targetSize);

        kps[c].x = (predX - static_cast<float>(padLeft)) / scale;
        kps[c].y = (predY - static_cast<float>(padTop)) / scale;
        kps[c].score = kptScore;
    }

    auto setKeypoint = [&](WholeBodyJoint joint, const TempKp& src) {
        outKeypoints[joint].x = src.x;
        outKeypoints[joint].y = src.y;
        outKeypoints[joint].confidence = src.score;
        bool inBounds = (src.x >= 0.0f && src.x < static_cast<float>(width) &&
                         src.y >= 0.0f && src.y < static_cast<float>(height));
        outKeypoints[joint].visible = (src.score > 0.25f && inBounds);
        outKeypoints[joint].isVisible = outKeypoints[joint].visible;
        outKeypoints[joint].pos = {src.x, src.y};
    };

    // Direct MoveNet mappings
    setKeypoint(JOINT_NOSE, kps[0]);
    setKeypoint(JOINT_SHOULDER_LEFT, kps[5]);
    setKeypoint(JOINT_SHOULDER_RIGHT, kps[6]);
    setKeypoint(JOINT_ELBOW_LEFT, kps[7]);
    setKeypoint(JOINT_ELBOW_RIGHT, kps[8]);
    setKeypoint(JOINT_WRIST_LEFT, kps[9]);
    setKeypoint(JOINT_WRIST_RIGHT, kps[10]);
    setKeypoint(JOINT_HIP_LEFT, kps[11]);
    setKeypoint(JOINT_HIP_RIGHT, kps[12]);
    setKeypoint(JOINT_KNEE_LEFT, kps[13]);
    setKeypoint(JOINT_KNEE_RIGHT, kps[14]);
    setKeypoint(JOINT_ANKLE_LEFT, kps[15]);
    setKeypoint(JOINT_ANKLE_RIGHT, kps[16]);

    // Derived anatomical joints
    const auto& sL = outKeypoints[JOINT_SHOULDER_LEFT];
    const auto& sR = outKeypoints[JOINT_SHOULDER_RIGHT];
    const auto& hL = outKeypoints[JOINT_HIP_LEFT];
    const auto& hR = outKeypoints[JOINT_HIP_RIGHT];
    const auto& aL = outKeypoints[JOINT_ANKLE_LEFT];
    const auto& aR = outKeypoints[JOINT_ANKLE_RIGHT];

    // Neck = midpoint of shoulders
    if (sL.visible && sR.visible) {
        outKeypoints[JOINT_NECK].x = (sL.x + sR.x) * 0.5f;
        outKeypoints[JOINT_NECK].y = (sL.y + sR.y) * 0.5f;
        outKeypoints[JOINT_NECK].confidence = std::min(sL.confidence, sR.confidence);
        outKeypoints[JOINT_NECK].visible = true;
        outKeypoints[JOINT_NECK].isVisible = true;
        outKeypoints[JOINT_NECK].pos = {outKeypoints[JOINT_NECK].x, outKeypoints[JOINT_NECK].y};
    } else if (sL.visible) {
        outKeypoints[JOINT_NECK] = sL;
    } else if (sR.visible) {
        outKeypoints[JOINT_NECK] = sR;
    }

    // Pelvis center = midpoint of hips
    if (hL.visible && hR.visible) {
        outKeypoints[JOINT_PELVIS_CENTER].x = (hL.x + hR.x) * 0.5f;
        outKeypoints[JOINT_PELVIS_CENTER].y = (hL.y + hR.y) * 0.5f;
        outKeypoints[JOINT_PELVIS_CENTER].confidence = std::min(hL.confidence, hR.confidence);
        outKeypoints[JOINT_PELVIS_CENTER].visible = true;
        outKeypoints[JOINT_PELVIS_CENTER].isVisible = true;
        outKeypoints[JOINT_PELVIS_CENTER].pos = {outKeypoints[JOINT_PELVIS_CENTER].x, outKeypoints[JOINT_PELVIS_CENTER].y};
    }

    // Spine mid = midpoint of neck and pelvis
    if (outKeypoints[JOINT_NECK].visible && outKeypoints[JOINT_PELVIS_CENTER].visible) {
        outKeypoints[JOINT_SPINE_MID].x = (outKeypoints[JOINT_NECK].x + outKeypoints[JOINT_PELVIS_CENTER].x) * 0.5f;
        outKeypoints[JOINT_SPINE_MID].y = (outKeypoints[JOINT_NECK].y + outKeypoints[JOINT_PELVIS_CENTER].y) * 0.5f;
        outKeypoints[JOINT_SPINE_MID].confidence = (outKeypoints[JOINT_NECK].confidence + outKeypoints[JOINT_PELVIS_CENTER].confidence) * 0.5f;
        outKeypoints[JOINT_SPINE_MID].visible = true;
        outKeypoints[JOINT_SPINE_MID].isVisible = true;
        outKeypoints[JOINT_SPINE_MID].pos = {outKeypoints[JOINT_SPINE_MID].x, outKeypoints[JOINT_SPINE_MID].y};
    }

    // Feet: Heel and Toes based on Ankles
    if (aL.visible) {
        outKeypoints[JOINT_HEEL_LEFT].x = aL.x;
        outKeypoints[JOINT_HEEL_LEFT].y = std::min(static_cast<float>(height - 1), aL.y + 12.0f);
        outKeypoints[JOINT_HEEL_LEFT].confidence = aL.confidence * 0.9f;
        outKeypoints[JOINT_HEEL_LEFT].visible = true;
        outKeypoints[JOINT_HEEL_LEFT].isVisible = true;
        outKeypoints[JOINT_HEEL_LEFT].pos = {outKeypoints[JOINT_HEEL_LEFT].x, outKeypoints[JOINT_HEEL_LEFT].y};

        outKeypoints[JOINT_BIG_TOE_LEFT].x = std::max(0.0f, aL.x - 10.0f);
        outKeypoints[JOINT_BIG_TOE_LEFT].y = outKeypoints[JOINT_HEEL_LEFT].y;
        outKeypoints[JOINT_BIG_TOE_LEFT].confidence = aL.confidence * 0.85f;
        outKeypoints[JOINT_BIG_TOE_LEFT].visible = true;
        outKeypoints[JOINT_BIG_TOE_LEFT].isVisible = true;
        outKeypoints[JOINT_BIG_TOE_LEFT].pos = {outKeypoints[JOINT_BIG_TOE_LEFT].x, outKeypoints[JOINT_BIG_TOE_LEFT].y};
    }

    if (aR.visible) {
        outKeypoints[JOINT_HEEL_RIGHT].x = aR.x;
        outKeypoints[JOINT_HEEL_RIGHT].y = std::min(static_cast<float>(height - 1), aR.y + 12.0f);
        outKeypoints[JOINT_HEEL_RIGHT].confidence = aR.confidence * 0.9f;
        outKeypoints[JOINT_HEEL_RIGHT].visible = true;
        outKeypoints[JOINT_HEEL_RIGHT].isVisible = true;
        outKeypoints[JOINT_HEEL_RIGHT].pos = {outKeypoints[JOINT_HEEL_RIGHT].x, outKeypoints[JOINT_HEEL_RIGHT].y};

        outKeypoints[JOINT_BIG_TOE_RIGHT].x = std::min(static_cast<float>(width - 1), aR.x + 10.0f);
        outKeypoints[JOINT_BIG_TOE_RIGHT].y = outKeypoints[JOINT_HEEL_RIGHT].y;
        outKeypoints[JOINT_BIG_TOE_RIGHT].confidence = aR.confidence * 0.85f;
        outKeypoints[JOINT_BIG_TOE_RIGHT].visible = true;
        outKeypoints[JOINT_BIG_TOE_RIGHT].isVisible = true;
        outKeypoints[JOINT_BIG_TOE_RIGHT].pos = {outKeypoints[JOINT_BIG_TOE_RIGHT].x, outKeypoints[JOINT_BIG_TOE_RIGHT].y};
    }

    bool hasTorso = (sL.visible || sR.visible || outKeypoints[JOINT_NECK].visible);
    return hasTorso;
}

} // namespace meitu::ai

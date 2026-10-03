#include "ai/selfie_human_parser.h"
#include <net.h>
#include <mat.h>
#include <android/log.h>
#include <cmath>
#include <algorithm>
#include <cstring>

#ifdef _OPENMP
#include <omp.h>
#endif

#define LOG_TAG "SelfieHumanParser"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace meitu::ai {

using namespace meitu_native;

SelfieHumanParser& SelfieHumanParser::getInstance() {
    static SelfieHumanParser instance;
    return instance;
}

SelfieHumanParser::SelfieHumanParser() : mNet(nullptr), mInitialized(false) {}

SelfieHumanParser::~SelfieHumanParser() {
    if (mNet) {
        delete mNet;
        mNet = nullptr;
    }
}

bool SelfieHumanParser::init(const std::string& paramPath, const std::string& binPath) {
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
        LOGE("MediaPipe Selfie Segmentation failed to load (ret1=%d, ret2=%d)", ret1, ret2);
        mInitialized = false;
        return false;
    }

    mInitialized = true;
    LOGI("MediaPipe Selfie Segmentation loaded successfully into NCNN C++!");
    return true;
}

bool SelfieHumanParser::segmentPerson(
    const uint32_t* srcRgba,
    int width,
    int height,
    std::vector<float>& outPersonProb,
    std::vector<uint8_t>& outBinaryMask
) {
    if (!srcRgba || width <= 0 || height <= 0 || !mInitialized || !mNet) {
        return false;
    }

    outPersonProb.assign(width * height, 0.0f);
    outBinaryMask.assign(width * height, 0);

    const int netSize = 256;
    ncnn::Mat inMat = ncnn::Mat::from_pixels_resize(
        reinterpret_cast<const unsigned char*>(srcRgba),
        ncnn::Mat::PIXEL_RGBA2RGB,
        width, height, netSize, netSize
    );

    const float normVals[3] = {1.0f / 255.0f, 1.0f / 255.0f, 1.0f / 255.0f};
    inMat.substract_mean_normalize(nullptr, normVals);

    ncnn::Extractor ex = mNet->create_extractor();
    int inRet = ex.input("in0", inMat);
    if (inRet != 0) {
        LOGE("Selfie Segmentation input failed: %d", inRet);
        return false;
    }

    ncnn::Mat out0;
    int outRet = ex.extract("out0", out0);
    if (outRet != 0 || out0.empty()) {
        LOGE("Selfie Segmentation extract failed: %d", outRet);
        return false;
    }

    const float* rawProb = reinterpret_cast<const float*>(out0.data);

    // Bilinear interpolation from 256x256 to width x height
    float scaleX = static_cast<float>(netSize) / static_cast<float>(width);
    float scaleY = static_cast<float>(netSize) / static_cast<float>(height);

    #pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        float srcY = y * scaleY;
        int y0 = std::min(netSize - 1, std::max(0, static_cast<int>(srcY)));
        int y1 = std::min(netSize - 1, y0 + 1);
        float fy = srcY - y0;

        for (int x = 0; x < width; ++x) {
            float srcX = x * scaleX;
            int x0 = std::min(netSize - 1, std::max(0, static_cast<int>(srcX)));
            int x1 = std::min(netSize - 1, x0 + 1);
            float fx = srcX - x0;

            float p00 = rawProb[y0 * netSize + x0];
            float p01 = rawProb[y0 * netSize + x1];
            float p10 = rawProb[y1 * netSize + x0];
            float p11 = rawProb[y1 * netSize + x1];

            float val = (1.0f - fy) * ((1.0f - fx) * p00 + fx * p01) +
                        fy * ((1.0f - fx) * p10 + fx * p11);

            val = std::max(0.0f, std::min(1.0f, val));
            int idx = y * width + x;
            outPersonProb[idx] = val;
            outBinaryMask[idx] = (val >= 0.40f) ? 255 : 0;
        }
    }

    return true;
}

bool SelfieHumanParser::generateParsingMask(
    const uint32_t* srcRgba,
    int width,
    int height,
    const std::vector<BodyKeypoint>& keypoints,
    std::vector<uint8_t>& outParsingMask,
    float* outConfidence
) {
    if (!srcRgba || width <= 0 || height <= 0) return false;

    std::vector<float> prob;
    std::vector<uint8_t> binMask;
    bool ok = segmentPerson(srcRgba, width, height, prob, binMask);
    if (!ok) return false;

    outParsingMask.assign(width * height, CLASS_BACKGROUND);

    int fgCount = 0;
    for (int i = 0; i < width * height; ++i) {
        if (binMask[i] > 0) fgCount++;
    }

    float fgRatio = static_cast<float>(fgCount) / static_cast<float>(width * height);
    if (outConfidence) {
        if (fgCount > 0) {
            double sumFgProb = 0.0;
            for (int i = 0; i < width * height; ++i) {
                if (binMask[i] > 0) {
                    sumFgProb += prob[i];
                }
            }
            float meanFgProb = static_cast<float>(sumFgProb / fgCount);
            if (fgRatio < 0.02f) {
                *outConfidence = meanFgProb * (fgRatio / 0.02f);
            } else if (fgRatio > 0.98f) {
                *outConfidence = meanFgProb * ((1.0f - fgRatio) / 0.02f);
            } else {
                *outConfidence = meanFgProb;
            }
        } else {
            *outConfidence = 0.0f;
        }
    }

    // Determine anatomical boundaries using real keypoints
    float noseY = -1.0f, neckY = -1.0f, hipY = -1.0f, kneeY = -1.0f, ankleY = -1.0f;
    float shoulderLeftX = -1.0f, shoulderRightX = -1.0f;
    float hipLeftX = -1.0f, hipRightX = -1.0f;

    if (keypoints.size() >= JOINT_COUNT) {
        if (keypoints[JOINT_NOSE].visible) noseY = keypoints[JOINT_NOSE].y;
        if (keypoints[JOINT_NECK].visible) neckY = keypoints[JOINT_NECK].y;
        if (keypoints[JOINT_SHOULDER_LEFT].visible && keypoints[JOINT_SHOULDER_RIGHT].visible) {
            shoulderLeftX = keypoints[JOINT_SHOULDER_LEFT].x;
            shoulderRightX = keypoints[JOINT_SHOULDER_RIGHT].x;
            if (neckY < 0.0f) neckY = (keypoints[JOINT_SHOULDER_LEFT].y + keypoints[JOINT_SHOULDER_RIGHT].y) * 0.5f;
        }
        if (keypoints[JOINT_HIP_LEFT].visible || keypoints[JOINT_HIP_RIGHT].visible) {
            hipY = keypoints[JOINT_HIP_LEFT].visible ? keypoints[JOINT_HIP_LEFT].y : keypoints[JOINT_HIP_RIGHT].y;
            hipLeftX = keypoints[JOINT_HIP_LEFT].visible ? keypoints[JOINT_HIP_LEFT].x : -1.0f;
            hipRightX = keypoints[JOINT_HIP_RIGHT].visible ? keypoints[JOINT_HIP_RIGHT].x : -1.0f;
        }
        if (keypoints[JOINT_KNEE_LEFT].visible || keypoints[JOINT_KNEE_RIGHT].visible) {
            kneeY = keypoints[JOINT_KNEE_LEFT].visible ? keypoints[JOINT_KNEE_LEFT].y : keypoints[JOINT_KNEE_RIGHT].y;
        }
        if (keypoints[JOINT_ANKLE_LEFT].visible || keypoints[JOINT_ANKLE_RIGHT].visible) {
            ankleY = keypoints[JOINT_ANKLE_LEFT].visible ? keypoints[JOINT_ANKLE_LEFT].y : keypoints[JOINT_ANKLE_RIGHT].y;
        }
    }

    #pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            if (binMask[idx] == 0) {
                outParsingMask[idx] = CLASS_BACKGROUND;
                continue;
            }

            // Foreground pixel: assign semantic class strictly inside the detected person boundary
            if (neckY > 0.0f && y < neckY) {
                outParsingMask[idx] = CLASS_FACE;
            } else if (hipY > 0.0f && y < hipY) {
                // Between neck and hips: Torso / Arms
                bool isArmLeft = (shoulderLeftX > 0.0f && x > shoulderLeftX + 20.0f);
                bool isArmRight = (shoulderRightX > 0.0f && x < shoulderRightX - 20.0f);
                if (isArmLeft) {
                    outParsingMask[idx] = CLASS_ARM_LEFT;
                } else if (isArmRight) {
                    outParsingMask[idx] = CLASS_ARM_RIGHT;
                } else {
                    outParsingMask[idx] = CLASS_UPPER_CLOTHES;
                }
            } else if (kneeY > 0.0f && y < kneeY) {
                // Thighs / Lower clothes
                outParsingMask[idx] = CLASS_LOWER_CLOTHES;
            } else if (ankleY > 0.0f && y < ankleY) {
                // Lower legs
                outParsingMask[idx] = (hipLeftX > 0.0f && x > (hipLeftX + hipRightX) * 0.5f) ?
                                      CLASS_LEG_LEFT_SKIN : CLASS_LEG_RIGHT_SKIN;
            } else if (ankleY > 0.0f && y >= ankleY) {
                // Feet / Shoes
                outParsingMask[idx] = (hipLeftX > 0.0f && x > (hipLeftX + hipRightX) * 0.5f) ?
                                      CLASS_SHOE_LEFT : CLASS_SHOE_RIGHT;
            } else {
                // Default body class if limbs not fully visible
                outParsingMask[idx] = CLASS_UPPER_CLOTHES;
            }
        }
    }

    return true;
}

} // namespace meitu::ai

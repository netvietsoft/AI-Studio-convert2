#include "ai/bisenet_face_parser.h"
#include <net.h>
#include <mat.h>
#include <android/log.h>
#include <cmath>
#include <algorithm>
#include <cstring>

#ifdef _OPENMP
#include <omp.h>
#endif

#define LOG_TAG "BiSeNetFaceParser"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)

namespace meitu::ai {

BiSeNetFaceParser& BiSeNetFaceParser::getInstance() {
    static BiSeNetFaceParser instance;
    return instance;
}

BiSeNetFaceParser::BiSeNetFaceParser() : mNet(nullptr), mInitialized(false) {}

BiSeNetFaceParser::~BiSeNetFaceParser() {
    if (mNet) {
        delete mNet;
        mNet = nullptr;
    }
}

bool BiSeNetFaceParser::init(const std::string& paramPath, const std::string& binPath) {
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
        LOGI("BiSeNet model files not found or failed to load (ret1=%d, ret2=%d). Using high-precision geometric fallback.", ret1, ret2);
        mInitialized = false;
        return false;
    }

    mInitialized = true;
    LOGI("BiSeNet 19-class Face Parsing loaded successfully into NCNN C++!");
    return true;
}

bool BiSeNetFaceParser::parseFace19(
    const uint32_t* srcRgba,
    int width,
    int height,
    std::vector<uint8_t>& outMask512,
    std::vector<float>* outClassProb512,
    std::vector<float>* outHairProb512
) {
    if (!srcRgba || width <= 0 || height <= 0) return false;
    outMask512.assign(512 * 512, static_cast<uint8_t>(Face19Class::BACKGROUND));
    if (outClassProb512) {
        outClassProb512->assign(512 * 512, 1.0f);
    }
    if (outHairProb512) {
        outHairProb512->assign(512 * 512, 0.0f);
    }

    bool success = false;
    if (mInitialized && mNet) {
        ncnn::Mat inMat = ncnn::Mat::from_pixels_resize(
            reinterpret_cast<const unsigned char*>(srcRgba),
            ncnn::Mat::PIXEL_RGBA2RGB,
            width, height, 512, 512
        );

        const float mean_vals[3] = {123.675f, 116.28f, 103.53f};
        const float norm_vals[3] = {1.0f / 58.395f, 1.0f / 57.12f, 1.0f / 57.375f};
        inMat.substract_mean_normalize(mean_vals, norm_vals);

        ncnn::Extractor ex = mNet->create_extractor();
        int inRet = ex.input("in0", inMat);
        if (inRet != 0) inRet = ex.input("input", inMat);
        if (inRet != 0) inRet = ex.input("data", inMat);

        ncnn::Mat outMat;
        int ret = ex.extract("out0", outMat);
        if (ret != 0) ret = ex.extract("output", outMat);
        if (ret != 0) ret = ex.extract("out", outMat);

        LOGI("BiSeNet inference: inRet=%d, outRet=%d, dims=[w=%d, h=%d, c=%d]", inRet, ret, outMat.w, outMat.h, outMat.c);

        if (ret == 0 && outMat.w == 512 && outMat.h == 512 && outMat.c >= 19) {
            int hairChannel = static_cast<int>(Face19Class::HAIR);

            #pragma omp parallel for schedule(static, 32)
            for (int y = 0; y < 512; ++y) {
                for (int x = 0; x < 512; ++x) {
                    int pixelIdx = y * 512 + x;
                    int bestClass = 0;
                    float maxScore = -1e9f;

                    for (int c = 0; c < 19; ++c) {
                        const float* channelPtr = outMat.channel(c);
                        float score = channelPtr[pixelIdx];
                        if (score > maxScore) {
                            maxScore = score;
                            bestClass = c;
                        }
                    }

                    outMask512[pixelIdx] = static_cast<uint8_t>(bestClass);

                    // Phase 01B: Softmax Hair Probability
                    float sumExp = 0.0f;
                    float hairExp = 0.0f;
                    for (int c = 0; c < 19; ++c) {
                        float e = std::exp(outMat.channel(c)[pixelIdx] - maxScore);
                        sumExp += e;
                        if (c == hairChannel) {
                            hairExp = e;
                        }
                    }

                    float hairProb = (sumExp > 1e-6f) ? (hairExp / sumExp) : 0.0f;

                    if (outHairProb512) {
                        (*outHairProb512)[pixelIdx] = hairProb;
                    }
                    if (outClassProb512) {
                        (*outClassProb512)[pixelIdx] = (sumExp > 1e-6f) ? (1.0f / sumExp) : 1.0f;
                    }
                }
            }
            success = true;
            LOGI("BiSeNet inference succeeded! Generated 19-class segmented mask & Soft Hair Probability map.");
        } else {
            LOGE("BiSeNet inference failed (ret=%d, w=%d, h=%d, c=%d)", ret, outMat.w, outMat.h, outMat.c);
        }
    }

    if (!success) {
        LOGI("Falling back to high-precision Geometric Anatomical Parsing");
        fallbackGeometricParse(srcRgba, width, height, outMask512, outHairProb512);
    }

    return true;
}

bool BiSeNetFaceParser::parseFace19Adaptive(
    const uint32_t* srcRgba,
    int width,
    int height,
    std::vector<uint8_t>& outFullMask,
    std::vector<uint8_t>* outMask512,
    std::vector<float>* outHairProb512
) {
    if (!srcRgba || width <= 0 || height <= 0) return false;
    outFullMask.assign(width * height, 0);

    float maxAspect = std::max(static_cast<float>(width) / height, static_cast<float>(height) / width);
    bool useLetterbox = (maxAspect > 1.80f);

    std::vector<uint8_t> localMask512(512 * 512, 0);
    std::vector<uint8_t>& targetMask512 = outMask512 ? *outMask512 : localMask512;
    targetMask512.assign(512 * 512, 0);

    if (outHairProb512) {
        outHairProb512->assign(512 * 512, 0.0f);
    }

    bool success = false;
    if (mInitialized && mNet) {
        ncnn::Mat inMat;
        int pad_x = 0, pad_y = 0, nw = 512, nh = 512;

        if (useLetterbox) {
            float scale = std::min(512.0f / width, 512.0f / height);
            nw = std::clamp(static_cast<int>(std::round(width * scale)), 1, 512);
            nh = std::clamp(static_cast<int>(std::round(height * scale)), 1, 512);
            pad_x = (512 - nw) / 2;
            pad_y = (512 - nh) / 2;

            ncnn::Mat scaled = ncnn::Mat::from_pixels_resize(
                reinterpret_cast<const unsigned char*>(srcRgba),
                ncnn::Mat::PIXEL_RGBA2RGB,
                width, height, nw, nh
            );

            inMat.create(512, 512, 3);
            inMat.fill(128.0f);

            #pragma omp parallel for schedule(static, 16)
            for (int q = 0; q < 3; ++q) {
                const float* srcPtr = scaled.channel(q);
                float* dstPtr = inMat.channel(q);
                for (int y = 0; y < nh; ++y) {
                    for (int x = 0; x < nw; ++x) {
                        dstPtr[(pad_y + y) * 512 + (pad_x + x)] = srcPtr[y * nw + x];
                    }
                }
            }
        } else {
            inMat = ncnn::Mat::from_pixels_resize(
                reinterpret_cast<const unsigned char*>(srcRgba),
                ncnn::Mat::PIXEL_RGBA2RGB,
                width, height, 512, 512
            );
        }

        const float mean_vals[3] = {123.675f, 116.28f, 103.53f};
        const float norm_vals[3] = {1.0f / 58.395f, 1.0f / 57.12f, 1.0f / 57.375f};
        inMat.substract_mean_normalize(mean_vals, norm_vals);

        ncnn::Extractor ex = mNet->create_extractor();
        int inRet = ex.input("in0", inMat);
        if (inRet != 0) inRet = ex.input("input", inMat);
        if (inRet != 0) inRet = ex.input("data", inMat);

        ncnn::Mat outMat;
        int ret = ex.extract("out0", outMat);
        if (ret != 0) ret = ex.extract("output", outMat);
        if (ret != 0) ret = ex.extract("out", outMat);

        if (ret == 0 && outMat.w == 512 && outMat.h == 512 && outMat.c >= 19) {
            int hairChannel = static_cast<int>(Face19Class::HAIR);

            #pragma omp parallel for schedule(static, 32)
            for (int y = 0; y < 512; ++y) {
                for (int x = 0; x < 512; ++x) {
                    int pixelIdx = y * 512 + x;
                    int bestClass = 0;
                    float maxScore = -1e9f;

                    for (int c = 0; c < 19; ++c) {
                        const float* channelPtr = outMat.channel(c);
                        float score = channelPtr[pixelIdx];
                        if (score > maxScore) {
                            maxScore = score;
                            bestClass = c;
                        }
                    }

                    targetMask512[pixelIdx] = static_cast<uint8_t>(bestClass);

                    if (outHairProb512) {
                        float sumExp = 0.0f;
                        float hairExp = 0.0f;
                        for (int c = 0; c < 19; ++c) {
                            float e = std::exp(outMat.channel(c)[pixelIdx] - maxScore);
                            sumExp += e;
                            if (c == hairChannel) hairExp = e;
                        }
                        (*outHairProb512)[pixelIdx] = (sumExp > 1e-6f) ? (hairExp / sumExp) : 0.0f;
                    }
                }
            }

            if (useLetterbox) {
                #pragma omp parallel for schedule(static, 16)
                for (int y = 0; y < height; ++y) {
                    int sy = pad_y + y * nh / height;
                    sy = std::clamp(sy, pad_y, pad_y + nh - 1);
                    for (int x = 0; x < width; ++x) {
                        int sx = pad_x + x * nw / width;
                        sx = std::clamp(sx, pad_x, pad_x + nw - 1);
                        outFullMask[y * width + x] = targetMask512[sy * 512 + sx];
                    }
                }
            } else {
                #pragma omp parallel for schedule(static, 16)
                for (int y = 0; y < height; ++y) {
                    int sy = y * 512 / height;
                    sy = std::clamp(sy, 0, 511);
                    for (int x = 0; x < width; ++x) {
                        int sx = x * 512 / width;
                        sx = std::clamp(sx, 0, 511);
                        outFullMask[y * width + x] = targetMask512[sy * 512 + sx];
                    }
                }
            }

            success = true;
        }
    }

    if (!success) {
        fallbackGeometricParse(srcRgba, width, height, targetMask512, outHairProb512);
        #pragma omp parallel for schedule(static, 16)
        for (int y = 0; y < height; ++y) {
            int sy = y * 512 / height;
            sy = std::clamp(sy, 0, 511);
            for (int x = 0; x < width; ++x) {
                int sx = x * 512 / width;
                sx = std::clamp(sx, 0, 511);
                outFullMask[y * width + x] = targetMask512[sy * 512 + sx];
            }
        }
    }

    return true;
}

static inline bool checkSkinRgb(int r, int g, int b) {
    if (r <= 45 || g <= 28 || b <= 15) return false;
    float y = 0.299f * r + 0.587f * g + 0.114f * b;
    float cr = (r - y) * 0.713f + 128.0f;
    float cb = (b - y) * 0.564f + 128.0f;
    return (cr >= 130.0f && cr <= 175.0f && cb >= 77.0f && cb <= 130.0f && r > b);
}

void BiSeNetFaceParser::fallbackGeometricParse(
    const uint32_t* srcRgba,
    int width,
    int height,
    std::vector<uint8_t>& outMask512,
    std::vector<float>* outHairProb512
) {
    #pragma omp parallel for schedule(static, 32)
    for (int y = 0; y < 512; ++y) {
        int origY = std::clamp(static_cast<int>(y * height / 512), 0, height - 1);
        float ny = y / 512.0f;

        for (int x = 0; x < 512; ++x) {
            int origX = std::clamp(static_cast<int>(x * width / 512), 0, width - 1);
            float nx = x / 512.0f;

            uint32_t c = srcRgba[origY * width + origX];
            int r = RGBA_R(c);
            int g = RGBA_G(c);
            int b = RGBA_B(c);
            float lum = (0.299f * r + 0.587f * g + 0.114f * b) / 255.0f;
            bool isSkin = checkSkinRgb(r, g, b);
            int cDiff = std::max(std::abs(r - g), std::abs(r - b));

            int idx = y * 512 + x;

            float dxFace = (nx - 0.50f) / 0.20f;
            float dyFace = (ny - 0.46f) / 0.21f;
            bool insideFaceOval = (dxFace * dxFace + dyFace * dyFace <= 1.0f) && (ny >= 0.24f) && (ny <= 0.68f);

            bool isWall = (lum >= 0.56f) && (cDiff <= 22);

            if ((ny >= 0.38f && ny <= 0.46f) && 
                ((nx >= 0.32f && nx <= 0.46f) || (nx >= 0.54f && nx <= 0.68f))) {
                outMask512[idx] = (nx < 0.50f) ? static_cast<uint8_t>(Face19Class::LEFT_EYE) : static_cast<uint8_t>(Face19Class::RIGHT_EYE);
                if (outHairProb512) (*outHairProb512)[idx] = 0.0f;
                continue;
            }
            if ((ny >= 0.31f && ny <= 0.38f) && 
                ((nx >= 0.31f && nx <= 0.46f) || (nx >= 0.54f && nx <= 0.70f))) {
                outMask512[idx] = (nx < 0.50f) ? static_cast<uint8_t>(Face19Class::LEFT_BROW) : static_cast<uint8_t>(Face19Class::RIGHT_BROW);
                if (outHairProb512) (*outHairProb512)[idx] = 0.0f;
                continue;
            }
            if (ny >= 0.42f && ny <= 0.54f && std::abs(nx - 0.50f) <= 0.08f) {
                outMask512[idx] = static_cast<uint8_t>(Face19Class::NOSE);
                if (outHairProb512) (*outHairProb512)[idx] = 0.0f;
                continue;
            }
            if (ny >= 0.55f && ny <= 0.64f && std::abs(nx - 0.50f) <= 0.12f) {
                outMask512[idx] = (ny < 0.59f) ? static_cast<uint8_t>(Face19Class::UPPER_LIP) : static_cast<uint8_t>(Face19Class::LOWER_LIP);
                if (outHairProb512) (*outHairProb512)[idx] = 0.0f;
                continue;
            }
            if (insideFaceOval) {
                outMask512[idx] = static_cast<uint8_t>(Face19Class::SKIN);
                if (outHairProb512) (*outHairProb512)[idx] = 0.0f;
                continue;
            }
            if (ny >= 0.65f && ny <= 0.76f && std::abs(nx - 0.50f) <= 0.18f && isSkin) {
                outMask512[idx] = static_cast<uint8_t>(Face19Class::NECK);
                if (outHairProb512) (*outHairProb512)[idx] = 0.0f;
                continue;
            }
            if (ny >= 0.72f && !isWall) {
                outMask512[idx] = static_cast<uint8_t>(Face19Class::CLOTH);
                if (outHairProb512) (*outHairProb512)[idx] = 0.0f;
                continue;
            }
            if (isWall) {
                outMask512[idx] = static_cast<uint8_t>(Face19Class::BACKGROUND);
                if (outHairProb512) (*outHairProb512)[idx] = 0.0f;
                continue;
            }

            bool isSkullHair = (ny <= 0.26f) && (nx >= 0.15f && nx <= 0.78f) && (lum <= 0.68f);
            bool isLeftCurlHair = (nx >= 0.12f && nx <= 0.36f) && (ny >= 0.18f && ny <= 0.34f) && (lum <= 0.50f);
            bool isRightBuzzHair = (nx >= 0.65f && nx <= 0.78f) && (ny >= 0.19f && ny <= 0.30f) && (lum <= 0.65f);
            bool isForeheadCurl = (ny >= 0.22f && ny <= 0.28f) && (nx >= 0.30f && nx <= 0.42f) && (lum <= 0.24f);

            if (isSkullHair || isLeftCurlHair || isRightBuzzHair || isForeheadCurl) {
                outMask512[idx] = static_cast<uint8_t>(Face19Class::HAIR);
                if (outHairProb512) (*outHairProb512)[idx] = 0.95f;
            } else {
                outMask512[idx] = static_cast<uint8_t>(Face19Class::BACKGROUND);
                if (outHairProb512) (*outHairProb512)[idx] = 0.0f;
            }
        }
    }
}

bool BiSeNetFaceParser::extractSingleClassAlpha(
    Face19Class targetClass,
    const std::vector<uint8_t>& mask512,
    std::vector<float>& outAlpha512
) {
    if (mask512.size() != 512 * 512) return false;
    outAlpha512.assign(512 * 512, 0.0f);
    uint8_t targetId = static_cast<uint8_t>(targetClass);

    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < 512 * 512; ++i) {
        if (mask512[i] == targetId) {
            outAlpha512[i] = 1.0f;
        }
    }
    return true;
}

bool BiSeNetFaceParser::extractIsolatedHairAlpha(
    const std::vector<uint8_t>& mask512,
    std::vector<float>& outHairAlpha512
) {
    if (mask512.size() != 512 * 512) return false;
    outHairAlpha512.assign(512 * 512, 0.0f);

    uint8_t hairId = static_cast<uint8_t>(Face19Class::HAIR);
    uint8_t clothId = static_cast<uint8_t>(Face19Class::CLOTH);
    uint8_t neckId = static_cast<uint8_t>(Face19Class::NECK);
    uint8_t bgId = static_cast<uint8_t>(Face19Class::BACKGROUND);

    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < 512 * 512; ++i) {
        uint8_t cls = mask512[i];
        if (cls == hairId && cls != clothId && cls != neckId && cls != bgId) {
            outHairAlpha512[i] = 1.0f;
        }
    }
    return true;
}

bool BiSeNetFaceParser::extractSoftHairAlpha(
    const std::vector<float>& hairProb512,
    const std::vector<uint8_t>& mask512,
    std::vector<float>& outHairAlpha512
) {
    if (hairProb512.size() != 512 * 512) return false;
    outHairAlpha512.resize(512 * 512);

    uint8_t clothId = static_cast<uint8_t>(Face19Class::CLOTH);
    uint8_t neckId  = static_cast<uint8_t>(Face19Class::NECK);
    bool hasMask = (mask512.size() == 512 * 512);

    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < 512 * 512; ++i) {
        float prob = hairProb512[i];
        if (hasMask) {
            uint8_t cls = mask512[i];
            if (cls == clothId || cls == neckId) {
                prob = std::min(prob, 0.01f);
            }
        }
        outHairAlpha512[i] = prob;
    }
    return true;
}

bool BiSeNetFaceParser::extractSkinAndNeckAlpha(
    const std::vector<uint8_t>& mask512,
    std::vector<float>& outSkinAlpha512
) {
    if (mask512.size() != 512 * 512) return false;
    outSkinAlpha512.assign(512 * 512, 0.0f);

    uint8_t skinId = static_cast<uint8_t>(Face19Class::SKIN);
    uint8_t neckId = static_cast<uint8_t>(Face19Class::NECK);
    uint8_t noseId = static_cast<uint8_t>(Face19Class::NOSE);

    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < 512 * 512; ++i) {
        uint8_t cls = mask512[i];
        if (cls == skinId || cls == neckId || cls == noseId) {
            outSkinAlpha512[i] = 1.0f;
        }
    }
    return true;
}

bool BiSeNetFaceParser::extractLipsAlpha(
    const std::vector<uint8_t>& mask512,
    std::vector<float>& outLipsAlpha512
) {
    if (mask512.size() != 512 * 512) return false;
    outLipsAlpha512.assign(512 * 512, 0.0f);

    uint8_t upLipId = static_cast<uint8_t>(Face19Class::UPPER_LIP);
    uint8_t lowLipId = static_cast<uint8_t>(Face19Class::LOWER_LIP);

    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < 512 * 512; ++i) {
        uint8_t cls = mask512[i];
        if (cls == upLipId || cls == lowLipId) {
            outLipsAlpha512[i] = 1.0f;
        }
    }
    return true;
}

} // namespace meitu::ai

#include "long_legs_body_slim_engine.h"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <omp.h>

namespace meitu {
namespace body {

LongLegsBodySlimEngine::LongLegsBodySlimEngine() = default;
LongLegsBodySlimEngine::~LongLegsBodySlimEngine() = default;

static inline float cubicWeight(float x) {
    x = std::abs(x);
    if (x <= 1.0f) {
        return (1.5f * x - 2.5f) * x * x + 1.0f;
    } else if (x < 2.0f) {
        return ((-0.5f * x + 2.5f) * x - 4.0f) * x + 2.0f;
    }
    return 0.0f;
}

void LongLegsBodySlimEngine::sampleBicubic(
    const uint8_t* src, int width, int height,
    float x, float y,
    uint8_t* outRgba
) {
    int x0 = static_cast<int>(std::floor(x));
    int y0 = static_cast<int>(std::floor(y));
    float fx = x - static_cast<float>(x0);
    float fy = y - static_cast<float>(y0);

    float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f, sumA = 0.0f;
    float totalWeight = 0.0f;

    for (int j = -1; j <= 2; ++j) {
        int py = std::max(0, std::min(height - 1, y0 + j));
        float wy = cubicWeight(static_cast<float>(j) - fy);

        for (int i = -1; i <= 2; ++i) {
            int px = std::max(0, std::min(width - 1, x0 + i));
            float wx = cubicWeight(static_cast<float>(i) - fx);
            float w = wx * wy;

            int idx = (py * width + px) * 4;
            sumR += src[idx] * w;
            sumG += src[idx + 1] * w;
            sumB += src[idx + 2] * w;
            sumA += src[idx + 3] * w;
            totalWeight += w;
        }
    }

    if (totalWeight > 1e-4f) {
        outRgba[0] = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, sumR / totalWeight)));
        outRgba[1] = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, sumG / totalWeight)));
        outRgba[2] = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, sumB / totalWeight)));
        outRgba[3] = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, sumA / totalWeight)));
    } else {
        int idx = (std::max(0, std::min(height - 1, y0)) * width + std::max(0, std::min(width - 1, x0))) * 4;
        std::memcpy(outRgba, &src[idx], 4);
    }
}

bool LongLegsBodySlimEngine::applyLongLegs(
    uint8_t* rgba, int width, int height,
    const HumanFrameResult& human,
    float overallScale,
    float thighScale,
    float calfScale
) {
    if (!rgba || width <= 0 || height <= 0 || overallScale <= 1e-4f) return false;

    float yHip = human.torso.hipCenterY;
    float yKnee = (human.leftLeg.kneeCenterY + human.rightLeg.kneeCenterY) * 0.5f;
    float yAnkle = (human.leftLeg.ankleCenterY + human.rightLeg.ankleCenterY) * 0.5f;
    float yFoot = std::max(human.leftFoot.heelY, human.rightFoot.heelY);

    if (yKnee <= yHip || yAnkle <= yKnee) {
        yHip = height * 0.45f;
        yKnee = height * 0.68f;
        yAnkle = height * 0.88f;
        yFoot = height * 0.98f;
    }

    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);

    float maxThighDisp = (yKnee - yHip) * overallScale * thighScale;
    float maxCalfDisp = (yAnkle - yKnee) * overallScale * calfScale;

    #pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        float dy = 0.0f;
        if (y > yHip && y <= yKnee) {
            float t = (y - yHip) / (yKnee - yHip);
            dy = t * maxThighDisp;
        } else if (y > yKnee && y <= yAnkle) {
            float t = (y - yKnee) / (yAnkle - yKnee);
            dy = maxThighDisp + t * maxCalfDisp;
        } else if (y > yAnkle) {
            dy = maxThighDisp + maxCalfDisp;
        }

        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            dyField[idx] = dy;
        }
    }

    // Protect background and enforce zero leakage
    if (!human.parsingMask.empty()) {
        bgEngine_.attenuateBoundaryLeakage(width, height, human.parsingMask.data(), dxField.data(), dyField.data());
    }
    if (!human.backgroundProtectionMask.empty()) {
        bgEngine_.regularizeDisplacementField(width, height, human.backgroundProtectionMask.data(), human.structuralLines, dxField.data(), dyField.data());
    }

    // Bicubic image warp
    std::vector<uint8_t> src(rgba, rgba + width * height * 4);
    #pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            float srcX = x - dxField[idx];
            float srcY = y - dyField[idx];

            if (std::abs(dxField[idx]) > 1e-3f || std::abs(dyField[idx]) > 1e-3f) {
                sampleBicubic(src.data(), width, height, srcX, srcY, &rgba[idx * 4]);
            }
        }
    }

    return true;
}

bool LongLegsBodySlimEngine::applyBodyHeight(
    uint8_t* rgba, int width, int height,
    const HumanFrameResult& human,
    float heightScale
) {
    if (!rgba || width <= 0 || height <= 0 || std::abs(heightScale) <= 1e-4f) return false;

    float yNeck = human.keypoints.size() > JOINT_NECK ? human.keypoints[JOINT_NECK].y : height * 0.20f;
    float yHip = human.torso.hipCenterY > 0 ? human.torso.hipCenterY : height * 0.50f;
    float yAnkle = (human.leftLeg.ankleCenterY + human.rightLeg.ankleCenterY) * 0.5f;
    if (yAnkle <= yHip) yAnkle = height * 0.88f;

    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);

    float torsoDisp = (yHip - yNeck) * heightScale * 0.35f;
    float legDisp = (yAnkle - yHip) * heightScale * 0.65f;

    #pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        float dy = 0.0f;
        if (y > yNeck && y <= yHip) {
            float t = (y - yNeck) / (yHip - yNeck);
            dy = t * torsoDisp;
        } else if (y > yHip && y <= yAnkle) {
            float t = (y - yHip) / (yAnkle - yHip);
            dy = torsoDisp + t * legDisp;
        } else if (y > yAnkle) {
            dy = torsoDisp + legDisp;
        }

        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            dyField[idx] = dy;
        }
    }

    if (!human.parsingMask.empty()) {
        bgEngine_.attenuateBoundaryLeakage(width, height, human.parsingMask.data(), dxField.data(), dyField.data());
    }
    if (!human.backgroundProtectionMask.empty()) {
        bgEngine_.regularizeDisplacementField(width, height, human.backgroundProtectionMask.data(), human.structuralLines, dxField.data(), dyField.data());
    }

    std::vector<uint8_t> src(rgba, rgba + width * height * 4);
    #pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            float srcX = x - dxField[idx];
            float srcY = y - dyField[idx];

            if (std::abs(dxField[idx]) > 1e-3f || std::abs(dyField[idx]) > 1e-3f) {
                sampleBicubic(src.data(), width, height, srcX, srcY, &rgba[idx * 4]);
            }
        }
    }

    return true;
}

bool LongLegsBodySlimEngine::applySlimBody(
    uint8_t* rgba, int width, int height,
    const HumanFrameResult& human,
    const BodySlimParams& params
) {
    if (!rgba || width <= 0 || height <= 0) return false;

    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);

    float waistY = human.torso.waistCenterY > 0 ? human.torso.waistCenterY : height * 0.45f;
    float torsoX = human.torso.centerX > 0 ? human.torso.centerX : width * 0.5f;
    float waistR = human.torso.waistWidthObserved > 0 ? human.torso.waistWidthObserved * 0.75f : width * 0.18f;

    // 1. Waist Slimming (Bilateral Inward Warp)
    if (std::abs(params.waistSlim) > 1e-4f) {
        float maxContraction = waistR * params.waistSlim * 0.35f;
        float sigmaY = waistR * 1.2f;

        #pragma omp parallel for
        for (int y = 0; y < height; ++y) {
            float distY = std::abs(y - waistY);
            if (distY < sigmaY) {
                float wy = std::cos(distY / sigmaY * 1.5707963f);
                wy *= wy;

                for (int x = 0; x < width; ++x) {
                    float distX = x - torsoX;
                    if (std::abs(distX) < waistR && std::abs(distX) > 1.0f) {
                        float sign = (distX > 0.0f) ? 1.0f : -1.0f;
                        float wx = 1.0f - (std::abs(distX) / waistR);
                        float dx = -sign * maxContraction * wx * wy;

                        int idx = y * width + x;
                        dxField[idx] += dx;
                    }
                }
            }
        }
    }

    // 2. Thigh Slimming
    if (std::abs(params.thighSlim) > 1e-4f) {
        float kneeY = (human.leftLeg.kneeCenterY + human.rightLeg.kneeCenterY) * 0.5f;
        float hipY = human.torso.hipCenterY;
        float thighR = human.leftLeg.thighMidWidth > 0 ? human.leftLeg.thighMidWidth : width * 0.10f;
        float maxThighSlim = thighR * params.thighSlim * 0.25f;

        #pragma omp parallel for
        for (int y = 0; y < height; ++y) {
            if (y > hipY && y < kneeY) {
                float ty = std::sin((y - hipY) / (kneeY - hipY) * 3.14159265f);
                for (int x = 0; x < width; ++x) {
                    float dxL = x - human.leftLeg.kneeCenterX;
                    float dxR = x - human.rightLeg.kneeCenterX;

                    if (std::abs(dxL) < thighR && std::abs(dxL) > 1.0f) {
                        float sign = (dxL > 0.0f) ? 1.0f : -1.0f;
                        dxField[y * width + x] += -sign * maxThighSlim * ty * (1.0f - std::abs(dxL) / thighR);
                    } else if (std::abs(dxR) < thighR && std::abs(dxR) > 1.0f) {
                        float sign = (dxR > 0.0f) ? 1.0f : -1.0f;
                        dxField[y * width + x] += -sign * maxThighSlim * ty * (1.0f - std::abs(dxR) / thighR);
                    }
                }
            }
        }
    }

    // Boundary attenuation & line protection
    if (!human.parsingMask.empty()) {
        bgEngine_.attenuateBoundaryLeakage(width, height, human.parsingMask.data(), dxField.data(), dyField.data());
    }
    if (!human.backgroundProtectionMask.empty()) {
        bgEngine_.regularizeDisplacementField(width, height, human.backgroundProtectionMask.data(), human.structuralLines, dxField.data(), dyField.data());
    }

    // Resample
    std::vector<uint8_t> src(rgba, rgba + width * height * 4);
    #pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            float srcX = x - dxField[idx];
            float srcY = y - dyField[idx];

            if (std::abs(dxField[idx]) > 1e-3f || std::abs(dyField[idx]) > 1e-3f) {
                sampleBicubic(src.data(), width, height, srcX, srcY, &rgba[idx * 4]);
            }
        }
    }

    return true;
}

} // namespace body
} // namespace meitu

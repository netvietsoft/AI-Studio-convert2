#include "body_limb_hand_engine.h"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <omp.h>

namespace meitu {
namespace body {

BodyLimbHandEngine::BodyLimbHandEngine() = default;
BodyLimbHandEngine::~BodyLimbHandEngine() = default;

static inline float cubicWeight(float x) {
    x = std::abs(x);
    if (x <= 1.0f) {
        return (1.5f * x - 2.5f) * x * x + 1.0f;
    } else if (x < 2.0f) {
        return ((-0.5f * x + 2.5f) * x - 4.0f) * x + 2.0f;
    }
    return 0.0f;
}

void BodyLimbHandEngine::sampleBicubic(
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

static inline void slimSegment(
    float ax, float ay, float bx, float by,
    float radius, float intensity,
    int width, int height,
    float* dxField, float* dyField
) {
    float vx = bx - ax;
    float vy = by - ay;
    float len = std::sqrt(vx * vx + vy * vy);
    if (len < 1e-3f) return;
    vx /= len;
    vy /= len;

    float nx = -vy;
    float ny = vx;

    int minX = std::max(0, static_cast<int>(std::min(ax, bx) - radius));
    int maxX = std::min(width - 1, static_cast<int>(std::max(ax, bx) + radius));
    int minY = std::max(0, static_cast<int>(std::min(ay, by) - radius));
    int maxY = std::min(height - 1, static_cast<int>(std::max(ay, by) + radius));

    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            float px = x - ax;
            float py = y - ay;
            float proj = px * vx + py * vy;

            if (proj >= 0.0f && proj <= len) {
                float distPerp = px * nx + py * ny;
                if (std::abs(distPerp) < radius && std::abs(distPerp) > 0.5f) {
                    float sign = (distPerp > 0.0f) ? 1.0f : -1.0f;
                    float wRadial = 1.0f - (std::abs(distPerp) / radius);
                    float wTaper = std::sin(proj / len * 3.14159265f);
                    float disp = -sign * intensity * radius * wRadial * wTaper * 0.30f;

                    int idx = y * width + x;
                    dxField[idx] += disp * nx;
                    dyField[idx] += disp * ny;
                }
            }
        }
    }
}

bool BodyLimbHandEngine::applyArmSlim(
    uint8_t* rgba, int width, int height,
    const HumanFrameResult& human,
    float upperArmSlim,
    float forearmSlim
) {
    if (!rgba || width <= 0 || height <= 0 || (upperArmSlim <= 1e-4f && forearmSlim <= 1e-4f)) return false;
    if (human.keypoints.size() < JOINT_COUNT) return false;

    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);

    const auto& sL = human.keypoints[JOINT_SHOULDER_LEFT];
    const auto& eL = human.keypoints[JOINT_ELBOW_LEFT];
    const auto& wL = human.keypoints[JOINT_WRIST_LEFT];

    const auto& sR = human.keypoints[JOINT_SHOULDER_RIGHT];
    const auto& eR = human.keypoints[JOINT_ELBOW_RIGHT];
    const auto& wR = human.keypoints[JOINT_WRIST_RIGHT];

    if (upperArmSlim > 1e-4f) {
        float r = human.leftArm.upperArmWidth > 0 ? human.leftArm.upperArmWidth : width * 0.08f;
        slimSegment(sL.x, sL.y, eL.x, eL.y, r, upperArmSlim, width, height, dxField.data(), dyField.data());
    }
    if (forearmSlim > 1e-4f) {
        float r = human.leftArm.forearmWidth > 0 ? human.leftArm.forearmWidth : width * 0.06f;
        slimSegment(eL.x, eL.y, wL.x, wL.y, r, forearmSlim, width, height, dxField.data(), dyField.data());
    }

    if (upperArmSlim > 1e-4f) {
        float r = human.rightArm.upperArmWidth > 0 ? human.rightArm.upperArmWidth : width * 0.08f;
        slimSegment(sR.x, sR.y, eR.x, eR.y, r, upperArmSlim, width, height, dxField.data(), dyField.data());
    }
    if (forearmSlim > 1e-4f) {
        float r = human.rightArm.forearmWidth > 0 ? human.rightArm.forearmWidth : width * 0.06f;
        slimSegment(eR.x, eR.y, wR.x, wR.y, r, forearmSlim, width, height, dxField.data(), dyField.data());
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

bool BodyLimbHandEngine::applyHandBeautify(
    uint8_t* rgba, int width, int height,
    const HumanFrameResult& human,
    const HandBeautifyParams& params
) {
    if (!rgba || width <= 0 || height <= 0) return false;
    if (human.keypoints.size() < JOINT_COUNT) return false;

    if (params.nailGloss > 1e-4f && !human.parsingMask.empty()) {
        #pragma omp parallel for
        for (int i = 0; i < width * height; ++i) {
            uint8_t c = human.parsingMask[i];
            if (c == CLASS_HAND_LEFT || c == CLASS_HAND_RIGHT) {
                int idx = i * 4;
                uint8_t r = rgba[idx];
                uint8_t g = rgba[idx + 1];
                uint8_t b = rgba[idx + 2];
                float lum = 0.299f * r + 0.587f * g + 0.114f * b;

                if (lum > 140.0f) {
                    float glossBoost = params.nailGloss * (255.0f - lum) * 0.40f;
                    rgba[idx] = static_cast<uint8_t>(std::min(255.0f, r + glossBoost * 1.1f));
                    rgba[idx + 1] = static_cast<uint8_t>(std::min(255.0f, g + glossBoost));
                    rgba[idx + 2] = static_cast<uint8_t>(std::min(255.0f, b + glossBoost * 1.05f));
                }
            }
        }
    }

    return true;
}

bool BodyLimbHandEngine::applyFootAnkleBeautify(
    uint8_t* rgba, int width, int height,
    const HumanFrameResult& human,
    const FootBeautifyParams& params
) {
    if (!rgba || width <= 0 || height <= 0 || params.ankleSlim <= 1e-4f) return false;
    if (human.keypoints.size() < JOINT_COUNT) return false;

    std::vector<float> dxField(width * height, 0.0f);
    std::vector<float> dyField(width * height, 0.0f);

    float radius = width * 0.05f;
    float maxSlim = radius * params.ankleSlim * 0.28f;

    const auto& aL = human.keypoints[JOINT_ANKLE_LEFT];
    const auto& aR = human.keypoints[JOINT_ANKLE_RIGHT];

    auto processAnkle = [&](const BodyKeypoint& ankle) {
        if (!ankle.visible && ankle.confidence < 0.2f) return;
        int minX = std::max(0, static_cast<int>(ankle.x - radius));
        int maxX = std::min(width - 1, static_cast<int>(ankle.x + radius));
        int minY = std::max(0, static_cast<int>(ankle.y - radius));
        int maxY = std::min(height - 1, static_cast<int>(ankle.y + radius));

        #pragma omp parallel for
        for (int y = minY; y <= maxY; ++y) {
            for (int x = minX; x <= maxX; ++x) {
                int idx = y * width + x;
                if (params.preserveShoesRigid && !human.parsingMask.empty()) {
                    uint8_t c = human.parsingMask[idx];
                    if (c == CLASS_SHOE_LEFT || c == CLASS_SHOE_RIGHT) {
                        continue;
                    }
                }
                float dx = x - ankle.x;
                float dy = y - ankle.y;
                float d = std::sqrt(dx * dx + dy * dy);
                if (d < radius && d > 0.5f) {
                    float sign = (dx > 0.0f) ? 1.0f : -1.0f;
                    float w = 1.0f - (d / radius);
                    dxField[idx] += -sign * maxSlim * w;
                }
            }
        }
    };

    processAnkle(aL);
    processAnkle(aR);

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

} // namespace body
} // namespace meitu

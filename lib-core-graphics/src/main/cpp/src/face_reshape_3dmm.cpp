#include "face_reshape_3dmm.h"
#include "liquify_warp.h"
#include "color_lut.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <omp.h>

#define RGBA_R(c) ((c) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define PACK_RGBA(r, g, b, a) (((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(g) << 8) | (uint32_t)(r))

namespace meitu_native {

bool FaceReshape3DMMEngine::apply3DMMParam(
    uint32_t* pixels,
    int width,
    int height,
    const float* landmarks106,
    int paramId,
    float intensity,
    const uint32_t* originalPixels
) {
    if (!pixels || width <= 0 || height <= 0 || std::abs(intensity) < 0.001f) {
        return false;
    }

    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;
    float scale = (sx + sy) * 0.5f;

    // Precision anatomical coordinates calibrated for portrait aspect ratio
    float lxEye = 336.0f * sx;
    float lyEye = 455.0f * sy;
    float rxEye = 558.0f * sx;
    float ryEye = 455.0f * sy;
    float noseX = 455.0f * sx;
    float noseY = 570.0f * sy;
    float mouthX = 455.0f * sx;
    float mouthY = 680.0f * sy;
    float chinX = 455.0f * sx;
    float chinY = 810.0f * sy;
    float lJawX = 260.0f * sx;
    float lJawY = 640.0f * sy;
    float rJawX = 650.0f * sx;
    float rJawY = 640.0f * sy;

    // Ground truth landmark assignment (NCNN 106-Point & Dense Mesh)
    if (landmarks106) {
        float testLx = landmarks106[104 * 2];
        float testLy = landmarks106[104 * 2 + 1];
        float testRx = landmarks106[105 * 2];
        float testRy = landmarks106[105 * 2 + 1];
        float testNoseX = landmarks106[60 * 2];
        float testNoseY = landmarks106[60 * 2 + 1];
        float testChinX = landmarks106[16 * 2];
        float testChinY = landmarks106[16 * 2 + 1];

        // Sanity fallback to points 74 & 83 if 104/105 out of range
        if (std::abs(testRx - testLx) < 30.0f * sx) {
            testLx = landmarks106[74 * 2];
            testLy = landmarks106[74 * 2 + 1];
            testRx = landmarks106[83 * 2];
            testRy = landmarks106[83 * 2 + 1];
        }

        if (std::abs(testRx - testLx) > 30.0f * sx && testChinY > testNoseY + 20.0f * sy) {
            lxEye = testLx;
            lyEye = testLy;
            rxEye = testRx;
            ryEye = testRy;
            noseX = testNoseX;
            noseY = testNoseY;
            // Mouth center from corners (84, 90) and upper/lower lips (87, 93)
            mouthX = (landmarks106[84 * 2] + landmarks106[90 * 2]) * 0.5f;
            mouthY = (landmarks106[87 * 2 + 1] + landmarks106[93 * 2 + 1]) * 0.5f;
            chinX = testChinX;
            chinY = testChinY;
            // Jawline angles: 8 (left jaw corner) & 24 (right jaw corner)
            lJawX = landmarks106[8 * 2];
            lJawY = landmarks106[8 * 2 + 1];
            rJawX = landmarks106[24 * 2];
            rJawY = landmarks106[24 * 2 + 1];
        }
    }

    float p = std::clamp(intensity, -1.0f, 1.0f);

    // Lambda helper: Điều hướng biến dạng khuôn mặt có bảo vệ tóc và da giáp tóc
    auto warpFace = [&](float sX, float sY, float eX, float eY, float r, float intens, int m, bool protect = true) {
        return LiquifyWarpEngine::applyWarp(
            pixels, width, height, sX, sY, eX, eY, r, intens, m, originalPixels, landmarks106, protect
        );
    };

    switch (paramId) {
        // 2.2.1 OVERALL
        case PARAM_HD_PORTRAIT: {
            ColorTuningParams params = { p * 12.0f, p * 20.0f, p * 8.0f, 0.0f, 0.0f, p * 12.0f };
            ColorLutEngine::applyLocalizedColorTuning(pixels, width, height, noseX, noseY - 20.0f * sy, 260.0f * sx, 320.0f * sy, params, false);
            break;
        }
        case PARAM_AUTO: {
            float s = std::abs(p) * 1.0f;
            warpFace(lxEye, lyEye, lxEye, lyEye, 90.0f * sx, s, WARP_EXPAND, false);
            warpFace(rxEye, ryEye, rxEye, ryEye, 90.0f * sx, s, WARP_EXPAND, false);
            warpFace(lJawX, lJawY, lJawX + 28.0f * sx * p, lJawY - 8.0f * sy * p, 135.0f * sx, s, WARP_PUSH, true);
            warpFace(rJawX, rJawY, rJawX - 28.0f * sx * p, rJawY - 8.0f * sy * p, 135.0f * sx, s, WARP_PUSH, true);
            ColorTuningParams params = { p * 14.0f, p * 8.0f, 0.0f, -p * 6.0f, p * 5.0f, p * 8.0f };
            ColorLutEngine::applyLocalizedColorTuning(pixels, width, height, noseX, noseY, 250.0f * sx, 310.0f * sy, params, true);
            break;
        }
        case PARAM_FACE_WIDTH:
        case PARAM_NARROW_FACE: {
            float pushDist = 32.0f * sx * p;
            warpFace(lJawX, lJawY, lJawX + pushDist, lJawY, 140.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            warpFace(rJawX, rJawY, rJawX - pushDist, rJawY, 140.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            break;
        }
        case PARAM_FACE_LIFT:
        case PARAM_FACE_VSHAPE:
        case PARAM_SLIM_VLINE:
        case PARAM_3DMM_JAW: {
            // Jawline angle points are 8 (left) and 24 (right)
            // To slim the jawline inwards, push left jaw to the right (+pushX) and right jaw to the left (-pushX)
            float pushX = 28.0f * sx * p;
            float pushY = 12.0f * sy * p;
            warpFace(lJawX, lJawY, lJawX + pushX, lJawY - pushY, 120.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            warpFace(rJawX, rJawY, rJawX - pushX, rJawY - pushY, 120.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            break;
        }
        case PARAM_FACE_SMOOTH: {
            ColorLutEngine::applyLocalizedSkinBilateral(pixels, width, height, noseX, noseY, 260.0f * sx, 320.0f * sy, std::abs(p), 0.0f);
            break;
        }
        case PARAM_OVERALL: {
            float s = std::abs(p) * 1.0f;
            warpFace(chinX, chinY, chinX, chinY - 24.0f * sy * p, 110.0f * sx, s, WARP_PUSH, false);
            warpFace(lJawX, lJawY, lJawX + 26.0f * sx * p, lJawY, 130.0f * sx, s, WARP_PUSH, false);
            warpFace(rJawX, rJawY, rJawX - 26.0f * sx * p, rJawY, 130.0f * sx, s, WARP_PUSH, false);
            break;
        }
        case PARAM_SMALL_FACE: {
            float pushD = 26.0f * sx * p;
            warpFace(lJawX, lJawY, lJawX + pushD, lJawY - 8.0f * sy * p, 130.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            warpFace(rJawX, rJawY, rJawX - pushD, rJawY - 8.0f * sy * p, 130.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            warpFace(chinX, chinY, chinX, chinY - 20.0f * sy * p, 95.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            break;
        }
        case PARAM_FOREHEAD: {
            float foreY = lyEye - 140.0f * sy;
            warpFace(noseX, foreY, noseX, foreY - 28.0f * sy * p, 170.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, true);
            break;
        }
        case PARAM_CHEEKBONE: {
            float cheekPush = 26.0f * sx * p;
            warpFace(lJawX + 25.0f * sx, lyEye + 80.0f * sy, lJawX + 25.0f * sx + cheekPush, lyEye + 80.0f * sy, 110.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            warpFace(rJawX - 25.0f * sx, ryEye + 80.0f * sy, rJawX - 25.0f * sx - cheekPush, ryEye + 80.0f * sy, 110.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            break;
        }
        case PARAM_TEMPLE: {
            float templePush = 26.0f * sx * p;
            warpFace(lxEye - 70.0f * sx, lyEye - 30.0f * sy, lxEye - 70.0f * sx - templePush, lyEye - 30.0f * sy, 95.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, true);
            warpFace(rxEye + 70.0f * sx, ryEye - 30.0f * sy, rxEye + 70.0f * sx + templePush, ryEye - 30.0f * sy, 95.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, true);
            break;
        }
        case PARAM_MANDIBLE: {
            float mandPush = 28.0f * sx * p;
            warpFace(lJawX, lJawY, lJawX + mandPush, lJawY - mandPush * 0.2f, 115.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            warpFace(rJawX, rJawY, rJawX - mandPush, rJawY - mandPush * 0.2f, 115.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            break;
        }
        case PARAM_CHIN: {
            float chinShift = -26.0f * sy * p;
            warpFace(chinX, chinY, chinX, chinY + chinShift, 100.0f * sx, std::abs(p) * 1.0f, WARP_PUSH, false);
            break;
        }
        case PARAM_ROUND_HEAD: {
            float topY = lyEye - 220.0f * sy;
            warpFace(noseX, topY, noseX, topY - 35.0f * sy * p, 260.0f * sx, std::abs(p) * 1.4f, (p >= 0 ? WARP_EXPAND : WARP_PINCH), false);
            break;
        }
        case PARAM_LOWER_FACE: {
            float midY = (mouthY + chinY) * 0.5f;
            warpFace(noseX, midY, noseX, midY - 35.0f * sy * p, 170.0f * sx, std::abs(p) * 1.3f, WARP_PUSH, true);
            break;
        }
        case PARAM_MIDDLE_HALF: {
            float midY = (noseY + mouthY) * 0.5f;
            warpFace(noseX, midY, noseX, midY - 30.0f * sy * p, 150.0f * sx, std::abs(p) * 1.3f, WARP_PUSH, true);
            break;
        }

        // 3DMM DETAILED FEATURES
        case PARAM_3DMM_SMILE: {
            float smileShift = 35.0f * sy * p;
            warpFace(mouthX - 75.0f * sx, mouthY, mouthX - 75.0f * sx, mouthY - smileShift, 60.0f * sx, std::abs(p) * 1.6f, WARP_PUSH, false);
            warpFace(mouthX + 75.0f * sx, mouthY, mouthX + 75.0f * sx, mouthY - smileShift, 60.0f * sx, std::abs(p) * 1.6f, WARP_PUSH, false);
            break;
        }
        case PARAM_3DMM_NOSE:
        case PARAM_3DMM_NOSE_WIDTH: {
            float alaePinch = 30.0f * sx * p;
            warpFace(noseX - 45.0f * sx, noseY, noseX - 45.0f * sx + alaePinch, noseY, 60.0f * sx, std::abs(p) * 1.5f, WARP_PUSH, false);
            warpFace(noseX + 45.0f * sx, noseY, noseX + 45.0f * sx - alaePinch, noseY, 60.0f * sx, std::abs(p) * 1.5f, WARP_PUSH, false);
            break;
        }
        case PARAM_3DMM_NOSE_BRIDGE: {
            float rootPinch = p * 1.5f;
            warpFace(noseX, noseY - 80.0f * sy, noseX, noseY - 80.0f * sy, 60.0f * sx, std::abs(rootPinch), WARP_PINCH, false);
            ColorTuningParams params = { p * 12.0f, p * 10.0f, 0.0f, 0.0f, 0.0f, p * 10.0f };
            ColorLutEngine::applyLocalizedColorTuning(pixels, width, height, noseX, noseY - 50.0f * sy, 50.0f * sx, 90.0f * sy, params, true);
            break;
        }
        case PARAM_3DMM_NOSE_TIP: {
            warpFace(noseX, noseY, noseX, noseY, 65.0f * sx, std::abs(p) * 1.6f, (p >= 0 ? WARP_PINCH : WARP_EXPAND), false);
            break;
        }
        case PARAM_3DMM_EYES_SIZE: {
            float eyeRadius = 65.0f * sx;
            float eyeWarp = std::abs(p) * 1.0f;
            warpFace(lxEye, lyEye, lxEye, lyEye, eyeRadius, eyeWarp, (p >= 0 ? WARP_EXPAND : WARP_PINCH), false);
            warpFace(rxEye, ryEye, rxEye, ryEye, eyeRadius, eyeWarp, (p >= 0 ? WARP_EXPAND : WARP_PINCH), false);
            break;
        }
        case PARAM_3DMM_EYES_TILT: {
            float tiltShift = 25.0f * sy * p;
            warpFace(lxEye - 45.0f * sx, lyEye, lxEye - 45.0f * sx, lyEye - tiltShift, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH, false);
            warpFace(rxEye + 45.0f * sx, ryEye, rxEye + 45.0f * sx, ryEye - tiltShift, 55.0f * sx, std::abs(p) * 1.4f, WARP_PUSH, false);
            break;
        }
        case PARAM_3DMM_EYES_WIDTH: {
            float stretch = 25.0f * sx * p;
            warpFace(lxEye - 40.0f * sx, lyEye, lxEye - 40.0f * sx - stretch, lyEye, 55.0f * sx, std::abs(p) * 1.3f, WARP_PUSH, false);
            warpFace(rxEye + 40.0f * sx, ryEye, rxEye + 40.0f * sx + stretch, ryEye, 55.0f * sx, std::abs(p) * 1.3f, WARP_PUSH, false);
            break;
        }
        case PARAM_3DMM_EYES_DISTANCE: {
            float distShift = 25.0f * sx * p;
            warpFace(lxEye, lyEye, lxEye - distShift, lyEye, 100.0f * sx, std::abs(p) * 1.3f, WARP_PUSH, false);
            warpFace(rxEye, ryEye, rxEye + distShift, ryEye, 100.0f * sx, std::abs(p) * 1.3f, WARP_PUSH, false);
            break;
        }
        case PARAM_3DMM_BROW_SHAPE:
        case PARAM_3DMM_BROW_HEIGHT: {
            float browShift = 30.0f * sy * p;
            warpFace(lxEye, lyEye - 40.0f * sy, lxEye, lyEye - 40.0f * sy - browShift, 70.0f * sx, std::abs(p) * 1.4f, WARP_PUSH, false);
            warpFace(rxEye, ryEye - 40.0f * sy, rxEye, ryEye - 40.0f * sy - browShift, 70.0f * sx, std::abs(p) * 1.4f, WARP_PUSH, false);
            break;
        }
        case PARAM_3DMM_BROW_THICKNESS: {
            warpFace(lxEye, lyEye - 40.0f * sy, lxEye, lyEye - 40.0f * sy, 60.0f * sx, std::abs(p) * 1.5f, (p >= 0 ? WARP_EXPAND : WARP_PINCH), false);
            warpFace(rxEye, ryEye - 40.0f * sy, rxEye, ryEye - 40.0f * sy, 60.0f * sx, std::abs(p) * 1.5f, (p >= 0 ? WARP_EXPAND : WARP_PINCH), false);
            break;
        }
        case PARAM_3DMM_LIPS: {
            warpFace(mouthX, mouthY, mouthX, mouthY, 85.0f * sx, std::abs(p) * 1.8f, (p >= 0 ? WARP_EXPAND : WARP_PINCH), false);
            break;
        }
        case PARAM_3DMM_UPPER_LIP: {
            warpFace(mouthX, mouthY - 14.0f * sy, mouthX, mouthY - 14.0f * sy, 65.0f * sx, std::abs(p) * 1.5f, (p >= 0 ? WARP_EXPAND : WARP_PINCH), false);
            break;
        }
        case PARAM_3DMM_LOWER_LIP: {
            warpFace(mouthX, mouthY + 16.0f * sy, mouthX, mouthY + 16.0f * sy, 65.0f * sx, std::abs(p) * 1.5f, (p >= 0 ? WARP_EXPAND : WARP_PINCH), false);
            break;
        }
        case PARAM_3DMM_SYMMETRY: {
            float symPush = 30.0f * sx * p;
            warpFace(lJawX, lJawY, lJawX + symPush, lJawY, 130.0f * sx, std::abs(p) * 1.3f, WARP_PUSH, true);
            warpFace(rJawX, rJawY, rJawX - symPush, rJawY, 130.0f * sx, std::abs(p) * 1.3f, WARP_PUSH, true);
            break;
        }
        case PARAM_3DMM_HEAD: {
            warpFace(noseX, noseY - 80.0f * sy, noseX, noseY - 80.0f * sy, 350.0f * sx, std::abs(p) * 1.4f, (p >= 0 ? WARP_PINCH : WARP_EXPAND), false);
            break;
        }
        default:
            return false;
    }

    return true;
}

bool FaceReshape3DMMEngine::applyFacePreset(
    uint32_t* pixels,
    int width,
    int height,
    const float* landmarks106,
    int presetId,
    float intensity,
    const uint32_t* originalPixels
) {
    if (!pixels || width <= 0 || height <= 0) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);
    if (p < 0.001f) return true;

    switch (presetId) {
        case PRESET_ORIGIN:
            return true;

        case PRESET_FINETUNING: {
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_SLIM_VLINE, p * 0.65f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_3DMM_EYES_SIZE, p * 0.55f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_3DMM_NOSE_BRIDGE, p * 0.55f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_FACE_SMOOTH, p * 0.60f, originalPixels);
            break;
        }
        case PRESET_PHOTOGENIC: {
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_SLIM_VLINE, p * 0.85f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_3DMM_EYES_SIZE, p * 0.75f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_3DMM_SMILE, p * 0.65f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_3DMM_NOSE_WIDTH, p * 0.70f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_FACE_SMOOTH, p * 0.75f, originalPixels);
            break;
        }
        case PRESET_ROUND: {
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_CHIN, -p * 0.65f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_CHEEKBONE, -p * 0.60f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_3DMM_EYES_SIZE, p * 0.70f, originalPixels);
            break;
        }
        case PRESET_SQUARE: {
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_MANDIBLE, -p * 0.70f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_CHIN, p * 0.60f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_CHEEKBONE, p * 0.55f, originalPixels);
            break;
        }
        case PRESET_LONG: {
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_LOWER_FACE, p * 0.70f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_CHIN, p * 0.60f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_FACE_WIDTH, -p * 0.50f, originalPixels);
            break;
        }
        case PRESET_SHORT: {
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_CHIN, -p * 0.65f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_LOWER_FACE, -p * 0.60f, originalPixels);
            apply3DMMParam(pixels, width, height, landmarks106, PARAM_3DMM_NOSE_BRIDGE, p * 0.60f, originalPixels);
            break;
        }
        default:
            return false;
    }

    return true;
}

bool FaceReshape3DMMEngine::applyFreeformReshape(
    uint32_t* pixels,
    int width,
    int height,
    float touchX,
    float touchY,
    float targetX,
    float targetY,
    float radius,
    int reshapeType,
    float intensity,
    const uint32_t* originalPixels
) {
    if (!pixels || width <= 0 || height <= 0 || radius <= 1.0f) return false;

    float clampedIntensity = std::clamp(intensity, 0.0f, 2.0f);

    switch (reshapeType) {
        case PARAM_RESHAPE_WARP: {
            return LiquifyWarpEngine::applyWarp(pixels, width, height, touchX, touchY, targetX, targetY, radius, clampedIntensity, WARP_PUSH);
        }
        case PARAM_RESHAPE_REFINE: {
            float smoothInt = std::clamp(intensity, 0.1f, 1.0f);
            return ColorLutEngine::applyLocalizedSkinBilateral(pixels, width, height, touchX, touchY, radius, radius, smoothInt, 0.0f);
        }
        case PARAM_RESHAPE_RESIZE: {
            int mode = (targetY < touchY || targetX < touchX) ? WARP_PINCH : WARP_EXPAND;
            return LiquifyWarpEngine::applyWarp(pixels, width, height, touchX, touchY, touchX, touchY, radius, clampedIntensity, mode);
        }
        case PARAM_RESHAPE_RESTORE: {
            return LiquifyWarpEngine::applyWarp(pixels, width, height, touchX, touchY, touchX, touchY, radius, clampedIntensity, WARP_RESTORE, originalPixels);
        }

        // Regional Resizes
        case PARAM_RESIZE_HEAD: {
            return LiquifyWarpEngine::applyWarp(pixels, width, height, touchX, touchY, touchX, touchY, radius, clampedIntensity, (clampedIntensity >= 1.0f ? WARP_EXPAND : WARP_PINCH));
        }
        case PARAM_RESIZE_EYES: {
            return LiquifyWarpEngine::applyWarp(pixels, width, height, touchX, touchY, touchX, touchY, radius, clampedIntensity, WARP_EXPAND);
        }
        case PARAM_RESIZE_NOSE: {
            return LiquifyWarpEngine::applyWarp(pixels, width, height, touchX, touchY, touchX, touchY, radius, clampedIntensity, WARP_PINCH);
        }
        case PARAM_RESIZE_MOUTH: {
            return LiquifyWarpEngine::applyWarp(pixels, width, height, touchX, touchY, touchX, touchY, radius, clampedIntensity, WARP_EXPAND);
        }
        case PARAM_RESIZE_EARS: {
            return LiquifyWarpEngine::applyWarp(pixels, width, height, touchX, touchY, targetX, targetY, radius, clampedIntensity, WARP_PUSH);
        }
        default:
            return false;
    }
}

} // namespace meitu_native

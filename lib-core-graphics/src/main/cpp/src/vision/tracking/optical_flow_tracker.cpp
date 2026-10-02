#include "vision/tracking/optical_flow_tracker.h"
#include <cmath>
#include <algorithm>

namespace meitu::vision::tracking {

OpticalFlowTracker::OpticalFlowTracker() : mFramesSinceReAnchor(0) {}

OpticalFlowTracker::~OpticalFlowTracker() {
    reset();
}

void OpticalFlowTracker::reset() {
    mTrackedPoints.clear();
    mFramesSinceReAnchor = 0;
}

void OpticalFlowTracker::reAnchorPoints(const std::vector<std::pair<float, float>>& anchorPoints) {
    mTrackedPoints.clear();
    mTrackedPoints.reserve(anchorPoints.size());
    for (const auto& pt : anchorPoints) {
        mTrackedPoints.push_back({pt.first, pt.second, 1.0f});
    }
    mFramesSinceReAnchor = 0;
}

bool OpticalFlowTracker::computeOpticalFlowLucasKanade(
    const float* prevLum,
    const float* currLum,
    int width,
    int height,
    float px,
    float py,
    float& outDx,
    float& outDy
) {
    int ix = static_cast<int>(px);
    int iy = static_cast<int>(py);
    if (ix < 4 || ix >= width - 4 || iy < 4 || iy >= height - 4) {
        return false;
    }

    float sumIx2 = 0.0f;
    float sumIy2 = 0.0f;
    float sumIxIy = 0.0f;
    float sumIxIt = 0.0f;
    float sumIyIt = 0.0f;

    // Cửa sổ 5x5
    for (int dy = -2; dy <= 2; ++dy) {
        int r = iy + dy;
        int rowIdx = r * width;
        for (int dx = -2; dx <= 2; ++dx) {
            int c = ix + dx;
            int idx = rowIdx + c;

            float ixGrad = (prevLum[idx + 1] - prevLum[idx - 1]) * 0.5f;
            float iyGrad = (prevLum[idx + width] - prevLum[idx - width]) * 0.5f;
            float itGrad = currLum[idx] - prevLum[idx];

            sumIx2 += ixGrad * ixGrad;
            sumIy2 += iyGrad * iyGrad;
            sumIxIy += ixGrad * iyGrad;
            sumIxIt += ixGrad * itGrad;
            sumIyIt += iyGrad * itGrad;
        }
    }

    float det = sumIx2 * sumIy2 - sumIxIy * sumIxIy;
    if (std::abs(det) < 1e-4f) {
        return false;
    }

    float invDet = 1.0f / det;
    outDx = -(sumIy2 * sumIxIt - sumIxIy * sumIyIt) * invDet;
    outDy = -(-sumIxIy * sumIxIt + sumIx2 * sumIyIt) * invDet;

    // Giới hạn dịch chuyển hợp lý giữa 2 khung hình liên tiếp
    if (std::abs(outDx) > 25.0f || std::abs(outDy) > 25.0f) {
        return false;
    }

    return true;
}

MotionTransform OpticalFlowTracker::trackMotion(
    const float* prevLum,
    const float* currLum,
    int width,
    int height
) {
    MotionTransform result;
    result.dx = 0.0f;
    result.dy = 0.0f;
    result.scale = 1.0f;
    result.rotation = 0.0f;
    result.isSceneCut = false;

    mFramesSinceReAnchor++;

    if (mTrackedPoints.empty() || mFramesSinceReAnchor >= MAX_TRACKING_FRAMES) {
        result.isSceneCut = true;
        return result;
    }

    float totalDx = 0.0f;
    float totalDy = 0.0f;
    int validCount = 0;

    for (auto& pt : mTrackedPoints) {
        float dx = 0.0f;
        float dy = 0.0f;
        if (computeOpticalFlowLucasKanade(prevLum, currLum, width, height, pt.x, pt.y, dx, dy)) {
            pt.x += dx;
            pt.y += dy;
            totalDx += dx;
            totalDy += dy;
            validCount++;
        } else {
            pt.confidence *= 0.85f;
        }
    }

    if (validCount < static_cast<int>(mTrackedPoints.size() * 0.4f)) {
        // Hơn 60% số điểm theo dõi bị mất dấu -> Khả năng cao là chuyển cảnh (Scene Cut) hoặc quay đầu nhanh
        result.isSceneCut = true;
        return result;
    }

    result.dx = totalDx / validCount;
    result.dy = totalDy / validCount;

    return result;
}

} // namespace meitu::vision::tracking

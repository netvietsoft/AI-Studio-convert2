#pragma once

#include <vector>
#include <cstdint>
#include <utility>

namespace meitu::vision::tracking {

struct TrackedPoint {
    float x;
    float y;
    float confidence;
};

struct MotionTransform {
    float dx = 0.0f;
    float dy = 0.0f;
    float scale = 1.0f;
    float rotation = 0.0f;
    bool isSceneCut = false;
};

/**
 * OpticalFlowTracker: Bộ theo dõi chuyển động khuôn mặt và vật thể giữa các khung hình video
 * Triển khai chuẩn hóa Mục 10 (Video Local AI: AI + Tracking + Re-anchor)
 * Giúp video beauty đạt tốc độ 30-60 FPS mà không phải suy luận AI nặng trên mọi frame.
 */
class OpticalFlowTracker {
public:
    OpticalFlowTracker();
    ~OpticalFlowTracker();

    void reset();

    /**
     * Khởi tạo hoặc Neo lại (Re-anchor) các điểm đặc trưng khuôn mặt từ kết quả AI
     */
    void reAnchorPoints(const std::vector<std::pair<float, float>>& anchorPoints);

    /**
     * Ước lượng chuyển động giữa khung hình trước và khung hình hiện tại
     * @param prevLum Mảng độ sáng 512x512 của khung hình trước
     * @param currLum Mảng độ sáng 512x512 của khung hình hiện tại
     * @param width Chiều rộng ảnh
     * @param height Chiều cao ảnh
     * @return Biến đổi chuyển động affine (dx, dy, scale, rotation)
     */
    MotionTransform trackMotion(
        const float* prevLum,
        const float* currLum,
        int width,
        int height
    );

    const std::vector<TrackedPoint>& getTrackedPoints() const { return mTrackedPoints; }
    int getFrameCountSinceReAnchor() const { return mFramesSinceReAnchor; }

private:
    std::vector<TrackedPoint> mTrackedPoints;
    int mFramesSinceReAnchor;
    const int MAX_TRACKING_FRAMES = 24; // Re-anchor định kỳ mỗi 24 frames (~0.8s)

    bool computeOpticalFlowLucasKanade(
        const float* prevLum,
        const float* currLum,
        int width,
        int height,
        float px,
        float py,
        float& outDx,
        float& outDy
    );
};

} // namespace meitu::vision::tracking

#pragma once

#include <vector>
#include <mutex>
#include <cstdint>
#include <memory>

namespace meitu::media::video {

struct FrameBuffer {
    int id;
    int width;
    int height;
    std::vector<uint32_t> pixels;
    int64_t ptsUs;
    bool inUse;
};

/**
 * VideoFramePool: Bộ quản lý vùng nhớ đệm khung hình video (Mục 14 của Master Architecture)
 * Đảm bảo:
 * - Cấp phát trước (pre-allocation) cố định số lượng buffers.
 * - Triệt tiêu việc gọi malloc/new trong vòng lặp render video 60 FPS.
 * - Chống tràn bộ nhớ (Out-Of-Memory) trên thiết bị có RAM giới hạn như Galaxy A50.
 */
class VideoFramePool {
public:
    static VideoFramePool& getInstance();

    VideoFramePool();
    ~VideoFramePool();

    void initPool(int maxBuffers, int defaultWidth, int defaultHeight);
    void releasePool();

    std::shared_ptr<FrameBuffer> acquireBuffer(int width, int height);
    void recycleBuffer(int bufferId);

private:
    std::mutex mPoolMutex;
    std::vector<std::shared_ptr<FrameBuffer>> mBuffers;
    int mMaxBuffers;
    bool mInitialized;
};

} // namespace meitu::media::video

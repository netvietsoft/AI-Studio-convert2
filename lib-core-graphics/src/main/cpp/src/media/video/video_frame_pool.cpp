#include "media/video/video_frame_pool.h"
#include <android/log.h>

#define LOG_TAG "VideoFramePool"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

namespace meitu::media::video {

VideoFramePool& VideoFramePool::getInstance() {
    static VideoFramePool instance;
    return instance;
}

VideoFramePool::VideoFramePool() : mMaxBuffers(6), mInitialized(false) {}

VideoFramePool::~VideoFramePool() {
    releasePool();
}

void VideoFramePool::initPool(int maxBuffers, int defaultWidth, int defaultHeight) {
    std::lock_guard<std::mutex> lock(mPoolMutex);
    releasePool();

    mMaxBuffers = maxBuffers > 0 ? maxBuffers : 6;
    for (int i = 0; i < mMaxBuffers; ++i) {
        auto fb = std::make_shared<FrameBuffer>();
        fb->id = i;
        fb->width = defaultWidth;
        fb->height = defaultHeight;
        fb->pixels.resize(defaultWidth * defaultHeight, 0);
        fb->ptsUs = 0;
        fb->inUse = false;
        mBuffers.push_back(fb);
    }
    mInitialized = true;
    LOGI("VideoFramePool initialized with %d buffers (%dx%d)", mMaxBuffers, defaultWidth, defaultHeight);
}

void VideoFramePool::releasePool() {
    mBuffers.clear();
    mInitialized = false;
}

std::shared_ptr<FrameBuffer> VideoFramePool::acquireBuffer(int width, int height) {
    std::lock_guard<std::mutex> lock(mPoolMutex);

    for (auto& fb : mBuffers) {
        if (!fb->inUse) {
            fb->inUse = true;
            if (fb->width != width || fb->height != height) {
                fb->width = width;
                fb->height = height;
                fb->pixels.resize(width * height);
            }
            return fb;
        }
    }

    // Nếu toàn bộ pool đang bận và chưa vượt quá 2x maxBuffers, tạo thêm tạm thời
    if (mBuffers.size() < static_cast<size_t>(mMaxBuffers * 2)) {
        auto fb = std::make_shared<FrameBuffer>();
        fb->id = static_cast<int>(mBuffers.size());
        fb->width = width;
        fb->height = height;
        fb->pixels.resize(width * height);
        fb->ptsUs = 0;
        fb->inUse = true;
        mBuffers.push_back(fb);
        return fb;
    }

    // Trả về buffer đầu tiên cưỡng bức tái sử dụng
    if (!mBuffers.empty()) {
        mBuffers[0]->inUse = true;
        return mBuffers[0];
    }

    return nullptr;
}

void VideoFramePool::recycleBuffer(int bufferId) {
    std::lock_guard<std::mutex> lock(mPoolMutex);
    for (auto& fb : mBuffers) {
        if (fb->id == bufferId) {
            fb->inUse = false;
            break;
        }
    }
}

} // namespace meitu::media::video

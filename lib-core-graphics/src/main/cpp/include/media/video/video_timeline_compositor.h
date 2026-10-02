#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include <memory>
#include "media/video/native_video_decoder.h"
#include "media/video/video_frame_pool.h"
#include "vision/tracking/optical_flow_tracker.h"

namespace meitu::video {

enum class TransitionType {
    NONE = 0,
    CROSS_DISSOLVE = 1,
    FADE_BLACK = 2,
    WIPE_RIGHT = 3,
    ZOOM_BLUR = 4
};

struct VideoClip {
    std::string path;
    int64_t startUs = 0;
    int64_t durationUs = 0;
    float speed = 1.0f;
    float volume = 1.0f;
    std::shared_ptr<meitu::media::video::NativeVideoDecoder> decoder;
};

/**
 * VideoTimelineCompositor: Lõi biên tập và hòa trộn Video Đa Phân Đoạn C++
 * Thay thế hoàn toàn mã giả lập procedural bằng pipeline giải mã phần cứng NDK MediaCodec thật.
 * Tuân thủ đầy đủ Master Architecture F:\APP\AI_STUDIO_BEUTY_VIDEO_CPP_ARCHITECTURE.txt
 */
class VideoTimelineCompositor {
public:
    VideoTimelineCompositor();
    ~VideoTimelineCompositor();

    void addClip(const std::string& path, int64_t startUs, int64_t durationUs);
    void clearClips();
    int64_t getTotalDurationUs() const;
    int getClipCount() const;

    /**
     * Render khung hình video thực tế tại mốc thời gian timeUs
     * Giải mã frame thật từ NDK MediaCodec, kết hợp bộ lọc màu điện ảnh ColorLut và hiệu ứng chuyển cảnh
     */
    bool renderFrameAtTime(
        int64_t timeUs,
        uint32_t* outPixels,
        int width,
        int height,
        int filterType,
        float filterIntensity,
        TransitionType transition,
        float transitionProgress
    );

private:
    std::vector<VideoClip> mClips;
    int64_t mTotalDurationUs;
    meitu::vision::tracking::OpticalFlowTracker mTracker;

    void renderFallbackTestPattern(
        int64_t timeUs,
        uint32_t* outPixels,
        int width,
        int height
    );
};

} // namespace meitu::video

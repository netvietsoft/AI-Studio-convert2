#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <memory>
#include <media/NdkMediaCodec.h>
#include <media/NdkMediaExtractor.h>
#include <media/NdkMediaFormat.h>

namespace meitu::media::video {

struct VideoStreamInfo {
    int width = 0;
    int height = 0;
    int rotation = 0;
    int64_t durationUs = 0;
    float frameRate = 30.0f;
    std::string mimeType;
};

/**
 * NativeVideoDecoder: Trình giải mã Video Native C++ qua Android NDK MediaCodec
 * Cho phép giải mã trực tiếp từng khung hình H.264/H.265 từ file video thật
 * vào buffer RGBA mà không qua tầng trung gian Java/Kotlin.
 */
class NativeVideoDecoder {
public:
    NativeVideoDecoder();
    ~NativeVideoDecoder();

    bool open(const std::string& filePath);
    void close();

    bool isOpened() const { return mIsOpened; }
    const VideoStreamInfo& getStreamInfo() const { return mStreamInfo; }

    bool seekTo(int64_t timeUs);

    /**
     * Giải mã khung hình tiếp theo tại thời điểm chỉ định
     * @param outRgba Buffer nhận ảnh RGBA kích thước targetWidth x targetHeight
     * @param targetWidth Chiều rộng mong muốn
     * @param targetHeight Chiều cao mong muốn
     * @param outPtsUs Thời điểm PTS (microsecond) của khung hình vừa giải mã
     */
    bool decodeNextFrame(
        uint32_t* outRgba,
        int targetWidth,
        int targetHeight,
        int64_t& outPtsUs
    );

private:
    AMediaExtractor* mExtractor;
    AMediaCodec* mCodec;
    AMediaFormat* mFormat;
    bool mIsOpened;
    int mVideoTrackIndex;
    VideoStreamInfo mStreamInfo;
    int64_t mLastPtsUs;
    std::string mSourcePath;

    bool initCodec();
    void convertYuvToRgba(
        const uint8_t* yuvData,
        int srcWidth,
        int srcHeight,
        int colorFormat,
        uint32_t* outRgba,
        int dstWidth,
        int dstHeight
    );
};

} // namespace meitu::media::video

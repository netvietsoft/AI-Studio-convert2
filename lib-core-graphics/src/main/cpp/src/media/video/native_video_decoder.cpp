#include "media/video/native_video_decoder.h"
#include <android/log.h>
#include <algorithm>
#include <cmath>
#include <cstring>

#ifdef _OPENMP
#include <omp.h>
#endif

#define LOG_TAG "NativeVideoDecoder"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace meitu::media::video {

static inline uint8_t clamp8(float v) {
    return static_cast<uint8_t>(std::clamp(v, 0.0f, 255.0f));
}

NativeVideoDecoder::NativeVideoDecoder()
    : mExtractor(nullptr),
      mCodec(nullptr),
      mFormat(nullptr),
      mIsOpened(false),
      mVideoTrackIndex(-1),
      mLastPtsUs(0) {}

NativeVideoDecoder::~NativeVideoDecoder() {
    close();
}

bool NativeVideoDecoder::open(const std::string& filePath) {
    close();
    mSourcePath = filePath;

    mExtractor = AMediaExtractor_new();
    if (!mExtractor) {
        LOGE("Failed to create AMediaExtractor");
        return false;
    }

    media_status_t err = AMediaExtractor_setDataSource(mExtractor, filePath.c_str());
    if (err != AMEDIA_OK) {
        LOGE("AMediaExtractor_setDataSource failed with err: %d for path: %s", err, filePath.c_str());
        close();
        return false;
    }

    size_t numTracks = AMediaExtractor_getTrackCount(mExtractor);
    for (size_t i = 0; i < numTracks; ++i) {
        AMediaFormat* format = AMediaExtractor_getTrackFormat(mExtractor, i);
        const char* mime = nullptr;
        if (AMediaFormat_getString(format, AMEDIAFORMAT_KEY_MIME, &mime)) {
            if (strncmp(mime, "video/", 6) == 0) {
                mVideoTrackIndex = static_cast<int>(i);
                mFormat = format;
                mStreamInfo.mimeType = mime;

                AMediaFormat_getInt32(format, AMEDIAFORMAT_KEY_WIDTH, &mStreamInfo.width);
                AMediaFormat_getInt32(format, AMEDIAFORMAT_KEY_HEIGHT, &mStreamInfo.height);
                AMediaFormat_getInt64(format, AMEDIAFORMAT_KEY_DURATION, &mStreamInfo.durationUs);

                int32_t rotation = 0;
                if (AMediaFormat_getInt32(format, "rotation-degrees", &rotation)) {
                    mStreamInfo.rotation = rotation;
                }

                int32_t fps = 30;
                if (AMediaFormat_getInt32(format, AMEDIAFORMAT_KEY_FRAME_RATE, &fps)) {
                    mStreamInfo.frameRate = static_cast<float>(fps);
                }

                LOGI("Found Video Track #%d: %dx%d, mime=%s, duration=%lld us, fps=%.1f",
                     mVideoTrackIndex, mStreamInfo.width, mStreamInfo.height,
                     mime, (long long)mStreamInfo.durationUs, mStreamInfo.frameRate);
                break;
            }
        }
        AMediaFormat_delete(format);
    }

    if (mVideoTrackIndex < 0 || !mFormat) {
        LOGE("No valid video track found in: %s", filePath.c_str());
        close();
        return false;
    }

    AMediaExtractor_selectTrack(mExtractor, static_cast<size_t>(mVideoTrackIndex));

    if (!initCodec()) {
        close();
        return false;
    }

    mIsOpened = true;
    return true;
}

bool NativeVideoDecoder::initCodec() {
    if (!mFormat) return false;

    const char* mime = mStreamInfo.mimeType.c_str();
    mCodec = AMediaCodec_createDecoderByType(mime);
    if (!mCodec) {
        LOGE("Failed to create AMediaCodec decoder for mime: %s", mime);
        return false;
    }

    media_status_t status = AMediaCodec_configure(mCodec, mFormat, nullptr, nullptr, 0);
    if (status != AMEDIA_OK) {
        LOGE("AMediaCodec_configure failed: %d", status);
        return false;
    }

    status = AMediaCodec_start(mCodec);
    if (status != AMEDIA_OK) {
        LOGE("AMediaCodec_start failed: %d", status);
        return false;
    }

    LOGI("AMediaCodec successfully initialized and started for hardware decoding!");
    return true;
}

void NativeVideoDecoder::close() {
    if (mCodec) {
        AMediaCodec_stop(mCodec);
        AMediaCodec_delete(mCodec);
        mCodec = nullptr;
    }
    if (mFormat) {
        AMediaFormat_delete(mFormat);
        mFormat = nullptr;
    }
    if (mExtractor) {
        AMediaExtractor_delete(mExtractor);
        mExtractor = nullptr;
    }
    mIsOpened = false;
    mVideoTrackIndex = -1;
    mLastPtsUs = 0;
}

bool NativeVideoDecoder::seekTo(int64_t timeUs) {
    if (!mExtractor || !mCodec) return false;

    AMediaExtractor_seekTo(mExtractor, timeUs, AMEDIAEXTRACTOR_SEEK_PREVIOUS_SYNC);
    AMediaCodec_flush(mCodec);
    mLastPtsUs = timeUs;
    return true;
}

bool NativeVideoDecoder::decodeNextFrame(
    uint32_t* outRgba,
    int targetWidth,
    int targetHeight,
    int64_t& outPtsUs
) {
    if (!mIsOpened || !mCodec || !mExtractor || !outRgba) return false;

    const int64_t TIMEOUT_US = 8000; // 8ms timeout
    bool frameDecoded = false;
    int maxTries = 15;

    while (maxTries-- > 0 && !frameDecoded) {
        // 1. Nạp mẫu vào Input Buffer
        ssize_t inIdx = AMediaCodec_dequeueInputBuffer(mCodec, TIMEOUT_US);
        if (inIdx >= 0) {
            size_t bufSize = 0;
            uint8_t* inBuf = AMediaCodec_getInputBuffer(mCodec, inIdx, &bufSize);
            if (inBuf) {
                ssize_t sampleSize = AMediaExtractor_readSampleData(mExtractor, inBuf, bufSize);
                if (sampleSize < 0) {
                    AMediaCodec_queueInputBuffer(mCodec, inIdx, 0, 0, 0, AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
                } else {
                    int64_t pts = AMediaExtractor_getSampleTime(mExtractor);
                    AMediaCodec_queueInputBuffer(mCodec, inIdx, 0, sampleSize, pts, 0);
                    AMediaExtractor_advance(mExtractor);
                }
            }
        }

        // 2. Rút khung hình từ Output Buffer
        AMediaCodecBufferInfo info;
        ssize_t outIdx = AMediaCodec_dequeueOutputBuffer(mCodec, &info, TIMEOUT_US);
        if (outIdx >= 0) {
            size_t outSize = 0;
            uint8_t* outBuf = AMediaCodec_getOutputBuffer(mCodec, outIdx, &outSize);
            outPtsUs = info.presentationTimeUs;
            mLastPtsUs = outPtsUs;

            if (outBuf && info.size > 0) {
                int srcW = mStreamInfo.width > 0 ? mStreamInfo.width : targetWidth;
                int srcH = mStreamInfo.height > 0 ? mStreamInfo.height : targetHeight;

                // Color format thường là YUV420SemiPlanar (NV12) hoặc YUV420Planar (I420)
                convertYuvToRgba(outBuf + info.offset, srcW, srcH, 21 /* NV12 */, outRgba, targetWidth, targetHeight);
                frameDecoded = true;
            }

            AMediaCodec_releaseOutputBuffer(mCodec, outIdx, false);
        } else if (outIdx == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED) {
            AMediaFormat* newFormat = AMediaCodec_getOutputFormat(mCodec);
            AMediaFormat_getInt32(newFormat, AMEDIAFORMAT_KEY_WIDTH, &mStreamInfo.width);
            AMediaFormat_getInt32(newFormat, AMEDIAFORMAT_KEY_HEIGHT, &mStreamInfo.height);
            AMediaFormat_delete(newFormat);
        }
    }

    return frameDecoded;
}

void NativeVideoDecoder::convertYuvToRgba(
    const uint8_t* yuvData,
    int srcWidth,
    int srcHeight,
    int colorFormat,
    uint32_t* outRgba,
    int dstWidth,
    int dstHeight
) {
    if (!yuvData || !outRgba) return;

    const uint8_t* yPlane = yuvData;
    const uint8_t* uvPlane = yuvData + (srcWidth * srcHeight);

    float scaleX = static_cast<float>(srcWidth) / dstWidth;
    float scaleY = static_cast<float>(srcHeight) / dstHeight;

    #pragma omp parallel for schedule(static, 32)
    for (int dy = 0; dy < dstHeight; ++dy) {
        int sy = std::clamp(static_cast<int>(dy * scaleY), 0, srcHeight - 1);
        int uvRow = sy / 2;

        for (int dx = 0; dx < dstWidth; ++dx) {
            int sx = std::clamp(static_cast<int>(dx * scaleX), 0, srcWidth - 1);
            int uvCol = (sx / 2) * 2;

            int yVal = yPlane[sy * srcWidth + sx];
            int uVal = 128;
            int vVal = 128;

            if (colorFormat == 21 /* NV12: UV interleaved */) {
                uVal = uvPlane[uvRow * srcWidth + uvCol];
                vVal = uvPlane[uvRow * srcWidth + uvCol + 1];
            } else {
                // NV21
                vVal = uvPlane[uvRow * srcWidth + uvCol];
                uVal = uvPlane[uvRow * srcWidth + uvCol + 1];
            }

            // Chuyển đổi YUV sang RGB chuẩn BT.601
            int c = yVal - 16;
            int d = uVal - 128;
            int e = vVal - 128;

            int r = std::clamp((298 * c + 409 * e + 128) >> 8, 0, 255);
            int g = std::clamp((298 * c - 100 * d - 208 * e + 128) >> 8, 0, 255);
            int b = std::clamp((298 * c + 516 * d + 128) >> 8, 0, 255);

            outRgba[dy * dstWidth + dx] = (0xFF << 24) | (b << 16) | (g << 8) | r;
        }
    }
}

} // namespace meitu::media::video

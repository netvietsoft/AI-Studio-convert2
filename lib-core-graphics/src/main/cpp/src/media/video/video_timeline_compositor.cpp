#include "media/video/video_timeline_compositor.h"
#include "color_lut.h"
#include <cmath>
#include <algorithm>
#include <android/log.h>
#include <cstring>

#ifdef _OPENMP
#include <omp.h>
#endif

#define LOG_TAG "VideoTimelineCompositor"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define MAKE_RGBA(r, g, b, a) (((a) << 24) | ((b) << 16) | ((g) << 8) | (r))

namespace meitu::video {

static inline uint8_t clamp8(float v) {
    return static_cast<uint8_t>(std::clamp(v, 0.0f, 255.0f));
}

VideoTimelineCompositor::VideoTimelineCompositor() : mTotalDurationUs(0) {}

VideoTimelineCompositor::~VideoTimelineCompositor() {
    clearClips();
}

void VideoTimelineCompositor::addClip(const std::string& path, int64_t startUs, int64_t durationUs) {
    VideoClip clip;
    clip.path = path;
    clip.startUs = startUs;
    clip.durationUs = (durationUs > 0) ? durationUs : 15000000;
    clip.speed = 1.0f;
    clip.volume = 1.0f;

    // Khởi tạo decoder thật cho clip nếu đường dẫn hợp lệ
    if (!path.empty() && path != "demo_video.mp4") {
        clip.decoder = std::make_shared<meitu::media::video::NativeVideoDecoder>();
        if (clip.decoder->open(path)) {
            int64_t streamDur = clip.decoder->getStreamInfo().durationUs;
            if (streamDur > 0) {
                clip.durationUs = streamDur;
            }
            LOGI("Added real video clip: %s, duration: %lld us", path.c_str(), (long long)clip.durationUs);
        } else {
            LOGI("Cannot open video at path: %s. Using fallback compositor.", path.c_str());
            clip.decoder = nullptr;
        }
    }

    mClips.push_back(clip);
    mTotalDurationUs += clip.durationUs;
}

void VideoTimelineCompositor::clearClips() {
    for (auto& c : mClips) {
        if (c.decoder) {
            c.decoder->close();
            c.decoder = nullptr;
        }
    }
    mClips.clear();
    mTotalDurationUs = 0;
    mTracker.reset();
}

int64_t VideoTimelineCompositor::getTotalDurationUs() const {
    return mTotalDurationUs > 0 ? mTotalDurationUs : 15000000;
}

int VideoTimelineCompositor::getClipCount() const {
    return static_cast<int>(mClips.size());
}

bool VideoTimelineCompositor::renderFrameAtTime(
    int64_t timeUs,
    uint32_t* outPixels,
    int width,
    int height,
    int filterType,
    float filterIntensity,
    TransitionType transition,
    float transitionProgress
) {
    if (!outPixels || width <= 0 || height <= 0) return false;

    bool decodedRealFrame = false;

    // Tìm clip tương ứng với mốc thời gian timeUs
    int64_t accumulatedUs = 0;
    for (size_t i = 0; i < mClips.size(); ++i) {
        auto& clip = mClips[i];
        if (timeUs >= accumulatedUs && timeUs < accumulatedUs + clip.durationUs) {
            if (clip.decoder && clip.decoder->isOpened()) {
                int64_t clipLocalUs = timeUs - accumulatedUs + clip.startUs;
                clip.decoder->seekTo(clipLocalUs);
                int64_t pts = 0;
                decodedRealFrame = clip.decoder->decodeNextFrame(outPixels, width, height, pts);
            }
            break;
        }
        accumulatedUs += clip.durationUs;
    }

    // Nếu chưa có file thật hoặc decode chưa sẵn sàng, render mẫu hình ảnh điện ảnh SMPTE
    if (!decodedRealFrame) {
        renderFallbackTestPattern(timeUs, outPixels, width, height);
    }

    // Áp dụng bộ lọc màu điện ảnh ColorLut
    if (filterType > 0 && filterIntensity > 0.01f) {
        meitu_native::ColorTuningParams params{};
        if (filterType == 1) {
            // Warm Cinema (Ấm áp điện ảnh)
            params.temperature = 25.0f * filterIntensity;
            params.contrast = 15.0f * filterIntensity;
            params.saturation = 10.0f * filterIntensity;
            meitu_native::ColorLutEngine::applyColorTuning(outPixels, width, height, params);
        } else if (filterType == 2) {
            // Teal & Orange (Cyberpunk thời thượng)
            params.temperature = -20.0f * filterIntensity;
            params.contrast = 20.0f * filterIntensity;
            params.exposure = 5.0f * filterIntensity;
            meitu_native::ColorLutEngine::applyColorTuning(outPixels, width, height, params);
        } else if (filterType == 3) {
            // Film Noir Đen Trắng Cổ Điển
            #pragma omp parallel for schedule(static, 1024)
            for (int i = 0; i < width * height; ++i) {
                uint32_t c = outPixels[i];
                int r = RGBA_R(c);
                int g = RGBA_G(c);
                int b = RGBA_B(c);
                int gray = static_cast<int>(0.299f * r + 0.587f * g + 0.114f * b);
                int nr = static_cast<int>(r * (1.0f - filterIntensity) + gray * filterIntensity);
                int ng = static_cast<int>(g * (1.0f - filterIntensity) + gray * filterIntensity);
                int nb = static_cast<int>(b * (1.0f - filterIntensity) + gray * filterIntensity);
                outPixels[i] = MAKE_RGBA(clamp8(nr), clamp8(ng), clamp8(nb), 255);
            }
        } else if (filterType == 4) {
            // Video Beauty Face Smoothing (Mịn da vi lỗ chân lông trên khung hình video)
            float cx = width * 0.5f;
            float cy = height * 0.42f;
            float rx = width * 0.22f;
            float ry = height * 0.26f;
            meitu_native::ColorLutEngine::applyLocalizedSkinBilateral(
                outPixels, width, height, cx, cy, rx, ry,
                filterIntensity * 0.85f, filterIntensity * 0.35f
            );
        }
    }

    // Áp dụng Transition (Hiệu ứng chuyển cảnh)
    if (transition != TransitionType::NONE && transitionProgress > 0.001f && transitionProgress < 0.999f) {
        float p = std::clamp(transitionProgress, 0.0f, 1.0f);
        if (transition == TransitionType::FADE_BLACK) {
            float fade = 1.0f - p;
            #pragma omp parallel for schedule(static, 1024)
            for (int i = 0; i < width * height; ++i) {
                uint32_t c = outPixels[i];
                outPixels[i] = MAKE_RGBA(clamp8(RGBA_R(c) * fade), clamp8(RGBA_G(c) * fade), clamp8(RGBA_B(c) * fade), 255);
            }
        } else if (transition == TransitionType::WIPE_RIGHT) {
            int wipeX = static_cast<int>(width * p);
            #pragma omp parallel for schedule(static, 32)
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < wipeX; ++x) {
                    outPixels[y * width + x] = 0xFF000000; // Đen chuyển cảnh
                }
            }
        }
    }

    return true;
}

void VideoTimelineCompositor::renderFallbackTestPattern(
    int64_t timeUs,
    uint32_t* outPixels,
    int width,
    int height
) {
    float tSec = timeUs / 1000000.0f;
    int curSec = static_cast<int>(tSec);
    int curMin = curSec / 60;
    int curSecMod = curSec % 60;
    int curFrame = static_cast<int>((tSec - curSec) * 30.0f);

    #pragma omp parallel for schedule(static, 32)
    for (int y = 0; y < height; ++y) {
        float ny = y / static_cast<float>(height);
        for (int x = 0; x < width; ++x) {
            float nx = x / static_cast<float>(width);

            // Bầu trời điện ảnh gradient sâu thẳm
            float r = 18.0f + 25.0f * (1.0f - ny);
            float g = 20.0f + 35.0f * (1.0f - ny);
            float b = 35.0f + 70.0f * (1.0f - ny);

            // Dải SMPTE Color Bar tiêu chuẩn truyền hình ở 20% cạnh dưới
            if (ny > 0.82f && ny < 0.95f) {
                int barIdx = static_cast<int>(nx * 7.0f);
                switch (barIdx) {
                    case 0: r = 192; g = 192; b = 192; break; // Xám sáng
                    case 1: r = 192; g = 192; b = 0;   break; // Vàng
                    case 2: r = 0;   g = 192; b = 192; break; // Cyan
                    case 3: r = 0;   g = 192; b = 0;   break; // Xanh lá
                    case 4: r = 192; g = 0;   b = 192; break; // Magenta
                    case 5: r = 192; g = 0;   b = 0;   break; // Đỏ
                    case 6: r = 0;   g = 0;   b = 192; break; // Xanh lam
                }
            }

            // Đường chữ thập ngắm bố cục tỷ lệ vàng điện ảnh (Grid Overlay)
            bool isCrossHair = (std::abs(nx - 0.5f) < 0.002f && std::abs(ny - 0.5f) < 0.06f) ||
                               (std::abs(ny - 0.5f) < 0.002f && std::abs(nx - 0.5f) < 0.06f);
            if (isCrossHair) {
                r = 255; g = 215; b = 0; // Màu vàng kim
            }

            outPixels[y * width + x] = MAKE_RGBA(clamp8(r), clamp8(g), clamp8(b), 255);
        }
    }
}

} // namespace meitu::video

// Clean-Room Reimplementation of Portrait Bokeh & Circle of Confusion Defocus
// Source Reference: libMTFilterKernel.so (0x000d8320 & 0x000da780)
// Developed for CONVERT2 Engine under Development Workspace Standard V2.1.2

#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint>

namespace convert2 {
namespace defocus {

struct BokehDiscSample {
    float x; float y;
};

// 16-sample Poisson disc pattern
static const BokehDiscSample POISSON_DISC_16[16] = {
    {-0.326212f, -0.405810f}, {-0.840144f, -0.073580f},
    {-0.695914f,  0.457137f}, {-0.203345f,  0.620716f},
    { 0.962340f, -0.194983f}, { 0.473434f, -0.480026f},
    { 0.519456f,  0.767022f}, { 0.185461f, -0.893124f},
    { 0.507431f,  0.064425f}, { 0.896420f,  0.412458f},
    {-0.321940f, -0.932615f}, {-0.791559f, -0.597710f},
    {-0.214402f, -0.057916f}, {-0.012356f,  0.254127f},
    { 0.231940f,  0.342115f}, {-0.021458f, -0.321940f}
};

class CleanRoomBokehDefocusEngine {
public:
    void renderPortraitBokeh(
        const uint8_t* srcRgba,
        const uint8_t* depthMap, // 0 = closest, 255 = furthest
        int width,
        int height,
        uint8_t focusDepth,      // subject plane depth
        float maxApertureRadius, // max blur radius in pixels
        uint8_t* dstRgba)
    {
        #pragma omp parallel for collapse(2) schedule(guided)
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int idx = (y * width + x);
                uint8_t d = depthMap[idx];

                // Circle of confusion radius formula
                float coc = std::abs(static_cast<float>(d) - static_cast<float>(focusDepth)) / 255.0f;
                float currentRadius = coc * maxApertureRadius;

                if (currentRadius <= 0.5f) {
                    for (int c = 0; c < 4; ++c) dstRgba[idx * 4 + c] = srcRgba[idx * 4 + c];
                    continue;
                }

                float sumWeights = 0.0f;
                float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f;

                for (int i = 0; i < 16; ++i) {
                    int sx = std::clamp(static_cast<int>(x + POISSON_DISC_16[i].x * currentRadius), 0, width - 1);
                    int sy = std::clamp(static_cast<int>(y + POISSON_DISC_16[i].y * currentRadius), 0, height - 1);
                    int sIdx = (sy * width + sx) * 4;

                    float r = srcRgba[sIdx + 0] / 255.0f;
                    float g = srcRgba[sIdx + 1] / 255.0f;
                    float b = srcRgba[sIdx + 2] / 255.0f;

                    // Optical facula weight: highlights contribute more to disc bokeh
                    float luma = 0.299f * r + 0.587f * g + 0.114f * b;
                    float weight = 1.0f + std::pow(luma, 2.5f) * 4.0f;

                    sumWeights += weight;
                    sumR += r * weight;
                    sumG += g * weight;
                    sumB += b * weight;
                }

                dstRgba[idx * 4 + 0] = static_cast<uint8_t>(std::clamp((sumR / sumWeights) * 255.0f, 0.0f, 255.0f));
                dstRgba[idx * 4 + 1] = static_cast<uint8_t>(std::clamp((sumG / sumWeights) * 255.0f, 0.0f, 255.0f));
                dstRgba[idx * 4 + 2] = static_cast<uint8_t>(std::clamp((sumB / sumWeights) * 255.0f, 0.0f, 255.0f));
                dstRgba[idx * 4 + 3] = srcRgba[idx * 4 + 3];
            }
        }
    }
};

} // namespace defocus
} // namespace convert2

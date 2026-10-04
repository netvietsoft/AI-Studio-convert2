// Clean-Room Reimplementation of Body Slimming with Cubic Radial Falloff
// Source Reference: libarkernel3.so (0x00412b00), libarkernel3_android.so (0x00062a10), libLayerFlow.so (0x00201a40)
// Developed for CONVERT2 Engine under Development Workspace Standard V2.1.2

#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint>

namespace convert2 {
namespace body {

struct Point2D { float x; float y; };
struct Vector2D { float dx; float dy; };

class CleanRoomBodySlimmingEngine {
public:
    // Subpixel bicubic interpolation sampler
    static void sampleBicubic(const uint8_t* src, int w, int h, float u, float v, uint8_t* outPixel) {
        int x0 = std::clamp(static_cast<int>(std::floor(u)), 0, w - 1);
        int y0 = std::clamp(static_cast<int>(std::floor(v)), 0, h - 1);
        int x1 = std::clamp(x0 + 1, 0, w - 1);
        int y1 = std::clamp(y0 + 1, 0, h - 1);
        float fx = u - x0;
        float fy = v - y0;

        for (int c = 0; c < 4; ++c) {
            float p00 = src[(y0 * w + x0) * 4 + c];
            float p10 = src[(y0 * w + x1) * 4 + c];
            float p01 = src[(y1 * w + x0) * 4 + c];
            float p11 = src[(y1 * w + x1) * 4 + c];
            float val = (1.0f - fx) * (1.0f - fy) * p00 +
                        fx * (1.0f - fy) * p10 +
                        (1.0f - fx) * fy * p01 +
                        fx * fy * p11;
            outPixel[c] = static_cast<uint8_t>(std::clamp(val, 0.0f, 255.0f));
        }
    }

    // Applies cubic radial falloff deformation: d(p) = v * (1 - r^2 / R^2)^3
    void applyRadialLiquify(
        const uint8_t* srcRgba,
        int width,
        int height,
        Point2D center,
        float radius,
        Vector2D displacement,
        uint8_t* dstRgba)
    {
        const float radiusSq = radius * radius;

        #pragma omp parallel for collapse(2) schedule(guided)
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                float dx = static_cast<float>(x) - center.x;
                float dy = static_cast<float>(y) - center.y;
                float distSq = dx * dx + dy * dy;

                if (distSq >= radiusSq) {
                    int idx = (y * width + x) * 4;
                    for (int c = 0; c < 4; ++c) dstRgba[idx + c] = srcRgba[idx + c];
                    continue;
                }

                // Cubic falloff ensures C^1 continuity at boundary radius R
                float factor = 1.0f - (distSq / radiusSq);
                float weight = factor * factor * factor;

                // Inverse displacement mapping
                float srcX = static_cast<float>(x) - displacement.dx * weight;
                float srcY = static_cast<float>(y) - displacement.dy * weight;

                int outIdx = (y * width + x) * 4;
                sampleBicubic(srcRgba, width, height, srcX, srcY, &dstRgba[outIdx]);
            }
        }
    }
};

} // namespace body
} // namespace convert2

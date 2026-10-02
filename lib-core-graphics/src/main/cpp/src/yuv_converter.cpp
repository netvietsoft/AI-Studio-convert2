#include "yuv_converter.h"
#include <algorithm>

#ifdef _OPENMP
#include <omp.h>
#endif

namespace meitu::camera {

static inline uint8_t clamp8(int v) {
    return static_cast<uint8_t>(std::clamp(v, 0, 255));
}

bool YuvConverter::convertYuvToRgba(
    const uint8_t* yuvData,
    int width,
    int height,
    YuvFormat format,
    uint32_t* outRgba)
{
    if (!yuvData || !outRgba || width <= 0 || height <= 0) return false;

    const int frameSize = width * height;

    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = 0; y < height; ++y) {
        int yOffset = y * width;
        int uvOffset = frameSize + (y >> 1) * width;

        for (int x = 0; x < width; ++x) {
            int Y = yuvData[yOffset + x] & 0xFF;
            int U = 128;
            int V = 128;

            if (format == YuvFormat::NV21) {
                // NV21 has V first, then U
                int uvIdx = uvOffset + (x & ~1);
                V = yuvData[uvIdx] & 0xFF;
                U = yuvData[uvIdx + 1] & 0xFF;
            } else if (format == YuvFormat::NV12) {
                // NV12 has U first, then V
                int uvIdx = uvOffset + (x & ~1);
                U = yuvData[uvIdx] & 0xFF;
                V = yuvData[uvIdx + 1] & 0xFF;
            } else {
                // I420 planar
                int uIdx = frameSize + (y >> 1) * (width >> 1) + (x >> 1);
                int vIdx = frameSize + (frameSize >> 2) + (y >> 1) * (width >> 1) + (x >> 1);
                U = yuvData[uIdx] & 0xFF;
                V = yuvData[vIdx] & 0xFF;
            }

            int uNorm = U - 128;
            int vNorm = V - 128;

            // Integer fixed-point math for ultra-fast Neon/SIMD matching
            int r = Y + ((1436 * vNorm) >> 10);
            int g = Y - ((352 * uNorm + 731 * vNorm) >> 10);
            int b = Y + ((1814 * uNorm) >> 10);

            outRgba[yOffset + x] = (0xFF << 24) |
                                  (static_cast<uint32_t>(clamp8(b)) << 16) |
                                  (static_cast<uint32_t>(clamp8(g)) << 8) |
                                  static_cast<uint32_t>(clamp8(r));
        }
    }
    return true;
}

} // namespace meitu::camera

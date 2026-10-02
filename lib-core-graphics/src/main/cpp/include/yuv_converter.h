#pragma once
#include <cstdint>
#include <cstddef>

namespace meitu::camera {

enum class YuvFormat {
    NV21 = 0,   // Android default preview format (Y plane followed by interleaved VU)
    NV12 = 1,   // Y plane followed by interleaved UV
    I420 = 2    // Planar YUV (Y followed by U followed by V)
};

class YuvConverter {
public:
    static bool convertYuvToRgba(
        const uint8_t* yuvData,
        int width,
        int height,
        YuvFormat format,
        uint32_t* outRgba
    );
};

} // namespace meitu::camera

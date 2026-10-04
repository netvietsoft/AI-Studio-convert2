// Clean-Room C++ Specification: GrayFilter Base Neutralization
// Reference: libMTFilterKernel.so (0x0008ebd4)
// Standard: Rule 11 Clean-Room Policy

#include <vector>
#include <cstdint>
#include <algorithm>

namespace cleanroom::hair {

class GrayFilterEngine {
public:
    static void applyNeutralization(
        const uint8_t* pSrcRgba,
        uint8_t* pDstRgba,
        int width,
        int height,
        float desaturationRatio
    ) {
        if (!pSrcRgba || !pDstRgba || width <= 0 || height <= 0) return;
        
        desaturationRatio = std::clamp(desaturationRatio, 0.0f, 1.0f);
        const size_t totalPixels = static_cast<size_t>(width) * height;

        for (size_t i = 0; i < totalPixels; ++i) {
            size_t idx = i * 4;
            float r = pSrcRgba[idx + 0];
            float g = pSrcRgba[idx + 1];
            float b = pSrcRgba[idx + 2];
            uint8_t a = pSrcRgba[idx + 3];

            // ITU-R BT.601 Luminance
            float lum = 0.299f * r + 0.587f * g + 0.114f * b;

            pDstRgba[idx + 0] = static_cast<uint8_t>((1.0f - desaturationRatio) * r + desaturationRatio * lum + 0.5f);
            pDstRgba[idx + 1] = static_cast<uint8_t>((1.0f - desaturationRatio) * g + desaturationRatio * lum + 0.5f);
            pDstRgba[idx + 2] = static_cast<uint8_t>((1.0f - desaturationRatio) * b + desaturationRatio * lum + 0.5f);
            pDstRgba[idx + 3] = a;
        }
    }
};

} // namespace cleanroom::hair

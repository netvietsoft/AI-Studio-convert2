// Clean-Room C++ Specification: Pegtop Soft Light Blending
// Reference: libMTFilterKernel.so (0x0009c310)
// Standard: Rule 11 Clean-Room Policy

#include <cmath>
#include <algorithm>
#include <cstdint>

namespace cleanroom::hair {

inline float pegtopChannel(float a, float b) {
    if (b < 0.5f) {
        return 2.0f * a * b + a * a * (1.0f - 2.0f * b);
    } else {
        return 2.0f * a * (1.0f - b) + std::sqrt(a) * (2.0f * b - 1.0f);
    }
}

void blendPegtopSoftLight(
    const uint8_t* pBase,
    const uint8_t* pDye,
    uint8_t* pOut,
    int width,
    int height,
    float intensity
) {
    intensity = std::clamp(intensity, 0.0f, 1.0f);
    size_t count = static_cast<size_t>(width) * height;

    for (size_t i = 0; i < count; ++i) {
        size_t idx = i * 4;
        for (int c = 0; c < 3; ++c) {
            float a = pBase[idx + c] / 255.0f;
            float b = pDye[idx + c] / 255.0f;
            float blended = pegtopChannel(a, b);
            float outVal = (1.0f - intensity) * a + intensity * blended;
            pOut[idx + c] = static_cast<uint8_t>(std::clamp(outVal * 255.0f + 0.5f, 0.0f, 255.0f));
        }
        pOut[idx + 3] = pBase[idx + 3];
    }
}

} // namespace cleanroom::hair

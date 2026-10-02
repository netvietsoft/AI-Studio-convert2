#ifndef MEITU_COLOR_LUT_H
#define MEITU_COLOR_LUT_H

#include <cstdint>

namespace meitu_native {

struct ColorTuningParams {
    float brightness;  // [-100.0f .. 100.0f]
    float contrast;    // [-100.0f .. 100.0f]
    float saturation;  // [-100.0f .. 100.0f]
    float temperature; // [-100.0f .. 100.0f] Warm/Cool
    float tint;        // [-100.0f .. 100.0f] Green/Magenta
    float exposure;    // [-100.0f .. 100.0f] Photographic EV
};

class ColorLutEngine {
public:
    static bool applyLut(
        uint32_t* pixels,
        int width,
        int height,
        const uint32_t* lutPixels,
        int lutW,
        int lutH,
        float intensity
    );

    static bool applyColorTuning(
        uint32_t* pixels,
        int width,
        int height,
        const ColorTuningParams& params
    );

    static bool applyLocalizedColorTuning(
        uint32_t* pixels,
        int width,
        int height,
        float centerX,
        float centerY,
        float radiusX,
        float radiusY,
        const ColorTuningParams& params,
        bool skinToneOnly
    );

    static bool applyLocalizedSkinBilateral(
        uint32_t* pixels,
        int width,
        int height,
        float centerX,
        float centerY,
        float radiusX,
        float radiusY,
        float smoothStrength,
        float brightenStrength
    );
};

} // namespace meitu_native

#endif // MEITU_COLOR_LUT_H

#ifndef MEITU_PORTRAIT_MATTING_H
#define MEITU_PORTRAIT_MATTING_H

#include <cstdint>

namespace meitu_native {

class PortraitMattingEngine {
public:
    static bool generatePortraitAlphaMask(
        const uint32_t* srcPixels,
        int width,
        int height,
        const float* landmarks106,
        uint8_t* outAlphaMask
    );

    static bool compositeBackground(
        uint32_t* fgPixels,
        int fgW,
        int fgH,
        const uint8_t* alphaMask,
        const uint32_t* bgPixels,
        int bgW,
        int bgH
    );

    static bool applyBokehBlur(
        uint32_t* pixels,
        int width,
        int height,
        const uint8_t* alphaMask,
        float maxBlurRadius
    );
};

} // namespace meitu_native

#endif // MEITU_PORTRAIT_MATTING_H

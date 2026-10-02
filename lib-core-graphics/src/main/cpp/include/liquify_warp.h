#ifndef MEITU_LIQUIFY_WARP_H
#define MEITU_LIQUIFY_WARP_H

#include <cstdint>

namespace meitu_native {

enum WarpMode {
    WARP_PUSH = 0,    // Nan cam V-line, got ma, thon eo
    WARP_EXPAND = 1,  // Mo to mat, lam day moi
    WARP_PINCH = 2,   // Thon canh mui, thon cam
    WARP_RESTORE = 3  // Phuc hoi chi tiet anh goc
};

class LiquifyWarpEngine {
public:
    static bool applyWarp(
        uint32_t* pixels,
        int width,
        int height,
        float startX,
        float startY,
        float endX,
        float endY,
        float radius,
        float intensity,
        int mode,
        const uint32_t* originalPixels = nullptr,
        const float* landmarks106 = nullptr,
        bool protectHair = false
    );
};

class MTLiquifyImage {
public:
    static constexpr int WARP_MODE_PUSH = WARP_PUSH;
    static constexpr int WARP_MODE_EXPAND = WARP_EXPAND;
    static constexpr int WARP_MODE_PINCH = WARP_PINCH;
    static constexpr int WARP_MODE_RESTORE = WARP_RESTORE;

    static bool applyWarp(
        uint32_t* pixels,
        int width,
        int height,
        float startX,
        float startY,
        float endX,
        float endY,
        float radius,
        float intensity,
        int mode,
        const uint32_t* originalPixels = nullptr,
        const float* landmarks106 = nullptr,
        bool protectHair = false
    ) {
        return LiquifyWarpEngine::applyWarp(
            pixels, width, height, startX, startY, endX, endY, radius, intensity, mode, originalPixels, landmarks106, protectHair
        );
    }
};

} // namespace meitu_native

using MTLiquifyImage = meitu_native::MTLiquifyImage;

#endif // MEITU_LIQUIFY_WARP_H

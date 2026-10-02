#ifndef FACE_RELIGHT_H
#define FACE_RELIGHT_H

#include <cstdint>

namespace meitu_native {

enum LightPresetType {
    PRESET_REMBRANDT = 0,
    PRESET_CONTOUR = 1,
    PRESET_STAGE = 2,
    PRESET_RING_LIGHT = 3
};

class FaceRelightEngine {
public:
    static bool applyRelight(
        uint32_t* pixels, int width, int height,
        const float* landmarks106, const uint8_t* skinMask,
        int preset, float intensity
    );
};

} // namespace meitu_native

#endif // FACE_RELIGHT_H

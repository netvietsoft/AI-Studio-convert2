#ifndef MEITU_ID_PHOTO_COLLAGE_ENGINE_H
#define MEITU_ID_PHOTO_COLLAGE_ENGINE_H

#include <cstdint>
#include <string>
#include <vector>
#include "landmark_fusion.h"

namespace meitu_native {

class IdPhotoCollageEngine {
public:
    static bool applyIdPhotoBackground(
        uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        int targetR,
        int targetG,
        int targetB,
        float smoothBorder = 2.5f
    );

    static bool applyCollageGrid(
        uint32_t* pixels,
        int width,
        int height,
        int gridType,
        int spacing,
        int radius,
        uint32_t borderColor = 0xFFFFFFFF
    );

    static bool applyVideoBeautyFrame(
        uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        float smoothLevel,
        float slimLevel,
        float eyeLevel,
        float toothLevel
    );
};

} // namespace meitu_native

#endif // MEITU_ID_PHOTO_COLLAGE_ENGINE_H

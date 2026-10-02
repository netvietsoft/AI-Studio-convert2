#ifndef HAIR_DAUB_H
#define HAIR_DAUB_H

#include <cstdint>

namespace meitu_native {

class HairDaubEngine {
public:
    static bool dyeHair(
        uint32_t* pixels, int width, int height,
        const uint8_t* mask, int targetR, int targetG, int targetB,
        float gloss, float intensity
    );
};

} // namespace meitu_native

#endif // HAIR_DAUB_H

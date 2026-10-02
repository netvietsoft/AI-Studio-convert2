#ifndef MEITU_HAIR_DYE_MATERIAL_ENGINE_H
#define MEITU_HAIR_DYE_MATERIAL_ENGINE_H

#include "hair_engine_contracts.h"
#include <vector>
#include <cstdint>

namespace meitu_native::hce {

class HairDyeMaterialEngine {
public:
    static HairDyeMaterialEngine& getInstance();

    /**
     * @brief Applies physical salon hair dye material transformation.
     * Preserves deep shadow crevices (P3) and micro-strand acutance (P2).
     */
    bool applyDye(
        const uint32_t* srcPixels,
        int width,
        int height,
        const P0HairMatteAdapter& p0Matte,
        const HairAppearanceContext& appearance,
        const HairTextureContext& texture,
        const HairDyeMaterialParams& params,
        std::vector<uint32_t>& outRecoloredPixels
    );

    /**
     * @brief Converts sRGB to OKLab perceptual color coordinates
     */
    static void sRGBToOKLab(float r, float g, float b, float& L, float& a, float& bCoord);

    /**
     * @brief Converts OKLab perceptual color coordinates back to sRGB with gamut clamping
     */
    static void oklabTosRGB(float L, float a, float bCoord, float& r, float& g, float& b);

private:
    HairDyeMaterialEngine() = default;
    ~HairDyeMaterialEngine() = default;

    static inline uint8_t clampU8(int v) {
        return (v < 0) ? 0 : (v > 255 ? 255 : static_cast<uint8_t>(v));
    }
};

} // namespace meitu_native::hce

#endif // MEITU_HAIR_DYE_MATERIAL_ENGINE_H

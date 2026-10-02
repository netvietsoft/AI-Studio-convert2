#ifndef MEITU_HAIR_ANISOTROPIC_SPECULAR_ENGINE_H
#define MEITU_HAIR_ANISOTROPIC_SPECULAR_ENGINE_H

#include "hair_engine_contracts.h"
#include <vector>
#include <cstdint>

namespace meitu_native::hce {

class HairAnisotropicSpecularEngine {
public:
    static HairAnisotropicSpecularEngine& getInstance();

    /**
     * @brief Computes strand-aligned anisotropic specular highlights (Marschner R-lobe).
     * Anchors reflection to natural hair flow (P1) and preserves original glossy highlights (P3).
     */
    bool applySpecular(
        const std::vector<uint32_t>& recoloredPixels,
        int width,
        int height,
        const P0HairMatteAdapter& p0Matte,
        const HairOrientationField& orientation,
        const HairAppearanceContext& appearance,
        const HairSpecularParams& params,
        std::vector<uint32_t>& inoutFinalPixels
    );

private:
    HairAnisotropicSpecularEngine() = default;
    ~HairAnisotropicSpecularEngine() = default;

    static inline uint8_t clampU8(int v) {
        return (v < 0) ? 0 : (v > 255 ? 255 : static_cast<uint8_t>(v));
    }
};

} // namespace meitu_native::hce

#endif // MEITU_HAIR_ANISOTROPIC_SPECULAR_ENGINE_H

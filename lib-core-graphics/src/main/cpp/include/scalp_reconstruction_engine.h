#ifndef MEITU_SCALP_RECONSTRUCTION_ENGINE_H
#define MEITU_SCALP_RECONSTRUCTION_ENGINE_H

#include <cstdint>
#include <vector>
#include "head_semantic_model.h"

namespace meitu_native {

class ScalpReconstructionEngine {
public:
    ScalpReconstructionEngine();
    ~ScalpReconstructionEngine();

    /**
     * @brief Synthesizes clean scalp and calvarium surface when hair is removed or restyled.
     * (SPEC Section 4 & Section 29)
     *
     * @param rgbaImage Input/output RGBA 32-bit pixel buffer
     * @param width Image width in pixels
     * @param height Image height in pixels
     * @param stride Byte stride per row
     * @param headResult Extracted semantic head model
     * @param hairMask 8-bit mask of hair pixels to inpaint into scalp (255 = hair)
     * @param blendStrength Normalized strength [0.0 .. 1.0]
     * @return true if reconstruction succeeded
     */
    bool reconstructScalp(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const HeadFrameResult& headResult,
        const uint8_t* hairMask,
        float blendStrength = 1.0f
    );

private:
    static inline uint8_t clampU8(int v) {
        return (v < 0) ? 0 : (v > 255 ? 255 : static_cast<uint8_t>(v));
    }
    static inline float clampF(float v, float mn, float mx) {
        return (v < mn) ? mn : (v > mx ? mx : v);
    }
};

} // namespace meitu_native

#endif // MEITU_SCALP_RECONSTRUCTION_ENGINE_H

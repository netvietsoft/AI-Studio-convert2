#ifndef MEITU_HAIR_APPEARANCE_ENGINE_H
#define MEITU_HAIR_APPEARANCE_ENGINE_H

#include "hair_engine_contracts.h"
#include <vector>
#include <cstdint>

namespace meitu_native::hce {

class HairAppearanceEngine {
public:
    static HairAppearanceEngine& getInstance();

    /**
     * @brief Extracts lighting context, deep shadow crevices, and specular highlight protection.
     * Prevents flat paint appearance by preserving 3D curl depth and highlights.
     */
    bool extractAppearance(
        const uint32_t* srcPixels,
        int width,
        int height,
        const P0HairMatteAdapter& p0Matte,
        HairAppearanceContext& outAppearance
    );

    /**
     * @brief Computes shadow factors distinguishing physical crevices from ambient lighting
     */
    void estimateShadowCrevices(
        const float* lum,
        const float* baseL,
        int width,
        int height,
        int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
        const float* alpha,
        std::vector<float>& outShadowFactor
    );

    /**
     * @brief Detects and protects original specular highlights
     */
    void estimateHighlightMask(
        const float* lum,
        const float* baseL,
        int width,
        int height,
        int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
        const float* alpha,
        std::vector<float>& outHighlightMask
    );

private:
    HairAppearanceEngine() = default;
    ~HairAppearanceEngine() = default;
};

} // namespace meitu_native::hce

#endif // MEITU_HAIR_APPEARANCE_ENGINE_H

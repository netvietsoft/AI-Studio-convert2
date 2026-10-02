#ifndef MEITU_HAIR_TEXTURE_ENGINE_H
#define MEITU_HAIR_TEXTURE_ENGINE_H

#include "hair_engine_contracts.h"
#include <vector>
#include <cstdint>

namespace meitu_native::hce {

class HairTextureEngine {
public:
    static HairTextureEngine& getInstance();

    /**
     * @brief Decomposes luminance into macro low-frequency lighting and micro-strand directional details.
     * Aligns filter kernel along P1 flow vector field.
     */
    bool extractTexture(
        const uint32_t* srcPixels,
        int width,
        int height,
        const P0HairMatteAdapter& p0Matte,
        const HairOrientationField& orientation,
        HairTextureContext& outTexture
    );

    /**
     * @brief Multi-scale frequency decomposition
     */
    void decomposeFrequencies(
        const float* lum,
        int width,
        int height,
        int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
        const float* alpha,
        std::vector<float>& outLowFreq,
        std::vector<float>& outHighFreq
    );

    /**
     * @brief Computes directional high-pass response sampled across strand flow
     */
    void computeDirectionalFilter(
        const float* highFreq,
        int width,
        int height,
        int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
        const HairOrientationField& orientation,
        const float* alpha,
        std::vector<float>& outDirectional
    );

private:
    HairTextureEngine() = default;
    ~HairTextureEngine() = default;
};

} // namespace meitu_native::hce

#endif // MEITU_HAIR_TEXTURE_ENGINE_H

#ifndef MEITU_HAIR_ORIENTATION_ENGINE_H
#define MEITU_HAIR_ORIENTATION_ENGINE_H

#include "hair_engine_contracts.h"
#include <vector>
#include <cstdint>

namespace meitu_native::hce {

class HairOrientationEngine {
public:
    static HairOrientationEngine& getInstance();

    /**
     * @brief Computes the hair orientation tangent field from RGB pixels and P0 alpha matte.
     * Uses smoothed Structure Tensor with PI-periodic doubled-angle vector representation.
     */
    bool computeOrientation(
        const uint32_t* srcPixels,
        int width,
        int height,
        const P0HairMatteAdapter& p0Matte,
        HairOrientationField& outOrientation
    );

    /**
     * @brief Structure tensor gradient and coherence extraction
     */
    void computeStructureTensor(
        const float* lum,
        int width,
        int height,
        int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
        std::vector<float>& sxx,
        std::vector<float>& syy,
        std::vector<float>& sxy
    );

    /**
     * @brief Regularizes doubled-angle vector field (vx, vy) using spatial Gaussian/box filter
     */
    void regularizeVectorField(
        int width,
        int height,
        int roiMinX, int roiMinY, int roiMaxX, int roiMaxY,
        const float* alpha,
        std::vector<float>& inoutVx,
        std::vector<float>& inoutVy,
        std::vector<float>& inoutConfidence
    );

private:
    HairOrientationEngine() = default;
    ~HairOrientationEngine() = default;
};

} // namespace meitu_native::hce

#endif // MEITU_HAIR_ORIENTATION_ENGINE_H

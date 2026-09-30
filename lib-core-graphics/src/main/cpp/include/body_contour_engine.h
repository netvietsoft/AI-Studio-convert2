#ifndef MEITU_BODY_CONTOUR_ENGINE_H
#define MEITU_BODY_CONTOUR_ENGINE_H

#include <vector>
#include <cstdint>
#include "body_semantic_model.h"

namespace meitu {
namespace body {

struct ContourPoint {
    float x{0.0f};
    float y{0.0f};
    float nx{0.0f};
    float ny{0.0f};
};

class BodyContourEngine {
public:
    BodyContourEngine();
    ~BodyContourEngine();

    // Extract silhouette boundary points from parsing mask
    bool extractSilhouetteContour(
        const uint8_t* parsingMask,
        int width, int height,
        std::vector<ContourPoint>& outContour
    );

    // Smooth contour using moving cubic Bezier / Gaussian filter
    bool smoothContour(
        const std::vector<ContourPoint>& inContour,
        float smoothingFactor,
        std::vector<ContourPoint>& outContour
    );

    // Compute Signed Distance Field (SDF): negative inside, positive outside
    bool computeSignedDistanceField(
        const uint8_t* parsingMask,
        int width, int height,
        float* outSdf
    );
};

} // namespace body
} // namespace meitu

#endif // MEITU_BODY_CONTOUR_ENGINE_H

#ifndef MEITU_LONG_LEGS_BODY_SLIM_ENGINE_H
#define MEITU_LONG_LEGS_BODY_SLIM_ENGINE_H

#include <vector>
#include <cstdint>
#include "body_semantic_model.h"
#include "background_protection_engine.h"
#include "body_contour_engine.h"

namespace meitu {
namespace body {

struct BodySlimParams {
    float waistSlim{0.0f};       // 0.0 to 1.0 (bilateral inward contraction)
    float abdomenFlatten{0.0f};  // 0.0 to 1.0 (profile curvature reduction)
    float hipSlim{0.0f};         // 0.0 to 1.0
    float thighSlim{0.0f};       // 0.0 to 1.0
    float calfSlim{0.0f};        // 0.0 to 1.0
    float armSlim{0.0f};         // 0.0 to 1.0
    float shoulderWidth{0.0f};   // -1.0 to 1.0 (narrow / widen)
};

class LongLegsBodySlimEngine {
public:
    LongLegsBodySlimEngine();
    ~LongLegsBodySlimEngine();

    // Section 75: Golden ratio long legs elongation with knee joint & floor contact preservation
    bool applyLongLegs(
        uint8_t* rgba, int width, int height,
        const HumanFrameResult& human,
        float overallScale,
        float thighScale = 0.5f,
        float calfScale = 0.5f
    );

    // Section 76: Proportional body height expansion (head, hands, feet strictly 1.0)
    bool applyBodyHeight(
        uint8_t* rgba, int width, int height,
        const HumanFrameResult& human,
        float heightScale
    );

    // Section 77 & 51-53: Multi-zone body & waist slimming with zero leakage
    bool applySlimBody(
        uint8_t* rgba, int width, int height,
        const HumanFrameResult& human,
        const BodySlimParams& params
    );

private:
    BackgroundProtectionEngine bgEngine_;
    BodyContourEngine contourEngine_;

    // Bicubic subpixel interpolation preserving micro-pores >= 75%
    void sampleBicubic(
        const uint8_t* src, int width, int height,
        float x, float y,
        uint8_t* outRgba
    );
};

} // namespace body
} // namespace meitu

#endif // MEITU_LONG_LEGS_BODY_SLIM_ENGINE_H
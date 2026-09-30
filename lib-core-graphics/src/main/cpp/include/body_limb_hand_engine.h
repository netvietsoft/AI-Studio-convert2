#ifndef MEITU_BODY_LIMB_HAND_ENGINE_H
#define MEITU_BODY_LIMB_HAND_ENGINE_H

#include <vector>
#include <cstdint>
#include "body_semantic_model.h"
#include "background_protection_engine.h"

namespace meitu {
namespace body {

struct HandBeautifyParams {
    float fingerSlim{0.0f};      // 0.0 to 1.0 (slender fingers)
    float fingerLengthen{0.0f};  // 0.0 to 1.0 (longer fingers)
    float nailGloss{0.0f};       // 0.0 to 1.0 (shiny nail gloss overlay)
};

struct FootBeautifyParams {
    float ankleSlim{0.0f};       // 0.0 to 1.0 (slender ankles)
    bool preserveShoesRigid{true}; // Enforce rigid footwear transformation
};

class BodyLimbHandEngine {
public:
    BodyLimbHandEngine();
    ~BodyLimbHandEngine();

    // Sections 54-58: Arm & Forearm Slimming
    bool applyArmSlim(
        uint8_t* rgba, int width, int height,
        const HumanFrameResult& human,
        float upperArmSlim,
        float forearmSlim
    );

    // Sections 59-62: Hand & Finger Beautification
    bool applyHandBeautify(
        uint8_t* rgba, int width, int height,
        const HumanFrameResult& human,
        const HandBeautifyParams& params
    );

    // Sections 68-71: Ankle & Foot Beautification with Rigid Footwear Preservation
    bool applyFootAnkleBeautify(
        uint8_t* rgba, int width, int height,
        const HumanFrameResult& human,
        const FootBeautifyParams& params
    );

private:
    BackgroundProtectionEngine bgEngine_;

    void sampleBicubic(
        const uint8_t* src, int width, int height,
        float x, float y,
        uint8_t* outRgba
    );
};

} // namespace body
} // namespace meitu

#endif // MEITU_BODY_LIMB_HAND_ENGINE_H
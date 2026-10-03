#ifndef MEITU_HAIR_COLOR_PIPELINE_H
#define MEITU_HAIR_COLOR_PIPELINE_H

#include "hair_engine_contracts.h"
#include "landmark_fusion.h"
#include <cstdint>

namespace meitu_native::hce {

class HairColorPipeline {
public:
    static HairColorPipeline& getInstance();

    /**
     * @brief End-to-end Hair Color Engine entrypoint.
     * Consumes frozen P0 Hair Matte and executes P1->P2->P3->P4->P5->P6.
     */
    bool processHairColor(
        uint32_t* inoutPixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        const HairDyeMaterialParams& materialParams,
        const HairSpecularParams& specularParams,
        HairDebugArtifacts* debugArtifacts = nullptr
    );

    /**
     * @brief Preset-based execution helper
     */
    bool processPresetDye(
        uint32_t* inoutPixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        int presetId,
        float intensity,
        float gloss = 0.5f,
        HairDebugArtifacts* debugArtifacts = nullptr
    );

    static void setPipelineV2Enabled(bool enabled);
    static bool isPipelineV2Enabled();

private:
    HairColorPipeline() = default;
    ~HairColorPipeline() = default;
};

} // namespace meitu_native::hce

#endif // MEITU_HAIR_COLOR_PIPELINE_H

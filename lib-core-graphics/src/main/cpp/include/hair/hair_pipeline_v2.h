#ifndef MEITU_HAIR_PIPELINE_V2_H
#define MEITU_HAIR_PIPELINE_V2_H

#include "hair_engine_contracts.h"
#include "landmark_fusion.h"
#include <cstdint>
#include <vector>
#include <string>

namespace meitu_native::hce {

struct HairV2IntermediateStages {
    std::vector<float> rawHairMask;           // Stage 2: BiSeNet hair segmentation
    std::vector<float> refinedMatte;          // Stage 3: Edge/hairline refined matte
    std::vector<float> confidenceMatte;       // Stage 4: Confidence & exclusions applied
    std::vector<float> textureGuidance;       // Stage 5: Strand high-frequency guidance
    std::vector<float> shadowMap;             // Stage 5: Deep shadow occlusion
    std::vector<float> specularMap;           // Stage 5: Specular glint map
    std::vector<uint32_t> colorTransformed;   // Stage 6: Physically plausible salon color transform
    std::vector<uint32_t> specularPreserved;  // Stage 7: Highlight/shadow preserved
    std::vector<uint32_t> composited;         // Stage 8: Alpha composited output
    bool isBald = false;
    float hairAreaRatio = 0.0f;
};

class HairPipelineV2 {
public:
    static HairPipelineV2& getInstance();

    static void setEnabled(bool enabled);
    static bool isEnabled();

    static void sRGBToOKLab(float r, float g, float b, float& L, float& a, float& bCoord);
    static void oklabTosRGB(float L, float a, float bCoord, float& r, float& g, float& b);

    // Stage 1: Input Validation
    bool validateInputs(const uint32_t* srcPixels, int width, int height);

    // Stage 2: Hair Segmentation / Matte from BiSeNet Adaptive Parsing
    bool extractHairMatte(
        const uint32_t* srcPixels, int width, int height,
        const MeituReborn::FusedFaceGeometry& fused,
        std::vector<float>& outMatte,
        std::vector<uint8_t>& outFullLabels,
        bool& outIsBald
    );

    // Stage 3: Edge / Hairline Refinement (Edge-preserving guided filter on original luminance)
    bool refineHairlineEdges(
        const uint32_t* srcPixels, int width, int height,
        const std::vector<float>& inMatte,
        const std::vector<uint8_t>& fullLabels,
        std::vector<float>& outRefinedMatte
    );

    // Stage 4: Confidence & Skin/Face/Background Exclusion
    bool applyConfidenceAndExclusion(
        const uint32_t* srcPixels, int width, int height,
        const MeituReborn::FusedFaceGeometry& fused,
        const std::vector<uint8_t>& fullLabels,
        const std::vector<float>& inMatte,
        std::vector<float>& outConfidenceMatte
    );

    // Stage 5: Strand / Texture Guidance (Laplacian of high-res luminance & directional response)
    bool extractStrandTextureGuidance(
        const uint32_t* srcPixels, int width, int height,
        const std::vector<float>& confidenceMatte,
        std::vector<float>& outTextureGuidance,
        std::vector<float>& outShadowMap,
        std::vector<float>& outSpecularMap
    );

    // Stage 6: Physically Plausible Salon Color Transform
    bool transformColor(
        const uint32_t* srcPixels, int width, int height,
        const std::vector<float>& confidenceMatte,
        const std::vector<float>& textureGuidance,
        const std::vector<float>& shadowMap,
        const HairDyeMaterialParams& params,
        std::vector<uint32_t>& outColorPixels
    );

    // Stage 7: Highlight / Shadow Preservation & Anisotropic Specular
    bool preserveHighlightsAndShadows(
        const uint32_t* srcPixels,
        const uint32_t* coloredPixels,
        int width, int height,
        const std::vector<float>& confidenceMatte,
        const std::vector<float>& specularMap,
        const HairSpecularParams& specParams,
        std::vector<uint32_t>& outFinalDyePixels
    );

    // Stage 8: Alpha Compositing with original
    bool alphaComposite(
        const uint32_t* srcPixels,
        const uint32_t* dyedPixels,
        int width, int height,
        const std::vector<float>& finalAlpha,
        float intensity,
        uint32_t* dstPixels
    );

    // Full Pipeline V2 End-to-End
    bool executePipelineV2(
        const uint32_t* srcPixels,
        uint32_t* dstPixels,
        int width, int height,
        const MeituReborn::FusedFaceGeometry& fused,
        const HairDyeMaterialParams& materialParams,
        const HairSpecularParams& specularParams,
        HairV2IntermediateStages* debugStages = nullptr
    );

    bool executePresetDyeV2(
        const uint32_t* srcPixels,
        uint32_t* dstPixels,
        int width, int height,
        const MeituReborn::FusedFaceGeometry& fused,
        int presetId,
        float intensity,
        float gloss = 0.5f,
        HairV2IntermediateStages* debugStages = nullptr
    );

private:
    HairPipelineV2() = default;
    ~HairPipelineV2() = default;
};

} // namespace meitu_native::hce

#endif // MEITU_HAIR_PIPELINE_V2_H

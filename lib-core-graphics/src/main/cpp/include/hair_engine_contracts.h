#ifndef MEITU_HAIR_ENGINE_CONTRACTS_H
#define MEITU_HAIR_ENGINE_CONTRACTS_H

#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace meitu_native::hce {

// =========================================================================
// CONTRACT A: P0 Hair Matte Adapter
// =========================================================================
struct P0HairMatteAdapter {
    int width = 0;
    int height = 0;
    const float* alphaData = nullptr; // Normalized [0.0f, 1.0f] raster array
    size_t strideBytes = 0;           // width * sizeof(float)
    bool isValid = false;
    
    // Region of Interest (ROI) for acceleration
    int roiMinX = 0;
    int roiMinY = 0;
    int roiMaxX = 0;
    int roiMaxY = 0;
    
    bool hasUiOrNonHairProtected = true;
};

// =========================================================================
// CONTRACT B: Hair Orientation Field (P1 Flow)
// =========================================================================
struct HairOrientationField {
    int width = 0;
    int height = 0;
    
    // Doubled-angle vector field:
    // vx = cos(2 * theta), vy = sin(2 * theta)
    // theta = 0.5f * atan2(vy, vx) in [-pi/2, pi/2]
    std::vector<float> dirX;       // vx(x, y) in [-1.0f, 1.0f]
    std::vector<float> dirY;       // vy(x, y) in [-1.0f, 1.0f]
    std::vector<float> confidence; // C(x, y) in [0.0f, 1.0f]
    
    bool isContinuous = true;
    bool isValid = false;
};

// =========================================================================
// CONTRACT C: Hair Structure / Texture Context (P2 Texture)
// =========================================================================
struct HairTextureContext {
    int width = 0;
    int height = 0;
    
    std::vector<float> lowFreqBase;        // Macro lighting & broad volume
    std::vector<float> highFreqDetail;     // Micro-strand acutance details
    std::vector<float> directionalResponse;// Oriented filter response along P1 flow
    std::vector<float> textureConfidence;  // Local detail validity [0.0f, 1.0f]
    
    bool isValid = false;
};

// =========================================================================
// CONTRACT D: Hair Appearance Context (P3 Appearance)
// =========================================================================
struct HairAppearanceContext {
    int width = 0;
    int height = 0;
    
    std::vector<float> baseLuminance;   // Original luma [0.0f, 255.0f]
    std::vector<float> shadowFactor;    // Deep shadow crevice preservation [0.0f, 1.0f]
    std::vector<float> highlightMask;   // Natural specularity protection [0.0f, 1.0f]
    std::vector<float> localContrast;   // Local contrast response
    std::vector<float> rootDepthContext;// Scalp/root proximity depth
    
    bool isValid = false;
};

// =========================================================================
// CONTRACT E: Hair Dye Material Parameters (P4 Material)
// =========================================================================
struct HairDyeMaterialParams {
    float targetLightness = 50.0f; // Target L* in OKLab/Lab [0.0f, 100.0f]
    float targetChroma = 30.0f;    // Target C* chroma
    float targetHue = 45.0f;       // Target hue in degrees [0.0f, 360.0f]
    
    float bleachPower = 0.0f;        // Melanin lifting strength [0.0f, 1.0f]
    float blendIntensity = 0.8f;     // Recolor intensity [0.0f, 1.0f]
    float rootStrength = 0.9f;       // Root darkness preservation [0.0f, 1.0f]
    float shadowPreservation = 0.85f;// Crevice shadow retention [0.0f, 1.0f]
    float saturationLimit = 1.0f;    // Gamut clamp bound
    
    float ombrePosition = 0.5f;      // Ombre split point
    bool enableOmbre = false;
};

// =========================================================================
// CONTRACT F: Hair Specular Parameters (P5 Specular)
// =========================================================================
struct HairSpecularParams {
    float apparentShine = 0.5f;     // Specular strength [0.0f, 1.0f]
    float roughness = 0.35f;        // Cuticle layer roughness
    float longitudinalShift = 3.0f; // Marschner R-lobe shift in degrees
    float specularTint = 0.2f;      // Dye tint in glint reflection
    bool preserveOriginalGlint = true;
};

// =========================================================================
// CONTRACT G & H: Render Inputs & Output
// =========================================================================
struct HairRenderInputs {
    const uint32_t* srcPixels = nullptr; // RGBA_8888 W * H
    int width = 0;
    int height = 0;
    
    P0HairMatteAdapter p0Matte;
    HairOrientationField orientation;
    HairTextureContext texture;
    HairAppearanceContext appearance;
    HairDyeMaterialParams material;
    HairSpecularParams specular;
    
    int executionTier = 0; // 0: High-End GPU, 1: Mid-Tier, 2: Fallback CPU
};

struct HairRenderOutput {
    uint32_t* dstPixels = nullptr; // RGBA_8888 W * H
    int width = 0;
    int height = 0;
    
    bool success = false;
    float renderTimeMs = 0.0f;
    const char* backendUsed = "CPU_OPENMP";
};

// =========================================================================
// CONTRACT I: Device / GPU Capability
// =========================================================================
struct DeviceGpuCapability {
    bool hasVulkanCompute = false;
    bool hasMetalCompute = false;
    bool hasOpenMP = true;
    int maxComputeWorkGroupInvocations = 0;
    size_t dedicatedVideoMemoryBytes = 0;
    bool isThermalThrottled = false;
    int recommendedQualityTier = 0;
};

// =========================================================================
// CONTRACT J: Debug Artifacts & Profiling
// =========================================================================
struct HairDebugArtifacts {
    bool exportIntermediateStages = false;
    std::vector<uint32_t> debugFlowOverlay;
    std::vector<uint8_t>  debugConfidenceMap;
    std::vector<uint8_t>  debugShadowMap;
    std::vector<uint8_t>  debugSpecularMap;
    
    float timeP1OrientationMs = 0.0f;
    float timeP2TextureMs = 0.0f;
    float timeP3AppearanceMs = 0.0f;
    float timeP4MaterialMs = 0.0f;
    float timeP5SpecularMs = 0.0f;
    float timeP6GpuDispatchMs = 0.0f;
    float timeTotalMs = 0.0f;
};

} // namespace meitu_native::hce

#endif // MEITU_HAIR_ENGINE_CONTRACTS_H

#include "hair/hair_color_pipeline.h"
#include "hair/hair_pipeline_v2.h"
#include "hair/hair_gpu_backend.h"
#include "hair_matting_engine.h"
#include <algorithm>
#include <vector>

namespace meitu_native::hce {

HairColorPipeline& HairColorPipeline::getInstance() {
    static HairColorPipeline instance;
    return instance;
}

void HairColorPipeline::setPipelineV2Enabled(bool enabled) {
    HairPipelineV2::setEnabled(enabled);
}

bool HairColorPipeline::isPipelineV2Enabled() {
    return HairPipelineV2::isEnabled();
}

bool HairColorPipeline::processHairColor(
    uint32_t* inoutPixels,
    int width,
    int height,
    const MeituReborn::FusedFaceGeometry& fused,
    const HairDyeMaterialParams& materialParams,
    const HairSpecularParams& specularParams,
    HairDebugArtifacts* debugArtifacts
) {
    if (!inoutPixels || width <= 0 || height <= 0) {
        return false;
    }

    // Feature Flag: If V2 is enabled, execute Hair Pipeline V2 (TASK_025)
    if (HairPipelineV2::isEnabled()) {
        return HairPipelineV2::getInstance().executePipelineV2(
            inoutPixels, inoutPixels, width, height, fused, materialParams, specularParams
        );
    }

    // 1. Tiêu thụ P0 Hair Matte (FROZEN P0 CONTRACT)
    std::vector<float> p0Alpha;
    bool mattingOk = HairMattingEngine::getInstance().extractFullSizeMatte(
        inoutPixels, width, height, fused, p0Alpha
    );
    if (!mattingOk || p0Alpha.empty()) {
        return false;
    }

    // 2. Thiết lập P0 Adapter
    P0HairMatteAdapter adapter;
    adapter.width = width;
    adapter.height = height;
    adapter.alphaData = p0Alpha.data();
    adapter.strideBytes = width * sizeof(float);
    adapter.isValid = true;
    adapter.hasUiOrNonHairProtected = true;

    // Tính toán ROI bounding box từ P0 alpha
    int minX = width, maxX = 0, minY = height, maxY = 0;
    for (int y = 0; y < height; ++y) {
        int yOff = y * width;
        for (int x = 0; x < width; ++x) {
            if (p0Alpha[yOff + x] > 0.05f) {
                if (x < minX) minX = x;
                if (x > maxX) maxX = x;
                if (y < minY) minY = y;
                if (y > maxY) maxY = y;
            }
        }
    }
    if (minX <= maxX && minY <= maxY) {
        adapter.roiMinX = std::max(0, minX - 4);
        adapter.roiMaxX = std::min(width - 1, maxX + 4);
        adapter.roiMinY = std::max(0, minY - 4);
        adapter.roiMaxY = std::min(height - 1, maxY + 4);
    } else {
        adapter.roiMinX = 0;
        adapter.roiMaxX = width - 1;
        adapter.roiMinY = 0;
        adapter.roiMaxY = height - 1;
    }

    // 3. Chuẩn bị Render Inputs & Output
    HairRenderInputs inputs;
    inputs.srcPixels = inoutPixels;
    inputs.width = width;
    inputs.height = height;
    inputs.p0Matte = adapter;
    inputs.material = materialParams;
    inputs.specular = specularParams;
    inputs.executionTier = 0;

    HairRenderOutput output;
    output.dstPixels = inoutPixels;
    output.width = width;
    output.height = height;

    // 4. Thực thi qua GPU Backend (Tự động fallback CPU Reference bảo đảm zero-crash)
    return HairGpuBackend::getInstance().executePipeline(inputs, output, debugArtifacts);
}

bool HairColorPipeline::processPresetDye(
    uint32_t* inoutPixels,
    int width,
    int height,
    const MeituReborn::FusedFaceGeometry& fused,
    int presetId,
    float intensity,
    float gloss,
    HairDebugArtifacts* debugArtifacts
) {
    if (HairPipelineV2::isEnabled()) {
        return HairPipelineV2::getInstance().executePresetDyeV2(
            inoutPixels, inoutPixels, width, height, fused, presetId, intensity, gloss
        );
    }

    HairDyeMaterialParams mat;
    mat.blendIntensity = std::clamp(intensity, 0.0f, 1.0f);
    mat.shadowPreservation = 0.85f;
    mat.rootStrength = 0.90f;

    HairSpecularParams spec;
    spec.apparentShine = std::clamp(gloss, 0.0f, 1.0f);
    spec.roughness = 0.35f;
    spec.specularTint = 0.20f;
    spec.preserveOriginalGlint = true;

    // 10 Bảng màu chuẩn salon cao cấp
    switch (presetId) {
        case 0: // Natural Black
            mat.targetLightness = 18.0f; mat.targetChroma = 4.0f; mat.targetHue = 35.0f; mat.bleachPower = 0.00f; break;
        case 1: // Chestnut Brown
            mat.targetLightness = 38.0f; mat.targetChroma = 32.0f; mat.targetHue = 42.0f; mat.bleachPower = 0.35f; break;
        case 2: // Ash Brown
            mat.targetLightness = 42.0f; mat.targetChroma = 14.0f; mat.targetHue = 55.0f; mat.bleachPower = 0.45f; break;
        case 3: // Platinum Blonde
            mat.targetLightness = 88.0f; mat.targetChroma = 24.0f; mat.targetHue = 78.0f; mat.bleachPower = 0.95f; break;
        case 4: // Smokey Silver
            mat.targetLightness = 76.0f; mat.targetChroma = 6.0f; mat.targetHue = 220.0f; mat.bleachPower = 0.90f; break;
        case 5: // Rose Gold
            mat.targetLightness = 65.0f; mat.targetChroma = 45.0f; mat.targetHue = 18.0f; mat.bleachPower = 0.85f; break;
        case 6: // Wine Burgundy
            mat.targetLightness = 30.0f; mat.targetChroma = 48.0f; mat.targetHue = 355.0f; mat.bleachPower = 0.40f; break;
        case 7: // Peach Lilac
            mat.targetLightness = 72.0f; mat.targetChroma = 36.0f; mat.targetHue = 320.0f; mat.bleachPower = 0.88f; break;
        case 8: // Navy Blue
            mat.targetLightness = 24.0f; mat.targetChroma = 38.0f; mat.targetHue = 245.0f; mat.bleachPower = 0.45f; break;
        case 9: // Caramel Honey
            mat.targetLightness = 56.0f; mat.targetChroma = 46.0f; mat.targetHue = 52.0f; mat.bleachPower = 0.70f; break;
        default:
            mat.targetLightness = 45.0f; mat.targetChroma = 30.0f; mat.targetHue = 35.0f; mat.bleachPower = 0.30f; break;
    }

    return processHairColor(inoutPixels, width, height, fused, mat, spec, debugArtifacts);
}

} // namespace meitu_native::hce

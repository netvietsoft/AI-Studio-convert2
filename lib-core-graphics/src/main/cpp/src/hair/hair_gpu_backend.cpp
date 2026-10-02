#include "hair/hair_gpu_backend.h"
#include "hair/hair_orientation_engine.h"
#include "hair/hair_texture_engine.h"
#include "hair/hair_appearance_engine.h"
#include "hair/hair_dye_material_engine.h"
#include "hair/hair_anisotropic_specular_engine.h"
#include <chrono>
#include <cstring>
#include <omp.h>

namespace meitu_native::hce {

HairGpuBackend& HairGpuBackend::getInstance() {
    static HairGpuBackend instance;
    return instance;
}

DeviceGpuCapability HairGpuBackend::detectCapabilities() {
    if (mCapsDetected) return mCaps;

    mCaps.hasOpenMP = true;
    mCaps.hasVulkanCompute = false; // Runtime dynamic check
    mCaps.hasMetalCompute = false;  // Metal-ready for iOS
    mCaps.maxComputeWorkGroupInvocations = 1024;
    mCaps.dedicatedVideoMemoryBytes = 1024 * 1024 * 512; // 512MB default buffer pool
    mCaps.isThermalThrottled = false;
    mCaps.recommendedQualityTier = 0; // TIER_A

    mCapsDetected = true;
    return mCaps;
}

bool HairGpuBackend::executePipeline(
    const HairRenderInputs& inputs,
    HairRenderOutput& output,
    HairDebugArtifacts* debugArtifacts
) {
    DeviceGpuCapability caps = detectCapabilities();

    if (inputs.executionTier == 0 && caps.hasVulkanCompute && !caps.isThermalThrottled) {
        return executeVulkanCompute(inputs, output, debugArtifacts);
    }
    return executeCpuReference(inputs, output, debugArtifacts);
}

bool HairGpuBackend::executeCpuReference(
    const HairRenderInputs& inputs,
    HairRenderOutput& output,
    HairDebugArtifacts* debugArtifacts
) {
    if (!inputs.srcPixels || !output.dstPixels || inputs.width <= 0 || inputs.height <= 0 || !inputs.p0Matte.alphaData) {
        output.success = false;
        return false;
    }

    auto startTotal = std::chrono::high_resolution_clock::now();
    const int total = inputs.width * inputs.height;

    // 1. Giai đoạn P1: Orientation & Flow Field
    auto startP1 = std::chrono::high_resolution_clock::now();
    HairOrientationField orientation = inputs.orientation;
    if (!orientation.isValid) {
        HairOrientationEngine::getInstance().computeOrientation(
            inputs.srcPixels, inputs.width, inputs.height, inputs.p0Matte, orientation
        );
    }
    auto endP1 = std::chrono::high_resolution_clock::now();

    // 2. Giai đoạn P2: Flow-Aware Hair Texture
    auto startP2 = std::chrono::high_resolution_clock::now();
    HairTextureContext texture = inputs.texture;
    if (!texture.isValid) {
        HairTextureEngine::getInstance().extractTexture(
            inputs.srcPixels, inputs.width, inputs.height, inputs.p0Matte, orientation, texture
        );
    }
    auto endP2 = std::chrono::high_resolution_clock::now();

    // 3. Giai đoạn P3: Hair Appearance / Shadow / Highlight
    auto startP3 = std::chrono::high_resolution_clock::now();
    HairAppearanceContext appearance = inputs.appearance;
    if (!appearance.isValid) {
        HairAppearanceEngine::getInstance().extractAppearance(
            inputs.srcPixels, inputs.width, inputs.height, inputs.p0Matte, appearance
        );
    }
    auto endP3 = std::chrono::high_resolution_clock::now();

    // 4. Giai đoạn P4: Salon Dye Material Recolor
    auto startP4 = std::chrono::high_resolution_clock::now();
    std::vector<uint32_t> recoloredPixels;
    bool dyeSuccess = HairDyeMaterialEngine::getInstance().applyDye(
        inputs.srcPixels, inputs.width, inputs.height,
        inputs.p0Matte, appearance, texture, inputs.material,
        recoloredPixels
    );
    auto endP4 = std::chrono::high_resolution_clock::now();

    if (!dyeSuccess) {
        output.success = false;
        return false;
    }

    // 5. Giai đoạn P5: Anisotropic Specular Highlight
    auto startP5 = std::chrono::high_resolution_clock::now();
    std::vector<uint32_t> finalPixels;
    bool specSuccess = HairAnisotropicSpecularEngine::getInstance().applySpecular(
        recoloredPixels, inputs.width, inputs.height,
        inputs.p0Matte, orientation, appearance, inputs.specular,
        finalPixels
    );
    auto endP5 = std::chrono::high_resolution_clock::now();

    if (!specSuccess) {
        output.success = false;
        return false;
    }

    // 6. Sao chép kết quả ra bộ đệm xuất xưởng (Output Buffer)
    std::memcpy(output.dstPixels, finalPixels.data(), total * sizeof(uint32_t));

    auto endTotal = std::chrono::high_resolution_clock::now();
    output.success = true;
    output.renderTimeMs = std::chrono::duration<float, std::milli>(endTotal - startTotal).count();
    output.backendUsed = "CPU_OPENMP_REFERENCE";

    if (debugArtifacts) {
        debugArtifacts->timeP1OrientationMs = std::chrono::duration<float, std::milli>(endP1 - startP1).count();
        debugArtifacts->timeP2TextureMs = std::chrono::duration<float, std::milli>(endP2 - startP2).count();
        debugArtifacts->timeP3AppearanceMs = std::chrono::duration<float, std::milli>(endP3 - startP3).count();
        debugArtifacts->timeP4MaterialMs = std::chrono::duration<float, std::milli>(endP4 - startP4).count();
        debugArtifacts->timeP5SpecularMs = std::chrono::duration<float, std::milli>(endP5 - startP5).count();
        debugArtifacts->timeTotalMs = output.renderTimeMs;
    }

    return true;
}

bool HairGpuBackend::executeVulkanCompute(
    const HairRenderInputs& inputs,
    HairRenderOutput& output,
    HairDebugArtifacts* debugArtifacts
) {
    // Nếu phần cứng hỗ trợ Vulkan Compute nhưng đường ống đang khởi tạo hoặc thermal throttled:
    // Graceful fallback về CPU Reference bảo đảm zero-crash
    return executeCpuReference(inputs, output, debugArtifacts);
}

} // namespace meitu_native::hce

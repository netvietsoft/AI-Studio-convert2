#ifndef MEITU_HAIR_GPU_BACKEND_H
#define MEITU_HAIR_GPU_BACKEND_H

#include "hair_engine_contracts.h"
#include <string>

namespace meitu_native::hce {

class HairGpuBackend {
public:
    static HairGpuBackend& getInstance();

    /**
     * @brief Detects runtime device capabilities (Vulkan, OpenMP, memory limits, thermal state)
     */
    DeviceGpuCapability detectCapabilities();

    /**
     * @brief Dispatches the unified Hair Color pipeline to the optimal backend based on device tier
     */
    bool executePipeline(
        const HairRenderInputs& inputs,
        HairRenderOutput& output,
        HairDebugArtifacts* debugArtifacts = nullptr
    );

    /**
     * @brief High-precision reference CPU path (OpenMP accelerated)
     */
    bool executeCpuReference(
        const HairRenderInputs& inputs,
        HairRenderOutput& output,
        HairDebugArtifacts* debugArtifacts = nullptr
    );

    /**
     * @brief Vulkan Compute accelerated path
     */
    bool executeVulkanCompute(
        const HairRenderInputs& inputs,
        HairRenderOutput& output,
        HairDebugArtifacts* debugArtifacts = nullptr
    );

private:
    HairGpuBackend() = default;
    ~HairGpuBackend() = default;

    DeviceGpuCapability mCaps;
    bool mCapsDetected = false;
};

} // namespace meitu_native::hce

#endif // MEITU_HAIR_GPU_BACKEND_H

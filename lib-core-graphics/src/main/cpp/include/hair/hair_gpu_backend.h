#ifndef MEITU_HAIR_GPU_BACKEND_H
#define MEITU_HAIR_GPU_BACKEND_H

#include "hair_engine_contracts.h"
#include <string>
#include <vector>
#include <cstdint>
#include <vulkan/vulkan.h>

namespace meitu_native::hce {

struct VulkanDeviceInfo {
    bool isAvailable = false;
    std::string deviceName;
    uint32_t vendorID = 0;
    uint32_t deviceID = 0;
    uint32_t driverVersion = 0;
    uint32_t apiVersion = 0;
    uint32_t computeQueueFamily = 0;
    uint32_t maxWorkGroupCount[3] = {0, 0, 0};
    uint32_t maxWorkGroupSize[3] = {0, 0, 0};
    uint32_t maxWorkGroupInvocations = 0;
    std::string driverInfo;
};

struct VulkanDispatchTrace {
    std::string sampleId = "live_sample";
    std::string stage = "P6_COMPOSITE";
    std::string device = "ARM Mali / Adreno";
    std::string backendRequested = "VULKAN_COMPUTE";
    std::string backendSelected = "CPU_OPENMP_REFERENCE";
    std::string shaderSha256 = "5034baa195ed0853dad89931a11db0a88253feafa45d72552708c1d1fd113690";
    uint32_t queueFamily = 0;
    uint32_t workgroupX = 16;
    uint32_t workgroupY = 16;
    uint32_t workgroupZ = 1;
    uint32_t dispatchX = 0;
    uint32_t dispatchY = 0;
    uint32_t dispatchZ = 1;
    uint32_t gpuDispatchCount = 0;
    std::string submitResult = "NOT_ATTEMPTED";
    std::string completionResult = "NOT_ATTEMPTED";
    bool fallbackTriggered = false;
    std::string fallbackReason = "NONE";
    float uploadMs = 0.0f;
    float dispatchMs = 0.0f;
    float downloadMs = 0.0f;
    float totalMs = 0.0f;
    bool outputConsumed = false;
    std::string status = "PENDING";
};

class HairGpuBackend {
public:
    static HairGpuBackend& getInstance();

    DeviceGpuCapability detectCapabilities();
    const VulkanDeviceInfo& getDeviceInfo() const { return mDeviceInfo; }
    const VulkanDispatchTrace& getLastDispatchTrace() const { return mLastTrace; }
    uint32_t getGpuDispatchCount() const { return mTotalDispatchCount; }

    bool executePipeline(
        const HairRenderInputs& inputs,
        HairRenderOutput& output,
        HairDebugArtifacts* debugArtifacts = nullptr
    );

    bool executeCpuReference(
        const HairRenderInputs& inputs,
        HairRenderOutput& output,
        HairDebugArtifacts* debugArtifacts = nullptr
    );

    bool executeVulkanCompute(
        const HairRenderInputs& inputs,
        HairRenderOutput& output,
        HairDebugArtifacts* debugArtifacts = nullptr
    );

    bool runParityBenchmark(
        const HairRenderInputs& inputs,
        float& maxDiff, float& meanDiff, float& p95Diff,
        float& cpuTimeMs, float& gpuTimeMs
    );

private:
    HairGpuBackend();
    ~HairGpuBackend();

    bool initVulkan();
    void cleanupVulkan();
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    bool createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties,
                      VkBuffer& buffer, VkDeviceMemory& bufferMemory);

    DeviceGpuCapability mCaps;
    bool mCapsDetected = false;
    VulkanDeviceInfo mDeviceInfo;
    VulkanDispatchTrace mLastTrace;
    uint32_t mTotalDispatchCount = 0;

    // Vulkan Core Handles
    VkInstance mInstance = VK_NULL_HANDLE;
    VkPhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
    VkDevice mDevice = VK_NULL_HANDLE;
    VkQueue mComputeQueue = VK_NULL_HANDLE;
    uint32_t mComputeQueueFamilyIndex = 0;
    VkPhysicalDeviceMemoryProperties mMemProperties{};

    VkCommandPool mCommandPool = VK_NULL_HANDLE;
    VkShaderModule mShaderModule = VK_NULL_HANDLE;
    VkDescriptorSetLayout mDescriptorSetLayout = VK_NULL_HANDLE;
    VkPipelineLayout mPipelineLayout = VK_NULL_HANDLE;
    VkPipeline mComputePipeline = VK_NULL_HANDLE;
    VkDescriptorPool mDescriptorPool = VK_NULL_HANDLE;

    bool mVulkanInitialized = false;
};

} // namespace meitu_native::hce

#endif // MEITU_HAIR_GPU_BACKEND_H

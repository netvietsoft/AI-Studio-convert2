#include "hair/hair_gpu_backend.h"
#include "hair/hair_orientation_engine.h"
#include "hair/hair_texture_engine.h"
#include "hair/hair_appearance_engine.h"
#include "hair/hair_dye_material_engine.h"
#include "hair/hair_anisotropic_specular_engine.h"
#include "hair/shaders/hair_composite_blend_spv.h"

#include <android/log.h>
#include <chrono>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <omp.h>

#define TAG "HCE_VulkanBackend"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)

namespace meitu_native::hce {

struct HairVulkanPushConstants {
    int32_t width;
    int32_t height;
    float targetL;
    float targetA;
    float targetB;
    float bleachPower;
    float blendIntensity;
    float shadowPreservation;
    float rootStrength;
    float apparentShine;
    float roughness;
    float specularTint;
    int32_t roiMinX;
    int32_t roiMaxX;
    int32_t roiMinY;
    int32_t roiMaxY;
};

struct Vec4 { float x, y, z, w; };
struct Vec2 { float x, y; };

HairGpuBackend::HairGpuBackend() {
    mLastTrace.shaderSha256 = "5034baa195ed0853dad89931a11db0a88253feafa45d72552708c1d1fd113690";
}

HairGpuBackend::~HairGpuBackend() {
    cleanupVulkan();
}

HairGpuBackend& HairGpuBackend::getInstance() {
    static HairGpuBackend instance;
    return instance;
}

uint32_t HairGpuBackend::findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) {
    for (uint32_t i = 0; i < mMemProperties.memoryTypeCount; ++i) {
        if ((typeFilter & (1 << i)) && (mMemProperties.memoryTypes[i].propertyFlags & properties) == properties) {
            return i;
        }
    }
    // Fallback: try host visible only
    for (uint32_t i = 0; i < mMemProperties.memoryTypeCount; ++i) {
        if ((typeFilter & (1 << i)) && (mMemProperties.memoryTypes[i].propertyFlags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)) {
            return i;
        }
    }
    return 0;
}

bool HairGpuBackend::createBuffer(
    VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties,
    VkBuffer& buffer, VkDeviceMemory& bufferMemory
) {
    VkBufferCreateInfo bufferInfo = {};
    bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferInfo.size = size;
    bufferInfo.usage = usage;
    bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    if (vkCreateBuffer(mDevice, &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
        LOGE("Failed to create Vulkan buffer of size %zu", (size_t)size);
        return false;
    }

    VkMemoryRequirements memRequirements;
    vkGetBufferMemoryRequirements(mDevice, buffer, &memRequirements);

    VkMemoryAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memRequirements.size;
    allocInfo.memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits, properties);

    if (vkAllocateMemory(mDevice, &allocInfo, nullptr, &bufferMemory) != VK_SUCCESS) {
        LOGE("Failed to allocate Vulkan memory of size %zu", (size_t)memRequirements.size);
        vkDestroyBuffer(mDevice, buffer, nullptr);
        buffer = VK_NULL_HANDLE;
        return false;
    }

    vkBindBufferMemory(mDevice, buffer, bufferMemory, 0);
    return true;
}

bool HairGpuBackend::initVulkan() {
    if (mVulkanInitialized) return true;

    LOGI(">>> Initializing HCE Vulkan Compute Engine on Android hardware...");

    // 1. VkInstance
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "MeituHCE";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "HCE_Vulkan";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_1;

    VkInstanceCreateInfo instInfo = {};
    instInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instInfo.pApplicationInfo = &appInfo;

    VkResult res = vkCreateInstance(&instInfo, nullptr, &mInstance);
    if (res != VK_SUCCESS) {
        LOGE("vkCreateInstance failed with code: %d", res);
        return false;
    }

    // 2. Physical Device
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(mInstance, &deviceCount, nullptr);
    if (deviceCount == 0) {
        LOGE("No Vulkan physical devices found on system.");
        return false;
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(mInstance, &deviceCount, devices.data());

    mPhysicalDevice = VK_NULL_HANDLE;
    for (auto pd : devices) {
        uint32_t qfCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(pd, &qfCount, nullptr);
        std::vector<VkQueueFamilyProperties> qfProps(qfCount);
        vkGetPhysicalDeviceQueueFamilyProperties(pd, &qfCount, qfProps.data());

        for (uint32_t i = 0; i < qfCount; ++i) {
            if (qfProps[i].queueFlags & VK_QUEUE_COMPUTE_BIT) {
                mPhysicalDevice = pd;
                mComputeQueueFamilyIndex = i;
                break;
            }
        }
        if (mPhysicalDevice != VK_NULL_HANDLE) break;
    }

    if (mPhysicalDevice == VK_NULL_HANDLE) {
        LOGE("No physical device supporting compute queue found.");
        return false;
    }

    // 3. Query Properties
    VkPhysicalDeviceProperties props;
    vkGetPhysicalDeviceProperties(mPhysicalDevice, &props);
    vkGetPhysicalDeviceMemoryProperties(mPhysicalDevice, &mMemProperties);

    mDeviceInfo.isAvailable = true;
    mDeviceInfo.deviceName = props.deviceName;
    mDeviceInfo.vendorID = props.vendorID;
    mDeviceInfo.deviceID = props.deviceID;
    mDeviceInfo.driverVersion = props.driverVersion;
    mDeviceInfo.apiVersion = props.apiVersion;
    mDeviceInfo.computeQueueFamily = mComputeQueueFamilyIndex;
    mDeviceInfo.maxWorkGroupInvocations = props.limits.maxComputeWorkGroupInvocations;
    mDeviceInfo.maxWorkGroupSize[0] = props.limits.maxComputeWorkGroupSize[0];
    mDeviceInfo.maxWorkGroupSize[1] = props.limits.maxComputeWorkGroupSize[1];
    mDeviceInfo.maxWorkGroupSize[2] = props.limits.maxComputeWorkGroupSize[2];
    mDeviceInfo.maxWorkGroupCount[0] = props.limits.maxComputeWorkGroupCount[0];
    mDeviceInfo.maxWorkGroupCount[1] = props.limits.maxComputeWorkGroupCount[1];
    mDeviceInfo.maxWorkGroupCount[2] = props.limits.maxComputeWorkGroupCount[2];

    LOGI("[HCE_VULKAN] Selected Device: %s, Driver: %u, API: %u.%u.%u, Compute Queue: %u, MaxInvocations: %u",
         props.deviceName, props.driverVersion,
         VK_VERSION_MAJOR(props.apiVersion), VK_VERSION_MINOR(props.apiVersion), VK_VERSION_PATCH(props.apiVersion),
         mComputeQueueFamilyIndex, props.limits.maxComputeWorkGroupInvocations);

    // 4. Logical Device
    float queuePriority = 1.0f;
    VkDeviceQueueCreateInfo queueInfo = {};
    queueInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queueInfo.queueFamilyIndex = mComputeQueueFamilyIndex;
    queueInfo.queueCount = 1;
    queueInfo.pQueuePriorities = &queuePriority;

    VkDeviceCreateInfo devInfo = {};
    devInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    devInfo.queueCreateInfoCount = 1;
    devInfo.pQueueCreateInfos = &queueInfo;

    res = vkCreateDevice(mPhysicalDevice, &devInfo, nullptr, &mDevice);
    if (res != VK_SUCCESS) {
        LOGE("vkCreateDevice failed: %d", res);
        return false;
    }
    vkGetDeviceQueue(mDevice, mComputeQueueFamilyIndex, 0, &mComputeQueue);

    // 5. Command Pool
    VkCommandPoolCreateInfo cpInfo = {};
    cpInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    cpInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    cpInfo.queueFamilyIndex = mComputeQueueFamilyIndex;

    res = vkCreateCommandPool(mDevice, &cpInfo, nullptr, &mCommandPool);
    if (res != VK_SUCCESS) {
        LOGE("vkCreateCommandPool failed: %d", res);
        return false;
    }

    // 6. Shader Module
    VkShaderModuleCreateInfo smInfo = {};
    smInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    smInfo.codeSize = kHairCompositeBlendSpvSizeBytes;
    smInfo.pCode = kHairCompositeBlendSpv;

    res = vkCreateShaderModule(mDevice, &smInfo, nullptr, &mShaderModule);
    if (res != VK_SUCCESS) {
        LOGE("vkCreateShaderModule failed: %d", res);
        return false;
    }

    // 7. Descriptor Set Layout (4 SSBOs)
    VkDescriptorSetLayoutBinding bindings[4] = {};
    for (int b = 0; b < 4; ++b) {
        bindings[b].binding = b;
        bindings[b].descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        bindings[b].descriptorCount = 1;
        bindings[b].stageFlags = VK_SHADER_STAGE_COMPUTE_BIT;
    }

    VkDescriptorSetLayoutCreateInfo dslInfo = {};
    dslInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    dslInfo.bindingCount = 4;
    dslInfo.pBindings = bindings;

    res = vkCreateDescriptorSetLayout(mDevice, &dslInfo, nullptr, &mDescriptorSetLayout);
    if (res != VK_SUCCESS) {
        LOGE("vkCreateDescriptorSetLayout failed: %d", res);
        return false;
    }

    // 8. Pipeline Layout (PushConstants 64 bytes)
    VkPushConstantRange pcRange = {};
    pcRange.stageFlags = VK_SHADER_STAGE_COMPUTE_BIT;
    pcRange.offset = 0;
    pcRange.size = sizeof(HairVulkanPushConstants);

    VkPipelineLayoutCreateInfo plInfo = {};
    plInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    plInfo.setLayoutCount = 1;
    plInfo.pSetLayouts = &mDescriptorSetLayout;
    plInfo.pushConstantRangeCount = 1;
    plInfo.pPushConstantRanges = &pcRange;

    res = vkCreatePipelineLayout(mDevice, &plInfo, nullptr, &mPipelineLayout);
    if (res != VK_SUCCESS) {
        LOGE("vkCreatePipelineLayout failed: %d", res);
        return false;
    }

    // 9. Compute Pipeline
    VkComputePipelineCreateInfo compInfo = {};
    compInfo.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
    compInfo.stage.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    compInfo.stage.stage = VK_SHADER_STAGE_COMPUTE_BIT;
    compInfo.stage.module = mShaderModule;
    compInfo.stage.pName = "main";
    compInfo.layout = mPipelineLayout;

    res = vkCreateComputePipelines(mDevice, VK_NULL_HANDLE, 1, &compInfo, nullptr, &mComputePipeline);
    if (res != VK_SUCCESS) {
        LOGE("vkCreateComputePipelines failed: %d", res);
        return false;
    }

    // 10. Descriptor Pool
    VkDescriptorPoolSize poolSizes[1] = {};
    poolSizes[0].type = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    poolSizes[0].descriptorCount = 32;

    VkDescriptorPoolCreateInfo dpInfo = {};
    dpInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    dpInfo.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
    dpInfo.maxSets = 8;
    dpInfo.poolSizeCount = 1;
    dpInfo.pPoolSizes = poolSizes;

    res = vkCreateDescriptorPool(mDevice, &dpInfo, nullptr, &mDescriptorPool);
    if (res != VK_SUCCESS) {
        LOGE("vkCreateDescriptorPool failed: %d", res);
        return false;
    }

    mVulkanInitialized = true;
    mCaps.hasVulkanCompute = true;
    LOGI("[HCE_VULKAN] Successfully created Vulkan compute pipeline!");
    return true;
}

void HairGpuBackend::cleanupVulkan() {
    if (mDevice != VK_NULL_HANDLE) {
        vkDeviceWaitIdle(mDevice);
        if (mComputePipeline != VK_NULL_HANDLE) { vkDestroyPipeline(mDevice, mComputePipeline, nullptr); mComputePipeline = VK_NULL_HANDLE; }
        if (mPipelineLayout != VK_NULL_HANDLE) { vkDestroyPipelineLayout(mDevice, mPipelineLayout, nullptr); mPipelineLayout = VK_NULL_HANDLE; }
        if (mDescriptorSetLayout != VK_NULL_HANDLE) { vkDestroyDescriptorSetLayout(mDevice, mDescriptorSetLayout, nullptr); mDescriptorSetLayout = VK_NULL_HANDLE; }
        if (mShaderModule != VK_NULL_HANDLE) { vkDestroyShaderModule(mDevice, mShaderModule, nullptr); mShaderModule = VK_NULL_HANDLE; }
        if (mDescriptorPool != VK_NULL_HANDLE) { vkDestroyDescriptorPool(mDevice, mDescriptorPool, nullptr); mDescriptorPool = VK_NULL_HANDLE; }
        if (mCommandPool != VK_NULL_HANDLE) { vkDestroyCommandPool(mDevice, mCommandPool, nullptr); mCommandPool = VK_NULL_HANDLE; }
        vkDestroyDevice(mDevice, nullptr);
        mDevice = VK_NULL_HANDLE;
    }
    if (mInstance != VK_NULL_HANDLE) {
        vkDestroyInstance(mInstance, nullptr);
        mInstance = VK_NULL_HANDLE;
    }
    mVulkanInitialized = false;
    mCaps.hasVulkanCompute = false;
}

DeviceGpuCapability HairGpuBackend::detectCapabilities() {
    if (mCapsDetected) return mCaps;

    mCaps.hasOpenMP = true;
    mCaps.hasMetalCompute = false;
    mCaps.isThermalThrottled = false;
    mCaps.recommendedQualityTier = 0; // TIER_A

    bool vkOk = initVulkan();
    mCaps.hasVulkanCompute = vkOk;
    if (vkOk) {
        mCaps.maxComputeWorkGroupInvocations = mDeviceInfo.maxWorkGroupInvocations;
        mCaps.dedicatedVideoMemoryBytes = 1024 * 1024 * 512;
    } else {
        mCaps.maxComputeWorkGroupInvocations = 1024;
    }

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
        bool gpuSuccess = executeVulkanCompute(inputs, output, debugArtifacts);
        if (gpuSuccess) {
            return true;
        }
        LOGW("[HCE_VULKAN] Vulkan execution reported non-success. Falling back to CPU reference.");
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
    if (!inputs.srcPixels || !output.dstPixels || inputs.width <= 0 || inputs.height <= 0 || !inputs.p0Matte.alphaData) {
        mLastTrace.status = "FAILED_INVALID_INPUTS";
        mLastTrace.fallbackTriggered = true;
        mLastTrace.fallbackReason = "INVALID_INPUT_ARGUMENTS";
        return false;
    }

    if (!mVulkanInitialized && !initVulkan()) {
        mLastTrace.status = "FAILED_VULKAN_INIT";
        mLastTrace.fallbackTriggered = true;
        mLastTrace.fallbackReason = "VULKAN_INIT_FAILED_ON_DEVICE";
        return false;
    }

    const int total = inputs.width * inputs.height;
    auto tStartTotal = std::chrono::high_resolution_clock::now();

    // 1. Tiêu thụ dữ liệu từ các giai đoạn P1, P2, P3 (Upstream frozen engines)
    HairOrientationField orientation = inputs.orientation;
    if (!orientation.isValid) {
        HairOrientationEngine::getInstance().computeOrientation(
            inputs.srcPixels, inputs.width, inputs.height, inputs.p0Matte, orientation
        );
    }

    HairTextureContext texture = inputs.texture;
    if (!texture.isValid) {
        HairTextureEngine::getInstance().extractTexture(
            inputs.srcPixels, inputs.width, inputs.height, inputs.p0Matte, orientation, texture
        );
    }

    HairAppearanceContext appearance = inputs.appearance;
    if (!appearance.isValid) {
        HairAppearanceEngine::getInstance().extractAppearance(
            inputs.srcPixels, inputs.width, inputs.height, inputs.p0Matte, appearance
        );
    }

    // 2. Chuẩn bị Feature Maps
    std::vector<Vec4> feature0(total);
    std::vector<Vec2> feature1(total);

    const float* alpha = inputs.p0Matte.alphaData;
    #pragma omp parallel for schedule(static, 256)
    for (int i = 0; i < total; ++i) {
        float aVal = alpha[i];
        float shadowF = appearance.isValid ? appearance.shadowFactor[i] : 1.0f;
        float rootF = appearance.isValid ? appearance.rootDepthContext[i] : 0.5f;
        float microDetail = 0.0f;
        if (texture.isValid) {
            microDetail = (texture.highFreqDetail[i] * 0.6f + texture.directionalResponse[i] * 0.4f) / 255.0f;
        }
        feature0[i] = { aVal, shadowF, rootF, microDetail };

        float hlMask = appearance.isValid ? appearance.highlightMask[i] : 0.0f;
        float flowConf = orientation.isValid ? orientation.confidence[i] : 0.5f;
        feature1[i] = { hlMask, flowConf };
    }

    // 3. Khởi tạo 4 Storage Buffers
    VkDeviceSize pixelBufferSize = total * sizeof(uint32_t);
    VkDeviceSize feat0BufferSize = total * sizeof(Vec4);
    VkDeviceSize feat1BufferSize = total * sizeof(Vec2);

    VkBuffer bufIn = VK_NULL_HANDLE, bufOut = VK_NULL_HANDLE;
    VkBuffer bufFeat0 = VK_NULL_HANDLE, bufFeat1 = VK_NULL_HANDLE;
    VkDeviceMemory memIn = VK_NULL_HANDLE, memOut = VK_NULL_HANDLE;
    VkDeviceMemory memFeat0 = VK_NULL_HANDLE, memFeat1 = VK_NULL_HANDLE;

    VkMemoryPropertyFlags hostFlags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    bool bOk = true;
    bOk &= createBuffer(pixelBufferSize, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, hostFlags, bufIn, memIn);
    bOk &= createBuffer(pixelBufferSize, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, hostFlags, bufOut, memOut);
    bOk &= createBuffer(feat0BufferSize, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, hostFlags, bufFeat0, memFeat0);
    bOk &= createBuffer(feat1BufferSize, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, hostFlags, bufFeat1, memFeat1);

    if (!bOk) {
        LOGE("Failed to allocate GPU storage buffers!");
        mLastTrace.status = "FAILED_BUFFER_ALLOCATION";
        mLastTrace.fallbackTriggered = true;
        mLastTrace.fallbackReason = "VK_BUFFER_ALLOC_FAIL";
        if (bufIn) vkDestroyBuffer(mDevice, bufIn, nullptr);
        if (bufOut) vkDestroyBuffer(mDevice, bufOut, nullptr);
        if (bufFeat0) vkDestroyBuffer(mDevice, bufFeat0, nullptr);
        if (bufFeat1) vkDestroyBuffer(mDevice, bufFeat1, nullptr);
        if (memIn) vkFreeMemory(mDevice, memIn, nullptr);
        if (memOut) vkFreeMemory(mDevice, memOut, nullptr);
        if (memFeat0) vkFreeMemory(mDevice, memFeat0, nullptr);
        if (memFeat1) vkFreeMemory(mDevice, memFeat1, nullptr);
        return false;
    }

    // 4. Đo lường Upload Thời Gian Thực (Upload Latency)
    auto tUpload0 = std::chrono::high_resolution_clock::now();
    void* ptrIn = nullptr;
    vkMapMemory(mDevice, memIn, 0, pixelBufferSize, 0, &ptrIn);
    std::memcpy(ptrIn, inputs.srcPixels, pixelBufferSize);
    vkUnmapMemory(mDevice, memIn);

    void* ptrFeat0 = nullptr;
    vkMapMemory(mDevice, memFeat0, 0, feat0BufferSize, 0, &ptrFeat0);
    std::memcpy(ptrFeat0, feature0.data(), feat0BufferSize);
    vkUnmapMemory(mDevice, memFeat0);

    void* ptrFeat1 = nullptr;
    vkMapMemory(mDevice, memFeat1, 0, feat1BufferSize, 0, &ptrFeat1);
    std::memcpy(ptrFeat1, feature1.data(), feat1BufferSize);
    vkUnmapMemory(mDevice, memFeat1);

    auto tUpload1 = std::chrono::high_resolution_clock::now();
    float uploadMs = std::chrono::duration<float, std::milli>(tUpload1 - tUpload0).count();

    // 5. Cấp phát Descriptor Set & Cập nhật Bindings
    VkDescriptorSetAllocateInfo dsAlloc = {};
    dsAlloc.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    dsAlloc.descriptorPool = mDescriptorPool;
    dsAlloc.descriptorSetCount = 1;
    dsAlloc.pSetLayouts = &mDescriptorSetLayout;

    VkDescriptorSet descSet = VK_NULL_HANDLE;
    if (vkAllocateDescriptorSets(mDevice, &dsAlloc, &descSet) != VK_SUCCESS) {
        LOGE("Failed to allocate descriptor set");
        mLastTrace.status = "FAILED_DESCRIPTOR_ALLOC";
        mLastTrace.fallbackTriggered = true;
        mLastTrace.fallbackReason = "VK_DESCRIPTOR_ALLOC_FAIL";
        return false;
    }

    VkDescriptorBufferInfo bInfos[4] = {
        { bufIn, 0, pixelBufferSize },
        { bufOut, 0, pixelBufferSize },
        { bufFeat0, 0, feat0BufferSize },
        { bufFeat1, 0, feat1BufferSize }
    };

    VkWriteDescriptorSet writes[4] = {};
    for (int b = 0; b < 4; ++b) {
        writes[b].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        writes[b].dstSet = descSet;
        writes[b].dstBinding = b;
        writes[b].dstArrayElement = 0;
        writes[b].descriptorCount = 1;
        writes[b].descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        writes[b].pBufferInfo = &bInfos[b];
    }
    vkUpdateDescriptorSets(mDevice, 4, writes, 0, nullptr);

    // 6. Ghi Command Buffer & Dispatch
    VkCommandBufferAllocateInfo cbAlloc = {};
    cbAlloc.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    cbAlloc.commandPool = mCommandPool;
    cbAlloc.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    cbAlloc.commandBufferCount = 1;

    VkCommandBuffer cmd = VK_NULL_HANDLE;
    vkAllocateCommandBuffers(mDevice, &cbAlloc, &cmd);

    VkCommandBufferBeginInfo beginInfo = {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    vkBeginCommandBuffer(cmd, &beginInfo);

    vkCmdBindPipeline(cmd, VK_PIPELINE_BIND_POINT_COMPUTE, mComputePipeline);
    vkCmdBindDescriptorSets(cmd, VK_PIPELINE_BIND_POINT_COMPUTE, mPipelineLayout, 0, 1, &descSet, 0, nullptr);

    // Chuẩn bị Push Constants
    HairVulkanPushConstants pc = {};
    pc.width = inputs.width;
    pc.height = inputs.height;

    float hueRad = inputs.material.targetHue * 0.0174532925f;
    float targetC = std::clamp(inputs.material.targetChroma / 100.0f * 0.28f, 0.0f, 0.35f);
    pc.targetA = targetC * std::cos(hueRad);
    pc.targetB = targetC * std::sin(hueRad);
    pc.targetL = std::clamp(inputs.material.targetLightness / 100.0f, 0.05f, 0.95f);
    pc.bleachPower = inputs.material.bleachPower;
    pc.blendIntensity = inputs.material.blendIntensity;
    pc.shadowPreservation = inputs.material.shadowPreservation;
    pc.rootStrength = inputs.material.rootStrength;

    pc.apparentShine = inputs.specular.apparentShine;
    pc.roughness = inputs.specular.roughness;
    pc.specularTint = inputs.specular.specularTint;

    pc.roiMinX = (inputs.p0Matte.roiMaxX > inputs.p0Matte.roiMinX) ? std::max(0, inputs.p0Matte.roiMinX) : 0;
    pc.roiMaxX = (inputs.p0Matte.roiMaxX > inputs.p0Matte.roiMinX) ? std::min(inputs.width - 1, inputs.p0Matte.roiMaxX) : inputs.width - 1;
    pc.roiMinY = (inputs.p0Matte.roiMaxY > inputs.p0Matte.roiMinY) ? std::max(0, inputs.p0Matte.roiMinY) : 0;
    pc.roiMaxY = (inputs.p0Matte.roiMaxY > inputs.p0Matte.roiMinY) ? std::min(inputs.height - 1, inputs.p0Matte.roiMaxY) : inputs.height - 1;

    vkCmdPushConstants(cmd, mPipelineLayout, VK_SHADER_STAGE_COMPUTE_BIT, 0, sizeof(pc), &pc);

    uint32_t groupX = (inputs.width + 15) / 16;
    uint32_t groupY = (inputs.height + 15) / 16;
    vkCmdDispatch(cmd, groupX, groupY, 1);

    // Memory Barrier đảm bảo ghi hoàn tất trước khi CPU đọc
    VkMemoryBarrier memBarrier = {};
    memBarrier.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
    memBarrier.srcAccessMask = VK_ACCESS_SHADER_WRITE_BIT;
    memBarrier.dstAccessMask = VK_ACCESS_HOST_READ_BIT;
    vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT, VK_PIPELINE_STAGE_HOST_BIT, 0, 1, &memBarrier, 0, nullptr, 0, nullptr);

    vkEndCommandBuffer(cmd);

    // 7. Thực thi Hàng đợi GPU (Queue Submit) và Đồng bộ qua Fence
    VkFence fence = VK_NULL_HANDLE;
    VkFenceCreateInfo fInfo = {};
    fInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    vkCreateFence(mDevice, &fInfo, nullptr, &fence);

    VkSubmitInfo submitInfo = {};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &cmd;

    auto tDisp0 = std::chrono::high_resolution_clock::now();
    VkResult subRes = vkQueueSubmit(mComputeQueue, 1, &submitInfo, fence);

    if (subRes != VK_SUCCESS) {
        LOGE("vkQueueSubmit failed with code: %d", subRes);
        mLastTrace.status = "FAILED_QUEUE_SUBMIT";
        mLastTrace.submitResult = "VK_SUBMIT_ERROR";
        mLastTrace.fallbackTriggered = true;
        mLastTrace.fallbackReason = "VK_QUEUE_SUBMIT_FAILED";
        vkDestroyFence(mDevice, fence, nullptr);
        vkFreeCommandBuffers(mDevice, mCommandPool, 1, &cmd);
        vkFreeDescriptorSets(mDevice, mDescriptorPool, 1, &descSet);
        vkDestroyBuffer(mDevice, bufIn, nullptr); vkDestroyBuffer(mDevice, bufOut, nullptr);
        vkDestroyBuffer(mDevice, bufFeat0, nullptr); vkDestroyBuffer(mDevice, bufFeat1, nullptr);
        vkFreeMemory(mDevice, memIn, nullptr); vkFreeMemory(mDevice, memOut, nullptr);
        vkFreeMemory(mDevice, memFeat0, nullptr); vkFreeMemory(mDevice, memFeat1, nullptr);
        return false;
    }

    VkResult waitRes = vkWaitForFences(mDevice, 1, &fence, VK_TRUE, 5000000000ULL); // 5s timeout
    auto tDisp1 = std::chrono::high_resolution_clock::now();
    float dispatchMs = std::chrono::duration<float, std::milli>(tDisp1 - tDisp0).count();

    if (waitRes != VK_SUCCESS) {
        LOGE("vkWaitForFences timed out or error: %d", waitRes);
        mLastTrace.status = "FAILED_FENCE_WAIT";
        mLastTrace.completionResult = "VK_FENCE_TIMEOUT";
        mLastTrace.fallbackTriggered = true;
        mLastTrace.fallbackReason = "VK_FENCE_WAIT_TIMEOUT";
        vkDestroyFence(mDevice, fence, nullptr);
        vkFreeCommandBuffers(mDevice, mCommandPool, 1, &cmd);
        vkFreeDescriptorSets(mDevice, mDescriptorPool, 1, &descSet);
        vkDestroyBuffer(mDevice, bufIn, nullptr); vkDestroyBuffer(mDevice, bufOut, nullptr);
        vkDestroyBuffer(mDevice, bufFeat0, nullptr); vkDestroyBuffer(mDevice, bufFeat1, nullptr);
        vkFreeMemory(mDevice, memIn, nullptr); vkFreeMemory(mDevice, memOut, nullptr);
        vkFreeMemory(mDevice, memFeat0, nullptr); vkFreeMemory(mDevice, memFeat1, nullptr);
        return false;
    }

    // 8. Đọc kết quả Thực thi GPU ra Bộ đệm Xuất xưởng (Download Latency)
    auto tDl0 = std::chrono::high_resolution_clock::now();
    void* ptrOut = nullptr;
    vkMapMemory(mDevice, memOut, 0, pixelBufferSize, 0, &ptrOut);
    std::memcpy(output.dstPixels, ptrOut, pixelBufferSize);
    vkUnmapMemory(mDevice, memOut);
    auto tDl1 = std::chrono::high_resolution_clock::now();
    float downloadMs = std::chrono::duration<float, std::milli>(tDl1 - tDl0).count();

    // 9. Dọn dẹp tài nguyên dispatch
    vkDestroyFence(mDevice, fence, nullptr);
    vkFreeCommandBuffers(mDevice, mCommandPool, 1, &cmd);
    vkFreeDescriptorSets(mDevice, mDescriptorPool, 1, &descSet);
    vkDestroyBuffer(mDevice, bufIn, nullptr); vkDestroyBuffer(mDevice, bufOut, nullptr);
    vkDestroyBuffer(mDevice, bufFeat0, nullptr); vkDestroyBuffer(mDevice, bufFeat1, nullptr);
    vkFreeMemory(mDevice, memIn, nullptr); vkFreeMemory(mDevice, memOut, nullptr);
    vkFreeMemory(mDevice, memFeat0, nullptr); vkFreeMemory(mDevice, memFeat1, nullptr);

    auto tEndTotal = std::chrono::high_resolution_clock::now();
    float totalMs = std::chrono::duration<float, std::milli>(tEndTotal - tStartTotal).count();

    // 10. Ghi nhận dấu vết Dispatch Thực (Real Hardware Audit Trace)
    mTotalDispatchCount++;
    mLastTrace.gpuDispatchCount = mTotalDispatchCount;
    mLastTrace.device = mDeviceInfo.deviceName;
    mLastTrace.backendRequested = "VULKAN_COMPUTE";
    mLastTrace.backendSelected = "VULKAN_COMPUTE";
    mLastTrace.queueFamily = mComputeQueueFamilyIndex;
    mLastTrace.workgroupX = 16;
    mLastTrace.workgroupY = 16;
    mLastTrace.workgroupZ = 1;
    mLastTrace.dispatchX = groupX;
    mLastTrace.dispatchY = groupY;
    mLastTrace.dispatchZ = 1;
    mLastTrace.submitResult = "VK_SUCCESS";
    mLastTrace.completionResult = "VK_SUCCESS";
    mLastTrace.fallbackTriggered = false;
    mLastTrace.fallbackReason = "NONE";
    mLastTrace.uploadMs = uploadMs;
    mLastTrace.dispatchMs = dispatchMs;
    mLastTrace.downloadMs = downloadMs;
    mLastTrace.totalMs = totalMs;
    mLastTrace.outputConsumed = true;
    mLastTrace.status = "SUCCESS";

    output.success = true;
    output.renderTimeMs = totalMs;
    output.backendUsed = "VULKAN_COMPUTE";

    LOGI("[HCE_VULKAN] Dispatch #%u completed successfully! Total: %.2fms (Upload: %.2fms, GPU Kernel: %.2fms, Readback: %.2fms)",
         mTotalDispatchCount, totalMs, uploadMs, dispatchMs, downloadMs);

    return true;
}

bool HairGpuBackend::runParityBenchmark(
    const HairRenderInputs& inputs,
    float& maxDiff, float& meanDiff, float& p95Diff,
    float& cpuTimeMs, float& gpuTimeMs
) {
    const int total = inputs.width * inputs.height;
    std::vector<uint32_t> cpuOut(total);
    std::vector<uint32_t> gpuOut(total);

    HairRenderOutput outCpu;
    outCpu.dstPixels = cpuOut.data();
    outCpu.width = inputs.width;
    outCpu.height = inputs.height;

    HairRenderOutput outGpu;
    outGpu.dstPixels = gpuOut.data();
    outGpu.width = inputs.width;
    outGpu.height = inputs.height;

    bool cpuOk = executeCpuReference(inputs, outCpu);
    cpuTimeMs = outCpu.renderTimeMs;

    bool gpuOk = executeVulkanCompute(inputs, outGpu);
    gpuTimeMs = outGpu.renderTimeMs;

    if (!cpuOk || !gpuOk) {
        return false;
    }

    std::vector<float> diffs;
    diffs.reserve(total);
    double sumDiff = 0.0;
    float maxD = 0.0f;

    for (int i = 0; i < total; ++i) {
        uint32_t cCpu = cpuOut[i];
        uint32_t cGpu = gpuOut[i];

        float dr = std::abs((float)RGBA_R(cCpu) - (float)RGBA_R(cGpu));
        float dg = std::abs((float)RGBA_G(cCpu) - (float)RGBA_G(cGpu));
        float db = std::abs((float)RGBA_B(cCpu) - (float)RGBA_B(cGpu));
        float pixDiff = std::max({ dr, dg, db });

        diffs.push_back(pixDiff);
        sumDiff += pixDiff;
        if (pixDiff > maxD) maxD = pixDiff;
    }

    std::sort(diffs.begin(), diffs.end());
    maxDiff = maxD;
    meanDiff = (float)(sumDiff / total);
    size_t p95Idx = static_cast<size_t>(0.95 * (total - 1));
    p95Diff = diffs[p95Idx];

    return true;
}

} // namespace meitu_native::hce

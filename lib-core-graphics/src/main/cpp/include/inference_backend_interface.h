#ifndef MEITU_INFERENCE_BACKEND_INTERFACE_H
#define MEITU_INFERENCE_BACKEND_INTERFACE_H

#include <string>
#include <vector>
#include <memory>

namespace meitu_native {

enum class InferenceDevice {
    CPU = 0,
    VULKAN_GPU = 1,
    METAL_GPU = 2,
    NNAPI = 3
};

struct TensorShape {
    int batches = 1;
    int channels = 0;
    int height = 0;
    int width = 0;
    size_t totalElements() const {
        return static_cast<size_t>(batches * channels * height * width);
    }
};

/**
 * @brief Pure virtual AI Inference Backend Abstraction (SPEC Section 28).
 * Decouples BeautyCore from specific inference engines (NCNN, ONNX, CoreML, TFLite).
 */
class IInferenceBackend {
public:
    virtual ~IInferenceBackend() = default;

    virtual bool initialize(InferenceDevice device = InferenceDevice::CPU) = 0;
    virtual bool loadModelFromFiles(const std::string& paramPath, const std::string& modelPath) = 0;
    virtual bool loadModelFromMemory(const uint8_t* paramBuffer, size_t paramSize,
                                    const uint8_t* modelBuffer, size_t modelSize) = 0;

    virtual bool setInputTensor(const std::string& inputName, const float* data, const TensorShape& shape) = 0;
    virtual bool runInference() = 0;
    virtual bool getOutputTensor(const std::string& outputName, std::vector<float>& outData, TensorShape& outShape) = 0;

    virtual bool isGpuAccelerated() const = 0;
    virtual const char* getBackendName() const = 0;
};

/**
 * @brief Factory for instantiating the optimal inference backend for the target platform.
 */
class InferenceBackendFactory {
public:
    static std::unique_ptr<IInferenceBackend> createDefaultBackend();
};

} // namespace meitu_native

#endif // MEITU_INFERENCE_BACKEND_INTERFACE_H

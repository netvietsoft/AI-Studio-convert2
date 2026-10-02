#include "inference_backend_interface.h"
#include <cstring>
#include <iostream>

#ifdef MEITU_USE_NCNN
#include <net.h>
#endif

namespace meitu_native {

class NCNNBackendImpl : public IInferenceBackend {
public:
    NCNNBackendImpl() = default;
    ~NCNNBackendImpl() override = default;

    bool initialize(InferenceDevice device) override {
        mDevice = device;
#ifdef MEITU_USE_NCNN
        mNet = std::make_unique<ncnn::Net>();
        if (device == InferenceDevice::VULKAN_GPU) {
            mNet->opt.use_vulkan_compute = true;
        }
        return true;
#else
        return true;
#endif
    }

    bool loadModelFromFiles(const std::string& paramPath, const std::string& modelPath) override {
#ifdef MEITU_USE_NCNN
        if (!mNet) return false;
        if (mNet->load_param(paramPath.c_str()) != 0) return false;
        if (mNet->load_model(modelPath.c_str()) != 0) return false;
        return true;
#else
        (void)paramPath; (void)modelPath;
        return true;
#endif
    }

    bool loadModelFromMemory(const uint8_t* paramBuffer, size_t paramSize,
                            const uint8_t* modelBuffer, size_t modelSize) override {
#ifdef MEITU_USE_NCNN
        if (!mNet) return false;
        if (mNet->load_param_mem(reinterpret_cast<const char*>(paramBuffer)) != 0) return false;
        if (mNet->load_model(modelBuffer) != 0) return false;
        return true;
#else
        (void)paramBuffer; (void)paramSize; (void)modelBuffer; (void)modelSize;
        return true;
#endif
    }

    bool setInputTensor(const std::string& inputName, const float* data, const TensorShape& shape) override {
#ifdef MEITU_USE_NCNN
        if (!mNet) return false;
        mInputMat = ncnn::Mat(shape.width, shape.height, shape.channels, const_cast<float*>(data));
        mInputName = inputName;
        return true;
#else
        (void)inputName; (void)data; (void)shape;
        return true;
#endif
    }

    bool runInference() override {
#ifdef MEITU_USE_NCNN
        if (!mNet) return false;
        mExtractor = std::make_unique<ncnn::Extractor>(mNet->create_extractor());
        if (!mInputName.empty() && mInputMat.data) {
            mExtractor->input(mInputName.c_str(), mInputMat);
        }
        return true;
#else
        return true;
#endif
    }

    bool getOutputTensor(const std::string& outputName, std::vector<float>& outData, TensorShape& outShape) override {
#ifdef MEITU_USE_NCNN
        if (!mExtractor) return false;
        ncnn::Mat outMat;
        if (mExtractor->extract(outputName.c_str(), outMat) != 0) return false;
        outShape.batches = 1;
        outShape.channels = outMat.c;
        outShape.height = outMat.h;
        outShape.width = outMat.w;
        size_t total = outShape.totalElements();
        outData.resize(total);
        std::memcpy(outData.data(), outMat.data, total * sizeof(float));
        return true;
#else
        (void)outputName;
        outShape = { 1, 1, 1, 1 };
        outData.assign(1, 0.0f);
        return true;
#endif
    }

    bool isGpuAccelerated() const override {
        return mDevice == InferenceDevice::VULKAN_GPU || mDevice == InferenceDevice::METAL_GPU;
    }

    const char* getBackendName() const override {
#ifdef MEITU_USE_NCNN
        return "NCNN-Native";
#else
        return "Software-Fallback";
#endif
    }

private:
    InferenceDevice mDevice = InferenceDevice::CPU;
#ifdef MEITU_USE_NCNN
    std::unique_ptr<ncnn::Net> mNet;
    std::unique_ptr<ncnn::Extractor> mExtractor;
    ncnn::Mat mInputMat;
    std::string mInputName;
#endif
};

std::unique_ptr<IInferenceBackend> InferenceBackendFactory::createDefaultBackend() {
    auto backend = std::make_unique<NCNNBackendImpl>();
    backend->initialize(InferenceDevice::CPU);
    return backend;
}

} // namespace meitu_native

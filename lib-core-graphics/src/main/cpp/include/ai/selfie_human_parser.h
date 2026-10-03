#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include "body_semantic_model.h"

namespace ncnn {
    class Net;
}

namespace meitu::ai {

class SelfieHumanParser {
public:
    static SelfieHumanParser& getInstance();

    SelfieHumanParser();
    ~SelfieHumanParser();

    bool init(const std::string& paramPath, const std::string& binPath);
    bool isInitialized() const { return mInitialized; }

    /**
     * @brief Run offline MediaPipe Selfie Segmentation NCNN model to produce real person segmentation.
     * @param srcRgba Source RGBA pixels (width x height)
     * @param width Image width
     * @param height Image height
     * @param outPersonProb Probability map [0.0f .. 1.0f] scaled to width x height
     * @param outBinaryMask Binary mask (255 for person, 0 for background) at width x height
     * @return true if inference succeeded
     */
    bool segmentPerson(
        const uint32_t* srcRgba,
        int width,
        int height,
        std::vector<float>& outPersonProb,
        std::vector<uint8_t>& outBinaryMask
    );

    /**
     * @brief Generate full 20-class BodyParsingClass map strictly bounded by neural segmentation.
     * @param srcRgba Source RGBA pixels
     * @param width Image width
     * @param height Image height
     * @param keypoints Real detected body keypoints
     * @param outParsingMask Output 20-class semantic map (width x height)
     * @param outConfidence Optional overall segmentation confidence output
     * @return true if successful
     */
    bool generateParsingMask(
        const uint32_t* srcRgba,
        int width,
        int height,
        const std::vector<meitu_native::BodyKeypoint>& keypoints,
        std::vector<uint8_t>& outParsingMask,
        float* outConfidence = nullptr
    );

private:
    ncnn::Net* mNet;
    bool mInitialized;
};

} // namespace meitu::ai

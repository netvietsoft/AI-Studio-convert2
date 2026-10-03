#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include "body_semantic_model.h"

namespace ncnn {
    class Net;
}

namespace meitu::ai {

class MoveNetPoseEstimator {
public:
    static MoveNetPoseEstimator& getInstance();

    MoveNetPoseEstimator();
    ~MoveNetPoseEstimator();

    bool init(const std::string& paramPath, const std::string& binPath);
    bool isInitialized() const { return mInitialized; }

    /**
     * @brief Run offline MoveNet SinglePose Lightning v4 inference.
     * @param srcRgba Source RGBA pixels (width x height)
     * @param width Image width
     * @param height Image height
     * @param outKeypoints Output vector of 22 BodyKeypoints matching WholeBodyJoint enum
     * @return true if inference succeeded and at least torso/shoulders detected with valid confidence
     */
    bool detectPose(
        const uint32_t* srcRgba,
        int width,
        int height,
        std::vector<meitu_native::BodyKeypoint>& outKeypoints
    );

private:
    ncnn::Net* mNet;
    bool mInitialized;
};

} // namespace meitu::ai

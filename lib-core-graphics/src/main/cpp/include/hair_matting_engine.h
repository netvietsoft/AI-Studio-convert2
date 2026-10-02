#ifndef MEITU_HAIR_MATTING_ENGINE_H
#define MEITU_HAIR_MATTING_ENGINE_H

#include <vector>
#include <string>
#include <cstdint>
#include "landmark_fusion.h"

namespace ncnn {
    class Net;
}

namespace meitu_native {

class HairMattingEngine {
public:
    static HairMattingEngine& getInstance();

    bool init(const std::string& paramPath, const std::string& binPath);
    bool isInitialized() const { return mInitialized; }

    bool extractHairMatte(
        const uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        std::vector<float>& outAlpha512
    );

    static void setP0B2REnabled(bool enabled);
    static bool isP0B2REnabled();

    bool extractFullSizeMatte(
        const uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        std::vector<float>& outFullAlpha
    );

private:
    HairMattingEngine();
    ~HairMattingEngine();

    bool runP0B2RNativePipeline(
        const uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        std::vector<float>& outFullAlpha
    );

    void applySubpixelGuidedRefinement(
        const uint32_t* srcPixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        std::vector<float>& inoutAlpha512,
        const std::vector<uint8_t>& bisenetMask512,
        const std::vector<float>& hairProb512,
        bool ncnnSuccess
    );

    ncnn::Net* mNet;
    bool mInitialized;
};

} // namespace meitu_native

#endif // MEITU_HAIR_MATTING_ENGINE_H

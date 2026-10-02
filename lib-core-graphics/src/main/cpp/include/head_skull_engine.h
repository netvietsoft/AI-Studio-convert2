#ifndef MEITU_HEAD_SKULL_ENGINE_H
#define MEITU_HEAD_SKULL_ENGINE_H

#include <cstdint>
#include "head_semantic_model.h"

namespace meitu_native {

enum HeadSkullParamId {
    PARAM_HEAD_SIZE        = 3001,
    PARAM_SKULL_CROWN      = 3002,
    PARAM_TEMPLE_WIDTH     = 3003,
    PARAM_FOREHEAD_RESHAPE = 3004,
    PARAM_FACE_HEAD_RATIO  = 3005
};

class HeadSkullEngine {
public:
    static constexpr int PARAM_HEAD_SIZE = 3001;
    static constexpr int PARAM_SKULL_CROWN = 3002;
    static constexpr int PARAM_TEMPLE_WIDTH = 3003;
    static constexpr int PARAM_FOREHEAD_RESHAPE = 3004;
    static constexpr int PARAM_FACE_HEAD_RATIO = 3005;

    static bool applyHeadSkullReshape(
        uint32_t* pixels,
        int width,
        int height,
        const HeadFrameResult& headModel,
        int paramId,
        float intensity
    );

    bool processHeadSize(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
        return applyHeadSkullReshape(reinterpret_cast<uint32_t*>(rgba), w, h, head, PARAM_HEAD_SIZE, intensity);
    }
    bool processSkullCrown(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
        return applyHeadSkullReshape(reinterpret_cast<uint32_t*>(rgba), w, h, head, PARAM_SKULL_CROWN, intensity);
    }
    bool processTempleWidth(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
        return applyHeadSkullReshape(reinterpret_cast<uint32_t*>(rgba), w, h, head, PARAM_TEMPLE_WIDTH, intensity);
    }
    bool processForeheadHeight(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
        return applyHeadSkullReshape(reinterpret_cast<uint32_t*>(rgba), w, h, head, PARAM_FOREHEAD_RESHAPE, intensity);
    }
    bool processFaceHeadRatio(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity) {
        return applyHeadSkullReshape(reinterpret_cast<uint32_t*>(rgba), w, h, head, PARAM_FACE_HEAD_RATIO, intensity);
    }
};

} // namespace meitu_native

#endif // MEITU_HEAD_SKULL_ENGINE_H

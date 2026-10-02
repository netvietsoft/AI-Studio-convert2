#ifndef MEITU_PHILTRUM_ENGINE_H
#define MEITU_PHILTRUM_ENGINE_H

#include <cstdint>
#include "head_semantic_model.h"

namespace meitu_native {

// Section 17 SPEC: PHILTRUM — NHÂN TRUNG
enum PhiltrumParamId {
    PARAM_PHILTRUM_LENGTH          = 1701, // Thu ngắn / kéo dài nhân trung (Length)
    PARAM_PHILTRUM_WIDTH           = 1702, // Thu hẹp / mở rộng hai trụ nhân trung (Width)
    PARAM_PHILTRUM_GROOVE_DEPTH    = 1703, // Độ sâu rãnh nhân trung (Groove Depth 3D Shading)
    PARAM_PHILTRUM_CUPID_ACCENT    = 1704  // Định hình đỉnh chữ M cung môi Cupid's Bow
};

class PhiltrumEngine {
public:
    // Chỉnh sửa hình học & ánh sáng 3D rãnh nhân trung (Bit & Pixel precision)
    // Bảo lưu 100% ranh giới chân mũi và đường viền môi trên (Vermilion border)
    static bool applyPhiltrumEdit(
        uint32_t* pixels,
        int width,
        int height,
        const HeadFrameResult& headModel,
        int paramId,
        float intensity
    );
};

} // namespace meitu_native

#endif // MEITU_PHILTRUM_ENGINE_H

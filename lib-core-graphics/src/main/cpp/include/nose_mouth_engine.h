#ifndef MEITU_NOSE_MOUTH_ENGINE_H
#define MEITU_NOSE_MOUTH_ENGINE_H

#include <cstdint>

namespace meitu_native {

// 2.5 NOSE PARAMETERS (MTARBeautyParm)
enum NoseParamId {
    PARAM_NOSE_SHRINK   = 2501, // Thu cánh mũi (Ala Nasi)
    PARAM_NOSE_TIP      = 2502, // Thu nhỏ đầu mũi (Tip)
    PARAM_NOSE_ROOT     = 2503, // Nâng sống mũi / chân mũi (Nasal Root)
    PARAM_NOSE_LONGER   = 2504, // Kéo dài dáng mũi (Nose Longer)
    PARAM_NOSE_RESIZE   = 2505, // Kích thước tổng thể mũi
    PARAM_NOSE_DISTANCE = 2506, // Khoảng cách mũi - trán/mắt
    PARAM_NOSE_NARROW   = 2507  // Tổng thể thu hẹp mũi
};

// 2.6 MOUTH / LIPS PARAMETERS (MTARBeautyParm)
enum MouthParamId {
    PARAM_LIP_OVERALL     = 2601, // Tổng thể môi căng mọng (Lip)
    PARAM_UPPER_LIP       = 2602, // Môi trên (Upper Lip)
    PARAM_LOWER_LIP       = 2603, // Môi dưới (Lower Lip)
    PARAM_MOUTH_WIDTH     = 2604, // Chiều rộng khóe miệng (Mouth Width)
    PARAM_MOUTH_ROTATE    = 2605, // Xoay cân chỉnh miệng (Mouth Rotate)
    PARAM_MOUTH_LATERAL   = 2606, // Dịch chuyển miệng ngang (Lateral Move)
    PARAM_PHILTRUM_HIGH   = 2607, // Thu ngắn nhân trung (Philtrum High)
    PARAM_PHILTRUM_WARP   = 2608, // Uốn viền nhân trung (Philtrum Warp)
    PARAM_COMIC_MOUTH_M   = 2609, // Môi cười kiểu M (Comic Mouth Shape M)
    PARAM_CONVEX_MOUTH    = 2610, // Thu môi vổ / môi nhô (Convex Mouth)
    PARAM_SMILE           = 2611, // Nụ cười rạng rỡ (Smile)
    PARAM_LIP_BUNNY       = 2612  // Môi thỏ tròn đầy (Plump Bunny Lips)
};

class NoseMouthEngine {
public:
    // 1. Chỉnh hình dáng mũi C++ (Bit & Pixel)
    static bool applyNoseReshape(
        uint32_t* pixels,
        int width,
        int height,
        float noseX, float noseY,
        int paramId,
        float intensity
    );

    // 2. Chỉnh hình dáng môi & miệng C++ (Bit & Pixel)
    static bool applyMouthReshape(
        uint32_t* pixels,
        int width,
        int height,
        float mouthX, float mouthY,
        int paramId,
        float intensity
    );
};

} // namespace meitu_native

#endif // MEITU_NOSE_MOUTH_ENGINE_H

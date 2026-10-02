#ifndef MEITU_EYELASH_ENGINE_H
#define MEITU_EYELASH_ENGINE_H

#include <cstdint>
#include "head_semantic_model.h"

namespace meitu_native {

// Section 11 SPEC: EYELASH — LÔNG MI
enum EyelashParamId {
    PARAM_LASH_DENSITY      = 1101, // Độ dày dặn / mật độ sợi mi (Apparent Density)
    PARAM_LASH_LENGTH       = 1102, // Chiều dài sợi mi vươn dài (Lash Length)
    PARAM_LASH_CURL         = 1103, // Độ cong vút của mi (Curl Curvature & Angle)
    PARAM_LASH_SHARPEN      = 1104, // Độ sắc nét vi sợi mi (Lash Acuity & Contrast)
    PARAM_LASH_LOWER        = 1105, // Hàng mi dưới tự nhiên thanh tú (Lower Lash)
    PARAM_LASH_COLOR_INTENSE= 1106  // Độ đậm màu sợi mi (Deep Black / Dark Brown)
};

enum EyelashStyleId {
    LASH_STYLE_NATURAL      = 0,    // Mi tự nhiên thanh lịch hàng ngày
    LASH_STYLE_DOLL_EYE     = 1,    // Mi búp bê mắt tròn to Baby Doll
    LASH_STYLE_CAT_EYE      = 2,    // Mi mắt mèo đuôi dài quyến rũ
    LASH_STYLE_WISPY_ANIME  = 3,    // Mi Wispy đan sợi cánh tiên Anime / K-Beauty
    LASH_STYLE_DENSE_GLAM   = 4     // Mi tiệc tối sắc sảo Dày & Cong
};

class EyelashEngine {
public:
    // Chỉnh sửa & vẽ hàng mi tự nhiên đạt chuẩn giải phẫu (Bit & Pixel precision)
    // Tự động bám theo đường cong viền mí, không lem vào giác mạc/củng mạc (iris/sclera)
    static bool applyEyelash(
        uint32_t* pixels,
        int width,
        int height,
        const HeadFrameResult& headModel,
        int styleId,
        float intensity,
        float lengthScale = 1.0f,
        float densityScale = 1.0f,
        float curlAngle = 0.0f
    );
};

} // namespace meitu_native

#endif // MEITU_EYELASH_ENGINE_H

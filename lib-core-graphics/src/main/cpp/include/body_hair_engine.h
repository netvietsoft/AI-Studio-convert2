#ifndef MEITU_BODY_HAIR_ENGINE_H
#define MEITU_BODY_HAIR_ENGINE_H

#include <cstdint>

namespace MeituReborn {
    struct FusedFaceGeometry;
}

namespace meitu_native {

// 2.9 HAIR PARAMETERS
enum HairParamId {
    PARAM_HAIR_LINE         = 2901, // Hạ/chỉnh đường chân tóc (Hairline)
    PARAM_HAIR_BANGS        = 2902, // Mái tóc phồng (Bangs)
    PARAM_HAIR_COLOR        = 2903, // Nhuộm tóc thời trang [VIP]
    PARAM_HAIR_VOLUME       = 2904, // Làm phồng chân tóc (Fluffy Hair Volume)
    PARAM_HAIR_WRAPPED      = 2905  // Tóc ôm mặt che góc hàm (Hair Wrapped Face)
};

// 2.10 BODY PARAMETERS
enum BodyParamId {
    PARAM_BODY_SLIM         = 3001, // Thon người toàn thân (Slim/Thin Body)
    PARAM_BODY_LEGS         = 3002, // Kéo dài chân tỉ lệ vàng (Long Legs)
    PARAM_BODY_HEAD         = 3003, // Thu nhỏ đầu (Shrink Head)
    PARAM_BODY_WAIST        = 3004, // Eo thon con kiến (Slim Waist)
    PARAM_BODY_LEGS_SLIM    = 3005, // Chân & bắp đùi thon gọn (Slim Leg)
    PARAM_BODY_ARMS         = 3006, // Bắp tay thon (Slim Big Arm)
    PARAM_BODY_SHOULDER     = 3007, // Vai vuông móc áo (Straight Shoulder)
    PARAM_BODY_NECK         = 3008, // Cổ thiên nga thon dài (Swan Neck)
    PARAM_BODY_BELLY        = 3009, // Bụng phẳng thon (Slim Belly)
    PARAM_BODY_CHEST        = 3010, // Nâng ngực tự nhiên (Chest Enlarge)
    PARAM_BODY_HIP          = 3011  // Nở nang đường cong hông (Hip Deform)
};

class BodyHairEngine {
public:
    // 1. Chỉnh tóc & nhuộm màu tóc (2.9 HAIR)
    static bool applyHair(
        uint32_t* pixels,
        int width,
        int height,
        float foreheadX, float foreheadY,
        int paramId,
        int colorToneId,
        float intensity,
        const MeituReborn::FusedFaceGeometry* fused = nullptr
    );

    // 2. Định hình vóc dáng cơ thể (2.10 BODY RESHAPE)
    static bool applyBodyReshape(
        uint32_t* pixels,
        int width,
        int height,
        int paramId,
        float intensity
    );
};

} // namespace meitu_native

#endif // MEITU_BODY_HAIR_ENGINE_H

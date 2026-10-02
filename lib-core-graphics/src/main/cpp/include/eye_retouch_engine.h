#ifndef MEITU_EYE_RETOUCH_ENGINE_H
#define MEITU_EYE_RETOUCH_ENGINE_H

#include <cstdint>

namespace meitu_native {

// 2.3.1 EYE SHAPE & MORPH PARAMETERS (MTARBeautyParm & EyeTabType)
enum EyeShapeParamId {
    PARAM_EYE_ENLARGE           = 223101, // Zoom_Eye / kParamFlag_Eye_Distance
    PARAM_EYE_HEIGHT            = 223102, // kParamFlag_EyeHeight
    PARAM_EYE_WIDTH             = 223103, // kParamFlag_LeftEyeWidth / RightEyeWidth
    PARAM_EYE_TILT              = 223104, // kParamFlag_EyeTilt
    PARAM_EYE_UPDOWN            = 223105, // kParamFlag_EyeUpDown
    PARAM_EYE_LONGER            = 223106, // kParamFlag_EyeLonger
    PARAM_EYE_END               = 223107, // kParamFlag_EyeEnd (Đuôi mắt)
    PARAM_EYE_EYELID            = 223108, // kParamFlag_Eyelid (Mí mắt)
    PARAM_EYE_INNER_CORNER      = 223109, // kParamFlag_InnerEyeCorner (Góc mắt trong)
    PARAM_EYE_OUTER_CORNER      = 223110, // kParamFlag_OuterEyeCorner (Góc mắt ngoài)
    PARAM_EYE_INNER_CANTHUS_ADJ = 223111, // kParamFlag_InnerCanthusAdj (Mắt phượng)
    PARAM_EYE_DISTANCE          = 223112, // kParamFlag_Eye_Distance (Khoảng cách 2 mắt)
    PARAM_EYE_PUPIL_ENLARGE     = 223113  // kParamFlag_EnlargePupil (Giãn tròng đồng tử)
};

// 2.3.2 EYE BRIGHTNESS & EFFECTS
enum EyeEffectParamId {
    PARAM_EYE_BRIGHT            = 223201, // EyeTabType.BRIGHT
    PARAM_EYE_REMOVE_REDNESS    = 223202, // EyeTabType.BLOOD
    PARAM_EYE_DOUBLE_EYELID     = 223203, // EyeTabType.HIGH_DOF
    PARAM_EYE_SHARPEN           = 223204, // DETAILS_SHARPEN_EYE
    PARAM_EYE_CLARITY           = 223205, // DETAILS_CLARITY_EYE
    PARAM_EYE_WHITEN_SCLERA     = 223206, // WHITEN_EYES
    PARAM_EYE_RED_EYE_REMOVE    = 223207  // RED_EYE_REMOVE
};

// 2.3.3 EYE COLOR PRESETS (8 màu)
enum EyeColorId {
    EYE_COLOR_NATURAL = 0,
    EYE_COLOR_BLUE    = 1,
    EYE_COLOR_GREEN   = 2,
    EYE_COLOR_HAZEL   = 3,
    EYE_COLOR_GRAY    = 4,
    EYE_COLOR_VIOLET  = 5,
    EYE_COLOR_AMBER   = 6,
    EYE_COLOR_HONEY   = 7
};

// 2.3.4 EYE CATCHLIGHT STYLES (15 kiểu phản xạ đồng tử)
enum EyeCatchlightStyle {
    CATCHLIGHT_CIRCLE       = 1,  // Studio Ring Light
    CATCHLIGHT_STAR         = 2,  // Ngôi sao 4 cánh lấp lánh
    CATCHLIGHT_HEART        = 3,  // Trái tim tình yêu
    CATCHLIGHT_SOFTBOX      = 4,  // Hình chữ nhật Softbox
    CATCHLIGHT_DOUBLE_DOT   = 5,  // Chấm đôi Anime
    CATCHLIGHT_CRESCENT     = 6,  // Trăng khuyết huyền ảo
    CATCHLIGHT_DIAMOND      = 7,  // Kim cương giác cạnh
    CATCHLIGHT_FLOWER       = 8   // Cánh hoa tinh khôi
};

// 2.3.5 EYE PRESETS (Photo_13)
enum EyePresetId {
    EYE_PRESET_ORIGIN       = 0,
    EYE_PRESET_SPICED_TEA   = 1,
    EYE_PRESET_TENDER_AI    = 2,
    EYE_PRESET_SOFT_GRACE   = 3,
    EYE_PRESET_PINK_TALE    = 4,
    EYE_PRESET_PURE_CRYSTAL = 5
};

// 2.4 EYEBROW SHAPE & ADJUST
enum EyebrowParamId {
    PARAM_BROW_SHAPE_TAIL     = 240101, // Đuôi mày nâng
    PARAM_BROW_SHAPE_CURVED   = 240102, // Mày cong mềm
    PARAM_BROW_SHAPE_GRADIENT = 240103, // Ombre tán bột [VIP]
    PARAM_BROW_SHAPE_DENSE    = 240104, // Mày rậm
    PARAM_BROW_SHAPE_STRAIGHT = 240105, // Mày ngang K-Beauty
    PARAM_BROW_SHAPE_ARCH     = 240106, // Mày vòm Âu Mỹ

    PARAM_BROW_SIZE           = 240201, // kParamFlag_EyeBrowSize
    PARAM_BROW_RIDGE          = 240202, // kParamFlag_EyeBrowRidge
    PARAM_BROW_HEIGHT         = 240203, // kParamFlag_EyeBrowsHeight
    PARAM_BROW_TILT           = 240204, // kParamFlag_EyeBrowsTilt
    PARAM_BROW_DISTANCE       = 240205, // kParamFlag_EyeBrowsDistance
    PARAM_BROW_LENGTH         = 240206, // kParamFlag_EyeBrowLength
    PARAM_BROW_HEAD_SPACING   = 240207, // KMVARParamFlag_EyeBrowHeadSpacing
    PARAM_BROW_RAISE          = 240208, // kParamFlag_RaiseEyebrows
    PARAM_BROW_ALPHA          = 240209  // kParamFlag_EyeBrowAlpha
};

enum EyebrowColorId {
    BROW_COLOR_BLACK       = 0,
    BROW_COLOR_DARK_BROWN  = 1,
    BROW_COLOR_LIGHT_BROWN = 2,
    BROW_COLOR_ASH_GRAY    = 3,
    BROW_COLOR_AUBURN      = 4
};

class EyeRetouchEngine {
public:
    // 1. Chỉnh hình dáng mắt C++
    static bool applyEyeShape(
        uint32_t* pixels,
        int width,
        int height,
        float lxEye, float lyEye,
        float rxEye, float ryEye,
        int paramId,
        float intensity
    );

    // 2. Hiệu ứng độ sáng, làm trắng lòng trắng, xóa tia máu, mí đôi
    static bool applyEyeEffect(
        uint32_t* pixels,
        int width,
        int height,
        float lxEye, float lyEye,
        float rxEye, float ryEye,
        int effectId,
        float intensity
    );

    // 3. Đổi màu tròng mắt (Eye Color)
    static bool applyEyeColor(
        uint32_t* pixels,
        int width,
        int height,
        float lxEye, float lyEye,
        float rxEye, float ryEye,
        int colorId,
        float intensity
    );

    // 4. Vẽ ánh sáng phản xạ đồng tử (Catchlight)
    static bool applyEyeCatchlight(
        uint32_t* pixels,
        int width,
        int height,
        float lxEye, float lyEye,
        float rxEye, float ryEye,
        int styleId,
        float intensity
    );

    // 5. Chỉnh hình dáng và chi tiết lông mày (Eyebrows)
    static bool applyEyebrow(
        uint32_t* pixels,
        int width,
        int height,
        float lxEye, float lyEye,
        float rxEye, float ryEye,
        int paramId,
        float intensity
    );

    // 6. Đổi màu lông mày
    static bool applyEyebrowColor(
        uint32_t* pixels,
        int width,
        int height,
        float lxEye, float lyEye,
        float rxEye, float ryEye,
        int colorId,
        float intensity
    );

    // 7. Áp dụng trọn bộ Preset mắt (Photo_13)
    static bool applyEyePreset(
        uint32_t* pixels,
        int width,
        int height,
        float lxEye, float lyEye,
        float rxEye, float ryEye,
        int presetId,
        float intensity
    );
};

} // namespace meitu_native

#endif // MEITU_EYE_RETOUCH_ENGINE_H

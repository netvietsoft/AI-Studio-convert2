#ifndef MEITU_SKIN_MAKEUP_ENGINE_H
#define MEITU_SKIN_MAKEUP_ENGINE_H

#include <cstdint>

namespace meitu_native {

// 2.7.1 SKIN TYPES
enum SkinTypeId {
    SKIN_TYPE_OILY       = 64804, // Da dầu
    SKIN_TYPE_DRY        = 64805, // Da khô
    SKIN_TYPE_COMBINED   = 64806, // Da hỗn hợp
    SKIN_TYPE_SENSITIVE  = 64807  // Da nhạy cảm
};

// 2.7.2 SKIN TOOLS
enum SkinToolParamId {
    PARAM_SKIN_SMOOTH       = 2701, // Làm mịn da lụa (Realtime Bilateral)
    PARAM_SKIN_TEXTURE      = 2702, // Kết cấu da (Texture retention)
    PARAM_SKIN_CLEAR        = 2703, // Xóa khuyết điểm đốm nâu
    PARAM_SKIN_BRIGHTEN     = 2704, // Nâng tông trắng sứ (Porcelain Whiten)
    PARAM_SKIN_EYEBAGS      = 2705, // Xóa bọng mắt & quầng thâm
    PARAM_SKIN_SMILE_LINES  = 2706, // Xóa rãnh cười mũi má (Laugh lines)
    PARAM_SKIN_NECK_LINES   = 2707, // Xóa nếp nhăn cổ (Neck lines)
    PARAM_SKIN_ACNE_REMOVE  = 2708, // Xóa thâm mụn AI (Neural Inpaint)
    PARAM_SKIN_OIL_CONTROL  = 2709, // Kiềm dầu matte chống bóng nhờn
    PARAM_SKIN_DETAIL       = 2710, // Độ chi tiết lỗ chân lông tự nhiên
    PARAM_SKIN_FOUNDATION   = 2711, // Kem nền CC/BB cream mịn mướt
    PARAM_SKIN_TONE_ROSY_WHITE   = 2712, // Tông da: Trắng hồng mịn màng (Rosy Porcelain White)
    PARAM_SKIN_TONE_HONEY_BRONZE = 2713  // Tông da: Bánh mật ngăm đen khỏe (Honey Bronze Tan)
};

// 2.8 MAKEUP PARAMETERS
enum MakeupLipColorId {
    LIP_COLOR_SOFT_PINK     = 0,
    LIP_COLOR_FRENCH_ROSE   = 1,
    LIP_COLOR_VELVET_RED    = 2,
    LIP_COLOR_CHERRY_WINE   = 3,
    LIP_COLOR_CHILI_ORANGE  = 4,
    LIP_COLOR_PEACH_NUDE    = 5,
    LIP_COLOR_TERRACOTTA    = 6,
    LIP_COLOR_MAUVE_PURPLE  = 7,
    LIP_COLOR_CORAL_TANGER  = 8,
    LIP_COLOR_HONEY_GLAZE   = 9,
    LIP_COLOR_RUBY_LUXURY   = 10
};

enum MakeupLipTextureId {
    LIP_TEX_MATTE           = 0,
    LIP_TEX_GLOSSY          = 1,
    LIP_TEX_JELLY           = 2,
    LIP_TEX_GLASS           = 3,
    LIP_TEX_METALLIC        = 4,
    LIP_TEX_OVERLIP         = 5,
    LIP_TEX_GRADIENT        = 6
};

enum MakeupBlushStyleId {
    BLUSH_PEACHY            = 0,
    BLUSH_ROSY              = 1,
    BLUSH_BRONZY            = 2,
    BLUSH_CORAL             = 3,
    BLUSH_SUN_KISSED        = 4,
    BLUSH_BERRY             = 5
};

enum MakeupShadowToneId {
    SHADOW_RED_ROSE         = 0,
    SHADOW_SUNSET_PEACH     = 1,
    SHADOW_ROYAL_PURPLE     = 2,
    SHADOW_SAPPHIRE_BLUE    = 3,
    SHADOW_EMERALD_TEAL     = 4,
    SHADOW_GOLDEN_YELLOW    = 5,
    SHADOW_WARM_BRONZE      = 6,
    SHADOW_SMOKEY_NEUTRAL   = 7
};

class SkinMakeupEngine {
public:
    // 1. Áp dụng loại da & tính chất da (2.7.1)
    static bool applySkinType(
        uint32_t* pixels,
        int width,
        int height,
        float faceCenterX, float faceCenterY,
        float faceRadiusX, float faceRadiusY,
        int skinTypeId,
        float intensity,
        const float* landmarks106 = nullptr
    );

    // 2. Áp dụng công cụ xử lý da chuyên sâu (2.7.2)
    static bool applySkinTool(
        uint32_t* pixels,
        int width,
        int height,
        float faceCenterX, float faceCenterY,
        float noseX, float noseY,
        float mouthX, float mouthY,
        float lxEye, float lyEye,
        float rxEye, float ryEye,
        int toolId,
        float intensity,
        const float* landmarks106 = nullptr
    );

    // 3. Đánh son môi Makeup (Lipstick 2.8.2)
    static bool applyLipstick(
        uint32_t* pixels,
        int width,
        int height,
        float mouthX, float mouthY,
        int colorId,
        int textureId,
        float intensity,
        const float* landmarks106 = nullptr
    );

    // 4. Má hồng 3D Makeup (Blusher 2.8.5)
    static bool applyBlush(
        uint32_t* pixels,
        int width,
        int height,
        float cheekLeftX, float cheekLeftY,
        float cheekRightX, float cheekRightY,
        int styleId,
        float intensity
    );

    // 5. Phấn mắt (Eyeshadow 2.8.4)
    static bool applyEyeShadow(
        uint32_t* pixels,
        int width,
        int height,
        float lxEye, float lyEye,
        float rxEye, float ryEye,
        int toneId,
        float intensity
    );

    // 6. Tạo khối 5 quan & Bọng mắt cười (Contour, Bronzer & Wocan 2.8.5)
    static bool applyContour3D(
        uint32_t* pixels,
        int width,
        int height,
        float noseX, float noseY,
        float lxEye, float lyEye,
        float rxEye, float ryEye,
        int contourType, // 0: Nose shadow, 1: Cheekbone bronze, 2: Highlight, 3: Wocan 3D
        float intensity
    );
    // 7. CẤU TRÚC PHÂN TÍCH BO VIỀN, BIÊN DẠNG CƠ THỂ & ĐỘ LỆCH ĐỐI XỨNG / KHUYẾT THIẾU
    struct BodyContourMetrics {
        bool isValid;
        int topY;
        int bottomY;
        float bodyCenterX;
        float maxLeftWidth;
        float maxRightWidth;
        float symmetryRatio;      // min(W_L, W_R) / max(W_L, W_R)
        bool isAsymmetric;        // symmetryRatio < 0.75
        bool hasChippedParts;     // vết khuyết / lõm bất thường ở biên dạng cơ thể
        int internalHoleCount;    // số lượng lỗ thủng bên trong thân người
        int defectCount;          // tổng số khuyết tật biên dạng cơ thể
        float totalBodyArea;      // diện tích biểu bì thân người (pixel)
    };

    // 8. TÍNH TOÁN BO VIỀN, BIÊN DA CƠ THỂ & KIỂM TRA HÌNH DẠNG CƠ THỂ (LỆCH / KHUYẾT / THIẾU)
    static BodyContourMetrics analyzeBodyContour(
        const uint32_t* pixels,
        int width,
        int height,
        const float* landmarks106
    );
};

} // namespace meitu_native

#endif // MEITU_SKIN_MAKEUP_ENGINE_H

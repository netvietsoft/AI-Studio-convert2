#ifndef MEITU_TEETH_EAR_ENGINE_H
#define MEITU_TEETH_EAR_ENGINE_H

#include <cstdint>

namespace meitu_native {

enum TeethShadeMode {
    TEETH_SHADE_PORCELAIN = 0, // Trắng sứ cao cấp (khử sạch ánh vàng men)
    TEETH_SHADE_IVORY = 1,     // Trắng ngà tự nhiên (ấm áp dịu nhẹ)
    TEETH_SHADE_ENAMEL = 2,    // Trắng đục / men ngọc trai
    TEETH_SHADE_DARK = 3       // Tông màu sẫm / làm tối
};

enum TeethShapeMode {
    TEETH_SHAPE_SIZE = 0,      // Kích thước to / nhỏ
    TEETH_SHAPE_ALIGN = 1,     // Đều đặn / thưa kẽ
    TEETH_SHAPE_PROTRUSION = 2 // Răng hô / vẩu (đẩy vào) vs Quặp (kéo ra)
};

enum EarShapeMode {
    EAR_SHAPE_SIZE = 0,        // Tai to / nhỏ / ép tai vểnh vào trong
    EAR_SHAPE_THICKNESS = 1    // Dái tai dày tài lộc / mỏng thanh thoát
};

// CÁC KIỂU DÁNG TAI NGHỆ THUẬT & THẨM MỸ (EAR STYLES C++)
enum EarStyleMode {
    EAR_STYLE_ELF = 0,         // Tai yêu tinh (Elf ears - vuốt nhọn vành tai trên)
    EAR_STYLE_PRESS = 1,       // Ép tai vểnh (Flatten ears - ép vành tai sát hộp sọ)
    EAR_STYLE_PIG = 2,         // Tai heo (Pig ears - vểnh to khum vòm hai bên ngộ nghĩnh)
    EAR_STYLE_MOUSE = 3,       // Tai chuột (Mouse ears - vành tròn xòe cao dễ thương)
    EAR_STYLE_BUDDHA = 4,      // Tai phật (Buddha ears - dái tai dài, dày thịt, đại phú đại quý)
    EAR_STYLE_THICKNESS = 5,   // Dái tai dày quý tướng (Lobe plump)
    EAR_STYLE_PROTRUDE = 6     // Tai vểnh đón gió (Protrude ears - đẩy xòe vểnh tự nhiên)
};

// BÁO CÁO GIẢI PHẪU TAI: BO VIỀN, VỊ TRÍ SO VỚI MÁ, CẰM, MẮT, HƯỚNG TAI & VÀNH TAI
struct EarAnatomyReport {
    bool isValid;
    float leftEarCenterX, leftEarCenterY;
    float rightEarCenterX, rightEarCenterY;
    float earRadius;
    float leftEyeToEarDist;      // Khoảng cách mắt trái -> tai trái
    float rightEyeToEarDist;     // Khoảng cách mắt phải -> tai phải
    float earToEyeElevation;     // Độ cao tai so với đường mắt
    float earToCheekDistance;    // Độ nhô / vểnh so với gò má và xương hàm
    float earToChinVertical;     // Khoảng cách từ tai xuống đáy cằm
    float leftEarAngleDeg;       // Hướng nghiêng trục tai trái (độ)
    float rightEarAngleDeg;      // Hướng nghiêng trục tai phải (độ)
    float earProtrusionRatio;    // Tỷ lệ độ vểnh đón gió trực diện
    float leftHelixTopX, leftHelixTopY;       // Điểm cao nhất vành tai trái
    float leftLobeBottomX, leftLobeBottomY;   // Điểm đáy dái tai trái
    float leftLobeCenterX, leftLobeCenterY;   // Tâm dái tai trái (Tai Phật)
    float rightHelixTopX, rightHelixTopY;     // Điểm cao nhất vành tai phải
    float rightLobeBottomX, rightLobeBottomY; // Điểm đáy dái tai phải
    float rightLobeCenterX, rightLobeCenterY; // Tâm dái tai phải (Tai Phật)
    // Bo viền vành tai (Ear Helix Bounding Box)
    int leftEarMinX, leftEarMaxX, leftEarMinY, leftEarMaxY;
    int rightEarMinX, rightEarMaxX, rightEarMinY, rightEarMaxY;
    // Độ hiển thị sinh lý học tai theo góc chụp (Profile/3/4 Occlusion Detection)
    bool isLeftEarVisible;       // Tai trái có nhìn thấy trong ảnh hay không (false nếu chụp nghiêng bị khuất)
    bool isRightEarVisible;      // Tai phải có nhìn thấy trong ảnh hay không (false nếu chụp nghiêng bị khuất)
    float headYawAngleDeg;       // Góc xoay mặt theo phương ngang (âm: quay trái, dương: quay phải)
};

class TeethEarEngine {
public:
    // --- 1. ĐIỀU CHỈNH RĂNG C++ ---
    static bool applyTeethWhitening(
        uint32_t* pixels,
        int width,
        int height,
        float mouthCenterX,
        float mouthCenterY,
        float radiusX,
        float radiusY,
        int shadeMode,
        float intensity
    );

    static bool applyTeethReshape(
        uint32_t* pixels,
        int width,
        int height,
        float mouthCenterX,
        float mouthCenterY,
        float radiusX,
        float radiusY,
        int shapeMode,
        float value
    );

    // --- 2. ĐIỀU CHỈNH TAI C++ (EAR RESHAPE & ANATOMY ENGINE) ---
    static bool applyEarReshape(
        uint32_t* pixels,
        int width,
        int height,
        float leftEarX,
        float leftEarY,
        float rightEarX,
        float rightEarY,
        float radius,
        int shapeMode,
        float value,
        bool isLeftVisible = true,
        bool isRightVisible = true
    );

    static bool applyEarColorTuning(
        uint32_t* pixels,
        int width,
        int height,
        float leftEarX,
        float leftEarY,
        float rightEarX,
        float rightEarY,
        float radius,
        float colorTone,
        bool isLeftVisible = true,
        bool isRightVisible = true,
        const float* landmarks106 = nullptr
    );

    // 3. TÍNH TOÁN BO VIỀN, VỊ TRÍ TAI SO VỚI MÁ, CẰM, MẮT, HƯỚNG TAI, VÀNH TAI & KHUÔN TAI THỰC TẾ
    static EarAnatomyReport analyzeEarAnatomy(
        const float* landmarks106,
        int imageWidth,
        int imageHeight,
        const uint32_t* pixels = nullptr
    );

    // 4. ÁP DỤNG KIỂU DÁNG TAI CHUYÊN BIỆT (TAI HEO, TAI CHUỘT, TAI PHẬT, TAI YÊU TINH)
    static bool applyEarStyle(
        uint32_t* pixels,
        int width,
        int height,
        const float* landmarks106,
        float leftEarX, float leftEarY,
        float rightEarX, float rightEarY,
        float radius,
        int earStyle, // 0: Elf, 1: Press, 2: Pig, 3: Mouse, 4: Buddha, 5: Thickness, 6: Protrude
        float intensity,
        bool isLeftVisible = true,
        bool isRightVisible = true
    );
};

} // namespace meitu_native

#endif // MEITU_TEETH_EAR_ENGINE_H

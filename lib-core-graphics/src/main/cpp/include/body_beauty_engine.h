#ifndef MEITU_BODY_BEAUTY_ENGINE_H
#define MEITU_BODY_BEAUTY_ENGINE_H

#include <cstdint>
#include <vector>
#include <memory>
#include "body_semantic_model.h"
#include "clothing_aware_engine.h"
#include "background_protection_engine.h"
#include "body_contour_engine.h"
#include "deformation_constraint_solver.h"

namespace meitu_native {

struct BodyBeautyParameters {
    // 1. Overall Height & Proportion (SPEC Sections 76, 78)
    float bodyHeight = 0.0f;       // Tăng chiều cao tự nhiên [-1.0 .. 1.0]
    float headBodyRatio = 0.0f;    // Điều chỉnh tỷ lệ vàng đầu/thân [0.0 .. 1.0]

    // 2. Torso, Waist & Hip (SPEC Sections 49, 51, 52, 53, 77)
    float slimBody = 0.0f;         // Thon gọn / nở nang toàn thân [-1.0 .. 1.0]
    float waistSlim = 0.0f;        // Bóp eo con kiến / nới eo [-1.0 .. 1.0]
    float waistCurve = 0.0f;       // Uốn cong eo đồng hồ cát [0.0 .. 1.0]
    float hipEnhance = 0.0f;       // Nở hông quả táo / thon hông [-1.0 .. 1.0]
    float abdomenSlim = 0.0f;      // Giảm mỡ bụng phẳng / nở bụng [-1.0 .. 1.0]

    // 3. Shoulder & Posture (SPEC Sections 47, 79)
    float shoulderSlim = 0.0f;     // Gọt thon vai / mở rộng vai [-1.0 .. 1.0]
    float shoulderBalance = 0.0f;  // Cân bằng hai vai lệch [-1.0 .. 1.0]

    // 4. Arms & Hands (SPEC Sections 54, 55, 57, 59)
    float armSlim = 0.0f;          // Thon bắp tay / nở cơ bắp [-1.0 .. 1.0]

    // 5. Legs & Long Legs (SPEC Sections 63, 64, 66, 75)
    float longLegs = 0.0f;         // Kéo dài chân tự nhiên [0.0 .. 1.0]
    float legSlim = 0.0f;          // Thon đùi & bắp chân / nở chân [-1.0 .. 1.0]
    float ankleSlim = 0.0f;        // Thon cổ chân [-1.0 .. 1.0]

    // 6. Body Skin (SPEC Section 72)
    float bodySkinSmooth = 0.0f;   // Mịn da cơ thể (giữ vi lỗ chân lông >= 75%) [0.0 .. 1.0]
    float bodySkinWhiten = 0.0f;   // Trắng sáng da body [0.0 .. 1.0]
    float bodySkinToneMatch = 0.0f;// Đồng bộ tone màu da mặt - cổ - tay - chân [0.0 .. 1.0]
};

class BodyBeautyEngine {
public:
    BodyBeautyEngine();
    ~BodyBeautyEngine();

    /**
     * @brief Kéo dài chân tự nhiên (Long Legs - SPEC Section 75).
     * Phân phối scale đùi và cẳng chân, giữ tỷ lệ khớp gối, bàn chân và tiếp xúc mặt sàn.
     * Bảo vệ background tuyệt đối không bị kéo méo.
     */
    bool applyLongLegs(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const HumanFrameResult& human,
        float intensity
    );

    /**
     * @brief Tăng chiều cao toàn thân cân đối (Body Height - SPEC Section 76).
     * Phân phối tỷ lệ chuẩn: Thân trên 25%, Đùi 45%, Cẳng chân 30%.
     * Không kéo méo đầu, bàn tay, bàn chân.
     */
    bool applyBodyHeight(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const HumanFrameResult& human,
        float intensity
    );

    /**
     * @brief Thon gọn cơ thể, thắt eo & nở hông (Slim Body, Waist & Hip Reshape - SPEC Section 51, 77).
     * - Hỗ trợ cả 2 chiều: thu gọn vào (slimming) và to ra (expansion / curvy hip).
     * - Nhận diện đường biên vật lý chính xác từng sub-pixel (Boundary Contour Alignment).
     * - Bảo vệ tuyệt đối background và các vật thể bên cạnh (Zero Background Distortion, Delta = 0).
     * - Bảo vệ chất liệu vải (Conformal Elasticity) và phụ kiện cứng (cúc áo, khóa kéo, mặt khóa, nhựa/kim loại).
     */
    bool applyWaistAndBodySlim(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const HumanFrameResult& human,
        float slimIntensity,
        float waistIntensity,
        float hipIntensity
    );

    /**
     * @brief Thon bắp tay & chỉnh vai (Arm & Shoulder Slim - SPEC Section 47, 54, 55).
     * - Hỗ trợ cả thu gọn và nở cơ bắp.
     * - Nhận diện đúng đường biên bắp tay/vai, bảo vệ đồng hồ, trang sức, vòng tay, viền áo.
     * - Background xung quanh tay không bị méo mó.
     */
    bool applyArmAndShoulderSlim(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const HumanFrameResult& human,
        float shoulderIntensity,
        float armIntensity
    );

    /**
     * @brief Thon gọn / nở nang đùi và bắp chân (Leg Slim - SPEC Section 64, 66, 67).
     * - Nhận diện biên đùi trong/ngoài, bắp chuối và cổ chân.
     * - Bảo vệ đường may quần, túi quần, giày dép và đường thẳng mặt sàn / chân tường.
     */
    bool applyLegSlim(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const HumanFrameResult& human,
        float legSlimIntensity,
        float ankleSlimIntensity
    );

    /**
     * @brief Làm mịn, dưỡng trắng và đồng bộ màu da cơ thể (Body Skin Engine - SPEC Section 72).
     * Bảo lưu cấu trúc vi lỗ chân lông (micro-pores >= 75%).
     */
    bool applyBodySkinBeauty(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const HumanFrameResult& human,
        float smoothIntensity,
        float whitenIntensity,
        float toneMatchIntensity
    );

    /**
     * @brief Bộ điều phối Full Body Beauty Master Pipeline.
     */
    bool processFullBodyBeauty(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const HumanFrameResult& human,
        const BodyBeautyParameters& params
    );

private:
    ClothingAwareEngine mClothingEngine;
    meitu::body::BackgroundProtectionEngine mBgEngine;
    meitu::body::BodyContourEngine mContourEngine;
    DeformationConstraintSolver mConstraintSolver;

    /**
     * @brief Dò tìm đường biên vật lý chính xác của cơ thể theo từng dòng quét (sub-pixel boundary).
     */
    void detectSilhouetteBounds(
        const uint32_t* pixels, int width, int height,
        int yStart, int yEnd, float centerX, float expectedRadius,
        const uint8_t* parsingMask,
        std::vector<float>& outLeftEdges, std::vector<float>& outRightEdges
    );

    /**
     * @brief Biến dạng đường biên bảo toàn chất liệu trang phục và bảo vệ tuyệt đối nền xung quanh (Zero Background Warping).
     * - Khi thu gọn vào (scale < 1.0): background bên ngoài không bị xê dịch (Delta = 0.00), vùng trống lộ ra được bù lấp tự nhiên.
     * - Khi to ra (scale > 1.0): background ngoài biên mới không bị ảnh hưởng, viền ngoài hòa nhập sub-pixel anti-aliasing.
     * - Giữ nguyên 100% hình học cúc áo, khóa kéo, mặt thắt lưng (Zero Strain Tensor).
     * - Bảo toàn góc dệt sợi vải (Cauchy-Riemann Conformal Elasticity).
     */
    void applyBoundaryPreservingWarp(
        uint32_t* pixels, int width, int height, int stride,
        int yStart, int yEnd, float centerX,
        const std::vector<float>& leftEdges,
        const std::vector<float>& rightEdges,
        const std::vector<float>& scaleFactors,
        const std::vector<float>& rigidityMap,
        const std::vector<RigidElement>& rigidElements
    );

    /**
     * @brief Dò tìm đường biên vật lý chính xác của một đoạn chi (cánh tay hoặc chân) dọc theo trục xương (sub-pixel).
     */
    void detectLimbSilhouetteBounds(
        const uint32_t* pixels, int width, int height,
        const Point2DF& p1, const Point2DF& p2, float expectedRadius,
        const uint8_t* parsingMask,
        std::vector<float>& outSampleT,
        std::vector<float>& outRadiusLeft,
        std::vector<float>& outRadiusRight
    );

    /**
     * @brief Biến dạng đoạn chi (tay, chân) bảo toàn đường biên thực tế, không làm biến dạng background lân cận,
     * bảo vệ phụ kiện (đồng hồ, vòng tay, cúc) và chất liệu vải quần áo.
     */
    void applyLimbBoundaryPreservingWarp(
        uint32_t* pixels, int width, int height,
        const Point2DF& p1, const Point2DF& p2, float expectedRadius,
        float intensity,
        const uint8_t* parsingMask,
        const std::vector<float>& rigidityMap,
        const std::vector<RigidElement>& rigidElements
    );
};

} // namespace meitu_native

#endif // MEITU_BODY_BEAUTY_ENGINE_H

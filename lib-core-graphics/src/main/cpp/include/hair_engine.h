#ifndef MEITU_HAIR_ENGINE_H
#define MEITU_HAIR_ENGINE_H

#include <cstdint>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "landmark_fusion.h"
#include "head_semantic_model.h"

namespace meitu_native {

// =========================================================================
// 1. NHẬN DIỆN VÙNG (REGION RECOGNITION — SPEC Mục 5)
// hair mask, hairline, bangs/fringe, top/crown, side hair, back hair,
// hair-skin/background/ear/neck boundaries.
// =========================================================================

struct HairRegionMap {
    std::vector<uint8_t> hairMask;          // 0-255 Alpha mask toàn bộ tóc
    std::vector<Point2DF> hairline;         // Đường ranh giới chân tóc trên trán
    std::vector<uint8_t> bangsMask;         // Vùng tóc mái (fringe/bangs)
    std::vector<uint8_t> topCrownMask;      // Đỉnh đầu / vòm sọ (top/crown)
    std::vector<uint8_t> sideHairMask;      // Hai bên mai / thái dương (side hair)
    std::vector<uint8_t> backHairMask;      // Tóc sau gáy / lưng vai (back hair)

    // Ranh giới tiếp giáp (Boundaries):
    std::vector<uint8_t> hairSkinBoundary;  // Ranh giới tóc - da mặt/trán
    std::vector<uint8_t> hairBgBoundary;    // Ranh giới tóc - background
    std::vector<uint8_t> hairEarBoundary;   // Ranh giới tóc - vành tai
    std::vector<uint8_t> hairNeckBoundary;  // Ranh giới tóc - da cổ/vai

    int width = 0;
    int height = 0;
    BoundingBox2D hairBoundingBox;
    bool isValid = false;
};

// =========================================================================
// 2. PHÂN TÍCH CẤU TRÚC (STRUCTURAL ANALYSIS — SPEC Mục 5)
// orientation field, curl/wave, volume, apparent density, relative length,
// khối lượng/độ dày biểu kiến, parting line, flyaway hair, bang shape.
// =========================================================================

enum BangShapeType {
    BANG_NONE = 0,             // Không có mái / trán thoáng
    BANG_BLUNT = 1,            // Mái bằng
    BANG_AIRY_SEE_THROUGH = 2, // Mái thưa Hàn Quốc
    BANG_SIDE_SWEPT = 3,       // Mái chéo / rẽ ngôi lệch
    BANG_CURTAIN = 4           // Mái bay cánh bướm
};

struct HairStructuralFeatures {
    std::vector<float> orientationField;    // Góc hướng sợi theta(x, y) [-pi/2 .. pi/2]
    std::vector<float> coherenceField;      // Độ đồng hướng [0.0 .. 1.0]
    float curlWaveScore = 0.0f;            // 0.0: Thẳng mượt, 0.5: Lượn sóng, 1.0: Xoăn bồng
    float volumeScore = 0.0f;              // Độ phồng bồng bềnh biểu kiến [0.0 .. 1.0]
    float apparentDensity = 0.0f;          // Mật độ bao phủ da đầu [0.0 .. 1.0]
    float relativeLength = 0.0f;           // Độ dài tương đối so với chiều cao đầu
    float apparentMass = 0.0f;             // Khối lượng / độ dày biểu kiến
    float partingLineX = 0.0f;             // Tọa độ X đường rẽ ngôi (tương đối theo trán)
    bool hasPartingLine = false;
    std::vector<Point2DF> flyawayStrands;  // Các tọa độ sợi tóc con / tóc tơ bay
    BangShapeType bangShape = BANG_NONE;
};

// =========================================================================
// 3. APPEARANCE (ĐẶC TÍNH QUANG HỌC & BỀ MẶT — SPEC Mục 5)
// baseColor, localColorMap, highlightMap, shadowMap, apparentShine,
// localContrast, saturation, roughnessEstimate, lightingDirectionEstimate.
// =========================================================================

struct HairAppearanceModel {
    uint32_t baseColor = 0xFF1C140D;       // ARGB màu cơ bản albedo keratin
    std::vector<uint32_t> localColorMap;   // Bản đồ màu phân bố cục bộ
    std::vector<uint8_t> highlightMap;     // 0-255 specular highlight map
    std::vector<uint8_t> shadowMap;        // 0-255 self-shadow / depth crevice map
    float apparentShine = 0.5f;            // Độ bóng bẩy biểu kiến [0.0 .. 1.0]
    float localContrast = 0.5f;            // Độ tương phản sợi tóc [0.0 .. 1.0]
    float saturation = 0.2f;               // Độ bão hòa màu tóc
    float roughnessEstimate = 0.3f;        // Độ nhám biểu bì tóc (cuticle roughness)
    Point2DF lightingDirectionEstimate{0.0f, -1.0f}; // Hướng ánh sáng chính
};

// =========================================================================
// 4. BỘ ĐIỀU KHIỂN CHỈNH SỬA TÓC TOÀN NĂNG (HAIR ENGINE PIPELINE)
// =========================================================================

class HairEngine {
public:
    static HairEngine& getInstance();

    /**
     * @brief Phân tích toàn diện: Vùng + Cấu trúc + Appearance
     */
    bool analyzeHair(
        const uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        HairRegionMap& outRegions,
        HairStructuralFeatures& outStructure,
        HairAppearanceModel& outAppearance
    );

    /**
     * @brief Chỉnh sửa 1: Đổi màu / Highlight / Ombre (Material-Aware Recolor)
     * HairMask + Orientation + Luminance + Highlight/Shadow -> material-aware recolor -> preserve strand texture/illumination
     */
    bool recolorMaterialAware(
        uint32_t* inoutPixels,
        int width,
        int height,
        const HairRegionMap& regions,
        const HairStructuralFeatures& structure,
        const HairAppearanceModel& appearance,
        uint32_t rootColor,
        uint32_t tipColor,
        float ombrePosition,  // 0.0: toàn root, 0.5: ombre giữa tóc, 1.0: toàn tip
        float intensity,
        float shineBoost,
        bool isHighlight = false,
        float highlightWidth = 0.2f
    );

    /**
     * @brief Chỉnh sửa 2: Sáng/Tối & Tương phản sợi tóc
     */
    bool adjustLuminanceAndContrast(
        uint32_t* inoutPixels,
        int width,
        int height,
        const HairRegionMap& regions,
        float brightnessDelta,  // [-1.0 .. 1.0]
        float contrastDelta     // [-1.0 .. 1.0]
    );

    /**
     * @brief Chỉnh sửa 3: Độ bóng (Apparent Shine / Specular Gloss)
     */
    bool adjustShine(
        uint32_t* inoutPixels,
        int width,
        int height,
        const HairRegionMap& regions,
        const HairAppearanceModel& appearance,
        float shineStrength     // [-1.0 .. 1.0]
    );

    /**
     * @brief Chỉnh sửa 4: Volume (Làm phồng chân tóc) & Dày/Mỏng biểu kiến
     */
    bool adjustVolumeAndDensity(
        uint32_t* inoutPixels,
        int width,
        int height,
        const HairRegionMap& regions,
        const MeituReborn::FusedFaceGeometry& fused,
        float volumeDelta,      // [-1.0 .. 1.0]
        float densityDelta      // [-1.0 .. 1.0]
    );

    /**
     * @brief Chỉnh sửa 5: Đổi đường rẽ ngôi (Parting Line)
     */
    bool adjustPartingLine(
        uint32_t* inoutPixels,
        int width,
        int height,
        const HairRegionMap& regions,
        const HairStructuralFeatures& structure,
        float targetPartingX    // [-1.0: lệch trái, 0.0: chính giữa, 1.0: lệch phải]
    );

    /**
     * @brief Chỉnh sửa 6: Tóc mái (Bangs/Fringe) & Hạ đường chân tóc
     */
    bool adjustBangsAndHairline(
        uint32_t* inoutPixels,
        int width,
        int height,
        const HairRegionMap& regions,
        const MeituReborn::FusedFaceGeometry& fused,
        BangShapeType targetShape,
        float hairlineHeightDelta // [-1.0 .. 1.0]
    );

    /**
     * @brief Chỉnh sửa 7: Thẳng / Xoăn (Straight vs Curl & Wave)
     */
    bool adjustCurlAndWave(
        uint32_t* inoutPixels,
        int width,
        int height,
        const HairRegionMap& regions,
        const HairStructuralFeatures& structure,
        float curlDelta         // [-1.0: duỗi thẳng, +1.0: uốn sóng xoăn]
    );

    /**
     * @brief Chỉnh sửa 8: Xóa tóc & Tái tạo da đầu (Scalp Reconstruction)
     */
    bool removeHairAndReconstructScalp(
        uint32_t* inoutPixels,
        int width,
        int height,
        const HairRegionMap& regions,
        const MeituReborn::FusedFaceGeometry& fused,
        float removalStrength   // [0.0 .. 1.0]
    );

    /**
     * @brief Chỉnh sửa 9: Thêm tóc / Thay kiểu tóc 3D
     * head/scalp geometry + pose + ear + forehead/hairline + depth ordering + occlusion + hair asset
     */
    bool replaceHairstyle3D(
        uint32_t* inoutPixels,
        int width,
        int height,
        const HairRegionMap& currentRegions,
        const MeituReborn::FusedFaceGeometry& fused,
        const HeadGeometry& headGeom,
        int hairstyleAssetId,
        uint32_t targetColor,
        float blendStrength
    );

    /**
     * @brief Chỉnh sửa 11: Cắt tóc ngắn & Tạo kiểu tóc (Short Haircut & Hairstyle Suite)
     * styleCode:
     * 1: Pixie / Short Crop (Tóc tém nữ tính / Tóc cắt ngắn ôm viền mặt)
     * 2: Buzzcut (Tóc húi cua / Đầu đinh 3 phân chuẩn nam tính)
     * 3: Fade Undercut (Cạo sát 2 bên mai mờ dần lên đỉnh)
     * 4: Short Bob (Tóc Bob ngắn ngang xương hàm)
     * 5: Korean Side Part (Tóc 2 mái Hàn Quốc 7/3, 6/4 phồng chân)
     * 6: Layer Cut (Tóc tỉa layer ôm mặt so le)
     */
    bool applyHairstyleTrim(
        uint32_t* inoutPixels,
        int width,
        int height,
        const HairRegionMap& regions,
        const MeituReborn::FusedFaceGeometry& fused,
        int styleCode,
        float intensity
    );

private:
    HairEngine() = default;
    ~HairEngine() = default;

    static inline uint8_t clampU8(int v) {
        return (v < 0) ? 0 : (v > 255 ? 255 : static_cast<uint8_t>(v));
    }

    static inline float clampF(float v, float mn, float mx) {
        return (v < mn) ? mn : (v > mx ? mx : v);
    }
};

} // namespace meitu_native

#endif // MEITU_HAIR_ENGINE_H

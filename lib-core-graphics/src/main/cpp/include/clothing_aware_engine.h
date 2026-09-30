#ifndef MEITU_CLOTHING_AWARE_ENGINE_H
#define MEITU_CLOTHING_AWARE_ENGINE_H

#include <vector>
#include <cstdint>
#include "body_semantic_model.h"

namespace meitu_native {

enum RigidElementType {
    RIGID_BUTTON = 0,       // Cuc ao nhua / kim loai (tron, giu 100% tron, khong meo)
    RIGID_ZIPPER = 1,       // Khoa keo (duong thang rang khoa, giu lien tuc thang)
    RIGID_BUCKLE = 2,       // Mat khoa that lung nhua / kim loai
    RIGID_ACCESSORY = 3     // Phu kien cung (dong ho, vong, huy hieu, logo nhua)
};

struct RigidElement {
    float x{0.0f};
    float y{0.0f};
    float radius{8.0f};
    RigidElementType type{RIGID_BUTTON};
    float rigidity{0.95f};  // 0.0 to 1.0 (do cung chong bien dang)
    float meanDx{0.0f};
    float meanDy{0.0f};
};

struct ClothingFeature {
    float x{0.0f};
    float y{0.0f};
    float rigidity{0.8f};
};

/**
 * @brief Clothing-Aware Engine (SPEC Section 73).
 * Bao ve tuyet doi ket cau trang phuc, chat lieu vai va phu kien cung:
 * - Cuc ao, khoa keo, mat khoa that lung, phu kien nhua/kim loai khong bi meo mo, bien dang.
 * - Hoa van vai (ke soc, caro, denim, len) khong bi vo, keo gian hoac mat ti le goc (Conformal Elasticity).
 */
class ClothingAwareEngine {
public:
    ClothingAwareEngine();
    ~ClothingAwareEngine();

    /**
     * @brief Trich xuat ban do do cung (rigidity map) va cac phan tu cung (buttons, zippers, buckles).
     */
    bool extractClothingConstraints(
        const uint8_t* rgba,
        int width,
        int height,
        const uint8_t* parsingMask,
        std::vector<float>& outRigidityMap,
        std::vector<RigidElement>& outRigidElements
    );

    /**
     * @brief Overload tuong thich cho ClothingFeature cu.
     */
    bool extractClothingConstraints(
        const uint8_t* rgba,
        int width,
        int height,
        const uint8_t* parsingMask,
        std::vector<float>& outRigidityMap,
        std::vector<ClothingFeature>& outFeatures
    );

    /**
     * @brief Khoa chuyen vi dong nhat cho tung phan tu cung (Zero Strain Tensor).
     * Dam bao cuc ao nhua van tron 100%, mat khoa that lung khong bi lech/meo.
     */
    void applyRigidElementConstraints(
        int width,
        int height,
        const std::vector<RigidElement>& rigidElements,
        float* dxField,
        float* dyField
    );

    /**
     * @brief Dieu hoa truong bien dang vai ao theo mo hinh Cauchy-Riemann Conformal Elasticity.
     * Bao toan goc det vai, chong vo hoa van ke soc / caro khi thay doi kich thuoc co the.
     */
    void regularizeClothingDisplacement(
        int width,
        int height,
        const std::vector<float>& rigidityMap,
        const std::vector<RigidElement>& rigidElements,
        float* dxField,
        float* dyField
    );

    // Overload tuong thich nguoc
    void regularizeClothingDisplacement(
        int width,
        int height,
        const std::vector<float>& rigidityMap,
        float* dxField,
        float* dyField
    );
};

} // namespace meitu_native

namespace meitu {
namespace body {
    using RigidElementType = meitu_native::RigidElementType;
    using RigidElement = meitu_native::RigidElement;
    using ClothingFeature = meitu_native::ClothingFeature;
    using ClothingAwareEngine = meitu_native::ClothingAwareEngine;
}
}

#endif // MEITU_CLOTHING_AWARE_ENGINE_H

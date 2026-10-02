#ifndef MEITU_BEARD_DYE_ENGINE_H
#define MEITU_BEARD_DYE_ENGINE_H

#include <cstdint>
#include <vector>
#include "landmark_fusion.h"

namespace meitu_native {

enum BeardStyle {
    BEARD_STYLE_FULL = 0,             // Full chinstrap + goatee + mustache
    BEARD_STYLE_MUSTACHE_GOATEE = 1,  // Ria Mep & Rau Cam (Chuan theo hinh ve nguoi dung)
    BEARD_STYLE_MUSTACHE_ONLY = 2,    // Chi ria mep
    BEARD_STYLE_GOATEE_ONLY = 3       // Chi rau cam
};

class BeardDyeEngine {
public:
    // 1. Gray Away: Xoa rau bac / Phu den rau hoa ram, giu nguyen 100% da mat
    static bool applyGrayAway(
        uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        float intensity,
        float thickness = 1.0f,
        float heightOffset = 0.0f,
        float widthScale = 1.0f,
        int beardStyle = 0
    );

    // 2. Beard Dye: Nhuom rau thoi trang toi tung soi rau (khong do mau len da)
    static bool applyBeardDye(
        uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        int targetR, int targetG, int targetB,
        float intensity,
        float thickness = 1.0f,
        float heightOffset = 0.0f,
        float widthScale = 1.0f,
        int beardStyle = 0,
        float horizontalOffset = 0.0f
    );

    // 3. Preset Beard Overlay & Dye: Dan rau PNG co san len khuon mat, tu dong resize & warp theo 478 diem moc
    static bool applyPresetBeard(
        uint32_t* pixels,
        int width,
        int height,
        const uint32_t* beardPixels,
        int beardWidth,
        int beardHeight,
        const MeituReborn::FusedFaceGeometry& fused,
        float intensity,
        int targetR, int targetG, int targetB,
        bool isDyeActive,
        float thickness = 1.0f,
        float heightOffset = 0.0f,
        float widthScale = 1.0f,
        float horizontalOffset = 0.0f
    );

private:
    // Trich xuat mat na cac soi rau (khu mau da day) dua tren 478 diem moc & goc quay 3D
    static bool extractBeardFiberMask(
        const uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        std::vector<float>& outFiberMask,
        std::vector<bool>& outIsGrayFiber,
        float thickness = 1.0f,
        float heightOffset = 0.0f,
        float widthScale = 1.0f,
        int beardStyle = 0,
        float horizontalOffset = 0.0f
    );
};

} // namespace meitu_native

#endif // MEITU_BEARD_DYE_ENGINE_H

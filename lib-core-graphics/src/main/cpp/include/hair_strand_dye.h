#ifndef MEITU_HAIR_STRAND_DYE_H
#define MEITU_HAIR_STRAND_DYE_H

#include <cstdint>
#include <vector>
#include "landmark_fusion.h"

namespace meitu_native {

struct HairDyePreset {
    const char* name;
    int targetR;
    int targetG;
    int targetB;
    float bleachPower;  // 0.0: khong tay (mau toi), 1.0: tay manh (bach kim, khoi, hong)
    float glossPower;   // He so bat sang highlight
};

class HairStrandDyeEngine {
public:
    static const int PRESET_NATURAL_BLACK    = 0;
    static const int PRESET_CHESTNUT_BROWN   = 1;
    static const int PRESET_ASH_BROWN        = 2;
    static const int PRESET_PLATINUM_BLONDE  = 3;
    static const int PRESET_SMOKEY_SILVER    = 4;
    static const int PRESET_ROSE_GOLD        = 5;
    static const int PRESET_WINE_BURGUNDY    = 6;
    static const int PRESET_PEACH_LILAC      = 7;
    static const int PRESET_NAVY_BLUE        = 8;
    static const int PRESET_CARAMEL_HONEY    = 9;

    static const HairDyePreset& getPreset(int presetId);

    // Thuc thi 4 tang thuat toan nhuom tung soi toc
    static bool applyStrandDye(
        uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        int presetId,
        float intensity,
        float gloss = 0.5f
    );

    // Nhuom bang mau tuy chinh RGB
    static bool applyCustomStrandDye(
        uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused,
        int targetR, int targetG, int targetB,
        float bleachPower,
        float intensity,
        float gloss = 0.5f
    );
};

} // namespace meitu_native

#endif // MEITU_HAIR_STRAND_DYE_H

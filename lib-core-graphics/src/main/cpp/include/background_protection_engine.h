#ifndef MEITU_BACKGROUND_PROTECTION_ENGINE_H
#define MEITU_BACKGROUND_PROTECTION_ENGINE_H

#include <vector>
#include <cstdint>
#include "body_semantic_model.h"

namespace meitu {
namespace body {

class BackgroundProtectionEngine {
public:
    BackgroundProtectionEngine();
    ~BackgroundProtectionEngine();

    // Detect straight vertical and horizontal structural lines in the background (Section 83)
    bool detectStructuralLines(
        const uint8_t* rgba, int width, int height,
        std::vector<meitu_native::StructuralLine>& outLines
    );

    // Generate protection stiffness map (Section 82)
    // 255 = completely rigid (lines / background / adjacent objects), 0 = fully deformable body
    bool generateProtectionMask(
        int width, int height,
        const uint8_t* parsingMask,
        const std::vector<meitu_native::StructuralLine>& lines,
        uint8_t* outProtectionMask
    );

    // Regularize 2D deformation field to enforce line straightness and zero background distortion
    void regularizeDisplacementField(
        int width, int height,
        const uint8_t* protectionMask,
        const std::vector<meitu_native::StructuralLine>& lines,
        float* dxField, float* dyField
    );

    // Smooth boundary attenuation ensuring 0 displacement outside body silhouette
    void attenuateBoundaryLeakage(
        int width, int height,
        const uint8_t* parsingMask,
        float* dxField, float* dyField,
        int marginPx = 8
    );

    /**
     * @brief Tai tao vung background bi bo trong khi thu gon (Inward Contraction / Vacated Space).
     * Khi eo / canh tay / chan thu nho vao trong, vung trong giua bien cu va bien moi
     * duoc dien day bang ket cau background tu nhien tu ban goc snapshot ma khong lam meo
     * cac vat the hay duong thang phia sau.
     */
    void synthesizeVacatedBackground(
        uint32_t* currentPixels,
        const uint32_t* originalSnapshot,
        int width, int height,
        const uint8_t* parsingMask,
        const float* dxField,
        const float* dyField
    );
};

} // namespace body
} // namespace meitu

#endif // MEITU_BACKGROUND_PROTECTION_ENGINE_H

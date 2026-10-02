#ifndef MEITU_SURFACE_NORMAL_ENGINE_H
#define MEITU_SURFACE_NORMAL_ENGINE_H

#include <cstdint>
#include <vector>
#include "head_semantic_model.h"

namespace meitu_native {

// Section 24 SPEC: DEPTH / NORMAL / LIGHTING
enum NormalLightingParamId {
    PARAM_NORMAL_RELIGHT           = 2401, // Bù sáng 3D theo pháp tuyến bề mặt (3D Normal Relight)
    PARAM_NORMAL_NOSE_SCULPT       = 2402, // Tạo khối sống mũi cao Tây 3D (3D Nose Ridge Sculpt)
    PARAM_NORMAL_CHEEKBONE_SCULPT  = 2403, // Tạo khối gò má thanh tú (3D Cheekbone Contour)
    PARAM_NORMAL_JAWLINE_SHADOW    = 2404, // Đổ bóng viền hàm V-Line sắc nét (Jawline Shading)
    PARAM_NORMAL_CHIN_PROJECTION   = 2405  // Độ nhô 3D của chóp cằm (3D Chin Projection Highlight)
};

class SurfaceNormalEngine {
public:
    // Chỉnh sửa & tạo khối ánh sáng 3D chuẩn xác từng bit, pixel
    static bool applyNormalSculpting(
        uint32_t* pixels,
        int width,
        int height,
        const HeadFrameResult& headModel,
        int paramId,
        float intensity
    );
};

} // namespace meitu_native

#endif // MEITU_SURFACE_NORMAL_ENGINE_H

#ifndef MEITU_CLAVICLE_SHOULDER_ENGINE_H
#define MEITU_CLAVICLE_SHOULDER_ENGINE_H

#include <cstdint>
#include "head_semantic_model.h"

namespace meitu_native {

// Section 22 SPEC: CLAVICLE / UPPER SHOULDER — XƯƠNG QUAI XANH & VAI TRÊN
enum ClavicleShoulderParamId {
    PARAM_CLAVICLE_HIGHLIGHT     = 2201, // Nổi bật sống xương quai xanh (Clavicle Ridge Highlight)
    PARAM_CLAVICLE_SHADOW        = 2202, // Đổ bóng hố xương đòn tạo chiều sâu quyến rũ (Fossa Shadow)
    PARAM_SHOULDER_SLIM          = 2203, // Hạ góc vai thiên nga thon thả (Swan Shoulder Slimming)
    PARAM_NECK_SLIM              = 2204, // Thon gọn cơ cổ hai bên (Neck Slimming)
    PARAM_NECK_LENGTH            = 2205  // Kéo dài cổ thanh tú (Neck Length Extension)
};

class ClavicleShoulderEngine {
public:
    // Chỉnh sửa & tạo khối xương quai xanh, góc vai và cổ (Bit & Pixel precision)
    // Tự động bảo vệ ranh giới cổ áo (clothing boundary) và phông nền phía sau
    static bool applyClavicleShoulderEdit(
        uint32_t* pixels,
        int width,
        int height,
        const HeadFrameResult& headModel,
        int paramId,
        float intensity
    );
};

} // namespace meitu_native

#endif // MEITU_CLAVICLE_SHOULDER_ENGINE_H

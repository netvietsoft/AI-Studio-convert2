#ifndef MEITU_ACCESSORY_OCCLUSION_ENGINE_H
#define MEITU_ACCESSORY_OCCLUSION_ENGINE_H

#include <cstdint>
#include <vector>
#include "head_semantic_model.h"

namespace meitu_native {

// Section 23 SPEC: ACCESSORY / OCCLUSION ENGINE (KÍNH, KHUYÊN TAI, VẬT CẢN)
enum AccessoryType {
    ACC_GLASSES_OPTICAL  = 2301, // Kính cận gọng thẳng
    ACC_GLASSES_SUN      = 2302, // Kính râm / kính mát thời trang
    ACC_EARRING_LEFT     = 2303, // Khuyên tai trái
    ACC_EARRING_RIGHT    = 2304, // Khuyên tai phải
    ACC_FACE_MASK        = 2305  // Khẩu trang bảo hộ / y tế
};

class AccessoryOcclusionEngine {
public:
    // 1. Nhận diện & khoanh vùng phụ kiện cứng (Glasses / Earrings / Mask)
    static bool analyzeAccessories(
        const uint32_t* pixels,
        int width,
        int height,
        HeadFrameResult& headModel
    );

    // 2. Thuật toán bảo vệ phụ kiện bất biến (Rigid Anti-Warp Protection):
    // Ngăn chặn gọng kính, tròng kính bị cong vênh méo mó khi gọt mặt V-line hoặc bóp cằm.
    // Gọng kính được giữ nguyên hình học cứng (Rigid Body Mechanics), da mặt trượt tự nhiên bên dưới.
    static bool protectRigidAccessories(
        uint32_t* warpedPixels,
        const uint32_t* originalPixels,
        int width,
        int height,
        const HeadFrameResult& headModel,
        float rigidStrength = 1.0f
    );
};

} // namespace meitu_native

#endif // MEITU_ACCESSORY_OCCLUSION_ENGINE_H

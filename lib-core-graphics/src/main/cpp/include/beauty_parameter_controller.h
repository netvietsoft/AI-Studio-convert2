#ifndef MEITU_BEAUTY_PARAMETER_CONTROLLER_H
#define MEITU_BEAUTY_PARAMETER_CONTROLLER_H

#include <cstdint>
#include <vector>
#include <memory>
#include "head_semantic_model.h"
#include "head_skull_engine.h"
#include "neck_clavicle_engine.h"
#include "eyebrow_lash_engine.h"
#include "accessory_occlusion_engine.h"
#include "scalp_reconstruction_engine.h"
#include "teeth_ear_engine.h"
#include "skin_makeup_engine.h"

namespace meitu_native {

struct BeautyParameters {
    // 1. Head & Skull (Mục 3, 7)
    float headSize = 0.0f;           // Thu nhỏ đầu [0.0 .. 1.0]
    float skullCrown = 0.0f;          // Nâng vòm sọ [0.0 .. 1.0]
    float templeWidth = 0.0f;         // Độ rộng thái dương [0.0 .. 1.0]
    float foreheadHeight = 0.0f;      // Chiều cao trán [0.0 .. 1.0]

    // 2. Face Contour & Jaw (Mục 9, 15, 16)
    float slimFace = 0.0f;            // Gọt mặt V-Line [0.0 .. 1.0]
    float jawWidth = 0.0f;            // Thu gọn xương hàm [0.0 .. 1.0]
    float chinLength = 0.0f;          // Kéo dài/thu ngắn cằm [0.0 .. 1.0]

    // 3. Neck & Clavicle (Mục 21, 22)
    float neckSlim = 0.0f;            // Thon cổ [0.0 .. 1.0]
    float neckLength = 0.0f;          // Cổ thiên nga [0.0 .. 1.0]
    float neckWrinkles = 0.0f;        // Xóa nhăn cổ [0.0 .. 1.0]
    float clavicleEnhance = 0.0f;     // Nổi xương quai xanh 3D [0.0 .. 1.0]
    float faceNeckToneMatch = 0.0f;   // Đồng bộ màu da mặt - cổ [0.0 .. 1.0]

    // 4. Eyebrow & Eyelash (Mục 10, 11)
    float browThickness = 0.0f;       // Dày lông mày [0.0 .. 1.0]
    float browArch = 0.0f;            // Nâng vòm chân mày [0.0 .. 1.0]
    float browDensityFill = 0.0f;     // Rậm chân mày [0.0 .. 1.0]
    float lashDensity = 0.0f;         // Dày lông mi [0.0 .. 1.0]
    float lashLength = 0.0f;          // Dài lông mi [0.0 .. 1.0]
    float lashCurl = 0.0f;            // Uốn cong mi 3D [0.0 .. 1.0]

    // 5. Ear (Mục 8)
    float earSize = 0.0f;             // Tai to / Tai Phật [0.0 .. 1.0]

    // 6. Skin & Teeth (Mục 6, 19)
    float skinSmooth = 0.0f;          // Làm mịn da [0.0 .. 1.0]
    float skinWhiten = 0.0f;          // Làm trắng da [0.0 .. 1.0]
    float teethWhiten = 0.0f;         // Trắng răng [0.0 .. 1.0]
};

/**
 * @brief Master Coordinator for Head Semantic Geometry + Appearance + Beauty Engine
 * (SPEC Sections 30, 37).
 * Executes all beauty modifications in verified physiological and occlusion order.
 */
class BeautyParameterController {
public:
    BeautyParameterController();
    ~BeautyParameterController();

    /**
     * @brief Executes the complete beauty transformation pipeline on an RGBA frame.
     * Guaranteed bit-exact and subpixel-accurate with rigid accessory protection.
     */
    bool applyBeautyPipeline(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const std::vector<float>& landmarkPoints, // [x0, y0, x1, y1...]
        const BeautyParameters& params
    );

private:
    std::unique_ptr<HeadSkullEngine> mSkullEngine;
    std::unique_ptr<NeckClavicleEngine> mNeckEngine;
    std::unique_ptr<EyebrowLashEngine> mBrowLashEngine;
    std::unique_ptr<ScalpReconstructionEngine> mScalpEngine;
};

} // namespace meitu_native

#endif // MEITU_BEAUTY_PARAMETER_CONTROLLER_H

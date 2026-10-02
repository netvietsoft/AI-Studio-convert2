#ifndef MEITU_FACE_RESHAPE_3DMM_H
#define MEITU_FACE_RESHAPE_3DMM_H

#include <cstdint>
#include <vector>

namespace meitu_native {

// Mã tham số 3DMM tương thích MTARBeautyParm và BeautySenseData
enum Face3DMMParamId {
    // 2.2.1 OVERALL
    PARAM_HD_PORTRAIT = 200007,
    PARAM_AUTO = 200000,
    PARAM_FACE_WIDTH = 4112,       // kParamFlag_Face_Whittle
    PARAM_FACE_LIFT = 4679,        // kParamFlag_FaceVShape
    PARAM_FACE_SMOOTH = 2000013,
    PARAM_OVERALL = 2000099,

    // 2.2.2 RATIO / SHAPE
    PARAM_NARROW_FACE = 4125,      // kParamFlag_Narrow_Face
    PARAM_SMALL_FACE = 4113,       // kParamFlag_Face_Smaller
    PARAM_SLIM_VLINE = 2000014,    // SlimDeform
    PARAM_FOREHEAD = 4114,         // kParamFlag_Face_Forehead
    PARAM_CHEEKBONE = 4638,        // kParamFlag_LeftCheekbone
    PARAM_TEMPLE = 4169,           // kParamFlag_BeautyFaceTemple
    PARAM_MANDIBLE = 4180,         // kParamFlag_Mandible
    PARAM_CHIN = 4690,             // kParamFlag_PointedAndRoundChin
    PARAM_ROUND_HEAD = 2000011,    // kParamFlag_RoundHead / Calvarium
    PARAM_LOWER_FACE = 4234,       // kParamFlag_LowerFace
    PARAM_MIDDLE_HALF = 4216,      // kParamFlag_MiddleHalfOfFace
    PARAM_FACE_VSHAPE = 4680,

    // RESHAPE 3DMM DETAILED
    PARAM_3DMM_JAW = 200008,
    PARAM_3DMM_SMILE = 600005,     // kParamFlag_Smile
    PARAM_3DMM_NOSE = 400001,
    PARAM_3DMM_NOSE_WIDTH = 400002,// kParamFlag_ShrinkNose
    PARAM_3DMM_NOSE_BRIDGE = 4158, // kParamFlag_BtidgeNose
    PARAM_3DMM_NOSE_TIP = 4159,    // kParamFlag_Nasaltip
    PARAM_3DMM_EYES_SIZE = 300001, // kParamFlag_Eye_Distance
    PARAM_3DMM_EYES_TILT = 4178,   // kParamFlag_EyeTilt
    PARAM_3DMM_EYES_WIDTH = 4612,  // kParamFlag_LeftEyeWidth
    PARAM_3DMM_EYES_DISTANCE = 4109,
    PARAM_3DMM_BROW_SHAPE = 500004,
    PARAM_3DMM_BROW_THICKNESS = 4189,
    PARAM_3DMM_BROW_HEIGHT = 4181,
    PARAM_3DMM_LIPS = 4188,
    PARAM_3DMM_UPPER_LIP = 4130,
    PARAM_3DMM_LOWER_LIP = 4131,
    PARAM_3DMM_SYMMETRY = 2000022,
    PARAM_3DMM_HEAD = 4104,

    // RESHAPE FREEFORM & RESIZES
    PARAM_RESHAPE_WARP = 700001,
    PARAM_RESHAPE_REFINE = 700002,
    PARAM_RESHAPE_RESIZE = 700003,
    PARAM_RESHAPE_RESTORE = 700004,

    PARAM_RESIZE_HEAD = 800001,
    PARAM_RESIZE_EYES = 800002,
    PARAM_RESIZE_NOSE = 800003,
    PARAM_RESIZE_MOUTH = 800004,
    PARAM_RESIZE_EARS = 800005
};

enum FacePresetId {
    PRESET_ORIGIN = 62149,
    PRESET_FINETUNING = 62164,
    PRESET_PHOTOGENIC = 62186,
    PRESET_ROUND = 62107,
    PRESET_SQUARE = 62108,
    PRESET_LONG = 62109,
    PRESET_SHORT = 62110
};

class FaceReshape3DMMEngine {
public:
    // Áp dụng định hình 3DMM theo tham số giải phẫu học
    static bool apply3DMMParam(
        uint32_t* pixels,
        int width,
        int height,
        const float* landmarks106,
        int paramId,
        float intensity,
        const uint32_t* originalPixels = nullptr
    );

    // Áp dụng preset tỷ lệ dáng mặt
    static bool applyFacePreset(
        uint32_t* pixels,
        int width,
        int height,
        const float* landmarks106,
        int presetId,
        float intensity,
        const uint32_t* originalPixels = nullptr
    );

    // Nắn bóp tự do và thay đổi kích thước vùng chọn
    static bool applyFreeformReshape(
        uint32_t* pixels,
        int width,
        int height,
        float touchX,
        float touchY,
        float targetX,
        float targetY,
        float radius,
        int reshapeType,
        float intensity,
        const uint32_t* originalPixels = nullptr
    );
};

} // namespace meitu_native

#endif // MEITU_FACE_RESHAPE_3DMM_H

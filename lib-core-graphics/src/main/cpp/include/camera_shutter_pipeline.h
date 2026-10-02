#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>

namespace meitu::camera {

enum class WhiteBalanceMode {
    OFF = 0,
    AUTO_GRAY_WORLD = 1,
    DAYLIGHT = 2,
    CLOUDY = 3,
    FLUORESCENT = 4,
    INCANDESCENT = 5
};

struct ShutterBeautyConfig {
    float skinSmoothIntensity = 0.5f;   // 0.0 - 1.0 (Bilateral Denoise)
    float skinWhitening = 0.3f;          // 0.0 - 1.0
    float vLineJawIntensity = 0.2f;       // 0.0 - 1.0
    float bigEyeIntensity = 0.2f;         // 0.0 - 1.0
    int teethShade = 1;                  // 0: Porcelain, 1: Ivory, 2: Enamel
    float teethWhitening = 0.4f;         // 0.0 - 1.0
    float earReshape = 0.2f;             // 0.0 - 1.0
    float earTone = 0.3f;                // 0.0 - 1.0
    WhiteBalanceMode awbMode = WhiteBalanceMode::AUTO_GRAY_WORLD;
    int targetQuality = 98;              // 1 - 100
};

class CameraShutterPipeline {
public:
    static bool applyAutoWhiteBalance(uint32_t* pixels, int width, int height, WhiteBalanceMode mode);
    static bool applyBilateralSkinSmooth(
        uint32_t* pixels, int width, int height,
        float spatialSigma, float rangeSigma, float intensity,
        const float* landmarks106 = nullptr, int landmarkCount = 0
    );
    static bool processShutterCapture(
        uint32_t* pixels, int width, int height,
        const ShutterBeautyConfig& config,
        const float* landmarks106 = nullptr, int landmarkCount = 0
    );
    
    // Live Preview Multi-Feature Engine (0-100% rõ rệt trên máy thật Samsung Galaxy A50)
    // Tối ưu biểu bì da: Bảo toàn tóc, lông mi, lông mày, râu, kính mắt
    static bool processLivePreviewBeauty(
        uint32_t* pixels, int width, int height,
        int lutType, float lutIntensity,
        float skinSmooth, float skinWhiten,
        float faceVLine, float bigEyes,
        float noseShrink, float lipPlump,
        float teethWhiten = 0.0f, float eyeBags = 0.0f, float skinClear = 0.0f,
        const float* landmarks106 = nullptr, int landmarkCount = 0
    );
};

} // namespace meitu::camera

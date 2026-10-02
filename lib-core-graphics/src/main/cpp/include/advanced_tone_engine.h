#ifndef MEITU_ADVANCED_TONE_ENGINE_H
#define MEITU_ADVANCED_TONE_ENGINE_H

#include <cstdint>

namespace meitu_native {

// 2.14 HSL 8 CHANNELS
enum HslChannelId {
    HSL_RED     = 0,
    HSL_ORANGE  = 1,
    HSL_YELLOW  = 2,
    HSL_GREEN   = 3,
    HSL_CYAN    = 4,
    HSL_BLUE    = 5,
    HSL_PURPLE  = 6,
    HSL_MAGENTA = 7
};

// 2.14 TONE PARAMETERS
enum ToneParamId {
    TONE_BRIGHTNESS   = 1401,
    TONE_CONTRAST     = 1402,
    TONE_SATURATION   = 1403,
    TONE_VIBRANCE     = 1404,
    TONE_TEMPERATURE  = 1405,
    TONE_TINT         = 1406,
    TONE_SHARPEN      = 1407,
    TONE_GRAIN        = 1408,
    TONE_EXPOSURE     = 1409,
    TONE_HIGHLIGHTS   = 1410,
    TONE_SHADOWS      = 1411
};

// 2.12 AI RETOUCH PRESETS
enum AiRetouchPresetId {
    AI_PRESET_IDOL          = 1201,
    AI_PRESET_YOUNG_PRO     = 1202,
    AI_PRESET_REFINED       = 1203,
    AI_PRESET_SCULPTED      = 1204,
    AI_PRESET_NATURAL_DEWY  = 1205,
    AI_PRESET_FRESH_CLEAN   = 1206
};

// 3D LUT FILTERS
enum FilterPresetId {
    FILTER_RETRO_FILM   = 1,
    FILTER_PORTRAIT_GLOW = 2,
    FILTER_CYBERPUNK    = 3,
    FILTER_VINTAGE_90S  = 4,
    FILTER_MOODY_BW     = 5,
    FILTER_GOLDEN_HOUR  = 6,
    FILTER_KODAK_PORTRA = 7,
    FILTER_FUJI_VELVIA  = 8
};

class AdvancedToneEngine {
public:
    // 1. Chỉnh màu HSL 8 Kênh độc lập
    static bool applyHslChannel(
        uint32_t* pixels,
        int width,
        int height,
        int channelId,
        float hueShift,
        float satShift,
        float lumShift
    );

    // 2. Chỉnh thông số kỹ thuật màu nhiếp ảnh (Tone Adjust)
    static bool applyToneParam(
        uint32_t* pixels,
        int width,
        int height,
        int paramId,
        float value
    );

    // 3. Áp dụng 3D LUT Color Filter
    static bool applyFilter(
        uint32_t* pixels,
        int width,
        int height,
        int filterId,
        float intensity
    );

    // 4. Áp dụng AI Retouch Preset (2.12)
    static bool applyAiRetouch(
        uint32_t* pixels,
        int width,
        int height,
        int presetId,
        float intensity
    );

    // 5. Xóa phông Portrait Bokeh Defocus / Depth of Field (2.14 / 2.15)
    static bool applyPortraitDefocus(
        uint32_t* pixels,
        int width,
        int height,
        float focusX, float focusY,
        float focusRadiusX, float focusRadiusY,
        float blurStrength
    );
};

} // namespace meitu_native

#endif // MEITU_ADVANCED_TONE_ENGINE_H

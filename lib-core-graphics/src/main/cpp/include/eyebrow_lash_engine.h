#ifndef MEITU_EYEBROW_LASH_ENGINE_H
#define MEITU_EYEBROW_LASH_ENGINE_H

#include <cstdint>
#include <vector>
#include <cmath>
#include <algorithm>
#include "head_semantic_model.h"

namespace meitu_native {

class EyebrowLashEngine {
public:
    // Parameter IDs for Eyebrow & Eyelash (SPEC Sections 10, 11, 30)
    static constexpr int PARAM_BROW_THICKNESS = 1;     // Dày/mỏng lông mày (0.0 .. 1.0)
    static constexpr int PARAM_BROW_ARCH = 2;          // Nâng/hạ đỉnh vòm lông mày (0.0 .. 1.0)
    static constexpr int PARAM_BROW_LENGTH = 3;        // Kéo dài/thu ngắn đuôi lông mày (0.0 .. 1.0)
    static constexpr int PARAM_BROW_DENSITY_FILL = 4;  // Điền đầy sợi / Làm rậm lông mày (0.0 .. 1.0)
    static constexpr int PARAM_BROW_COLOR = 5;         // Nhuộm màu lông mày (Nâu đậm, Tự nhiên)
    static constexpr int PARAM_LASH_DENSITY = 6;       // Làm dày/rậm mi (0.0 .. 1.0)
    static constexpr int PARAM_LASH_LENGTH = 7;        // Nối dài mi tự nhiên (0.0 .. 1.0)
    static constexpr int PARAM_LASH_CURL = 8;          // Uốn cong mi 3D (0.0 .. 1.0)

    EyebrowLashEngine();
    ~EyebrowLashEngine();

    /**
     * @brief Process eyebrow & eyelash editing with subpixel precision and
     * strict sclera/iris/pupil exclusion to prevent color pollution.
     */
    bool processEyebrowLash(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const HeadFrameResult& headResult,
        int paramId,
        float intensity
    );

private:
    bool applyBrowThickness(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity);
    bool applyBrowArch(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity);
    bool applyBrowDensityFill(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity);
    bool applyBrowColor(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity);
    bool applyLashDensity(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity);
    bool applyLashLengthAndCurl(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity, bool curl);

    // Helpers
    static inline float clampF(float v, float mn, float mx) {
        return (v < mn) ? mn : (v > mx ? mx : v);
    }
    static inline uint8_t clampU8(int v) {
        return (v < 0) ? 0 : (v > 255 ? 255 : static_cast<uint8_t>(v));
    }
    static void sampleBilinear(const uint8_t* src, int w, int h, int stride, float x, float y, uint8_t out[4]);
};

} // namespace meitu_native

#endif // MEITU_EYEBROW_LASH_ENGINE_H

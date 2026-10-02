#ifndef MEITU_NECK_CLAVICLE_ENGINE_H
#define MEITU_NECK_CLAVICLE_ENGINE_H

#include <cstdint>
#include <vector>
#include <cmath>
#include <algorithm>
#include "head_semantic_model.h"

namespace meitu_native {

class NeckClavicleEngine {
public:
    // Parameter IDs for Neck & Clavicle (SPEC Sections 21, 22, 30)
    static constexpr int PARAM_NECK_SLIM = 1;          // Thon cổ (0.0 .. 1.0)
    static constexpr int PARAM_NECK_LENGTH = 2;        // Cổ thiên nga / Kéo dài cổ (0.0 .. 1.0)
    static constexpr int PARAM_NECK_WRINKLE_SMOOTH = 3; // Xóa nếp nhăn cổ / Vòng cổ Venus (0.0 .. 1.0)
    static constexpr int PARAM_CLAVICLE_ENHANCE = 4;   // Nổi xương quai xanh 3D (0.0 .. 1.0)
    static constexpr int PARAM_FACE_NECK_TONE = 5;     // Đồng bộ tông màu da mặt - cổ (0.0 .. 1.0)

    NeckClavicleEngine();
    ~NeckClavicleEngine();

    /**
     * @brief Apply neck reshaping & clavicle enhancement with subpixel precision
     * and strict collar/clothing/hair boundary protection.
     *
     * @param rgbaImage Input/output RGBA 32-bit pixel buffer
     * @param width Image width in pixels
     * @param height Image height in pixels
     * @param stride Byte stride per row (typically width * 4)
     * @param headResult Extracted semantic head model
     * @param paramId One of PARAM_*
     * @param intensity Normalized parameter intensity [0.0f .. 1.0f]
     * @return true if processing succeeded
     */
    bool processNeckClavicle(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const HeadFrameResult& headResult,
        int paramId,
        float intensity
    );

private:
    // Sub-operations
    bool applyNeckSlimming(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity);
    bool applyNeckLength(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity);
    bool applyNeckWrinkleSmoothing(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity);
    bool applyClavicleEnhancement(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity);
    bool applyFaceNeckToneMatching(uint8_t* rgba, int w, int h, int stride, const HeadFrameResult& head, float intensity);

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

#endif // MEITU_NECK_CLAVICLE_ENGINE_H

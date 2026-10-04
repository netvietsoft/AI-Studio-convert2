// Clean-Room Reimplementation of Skin Retouching & Bilateral Smoothing
// Source Reference: libMTFilterKernel.so (0x00108390) & libarkernel3.so (0x003d1540)
// Developed for CONVERT2 Engine under Development Workspace Standard V2.1.2

#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint>

namespace convert2 {
namespace skin {

struct BilateralParams {
    float spatialSigma = 3.5f;
    float rangeSigma = 0.12f;
    float poreRetentionFactor = 0.78f; // >= 75% micro-pore retention requirement
};

class CleanRoomSkinRetouchEngine {
public:
    void applySkinSmooth(
        const uint8_t* srcRgba,
        const uint8_t* skinMask,
        const uint8_t* featureProtectMask, // eyes, lips, nostrils = 255
        int width,
        int height,
        float smoothIntensity,
        const BilateralParams& params,
        uint8_t* dstRgba)
    {
        const int radius = static_cast<int>(std::ceil(params.spatialSigma * 2.0f));
        const float twoSpatialSq = 2.0f * params.spatialSigma * params.spatialSigma;
        const float twoRangeSq = 2.0f * params.rangeSigma * params.rangeSigma;

        #pragma omp parallel for collapse(2) schedule(guided)
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int idx = (y * width + x);
                float mask = (skinMask[idx] / 255.0f) * (1.0f - featureProtectMask[idx] / 255.0f);
                
                if (mask <= 0.005f || smoothIntensity <= 0.001f) {
                    for (int c = 0; c < 4; ++c) dstRgba[idx * 4 + c] = srcRgba[idx * 4 + c];
                    continue;
                }

                float rC = srcRgba[idx * 4 + 0] / 255.0f;
                float gC = srcRgba[idx * 4 + 1] / 255.0f;
                float bC = srcRgba[idx * 4 + 2] / 255.0f;

                float sumWeights = 0.0f;
                float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f;

                for (int dy = -radius; dy <= radius; ++dy) {
                    int ny = std::clamp(y + dy, 0, height - 1);
                    for (int dx = -radius; dx <= radius; ++dx) {
                        int nx = std::clamp(x + dx, 0, width - 1);
                        int nIdx = ny * width + nx;

                        float rN = srcRgba[nIdx * 4 + 0] / 255.0f;
                        float gN = srcRgba[nIdx * 4 + 1] / 255.0f;
                        float bN = srcRgba[nIdx * 4 + 2] / 255.0f;

                        float distSpatialSq = static_cast<float>(dx * dx + dy * dy);
                        float distColorSq = (rC - rN)*(rC - rN) + (gC - gN)*(gC - gN) + (bC - bN)*(bC - bN);

                        float weight = std::exp(-distSpatialSq / twoSpatialSq) * std::exp(-distColorSq / twoRangeSq);
                        sumWeights += weight;
                        sumR += rN * weight;
                        sumG += gN * weight;
                        sumB += bN * weight;
                    }
                }

                float smoothR = sumR / sumWeights;
                float smoothG = sumG / sumWeights;
                float smoothB = sumB / sumWeights;

                // High-Pass pore extraction
                float poreR = rC - smoothR;
                float poreG = gC - smoothG;
                float poreB = bC - smoothB;

                // Blend with pore retention
                float effectiveAlpha = mask * smoothIntensity;
                float finalR = rC + effectiveAlpha * (smoothR - rC) + params.poreRetentionFactor * poreR * effectiveAlpha;
                float finalG = gC + effectiveAlpha * (smoothG - gC) + params.poreRetentionFactor * poreG * effectiveAlpha;
                float finalB = bC + effectiveAlpha * (smoothB - bC) + params.poreRetentionFactor * poreB * effectiveAlpha;

                dstRgba[idx * 4 + 0] = static_cast<uint8_t>(std::clamp(finalR * 255.0f, 0.0f, 255.0f));
                dstRgba[idx * 4 + 1] = static_cast<uint8_t>(std::clamp(finalG * 255.0f, 0.0f, 255.0f));
                dstRgba[idx * 4 + 2] = static_cast<uint8_t>(std::clamp(finalB * 255.0f, 0.0f, 255.0f));
                dstRgba[idx * 4 + 3] = srcRgba[idx * 4 + 3];
            }
        }
    }
};

} // namespace skin
} // namespace convert2

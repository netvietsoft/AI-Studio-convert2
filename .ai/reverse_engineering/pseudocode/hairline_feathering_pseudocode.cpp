// SOURCE: Clean-Room C++ Reconstruction from libMTFilterKernel.so (0x000a2410)
// Reconstructed for Project CONVERT2 — Hair Color Engine

#include <cmath>
#include <algorithm>
#include <cstdint>
#include <vector>

namespace convert2 {
namespace hair {

class HairlineFeatheringPass {
public:
    static void ApplyFeathering(
        const float* rawHairMask,
        const float* rawSkinMask,
        int width,
        int height,
        float featherRadius,
        float* outFeatheredMask
    ) {
        int r = static_cast<int>(std::ceil(featherRadius));
        if (r < 1) r = 1;

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int centerIdx = y * width + x;
                float skinVal = rawSkinMask[centerIdx];

                // Hard skin protection gate: if confidence of facial skin > 0.65, zero hair alpha
                if (skinVal > 0.65f) {
                    outFeatheredMask[centerIdx] = 0.0f;
                    continue;
                }

                // Bilateral-weighted local alpha averaging
                float weightSum = 0.0f;
                float valSum = 0.0f;

                for (int dy = -r; dy <= r; ++dy) {
                    int ny = y + dy;
                    if (ny < 0 || ny >= height) continue;

                    for (int dx = -r; dx <= r; ++dx) {
                        int nx = x + dx;
                        if (nx < 0 || nx >= width) continue;

                        int neighborIdx = ny * width + nx;
                        float distSq = static_cast<float>(dx * dx + dy * dy);
                        float spatialWeight = std::exp(-distSq / (2.0f * featherRadius * featherRadius));

                        // Suppress neighbor contribution if neighbor is deep inside skin
                        float neighborSkin = rawSkinMask[neighborIdx];
                        float skinPenalty = (neighborSkin > 0.5f) ? 0.1f : 1.0f;

                        float w = spatialWeight * skinPenalty;
                        valSum += rawHairMask[neighborIdx] * w;
                        weightSum += w;
                    }
                }

                float smoothedAlpha = (weightSum > 1e-5f) ? (valSum / weightSum) : rawHairMask[centerIdx];

                // Smooth ramp suppression against face skin
                float skinSuppression = 1.0f;
                if (skinVal > 0.10f) {
                    float t = (skinVal - 0.10f) / (0.65f - 0.10f);
                    t = std::max(0.0f, std::min(1.0f, t));
                    skinSuppression = 1.0f - (t * t * (3.0f - 2.0f * t)); // Smoothstep
                }

                outFeatheredMask[centerIdx] = std::max(0.0f, std::min(1.0f, smoothedAlpha * skinSuppression));
            }
        }
    }
};

} // namespace hair
} // namespace convert2

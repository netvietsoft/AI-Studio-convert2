// Clean-Room Reimplementation of MTSoftHairFilter (libMTFilterKernel.so 0x000f3f58)
// Developed for CONVERT2 Engine under Development Workspace Standard V2.1
#include <vector>
#include <cmath>
#include <algorithm>

namespace convert2 {
namespace hair {

struct GaussianWeights {
    static constexpr float weights[5] = {0.159676f, 0.263348f, 0.122118f, 0.030573f, 0.004122f};
};

class CleanRoomSoftHairFilter {
public:
    void render5PassPipeline(
        const uint8_t* srcRgba,
        const uint8_t* hairMask,
        int width,
        int height,
        float dyeIntensity,
        float shineFactor,
        const float dyeColor[3],
        uint8_t* dstRgba)
    {
        // Pass 1: Extract Luminance FBO (grayFilterToFBO 0x000f42fc)
        std::vector<float> luminance(width * height);
        for (int i = 0; i < width * height; ++i) {
            float r = srcRgba[i * 4 + 0] / 255.0f;
            float g = srcRgba[i * 4 + 1] / 255.0f;
            float b = srcRgba[i * 4 + 2] / 255.0f;
            luminance[i] = 0.299f * r + 0.587f * g + 0.114f * b;
        }

        // Pass 2: Filter Hair Mask FBO (hairMaskFilterToFBO 0x000f4400)
        std::vector<float> featherMask(width * height);
        for (int i = 0; i < width * height; ++i) {
            featherMask[i] = hairMask[i] / 255.0f;
        }

        // Pass 3 & 4: Separable Gaussian Blur (blurHFilterToFBO 0x000f4528 & blurV 0x000f46d0)
        std::vector<float> blurH(width * height);
        std::vector<float> blurV(width * height);
        apply1DGaussian(luminance.data(), blurH.data(), width, height, true);
        apply1DGaussian(blurH.data(), blurV.data(), width, height, false);

        // Pass 5: Unsharp Mask Clarity 0.4 & Pegtop SoftLight Composite (0x000f4878)
        for (int i = 0; i < width * height; ++i) {
            float m = featherMask[i];
            if (m <= 0.001f) {
                dstRgba[i * 4 + 0] = srcRgba[i * 4 + 0];
                dstRgba[i * 4 + 1] = srcRgba[i * 4 + 1];
                dstRgba[i * 4 + 2] = srcRgba[i * 4 + 2];
                dstRgba[i * 4 + 3] = srcRgba[i * 4 + 3];
                continue;
            }

            float baseLuma = luminance[i];
            float blurredLuma = blurV[i];
            float highPass = baseLuma - blurredLuma;
            float clarityLuma = baseLuma + highPass * 0.4f * 1.8f;
            clarityLuma = std::clamp(clarityLuma, 0.0f, 1.0f);

            // Pegtop SoftLight Blend formula: (1 - 2*b)*a^2 + 2*b*a
            float outR = pegtopBlend(clarityLuma, dyeColor[0]);
            float outG = pegtopBlend(clarityLuma, dyeColor[1]);
            float outB = pegtopBlend(clarityLuma, dyeColor[2]);

            // Alpha composite with original pixel
            float alpha = m * dyeIntensity;
            dstRgba[i * 4 + 0] = static_cast<uint8_t>(std::clamp((srcRgba[i * 4 + 0] * (1.0f - alpha) + outR * 255.0f * alpha), 0.0f, 255.0f));
            dstRgba[i * 4 + 1] = static_cast<uint8_t>(std::clamp((srcRgba[i * 4 + 1] * (1.0f - alpha) + outG * 255.0f * alpha), 0.0f, 255.0f));
            dstRgba[i * 4 + 2] = static_cast<uint8_t>(std::clamp((srcRgba[i * 4 + 2] * (1.0f - alpha) + outB * 255.0f * alpha), 0.0f, 255.0f));
            dstRgba[i * 4 + 3] = srcRgba[i * 4 + 3];
        }
    }

private:
    static float pegtopBlend(float a, float b) {
        return (1.0f - 2.0f * b) * a * a + 2.0f * b * a;
    }

    static void apply1DGaussian(const float* in, float* out, int w, int h, bool horizontal) {
        const float* k = GaussianWeights::weights;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                float val = in[y * w + x] * k[0];
                for (int step = 1; step < 5; ++step) {
                    int nx = horizontal ? std::clamp(x + step, 0, w - 1) : x;
                    int ny = horizontal ? y : std::clamp(y + step, 0, h - 1);
                    int px = horizontal ? std::clamp(x - step, 0, w - 1) : x;
                    int py = horizontal ? y : std::clamp(y - step, 0, h - 1);
                    val += in[ny * w + nx] * k[step];
                    val += in[py * w + px] * k[step];
                }
                out[y * w + x] = val;
            }
        }
    }
};

} // namespace hair
} // namespace convert2

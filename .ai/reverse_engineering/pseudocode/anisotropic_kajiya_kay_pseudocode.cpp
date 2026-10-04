// SOURCE: Clean-Room C++ Reconstruction from libMTFilterKernel.so (0x0009d180)
// Reconstructed for Project CONVERT2 — Hair Color Engine

#include <cmath>
#include <algorithm>
#include <cstdint>

namespace convert2 {
namespace hair {

struct Vec3 {
    float x, y, z;
    Vec3(float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f) : x(x_), y(y_), z(z_) {}
    
    inline Vec3 normalize() const {
        float len = std::sqrt(x * x + y * y + z * z);
        if (len > 1e-6f) {
            float inv = 1.0f / len;
            return Vec3(x * inv, y * inv, z * inv);
        }
        return Vec3(0.0f, 0.0f, 1.0f);
    }
    
    inline float dot(const Vec3& o) const {
        return x * o.x + y * o.y + z * o.z;
    }
};

class AnisotropicHairSpecularPass {
public:
    static void ComputeSpecularHighlights(
        const uint8_t* baseDyedRgb,
        const float* tangentMapX,
        const float* tangentMapY,
        const float* hairMask,
        int width,
        int height,
        float shineIntensity,
        const Vec3& lightDir,
        const Vec3& dyeColorRgb,
        uint8_t* outRgb
    ) {
        Vec3 L = lightDir.normalize();
        Vec3 V(0.0f, 0.0f, 1.0f); // Default camera viewing forward

        for (int i = 0; i < width * height; ++i) {
            float mask = hairMask[i];
            int idx = i * 3;
            if (mask < 0.005f) {
                outRgb[idx]     = baseDyedRgb[idx];
                outRgb[idx + 1] = baseDyedRgb[idx + 1];
                outRgb[idx + 2] = baseDyedRgb[idx + 2];
                continue;
            }

            // Tangent along hair stream
            float tx = -tangentMapY[i];
            float ty =  tangentMapX[i];
            Vec3 T = Vec3(tx, ty, 0.15f).normalize();

            float dotTL = T.dot(L);
            float dotTV = T.dot(V);
            float sinTL = std::sqrt(std::max(0.0f, 1.0f - dotTL * dotTL));
            float sinTV = std::sqrt(std::max(0.0f, 1.0f - dotTV * dotTV));

            // Primary R Lobe
            float specR = std::max(0.0f, sinTL * sinTV - dotTL * dotTV);
            specR = std::pow(specR, 48.0f) * 0.75f;

            // Secondary TRT Lobe with tilt
            float shiftTV = dotTV + 0.12f;
            float sinShiftTV = std::sqrt(std::max(0.0f, 1.0f - shiftTV * shiftTV));
            float specTRT = std::max(0.0f, sinTL * sinShiftTV - dotTL * shiftTV);
            specTRT = std::pow(specTRT, 20.0f) * 0.45f;

            // Base luminance protection
            float lum = (baseDyedRgb[idx] * 0.299f + baseDyedRgb[idx + 1] * 0.587f + baseDyedRgb[idx + 2] * 0.114f) / 255.0f;
            float lumFactor = std::sqrt(lum) * shineIntensity * mask;

            float rAdd = (specR + specTRT * dyeColorRgb.x) * lumFactor * 255.0f;
            float gAdd = (specR + specTRT * dyeColorRgb.y) * lumFactor * 255.0f;
            float bAdd = (specR + specTRT * dyeColorRgb.z) * lumFactor * 255.0f;

            outRgb[idx]     = static_cast<uint8_t>(std::min(255.0f, baseDyedRgb[idx]     + rAdd));
            outRgb[idx + 1] = static_cast<uint8_t>(std::min(255.0f, baseDyedRgb[idx + 1] + gAdd));
            outRgb[idx + 2] = static_cast<uint8_t>(std::min(255.0f, baseDyedRgb[idx + 2] + bAdd));
        }
    }
};

} // namespace hair
} // namespace convert2

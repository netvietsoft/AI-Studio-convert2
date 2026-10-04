// CONVERT2 CLEAN-ROOM RECONSTRUCTION: ColorSpace Convert Lab
// SOURCE: libPVGColorFunctions.so (offset: 0x0002b284)
// STATUS: LEVEL_5_REIMPLEMENTABLE
#include <cmath>

void convertToLab(float r, float g, float b, float* outL, float* outA, float* outB) {
    // 1. Inverse sRGB gamma to linear RGB
    auto toLinear = [](float c) {
        return (c > 0.04045f) ? std::pow((c + 0.055f) / 1.055f, 2.4f) : (c / 12.92f);
    };
    float lr = toLinear(r);
    float lg = toLinear(g);
    float lb = toLinear(b);

    // 2. Matrix multiplication to D65 XYZ
    float x = lr * 0.4124564f + lg * 0.3575761f + lb * 0.1804375f;
    float y = lr * 0.2126729f + lg * 0.7151522f + lb * 0.0721750f;
    float z = lr * 0.0193339f + lg * 0.1191920f + lb * 0.9503041f;

    // 3. Normalize to D65 reference white
    x /= 0.95047f;
    y /= 1.00000f;
    z /= 1.08883f;

    // 4. Non-linear cubic root transform
    auto fxyz = [](float t) {
        return (t > 0.008856f) ? std::cbrt(t) : (7.787f * t + 16.0f / 116.0f);
    };
    float fx = fxyz(x);
    float fy = fxyz(y);
    float fz = fxyz(z);

    *outL = (116.0f * fy) - 16.0f;
    *outA = 500.0f * (fx - fy);
    *outB = 200.0f * (fy - fz);
}

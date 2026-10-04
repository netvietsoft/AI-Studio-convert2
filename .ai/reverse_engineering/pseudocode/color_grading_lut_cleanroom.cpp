// Clean-Room Reimplementation of 3D LUT Color Grading & NEON HSL Vector
// Source Reference: libMTFilterKernel.so (0x000cb920) & libPVGColorFunctions.so (0x00018df0)
// Developed for CONVERT2 Engine under Development Workspace Standard V2.1.2

#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint>

namespace convert2 {
namespace color {

class CleanRoomColorGradingEngine {
public:
    // Tetrahedral Simplex 3D LUT Interpolation
    static void sample3DLutTetrahedral(
        const float* lutData, // 64 x 64 x 64 x 3
        int lutDim,
        float r, float g, float b,
        float outColor[3])
    {
        float scale = static_cast<float>(lutDim - 1);
        float rVal = std::clamp(r, 0.0f, 1.0f) * scale;
        float gVal = std::clamp(g, 0.0f, 1.0f) * scale;
        float bVal = std::clamp(b, 0.0f, 1.0f) * scale;

        int r0 = static_cast<int>(rVal);
        int g0 = static_cast<int>(gVal);
        int b0 = static_cast<int>(bVal);
        int r1 = std::min(r0 + 1, lutDim - 1);
        int g1 = std::min(g0 + 1, lutDim - 1);
        int b1 = std::min(b0 + 1, lutDim - 1);

        float dr = rVal - r0;
        float dg = gVal - g0;
        float db = bVal - b0;

        auto getLut = [&](int ir, int ig, int ib, int c) -> float {
            return lutData[((ib * lutDim + ig) * lutDim + ir) * 3 + c];
        };

        // Tetrahedral partition logic
        for (int c = 0; c < 3; ++c) {
            float c000 = getLut(r0, g0, b0, c);
            float c111 = getLut(r1, g1, b1, c);
            if (dr >= dg && dg >= db) {
                float c100 = getLut(r1, g0, b0, c);
                float c110 = getLut(r1, g1, b0, c);
                outColor[c] = (1.0f - dr) * c000 + (dr - dg) * c100 + (dg - db) * c110 + db * c111;
            } else if (dr >= db && db >= dg) {
                float c100 = getLut(r1, g0, b0, c);
                float c101 = getLut(r1, g0, b1, c);
                outColor[c] = (1.0f - dr) * c000 + (dr - db) * c100 + (db - dg) * c101 + dg * c111;
            } else if (dg >= dr && dr >= db) {
                float c010 = getLut(r0, g1, b0, c);
                float c110 = getLut(r1, g1, b0, c);
                outColor[c] = (1.0f - dg) * c000 + (dg - dr) * c010 + (dr - db) * c110 + db * c111;
            } else if (dg >= db && db >= dr) {
                float c010 = getLut(r0, g1, b0, c);
                float c011 = getLut(r0, g1, b1, c);
                outColor[c] = (1.0f - dg) * c000 + (dg - db) * c010 + (db - dr) * c011 + dr * c111;
            } else if (db >= dr && dr >= dg) {
                float c001 = getLut(r0, g0, b1, c);
                float c101 = getLut(r1, g0, b1, c);
                outColor[c] = (1.0f - db) * c000 + (db - dr) * c001 + (dr - dg) * c101 + dg * c111;
            } else {
                float c001 = getLut(r0, g0, b1, c);
                float c011 = getLut(r0, g1, b1, c);
                outColor[c] = (1.0f - db) * c000 + (db - dg) * c001 + (dg - dr) * c011 + dr * c111;
            }
        }
    }
};

} // namespace color
} // namespace convert2

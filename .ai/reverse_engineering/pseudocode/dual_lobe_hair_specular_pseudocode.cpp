// dual_lobe_hair_specular_pseudocode.cpp — TRIỂN KHAI PHÒNG SẠCH C++ ÁNH KIM LỌN TÓC ĐA THÙY
// Thẩm quyền: Chủ tịch Tony (Chairman)
// Tiêu chuẩn Vận hành: 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD & Development Workspace Standard V2.1
// Quy chuẩn Pháp lý: RULE 11 CLEAN-ROOM SPECIFICATION (100% C++ Tái Dựng Độc Lập)

#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint>

namespace meitu::reborn::hair {

struct Vec3 {
    float x, y, z;
    float Dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
};

struct StrandSpecularParams {
    float alphaR = 0.05236f;       // Cuticle tilt R (+3.0 deg)
    float alphaTRT = -0.10472f;    // Cuticle tilt TRT (-6.0 deg)
    float roughnessR = 0.08f;      // Longitudinal roughness R
    float roughnessTRT = 0.16f;    // Longitudinal roughness TRT
    float weightR = 0.35f;         // Surface white specular
    float weightTRT = 0.65f;       // Internal dye-accent sheen
    Vec3 dyeAccent = { 0.95f, 0.82f, 0.60f }; // Warm blonde / accent
};

class DualLobeHairShader {
public:
    static void ComputeDualLobeSpecular(
        const float* tangentFlowField, // 2 floats per pixel: (cos, sin)
        const uint8_t* hairMask,       // 1 byte per pixel: [0..255]
        const float* shineMap,         // 1 float per pixel: [0..1]
        int width, int height,
        const Vec3& lightDir,
        const Vec3& viewDir,
        const StrandSpecularParams& params,
        float* outHighlightRgb         // 3 floats per pixel: (R, G, B)
    ) {
        int totalPixels = width * height;

        #pragma omp parallel for schedule(static)
        for (int p = 0; p < totalPixels; ++p) {
            uint8_t m = hairMask[p];
            if (m == 0) {
                outHighlightRgb[p * 3 + 0] = 0.0f;
                outHighlightRgb[p * 3 + 1] = 0.0f;
                outHighlightRgb[p * 3 + 2] = 0.0f;
                continue;
            }

            float maskNorm = static_cast<float>(m) / 255.0f;
            float tx = tangentFlowField[p * 2 + 0];
            float ty = tangentFlowField[p * 2 + 1];
            Vec3 tangent = { tx, ty, 0.0f };

            float sinThetaI = tangent.Dot(lightDir);
            float sinThetaR = tangent.Dot(viewDir);

            float thetaI = std::asin(std::clamp(sinThetaI, -1.0f, 1.0f));
            float thetaR = std::asin(std::clamp(sinThetaR, -1.0f, 1.0f));

            float thetaH = 0.5f * (thetaR + thetaI);

            // Thùy 1: R Surface Specular
            float dR = thetaH - params.alphaR;
            float sR = std::exp(- (dR * dR) / (2.0f * params.roughnessR * params.roughnessR));

            // Thùy 2: TRT Colored Internal Specular
            float dTRT = thetaH - params.alphaTRT;
            float sTRT = std::exp(- (dTRT * dTRT) / (2.0f * params.roughnessTRT * params.roughnessTRT));

            float shine = shineMap ? shineMap[p] : 1.0f;
            float scale = maskNorm * shine;

            float lightR = sR * params.weightR;
            float lightTRT = sTRT * params.weightTRT;

            outHighlightRgb[p * 3 + 0] = (lightR + lightTRT * params.dyeAccent.x) * scale;
            outHighlightRgb[p * 3 + 1] = (lightR + lightTRT * params.dyeAccent.y) * scale;
            outHighlightRgb[p * 3 + 2] = (lightR + lightTRT * params.dyeAccent.z) * scale;
        }
    }
};

} // namespace meitu::reborn::hair

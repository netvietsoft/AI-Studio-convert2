#version 300 es
precision highp float;

// GLSL DUAL-LOBE STRAND SPECULAR SHADER (CLEAN-ROOM RULE 11)
// Thẩm quyền: Chủ tịch Tony (Chairman)
// Phân hệ: Core C++ Native Image Engine / Hair Strand Shading
// Thư viện tham chiếu: libLayerFlow.so (0x0007b420), libMTFilterKernel.so

in vec2 v_TexCoord;
out vec4 FragColor;

uniform sampler2D u_MainTexture;       // Texture tóc đã nhuộm màu nền
uniform sampler2D u_FlowTexture;       // Vector tiếp tuyến dòng sợi tóc (RG = cos(theta), sin(theta))
uniform sampler2D u_MaskTexture;       // Mặt nạ phân đoạn tóc (Kênh R)
uniform sampler2D u_ShineTexture;      // Bản đồ độ bóng bề mặt

uniform vec3 u_LightDir;               // Hướng ánh sáng tới nguồn sáng chính (chuẩn hóa)
uniform vec3 u_ViewDir;                // Hướng mắt nhìn camera (chuẩn hóa)
uniform vec3 u_DyeAccentColor;         // Màu điểm xuyết ánh kim của thuốc nhuộm
uniform float u_RoughnessR;            // Độ nhám thùy R (mặc định 0.08)
uniform float u_RoughnessTRT;          // Độ nhám thùy TRT (mặc định 0.16)
uniform float u_SpecularWeightR;       // Trọng số thùy phản xạ bề mặt
uniform float u_SpecularWeightTRT;     // Trọng số thùy phản xạ nội vùng

const float PI = 3.14159265359;
const float ALPHA_R = 0.05236;         // Lệch biểu bì R: +3.0 độ (radian)
const float ALPHA_TRT = -0.10472;      // Lệch biểu bì TRT: -6.0 độ (radian)

void main() {
    vec4 baseColor = texture(u_MainTexture, v_TexCoord);
    float mask = texture(u_MaskTexture, v_TexCoord).r;
    
    // Nếu nằm ngoài mặt nạ tóc, giữ nguyên 100% không tác động (Zero Leakage)
    if (mask <= 0.001) {
        FragColor = baseColor;
        return;
    }

    vec2 flow = texture(u_FlowTexture, v_TexCoord).rg;
    vec3 tangent = normalize(vec3(flow.x, flow.y, 0.0));

    // Tính toán góc nghiêng dọc trục sợi tóc
    float sinThetaI = dot(tangent, u_LightDir);
    float cosThetaI = sqrt(max(0.0, 1.0 - sinThetaI * sinThetaI));

    float sinThetaR = dot(tangent, u_ViewDir);
    float cosThetaR = sqrt(max(0.0, 1.0 - sinThetaR * sinThetaR));

    float thetaD = 0.5 * (asin(clamp(sinThetaR, -1.0, 1.0)) - asin(clamp(sinThetaI, -1.0, 1.0)));
    float thetaH = 0.5 * (asin(clamp(sinThetaR, -1.0, 1.0)) + asin(clamp(sinThetaI, -1.0, 1.0)));

    // Thùy 1: Phản xạ ngoài biểu bì R (Ánh sáng trắng)
    float deltaR = thetaH - ALPHA_R;
    float specR = exp(- (deltaR * deltaR) / (2.0 * u_RoughnessR * u_RoughnessR));

    // Thùy 2: Phản xạ nội vùng lõi sợi TRT (Ánh kim màu thuốc nhuộm)
    float deltaTRT = thetaH - ALPHA_TRT;
    float specTRT = exp(- (deltaTRT * deltaTRT) / (2.0 * u_RoughnessTRT * u_RoughnessTRT));

    // Lấy hệ số bóng cục bộ
    float shineMod = texture(u_ShineTexture, v_TexCoord).r;

    // Tổng hợp ánh sáng điểm xuyết (Spec Highlight)
    vec3 lightR = vec3(1.0) * specR * u_SpecularWeightR;
    vec3 lightTRT = u_DyeAccentColor * specTRT * u_SpecularWeightTRT;
    vec3 totalHighlight = (lightR + lightTRT) * shineMod * mask;

    vec3 finalRgb = baseColor.rgb + totalHighlight;
    FragColor = vec4(finalRgb, baseColor.a);
}

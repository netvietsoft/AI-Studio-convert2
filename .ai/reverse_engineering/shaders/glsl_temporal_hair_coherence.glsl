#version 300 es
precision highp float;

// GLSL TEMPORAL HAIR COHERENCE SHADER (CLEAN-ROOM RULE 11)
// Thẩm quyền: Chủ tịch Tony (Chairman)
// Phân hệ: Core C++ Native Video/Image Engine / Anti-Flicker
// Thư viện tham chiếu: libffmpegfilter.so (0x00098200), libMTFilterKernel.so

in vec2 v_TexCoord;
out vec4 FragColor;

uniform sampler2D u_CurrentFrame;      // Khung hình hiện tại (t)
uniform sampler2D u_HistoryFrame;      // Khung hình tích lũy trước đó (t-1)
uniform sampler2D u_OpticalFlow;       // Vector dòng quang học (RG = deltaU, deltaV tính bằng pixel)
uniform vec2 u_ScreenResolution;       // Độ phân giải khung hình (width, height)
uniform float u_FeedbackAlpha;         // Trọng số hòa trộn quá khứ [0.10, 0.30]

void main() {
    vec2 invRes = 1.0 / u_ScreenResolution;
    vec4 currentCenter = texture(u_CurrentFrame, v_TexCoord);

    // 1. Quét lân cận 3x3 trong khung hình hiện tại để tìm hộp bao màu (Color Box)
    vec3 cMin = currentCenter.rgb;
    vec3 cMax = currentCenter.rgb;

    for (int y = -1; y <= 1; ++y) {
        for (int x = -1; x <= 1; ++x) {
            vec3 neighbor = texture(u_CurrentFrame, v_TexCoord + vec2(float(x), float(y)) * invRes).rgb;
            cMin = min(cMin, neighbor);
            cMax = max(cMax, neighbor);
        }
    }

    // 2. Tái lấy mẫu khung hình trước bằng vector dòng quang học
    vec2 flow = texture(u_OpticalFlow, v_TexCoord).rg;
    vec2 historyUv = v_TexCoord - (flow * invRes);
    vec4 historySample = texture(u_HistoryFrame, historyUv);

    // 3. Kẹp giá trị lịch sử vào hộp bao lân cận 3x3 để triệt tiêu bóng ma (Ghosting)
    vec3 clampedHistory = clamp(historySample.rgb, cMin, cMax);

    // 4. Hòa trộn tích lũy mượt mà
    vec3 stabilizedRgb = mix(clampedHistory, currentCenter.rgb, u_FeedbackAlpha);

    FragColor = vec4(stabilizedRgb, currentCenter.a);
}

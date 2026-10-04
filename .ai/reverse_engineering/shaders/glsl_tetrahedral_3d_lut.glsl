#version 300 es
precision highp float;

// GLSL TETRAHEDRAL 3D LUT INTERPOLATION SHADER (CLEAN-ROOM RULE 11)
// Thẩm quyền: Chủ tịch Tony (Chairman)
// Phân hệ: Core C++ Native Image Engine / Color Grading
// Thư viện tham chiếu: libPVGColorFunctions.so (0x00011400)

in vec2 v_TexCoord;
out vec4 FragColor;

uniform sampler2D u_MainTexture;       // Texture khung hình tóc đã nhuộm cơ bản (RGBA8)
uniform sampler3D u_Lut3DTexture;      // Bảng tra màu 3D LUT 33x33x33 (RGBA16F hoặc RGBA8)
uniform float u_LutSize;               // Kích thước cạnh khối lập phương (33.0)
uniform float u_Intensity;             // Cường độ hòa trộn LUT [0.0, 1.0]

vec3 sampleLutTetrahedral(vec3 color) {
    vec3 clampedColor = clamp(color, 0.0, 1.0);
    vec3 coord = clampedColor * (u_LutSize - 1.0);
    vec3 baseIndex = floor(coord);
    vec3 delta = coord - baseIndex;
    
    // Tọa độ chuẩn hóa cho phép truy cập texture3D
    float invSize = 1.0 / u_LutSize;
    float halfPixel = 0.5 * invSize;
    
    #define GET_LUT(dx, dy, dz) texture(u_Lut3DTexture, ((baseIndex + vec3(dx, dy, dz)) * invSize) + halfPixel).rgb

    vec3 c000 = GET_LUT(0.0, 0.0, 0.0);
    vec3 c111 = GET_LUT(1.0, 1.0, 1.0);
    vec3 result = c000;

    // Phân rã 6 khối tứ diện theo thứ tự sắp xếp của delta
    if (delta.r >= delta.g) {
        if (delta.g >= delta.b) {
            // Case 1: dr >= dg >= db
            vec3 c100 = GET_LUT(1.0, 0.0, 0.0);
            vec3 c110 = GET_LUT(1.0, 1.0, 0.0);
            result = (1.0 - delta.r) * c000 + (delta.r - delta.g) * c100 + (delta.g - delta.b) * c110 + delta.b * c111;
        } else if (delta.r >= delta.b) {
            // Case 2: dr >= db > dg
            vec3 c100 = GET_LUT(1.0, 0.0, 0.0);
            vec3 c101 = GET_LUT(1.0, 0.0, 1.0);
            result = (1.0 - delta.r) * c000 + (delta.r - delta.b) * c100 + (delta.b - delta.g) * c101 + delta.g * c111;
        } else {
            // Case 5: db > dr >= dg
            vec3 c001 = GET_LUT(0.0, 0.0, 1.0);
            vec3 c101 = GET_LUT(1.0, 0.0, 1.0);
            result = (1.0 - delta.b) * c000 + (delta.b - delta.r) * c001 + (delta.r - delta.g) * c101 + delta.g * c111;
        }
    } else {
        if (delta.r >= delta.b) {
            // Case 3: dg > dr >= db
            vec3 c010 = GET_LUT(0.0, 1.0, 0.0);
            vec3 c110 = GET_LUT(1.0, 1.0, 0.0);
            result = (1.0 - delta.g) * c000 + (delta.g - delta.r) * c010 + (delta.r - delta.b) * c110 + delta.b * c111;
        } else if (delta.g >= delta.b) {
            // Case 4: dg >= db > dr
            vec3 c010 = GET_LUT(0.0, 1.0, 0.0);
            vec3 c011 = GET_LUT(0.0, 1.0, 1.0);
            result = (1.0 - delta.g) * c000 + (delta.g - delta.b) * c010 + (delta.b - delta.r) * c011 + delta.r * c111;
        } else {
            // Case 6: db > dg > dr
            vec3 c001 = GET_LUT(0.0, 0.0, 1.0);
            vec3 c011 = GET_LUT(0.0, 1.0, 1.0);
            result = (1.0 - delta.b) * c000 + (delta.b - delta.g) * c001 + (delta.g - delta.r) * c011 + delta.r * c111;
        }
    }

    #undef GET_LUT
    return result;
}

void main() {
    vec4 orig = texture(u_MainTexture, v_TexCoord);
    vec3 graded = sampleLutTetrahedral(orig.rgb);
    vec3 finalColor = mix(orig.rgb, graded, u_Intensity);
    FragColor = vec4(finalColor, orig.a);
}

#version 300 es
precision mediump float;
in vec2 v_TexCoord;
out vec4 fragColor;

uniform sampler2D u_BaseTexture; // Texture sau khi qua 21-tap LIC
uniform sampler2D u_DyePalette;  // Bản đồ màu nhuộm (LUT hoặc RGBA)
uniform float u_BlendIntensity;  // Hệ số hòa trộn [0.0, 1.0]

float pegtopSoftLightChannel(float a, float b) {
    if (b < 0.5) {
        return 2.0 * a * b + a * a * (1.0 - 2.0 * b);
    } else {
        return 2.0 * a * (1.0 - b) + sqrt(a) * (2.0 * b - 1.0);
    }
}

vec3 pegtopSoftLight(vec3 a, vec3 b) {
    return vec3(
        pegtopSoftLightChannel(a.r, b.r),
        pegtopSoftLightChannel(a.g, b.g),
        pegtopSoftLightChannel(a.b, b.b)
    );
}

void main() {
    vec4 baseCol = texture(u_BaseTexture, v_TexCoord);
    vec4 dyeCol = texture(u_DyePalette, v_TexCoord);
    vec3 blended = pegtopSoftLight(baseCol.rgb, dyeCol.rgb);
    vec3 finalRgb = mix(baseCol.rgb, blended, u_BlendIntensity);
    fragColor = vec4(finalRgb, baseCol.a);
}

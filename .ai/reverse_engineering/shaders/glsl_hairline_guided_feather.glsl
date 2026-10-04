// GLSL: glsl_hairline_guided_feather.glsl
// Clean-Room Hairline Soft Feathering & Zero Leakage Shading
// Authority: Chairman Tony & Project CONVERT2

precision highp float;

varying vec2 v_texCoord;

uniform sampler2D u_hairMask;      // Raw BiSeNet hair mask
uniform sampler2D u_skinMask;      // Face skin mask
uniform sampler2D u_guideTexture;  // Luminance guide image
uniform vec2      u_texelSize;     // 1.0 / vec2(width, height)
uniform float     u_featherRadius; // Feathering radius in pixels

void main() {
    float rawHair = texture2D(u_hairMask, v_texCoord).r;
    float rawSkin = texture2D(u_skinMask, v_texCoord).r;

    // Hard skin protection threshold
    if (rawSkin > 0.65) {
        gl_FragColor = vec4(0.0);
        return;
    }

    // 5-tap cross-filter for boundary alpha smoothing
    float sumHair = rawHair * 0.40;
    sumHair += texture2D(u_hairMask, v_texCoord + vec2( u_texelSize.x, 0.0) * u_featherRadius).r * 0.15;
    sumHair += texture2D(u_hairMask, v_texCoord + vec2(-u_texelSize.x, 0.0) * u_featherRadius).r * 0.15;
    sumHair += texture2D(u_hairMask, v_texCoord + vec2(0.0,  u_texelSize.y) * u_featherRadius).r * 0.15;
    sumHair += texture2D(u_hairMask, v_texCoord + vec2(0.0, -u_texelSize.y) * u_featherRadius).r * 0.15;

    // Modulate transition against skin boundary
    float skinSuppression = clamp(1.0 - smoothstep(0.1, 0.5, rawSkin), 0.0, 1.0);
    float finalAlpha = clamp(sumHair * skinSuppression, 0.0, 1.0);

    gl_FragColor = vec4(finalAlpha, finalAlpha, finalAlpha, 1.0);
}

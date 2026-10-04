// GLSL: glsl_anisotropic_kajiya_kay.glsl
// Clean-Room reconstruction of Anisotropic Hair Specular Shader
// Authority: Chairman Tony & Project CONVERT2

precision highp float;

varying vec2 v_texCoord;

uniform sampler2D u_inputTexture;    // Base dyed hair texture
uniform sampler2D u_tangentTexture;  // Tangent flow field (cos phi, sin phi)
uniform sampler2D u_hairMaskTexture; // Hair boundary alpha mask

uniform vec3  u_lightDir;           // Normalized light vector (e.g. normalize(vec3(0.2, 0.4, 0.9)))
uniform vec3  u_viewDir;            // View vector (default vec3(0.0, 0.0, 1.0))
uniform vec4  u_specularColor;      // Dye tint specular color (TRT lobe)
uniform float u_shineIntensity;     // UI slider intensity [0.0, 1.0]

void main() {
    vec4 baseColor = texture2D(u_inputTexture, v_texCoord);
    float mask = texture2D(u_hairMaskTexture, v_texCoord).r;

    if (mask <= 0.001) {
        gl_FragColor = baseColor;
        return;
    }

    // Decode 2D tangent vector from flow field
    vec2 flow = texture2D(u_tangentTexture, v_texCoord).xy;
    vec3 T = normalize(vec3(-flow.y, flow.x, 0.15)); // 3D tangent vector along hair strand

    // Kajiya-Kay specular terms
    float dotTL = dot(T, u_lightDir);
    float dotTV = dot(T, u_viewDir);
    float sinTL = sqrt(max(0.0, 1.0 - dotTL * dotTL));
    float sinTV = sqrt(max(0.0, 1.0 - dotTV * dotTV));

    // Primary R lobe (neutral white highlight)
    float specR = max(0.0, sinTL * sinTV - dotTL * dotTV);
    specR = pow(specR, 48.0) * 0.75;

    // Secondary TRT lobe (tinted by dye color)
    float shiftTV = dotTV + 0.12; // Shift towards hair tip
    float sinShiftTV = sqrt(max(0.0, 1.0 - shiftTV * shiftTV));
    float specTRT = max(0.0, sinTL * sinShiftTV - dotTL * shiftTV);
    specTRT = pow(specTRT, 20.0) * 0.45;

    // Composite specular components
    vec3 specTotal = (vec3(specR) + specTRT * u_specularColor.rgb) * u_shineIntensity;

    // Modulate by luminance to protect shadow regions
    float lum = dot(baseColor.rgb, vec3(0.299, 0.587, 0.114));
    specTotal *= sqrt(lum);

    vec3 finalRgb = baseColor.rgb + specTotal * mask;
    gl_FragColor = vec4(clamp(finalRgb, 0.0, 1.0), baseColor.a);
}

#version 300 es
precision mediump float;
in vec2 v_TexCoord;
out vec4 fragColor;

uniform sampler2D u_Texture;
uniform float u_DesatIntensity; // [0.0, 1.0]

const vec3 LUMINANCE_WEIGHTS = vec3(0.299, 0.587, 0.114);

void main() {
    vec4 src = texture(u_Texture, v_TexCoord);
    float lum = dot(src.rgb, LUMINANCE_WEIGHTS);
    vec3 neutral = mix(src.rgb, vec3(lum), u_DesatIntensity);
    fragColor = vec4(neutral, src.a);
}

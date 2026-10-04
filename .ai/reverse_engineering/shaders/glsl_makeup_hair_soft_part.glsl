#version 300 es
precision mediump float;
in vec2 v_TexCoord;
out vec4 fragColor;

uniform sampler2D u_HairResult;
uniform sampler2D u_FaceSkinResult;
uniform sampler2D u_HairMaskSDF;
uniform float u_InnerRadius;
uniform float u_OuterRadius;

void main() {
    float dist = texture(u_HairMaskSDF, v_TexCoord).r;
    float alpha = smoothstep(u_InnerRadius, u_OuterRadius, dist);
    
    vec4 hairCol = texture(u_HairResult, v_TexCoord);
    vec4 faceCol = texture(u_FaceSkinResult, v_TexCoord);
    
    fragColor = mix(faceCol, hairCol, alpha);
}

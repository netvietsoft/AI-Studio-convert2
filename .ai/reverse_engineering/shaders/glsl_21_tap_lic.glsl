// SOURCE: libLayerFlow.so (offset 0x00024880)
// PURPOSE: 21-Tap Symmetric Line Integral Convolution along strand tangent
precision mediump float;
uniform sampler2D u_noiseOrShineTexture;
uniform sampler2D u_orientationTexture; // Stores angle theta
varying vec2 v_texCoord;

const int NUM_STEPS = 10;
const float STEP_SIZE = 1.0 / 1024.0;

void main() {
    float theta = texture2D(u_orientationTexture, v_texCoord).r * 3.14159265;
    vec2 dir = vec2(-sin(theta), cos(theta));
    vec4 accum = vec4(0.0);
    float weightSum = 0.0;
    
    for (int i = -NUM_STEPS; i <= NUM_STEPS; ++i) {
        float fi = float(i);
        vec2 offset = dir * (fi * STEP_SIZE);
        float w = 1.0 - abs(fi) / float(NUM_STEPS + 1);
        accum += texture2D(u_noiseOrShineTexture, v_texCoord + offset) * w;
        weightSum += w;
    }
    gl_FragColor = accum / weightSum;
}

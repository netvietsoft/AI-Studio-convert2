// SOURCE: libMTFilterKernel.so (offset 0x77afa)
// PURPOSE: 9x9 Unsharp Mask Clarity Boost with 0.4 intensity and 1.8 luma boost
precision mediump float;
uniform sampler2D u_inputTexture;
uniform sampler2D u_blurTexture;
uniform vec2 u_stepOffset; // Step size 2.3 / resolution
uniform float u_clarity;   // Constant 0.4
uniform float u_boost;     // Constant 1.8
varying vec2 v_texCoord;

void main() {
    vec4 orig = texture2D(u_inputTexture, v_texCoord);
    vec4 blur = texture2D(u_blurTexture, v_texCoord);
    vec4 highPass = orig - blur;
    vec4 sharp = orig + highPass * u_clarity * u_boost;
    gl_FragColor = clamp(sharp, 0.0, 1.0);
}

// SOURCE: libPVGColorFunctions.so (offset 0x11170)
// PURPOSE: 3D LUT Color Transfer Frag Shader
precision mediump float;
uniform sampler2D u_inputTexture;
uniform sampler3D u_lutTexture;
uniform float u_intensity;
varying vec2 v_texCoord;

void main() {
    vec4 srcColor = texture2D(u_inputTexture, v_texCoord);
    vec3 lutColor = texture3D(u_lutTexture, srcColor.rgb).rgb;
    vec3 finalRgb = mix(srcColor.rgb, lutColor, u_intensity);
    gl_FragColor = vec4(finalRgb, srcColor.a);
}

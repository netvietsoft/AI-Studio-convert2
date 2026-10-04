// Reconstructed Pseudocode for libMTFilterKernel_fn_000fd3d8 (_ZN14MTFilterKernel18MTDarkCornerFilter4initEPNS_15GPUImageContextE)
// Library: libMTFilterKernel.so | RVA: 0x000fd3d8 | Size: 344 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'varying highp vec2 textureCoordinate; uniform sampler2D inputImageTexture; uniform sampler2D inputImageTexture1; uniform sampler2D inputImageTexture2; uniform sampler2D inputImageTexture3; uniform float alpha; void main() { vec4 orgColor = texture2D(inputImageTexture, textureCoordinate); vec4 tempColor = orgColor; vec4 temp = texture2D(inputImageTexture2, textureCoordinate); orgColor.r = texture2D(inputImageTexture3, vec2(temp.r, orgColor.r)).r; orgColor.g = texture2D(inputImageTexture3, vec2(temp.g, orgColor.g)).g; orgColor.b = texture2D(inputImageTexture3, vec2(temp.b, orgColor.b)).b; orgColor = mix(tempColor, orgColor, alpha); gl_FragColor = orgColor; }'

void libMTFilterKernel_fn_000fd3d8(void* env, void* obj, ...) {
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x001021c4(...);
    call_func_0x001b42e0(...);
    call_func_0x001433e0(...);
    call_func_0x001433e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b4280(...);
    return;
}

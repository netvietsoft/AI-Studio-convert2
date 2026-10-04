// Reconstructed Pseudocode for libMTFilterKernel_fn_000dde70 (_ZN14MTFilterKernel13MTFrameFilter4initEPNS_15GPUImageContextE)
// Library: libMTFilterKernel.so | RVA: 0x000dde70 | Size: 364 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec3 position; attribute vec2 inputTextureCoordinate; attribute vec2 inputTextureCoordinate2; varying vec2 textureCoordinate; varying vec2 textureCoordinate2; void main() { gl_Position = vec4(position, 1.0); textureCoordinate = inputTextureCoordinate; textureCoordinate2 = inputTextureCoordinate2; }'
//   'uniform sampler2D inputImageTexture; uniform sampler2D inputImageTexture2; varying vec2 textureCoordinate; varying vec2 textureCoordinate2; void main() { vec4 bgc = texture2D(inputImageTexture, textureCoordinate); vec4 fgc = texture2D(inputImageTexture2, textureCoordinate2); vec4 color = vec4(0.0, 0.0, 0.0, 1.0); color.rgb = mix(bgc.rgb, fgc.rgb, fgc.a); gl_FragColor = color; }'

void libMTFilterKernel_fn_000dde70(void* env, void* obj, ...) {
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x00101f78(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b4280(...);
    return;
}

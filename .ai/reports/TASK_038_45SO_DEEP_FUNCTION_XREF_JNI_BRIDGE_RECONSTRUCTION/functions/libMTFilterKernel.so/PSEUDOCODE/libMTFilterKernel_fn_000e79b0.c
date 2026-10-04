// Reconstructed Pseudocode for libMTFilterKernel_fn_000e79b0 (_ZN14MTFilterKernel13MTScaleFilter4initEPNS_15GPUImageContextE)
// Library: libMTFilterKernel.so | RVA: 0x000e79b0 | Size: 536 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; uniform mat4 ModelView; varying vec2 textureCoordinate; void main() { gl_Position = ModelView * position; textureCoordinate = inputTextureCoordinate.xy; }'
//   'varying highp vec2 textureCoordinate; uniform sampler2D inputImageTexture; void main() { gl_FragColor = texture2D(inputImageTexture, textureCoordinate); }'

void libMTFilterKernel_fn_000e79b0(void* env, void* obj, ...) {
    call_func_0x001afc84(...);
    call_func_0x001afc58(...);
    call_func_0x001b42d0(...);
    call_func_0x001b42d0(...);
    call_func_0x00101f78(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b4280(...);
    return;
}

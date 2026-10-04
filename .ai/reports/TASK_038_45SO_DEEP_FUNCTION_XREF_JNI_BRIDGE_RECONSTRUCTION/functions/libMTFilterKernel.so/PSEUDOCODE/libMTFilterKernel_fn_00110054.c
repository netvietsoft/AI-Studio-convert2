// Reconstructed Pseudocode for libMTFilterKernel_fn_00110054 (_ZN14MTFilterKernel20MTSpliceFilterKernel4initEPNS_15GPUImageContextE)
// Library: libMTFilterKernel.so | RVA: 0x00110054 | Size: 220 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec3 position; attribute vec2 inputTextureCoordinate; attribute vec2 inputTextureCoordinate2; varying vec2 textureCoordinate; varying vec2 textureCoordinate2; void main() { gl_Position = vec4(position, 1.0); textureCoordinate = inputTextureCoordinate; textureCoordinate2 = inputTextureCoordinate2; }'
//   'varying highp vec2 textureCoordinate; varying highp vec2 textureCoordinate2; uniform sampler2D inputImageTexture; uniform sampler2D inputImageTexture2; void main() { vec4 orgColor = texture2D(inputImageTexture, textureCoordinate); vec4 tempColor = orgColor; vec4 temp = texture2D(inputImageTexture2, textureCoordinate2); tempColor = vec4(mix(orgColor.rgb, temp.rgb, temp.a),orgColor.a); gl_FragColor = tempColor; }'

void libMTFilterKernel_fn_00110054(void* env, void* obj, ...) {
    call_func_0x00101d40(...);
    call_func_0x001433e0(...);
    call_func_0x001b48b0(...);
    call_func_0x001b42d0(...);
    call_func_0x00167ea0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b4280(...);
    return;
}

// Reconstructed Pseudocode for libMTFilterKernel_fn_000e9900 (_ZN14MTFilterKernel22MTSimpleFaceMaskFilter4initEPNS_15GPUImageContextE)
// Library: libMTFilterKernel.so | RVA: 0x000e9900 | Size: 408 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec4 position; attribute vec2 inputTextureCoordinate; varying vec2 textureCoordinate; void main() { textureCoordinate = inputTextureCoordinate.xy; gl_Position = position; }'
//   'varying highp vec2 textureCoordinate; uniform sampler2D inputImageTexture; uniform highp vec2 centerValue; uniform highp vec2 ellipseValue; uniform highp float inner; uniform highp float outer; uniform float faceCount; void main() { float result = 1.0; highp float fy = textureCoordinate.y - centerValue.y; fy = fy * fy * ellipseValue.y; highp float fx = textureCoordinate.x - centerValue.x; fx = fx * fx * ellipseValue.x; highp float dist = sqrt(fx + fy); if (dist > inner) { result = 1.0 - min((dist - inner) / outer, 1.0); } vec4 color = texture2D(inputImageTexture, textureCoordinate); result = result * 1.0 + (1.0 - result) * color.r; gl_FragColor = vec4(result, 0.0, 0.0, 1.0); }'

void libMTFilterKernel_fn_000e9900(void* env, void* obj, ...) {
    call_func_0x001b42d0(...);
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

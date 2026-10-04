// Reconstructed Pseudocode for libMTFilterKernel_fn_001291e8 (_ZN14MTFilterKernel20CMTRandomNoiseFilter8InitlizeEPNS_18DynamicFilterParamEPKc)
// Library: libMTFilterKernel.so | RVA: 0x001291e8 | Size: 320 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; varying highp vec2 textureCoordinate; void main() { gl_Position = position; textureCoordinate = inputTextureCoordinate.xy; }'
//   'precision highp float; varying highp vec2 textureCoordinate; float noise(vec2 co){ return fract(sin(dot(co ,vec2(12.9898,78.233))) * 13.14); } vec2 hash(vec2 p){ p = vec2(dot(p,vec2(127.1,311.7)),dot(p,vec2(269.5,183.3))); return fract(sin(p)*161.8); } void main() { vec3 color = vec3(noise(hash(textureCoordinate))); gl_FragColor = vec4(color,1.0); }'
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; varying highp vec2 textureCoordinate; void main() { gl_Position = position; textureCoordinate = inputTextureCoordinate.xy; }'
//   'uniform sampler2D inputImageTexture; uniform sampler2D inputImageTexture2; uniform lowp float degree; varying highp vec2 textureCoordinate; void main() { highp vec3 color = texture2D(inputImageTexture, textureCoordinate).rgb; highp vec3 noise = texture2D(inputImageTexture2, textureCoordinate).rgb * 0.35 - 0.18; color = max(min((color + noise * degree), vec3(1)), vec3(0)); gl_FragColor = vec4(color, 1.0); }'

void libMTFilterKernel_fn_001291e8(void* env, void* obj, ...) {
    call_func_0x000ed3a4(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42d0(...);
    call_func_0x0011c2ac(...);
    call_func_0x000ef55c(...);
    call_func_0x001b42d0(...);
    call_func_0x0013f6cc(...);
    call_func_0x001b42d0(...);
    call_func_0x0013f6cc(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    return;
}

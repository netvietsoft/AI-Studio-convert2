// Reconstructed Pseudocode for libMTFilterKernel_fn_00118738 (_ZN14MTFilterKernel23MTFilterTwoInputMaskMix4initEPNS_15GPUImageContextE)
// Library: libMTFilterKernel.so | RVA: 0x00118738 | Size: 288 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'varying highp vec2 textureCoordinate; varying highp vec2 textureCoordinate2; uniform sampler2D inputImageTexture; uniform sampler2D inputImageTexture2; uniform sampler2D maskTexture; uniform float alpha; uniform int isMask; void main() { vec3 backgroundColor = texture2D(inputImageTexture2, textureCoordinate2).rgb; vec3 foregroundColor = texture2D(inputImageTexture, textureCoordinate).rgb; float maskAlpha = texture2D(maskTexture, textureCoordinate).r; if (isMask == 0) { gl_FragColor = vec4(foregroundColor, 1.0); } else { gl_FragColor = vec4( mix(backgroundColor, foregroundColor, alpha * maskAlpha), 1.0); } }'
//   'varying highp vec2 textureCoordinate; varying highp vec2 textureCoordinate2; uniform sampler2D inputImageTexture; uniform sampler2D inputImageTexture2; uniform sampler2D maskTexture; uniform float alpha; uniform int isMask; void main() { vec3 backgroundColor = texture2D(inputImageTexture, textureCoordinate).rgb; vec3 foregroundColor = texture2D(inputImageTexture2, textureCoordinate2).rgb; float maskAlpha = texture2D(maskTexture, textureCoordinate).r; if (isMask == 0) { gl_FragColor = vec4(foregroundColor, 1.0); } else { gl_FragColor = vec4( mix(backgroundColor, foregroundColor, alpha * maskAlpha), 1.0); } }'

void libMTFilterKernel_fn_00118738(void* env, void* obj, ...) {
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x0016a6ac(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x0016a6ac(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b4280(...);
    return;
}

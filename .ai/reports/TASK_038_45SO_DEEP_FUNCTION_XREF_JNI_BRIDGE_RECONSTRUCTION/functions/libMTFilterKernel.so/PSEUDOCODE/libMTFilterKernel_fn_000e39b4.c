// Reconstructed Pseudocode for libMTFilterKernel_fn_000e39b4 (_ZN14MTFilterKernel16MTMaterialFilter4initEPNS_15GPUImageContextE)
// Library: libMTFilterKernel.so | RVA: 0x000e39b4 | Size: 756 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec3 position; attribute vec2 inputTextureCoordinate; attribute vec2 inputTextureCoordinate2; varying vec2 textureCoordinate; varying vec2 textureCoordinate2; void main() { gl_Position = vec4(position, 1.0); textureCoordinate = inputTextureCoordinate; textureCoordinate2 = inputTextureCoordinate2; }'
//   'varying highp vec2 textureCoordinate; varying vec2 textureCoordinate2; uniform sampler2D inputImageTexture; uniform sampler2D inputImageTexture2; uniform sampler2D inputImageTexture3; uniform sampler2D maskTexture; uniform float isOutMask; uniform int type; void main() { if (type == 0) { gl_FragColor = texture2D(inputImageTexture, textureCoordinate); } else { float maskAlpha; if (isOutMask > 0.5) { maskAlpha = texture2D(maskTexture, textureCoordinate).r; } else { maskAlpha = 1.0 - texture2D(maskTexture, textureCoordinate).r; } vec4 orgColor = texture2D(inputImageTexture, textureCoordinate2); vec4 tempColor = orgColor; vec4 temp = texture2D(inputImageTexture2, textureCoordinate); tempColor.r = mix( tempColor.r, texture2D(inputImageTexture3, vec2(temp.r, tempColor.r)).r, temp.a); tempColor.g = mix( tempColor.g, texture2D(inputImageTexture3, vec2(temp.g, tempColor.g)).g, temp.a); tempColor.b = mix( tempColor.b, texture2D(inputImageTexture3, vec2(temp.b, tempColor.b)).b, temp.a); tempColor = mix(orgColor, tempColor, maskAlpha); gl_FragColor = tempColor; } }'
//   'attribute vec3 position; attribute vec2 inputTextureCoordinate; attribute vec2 inputTextureCoordinate2; varying vec2 textureCoordinate; varying vec2 textureCoordinate2; void main() { gl_Position = vec4(position, 1.0); textureCoordinate = inputTextureCoordinate; textureCoordinate2 = inputTextureCoordinate2; }'

void libMTFilterKernel_fn_000e39b4(void* env, void* obj, ...) {
    call_func_0x001433e0(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x0010c444(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001415c8(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x001b4310(...);
    call_func_0x001b42d0(...);
    call_func_0x001b43a0(...);
    call_func_0x0010c444(...);
    call_func_0x001b42b0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x000c3100(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b4280(...);
    return;
}

// Reconstructed Pseudocode for libMTFilterKernel_fn_00123644 (_ZN14MTFilterKernel14CMTBokehFilter8InitlizeEPNS_18DynamicFilterParamEPKc)
// Library: libMTFilterKernel.so | RVA: 0x00123644 | Size: 892 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; varying vec2 textureCoordinate; uniform float textureWidth; uniform float textureHeight; uniform float textureOffsetDegree; varying vec2 off5_1; varying vec2 off9_1; varying vec2 off9_2; varying vec2 off13_1; varying vec2 off13_2; varying vec2 off13_3; void main() { gl_Position = position; textureCoordinate = inputTextureCoordinate.xy; vec2 iResolution = vec2(textureOffsetDegree)/vec2(textureWidth,textureHeight); off5_1 = vec2(1.3333333333333333) * iResolution; off9_1 = vec2(1.3846153846) * iResolution; off9_2 = vec2(3.2307692308) * iResolution; off13_1 = vec2(1.411764705882353)*iResolution; off13_2 = vec2(3.2941176470588234)*iResolution; off13_3 = vec2(5.176470588235294)*iResolution; }'
//   'varying vec2 textureCoordinate; uniform sampler2D inputImageTexture; uniform sampler2D inputImageTexture2; uniform sampler2D maskTexture; uniform float alpha; void main() { vec3 srcColor = texture2D(inputImageTexture, textureCoordinate).rgb; vec3 dstColor = texture2D(inputImageTexture2, textureCoordinate).rgb; float maskAlpha = 1.0 - texture2D(maskTexture, textureCoordinate).r; vec3 result = mix(srcColor, dstColor,clamp(alpha*maskAlpha,0.0,1.0)); gl_FragColor = vec4(result,1.0); }'
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; varying highp vec2 textureCoordinate; void main() { gl_Position = position; textureCoordinate = inputTextureCoordinate.xy; }'
//   'uniform sampler2D texture; uniform sampler2D fabbyMask; uniform vec2 direction; varying vec2 textureCoordinate; varying vec2 off5_1; varying vec2 off9_1; varying vec2 off9_2; varying vec2 off13_1; varying vec2 off13_2; varying vec2 off13_3; vec4 blur13(sampler2D image, vec2 uv, vec2 dir) { vec4 color = vec4(0.0); vec2 off1 = off13_1 * dir; vec2 off2 = off13_2 * dir; vec2 off3 = off13_3 * dir; color += texture2D(image, uv) * 0.1964825501511404; color += texture2D(image, uv + (off1)) * 0.2969069646728344; color += texture2D(image, uv - (off1)) * 0.2969069646728344; color += texture2D(image, uv + (off2)) * 0.09447039785044732; color += texture2D(image, uv - (off2)) * 0.09447039785044732; color += texture2D(image, uv + (off3)) * 0.010381362401148057; color += texture2D(image, uv - (off3)) * 0.010381362401148057; return color; } vec4 blur9(sampler2D image, sampler2D mask, vec2 uv, vec2 dir) { vec4 color = vec4(0.0); vec2 off1 = off9_1 * dir; vec2 off2 = off9_2 * dir; float maskAlpha = 1.0 - texture2D(mask, uv).r; float maskSum = 0.2270270270 * maskAlpha; color += texture2D(image, uv) * 0.2270270270 * maskAlpha; maskAlpha = 1.0 - texture2D(mask, uv + (off1)).r; maskSum += 0.3162162162 * maskAlpha; color += texture2D(image, uv + (off1)) * 0.3162162162 * maskAlpha; maskAlpha = 1.0 - texture2D(mask, uv - (off1)).r; maskSum += 0.3162162162 * maskAlpha; color += texture2D(image, uv - (off1)) * 0.3162162162 * maskAlpha; maskAlpha = 1.0 - texture2D(mask, uv + (off2)).r; maskSum += 0.0702702703 * maskAlpha; color += texture2D(image, uv + (off2)) * 0.0702702703 * maskAlpha; maskAlpha = 1.0 - texture2D(mask, uv - (off2)).r; maskSum += 0.0702702703 * maskAlpha; color += texture2D(image, uv - (off2)) * 0.0702702703 * maskAlpha; return color / maskSum; } vec4 blur5(sampler2D image, vec2 uv, vec2 dir) { vec4 color = vec4(0.0); vec2 off1 = off5_1 * dir; color += texture2D(image, uv) * 0.29411764705882354; color += texture2D(image, uv + (off1)) * 0.35294117647058826; color += texture2D(image, uv - (off1)) * 0.35294117647058826; return color; } void main() { vec2 uv = textureCoordinate; float backdegree = 1.0 - texture2D(fabbyMask, uv).r; if(backdegree > 0.0001) { vec2 dir = direction*backdegree; gl_FragColor = blur9(texture, fabbyMask, uv, dir); } else { gl_FragColor = texture2D(texture, uv); } }'

void libMTFilterKernel_fn_00123644(void* env, void* obj, ...) {
    call_func_0x000ed3a4(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42d0(...);
    call_func_0x0011c2ac(...);
    call_func_0x000ef55c(...);
    call_func_0x001b42d0(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x001b42d0(...);
    call_func_0x001b42d0(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x0013f6cc(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42d0(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x0013f6cc(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    return;
}

// Reconstructed Pseudocode for libMTFilterKernel_fn_00133544 (_ZN14MTFilterKernel18CMTXTDetailsFilter8InitlizeEPNS_18DynamicFilterParamEPKc)
// Library: libMTFilterKernel.so | RVA: 0x00133544 | Size: 304 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; uniform float widthOffset; uniform float heightOffset; varying vec2 texCoord; varying vec2 textureShift_1; varying vec2 textureShift_2; varying vec2 textureShift_3; varying vec2 textureShift_4; void main() { gl_Position = vec4(position.xyz, 1.0); texCoord = inputTextureCoordinate.xy; textureShift_1 = vec2(inputTextureCoordinate.xy + 0.5 * vec2(widthOffset,heightOffset)); textureShift_2 = vec2(inputTextureCoordinate.xy + 0.5 * vec2(-widthOffset,-heightOffset)); textureShift_3 = vec2(inputTextureCoordinate.xy + 0.5 * vec2(-widthOffset,heightOffset)); textureShift_4 = vec2(inputTextureCoordinate.xy + 0.5 * vec2(widthOffset,-heightOffset)); }'
//   'precision highp float; varying vec2 texCoord; varying vec2 textureShift_1; varying vec2 textureShift_2; varying vec2 textureShift_3; varying vec2 textureShift_4; uniform sampler2D inputImageTexture; uniform sampler2D inputImageMaskTexture; uniform sampler2D lastPassTexture; uniform sampler2D blurImageTexture; uniform float eyeDetailIntensity; uniform float colorR; uniform float colorG; uniform float colorB; uniform float colorA; uniform int mode; void main() { lowp vec4 color = texture2D(inputImageTexture, texCoord); lowp vec4 maskColor = texture2D(inputImageMaskTexture, texCoord); lowp vec4 blurColor = texture2D(blurImageTexture, texCoord); lowp vec3 resultColor = color.rgb; lowp float mixture = maskColor.a; if (mode == 1) { mixture = maskColor.r; } if(mixture > 0.005 && eyeDetailIntensity >= 0.01) { lowp vec3 lastPassColor = texture2D(lastPassTexture,texCoord).rgb; mediump vec3 sum = texture2D(lastPassTexture,textureShift_1).rgb; sum += texture2D(lastPassTexture,textureShift_2).rgb; sum += texture2D(lastPassTexture,textureShift_3).rgb; sum += texture2D(lastPassTexture,textureShift_4).rgb; sum = sum * 0.25; lowp vec3 hPass = lastPassColor - sum; lowp vec3 tmpColor = sum + hPass * 3.0; lowp vec3 sharpColor = clamp(tmpColor,0.0,1.0); highp vec3 diffColor = (resultColor - blurColor.rgb) * 7.07; diffColor = min(diffColor * diffColor, 1.0); lowp float diff = (diffColor.r+diffColor.g+diffColor.b) * 0.333; sharpColor = mix(lastPassColor,sharpColor,diff/(diff + 0.1)); resultColor = mix(resultColor,sharpColor,eyeDetailIntensity * mixture); if(colorA > 0.000001 && mode == 0){ maskColor.rgb = vec3(colorR, colorG, colorB); resultColor = mix(resultColor, maskColor.rgb, maskColor.a*colorA); } } gl_FragColor = vec4(resultColor, 1.0); }'
//   'FilterKernel'
//   'ERROR: failed to create program in CMTXTDetailsFilter .....'

void libMTFilterKernel_fn_00133544(void* env, void* obj, ...) {
    call_func_0x000ed3a4(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42d0(...);
    call_func_0x0011c2ac(...);
    call_func_0x000ef55c(...);
    call_func_0x00141d90(...);
    call_func_0x000c5d08(...);
    call_func_0x001b4270(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    return;
}

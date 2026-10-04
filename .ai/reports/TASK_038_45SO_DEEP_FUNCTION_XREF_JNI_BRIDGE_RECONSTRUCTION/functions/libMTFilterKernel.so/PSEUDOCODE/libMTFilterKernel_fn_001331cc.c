// Reconstructed Pseudocode for libMTFilterKernel_fn_001331cc (_ZN14MTFilterKernel18CMTXTDetailsFilter19drawWithBlurAndMaskEj)
// Library: libMTFilterKernel.so | RVA: 0x001331cc | Size: 888 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; varying vec2 texCoord; void main() { gl_Position = vec4(position.xyz, 1.0); texCoord = inputTextureCoordinate.xy; }'
//   'precision highp float; varying vec2 texCoord; uniform sampler2D inputImageTexture; uniform sampler2D inputImageMaskTexture; uniform sampler2D blurImageTexture; uniform float texWidthOffset; uniform float texHeightOffset; uniform int mode; void main() { lowp vec4 color = texture2D(inputImageTexture, texCoord); lowp vec4 maskColor = texture2D(inputImageMaskTexture, texCoord); lowp vec3 resultColor = color.rgb; lowp float mixture = maskColor.a; if (mode == 1) { mixture = maskColor.r; } if(mixture > 0.005) { vec2 horizontalStep = vec2(texWidthOffset, 0.0) * 2.3; vec2 verticalStep = vec2(0.0, texHeightOffset) * 2.3; vec3 sumColor = vec3(0.0, 0.0, 0.0); for(float t = -4.0; t < 4.5; t += 1.0) { for(float p = -4.0;p < 4.5; p += 1.0) { sumColor += texture2D(inputImageTexture,texCoord + t * horizontalStep + p * verticalStep).rgb; } } sumColor = sumColor * 0.0123; sumColor = clamp(sumColor + (color.rgb - sumColor) * 1.8, 0.0, 1.0); sumColor = max(color.rgb, sumColor); lowp vec3 blurColor = texture2D(blurImageTexture, texCoord).rgb; lowp vec3 diffColor = color.rgb - blurColor; diffColor = min(diffColor, 0.0); lowp float clarity = 0.4; sumColor += (diffColor + 0.015) * clarity; sumColor = clamp(sumColor, 0.0,1.0); resultColor = sumColor; } gl_FragColor = vec4(resultColor, 1.0); }'
//   'texWidthOffset'
//   'texHeightOffset'
//   'mode'
//   'position'
//   'inputTextureCoordinate'
//   'inputImageTexture'
//   'inputImageMaskTexture'
//   'blurImageTexture'

void libMTFilterKernel_fn_001331cc(void* env, void* obj, ...) {
    call_func_0x000c8b5c(...);
    call_func_0x001b4290(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42d0(...);
    call_func_0x0013f6cc(...);
    call_func_0x001410d0(...);
    call_func_0x001b42e0(...);
    call_func_0x0011e658(...);
    call_func_0x001b4900(...);
    call_func_0x0013faf0(...);
    call_func_0x00140708(...);
    call_func_0x00140708(...);
    call_func_0x0014003c(...);
    call_func_0x001b4580(...);
    call_func_0x001405dc(...);
    call_func_0x001405dc(...);
    call_func_0x001b4780(...);
    call_func_0x001b46f0(...);
    call_func_0x0014003c(...);
    call_func_0x001b4780(...);
    call_func_0x001b46f0(...);
    call_func_0x0014003c(...);
    call_func_0x001b4780(...);
    call_func_0x001b46f0(...);
    call_func_0x0014003c(...);
    call_func_0x001b47c0(...);
    call_func_0x001b4740(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b4280(...);
    return;
}

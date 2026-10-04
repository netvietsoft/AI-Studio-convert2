// Reconstructed Pseudocode for libMTFilterKernel_fn_00132f84 (_ZN14MTFilterKernel18CMTXTDetailsFilter4blurEjff)
// Library: libMTFilterKernel.so | RVA: 0x00132f84 | Size: 584 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; uniform float texBlurWidthOffset; uniform float texBlurHeightOffset; varying vec2 textureCoord; varying vec4 texBlurShift1; varying vec4 texBlurShift2; varying vec4 texBlurShift3; varying vec4 texBlurShift4; void main() { gl_Position = vec4(position.xyz, 1.0); textureCoord = inputTextureCoordinate.xy; vec2 singleStepOffset = vec2(texBlurWidthOffset, texBlurHeightOffset) * 2.25; texBlurShift1 = vec4(inputTextureCoordinate.xy - singleStepOffset, inputTextureCoordinate.xy + singleStepOffset); texBlurShift2 = vec4(inputTextureCoordinate.xy - 2.0*singleStepOffset, inputTextureCoordinate.xy + 2.0*singleStepOffset); texBlurShift3 = vec4(inputTextureCoordinate.xy - 3.0*singleStepOffset, inputTextureCoordinate.xy + 3.0*singleStepOffset); texBlurShift4 = vec4(inputTextureCoordinate.xy - 4.0*singleStepOffset, inputTextureCoordinate.xy + 4.0*singleStepOffset); }'
//   'precision lowp float; uniform sampler2D srcImageTex; varying highp vec2 textureCoord; varying highp vec4 texBlurShift1; varying highp vec4 texBlurShift2; varying highp vec4 texBlurShift3; varying highp vec4 texBlurShift4; void main() { mediump vec3 sum = texture2D(srcImageTex, textureCoord).rgb; sum += texture2D(srcImageTex, texBlurShift1.xy).rgb; sum += texture2D(srcImageTex, texBlurShift1.zw).rgb; sum += texture2D(srcImageTex, texBlurShift2.xy).rgb; sum += texture2D(srcImageTex, texBlurShift2.zw).rgb; sum += texture2D(srcImageTex, texBlurShift3.xy).rgb; sum += texture2D(srcImageTex, texBlurShift3.zw).rgb; sum += texture2D(srcImageTex, texBlurShift4.xy).rgb; sum += texture2D(srcImageTex, texBlurShift4.zw).rgb; gl_FragColor = vec4(sum * 0.1111, 1.0); }'
//   'texBlurWidthOffset'
//   'texBlurHeightOffset'
//   'position'
//   'inputTextureCoordinate'
//   'srcImageTex'

void libMTFilterKernel_fn_00132f84(void* env, void* obj, ...) {
    call_func_0x0011e658(...);
    call_func_0x001410d0(...);
    call_func_0x001b4730(...);
    call_func_0x0011e658(...);
    call_func_0x001b42d0(...);
    call_func_0x0013f6cc(...);
    call_func_0x001b4900(...);
    call_func_0x0013faf0(...);
    call_func_0x00140708(...);
    call_func_0x00140708(...);
    call_func_0x001b4580(...);
    call_func_0x001405dc(...);
    call_func_0x001405dc(...);
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

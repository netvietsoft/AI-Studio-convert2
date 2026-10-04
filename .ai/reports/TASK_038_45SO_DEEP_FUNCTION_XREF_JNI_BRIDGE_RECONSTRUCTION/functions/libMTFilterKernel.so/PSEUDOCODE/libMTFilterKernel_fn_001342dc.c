// Reconstructed Pseudocode for libMTFilterKernel_fn_001342dc (_ZN14MTFilterKernel17CMTFilterSoftHair8InitlizeEPNS_18DynamicFilterParamEPKc)
// Library: libMTFilterKernel.so | RVA: 0x001342dc | Size: 524 bytes
// Visibility: EXPORTED | Semantic: HAIR_PROCESSING_CORE
// Referenced Strings:
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; varying highp vec2 textureCoordinate; void main() { gl_Position = position; textureCoordinate = inputTextureCoordinate.xy; }'
//   'uniform sampler2D inputImageTexture; varying highp vec2 textureCoordinate; void main() { highp vec4 color = texture2D(inputImageTexture, textureCoordinate); highp float gray = dot(color.rgb, vec3(0.298912, 0.586611, 0.114478)); gl_FragColor = vec4(vec3(gray), color.a); }'
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; varying highp vec2 textureCoordinate; void main() { gl_Position = position; textureCoordinate = inputTextureCoordinate.xy; }'
//   'uniform sampler2D inputImageTexture; varying highp vec2 textureCoordinate; uniform highp vec2 shiftingSize; void main() { highp vec2 uv = textureCoordinate; highp float gray00 = texture2D(inputImageTexture, uv).r; highp float gray01 = texture2D(inputImageTexture, uv + vec2(shiftingSize.x, 0)).r; highp float gray10 = texture2D(inputImageTexture, uv + vec2(0, shiftingSize.y)).r; highp float gray11 = texture2D(inputImageTexture, uv + shiftingSize).r; highp vec2 grad = vec2(gray01 + gray11 - gray00 - gray10, gray10 + gray11 - gray00 - gray01) * 0.5; highp vec2 grad2 = grad * grad; highp float gradLen2 = grad2.x + grad2.y; highp vec2 gradDouble = gradLen2 != 0.0 ? vec2(grad2.x - grad2.y, 2.0 * grad.x * grad.y) / gradLen2 : vec2(0); gl_FragColor = vec4(gradDouble * 0.5 + 0.5, 0, 1); }'
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; varying highp vec2 textureCoordinate; void main() { gl_Position = position; textureCoordinate = inputTextureCoordinate.xy; }'
//   'uniform sampler2D inputImageTexture; varying highp vec2 textureCoordinate; uniform highp float Weights[5]; uniform highp float Offsets[5]; void main() { highp vec2 uv = textureCoordinate; highp vec4 srccolor = texture2D(inputImageTexture, uv); highp vec4 sum = srccolor * Weights[0]; for (int i = 1; i < 5; ++i) { srccolor = texture2D(inputImageTexture, vec2(uv.x, uv.y - Offsets[i])); sum += srccolor * Weights[i]; srccolor = texture2D(inputImageTexture, vec2(uv.x, uv.y + Offsets[i])); sum += srccolor * Weights[i]; } gl_FragColor = sum; }'
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; varying highp vec2 textureCoordinate; void main() { gl_Position = position; textureCoordinate = inputTextureCoordinate.xy; }'
//   'uniform sampler2D inputImageTexture; varying highp vec2 textureCoordinate; uniform highp float Weights[5]; uniform highp float Offsets[5]; void main() { highp vec2 uv = textureCoordinate; highp vec4 srccolor = texture2D(inputImageTexture, uv); highp vec4 sum = srccolor * Weights[0]; for (int i = 1; i < 5; ++i) { srccolor = texture2D(inputImageTexture, vec2(uv.x - Offsets[i], uv.y)); sum += srccolor * Weights[i]; srccolor = texture2D(inputImageTexture, vec2(uv.x + Offsets[i], uv.y)); sum += srccolor * Weights[i]; } gl_FragColor = sum; }'
//   'attribute vec4 position; attribute vec4 inputTextureCoordinate; varying highp vec2 textureCoordinate; void main() { gl_Position = position; textureCoordinate = inputTextureCoordinate.xy; }'
//   'const int KERNEL_SIZE = 10; varying highp vec2 textureCoordinate; uniform sampler2D inputImageTexture; uniform sampler2D gradientTexture; uniform sampler2D hairMaskTexture; uniform highp vec2 shiftingSize; uniform highp float threshold; uniform highp float gain; uniform highp float kernel[10]; void main() { highp vec2 uv = textureCoordinate; highp vec2 gradient = texture2D(gradientTexture, uv).rg * 2.0 - 1.0; highp float direction = atan(gradient.y, gradient.x) * 0.5 + 3.14159 * 0.5; direction = mod(direction, 3.14159); highp float amount = (length(gradient) - threshold) * gain; highp float sumWeight = kernel[0]; highp vec4 sumColor = texture2D(inputImageTexture, uv) * kernel[0]; highp vec2 directionUV = vec2(cos(direction), sin(direction)) * shiftingSize; for (int i = 1; i < KERNEL_SIZE; ++i) { highp vec2 offset = directionUV * float(i); highp vec4 color1 = texture2D(inputImageTexture, uv + offset); highp vec4 color2 = texture2D(inputImageTexture, uv - offset); highp float weight = kernel[i]; sumWeight += 2.0 * weight; sumColor += (color1 + color2) * weight; } highp vec4 origColor = texture2D(inputImageTexture, uv); highp vec4 hairMask = texture2D(hairMaskTexture, uv); gl_FragColor = mix(origColor, sumColor / sumWeight, hairMask.r*gain); }'

void libMTFilterKernel_fn_001342dc(void* env, void* obj, ...) {
    call_func_0x000ed3a4(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42d0(...);
    call_func_0x0011c2ac(...);
    call_func_0x000ef55c(...);
    call_func_0x001b42d0(...);
    call_func_0x0013f6cc(...);
    call_func_0x001b42d0(...);
    call_func_0x0013f6cc(...);
    call_func_0x001b42d0(...);
    call_func_0x0013f6cc(...);
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
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    return;
}

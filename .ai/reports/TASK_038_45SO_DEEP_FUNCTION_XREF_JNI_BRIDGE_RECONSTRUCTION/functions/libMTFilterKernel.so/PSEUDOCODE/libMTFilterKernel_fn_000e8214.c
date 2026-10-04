// Reconstructed Pseudocode for libMTFilterKernel_fn_000e8214 (_ZN14MTFilterKernel22MTSimpleBodyMaskFilter4initEPNS_15GPUImageContextE)
// Library: libMTFilterKernel.so | RVA: 0x000e8214 | Size: 408 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec3 position; attribute vec2 inputTextureCoordinate; varying vec2 textureCoordinate; void main() { gl_Position = vec4(position, 1.0); textureCoordinate = inputTextureCoordinate; }'
//   'varying highp vec2 textureCoordinate; varying vec2 textureCoordinate2; uniform sampler2D inputImageTexture; uniform sampler2D mTexture; uniform float centerx; uniform float centery; uniform float centerin; uniform float centerout; uniform float leftk; uniform float rightk; uniform float isRotation; uniform float isGradeLow; void main() { float mask = 0.0; vec4 orgColor = texture2D(inputImageTexture, textureCoordinate); vec4 result = vec4(0.0, 0.0, 0.0, 1.0); if (isGradeLow > 0.5) { if (centerin == 0.0) { if ((textureCoordinate.x - 0.5) * (textureCoordinate.x - 0.5) + (textureCoordinate.y - 0.5) * (textureCoordinate.y - 0.5) < 0.25) result = vec4(1.0, 1.0, 1.0, 1.0); } else { float rx = (textureCoordinate.x - centerx) * (textureCoordinate.x - centerx); float ry = (textureCoordinate.y - centery) * (textureCoordinate.y - centery); float ra = centerin * centerin; float rb = centerout * centerout; float leftb = centery - leftk * centerx + 0.08; float rightb = centery - rightk * centerx + 0.08; float dis = length(textureCoordinate - vec2(centerx, centery)); if (rx / ra + ry / rb < 1.0) { result = vec4(1.0, orgColor.r, 1.0, 1.0); } else { float v = 0.0; if (isRotation < 0.5) { v = clamp(1.0 - (rx * 3.0 + ry * 5.5 - max(rb, ra)), 0.0, 1.0); } else { v = clamp( 1.0 - (rx * 10.0 + ry * 2.0 - max(rb, ra)), 0.0, 1.0); } result = vec4(v, orgColor.r, v, 1.0); } } mask = result.r; } else { mask = texture2D(mTexture, textureCoordinate).x; } gl_FragColor = vec4(mask, 0.0, 0.0, 1.0); }'

void libMTFilterKernel_fn_000e8214(void* env, void* obj, ...) {
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

// Reconstructed Pseudocode for libMTFilterKernel_fn_000e26d4 (_ZN14MTFilterKernel18MTImageBlendFilter4initEPNS_15GPUImageContextE)
// Library: libMTFilterKernel.so | RVA: 0x000e26d4 | Size: 420 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec3 position; attribute vec2 inputTextureCoordinate; attribute vec2 inputTextureCoordinate2; varying vec2 textureCoordinate; varying vec2 textureCoordinate2; void main() { gl_Position = vec4(position, 1.0); textureCoordinate = inputTextureCoordinate; textureCoordinate2 = inputTextureCoordinate2; }'
//   'varying highp vec2 textureCoordinate; varying vec2 textureCoordinate2; uniform sampler2D inputImageTexture; uniform sampler2D inputImageTexture2; uniform sampler2D inputImageTexture3; uniform sampler2D mTexture; uniform float centerx; uniform float centery; uniform float centerin; uniform float centerout; uniform float leftk; uniform float rightk; uniform float width; uniform float height; uniform float isRotation; uniform float isGradeLow; uniform int maskType; uniform highp float centerValue[20]; uniform highp float ellipseValue[20]; uniform highp float inner[10]; uniform highp float outer[10]; uniform int faceCount; void main() { float mask = 0.0; vec4 orgColor = texture2D(inputImageTexture, textureCoordinate); vec4 result = vec4(0.0, 0.0, 0.0, 1.0); if (maskType == 2 || maskType == 4) { if (isGradeLow > 0.5) { if (centerin == 0.0) { if ((textureCoordinate.x - 0.5) * (textureCoordinate.x - 0.5) + (textureCoordinate.y - 0.5) * (textureCoordinate.y - 0.5) < 0.25) result = vec4(1.0, 1.0, 1.0, 1.0); } else { float rx = (textureCoordinate.x - centerx) * (textureCoordinate.x - centerx); float ry = (textureCoordinate.y - centery) * (textureCoordinate.y - centery); float ra = centerin * centerin; float rb = centerout * centerout; float leftb = centery - leftk * centerx + 0.08; float rightb = centery - rightk * centerx + 0.08; float dis = length(textureCoordinate - vec2(centerx, centery)); if (rx / ra + ry / rb < 1.0) { result = vec4(1.0, orgColor.r, 1.0, 1.0); } else { float v = 0.0; if (isRotation < 0.5) { v = clamp( 1.0 - (rx * 3.0 + ry * 5.5 - max(rb, ra)), 0.0, 1.0); } else { v = clamp( 1.0 - (rx * 10.0 + ry * 2.0 - max(rb, ra)), 0.0, 1.0); } result = vec4(v, orgColor.r, v, 1.0); } } mask = 1.0 - result.r; } else { mask = 1.0 - texture2D(mTexture, textureCoordinate2).x; } if (maskType == 4) { mask = 1.0 - mask; } } else if (maskType == 1 || maskType == 3) { vec4 color = vec4(0.0, 0.0, 0.0, 1.0); if (faceCount > 0) { for (int i = 0; i < faceCount; ++i) { result.r = 1.0; highp float fy = textureCoordinate.y - centerValue[i * 2 + 1]; fy = fy * fy * ellipseValue[i * 2 + 1]; highp float fx = textureCoordinate.x - centerValue[i * 2]; fx = fx * fx * ellipseValue[i * 2]; highp float dist = sqrt(fx + fy); if (dist > inner[i]) { result.r = 1.0 - min((dist - inner[i]) / outer[i], 1.0); } result.r = result.r + (1.0 - result.r) * color.r; color.r = result.r; } } else { result.r = 0.0; } mask = result.r; if (maskType == 1) { mask = 1.0 - mask; } } vec4 tempColor = orgColor; vec4 temp = texture2D(inputImageTexture2, textureCoordinate2); tempColor.r = mix(tempColor.r, texture2D(inputImageTexture3, vec2(temp.r, tempColor.r)).r, temp.a); tempColor.g = mix(tempColor.g, texture2D(inputImageTexture3, vec2(temp.g, tempColor.g)).g, temp.a); tempColor.b = mix(tempColor.b, texture2D(inputImageTexture3, vec2(temp.b, tempColor.b)).b, temp.a); if (maskType > 0) { tempColor = mix(orgColor, tempColor, mask); } else { tempColor = mix(orgColor, tempColor, 1.0); } gl_FragColor = tempColor; }'

void libMTFilterKernel_fn_000e26d4(void* env, void* obj, ...) {
    call_func_0x001433e0(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x0010c444(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b4280(...);
    return;
}

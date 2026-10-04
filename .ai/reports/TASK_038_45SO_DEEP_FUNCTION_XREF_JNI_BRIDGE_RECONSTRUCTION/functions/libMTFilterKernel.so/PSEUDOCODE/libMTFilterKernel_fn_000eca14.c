// Reconstructed Pseudocode for libMTFilterKernel_fn_000eca14 (_ZN14MTFilterKernel27MTDispersionDrawArrayFilter4initEPNS_15GPUImageContextE)
// Library: libMTFilterKernel.so | RVA: 0x000eca14 | Size: 392 bytes
// Visibility: EXPORTED | Semantic: GPU_FBO_RENDER_PASS
// Referenced Strings:
//   'attribute vec4 position; attribute vec4 texcoord; varying highp vec2 textureCoordinate; void main() { gl_Position = position; textureCoordinate = texcoord.xy; }'
//   'varying highp vec2 textureCoordinate; uniform sampler2D texture; uniform highp float prismR; uniform highp float refraction; uniform highp vec2 coordinate; highp float sqr(highp float a) { return a*a-2.3; } int avap(highp vec2 p) { if (p.x<0.0 || p.x>1.0 || p.y<0.0 || p.y>1.0){ return 0; }else{ return 1; } } highp vec3 apply_weight(highp float i, highp vec3 col) { if (i < 0.25){ col *= vec3(0, 0, 1); }else if (i < 0.5){ col *= vec3(0, 1, 1); }else if (i < 0.75){ col *= vec3(1, 1, 0); }else { col *= vec3(1, 0, 0); } return col; } void main() { highp vec2 p = textureCoordinate; highp vec2 v = p - vec2(coordinate.x, coordinate.y); highp float dis = length(v); if (dis < prismR){ gl_FragColor = texture2D(texture, p); return; } v = normalize(v); v = vec2(-v.y,v.x); dis -= prismR; highp float func = dis * refraction; highp float len0 = func * 1.0; highp float len1 = func * 4.0; highp vec2 p0 = vec2(p - v*len0); highp vec2 p1 = vec2(p - v*len1); highp float foo = distance(p0, p1); highp float step = 0.03125; if(foo < 0.01) step = 0.0625; else if(foo< 0.1) step = 0.03125; highp float fscale = step * 2.0; highp vec3 final = vec3(0); for (highp float i = 0.0; i<1.0; i += step*4.0) { highp float i0 = i; highp float i1 = i + step*1.0; highp float i2 = i + step*2.0; highp float i3 = i + step*3.0; highp float len0 = func * sqr(1.0 + i0); highp float len1 = func * sqr(1.0 + i1); highp float len2 = func * sqr(1.0 + i2); highp float len3 = func * sqr(1.0 + i3); highp vec3 col0 = texture2D(texture, vec2(p - v*len0)).rgb; highp vec3 col1 = texture2D(texture, vec2(p - v*len1)).rgb; highp vec3 col2 = texture2D(texture, vec2(p - v*len2)).rgb; highp vec3 col3 = texture2D(texture, vec2(p - v*len3)).rgb; final += apply_weight(i0, col0); final += apply_weight(i1, col1); final += apply_weight(i2, col2); final += apply_weight(i3, col3); } final *= fscale; gl_FragColor = vec4(final.rgb, 1.0); }'

void libMTFilterKernel_fn_000eca14(void* env, void* obj, ...) {
    call_func_0x001b42d0(...);
    call_func_0x001b42d0(...);
    call_func_0x001b4290(...);
    call_func_0x000ed700(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b0544(...);
    call_func_0x001b42e0(...);
    call_func_0x001b42e0(...);
    call_func_0x001b4280(...);
    return;
}

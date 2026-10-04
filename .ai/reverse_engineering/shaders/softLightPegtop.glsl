// SOURCE: libMTFilterKernel.so (offset: 0x82369)
// SHADER: Non-Branching Pegtop SoftLight Blending Function
highp vec3 blendSoftLight(in highp vec3 base, in highp vec3 blend) {
    highp vec3 above = sqrt(base) * (2.0 * blend - 1.0) + 2.0 * base * (1.0 - blend);
    highp vec3 below = 2.0 * base * blend + base * base * (1.0 - 2.0 * blend);
    return mix(below, above, step(0.5, blend));
}

highp vec3 blendSoftLight(in highp vec3 base, in highp vec3 blend, in highp float opacity) {
    return mix(base, blendSoftLight(base, blend), opacity);
}

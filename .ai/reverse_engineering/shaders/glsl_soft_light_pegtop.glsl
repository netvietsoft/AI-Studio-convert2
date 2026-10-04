// SOURCE: libMTFilterKernel.so (offset 0x82369)
// PURPOSE: Pegtop Soft Light Blend Mode Formula
// a: Base hair color luminance, b: Dye pigment color
float blendSoftLight(float a, float b) {
    return (1.0 - 2.0 * b) * a * a + 2.0 * b * a;
}

vec3 blendSoftLightVec3(vec3 base, vec3 blend) {
    return vec3(
        blendSoftLight(base.r, blend.r),
        blendSoftLight(base.g, blend.g),
        blendSoftLight(base.b, blend.b)
    );
}

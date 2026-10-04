// Function: MTFilterKernel::MTRandomNoiseDrawArrayFilter::init(MTFilterKernel::GPUImageContext*)
// RVA: 0xf2d84, Size: 612 bytes
int64_t _ZN14MTFilterKernel28MTRandomNoiseDrawArrayFilter4initEPNS_15GPUImageContextE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xf2db4
    const char* str = "attribute vec4 position; attribute vec4 texcoord; varying highp vec2 textureCoordinate; void main() { gl_Position = position; te";
    _Znwm(...); // call PLT API at 0xf2e1c
    const char* str = "precision highp float; varying highp vec2 textureCoordinate; float noise(vec2 co){ return fract(sin(dot(co ,vec2(12.9898,78.233)";
    memcpy(...); // call PLT API at 0xf2e40
    _ZN14MTFilterKernel17MTDrawArrayFilter4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_(...); // call internal at 0xf2e58
    _ZdlPv(...); // call PLT API at 0xf2e7c
    _ZdlPv(...); // call PLT API at 0xf2e8c
    _Znwm(...); // call PLT API at 0xf2e9c
    _Znwm(...); // call PLT API at 0xf2ee0
    const char* str = "uniform sampler2D inputImageTexture; uniform sampler2D inputImageTexture2; uniform lowp float degree; varying highp vec2 texture";
    memcpy(...); // call PLT API at 0xf2f04
    _ZN14MTFilterKernel15GPUImageContext51programForVertexShaderStringAndFragmentShaderStringERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_(...); // call internal at 0xf2f18
    _ZdlPv(...); // call PLT API at 0xf2f2c
    _ZdlPv(...); // call PLT API at 0xf2f3c
    return a0;
    sub_1B0544(...); // call internal at 0xf2fa8
    _ZdlPv(...); // call PLT API at 0xf2fb0
    _ZdlPv(...); // call PLT API at 0xf2fd0
    __stack_chk_fail(...); // call PLT API at 0xf2fe4
}

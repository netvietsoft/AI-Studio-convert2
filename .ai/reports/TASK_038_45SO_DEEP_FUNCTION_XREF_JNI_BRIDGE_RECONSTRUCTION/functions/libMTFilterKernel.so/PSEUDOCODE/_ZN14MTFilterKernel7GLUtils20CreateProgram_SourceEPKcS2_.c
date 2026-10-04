// Function: MTFilterKernel::GLUtils::CreateProgram_Source(char const*, char const*)
// RVA: 0x141d90, Size: 2740 bytes
int64_t _ZN14MTFilterKernel7GLUtils20CreateProgram_SourceEPKcS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    strlen(...); // call PLT API at 0x141dc4
    _Znwm(...); // call PLT API at 0x141dfc
    memcpy(...); // call PLT API at 0x141e1c
    strlen(...); // call PLT API at 0x141e28
    _Znwm(...); // call PLT API at 0x141e64
    memcpy(...); // call PLT API at 0x141e84
    _Znwm(...); // call PLT API at 0x141e90
    const char* str = "#ifdef GL_ES 
#ifdef GL_FRAGMENT_PRECISION_HIGH 
precision highp float; 
#else 
precision mediump float; 
#endif 
#else 
#define";
    strlen(...); // call PLT API at 0x141f00
    const char* str = "er";
    _Znwm(...); // call PLT API at 0x141f3c
    memcpy(...); // call PLT API at 0x141f5c
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm(...); // call PLT API at 0x141f88
    _ZdlPv(...); // call PLT API at 0x141fb8
    _ZdlPv(...); // call PLT API at 0x141fe4
    _ZdlPv(...); // call PLT API at 0x141ff8
    glCreateShader(...); // call PLT API at 0x142014
    glShaderSource(...); // call PLT API at 0x142030
    glCompileShader(...); // call PLT API at 0x142038
    glGetShaderiv(...); // call PLT API at 0x14204c
    glDeleteShader(...); // call PLT API at 0x14205c
    _ZN14MTFilterKernel7GLUtils17LoadShader_SourceEjPKcb(...); // call internal at 0x14206c
    _Znwm(...); // call PLT API at 0x14207c
    strlen(...); // call PLT API at 0x1420c4
    const char* str = "er";
    _Znwm(...); // call PLT API at 0x142100
    memcpy(...); // call PLT API at 0x142120
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm(...); // call PLT API at 0x14214c
    _ZdlPv(...); // call PLT API at 0x14217c
    _ZdlPv(...); // call PLT API at 0x1421a8
    _ZdlPv(...); // call PLT API at 0x1421bc
    glCreateShader(...); // call PLT API at 0x1421d8
    glShaderSource(...); // call PLT API at 0x1421f4
    glCompileShader(...); // call PLT API at 0x1421fc
    glGetShaderiv(...); // call PLT API at 0x142210
    glDeleteShader(...); // call PLT API at 0x142220
    glCreateShader(...); // call PLT API at 0x14222c
    glShaderSource(...); // call PLT API at 0x142248
    glCompileShader(...); // call PLT API at 0x142250
    glGetShaderiv(...); // call PLT API at 0x142264
    glDeleteShader(...); // call PLT API at 0x142274
    _Znwm(...); // call PLT API at 0x14227c
    strlen(...); // call PLT API at 0x1422d0
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x142300
    const char* str = "FilterKernel";
    const char* str = "ERROR: load vertex shader failed.";
    __android_log_print(...); // call PLT API at 0x142320
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x142324
    const char* str = "FilterKernel";
    const char* str = "vs = %s";
    __android_log_print(...); // call PLT API at 0x142348
    _Znwm(...); // call PLT API at 0x14235c
    memmove(...); // call PLT API at 0x14237c
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm(...); // call PLT API at 0x1423a8
    _ZdlPv(...); // call PLT API at 0x1423d0
    _ZdlPv(...); // call PLT API at 0x1423e0
    __strlen_chk(...); // call PLT API at 0x142400
    _Znam(...); // call PLT API at 0x14241c
    memset(...); // call PLT API at 0x14242c
    const char* str = "%s";
    sub_141CEC(...); // call internal at 0x142458
    memcpy(...); // call PLT API at 0x142468
    _ZN14MTFilterKernel7GLUtils17LoadShader_SourceEjPKcb(...); // call internal at 0x14247c
    _ZdaPv(...); // call PLT API at 0x142488
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc(...); // call PLT API at 0x142498
    _ZdlPv(...); // call PLT API at 0x1424ac
    glCreateProgram(...); // call PLT API at 0x1424b0
    glAttachShader(...); // call PLT API at 0x1424c4
    glAttachShader(...); // call PLT API at 0x1424d0
    glLinkProgram(...); // call PLT API at 0x1424d8
    glGetProgramiv(...); // call PLT API at 0x1424ec
    glGetProgramiv(...); // call PLT API at 0x14250c
    malloc(...); // call PLT API at 0x14251c
    glGetProgramInfoLog(...); // call PLT API at 0x142538
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x14253c
    const char* str = "FilterKernel";
    const char* str = "link program error = %s";
    __android_log_print(...); // call PLT API at 0x142560
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x142564
    const char* str = "FilterKernel";
    const char* str = "vs = %s";
    __android_log_print(...); // call PLT API at 0x142588
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x14258c
    const char* str = "FilterKernel";
    const char* str = "fs = %s";
    __android_log_print(...); // call PLT API at 0x1425b0
    free(...); // call PLT API at 0x1425b8
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1425c0
    const char* str = "FilterKernel";
    const char* str = "ERROR: load fragment shader failed.";
    __android_log_print(...); // call PLT API at 0x1425e0
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1425e4
    const char* str = "FilterKernel";
    const char* str = "fs = %s";
    __android_log_print(...); // call PLT API at 0x142608
    _ZdlPv(...); // call PLT API at 0x142618
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x142624
    const char* str = "FilterKernel";
    const char* str = "ERROR: link program failed. unkown value.";
    __android_log_print(...); // call PLT API at 0x142644
    glDeleteProgram(...); // call PLT API at 0x14264c
    glDeleteShader(...); // call PLT API at 0x142658
    glDeleteShader(...); // call PLT API at 0x142660
    _ZdlPv(...); // call PLT API at 0x14268c
    _ZdlPv(...); // call PLT API at 0x14269c
    return a0;
    sub_C3100(...); // call internal at 0x1426e8
    sub_C3100(...); // call internal at 0x142700
    sub_C3100(...); // call internal at 0x142718
    sub_C3100(...); // call internal at 0x142730
    sub_C3100(...); // call internal at 0x142748
    _ZdlPv(...); // call PLT API at 0x142760
    _ZdlPv(...); // call PLT API at 0x142784
    _ZdlPv(...); // call PLT API at 0x1427a8
    _ZdlPv(...); // call PLT API at 0x1427cc
    sub_1B0544(...); // call internal at 0x142814
    _ZdlPv(...); // call PLT API at 0x14281c
    _ZdlPv(...); // call PLT API at 0x14282c
    __stack_chk_fail(...); // call PLT API at 0x142840
}

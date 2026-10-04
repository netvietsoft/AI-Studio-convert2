// Function: MTFilterKernel::GLUtils::LoadShader_Source(unsigned int, char const*, bool)
// RVA: 0x140f80, Size: 336 bytes
int64_t _ZN14MTFilterKernel7GLUtils17LoadShader_SourceEjPKcb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glCreateShader(...); // call PLT API at 0x140fb0
    glShaderSource(...); // call PLT API at 0x140fcc
    glCompileShader(...); // call PLT API at 0x140fd4
    glGetShaderiv(...); // call PLT API at 0x140fe8
    glGetShaderiv(...); // call PLT API at 0x141008
    malloc(...); // call PLT API at 0x141018
    glGetShaderInfoLog(...); // call PLT API at 0x141034
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x141038
    const char* str = "FilterKernel";
    const char* str = "LoadShader_Source shaderType = %d 
, pSource = %s";
    __android_log_print(...); // call PLT API at 0x141060
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x141064
    const char* str = "FilterKernel";
    const char* str = "LoadShader_Source error = %s";
    __android_log_print(...); // call PLT API at 0x141088
    free(...); // call PLT API at 0x141090
    glDeleteShader(...); // call PLT API at 0x141098
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1410cc
}

// Function: MTFilterKernel::CGLProgram::SetUniform2fv(char const*, float const*, int)
// RVA: 0x140a30, Size: 196 bytes
int64_t _ZN14MTFilterKernel10CGLProgram13SetUniform2fvEPKcPKfi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram18GetUniformLocationEPKc(...); // call internal at 0x140a50
    glUniform2fv(...); // call PLT API at 0x140a70
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140a74
    const char* str = "FilterKernel";
    const char* str = "SetUniform2fv there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x140a9c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140ab0
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x140ae0
    return a0;
}

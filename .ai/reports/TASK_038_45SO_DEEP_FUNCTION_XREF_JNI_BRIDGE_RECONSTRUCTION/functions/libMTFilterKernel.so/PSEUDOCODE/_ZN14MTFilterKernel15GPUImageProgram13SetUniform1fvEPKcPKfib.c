// Function: MTFilterKernel::GPUImageProgram::SetUniform1fv(char const*, float const*, int, bool)
// RVA: 0x168afc, Size: 188 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram13SetUniform1fvEPKcPKfib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0x168b24
    glUniform1fv(...); // call PLT API at 0x168b48
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x168b50
    glIsProgram(...); // call PLT API at 0x168b64
    const char* str = "FilterKernel";
    const char* str = "%s there is no uniform called: %s , m_Program = %d, %d";
    const char* str = "SetUniform1fv";
    __android_log_print(...); // call PLT API at 0x168ba0
    return a0;
}

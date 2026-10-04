// Function: MTFilterKernel::GPUImageProgram::SetUniform3f(char const*, float, float, float, bool)
// RVA: 0x16894c, Size: 212 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram12SetUniform3fEPKcfffb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0x16897c
    glUniform3f(...); // call PLT API at 0x1689a8
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1689b0
    glIsProgram(...); // call PLT API at 0x1689c4
    const char* str = "FilterKernel";
    const char* str = "%s there is no uniform called: %s , m_Program = %d, %d";
    const char* str = "SetUniform3f";
    __android_log_print(...); // call PLT API at 0x168a04
    return a0;
}

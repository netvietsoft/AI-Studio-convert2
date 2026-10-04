// Function: MTFilterKernel::GPUImageProgram::SetUniform4f(char const*, float, float, float, float, bool)
// RVA: 0x168a20, Size: 220 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram12SetUniform4fEPKcffffb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0x168a54
    glUniform4f(...); // call PLT API at 0x168a84
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x168a8c
    glIsProgram(...); // call PLT API at 0x168aa0
    const char* str = "FilterKernel";
    const char* str = "%s there is no uniform called: %s , m_Program = %d, %d";
    const char* str = "SetUniform4f";
    __android_log_print(...); // call PLT API at 0x168ae0
    return a0;
}

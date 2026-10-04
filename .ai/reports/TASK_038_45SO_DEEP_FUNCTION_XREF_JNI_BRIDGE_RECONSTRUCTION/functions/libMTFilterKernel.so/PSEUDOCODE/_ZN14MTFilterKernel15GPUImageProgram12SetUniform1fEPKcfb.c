// Function: MTFilterKernel::GPUImageProgram::SetUniform1f(char const*, float, bool)
// RVA: 0x1687dc, Size: 180 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0x168800
    glUniform1f(...); // call PLT API at 0x168820
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x168828
    glIsProgram(...); // call PLT API at 0x16883c
    const char* str = "FilterKernel";
    const char* str = "%s there is no uniform called: %s , m_Program = %d, %d";
    const char* str = "SetUniform1f";
    __android_log_print(...); // call PLT API at 0x168878
    return a0;
}

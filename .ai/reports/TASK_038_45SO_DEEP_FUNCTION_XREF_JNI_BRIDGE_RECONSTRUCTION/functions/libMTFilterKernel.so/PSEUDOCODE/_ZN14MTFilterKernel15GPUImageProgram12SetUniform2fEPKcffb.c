// Function: MTFilterKernel::GPUImageProgram::SetUniform2f(char const*, float, float, bool)
// RVA: 0x168890, Size: 188 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram12SetUniform2fEPKcffb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0x1688b8
    glUniform2f(...); // call PLT API at 0x1688dc
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1688e4
    glIsProgram(...); // call PLT API at 0x1688f8
    const char* str = "FilterKernel";
    const char* str = "%s there is no uniform called: %s , m_Program = %d, %d";
    const char* str = "SetUniform2f";
    __android_log_print(...); // call PLT API at 0x168934
    return a0;
}

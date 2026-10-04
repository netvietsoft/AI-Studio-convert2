// Function: MTFilterKernel::GPUImageProgram::SetUniform1i(char const*, unsigned int, bool)
// RVA: 0x1685b0, Size: 164 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0x1685d0
    glUniform1i(...); // call PLT API at 0x1685ec
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1685f4
    glIsProgram(...); // call PLT API at 0x168608
    const char* str = "FilterKernel";
    const char* str = "%s there is no uniform called: %s , m_Program = %d, %d";
    const char* str = "SetUniform1i";
    __android_log_print(...); // call PLT API at 0x168640
    return a0;
}

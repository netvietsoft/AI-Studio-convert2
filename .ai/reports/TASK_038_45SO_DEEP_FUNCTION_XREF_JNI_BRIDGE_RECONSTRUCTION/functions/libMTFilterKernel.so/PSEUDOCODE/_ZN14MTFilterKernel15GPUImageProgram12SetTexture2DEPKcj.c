// Function: MTFilterKernel::GPUImageProgram::SetTexture2D(char const*, unsigned int)
// RVA: 0x1684f4, Size: 188 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glActiveTexture(...); // call PLT API at 0x16851c
    glBindTexture(...); // call PLT API at 0x168528
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0x168538
    glUniform1i(...); // call PLT API at 0x168548
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x168550
    glIsProgram(...); // call PLT API at 0x168564
    const char* str = "FilterKernel";
    const char* str = "%s there is no uniform called: %s , m_Program = %d, %d";
    const char* str = "SetUniform1i";
    __android_log_print(...); // call PLT API at 0x168590
    return a0;
}

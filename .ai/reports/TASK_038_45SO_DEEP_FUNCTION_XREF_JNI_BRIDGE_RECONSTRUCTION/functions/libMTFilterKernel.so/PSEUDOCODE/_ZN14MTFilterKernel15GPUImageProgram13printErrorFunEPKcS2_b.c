// Function: MTFilterKernel::GPUImageProgram::printErrorFun(char const*, char const*, bool)
// RVA: 0x168478, Size: 124 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram13printErrorFunEPKcS2_b(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x168498
    glIsProgram(...); // call PLT API at 0x1684ac
    const char* str = "FilterKernel";
    const char* str = "%s there is no uniform called: %s , m_Program = %d, %d";
    __android_log_print(...); // call PLT API at 0x1684e0
    return a0;
}

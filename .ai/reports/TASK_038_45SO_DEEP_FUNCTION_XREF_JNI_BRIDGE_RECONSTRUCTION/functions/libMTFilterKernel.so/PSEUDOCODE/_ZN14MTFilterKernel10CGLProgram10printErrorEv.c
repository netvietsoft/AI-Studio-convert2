// Function: MTFilterKernel::CGLProgram::printError()
// RVA: 0x13ffe0, Size: 92 bytes
int64_t _ZN14MTFilterKernel10CGLProgram10printErrorEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140000
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x14002c
    return a0;
}

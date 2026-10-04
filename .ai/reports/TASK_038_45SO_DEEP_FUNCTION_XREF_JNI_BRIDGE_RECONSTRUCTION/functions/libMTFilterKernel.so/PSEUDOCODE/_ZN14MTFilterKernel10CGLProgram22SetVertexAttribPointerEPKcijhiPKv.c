// Function: MTFilterKernel::CGLProgram::SetVertexAttribPointer(char const*, int, unsigned int, unsigned char, int, void const*)
// RVA: 0x1405dc, Size: 264 bytes
int64_t _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram17GetAttribLocationEPKc(...); // call internal at 0x140610
    glEnableVertexAttribArray(...); // call PLT API at 0x140620
    glVertexAttribPointer(...); // call PLT API at 0x140650
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140654
    const char* str = "FilterKernel";
    const char* str = "SetVertexAttribPointer there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x14067c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140690
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x1406c8
    return a0;
}

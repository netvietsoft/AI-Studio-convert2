// Function: MTFilterKernel::CMTDynamicFilter::BindTexture()
// RVA: 0x11df3c, Size: 252 bytes
int64_t _ZN14MTFilterKernel16CMTDynamicFilter11BindTextureEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "FilterKernel";
    const char* str = "ERROR:BindTexture failed index=%d";
    glBindTexture(...); // call PLT API at 0x11df88
    glUniform1i(...); // call PLT API at 0x11df98
    glActiveTexture(...); // call PLT API at 0x11dfd0
    glBindTexture(...); // call PLT API at 0x11dfec
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11dffc
    __android_log_print(...); // call PLT API at 0x11e018
    return a0;
}

// Function: MTFilterKernel::MTDrawArrayFilter::bindTexture()
// RVA: 0xedf1c, Size: 208 bytes
int64_t _ZN14MTFilterKernel17MTDrawArrayFilter11bindTextureEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "FilterKernel";
    const char* str = "ERROR:BindTexture failed index=%d";
    glActiveTexture(...); // call PLT API at 0xedf60
    glBindTexture(...); // call PLT API at 0xedf74
    glUniform1i(...); // call PLT API at 0xedf84
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xedfb4
    __android_log_print(...); // call PLT API at 0xedfd0
    return a0;
}

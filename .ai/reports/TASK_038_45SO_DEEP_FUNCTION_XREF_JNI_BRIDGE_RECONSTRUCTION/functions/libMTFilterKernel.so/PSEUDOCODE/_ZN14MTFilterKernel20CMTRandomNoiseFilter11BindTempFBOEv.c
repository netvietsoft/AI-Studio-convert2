// Function: MTFilterKernel::CMTRandomNoiseFilter::BindTempFBO()
// RVA: 0x129768, Size: 436 bytes
int64_t _ZN14MTFilterKernel20CMTRandomNoiseFilter11BindTempFBOEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x129794
    return a0;
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x1297f0
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x12980c
    glGenFramebuffers(...); // call PLT API at 0x129828
    glBindFramebuffer(...); // call PLT API at 0x129834
    glFramebufferTexture2D(...); // call PLT API at 0x12984c
    glCheckFramebufferStatus(...); // call PLT API at 0x129854
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x129878
    const char* str = "FilterKernel";
    const char* str = "ERROR: glCheckFramebufferStatus status = %d";
    __android_log_print(...); // call PLT API at 0x12989c
    return a0;
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x1298e0
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x129904
}

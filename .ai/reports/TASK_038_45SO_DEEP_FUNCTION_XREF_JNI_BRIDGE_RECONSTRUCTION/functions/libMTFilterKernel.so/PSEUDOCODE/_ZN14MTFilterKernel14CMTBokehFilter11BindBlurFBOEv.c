// Function: MTFilterKernel::CMTBokehFilter::BindBlurFBO()
// RVA: 0x124174, Size: 448 bytes
int64_t _ZN14MTFilterKernel14CMTBokehFilter11BindBlurFBOEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x1241a0
    return a0;
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x124200
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x12421c
    glGenFramebuffers(...); // call PLT API at 0x124238
    glBindFramebuffer(...); // call PLT API at 0x124244
    glFramebufferTexture2D(...); // call PLT API at 0x12425c
    glCheckFramebufferStatus(...); // call PLT API at 0x124264
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x124288
    const char* str = "FilterKernel";
    const char* str = "ERROR: glCheckFramebufferStatus status = %d";
    __android_log_print(...); // call PLT API at 0x1242ac
    return a0;
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x1242f8
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x12431c
}

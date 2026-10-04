// Function: MTFilterKernel::MTImgTextureManger::releaseTexture()
// RVA: 0xf98ac, Size: 208 bytes
int64_t _ZN14MTFilterKernel18MTImgTextureManger14releaseTextureEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "FilterKernel";
    const char* str = "MTImgTextureManger::releaseTexture id=%d";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xf98f8
    __android_log_print(...); // call PLT API at 0xf9914
    glDeleteTextures(...); // call PLT API at 0xf9920
    sub_F9EDC(...); // call internal at 0xf995c
    return a0;
}

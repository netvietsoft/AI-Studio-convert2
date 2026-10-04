// Function: MTFilterKernel::MTImgTextureManger::~MTImgTextureManger()
// RVA: 0xf97ac, Size: 256 bytes
int64_t _ZN14MTFilterKernel18MTImgTextureMangerD1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "FilterKernel";
    const char* str = "MTImgTextureManger::releaseTexture id=%d";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xf9808
    __android_log_print(...); // call PLT API at 0xf9824
    glDeleteTextures(...); // call PLT API at 0xf9830
    sub_F9EDC(...); // call internal at 0xf986c
    _ZdlPv(...); // call PLT API at 0xf9888
    sub_F9EDC(...); // call internal at 0xf98a4
    sub_C0B38(...); // call internal at 0xf98a8
}

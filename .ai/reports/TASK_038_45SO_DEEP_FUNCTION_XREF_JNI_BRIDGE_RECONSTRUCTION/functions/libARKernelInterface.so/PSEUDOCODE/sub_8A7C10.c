// Function: sub_8A7C10
// RVA: 0x8a7c10, Size: 328 bytes
int64_t sub_8A7C10(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenFramebuffers(...); // call PLT API at 0x8a7c5c
    sub_DA2FE4(...); // call internal at 0x8a7c64
    sub_DA2A48(...); // call internal at 0x8a7c68
    sub_DA2FE4(...); // call internal at 0x8a7c74
    sub_DA2A38(...); // call internal at 0x8a7c78
    sub_DA2FE4(...); // call internal at 0x8a7c84
    sub_DA2A40(...); // call internal at 0x8a7c88
    _Znam(...); // call PLT API at 0x8a7c98
    glBindFramebuffer(...); // call PLT API at 0x8a7ca8
    glFramebufferTexture2D(...); // call PLT API at 0x8a7cc0
    glReadPixels(...); // call PLT API at 0x8a7ce0
    sub_8A6C3C(...); // call internal at 0x8a7d0c
    glDeleteFramebuffers(...); // call PLT API at 0x8a7d18
    _ZdaPv(...); // call PLT API at 0x8a7d20
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x8a7d54
}

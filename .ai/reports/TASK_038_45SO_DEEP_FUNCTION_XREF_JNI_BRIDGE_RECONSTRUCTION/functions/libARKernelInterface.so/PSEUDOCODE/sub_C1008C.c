// Function: sub_C1008C
// RVA: 0xc1008c, Size: 416 bytes
int64_t sub_C1008C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenFramebuffers(...); // call PLT API at 0xc100c8
    sub_DA2FE4(...); // call internal at 0xc100d0
    sub_DA2A48(...); // call internal at 0xc100d4
    sub_DA2FE4(...); // call internal at 0xc100e0
    sub_DA2A38(...); // call internal at 0xc100e4
    sub_DA2FE4(...); // call internal at 0xc100f0
    sub_DA2A40(...); // call internal at 0xc100f4
    _Znam(...); // call PLT API at 0xc10104
    glBindFramebuffer(...); // call PLT API at 0xc10114
    glFramebufferTexture2D(...); // call PLT API at 0xc1012c
    glReadPixels(...); // call PLT API at 0xc1014c
    glDeleteFramebuffers(...); // call PLT API at 0xc101cc
    _ZdaPv(...); // call PLT API at 0xc101d4
    sub_D7FB90(...); // call internal at 0xc101f4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc10228
}

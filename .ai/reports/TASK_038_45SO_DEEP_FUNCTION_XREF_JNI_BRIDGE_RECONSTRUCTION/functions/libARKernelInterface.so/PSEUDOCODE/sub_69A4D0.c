// Function: sub_69A4D0
// RVA: 0x69a4d0, Size: 216 bytes
int64_t sub_69A4D0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenFramebuffers(...); // call PLT API at 0x69a514
    glBindFramebuffer(...); // call PLT API at 0x69a520
    glFramebufferTexture2D(...); // call PLT API at 0x69a538
    glClearColor(...); // call PLT API at 0x69a54c
    glClear(...); // call PLT API at 0x69a554
    glBindFramebuffer(...); // call PLT API at 0x69a560
    glDeleteFramebuffers(...); // call PLT API at 0x69a574
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x69a5a4
}

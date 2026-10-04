// Function: sub_AFE13C
// RVA: 0xafe13c, Size: 660 bytes
int64_t sub_AFE13C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteTextures(...); // call PLT API at 0xafe1a4
    sub_69A024(...); // call internal at 0xafe1b4
    glBindFramebuffer(...); // call PLT API at 0xafe1c4
    glFramebufferTexture2D(...); // call PLT API at 0xafe1dc
    glViewport(...); // call PLT API at 0xafe1f0
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0xafe240
    glBindTexture(...); // call PLT API at 0xafe24c
    const char* str = "texture";
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0xafe270
    glBindTexture(...); // call PLT API at 0xafe27c
    const char* str = "texture2";
    (*x8)(...);
    const char* str = "mvpMatrix";
    (*x8)(...);
    const char* str = "position";
    (*x8)(...);
    const char* str = "texcoord";
    (*x8)(...);
    glDrawElements(...); // call PLT API at 0xafe360
    (*x8)(...);
    const char* str = "texCoord";
    (*x8)(...);
    glBindFramebuffer(...); // call PLT API at 0xafe398
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xafe3cc
}

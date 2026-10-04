// Function: sub_7B919C
// RVA: 0x7b919c, Size: 324 bytes
int64_t sub_7B919C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glViewport(...); // call PLT API at 0x7b91e0
    (*x8)(...);
    glBindFramebuffer(...); // call PLT API at 0x7b91fc
    glClearColor(...); // call PLT API at 0x7b9210
    glClear(...); // call PLT API at 0x7b9218
    const char* str = "inputTextureCoordinate";
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0x7b9260
    glBindTexture(...); // call PLT API at 0x7b926c
    const char* str = "inputImageTexture";
    (*x8)(...);
    glDrawArrays(...); // call PLT API at 0x7b9298
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x7b92dc
}

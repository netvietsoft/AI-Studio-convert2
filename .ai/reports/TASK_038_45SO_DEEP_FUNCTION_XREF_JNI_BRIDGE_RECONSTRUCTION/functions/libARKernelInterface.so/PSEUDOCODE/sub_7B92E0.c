// Function: sub_7B92E0
// RVA: 0x7b92e0, Size: 252 bytes
int64_t sub_7B92E0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glViewport(...); // call PLT API at 0x7b9318
    (*x8)(...);
    glBindFramebuffer(...); // call PLT API at 0x7b9334
    const char* str = "inputTextureCoordinate";
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0x7b936c
    glBindTexture(...); // call PLT API at 0x7b9378
    const char* str = "inputImageTexture";
    (*x8)(...);
    glDrawElements(...); // call PLT API at 0x7b93ac
    (*x8)(...);
    return a0;
}

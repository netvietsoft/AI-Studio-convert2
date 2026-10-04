// Function: sub_ACA680
// RVA: 0xaca680, Size: 916 bytes
int64_t sub_ACA680(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0xaca6cc
    sub_58F19C(...); // call internal at 0xaca6e0
    (*x8)(...);
    _ZdlPv(...); // call PLT API at 0xaca70c
    (*x8)(...);
    glViewport(...); // call PLT API at 0xaca734
    sub_FC2A84(...); // call internal at 0xaca764
    glActiveTexture(...); // call PLT API at 0xaca7e4
    glBindTexture(...); // call PLT API at 0xaca7f0
    const char* str = "texture";
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0xaca814
    glBindTexture(...); // call PLT API at 0xaca820
    const char* str = "blurTex";
    (*x8)(...);
    const char* str = "threshold";
    (*x8)(...);
    const char* str = "scalar";
    (*x8)(...);
    sub_BBBCB0(...); // call internal at 0xaca880
    const char* str = "HLVig";
    (*x8)(...);
    const char* str = "grayScale";
    (*x8)(...);
    const char* str = "mvpMatrix";
    (*x8)(...);
    const char* str = "position";
    (*x8)(...);
    const char* str = "texcoord";
    (*x8)(...);
    glDrawArrays(...); // call PLT API at 0xaca9b0
    (*x8)(...);
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xacaa10
}

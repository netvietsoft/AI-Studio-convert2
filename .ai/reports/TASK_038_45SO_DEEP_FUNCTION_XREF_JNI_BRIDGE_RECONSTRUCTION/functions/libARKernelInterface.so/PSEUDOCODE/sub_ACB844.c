// Function: sub_ACB844
// RVA: 0xacb844, Size: 1044 bytes
int64_t sub_ACB844(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0xacb890
    sub_58F19C(...); // call internal at 0xacb8a4
    (*x8)(...);
    _ZdlPv(...); // call PLT API at 0xacb8d0
    (*x8)(...);
    glViewport(...); // call PLT API at 0xacb8f8
    sub_FC2A84(...); // call internal at 0xacb924
    glActiveTexture(...); // call PLT API at 0xacb9a4
    glBindTexture(...); // call PLT API at 0xacb9b0
    const char* str = "texture";
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0xacb9d4
    glBindTexture(...); // call PLT API at 0xacb9e0
    const char* str = "blurTex";
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0xacba04
    glBindTexture(...); // call PLT API at 0xacba10
    const char* str = "softTex";
    (*x8)(...);
    const char* str = "uCOLOR";
    (*x8)(...);
    const char* str = "uTONE";
    (*x8)(...);
    const char* str = "uFX";
    (*x8)(...);
    const char* str = "alpha";
    (*x8)(...);
    const char* str = "mvpMatrix";
    (*x8)(...);
    const char* str = "position";
    (*x8)(...);
    const char* str = "texcoord";
    (*x8)(...);
    glDrawArrays(...); // call PLT API at 0xacbb48
    (*x8)(...);
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xacbba4
    sub_ACBC58(...); // call internal at 0xacbc48
    return a0;
}

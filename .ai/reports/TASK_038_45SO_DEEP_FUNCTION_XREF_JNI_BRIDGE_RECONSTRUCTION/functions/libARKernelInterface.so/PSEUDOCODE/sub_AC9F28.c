// Function: sub_AC9F28
// RVA: 0xac9f28, Size: 620 bytes
int64_t sub_AC9F28(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0xac9f68
    sub_58F19C(...); // call internal at 0xac9f7c
    (*x8)(...);
    _ZdlPv(...); // call PLT API at 0xac9fa8
    (*x8)(...);
    glViewport(...); // call PLT API at 0xac9fd0
    sub_FC2A84(...); // call internal at 0xac9ffc
    glActiveTexture(...); // call PLT API at 0xaca07c
    glBindTexture(...); // call PLT API at 0xaca088
    const char* str = "texture";
    (*x8)(...);
    const char* str = "mvpMatrix";
    (*x8)(...);
    const char* str = "position";
    (*x8)(...);
    const char* str = "texcoord";
    (*x8)(...);
    glDrawArrays(...); // call PLT API at 0xaca138
    (*x8)(...);
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xaca190
}

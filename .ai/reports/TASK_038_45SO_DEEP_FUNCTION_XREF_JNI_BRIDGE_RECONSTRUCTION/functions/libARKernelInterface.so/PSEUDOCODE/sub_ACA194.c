// Function: sub_ACA194
// RVA: 0xaca194, Size: 620 bytes
int64_t sub_ACA194(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0xaca1d4
    sub_58F19C(...); // call internal at 0xaca1e8
    (*x8)(...);
    _ZdlPv(...); // call PLT API at 0xaca214
    (*x8)(...);
    glViewport(...); // call PLT API at 0xaca23c
    sub_FC2A84(...); // call internal at 0xaca268
    glActiveTexture(...); // call PLT API at 0xaca2e8
    glBindTexture(...); // call PLT API at 0xaca2f4
    const char* str = "s_texture";
    (*x8)(...);
    const char* str = "u_mvpMatrix";
    (*x8)(...);
    const char* str = "a_position";
    (*x8)(...);
    const char* str = "a_texcoord";
    (*x8)(...);
    glDrawArrays(...); // call PLT API at 0xaca3a4
    (*x8)(...);
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xaca3fc
}

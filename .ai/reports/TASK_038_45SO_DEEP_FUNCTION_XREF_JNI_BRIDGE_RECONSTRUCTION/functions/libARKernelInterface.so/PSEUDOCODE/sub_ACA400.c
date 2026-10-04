// Function: sub_ACA400
// RVA: 0xaca400, Size: 640 bytes
int64_t sub_ACA400(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0xaca44c
    sub_58F19C(...); // call internal at 0xaca464
    (*x8)(...);
    _ZdlPv(...); // call PLT API at 0xaca490
    (*x8)(...);
    glViewport(...); // call PLT API at 0xaca4b8
    sub_FC2A84(...); // call internal at 0xaca4e4
    glActiveTexture(...); // call PLT API at 0xaca564
    glBindTexture(...); // call PLT API at 0xaca570
    const char* str = "texture";
    (*x8)(...);
    const char* str = "mvpMatrix";
    (*x8)(...);
    const char* str = "position";
    (*x8)(...);
    const char* str = "texcoord";
    (*x8)(...);
    glDrawArrays(...); // call PLT API at 0xaca620
    (*x8)(...);
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xaca67c
}

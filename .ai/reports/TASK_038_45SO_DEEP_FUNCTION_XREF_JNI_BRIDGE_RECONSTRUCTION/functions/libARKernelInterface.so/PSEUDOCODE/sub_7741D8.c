// Function: sub_7741D8
// RVA: 0x7741d8, Size: 552 bytes
int64_t sub_7741D8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_C41220(...); // call internal at 0x77420c
    (*x8)(...);
    sub_698A74(...); // call internal at 0x77422c
    glBindFramebuffer(...); // call PLT API at 0x774238
    sub_69B7C4(...); // call internal at 0x774240
    glFramebufferTexture2D(...); // call PLT API at 0x774258
    glViewport(...); // call PLT API at 0x77426c
    (*x8)(...);
    sub_69B76C(...); // call internal at 0x7742c4
    const char* str = "texture";
    (*x8)(...);
    const char* str = "mvpMatrix";
    (*x8)(...);
    const char* str = "position";
    (*x8)(...);
    const char* str = "texcoord";
    (*x8)(...);
    glDrawElements(...); // call PLT API at 0x7743a8
    (*x8)(...);
    const char* str = "texCoord";
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x7743fc
}

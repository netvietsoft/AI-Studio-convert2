// Function: sub_9928B4
// RVA: 0x9928b4, Size: 520 bytes
int64_t sub_9928B4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_697FB4(...); // call internal at 0x992910
    sub_6981A0(...); // call internal at 0x992918
    sub_698564(...); // call internal at 0x992920
    sub_69856C(...); // call internal at 0x99292c
    glViewport(...); // call PLT API at 0x992940
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0x992958
    sub_69B7C4(...); // call internal at 0x992960
    glBindTexture(...); // call PLT API at 0x99296c
    const char* str = "s_texture";
    (*x8)(...);
    const char* str = "u_mvpMatrix";
    (*x8)(...);
    const char* str = "a_position";
    (*x8)(...);
    const char* str = "a_texcoord";
    (*x8)(...);
    glDrawArrays(...); // call PLT API at 0x992a44
    (*x8)(...);
    (*x8)(...);
    glBindFramebuffer(...); // call PLT API at 0x992a78
    sub_698448(...); // call internal at 0x992a80
    sub_697894(...); // call internal at 0x992a8c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x992ab8
}

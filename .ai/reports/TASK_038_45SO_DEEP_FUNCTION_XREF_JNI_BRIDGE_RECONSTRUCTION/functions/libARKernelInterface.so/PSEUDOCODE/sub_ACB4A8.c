// Function: sub_ACB4A8
// RVA: 0xacb4a8, Size: 924 bytes
int64_t sub_ACB4A8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0xacb4f0
    sub_58F19C(...); // call internal at 0xacb504
    (*x8)(...);
    _ZdlPv(...); // call PLT API at 0xacb530
    (*x8)(...);
    glViewport(...); // call PLT API at 0xacb558
    sub_FC2A84(...); // call internal at 0xacb584
    glActiveTexture(...); // call PLT API at 0xacb604
    glBindTexture(...); // call PLT API at 0xacb610
    const char* str = "sampler1";
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0xacb634
    glBindTexture(...); // call PLT API at 0xacb640
    const char* str = "sampler2";
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0xacb664
    const char* str = "mixCoeff";
    (*x8)(...);
    const char* str = "dstColor";
    (*x8)(...);
    const char* str = "mvpMatrix";
    (*x8)(...);
    const char* str = "position";
    (*x8)(...);
    const char* str = "texcoord";
    (*x8)(...);
    glDrawArrays(...); // call PLT API at 0xacb7e4
    (*x8)(...);
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xacb840
}

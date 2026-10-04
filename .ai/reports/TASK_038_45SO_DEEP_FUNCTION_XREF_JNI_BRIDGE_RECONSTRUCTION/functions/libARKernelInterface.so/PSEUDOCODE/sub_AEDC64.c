// Function: sub_AEDC64
// RVA: 0xaedc64, Size: 384 bytes
int64_t sub_AEDC64(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_AEDA0C(...); // call internal at 0xaedc8c
    glViewport(...); // call PLT API at 0xaedca8
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0xaedcc8
    glBindTexture(...); // call PLT API at 0xaedcd4
    const char* str = "s_materialMap";
    (*x8)(...);
    sub_AE513C(...); // call internal at 0xaedcfc
    const char* str = "u_mvpMatrix";
    (*x8)(...);
    const char* str = "a_Position";
    (*x8)(...);
    const char* str = "a_UV";
    (*x8)(...);
    glDrawArrays(...); // call PLT API at 0xaedd90
    (*x8)(...);
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xaedde0
}

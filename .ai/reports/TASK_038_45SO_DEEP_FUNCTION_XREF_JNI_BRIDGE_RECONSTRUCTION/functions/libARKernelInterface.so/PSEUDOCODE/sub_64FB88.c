// Function: sub_64FB88
// RVA: 0x64fb88, Size: 204 bytes
int64_t sub_64FB88(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x9)(...);
    memset(...); // call PLT API at 0x64fbcc
    memcpy(...); // call PLT API at 0x64fc28
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x64fc50
}

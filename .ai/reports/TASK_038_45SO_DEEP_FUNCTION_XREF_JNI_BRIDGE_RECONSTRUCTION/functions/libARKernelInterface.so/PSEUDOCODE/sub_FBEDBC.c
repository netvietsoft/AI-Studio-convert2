// Function: sub_FBEDBC
// RVA: 0xfbedbc, Size: 260 bytes
int64_t sub_FBEDBC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_BA5404(...); // call internal at 0xfbee30
    sub_BA580C(...); // call internal at 0xfbee6c
    free(...); // call PLT API at 0xfbee7c
    free(...); // call PLT API at 0xfbee8c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfbeebc
}

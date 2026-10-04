// Function: sub_1B3A94
// RVA: 0x1b3a94, Size: 640 bytes
int64_t sub_1B3A94(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_1B552C(...); // call internal at 0x1b3ad8
    malloc(...); // call PLT API at 0x1b3b0c
    free(...); // call PLT API at 0x1b3b68
    malloc(...); // call PLT API at 0x1b3b80
    const char* str = "outofmem";
    __memcpy_chk(...); // call PLT API at 0x1b3c14
    memcpy(...); // call PLT API at 0x1b3c24
    memcpy(...); // call PLT API at 0x1b3c34
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1b3d10
}

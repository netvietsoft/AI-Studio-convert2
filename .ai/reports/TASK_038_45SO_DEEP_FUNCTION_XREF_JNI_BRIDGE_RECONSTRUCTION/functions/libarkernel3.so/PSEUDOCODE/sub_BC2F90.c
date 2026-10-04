// Function: sub_BC2F90
// RVA: 0xbc2f90, Size: 620 bytes
int64_t sub_BC2F90(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_BC2F10(...); // call internal at 0xbc3010
    (*x8)(...);
    sub_BC0020(...); // call internal at 0xbc30a0
    (*x8)(...);
    free(...); // call PLT API at 0xbc30f4
    return a0;
    free(...); // call PLT API at 0xbc3144
    sub_106B814(...); // call internal at 0xbc315c
    __stack_chk_fail(...); // call PLT API at 0xbc3160
    sub_BC31FC(...); // call internal at 0xbc31ac
    memcpy(...); // call PLT API at 0xbc31c0
    free(...); // call PLT API at 0xbc31e8
    return a0;
}

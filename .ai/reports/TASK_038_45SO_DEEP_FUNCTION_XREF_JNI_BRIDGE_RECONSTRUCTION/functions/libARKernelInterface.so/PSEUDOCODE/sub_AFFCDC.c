// Function: sub_AFFCDC
// RVA: 0xaffcdc, Size: 548 bytes
int64_t sub_AFFCDC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_A1738C(...); // call internal at 0xaffe10
    sub_C3CD6C(...); // call internal at 0xaffe20
    sub_A19264(...); // call internal at 0xaffe30
    (*x8)(...);
    (*x9)(...);
    memcpy(...); // call PLT API at 0xaffe88
    sub_A17644(...); // call internal at 0xaffebc
    sub_A17440(...); // call internal at 0xaffec8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xaffefc
}

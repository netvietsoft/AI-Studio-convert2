// Function: sub_D1150
// RVA: 0xd1150, Size: 248 bytes
int64_t sub_D1150(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsprintf_chk(...); // call PLT API at 0xd11cc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd11f0
    gettimeofday(...); // call PLT API at 0xd1224
    return a0;
}

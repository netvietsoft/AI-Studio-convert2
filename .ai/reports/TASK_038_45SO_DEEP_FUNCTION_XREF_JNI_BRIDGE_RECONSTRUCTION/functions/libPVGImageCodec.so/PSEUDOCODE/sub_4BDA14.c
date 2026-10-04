// Function: sub_4BDA14
// RVA: 0x4bda14, Size: 148 bytes
int64_t sub_4BDA14(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vsnprintf(...); // call PLT API at 0x4bda80
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x4bdaa4
}

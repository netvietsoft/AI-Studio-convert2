// Function: sub_B399E8
// RVA: 0xb399e8, Size: 152 bytes
int64_t sub_B399E8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vsnprintf(...); // call PLT API at 0xb39a58
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xb39a7c
}

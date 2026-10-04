// Function: sub_8832A8
// RVA: 0x8832a8, Size: 152 bytes
int64_t sub_8832A8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vsnprintf(...); // call PLT API at 0x883318
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x88333c
}

// Function: sub_68C7C8
// RVA: 0x68c7c8, Size: 152 bytes
int64_t sub_68C7C8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vsnprintf(...); // call PLT API at 0x68c838
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x68c85c
}

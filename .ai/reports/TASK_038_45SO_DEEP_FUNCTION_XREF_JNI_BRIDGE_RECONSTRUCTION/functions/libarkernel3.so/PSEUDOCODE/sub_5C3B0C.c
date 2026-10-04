// Function: sub_5C3B0C
// RVA: 0x5c3b0c, Size: 568 bytes
int64_t sub_5C3B0C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sincosf(...); // call PLT API at 0x5c3b60
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x5c3d40
}

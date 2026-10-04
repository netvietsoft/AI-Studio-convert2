// Function: sub_5A83A0
// RVA: 0x5a83a0, Size: 556 bytes
int64_t sub_5A83A0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sincosf(...); // call PLT API at 0x5a83fc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x5a85c8
}

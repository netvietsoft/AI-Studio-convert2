// Function: sub_BA503C
// RVA: 0xba503c, Size: 236 bytes
int64_t sub_BA503C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memcpy(...); // call PLT API at 0xba50a0
    memcpy(...); // call PLT API at 0xba50d4
    sub_BA5128(...); // call internal at 0xba50f8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xba5124
}

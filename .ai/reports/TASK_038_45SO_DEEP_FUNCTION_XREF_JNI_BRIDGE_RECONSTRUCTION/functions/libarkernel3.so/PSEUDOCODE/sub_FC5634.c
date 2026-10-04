// Function: sub_FC5634
// RVA: 0xfc5634, Size: 152 bytes
int64_t sub_FC5634(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vsnprintf(...); // call PLT API at 0xfc56a4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfc56c8
}

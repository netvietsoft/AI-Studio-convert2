// Function: sub_E3FC04
// RVA: 0xe3fc04, Size: 96 bytes
int64_t sub_E3FC04(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_E3FC64(...); // call internal at 0xe3fc28
    _ZdlPv(...); // call PLT API at 0xe3fc38
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe3fc60
}

// Function: sub_E0C6E8
// RVA: 0xe0c6e8, Size: 748 bytes
int64_t sub_E0C6E8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_E0C594(...); // call internal at 0xe0c72c
    sincosf(...); // call PLT API at 0xe0c7a4
    sub_DA6EC4(...); // call internal at 0xe0c7cc
    sincosf(...); // call PLT API at 0xe0c7e8
    sub_DA6EC4(...); // call internal at 0xe0c824
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe0c9d0
}

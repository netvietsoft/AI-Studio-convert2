// Function: sub_E0064C
// RVA: 0xe0064c, Size: 688 bytes
int64_t sub_E0064C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_E025A4(...); // call internal at 0xe00698
    sub_DFFCAC(...); // call internal at 0xe006dc
    sincosf(...); // call PLT API at 0xe00734
    sub_E025A4(...); // call internal at 0xe0078c
    sincosf(...); // call PLT API at 0xe007d4
    sub_E025A4(...); // call internal at 0xe0082c
    sub_E025A4(...); // call internal at 0xe00888
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe008f8
}

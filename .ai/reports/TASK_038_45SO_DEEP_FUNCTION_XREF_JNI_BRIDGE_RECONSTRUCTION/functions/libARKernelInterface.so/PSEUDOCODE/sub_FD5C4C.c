// Function: sub_FD5C4C
// RVA: 0xfd5c4c, Size: 280 bytes
int64_t sub_FD5C4C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_FD5D64(...); // call internal at 0xfd5ca8
    memmove(...); // call PLT API at 0xfd5cd8
    memmove(...); // call PLT API at 0xfd5d20
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfd5d60
}

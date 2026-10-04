// Function: sub_FD6D10
// RVA: 0xfd6d10, Size: 316 bytes
int64_t sub_FD6D10(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_FD6E4C(...); // call internal at 0xfd6d6c
    memmove(...); // call PLT API at 0xfd6da4
    memmove(...); // call PLT API at 0xfd6e00
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfd6e48
}

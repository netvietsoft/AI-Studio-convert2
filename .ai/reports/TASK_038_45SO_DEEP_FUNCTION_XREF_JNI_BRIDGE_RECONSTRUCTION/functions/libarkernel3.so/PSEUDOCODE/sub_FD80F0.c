// Function: sub_FD80F0
// RVA: 0xfd80f0, Size: 196 bytes
int64_t sub_FD80F0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call PLT API at 0xfd8154
    sub_FD7F18(...); // call internal at 0xfd817c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfd81b0
}

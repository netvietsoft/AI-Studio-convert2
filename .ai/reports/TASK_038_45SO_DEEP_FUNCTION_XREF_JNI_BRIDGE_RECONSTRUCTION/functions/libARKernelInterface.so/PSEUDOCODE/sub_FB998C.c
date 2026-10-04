// Function: sub_FB998C
// RVA: 0xfb998c, Size: 276 bytes
int64_t sub_FB998C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_B9B524(...); // call internal at 0xfb9a04
    sub_FB9AA0(...); // call internal at 0xfb9a48
    free(...); // call PLT API at 0xfb9a58
    free(...); // call PLT API at 0xfb9a68
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfb9a9c
}

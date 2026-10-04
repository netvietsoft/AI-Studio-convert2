// Function: sub_FBBD58
// RVA: 0xfbbd58, Size: 264 bytes
int64_t sub_FBBD58(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_B9B524(...); // call internal at 0xfbbdc8
    sub_FBBE60(...); // call internal at 0xfbbe0c
    free(...); // call PLT API at 0xfbbe1c
    free(...); // call PLT API at 0xfbbe2c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfbbe5c
}

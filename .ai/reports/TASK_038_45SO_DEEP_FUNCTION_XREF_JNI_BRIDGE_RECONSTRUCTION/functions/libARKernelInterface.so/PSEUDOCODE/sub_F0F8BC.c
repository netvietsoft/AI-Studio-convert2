// Function: sub_F0F8BC
// RVA: 0xf0f8bc, Size: 200 bytes
int64_t sub_F0F8BC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_F0D2B8(...); // call internal at 0xf0f8f4
    sub_F0CCE4(...); // call internal at 0xf0f914
    sub_F0F704(...); // call internal at 0xf0f924
    memcpy(...); // call PLT API at 0xf0f930
    sub_F0CBF8(...); // call internal at 0xf0f954
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf0f980
}

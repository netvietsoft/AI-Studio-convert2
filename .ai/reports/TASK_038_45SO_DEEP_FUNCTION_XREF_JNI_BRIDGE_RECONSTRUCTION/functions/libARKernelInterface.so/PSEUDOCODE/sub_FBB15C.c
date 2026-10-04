// Function: sub_FBB15C
// RVA: 0xfbb15c, Size: 260 bytes
int64_t sub_FBB15C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_B9B524(...); // call internal at 0xfbb1cc
    sub_FBB260(...); // call internal at 0xfbb20c
    free(...); // call PLT API at 0xfbb21c
    free(...); // call PLT API at 0xfbb22c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfbb25c
}

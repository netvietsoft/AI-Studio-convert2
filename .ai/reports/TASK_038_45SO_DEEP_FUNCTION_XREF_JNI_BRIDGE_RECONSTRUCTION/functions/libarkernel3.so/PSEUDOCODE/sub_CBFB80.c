// Function: sub_CBFB80
// RVA: 0xcbfb80, Size: 96 bytes
int64_t sub_CBFB80(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_CBFBE0(...); // call internal at 0xcbfba4
    _ZdlPv(...); // call PLT API at 0xcbfbb4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xcbfbdc
}

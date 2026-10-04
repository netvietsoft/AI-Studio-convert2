// Function: sub_BADEDC
// RVA: 0xbadedc, Size: 508 bytes
int64_t sub_BADEDC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xbadf7c
    _Znam(...); // call PLT API at 0xbadf94
    sub_BAD300(...); // call internal at 0xbae024
    sub_BAD3A0(...); // call internal at 0xbae03c
    sub_BAD2D4(...); // call internal at 0xbae044
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xbae0d4
}

// Function: sub_91FF0C
// RVA: 0x91ff0c, Size: 96 bytes
int64_t sub_91FF0C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_91FF6C(...); // call internal at 0x91ff30
    _ZdlPv(...); // call PLT API at 0x91ff40
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x91ff68
}

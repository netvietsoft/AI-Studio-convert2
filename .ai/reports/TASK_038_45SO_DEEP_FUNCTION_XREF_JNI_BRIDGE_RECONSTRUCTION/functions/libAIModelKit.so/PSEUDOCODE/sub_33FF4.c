// Function: sub_33FF4
// RVA: 0x33ff4, Size: 284 bytes
int64_t sub_33FF4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x3401c
    (*x8)(...); // indirect call at 0x34040
    realloc(...); // call imported API via PLT at 0x3406c
    (*x8)(...); // indirect call at 0x340a0
    return a0;
    abort(...); // call imported API via PLT at 0x340ec
    _ZdlPv(...); // call imported API via PLT at 0x34108
}

// Function: sub_D8BAC
// RVA: 0xd8bac, Size: 476 bytes
int64_t sub_D8BAC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xd8c1c
    _Znwm(...); // call imported API via PLT at 0xd8c54
    memset(...); // call imported API via PLT at 0xd8c74
    (*x8)(...); // indirect call at 0xd8ca4
    _ZdlPv(...); // call imported API via PLT at 0xd8cb8
    (*x8)(...); // indirect call at 0xd8ce4
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0xd8d68
    __stack_chk_fail(...); // call imported API via PLT at 0xd8d84
}

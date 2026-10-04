// Function: sub_DBF8FC
// RVA: 0xdbf8fc, Size: 364 bytes
int64_t sub_DBF8FC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xdbf95c
    (*x8)(...); // indirect call at 0xdbfa24
    (*x8)(...); // indirect call at 0xdbfa38
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xdbfa60
    _ZdlPv(...); // call imported API via PLT at 0xdbfa64
}

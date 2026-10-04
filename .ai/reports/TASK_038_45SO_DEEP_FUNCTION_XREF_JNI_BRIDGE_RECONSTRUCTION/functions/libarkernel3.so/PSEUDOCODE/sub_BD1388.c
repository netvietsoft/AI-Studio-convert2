// Function: sub_BD1388
// RVA: 0xbd1388, Size: 188 bytes
int64_t sub_BD1388(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xbd13fc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xbd1420
    sub_BD1388(...); // call internal func at 0xbd143c
    return a0;
}

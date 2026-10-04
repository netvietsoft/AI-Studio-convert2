// Function: sub_C3FD80
// RVA: 0xc3fd80, Size: 384 bytes
int64_t sub_C3FD80(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xc3fdac
    (*x8)(...); // indirect call at 0xc3fdc4
    (*x8)(...); // indirect call at 0xc3fddc
    (*x8)(...); // indirect call at 0xc3fdf4
    sub_C4088C(...); // call internal func at 0xc3fe00
    (*x8)(...); // indirect call at 0xc3fe28
    (*x8)(...); // indirect call at 0xc3fe34
    (*x8)(...); // indirect call at 0xc3fe74
    (*x8)(...); // indirect call at 0xc3feac
    (*x8)(...); // indirect call at 0xc3febc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xc3fefc
}

// Function: sub_8E4D5C
// RVA: 0x8e4d5c, Size: 224 bytes
int64_t sub_8E4D5C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x8e4dbc
    (*x8)(...); // indirect call at 0x8e4e04
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x8e4e38
}

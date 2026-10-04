// Function: sub_E09A9C
// RVA: 0xe09a9c, Size: 404 bytes
int64_t sub_E09A9C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xe09aec
    __dynamic_cast(...); // call imported API via PLT at 0xe09b18
    (*x8)(...); // indirect call at 0xe09b6c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xe09c24
    sub_E09A9C(...); // call internal func at 0xe09c2c
}

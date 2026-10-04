// Function: sub_1B6928
// RVA: 0x1b6928, Size: 612 bytes
int64_t sub_1B6928(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0x1b6a04
    (*x28)(...); // indirect call at 0x1b6a7c
    memcpy(...); // call imported API via PLT at 0x1b6a8c
    (*x28)(...); // indirect call at 0x1b6aa4
    memcpy(...); // call imported API via PLT at 0x1b6ab8
    (*x26)(...); // indirect call at 0x1b6ad0
    (*x28)(...); // indirect call at 0x1b6b10
    memcpy(...); // call imported API via PLT at 0x1b6b24
    free(...); // call imported API via PLT at 0x1b6b2c
    return a0;
}

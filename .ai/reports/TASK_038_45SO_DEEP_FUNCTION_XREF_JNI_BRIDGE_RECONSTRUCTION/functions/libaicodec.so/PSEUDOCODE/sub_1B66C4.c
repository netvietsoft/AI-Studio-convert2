// Function: sub_1B66C4
// RVA: 0x1b66c4, Size: 612 bytes
int64_t sub_1B66C4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0x1b67a0
    (*x28)(...); // indirect call at 0x1b6818
    memcpy(...); // call imported API via PLT at 0x1b6828
    (*x28)(...); // indirect call at 0x1b6840
    memcpy(...); // call imported API via PLT at 0x1b6854
    (*x27)(...); // indirect call at 0x1b686c
    (*x28)(...); // indirect call at 0x1b68ac
    memcpy(...); // call imported API via PLT at 0x1b68c0
    free(...); // call imported API via PLT at 0x1b68c8
    return a0;
}

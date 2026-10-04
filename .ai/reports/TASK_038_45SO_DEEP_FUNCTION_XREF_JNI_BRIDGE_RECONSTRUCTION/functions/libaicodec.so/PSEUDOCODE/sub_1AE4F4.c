// Function: sub_1AE4F4
// RVA: 0x1ae4f4, Size: 560 bytes
int64_t sub_1AE4F4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0x1ae66c
    (*x24)(...); // indirect call at 0x1ae6b4
    (*x25)(...); // indirect call at 0x1ae6c4
    (*x8)(...); // indirect call at 0x1ae6e0
    free(...); // call imported API via PLT at 0x1ae6fc
    return a0;
}

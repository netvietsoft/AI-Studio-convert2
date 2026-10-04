// Function: sub_9AA14
// RVA: 0x9aa14, Size: 416 bytes
int64_t sub_9AA14(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    getwc(...); // call imported API via PLT at 0x9aa60
    getc(...); // call imported API via PLT at 0x9aa90
    (*x8)(...); // indirect call at 0x9aadc
    getc(...); // call imported API via PLT at 0x9aafc
    ungetwc(...); // call imported API via PLT at 0x9ab1c
    ungetc(...); // call imported API via PLT at 0x9ab7c
    return a0;
}

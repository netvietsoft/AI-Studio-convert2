// Function: sub_DFAD0
// RVA: 0xdfad0, Size: 200 bytes
int64_t sub_DFAD0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xdfaf0
    (*x8)(...); // indirect call at 0xdfb14
    return a0;
    realloc(...); // call imported API via PLT at 0xdfb5c
    return a0;
    abort(...); // call imported API via PLT at 0xdfb90
}

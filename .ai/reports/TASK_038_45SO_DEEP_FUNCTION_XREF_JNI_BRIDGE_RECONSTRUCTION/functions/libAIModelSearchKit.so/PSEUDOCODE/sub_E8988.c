// Function: sub_E8988
// RVA: 0xe8988, Size: 448 bytes
int64_t sub_E8988(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xe89a8
    (*x8)(...); // indirect call at 0xe89d0
    (*x8)(...); // indirect call at 0xe8a00
    realloc(...); // call imported API via PLT at 0xe8a30
    realloc(...); // call imported API via PLT at 0xe8a70
    (*x8)(...); // indirect call at 0xe8aa8
    (*x8)(...); // indirect call at 0xe8acc
    realloc(...); // call imported API via PLT at 0xe8af8
    return a0;
    abort(...); // call imported API via PLT at 0xe8b38
    abort(...); // call imported API via PLT at 0xe8b3c
    abort(...); // call imported API via PLT at 0xe8b40
}

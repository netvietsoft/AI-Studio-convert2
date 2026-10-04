// Function: sub_386C8
// RVA: 0x386c8, Size: 448 bytes
int64_t sub_386C8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x386e8
    (*x8)(...); // indirect call at 0x38710
    (*x8)(...); // indirect call at 0x38740
    realloc(...); // call imported API via PLT at 0x38770
    realloc(...); // call imported API via PLT at 0x387b0
    (*x8)(...); // indirect call at 0x387e8
    (*x8)(...); // indirect call at 0x3880c
    realloc(...); // call imported API via PLT at 0x38838
    return a0;
    abort(...); // call imported API via PLT at 0x38878
    abort(...); // call imported API via PLT at 0x3887c
    abort(...); // call imported API via PLT at 0x38880
}

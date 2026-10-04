// Function: sub_9A358
// RVA: 0x9a358, Size: 424 bytes
int64_t sub_9A358(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    getc(...); // call imported API via PLT at 0x9a3a4
    getc(...); // call imported API via PLT at 0x9a3d8
    (*x8)(...); // indirect call at 0x9a424
    getc(...); // call imported API via PLT at 0x9a444
    ungetc(...); // call imported API via PLT at 0x9a464
    ungetc(...); // call imported API via PLT at 0x9a4c8
    return a0;
}

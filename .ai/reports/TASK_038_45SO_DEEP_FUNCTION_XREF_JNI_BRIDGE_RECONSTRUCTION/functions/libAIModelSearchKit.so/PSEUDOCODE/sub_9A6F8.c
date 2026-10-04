// Function: sub_9A6F8
// RVA: 0x9a6f8, Size: 304 bytes
int64_t sub_9A6F8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fwrite(...); // call imported API via PLT at 0x9a740
    (*x8)(...); // indirect call at 0x9a78c
    fwrite(...); // call imported API via PLT at 0x9a7c8
    fwrite(...); // call imported API via PLT at 0x9a7f4
    return a0;
}

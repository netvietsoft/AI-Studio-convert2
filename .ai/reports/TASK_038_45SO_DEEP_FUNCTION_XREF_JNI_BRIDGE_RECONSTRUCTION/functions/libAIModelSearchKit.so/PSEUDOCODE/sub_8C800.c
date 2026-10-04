// Function: sub_8C800
// RVA: 0x8c800, Size: 204 bytes
int64_t sub_8C800(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memmove(...); // call imported API via PLT at 0x8c870
    (*x8)(...); // indirect call at 0x8c88c
    return a0;
}

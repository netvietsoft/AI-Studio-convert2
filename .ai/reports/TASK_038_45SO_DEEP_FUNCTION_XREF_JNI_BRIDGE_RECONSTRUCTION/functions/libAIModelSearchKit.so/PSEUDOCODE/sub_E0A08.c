// Function: sub_E0A08
// RVA: 0xe0a08, Size: 244 bytes
int64_t sub_E0A08(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe0a4c
    realloc(...); // call imported API via PLT at 0xe0aa8
    memcpy(...); // call imported API via PLT at 0xe0ac4
    return a0;
    abort(...); // call imported API via PLT at 0xe0ae8
    abort(...); // call imported API via PLT at 0xe0aec
    _ZdlPv(...); // call imported API via PLT at 0xe0af4
}

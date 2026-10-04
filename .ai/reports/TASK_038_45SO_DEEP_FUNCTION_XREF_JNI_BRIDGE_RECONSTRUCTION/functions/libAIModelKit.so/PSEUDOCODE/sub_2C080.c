// Function: sub_2C080
// RVA: 0x2c080, Size: 196 bytes
int64_t sub_2C080(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0x2c0e0
    memcpy(...); // call imported API via PLT at 0x2c0fc
    abort(...); // call imported API via PLT at 0x2c134
    _ZdlPv(...); // call imported API via PLT at 0x2c13c
}

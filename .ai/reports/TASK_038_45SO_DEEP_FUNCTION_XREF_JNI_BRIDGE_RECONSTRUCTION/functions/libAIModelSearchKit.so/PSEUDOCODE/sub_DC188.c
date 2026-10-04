// Function: sub_DC188
// RVA: 0xdc188, Size: 176 bytes
int64_t sub_DC188(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xdc1e8
    memcpy(...); // call imported API via PLT at 0xdc204
    return a0;
    abort(...); // call imported API via PLT at 0xdc228
    _ZdlPv(...); // call imported API via PLT at 0xdc230
}

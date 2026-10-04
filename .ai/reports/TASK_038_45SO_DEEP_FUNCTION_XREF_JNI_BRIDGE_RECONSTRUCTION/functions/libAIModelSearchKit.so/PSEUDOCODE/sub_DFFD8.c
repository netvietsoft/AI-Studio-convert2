// Function: sub_DFFD8
// RVA: 0xdffd8, Size: 352 bytes
int64_t sub_DFFD8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe001c
    realloc(...); // call imported API via PLT at 0xe008c
    memcpy(...); // call imported API via PLT at 0xe00a8
    realloc(...); // call imported API via PLT at 0xe00e0
    abort(...); // call imported API via PLT at 0xe0120
    abort(...); // call imported API via PLT at 0xe0124
    abort(...); // call imported API via PLT at 0xe0128
    _ZdlPv(...); // call imported API via PLT at 0xe0130
}

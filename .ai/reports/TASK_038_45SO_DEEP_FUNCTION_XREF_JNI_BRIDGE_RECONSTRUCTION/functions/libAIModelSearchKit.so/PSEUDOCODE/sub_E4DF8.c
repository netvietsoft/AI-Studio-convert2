// Function: sub_E4DF8
// RVA: 0xe4df8, Size: 272 bytes
int64_t sub_E4DF8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe4e78
    return a0;
    abort(...); // call imported API via PLT at 0xe4ef8
    _ZdlPv(...); // call imported API via PLT at 0xe4f00
}

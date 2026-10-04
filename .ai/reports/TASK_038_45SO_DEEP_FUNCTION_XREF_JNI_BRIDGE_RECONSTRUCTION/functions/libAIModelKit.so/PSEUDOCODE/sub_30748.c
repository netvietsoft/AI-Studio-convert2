// Function: sub_30748
// RVA: 0x30748, Size: 244 bytes
int64_t sub_30748(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0x3078c
    realloc(...); // call imported API via PLT at 0x307e8
    memcpy(...); // call imported API via PLT at 0x30804
    return a0;
    abort(...); // call imported API via PLT at 0x30828
    abort(...); // call imported API via PLT at 0x3082c
    _ZdlPv(...); // call imported API via PLT at 0x30834
}

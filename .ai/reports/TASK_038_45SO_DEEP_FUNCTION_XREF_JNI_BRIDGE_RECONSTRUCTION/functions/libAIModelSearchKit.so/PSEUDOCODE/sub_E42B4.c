// Function: sub_E42B4
// RVA: 0xe42b4, Size: 284 bytes
int64_t sub_E42B4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xe42dc
    (*x8)(...); // indirect call at 0xe4300
    realloc(...); // call imported API via PLT at 0xe432c
    (*x8)(...); // indirect call at 0xe4360
    return a0;
    abort(...); // call imported API via PLT at 0xe43ac
    _ZdlPv(...); // call imported API via PLT at 0xe43c8
}

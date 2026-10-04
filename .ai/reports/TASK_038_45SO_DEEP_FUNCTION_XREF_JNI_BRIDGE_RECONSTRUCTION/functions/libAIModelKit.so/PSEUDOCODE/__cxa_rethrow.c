// Function: __cxa_rethrow
// RVA: 0x39b94, Size: 228 bytes
int64_t __cxa_rethrow(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __cxa_get_globals(...); // call imported API via PLT at 0x39ba8
    _ZSt9terminatev(...); // call imported API via PLT at 0x39bb4
    __cxa_get_globals(...); // call imported API via PLT at 0x39c08
}

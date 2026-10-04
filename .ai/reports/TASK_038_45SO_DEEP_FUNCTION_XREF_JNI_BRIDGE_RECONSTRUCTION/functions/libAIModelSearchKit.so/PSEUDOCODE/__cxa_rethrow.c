// Function: __cxa_rethrow
// RVA: 0xe9e54, Size: 228 bytes
int64_t __cxa_rethrow(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __cxa_get_globals(...); // call imported API via PLT at 0xe9e68
    _ZSt9terminatev(...); // call imported API via PLT at 0xe9e74
    __cxa_get_globals(...); // call imported API via PLT at 0xe9ec8
    sub_754CC(...); // call internal func at 0xe9f34
}

// Function: __cxa_rethrow_primary_exception
// RVA: 0x39d30, Size: 304 bytes
int64_t __cxa_rethrow_primary_exception(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZSt14get_unexpectedv(...); // call imported API via PLT at 0x39da0
    _ZSt13get_terminatev(...); // call imported API via PLT at 0x39da8
    __cxa_get_globals(...); // call imported API via PLT at 0x39db8
    __cxa_get_globals(...); // call imported API via PLT at 0x39de0
    return a0;
    return a0;
    _ZSt9terminatev(...); // call imported API via PLT at 0x39e58
}

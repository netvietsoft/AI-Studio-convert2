// Function: __cxa_throw
// RVA: 0xe9b80, Size: 132 bytes
int64_t __cxa_throw(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __cxa_get_globals(...); // call imported API via PLT at 0xe9ba0
    _ZSt14get_unexpectedv(...); // call imported API via PLT at 0xe9ba8
    _ZSt13get_terminatev(...); // call imported API via PLT at 0xe9bb0
}

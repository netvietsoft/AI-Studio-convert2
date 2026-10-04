// Function: operator new(unsigned long)
// RVA: 0xe9790, Size: 112 bytes
int64_t _Znwm(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0xe97ac
    _ZSt15get_new_handlerv(...); // call imported API via PLT at 0xe97b4
    (*x0)(...); // indirect call at 0xe97bc
    return a0;
    __cxa_allocate_exception(...); // call imported API via PLT at 0xe97d8
    _ZNSt9bad_allocC1Ev(...); // call imported API via PLT at 0xe97e0
    __cxa_throw(...); // call imported API via PLT at 0xe97f8
    sub_754CC(...); // call internal func at 0xe97fc
}

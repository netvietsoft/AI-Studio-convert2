// Function: operator new(unsigned long, std::nothrow_t const&)
// RVA: 0xe9800, Size: 56 bytes
int64_t _ZnwmRKSt9nothrow_t(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call imported API via PLT at 0xe980c
    return a0;
    __cxa_begin_catch(...); // call imported API via PLT at 0xe981c
    __cxa_end_catch(...); // call imported API via PLT at 0xe9820
    return a0;
    sub_754CC(...); // call internal func at 0xe9834
}

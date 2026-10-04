// Function: std::__ndk1::__time_put::__do_put(wchar_t*, wchar_t*&, tm const*, char, char) const
// RVA: 0xad14c, Size: 248 bytes
int64_t _ZNKSt6__ndk110__time_put8__do_putEPwRS1_PK2tmcc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    strftime_l(...); // call imported API via PLT at 0xad1ac
    uselocale(...); // call imported API via PLT at 0xad1c4
    mbsrtowcs(...); // call imported API via PLT at 0xad1e0
    uselocale(...); // call imported API via PLT at 0xad1f0
    return a0;
    const char* s_4903b = "locale not supported"; // string xref
    _ZNSt6__ndk121__throw_runtime_errorEPKc(...); // call imported API via PLT at 0xad228
    sub_754CC(...); // call internal func at 0xad22c
}

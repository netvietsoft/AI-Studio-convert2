// Function: std::__ndk1::moneypunct_byname<wchar_t, true>::init(char const*)
// RVA: 0xcaf3c, Size: 1080 bytes
int64_t _ZNSt6__ndk117moneypunct_bynameIwLb1EE4initEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    newlocale(...); // call imported API via PLT at 0xcaf68
    uselocale(...); // call imported API via PLT at 0xcaf78
    localeconv(...); // call imported API via PLT at 0xcaf84
    uselocale(...); // call imported API via PLT at 0xcaf94
    uselocale(...); // call imported API via PLT at 0xcafe8
    mbsrtowcs(...); // call imported API via PLT at 0xcb004
    uselocale(...); // call imported API via PLT at 0xcb014
    uselocale(...); // call imported API via PLT at 0xcb05c
    mbsrtowcs(...); // call imported API via PLT at 0xcb078
    uselocale(...); // call imported API via PLT at 0xcb088
    uselocale(...); // call imported API via PLT at 0xcb0c0
    mbsrtowcs(...); // call imported API via PLT at 0xcb0dc
    uselocale(...); // call imported API via PLT at 0xcb0ec
    _ZdlPv(...); // call imported API via PLT at 0xcb1f4
    freelocale(...); // call imported API via PLT at 0xcb1fc
    return a0;
    const char* s_4903b = "locale not supported"; // string xref
    _ZNSt6__ndk121__throw_runtime_errorEPKc(...); // call imported API via PLT at 0xcb224
    const char* s_4a25f = "moneypunct_byname failed to construct for "; // string xref
    _ZNSt6__ndk121__throw_runtime_errorEPKc(...); // call imported API via PLT at 0xcb260
    const char* s_4903b = "locale not supported"; // string xref
    _ZNSt6__ndk121__throw_runtime_errorEPKc(...); // call imported API via PLT at 0xcb26c
    _ZdlPv(...); // call imported API via PLT at 0xcb280
    sub_754CC(...); // call internal func at 0xcb298
    sub_754CC(...); // call internal func at 0xcb29c
    sub_754CC(...); // call internal func at 0xcb2d0
    sub_754CC(...); // call internal func at 0xcb2d4
    sub_754CC(...); // call internal func at 0xcb2d8
    _ZdlPv(...); // call imported API via PLT at 0xcb324
}

// Function: std::__ndk1::numpunct_byname<wchar_t>::__init(char const*)
// RVA: 0xc3c80, Size: 416 bytes
int64_t _ZNSt6__ndk115numpunct_bynameIwE6__initEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_4a8fe = (void*)0x4a8fe; // global ref
    strcmp(...); // call imported API via PLT at 0xc3cac
    newlocale(...); // call imported API via PLT at 0xc3cc0
    uselocale(...); // call imported API via PLT at 0xc3cd0
    localeconv(...); // call imported API via PLT at 0xc3cdc
    uselocale(...); // call imported API via PLT at 0xc3cec
    freelocale(...); // call imported API via PLT at 0xc3d20
    return a0;
    const char* s_4a21c = "numpunct_byname<wchar_t>::numpunct_byname failed to construct for "; // string xref
    _ZNSt6__ndk121__throw_runtime_errorEPKc(...); // call imported API via PLT at 0xc3d74
    _ZdlPv(...); // call imported API via PLT at 0xc3da0
    _ZdlPv(...); // call imported API via PLT at 0xc3dc0
    sub_754CC(...); // call internal func at 0xc3de8
    sub_754CC(...); // call internal func at 0xc3dec
}

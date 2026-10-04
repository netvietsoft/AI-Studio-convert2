// Function: std::__ndk1::numpunct_byname<char>::__init(char const*)
// RVA: 0xc38d4, Size: 416 bytes
int64_t _ZNSt6__ndk115numpunct_bynameIcE6__initEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_4a8fe = (void*)0x4a8fe; // global ref
    strcmp(...); // call imported API via PLT at 0xc3900
    newlocale(...); // call imported API via PLT at 0xc3914
    uselocale(...); // call imported API via PLT at 0xc3924
    localeconv(...); // call imported API via PLT at 0xc3930
    uselocale(...); // call imported API via PLT at 0xc3940
    freelocale(...); // call imported API via PLT at 0xc3974
    return a0;
    const char* s_49adf = "numpunct_byname<char>::numpunct_byname failed to construct for "; // string xref
    _ZNSt6__ndk121__throw_runtime_errorEPKc(...); // call imported API via PLT at 0xc39c8
    _ZdlPv(...); // call imported API via PLT at 0xc39f4
    _ZdlPv(...); // call imported API via PLT at 0xc3a14
    sub_754CC(...); // call internal func at 0xc3a3c
    sub_754CC(...); // call internal func at 0xc3a40
}

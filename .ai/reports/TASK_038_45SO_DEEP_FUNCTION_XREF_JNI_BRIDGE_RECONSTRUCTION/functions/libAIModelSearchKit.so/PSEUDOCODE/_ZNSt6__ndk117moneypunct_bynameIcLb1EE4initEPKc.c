// Function: std::__ndk1::moneypunct_byname<char, true>::init(char const*)
// RVA: 0xca2b8, Size: 756 bytes
int64_t _ZNSt6__ndk117moneypunct_bynameIcLb1EE4initEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    newlocale(...); // call imported API via PLT at 0xca2e0
    uselocale(...); // call imported API via PLT at 0xca2f0
    localeconv(...); // call imported API via PLT at 0xca2fc
    uselocale(...); // call imported API via PLT at 0xca30c
    sub_75B80(...); // call internal func at 0xca454
    _ZdlPv(...); // call imported API via PLT at 0xca49c
    freelocale(...); // call imported API via PLT at 0xca4a4
    return a0;
    const char* s_4a25f = "moneypunct_byname failed to construct for "; // string xref
    _ZNSt6__ndk121__throw_runtime_errorEPKc(...); // call imported API via PLT at 0xca4f8
    _ZdlPv(...); // call imported API via PLT at 0xca50c
    sub_754CC(...); // call internal func at 0xca550
    sub_754CC(...); // call internal func at 0xca554
    _ZdlPv(...); // call imported API via PLT at 0xca584
}

// Function: std::__ndk1::__time_get::__time_get(char const*)
// RVA: 0xc5f9c, Size: 204 bytes
int64_t _ZNSt6__ndk110__time_getC1EPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    newlocale(...); // call imported API via PLT at 0xc5fc0
    return a0;
    const char* s_4a900 = "time_get_byname failed to construct for "; // string xref
    _ZNSt6__ndk121__throw_runtime_errorEPKc(...); // call imported API via PLT at 0xc6018
    _ZdlPv(...); // call imported API via PLT at 0xc603c
    _ZdlPv(...); // call imported API via PLT at 0xc605c
}

// Function: std::__ndk1::__throw_runtime_error(char const*)
// RVA: 0x819c4, Size: 84 bytes
int64_t _ZNSt6__ndk121__throw_runtime_errorEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __cxa_allocate_exception(...); // call imported API via PLT at 0x819dc
    _ZNSt13runtime_errorC1EPKc(...); // call imported API via PLT at 0x819e8
    __cxa_throw(...); // call imported API via PLT at 0x81a00
    __cxa_free_exception(...); // call imported API via PLT at 0x81a0c
}

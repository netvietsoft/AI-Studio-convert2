// Function: std::__throw_bad_alloc()
// RVA: 0x8c0fc, Size: 56 bytes
int64_t _ZSt17__throw_bad_allocv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __cxa_allocate_exception(...); // call imported API via PLT at 0x8c110
    _ZNSt9bad_allocC1Ev(...); // call imported API via PLT at 0x8c118
    __cxa_throw(...); // call imported API via PLT at 0x8c130
}

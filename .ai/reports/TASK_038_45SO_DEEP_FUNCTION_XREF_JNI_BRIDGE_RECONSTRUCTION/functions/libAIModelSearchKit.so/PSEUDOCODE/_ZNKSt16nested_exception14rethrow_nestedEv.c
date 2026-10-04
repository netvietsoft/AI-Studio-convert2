// Function: std::nested_exception::rethrow_nested() const
// RVA: 0x999e8, Size: 88 bytes
int64_t _ZNKSt16nested_exception14rethrow_nestedEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt13exception_ptrD1Ev(...); // call imported API via PLT at 0x99a0c
    _ZSt9terminatev(...); // call imported API via PLT at 0x99a14
    _ZNSt13exception_ptrC1ERKS_(...); // call imported API via PLT at 0x99a20
    _ZSt17rethrow_exceptionSt13exception_ptr(...); // call imported API via PLT at 0x99a28
    _ZNSt13exception_ptrD1Ev(...); // call imported API via PLT at 0x99a34
}

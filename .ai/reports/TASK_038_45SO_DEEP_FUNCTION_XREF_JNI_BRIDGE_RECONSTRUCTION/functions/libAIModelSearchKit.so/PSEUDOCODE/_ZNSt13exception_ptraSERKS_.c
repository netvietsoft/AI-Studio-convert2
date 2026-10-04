// Function: std::exception_ptr::operator=(std::exception_ptr const&)
// RVA: 0x998ec, Size: 80 bytes
int64_t _ZNSt13exception_ptraSERKS_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __cxa_increment_exception_refcount(...); // call imported API via PLT at 0x99914
    __cxa_decrement_exception_refcount(...); // call imported API via PLT at 0x9991c
    return a0;
}

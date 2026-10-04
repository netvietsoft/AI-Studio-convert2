// Function: std::current_exception()
// RVA: 0x99978, Size: 44 bytes
int64_t _ZSt17current_exceptionv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __cxa_current_primary_exception(...); // call imported API via PLT at 0x9998c
    return a0;
}

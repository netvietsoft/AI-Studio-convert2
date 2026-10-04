// Function: __cxa_uncaught_exception
// RVA: 0xea194, Size: 48 bytes
int64_t __cxa_uncaught_exception(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __cxa_get_globals_fast(...); // call imported API via PLT at 0xea1a0
    return a0;
    sub_754CC(...); // call internal func at 0xea1c0
}

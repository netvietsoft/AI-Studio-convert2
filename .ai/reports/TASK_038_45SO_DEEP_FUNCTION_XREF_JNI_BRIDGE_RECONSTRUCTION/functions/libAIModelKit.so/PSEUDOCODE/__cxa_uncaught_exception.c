// Function: __cxa_uncaught_exception
// RVA: 0x39ed4, Size: 48 bytes
int64_t __cxa_uncaught_exception(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __cxa_get_globals_fast(...); // call imported API via PLT at 0x39ee0
    return a0;
}

// Function: __cxa_allocate_exception
// RVA: 0x3975c, Size: 80 bytes
int64_t __cxa_allocate_exception(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memset(...); // call imported API via PLT at 0x3978c
    return a0;
    _ZSt9terminatev(...); // call imported API via PLT at 0x397a4
}

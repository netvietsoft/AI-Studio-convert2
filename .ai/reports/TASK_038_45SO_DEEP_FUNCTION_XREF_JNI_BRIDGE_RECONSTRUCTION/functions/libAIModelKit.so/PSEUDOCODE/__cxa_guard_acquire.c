// Function: __cxa_guard_acquire
// RVA: 0x1e9ec, Size: 304 bytes
int64_t __cxa_guard_acquire(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_10f34 = "__cxa_guard_acquire";
    pthread_mutex_lock(...); // call imported API via PLT at 0x1ea30
    syscall(...); // call imported API via PLT at 0x1ea48
    pthread_cond_wait(...); // call imported API via PLT at 0x1ea70
    syscall(...); // call imported API via PLT at 0x1ea88
    pthread_mutex_unlock(...); // call imported API via PLT at 0x1eaa4
    return a0;
    const char* s_1017b = "%s failed to acquire mutex"; // string xref
    const char* s_10f34 = "__cxa_guard_acquire";
    const char* s_fd59 = "%s failed to release mutex"; // string xref
    const char* s_10f34 = "__cxa_guard_acquire";
    const char* s_113b7 = "__cxa_guard_acquire detected recursive initialization: do you have a function-local static variable whose initialization depends"; // string xref
}

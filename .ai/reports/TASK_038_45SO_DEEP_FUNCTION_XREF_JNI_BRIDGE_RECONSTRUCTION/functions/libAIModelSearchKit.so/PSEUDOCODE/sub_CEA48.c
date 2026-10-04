// Function: sub_CEA48
// RVA: 0xcea48, Size: 300 bytes
int64_t sub_CEA48(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_4aa0b = "__cxa_guard_acquire";
    pthread_mutex_lock(...); // call imported API via PLT at 0xcea88
    syscall(...); // call imported API via PLT at 0xceaa0
    pthread_cond_wait(...); // call imported API via PLT at 0xceac8
    syscall(...); // call imported API via PLT at 0xceae0
    pthread_mutex_unlock(...); // call imported API via PLT at 0xceafc
    return a0;
    const char* s_4971f = "%s failed to acquire mutex"; // string xref
    const char* s_4aa0b = "__cxa_guard_acquire";
    const char* s_491ae = "%s failed to release mutex"; // string xref
    const char* s_4aa0b = "__cxa_guard_acquire";
    const char* s_4b07f = "__cxa_guard_acquire detected recursive initialization: do you have a function-local static variable whose initialization depends"; // string xref
    sub_754CC(...); // call internal func at 0xceb5c
}

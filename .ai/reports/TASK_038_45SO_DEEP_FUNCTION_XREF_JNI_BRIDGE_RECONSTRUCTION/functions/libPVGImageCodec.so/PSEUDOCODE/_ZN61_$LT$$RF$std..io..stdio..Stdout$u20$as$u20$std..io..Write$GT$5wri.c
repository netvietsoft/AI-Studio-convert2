// Function: _$LT$$RF$std..io..stdio..Stdout$u20$as$u20$std..io..Write$GT$::write::h2a5ccbb9e21de3cf
// RVA: 0x300f70, Size: 336 bytes
int64_t _ZN61_$LT$$RF$std..io..stdio..Stdout$u20$as$u20$std..io..Write$GT$5write17h2a5ccbb9e21de3cfE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_322208(...); // call internal at 0x300f98
    const char* str = "lock count overflow in reentrant mutexlibrary/std/src/sys_common/remutex.rsRUST_MIN_STACKlibrary/std/src/sys_common/thread_info.";
    _ZN4core6option13expect_failed17h773922ac044cf95cE(...); // call PLT API at 0x300fd0
    _ZN61_$LT$std..io..stdio..StdoutLock$u20$as$u20$std..io..Write$GT$5write17h8725ecd89f5db4fcE(...); // call PLT API at 0x301010
    syscall(...); // call PLT API at 0x30105c
    return a0;
    _ZN3std3sys4unix5locks11futex_mutex5Mutex14lock_contended17hecdef02271eb1c4dE(...); // call PLT API at 0x301078
    const char* str = "cannot access a Thread Local Storage value during or after destructionlibrary/std/src/thread/local.rstoo many running threads in";
    _ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E(...); // call PLT API at 0x3010a0
    sub_2E1DC8(...); // call internal at 0x3010b0
    sub_4BEBFC(...); // call internal at 0x3010b8
}

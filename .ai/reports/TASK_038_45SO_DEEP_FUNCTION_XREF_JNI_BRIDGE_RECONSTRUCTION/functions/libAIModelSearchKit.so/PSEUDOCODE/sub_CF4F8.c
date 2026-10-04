// Function: sub_CF4F8
// RVA: 0xcf4f8, Size: 292 bytes
int64_t sub_CF4F8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_4b3b3 = "libc++abi: ";
    void* g_fd130 = (void*)0xfd130; // global ref
    fwrite(...); // call imported API via PLT at 0xcf554
    void* g_fd130 = (void*)0xfd130; // global ref
    vfprintf(...); // call imported API via PLT at 0xcf590
    void* g_fd130 = (void*)0xfd130; // global ref
    fputc(...); // call imported API via PLT at 0xcf59c
    vasprintf(...); // call imported API via PLT at 0xcf5bc
    android_set_abort_message(...); // call imported API via PLT at 0xcf5c4
    const char* s_4b30e = "libc++abi"; // string xref
    openlog(...); // call imported API via PLT at 0xcf5d8
    const char* s_49f88 = "%s"; // string xref
    syslog(...); // call imported API via PLT at 0xcf5ec
    closelog(...); // call imported API via PLT at 0xcf5f0
    abort(...); // call imported API via PLT at 0xcf5f4
    _ZNSt9type_infoD2Ev(...); // call imported API via PLT at 0xcf5fc
    return a0;
    return a0;
}

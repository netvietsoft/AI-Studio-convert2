// Function: sub_CB504
// RVA: 0xcb504, Size: 188 bytes
int64_t sub_CB504(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_fd010 = (void*)0xfd010; // global ref
    void* g_1036e0 = (void*)0x1036e0; // global ref
    freelocale(...); // call imported API via PLT at 0xcb54c
    _ZNSt6__ndk114__shared_countD2Ev(...); // call imported API via PLT at 0xcb560
    void* g_1036e0 = (void*)0x1036e0; // global ref
    __cxa_guard_acquire(...); // call imported API via PLT at 0xcb56c
    void* g_4a8fe = (void*)0x4a8fe; // global ref
    newlocale(...); // call imported API via PLT at 0xcb584
    __cxa_guard_release(...); // call imported API via PLT at 0xcb598
    void* g_1036e0 = (void*)0x1036e0; // global ref
    __cxa_guard_abort(...); // call imported API via PLT at 0xcb5ac
    sub_754CC(...); // call internal func at 0xcb5b4
    sub_754CC(...); // call internal func at 0xcb5b8
}

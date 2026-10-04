// Function: sub_910E68
// RVA: 0x910e68, Size: 100 bytes
int64_t sub_910E68(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call PLT API at 0x910e7c
    _ZNSt6__ndk15mutex8try_lockEv(...); // call PLT API at 0x910e84
    _ZNSt6__ndk15mutex6unlockEv(...); // call PLT API at 0x910e90
    sched_yield(...); // call PLT API at 0x910e94
    _ZNSt6__ndk15mutex4lockEv(...); // call PLT API at 0x910e9c
    _ZNSt6__ndk15mutex8try_lockEv(...); // call PLT API at 0x910ea4
    _ZNSt6__ndk15mutex6unlockEv(...); // call PLT API at 0x910eb0
    sched_yield(...); // call PLT API at 0x910eb4
    return a0;
}

// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x3eaa8
// Recovered Name: sub_3eaa8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3eaa8 | Size: 672 bytes | SHA256: c38773c1c88eb940de3b171a3905344061d8a0e71bd3af88e7da37bf256c33ff
// Callers: 0 | Callees: 3 | Imports: 15

// Calls external APIs: _ZN17MMDetectionPlugin10AIDetectorC1Ev, _ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv, _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev, _ZNSt6__ndk15mutex4lockEv, _ZNSt6__ndk15mutex6unlockEv, _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev, _ZdlPv, _Znwm, __android_log_print, __stack_chk_fail, pthread_self, strcmp, vlai_init
// Strings referenced:
//   "MTMVCore"
//   "createAIDetector"

void sub_3eaa8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 168 instructions
    /* 0x3eaa8 */ stp x29, x30, [sp, #0x140];
    /* 0x3eaac */ stp x28, x23, [sp, #0x150];
    /* 0x3eab0 */ stp x22, x21, [sp, #0x160];
    /* 0x3eab4 */ stp x20, x19, [sp, #0x170];
    /* 0x3eab8 */ add x29, sp, #0x140;
    /* 0x3eabc */ mrs x22, tpidr_el0;
    /* 0x3eac0 */ adrp x20, #0x82000;
    /* 0x3eac4 */ mov x19, x0;
    /* 0x3eac8 */ ldr x8, [x22, #0x28];
    /* 0x3eacc */ ldr x20, [x20, #0xd50];
    /* 0x3ead0 */ stur x8, [x29, #-8];
    __android_log_print();
    strcmp();
    __android_log_print();
    _ZNSt6__ndk15mutex4lockEv();
    vlai_init();
    _Znwm();
    _ZN17MMDetectionPlugin10AIDetectorC1Ev();
    sub_3ef78();
    pthread_self();
    sub_3f09c();
    _ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv();
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk15mutex6unlockEv();
    return x0;
    _ZdlPv();
    _ZNSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev();
    _ZdlPv();
    _ZNSt6__ndk15mutex6unlockEv();
    sub_75c14();
    __stack_chk_fail();
}

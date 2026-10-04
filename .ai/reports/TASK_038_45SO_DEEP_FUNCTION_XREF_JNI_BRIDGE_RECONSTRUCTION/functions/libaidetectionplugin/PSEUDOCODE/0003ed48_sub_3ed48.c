// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x3ed48
// Recovered Name: sub_3ed48
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3ed48 | Size: 560 bytes | SHA256: 5ec918b666538577642ef65398ab14209149de2b6e7f9533869457849aec7c82
// Callers: 0 | Callees: 3 | Imports: 11

// Calls external APIs: _ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv, _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev, _ZNSt6__ndk15mutex4lockEv, _ZNSt6__ndk15mutex6unlockEv, _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev, _ZdlPv, __android_log_print, __stack_chk_fail, pthread_self
// Strings referenced:
//   "MTMVCore"
//   "destroyAIDetector"

void sub_3ed48(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 140 instructions
    /* 0x3ed48 */ stp x29, x30, [sp, #0x140];
    /* 0x3ed4c */ stp x28, x23, [sp, #0x150];
    /* 0x3ed50 */ stp x22, x21, [sp, #0x160];
    /* 0x3ed54 */ stp x20, x19, [sp, #0x170];
    /* 0x3ed58 */ add x29, sp, #0x140;
    /* 0x3ed5c */ mrs x22, tpidr_el0;
    /* 0x3ed60 */ ldr x8, [x22, #0x28];
    /* 0x3ed64 */ stur x8, [x29, #-8];
    /* 0x3ed68 */ cbz x0, #0x3eeb0;
    /* 0x3ed6c */ mov x19, x0;
    /* 0x3ed70 */ nop ;
    _ZNSt6__ndk15mutex4lockEv();
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
    __android_log_print();
    return x0;
    _ZdlPv();
    _ZNSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev();
    _ZNSt6__ndk15mutex6unlockEv();
    sub_75c14();
    __stack_chk_fail();
}

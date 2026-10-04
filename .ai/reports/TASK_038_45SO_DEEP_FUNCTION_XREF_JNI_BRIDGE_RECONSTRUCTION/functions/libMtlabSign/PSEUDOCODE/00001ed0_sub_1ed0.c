// Library: libMtlabSign.so
// Function ID: libMtlabSign::0x1ed0
// Recovered Name: sub_1ed0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1ed0 | Size: 772 bytes | SHA256: b4f47a81d7bf9be29b9a4b605e0f55d1733696cf933ce1a5c44dae7d87c6a45a
// Callers: 0 | Callees: 0 | Imports: 13

// Calls external APIs: _Z11jstring2strP7_JNIEnvP8_jstring, _ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi, _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev, _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk18ios_base4initEPv, _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev, _ZdlPv, __stack_chk_fail, rand
// Strings referenced:
//   "&f="
//   "&r="
//   "&t="
//   "a="
//   "k="

void sub_1ed0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 193 instructions
    /* 0x1ed0 */ stp x29, x30, [sp, #0x160];
    /* 0x1ed4 */ stp x28, x27, [sp, #0x170];
    /* 0x1ed8 */ stp x26, x25, [sp, #0x180];
    /* 0x1edc */ stp x24, x23, [sp, #0x190];
    /* 0x1ee0 */ stp x22, x21, [sp, #0x1a0];
    /* 0x1ee4 */ stp x20, x19, [sp, #0x1b0];
    /* 0x1ee8 */ add x29, sp, #0x160;
    /* 0x1eec */ mrs x24, tpidr_el0;
    /* 0x1ef0 */ mov x19, x8;
    /* 0x1ef4 */ mov x20, x2;
    /* 0x1ef8 */ ldr x8, [x24, #0x28];
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _Z11jstring2strP7_JNIEnvP8_jstring();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _Z11jstring2strP7_JNIEnvP8_jstring();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _Z11jstring2strP7_JNIEnvP8_jstring();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk18ios_base4initEPv();
    _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev();
    rand();
    _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi();
    _ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZdlPv();
    _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}

// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x3f0a0
// Recovered Name: sub_3f0a0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3f0a0 | Size: 644 bytes | SHA256: 330f595f3efa33fde1420743b48c4d406d801bfa43cd9bd27cee6a3bb31b0974
// Callers: 0 | Callees: 2 | Imports: 16

// Calls external APIs: _ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv, _ZNKSt6__ndk18ios_base6getlocEv, _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl, _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev, _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev, _ZNSt6__ndk16locale7classicEv, _ZNSt6__ndk16localeC1ERKS0_, _ZNSt6__ndk16localeD1Ev, _ZNSt6__ndk16localeaSERKS0_, _ZNSt6__ndk18ios_base4initEPv, _ZNSt6__ndk18ios_base5imbueERKNS_6localeE, _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev, _ZdlPv, __stack_chk_fail

void sub_3f0a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 161 instructions
    /* 0x3f0a0 */ stp x29, x30, [sp, #0x140];
    /* 0x3f0a4 */ str x28, [sp, #0x150];
    /* 0x3f0a8 */ stp x26, x25, [sp, #0x160];
    /* 0x3f0ac */ stp x24, x23, [sp, #0x170];
    /* 0x3f0b0 */ stp x22, x21, [sp, #0x180];
    /* 0x3f0b4 */ stp x20, x19, [sp, #0x190];
    /* 0x3f0b8 */ add x29, sp, #0x140;
    /* 0x3f0bc */ mrs x23, tpidr_el0;
    /* 0x3f0c0 */ adrp x22, #0x82000;
    /* 0x3f0c4 */ adrp x25, #0x82000;
    /* 0x3f0c8 */ ldr x22, [x22, #0xd78];
    _ZNSt6__ndk18ios_base4initEPv();
    _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev();
    _ZNSt6__ndk16locale7classicEv();
    _ZNKSt6__ndk18ios_base6getlocEv();
    _ZNSt6__ndk18ios_base5imbueERKNS_6localeE();
    _ZNSt6__ndk16localeD1Ev();
    _ZNSt6__ndk16localeC1ERKS0_();
    _ZNSt6__ndk16localeaSERKS0_();
    _ZNSt6__ndk16localeD1Ev();
    _ZNSt6__ndk16localeD1Ev();
    _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl();
    _ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv();
    sub_3f430();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev();
    return x0;
    _ZdlPv();
    _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk16localeD1Ev();
    _ZNSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev();
    sub_75c14();
    __stack_chk_fail();
}

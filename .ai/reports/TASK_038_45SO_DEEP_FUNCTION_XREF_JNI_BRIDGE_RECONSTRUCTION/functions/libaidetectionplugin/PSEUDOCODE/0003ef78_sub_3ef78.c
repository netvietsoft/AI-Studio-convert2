// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x3ef78
// Recovered Name: sub_3ef78
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3ef78 | Size: 292 bytes | SHA256: c40f8b3707612c26bae5cefd90fe19812354eb82b8f4c2819962b14e8470661c
// Callers: 2 | Callees: 1 | Imports: 4

// Calls external APIs: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev, _ZNSt6__ndk18ios_base4initEPv, _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev

void sub_3ef78(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 73 instructions
    /* 0x3ef78 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x3ef7c */ stp x26, x25, [sp, #0x10];
    /* 0x3ef80 */ stp x24, x23, [sp, #0x20];
    /* 0x3ef84 */ stp x22, x21, [sp, #0x30];
    /* 0x3ef88 */ stp x20, x19, [sp, #0x40];
    /* 0x3ef8c */ mov x29, sp;
    /* 0x3ef90 */ adrp x23, #0x82000;
    /* 0x3ef94 */ adrp x22, #0x82000;
    /* 0x3ef98 */ mov x20, x0;
    /* 0x3ef9c */ ldr x23, [x23, #0xd70];
    /* 0x3efa0 */ ldr x22, [x22, #0xd60];
    _ZNSt6__ndk18ios_base4initEPv();
    _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev();
    return x0;
    _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev();
    sub_75c14();
}

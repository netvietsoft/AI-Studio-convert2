// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x3f324
// Recovered Name: _ZNSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3f324 | Size: 128 bytes | SHA256: 9f81d2eea2c798c6c6ee506a77e4eeae54b374cae83eba6021be824ce37078a0
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev, _ZdlPv

void _ZNSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 32 instructions
    /* 0x3f324 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x3f328 */ str x21, [sp, #0x10];
    /* 0x3f32c */ stp x20, x19, [sp, #0x20];
    /* 0x3f330 */ mov x29, sp;
    /* 0x3f334 */ adrp x21, #0x82000;
    /* 0x3f338 */ adrp x9, #0x82000;
    /* 0x3f33c */ mov x20, x0;
    /* 0x3f340 */ ldr x21, [x21, #0xd60];
    /* 0x3f344 */ mov x19, x0;
    /* 0x3f348 */ ldr x8, [x21];
    /* 0x3f34c */ ldp x10, x11, [x21, #0x40];
    _ZdlPv();
    _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev();
}

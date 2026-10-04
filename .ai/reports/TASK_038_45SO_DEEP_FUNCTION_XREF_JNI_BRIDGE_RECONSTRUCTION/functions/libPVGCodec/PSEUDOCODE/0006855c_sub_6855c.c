// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x6855c
// Recovered Name: sub_6855c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6855c | Size: 52 bytes | SHA256: 7be55145e24fbddce5d5f59498f48e8a566eca8b6592f1e09581e9aca1cec109
// Callers: 1 | Callees: 0 | Imports: 2

// Calls external APIs: _ZNSt6__ndk15mutex4lockEv, _ZNSt6__ndk15mutex6unlockEv

void sub_6855c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x6855c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x68560 */ str x19, [sp, #0x10];
    /* 0x68564 */ mov x29, sp;
    /* 0x68568 */ mov x19, x0;
    /* 0x6856c */ add x0, x0, #8;
    _ZNSt6__ndk15mutex4lockEv();
    /* 0x68574 */ ldr w8, [x19, #0x30];
    /* 0x68578 */ add x0, x19, #8;
    /* 0x6857c */ add w8, w8, #1;
    /* 0x68580 */ str w8, [x19, #0x30];
    /* 0x68584 */ ldr x19, [sp, #0x10];
}

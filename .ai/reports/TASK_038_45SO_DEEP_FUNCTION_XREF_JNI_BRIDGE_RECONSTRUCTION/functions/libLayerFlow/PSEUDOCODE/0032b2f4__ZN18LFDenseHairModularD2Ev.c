// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x32b2f4
// Recovered Name: _ZN18LFDenseHairModularD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x32b2f4 | Size: 68 bytes | SHA256: 84bbe773faa903f341206c724692791318238198cb67e0002cde2afaaf46ace0
// Callers: 7 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN18LFDenseHairModularD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x32b2f4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x32b2f8 */ str x19, [sp, #0x10];
    /* 0x32b2fc */ mov x29, sp;
    /* 0x32b300 */ mov x19, x0;
    /* 0x32b304 */ ldr x0, [x0, #0x20];
    /* 0x32b308 */ cbz x0, #0x32b314;
    /* 0x32b30c */ str x0, [x19, #0x28];
    _ZdlPv();
    /* 0x32b314 */ ldrb w8, [x19, #8];
    /* 0x32b318 */ tbnz w8, #0, #0x32b328;
    /* 0x32b31c */ ldr x19, [sp, #0x10];
    return x0;
}

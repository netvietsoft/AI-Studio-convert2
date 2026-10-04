// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x34213c
// Recovered Name: _ZN11LayerFlowNS12CLFBlurLayerD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x34213c | Size: 116 bytes | SHA256: 819fb16c38213942588025464891e31f0c94461b9238ee5f73b3dd04c659e03e
// Callers: 1 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN11LayerFlowNS12CLFBlurLayerD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0x34213c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x342140 */ str x19, [sp, #0x10];
    /* 0x342144 */ mov x29, sp;
    /* 0x342148 */ adrp x8, #0x54a000;
    /* 0x34214c */ mov x19, x0;
    /* 0x342150 */ ldr x8, [x8, #0xb20];
    /* 0x342154 */ ldr x1, [x0, #0x510];
    /* 0x342158 */ add x8, x8, #0x10;
    /* 0x34215c */ str x8, [x0];
    /* 0x342160 */ add x0, x0, #0x508;
    sub_33f2f0();
    _ZdlPv();
    _ZdlPv();
}

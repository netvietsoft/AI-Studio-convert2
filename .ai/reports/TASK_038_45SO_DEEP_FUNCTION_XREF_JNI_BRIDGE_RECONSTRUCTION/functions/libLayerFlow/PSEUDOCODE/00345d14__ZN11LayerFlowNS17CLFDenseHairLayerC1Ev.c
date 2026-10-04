// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x345d14
// Recovered Name: _ZN11LayerFlowNS17CLFDenseHairLayerC1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x345d14 | Size: 252 bytes | SHA256: 18f083e138067baa63a4c152cca9eb940ece7d56b422f2bfbdd15f56660e4ce3
// Callers: 2 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt6__ndk16chrono12steady_clock3nowEv

void _ZN11LayerFlowNS17CLFDenseHairLayerC1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 63 instructions
    /* 0x345d14 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x345d18 */ str x19, [sp, #0x10];
    /* 0x345d1c */ mov x29, sp;
    /* 0x345d20 */ adrp x8, #0x54a000;
    /* 0x345d24 */ mov w9, #6;
    /* 0x345d28 */ movi v0.2d, #0000000000000000;
    /* 0x345d2c */ ldr x8, [x8, #0xa80];
    /* 0x345d30 */ strb w9, [x0, #8];
    /* 0x345d34 */ mov w9, #0x3332;
    /* 0x345d38 */ movk w9, #0x30, lsl #16;
    /* 0x345d3c */ mov x19, x0;
    _ZNSt6__ndk16chrono12steady_clock3nowEv();
    return x0;
}

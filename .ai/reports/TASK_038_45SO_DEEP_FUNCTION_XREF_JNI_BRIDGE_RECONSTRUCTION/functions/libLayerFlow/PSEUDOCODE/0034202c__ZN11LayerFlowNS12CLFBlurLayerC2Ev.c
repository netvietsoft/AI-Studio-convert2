// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x34202c
// Recovered Name: _ZN11LayerFlowNS12CLFBlurLayerC2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x34202c | Size: 272 bytes | SHA256: 9b46900216535b8f860604484730119afea1b58f0adee21f49a3673508a1276e
// Callers: 2 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt6__ndk16chrono12steady_clock3nowEv

void _ZN11LayerFlowNS12CLFBlurLayerC2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 68 instructions
    /* 0x34202c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x342030 */ str x19, [sp, #0x10];
    /* 0x342034 */ mov x29, sp;
    /* 0x342038 */ adrp x8, #0x54a000;
    /* 0x34203c */ mov w9, #8;
    /* 0x342040 */ movi v0.2d, #0000000000000000;
    /* 0x342044 */ ldr x8, [x8, #0xa80];
    /* 0x342048 */ strb w9, [x0, #8];
    /* 0x34204c */ mov w9, #0x6c62;
    /* 0x342050 */ movk w9, #0x7275, lsl #16;
    /* 0x342054 */ mov x19, x0;
    _ZNSt6__ndk16chrono12steady_clock3nowEv();
    return x0;
}

// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3421b0
// Recovered Name: _ZN11LayerFlowNS12CLFBlurLayerD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3421b0 | Size: 36 bytes | SHA256: c48c913fedda233a8686616161ddbb398156f7b6fcd70827c465169652d6c293
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN11LayerFlowNS12CLFBlurLayerD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x3421b0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3421b4 */ str x19, [sp, #0x10];
    /* 0x3421b8 */ mov x29, sp;
    /* 0x3421bc */ mov x19, x0;
    _ZN11LayerFlowNS12CLFBlurLayerD2Ev();
    /* 0x3421c4 */ mov x0, x19;
    /* 0x3421c8 */ ldr x19, [sp, #0x10];
    /* 0x3421cc */ ldp x29, x30, [sp], #0x20;
    /* 0x3421d0 */ b #0x52a280;
}

// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3eae50
// Recovered Name: _ZN11LayerFlowNS16CLFBlurProcessorD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3eae50 | Size: 36 bytes | SHA256: 4bb9ecd0dbd96ecd251d3d3389819f4aa9bde29ef765d999872fa3cce05a610c
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN11LayerFlowNS16CLFBlurProcessorD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x3eae50 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3eae54 */ str x19, [sp, #0x10];
    /* 0x3eae58 */ mov x29, sp;
    /* 0x3eae5c */ mov x19, x0;
    _ZN11LayerFlowNS16CLFBlurProcessorD1Ev();
    /* 0x3eae64 */ mov x0, x19;
    /* 0x3eae68 */ ldr x19, [sp, #0x10];
    /* 0x3eae6c */ ldp x29, x30, [sp], #0x20;
    /* 0x3eae70 */ b #0x52a280;
}

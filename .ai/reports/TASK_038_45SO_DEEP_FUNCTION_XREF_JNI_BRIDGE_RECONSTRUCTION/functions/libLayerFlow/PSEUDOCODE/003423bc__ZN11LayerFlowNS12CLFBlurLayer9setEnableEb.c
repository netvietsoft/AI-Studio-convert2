// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3423bc
// Recovered Name: _ZN11LayerFlowNS12CLFBlurLayer9setEnableEb
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3423bc | Size: 24 bytes | SHA256: d0708e7a27433a7bd160d0adf09216d30a8e847015e4d738385b3078f372f486
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN11LayerFlowNS12CLFBlurLayer9setEnableEb(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x3423bc */ ldr w8, [x0, #0x258];
    /* 0x3423c0 */ cmp w8, #0x15;
    /* 0x3423c4 */ b.ne #0x3423d4;
    /* 0x3423c8 */ and w8, w1, #1;
    /* 0x3423cc */ strb w8, [x0, #0x38];
    return x0;
}

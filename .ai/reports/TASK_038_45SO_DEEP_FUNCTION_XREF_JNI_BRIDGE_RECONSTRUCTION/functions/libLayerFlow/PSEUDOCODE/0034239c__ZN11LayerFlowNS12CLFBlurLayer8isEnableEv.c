// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x34239c
// Recovered Name: _ZN11LayerFlowNS12CLFBlurLayer8isEnableEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x34239c | Size: 20 bytes | SHA256: 6d3042fce8d2394214ca1992ffa01b359dc0dc8066a1abc497dc88c46679ae35
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN11LayerFlowNS12CLFBlurLayer8isEnableEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x34239c */ ldr w8, [x0, #0x258];
    /* 0x3423a0 */ cmp w8, #0x15;
    /* 0x3423a4 */ b.ne #0x3423b0;
    /* 0x3423a8 */ ldrb w0, [x0, #0x38];
    return x0;
}

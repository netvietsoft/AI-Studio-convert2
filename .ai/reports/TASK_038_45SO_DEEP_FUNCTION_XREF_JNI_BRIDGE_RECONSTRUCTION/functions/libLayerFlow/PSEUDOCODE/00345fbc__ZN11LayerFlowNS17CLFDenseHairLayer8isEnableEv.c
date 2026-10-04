// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x345fbc
// Recovered Name: _ZN11LayerFlowNS17CLFDenseHairLayer8isEnableEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x345fbc | Size: 20 bytes | SHA256: 7c99dcb6bf2bc2eca4eeeaa44c30f669515ce84c29baaaa2bb764d8e897f591d
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN11LayerFlowNS17CLFDenseHairLayer8isEnableEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x345fbc */ ldr w8, [x0, #0x258];
    /* 0x345fc0 */ cmp w8, #0x28;
    /* 0x345fc4 */ b.ne #0x345fd0;
    /* 0x345fc8 */ ldrb w0, [x0, #0x38];
    return x0;
}

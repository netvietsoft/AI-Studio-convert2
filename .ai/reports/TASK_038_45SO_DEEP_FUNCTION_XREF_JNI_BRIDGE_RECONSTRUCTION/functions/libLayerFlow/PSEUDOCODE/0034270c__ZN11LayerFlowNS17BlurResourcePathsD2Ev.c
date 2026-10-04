// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x34270c
// Recovered Name: _ZN11LayerFlowNS17BlurResourcePathsD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x34270c | Size: 68 bytes | SHA256: d32fc5b495741c2485049f18f3ec77bdf31e2fcba8d7588ea1c6ab81718c3064
// Callers: 2 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN11LayerFlowNS17BlurResourcePathsD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x34270c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x342710 */ str x19, [sp, #0x10];
    /* 0x342714 */ mov x29, sp;
    /* 0x342718 */ ldrb w8, [x0, #0x18];
    /* 0x34271c */ mov x19, x0;
    /* 0x342720 */ tbz w8, #0, #0x34272c;
    /* 0x342724 */ ldr x0, [x19, #0x28];
    _ZdlPv();
    /* 0x34272c */ ldrb w8, [x19];
    /* 0x342730 */ tbnz w8, #0, #0x342740;
    /* 0x342734 */ ldr x19, [sp, #0x10];
    return x0;
}

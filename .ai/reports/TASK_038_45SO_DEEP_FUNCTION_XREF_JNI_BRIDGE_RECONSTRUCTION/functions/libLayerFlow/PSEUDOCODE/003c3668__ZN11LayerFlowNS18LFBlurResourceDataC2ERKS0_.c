// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3c3668
// Recovered Name: _ZN11LayerFlowNS18LFBlurResourceDataC2ERKS0_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3c3668 | Size: 316 bytes | SHA256: cb259732269a6ed42c29a118e6f36cf976e6efd69b5aba2fa23fc585a4c5398b
// Callers: 1 | Callees: 4 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN11LayerFlowNS18LFBlurResourceDataC2ERKS0_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 79 instructions
    /* 0x3c3668 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x3c366c */ str x21, [sp, #0x10];
    /* 0x3c3670 */ stp x20, x19, [sp, #0x20];
    /* 0x3c3674 */ mov x29, sp;
    /* 0x3c3678 */ ldrb w8, [x1];
    /* 0x3c367c */ mov x20, x1;
    /* 0x3c3680 */ mov x19, x0;
    /* 0x3c3684 */ tbnz w8, #0, #0x3c36f8;
    /* 0x3c3688 */ ldr x8, [x20, #0x10];
    /* 0x3c368c */ ldr q0, [x20];
    /* 0x3c3690 */ str x8, [x19, #0x10];
    sub_2bc260();
    sub_5263b0();
    return x0;
    sub_2bc260();
    sub_2bc260();
    return x0;
    sub_2bbdb4();
    sub_526544();
    _ZdlPv();
    _ZdlPv();
    sub_526544();
}

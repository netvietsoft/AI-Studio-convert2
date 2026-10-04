// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x122254
// Recovered Name: _ZN14MTFilterKernel18CMTBokehBlurFilterC2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x122254 | Size: 72 bytes | SHA256: 2dfffe4dff8c5b700127f6fffbe9a5b252d7b62fbbef45bceb55d2de5636cb1f
// Callers: 1 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel18CMTBokehBlurFilterC2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x122254 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x122258 */ str x19, [sp, #0x10];
    /* 0x12225c */ mov x29, sp;
    /* 0x122260 */ mov x19, x0;
    _ZN14MTFilterKernel16CMTDynamicFilterC1Ev();
    /* 0x122268 */ adrp x8, #0x1c5000;
    /* 0x12226c */ movi v0.2d, #0000000000000000;
    /* 0x122270 */ ldr x8, [x8, #0x830];
    /* 0x122274 */ str wzr, [x19, #0x174];
    /* 0x122278 */ add x8, x8, #0x10;
    /* 0x12227c */ str x8, [x19];
    return x0;
}

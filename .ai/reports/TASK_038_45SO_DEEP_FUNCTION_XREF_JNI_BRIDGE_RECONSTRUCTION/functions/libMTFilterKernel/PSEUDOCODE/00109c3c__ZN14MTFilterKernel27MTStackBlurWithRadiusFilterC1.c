// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x109c3c
// Recovered Name: _ZN14MTFilterKernel27MTStackBlurWithRadiusFilterC1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x109c3c | Size: 76 bytes | SHA256: e7acf614a2a243915af46df66c495decfe161147ba9a59532b242b1f5c715503
// Callers: 1 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel27MTStackBlurWithRadiusFilterC1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x109c3c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x109c40 */ str x19, [sp, #0x10];
    /* 0x109c44 */ mov x29, sp;
    /* 0x109c48 */ mov x19, x0;
    _ZN14MTFilterKernel19MTTwoPassFilterBaseC2Ev();
    /* 0x109c50 */ adrp x8, #0x1c5000;
    /* 0x109c54 */ mov x9, #6;
    /* 0x109c58 */ ldr x8, [x8, #0x6d0];
    /* 0x109c5c */ movk x9, #0x3f80, lsl #48;
    /* 0x109c60 */ strb wzr, [x19, #0xc0];
    /* 0x109c64 */ str x9, [x19, #0xb8];
    return x0;
}

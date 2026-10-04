// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xdbd4c
// Recovered Name: _ZN14MTFilterKernel23MTFocusFaculaBlurFilterC2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xdbd4c | Size: 88 bytes | SHA256: 334835e64e8935b49a08ac622e1c27db431d13f7ec6a84fc379dcf467c9e9b52
// Callers: 1 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel23MTFocusFaculaBlurFilterC2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 22 instructions
    /* 0xdbd4c */ stp x29, x30, [sp, #-0x20]!;
    /* 0xdbd50 */ str x19, [sp, #0x10];
    /* 0xdbd54 */ mov x29, sp;
    /* 0xdbd58 */ mov x19, x0;
    _ZN14MTFilterKernel12MTFilterBaseC1Ev();
    /* 0xdbd60 */ movi v0.2d, #0000000000000000;
    /* 0xdbd64 */ adrp x9, #0x8d000;
    /* 0xdbd68 */ adrp x8, #0x1c5000;
    /* 0xdbd6c */ ldr q1, [x9, #0x680];
    /* 0xdbd70 */ adrp x9, #0x8d000;
    /* 0xdbd74 */ ldr x8, [x8, #0x520];
    return x0;
}

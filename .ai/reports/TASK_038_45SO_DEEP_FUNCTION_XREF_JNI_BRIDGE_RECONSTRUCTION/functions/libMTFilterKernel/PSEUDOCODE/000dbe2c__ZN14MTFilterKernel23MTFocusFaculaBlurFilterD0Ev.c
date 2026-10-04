// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xdbe2c
// Recovered Name: _ZN14MTFilterKernel23MTFocusFaculaBlurFilterD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xdbe2c | Size: 36 bytes | SHA256: 8fc95341abb9235fa12619e10891e80e7cdc451b908455b0ee8ed5de766737d9
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel23MTFocusFaculaBlurFilterD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0xdbe2c */ stp x29, x30, [sp, #-0x20]!;
    /* 0xdbe30 */ str x19, [sp, #0x10];
    /* 0xdbe34 */ mov x29, sp;
    /* 0xdbe38 */ mov x19, x0;
    _ZN14MTFilterKernel23MTFocusFaculaBlurFilterD2Ev();
    /* 0xdbe40 */ mov x0, x19;
    /* 0xdbe44 */ ldr x19, [sp, #0x10];
    /* 0xdbe48 */ ldp x29, x30, [sp], #0x20;
    /* 0xdbe4c */ b #0x1b42e0;
}

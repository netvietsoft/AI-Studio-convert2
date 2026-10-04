// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x122508
// Recovered Name: _ZN14MTFilterKernel18CMTBokehBlurFilterD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x122508 | Size: 36 bytes | SHA256: 3239b4ffd91ad53c6e83a05130fc2f65e64eb53094dcbb6b877a8e0ec4c27e25
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel18CMTBokehBlurFilterD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x122508 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x12250c */ str x19, [sp, #0x10];
    /* 0x122510 */ mov x29, sp;
    /* 0x122514 */ mov x19, x0;
    _ZN14MTFilterKernel18CMTBokehBlurFilterD2Ev();
    /* 0x12251c */ mov x0, x19;
    /* 0x122520 */ ldr x19, [sp, #0x10];
    /* 0x122524 */ ldp x29, x30, [sp], #0x20;
    /* 0x122528 */ b #0x1b42e0;
}

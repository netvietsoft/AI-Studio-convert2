// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1342b8
// Recovered Name: _ZN14MTFilterKernel17CMTFilterSoftHairD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1342b8 | Size: 36 bytes | SHA256: 42aaed951e5205c994372761cfa5977af560d87dbbe8ad59e69699101572d0c0
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel17CMTFilterSoftHairD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x1342b8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1342bc */ str x19, [sp, #0x10];
    /* 0x1342c0 */ mov x29, sp;
    /* 0x1342c4 */ mov x19, x0;
    _ZN14MTFilterKernel17CMTFilterSoftHairD1Ev();
    /* 0x1342cc */ mov x0, x19;
    /* 0x1342d0 */ ldr x19, [sp, #0x10];
    /* 0x1342d4 */ ldp x29, x30, [sp], #0x20;
    /* 0x1342d8 */ b #0x1b42e0;
}

// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xf393c
// Recovered Name: _ZN14MTFilterKernel16MTSoftHairFilterD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xf393c | Size: 36 bytes | SHA256: 394f05c211be616092fb463d116200d5c5e515ec486a1b4ec7c15a8ce603c8c2
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel16MTSoftHairFilterD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0xf393c */ stp x29, x30, [sp, #-0x20]!;
    /* 0xf3940 */ str x19, [sp, #0x10];
    /* 0xf3944 */ mov x29, sp;
    /* 0xf3948 */ mov x19, x0;
    _ZN14MTFilterKernel16MTSoftHairFilterD1Ev();
    /* 0xf3950 */ mov x0, x19;
    /* 0xf3954 */ ldr x19, [sp, #0x10];
    /* 0xf3958 */ ldp x29, x30, [sp], #0x20;
    /* 0xf395c */ b #0x1b42e0;
}

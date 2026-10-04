// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xeb808
// Recovered Name: _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilterD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xeb808 | Size: 36 bytes | SHA256: 08cdd16efdb31aa6efabcf9aea0fe2857728e1f227954a3b5b677440434aa0df
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilterD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0xeb808 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xeb80c */ str x19, [sp, #0x10];
    /* 0xeb810 */ mov x29, sp;
    /* 0xeb814 */ mov x19, x0;
    _ZN14MTFilterKernel17MTDrawArrayFilterD2Ev();
    /* 0xeb81c */ mov x0, x19;
    /* 0xeb820 */ ldr x19, [sp, #0x10];
    /* 0xeb824 */ ldp x29, x30, [sp], #0x20;
    /* 0xeb828 */ b #0x1b42e0;
}

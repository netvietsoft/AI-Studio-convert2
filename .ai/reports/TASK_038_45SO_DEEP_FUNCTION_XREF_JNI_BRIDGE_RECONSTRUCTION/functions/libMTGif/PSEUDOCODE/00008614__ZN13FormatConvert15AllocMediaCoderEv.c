// Library: libMTGif.so
// Function ID: libMTGif::0x8614
// Recovered Name: _ZN13FormatConvert15AllocMediaCoderEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x8614 | Size: 44 bytes | SHA256: 74d4fc2893ce8e9fbfb0cdddaba1963e617e1189bfeb5bb04f388f2a90fb153a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: malloc

void _ZN13FormatConvert15AllocMediaCoderEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x8614 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8618 */ mov x29, sp;
    /* 0x861c */ mov w0, #0x28;
    malloc();
    /* 0x8624 */ cbz x0, #0x8638;
    /* 0x8628 */ movi v0.2d, #0000000000000000;
    /* 0x862c */ mov w8, #-1;
    /* 0x8630 */ str w8, [x0, #0x20];
    /* 0x8634 */ stp q0, q0, [x0];
    /* 0x8638 */ ldp x29, x30, [sp], #0x10;
    return x0;
}

// Library: libarkernel3_c.so
// Function ID: libarkernel3_c::0x5d234
// Recovered Name: SWIG_rt_unhandled
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x5d234 | Size: 56 bytes | SHA256: 3b84d8e221f9154dc3c9d2d2657041ef9dc9817a21ed74f67822503826c8a5fe
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: free, longjmp

void SWIG_rt_unhandled(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x5d234 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x5d238 */ str x19, [sp, #0x10];
    /* 0x5d23c */ mov x29, sp;
    /* 0x5d240 */ adrp x19, #0x7b000;
    /* 0x5d244 */ ldr x19, [x19, #0x1b0];
    /* 0x5d248 */ ldr x0, [x19, #8];
    /* 0x5d24c */ cbz x0, #0x5d258;
    free();
    /* 0x5d254 */ str xzr, [x19, #8];
    sub_5d194();
    /* 0x5d25c */ adrp x0, #0x7b000;
    longjmp();
}

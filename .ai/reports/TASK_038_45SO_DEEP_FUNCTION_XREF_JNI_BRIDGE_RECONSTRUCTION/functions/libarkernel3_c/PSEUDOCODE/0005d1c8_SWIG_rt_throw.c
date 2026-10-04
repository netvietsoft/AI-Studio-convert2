// Library: libarkernel3_c.so
// Function ID: libarkernel3_c::0x5d1c8
// Recovered Name: SWIG_rt_throw
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x5d1c8 | Size: 108 bytes | SHA256: 419bc178931a477862a260a0706e1f8bd0f57388c6c721ee59b04e3bca32572b
// Callers: 0 | Callees: 0 | Imports: 5

// Calls external APIs: free, longjmp, malloc, strcpy, strlen

void SWIG_rt_throw(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x5d1c8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5d1cc */ str x21, [sp, #0x10];
    /* 0x5d1d0 */ stp x20, x19, [sp, #0x20];
    /* 0x5d1d4 */ mov x29, sp;
    /* 0x5d1d8 */ adrp x21, #0x7b000;
    /* 0x5d1dc */ mov x20, x1;
    /* 0x5d1e0 */ mov x19, x0;
    /* 0x5d1e4 */ ldr x21, [x21, #0x1b0];
    /* 0x5d1e8 */ ldr x8, [x21, #8];
    /* 0x5d1ec */ cbz x8, #0x5d1fc;
    /* 0x5d1f0 */ mov x0, x8;
    free();
    strlen();
    malloc();
    strcpy();
    longjmp();
}

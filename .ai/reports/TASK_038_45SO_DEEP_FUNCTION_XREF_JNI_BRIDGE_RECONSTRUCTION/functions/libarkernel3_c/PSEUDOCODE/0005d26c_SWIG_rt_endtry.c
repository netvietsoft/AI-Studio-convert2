// Library: libarkernel3_c.so
// Function ID: libarkernel3_c::0x5d26c
// Recovered Name: SWIG_rt_endtry
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x5d26c | Size: 120 bytes | SHA256: 278bb6007c54cdc0acf24cee89663f35431d38fa8d7ef160fb9fd250333a32f4
// Callers: 0 | Callees: 1 | Imports: 3

// Calls external APIs: longjmp, memcpy, setjmp

void SWIG_rt_endtry(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0x5d26c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x5d270 */ mov x29, sp;
    /* 0x5d274 */ adrp x8, #0x7b000;
    /* 0x5d278 */ ldr x8, [x8, #0x1b0];
    /* 0x5d27c */ ldr w8, [x8, #0x18];
    /* 0x5d280 */ cbz w8, #0x5d2a8;
    /* 0x5d284 */ adrp x0, #0x7b000;
    /* 0x5d288 */ ldr x0, [x0, #0x1a8];
    setjmp();
    /* 0x5d290 */ cbnz w0, #0x5d2dc;
    sub_5d0b0();
    longjmp();
    memcpy();
    return x0;
}

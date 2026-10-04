// Library: libarkernel3_c.so
// Function ID: libarkernel3_c::0x5d074
// Recovered Name: SWIG_rt_try
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x5d074 | Size: 60 bytes | SHA256: 9430504a86deeedc6a5b9f3f91385ed864790d36a225f09892cb6c856a4168c9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: memcpy

void SWIG_rt_try(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x5d074 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x5d078 */ stp x20, x19, [sp, #0x10];
    /* 0x5d07c */ mov x29, sp;
    /* 0x5d080 */ adrp x20, #0x82000;
    /* 0x5d084 */ adrp x1, #0x7b000;
    /* 0x5d088 */ mov w2, #0x100;
    /* 0x5d08c */ ldr x19, [x20, #0x248];
    /* 0x5d090 */ ldr x1, [x1, #0x1a8];
    /* 0x5d094 */ mov x0, x19;
    memcpy();
    /* 0x5d09c */ add x8, x19, #0x100;
    return x0;
}

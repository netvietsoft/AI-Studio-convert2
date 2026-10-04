// Library: libarkernel3_c.so
// Function ID: libarkernel3_c::0x5d300
// Recovered Name: sub_5d300
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5d300 | Size: 180 bytes | SHA256: 8c37721ed5d57f499e77399c8aa5f34268012c3e6efe9861b5c76171686f0d17
// Callers: 2 | Callees: 1 | Imports: 1

// Calls external APIs: free

void sub_5d300(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x5d300 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5d304 */ str x21, [sp, #0x10];
    /* 0x5d308 */ stp x20, x19, [sp, #0x20];
    /* 0x5d30c */ mov x29, sp;
    /* 0x5d310 */ adrp x8, #0x82000;
    /* 0x5d314 */ ldr x0, [x8, #0x250];
    /* 0x5d318 */ cbz x0, #0x5d320;
    free();
    /* 0x5d320 */ adrp x19, #0x7b000;
    /* 0x5d324 */ ldr x19, [x19, #0x1b0];
    /* 0x5d328 */ ldr x0, [x19, #8];
    free();
    free();
    free();
    sub_6bbf4();
    free();
    return x0;
}

// Library: libarkernel3.so
// Function ID: libarkernel3::0x9a7050
// Recovered Name: sub_9a7050
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x9a7050 | Size: 388 bytes | SHA256: 1bb0b87ec25b768f04c97b2d27b9f089ae495313b25855aace3b6d4d0243c8af
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: HIJ()* (table at 0x10cd340)

jlong sub_9a7050(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 97 instructions
    /* 0x9a7050 */ adrp x8, #0x289000;
    /* 0x9a7054 */ adrp x9, #0x28a000;
    /* 0x9a7058 */ adrp x10, #0x28a000;
    /* 0x9a705c */ ldr q0, [x8, #0x4f0];
    /* 0x9a7060 */ ldr q1, [x9, #0x420];
    /* 0x9a7064 */ adrp x8, #0x1117000;
    /* 0x9a7068 */ add x8, x8, #0x80;
    /* 0x9a706c */ adrp x9, #0x289000;
    /* 0x9a7070 */ ldr q2, [x10, #0xe30];
    /* 0x9a7074 */ stp q0, q1, [x8];
    /* 0x9a7078 */ ldr q0, [x9, #0x830];
    return x0;
}

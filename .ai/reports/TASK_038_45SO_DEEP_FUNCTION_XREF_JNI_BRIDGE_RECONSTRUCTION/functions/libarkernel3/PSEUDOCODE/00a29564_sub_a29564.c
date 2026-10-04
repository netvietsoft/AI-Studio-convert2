// Library: libarkernel3.so
// Function ID: libarkernel3::0xa29564
// Recovered Name: sub_a29564
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xa29564 | Size: 388 bytes | SHA256: bf3ede081303ba00bf6b9109ce35b800d01d7cbf3ebcbe3db3b21e477bac1605
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: HIJ()* (table at 0x10cd3a0)

jlong sub_a29564(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 97 instructions
    /* 0xa29564 */ adrp x8, #0x289000;
    /* 0xa29568 */ adrp x9, #0x28a000;
    /* 0xa2956c */ adrp x10, #0x28a000;
    /* 0xa29570 */ ldr q0, [x8, #0x4f0];
    /* 0xa29574 */ ldr q1, [x9, #0x420];
    /* 0xa29578 */ adrp x8, #0x1118000;
    /* 0xa2957c */ add x8, x8, #0x8e0;
    /* 0xa29580 */ adrp x9, #0x289000;
    /* 0xa29584 */ ldr q2, [x10, #0xe30];
    /* 0xa29588 */ stp q0, q1, [x8];
    /* 0xa2958c */ ldr q0, [x9, #0x830];
    return x0;
}

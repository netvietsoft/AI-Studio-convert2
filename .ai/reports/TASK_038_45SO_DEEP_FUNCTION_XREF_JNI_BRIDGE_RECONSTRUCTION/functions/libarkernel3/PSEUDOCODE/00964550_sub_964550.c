// Library: libarkernel3.so
// Function ID: libarkernel3::0x964550
// Recovered Name: sub_964550
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x964550 | Size: 388 bytes | SHA256: 57e85646e41b7633c2daa2802015205ef4b6b6da794e5266c6d2b67add613541
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: Hij()* (table at 0x10cd2b0)

jlong sub_964550(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 97 instructions
    /* 0x964550 */ adrp x8, #0x289000;
    /* 0x964554 */ adrp x9, #0x28a000;
    /* 0x964558 */ adrp x10, #0x28a000;
    /* 0x96455c */ ldr q0, [x8, #0x4f0];
    /* 0x964560 */ ldr q1, [x9, #0x420];
    /* 0x964564 */ adrp x8, #0x1114000;
    /* 0x964568 */ add x8, x8, #0xd20;
    /* 0x96456c */ adrp x9, #0x289000;
    /* 0x964570 */ ldr q2, [x10, #0xe30];
    /* 0x964574 */ stp q0, q1, [x8];
    /* 0x964578 */ ldr q0, [x9, #0x830];
    return x0;
}

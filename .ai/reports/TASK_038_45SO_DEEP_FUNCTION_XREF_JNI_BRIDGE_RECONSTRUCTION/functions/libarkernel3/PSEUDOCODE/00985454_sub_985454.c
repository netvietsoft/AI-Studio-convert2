// Library: libarkernel3.so
// Function ID: libarkernel3::0x985454
// Recovered Name: sub_985454
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x985454 | Size: 388 bytes | SHA256: 57ddc27c1bdb6ba614f9cc8c69ecc44e6db8b075d297e3563a32cc8e736158ed
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: HIJ()* (table at 0x10cd2f0)

jlong sub_985454(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 97 instructions
    /* 0x985454 */ adrp x8, #0x289000;
    /* 0x985458 */ adrp x9, #0x28a000;
    /* 0x98545c */ adrp x10, #0x28a000;
    /* 0x985460 */ ldr q0, [x8, #0x4f0];
    /* 0x985464 */ ldr q1, [x9, #0x420];
    /* 0x985468 */ adrp x8, #0x1115000;
    /* 0x98546c */ add x8, x8, #0xca0;
    /* 0x985470 */ adrp x9, #0x289000;
    /* 0x985474 */ ldr q2, [x10, #0xe30];
    /* 0x985478 */ stp q0, q1, [x8];
    /* 0x98547c */ ldr q0, [x9, #0x830];
    return x0;
}

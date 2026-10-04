// Library: libarkernel3.so
// Function ID: libarkernel3::0xb46428
// Recovered Name: sub_b46428
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xb46428 | Size: 388 bytes | SHA256: ec00e33be6bc55b0af425a9a10574a420c4a7a1468e6b895f299e186bb3488c6
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: hij()* (table at 0x10cd530)

jlong sub_b46428(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 97 instructions
    /* 0xb46428 */ adrp x8, #0x289000;
    /* 0xb4642c */ adrp x9, #0x28a000;
    /* 0xb46430 */ adrp x10, #0x28a000;
    /* 0xb46434 */ ldr q0, [x8, #0x4f0];
    /* 0xb46438 */ ldr q1, [x9, #0x420];
    /* 0xb4643c */ adrp x8, #0x111f000;
    /* 0xb46440 */ add x8, x8, #0x1a0;
    /* 0xb46444 */ adrp x9, #0x289000;
    /* 0xb46448 */ ldr q2, [x10, #0xe30];
    /* 0xb4644c */ stp q0, q1, [x8];
    /* 0xb46450 */ ldr q0, [x9, #0x830];
    return x0;
}

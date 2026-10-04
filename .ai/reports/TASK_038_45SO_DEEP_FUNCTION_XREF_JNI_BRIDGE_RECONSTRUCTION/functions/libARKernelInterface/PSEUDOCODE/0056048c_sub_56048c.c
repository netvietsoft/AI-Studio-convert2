// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56048c
// Recovered Name: sub_56048c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56048c | Size: 52 bytes | SHA256: 1502b5b95b4517816d34acc9fd42f603f8cbb73861c182436c0bb0cf5eeff0e3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceMeshCount(JI)V (table at 0x10cc488)

jlong sub_56048c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x56048c */ cbz x2, #0x5604bc;
    /* 0x560490 */ mov w8, #0x1b91;
    /* 0x560494 */ cmp w3, #1;
    /* 0x560498 */ movk w8, #1, lsl #16;
    /* 0x56049c */ b.lt #0x5604b8;
    /* 0x5604a0 */ mov w9, #1;
    /* 0x5604a4 */ strb w9, [x2, x8];
    /* 0x5604a8 */ mov w8, #0x1b94;
    /* 0x5604ac */ movk w8, #1, lsl #16;
    /* 0x5604b0 */ str w3, [x2, x8];
    return x0;
    return x0;
}

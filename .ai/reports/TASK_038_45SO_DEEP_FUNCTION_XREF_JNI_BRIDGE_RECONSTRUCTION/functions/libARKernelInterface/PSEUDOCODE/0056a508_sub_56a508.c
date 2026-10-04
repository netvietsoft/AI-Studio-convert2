// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a508
// Recovered Name: sub_56a508
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a508 | Size: 32 bytes | SHA256: 368de9153ab82d3b6124732e758cfbd4c2d389f750a05f39bb3217edeacdda59
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetPointCount2D(JI)I (table at 0x10cce90)

jlong sub_56a508(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x56a508 */ mov w0, wzr;
    /* 0x56a50c */ cbz x2, #0x56a524;
    /* 0x56a510 */ cmp w3, #0x13;
    /* 0x56a514 */ b.hi #0x56a524;
    /* 0x56a518 */ mov w8, #0x5c0;
    /* 0x56a51c */ umaddl x8, w3, w8, x2;
    /* 0x56a520 */ ldr w0, [x8, #0x44];
    return x0;
}

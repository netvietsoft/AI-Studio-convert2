// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56b1e4
// Recovered Name: sub_56b1e4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56b1e4 | Size: 28 bytes | SHA256: 873f40d56873a9057d63f08f57e8f197f93919fc4890ebd20145bbdeb84427d9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFacialInterPoint(JI)[F (table at 0x10cd0d0)

jlong sub_56b1e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x56b1e4 */ cbz x2, #0x56b26c;
    /* 0x56b1e8 */ cmp w3, #0x13;
    /* 0x56b1ec */ b.hi #0x56b26c;
    /* 0x56b1f0 */ mov w8, #0x5c0;
    /* 0x56b1f4 */ umaddl x8, w3, w8, x2;
    /* 0x56b1f8 */ ldrb w8, [x8, #0x4a];
    /* 0x56b1fc */ cbz w8, #0x56b26c;
}

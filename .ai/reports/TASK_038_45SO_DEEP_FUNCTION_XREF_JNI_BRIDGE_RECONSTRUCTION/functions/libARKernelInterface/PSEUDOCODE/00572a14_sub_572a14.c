// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x572a14
// Recovered Name: sub_572a14
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x572a14 | Size: 48 bytes | SHA256: 46e2c4e9745f5147d4bd69eac6bc7c7992cfbcb2d46791c5235b7f90b8dc70ac
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetNailRect(JIFFFF)V (table at 0x10cd988)

jlong sub_572a14(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x572a14 */ cbz x2, #0x572a40;
    /* 0x572a18 */ cmp w3, #9;
    /* 0x572a1c */ b.hi #0x572a40;
    /* 0x572a20 */ mov w8, #0x88;
    /* 0x572a24 */ mov w9, #1;
    /* 0x572a28 */ umaddl x8, w3, w8, x2;
    /* 0x572a2c */ strb w9, [x8, #0x960];
    /* 0x572a30 */ str s0, [x8, #0x964];
    /* 0x572a34 */ str s1, [x8, #0x968];
    /* 0x572a38 */ str s2, [x8, #0x96c];
    /* 0x572a3c */ str s3, [x8, #0x970];
    return x0;
}

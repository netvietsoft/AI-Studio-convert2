// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5822bc
// Recovered Name: sub_5822bc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5822bc | Size: 32 bytes | SHA256: cbdbaefc24199ebb35be09dcda5fb6ecdfd917ee562ccc1218dbfccec1cf7cc1
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTimestamp(J)J (table at 0x10cf488)

jlong sub_5822bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x5822bc */ cbz x2, #0x5822d4;
    /* 0x5822c0 */ ldr x0, [x2, #0x140];
    /* 0x5822c4 */ cbz x0, #0x5822dc;
    /* 0x5822c8 */ ldr x8, [x0];
    /* 0x5822cc */ ldr x1, [x8, #0x30];
    /* 0x5822d0 */ br x1;
    /* 0x5822d4 */ mov x0, xzr;
    return x0;
}

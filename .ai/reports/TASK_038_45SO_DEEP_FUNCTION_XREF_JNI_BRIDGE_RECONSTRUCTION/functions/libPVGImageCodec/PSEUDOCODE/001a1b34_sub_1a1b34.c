// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x1a1b34
// Recovered Name: sub_1a1b34
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1a1b34 | Size: 16 bytes | SHA256: 9a2d716175652eb87d14826702cd01228982092726e9fd0135d6ff94eb3a944c
// Callers: 0 | Callees: 0 | Imports: 0


void sub_1a1b34(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x1a1b34 */ ldr x8, [x1];
    /* 0x1a1b38 */ mov w0, #1;
    /* 0x1a1b3c */ str x8, [x1, #8];
    return x0;
}

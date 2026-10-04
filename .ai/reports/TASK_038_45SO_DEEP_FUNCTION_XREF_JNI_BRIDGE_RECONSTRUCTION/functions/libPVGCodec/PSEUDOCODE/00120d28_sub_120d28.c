// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x120d28
// Recovered Name: sub_120d28
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x120d28 | Size: 24 bytes | SHA256: a0bd6506ff9c25065e64e2bc46f6474be3184075073ce54b38103f4975919f29
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: native_getFrameIndex(JJ)I (table at 0x13a748)

jlong sub_120d28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x120d28 */ cbz x2, #0x120d40;
    /* 0x120d2c */ ldr x8, [x2];
    /* 0x120d30 */ mov x0, x2;
    /* 0x120d34 */ mov x1, x3;
    /* 0x120d38 */ ldr x4, [x8, #0x28];
    /* 0x120d3c */ br x4;
}

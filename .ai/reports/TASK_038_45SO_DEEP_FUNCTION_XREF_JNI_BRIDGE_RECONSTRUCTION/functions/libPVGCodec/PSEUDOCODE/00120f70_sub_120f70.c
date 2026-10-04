// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x120f70
// Recovered Name: sub_120f70
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x120f70 | Size: 24 bytes | SHA256: e235cb3dc25c298d032c7c2e5b1f4c17155e349e864d9226fa2abf86d547d725
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: native_getKeyFrameIndex(JJ)I (table at 0x13a790)

jlong sub_120f70(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x120f70 */ cbz x2, #0x120f88;
    /* 0x120f74 */ ldr x8, [x2];
    /* 0x120f78 */ mov x0, x2;
    /* 0x120f7c */ mov x1, x3;
    /* 0x120f80 */ ldr x4, [x8, #0x40];
    /* 0x120f84 */ br x4;
}

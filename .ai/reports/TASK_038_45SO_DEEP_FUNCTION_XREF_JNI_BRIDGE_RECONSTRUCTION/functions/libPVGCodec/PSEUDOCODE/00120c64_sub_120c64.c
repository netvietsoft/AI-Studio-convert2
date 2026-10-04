// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x120c64
// Recovered Name: sub_120c64
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x120c64 | Size: 24 bytes | SHA256: d6330b5b22df02db94bf23a6c3a0acf27fbae2c0bbef49033e3bf825ae843647
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: native_getEntryTimestamp(JI)J (table at 0x13a730)

jlong sub_120c64(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x120c64 */ cbz x2, #0x120c7c;
    /* 0x120c68 */ ldr x8, [x2];
    /* 0x120c6c */ mov x0, x2;
    /* 0x120c70 */ mov w1, w3;
    /* 0x120c74 */ ldr x4, [x8, #0x20];
    /* 0x120c78 */ br x4;
}
